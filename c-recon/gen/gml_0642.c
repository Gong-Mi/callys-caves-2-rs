/* generated from CODE 642 (gml_Object_obj_lloydtutorial13_Create_0), source start 4970424, end 4970720. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0642(GmVM* vm) {
    /* @4970424 constant */
    /* @4970428 cast */
    /* @4970432 call */
    GM_SITE(vm, 642, 4970432);
    /* @4970440 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(1)));
    /* @4970444 constant */
    /* @4970448 store */
    GM_WRITE(vm, -1, "taplock", VAL(0));
    /* @4970456 constant */
    /* @4970460 store */
    GM_WRITE(vm, -1, "drawpanel1", VAL(1));
    /* @4970468 constant */
    /* @4970472 store */
    GM_WRITE(vm, -1, "drawpanel2", VAL(0));
    /* @4970480 constant */
    /* @4970484 store */
    GM_WRITE(vm, -1, "drawpanel3", VAL(0));
    /* @4970492 constant */
    /* @4970496 store */
    GM_WRITE(vm, -1, "drawpanel4", VAL(0));
    /* @4970504 constant */
    /* @4970508 store */
    GM_WRITE(vm, -1, "drawpanel5", VAL(0));
    /* @4970516 constant */
    /* @4970520 store */
    GM_WRITE(vm, -1, "drawpanel6", VAL(0));
    /* @4970528 constant */
    /* @4970532 constant */
    /* @4970536 constant */
    /* @4970540 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(100));
    /* @4970548 constant */
    /* @4970552 constant */
    /* @4970556 constant */
    /* @4970560 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(200));
    /* @4970568 constant */
    /* @4970572 constant */
    /* @4970576 constant */
    /* @4970580 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(300));
    /* @4970588 constant */
    /* @4970592 constant */
    /* @4970596 constant */
    /* @4970600 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(400));
    /* @4970608 constant */
    /* @4970612 constant */
    /* @4970616 constant */
    /* @4970620 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(5), VAL(500));
    /* @4970628 load */
    /* @4970636 constant */
    /* @4970640 cmp */
    /* @4970644 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4970652;
    /* @4970648 b */
    goto L_4970720;
    L_4970652: ;
    /* @4970652 load */
    /* @4970660 constant */
    /* @4970664 cmp */
    /* @4970668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4970720;
    /* @4970672 call */
    GM_SITE(vm, 642, 4970672);
    /* @4970680 popz */
    (void)(GM_CALL(vm, "audio_pause_all", 0));
    /* @4970684 constant */
    /* @4970688 cast */
    /* @4970692 constant */
    /* @4970696 cast */
    /* @4970700 constant */
    /* @4970704 cast */
    /* @4970708 call */
    GM_SITE(vm, 642, 4970708);
    /* @4970716 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(32), VAL(0), VAL(1)));
    L_4970720: ;
    return;
}
