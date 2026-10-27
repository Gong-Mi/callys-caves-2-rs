/* generated from CODE 427 (gml_Object_obj_swordupgrade3_Mouse_0), source start 4600972, end 4601172. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0427(GmVM* vm) {
    Val p4601016_0;
    /* @4600972 load */
    /* @4600980 constant */
    /* @4600984 cmp */
    /* @4600988 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "score") >= VAL(15000)))) goto L_4601012;
    /* @4600992 load */
    /* @4601000 constant */
    /* @4601004 cmp */
    /* @4601008 b */
    p4601016_0 = NUMBOOL(GM_READ(vm, -5, "swordupgrade3bought") == VAL(0));
    goto L_4601016;
    L_4601012: ;
    /* @4601012 constant */
    p4601016_0 = VAL(0);
    L_4601016: ;
    /* @4601016 bf */
    if (!TRUTH(p4601016_0)) goto L_4601172;
    /* @4601020 constant */
    /* @4601024 store */
    GM_WRITE(vm, -5, "swordupgrade3bought", VAL(1));
    /* @4601032 constant */
    /* @4601036 store */
    GM_WRITE(vm, -5, "swordupgrade2bought", VAL(1));
    /* @4601044 constant */
    /* @4601048 store */
    GM_WRITE(vm, -5, "swordupgradebought", VAL(1));
    /* @4601056 load */
    /* @4601064 constant */
    /* @4601068 sub */
    /* @4601072 store */
    GM_WRITE(vm, -1, "score", (GM_READ(vm, -1, "score") - VAL(15000)));
    /* @4601080 constant */
    /* @4601084 store */
    GM_WRITE(vm, -5, "sword", VAL(3));
    /* @4601092 load */
    /* @4601100 constant */
    /* @4601104 cmp */
    /* @4601108 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4601116;
    /* @4601112 b */
    goto L_4601172;
    L_4601116: ;
    /* @4601116 load */
    /* @4601124 constant */
    /* @4601128 cmp */
    /* @4601132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4601172;
    /* @4601136 constant */
    /* @4601140 cast */
    /* @4601144 constant */
    /* @4601148 cast */
    /* @4601152 constant */
    /* @4601156 cast */
    /* @4601160 call */
    GM_SITE(vm, 427, 4601160);
    /* @4601168 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(19), VAL(0), VAL(0)));
    L_4601172: ;
    return;
}
