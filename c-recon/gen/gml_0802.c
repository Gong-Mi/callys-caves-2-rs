/* generated from CODE 802 (gml_Object_obj_bosspuff_Alarm_0), source start 5043148, end 5043264. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0802(GmVM* vm) {
    /* @5043148 constant */
    /* @5043152 cast */
    /* @5043156 load */
    /* @5043164 load */
    /* @5043172 call */
    GM_SITE(vm, 802, 5043172);
    /* @5043180 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(188)));
    /* @5043184 load */
    /* @5043192 constant */
    /* @5043196 cmp */
    /* @5043200 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5043208;
    /* @5043204 b */
    goto L_5043264;
    L_5043208: ;
    /* @5043208 load */
    /* @5043216 constant */
    /* @5043220 cmp */
    /* @5043224 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5043264;
    /* @5043228 constant */
    /* @5043232 cast */
    /* @5043236 constant */
    /* @5043240 cast */
    /* @5043244 constant */
    /* @5043248 cast */
    /* @5043252 call */
    GM_SITE(vm, 802, 5043252);
    /* @5043260 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(8), VAL(0), VAL(0)));
    L_5043264: ;
    return;
}
