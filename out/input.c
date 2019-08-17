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
input.c: FreePrince : Input interface
¯¯¯¯¯¯¯¯
 Copyright 2004 Princed Development Team
  Created: 19 Jun 2004

  Authores: Diego Essaya <dessaya.cod@princed.com.ar>
	          Enrique Calot <ecalot.cod@princed.com.ar>

 Note:
  DO NOT remove this copyright notice
*/

#include <SDL/SDL.h>
#include "input.h"
#include "common.h"
#include <stdio.h> /* only for the printf debug */

tKey inputCreateKey() {
	tKey key;
/*	inputSetshift(key->status,0);
	inputSetcontrol(key->status,0);
	inputSetup(key->status,0);
	inputSetleft(key->status,0);
	inputSetright(key->status,0);*/
	key.status=0;
	key.actionPerformed=none;
	return key;
}

int editAction(tKey* key,SDLKey k) {
	key->actionPerformed=other;

if(k==108) /* vbt : petit hack en attendant mieux */
key->status=2;

	/* Control actions */
	if (inputGetCtrl(key->status)) {
	slPrint("inputGetCtrl(yes)                                     ",slLocate(2,4));
		switch (k) {
		case SDLK_g:
			key->actionPerformed=save;
			break;
		case SDLK_j:
			key->actionPerformed=joystick;
			break;
		case SDLK_k:
			key->actionPerformed=keyboard;
			break;
		case SDLK_a:
			key->actionPerformed=reload;
			break;
		case SDLK_l:
			key->actionPerformed=load;
			break;
		case SDLK_q:	
			key->actionPerformed=quit;
			break;
		case SDLK_r:	
			key->actionPerformed=gotoTitles;
			break;
		case SDLK_v:	
			key->actionPerformed=showVersion;
			break;
		default:
			break;
		}
	}
	else
	{
	slPrint("inputGetCtrl(no)                                     ",slLocate(2,4));
	}

	/* Shift actions */
	if (inputGetShift(key->status)) {
		switch (k) {
		case SDLK_c:
			key->actionPerformed=showMoreScreens;
			break;
		case SDLK_w:
			key->actionPerformed=featherWeight;
			break;
		case SDLK_t:
			key->actionPerformed=addLive;
			break;
		case SDLK_s:
			key->actionPerformed=addHitPoint;
			break;
		case SDLK_i:
			key->actionPerformed=invert;
			break;
		case SDLK_b:
			key->actionPerformed=blind;
			break;
		case SDLK_l:
			key->actionPerformed=passLevel;
			break;
		case SDLK_PLUS:
		case SDLK_KP_PLUS:
			key->actionPerformed=addTime;
			break;
		case SDLK_LESS:
		case SDLK_KP_MINUS:
			key->actionPerformed=takeTime;
			break;
		default:
			key->actionPerformed=buttonPressed;
			break;
		}
	}
	/* Normal actions */
	if (!(key->status)) {
		switch (k) {
		case SDLK_ESCAPE:
			key->actionPerformed=pause;
			break;
		case SDLK_RETURN:
			key->actionPerformed=buttonPressed;
			break;
		case SDLK_r:
			key->actionPerformed=resurrect;
			break;
		case SDLK_k:
			key->actionPerformed=kill;
			break;
		case SDLK_u:
			key->actionPerformed=showUp;
			break;
		case SDLK_h:	
			key->actionPerformed=showLeft;
			break;
		case SDLK_n:	
			key->actionPerformed=showDown;
			break;
		case SDLK_j:	
			key->actionPerformed=showRight;
			break;
		case SDLK_SPACE:	
			key->actionPerformed=showTime;
			break;
		case SDLK_c:	
			key->actionPerformed=showScreens;
			break;
		default:
			break;
		}
	}
	return key->actionPerformed;
}

int editKey(tKey* key, SDLKey sdlkey, int status) {
	switch (sdlkey) {
		/* keys */
		case SDLK_UP:
			inputSetUp(key->status,status);
			inputSetDown(key->status,0);
			break;
		case SDLK_DOWN:
			inputSetDown(key->status,status);
			inputSetUp(key->status,0);
			break;					
		case SDLK_RIGHT:
			inputSetRight(key->status,status);
			inputSetLeft(key->status,0);
			break;					
		case SDLK_LEFT:
			inputSetLeft(key->status,status);
			inputSetRight(key->status,0);
			break;					
		case SDLK_HOME:
			inputSetUp(key->status,status);
			inputSetLeft(key->status,status);
			inputSetRight(key->status,0);
			break;					
		case SDLK_END:
			inputSetDown(key->status,status);
			inputSetLeft(key->status,status);
			inputSetRight(key->status,0);
			break;					
		case SDLK_PAGEUP:
			inputSetUp(key->status,status);
			inputSetLeft(key->status,0);
			inputSetRight(key->status,status);
			break;					
		case SDLK_PAGEDOWN:
			inputSetDown(key->status,status);
			inputSetLeft(key->status,0);
			inputSetRight(key->status,status);
			break;					
		/* mods*/
		case SDLK_RSHIFT:
		case SDLK_LSHIFT:
			inputSetShift(key->status,status);
			break;					
		case SDLK_RCTRL:
		case SDLK_LCTRL:
			inputSetCtrl(key->status,status);
			break;
		default:
			return 0;
	}
	return 1;
}

int inputGetEvent(tKey* key) {
	SDL_Event event;
char toto[50];
	
	while(SDL_WaitEvent(&event))
	{
		key->actionPerformed=none;
		switch (event.type) {
		case SDL_KEYDOWN:
			editKey(key,event.key.keysym.sym,1);

			if (editAction(key,event.key.keysym.sym)) return 0;
			break;
		case SDL_KEYUP:
			editKey(key,event.key.keysym.sym,0);
			break;
#ifdef DEBUG_POS
		case SDL_MOUSEBUTTONDOWN:
			printf("button pressed (%d,%d)\n",event.button.x,event.button.y);
			break;
		case SDL_MOUSEBUTTONUP:
			printf("button released (%d,%d)\n",event.button.x,event.button.y);
			break;
#endif
		case SDL_USEREVENT:
			return 1; /* A new time cicle has started! */
		case SDL_QUIT:
			key->actionPerformed=quit;
			return 0;
		}
	}
	printf("inputGetEvent: unreachable code\n");
	return 0;	
}

static SDL_TimerID timer;
int timerValue=0;
Uint32 timer_callback(Uint32 interval, void *param)
{
	if(timerValue==5)
	{
		SDL_Event event;

		/* Push a user-defined event on the event queue: */
		event.type = SDL_USEREVENT;
		event.user.code = 0;
		event.user.data1 = NULL;
		event.user.data2 = NULL;
		SDL_PushEvent(&event);
		timerValue=0;
	}
	timerValue++;
	return interval; /* Timer must raise an alarm again after 'interval' ms. */
}

#ifdef DEBUG_POS
void inputDebugSetTimer(int fps) {
	inputStopTimer();
	timer=SDL_AddTimer(fps, timer_callback, NULL);
}
#endif

void inputInitTimer()
{
	timer=SDL_AddTimer(83, timer_callback, NULL);
}

void inputStopTimer()
{
	SDL_RemoveTimer(timer);
}


int inputDelay(tKey* key,int ticks) {
	while(ticks&&inputGetEvent(key)) {
		ticks--;
	}
	return ticks;
}

void inputPause() {
	tKey key=inputCreateKey();
	while (1)
		if (!inputGetEvent(&key)) return;
}

