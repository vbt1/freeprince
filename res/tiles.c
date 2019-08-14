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
tiles.c: FreePrince : Tile functions
¯¯¯¯¯¯¯
 Copyright 2004 Princed Development Team
  Created: 19 Oct 2004

  Author: Enrique Calot <ecalot.cod@princed.com.ar>

 Note:
  DO NOT remove this copyright notice
*/

#include "tiles.h"
#include <stdio.h> /* NULL */

int evaluate(tTile tile,int type) { /* type is the number in the modifier */
	if (!tile.moreInfo) {
		slPrint("Runtime Error: trying to use a tile that hasn't extra information            ",slLocate(2,21));
/*		fprintf(stderr,"Runtime Error: trying to use a tile that hasn't extra information\n");*/
		return 0;
	}
	TILES_MACROS_CASE(type,tile)
}

int isIn(tTile tile,short group) {
	static unsigned char tileList[]=TILE_GROUP_LIST;
	unsigned char* i;

	tile.code=tile.code&0x1F; /* get the last 5 bits and clear the beginning */
	if (group<32) return (tile.code==group);
	i=tileList+(group-32);
	tile.code++;

	while (*i) {
		if ((*i)&0x80) { /* compare against the back */
			if (((*(i++))&0x3f)==tile.code) 
				if (*i==tile.back) return 1;
		} else if ((*i)&0x40) { /* compare against the function */
			if (((*(i++))&0x3f)==tile.code) 
				if (evaluate(tile,*i)) return 1;
		} else { /* compare the simple tile */
			if (((*i)&0x3f)==tile.code) return 1;
		}
		i++;
	} 
	return 0; /* returns 1 if true and zero if false */
}

int isInGroup(unsigned char fore,unsigned char back,short group) {
	tTile t;
	t.code=fore;
	t.back=back;
	t.moreInfo=NULL;
	return isIn(t,group);
}

