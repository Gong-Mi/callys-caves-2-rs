/* generated from CODE 534 (gml_Object_obj_coinadd_Create_0), source start 4836176, end 4836244. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0534(GmVM* vm) {
    /* @4836176 load */
    /* @4836184 constant */
    /* @4836188 sub */
    /* @4836192 store */
    GM_WRITE(vm, -1, "drawy", (GM_READ(vm, 0, "y") - VAL(50)));
    /* @4836200 load */
    /* @4836208 constant */
    /* @4836212 sub */
    /* @4836216 store */
    GM_WRITE(vm, -1, "drawy2", (GM_READ(vm, 0, "y") - VAL(40)));
    /* @4836224 constant */
    /* @4836228 constant */
    /* @4836232 constant */
    /* @4836236 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(45));
    L_4836244: ;
    return;
}
