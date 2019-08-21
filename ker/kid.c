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
kid.c: Free Prince : Kid object
¯¯¯¯¯
 Copyright 2004 Princed Development Team
  Created: 19 Jul 2004

  Author: Enrique Calot <ecalot.cod@princed.com.ar>

 Note:
  DO NOT remove this copyright notice
*/

#include "kid.h"
#include "room.h"
#include <stdio.h> /* DEBUG printf */
#include "states.h"
#include "common.h"
#include "output.h" /* outputDrawBitmap */
#include "maps.h" /* mapGetRoom */

/* Live stuff */
#define KID_LIVE_FILL 216
#define KID_LIVE_EMPTY 217

void kidDrawLives(tObject *kid) {
	int i;
	static int blink=0;
	blink=!blink;
	for (i=0;i<kid->lives;i++){
		register int res=((i<kid->hitPoints)&&!((kid->hitPoints==1)&&(blink)))?
			KID_LIVE_FILL:KID_LIVE_EMPTY;
		
		outputDrawBitmap(NULL,kid->gfxCache[1]->pFrames[res],2+8*i,11+3*TILE_H);

	}
}

void kidGetLife(tObject *kid) {
	kid->hitPoints=++kid->lives;
}

void kidGetHitPoint(tObject *kid) {
	if (kid->hitPoints<kid->lives)
		kid->hitPoints++;
}

int kidTakeHitPoint(tObject *kid) {
	/* Returns 0 if death or the number of remaining hit points if not */
	return --kid->hitPoints;
}				

void kidKillHim(tObject *kid) {
	/* Returns 0 if death or the number of remaining hit points if not */
	kid->hitPoints=0;
}				

int kidDrinkPotion(tObject* kid,tTile tile) {
	/* returns 0 if died */
	if (isIn(tile,TILE_SWORD)) {
	} else if (isIn(tile,TILES_HITPOINT)) {
		kidGetHitPoint(kid);
		outputBlinkScreen(2,1);
	} else if (isIn(tile,TILES_LIFE)) {
		kidGetLife(kid);
		outputBlinkScreen(2,1);
	} else if (isIn(tile,TILES_POISON)) {
		return kidTakeHitPoint(kid);
	}
	return 1;	
}

/* Room stuff */
				
int kidVerifyRoom(tObject *kid,tRoom *room,int refresh) {
	/* if the kid is out of the screen we need to change the screen and put
	 * the kid back again on it
	 * PRE: tObject *kid is a kid
	 */
	
	/* The kid is down */
	if (kid->floor==3) {
		kid->floor=0;
		*room=mapGetRoom(room->level,room->links[eDown]);
		refresh=0;
	}
	
	/* The kid is up */
	if (kid->floor==-1) {
		kid->floor=2;
		*room=mapGetRoom(room->level,room->links[eUp]);
		refresh=0;
	}

	/* The kid is left */
	if (kid->location<0) {
		kid->location+=TILE_W*10;
		refresh=0;
		*room=mapGetRoom(room->level,room->links[eLeft]);
		roomKidChangedFloor(room,kid);
	}

	/* The kid is right */
	if (kid->location>TILE_W*10) {
		kid->location-=TILE_W*10;
		refresh=0;
		*room=mapGetRoom(room->level,room->links[eRight]);
		roomKidChangedFloor(room,kid);
	}

	return refresh;
}
	
int kidMove(tObject* kid,short flags,tRoom* room) {
	int refresh=0;
	
/*	x=object_getLocation(*kid,kid->gfxCache[kid->direction]->pFrames[stateGetImage(*kid)-1])/TILE_W;*/
	
	if (flags&STATES_FLAG_P)
		refresh=roomPress(room,kid);
	if (flags&STATES_FLAG_F) {
		kid->floor++;
		roomKidChangedFloor(room,kid);
	}
	if (flags&STATES_FLAG_U) {
		kid->floor--;
		roomKidChangedFloor(room,kid);
	}
	return kidVerifyRoom(kid,room,refresh);
}

