/* generated from CODE 425 (gml_Object_obj_swordupgrade2_Mouse_0), source start 4597412, end 4597620. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0425(GmVM* vm) {
    Val p4597476_0;
    /* @4597412 load */
    /* @4597420 constant */
    /* @4597424 cmp */
    /* @4597428 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "swordupgrade3bought") != VAL(1)))) goto L_4597620;
    /* @4597432 load */
    /* @4597440 constant */
    /* @4597444 cmp */
    /* @4597448 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "score") >= VAL(10000)))) goto L_4597472;
    /* @4597452 load */
    /* @4597460 constant */
    /* @4597464 cmp */
    /* @4597468 b */
    p4597476_0 = NUMBOOL(GM_READ(vm, -5, "swordupgrade2bought") == VAL(0));
    goto L_4597476;
    L_4597472: ;
    /* @4597472 constant */
    p4597476_0 = VAL(0);
    L_4597476: ;
    /* @4597476 bf */
    if (!TRUTH(p4597476_0)) goto L_4597620;
    /* @4597480 constant */
    /* @4597484 store */
    GM_WRITE(vm, -5, "swordupgrade2bought", VAL(1));
    /* @4597492 constant */
    /* @4597496 store */
    GM_WRITE(vm, -5, "swordupgradebought", VAL(1));
    /* @4597504 load */
    /* @4597512 constant */
    /* @4597516 sub */
    /* @4597520 store */
    GM_WRITE(vm, -1, "score", (GM_READ(vm, -1, "score") - VAL(10000)));
    /* @4597528 constant */
    /* @4597532 store */
    GM_WRITE(vm, -5, "sword", VAL(2));
    /* @4597540 load */
    /* @4597548 constant */
    /* @4597552 cmp */
    /* @4597556 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4597564;
    /* @4597560 b */
    goto L_4597620;
    L_4597564: ;
    /* @4597564 load */
    /* @4597572 constant */
    /* @4597576 cmp */
    /* @4597580 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4597620;
    /* @4597584 constant */
    /* @4597588 cast */
    /* @4597592 constant */
    /* @4597596 cast */
    /* @4597600 constant */
    /* @4597604 cast */
    /* @4597608 call */
    GM_SITE(vm, 425, 4597608);
    /* @4597616 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(19), VAL(0), VAL(0)));
    L_4597620: ;
    return;
}
