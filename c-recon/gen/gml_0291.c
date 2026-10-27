/* generated from CODE 291 (gml_Object_obj_spikegunspike_Create_0), source start 4122024, end 4122144. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0291(GmVM* vm) {
    /* @4122024 constant */
    /* @4122028 constant */
    /* @4122032 constant */
    /* @4122036 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(240));
    /* @4122044 constant */
    /* @4122048 store */
    GM_WRITE(vm, -1, "type", VAL(2));
    /* @4122056 load */
    /* @4122064 constant */
    /* @4122068 cmp */
    /* @4122072 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(1)))) goto L_4122100;
    /* @4122076 constant */
    /* @4122080 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-14));
    /* @4122088 constant */
    /* @4122092 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    L_4122100: ;
    /* @4122100 load */
    /* @4122108 constant */
    /* @4122112 cmp */
    /* @4122116 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(0)))) goto L_4122144;
    /* @4122120 constant */
    /* @4122124 store */
    GM_WRITE(vm, -1, "hspeed", VAL(14));
    /* @4122132 constant */
    /* @4122136 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(1));
    L_4122144: ;
    return;
}
