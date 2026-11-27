/* generated from CODE 745 (gml_Object_obj_slimeintro_Create_0), source start 5035320, end 5035524. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0745(GmVM* vm) {
    Val v1;
    /* @5035320 load */
    /* @5035328 constant */
    /* @5035332 cmp */
    /* @5035336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5035344;
    /* @5035340 b */
    goto L_5035400;
    L_5035344: ;
    /* @5035344 load */
    /* @5035352 constant */
    /* @5035356 cmp */
    /* @5035360 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5035400;
    /* @5035364 constant */
    /* @5035368 cast */
    /* @5035372 constant */
    /* @5035376 cast */
    /* @5035380 constant */
    /* @5035384 cast */
    /* @5035388 call */
    GM_SITE(vm, 745, 5035388);
    /* @5035396 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(4), VAL(0), VAL(0)));
    L_5035400: ;
    /* @5035400 constant */
    /* @5035404 constant */
    /* @5035408 constant */
    /* @5035412 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(60));
    /* @5035420 constant */
    /* @5035424 cast */
    /* @5035428 load */
    /* @5035436 constant */
    /* @5035440 sub */
    /* @5035444 load */
    /* @5035452 constant */
    /* @5035456 add */
    /* @5035460 call */
    GM_SITE(vm, 745, 5035460);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(320));
    /* @5035468 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(30)), VAL(164)));
    /* @5035472 constant */
    /* @5035476 cast */
    /* @5035480 load */
    /* @5035488 constant */
    /* @5035492 sub */
    /* @5035496 load */
    /* @5035504 constant */
    /* @5035508 sub */
    /* @5035512 call */
    GM_SITE(vm, 745, 5035512);
    /* @5035520 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(320)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(165)));
    L_5035524: ;
    return;
}
