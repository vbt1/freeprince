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
dat.h: Princed Resources : DAT library headers
�����
 Copyright 2004 Princed Development Team
  Created: 15 Mar 2004

  Author: Enrique Calot <ecalot.cod@princed.com.ar>
  Version: 1.00 (2004-Mar-15)

 Note:
  DO NOT remove this copyright notice
*/

#ifndef _PR_DAT_H_
#define _PR_DAT_H_

#include "resources.h"

#define PR_DAT_INCLUDE_DATREAD
/*#define PR_DAT_INCLUDE_DATWRITE*/

#ifdef PR_DAT_INCLUDE_DATREAD
#ifdef PR_DAT_INCLUDE_DATWRITE
/* DAT reading and writing primitives */
int mRWBeginDatFile(const char* vFile, unsigned short int *numberOfItems, int optionflag);
#define mRWCloseDatFile(dontSave) \
mReadCloseDatFile();\
mWriteCloseDatFile(r,dontSave,optionflag,backupExtension)
#endif
#endif

#ifdef PR_DAT_INCLUDE_DATREAD
/* DAT reading primitives */
int  mReadBeginDatFile(unsigned short int *numberOfItems,const char* vFile);
int  mReadFileInDatFile(int indexNumber,unsigned char** data,unsigned long int *size);
int  mReadInitResource(tResource** res,const unsigned char* data,long size);
void mReadCloseDatFile();
#endif

#ifdef PR_DAT_INCLUDE_DATWRITE
/* DAT writing primitives */
int  mWriteBeginDatFile(const char* vFile, int optionflag);
void mWriteFileInDatFile(const unsigned char* data, int size);
void mWriteFileInDatFileIgnoreChecksum(unsigned char* data,int size);
void mWriteInitResource(tResource** res);
void mWriteCloseDatFile(tResource* r[],int dontSave,int optionflag, const char* backupExtension);
#endif

#endif
