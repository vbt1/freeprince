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

# walls_conf.awk: FreePrince : walls.conf parser
# ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
# Copyright 2005 Princed Development Team
#  Created: 1 Jan 2005
#
#  Author: Enrique Calot <ecalot.cod@princed.com.ar>
#
# Note:
#  DO NOT remove this copyright notice
#

BEGIN {
	env=-1
	loc=-1
	print "/* ENV and LOC defines */"
}

##########################
# PART 1                 #
# Parse file into memory #
##########################

#comments
/^[\t ]*#/ {

}

#environtment cathegories
/^[\t ]*WALL[\t ]/ {
	$2=toupper($2)
	$3=toupper($3)
	currentenvironment=$2
	currentlocation=$3
	currenttable=""
	total=0
	if ($2 && !environments[$2]) {
		environments[$2]=1
		env++
		envnum[env]=$2
		printf("#define WALL_ENV_%s %d\n",$2,env)
	}
	if ($3 && !locations[$3]) {
		locations[$3]=1
		loc++
		locnum[loc]=$3
		printf("#define WALL_LOC_%s %d\n",$3,loc)
	}
	tots[ $2 "-" $3 ]=$4/1
	
}

#tables
/^[\t ]*TABLE[\t ]/ {
	$2=toupper($2)
	if (total>tots[ currentenvironment "-" currentlocation ]) tots[ currentenvironment "-" currentlocation ]=total
	currenttable=$2
	if ($2 && !tables[$2]) {
		tables[$2]=1
	}
	total=0
}



#add item
function additem(base) {

	# 1) detect strings: y,yes,t,true. f,false,n,no.
	if (base ~ /[yY]([eE][sS])?/) base=1
	if (base ~ /[nN]([oO]|[Uu][Ll][lL])?/) base=0
	if (base ~ /[tT]([rR][uU][eE])?/) base=1
	if (base ~ /[fF]([aA][Ll][sS][eE])?/) base=0
	
	# 2) calculate max and total
	if (base>maxs[currenttable]) maxs[currenttable]=base
	total++
	 
	# 3) save the element in the correct table  
	items[currentenvironment "-" currentlocation "-" currenttable "-" total]=base/1
}

#parse items 
/^[\t ]*LINE[\t ]/ {
	if (currentenvironment && currenttable) {
		for (i=2;i<=NF;i++) {
			if ($i ~ /\*/) {
				split($i,a,"*")
				mult=a[1]
				base=a[2]
				for (j=0;j<mult;j++) {
					additem(base)
				}
			} else {
				additem($i)
			}
		}
	
	} else {
		#syntax error: items out of place
		printf("Syntax error in line %d at walls.conf: LINE outside a table.\n",NR)>"/dev/stderr"
		exit 40
	}
}

/^[\t ]*PLACE[\t ]/ {
	if (currentenvironment && currenttable) {
		maxtt=0
		for (i=2;i<=NF;i++) {
			total=$i
			if (total>maxtt) maxtt=total
			additem(1)
		}
		total=maxtt
	} else {
		#syntax error: items out of place
		printf("Syntax error in line %d at walls.conf: PLACE outside a table.\n",NR)>"/dev/stderr"
		exit 41
	}
}


##########################
# PART 2                 #
# Calculate bits         #
##########################

function getbits(k) {
	i=0
	for (;k;i++) k=(k-k%2)/2
	return i
}

END {
	if (total>tots[ currentenvironment "-" currentlocation ]) tots[ currentenvironment "-" currentlocation ]=total

	# 1) calculate inc and tab for each table
	inc=0
	tab=0
	maxsiz=0
	for (table in tables) {
		b=getbits(maxs[table])
		if (inc+b>31) {
			inc=0
			tab++
		}
		#exception: in case max=0 (b=0) tab and inc will be 0
		if (b==0) {
			tableinfo[table "inc"]=0
			tableinfo[table "tab"]=0
			tableinfo[table "siz"]=0
		} else {
			tableinfo[table "inc"]=inc
			tableinfo[table "tab"]=tab
			tableinfo[table "siz"]=b
			if (b>maxsiz) maxsiz=b
		}
		inc+=b;
	}
	
	sizeoftab=getbits(tab)
	if (tab) {
		sizeofinc=5
	} else {
		sizeofinc=getbits(inc)
	}
	sizeofsiz=getbits(maxsiz)
	
	printf("\n/* TableId sizes */\n")
	printf("/* maxtab=%d maxinc=%d maxsiz=%d. Size of tabincsiz is %d bits */\n",sizeoftab,sizeofinc,sizeofsiz,sizeofinc+sizeoftab+sizeofsiz)
	printf("#define WALL_gettab(tabincsiz) (tabincsiz>>%d)\n",sizeofinc+sizeofsiz)
	printf("#define WALL_getinc(tabincsiz) ((tabincsiz>>%d)&0x%X)\n",sizeofsiz,(2^sizeofinc)-1)
	printf("#define WALL_getsiz(tabincsiz) (tabincsiz&0x%X)\n",(2^sizeofsiz)-1)
	printf("#define WALL_gettabinc(tab,inc,siz) ((((tab<<%d)|inc)<<%d)|siz)\n\n",sizeofinc,sizeofsiz)
	
	for (table in tables) {
		tableinfo[table "id"]=((((tableinfo[table "tab"]*2^sizeofinc)+tableinfo[table "inc"])*2^sizeofsiz)+tableinfo[table "siz"])
		printf("#define WALL_TABLE_%s %d /* WALL_gettabinc(%d,%d,%d) */\n",table,tableinfo[table "id"],tableinfo[table "tab"],tableinfo[table "inc"],tableinfo[table "siz"])
	}
	
	sizeofenv=getbits(env)
	sizeofloc=getbits(loc)
	
	printf("\n/* Index sizes */\n")
	printf("/* maxenv=%d maxloc=%d maxtab=%d. Size of envloctab is %d bits */\n",sizeofenv,sizeofloc,sizeoftab,sizeofenv+sizeofloc+sizeoftab)
	printf("#define WALL_getenv(envloctab) (envloctab>>%d)\n",sizeofloc+sizeoftab)
	printf("#define WALL_getloc(envloctab) ((envloctab>>%d)&0x%X)\n",sizeofloc,(2^sizeoftab)-1)
	printf("#define WALL_gettab2(envloctab) (envloctab&0x%X)\n",(2^sizeoftab)-1)
	printf("#define WALL_getenvloctab(env,loc,tab) ((((env<<%d)|loc)<<%d)|tab)\n\n",sizeofloc,sizeoftab)

	printf("\n/* A total of %d arrays will be created */\n",2^(sizeofenv+sizeofloc+sizeoftab))
	
	printf("#define WALL_ARRAYS {\\\n")
	totaltotal=0
	coma2=""
	for (e=0;e<2^sizeofenv;e++) {
		environment=envnum[e]
		for (l=0;l<2^sizeofloc;l++) {
			location=locnum[l]
			for (table in tables) {
#				printf("/* table %s. e=%d(%s) l=%d(%s) t=%d i=%d s=%d */\n",table,e,environment,l,location,tableinfo[table "tab"],tableinfo[table "inc"],tableinfo[table "siz"])
				for (i=1;i<=tots[environment "-" location];i++) {
					key= ( environment "-" location "-" table "-" i )
					res[tableinfo[table "tab"] "-" i]+=(items[key]/1)*2^(tableinfo[table "inc"])
				}
			}
			for (t=0;t<2^sizeoftab;t++) {
				printf("\t/* e=%d(%s) l=%d(%s) t=%d */ %s{",e,environment,l,location,t,coma2)
				coma2=","
				coma=""
				#this is to allow al least one item and avoid empty brackets
				if (!tots[environment "-" location]) tots[environment "-" location]=1
				
				for (i=1;i<=tots[environment "-" location];i++) {
					printf("%s(unsigned long)%d",coma,res[t "-" i])
					coma=","
				}
				totalcount++
				if (tots[environment "-" location]>totaltotal) totaltotal=tots[environment "-" location]
				printf("}\\\n")
			}
			delete res
		}
	}
	printf("}\n")
	printf("#define WALL_COUNT_TABLES %d\n#define WALL_SIZE_TABLES %d\n",totalcount,totaltotal)
	printf("#define WALL_LOC_NONE %d\n",loc+1)
}

