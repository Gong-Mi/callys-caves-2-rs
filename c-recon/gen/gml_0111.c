/* generated from CODE 111 (gml_Object_obj_shooter2_Draw_0), source start 3941392, end 3941584. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0111(GmVM* vm) {
    /* @3941392 load */
    /* @3941400 constant */
    /* @3941404 cmp */
    /* @3941408 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3941520;
    /* @3941412 constant */
    /* @3941416 cast */
    /* @3941420 constant */
    /* @3941424 cast */
    /* @3941428 constant */
    /* @3941436 cast */
    /* @3941440 constant */
    /* @3941444 cast */
    /* @3941448 call */
    GM_SITE(vm, 111, 3941448);
    /* @3941456 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(1), VAL(16777215), VAL(0), VAL(0)));
    /* @3941460 call */
    GM_SITE(vm, 111, 3941460);
    /* @3941468 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    /* @3941472 constant */
    /* @3941476 cast */
    /* @3941480 constant */
    /* @3941484 cast */
    /* @3941488 constant */
    /* @3941492 cast */
    /* @3941496 constant */
    /* @3941500 cast */
    /* @3941504 call */
    GM_SITE(vm, 111, 3941504);
    /* @3941512 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(0), VAL(0), VAL(0), VAL(0)));
    /* @3941516 b */
    goto L_3941552;
    L_3941520: ;
    /* @3941520 load */
    /* @3941528 constant */
    /* @3941532 cmp */
    /* @3941536 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(0)))) goto L_3941552;
    /* @3941540 call */
    GM_SITE(vm, 111, 3941540);
    /* @3941548 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    L_3941552: ;
    /* @3941552 load */
    /* @3941560 constant */
    /* @3941564 cmp */
    /* @3941568 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3941584;
    /* @3941572 constant */
    /* @3941576 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    L_3941584: ;
    return;
}
