#   Princed V3 - Prince of Persia Level Editor for PC Version
#   Copyright (C) 2003 Princed Development Team
#
#   This program is free software; you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation; either version 2 of the License, or
#   (at your option) any later version.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program; if not, write to the Free Software
#   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
#
#   The authors of this program may be contacted at http://forum.princed.com.ar

# room_conf.awk: FreePrince : room.conf parser
# ¯¯¯¯¯¯¯¯¯¯¯¯¯
# Copyright 2005 Princed Development Team
#  Created: 5 Mar 2005
#
#  Author: Enrique Calot <ecalot.cod@princed.com.ar>
#
# Note:
#  DO NOT remove this copyright notice
#

function replace() {
	if (match(value,/[a-z]+[!=]=TILE[A-Z_0-9]+/)) {
		r=RSTART
		l=RLENGTH
		head=substr(value,1,r-1)
		tail=substr(value,r+l)
		middle=substr(value,r,l)
		if (match(middle,/==/)) {	
			r=RSTART
			l=RLENGTH
			val1=substr(middle,1,r-1)
			val2=substr(middle,r+l)
			not=""
		} else {
			match(middle,/!=/)
			r=RSTART
			l=RLENGTH
			val1=substr(middle,1,r-1)
			val2=substr(middle,r+l)
			not="!"
		}
		value=sprintf("%s%sisIn(%s,%s)%s", head, not, val1, val2, tail)
	} else {
		keep=0
	}
}

/^[\t ]*XX .*/ {
	if (inIf) printf("}\n");
	printf("\n#define draw%s(x,y,left,tile,right,dleft) \\\n",$2)
	inIf=0
}

/^[\t ]*cond / {
	if (inIf) printf("}\\\n");
	$1=""
	value=$0
	keep=1
	while (keep) replace()
	printf("if (%s) {\\\n",value)
	inIf=1
}

/^[\t ]*draw/ {
	f=$1
	x=$2
	y=$3
	$1=$2=$3=""
	value=$0
	keep=1
	while (keep) replace()
	comma=","
	if ($0~/^[\t ]*$/) comma=""
	printf("%s((x)+(%s),(y)+(%s)%s%s);\\\n",f,x,y,comma,value);
}

END {
	if (inIf) printf("}\\\n");
	print
}

