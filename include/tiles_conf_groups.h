#define TILE_GROUP_LIST {(unsigned char)(TILE_LOOSE+65),1,0,(unsigned char)(TILE_POTION+129),5\
,0,TILE_GATE+1,TILE_TAPESTRY_TOP+1,0,(unsigned char)(TILE_GATE+65),2,TILE_WALL+1,0,(unsigned char)(TILE_POTION+129),3\
,0,TILE_EMPTY+1,TILE_SPIKES+1,TILE_BTN_RAISE+1,0\
,(unsigned char)(TILE_POTION+129),2,0,(unsigned char)(TILE_BTN_DROP+65),3\
,0,TILE_FLOOR+1,TILE_SPIKES+1,TILE_PILLAR+1,TILE_GATE+1\
,TILE_BTN_STUCK+1,TILE_BTN_DROP+1,TILE_BP_BOTTOM+1,TILE_POTION+1,(unsigned char)(TILE_LOOSE+65),4,TILE_MIRROR+1,TILE_DEBRIS+1,TILE_BTN_RAISE+1,TILE_EXIT_LEFT+1\
,TILE_EXIT_RIGHT+1,TILE_CHOPPER+1,TILE_TORCH+1,TILE_SKELETON+1,TILE_SWORD+1\
,TILE_TORCH_DEBRIS+1,0,TILE_WALL+1,0,TILE_GATE+1\
,0,(unsigned char)(TILE_FLOOR+129),1,0,(unsigned char)(TILE_FLOOR+129),2,0,TILE_GATE+1,TILE_EXIT_LEFT+1,0\
,(unsigned char)(TILE_POTION+129),4,0,(unsigned char)(TILE_BTN_DROP+65),5\
,0,TILE_POTION+1,0,TILE_BTN_DROP+1,TILE_BTN_RAISE+1\
,0,(unsigned char)(TILE_SPIKES+65),6,0,(unsigned char)(TILE_POTION+129),0,(unsigned char)(TILE_POTION+129),1,(unsigned char)(TILE_POTION+129),5\
,(unsigned char)(TILE_POTION+129),6,0,TILE_BTN_RAISE+1,0\
,TILE_SKELETON+1,0,TILE_SPIKES+1,0,(unsigned char)(TILE_EXIT_LEFT+65),7,0,TILE_EMPTY+1,(unsigned char)(TILE_LOOSE+65),8\
,0,TILE_TORCH+1,TILE_TORCH_DEBRIS+1,0,(unsigned char)(TILE_LOOSE+65),9,0,(unsigned char)(TILE_POTION+129),2,(unsigned char)(TILE_POTION+129),3,(unsigned char)(TILE_POTION+129),4,0,(unsigned char)(TILE_BTN_DROP+65),3,(unsigned char)(TILE_BTN_RAISE+65),3,0,(unsigned char)(TILE_POTION+129),1,0,TILE_SPIKES+1,TILE_LOOSE+1,TILE_CHOPPER+1\
,0,(unsigned char)(TILE_BTN_DROP+65),5,(unsigned char)(TILE_BTN_RAISE+65),5\
,0,TILE_SWORD+1,0,(unsigned char)(TILE_EMPTY+129),1\
,0,(unsigned char)(TILE_EMPTY+129),2,0,(unsigned char)(TILE_POTION+129),1,(unsigned char)(TILE_POTION+129),2,0,(unsigned char)(TILE_POTION+129),6,0,(unsigned char)(TILE_BTN_RAISE+65),5,0\
,(unsigned char)(TILE_BTN_RAISE+65),3,0,(unsigned char)(TILE_POTION+129),5\
,(unsigned char)(TILE_POTION+129),6,0,(unsigned char)(TILE_EMPTY+129),3\
,0,TILE_FLOOR+1,TILE_POTION+1,(unsigned char)(TILE_LOOSE+65),1\
,TILE_CHOPPER+1,TILE_TORCH+1,TILE_SWORD+1,0,TILE_CHOPPER+1\
,0,(unsigned char)(TILE_POTION+129),3,(unsigned char)(TILE_POTION+129),4\
,0,TILE_PILLAR+1,TILE_LATTICE_PILLAR+1,0,TILE_DEBRIS+1\
,TILE_TORCH_DEBRIS+1,0}
#define TILES_LOOSENORMAL 32
#define TILES_POISON 35
#define TILES_GATEFRAME 38
#define TILES_BLOCK 41
#define TILES_FEATHERFALL 45
#define TILES_DANGEROUS 48
#define TILES_LIFE 52
#define TILES_DROP_UNPRESSED 55
#define TILES_WALKABLE 58
#define TILES_WALL 79
#define TILES_DOOR 81
#define TILES_BRICKF1 83
#define TILES_BRICKF2 86
#define TILES_GATES 89
#define TILES_INVERT 92
#define TILES_DROP_PRESSED 95
#define TILES_POTION 98
#define TILES_PRESSABLE 100
#define TILES_SPIKEUP 103
#define TILES_SMALLPOTION 106
#define TILES_RAISE 115
#define TILES_SKELETON 117
#define TILES_SPIKES 119
#define TILES_EXITDOOR 121
#define TILES_SPACE 124
#define TILES_TORCH 128
#define TILES_LOOSEMOVING 131
#define TILES_BIGPOTION 134
#define TILES_UNPRESSED 141
#define TILES_HITPOINT 146
#define TILES_CHOPPER_SPIKE 149
#define TILES_PRESSED 153
#define TILES_SWORD 158
#define TILES_BRICKE1 160
#define TILES_BRICKE2 163
#define TILES_REDPOTION 166
#define TILES_OPEN 171
#define TILES_RAISE_PRESSED 174
#define TILES_RAISE_UNPRESSED 177
#define TILES_BLUEPOTION 180
#define TILES_WINDOW 185
#define TILES_FLOOR 188
#define TILES_CHOPPER 196
#define TILES_GREENPOTION 198
#define TILES_BROKENTILE 206
#define TILES_PILLAR 203

#define TILES_MACRO_1_1(a) ((tDanger*)((a).moreInfo))
#define TILES_MACRO_2_1(info) (info->action==eLosNormal)
#define TILES_MACRO_x_1(tile) TILES_MACRO_2_1(TILES_MACRO_1_1(tile))
#define TILES_MACRO_1_2(a) ((tGate*)((a).moreInfo))
#define TILES_MACRO_2_2(info) (info->frame>15)
#define TILES_MACRO_x_2(tile) TILES_MACRO_2_2(TILES_MACRO_1_2(tile))
#define TILES_MACRO_1_3(a) ((tPressable*)((a).moreInfo))
#define TILES_MACRO_2_3(info) (info->action==eNormal)
#define TILES_MACRO_x_3(tile) TILES_MACRO_2_3(TILES_MACRO_1_3(tile))
#define TILES_MACRO_1_4(a) ((tDanger*)((a).moreInfo))
#define TILES_MACRO_2_4(info) (info->action!=eLosDown)
#define TILES_MACRO_x_4(tile) TILES_MACRO_2_4(TILES_MACRO_1_4(tile))
#define TILES_MACRO_1_5(a) ((tPressable*)((a).moreInfo))
#define TILES_MACRO_2_5(info) (info->action!=eNormal)
#define TILES_MACRO_x_5(tile) TILES_MACRO_2_5(TILES_MACRO_1_5(tile))
#define TILES_MACRO_1_6(a) ((tDanger*)((a).moreInfo))
#define TILES_MACRO_2_6(info) (((2<info->frame)&&(info->frame<5)))
#define TILES_MACRO_x_6(tile) TILES_MACRO_2_6(TILES_MACRO_1_6(tile))
#define TILES_MACRO_1_7(a) ((tGate*)((a).moreInfo))
#define TILES_MACRO_2_7(info) (info->frame==0)
#define TILES_MACRO_x_7(tile) TILES_MACRO_2_7(TILES_MACRO_1_7(tile))
#define TILES_MACRO_1_8(a) ((tDanger*)((a).moreInfo))
#define TILES_MACRO_2_8(info) (info->action==eLosDown)
#define TILES_MACRO_x_8(tile) TILES_MACRO_2_8(TILES_MACRO_1_8(tile))
#define TILES_MACRO_1_9(a) ((tDanger*)((a).moreInfo))
#define TILES_MACRO_2_9(info) (info->action==eLosMoving)
#define TILES_MACRO_x_9(tile) TILES_MACRO_2_9(TILES_MACRO_1_9(tile))

#define TILES_MACROS_CASE(type,tile) switch (type) {\
	case 1:return TILES_MACRO_x_1(tile);\
	case 2:return TILES_MACRO_x_2(tile);\
	case 3:return TILES_MACRO_x_3(tile);\
	case 4:return TILES_MACRO_x_4(tile);\
	case 5:return TILES_MACRO_x_5(tile);\
	case 6:return TILES_MACRO_x_6(tile);\
	case 7:return TILES_MACRO_x_7(tile);\
	case 8:return TILES_MACRO_x_8(tile);\
	case 9:return TILES_MACRO_x_9(tile);\
	default:return 0;\
}

