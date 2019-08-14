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

# tiles_conf_groups.awk: FreePrince : tiles.conf to tiles_conf_groups.h parser
# ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
# Copyright 2004, 2003 Princed Development Team
#  Created: 19 Oct 2004
#
#  Author: Enrique Calot <ecalot.cod@princed.com.ar>
#
# Note:
#  DO NOT remove this copyright notice
#

/^[ ]*tile .*$/ {
	tile=sprintf("TILE_%s",$2)
}

$0 !~ /^[ ]*(#.*|tile .*|[ ]*)$/ {
	for (i=1;i<=NF;i++) {
		group=$i
		back=0
		info=0
		info2=0
		if (group ~ /@/) {
			split(group,a,"@")
			if (a[2] ~ /^[0-9]+$/) {
				group=a[1]
				back=a[2]+1
			} else if (a[2] ~ /^[A-Z][a-z]+$/) {
				group=a[1]
				info=a[2]
				info2=a[3]
			} else {
				#error
				printf("Parsing error in tiles.conf: Syntax error at %s modifier in line %d.\n",a[1],NR)>"/dev/stderr"
				exit 50
			}
		}
		group=toupper(group)
		if (!total[group]) total[group]=0
		groups[group,total[group]]=tile
		infos[group,total[group]]=info
		info2s[group,total[group]]=info2
		backs[group,total[group]]=back
		total[group]++;
	}
}

END {
	offset=0
	coma=""
	infocount=0
	printf "#define TILE_GROUP_LIST {"
	for (group in total) {
		offsets[group]=offset
		for (i=0;i<total[group];i++) {
			if (backs[group,i]) { #if there is a back selected add them
				printf "%s(unsigned char)(%s+129),%d",coma,groups[group,i],backs[group,i]-1
				offset+=2
			} else if (infos[group,i]) { #if there is info selected add them
				in1=infos[group,i]
				in2=info2s[group,i]
				if (findInfo[in1,in2]) { #if there is another pair of info and info2
				                         #equal, use this number
					result=findInfo[in1,in2]
				} else { #if not, add it
					infocount++
					result=infocount
					arrinfos[result]=in1
					arrinfo2s[result]=in2
					findInfo[in1,in2]=result
				}

				printf "%s(unsigned char)(%s+65),%d",coma,groups[group,i],result
				offset+=2
			} else {
				printf "%s%s+1",coma,groups[group,i]
				offset++
			}
			coma=","
			if (offset%5==0) printf("\\\n")
		}
		printf ",0"
		offset++
		if (offset%5==0) printf("\\\n")
	}
	printf "}\n"
	#add the TILES_* group defines
	for (group in offsets) {
		printf "#define TILES_%s %d\n",group,offsets[group]+32
	}
	#add the TILES_MACRO_?_* macro defines
	printf "\n"
	for (i=1;i<=infocount;i++) {
		printf "#define TILES_MACRO_1_%d(a) ((t%s*)((a).moreInfo))\n",i,arrinfos[i]
		printf "#define TILES_MACRO_2_%d(info) (%s)\n",i,arrinfo2s[i]
		printf "#define TILES_MACRO_x_%d(tile) TILES_MACRO_2_%d(TILES_MACRO_1_%d(tile))\n",i,i,i
	}
	#add the TILES_MACROS_CASE define
	printf "\n"
	printf "#define TILES_MACROS_CASE(type,tile) switch (type) {\\\n"
	for (i=1;i<=infocount;i++) {
		printf "\tcase %d:return TILES_MACRO_x_%d(tile);\\\n",i,i
	}
	printf "\tdefault:return 0;\\\n}\n\n"
}

