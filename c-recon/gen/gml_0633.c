/* generated from CODE 633 (gml_Object_obj_lloydtutorial12_Create_0), source start 4957504, end 4957820. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0633(GmVM* vm) {
    /* @4957504 constant */
    /* @4957508 cast */
    /* @4957512 call */
    GM_SITE(vm, 633, 4957512);
    /* @4957520 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(1)));
    /* @4957524 constant */
    /* @4957528 store */
    GM_WRITE(vm, -1, "taplock", VAL(0));
    /* @4957536 constant */
    /* @4957540 store */
    GM_WRITE(vm, -1, "drawpanel1", VAL(1));
    /* @4957548 constant */
    /* @4957552 store */
    GM_WRITE(vm, -1, "drawpanel2", VAL(0));
    /* @4957560 constant */
    /* @4957564 store */
    GM_WRITE(vm, -1, "drawpanel3", VAL(0));
    /* @4957572 constant */
    /* @4957576 store */
    GM_WRITE(vm, -1, "drawpanel4", VAL(0));
    /* @4957584 constant */
    /* @4957588 store */
    GM_WRITE(vm, -1, "drawpanel5", VAL(0));
    /* @4957596 constant */
    /* @4957600 store */
    GM_WRITE(vm, -1, "drawpanel6", VAL(0));
    /* @4957608 constant */
    /* @4957612 constant */
    /* @4957616 constant */
    /* @4957620 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(100));
    /* @4957628 constant */
    /* @4957632 constant */
    /* @4957636 constant */
    /* @4957640 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(200));
    /* @4957648 constant */
    /* @4957652 constant */
    /* @4957656 constant */
    /* @4957660 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(300));
    /* @4957668 constant */
    /* @4957672 constant */
    /* @4957676 constant */
    /* @4957680 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(400));
    /* @4957688 constant */
    /* @4957692 constant */
    /* @4957696 constant */
    /* @4957700 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(500));
    /* @4957708 constant */
    /* @4957712 constant */
    /* @4957716 constant */
    /* @4957720 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(5), VAL(600));
    /* @4957728 load */
    /* @4957736 constant */
    /* @4957740 cmp */
    /* @4957744 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4957752;
    /* @4957748 b */
    goto L_4957820;
    L_4957752: ;
    /* @4957752 load */
    /* @4957760 constant */
    /* @4957764 cmp */
    /* @4957768 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4957820;
    /* @4957772 call */
    GM_SITE(vm, 633, 4957772);
    /* @4957780 popz */
    (void)(GM_CALL(vm, "audio_pause_all", 0));
    /* @4957784 constant */
    /* @4957788 cast */
    /* @4957792 constant */
    /* @4957796 cast */
    /* @4957800 constant */
    /* @4957804 cast */
    /* @4957808 call */
    GM_SITE(vm, 633, 4957808);
    /* @4957816 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(32), VAL(0), VAL(1)));
    L_4957820: ;
    return;
}
