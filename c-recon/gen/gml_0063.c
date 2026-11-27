/* generated from CODE 63 (gml_Object_obj_shooter1_Alarm_3), source start 3903376, end 3903416. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0063(GmVM* vm) {
    /* @3903376 load */
    /* @3903384 constant */
    /* @3903392 sub */
    /* @3903396 store */
    GM_WRITE(vm, -1, "image_blend", (GM_READ(vm, -1, "image_blend") - VAL(16777215)));
    /* @3903404 constant */
    /* @3903408 store */
    GM_WRITE(vm, -1, "hpshooter1frozen", VAL(0));
    L_3903416: ;
    return;
}
