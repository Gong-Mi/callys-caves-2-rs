/* generated from CODE 431 (gml_Object_obj_healthregen_Mouse_0), source start 4608048, end 4608220. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0431(GmVM* vm) {
    Val p4608096_0;
    /* @4608048 load */
    /* @4608056 constant */
    /* @4608064 cmp */
    /* @4608068 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "score") >= VAL(75000)))) goto L_4608092;
    /* @4608072 load */
    /* @4608080 constant */
    /* @4608084 cmp */
    /* @4608088 b */
    p4608096_0 = NUMBOOL(GM_READ(vm, -5, "healthregenbought") == VAL(0));
    goto L_4608096;
    L_4608092: ;
    /* @4608092 constant */
    p4608096_0 = VAL(0);
    L_4608096: ;
    /* @4608096 bf */
    if (!TRUTH(p4608096_0)) goto L_4608220;
    /* @4608100 load */
    /* @4608108 constant */
    /* @4608116 sub */
    /* @4608120 store */
    GM_WRITE(vm, -1, "score", (GM_READ(vm, -1, "score") - VAL(75000)));
    /* @4608128 constant */
    /* @4608132 store */
    GM_WRITE(vm, -5, "healthregenbought", VAL(1));
    /* @4608140 load */
    /* @4608148 constant */
    /* @4608152 cmp */
    /* @4608156 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4608164;
    /* @4608160 b */
    goto L_4608220;
    L_4608164: ;
    /* @4608164 load */
    /* @4608172 constant */
    /* @4608176 cmp */
    /* @4608180 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4608220;
    /* @4608184 constant */
    /* @4608188 cast */
    /* @4608192 constant */
    /* @4608196 cast */
    /* @4608200 constant */
    /* @4608204 cast */
    /* @4608208 call */
    GM_SITE(vm, 431, 4608208);
    /* @4608216 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(19), VAL(0), VAL(0)));
    L_4608220: ;
    return;
}
