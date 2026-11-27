/* generated from CODE 228 (gml_Object_obj_finalboss_Alarm_0), source start 4030680, end 4030772. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0228(GmVM* vm) {
    /* @4030680 load */
    /* @4030688 constant */
    /* @4030692 cmp */
    /* @4030696 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4030704;
    /* @4030700 b */
    goto L_4030760;
    L_4030704: ;
    /* @4030704 load */
    /* @4030712 constant */
    /* @4030716 cmp */
    /* @4030720 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4030760;
    /* @4030724 constant */
    /* @4030728 cast */
    /* @4030732 constant */
    /* @4030736 cast */
    /* @4030740 constant */
    /* @4030744 cast */
    /* @4030748 call */
    GM_SITE(vm, 228, 4030748);
    /* @4030756 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(7), VAL(0), VAL(0)));
    L_4030760: ;
    /* @4030760 call */
    GM_SITE(vm, 228, 4030760);
    /* @4030768 popz */
    (void)(GM_CALL(vm, "action_kill_object", 0));
    L_4030772: ;
    return;
}
