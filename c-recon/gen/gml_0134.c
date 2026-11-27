/* generated from CODE 134 (gml_Object_obj_enemy2_Draw_0), source start 3957468, end 3957660. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0134(GmVM* vm) {
    /* @3957468 load */
    /* @3957476 constant */
    /* @3957480 cmp */
    /* @3957484 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3957596;
    /* @3957488 constant */
    /* @3957492 cast */
    /* @3957496 constant */
    /* @3957500 cast */
    /* @3957504 constant */
    /* @3957512 cast */
    /* @3957516 constant */
    /* @3957520 cast */
    /* @3957524 call */
    GM_SITE(vm, 134, 3957524);
    /* @3957532 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(1), VAL(16777215), VAL(0), VAL(0)));
    /* @3957536 call */
    GM_SITE(vm, 134, 3957536);
    /* @3957544 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    /* @3957548 constant */
    /* @3957552 cast */
    /* @3957556 constant */
    /* @3957560 cast */
    /* @3957564 constant */
    /* @3957568 cast */
    /* @3957572 constant */
    /* @3957576 cast */
    /* @3957580 call */
    GM_SITE(vm, 134, 3957580);
    /* @3957588 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(0), VAL(0), VAL(0), VAL(0)));
    /* @3957592 b */
    goto L_3957628;
    L_3957596: ;
    /* @3957596 load */
    /* @3957604 constant */
    /* @3957608 cmp */
    /* @3957612 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(0)))) goto L_3957628;
    /* @3957616 call */
    GM_SITE(vm, 134, 3957616);
    /* @3957624 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    L_3957628: ;
    /* @3957628 load */
    /* @3957636 constant */
    /* @3957640 cmp */
    /* @3957644 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3957660;
    /* @3957648 constant */
    /* @3957652 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    L_3957660: ;
    return;
}
