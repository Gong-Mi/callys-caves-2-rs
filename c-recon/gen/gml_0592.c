/* generated from CODE 592 (gml_Object_obj_lloydtutorial6_Create_0), source start 4899668, end 4899964. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0592(GmVM* vm) {
    /* @4899668 constant */
    /* @4899672 cast */
    /* @4899676 call */
    GM_SITE(vm, 592, 4899676);
    /* @4899684 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(1)));
    /* @4899688 constant */
    /* @4899692 store */
    GM_WRITE(vm, -1, "taplock", VAL(0));
    /* @4899700 constant */
    /* @4899704 store */
    GM_WRITE(vm, -1, "drawpanel1", VAL(1));
    /* @4899712 constant */
    /* @4899716 store */
    GM_WRITE(vm, -1, "drawpanel2", VAL(0));
    /* @4899724 constant */
    /* @4899728 store */
    GM_WRITE(vm, -1, "drawpanel3", VAL(0));
    /* @4899736 constant */
    /* @4899740 store */
    GM_WRITE(vm, -1, "drawpanel4", VAL(0));
    /* @4899748 constant */
    /* @4899752 store */
    GM_WRITE(vm, -1, "drawpanel5", VAL(0));
    /* @4899760 constant */
    /* @4899764 store */
    GM_WRITE(vm, -1, "drawpanel6", VAL(0));
    /* @4899772 constant */
    /* @4899776 constant */
    /* @4899780 constant */
    /* @4899784 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(100));
    /* @4899792 constant */
    /* @4899796 constant */
    /* @4899800 constant */
    /* @4899804 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(200));
    /* @4899812 constant */
    /* @4899816 constant */
    /* @4899820 constant */
    /* @4899824 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(300));
    /* @4899832 constant */
    /* @4899836 constant */
    /* @4899840 constant */
    /* @4899844 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(400));
    /* @4899852 constant */
    /* @4899856 constant */
    /* @4899860 constant */
    /* @4899864 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(5), VAL(500));
    /* @4899872 load */
    /* @4899880 constant */
    /* @4899884 cmp */
    /* @4899888 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4899896;
    /* @4899892 b */
    goto L_4899964;
    L_4899896: ;
    /* @4899896 load */
    /* @4899904 constant */
    /* @4899908 cmp */
    /* @4899912 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4899964;
    /* @4899916 call */
    GM_SITE(vm, 592, 4899916);
    /* @4899924 popz */
    (void)(GM_CALL(vm, "audio_pause_all", 0));
    /* @4899928 constant */
    /* @4899932 cast */
    /* @4899936 constant */
    /* @4899940 cast */
    /* @4899944 constant */
    /* @4899948 cast */
    /* @4899952 call */
    GM_SITE(vm, 592, 4899952);
    /* @4899960 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(32), VAL(0), VAL(1)));
    L_4899964: ;
    return;
}
