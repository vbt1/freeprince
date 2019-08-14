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
kernel.c: FreePrince : Main Kernel
¯¯¯¯¯¯¯¯
 Copyright 2004 Princed Development Team
  Created: 16 Jun 2004

  Authores: Diego Essaya <dessaya.cod@princed.com.ar>
            Enrique Calot <ecalot.cod@princed.com.ar>

 Note:
  DO NOT remove this copyright notice
*/

#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "kernel.h"
#include "maps.h"
#include "object.h"
#include "kid.h"
#include "output.h"
#include "resources.h"
#include "room.h"
#include "states.h" /* stateKidInLevel */
#include "titles.h"
#include "common.h"

/*
 * Main game control function
 */

tObject kid;

int playgame(int optionflag,int level) {
	/* Create objects */
	tKey    key;
	tData*  resMap;
	tMap*   map;
	tRoom   room;
	tRoomId roomId;
	int notReset;
	int flags;
	int timeDead;
	
	while (1) {	
		/* Initialize */
		key=inputCreateKey();
		resMap=resLoad(RES_MAP|level);
		map=(tMap*)resMap->pFrames;
		notReset=1;
		flags=0;
		timeDead=0;
		
		/*TODO: use a map.c function that reads this information and creates the kid*/
		kid=objectCreate(30,1,DIR_RIGHT,stateKidInLevel(level),RES_IMG_ALL_KID,1,oKid);
		outputDrawMessage(24,"LEVEL %d",level);
		
		/* Game loop here */
		
		/* Initialize kid and room in the map */
		mapStart(map,&kid,&roomId,level);
		room=mapGetRoom(map,roomId);
		
		/* Level loop here */
		while (notReset) {
			if (inputGetEvent(&key)) {
				/* Time event */
	
				/* Moving objects */
				/* keylogIntercept(&key);
				 * TODO: send to the real place where
				 * the key is interpreted in kid object
				 */
				flags=objectMove(&kid,key,&room);
				if (mapMove(map)) room=mapGetRoom(map,room.id);
				/* Drawing functions */
				outputClearScreen(); /* TODO: send to drawBackground() */
				roomDrawBackground(&room);
				kidDrawLives(&kid);
				objectDraw(&kid);
				roomDrawForeground(&room);
				/* if dead */
				if (flags&STATES_FLAG_X) {
					timeDead++;	
					kidKillHim(&kid);
				}
				/* hardcoded blinking message */
				if (timeDead==20) outputDrawMessage(120,"Press Button to Continue");
				if (timeDead==160) outputDrawMessage(10,"Press Button to Continue");
				if (timeDead==180) outputDrawMessage(10,"Press Button to Continue");
				if (timeDead==200) outputDrawMessage(10,"Press Button to Continue");
				if (timeDead==210) {
					resFree(resMap);
					return 0;
				}
				outputUpdateScreen();
			} else {
				/* Action event */
				switch (key.actionPerformed) {
				case quit:
					resFree(resMap);
					return 1;
				case gotoTitles:
					resFree(resMap);
					return 0;
				case showUp:
					if ((roomId=room.links[eUp])) {
						room=mapGetRoom(map,roomId);
						printf("Kernel/playgame: cheat: Looking up\n");
					}
					break;
				case showLeft:
					if ((roomId=room.links[eLeft]))
						room=mapGetRoom(map,roomId);
					break;
				case showDown:
					if ((roomId=room.links[eDown]))
						room=mapGetRoom(map,roomId);
					break;
				case showRight:
					if ((roomId=room.links[eRight]))
						room=mapGetRoom(map,roomId);
					break;
				case passLevel:
					resFree(resMap);
					level++;
					level%=16;
					notReset=0;
					break;
				case buttonPressed:
					if (!(flags&STATES_FLAG_X))
						break; /* break if not dead */
				case reload:
					notReset=0;
					break;
				case addLive:
					kidGetLife(&kid);
					break;
				case addHitPoint:
					kidGetHitPoint(&kid);
					break;
				case showVersion:
					outputDrawMessage(24,"FreePrince v"FP_VERSION"\n");
					break;
				case showScreens:
					outputDrawMessage(24,"S%d L%d R%d A%d B%d\n",
						room.id,
						room.links[eLeft],
						room.links[eRight],
						room.links[eUp],
						room.links[eDown]
					);
					break;
				case pause:
					/* using to turn to interactive debug mode if compuled with the flag */
#ifdef DEBUG_POS
					inputDebugSetTimer(500);
#endif
					break;
				case showMoreScreens:
					outputDrawMessage(24,"S%d AL%d AR%d BL%d BR%d\n",
						room.id,
						room.corners[0],
						room.corners[1],
						room.corners[2],
						room.corners[3]
					);
					break;
				default:
					break;
				}
			}
		}
	}
	return 0;
}

/*
 * Main function
 */


int kernel(int optionflag,int level) {
/* levels=-1 is default
 * levels from 0 to n is the level number
 *  
 * optionflag may be read using hasFlag(name_flag); Note that the variable
 * must be called optionflag
 */
	int menuOption;
	int quit=0;
	if (outputInit()) {
/*	SYS_Exit(0);*/
/*		fprintf(stderr, "Unable to initialize screen\n");*/
while(1);
/*		exit(1);*/
	}
	inputInitTimer();

	/*
	 * Start main menu loop (story and titles)
	 */
	do {
		if (level==-1) {
			menuOption=showTitles();

			switch (menuOption) {
				case menuLoad:
					level=8; /* TODO: make read level function */
					break;
				case menuStart:
					level=1;
					break;
				case menuQuit:
					quit=1;
					break;
			}
/*			slSynch();*/
		}
		if (!quit) {
			quit=playgame(optionflag,level);
			level = -1;
		}
	} while(!quit);

	objectFree(&kid); /*TODO: exiting from the story will cause a game crash because this object wasn't allocated */
	inputStopTimer();
	outputStop();
	return 0;
}

