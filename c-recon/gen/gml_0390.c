/* generated from CODE 390 (gml_Object_obj_rocketlauncher_Create_0), source start 4517308, end 4517408. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0390(GmVM* vm) {
    Val v1;
    /* @4517308 constant */
    /* @4517312 store */
    GM_WRITE(vm, -1, "image_speed", VAL(0));
    /* @4517320 load */
    /* @4517328 constant */
    /* @4517332 cmp */
    /* @4517336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(1)))) goto L_4517356;
    /* @4517340 call */
    GM_SITE(vm, 390, 4517340);
    /* @4517348 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4517352 b */
    goto L_4517408;
    L_4517356: ;
    /* @4517356 constant */
    /* @4517360 cast */
    /* @4517364 load */
    /* @4517372 constant */
    /* @4517376 sub */
    /* @4517380 load */
    /* @4517388 constant */
    /* @4517392 add */
    /* @4517396 call */
    GM_SITE(vm, 390, 4517396);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @4517404 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(20)), VAL(70)));
    L_4517408: ;
    return;
}
