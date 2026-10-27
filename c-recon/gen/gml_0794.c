/* generated from CODE 794 (gml_Object_obj_bosspuff_Alarm_8), source start 5042156, end 5042280. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0794(GmVM* vm) {
    Val v1;
    /* @5042156 constant */
    /* @5042160 cast */
    /* @5042164 load */
    /* @5042172 constant */
    /* @5042176 add */
    /* @5042180 load */
    /* @5042188 call */
    GM_SITE(vm, 794, 5042188);
    v1 = GM_ADD(GM_READ(vm, -1, "y"), VAL(10));
    /* @5042196 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), v1, VAL(188)));
    /* @5042200 load */
    /* @5042208 constant */
    /* @5042212 cmp */
    /* @5042216 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5042224;
    /* @5042220 b */
    goto L_5042280;
    L_5042224: ;
    /* @5042224 load */
    /* @5042232 constant */
    /* @5042236 cmp */
    /* @5042240 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5042280;
    /* @5042244 constant */
    /* @5042248 cast */
    /* @5042252 constant */
    /* @5042256 cast */
    /* @5042260 constant */
    /* @5042264 cast */
    /* @5042268 call */
    GM_SITE(vm, 794, 5042268);
    /* @5042276 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(8), VAL(0), VAL(0)));
    L_5042280: ;
    return;
}
