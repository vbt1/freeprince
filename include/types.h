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
types.h: FreePrince : Kernel types
¯¯¯¯¯¯¯¯
 Copyright 2004 Princed Development Team
  Created: 23 Aug 2004

  Author:  Enrique Calot <ecalot.cod@princed.com.ar>
  Dev Cpp port: Hélder Maurício Gomes Ferreira Filho

 Note:
  DO NOT remove this copyright notice
*/

#ifndef _PR_TYPES_H_
#define _PR_TYPES_H_

#include "resources.h"

typedef unsigned char tRoomId;
typedef unsigned char tTileId;
typedef unsigned char tModId;

typedef enum {eOpenTimer,eOpen,eClose,eClosing,eOpening,eClosingFast}tGateAction;
typedef enum {eJustPressed,eNormal,ePressed,eStuck}tPressableAction;
typedef enum {eNormalGate,eExitGate}tGateType;
typedef enum {eDrop,eRaise}tPressableType;

typedef struct { /* The state object: only struct that is not static to the state class */
	short  frame; /* when zero, animation is released and the next state is taken */
	short* animation; /* list of frames for this state */
	short* animOffset; /* position of those frames */
	short* flags;      /* actions to be performed by each frame (make sound, press floor, etc) */
	short* steps;      /* the number of steps each frame has to move */
	short* offsx;      /* the height the images has to be raised */
	short  currentState; /* the Id of the state the object is */
	short  imgoffx;    /* the height the current image has to be raised */
	short  image; /* the next image to be shown */
	float  step; /* the number of pixels a frame has to move */
	int    mirror; /* the image has to be inverted */
	float  acumLocation; /* the kid location in float (will be casted to int in the kid object) */
} tState;

typedef struct {
	int time;
	int frame;
	tGateType type;
	tGateAction action;
} tGate;

typedef struct {
	tGate* gate;
	int triggerNext;
} tEvent;

typedef struct {
	tEvent* event;
	tPressableType type;
	tPressableAction action;
} tPressable;

typedef struct {
	int frame;
	enum {eChoActive,eChoInactive,eSpiUp,eSpiWaitUp,eSpiDown,eSpiStuck,eLosNormal,eLosMoving,eLosDown} action;
	union {
		int time;
		unsigned char back;
	} more;
	short pos;
} tDanger;

typedef struct node {
	int            screen;
	int            x,y;
	int            speed;
	struct node*   next;
}tFlying;
	
typedef struct {
	tRoomId        links[ 4*24];
	unsigned char  fore [24*30];
	unsigned char  back [24*30];
	
	tGate**        screenGates[24];
	tGate*         gates;
	int            totalGates;
	
	tPressable**   screenPressables[24];
	tPressable*    pressables;
	int            totalPressables;
	
	tDanger**      screenDangers[24];
	tDanger*       dangers;
	int            totalDangers;
	
	tEvent         events[256];
	int            time;
	unsigned char  start[3];
	unsigned char  levelNumber;

	tFlying*       flyingObjects;
	int            refresh;
} tMap;

typedef struct {
	tMap*          level;
	tRoomId        id;
	tRoomId        links[4];
	tRoomId        corners[4];
	unsigned char  fore [60];	
	unsigned char  back [60];
	/* TODO: add guards */
} tRoom;

typedef struct {
	/* Graphical arributes */
	void* moreInfo;

	tModId back;
	unsigned char code;
} tTile;

typedef	enum {oGeneric,oKid,oGuard,oTorch,oFallingTile} tObjectType;

typedef struct {
	int location;
	int floor;
	int direction;
	tData* gfxCache[2];
	tState action;
	tObjectType type;
	int hitPoints;
	int lives;
} tObject;

typedef enum {eLeft=0,eRight=1,eUp=2,eDown=3}tDirection;

#endif
