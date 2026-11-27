/* generated from CODE 285 (gml_Object_obj_iceball_Create_0), source start 4107044, end 4107092. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0285(GmVM* vm) {
    /* @4107044 load */
    /* @4107052 constant */
    /* @4107056 cmp */
    /* @4107060 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(1)))) goto L_4107080;
    /* @4107064 constant */
    /* @4107068 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-15));
    /* @4107076 b */
    goto L_4107092;
    L_4107080: ;
    /* @4107080 constant */
    /* @4107084 store */
    GM_WRITE(vm, -1, "hspeed", VAL(15));
    L_4107092: ;
    return;
}
