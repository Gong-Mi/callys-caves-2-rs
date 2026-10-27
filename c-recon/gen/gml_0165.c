/* generated from CODE 165 (gml_Object_obj_boss2_Alarm_6), source start 3983908, end 3984044. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0165(GmVM* vm) {
    Val v1;
    /* @3983908 constant */
    /* @3983912 store */
    GM_WRITE(vm, -1, "poisoned", VAL(1));
    /* @3983920 load */
    /* @3983928 constant */
    /* @3983940 sub */
    /* @3983944 store */
    GM_WRITE(vm, -1, "hpboss2", (GM_READ(vm, -1, "hpboss2") - VAL(0.25)));
    /* @3983952 constant */
    /* @3983956 cast */
    /* @3983960 load */
    /* @3983968 load */
    /* @3983976 call */
    GM_SITE(vm, 165, 3983976);
    /* @3983984 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v1);
    /* @3983992 constant */
    /* @3984004 load */
    /* @3984012 cast */
    /* @3984016 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(0.25));
    /* @3984024 constant */
    /* @3984028 constant */
    /* @3984032 constant */
    /* @3984036 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(6), VAL(30));
    L_3984044: ;
    return;
}
