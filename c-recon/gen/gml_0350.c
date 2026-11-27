/* generated from CODE 350 (gml_Object_obj_health_Destroy_0), source start 4198640, end 4198720. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0350(GmVM* vm) {
    /* @4198640 load */
    /* @4198648 constant */
    /* @4198652 cmp */
    /* @4198656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4198664;
    /* @4198660 b */
    goto L_4198720;
    L_4198664: ;
    /* @4198664 load */
    /* @4198672 constant */
    /* @4198676 cmp */
    /* @4198680 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4198720;
    /* @4198684 constant */
    /* @4198688 cast */
    /* @4198692 constant */
    /* @4198696 cast */
    /* @4198700 constant */
    /* @4198704 cast */
    /* @4198708 call */
    GM_SITE(vm, 350, 4198708);
    /* @4198716 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(19), VAL(0), VAL(0)));
    L_4198720: ;
    return;
}
