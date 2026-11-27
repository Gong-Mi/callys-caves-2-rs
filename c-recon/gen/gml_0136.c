/* generated from CODE 136 (gml_Object_obj_wolf_Destroy_0), source start 3958492, end 3958576. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0136(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3958492 load */
    /* @3958500 constant */
    /* @3958504 add */
    /* @3958508 store */
    v1 = GM_ADD(GM_READ(vm, -5, "wolfkilled"), VAL(1));
    GM_WRITE(vm, -5, "wolfkilled", v1);
    /* @3958516 load */
    /* @3958524 constant */
    /* @3958528 add */
    /* @3958532 store */
    v2 = GM_ADD(GM_READ(vm, -5, "enemieskilled"), VAL(1));
    GM_WRITE(vm, -5, "enemieskilled", v2);
    /* @3958540 constant */
    /* @3958544 cast */
    /* @3958548 load */
    /* @3958556 load */
    /* @3958564 call */
    GM_SITE(vm, 136, 3958564);
    /* @3958572 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(187)));
    L_3958576: ;
    return;
}
