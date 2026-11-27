/* generated from CODE 209 (gml_Object_obj_boss5_Alarm_3), source start 4018384, end 4018596. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0209(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    /* @4018384 load */
    /* @4018392 constant */
    /* @4018396 cmp */
    /* @4018400 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_4018464;
    /* @4018404 constant */
    /* @4018408 cast */
    /* @4018412 load */
    /* @4018420 constant */
    /* @4018424 sub */
    /* @4018428 load */
    /* @4018436 constant */
    /* @4018440 sub */
    /* @4018444 call */
    GM_SITE(vm, 209, 4018444);
    /* @4018452 store */
    v1 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(50)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(54));
    GM_WRITE(vm, -1, "bullet1", v1);
    /* @4018460 b */
    goto L_4018540;
    L_4018464: ;
    /* @4018464 load */
    /* @4018472 constant */
    /* @4018476 cmp */
    /* @4018480 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_4018540;
    /* @4018484 constant */
    /* @4018488 cast */
    /* @4018492 load */
    /* @4018500 constant */
    /* @4018504 sub */
    /* @4018508 load */
    /* @4018516 constant */
    /* @4018520 add */
    /* @4018524 call */
    GM_SITE(vm, 209, 4018524);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(50));
    /* @4018532 store */
    v3 = GM_CALL(vm, "instance_create", 3, v2, (GM_READ(vm, -1, "y") - VAL(5)), VAL(54));
    GM_WRITE(vm, -1, "bullet1", v3);
    L_4018540: ;
    /* @4018540 constant */
    /* @4018544 cast */
    /* @4018548 constant */
    /* @4018552 cast */
    /* @4018556 constant */
    /* @4018560 cast */
    /* @4018564 call */
    GM_SITE(vm, 209, 4018564);
    /* @4018572 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(12), VAL(0), VAL(0)));
    /* @4018576 constant */
    /* @4018580 constant */
    /* @4018584 constant */
    /* @4018588 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    L_4018596: ;
    return;
}
