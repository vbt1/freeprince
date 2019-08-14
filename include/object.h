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
kid.h: Free Prince : Generic objects
¯¯¯¯¯
 Copyright 2004 Princed Development Team
  Created: 19 Jul 2004

  Author: Enrique Calot <ecalot.cod@princed.com.ar>

 Note:
  DO NOT remove this copyright notice
*/

#ifndef _PR_OBJECT_H_
#define _PR_OBJECT_H_

#include "resources.h"
#include "input.h"
#include "room.h"

#define DIR_LEFT  1
#define DIR_RIGHT 0

#define object_getLocation(object,image) ((object)->location/*-(outputGetWidth(image)>>1)*/)

#include "types.h"

tObject objectCreate(int location, int floor, int direction, int stateId, unsigned long resId, int cacheMirror, tObjectType type);
void objectDraw(tObject* obj);
int  objectMove(tObject* obj,tKey key,tRoom* room);
void objectInterrupt(tObject* obj,short action);
void objectFree(tObject* obj);

#endif

