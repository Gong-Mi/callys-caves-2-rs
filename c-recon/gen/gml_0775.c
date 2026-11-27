/* generated from CODE 775 (gml_Object_obj_boss5intro_Create_0), source start 5038320, end 5038524. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0775(GmVM* vm) {
    Val v1;
    /* @5038320 load */
    /* @5038328 constant */
    /* @5038332 cmp */
    /* @5038336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5038344;
    /* @5038340 b */
    goto L_5038400;
    L_5038344: ;
    /* @5038344 load */
    /* @5038352 constant */
    /* @5038356 cmp */
    /* @5038360 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5038400;
    /* @5038364 constant */
    /* @5038368 cast */
    /* @5038372 constant */
    /* @5038376 cast */
    /* @5038380 constant */
    /* @5038384 cast */
    /* @5038388 call */
    GM_SITE(vm, 775, 5038388);
    /* @5038396 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(4), VAL(0), VAL(0)));
    L_5038400: ;
    /* @5038400 constant */
    /* @5038404 constant */
    /* @5038408 constant */
    /* @5038412 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(60));
    /* @5038420 constant */
    /* @5038424 cast */
    /* @5038428 load */
    /* @5038436 constant */
    /* @5038440 sub */
    /* @5038444 load */
    /* @5038452 constant */
    /* @5038456 add */
    /* @5038460 call */
    GM_SITE(vm, 775, 5038460);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(320));
    /* @5038468 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(30)), VAL(164)));
    /* @5038472 constant */
    /* @5038476 cast */
    /* @5038480 load */
    /* @5038488 constant */
    /* @5038492 sub */
    /* @5038496 load */
    /* @5038504 constant */
    /* @5038508 sub */
    /* @5038512 call */
    GM_SITE(vm, 775, 5038512);
    /* @5038520 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(320)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(165)));
    L_5038524: ;
    return;
}
