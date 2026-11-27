/* generated from CODE 182 (gml_Object_obj_boss3_Alarm_2), source start 3995672, end 3995740. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0182(GmVM* vm) {
    Val v1;
    /* @3995672 constant */
    /* @3995676 cast */
    /* @3995680 load */
    /* @3995688 load */
    /* @3995696 constant */
    /* @3995700 sub */
    /* @3995704 call */
    GM_SITE(vm, 182, 3995704);
    /* @3995712 store */
    v1 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(50)), GM_READ(vm, -1, "y"), VAL(55));
    GM_WRITE(vm, -1, "bullet1", v1);
    /* @3995720 constant */
    /* @3995724 constant */
    /* @3995728 constant */
    /* @3995732 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(10));
    L_3995740: ;
    return;
}
