/* generated from CODE 654 (gml_Object_obj_lloydtutorial15_Create_0), source start 4987284, end 4987580. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0654(GmVM* vm) {
    /* @4987284 constant */
    /* @4987288 cast */
    /* @4987292 call */
    GM_SITE(vm, 654, 4987292);
    /* @4987300 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(1)));
    /* @4987304 constant */
    /* @4987308 store */
    GM_WRITE(vm, -1, "taplock", VAL(0));
    /* @4987316 constant */
    /* @4987320 store */
    GM_WRITE(vm, -1, "drawpanel1", VAL(1));
    /* @4987328 constant */
    /* @4987332 store */
    GM_WRITE(vm, -1, "drawpanel2", VAL(0));
    /* @4987340 constant */
    /* @4987344 store */
    GM_WRITE(vm, -1, "drawpanel3", VAL(0));
    /* @4987352 constant */
    /* @4987356 store */
    GM_WRITE(vm, -1, "drawpanel4", VAL(0));
    /* @4987364 constant */
    /* @4987368 store */
    GM_WRITE(vm, -1, "drawpanel5", VAL(0));
    /* @4987376 constant */
    /* @4987380 store */
    GM_WRITE(vm, -1, "drawpanel6", VAL(0));
    /* @4987388 constant */
    /* @4987392 constant */
    /* @4987396 constant */
    /* @4987400 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(100));
    /* @4987408 constant */
    /* @4987412 constant */
    /* @4987416 constant */
    /* @4987420 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(200));
    /* @4987428 constant */
    /* @4987432 constant */
    /* @4987436 constant */
    /* @4987440 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(300));
    /* @4987448 constant */
    /* @4987452 constant */
    /* @4987456 constant */
    /* @4987460 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(400));
    /* @4987468 constant */
    /* @4987472 constant */
    /* @4987476 constant */
    /* @4987480 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(5), VAL(500));
    /* @4987488 load */
    /* @4987496 constant */
    /* @4987500 cmp */
    /* @4987504 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4987512;
    /* @4987508 b */
    goto L_4987580;
    L_4987512: ;
    /* @4987512 load */
    /* @4987520 constant */
    /* @4987524 cmp */
    /* @4987528 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4987580;
    /* @4987532 call */
    GM_SITE(vm, 654, 4987532);
    /* @4987540 popz */
    (void)(GM_CALL(vm, "audio_pause_all", 0));
    /* @4987544 constant */
    /* @4987548 cast */
    /* @4987552 constant */
    /* @4987556 cast */
    /* @4987560 constant */
    /* @4987564 cast */
    /* @4987568 call */
    GM_SITE(vm, 654, 4987568);
    /* @4987576 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(32), VAL(0), VAL(1)));
    L_4987580: ;
    return;
}
