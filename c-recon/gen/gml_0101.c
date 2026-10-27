/* generated from CODE 101 (gml_Object_obj_shooter2_Destroy_0), source start 3933972, end 3934056. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0101(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3933972 load */
    /* @3933980 constant */
    /* @3933984 add */
    /* @3933988 store */
    v1 = GM_ADD(GM_READ(vm, -5, "trapskilled"), VAL(1));
    GM_WRITE(vm, -5, "trapskilled", v1);
    /* @3933996 load */
    /* @3934004 constant */
    /* @3934008 add */
    /* @3934012 store */
    v2 = GM_ADD(GM_READ(vm, -5, "enemieskilled"), VAL(1));
    GM_WRITE(vm, -5, "enemieskilled", v2);
    /* @3934020 constant */
    /* @3934024 cast */
    /* @3934028 load */
    /* @3934036 load */
    /* @3934044 call */
    GM_SITE(vm, 101, 3934044);
    /* @3934052 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(187)));
    L_3934056: ;
    return;
}
