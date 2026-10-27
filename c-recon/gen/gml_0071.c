/* generated from CODE 71 (gml_Object_obj_skeleton_Alarm_6), source start 3910912, end 3911048. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0071(GmVM* vm) {
    Val v1;
    /* @3910912 constant */
    /* @3910916 store */
    GM_WRITE(vm, -1, "poisoned", VAL(1));
    /* @3910924 load */
    /* @3910932 constant */
    /* @3910944 sub */
    /* @3910948 store */
    GM_WRITE(vm, -1, "hpskeleton", (GM_READ(vm, -1, "hpskeleton") - VAL(0.25)));
    /* @3910956 constant */
    /* @3910960 cast */
    /* @3910964 load */
    /* @3910972 load */
    /* @3910980 call */
    GM_SITE(vm, 71, 3910980);
    /* @3910988 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v1);
    /* @3910996 constant */
    /* @3911008 load */
    /* @3911016 cast */
    /* @3911020 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(0.25));
    /* @3911028 constant */
    /* @3911032 constant */
    /* @3911036 constant */
    /* @3911040 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(6), VAL(30));
    L_3911048: ;
    return;
}
