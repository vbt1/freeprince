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
disk.c: Princed Resources : Disk Access & File handling functions
������
 Copyright 2003 Princed Development Team
  Created: 29 Oct 2003

  Author: Enrique Calot <ecalot.cod@princed.com.ar>
  Version: 1.00 (2003-Oct-29)

  Modified by: Enrique Calot <ecalot.cod@princed.com.ar>
  Version: 1.10 (2003-Dec-03)
  Modified by: Santiago Zamora <drkzight@users.sourceforge.net>
  Version: 1.20 (2004-Jan-06)

 Note:
  DO NOT remove this copyright notice
*/

/* Defines */
#include "memory.h"
#include <string.h>
#include "disk.h"
#ifndef WIN32
#define UNIX
#endif

#include <sys/types.h>
#include <sys/stat.h>

#ifndef DISK_ALLWAYS_FORCE
#include "common.h" /* language texts */
#include "xmlparse.h" /* equalsIgnoreCase */
#endif

#ifndef WIN32
  #define defmkdir(a) mkdir (a,(mode_t)0755)
	/* Recursive directory scanning needs <dirent> for posix or "direntwin" for windows */
	#ifdef DISK_DIR_SCANING
		#include <dirent.h>
	#endif
	/* Terminal manipulation for unix (to avoid the enter after selecting an option) */
	#ifdef DISK_TERM_MANIPULATION
		#include <termios.h>
		#include <unistd.h>
		#include <fcntl.h>
	#endif
	#define osIndepGetCharacter() getchar()
#else
	#include <direct.h> /* mkdir */ 
  #define defmkdir(a) mkdir (a)
	#ifdef DISK_DIR_SCANING
		#include "direntwin.h"
	#endif
	#include <conio.h> /* getche */
	#define osIndepGetCharacter() getche()
#endif

#ifndef DISK_ALLWAYS_FORCE
extern FILE* outputStream;
#endif

extern short *res_list;
extern char **res_file;
/*
extern short *res_fileid;
*/
/***************************************************************\
|              Disk Access & File handling functions            |
\***************************************************************/
#if 0
/* Repair folders */
const char *repairFolders(const char* a) {
	int i,k;
	static char result[MAX_FILENAME_SIZE];

	for (i=0,k=0;(k<MAX_FILENAME_SIZE)&&a[i];) {
		if (isDirSep(a,i)) {
			result[k]=DIR_SEPARATOR;
			i++;
			while (isDirSep(a,i)) i++;
		} else {
			result[k]=a[i];
			i++;
		}
		k++;
	}
	result[k]=0;
	return result;
}


/* Create base directory of a file */
int makebase(const char* p) {
	/*
		Creates the base directory of the given file "p"
		Returns 0 if created
		Returns -1 if an error occurred

		Note: if the base directory already exists it will return -1!
	*/

	/* Declare variables */
	static char old[MAX_FILENAME_SIZE];
	int i,a,equal=1;
	int size;
	char* aux;

	/* Initialize variables */
	size=(strlen(p)+1);
	aux=(char*)malloc(size);

	/* Make directories */
	for (i=0;i<size;i++) {
		aux[i]=0;
		equal=equal&&(old[i]==p[i]);
/*		if ((!equal)&&(p[i]==DIR_SEPARATOR)) a=defmkdir(aux); */
		old[i]=p[i];
		aux[i]=p[i];
	}

	free(aux);
	return a;
}
#endif

#ifndef DISK_ALLWAYS_FORCE
static tOpenFiles* openFilesList=NULL;

void addFileToOpenFilesList(const char* fileName,int hasBackup) {
	/*
		Add a recently safe open file to the file pointer dynamic table
		using the LIFO philosophy.
	*/

	tOpenFiles* newNode;

	/* Create the new node and fill in the fields */
	newNode=(tOpenFiles*)malloc(sizeof(tOpenFiles));
	CHECKMALLOCRESULT(newNode);
	newNode->next=openFilesList;
	newNode->name=strallocandcopy(fileName);

	if (hasBackup) {
		newNode->size=mLoadFileArray(fileName,&(newNode->content));
	} else {
		newNode->size=0;
	}
	openFilesList=newNode;
}

void addPointerToOpenFilesList(FILE* fp) { /* TODO: use a define */
	openFilesList->file=fp;
}

int getFromOpenFilesList(FILE* fp, char** fileName, unsigned char** content, unsigned long int *size) {
	tOpenFiles* currentNode;
	tOpenFiles* priorNode=NULL;

	/* Search using FILE* file as key */
	if (openFilesList==NULL) return 0; /* Empty list */
	currentNode=openFilesList;
	while ((currentNode->file!=fp)&&(currentNode->next!=NULL)) {
		priorNode=currentNode;
		currentNode=currentNode->next;
	}
	if (currentNode->file!=fp) return 0; /* Not found */

	/* Return results */
	*fileName=currentNode->name;
	*content=currentNode->content;
	*size=currentNode->size;

	/* free node and set prior pointer to the next */
	if (priorNode==NULL) {
		openFilesList=currentNode->next;
	} else {
		priorNode->next=currentNode->next;
	}
	free(currentNode);

	return 1;
}
#if 0
int writeClose(FILE* fp,int dontSave,int optionflag,const char* backupExtension) {
	unsigned char* content;
	char* fileName;
	unsigned long int size;

	if (getFromOpenFilesList(fp,&fileName,&content,&size)) {
		if (dontSave) {
			fclose(fp);
			if (size) {
				fp=fopen(fileName,"wb");
				if (fp==NULL) return -1;
				fwrite(content,1,size,fp);
				fclose(fp);
			} else {
				remove(fileName);
			}
		} else {
			/* File Existed before and we need to back it up */
			if (hasFlag(backup_flag)) {
				char aux[MAX_FILENAME_SIZE];
				static const char defaultbackupExtension[]=DEFAULT_BACKUP_EXTENSION;
				/* Set default values if there isn't */
				if (backupExtension==NULL) backupExtension=defaultbackupExtension;
				/* generate the file name */
				sprintf(aux,"%s.%s",fileName, backupExtension);
				fclose(fp);
				fp=fopen(aux,"wb");
				if (fp==NULL) return -2;
				fwrite(content,1,size,fp);
				fclose(fp);
			} else {
				fclose(fp);
			}
		}

		free(fileName);
		if (size) free(content);
	}

	return 0;
}

int writeOpen(const char* vFileext, FILE* *fp, int optionflag) {
	/*
		Opens vFileext for write access
		 if the path doesn't exist it is created
		 if the file doesn't exist it is created
		 if the file does exist it is overwritten

		Sets the file pointer and returns 1 if Ok or 0 if error

		Returns
		 0 if error
		 1 if ok
	*/
	const char* file;
	whatIs fileType;
	static int all=0;
	int result;

#ifdef UNIX
#ifdef DISK_TERM_MANIPULATION
	/* This will eliminate the enter after the input */
	struct termios term;
	struct termios termOld;

	tcgetattr (STDIN_FILENO, &term);
	tcgetattr (STDIN_FILENO, &termOld); /* save original proprieties */
	term.c_lflag &= ~(ICANON);
	tcsetattr (STDIN_FILENO, TCSANOW, &term);
#endif
#endif

	/* Create base directory and save file */
	file=repairFolders(vFileext);

	/* Verify if file already exists. */
	fileType=isDir(vFileext);
	if (fileType==eDirectory) return 0;


	if (fileType==eFile) {
		/* File exists. We need to ask */
		if ((!(hasFlag(force_flag)))&&(!all)) {
			char answer;
			printf(PR_TEXT_DISK_REPLACE,getFileNameFromPath(file));
			answer=osIndepGetCharacter();
			printf("\n");
			if (charToUpper(answer)==PR_DISK_REPLACE_NO)  return 0;
			if (charToUpper(answer)==PR_DISK_REPLACE_ALL) all=1;
		}
	} else {
		makebase(file);
	}


#ifdef UNIX
#ifdef DISK_TERM_MANIPULATION
	/* restoring previous terminal options */
	term=termOld;
	tcsetattr (STDIN_FILENO, TCSANOW, &termOld);
#endif
#endif
	/*
		If the file exists, we need to remember the old content in memory
		if not, we need to know the name in case we need to delete it
	*/


	addFileToOpenFilesList(file,hasFlag(backup_flag));

	if ((result=((*fp=fopen(file,"wb"))!=NULL))) addPointerToOpenFilesList(*fp);

	return result;
}
#else
int writeClose(FILE* fp,int dontSave,int optionflag,const char* backupExtension) {
	unsigned long int size=0;

		if (dontSave) {
			fclose(fp);
			if (size) {
				fp=fopen(/*fileName*/"/dev/null","wb");
				if (fp==NULL) return -1;
			}
	}

	return fclose(fp);
}

int writeOpen(const char* vFileext, FILE* *fp, int optionflag) {
	/*
		Opens vFileext for write access
		 if the path doesn't exist it is created
		 if the file doesn't exist it is created
		 if the file does exist it is overwritten

		Sets the file pointer and returns 1 if Ok or 0 if error

		Returns
		 0 if error
		 1 if ok
	*/
	const char* file;
	whatIs fileType;
	int result;

	/* Create base directory and save file */
	file=repairFolders(vFileext);

	/* Verify if file already exists. */
	fileType=isDir(vFileext);
	if (fileType==eDirectory) return 0;

	if (fileType==eFile) {
		/* File exists. We need to ask */
	} else {
		makebase(file);
	}

	/*
		If the file exists, we need to remember the old content in memory
		if not, we need to know the name in case we need to delete it
	*/

/*	addFileToOpenFilesList(file,hasFlag(backup_flag));*/
	result=((*fp=fopen(file,"wb"))!=NULL);/* addPointerToOpenFilesList(*fp);*/
	return result;
}
#endif

int writeData(const unsigned char* data, int ignoreChars, char* vFileext, int size, int optionflag,const char* backupExtension) {
	/*
		Creates vFileext and saves data in it. In case the directory doesn't
		exist it will be created.

		Data is read from ignoreChars to size.
		Example:
			if data="123456789", ignoreChars=3, size=8
			saved file will contain "45678"

		Returns
		 0 if error
		 1 if ok
	*/

	/* Declare variables */
	FILE* target;
	char  ok;

	/* Verify parameters */
	size-=ignoreChars;
	if (size<0) return 0;
	/*if (size==0) return 1; * Wrote 0 bytes */

	/* Save file */
	ok=writeOpen(vFileext,&target,optionflag);
	ok=ok&&((!size)||fwrite(data+ignoreChars,size,1,target));
	ok=ok&&(!writeCloseOk(target,optionflag,backupExtension));
	return ok;
}
#endif
/*int vbt = 0; */
#define TVSTAT      (*(volatile unsigned short *)0x25F80004)

void wait_vblank(void)
{
     while((TVSTAT & 8) == 0);
     while((TVSTAT & 8) == 8);
}

int mLoadFileArray(const char* vFile,unsigned char** array) {
	/*
		Using the string in vFile, it opens the file and returns the
		number of bytes	in it and the content of the file in array.
		In case the file couldn't be open or memory allocated returns 0.
	*/
/*vbt++; */
	/* declare variables */
	int  aux,i;
	int fileId =  GFS_NameToId((signed char*)strupr(vFile)); 

char toto[40];
sprintf(toto,"%s %d       ",vFile,fileId);
slPrint(toto,slLocate(2,1));



/*	heapWalk();*/


	long fileSize = GetFileSize(fileId);
	aux = fileSize;


sprintf(toto,"fs:%ld %s %d     ",fileSize,vFile,fileId);
slPrint(toto,slLocate(2,2));

#if 1
	if ( !aux || (aux>SIZE_OF_FILE) || ( ((*array=(unsigned char*)malloc(aux+1))==NULL) ) ) {
slPrint("file was null or bigger than max size or can't allocate memory ",slLocate(2,22));
		/* if the file was null or bigger than the max size or couldn't allocate the file in memory */
		return 0;
	}
#endif
	GFS_Load(fileId, 0, *array, fileSize);
	wait_vblank();
	(*array)[fileSize]=0;
	return fileSize;
}
#if 0
const char* getFileNameFromPath(const char* path) {
	/*
		If you give a path you get the filename,
		if you give a filename, you get the same filename
	*/
	int size;
	size=strlen(path);
	while (size) {
		if (isDirSep(path,size)) {
			return path+size+1;
		}
		size--;
	}
	return path;
}

whatIs isDir(const char *path) {
	/*
		eDirectory if path is a directory
		eNotFound if path isn't a directory or doesn't exist
		eFile if it is a file
	*/
	struct stat buf;

	if(stat(path,&buf)==-1) return eNotFound;
	return (S_ISDIR(buf.st_mode))?eDirectory:eFile;
}

#ifdef DISK_DIR_SCANING

int recurseDirectory(const char* path,int recursive, void* pass, void (*function)(const char*,void*)) {
	/*
		Search for all .dat files in the directory
		if recursive flag is set search over the subdirectories
		if verbose flag is set shows some messages in the screen
		when .dat files are found it runs prMain form each of them
	*/

	/* Declare variables */
	char*          recursivePath;
	struct dirent* directoryStructure;
	DIR*           dir;

	/* Opens directory */
	if ((dir = opendir(path))==NULL) {
		return -1;
	}

	/* Main loop: while there are still more files left */
	while ((directoryStructure = readdir(dir))!=NULL) {
		if /* Don't look over the system directories */
			(
				strcmp(directoryStructure->d_name,".")&&
				strcmp(directoryStructure->d_name,"..")
		) {
			/* Declare variables */
			int sizeOfPath=strlen(path);
			int sizeOfFile=strlen(directoryStructure->d_name);

			/* Generate recursive path */
			recursivePath=(char*)malloc(sizeOfPath+2+sizeOfFile);
			memcpy(recursivePath,path,sizeOfPath);
			recursivePath[sizeOfPath]=DIR_SEPARATOR;
			memcpy(recursivePath+sizeOfPath+1,directoryStructure->d_name,sizeOfFile+1);

			if (isDir(recursivePath)==eDirectory&&recursive) {
				/* Only recurse if we are in a directory and recursive is true */
				recurseDirectory(recursivePath,recursive,pass,function);
			} else {
				function(recursivePath,pass);
			}
			/* Free all allocated memory */
			free(recursivePath);
		}
	}
	closedir(dir);
	return 0;
}
#endif

#ifdef MACOS
int macfreads (void* bigEndian,FILE* file) {
	unsigned short int littleEndian;
	unsigned char* lit_e=(unsigned char*)&littleEndian;
	unsigned char* big_e=(unsigned char*)bigEndian;
	int result=fread(lit_e,2,1,file);
	big_e[0]=lit_e[1];
	big_e[1]=lit_e[0];
	return result;
}
int macfreadl (void* bigEndian,FILE* file) {
	unsigned long int littleEndian;
	unsigned char* lit_e=(unsigned char*)&littleEndian;
	unsigned char* big_e=(unsigned char*)bigEndian;
	int result=fread(lit_e,4,1,file);
	big_e[0]=lit_e[3];
	big_e[1]=lit_e[2];
	big_e[2]=lit_e[1];
	big_e[3]=lit_e[0];
	return result;
}
int macfwrites(const void* var,FILE* file) {
	unsigned short int littleEndian;
	unsigned short int bigEndian=*(unsigned short int*)(var);
	unsigned char* lit_e=(unsigned char*)&littleEndian;
	unsigned char* big_e=(unsigned char*)&bigEndian;
	lit_e[0]=big_e[1];
	lit_e[1]=big_e[0];
	return fwrite(lit_e,2,1,file);
}

int macfwritel(const void* var,FILE* file) {
	unsigned long int littleEndian;
	long int bigEndian=*(long int*)(var);
	unsigned char* lit_e=(unsigned char*)&littleEndian;
	unsigned char* big_e=(unsigned char*)&bigEndian;
	lit_e[0]=big_e[3];
	lit_e[1]=big_e[2];
	lit_e[2]=big_e[1];
	lit_e[3]=big_e[0];
	return fwrite(lit_e,4,1,file);
}

#endif

#endif
