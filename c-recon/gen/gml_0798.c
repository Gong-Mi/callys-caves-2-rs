/* generated from CODE 798 (gml_Object_obj_bosspuff_Alarm_4), source start 5042652, end 5042776. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0798(GmVM* vm) {
    /* @5042652 constant */
    /* @5042656 cast */
    /* @5042660 load */
    /* @5042668 constant */
    /* @5042672 sub */
    /* @5042676 load */
    /* @5042684 call */
    GM_SITE(vm, 798, 5042684);
    /* @5042692 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(188)));
    /* @5042696 load */
    /* @5042704 constant */
    /* @5042708 cmp */
    /* @5042712 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5042720;
    /* @5042716 b */
    goto L_5042776;
    L_5042720: ;
    /* @5042720 load */
    /* @5042728 constant */
    /* @5042732 cmp */
    /* @5042736 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5042776;
    /* @5042740 constant */
    /* @5042744 cast */
    /* @5042748 constant */
    /* @5042752 cast */
    /* @5042756 constant */
    /* @5042760 cast */
    /* @5042764 call */
    GM_SITE(vm, 798, 5042764);
    /* @5042772 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(8), VAL(0), VAL(0)));
    L_5042776: ;
    return;
}
