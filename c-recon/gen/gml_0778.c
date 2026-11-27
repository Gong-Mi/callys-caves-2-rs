/* generated from CODE 778 (gml_Object_obj_boss6intro_Create_0), source start 5038620, end 5038824. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0778(GmVM* vm) {
    Val v1;
    /* @5038620 load */
    /* @5038628 constant */
    /* @5038632 cmp */
    /* @5038636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5038644;
    /* @5038640 b */
    goto L_5038700;
    L_5038644: ;
    /* @5038644 load */
    /* @5038652 constant */
    /* @5038656 cmp */
    /* @5038660 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5038700;
    /* @5038664 constant */
    /* @5038668 cast */
    /* @5038672 constant */
    /* @5038676 cast */
    /* @5038680 constant */
    /* @5038684 cast */
    /* @5038688 call */
    GM_SITE(vm, 778, 5038688);
    /* @5038696 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(4), VAL(0), VAL(0)));
    L_5038700: ;
    /* @5038700 constant */
    /* @5038704 constant */
    /* @5038708 constant */
    /* @5038712 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(60));
    /* @5038720 constant */
    /* @5038724 cast */
    /* @5038728 load */
    /* @5038736 constant */
    /* @5038740 sub */
    /* @5038744 load */
    /* @5038752 constant */
    /* @5038756 add */
    /* @5038760 call */
    GM_SITE(vm, 778, 5038760);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(320));
    /* @5038768 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(30)), VAL(164)));
    /* @5038772 constant */
    /* @5038776 cast */
    /* @5038780 load */
    /* @5038788 constant */
    /* @5038792 sub */
    /* @5038796 load */
    /* @5038804 constant */
    /* @5038808 sub */
    /* @5038812 call */
    GM_SITE(vm, 778, 5038812);
    /* @5038820 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(320)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(165)));
    L_5038824: ;
    return;
}
