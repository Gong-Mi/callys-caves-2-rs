/* generated from CODE 156 (gml_Object_obj_trex_Alarm_6), source start 3972956, end 3973092. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0156(GmVM* vm) {
    Val v1;
    /* @3972956 constant */
    /* @3972960 store */
    GM_WRITE(vm, -1, "poisoned", VAL(1));
    /* @3972968 load */
    /* @3972976 constant */
    /* @3972988 sub */
    /* @3972992 store */
    GM_WRITE(vm, -1, "hptrex", (GM_READ(vm, -1, "hptrex") - VAL(0.25)));
    /* @3973000 constant */
    /* @3973004 cast */
    /* @3973008 load */
    /* @3973016 load */
    /* @3973024 call */
    GM_SITE(vm, 156, 3973024);
    /* @3973032 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v1);
    /* @3973040 constant */
    /* @3973052 load */
    /* @3973060 cast */
    /* @3973064 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(0.25));
    /* @3973072 constant */
    /* @3973076 constant */
    /* @3973080 constant */
    /* @3973084 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(6), VAL(30));
    L_3973092: ;
    return;
}
