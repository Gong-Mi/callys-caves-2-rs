/* generated from CODE 224 (gml_Object_obj_finalboss_Alarm_4), source start 4029816, end 4029880. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0224(GmVM* vm) {
    /* @4029816 load */
    /* @4029824 constant */
    /* @4029828 cmp */
    /* @4029832 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") != VAL(110)))) goto L_4029880;
    /* @4029836 constant */
    /* @4029840 store */
    GM_WRITE(vm, -1, "vspeed", VAL(2));
    /* @4029848 constant */
    /* @4029852 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-2));
    /* @4029860 constant */
    /* @4029864 constant */
    /* @4029868 constant */
    /* @4029872 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(100));
    L_4029880: ;
    return;
}
