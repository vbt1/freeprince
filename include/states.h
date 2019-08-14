#ifndef _PR_STATES_H_
#define _PR_STATES_H_

/* Structs */

#include "types.h" /* tMap */
#include "input.h" /* tKey */

#define STATES_KEY_PRESSED 1
#define STATES_KEY_NOTPRESSED 0

typedef enum {esLast=0,esKeyUp,esKeyDown,esKeyForward,esKeyBack,esKeyShift,esMapUp,esMapUpForward,esMapDown,esMapForward,esMapBack,esMapBackUp,esMapOn,esForwardTileNearerThan,esForwardTileFartherThan,esScreenUp,esScreenDown,esScreenLeft,esScreenRight,esInScreen,esInLevel,esForwardChangeToScreen,esInFloorTop,esInfloorMiddle,esInfloorBottom,esMapNotOn,esMapNotBack,esMapDownBack,esMapNotDownBack,esMapNotForward,esKidLooking}tsConditionType;

								
typedef enum {esDangerous,esNone,esWalk,esPotion,esSword,esMirror,esNotApplicable=0}tsTileType;
/*typedef enum {esRelative,esForwardTile,esRelativeTurn}tsMoveType;   */
typedef char tsMoveType;

typedef struct {
	tsConditionType type;
	short           argument;
} tsCondition;

typedef struct {
	short        conditionId; /* Id of the first condition to be evaluated */
	tsMoveType   moveType; /* absolute or relative */
	char         moveOffset; /* amount of moving units the kid will move depending on the offset type */
	short        nextStateId; /* Id of the first action of the next state */
	short        animStart; /* Index of the first frame in the animation array */
	short        animSize; /* number of frames to be shown */
} tsAction;

#define stateGetImage(a) (((a)->action.image))
#define stateGetBottom(a) (((a)->action.imgoffx))
#define stateGetMirror(a) (((a)->action.mirror))

/* public functions interface */

/* This function should return the frame flags
 * and actions to be performed by this call
 *
 * Usage:
 *  stateUpdate(tKey* key, tObject* kid,tRoom* room);
 *  where key is a tKey* with the current key state (read from a file,
 *  keyboard or joystick) or NULL in case there is no need to interpretate
 *  key events to manipulate states
 *
 *  kid is a pointer to a person or object that uses states, with states
 *  initialized properly by createState fucntion.
 *
 *  room is a pointer to a room where the events will be interpreted, the NULL
 *  pointer is allowed. In that case actions that needs map conditions won't
 *  be performed.
 */

short stateUpdate(tKey* key, tObject* kid,tRoom* room);

/* Create a State depending on the level */
int stateKidInLevel(int level);
tState stateCreate(short stateId);
void stateReset(tState* state, short stateId);
void stateFree(tState* state);

#include "states_conf.h"

#define STATES_CONDRESULT_FALSE 2
#define STATES_CONDRESULT_END 1
#define STATES_CONDRESULT_TRUE 0

#endif

