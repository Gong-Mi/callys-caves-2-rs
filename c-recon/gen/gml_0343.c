/* generated from CODE 343 (gml_Object_obj_gem_Step_0), source start 4197320, end 4197580. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0343(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    /* @4197320 constant */
    /* @4197324 cast */
    /* @4197328 load */
    /* @4197336 constant */
    /* @4197340 add */
    /* @4197344 load */
    /* @4197352 call */
    GM_SITE(vm, 343, 4197352);
    v1 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4197360 cast */
    /* @4197364 bf */
    v2 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v1, VAL(34)));
    if (!TRUTH(v2)) goto L_4197444;
    /* @4197368 load */
    /* @4197376 load */
    /* @4197384 cmp */
    /* @4197388 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "y") >= GM_READ(vm, -1, "yorigin")))) goto L_4197420;
    /* @4197392 constant */
    /* @4197396 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @4197404 constant */
    /* @4197408 store */
    GM_WRITE(vm, -1, "gravity", VAL(0));
    /* @4197416 b */
    goto L_4197440;
    L_4197420: ;
    /* @4197420 constant */
    /* @4197432 store */
    GM_WRITE(vm, -1, "gravity", VAL(0.6));
    L_4197440: ;
    /* @4197440 b */
    goto L_4197464;
    L_4197444: ;
    /* @4197444 constant */
    /* @4197456 store */
    GM_WRITE(vm, -1, "gravity", VAL(0.6));
    L_4197464: ;
    /* @4197464 constant */
    /* @4197468 cast */
    /* @4197472 load */
    /* @4197480 load */
    /* @4197488 load */
    /* @4197496 add */
    /* @4197500 call */
    GM_SITE(vm, 343, 4197500);
    v3 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @4197508 cast */
    /* @4197512 bf */
    v4 = BOOL(GM_CALL(vm, "instance_place", 3, v3, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v4)) goto L_4197528;
    /* @4197516 constant */
    /* @4197520 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_4197528: ;
    /* @4197528 constant */
    /* @4197532 cast */
    /* @4197536 load */
    /* @4197544 load */
    /* @4197552 call */
    GM_SITE(vm, 343, 4197552);
    /* @4197560 cast */
    /* @4197564 bf */
    v5 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(9)));
    if (!TRUTH(v5)) goto L_4197580;
    /* @4197568 call */
    GM_SITE(vm, 343, 4197568);
    /* @4197576 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4197580: ;
    return;
}
