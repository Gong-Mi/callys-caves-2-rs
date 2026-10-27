/* generated from CODE 177 (gml_Object_obj_boss3_Alarm_7), source start 3995388, end 3995456. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0177(GmVM* vm) {
    Val v1;
    /* @3995388 constant */
    /* @3995392 cast */
    /* @3995396 load */
    /* @3995404 load */
    /* @3995412 constant */
    /* @3995416 sub */
    /* @3995420 call */
    GM_SITE(vm, 177, 3995420);
    /* @3995428 store */
    v1 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(50)), GM_READ(vm, -1, "y"), VAL(55));
    GM_WRITE(vm, -1, "bullet1", v1);
    /* @3995436 constant */
    /* @3995440 constant */
    /* @3995444 constant */
    /* @3995448 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(10));
    L_3995456: ;
    return;
}
