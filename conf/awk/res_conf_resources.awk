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

# res_conf_resources.awk: FreePrince : resources.conf parser
# ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
# Copyright 2004, 2003 Princed Development Team
#  Created: 15 Oct 2004
#
#  Author: Enrique Calot <ecalot.cod@princed.com.ar>
#
# Note:
#  DO NOT remove this copyright notice
#

BEGIN {
	res=0
	coma=""
	filelist=""
	items=0
}

/^([ ]*[^# ].*)$/ {
	oldres=res
	if (substr($2,1,2)=="OF") {
		if ((items!=0)&&(NF!=items)) {
			print "ERROR: item numbers do not match between different OFFSETs\n"
			exit -1;
		}
		if (items==0) items=NF
		if (offsets!="") offsets=( offsets "|" )
		offsets=( offsets "RES_MODS_HAS_" substr($2,3,1) )
		inc=3
		for (i=0;i<=((NF-3)/2);i++) {
			one=$inc
			inc++
			two=$inc
			inc++
			res++
			filelist=(filelist coma "(unsigned short)" ((two+64)*256+(one+64)) )
			coma=","
		}
	} else {
		for (i=3;i<=NF;i++) {
			if (match($i,/^[A-Z]+(\+[0-9]+)?$/)) {
				filelist=(filelist coma "RES_FILE_" $i)
				res++
			} else if (match($i,/^[0-9]+-[0-9]*$/)) {
				split($i,a,"-")
				for (g=a[1];g<=a[2];g++) {
					filelist=(filelist coma g)
					res++
					coma=","
				}
			} else {
				res++
				filelist=(filelist coma $i)
			}
			coma=","
		}
		if (items==0) {
			extra="";
		} else {
			extra=( "|res_set_part_mods(" offsets ")" )
			offsets=""
		}
		printf "#define RES_%s res_set_part_type(RES_TYPE_%s)|res_set_part_from(%d)|res_set_part_size(%d)%s\n",$1,$2,oldres,res-oldres,extra
		if ((items!=0)&&(res-oldres!=items)) {
			print "ERROR: item numbers do not match between OFFSETs and IMGs\n"
			exit -1;
		}
		items=0
	}
}

END {
	print(" /* define codes */\n#define RES_LIST {" filelist "}\n")
}

