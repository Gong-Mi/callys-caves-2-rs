/* generated from CODE 662 (gml_Object_obj_lloydtutorial16_Create_0), source start 5001868, end 5002164. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0662(GmVM* vm) {
    /* @5001868 constant */
    /* @5001872 cast */
    /* @5001876 call */
    GM_SITE(vm, 662, 5001876);
    /* @5001884 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(1)));
    /* @5001888 constant */
    /* @5001892 store */
    GM_WRITE(vm, -1, "taplock", VAL(0));
    /* @5001900 constant */
    /* @5001904 store */
    GM_WRITE(vm, -1, "drawpanel1", VAL(1));
    /* @5001912 constant */
    /* @5001916 store */
    GM_WRITE(vm, -1, "drawpanel2", VAL(0));
    /* @5001924 constant */
    /* @5001928 store */
    GM_WRITE(vm, -1, "drawpanel3", VAL(0));
    /* @5001936 constant */
    /* @5001940 store */
    GM_WRITE(vm, -1, "drawpanel4", VAL(0));
    /* @5001948 constant */
    /* @5001952 store */
    GM_WRITE(vm, -1, "drawpanel5", VAL(0));
    /* @5001960 constant */
    /* @5001964 store */
    GM_WRITE(vm, -1, "drawpanel6", VAL(0));
    /* @5001972 constant */
    /* @5001976 constant */
    /* @5001980 constant */
    /* @5001984 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(100));
    /* @5001992 constant */
    /* @5001996 constant */
    /* @5002000 constant */
    /* @5002004 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(200));
    /* @5002012 constant */
    /* @5002016 constant */
    /* @5002020 constant */
    /* @5002024 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(300));
    /* @5002032 constant */
    /* @5002036 constant */
    /* @5002040 constant */
    /* @5002044 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(400));
    /* @5002052 constant */
    /* @5002056 constant */
    /* @5002060 constant */
    /* @5002064 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(5), VAL(500));
    /* @5002072 load */
    /* @5002080 constant */
    /* @5002084 cmp */
    /* @5002088 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_5002096;
    /* @5002092 b */
    goto L_5002164;
    L_5002096: ;
    /* @5002096 load */
    /* @5002104 constant */
    /* @5002108 cmp */
    /* @5002112 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_5002164;
    /* @5002116 call */
    GM_SITE(vm, 662, 5002116);
    /* @5002124 popz */
    (void)(GM_CALL(vm, "audio_pause_all", 0));
    /* @5002128 constant */
    /* @5002132 cast */
    /* @5002136 constant */
    /* @5002140 cast */
    /* @5002144 constant */
    /* @5002148 cast */
    /* @5002152 call */
    GM_SITE(vm, 662, 5002152);
    /* @5002160 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(32), VAL(0), VAL(1)));
    L_5002164: ;
    return;
}
