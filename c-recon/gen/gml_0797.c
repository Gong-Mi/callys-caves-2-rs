/* generated from CODE 797 (gml_Object_obj_bosspuff_Alarm_5), source start 5042528, end 5042652. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0797(GmVM* vm) {
    Val v1;
    /* @5042528 constant */
    /* @5042532 cast */
    /* @5042536 load */
    /* @5042544 load */
    /* @5042552 constant */
    /* @5042556 add */
    /* @5042560 call */
    GM_SITE(vm, 797, 5042560);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @5042568 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, GM_READ(vm, -1, "y"), VAL(188)));
    /* @5042572 load */
    /* @5042580 constant */
    /* @5042584 cmp */
    /* @5042588 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5042596;
    /* @5042592 b */
    goto L_5042652;
    L_5042596: ;
    /* @5042596 load */
    /* @5042604 constant */
    /* @5042608 cmp */
    /* @5042612 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5042652;
    /* @5042616 constant */
    /* @5042620 cast */
    /* @5042624 constant */
    /* @5042628 cast */
    /* @5042632 constant */
    /* @5042636 cast */
    /* @5042640 call */
    GM_SITE(vm, 797, 5042640);
    /* @5042648 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(8), VAL(0), VAL(0)));
    L_5042652: ;
    return;
}
