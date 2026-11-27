/* generated from CODE 619 (gml_Object_obj_lloydtutorial10_Create_0), source start 4938208, end 4938444. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0619(GmVM* vm) {
    /* @4938208 constant */
    /* @4938212 cast */
    /* @4938216 call */
    GM_SITE(vm, 619, 4938216);
    /* @4938224 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(1)));
    /* @4938228 constant */
    /* @4938232 store */
    GM_WRITE(vm, -1, "taplock", VAL(0));
    /* @4938240 constant */
    /* @4938244 store */
    GM_WRITE(vm, -1, "drawpanel1", VAL(1));
    /* @4938252 constant */
    /* @4938256 store */
    GM_WRITE(vm, -1, "drawpanel2", VAL(0));
    /* @4938264 constant */
    /* @4938268 store */
    GM_WRITE(vm, -1, "drawpanel3", VAL(0));
    /* @4938276 constant */
    /* @4938280 store */
    GM_WRITE(vm, -1, "drawpanel4", VAL(0));
    /* @4938288 constant */
    /* @4938292 store */
    GM_WRITE(vm, -1, "drawpanel5", VAL(0));
    /* @4938300 constant */
    /* @4938304 store */
    GM_WRITE(vm, -1, "drawpanel6", VAL(0));
    /* @4938312 constant */
    /* @4938316 constant */
    /* @4938320 constant */
    /* @4938324 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(100));
    /* @4938332 constant */
    /* @4938336 constant */
    /* @4938340 constant */
    /* @4938344 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(5), VAL(200));
    /* @4938352 load */
    /* @4938360 constant */
    /* @4938364 cmp */
    /* @4938368 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4938376;
    /* @4938372 b */
    goto L_4938444;
    L_4938376: ;
    /* @4938376 load */
    /* @4938384 constant */
    /* @4938388 cmp */
    /* @4938392 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4938444;
    /* @4938396 call */
    GM_SITE(vm, 619, 4938396);
    /* @4938404 popz */
    (void)(GM_CALL(vm, "audio_pause_all", 0));
    /* @4938408 constant */
    /* @4938412 cast */
    /* @4938416 constant */
    /* @4938420 cast */
    /* @4938424 constant */
    /* @4938428 cast */
    /* @4938432 call */
    GM_SITE(vm, 619, 4938432);
    /* @4938440 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(32), VAL(0), VAL(1)));
    L_4938444: ;
    return;
}
