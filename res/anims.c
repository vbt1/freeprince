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
anims.c: FreePrince : Animation handling library implementation
¯¯¯¯¯¯¯¯
 Copyright 2005 Princed Development Team
  Created: 5 Jan 2005

  Author: Enrique Calot <ecalot.cod@princed.com.ar>

 Note:
  DO NOT remove this copyright notice
*/

/* Read the static animation tables and return this information to
 * the player module */

#include "anims.h"

/* private type: table of tables */
typedef struct {
	unsigned short fixedimgStart;
	unsigned short fixedimgSize;
	unsigned short stateStart;
	unsigned short stateSize;
	unsigned short soundStart;
	unsigned short soundSize;
	unsigned short animSize;
} animTable;

static animImage fixedimg[]=ANIMS_IMAGE;
static animObject state[]=ANIMS_OBJECT;
static animSound sound[]=ANIMS_SOUND;
static animTable table[]=ANIMS_TABLE;

static animTable rec;
static int frame;

void animStart(int animId,int *qf,int *qt,int *qo) {
	rec=table[animId];
	frame=0;
	*qf=rec.fixedimgSize;
	*qt=rec.stateSize;
	*qo=rec.soundSize;
}

int animGetFrame(int* qf,int* qt,int* qo, animImage** f,animObject** t, animSound** o) {
	*qf=0;
	*qt=0;
	*qo=0;
	*f=fixedimg+rec.fixedimgStart;
	*t=state+rec.stateStart;
	*o=sound+rec.soundStart;
	while (rec.fixedimgSize&&fixedimg[rec.fixedimgStart].frame==frame) {
		rec.fixedimgSize--;
		rec.fixedimgStart++;
		(*qf)++;
	}
	while (rec.stateSize&&state[rec.stateStart].frame==frame) {
		rec.stateSize--;
		rec.stateStart++;
		(*qt)++;
	}
	while (rec.soundSize&&sound[rec.soundStart].frame==frame) {
		rec.soundSize--;
		rec.soundStart++;
		(*qo)++;
	}
	frame++;

	return frame!=rec.animSize;
}

