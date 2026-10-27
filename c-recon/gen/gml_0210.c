/* generated from CODE 210 (gml_Object_obj_boss5_Alarm_2), source start 4018596, end 4018808. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0210(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    /* @4018596 load */
    /* @4018604 constant */
    /* @4018608 cmp */
    /* @4018612 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_4018676;
    /* @4018616 constant */
    /* @4018620 cast */
    /* @4018624 load */
    /* @4018632 constant */
    /* @4018636 sub */
    /* @4018640 load */
    /* @4018648 constant */
    /* @4018652 sub */
    /* @4018656 call */
    GM_SITE(vm, 210, 4018656);
    /* @4018664 store */
    v1 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(50)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(54));
    GM_WRITE(vm, -1, "bullet1", v1);
    /* @4018672 b */
    goto L_4018752;
    L_4018676: ;
    /* @4018676 load */
    /* @4018684 constant */
    /* @4018688 cmp */
    /* @4018692 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_4018752;
    /* @4018696 constant */
    /* @4018700 cast */
    /* @4018704 load */
    /* @4018712 constant */
    /* @4018716 sub */
    /* @4018720 load */
    /* @4018728 constant */
    /* @4018732 add */
    /* @4018736 call */
    GM_SITE(vm, 210, 4018736);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(50));
    /* @4018744 store */
    v3 = GM_CALL(vm, "instance_create", 3, v2, (GM_READ(vm, -1, "y") - VAL(5)), VAL(54));
    GM_WRITE(vm, -1, "bullet1", v3);
    L_4018752: ;
    /* @4018752 constant */
    /* @4018756 cast */
    /* @4018760 constant */
    /* @4018764 cast */
    /* @4018768 constant */
    /* @4018772 cast */
    /* @4018776 call */
    GM_SITE(vm, 210, 4018776);
    /* @4018784 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(12), VAL(0), VAL(0)));
    /* @4018788 constant */
    /* @4018792 constant */
    /* @4018796 constant */
    /* @4018800 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(10));
    L_4018808: ;
    return;
}
