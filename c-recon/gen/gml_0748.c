/* generated from CODE 748 (gml_Object_obj_boss2intro_Create_0), source start 5035620, end 5035824. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0748(GmVM* vm) {
    Val v1;
    /* @5035620 load */
    /* @5035628 constant */
    /* @5035632 cmp */
    /* @5035636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5035644;
    /* @5035640 b */
    goto L_5035700;
    L_5035644: ;
    /* @5035644 load */
    /* @5035652 constant */
    /* @5035656 cmp */
    /* @5035660 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5035700;
    /* @5035664 constant */
    /* @5035668 cast */
    /* @5035672 constant */
    /* @5035676 cast */
    /* @5035680 constant */
    /* @5035684 cast */
    /* @5035688 call */
    GM_SITE(vm, 748, 5035688);
    /* @5035696 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(4), VAL(0), VAL(0)));
    L_5035700: ;
    /* @5035700 constant */
    /* @5035704 constant */
    /* @5035708 constant */
    /* @5035712 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(60));
    /* @5035720 constant */
    /* @5035724 cast */
    /* @5035728 load */
    /* @5035736 constant */
    /* @5035740 sub */
    /* @5035744 load */
    /* @5035752 constant */
    /* @5035756 add */
    /* @5035760 call */
    GM_SITE(vm, 748, 5035760);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(320));
    /* @5035768 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(30)), VAL(164)));
    /* @5035772 constant */
    /* @5035776 cast */
    /* @5035780 load */
    /* @5035788 constant */
    /* @5035792 sub */
    /* @5035796 load */
    /* @5035804 constant */
    /* @5035808 sub */
    /* @5035812 call */
    GM_SITE(vm, 748, 5035812);
    /* @5035820 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(320)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(165)));
    L_5035824: ;
    return;
}
