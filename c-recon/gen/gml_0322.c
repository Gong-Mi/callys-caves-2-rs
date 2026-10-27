/* generated from CODE 322 (gml_Object_obj_finalbossgrenade_Alarm_0), source start 4190112, end 4190260. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0322(GmVM* vm) {
    /* @4190112 load */
    /* @4190120 constant */
    /* @4190124 cmp */
    /* @4190128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "sprite_index") != VAL(50)))) goto L_4190156;
    /* @4190132 constant */
    /* @4190136 store */
    GM_WRITE(vm, -1, "image_index", VAL(0));
    /* @4190144 constant */
    /* @4190148 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(50));
    L_4190156: ;
    /* @4190156 constant */
    /* @4190160 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4190168 constant */
    /* @4190172 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @4190180 load */
    /* @4190188 constant */
    /* @4190192 cmp */
    /* @4190196 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4190204;
    /* @4190200 b */
    goto L_4190260;
    L_4190204: ;
    /* @4190204 load */
    /* @4190212 constant */
    /* @4190216 cmp */
    /* @4190220 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4190260;
    /* @4190224 constant */
    /* @4190228 cast */
    /* @4190232 constant */
    /* @4190236 cast */
    /* @4190240 constant */
    /* @4190244 cast */
    /* @4190248 call */
    GM_SITE(vm, 322, 4190248);
    /* @4190256 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(8), VAL(0), VAL(0)));
    L_4190260: ;
    return;
}
