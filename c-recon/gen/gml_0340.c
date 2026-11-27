/* generated from CODE 340 (gml_Object_obj_coin_Destroy_0), source start 4197032, end 4197112. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0340(GmVM* vm) {
    /* @4197032 load */
    /* @4197040 constant */
    /* @4197044 cmp */
    /* @4197048 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4197056;
    /* @4197052 b */
    goto L_4197112;
    L_4197056: ;
    /* @4197056 load */
    /* @4197064 constant */
    /* @4197068 cmp */
    /* @4197072 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4197112;
    /* @4197076 constant */
    /* @4197080 cast */
    /* @4197084 constant */
    /* @4197088 cast */
    /* @4197092 load */
    /* @4197100 call */
    GM_SITE(vm, 340, 4197100);
    /* @4197108 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, GM_READ(vm, -5, "coinsound"), VAL(0), VAL(0)));
    L_4197112: ;
    return;
}
