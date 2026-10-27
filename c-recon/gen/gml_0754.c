/* generated from CODE 754 (gml_Object_obj_redslimeintro_Create_0), source start 5036220, end 5036424. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0754(GmVM* vm) {
    Val v1;
    /* @5036220 load */
    /* @5036228 constant */
    /* @5036232 cmp */
    /* @5036236 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5036244;
    /* @5036240 b */
    goto L_5036300;
    L_5036244: ;
    /* @5036244 load */
    /* @5036252 constant */
    /* @5036256 cmp */
    /* @5036260 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5036300;
    /* @5036264 constant */
    /* @5036268 cast */
    /* @5036272 constant */
    /* @5036276 cast */
    /* @5036280 constant */
    /* @5036284 cast */
    /* @5036288 call */
    GM_SITE(vm, 754, 5036288);
    /* @5036296 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(4), VAL(0), VAL(0)));
    L_5036300: ;
    /* @5036300 constant */
    /* @5036304 constant */
    /* @5036308 constant */
    /* @5036312 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(60));
    /* @5036320 constant */
    /* @5036324 cast */
    /* @5036328 load */
    /* @5036336 constant */
    /* @5036340 sub */
    /* @5036344 load */
    /* @5036352 constant */
    /* @5036356 add */
    /* @5036360 call */
    GM_SITE(vm, 754, 5036360);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(320));
    /* @5036368 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(30)), VAL(164)));
    /* @5036372 constant */
    /* @5036376 cast */
    /* @5036380 load */
    /* @5036388 constant */
    /* @5036392 sub */
    /* @5036396 load */
    /* @5036404 constant */
    /* @5036408 sub */
    /* @5036412 call */
    GM_SITE(vm, 754, 5036412);
    /* @5036420 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(320)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(165)));
    L_5036424: ;
    return;
}
