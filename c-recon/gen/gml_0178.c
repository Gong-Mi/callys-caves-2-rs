/* generated from CODE 178 (gml_Object_obj_boss3_Alarm_6), source start 3995456, end 3995524. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0178(GmVM* vm) {
    Val v1;
    /* @3995456 constant */
    /* @3995460 cast */
    /* @3995464 load */
    /* @3995472 load */
    /* @3995480 constant */
    /* @3995484 sub */
    /* @3995488 call */
    GM_SITE(vm, 178, 3995488);
    /* @3995496 store */
    v1 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(50)), GM_READ(vm, -1, "y"), VAL(55));
    GM_WRITE(vm, -1, "bullet1", v1);
    /* @3995504 constant */
    /* @3995508 constant */
    /* @3995512 constant */
    /* @3995516 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(10));
    L_3995524: ;
    return;
}
