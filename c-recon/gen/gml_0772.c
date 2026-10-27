/* generated from CODE 772 (gml_Object_obj_boss4intro_Create_0), source start 5038020, end 5038224. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0772(GmVM* vm) {
    Val v1;
    /* @5038020 load */
    /* @5038028 constant */
    /* @5038032 cmp */
    /* @5038036 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5038044;
    /* @5038040 b */
    goto L_5038100;
    L_5038044: ;
    /* @5038044 load */
    /* @5038052 constant */
    /* @5038056 cmp */
    /* @5038060 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5038100;
    /* @5038064 constant */
    /* @5038068 cast */
    /* @5038072 constant */
    /* @5038076 cast */
    /* @5038080 constant */
    /* @5038084 cast */
    /* @5038088 call */
    GM_SITE(vm, 772, 5038088);
    /* @5038096 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(4), VAL(0), VAL(0)));
    L_5038100: ;
    /* @5038100 constant */
    /* @5038104 constant */
    /* @5038108 constant */
    /* @5038112 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(60));
    /* @5038120 constant */
    /* @5038124 cast */
    /* @5038128 load */
    /* @5038136 constant */
    /* @5038140 sub */
    /* @5038144 load */
    /* @5038152 constant */
    /* @5038156 add */
    /* @5038160 call */
    GM_SITE(vm, 772, 5038160);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(320));
    /* @5038168 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(30)), VAL(164)));
    /* @5038172 constant */
    /* @5038176 cast */
    /* @5038180 load */
    /* @5038188 constant */
    /* @5038192 sub */
    /* @5038196 load */
    /* @5038204 constant */
    /* @5038208 sub */
    /* @5038212 call */
    GM_SITE(vm, 772, 5038212);
    /* @5038220 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(320)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(165)));
    L_5038224: ;
    return;
}
