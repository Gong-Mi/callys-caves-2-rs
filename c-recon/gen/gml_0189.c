/* generated from CODE 189 (gml_Object_obj_boss4_Alarm_10), source start 4005968, end 4006104. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0189(GmVM* vm) {
    Val v1;
    /* @4005968 constant */
    /* @4005972 store */
    GM_WRITE(vm, -1, "poisoned", VAL(1));
    /* @4005980 load */
    /* @4005988 constant */
    /* @4006000 sub */
    /* @4006004 store */
    GM_WRITE(vm, -1, "hpboss4", (GM_READ(vm, -1, "hpboss4") - VAL(0.25)));
    /* @4006012 constant */
    /* @4006016 cast */
    /* @4006020 load */
    /* @4006028 load */
    /* @4006036 call */
    GM_SITE(vm, 189, 4006036);
    /* @4006044 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v1);
    /* @4006052 constant */
    /* @4006064 load */
    /* @4006072 cast */
    /* @4006076 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(0.25));
    /* @4006084 constant */
    /* @4006088 constant */
    /* @4006092 constant */
    /* @4006096 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(10), VAL(30));
    L_4006104: ;
    return;
}
