/* generated from CODE 342 (gml_Object_obj_gem_Destroy_0), source start 4197240, end 4197320. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0342(GmVM* vm) {
    /* @4197240 load */
    /* @4197248 constant */
    /* @4197252 cmp */
    /* @4197256 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4197264;
    /* @4197260 b */
    goto L_4197320;
    L_4197264: ;
    /* @4197264 load */
    /* @4197272 constant */
    /* @4197276 cmp */
    /* @4197280 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4197320;
    /* @4197284 constant */
    /* @4197288 cast */
    /* @4197292 constant */
    /* @4197296 cast */
    /* @4197300 load */
    /* @4197308 call */
    GM_SITE(vm, 342, 4197308);
    /* @4197316 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, GM_READ(vm, -5, "coinsound"), VAL(0), VAL(0)));
    L_4197320: ;
    return;
}
