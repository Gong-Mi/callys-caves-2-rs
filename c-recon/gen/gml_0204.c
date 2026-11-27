/* generated from CODE 204 (gml_Object_obj_boss5_Alarm_8), source start 4017524, end 4017736. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0204(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    /* @4017524 load */
    /* @4017532 constant */
    /* @4017536 cmp */
    /* @4017540 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_4017604;
    /* @4017544 constant */
    /* @4017548 cast */
    /* @4017552 load */
    /* @4017560 constant */
    /* @4017564 sub */
    /* @4017568 load */
    /* @4017576 constant */
    /* @4017580 sub */
    /* @4017584 call */
    GM_SITE(vm, 204, 4017584);
    /* @4017592 store */
    v1 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(50)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(54));
    GM_WRITE(vm, -1, "bullet1", v1);
    /* @4017600 b */
    goto L_4017680;
    L_4017604: ;
    /* @4017604 load */
    /* @4017612 constant */
    /* @4017616 cmp */
    /* @4017620 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_4017680;
    /* @4017624 constant */
    /* @4017628 cast */
    /* @4017632 load */
    /* @4017640 constant */
    /* @4017644 sub */
    /* @4017648 load */
    /* @4017656 constant */
    /* @4017660 add */
    /* @4017664 call */
    GM_SITE(vm, 204, 4017664);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(50));
    /* @4017672 store */
    v3 = GM_CALL(vm, "instance_create", 3, v2, (GM_READ(vm, -1, "y") - VAL(5)), VAL(54));
    GM_WRITE(vm, -1, "bullet1", v3);
    L_4017680: ;
    /* @4017680 constant */
    /* @4017684 cast */
    /* @4017688 constant */
    /* @4017692 cast */
    /* @4017696 constant */
    /* @4017700 cast */
    /* @4017704 call */
    GM_SITE(vm, 204, 4017704);
    /* @4017712 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(12), VAL(0), VAL(0)));
    /* @4017716 constant */
    /* @4017720 constant */
    /* @4017724 constant */
    /* @4017728 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(9), VAL(10));
    L_4017736: ;
    return;
}
