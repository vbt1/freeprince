
/* parts */
 /* mods, size=8 */
#define res_get_part_mods(a) (((a)>>0)&0x000000ff)
#define res_set_part_mods(a) (((a)&0x000000ff)<<0)
 /* size, size=8 */
#define res_get_part_size(a) (((a)>>8)&0x000000ff)
#define res_set_part_size(a) (((a)&0x000000ff)<<8)
 /* from, size=12 */
#define res_get_part_from(a) (((a)>>16)&0x00000fff)
#define res_set_part_from(a) (((a)&0x00000fff)<<16)
 /* type, size=3 */
#define res_get_part_type(a) (((a)>>28)&0x00000007)
#define res_set_part_type(a) (((a)&0x00000007)<<28)
