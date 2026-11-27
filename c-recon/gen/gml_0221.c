/* generated from CODE 221 (gml_Object_obj_finalboss_Alarm_7), source start 4029596, end 4029668. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0221(GmVM* vm) {
    /* @4029596 load */
    /* @4029604 constant */
    /* @4029608 cmp */
    /* @4029612 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") != VAL(110)))) goto L_4029668;
    /* @4029616 constant */
    /* @4029620 store */
    GM_WRITE(vm, -1, "vspeed", VAL(3));
    /* @4029628 constant */
    /* @4029640 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0.5));
    /* @4029648 constant */
    /* @4029652 constant */
    /* @4029656 constant */
    /* @4029660 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(50));
    L_4029668: ;
    return;
}
