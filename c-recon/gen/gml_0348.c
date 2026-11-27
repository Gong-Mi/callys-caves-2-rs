/* generated from CODE 348 (gml_Object_obj_XPorb_Step_0), source start 4198188, end 4198448. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0348(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    /* @4198188 constant */
    /* @4198192 cast */
    /* @4198196 load */
    /* @4198204 constant */
    /* @4198208 add */
    /* @4198212 load */
    /* @4198220 call */
    GM_SITE(vm, 348, 4198220);
    v1 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4198228 cast */
    /* @4198232 bf */
    v2 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v1, VAL(34)));
    if (!TRUTH(v2)) goto L_4198312;
    /* @4198236 load */
    /* @4198244 load */
    /* @4198252 cmp */
    /* @4198256 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "y") >= GM_READ(vm, -1, "yorigin")))) goto L_4198288;
    /* @4198260 constant */
    /* @4198264 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @4198272 constant */
    /* @4198276 store */
    GM_WRITE(vm, -1, "gravity", VAL(0));
    /* @4198284 b */
    goto L_4198308;
    L_4198288: ;
    /* @4198288 constant */
    /* @4198300 store */
    GM_WRITE(vm, -1, "gravity", VAL(0.6));
    L_4198308: ;
    /* @4198308 b */
    goto L_4198332;
    L_4198312: ;
    /* @4198312 constant */
    /* @4198324 store */
    GM_WRITE(vm, -1, "gravity", VAL(0.6));
    L_4198332: ;
    /* @4198332 constant */
    /* @4198336 cast */
    /* @4198340 load */
    /* @4198348 load */
    /* @4198356 load */
    /* @4198364 add */
    /* @4198368 call */
    GM_SITE(vm, 348, 4198368);
    v3 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @4198376 cast */
    /* @4198380 bf */
    v4 = BOOL(GM_CALL(vm, "instance_place", 3, v3, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v4)) goto L_4198396;
    /* @4198384 constant */
    /* @4198388 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_4198396: ;
    /* @4198396 constant */
    /* @4198400 cast */
    /* @4198404 load */
    /* @4198412 load */
    /* @4198420 call */
    GM_SITE(vm, 348, 4198420);
    /* @4198428 cast */
    /* @4198432 bf */
    v5 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(9)));
    if (!TRUTH(v5)) goto L_4198448;
    /* @4198436 call */
    GM_SITE(vm, 348, 4198436);
    /* @4198444 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4198448: ;
    return;
}
