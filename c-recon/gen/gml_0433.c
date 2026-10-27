/* generated from CODE 433 (gml_Object_obj_strengthupgrade_Mouse_0), source start 4611492, end 4611656. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0433(GmVM* vm) {
    Val p4611536_0;
    /* @4611492 load */
    /* @4611500 constant */
    /* @4611504 cmp */
    /* @4611508 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "score") >= VAL(3000)))) goto L_4611532;
    /* @4611512 load */
    /* @4611520 constant */
    /* @4611524 cmp */
    /* @4611528 b */
    p4611536_0 = NUMBOOL(GM_READ(vm, -5, "strengthupgradebought") == VAL(0));
    goto L_4611536;
    L_4611532: ;
    /* @4611532 constant */
    p4611536_0 = VAL(0);
    L_4611536: ;
    /* @4611536 bf */
    if (!TRUTH(p4611536_0)) goto L_4611656;
    /* @4611540 load */
    /* @4611548 constant */
    /* @4611552 sub */
    /* @4611556 store */
    GM_WRITE(vm, -1, "score", (GM_READ(vm, -1, "score") - VAL(3000)));
    /* @4611564 constant */
    /* @4611568 store */
    GM_WRITE(vm, -5, "strengthupgradebought", VAL(1));
    /* @4611576 load */
    /* @4611584 constant */
    /* @4611588 cmp */
    /* @4611592 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4611600;
    /* @4611596 b */
    goto L_4611656;
    L_4611600: ;
    /* @4611600 load */
    /* @4611608 constant */
    /* @4611612 cmp */
    /* @4611616 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4611656;
    /* @4611620 constant */
    /* @4611624 cast */
    /* @4611628 constant */
    /* @4611632 cast */
    /* @4611636 constant */
    /* @4611640 cast */
    /* @4611644 call */
    GM_SITE(vm, 433, 4611644);
    /* @4611652 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(19), VAL(0), VAL(0)));
    L_4611656: ;
    return;
}
