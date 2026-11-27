/* generated from CODE 600 (gml_Object_obj_lloydtutorial7_Create_0), source start 4911084, end 4911340. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0600(GmVM* vm) {
    /* @4911084 constant */
    /* @4911088 cast */
    /* @4911092 call */
    GM_SITE(vm, 600, 4911092);
    /* @4911100 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(1)));
    /* @4911104 constant */
    /* @4911108 store */
    GM_WRITE(vm, -1, "taplock", VAL(0));
    /* @4911116 constant */
    /* @4911120 store */
    GM_WRITE(vm, -1, "drawpanel1", VAL(1));
    /* @4911128 constant */
    /* @4911132 store */
    GM_WRITE(vm, -1, "drawpanel2", VAL(0));
    /* @4911140 constant */
    /* @4911144 store */
    GM_WRITE(vm, -1, "drawpanel3", VAL(0));
    /* @4911152 constant */
    /* @4911156 store */
    GM_WRITE(vm, -1, "drawpanel4", VAL(0));
    /* @4911164 constant */
    /* @4911168 store */
    GM_WRITE(vm, -1, "drawpanel5", VAL(0));
    /* @4911176 constant */
    /* @4911180 store */
    GM_WRITE(vm, -1, "drawpanel6", VAL(0));
    /* @4911188 constant */
    /* @4911192 constant */
    /* @4911196 constant */
    /* @4911200 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(100));
    /* @4911208 constant */
    /* @4911212 constant */
    /* @4911216 constant */
    /* @4911220 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(200));
    /* @4911228 constant */
    /* @4911232 constant */
    /* @4911236 constant */
    /* @4911240 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(5), VAL(350));
    /* @4911248 load */
    /* @4911256 constant */
    /* @4911260 cmp */
    /* @4911264 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4911272;
    /* @4911268 b */
    goto L_4911340;
    L_4911272: ;
    /* @4911272 load */
    /* @4911280 constant */
    /* @4911284 cmp */
    /* @4911288 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4911340;
    /* @4911292 call */
    GM_SITE(vm, 600, 4911292);
    /* @4911300 popz */
    (void)(GM_CALL(vm, "audio_pause_all", 0));
    /* @4911304 constant */
    /* @4911308 cast */
    /* @4911312 constant */
    /* @4911316 cast */
    /* @4911320 constant */
    /* @4911324 cast */
    /* @4911328 call */
    GM_SITE(vm, 600, 4911328);
    /* @4911336 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(32), VAL(0), VAL(1)));
    L_4911340: ;
    return;
}
