/*  Princed V3 - Prince of Persia Level Editor for PC Version
    Copyright (C) 2003 Princed Development Team

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
titles.c: FreePrince : Titles, animation and presentation
¯¯¯¯¯¯¯¯¯
 Copyright 2004 Princed Development Team
  Created: 18 Jul 2004

  Authores: Diego Essaya <dessaya.cod@princed.com.ar>
	          Enrique Calot <ecalot.cod@princed.com.ar>

 Note:
  DO NOT remove this copyright notice
*/

#include "output.h"
#include "titles.h"
#include "input.h"
#include <stdio.h> /* NULL */
#include <stdlib.h> /* malloc/free */

#include "anims.h"
#include "object.h"

#define		CHECKMALLOCRESULT(x) if(!(x)) Quit("Out of memory at %s:%i", __FILE__, __LINE__)

/* private structures */
typedef struct {
	tData*        img;
	unsigned char layer;
	unsigned short duration;
	unsigned short x;
	unsigned short y;
} titleImage;

typedef struct {
	tObject        obj;
	int            active;
	unsigned short duration;
} titleObject;

tMenuOption getAction(tKey key) {
	switch(key.actionPerformed) {
	case quit:
		return menuQuit;
	case load:
slPrint("menuLoad(key)                                     ",slLocate(2,20));
		return menuLoad;
	default:
		return menuStart;
	}
}

tMenuOption playAnimation(int id) {

	/* Declare variables */
	int imgCount,         objCount,              sndCount,               i;
	animImage*  img;      animObject* obj;       animSound* snd;
	titleImage* imgArray; titleObject* objArray; /*animSound* sndArray;*/
	int imgsActive=0;     int objsActive=0;      /*int sndsActive=0;*/
	int imgTotal,         objTotal,              sndTotal;

	tKey key=inputCreateKey();
	tKey nullKey=inputCreateKey();

	/* Initialize animation and allocate memory */
	animStart(id,&imgTotal,&objTotal,&sndTotal);

	imgArray=(titleImage*)malloc(imgTotal*sizeof(titleImage)); 
	CHECKMALLOCRESULT(imgArray);
	objArray=(titleObject*)malloc(objTotal*sizeof(titleObject));
	CHECKMALLOCRESULT(objArray);
/*
	imgArray=(titleImage*)0x00202000; 
	CHECKMALLOCRESULT(imgArray);
	objArray=(titleObject*)0x00202000+(imgTotal*sizeof(titleImage));
	CHECKMALLOCRESULT(objArray);
*/
	/*sndArray=(animSound*)malloc(sndTotal*sizeof(animSound));*/

	/* main animation kernel loop */
	while (animGetFrame(&imgCount,&objCount,&sndCount,&img,&obj,&snd)) {
		int reprocessInput=1;

		while(reprocessInput) {
		if (!inputGetEvent(&key)) {
/*		if (0) {  */
			/* key pressed */
		 	/*  if there is an action      and  the action wasn't control key */
			if (key.actionPerformed!=none  &&   !(inputGetCtrl(key.status)&&key.actionPerformed==other))
			{
				return getAction(key);
			}
		} else {
			reprocessInput=0;
			/* create new images/objects/sounds */
			for (i=0;i<imgCount;i++) { /*images*/
				imgArray[imgsActive].img=resLoad(img[i].res);
				if (!imgArray[imgsActive].img) {
slPrint("resource coudn't be loaded.                                     ",slLocate(2,22));
/*					fprintf(stderr,"resource coudn't be loaded.");*/
					return menuQuit;
				}
				imgArray[imgsActive].y=img[i].y;
				imgArray[imgsActive].x=img[i].x;
				imgArray[imgsActive].layer=img[i].layer;
				imgArray[imgsActive].duration=img[i].duration;
				imgsActive++;
			}

#if 0
			for (i=0;i<objCount;i++) { /*objects*/
				objArray[objsActive].obj=objectCreate(obj[i].location,obj[i].floor,DIR_LEFT,obj[i].state,obj[i].res,obj[i].cacheMirror,oGeneric);
				objArray[objsActive].active=1;
				objArray[objsActive].duration=obj[i].duration;
				objsActive++;
			}
#endif
/*		TODO: code sounds	
 *		for (i=0;i<sndCount;i++) {
				sndArray[sndsActive]=snd[i];
				sndsActive++;
			}*/

			outputClearScreen();
			/* The bottom layer */
			for (i=0;i<imgsActive;i++) {
				if (imgArray[i].layer==ANIMS_LAYERTYPE_BOTTOM)
				{
/*					slPrint("ANIMS_LAYERTYPE_BOTTOM                                     ",slLocate(2,10));*/
					outputDrawBitmap(imgArray[i].img->pFrames[0], imgArray[i].x, imgArray[i].y);
				}
			}
#if 1			
			/* move objects */
			for (i=0;i<objsActive;i++) {
				/*TODO: detect exits */
				if (objArray[i].active) {
					int exitCode;
		  		exitCode=objectMove(&(objArray[i].obj),nullKey,NULL);
					if (objArray[i].duration) objArray[i].duration--;

					/* detect exited states and destroy them */

					/* if the time is over or exit code detected */
					if ((objArray[i].duration==1)||(exitCode<0)) {
						/*printf("exit Code detected: i=%d exit=%d \n",i,exitCode);*/
						objectFree(&objArray[i].obj);
						objArray[i].active=0; /* remember it is destroyed */
					} else {
		  			objectDraw(&objArray[i].obj); 
					}
				}
			}
			
			/* The top layer */
			for (i=0;i<imgsActive;i++) {
				if (imgArray[i].layer==ANIMS_LAYERTYPE_TOP) {
/*					slPrint("ANIMS_LAYERTYPE_TOP                                     ",slLocate(2,10));*/
					outputDrawBitmap(imgArray[i].img->pFrames[0], imgArray[i].x, imgArray[i].y);
				}
			}
#endif
			outputUpdateScreen();

			/* caducied backgrounds destruction */
			i=imgsActive;
			while(i) {
				i--;
				if (imgArray[i].duration) { /* if not 0 (infinite) */
					imgArray[i].duration--;
					if (!imgArray[i].duration) { /* time is over for this images */
						imgsActive--;
						resFree(imgArray[i].img);
						imgArray[i]=imgArray[imgsActive];
					}
				}
			}	}
		}
	}

	for (i=0;i<objsActive;i++) if (objArray[i].active) objectFree(&objArray[i].obj);
	for (i=0;i<imgsActive;i++) resFree(imgArray[i].img);
	free(objArray);
	free(imgArray);
	/*free(sndArray);*/
	return menuQuit;
}

tMenuOption showTitles() {
/* Show the titles animation
 * returns 0 if the user has finished the animations with quit
 * returns 1 if the user has selected to load a saved game 
 * returns 2 if the user has selected to start the game
 */
	return playAnimation(ANIMS_ID_PRESENTATION);
}	

