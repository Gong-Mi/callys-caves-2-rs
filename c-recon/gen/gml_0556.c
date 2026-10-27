/* generated from CODE 556 (gml_Object_obj_lloydtutorial1_Create_0), source start 4847648, end 4847984. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0556(GmVM* vm) {
    /* @4847648 constant */
    /* @4847652 cast */
    /* @4847656 call */
    GM_SITE(vm, 556, 4847656);
    /* @4847664 popz */
    (void)(GM_CALL(vm, "mouse_clear", 1, VAL(-1)));
    /* @4847668 constant */
    /* @4847672 cast */
    /* @4847676 call */
    GM_SITE(vm, 556, 4847676);
    /* @4847684 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(1)));
    /* @4847688 constant */
    /* @4847692 store */
    GM_WRITE(vm, -1, "taplock", VAL(0));
    /* @4847700 constant */
    /* @4847704 store */
    GM_WRITE(vm, -1, "drawpanel1", VAL(1));
    /* @4847712 constant */
    /* @4847716 store */
    GM_WRITE(vm, -1, "drawpanel2", VAL(0));
    /* @4847724 constant */
    /* @4847728 store */
    GM_WRITE(vm, -1, "drawpanel3", VAL(0));
    /* @4847736 constant */
    /* @4847740 store */
    GM_WRITE(vm, -1, "drawpanel4", VAL(0));
    /* @4847748 constant */
    /* @4847752 store */
    GM_WRITE(vm, -1, "drawpanel5", VAL(0));
    /* @4847760 constant */
    /* @4847764 store */
    GM_WRITE(vm, -1, "drawpanel6", VAL(0));
    /* @4847772 constant */
    /* @4847776 constant */
    /* @4847780 constant */
    /* @4847784 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(100));
    /* @4847792 constant */
    /* @4847796 constant */
    /* @4847800 constant */
    /* @4847804 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(200));
    /* @4847812 constant */
    /* @4847816 constant */
    /* @4847820 constant */
    /* @4847824 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(300));
    /* @4847832 constant */
    /* @4847836 constant */
    /* @4847840 constant */
    /* @4847844 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(400));
    /* @4847852 constant */
    /* @4847856 constant */
    /* @4847860 constant */
    /* @4847864 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(500));
    /* @4847872 constant */
    /* @4847876 constant */
    /* @4847880 constant */
    /* @4847884 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(5), VAL(600));
    /* @4847892 load */
    /* @4847900 constant */
    /* @4847904 cmp */
    /* @4847908 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4847916;
    /* @4847912 b */
    goto L_4847984;
    L_4847916: ;
    /* @4847916 load */
    /* @4847924 constant */
    /* @4847928 cmp */
    /* @4847932 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4847984;
    /* @4847936 call */
    GM_SITE(vm, 556, 4847936);
    /* @4847944 popz */
    (void)(GM_CALL(vm, "audio_pause_all", 0));
    /* @4847948 constant */
    /* @4847952 cast */
    /* @4847956 constant */
    /* @4847960 cast */
    /* @4847964 constant */
    /* @4847968 cast */
    /* @4847972 call */
    GM_SITE(vm, 556, 4847972);
    /* @4847980 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(32), VAL(0), VAL(1)));
    L_4847984: ;
    return;
}
