/* generated from CODE 180 (gml_Object_obj_boss3_Alarm_4), source start 3995536, end 3995604. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0180(GmVM* vm) {
    Val v1;
    /* @3995536 constant */
    /* @3995540 cast */
    /* @3995544 load */
    /* @3995552 load */
    /* @3995560 constant */
    /* @3995564 sub */
    /* @3995568 call */
    GM_SITE(vm, 180, 3995568);
    /* @3995576 store */
    v1 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(50)), GM_READ(vm, -1, "y"), VAL(55));
    GM_WRITE(vm, -1, "bullet1", v1);
    /* @3995584 constant */
    /* @3995588 constant */
    /* @3995592 constant */
    /* @3995596 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(6), VAL(10));
    L_3995604: ;
    return;
}
