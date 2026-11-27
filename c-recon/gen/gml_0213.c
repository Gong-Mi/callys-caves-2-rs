/* generated from CODE 213 (gml_Object_obj_boss5_Step_0), source start 4028176, end 4028628. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0213(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    /* @4028176 load */
    /* @4028184 constant */
    /* @4028188 cmp */
    /* @4028192 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpboss5") >= VAL(0)))) goto L_4028216;
    /* @4028196 constant */
    /* @4028200 constant */
    /* @4028204 constant */
    /* @4028208 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(0));
    L_4028216: ;
    /* @4028216 load */
    /* @4028224 constant */
    /* @4028228 cmp */
    /* @4028232 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpboss5") <= VAL(0)))) goto L_4028256;
    /* @4028236 constant */
    /* @4028240 constant */
    /* @4028244 constant */
    /* @4028248 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    L_4028256: ;
    /* @4028256 constant */
    /* @4028260 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @4028268 load */
    /* @4028276 constant */
    /* @4028280 cmp */
    /* @4028284 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "swordstunned") == VAL(1)))) goto L_4028324;
    /* @4028288 constant */
    /* @4028292 store */
    GM_WRITE(vm, -1, "image_blend", VAL(255));
    /* @4028300 constant */
    /* @4028304 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4028312 constant */
    /* @4028316 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_4028324: ;
    /* @4028324 load */
    /* @4028332 constant */
    /* @4028336 cmp */
    /* @4028340 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "poisoned") == VAL(1)))) goto L_4028360;
    /* @4028344 constant */
    /* @4028352 store */
    GM_WRITE(vm, -1, "image_blend", VAL(32768));
    L_4028360: ;
    /* @4028360 load */
    /* @4028368 load */
    /* @4028376 cmp */
    /* @4028380 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "x") > GM_READ(vm, -1, "x")))) goto L_4028472;
    /* @4028384 constant */
    /* @4028388 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(1));
    /* @4028396 constant */
    /* @4028400 cast */
    /* @4028404 load */
    /* @4028412 load */
    /* @4028420 constant */
    /* @4028424 add */
    /* @4028428 call */
    GM_SITE(vm, 213, 4028428);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(100));
    /* @4028436 cast */
    /* @4028440 not */
    /* @4028444 bf */
    v2 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v1, GM_READ(vm, -1, "y"), VAL(34))));
    if (!TRUTH(v2)) goto L_4028460;
    /* @4028448 constant */
    /* @4028452 store */
    GM_WRITE(vm, -1, "hspeed", VAL(1));
    L_4028460: ;
    /* @4028460 constant */
    /* @4028464 store */
    GM_WRITE(vm, -1, "facing", VAL(1));
    L_4028472: ;
    /* @4028472 load */
    /* @4028480 load */
    /* @4028488 cmp */
    /* @4028492 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "x") < GM_READ(vm, -1, "x")))) goto L_4028584;
    /* @4028496 constant */
    /* @4028500 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    /* @4028508 constant */
    /* @4028512 cast */
    /* @4028516 load */
    /* @4028524 load */
    /* @4028532 constant */
    /* @4028536 sub */
    /* @4028540 call */
    GM_SITE(vm, 213, 4028540);
    /* @4028548 cast */
    /* @4028552 not */
    /* @4028556 bf */
    v3 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(100)), GM_READ(vm, -1, "y"), VAL(34))));
    if (!TRUTH(v3)) goto L_4028572;
    /* @4028560 constant */
    /* @4028564 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-1));
    L_4028572: ;
    /* @4028572 constant */
    /* @4028576 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    L_4028584: ;
    /* @4028584 load */
    /* @4028592 constant */
    /* @4028596 cmp */
    /* @4028600 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_4028628;
    /* @4028604 constant */
    /* @4028608 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4028616 constant */
    /* @4028620 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_4028628: ;
    return;
}
