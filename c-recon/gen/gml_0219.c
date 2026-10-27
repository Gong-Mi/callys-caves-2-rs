/* generated from CODE 219 (gml_Object_obj_finalboss_Alarm_9), source start 4029484, end 4029544. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0219(GmVM* vm) {
    /* @4029484 load */
    /* @4029492 constant */
    /* @4029496 cmp */
    /* @4029500 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") != VAL(110)))) goto L_4029544;
    /* @4029504 constant */
    /* @4029516 store */
    GM_WRITE(vm, -1, "vspeed", VAL(-0.5));
    /* @4029524 constant */
    /* @4029528 constant */
    /* @4029532 constant */
    /* @4029536 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(10), VAL(100));
    L_4029544: ;
    return;
}
