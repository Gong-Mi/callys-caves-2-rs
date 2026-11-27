/* generated from CODE 327 (gml_Object_obj_hulkingbanditbullet_Alarm_1), source start 4190968, end 4191112. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0327(GmVM* vm) {
    /* @4190968 load */
    /* @4190976 constant */
    /* @4190980 cmp */
    /* @4190984 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "sprite_index") != VAL(50)))) goto L_4191012;
    /* @4190988 constant */
    /* @4190992 store */
    GM_WRITE(vm, -1, "image_index", VAL(0));
    /* @4191000 constant */
    /* @4191004 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(50));
    L_4191012: ;
    /* @4191012 load */
    /* @4191020 constant */
    /* @4191024 cmp */
    /* @4191028 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4191036;
    /* @4191032 b */
    goto L_4191092;
    L_4191036: ;
    /* @4191036 load */
    /* @4191044 constant */
    /* @4191048 cmp */
    /* @4191052 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4191092;
    /* @4191056 constant */
    /* @4191060 cast */
    /* @4191064 constant */
    /* @4191068 cast */
    /* @4191072 constant */
    /* @4191076 cast */
    /* @4191080 call */
    GM_SITE(vm, 327, 4191080);
    /* @4191088 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(7), VAL(0), VAL(0)));
    L_4191092: ;
    /* @4191092 constant */
    /* @4191096 constant */
    /* @4191100 constant */
    /* @4191104 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(18));
    L_4191112: ;
    return;
}
