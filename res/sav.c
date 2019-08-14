/*
Range values:

Minutes remining [0 to 32766 for minutes; 32767 to 65534 for NO TIME; 65535 for game over]
Seconds remining [0.000 to 59.916] rounded by units of 0.0833333
Level [1 to 12 for normal levels; 13 for 12bis; 14 for princess; 15 for posion level]
Lives [0 (not recomended), 1 to 65535]
*/


//types
typedef struct {
	unsigned short int minleft;
	unsigned short int secleft;
	unsigned short int level;
	unsigned short int lives;
}tSav;

//Includes
#include <math.h>
#include <stdio.h>

//Prototypes

char mSaveSAV(char* vFile,tSav* vSav);
char mLoadSAV(char* vFile,tSav* vSav);
void mGetGame(tSav* vSav,unsigned short int *min,float *sec,unsigned short int *level,unsigned short int *lives);
void mSetGame(tSav* vSav,unsigned short int  min,float sec,unsigned short int level,unsigned short int lives);

//Implementation
char mSaveSAV(char* vFile,tSav* vSav) {
  FILE * pFile;
  if ((pFile = fopen (vFile , "wb"))==NULL) {
		return 0;
	}
  fwrite (vSav, 1, 8, pFile);
  fclose (pFile);
  return 1;
}

char mLoadSAV(char* vFile,tSav* vSav) {
	FILE *fp;
	char aux;

	if ((fp=fopen(vFile,"rb"))==NULL) {
		return 0;
	} else {
		aux=fread (vSav,8,1,fp);
		fclose(fp);
		return aux;
	}
}

void mGetGame(tSav* vSav,unsigned short int *min,float *sec,unsigned short int *level,unsigned short int *lives) {
	*sec=(((float)(((*vSav).secleft)-1))/12);
	*min=(*vSav).minleft-1;
	*level=(*vSav).level;
	*lives=(*vSav).lives;
}

void mSetGame(tSav* vSav,unsigned short int min,float sec,unsigned short int level,unsigned short int lives) {
	(*vSav).secleft=(floor(sec*12)+1);
	(*vSav).minleft=min+1;
	(*vSav).level=level;
	(*vSav).lives=lives;
}

//main test program
#include <conio.h>
void main (){
	tSav vSav;
	unsigned short int min;
	float sec;
	unsigned short int level;
	unsigned short int lives;
	printf("kaka: %d jaja.\n",mLoadSAV("prince.sav",&vSav));
	mGetGame(&vSav,&min,&sec,&level,&lives);
	printf("Min: %d. Sec: %f. Level: %d. Lives: %d.\n",min,sec,level,lives);
	//mSetGame(&vSav,0,35,5,7);
	//mSaveSAV("prince.sav",&vSav);


	getche();
};
