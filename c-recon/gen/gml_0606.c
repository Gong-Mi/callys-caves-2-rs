/* generated from CODE 606 (gml_Object_obj_lloydtutorial8_Create_0), source start 4920044, end 4920340. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0606(GmVM* vm) {
    /* @4920044 constant */
    /* @4920048 cast */
    /* @4920052 call */
    GM_SITE(vm, 606, 4920052);
    /* @4920060 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(1)));
    /* @4920064 constant */
    /* @4920068 store */
    GM_WRITE(vm, -1, "taplock", VAL(0));
    /* @4920076 constant */
    /* @4920080 store */
    GM_WRITE(vm, -1, "drawpanel1", VAL(1));
    /* @4920088 constant */
    /* @4920092 store */
    GM_WRITE(vm, -1, "drawpanel2", VAL(0));
    /* @4920100 constant */
    /* @4920104 store */
    GM_WRITE(vm, -1, "drawpanel3", VAL(0));
    /* @4920112 constant */
    /* @4920116 store */
    GM_WRITE(vm, -1, "drawpanel4", VAL(0));
    /* @4920124 constant */
    /* @4920128 store */
    GM_WRITE(vm, -1, "drawpanel5", VAL(0));
    /* @4920136 constant */
    /* @4920140 store */
    GM_WRITE(vm, -1, "drawpanel6", VAL(0));
    /* @4920148 constant */
    /* @4920152 constant */
    /* @4920156 constant */
    /* @4920160 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(100));
    /* @4920168 constant */
    /* @4920172 constant */
    /* @4920176 constant */
    /* @4920180 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(200));
    /* @4920188 constant */
    /* @4920192 constant */
    /* @4920196 constant */
    /* @4920200 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(300));
    /* @4920208 constant */
    /* @4920212 constant */
    /* @4920216 constant */
    /* @4920220 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(400));
    /* @4920228 constant */
    /* @4920232 constant */
    /* @4920236 constant */
    /* @4920240 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(5), VAL(500));
    /* @4920248 load */
    /* @4920256 constant */
    /* @4920260 cmp */
    /* @4920264 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4920272;
    /* @4920268 b */
    goto L_4920340;
    L_4920272: ;
    /* @4920272 load */
    /* @4920280 constant */
    /* @4920284 cmp */
    /* @4920288 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4920340;
    /* @4920292 call */
    GM_SITE(vm, 606, 4920292);
    /* @4920300 popz */
    (void)(GM_CALL(vm, "audio_pause_all", 0));
    /* @4920304 constant */
    /* @4920308 cast */
    /* @4920312 constant */
    /* @4920316 cast */
    /* @4920320 constant */
    /* @4920324 cast */
    /* @4920328 call */
    GM_SITE(vm, 606, 4920328);
    /* @4920336 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(32), VAL(0), VAL(1)));
    L_4920340: ;
    return;
}
