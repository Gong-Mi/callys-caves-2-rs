/* generated from CODE 429 (gml_Object_obj_energywaveupgrade_Mouse_0), source start 4604524, end 4604696. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0429(GmVM* vm) {
    Val p4604572_0;
    /* @4604524 load */
    /* @4604532 constant */
    /* @4604540 cmp */
    /* @4604544 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "score") >= VAL(50000)))) goto L_4604568;
    /* @4604548 load */
    /* @4604556 constant */
    /* @4604560 cmp */
    /* @4604564 b */
    p4604572_0 = NUMBOOL(GM_READ(vm, -5, "energywavebought") == VAL(0));
    goto L_4604572;
    L_4604568: ;
    /* @4604568 constant */
    p4604572_0 = VAL(0);
    L_4604572: ;
    /* @4604572 bf */
    if (!TRUTH(p4604572_0)) goto L_4604696;
    /* @4604576 load */
    /* @4604584 constant */
    /* @4604592 sub */
    /* @4604596 store */
    GM_WRITE(vm, -1, "score", (GM_READ(vm, -1, "score") - VAL(50000)));
    /* @4604604 constant */
    /* @4604608 store */
    GM_WRITE(vm, -5, "energywavebought", VAL(1));
    /* @4604616 load */
    /* @4604624 constant */
    /* @4604628 cmp */
    /* @4604632 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4604640;
    /* @4604636 b */
    goto L_4604696;
    L_4604640: ;
    /* @4604640 load */
    /* @4604648 constant */
    /* @4604652 cmp */
    /* @4604656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4604696;
    /* @4604660 constant */
    /* @4604664 cast */
    /* @4604668 constant */
    /* @4604672 cast */
    /* @4604676 constant */
    /* @4604680 cast */
    /* @4604684 call */
    GM_SITE(vm, 429, 4604684);
    /* @4604692 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(19), VAL(0), VAL(0)));
    L_4604696: ;
    return;
}
