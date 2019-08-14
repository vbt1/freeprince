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

# anims_conf.awk: FreePrince : walls.conf parser
# ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
# Copyright 2005 Princed Development Team
#  Created: 5 Jan 2005
#
#  Author: Enrique Calot <ecalot.cod@princed.com.ar>
#
# Note:
#  DO NOT remove this copyright notice
#

BEGIN {
}

###########################
# PART 1                  #
# Parse input into memory #
###########################

#animation cathegories
/^[\t ]*ANIMATION[\t ]/ {
	$2=toupper($2)
	animcount++
	animation["name" animcount]=$2
	animation["size" animcount]=$3
	animation["startf" animcount]=totalimage
	animation["startt" animcount]=totalobject
	animation["starto" animcount]=totalsound
}

#tables
#static images
/^[\t ]*[0-9]+[\t ]+IMAGE[\t ]/ {
	totalimage++
	f["frame" totalimage]=$1/1
	f["res" totalimage]=toupper($3)
	if (toupper($4)=="INFINITE") $4=0
	f["duration" totalimage]=$4/1
	f["layer" totalimage]=toupper($5)
	if (tolower($6)=="right") $6=320 #here will be the screen width size
	if (tolower($6)=="left") $6=0
	f["x" totalimage]=$6/1
	if (tolower($7)=="bottom") $7=200 #here will be the screen height size
	if (tolower($7)=="top") $7=0
	f["y" totalimage]=$7/1
	animation["sizef" animcount]++
}

#objects
/^[\t ]*[0-9]+[\t ]+OBJECT[\t ]/ {
	totalobject++
	$4=tolower($4)
	$7=tolower($7)
	$8=tolower($8)
	
	t["frame" totalobject]=$1/1
	t["res" totalobject]=toupper($3)
	if ($4=="infinite") $4=0
	if ($4=="untilexit") $4=0
	t["duration" totalobject]=$4/1
	t["object" totalobject]=toupper($5)
	t["location" totalobject]=$6/1
	if ($7=="up") $7=1
	if ($7=="middle") $7=2
	if ($7=="center") $7=2
	if ($7=="centre") $7=2
	if ($7=="down") $7=3
	t["floor" totalobject]=$7/1
	if ($8=="no") $8=0
	if ($8=="yes") $8=1
	if ($8=="mirror") $8=1
	t["cacheMirror" totalobject]=$8/1
	animation["sizet" animcount]++
}

#sounds
/^[\t ]*[0-9]+[\t ]+(MIDI|WAV|SPEAKER)[\t ]/ {
	totalsound++
	o["frame" totalsound]=$1/1
	o["res" totalsound]=toupper($3)
	o["type" totalsound]=tolower($2)
	animation["sizeo" animcount]++
}

##########################
# PART 2                 #
# Generate output        #
##########################

END {
	#avoid empty records
	if (!totalimage) {
		printf("Semantic error in anims.conf: At least one IMAGE is needed.\n")>"/dev/stderr"
		exit 30
	}
	if (!totalobject) {
		printf("Semantic error in anims.conf: At least one OBJECT is needed.\n")>"/dev/stderr"
		exit 31
	}
	if (!totalsound) {
		printf("Semantic error in anims.conf: At least one SOUND is needed.\n")>"/dev/stderr"
		exit 32
	}

	#static defines
	printf("#define ANIMS_LAYERTYPE_TOP     0\n")
	printf("#define ANIMS_LAYERTYPE_BOTTOM  1\n")
	printf("\n")
	
	#output image table
	coma=""
	printf("#define ANIMS_IMAGE {")
	for (i=1;i<=totalimage;i++) {
		printf("%s\\\n\t{/*frame*/ %d,/*res*/ (unsigned long)(RES_%s), /*duration*/ %d, /*layer*/ (unsigned char)ANIMS_LAYERTYPE_%s, /*x,y*/ (unsigned short)%d,(unsigned short)%d}",coma,f["frame" i],f["res" i],f["duration" i],f["layer" i],f["x" i],f["y" i])
		coma=","
	}
	printf("\\\n}\n\n")

	#output object mark table
	coma=""
	printf("#define ANIMS_OBJECT {")
	for (i=1;i<=totalobject;i++) {
		printf("%s\\\n\t{/*frame*/ %d, /*res*/ (unsigned long)(RES_%s), /*duration*/ %d, /*object*/ STATE_MARKS_%s, /*loc*/ %d, /*floor*/%d, /*mirror*/ %d}",coma,t["frame" i],t["res" i],t["duration" i],t["object" i],t["location" i],t["floor" i],t["cacheMirror" i])
		coma=","
	}
	printf("\\\n}\n\n")
	
	#output sound table
	coma=""
	printf("#define ANIMS_SOUND {")
	for (i=1;i<=totalsound;i++) {
		printf("%s\\\n\t{/*frame*/ %d,/*res*/ (unsigned long)RES_%s, /*type*/ anims_enum_%s}",coma,o["frame" i],o["res" i],o["type" i])
		coma=","
	}
	printf("\\\n}\n\n")
	
	#the index table
	coma=""
	printf("#define ANIMS_TABLE {")
	for (i=1;i<=animcount;i++) {
		printf("%s\\\n\t{/*image*/ %d,%d, /*object*/ %d,%d, /*sound*/ %d,%d, /*animsize*/ %d}",coma,animation["startf" i],animation["sizef" i],animation["startt" i],animation["sizet" i],animation["starto" i],animation["sizeo" i],animation["size" i])
		coma=","
	}
	printf("\\\n}\n\n")

	#finally write the animation ids
	for (i=1;i<=animcount;i++) {
		printf("#define ANIMS_ID_%s %d\n",animation["name" i],i-1)
	}
}

