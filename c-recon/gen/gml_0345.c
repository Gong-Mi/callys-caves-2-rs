/* generated from CODE 345 (gml_Object_obj_silvercoin_Destroy_0), source start 4197708, end 4197788. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0345(GmVM* vm) {
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4197732;
    goto L_4197788;
    L_4197732: ;
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4197788;
    (void)(GM_CALL(vm, "audio_play_sound", 3, GM_READ(vm, -5, "coinsound"), VAL(0), VAL(0)));
    L_4197788: ;
    return;
}
