/* generated from CODE 300 (gml_Object_obj_rocket_Destroy_0), source start 4148000, end 4148080. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0300(GmVM* vm) {
    /* @4148000 load */
    /* @4148008 constant */
    /* @4148012 cmp */
    /* @4148016 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4148024;
    /* @4148020 b */
    goto L_4148080;
    L_4148024: ;
    /* @4148024 load */
    /* @4148032 constant */
    /* @4148036 cmp */
    /* @4148040 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4148080;
    /* @4148044 constant */
    /* @4148048 cast */
    /* @4148052 constant */
    /* @4148056 cast */
    /* @4148060 constant */
    /* @4148064 cast */
    /* @4148068 call */
    GM_SITE(vm, 300, 4148068);
    /* @4148076 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(8), VAL(0), VAL(0)));
    L_4148080: ;
    return;
}
