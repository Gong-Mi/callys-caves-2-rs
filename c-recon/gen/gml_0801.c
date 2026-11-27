/* generated from CODE 801 (gml_Object_obj_bosspuff_Alarm_1), source start 5043024, end 5043148. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0801(GmVM* vm) {
    Val v1;
    /* @5043024 constant */
    /* @5043028 cast */
    /* @5043032 load */
    /* @5043040 load */
    /* @5043048 constant */
    /* @5043052 add */
    /* @5043056 call */
    GM_SITE(vm, 801, 5043056);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @5043064 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, GM_READ(vm, -1, "y"), VAL(188)));
    /* @5043068 load */
    /* @5043076 constant */
    /* @5043080 cmp */
    /* @5043084 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5043092;
    /* @5043088 b */
    goto L_5043148;
    L_5043092: ;
    /* @5043092 load */
    /* @5043100 constant */
    /* @5043104 cmp */
    /* @5043108 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5043148;
    /* @5043112 constant */
    /* @5043116 cast */
    /* @5043120 constant */
    /* @5043124 cast */
    /* @5043128 constant */
    /* @5043132 cast */
    /* @5043136 call */
    GM_SITE(vm, 801, 5043136);
    /* @5043144 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(8), VAL(0), VAL(0)));
    L_5043148: ;
    return;
}
