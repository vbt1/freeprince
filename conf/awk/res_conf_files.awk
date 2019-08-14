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

# res_conf_files.awk: FreePrince : files.conf parser
# ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
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
}

/^([ ]*[^# ].*)$/ {
	printf "#define RES_FILE_%s %d\n",$1,res
	for (i = 2; i <= NF; i++) {
		filelist=(filelist coma $i)
		coma="\",\\\n\t\""
		res++
	}
}

END {
	print (" /* numbers */\n#define RES_FILES {\\\n\t\""filelist "\"\\\n}")
}

