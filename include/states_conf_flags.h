/* press the floor */
#define STATES_FLAG_P (1<<0)

/* press the ceiling */
#define STATES_FLAG_C (1<<1)

/* make a sound */
#define STATES_FLAG_S (1<<2)

/* you hit the guard/kid */
#define STATES_FLAG_G (1<<3)

/* fall down */
#define STATES_FLAG_F (1<<4)

/* go up one floor */
#define STATES_FLAG_U (1<<5)

/* turn */
#define STATES_FLAG_T (1<<6)

/* mirror */
#define STATES_FLAG_M (1<<7)

/* you are dead! */
#define STATES_FLAG_X (1<<8)

/* drink something that is in the tile you are in */
#define STATES_FLAG_D (1<<9)

/* loose a hit point */
#define STATES_FLAG_H (1<<10)

/* internal flag to detect frames with height (deprecated or to be implemented) */
#define STATES_FLAG_HEIGHTOFFSET (1<<11)

