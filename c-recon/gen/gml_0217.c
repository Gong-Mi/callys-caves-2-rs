/* generated from CODE 217 (gml_Object_obj_finalboss_Alarm_11), source start 4029356, end 4029420. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0217(GmVM* vm) {
    /* @4029356 load */
    /* @4029364 constant */
    /* @4029368 cmp */
    /* @4029372 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") != VAL(110)))) goto L_4029420;
    /* @4029376 constant */
    /* @4029380 store */
    GM_WRITE(vm, -1, "vspeed", VAL(1));
    /* @4029388 constant */
    /* @4029392 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-2));
    /* @4029400 constant */
    /* @4029404 constant */
    /* @4029408 constant */
    /* @4029412 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(100));
    L_4029420: ;
    return;
}
