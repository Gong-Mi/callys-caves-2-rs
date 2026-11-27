/* generated from CODE 124 (gml_Object_obj_enemy2_Destroy_0), source start 3950952, end 3951036. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0124(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3950952 load */
    /* @3950960 constant */
    /* @3950964 add */
    /* @3950968 store */
    v1 = GM_ADD(GM_READ(vm, -5, "chomperbotkilled"), VAL(1));
    GM_WRITE(vm, -5, "chomperbotkilled", v1);
    /* @3950976 load */
    /* @3950984 constant */
    /* @3950988 add */
    /* @3950992 store */
    v2 = GM_ADD(GM_READ(vm, -5, "enemieskilled"), VAL(1));
    GM_WRITE(vm, -5, "enemieskilled", v2);
    /* @3951000 constant */
    /* @3951004 cast */
    /* @3951008 load */
    /* @3951016 load */
    /* @3951024 call */
    GM_SITE(vm, 124, 3951024);
    /* @3951032 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(187)));
    L_3951036: ;
    return;
}
