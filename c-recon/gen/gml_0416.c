/* generated from CODE 416 (gml_Object_obj_powerupgrade2_Mouse_0), source start 4583240, end 4583416. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0416(GmVM* vm) {
    Val p4583284_0;
    /* @4583240 load */
    /* @4583248 constant */
    /* @4583252 cmp */
    /* @4583256 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "score") >= VAL(25000)))) goto L_4583280;
    /* @4583260 load */
    /* @4583268 constant */
    /* @4583272 cmp */
    /* @4583276 b */
    p4583284_0 = NUMBOOL(GM_READ(vm, -5, "powerupgrade2bought") == VAL(0));
    goto L_4583284;
    L_4583280: ;
    /* @4583280 constant */
    p4583284_0 = VAL(0);
    L_4583284: ;
    /* @4583284 bf */
    if (!TRUTH(p4583284_0)) goto L_4583416;
    /* @4583288 load */
    /* @4583296 constant */
    /* @4583300 sub */
    /* @4583304 store */
    GM_WRITE(vm, -1, "score", (GM_READ(vm, -1, "score") - VAL(25000)));
    /* @4583312 constant */
    /* @4583316 store */
    GM_WRITE(vm, -5, "pwr", VAL(3));
    /* @4583324 constant */
    /* @4583328 store */
    GM_WRITE(vm, -5, "powerupgrade2bought", VAL(1));
    /* @4583336 load */
    /* @4583344 constant */
    /* @4583348 cmp */
    /* @4583352 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4583360;
    /* @4583356 b */
    goto L_4583416;
    L_4583360: ;
    /* @4583360 load */
    /* @4583368 constant */
    /* @4583372 cmp */
    /* @4583376 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4583416;
    /* @4583380 constant */
    /* @4583384 cast */
    /* @4583388 constant */
    /* @4583392 cast */
    /* @4583396 constant */
    /* @4583400 cast */
    /* @4583404 call */
    GM_SITE(vm, 416, 4583404);
    /* @4583412 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(19), VAL(0), VAL(0)));
    L_4583416: ;
    return;
}
