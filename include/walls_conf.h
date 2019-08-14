/* ENV and LOC defines */
#define WALL_ENV_DUNGEON 0
#define WALL_LOC_WWW 0
#define WALL_LOC_SWW 1
#define WALL_LOC_WWS 2
#define WALL_LOC_SWS 3

/* TableId sizes */
/* maxtab=0 maxinc=5 maxsiz=2. Size of tabincsiz is 7 bits */
#define WALL_gettab(tabincsiz) (tabincsiz>>7)
#define WALL_getinc(tabincsiz) ((tabincsiz>>2)&0x1F)
#define WALL_getsiz(tabincsiz) (tabincsiz&0x3)
#define WALL_gettabinc(tab,inc,siz) ((((tab<<5)|inc)<<2)|siz)

#define WALL_TABLE_LINE3_RIGHT_DOWN 0 /* WALL_gettabinc(0,0,0) */
#define WALL_TABLE_LINE2_RIGHT_DOWN 1 /* WALL_gettabinc(0,0,1) */
#define WALL_TABLE_LINE1_RIGHT_DOWN 5 /* WALL_gettabinc(0,1,1) */
#define WALL_TABLE_LINE3_SEP 9 /* WALL_gettabinc(0,2,1) */
#define WALL_TABLE_LINE1_LEFT_UP 13 /* WALL_gettabinc(0,3,1) */
#define WALL_TABLE_LINE3_RIGHT_UP 0 /* WALL_gettabinc(0,0,0) */
#define WALL_TABLE_LINE3_DARKER 0 /* WALL_gettabinc(0,0,0) */
#define WALL_TABLE_LINE3_OFFSET 19 /* WALL_gettabinc(0,4,3) */
#define WALL_TABLE_LINE2_RIGHT_UP 29 /* WALL_gettabinc(0,7,1) */
#define WALL_TABLE_LINE2_DARKER 0 /* WALL_gettabinc(0,0,0) */
#define WALL_TABLE_LINE2_OFFSET 35 /* WALL_gettabinc(0,8,3) */
#define WALL_TABLE_LINE1_DARKER 45 /* WALL_gettabinc(0,11,1) */
#define WALL_TABLE_LINE3_LEFT_DOWN 0 /* WALL_gettabinc(0,0,0) */
#define WALL_TABLE_LINE3_LEFT_UP 49 /* WALL_gettabinc(0,12,1) */
#define WALL_TABLE_LINE2_SEP 53 /* WALL_gettabinc(0,13,1) */
#define WALL_TABLE_LINE2_LEFT_DOWN 57 /* WALL_gettabinc(0,14,1) */
#define WALL_TABLE_LINE2_LEFT_UP 61 /* WALL_gettabinc(0,15,1) */
#define WALL_TABLE_LINE1_RIGHT_UP 65 /* WALL_gettabinc(0,16,1) */
#define WALL_TABLE_LINE1_LEFT_DOWN 69 /* WALL_gettabinc(0,17,1) */

/* Index sizes */
/* maxenv=0 maxloc=2 maxtab=0. Size of envloctab is 2 bits */
#define WALL_getenv(envloctab) (envloctab>>2)
#define WALL_getloc(envloctab) ((envloctab>>2)&0x0)
#define WALL_gettab2(envloctab) (envloctab&0x0)
#define WALL_getenvloctab(env,loc,tab) ((((env<<2)|loc)<<0)|tab)


/* A total of 4 arrays will be created */
#define WALL_ARRAYS {\
	/* e=0(DUNGEON) l=0(WWW) t=0 */ {(unsigned long)1364,(unsigned long)9280,(unsigned long)142129,(unsigned long)820,(unsigned long)65808,(unsigned long)3408,(unsigned long)9412,(unsigned long)8736,(unsigned long)277,(unsigned long)33044,(unsigned long)107856,(unsigned long)140084,(unsigned long)8868,(unsigned long)272,(unsigned long)3412,(unsigned long)9284,(unsigned long)13104,(unsigned long)10788,(unsigned long)1364,(unsigned long)1088,(unsigned long)10244,(unsigned long)8196,(unsigned long)8192,(unsigned long)132,(unsigned long)0,(unsigned long)8193,(unsigned long)8196,(unsigned long)8194,(unsigned long)0,(unsigned long)132,(unsigned long)8192,(unsigned long)73728,(unsigned long)10244,(unsigned long)2,(unsigned long)16384,(unsigned long)10245,(unsigned long)139264,(unsigned long)73736,(unsigned long)4,(unsigned long)128,(unsigned long)8196,(unsigned long)8196,(unsigned long)0,(unsigned long)4,(unsigned long)4,(unsigned long)139264,(unsigned long)8196,(unsigned long)16388,(unsigned long)0,(unsigned long)4,(unsigned long)10244,(unsigned long)8192,(unsigned long)4}\
	/* e=0(DUNGEON) l=1(SWW) t=0 */ ,{(unsigned long)0}\
	/* e=0(DUNGEON) l=2(WWS) t=0 */ ,{(unsigned long)0}\
	/* e=0(DUNGEON) l=3(SWS) t=0 */ ,{(unsigned long)0}\
}
#define WALL_COUNT_TABLES 4
#define WALL_SIZE_TABLES 53
#define WALL_LOC_NONE 4
