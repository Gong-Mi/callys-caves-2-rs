/* generated from CODE 304 (gml_Object_obj_energywave_Create_0), source start 4156548, end 4156708. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0304(GmVM* vm) {
    /* @4156548 constant */
    /* @4156552 store */
    GM_WRITE(vm, -1, "canhit", VAL(0));
    /* @4156560 load */
    /* @4156568 constant */
    /* @4156572 cmp */
    /* @4156576 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(1)))) goto L_4156596;
    /* @4156580 constant */
    /* @4156584 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-20));
    /* @4156592 b */
    goto L_4156608;
    L_4156596: ;
    /* @4156596 constant */
    /* @4156600 store */
    GM_WRITE(vm, -1, "hspeed", VAL(20));
    L_4156608: ;
    /* @4156608 constant */
    /* @4156612 constant */
    /* @4156616 constant */
    /* @4156620 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(12));
    /* @4156628 load */
    /* @4156636 constant */
    /* @4156640 cmp */
    /* @4156644 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4156652;
    /* @4156648 b */
    goto L_4156708;
    L_4156652: ;
    /* @4156652 load */
    /* @4156660 constant */
    /* @4156664 cmp */
    /* @4156668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4156708;
    /* @4156672 constant */
    /* @4156676 cast */
    /* @4156680 constant */
    /* @4156684 cast */
    /* @4156688 constant */
    /* @4156692 cast */
    /* @4156696 call */
    GM_SITE(vm, 304, 4156696);
    /* @4156704 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(6), VAL(0), VAL(0)));
    L_4156708: ;
    return;
}
