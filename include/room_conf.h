
#define drawAllLeft(x,y,left,tile,right,dleft) \
if ( isIn(left,TILES_DOOR)) {\
drawAll((x)+(0),(y)+(2),   15);\
drawGate((x)+(0),(y)+(-TILE_H+3),   gateGetFrame(left));\
}\
if ( isIn(left,TILES_FLOOR)) {\
drawAll((x)+(0),(y)+(2),   10);\
}\
if ( isIn(left,TILES_LOOSEMOVING)) {\
drawLoose((x)+(0),(y)+(2),   looseGetFrame(left),layTritop);\
}\
if ( isIn(left,TILE_EXIT_RIGHT)) {\
drawAll((x)+(0),(y)+(2),   7);\
}\
if ( isIn(left,TILES_PILLAR)) {\
drawAll((x)+(0),(y)+(2),   44);\
}\
if ( isIn(left,TILE_BP_BOTTOM)) {\
drawAll((x)+(0),(y)+(2),   83);\
}\
if ( isIn(left,TILE_BP_TOP)) {\
drawAll((x)+(0),(y)+(3),   85);\
}\
if ( isIn(left,TILES_RAISE_PRESSED)) {\
drawAll((x)+(0),(y)+(2),   10);\
}\
if ( isIn(left,TILES_RAISE_UNPRESSED)) {\
drawAll((x)+(0),(y)+(1),   10);\
}\
if ( isIn(left,TILES_DROP_PRESSED)) {\
drawAll((x)+(0),(y)+(3),   10);\
}\
if ( isIn(left,TILES_DROP_UNPRESSED)) {\
drawAll((x)+(0),(y)+(2),   10);\
}\
if ( isIn(left,TILES_BROKENTILE)) {\
drawAll((x)+(0),(y)+(2),   49);\
}\
if ( isIn(left,TILES_SPIKES)) {\
drawAll((x)+(0),(y)+(2),   107);\
drawSpike((x)+(-TILE_W),(y)+(0),   spikeGetFrame(left),layRight);\
}\
if ( isIn(left,TILES_SKELETON)) {\
drawAll((x)+(0),(y)+(2),   81);\
}\
if ( isIn(left,TILES_SWORD)) {\
drawSword((x)+(-15),(y)+(-4)  );\
}\
if ( isIn(left,TILES_SMALLPOTION)) {\
drawPotionSmallBase((x)+(-15),(y)+(-4)  );\
}\
if ( (isIn(left,TILES_BIGPOTION))) {\
drawPotionBigBase((x)+(-15),(y)+(-4)  );\
}\
if ( isIn(left,TILES_REDPOTION)) {\
drawPotionRedBubbles((x)+(3-15),(y)+(-15),   isIn(left,TILES_BIGPOTION));\
}\
if ( isIn(left,TILES_GREENPOTION)) {\
drawPotionGreenBubbles((x)+(3-15),(y)+(-15),   isIn(left,TILES_BIGPOTION));\
}\
if ( isIn(left,TILES_BLUEPOTION)) {\
drawPotionBlueBubbles((x)+(3-15),(y)+(-15),   isIn(left,TILES_BIGPOTION));\
}

#define drawAllTile(x,y,left,tile,right,dleft) \
if ( (!isIn(tile,TILES_WALL))&&(isIn(left,TILES_WALL))) {\
drawAll((x)+(0),(y)+(2),   63);\
}\
if ( isIn(tile,TILES_TORCH)) {\
drawTorchFire((x)+(11+TILE_W),(y)+(-39)  );\
drawAll((x)+(3+TILE_W),(y)+(-24),   56);\
}\
if ( isIn(tile,TILE_CHOPPER)) {\
drawChopper((x)+(0),(y)+(0),   chopperGetFrame(tile),layCBack);\
}\
if ( isIn(tile,TILES_BRICKE1)) {\
drawAll((x)+(TILE_W+0),(y)+(-18),   52);\
}\
if ( isIn(tile,TILES_BRICKE2)) {\
drawAll((x)+(TILE_W+0),(y)+(-18),   53);\
}\
if ( isIn(tile,TILES_WINDOW)) {\
drawAll((x)+(TILE_W+0),(y)+(-18),   54);\
}\
if ( isIn(tile,TILES_BRICKF1)) {\
drawAll((x)+(TILE_W+0),(y)+(-18),   12);\
}\
if ( isIn(tile,TILES_BRICKF2)) {\
drawAll((x)+(TILE_W+0),(y)+(-18),   13);\
}\
if ( isIn(tile,TILES_DOOR)) {\
drawAll((x)+(0),(y)+(0),   14);\
}\
if ( isIn(tile,TILES_GATEFRAME)) {\
drawAll((x)+(24),(y)+(0),   17);\
}\
if ( isIn(tile,TILES_FLOOR)) {\
drawAll((x)+(0),(y)+(0),   9);\
}\
if ( isIn(tile,TILES_LOOSEMOVING)) {\
drawLoose((x)+(0),(y)+(0),   looseGetFrame(tile),layTribot);\
}\
if ( isIn(tile,TILE_EXIT_RIGHT)) {\
drawAll((x)+(0),(y)+(0),   5);\
}\
if ( isIn(tile,TILE_EXIT_LEFT)) {\
drawAll((x)+(0),(y)+(0),   9);\
drawExit((x)+(TILE_W+8),(y)+(-TILE_H-1),   gateGetFrame(tile));\
}\
if ( isIn(tile,TILES_PILLAR)) {\
drawAll((x)+(0),(y)+(0),   43);\
}\
if ( isIn(tile,TILE_BP_BOTTOM)) {\
drawAll((x)+(0),(y)+(0),   82);\
}\
if ( isIn(tile,TILE_BP_TOP)) {\
drawAll((x)+(8),(y)+(3),   87);\
}\
if ( isIn(tile,TILES_RAISE_UNPRESSED)&&isIn(left,TILES_WALKABLE)&&(!isIn(left,TILES_RAISE))) {\
drawAll((x)+(0),(y)+(0),   57);\
}\
if ( (isIn(tile,TILES_RAISE)&&((!isIn(tile,TILES_UNPRESSED))||(!isIn(left,TILES_WALKABLE))||isIn(left,TILES_RAISE)))&&(isIn(tile,TILES_UNPRESSED))) {\
drawAll((x)+(0),(y)+(0),   58);\
}\
if ( ((isIn(tile,TILES_RAISE)&&((!isIn(tile,TILES_UNPRESSED))||(!isIn(left,TILES_WALKABLE))||isIn(left,TILES_RAISE)))&&(!isIn(tile,TILES_UNPRESSED)))||isIn(tile,TILES_DROP_UNPRESSED)) {\
drawAll((x)+(0),(y)+(1),   58);\
}\
if ( isIn(tile,TILES_DROP_PRESSED)) {\
drawAll((x)+(0),(y)+(2),   58);\
}\
if ( isIn(tile,TILES_BROKENTILE)) {\
drawAll((x)+(0),(y)+(0),   48);\
}\
if ( isIn(tile,TILES_SPIKES)) {\
drawAll((x)+(0),(y)+(0),   101);\
drawSpike((x)+(0),(y)+(0),   spikeGetFrame(tile),layBack);\
}\
if ( isIn(tile,TILES_SKELETON)) {\
drawAll((x)+(0),(y)+(0),   80);\
}

#define drawAllBack(x,y,left,tile,right,dleft) \
if ( isIn(tile,TILES_LOOSEMOVING)) {\
drawLoose((x)+(0),(y)+(3),   looseGetFrame(tile),layBase);\
}\
if ( isIn(tile,TILES_UNPRESSED)) {\
drawAll((x)+(0),(y)+(3),   59);\
}\
if ( isIn(tile,TILES_PRESSED)) {\
drawAll((x)+(0),(y)+(4),   59);\
}\
if ( isIn(tile,TILES_WALKABLE) && !isIn(tile,TILES_LOOSEMOVING) && !isIn(tile,TILES_PRESSABLE)) {\
drawAll((x)+(0),(y)+(3),   11);\
}\
if ( wallCase(WALL_LOC_WWW)) {\
drawAll((x)+(0),(y)+(3),   65);\
}\
if ( wallCase(WALL_LOC_SWW)) {\
drawAll((x)+(0),(y)+(3),   71);\
}\
if ( wallCase(WALL_LOC_WWS)) {\
drawAll((x)+(0),(y)+(3),   67);\
}\
if ( wallCase(WALL_LOC_SWS)) {\
drawAll((x)+(0),(y)+(3),   69);\
}\
if ( isIn(tile,TILES_SPACE) && isIn(tile,TILES_GATEFRAME)) {\
drawAll((x)+(0),(y)+(3),   42);\
}\
if ( isIn(tile,TILES_SPACE) && isIn(dleft,TILES_DOOR)) {\
drawAll((x)+(0),(y)+(3),   16);\
}\
if ( isIn(tile,TILES_SPACE) && isIn(dleft,TILE_BP_TOP)) {\
drawAll((x)+(0),(y)+(3),   86);\
}\
if ( isIn(tile,TILES_SPACE) && isIn(dleft,TILES_PILLAR)) {\
drawAll((x)+(0),(y)+(3),   45);\
}\
if ( isIn(tile,TILES_SPACE) && isIn(dleft,TILES_WALL)) {\
drawAll((x)+(0),(y)+(3),   64);\
}\
if ( isIn(tile,TILE_EXIT_LEFT)) {\
drawAll((x)+(0+TILE_W),(y)+(-TILE_H+3),   6);\
}\
if ( isIn(tile,TILE_EXIT_RIGHT)) {\
drawAll((x)+(0+TILE_W),(y)+(-TILE_H+3),   8);\
}

#define drawAllFore(x,y,left,tile,right,dleft) \
if ( isIn(tile,TILES_PILLAR)) {\
drawAll((x)+(8),(y)+(0),   46);\
}\
if ( isIn(tile,TILE_BP_BOTTOM)) {\
drawAll((x)+(8),(y)+(0),   84);\
}\
if ( wallCase(WALL_LOC_WWW)) {\
drawAll((x)+(0),(y)+(0),   66);\
}\
if ( wallCase(WALL_LOC_SWW)) {\
drawAll((x)+(0),(y)+(0),   72);\
}\
if ( wallCase(WALL_LOC_WWS)) {\
drawAll((x)+(0),(y)+(0),   68);\
}\
if ( wallCase(WALL_LOC_SWS)) {\
drawAll((x)+(0),(y)+(0),   70);\
}\
if ( wallGetInfo(WALL_TABLE_LINE1_DARKER)) {\
drawAll((x)+(0),(y)+(-39),   75);\
}\
if ( wallGetInfo(WALL_TABLE_LINE1_LEFT_DOWN)) {\
drawAll((x)+(0),(y)+(-39),   77);\
}\
if ( wallGetInfo(WALL_TABLE_LINE1_RIGHT_DOWN)) {\
drawAll((x)+(24),(y)+(-39),   79);\
}\
if ( wallGetInfo(WALL_TABLE_LINE1_RIGHT_UP)) {\
drawAll((x)+(24),(y)+(-49),   78);\
}\
if ( wallGetInfo(WALL_TABLE_LINE1_LEFT_UP)) {\
drawAll((x)+(0),(y)+(-54),   76);\
}\
if ( isIn(tile,TILES_WALL)) {\
drawAll((x)+(7+wallGetInfo(WALL_TABLE_LINE2_OFFSET)),(y)+(-18),   74-wallGetInfo(WALL_TABLE_LINE2_SEP));\
}\
if ( wallGetInfo(WALL_TABLE_LINE2_LEFT_DOWN)) {\
drawAll((x)+(7+wallGetInfo(WALL_TABLE_LINE2_OFFSET)+5),(y)+(-39+21),   77);\
}\
if ( wallGetInfo(WALL_TABLE_LINE2_RIGHT_DOWN)) {\
drawAll((x)+(24+7+wallGetInfo(WALL_TABLE_LINE2_OFFSET)-32+5),(y)+(-39+21),   79);\
}\
if ( wallGetInfo(WALL_TABLE_LINE2_RIGHT_UP)) {\
drawAll((x)+(24+7+wallGetInfo(WALL_TABLE_LINE2_OFFSET)-32+5),(y)+(-49+21),   78);\
}\
if ( wallGetInfo(WALL_TABLE_LINE2_LEFT_UP)) {\
drawAll((x)+(7+wallGetInfo(WALL_TABLE_LINE2_OFFSET)+5),(y)+(-54+21),   76);\
}\
if ( isIn(tile,TILES_WALL)) {\
drawAll((x)+(3+wallGetInfo(WALL_TABLE_LINE3_OFFSET)),(y)+(3),   74-wallGetInfo(WALL_TABLE_LINE3_SEP));\
}\
if ( wallGetInfo(WALL_TABLE_LINE3_LEFT_UP)) {\
drawAll((x)+(5+wallGetInfo(WALL_TABLE_LINE3_OFFSET)+5),(y)+(-55+21*2),   76);\
}\
if ( isIn(tile,TILES_BROKENTILE)) {\
drawAll((x)+(0),(y)+(0),   51);\
}\
if ( isIn(tile,TILES_SPIKES)) {\
drawSpike((x)+(0),(y)+(0),   spikeGetFrame(tile),layFore);\
}\

