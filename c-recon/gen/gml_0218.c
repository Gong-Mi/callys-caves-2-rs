/* generated from CODE 218 (gml_Object_obj_finalboss_Alarm_10), source start 4029420, end 4029484. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0218(GmVM* vm) {
    /* @4029420 load */
    /* @4029428 constant */
    /* @4029432 cmp */
    /* @4029436 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") != VAL(110)))) goto L_4029484;
    /* @4029440 constant */
    /* @4029444 store */
    GM_WRITE(vm, -1, "hspeed", VAL(2));
    /* @4029452 constant */
    /* @4029456 store */
    GM_WRITE(vm, -1, "vspeed", VAL(3));
    /* @4029464 constant */
    /* @4029468 constant */
    /* @4029472 constant */
    /* @4029476 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(11), VAL(100));
    L_4029484: ;
    return;
}
