/* generated from CODE 565 (gml_Object_obj_lloydtutorial2_Create_0), source start 4861644, end 4861900. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0565(GmVM* vm) {
    /* @4861644 constant */
    /* @4861648 cast */
    /* @4861652 call */
    GM_SITE(vm, 565, 4861652);
    /* @4861660 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(1)));
    /* @4861664 constant */
    /* @4861668 store */
    GM_WRITE(vm, -1, "taplock", VAL(0));
    /* @4861676 constant */
    /* @4861680 store */
    GM_WRITE(vm, -1, "drawpanel1", VAL(1));
    /* @4861688 constant */
    /* @4861692 store */
    GM_WRITE(vm, -1, "drawpanel2", VAL(0));
    /* @4861700 constant */
    /* @4861704 store */
    GM_WRITE(vm, -1, "drawpanel3", VAL(0));
    /* @4861712 constant */
    /* @4861716 store */
    GM_WRITE(vm, -1, "drawpanel4", VAL(0));
    /* @4861724 constant */
    /* @4861728 store */
    GM_WRITE(vm, -1, "drawpanel5", VAL(0));
    /* @4861736 constant */
    /* @4861740 store */
    GM_WRITE(vm, -1, "drawpanel6", VAL(0));
    /* @4861748 constant */
    /* @4861752 constant */
    /* @4861756 constant */
    /* @4861760 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(100));
    /* @4861768 constant */
    /* @4861772 constant */
    /* @4861776 constant */
    /* @4861780 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(200));
    /* @4861788 constant */
    /* @4861792 constant */
    /* @4861796 constant */
    /* @4861800 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(5), VAL(300));
    /* @4861808 load */
    /* @4861816 constant */
    /* @4861820 cmp */
    /* @4861824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4861832;
    /* @4861828 b */
    goto L_4861900;
    L_4861832: ;
    /* @4861832 load */
    /* @4861840 constant */
    /* @4861844 cmp */
    /* @4861848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4861900;
    /* @4861852 call */
    GM_SITE(vm, 565, 4861852);
    /* @4861860 popz */
    (void)(GM_CALL(vm, "audio_pause_all", 0));
    /* @4861864 constant */
    /* @4861868 cast */
    /* @4861872 constant */
    /* @4861876 cast */
    /* @4861880 constant */
    /* @4861884 cast */
    /* @4861888 call */
    GM_SITE(vm, 565, 4861888);
    /* @4861896 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(32), VAL(0), VAL(1)));
    L_4861900: ;
    return;
}
