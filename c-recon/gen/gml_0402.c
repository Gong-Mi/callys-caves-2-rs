/* generated from CODE 402 (gml_Object_obj_icegun_Create_0), source start 4519460, end 4519560. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0402(GmVM* vm) {
    Val v1;
    /* @4519460 constant */
    /* @4519464 store */
    GM_WRITE(vm, -1, "image_speed", VAL(0));
    /* @4519472 load */
    /* @4519480 constant */
    /* @4519484 cmp */
    /* @4519488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(1)))) goto L_4519508;
    /* @4519492 call */
    GM_SITE(vm, 402, 4519492);
    /* @4519500 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4519504 b */
    goto L_4519560;
    L_4519508: ;
    /* @4519508 constant */
    /* @4519512 cast */
    /* @4519516 load */
    /* @4519524 constant */
    /* @4519528 sub */
    /* @4519532 load */
    /* @4519540 constant */
    /* @4519544 add */
    /* @4519548 call */
    GM_SITE(vm, 402, 4519548);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4519556 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(18)), VAL(70)));
    L_4519560: ;
    return;
}
