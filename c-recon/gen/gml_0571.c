/* generated from CODE 571 (gml_Object_obj_lloydtutorial3_Create_0), source start 4870052, end 4870288. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0571(GmVM* vm) {
    /* @4870052 constant */
    /* @4870056 cast */
    /* @4870060 call */
    GM_SITE(vm, 571, 4870060);
    /* @4870068 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(1)));
    /* @4870072 constant */
    /* @4870076 store */
    GM_WRITE(vm, -1, "taplock", VAL(0));
    /* @4870084 constant */
    /* @4870088 store */
    GM_WRITE(vm, -1, "drawpanel1", VAL(1));
    /* @4870096 constant */
    /* @4870100 store */
    GM_WRITE(vm, -1, "drawpanel2", VAL(0));
    /* @4870108 constant */
    /* @4870112 store */
    GM_WRITE(vm, -1, "drawpanel3", VAL(0));
    /* @4870120 constant */
    /* @4870124 store */
    GM_WRITE(vm, -1, "drawpanel4", VAL(0));
    /* @4870132 constant */
    /* @4870136 store */
    GM_WRITE(vm, -1, "drawpanel5", VAL(0));
    /* @4870144 constant */
    /* @4870148 store */
    GM_WRITE(vm, -1, "drawpanel6", VAL(0));
    /* @4870156 constant */
    /* @4870160 constant */
    /* @4870164 constant */
    /* @4870168 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(100));
    /* @4870176 constant */
    /* @4870180 constant */
    /* @4870184 constant */
    /* @4870188 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(5), VAL(200));
    /* @4870196 load */
    /* @4870204 constant */
    /* @4870208 cmp */
    /* @4870212 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4870220;
    /* @4870216 b */
    goto L_4870288;
    L_4870220: ;
    /* @4870220 load */
    /* @4870228 constant */
    /* @4870232 cmp */
    /* @4870236 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4870288;
    /* @4870240 call */
    GM_SITE(vm, 571, 4870240);
    /* @4870248 popz */
    (void)(GM_CALL(vm, "audio_pause_all", 0));
    /* @4870252 constant */
    /* @4870256 cast */
    /* @4870260 constant */
    /* @4870264 cast */
    /* @4870268 constant */
    /* @4870272 cast */
    /* @4870276 call */
    GM_SITE(vm, 571, 4870276);
    /* @4870284 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(32), VAL(0), VAL(1)));
    L_4870288: ;
    return;
}
