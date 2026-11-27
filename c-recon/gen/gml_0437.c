/* generated from CODE 437 (gml_Object_obj_coinmultiplier5_Mouse_0), source start 4618524, end 4618700. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0437(GmVM* vm) {
    Val p4618568_0;
    /* @4618524 load */
    /* @4618532 constant */
    /* @4618536 cmp */
    /* @4618540 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "score") >= VAL(20000)))) goto L_4618564;
    /* @4618544 load */
    /* @4618552 constant */
    /* @4618556 cmp */
    /* @4618560 b */
    p4618568_0 = NUMBOOL(GM_READ(vm, -5, "coinmultiplier5bought") == VAL(0));
    goto L_4618568;
    L_4618564: ;
    /* @4618564 constant */
    p4618568_0 = VAL(0);
    L_4618568: ;
    /* @4618568 bf */
    if (!TRUTH(p4618568_0)) goto L_4618700;
    /* @4618572 load */
    /* @4618580 constant */
    /* @4618584 sub */
    /* @4618588 store */
    GM_WRITE(vm, -1, "score", (GM_READ(vm, -1, "score") - VAL(20000)));
    /* @4618596 constant */
    /* @4618600 store */
    GM_WRITE(vm, -5, "coinmultiply", VAL(5));
    /* @4618608 constant */
    /* @4618612 store */
    GM_WRITE(vm, -5, "coinmultiplier5bought", VAL(1));
    /* @4618620 load */
    /* @4618628 constant */
    /* @4618632 cmp */
    /* @4618636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4618644;
    /* @4618640 b */
    goto L_4618700;
    L_4618644: ;
    /* @4618644 load */
    /* @4618652 constant */
    /* @4618656 cmp */
    /* @4618660 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4618700;
    /* @4618664 constant */
    /* @4618668 cast */
    /* @4618672 constant */
    /* @4618676 cast */
    /* @4618680 constant */
    /* @4618684 cast */
    /* @4618688 call */
    GM_SITE(vm, 437, 4618688);
    /* @4618696 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(19), VAL(0), VAL(0)));
    L_4618700: ;
    return;
}
