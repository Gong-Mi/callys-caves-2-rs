/* generated from CODE 102 (gml_Object_obj_shooter2_Alarm_7), source start 3934056, end 3934192. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0102(GmVM* vm) {
    Val v1;
    /* @3934056 constant */
    /* @3934060 store */
    GM_WRITE(vm, -1, "poisoned", VAL(1));
    /* @3934068 load */
    /* @3934076 constant */
    /* @3934088 sub */
    /* @3934092 store */
    GM_WRITE(vm, -1, "hpshooter2", (GM_READ(vm, -1, "hpshooter2") - VAL(0.25)));
    /* @3934100 constant */
    /* @3934104 cast */
    /* @3934108 load */
    /* @3934116 load */
    /* @3934124 call */
    GM_SITE(vm, 102, 3934124);
    /* @3934132 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v1);
    /* @3934140 constant */
    /* @3934152 load */
    /* @3934160 cast */
    /* @3934164 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(0.25));
    /* @3934172 constant */
    /* @3934176 constant */
    /* @3934180 constant */
    /* @3934184 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(30));
    L_3934192: ;
    return;
}
