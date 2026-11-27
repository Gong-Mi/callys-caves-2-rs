/* generated from CODE 742 (gml_Object_obj_turretintro_Create_0), source start 5035020, end 5035224. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0742(GmVM* vm) {
    Val v1;
    /* @5035020 load */
    /* @5035028 constant */
    /* @5035032 cmp */
    /* @5035036 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5035044;
    /* @5035040 b */
    goto L_5035100;
    L_5035044: ;
    /* @5035044 load */
    /* @5035052 constant */
    /* @5035056 cmp */
    /* @5035060 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5035100;
    /* @5035064 constant */
    /* @5035068 cast */
    /* @5035072 constant */
    /* @5035076 cast */
    /* @5035080 constant */
    /* @5035084 cast */
    /* @5035088 call */
    GM_SITE(vm, 742, 5035088);
    /* @5035096 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(4), VAL(0), VAL(0)));
    L_5035100: ;
    /* @5035100 constant */
    /* @5035104 constant */
    /* @5035108 constant */
    /* @5035112 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(60));
    /* @5035120 constant */
    /* @5035124 cast */
    /* @5035128 load */
    /* @5035136 constant */
    /* @5035140 sub */
    /* @5035144 load */
    /* @5035152 constant */
    /* @5035156 add */
    /* @5035160 call */
    GM_SITE(vm, 742, 5035160);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(320));
    /* @5035168 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(30)), VAL(164)));
    /* @5035172 constant */
    /* @5035176 cast */
    /* @5035180 load */
    /* @5035188 constant */
    /* @5035192 sub */
    /* @5035196 load */
    /* @5035204 constant */
    /* @5035208 sub */
    /* @5035212 call */
    GM_SITE(vm, 742, 5035212);
    /* @5035220 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(320)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(165)));
    L_5035224: ;
    return;
}
