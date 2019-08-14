#define STATES_MOVETYPES_ABSOLUTEONSTART 0
#define STATES_MOVETYPES_ABSOLUTEONSTOP 1
#define STATES_MOVETYPES_RELATIVETURN 2
#define STATES_MOVETYPES_RELATIVE 3
#define STATES_CONDITIONS {\
	{esLast,0}, /* condition number 0 */\
	{esMapNotOn,TILES_WALKABLE}, /* condition number 1 */\
	{esMapOn,TILES_WALKABLE}, /* condition number 2 */\
	{esLast,0}, /* condition number 3 */\
	{esKeyUp,STATES_KEY_PRESSED}, /* condition number 4 */\
	{esKeyForward,STATES_KEY_PRESSED}, /* condition number 5 */\
	{esLast,0}, /* condition number 6 */\
	{esKeyUp,STATES_KEY_PRESSED}, /* condition number 7 */\
	{esMapOn,TILES_EXITDOOR}, /* condition number 8 */\
	{esLast,0}, /* condition number 9 */\
	{esKeyUp,STATES_KEY_PRESSED}, /* condition number 10 */\
	{esMapBackUp,TILES_SPACE}, /* condition number 11 */\
	{esMapUp,TILES_WALKABLE}, /* condition number 12 */\
	{esLast,0}, /* condition number 13 */\
	{esKeyUp,STATES_KEY_PRESSED}, /* condition number 14 */\
	{esMapUp,TILES_SPACE}, /* condition number 15 */\
	{esMapUpForward,TILES_WALKABLE}, /* condition number 16 */\
	{esLast,0}, /* condition number 17 */\
	{esKeyUp,STATES_KEY_PRESSED}, /* condition number 18 */\
	{esMapUp,TILES_SPACE}, /* condition number 19 */\
	{esMapForward,TILES_BLOCK}, /* condition number 20 */\
	{esLast,0}, /* condition number 21 */\
	{esKeyUp,STATES_KEY_PRESSED}, /* condition number 22 */\
	{esMapUp,TILES_SPACE}, /* condition number 23 */\
	{esLast,0}, /* condition number 24 */\
	{esKeyUp,STATES_KEY_PRESSED}, /* condition number 25 */\
	{esLast,0}, /* condition number 26 */\
	{esKeyShift,STATES_KEY_PRESSED}, /* condition number 27 */\
	{esKeyForward,STATES_KEY_PRESSED}, /* condition number 28 */\
	{esForwardTileNearerThan,13}, /* condition number 29 */\
	{esMapNotForward,TILES_WALKABLE}, /* condition number 30 */\
	{esLast,0}, /* condition number 31 */\
	{esKeyShift,STATES_KEY_PRESSED}, /* condition number 32 */\
	{esKeyForward,STATES_KEY_PRESSED}, /* condition number 33 */\
	{esLast,0}, /* condition number 34 */\
	{esKeyForward,STATES_KEY_PRESSED}, /* condition number 35 */\
	{esLast,0}, /* condition number 36 */\
	{esKeyBack,STATES_KEY_PRESSED}, /* condition number 37 */\
	{esLast,0}, /* condition number 38 */\
	{esKeyDown,STATES_KEY_PRESSED}, /* condition number 39 */\
	{esMapNotDownBack,TILES_WALKABLE}, /* condition number 40 */\
	{esMapNotBack,TILES_WALKABLE}, /* condition number 41 */\
	{esLast,0}, /* condition number 42 */\
	{esKeyDown,STATES_KEY_PRESSED}, /* condition number 43 */\
	{esMapDownBack,TILES_WALKABLE}, /* condition number 44 */\
	{esMapNotBack,TILES_WALKABLE}, /* condition number 45 */\
	{esLast,0}, /* condition number 46 */\
	{esKeyDown,STATES_KEY_PRESSED}, /* condition number 47 */\
	{esLast,0}, /* condition number 48 */\
	{esMapOn,TILES_POTION}, /* condition number 49 */\
	{esKeyShift,STATES_KEY_PRESSED}, /* condition number 50 */\
	{esLast,0}, /* condition number 51 */\
	{esKeyDown,STATES_KEY_PRESSED}, /* condition number 52 */\
	{esKeyForward,STATES_KEY_PRESSED}, /* condition number 53 */\
	{esLast,0}, /* condition number 54 */\
	{esKeyUp,STATES_KEY_PRESSED}, /* condition number 55 */\
	{esKeyForward,STATES_KEY_PRESSED}, /* condition number 56 */\
	{esForwardTileNearerThan,95}, /* condition number 57 */\
	{esMapNotForward,TILES_WALKABLE}, /* condition number 58 */\
	{esLast,0}, /* condition number 59 */\
	{esKeyUp,STATES_KEY_PRESSED}, /* condition number 60 */\
	{esKeyForward,STATES_KEY_PRESSED}, /* condition number 61 */\
	{esLast,0}, /* condition number 62 */\
	{esKeyForward,STATES_KEY_PRESSED}, /* condition number 63 */\
	{esLast,0}, /* condition number 64 */\
	{esKeyBack,STATES_KEY_PRESSED}, /* condition number 65 */\
	{esLast,0}, /* condition number 66 */\
	{esKeyDown,STATES_KEY_PRESSED}, /* condition number 67 */\
	{esKeyForward,STATES_KEY_PRESSED}, /* condition number 68 */\
	{esLast,0}, /* condition number 69 */\
	{esKeyDown,STATES_KEY_PRESSED}, /* condition number 70 */\
	{esLast,0}, /* condition number 71 */\
	{esKeyUp,STATES_KEY_PRESSED}, /* condition number 72 */\
	{esLast,0}, /* condition number 73 */\
	{esKeyUp,STATES_KEY_PRESSED}, /* condition number 74 */\
	{esLast,0}, /* condition number 75 */\
	{esMapNotDownBack,TILES_WALKABLE}, /* condition number 76 */\
	{esMapNotBack,TILES_WALKABLE}, /* condition number 77 */\
	{esLast,0}, /* condition number 78 */\
	{esMapDownBack,TILES_WALKABLE}, /* condition number 79 */\
	{esMapNotBack,TILES_WALKABLE}, /* condition number 80 */\
	{esLast,0}, /* condition number 81 */\
	{esMapDown,TILES_SPIKES}, /* condition number 82 */\
	{esLast,0}, /* condition number 83 */\
	{esMapDown,TILES_WALKABLE}, /* condition number 84 */\
	{esLast,0}, /* condition number 85 */\
	{esMapDown,TILES_SPIKES}, /* condition number 86 */\
	{esLast,0}, /* condition number 87 */\
	{esMapDown,TILES_WALKABLE}, /* condition number 88 */\
	{esLast,0}, /* condition number 89 */\
	{esMapDown,TILES_SPIKES}, /* condition number 90 */\
	{esLast,0}, /* condition number 91 */\
	{esMapDown,TILES_WALKABLE}, /* condition number 92 */\
	{esLast,0} /* the end */\
}

#define STATES_ACTIONS {\
	/* Action: ToFall (0) \
	 * State: create (0) \
	 * Animations: animStart=0, animSize=1 \
	 * Conditionals: conditionId=1, nextStateId=32 (falling1) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{1,STATES_MOVETYPES_RELATIVE,0,32,0,1},\
	/* Action: Jump (1) \
	 * Animations: animStart=1, animSize=18 \
	 * Conditionals: conditionId=4, nextStateId=0 (normal) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{4,STATES_MOVETYPES_RELATIVE,0,0,1,18},\
	/* Action: Pass level (2) \
	 * Animations: animStart=19, animSize=12 \
	 * Conditionals: conditionId=7, nextStateId=0 (normal) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{7,STATES_MOVETYPES_RELATIVE,0,0,19,12},\
	/* Action: Climb up, going backwards (3) \
	 * Animations: animStart=31, animSize=17 \
	 * Conditionals: conditionId=10, nextStateId=27 (climbingup) \
	 * Movements: moveType=absoluteonstart, moveOffset=-32 */ \
		{10,STATES_MOVETYPES_ABSOLUTEONSTART,-32,27,31,17},\
	/* Action: Climb up (4) \
	 * Animations: animStart=48, animSize=17 \
	 * Conditionals: conditionId=14, nextStateId=27 (climbingup) \
	 * Movements: moveType=absoluteonstart, moveOffset=0 */ \
		{14,STATES_MOVETYPES_ABSOLUTEONSTART,0,27,48,17},\
	/* Action: Jump up with free space up and a block in front (5) \
	 * Animations: animStart=65, animSize=17 \
	 * Conditionals: conditionId=18, nextStateId=0 (normal) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{18,STATES_MOVETYPES_RELATIVE,0,0,65,17},\
	/* Action: Jump up with free space up (6) \
	 * Animations: animStart=82, animSize=20 \
	 * Conditionals: conditionId=22, nextStateId=0 (normal) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{22,STATES_MOVETYPES_RELATIVE,0,0,82,20},\
	/* Action: Jump up with cieling (7) \
	 * Animations: animStart=102, animSize=15 \
	 * Conditionals: conditionId=25, nextStateId=0 (normal) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{25,STATES_MOVETYPES_RELATIVE,0,0,102,15},\
	/* Action: Walking a step, getting near the border (8) \
	 * Animations: animStart=117, animSize=13 \
	 * Conditionals: conditionId=27, nextStateId=0 (normal) \
	 * Movements: moveType=absoluteonstop, moveOffset=-2 */ \
		{27,STATES_MOVETYPES_ABSOLUTEONSTOP,-2,0,117,13},\
	/* Action: Walking a step (9) \
	 * Animations: animStart=130, animSize=12 \
	 * Conditionals: conditionId=32, nextStateId=0 (normal) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{32,STATES_MOVETYPES_RELATIVE,0,0,130,12},\
	/* Action: Start running (10) \
	 * Animations: animStart=142, animSize=8 \
	 * Conditionals: conditionId=35, nextStateId=17 (running) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{35,STATES_MOVETYPES_RELATIVE,0,17,142,8},\
	/* Action: Turn (11) \
	 * Animations: animStart=150, animSize=8 \
	 * Conditionals: conditionId=37, nextStateId=0 (normal) \
	 * Movements: moveType=relativeturn, moveOffset=5 */ \
		{37,STATES_MOVETYPES_RELATIVETURN,5,0,150,8},\
	/* Action: Climb Down to empty (12) \
	 * Animations: animStart=158, animSize=12 \
	 * Conditionals: conditionId=39, nextStateId=29 (hangedup) \
	 * Movements: moveType=absoluteonstart, moveOffset=-32 */ \
		{39,STATES_MOVETYPES_ABSOLUTEONSTART,-32,29,158,12},\
	/* Action: Climb Down to walkable place (13) \
	 * Animations: animStart=170, animSize=12 \
	 * Conditionals: conditionId=43, nextStateId=29 (hangedup) \
	 * Movements: moveType=absoluteonstart, moveOffset=-32 */ \
		{43,STATES_MOVETYPES_ABSOLUTEONSTART,-32,29,170,12},\
	/* Action: Crouch (14) \
	 * Animations: animStart=182, animSize=3 \
	 * Conditionals: conditionId=47, nextStateId=23 (crouched) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{47,STATES_MOVETYPES_RELATIVE,0,23,182,3},\
	/* Action: Drink potion (15) \
	 * Animations: animStart=185, animSize=23 \
	 * Conditionals: conditionId=49, nextStateId=0 (normal) \
	 * Movements: moveType=absoluteonstart, moveOffset=-20 */ \
		{49,STATES_MOVETYPES_ABSOLUTEONSTART,-20,0,185,23},\
	/* Action: If there aren't more actions then the normal state is kept (16) \
	 * Animations: animStart=208, animSize=1 \
	 * Conditionals: conditionId=0, nextStateId=0 (normal) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{0,STATES_MOVETYPES_RELATIVE,0,0,208,1},\
	/* Action: Crouch (17) \
	 * State: running (17) \
	 * Animations: animStart=209, animSize=3 \
	 * Conditionals: conditionId=52, nextStateId=23 (crouched) \
	 * Movements: moveType=relative, moveOffset=2 */ \
		{52,STATES_MOVETYPES_RELATIVE,2,23,209,3},\
	/* Action: Jump Running, getting to the border to jump (18) \
	 * Animations: animStart=212, animSize=5 \
	 * Conditionals: conditionId=55, nextStateId=26 (jumping) \
	 * Movements: moveType=absoluteonstop, moveOffset=-2 */ \
		{55,STATES_MOVETYPES_ABSOLUTEONSTOP,-2,26,212,5},\
	/* Action: Jump Running (19) \
	 * Animations: animStart=217, animSize=12 \
	 * Conditionals: conditionId=60, nextStateId=17 (running) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{60,STATES_MOVETYPES_RELATIVE,0,17,217,12},\
	/* Action: Keep running (20) \
	 * Animations: animStart=229, animSize=6 \
	 * Conditionals: conditionId=63, nextStateId=17 (running) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{63,STATES_MOVETYPES_RELATIVE,0,17,229,6},\
	/* Action: Turn (21) \
	 * Animations: animStart=235, animSize=13 \
	 * Conditionals: conditionId=65, nextStateId=17 (running) \
	 * Movements: moveType=relativeturn, moveOffset=0 */ \
		{65,STATES_MOVETYPES_RELATIVETURN,0,17,235,13},\
	/* Action: Stop running (22) \
	 * Animations: animStart=248, animSize=8 \
	 * Conditionals: conditionId=0, nextStateId=0 (normal) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{0,STATES_MOVETYPES_RELATIVE,0,0,248,8},\
	/* Action: Walk crouched (23) \
	 * State: crouched (23) \
	 * Animations: animStart=256, animSize=4 \
	 * Conditionals: conditionId=67, nextStateId=23 (crouched) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{67,STATES_MOVETYPES_RELATIVE,0,23,256,4},\
	/* Action: Stay Crouch (24) \
	 * Animations: animStart=260, animSize=1 \
	 * Conditionals: conditionId=70, nextStateId=23 (crouched) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{70,STATES_MOVETYPES_RELATIVE,0,23,260,1},\
	/* Action: Get up (25) \
	 * Animations: animStart=261, animSize=10 \
	 * Conditionals: conditionId=0, nextStateId=0 (normal) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{0,STATES_MOVETYPES_RELATIVE,0,0,261,10},\
	/* Action: jumping (26) \
	 * State: jumping (26) \
	 * Animations: animStart=271, animSize=7 \
	 * Conditionals: conditionId=0, nextStateId=17 (running) \
	 * Movements: moveType=absoluteonstart, moveOffset=-32 */ \
		{0,STATES_MOVETYPES_ABSOLUTEONSTART,-32,17,271,7},\
	/* Action: continue climbing up (27) \
	 * State: climbingup (27) \
	 * Animations: animStart=278, animSize=15 \
	 * Conditionals: conditionId=72, nextStateId=0 (normal) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{72,STATES_MOVETYPES_RELATIVE,0,0,278,15},\
	/* Action: Climb down in the middle (28) \
	 * Animations: animStart=293, animSize=2 \
	 * Conditionals: conditionId=0, nextStateId=0 (normal) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{0,STATES_MOVETYPES_RELATIVE,0,0,293,2},\
	/* Action: Climb up in the middle (29) \
	 * State: hangedup (29) \
	 * Animations: animStart=295, animSize=13 \
	 * Conditionals: conditionId=74, nextStateId=0 (normal) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{74,STATES_MOVETYPES_RELATIVE,0,0,295,13},\
	/* Action: Climb Down to empty (30) \
	 * Animations: animStart=308, animSize=4 \
	 * Conditionals: conditionId=76, nextStateId=32 (falling1) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{76,STATES_MOVETYPES_RELATIVE,0,32,308,4},\
	/* Action: Climb Down to walkable place (31) \
	 * Animations: animStart=312, animSize=4 \
	 * Conditionals: conditionId=79, nextStateId=0 (normal) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{79,STATES_MOVETYPES_RELATIVE,0,0,312,4},\
	/* Action: falling to spikes (32) \
	 * State: falling1 (32) \
	 * Animations: animStart=316, animSize=6 \
	 * Conditionals: conditionId=82, nextStateId=41 (spiked) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{82,STATES_MOVETYPES_RELATIVE,0,41,316,6},\
	/* Action: falling to a walkable place (33) \
	 * Animations: animStart=322, animSize=5 \
	 * Conditionals: conditionId=84, nextStateId=23 (crouched) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{84,STATES_MOVETYPES_RELATIVE,0,23,322,5},\
	/* Action: Continue falling (34) \
	 * Animations: animStart=327, animSize=5 \
	 * Conditionals: conditionId=0, nextStateId=35 (falling2) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{0,STATES_MOVETYPES_RELATIVE,0,35,327,5},\
	/* Action: falling to spikes (35) \
	 * State: falling2 (35) \
	 * Animations: animStart=332, animSize=6 \
	 * Conditionals: conditionId=86, nextStateId=41 (spiked) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{86,STATES_MOVETYPES_RELATIVE,0,41,332,6},\
	/* Action: falling to a walkable place (36) \
	 * Animations: animStart=338, animSize=4 \
	 * Conditionals: conditionId=88, nextStateId=23 (crouched) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{88,STATES_MOVETYPES_RELATIVE,0,23,338,4},\
	/* Action: Continue falling (37) \
	 * Animations: animStart=342, animSize=4 \
	 * Conditionals: conditionId=0, nextStateId=38 (falling3) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{0,STATES_MOVETYPES_RELATIVE,0,38,342,4},\
	/* Action: falling to spikes (38) \
	 * State: falling3 (38) \
	 * Animations: animStart=346, animSize=6 \
	 * Conditionals: conditionId=90, nextStateId=41 (spiked) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{90,STATES_MOVETYPES_RELATIVE,0,41,346,6},\
	/* Action: falling to a walkable place (39) \
	 * Animations: animStart=352, animSize=5 \
	 * Conditionals: conditionId=92, nextStateId=42 (splash) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{92,STATES_MOVETYPES_RELATIVE,0,42,352,5},\
	/* Action: Continue falling (40) \
	 * Animations: animStart=357, animSize=3 \
	 * Conditionals: conditionId=0, nextStateId=38 (falling3) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{0,STATES_MOVETYPES_RELATIVE,0,38,357,3},\
	/* Action: speaked forever (41) \
	 * State: spiked (41) \
	 * Animations: animStart=360, animSize=1 \
	 * Conditionals: conditionId=0, nextStateId=41 (spiked) \
	 * Movements: moveType=absoluteonstart, moveOffset=-16 */ \
		{0,STATES_MOVETYPES_ABSOLUTEONSTART,-16,41,360,1},\
	/* Action: dead forever (42) \
	 * State: splash (42) \
	 * Animations: animStart=361, animSize=1 \
	 * Conditionals: conditionId=0, nextStateId=42 (splash) \
	 * Movements: moveType=absoluteonstart, moveOffset=-16 */ \
		{0,STATES_MOVETYPES_ABSOLUTEONSTART,-16,42,361,1},\
	/* Action: you are in two parts, ouch! (43) \
	 * State: chopped (43) \
	 * Animations: animStart=362, animSize=1 \
	 * Conditionals: conditionId=0, nextStateId=43 (chopped) \
	 * Movements: moveType=absoluteonstart, moveOffset=-16 */ \
		{0,STATES_MOVETYPES_ABSOLUTEONSTART,-16,43,362,1},\
	/* Action:  (44) \
	 * State: crashed (44) \
	 * Animations: animStart=363, animSize=1 \
	 * Conditionals: conditionId=0, nextStateId=0 (normal) \
	 * Movements: moveType=absoluteonstart, moveOffset=-34 */ \
		{0,STATES_MOVETYPES_ABSOLUTEONSTART,-34,0,363,1},\
	/* Action: crash against a wall (45) \
	 * State: none (45) \
	 * Animations: animStart=364, animSize=1 \
	 * Conditionals: conditionId=0, nextStateId=44 (crashed) \
	 * Movements: moveType=absoluteonstart, moveOffset=-34 */ \
		{0,STATES_MOVETYPES_ABSOLUTEONSTART,-34,44,364,1},\
	/* Action: Jaffar sais hi to the princess (46) \
	 * State: walkingjaffar (46) \
	 * Animations: animStart=365, animSize=19 \
	 * Conditionals: conditionId=0, nextStateId=47 (conjuring) \
	 * Movements: moveType=relative, moveOffset=15 */ \
		{0,STATES_MOVETYPES_RELATIVE,15,47,365,19},\
	/* Action: Jaffar conjuring (47) \
	 * State: conjuring (47) \
	 * Animations: animStart=384, animSize=19 \
	 * Conditionals: conditionId=0, nextStateId=-2 (exit JAFFAR) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{0,STATES_MOVETYPES_RELATIVE,0,-2,384,19},\
	/* Action: Lighting (48) \
	 * State: torch (48) \
	 * Animations: animStart=403, animSize=9 \
	 * Conditionals: conditionId=0, nextStateId=48 (torch) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{0,STATES_MOVETYPES_RELATIVE,0,48,403,9},\
	/* Action: Stars blinking (49) \
	 * State: stars (49) \
	 * Animations: animStart=412, animSize=6 \
	 * Conditionals: conditionId=0, nextStateId=49 (stars) \
	 * Movements: moveType=relative, moveOffset=0 */ \
		{0,STATES_MOVETYPES_RELATIVE,0,49,412,6}\
}

#define STATES_ANIMATIONS {\
	15,STATES_FLAG_HEIGHTOFFSET|0,2,/* h= */5,16,0,3,/* h= */0,17,0,3,/* h= */0,18,0,3,/* h= */0,19,0,3,/* h= */0,20,0,3,/* h= */0,21,0,3,/* h= */0,22,0,3,/* h= */0,23,0,3,/* h= */0,24,0,3,/* h= */0\
	,25,0,3,/* h= */0,26,0,3,/* h= */0,27,0,3,/* h= */0,28,STATES_FLAG_P|STATES_FLAG_S|0,0,/* h= */0,29,STATES_FLAG_P|0,4,/* h= */0,30,STATES_FLAG_P|0,4,/* h= */0,31,STATES_FLAG_P|0,4,/* h= */0,32,STATES_FLAG_P|0,4,/* h= */0,33,STATES_FLAG_P|0,4,/* h= */0,53,0,0,/* h= */0\
	,54,0,0,/* h= */0,55,0,0,/* h= */0,56,0,0,/* h= */0,57,0,0,/* h= */0,58,0,0,/* h= */0,59,0,0,/* h= */0,60,0,0,/* h= */0,61,0,0,/* h= */0,62,0,0,/* h= */0,63,0,0,/* h= */0\
	,64,0,0,/* h= */0,81,0,0,/* h= */0,82,0,0,/* h= */0,83,0,0,/* h= */0,84,0,0,/* h= */0,85,0,0,/* h= */0,86,0,0,/* h= */0,87,0,0,/* h= */0,88,0,0,/* h= */0,89,0,0,/* h= */0\
	,90,0,0,/* h= */0,91,0,0,/* h= */0,92,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */12,93,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */12,96,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */12,97,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */12,145,0,0,/* h= */0,146,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */20,81,0,0,/* h= */0,82,0,0,/* h= */0\
	,83,0,0,/* h= */0,84,0,0,/* h= */0,85,0,0,/* h= */0,86,0,0,/* h= */0,87,0,0,/* h= */0,88,0,0,/* h= */0,89,0,0,/* h= */0,90,0,0,/* h= */0,91,0,0,/* h= */0,92,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */12\
	,93,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */12,96,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */12,97,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */12,145,0,0,/* h= */0,146,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */20,81,0,0,/* h= */0,82,0,0,/* h= */0,83,0,0,/* h= */0,84,0,0,/* h= */0,85,0,0,/* h= */0\
	,86,0,0,/* h= */0,87,0,0,/* h= */0,88,0,0,/* h= */0,89,0,0,/* h= */0,90,0,0,/* h= */0,91,0,0,/* h= */0,92,0,0,/* h= */0,93,0,0,/* h= */0,96,0,0,/* h= */0,97,0,0,/* h= */0\
	,98,0,0,/* h= */0,99,0,0,/* h= */0,81,0,0,/* h= */0,82,0,0,/* h= */0,83,0,0,/* h= */0,84,0,0,/* h= */0,85,0,0,/* h= */0,86,0,0,/* h= */0,87,0,0,/* h= */0,88,0,0,/* h= */0\
	,89,0,0,/* h= */0,90,0,0,/* h= */0,91,0,0,/* h= */0,92,0,0,/* h= */0,93,0,0,/* h= */0,93,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */3,93,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */6,93,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */9,96,0,2,/* h= */0,97,0,2,/* h= */0\
	,98,0,2,/* h= */0,99,0,2,/* h= */0,81,0,0,/* h= */0,82,0,0,/* h= */0,83,0,0,/* h= */0,84,0,0,/* h= */0,85,0,0,/* h= */0,86,0,0,/* h= */0,87,0,0,/* h= */0,88,0,0,/* h= */0\
	,89,0,0,/* h= */0,90,0,0,/* h= */0,91,0,0,/* h= */0,92,0,0,/* h= */0,97,0,0,/* h= */0,98,0,0,/* h= */0,99,0,0,/* h= */0,15,STATES_FLAG_P|0,0,/* h= */0,134,STATES_FLAG_P|0,1,/* h= */0,135,STATES_FLAG_P|0,1,/* h= */0\
	,136,0,5,/* h= */0,137,0,3,/* h= */0,138,0,3,/* h= */0,139,0,3,/* h= */0,140,0,3,/* h= */0,141,STATES_FLAG_P|0,1,/* h= */0,142,STATES_FLAG_P|0,1,/* h= */0,143,STATES_FLAG_P|0,1,/* h= */0,144,STATES_FLAG_P|0,1,/* h= */0,145,STATES_FLAG_P|0,1,/* h= */0\
	,134,0,1,/* h= */0,135,0,1,/* h= */0,136,0,5,/* h= */0,137,0,3,/* h= */0,138,0,3,/* h= */0,139,0,3,/* h= */0,140,0,3,/* h= */0,141,STATES_FLAG_P|0,1,/* h= */0,142,STATES_FLAG_P|0,1,/* h= */0,143,STATES_FLAG_P|0,1,/* h= */0\
	,144,STATES_FLAG_P|0,1,/* h= */0,145,STATES_FLAG_P|0,1,/* h= */0,1,0,2,/* h= */0,2,0,2,/* h= */0,3,STATES_FLAG_P|0,4,/* h= */0,4,STATES_FLAG_P|0,4,/* h= */0,5,STATES_FLAG_P|0,4,/* h= */0,6,STATES_FLAG_P|0,4,/* h= */0,7,STATES_FLAG_P|0,4,/* h= */0,8,STATES_FLAG_P|0,4,/* h= */0\
	,45,STATES_FLAG_P|0,0,/* h= */0,46,STATES_FLAG_P|0,0,/* h= */0,47,STATES_FLAG_P|0,0,/* h= */0,48,STATES_FLAG_P|0,0,/* h= */0,49,STATES_FLAG_P|0,0,/* h= */0,50,STATES_FLAG_P|0,0,/* h= */0,51,STATES_FLAG_P|0,0,/* h= */0,52,STATES_FLAG_P|0,0,/* h= */0,154,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-10,155,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-10\
	,156,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-10,157,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-10,158,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-10,159,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-10,160,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-10,152,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-25,153,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-25,149,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-35,150,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-35,151,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-35\
	,154,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-10,155,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-10,156,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-10,157,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-10,158,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-10,159,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-10,160,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-10,152,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-25,153,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-25,149,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-35\
	,150,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-35,151,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-35,118,STATES_FLAG_P|0,0,/* h= */0,119,STATES_FLAG_P|0,0,/* h= */0,120,STATES_FLAG_P|0,0,/* h= */0,118,STATES_FLAG_P|0,0,/* h= */0,119,STATES_FLAG_P|0,0,/* h= */0,120,STATES_FLAG_P|0,0,/* h= */0,193,STATES_FLAG_P|0,0,/* h= */0,194,STATES_FLAG_P|0,0,/* h= */0\
	,195,STATES_FLAG_P|0,0,/* h= */0,196,STATES_FLAG_P|0,0,/* h= */0,197,STATES_FLAG_P|0,0,/* h= */0,198,STATES_FLAG_P|0,0,/* h= */0,199,STATES_FLAG_P|0,0,/* h= */0,200,STATES_FLAG_P|0,0,/* h= */0,201,STATES_FLAG_P|0,0,/* h= */0,202,STATES_FLAG_P|0,0,/* h= */0,203,STATES_FLAG_P|0,0,/* h= */0,204,STATES_FLAG_P|0,0,/* h= */0\
	,205,STATES_FLAG_P|0,0,/* h= */0,206,STATES_FLAG_P|0,0,/* h= */0,207,STATES_FLAG_P|0,0,/* h= */0,207,STATES_FLAG_P|STATES_FLAG_D|0,0,/* h= */0,207,STATES_FLAG_P|0,0,/* h= */0,207,STATES_FLAG_P|0,0,/* h= */0,206,STATES_FLAG_P|0,0,/* h= */0,205,STATES_FLAG_P|0,0,/* h= */0,15,STATES_FLAG_P|0,0,/* h= */0,118,STATES_FLAG_P|0,0,/* h= */0\
	,119,STATES_FLAG_P|0,0,/* h= */0,120,STATES_FLAG_P|0,0,/* h= */0,34,STATES_FLAG_P|0,10,/* h= */0,35,STATES_FLAG_P|0,10,/* h= */0,36,STATES_FLAG_P|0,10,/* h= */0,37,STATES_FLAG_P|0,10,/* h= */0,38,STATES_FLAG_P|0,0,/* h= */0,34,STATES_FLAG_P|0,10,/* h= */0,35,STATES_FLAG_P|0,10,/* h= */0,36,STATES_FLAG_P|0,10,/* h= */0\
	,37,STATES_FLAG_P|0,10,/* h= */0,38,STATES_FLAG_P|0,0,/* h= */0,39,0,15,/* h= */0,40,STATES_FLAG_HEIGHTOFFSET|0,15,/* h= */7,41,STATES_FLAG_HEIGHTOFFSET|0,15,/* h= */10,42,STATES_FLAG_HEIGHTOFFSET|0,15,/* h= */7,43,STATES_FLAG_HEIGHTOFFSET|0,15,/* h= */5,44,0,10,/* h= */0,44,STATES_FLAG_P|0,10,/* h= */0,9,STATES_FLAG_P|0,6,/* h= */0\
	,10,STATES_FLAG_P|0,8,/* h= */0,11,STATES_FLAG_P|0,8,/* h= */0,12,STATES_FLAG_P|0,8,/* h= */0,13,STATES_FLAG_P|0,8,/* h= */0,14,STATES_FLAG_P|0,8,/* h= */0,65,STATES_FLAG_P|0,0,/* h= */0,66,STATES_FLAG_P|0,0,/* h= */0,67,STATES_FLAG_P|0,0,/* h= */0,68,STATES_FLAG_P|0,0,/* h= */0,69,STATES_FLAG_P|0,0,/* h= */0\
	,70,STATES_FLAG_P|0,0,/* h= */0,71,STATES_FLAG_P|0,0,/* h= */0,72,STATES_FLAG_P|0,0,/* h= */0,73,STATES_FLAG_P|0,0,/* h= */0,74,STATES_FLAG_P|0,0,/* h= */0,75,STATES_FLAG_P|0,0,/* h= */0,76,STATES_FLAG_P|0,0,/* h= */0,77,STATES_FLAG_P|0,0,/* h= */0,65,STATES_FLAG_P|0,0,/* h= */0,66,STATES_FLAG_P|0,0,/* h= */0\
	,67,STATES_FLAG_P|0,0,/* h= */0,68,STATES_FLAG_P|0,0,/* h= */0,49,STATES_FLAG_P|0,0,/* h= */0,50,STATES_FLAG_P|0,0,/* h= */0,51,STATES_FLAG_P|0,0,/* h= */0,52,STATES_FLAG_P|0,0,/* h= */0,120,0,0,/* h= */0,121,STATES_FLAG_P|0,0,/* h= */0,122,STATES_FLAG_P|0,0,/* h= */0,123,STATES_FLAG_P|0,0,/* h= */0\
	,120,STATES_FLAG_P|0,0,/* h= */0,121,STATES_FLAG_P|0,0,/* h= */0,122,STATES_FLAG_P|0,0,/* h= */0,123,STATES_FLAG_P|0,0,/* h= */0,124,STATES_FLAG_P|0,0,/* h= */0,125,STATES_FLAG_P|0,0,/* h= */0,126,STATES_FLAG_P|0,0,/* h= */0,127,STATES_FLAG_P|0,0,/* h= */0,128,STATES_FLAG_P|0,0,/* h= */0,129,STATES_FLAG_P|0,0,/* h= */0\
	,130,STATES_FLAG_P|0,0,/* h= */0,39,0,15,/* h= */0,340,STATES_FLAG_HEIGHTOFFSET|0,15,/* h= */7,41,STATES_FLAG_HEIGHTOFFSET|0,15,/* h= */10,42,STATES_FLAG_HEIGHTOFFSET|0,15,/* h= */7,43,STATES_FLAG_HEIGHTOFFSET|0,15,/* h= */5,44,0,10,/* h= */0,44,STATES_FLAG_P|0,10,/* h= */0,147,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */25,148,STATES_FLAG_U|0,0,/* h= */0\
	,149,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-22,150,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-22,151,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-22,152,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-12,153,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-12,154,STATES_FLAG_HEIGHTOFFSET|0,4,/* h= */-3,155,STATES_FLAG_HEIGHTOFFSET|0,4,/* h= */-3,156,STATES_FLAG_HEIGHTOFFSET|0,4,/* h= */-3,157,STATES_FLAG_HEIGHTOFFSET|0,4,/* h= */-3,158,STATES_FLAG_HEIGHTOFFSET|0,4,/* h= */-3\
	,159,STATES_FLAG_HEIGHTOFFSET|0,4,/* h= */-3,160,STATES_FLAG_HEIGHTOFFSET|0,4,/* h= */-3,99,0,5,/* h= */0,146,0,0,/* h= */0,145,STATES_FLAG_P|0,-3,/* h= */0,149,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-22,150,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-22,151,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-22,152,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-12,153,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */-12\
	,154,STATES_FLAG_HEIGHTOFFSET|0,4,/* h= */-3,155,STATES_FLAG_HEIGHTOFFSET|0,4,/* h= */-3,156,STATES_FLAG_HEIGHTOFFSET|0,4,/* h= */-3,157,STATES_FLAG_HEIGHTOFFSET|0,4,/* h= */-3,158,STATES_FLAG_HEIGHTOFFSET|0,4,/* h= */-3,159,STATES_FLAG_HEIGHTOFFSET|0,4,/* h= */-3,160,STATES_FLAG_HEIGHTOFFSET|0,4,/* h= */-3,99,0,5,/* h= */0,148,STATES_FLAG_F|0,0,/* h= */0,147,0,0,/* h= */0\
	,146,0,0,/* h= */0,145,0,0,/* h= */0,148,STATES_FLAG_F|0,0,/* h= */0,147,0,0,/* h= */0,146,0,0,/* h= */0,145,0,0,/* h= */0,15,STATES_FLAG_F|STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */50,212,0,0,/* h= */0,213,0,0,/* h= */0,214,0,0,/* h= */0\
	,215,0,0,/* h= */0,216,0,0,/* h= */0,113,STATES_FLAG_F|STATES_FLAG_HEIGHTOFFSET|0,2,/* h= */50,114,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */20,115,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */5,116,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */3,117,0,0,/* h= */0,113,STATES_FLAG_F|STATES_FLAG_HEIGHTOFFSET|0,2,/* h= */50,114,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */20,115,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */5\
	,116,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */3,117,0,0,/* h= */0,15,STATES_FLAG_F|STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */50,212,0,0,/* h= */0,213,0,0,/* h= */0,214,0,0,/* h= */0,215,0,0,/* h= */0,216,0,0,/* h= */0,117,STATES_FLAG_F|STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */50,117,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */15\
	,117,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */3,219,STATES_FLAG_H|0,0,/* h= */0,117,STATES_FLAG_F|STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */50,117,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */15,117,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */3,117,0,0,/* h= */0,15,STATES_FLAG_F|STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */45,212,0,0,/* h= */0,213,0,0,/* h= */0,214,0,0,/* h= */0\
	,215,0,0,/* h= */0,216,0,0,/* h= */0,117,STATES_FLAG_F|STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */45,117,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */20,117,0,0,/* h= */0,215,0,0,/* h= */0,216,0,0,/* h= */0,117,STATES_FLAG_F|STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */45,117,STATES_FLAG_HEIGHTOFFSET|0,0,/* h= */20,117,0,0,/* h= */0\
	,79,STATES_FLAG_X|0,0,/* h= */0,80,STATES_FLAG_X|0,0,/* h= */0,78,STATES_FLAG_X|0,0,/* h= */0,15,0,0,/* h= */0,15,0,0,/* h= */0,1,0,0,/* h= */0,2,0,0,/* h= */0,3,0,0,/* h= */0,4,0,0,/* h= */0,5,0,0,/* h= */0\
	,6,0,0,/* h= */0,7,0,0,/* h= */0,8,0,0,/* h= */0,9,0,0,/* h= */0,10,0,0,/* h= */0,11,0,0,/* h= */0,12,0,0,/* h= */0,13,0,0,/* h= */0,14,0,0,/* h= */0,15,0,0,/* h= */0\
	,16,0,0,/* h= */0,17,0,0,/* h= */0,18,0,0,/* h= */0,19,0,0,/* h= */0,20,0,0,/* h= */0,21,0,0,/* h= */0,22,0,0,/* h= */0,23,0,0,/* h= */0,24,0,0,/* h= */0,25,0,0,/* h= */0\
	,26,0,0,/* h= */0,27,0,0,/* h= */0,28,0,0,/* h= */0,29,0,0,/* h= */0,30,0,0,/* h= */0,31,0,0,/* h= */0,32,0,0,/* h= */0,33,0,0,/* h= */0,34,0,0,/* h= */0,35,0,0,/* h= */0\
	,36,0,0,/* h= */0,37,0,0,/* h= */0,38,0,0,/* h= */0,1,0,0,/* h= */0,2,0,0,/* h= */0,3,0,0,/* h= */0,4,0,0,/* h= */0,5,0,0,/* h= */0,6,0,0,/* h= */0,7,0,0,/* h= */0\
	,8,0,0,/* h= */0,9,0,0,/* h= */0,1,0,0,/* h= */0,1,0,0,/* h= */0,1,0,0,/* h= */0,2,0,0,/* h= */0,2,0,0,/* h= */0,2,0,0,/* h= */0\
}

#define STATES_LEVELS {16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16}

#define STATES_GUARDS {16}

#define STATE_EXIT_CODE_JAFFAR -2
#define STATE_EXIT_CODE_SPLASH -1

#define STATE_MARKS_FALL 0
#define STATE_MARKS_TORCH 48
#define STATE_MARKS_RESURRECT 16
#define STATE_MARKS_STARS 49
#define STATE_MARKS_CRASH 45
#define STATE_MARKS_DEADBODY 42
#define STATE_MARKS_JAFFAR 46

