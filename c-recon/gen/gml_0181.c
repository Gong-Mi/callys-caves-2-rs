/* generated from CODE 181 (gml_Object_obj_boss3_Alarm_3), source start 3995604, end 3995672. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0181(GmVM* vm) {
    Val v1;
    /* @3995604 constant */
    /* @3995608 cast */
    /* @3995612 load */
    /* @3995620 load */
    /* @3995628 constant */
    /* @3995632 sub */
    /* @3995636 call */
    GM_SITE(vm, 181, 3995636);
    /* @3995644 store */
    v1 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(50)), GM_READ(vm, -1, "y"), VAL(55));
    GM_WRITE(vm, -1, "bullet1", v1);
    /* @3995652 constant */
    /* @3995656 constant */
    /* @3995660 constant */
    /* @3995664 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    L_3995672: ;
    return;
}
