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
memory.h: Princed Resources : Memory handling headers
¯¯¯¯¯¯¯¯
 Copyright 2003 Princed Development Team
  Created: 20 Dec 2003

  Author: Enrique Calot <ecalot.cod@princed.com.ar>
  Version: 1.01 (2004-Feb-13)

 Note:
  DO NOT remove this copyright notice
*/

#ifndef _PR_MEMORY_H_
#define _PR_MEMORY_H_

/* #define MEM_CHECK */

#include <stdlib.h>
#define getMemory(size) ((unsigned char*)malloc(size))
char* strallocandcopy(const char* text);
#define freeAllocation(m) if ((m)!=NULL) free(m)

#ifdef MEM_CHECK
void myfree(void* a,char* fileName,int line);
void* mymalloc(int size,char* fileName,int line);
void showStats();
#else
#define showInfo(a)
#endif

#endif

