#define ANIMS_LAYERTYPE_TOP     0
#define ANIMS_LAYERTYPE_BOTTOM  1

#define ANIMS_IMAGE {\
	{/*frame*/ 0,/*res*/ (unsigned long)(RES_IMG_MAIN_BACKGROUND), /*duration*/ 30, /*layer*/ (unsigned char)ANIMS_LAYERTYPE_BOTTOM, /*x,y*/ (unsigned short)0,(unsigned short)200},\
	{/*frame*/ 2,/*res*/ (unsigned long)(RES_IMG_MAIN_PRESENTS), /*duration*/ 6, /*layer*/ (unsigned char)ANIMS_LAYERTYPE_TOP, /*x,y*/ (unsigned short)96,(unsigned short)153},\
	{/*frame*/ 10,/*res*/ (unsigned long)(RES_IMG_MAIN_AUTHOR), /*duration*/ 4, /*layer*/ (unsigned char)ANIMS_LAYERTYPE_TOP, /*x,y*/ (unsigned short)96,(unsigned short)153},\
	{/*frame*/ 15,/*res*/ (unsigned long)(RES_IMG_MAIN_GAME_NAME), /*duration*/ 8, /*layer*/ (unsigned char)ANIMS_LAYERTYPE_TOP, /*x,y*/ (unsigned short)24,(unsigned short)172},\
	{/*frame*/ 24,/*res*/ (unsigned long)(RES_IMG_MAIN_COPYRIGHT), /*duration*/ 6, /*layer*/ (unsigned char)ANIMS_LAYERTYPE_TOP, /*x,y*/ (unsigned short)50,(unsigned short)190},\
	{/*frame*/ 30,/*res*/ (unsigned long)(RES_IMG_TEXT_BACKGROUND), /*duration*/ 10, /*layer*/ (unsigned char)ANIMS_LAYERTYPE_BOTTOM, /*x,y*/ (unsigned short)0,(unsigned short)200},\
	{/*frame*/ 30,/*res*/ (unsigned long)(RES_IMG_TEXT_IN_THE_ABSENSE|RES_MODS_BW), /*duration*/ 10, /*layer*/ (unsigned char)ANIMS_LAYERTYPE_TOP, /*x,y*/ (unsigned short)20,(unsigned short)170},\
	{/*frame*/ 40,/*res*/ (unsigned long)(RES_IMG_PRINCESS_ROOM), /*duration*/ 30, /*layer*/ (unsigned char)ANIMS_LAYERTYPE_BOTTOM, /*x,y*/ (unsigned short)0,(unsigned short)200},\
	{/*frame*/ 40,/*res*/ (unsigned long)(RES_IMG_PRINCESS_BED), /*duration*/ 30, /*layer*/ (unsigned char)ANIMS_LAYERTYPE_BOTTOM, /*x,y*/ (unsigned short)0,(unsigned short)183},\
	{/*frame*/ 40,/*res*/ (unsigned long)(RES_IMG_PRINCESS_PILLAR), /*duration*/ 30, /*layer*/ (unsigned char)ANIMS_LAYERTYPE_TOP, /*x,y*/ (unsigned short)188,(unsigned short)124},\
	{/*frame*/ 70,/*res*/ (unsigned long)(RES_IMG_TEXT_BACKGROUND), /*duration*/ 0, /*layer*/ (unsigned char)ANIMS_LAYERTYPE_BOTTOM, /*x,y*/ (unsigned short)0,(unsigned short)200},\
	{/*frame*/ 70,/*res*/ (unsigned long)(RES_IMG_TEXT_MARRY_JAFFAR|RES_MODS_BW), /*duration*/ 0, /*layer*/ (unsigned char)ANIMS_LAYERTYPE_TOP, /*x,y*/ (unsigned short)20,(unsigned short)170}\
}

#define ANIMS_OBJECT {\
	{/*frame*/ 40, /*res*/ (unsigned long)(RES_ANIM_TORCH), /*duration*/ 30, /*object*/ STATE_MARKS_TORCH, /*loc*/ 101, /*floor*/1, /*mirror*/ 0},\
	{/*frame*/ 40, /*res*/ (unsigned long)(RES_ANIM_TORCH), /*duration*/ 30, /*object*/ STATE_MARKS_TORCH, /*loc*/ 217, /*floor*/1, /*mirror*/ 0},\
	{/*frame*/ 45, /*res*/ (unsigned long)(RES_IMG_JAFFAR), /*duration*/ 0, /*object*/ STATE_MARKS_JAFFAR, /*loc*/ 100, /*floor*/2, /*mirror*/ 1},\
	{/*frame*/ 0, /*res*/ (unsigned long)(RES_IMG_JAFFAR), /*duration*/ 0, /*object*/ STATE_MARKS_JAFFAR, /*loc*/ 100, /*floor*/2, /*mirror*/ 0}\
}

#define ANIMS_SOUND {\
	{/*frame*/ 0,/*res*/ (unsigned long)RES_SND_MIDI_TITLES, /*type*/ anims_enum_speaker}\
}

#define ANIMS_TABLE {\
	{/*image*/ 0,12, /*object*/ 0,3, /*sound*/ 0,1, /*animsize*/ 1000},\
	{/*image*/ 12,0, /*object*/ 3,1, /*sound*/ 1,0, /*animsize*/ 200}\
}

#define ANIMS_ID_PRESENTATION 0
#define ANIMS_ID_LEVEL1 1
