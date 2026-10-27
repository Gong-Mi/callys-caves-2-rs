/* generated from CODE 320 (gml_Object_obj_finalbossgrenade_Destroy_0), source start 4190020, end 4190100. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0320(GmVM* vm) {
    /* @4190020 load */
    /* @4190028 constant */
    /* @4190032 cmp */
    /* @4190036 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4190044;
    /* @4190040 b */
    goto L_4190100;
    L_4190044: ;
    /* @4190044 load */
    /* @4190052 constant */
    /* @4190056 cmp */
    /* @4190060 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4190100;
    /* @4190064 constant */
    /* @4190068 cast */
    /* @4190072 constant */
    /* @4190076 cast */
    /* @4190080 constant */
    /* @4190084 cast */
    /* @4190088 call */
    GM_SITE(vm, 320, 4190088);
    /* @4190096 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(8), VAL(0), VAL(0)));
    L_4190100: ;
    return;
}
