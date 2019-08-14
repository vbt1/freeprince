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
config.h: Free Prince : Resource Handler
¯¯¯¯¯¯¯¯
 Copyright 2003,2004 Princed Development Team
  Created: 24 Jun 2004

  Author: Enrique Calot <ecalot.cod@princed.com.ar>

 Note:
  DO NOT remove this copyright notice
*/

#include "conf_ids.h"

int configInit();
/* Only to be called once and from the resource module */
void configStop();
/* Only to be called once and from the resource module */

void configSet(int id, void* data,int size);

#define configSetVar(id,variable) configSet(id,((void*)(&variable)),sizeof(variable))
/* void configSetVar(int id, atomic variable);
 * where atomic may be (signed|unsigned) ((short|long) int|char)|(double) float
 */

#define configSetString(id,string) configSet(id,((void*)(string)),strlen(string)+1)
/* void configSetString(int id, char* string);
 */

#define configSetArray(id,array,size) configSet(id,((void*)(array)),size*sizeof(*array))
/* void configSetArray(int id, atomic* array, int arraySize);
 * where atomic* may be (signed|unsigned) ((short|long) int*|char*)|(double) float*
 */

void* configGet(int id);
#define configGetVar(id,type) *((type*)configGet(id))

void* configGetArray(int id,int* size);

void configSync();
/* Saves the configuration
 */


