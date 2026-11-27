/* generated from CODE 736 (gml_Object_obj_pistolbanditintro_Create_0), source start 5034420, end 5034624. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0736(GmVM* vm) {
    Val v1;
    /* @5034420 load */
    /* @5034428 constant */
    /* @5034432 cmp */
    /* @5034436 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5034444;
    /* @5034440 b */
    goto L_5034500;
    L_5034444: ;
    /* @5034444 load */
    /* @5034452 constant */
    /* @5034456 cmp */
    /* @5034460 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5034500;
    /* @5034464 constant */
    /* @5034468 cast */
    /* @5034472 constant */
    /* @5034476 cast */
    /* @5034480 constant */
    /* @5034484 cast */
    /* @5034488 call */
    GM_SITE(vm, 736, 5034488);
    /* @5034496 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(4), VAL(0), VAL(0)));
    L_5034500: ;
    /* @5034500 constant */
    /* @5034504 constant */
    /* @5034508 constant */
    /* @5034512 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(60));
    /* @5034520 constant */
    /* @5034524 cast */
    /* @5034528 load */
    /* @5034536 constant */
    /* @5034540 sub */
    /* @5034544 load */
    /* @5034552 constant */
    /* @5034556 add */
    /* @5034560 call */
    GM_SITE(vm, 736, 5034560);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(320));
    /* @5034568 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(30)), VAL(164)));
    /* @5034572 constant */
    /* @5034576 cast */
    /* @5034580 load */
    /* @5034588 constant */
    /* @5034592 sub */
    /* @5034596 load */
    /* @5034604 constant */
    /* @5034608 sub */
    /* @5034612 call */
    GM_SITE(vm, 736, 5034612);
    /* @5034620 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(320)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(165)));
    L_5034624: ;
    return;
}
