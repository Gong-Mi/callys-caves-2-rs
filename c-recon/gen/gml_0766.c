/* generated from CODE 766 (gml_Object_obj_boss3intro_Create_0), source start 5037420, end 5037624. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0766(GmVM* vm) {
    Val v1;
    /* @5037420 load */
    /* @5037428 constant */
    /* @5037432 cmp */
    /* @5037436 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5037444;
    /* @5037440 b */
    goto L_5037500;
    L_5037444: ;
    /* @5037444 load */
    /* @5037452 constant */
    /* @5037456 cmp */
    /* @5037460 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5037500;
    /* @5037464 constant */
    /* @5037468 cast */
    /* @5037472 constant */
    /* @5037476 cast */
    /* @5037480 constant */
    /* @5037484 cast */
    /* @5037488 call */
    GM_SITE(vm, 766, 5037488);
    /* @5037496 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(4), VAL(0), VAL(0)));
    L_5037500: ;
    /* @5037500 constant */
    /* @5037504 constant */
    /* @5037508 constant */
    /* @5037512 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(60));
    /* @5037520 constant */
    /* @5037524 cast */
    /* @5037528 load */
    /* @5037536 constant */
    /* @5037540 sub */
    /* @5037544 load */
    /* @5037552 constant */
    /* @5037556 add */
    /* @5037560 call */
    GM_SITE(vm, 766, 5037560);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(320));
    /* @5037568 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(30)), VAL(164)));
    /* @5037572 constant */
    /* @5037576 cast */
    /* @5037580 load */
    /* @5037588 constant */
    /* @5037592 sub */
    /* @5037596 load */
    /* @5037604 constant */
    /* @5037608 sub */
    /* @5037612 call */
    GM_SITE(vm, 766, 5037612);
    /* @5037620 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(320)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(165)));
    L_5037624: ;
    return;
}
