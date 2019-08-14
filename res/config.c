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
config.c: Free Prince : Configuration Handler
¯¯¯¯¯¯¯¯
 Copyright 2003,2004 Princed Development Team
  Created: 24 Jun 2004

  Author: Enrique Calot <ecalot.cod@princed.com.ar>

 Note:
  DO NOT remove this copyright notice
*/

#include <string.h> /* memcpy */
#include <stdlib.h> /* free/malloc */
#include "config.h"
#include "dat.h"
#include "freeprince.h"
#include "resources.h"

static tMemory options[CONFIG_MAX_ITEMS];

int configInit() {
	int id;
	/*unsigned char* aux;*/
					
	for (id=0;id<CONFIG_MAX_ITEMS;id++) {
		options[id].size=-1;
		options[id].array=NULL;
	}
#if 0
	/* READ INDEX */
	if (!mReadBeginDatFile((unsigned short int *)&id,FP_CONFIG_FILE)) return -1;
	for (id=0;id<DATA_END_ITEMS;id++) {
		if (res_getDataById(id,DATA_END_ITEMS,options+id)) {
			aux=options[id].array;
			options[id].array=malloc(options[id].size);
			memcpy(options[id].array,aux,options[id].size);
		} else {
			return -3;
		}
	}
#endif
	mReadCloseDatFile();
	return 0;
}

void configStop() {
	/*use CONFIG_FILE from freeprince.h*/
	int i;

	for (i=0;i<CONFIG_MAX_ITEMS;i++) {
		if (options[i].array) free(options[i].array);
	}
}

void configSet(int id, void* data,int size) {
	if (options[id].array) free(options[id].array);
	options[id].array=(void*)malloc(size);
	memcpy(options[id].array,data,size);
	options[id].size=size;
}

void* configGet(int id) {
	return (void*)options[id].array;
}

void* configGetArray(int id,int *size) {
	*size=options[id].size;
	return options[id].array;
}

void configSync() {

}


