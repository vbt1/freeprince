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
main.h: Princed Resources : Main function and parser headers
¯¯¯¯¯¯
 Copyright 2003, 2004 Princed Development Team
  Created: 16 Jun 2004

  Author: Enrique Calot <ecalot.cod@princed.com.ar>

 Note:
  DO NOT remove this copyright notice
*/

#ifndef _PR_MAIN_H_
#define _PR_MAIN_H_

/***************************************************************\
|                   Command Line specific options               |
\***************************************************************/

#define PARSING_OPTIONS {\
{"menu",        no_argument,       0,'m'},\
{"megahit",     no_argument,       0,'t'},\
{"version",     no_argument,       0,1},\
{"help",        no_argument,       0,'?'},\
{"level",   required_argument,     0,'l'},\
{0, 0, 0, 0}\
}
/*
{"export",      optional_argument, 0,'x'},\
{"backup",      optional_argument, 0,'b'},\
{"force",       no_argument,       0,'f'},\
{"cgi",         no_argument,       0,'g'},\
{"resource",    required_argument, 0,'s'}\
{"recursive",   no_argument,       0,'R'},\
{"datfile",     required_argument, 0,'t'},\
{"unknown",     no_argument,       0,2},\
{"verbose",     no_argument,       0,'v'},\
*/

#define PARSING_CHARS    "mtl::?"

#endif

