/* generated from CODE 208 (gml_Object_obj_boss5_Alarm_4), source start 4018172, end 4018384. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0208(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    /* @4018172 load */
    /* @4018180 constant */
    /* @4018184 cmp */
    /* @4018188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_4018252;
    /* @4018192 constant */
    /* @4018196 cast */
    /* @4018200 load */
    /* @4018208 constant */
    /* @4018212 sub */
    /* @4018216 load */
    /* @4018224 constant */
    /* @4018228 sub */
    /* @4018232 call */
    GM_SITE(vm, 208, 4018232);
    /* @4018240 store */
    v1 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(50)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(54));
    GM_WRITE(vm, -1, "bullet1", v1);
    /* @4018248 b */
    goto L_4018328;
    L_4018252: ;
    /* @4018252 load */
    /* @4018260 constant */
    /* @4018264 cmp */
    /* @4018268 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_4018328;
    /* @4018272 constant */
    /* @4018276 cast */
    /* @4018280 load */
    /* @4018288 constant */
    /* @4018292 sub */
    /* @4018296 load */
    /* @4018304 constant */
    /* @4018308 add */
    /* @4018312 call */
    GM_SITE(vm, 208, 4018312);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(50));
    /* @4018320 store */
    v3 = GM_CALL(vm, "instance_create", 3, v2, (GM_READ(vm, -1, "y") - VAL(5)), VAL(54));
    GM_WRITE(vm, -1, "bullet1", v3);
    L_4018328: ;
    /* @4018328 constant */
    /* @4018332 cast */
    /* @4018336 constant */
    /* @4018340 cast */
    /* @4018344 constant */
    /* @4018348 cast */
    /* @4018352 call */
    GM_SITE(vm, 208, 4018352);
    /* @4018360 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(12), VAL(0), VAL(0)));
    /* @4018364 constant */
    /* @4018368 constant */
    /* @4018372 constant */
    /* @4018376 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(6), VAL(10));
    L_4018384: ;
    return;
}
