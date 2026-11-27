/* generated from CODE 220 (gml_Object_obj_finalboss_Alarm_8), source start 4029544, end 4029596. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0220(GmVM* vm) {
    /* @4029544 load */
    /* @4029552 constant */
    /* @4029556 cmp */
    /* @4029560 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") != VAL(110)))) goto L_4029596;
    /* @4029564 constant */
    /* @4029568 store */
    GM_WRITE(vm, -1, "vspeed", VAL(10));
    /* @4029576 constant */
    /* @4029580 constant */
    /* @4029584 constant */
    /* @4029588 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(9), VAL(20));
    L_4029596: ;
    return;
}
