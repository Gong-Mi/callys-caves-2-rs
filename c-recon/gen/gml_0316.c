/* generated from CODE 316 (gml_Object_obj_finalbosslaser_Create_0), source start 4189080, end 4189184. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0316(GmVM* vm) {
    /* @4189080 constant */
    /* @4189084 store */
    GM_WRITE(vm, -1, "canhit", VAL(0));
    /* @4189092 constant */
    /* @4189096 store */
    GM_WRITE(vm, -1, "speed", VAL(10));
    /* @4189104 load */
    /* @4189112 constant */
    /* @4189116 cmp */
    /* @4189120 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4189128;
    /* @4189124 b */
    goto L_4189184;
    L_4189128: ;
    /* @4189128 load */
    /* @4189136 constant */
    /* @4189140 cmp */
    /* @4189144 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4189184;
    /* @4189148 constant */
    /* @4189152 cast */
    /* @4189156 constant */
    /* @4189160 cast */
    /* @4189164 constant */
    /* @4189168 cast */
    /* @4189172 call */
    GM_SITE(vm, 316, 4189172);
    /* @4189180 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(15), VAL(0), VAL(0)));
    L_4189184: ;
    return;
}
