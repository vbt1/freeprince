/*  FreePrince - POP1 remake
    Copyright (C) 2003,2004 Princed Development Team

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    The authors of this program may be contacted at http://forum.princed.com.ar
*/

/*
resources.c: Princed Resources : DAT Extractor
¯¯¯¯¯¯¯¯¯¯¯
 Copyright 2003, 2004 Princed Development Team
  Created: 24 Aug 2003

  Author: Enrique Calot <ecalot.cod@princed.com.ar>
  Version: 1.01 (2003-Oct-23)
  Version: 1.20 (2004-Mar-07)
  Version: 1.30 (2004-Mar-15)

 Note:
  DO NOT remove this copyright notice
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freeprince.h"
#include "resources.h"
#include "output.h"
#include "maps.h"

#include "compress.h"

#include "dat.h"
#include "disk.h"

/***************************************************************\
|                  I M P L E M E N T A T I O N                  |
\***************************************************************/

/*
 * Resource creation
 */

/*
 * Functions made to get data from the DAT files using some optimizations
 */

int res_getDataById(int id,int maxItems,tMemory* result) {
	/* This function looks for a data resource in a dat file optimizing the search knowing
	 * that the id's starts in 0
	 */
/* TODO: use static to remember where it is */	
	long int gotId;
	int indexNumber;
	
	/* main loop */
	for (indexNumber=0;indexNumber<maxItems;indexNumber++) {
		gotId=mReadFileInDatFile(
				(indexNumber+id)%maxItems,
				&(result->array),
				(unsigned long *)&(result->size));
		if (gotId==id) break;
	}
	
	/* Return value */
	return (gotId==id); /* 1 if the id was found, 0 if not */
}

short res_list[]=RES_LIST;
char* res_file[]=RES_FILES;
/*short res_fileid[12]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};*/

void getOffsets(int *down, int *left, int *right, int from, int hasD, int hasL, int hasR,int total, int resource) {
	const unsigned short* list;
	short d,l,r;
	int resourceInShorts=resource>>1;
	total++;
	total>>=1;
	/* set the start of the list to the start od the offsets */
	list=(const unsigned short*)(res_list+from-total*(hasD+hasL+hasR));

	/* set the values */
	if (hasD) {
		d=list[resourceInShorts];
		if (resource&1) {
			*down=(d>>8)-64;
		} else {
			*down=(d&0xff)-64;
		}
	} else {
		*down=0;
	}
	if (hasL) {
		l=list[resourceInShorts+total*hasD];
		if (resource&1) {
			*left=(l>>8)-64;
		} else {
			*left=(l&0xff)-64;
		}
	} else {
		*left=0;
	}
	if (hasR) {
		r=list[resourceInShorts+total*(hasD+hasL)];
		if (resource&1) {
			*right=(r>>8)-64;
		} else {
			*right=(r&0xff)-64;
		}
	} else {
		*right=0;
	}
}


unsigned int LitToBigEndian(unsigned int x)
{
	return (((x>>24) & 0x000000ff) | ((x>>8) & 0x0000ff00) | ((x<<8) & 0x00ff0000) | ((x<<24) & 0xff000000));
}


/**
 * Public functions
 * */

tData* resLoad(long id) {
	/* Initialize abstract variables to read this new DAT file */
	unsigned short int numberOfItems;
/* vbt on part du principe que c'était du little endian */	
/*	id=LitToBigEndian(id);*/

	tData* result;
	tMemory raw;
/*
	int mask=res_get_part_mods(id);
	int total=res_get_part_size(id);
	int from=res_get_part_from(id);
	int type=res_get_part_type(id);
*/
	int mask=res_get_part_mods(id);
	int total=res_get_part_size(id);
	int from=res_get_part_from(id);
	int type=res_get_part_type(id);

	
	switch (type) {
		case RES_TYPE_LVL:

			if (total!=2) {
				slPrint("Fatal Error: resLoad: invalid level define!                                     ",slLocate(2,21));
/*				fprintf(stderr,"Fatal Error: resLoad: invalid level define!\n");*/
				return NULL;
			}

			mask+=res_list[from+1];

			if (!mReadBeginDatFile(&numberOfItems,res_file[res_list[from]])) {
				slPrint("Fatal Error: resLoad: level file not found!                                     ",slLocate(2,21));
/*				fprintf(stderr,"Fatal Error: resLoad: level file not found!\n");*/
				return NULL;
			}
			if(!res_getDataById(mask,numberOfItems,&raw)) {
				slPrint("Fatal Error: resLoad: level not found!                                     ",slLocate(2,21));
/*				fprintf(stderr,"Fatal Error: resLoad: level not found!\n");*/
				return NULL;
			}
			result=(tData*)malloc(sizeof(tData));
			result->frames=1; /* drop filename and palette */
			result->type=eLevels;
			result->pFrames=(void**)mapLoadLevel(raw);
			mReadCloseDatFile();
			return result; /* transform from raw to a loaded map */
		case RES_TYPE_IMG: {
				slPrint("RES_TYPE_IMG                                    ",slLocate(2,19));

			tMemory palette;
			tImage image;
			tPalette pal;
			int has_D=((mask&RES_MODS_HAS_D)?1:0);
			int has_L=((mask&RES_MODS_HAS_L)?1:0);
			int has_R=((mask&RES_MODS_HAS_R)?1:0);
			int down,left,right;
			int invert=((mask&(RES_MODS_INVERT))==(RES_MODS_INVERT));

			result=(tData*)malloc(sizeof(tData));
			result->type=eImages;

			if (!mReadBeginDatFile(&numberOfItems,res_file[res_list[from]])) {
				slPrint("Fatal Error: resLoad: level file not found!                                     ",slLocate(2,22));
/*				fprintf(stderr,"Fatal Error: resLoad: level file not found!\n");*/
				return NULL;
			}
			if (mask&RES_MODS_BW) { /* if black and white */
				/* this palette is white, red, green, blue */
				static const char bwpalettes[]=BW_COLORS;
				static char       bwpalette[]={0,0,0,0,0,0};
 				memcpy(bwpalette+3,bwpalettes+3*((mask>>5)&3),3);
				pal.colors=2;
				pal.color=(tColor*)bwpalette;
				result->frames=total-1; /* drop filename */
			} else {
				from++;
				if(!res_getDataById(res_list[from],numberOfItems,&palette)) {
					slPrint("Fatal Error: resLoad: palette not found!                                     ",slLocate(2,21));
/*					fprintf(stderr,"Fatal Error: resLoad: palette not found!\n");*/
					return NULL;
				}
				if (palette.size!=100) {

				slPrint("Fatal error: resLoad: invalid palette                                     ",slLocate(2,21));
/*     			fprintf(stderr,"Fatal error: resLoad: invalid palette\n");*/
					return NULL;
				}
				pal.colors=16;
				pal.color=(tColor*)(palette.array+5);
				result->frames=total-2; /* drop filename and palette */
			}
			from++;

			result->pFrames=(void**)malloc(result->frames*sizeof(void*));
			for (total=0;total<result->frames;total++) {
				if(!res_getDataById(res_list[from+total],numberOfItems,&raw)) {
					slPrint("Fatal Error: resLoad: image not found!                                     ",slLocate(2,21));
/*					fprintf(stderr,"Fatal Error: resLoad: image not found!\n");*/
					return NULL;
				}

				/* get the offsets to move the image */
				if (pal.colors==16) {/* available only for 16 colors images */
					getOffsets(&down,&left,&right,from-2,has_D,has_L,has_R,result->frames,total);
				} else {
					down=left=right=0;
				}

char toto[50];
 sprintf(toto,"d %d l %d r %d hd %d hl %d hr %d           ",down,left,right,has_D,has_L,has_R); 
slPrint(toto,slLocate(2,5));
 sprintf(toto,"m %x t %x f %x t %x id %x 0x000000ff           ",mask,total,from,type,id); 
slPrint(toto,slLocate(2,6));
				/* expand raw image into an image structure */

				mExpandGraphic(raw.array,&image,raw.size);

				/* convert image structure into blittable output surfaces */

				result->pFrames[total]=(void*)outputLoadBitmap(
					image.pix,image.widthInBytes*image.height,pal,image.height,image.width,
					invert,!(mask&RES_MODS_BW),down,invert?right:left
        );

/*while(1);*/
				/* free intermediate image data */
				free(image.pix);
			
			}
			mReadCloseDatFile();
			return result;
		}
	}
	return NULL; /* unknown type */
}

void resFree(tData* res) {
	if (!res) return;
	if (res->type==eImages) {
		while (res->frames) { /* free all frames */
			outputFreeBitmap(res->pFrames[--(res->frames)]);
		}
		free(res->pFrames); /* free the frame list */
	} else if (res->type==eLevels) {
		mapFreeLevel((tMap*)(res->pFrames)); /* free the map */
	}
#ifdef RESOURCESDEBUG
	fprintf(stderr,"ResFree activated\n");
#endif
	free(res); /* free the resource structure */
}

