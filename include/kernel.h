
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
kernel.h: Princed Resources : Resource Handler headers
¯¯¯¯¯¯¯¯
 Copyright 2003 Princed Development Team
  Created: 16 Jun 2004

  Author: Diego Essaya <dessaya.cod@princed.com.ar>

 Note:
  DO NOT remove this copyright notice
*/

#ifndef _PR_KERNEL_H_
#define _PR_KERNEL_H_

/* Flags */
#define megahit_flag     0x0001
#define menu_flag        0x0002
#define help_flag        0x0004
#define version_flag     0x0008

#define hasFlag(a) (optionflag&(a))
#define setFlag(a) optionflag|=(a)

#define FP_VERSION "0.4-pre-alpha-rata"

int kernel(int optionflag,int level);
/* level=-1 is default
 * levels from 0 to n is the level number
 *  
 * optionflag may be read using hasFlag(name_flag); Note that the variable must be called optionflag
 */

#endif

