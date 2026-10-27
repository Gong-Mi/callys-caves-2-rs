/* generated from CODE 203 (gml_Object_obj_boss5_Alarm_9), source start 4017312, end 4017524. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0203(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    /* @4017312 load */
    /* @4017320 constant */
    /* @4017324 cmp */
    /* @4017328 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_4017392;
    /* @4017332 constant */
    /* @4017336 cast */
    /* @4017340 load */
    /* @4017348 constant */
    /* @4017352 sub */
    /* @4017356 load */
    /* @4017364 constant */
    /* @4017368 sub */
    /* @4017372 call */
    GM_SITE(vm, 203, 4017372);
    /* @4017380 store */
    v1 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(50)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(54));
    GM_WRITE(vm, -1, "bullet1", v1);
    /* @4017388 b */
    goto L_4017468;
    L_4017392: ;
    /* @4017392 load */
    /* @4017400 constant */
    /* @4017404 cmp */
    /* @4017408 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_4017468;
    /* @4017412 constant */
    /* @4017416 cast */
    /* @4017420 load */
    /* @4017428 constant */
    /* @4017432 sub */
    /* @4017436 load */
    /* @4017444 constant */
    /* @4017448 add */
    /* @4017452 call */
    GM_SITE(vm, 203, 4017452);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(50));
    /* @4017460 store */
    v3 = GM_CALL(vm, "instance_create", 3, v2, (GM_READ(vm, -1, "y") - VAL(5)), VAL(54));
    GM_WRITE(vm, -1, "bullet1", v3);
    L_4017468: ;
    /* @4017468 constant */
    /* @4017472 cast */
    /* @4017476 constant */
    /* @4017480 cast */
    /* @4017484 constant */
    /* @4017488 cast */
    /* @4017492 call */
    GM_SITE(vm, 203, 4017492);
    /* @4017500 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(12), VAL(0), VAL(0)));
    /* @4017504 constant */
    /* @4017508 constant */
    /* @4017512 constant */
    /* @4017516 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(30));
    L_4017524: ;
    return;
}
