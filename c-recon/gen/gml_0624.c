/* generated from CODE 624 (gml_Object_obj_lloydtutorial11_Create_0), source start 4945112, end 4945428. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0624(GmVM* vm) {
    /* @4945112 constant */
    /* @4945116 cast */
    /* @4945120 call */
    GM_SITE(vm, 624, 4945120);
    /* @4945128 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(1)));
    /* @4945132 constant */
    /* @4945136 store */
    GM_WRITE(vm, -1, "taplock", VAL(0));
    /* @4945144 constant */
    /* @4945148 store */
    GM_WRITE(vm, -1, "drawpanel1", VAL(1));
    /* @4945156 constant */
    /* @4945160 store */
    GM_WRITE(vm, -1, "drawpanel2", VAL(0));
    /* @4945168 constant */
    /* @4945172 store */
    GM_WRITE(vm, -1, "drawpanel3", VAL(0));
    /* @4945180 constant */
    /* @4945184 store */
    GM_WRITE(vm, -1, "drawpanel4", VAL(0));
    /* @4945192 constant */
    /* @4945196 store */
    GM_WRITE(vm, -1, "drawpanel5", VAL(0));
    /* @4945204 constant */
    /* @4945208 store */
    GM_WRITE(vm, -1, "drawpanel6", VAL(0));
    /* @4945216 constant */
    /* @4945220 constant */
    /* @4945224 constant */
    /* @4945228 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(100));
    /* @4945236 constant */
    /* @4945240 constant */
    /* @4945244 constant */
    /* @4945248 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(200));
    /* @4945256 constant */
    /* @4945260 constant */
    /* @4945264 constant */
    /* @4945268 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(300));
    /* @4945276 constant */
    /* @4945280 constant */
    /* @4945284 constant */
    /* @4945288 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(400));
    /* @4945296 constant */
    /* @4945300 constant */
    /* @4945304 constant */
    /* @4945308 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(500));
    /* @4945316 constant */
    /* @4945320 constant */
    /* @4945324 constant */
    /* @4945328 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(5), VAL(600));
    /* @4945336 load */
    /* @4945344 constant */
    /* @4945348 cmp */
    /* @4945352 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4945360;
    /* @4945356 b */
    goto L_4945428;
    L_4945360: ;
    /* @4945360 load */
    /* @4945368 constant */
    /* @4945372 cmp */
    /* @4945376 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4945428;
    /* @4945380 call */
    GM_SITE(vm, 624, 4945380);
    /* @4945388 popz */
    (void)(GM_CALL(vm, "audio_pause_all", 0));
    /* @4945392 constant */
    /* @4945396 cast */
    /* @4945400 constant */
    /* @4945404 cast */
    /* @4945408 constant */
    /* @4945412 cast */
    /* @4945416 call */
    GM_SITE(vm, 624, 4945416);
    /* @4945424 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(32), VAL(0), VAL(1)));
    L_4945428: ;
    return;
}
