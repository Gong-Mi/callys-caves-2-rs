/* generated from CODE 42 (gml_Object_obj_enemy_Alarm_6), source start 3889924, end 3890060. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0042(GmVM* vm) {
    Val v1;
    /* @3889924 constant */
    /* @3889928 store */
    GM_WRITE(vm, -1, "poisoned", VAL(1));
    /* @3889936 load */
    /* @3889944 constant */
    /* @3889956 sub */
    /* @3889960 store */
    GM_WRITE(vm, -1, "hp", (GM_READ(vm, -1, "hp") - VAL(0.25)));
    /* @3889968 constant */
    /* @3889972 cast */
    /* @3889976 load */
    /* @3889984 load */
    /* @3889992 call */
    GM_SITE(vm, 42, 3889992);
    /* @3890000 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v1);
    /* @3890008 constant */
    /* @3890020 load */
    /* @3890028 cast */
    /* @3890032 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(0.25));
    /* @3890040 constant */
    /* @3890044 constant */
    /* @3890048 constant */
    /* @3890052 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(6), VAL(30));
    L_3890060: ;
    return;
}
