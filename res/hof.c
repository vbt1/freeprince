
//Programa princed;

#include <stdio.h>
#include <conio.h>
#include <math.h>

#define cPath     ""/*'d:\juegos\princed\';*/
#define cFileSav  "prince.hof"

#define HOF_MAX_RECORDS 6
#define HOF_NAME_SIZE 25

typedef struct {
	char nombre[HOF_NAME_SIZE+1];
	unsigned short int min;
	float sec;
	char empty;
}tRec;
typedef struct {
	unsigned short int records;
	tRec q[HOF_MAX_RECORDS];
}tHof;

/*
 unsigned char fselectrecord {
  unsigned char r;
  printf("Select Record: ");
  gets(r);
  return r;
 };*/

void mSortHof(tHof *juego) {
  tRec aux;
  unsigned char i,j;

	for (i=1;i<=(*juego).records;i++) {
		for (j=i+1;j<=(*juego).records;j++) {
			if (((*juego).q[i].min<(*juego).q[j].min)||(((*juego).q[i].min==(*juego).q[j].min)&&((*juego).q[i].sec<(*juego).q[j].sec))) {
				aux=(*juego).q[i];
				(*juego).q[i]=(*juego).q[j];
				(*juego).q[j]=aux;
			}
		}
	}
}
/*
void mEditarHof(tHof *juego;unsigned r:unsigned);

  secs:float;
  i:byte;
  nombre:char *[25];
 {
  printf("Record ",r," name text: ");
  gets(nombre);
  for( i=0 ; I++; I<= strlen(nombre)-1 )
   juego.q[r].nombre[i]=nombre[i+1];
  for( i=strlen(nombre) ; I++; I<= 24 )
   juego.q[r].nombre[i]=#0;
  printf("Record ",r," minutes left: ");
  gets(juego.q[r].min);
  ++(juego.q[r].min);
  printf("Record ",r," seconds left: ");
  gets(secs);
  juego.q[r].sec=floor(secs*12)+1;
 };
*/
void mLimpiarHof(tHof *juego) {
  char i;

  (*juego).records=0;
	for (i=0;i<HOF_MAX_RECORDS;(*juego).q[i++].empty=1);
	//Dejo el flag empty en 1 para que no se guarden estos datos
}

char mBorrarHof(tHof *juego,char selectRecord) {
	char i;

	if(((*juego).records)) {
		for(i=selectRecord;i<(*juego).records;(*juego).q[i]=(*juego).q[++i]); //adelanta los otros registros
		(*juego).q[((*juego).records--)].empty=1; //borra el ultimo
		return 1;
	} else {
		return 0;
	}
}

char mAgregarHof(tHof *juego,unsigned int min,float sec,char nombre[]) {
  unsigned char i,j;

  if ((*juego).records++<6) {
		//Posicionarse en un registro ordenado
		for (i=0;((i<(*juego).records)&&(((*juego).q[i].min<min)||(((*juego).q[i].min==min)&&((*juego).q[i].sec<sec))));i++);
    //correr los otros registros
    for(j=i+1;j<(*juego).records;(*juego).q[j]=(*juego).q[++j]);
		//Guardar el registro
    for(j=0;j<=HOF_NAME_SIZE;(*juego).q[i].nombre[j]=nombre[j++]);
    (*juego).q[i].sec=sec;
    (*juego).q[i].min=min;
    (*juego).q[i].empty=0;

    return 1;
	} else {
		return 0;
	}
}

char mCargarHof(const char* archivo,tHof *juego) {
	FILE *fp;
	char aux,i;
	unsigned short int auxsec;

	if ((fp=fopen(archivo,"rb"))==NULL) {
		return 0;
	} else {
		aux=fread (&(*juego).records, 2,1,fp);
		for (i=0;i<HOF_MAX_RECORDS;i++) {
			aux=aux&&fread (&(*juego).q[i].nombre,HOF_NAME_SIZE,1,fp);
			aux=aux&&fread (&(*juego).q[i].min,2,1,fp);
			aux=aux&&fread (&auxsec,2,1,fp);
			(*juego).q[i].sec=(((float)(auxsec-1))/12);
			(*juego).q[i].empty=0;
			(*juego).q[i].nombre[HOF_NAME_SIZE]=0;
		}
		fclose(fp);
		return aux;
	}
}

char mSalvarHof(char* vFile,tHof *juego) {
  FILE * pFile;
  char aux;
  if ((pFile = fopen (vFile , "wb"))==NULL) {
		return 0;
	}
	static const char empty[29]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	unsigned short int auxsec;
	aux=fwrite (&(*juego).records, 1, 2, pFile);
	for (char i=0;i<HOF_MAX_RECORDS;i++) {
		if ((*juego).q[i].empty) {
			aux=aux&&fwrite (&empty, 1, 29, pFile);
		} else {
			aux=aux&&fwrite (&(*juego).q[i].nombre, 1, HOF_NAME_SIZE, pFile);
			aux=aux&&fwrite (&(*juego).q[i].min, 1, 2, pFile);
			auxsec=(floor((*juego).q[i].sec*12)+1);
			aux=aux&&fwrite (&auxsec, 1, 2, pFile);
		}
	}
  fclose (pFile);
  return aux;
}

int main() {
	tHof game;
	int i;
	char salir=0;

	salir=!mCargarHof(cFileSav,&game);
	while(!salir) {
		printf("Prinhof V1.0 (c) 2003 - Enrique P. Calot\n");
		printf("Check for the latest version at http://www.princed.0.net.ar\n");
		printf("Keys:\n\n");
		printf(" L:load prince.hof (loose changes)\n");
		printf(" G:save prince.hof\n");
		printf(" E:edit record     (not saved)\n");
		printf(" A:add record      (not saved)\n");
		printf(" D:delete record   (not saved)\n");
		printf(" S:sort records    (not saved)\n");
		printf(" C:clear records   (not saved)\n");
		printf(" Q:quit\n\nTotal: %d registros\n\n",game.records);

		for(i=0;i<game.records&&i<HOF_MAX_RECORDS;i++){
			printf("%d) Name: '%s' Time: '%02d:%05.2f'\n",i+1,game.q[i].nombre,game.q[i].min,game.q[i].sec);
		};

		switch(getche()){
			case 'l':printf("jaja %d ohhh",mCargarHof(cFileSav,&game));break;
			case 'g':mSalvarHof(cFileSav,&game);break;
			case 'q':salir=1;break;
    //'e':meditarhof(game,fselectrecord);
			case 'a':mAgregarHof(&game,55,45.3,"Enrique P. Calot");break;
			case 'd':mBorrarHof(&game,4);break;
			case 'c':mLimpiarHof(&game);break;
			case 's':mSortHof(&game);break;
		}
	}
	return 1;
}

