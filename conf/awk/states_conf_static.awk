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

# states_conf_static.awk: FreePrince : states.conf parser
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
	currentCondition=-1
	currentAction=-1
	exitNextState=-1

	exitError=0

	printf("#define STATES_MOVETYPES_ABSOLUTEONSTART 0\n")
	printf("#define STATES_MOVETYPES_ABSOLUTEONSTOP 1\n")
	printf("#define STATES_MOVETYPES_RELATIVETURN 2\n")
	printf("#define STATES_MOVETYPES_RELATIVE 3\n")
	printf("#define STATES_CONDITIONS {\\\n")

#mawg property validation
#	tmp="conf/statesproperties.conf"
#	while ((getline line < tmp) > 0) {
#		gsub(/[	 ]+/, "-",line)
#		m=index(line,"-")
#		if (m) {
#			word=substr(line,0,m)
#			number=substr(line,m+1)
#			defines[word]=number
#		}
#	}
#	close(tmp)
	currentAnimation=0
	greatestLevel=-1
	first=0
}

function addExit (name) {
	if (exitArray[name]) {
		nextStateId=exitArray[name]
	} else {
		nextStateId=exitNextState
		exitArray[name]=exitNextState
		exitNextState--
	}
}

/^create exit [^ ]+$/ {
	addExit(toupper($3))
}

#3 tabs (options values)
/^\t\t\t[^\t# ].*$/ {
# next option
	if (listType == "next") {
		nextState=tolower($1)
		if (nextState=="exit" && $2) {
			nextState="exit " toupper($2)
		}
# steps option
	} else if (listType == "steps") {
		moveOffset=$2
		moveType=tolower($1)
# conditions option
	} else if (listType == "conditions") {
		#ignore "none"
		if ($1=="none") next
		#if there is a new group add a "break"
		if (oldType != listType ) {
			oldType=listType
			currentCondition++
			printf("\t{esLast,0}, /* condition number %d */\\\n",currentCondition)
			conditions=currentCondition+1
		}
		#add condition
		currentCondition++
		if ($2!=sprintf("%d",$2)) {
			#if (1) {      #defines[$2]) {
				if ($1~/^Map/) {
					result=sprintf("TILES_%s",toupper($2))
				} else if ($1~/Looking/) {
					result=sprintf("DIR_%s",toupper($2))
				} else if ($1~/Key/) {
					result=sprintf("STATES_KEY_%s",toupper($2))
				} else {
					result=sprintf("STATES_COND_%s",toupper($2))
				}
			#} else {
			#
			#	if ($2) {
			#		printf("Parsing error in states.conf: Condition modifier '%s' not recognized on uncommented line %d.\n",$2,NR)>"/dev/stderr"
			#		exit 22
			#	}
			#	result=0
			#}
		} else {
			result=$2
		}
		printf("\t{es%s,%s}, /* condition number %d */\\\n",$1,result,currentCondition)
# animation option
	} else if (listType == "animation") {
		if (match($1,/^[0-9]+-[0-9]*$/)) {
			split($1,a,"-")
			for (g=a[1];g<=a[2];g++) {
				arrayAnimation[currentAnimation,"frame"]=g
				$1=""
				arrayAnimation[currentAnimation,"flags"]=$0
				currentAnimation++
			}
		} else {
			arrayAnimation[currentAnimation,"frame"]=$1
			$1=""
			arrayAnimation[currentAnimation,"flags"]=$0
			currentAnimation++
		}
# level option
	} else if (listType == "level") {
		if (arrayLevel[$1]) {
			printf("Parsing error in %s: Redeclaration of level '%d' on line %d.\n",FILENAME,$1,FNR)>"/dev/stderr"
			exitError=23
			exit 23
		} else {
			arrayLevel[$1]=currentAction+1 #i'm adding 1 to leave the 0 as "not set"
			if ($1>greatestLevel) {
				greatestLevel=$1
			}
		}
# guardskill option
	} else if (listType == "guardskill") {
		if (arrayGuard[$1]) {
			printf("Parsing error in %s: Redeclaration of guard skill '%d' on line %d.\n",FILENAME,$1,FNR)>"/dev/stderr"
			exitError=25
			exit 25
		} else {
			arrayGuard[$1]=currentAction+1 #i'm adding 1 to leave the 0 as "not set"
			if ($1>greatestSkill) {
				greatestSkill=$1
			}
		}
# mark option
	} else if (listType == "mark") {
		arrayMarks[toupper($1)]=currentAction
	}
}

#2 tabs (action options)
/^\t\t[^\t# ].*$/ {
	oldType=listType
	listType=tolower($1)
}
#1 tab (action)
/^\t[^\t# ].*$/ {
	actionArray[currentAction,"description"]=rememberAction
	actionArray[currentAction,"isFirstInState"]=currentState
	if ((priorActionLine)&&(currentAnimation==startAnimation)) {
		printf("Parsing error in %s: Missing action animation from line %d to line %d.\n",FILENAME,priorActionLine,FNR-1)>"/dev/stderr"
		exitError=27
		exit 27
	}
	actionArray[currentAction,"animationStart"]=startAnimation
	actionArray[currentAction,"animationSize"]=currentAnimation-startAnimation
	actionArray[currentAction,"conditionStart"]=conditions
	actionArray[currentAction,"nextState"]=nextState
	if ((priorActionLine)&&(!nextState)) {
		printf("Parsing error in %s: Missing next state in action from line %d to line %d.\n",FILENAME,priorActionLine,FNR-1)>"/dev/stderr"
		exitError=28
		exit 28
	}
	nextState=""
	actionArray[currentAction,"moveType"]=moveType
	actionArray[currentAction,"moveOffset"]=moveOffset
	actionArray[currentAction,"lastComma"]=","
	currentState=""

	#remember prior action line in case the animation is empty
	priorActionLine=FNR

	currentAction++
	startAnimation=currentAnimation
	listType=""
	conditions=0
	if (tolower($1) != "action") {
		printf("Error! \"%s\" should be an action.\n",$0)>"/dev/stderr"
	}
	$1=""
	rememberAction=substr($0,2)
}

#no tabs (states)
/^[^\t# ].*$/ {
		listType=""
		if ($1 ~ /:$/) $1=substr($1,1,length($1)-1)
		if (!currentState) {
		#	priorState=tolower($1)
		#} else {
			currentState=tolower($1)
		}
		stateList[tolower($1)]=currentAction+1
}

END {
	if (exitError) exit exitError
	actionArray[currentAction,"description"]=rememberAction
	actionArray[currentAction,"isFirstInState"]=currentState
	if ((currentAnimation)&&(currentAnimation==startAnimation)) {
		printf("Parsing error in %s: Missing action animation from line %d to line %d.\n",FILENAME,priorActionLine,FNR-1)>"/dev/stderr"
		exit 29
	}
	actionArray[currentAction,"animationStart"]=startAnimation
	actionArray[currentAction,"animationSize"]=currentAnimation-startAnimation
	actionArray[currentAction,"conditionStart"]=conditions
	actionArray[currentAction,"nextState"]=nextState
	actionArray[currentAction,"moveType"]=moveType
	actionArray[currentAction,"moveOffset"]=moveOffset
	actionArray[currentAction,"lastComma"]=""
	printf("\t{esLast,0} /* the end */\\\n}\n\n#define STATES_ACTIONS {\\\n")

	for (i=0;i<=currentAction;i++) {
		nextState=actionArray[i,"nextState"]
		if (nextState ~ /^exit /) { #if the next state is exit+something, something will be remembered
			split(nextState,a," ")
			addExit(a[2])
		} else {
			nextStateId=stateList[nextState]
		}
		#print comments
		printf("\t/* Action: %s (%d) \\\n",\
			actionArray[i,"description"],\
			i\
		)
		if (actionArray[i-1,"isFirstInState"]) {
			printf("\t * State: %s (%d) \\\n",\
				actionArray[i-1,"isFirstInState"],\
				i\
			)
		}
		printf("\t * Animations: animStart=%d, animSize=%d \\\n",\
			actionArray[i,"animationStart"],\
			actionArray[i,"animationSize"]\
		)
		printf("\t * Conditionals: conditionId=%d, nextStateId=%d (%s) \\\n",\
			actionArray[i,"conditionStart"],\
			nextStateId,\
			actionArray[i,"nextState"]\
		)
		printf("\t * Movements: moveType=%s, moveOffset=%d */ \\\n",\
			actionArray[i,"moveType"],\
			actionArray[i,"moveOffset"]\
		)
		#print array
		printf("\t\t{%d,STATES_MOVETYPES_%s,%d,%d,%d,%d}%s\\\n",\
			actionArray[i,"conditionStart"],\
			toupper(actionArray[i,"moveType"]),\
			actionArray[i,"moveOffset"],\
			nextStateId,\
			actionArray[i,"animationStart"],\
			actionArray[i,"animationSize"],\
			actionArray[i,"lastComma"]\
		)
	}

	printf("}\n\n#define STATES_ANIMATIONS {\\\n\t")
	coma=""
	for (i=0;i<currentAnimation;i++) {
		flags=arrayAnimation[i,"flags"]
		
		b=match(flags,/\$[ ]*([+-]?[0-9]+)/)
		steps=substr(flags,b+1,RLENGTH)/1
		c=match(flags,/\@[ ]*([+-]?[0-9]+)/)
		offxs=substr(flags,c+1,RLENGTH)/1
		
		s=match(flags,/([^0-9 +@\$-])/)
		if (s) d=substr(flags,s,1)
		if (s&&(d!="#")) {
			flagmask=""
			while (s) {
				flagmask=sprintf("%sSTATES_FLAG_%s|",flagmask,toupper(d))
				flags=substr(flags,s+1,length(flags)-s)
				s=match(flags,/([^0-9 +@\$-])/)
				if (s) d=substr(flags,s,1)
				if (d=="#") s=0
			}
		} else {
			flagmask=""
		}
		if (offxs) flagmask=sprintf("%sSTATES_FLAG_HEIGHTOFFSET|",flagmask)
		printf "%s%d,%s0,%d,/* h= */%d",coma,arrayAnimation[i,"frame"],flagmask,steps,offxs
		if (i%10==9) printf("\\\n\t")
		coma=","
	}

	printf("\\\n}\n\n#define STATES_LEVELS {")
	coma=""
	for (i=0;i<=greatestLevel;i++) {
		if (!arrayLevel[i]) {
			printf("Parsing error in states directory: Level number %d is defined but level %d is not.\n",greatestLevel,i)>"/dev/stderr"
			exit 24
		}
		printf "%s%s",coma,arrayLevel[i]-1
		coma=","
	}
	printf("}\n\n#define STATES_GUARDS {")
	coma=""
	for (i=0;i<=greatestGuard;i++) {
		if (!arrayGuard[i]) {
			printf("Parsing error in states directory: Guard skill %d is defined but skill %d is not.\n",greatestGuard,i)>"/dev/stderr"
			exit 26
		}
		printf "%s%s",coma,arrayGuard[i]-1
		coma=","
	}
	printf("}\n\n")
	#define exit codes
	for (exitCode in exitArray) {
		printf "#define STATE_EXIT_CODE_%s %d\n",exitCode,exitArray[exitCode]
	}
	printf("\n")
	#define marks
	for (marks in arrayMarks) {
		printf "#define STATE_MARKS_%s %d\n",marks,arrayMarks[marks]
	}
	printf("\n")
}

