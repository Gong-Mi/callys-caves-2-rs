/* generated from CODE 345 (gml_Object_obj_silvercoin_Destroy_0), source start 4197708, end 4197788. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0345(GmVM* vm) {
    /* @4197708 load */
    /* @4197716 constant */
    /* @4197720 cmp */
    /* @4197724 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4197732;
    /* @4197728 b */
    goto L_4197788;
    L_4197732: ;
    /* @4197732 load */
    /* @4197740 constant */
    /* @4197744 cmp */
    /* @4197748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4197788;
    /* @4197752 constant */
    /* @4197756 cast */
    /* @4197760 constant */
    /* @4197764 cast */
    /* @4197768 load */
    /* @4197776 call */
    GM_SITE(vm, 345, 4197776);
    /* @4197784 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, GM_READ(vm, -5, "coinsound"), VAL(0), VAL(0)));
    L_4197788: ;
    return;
}
