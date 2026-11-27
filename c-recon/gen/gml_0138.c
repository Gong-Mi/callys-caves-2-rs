/* generated from CODE 138 (gml_Object_obj_wolf_Alarm_6), source start 3958600, end 3958736. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0138(GmVM* vm) {
    Val v1;
    /* @3958600 constant */
    /* @3958604 store */
    GM_WRITE(vm, -1, "poisoned", VAL(1));
    /* @3958612 load */
    /* @3958620 constant */
    /* @3958632 sub */
    /* @3958636 store */
    GM_WRITE(vm, -1, "hpwolf", (GM_READ(vm, -1, "hpwolf") - VAL(0.25)));
    /* @3958644 constant */
    /* @3958648 cast */
    /* @3958652 load */
    /* @3958660 load */
    /* @3958668 call */
    GM_SITE(vm, 138, 3958668);
    /* @3958676 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v1);
    /* @3958684 constant */
    /* @3958696 load */
    /* @3958704 cast */
    /* @3958708 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(0.25));
    /* @3958716 constant */
    /* @3958720 constant */
    /* @3958724 constant */
    /* @3958728 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(6), VAL(30));
    L_3958736: ;
    return;
}
