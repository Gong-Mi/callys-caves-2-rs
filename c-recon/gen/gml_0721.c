/* generated from CODE 721 (gml_Object_obj_bearcubintro_Create_0), source start 5032920, end 5033124. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0721(GmVM* vm) {
    Val v1;
    /* @5032920 load */
    /* @5032928 constant */
    /* @5032932 cmp */
    /* @5032936 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5032944;
    /* @5032940 b */
    goto L_5033000;
    L_5032944: ;
    /* @5032944 load */
    /* @5032952 constant */
    /* @5032956 cmp */
    /* @5032960 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5033000;
    /* @5032964 constant */
    /* @5032968 cast */
    /* @5032972 constant */
    /* @5032976 cast */
    /* @5032980 constant */
    /* @5032984 cast */
    /* @5032988 call */
    GM_SITE(vm, 721, 5032988);
    /* @5032996 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(4), VAL(0), VAL(0)));
    L_5033000: ;
    /* @5033000 constant */
    /* @5033004 constant */
    /* @5033008 constant */
    /* @5033012 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(60));
    /* @5033020 constant */
    /* @5033024 cast */
    /* @5033028 load */
    /* @5033036 constant */
    /* @5033040 sub */
    /* @5033044 load */
    /* @5033052 constant */
    /* @5033056 add */
    /* @5033060 call */
    GM_SITE(vm, 721, 5033060);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(320));
    /* @5033068 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(30)), VAL(164)));
    /* @5033072 constant */
    /* @5033076 cast */
    /* @5033080 load */
    /* @5033088 constant */
    /* @5033092 sub */
    /* @5033096 load */
    /* @5033104 constant */
    /* @5033108 sub */
    /* @5033112 call */
    GM_SITE(vm, 721, 5033112);
    /* @5033120 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(320)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(165)));
    L_5033124: ;
    return;
}
