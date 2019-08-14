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
input.h: Free Prince : Input devices handling
¯¯¯¯¯¯¯¯
 Copyright 2004 Princed Development Team
  Created: 24 Aug 2003

  Author: name <name.cod@princed.com.ar>

 Note:
  DO NOT remove this copyright notice
*/

#ifndef _PR_KEYLOG_H_
#define _PR_KEYLOG_H_

#include "input.h"


typedef enum {
	none=0,
	recording,
	playing,
}tLogstatus;

typedef struct {
	unsigned char* buffer;
	int            bufferSize;
	int            bufferLocation;
	unsigned char* compressed;
	long           compressedSize;
	tLogstatus     status;
} tKeylog;

/* Kernel key intercept function */
void keylogIntercept(tKeylog* keylog,tKey* key);

/* Recording functions */
int keylogInitRecorging(tKeylog* keylog);
int keylogStopRecording(tKeylog* keylog);

/* Playing functions */
int keylogInitPlaying(tKeylog* keylog,int onStopAction);
int keylogStopPlaying(tKeylog* keylog,int   stopAction);

/* Saving function */
int keylogSave(tKeylog* keylog,const char* file);
int keylogLoad(tKeylog* keylog,const char* file);

/* Contructor/destructor */
tKeylog* keylogCreate();
void     keylogDistroy(tKeylog* keylog);

/* Private functions. TODO: send to keylog.c */
/*void keylog_init    (tKeylog* keylog);
void keylog_distroy (tKeylog* keylog);*/
void keylog_addkey  (tKeylog* keylog,unsigned char key);
void keylog_sync    (tKeylog* keylog);
void keylog_getkey  (tKeylog* keylog);

#endif

