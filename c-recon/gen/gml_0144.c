/* generated from CODE 144 (gml_Object_obj_wolf_Draw_0), source start 3965340, end 3965532. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0144(GmVM* vm) {
    /* @3965340 load */
    /* @3965348 constant */
    /* @3965352 cmp */
    /* @3965356 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3965468;
    /* @3965360 constant */
    /* @3965364 cast */
    /* @3965368 constant */
    /* @3965372 cast */
    /* @3965376 constant */
    /* @3965384 cast */
    /* @3965388 constant */
    /* @3965392 cast */
    /* @3965396 call */
    GM_SITE(vm, 144, 3965396);
    /* @3965404 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(1), VAL(16777215), VAL(0), VAL(0)));
    /* @3965408 call */
    GM_SITE(vm, 144, 3965408);
    /* @3965416 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    /* @3965420 constant */
    /* @3965424 cast */
    /* @3965428 constant */
    /* @3965432 cast */
    /* @3965436 constant */
    /* @3965440 cast */
    /* @3965444 constant */
    /* @3965448 cast */
    /* @3965452 call */
    GM_SITE(vm, 144, 3965452);
    /* @3965460 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(0), VAL(0), VAL(0), VAL(0)));
    /* @3965464 b */
    goto L_3965500;
    L_3965468: ;
    /* @3965468 load */
    /* @3965476 constant */
    /* @3965480 cmp */
    /* @3965484 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(0)))) goto L_3965500;
    /* @3965488 call */
    GM_SITE(vm, 144, 3965488);
    /* @3965496 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    L_3965500: ;
    /* @3965500 load */
    /* @3965508 constant */
    /* @3965512 cmp */
    /* @3965516 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3965532;
    /* @3965520 constant */
    /* @3965524 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    L_3965532: ;
    return;
}
