/* generated from CODE 576 (gml_Object_obj_lloydtutorial4_Create_0), source start 4876956, end 4877252. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0576(GmVM* vm) {
    /* @4876956 constant */
    /* @4876960 cast */
    /* @4876964 call */
    GM_SITE(vm, 576, 4876964);
    /* @4876972 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(1)));
    /* @4876976 constant */
    /* @4876980 store */
    GM_WRITE(vm, -1, "taplock", VAL(0));
    /* @4876988 constant */
    /* @4876992 store */
    GM_WRITE(vm, -1, "drawpanel1", VAL(1));
    /* @4877000 constant */
    /* @4877004 store */
    GM_WRITE(vm, -1, "drawpanel2", VAL(0));
    /* @4877012 constant */
    /* @4877016 store */
    GM_WRITE(vm, -1, "drawpanel3", VAL(0));
    /* @4877024 constant */
    /* @4877028 store */
    GM_WRITE(vm, -1, "drawpanel4", VAL(0));
    /* @4877036 constant */
    /* @4877040 store */
    GM_WRITE(vm, -1, "drawpanel5", VAL(0));
    /* @4877048 constant */
    /* @4877052 store */
    GM_WRITE(vm, -1, "drawpanel6", VAL(0));
    /* @4877060 constant */
    /* @4877064 constant */
    /* @4877068 constant */
    /* @4877072 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(100));
    /* @4877080 constant */
    /* @4877084 constant */
    /* @4877088 constant */
    /* @4877092 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(200));
    /* @4877100 constant */
    /* @4877104 constant */
    /* @4877108 constant */
    /* @4877112 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(300));
    /* @4877120 constant */
    /* @4877124 constant */
    /* @4877128 constant */
    /* @4877132 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(400));
    /* @4877140 constant */
    /* @4877144 constant */
    /* @4877148 constant */
    /* @4877152 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(5), VAL(500));
    /* @4877160 load */
    /* @4877168 constant */
    /* @4877172 cmp */
    /* @4877176 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4877184;
    /* @4877180 b */
    goto L_4877252;
    L_4877184: ;
    /* @4877184 load */
    /* @4877192 constant */
    /* @4877196 cmp */
    /* @4877200 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4877252;
    /* @4877204 call */
    GM_SITE(vm, 576, 4877204);
    /* @4877212 popz */
    (void)(GM_CALL(vm, "audio_pause_all", 0));
    /* @4877216 constant */
    /* @4877220 cast */
    /* @4877224 constant */
    /* @4877228 cast */
    /* @4877232 constant */
    /* @4877236 cast */
    /* @4877240 call */
    GM_SITE(vm, 576, 4877240);
    /* @4877248 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(32), VAL(0), VAL(1)));
    L_4877252: ;
    return;
}
