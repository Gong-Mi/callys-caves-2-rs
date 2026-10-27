/* generated from CODE 198 (gml_Object_obj_boss4_Draw_0), source start 4016500, end 4016692. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0198(GmVM* vm) {
    /* @4016500 load */
    /* @4016508 constant */
    /* @4016512 cmp */
    /* @4016516 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_4016628;
    /* @4016520 constant */
    /* @4016524 cast */
    /* @4016528 constant */
    /* @4016532 cast */
    /* @4016536 constant */
    /* @4016544 cast */
    /* @4016548 constant */
    /* @4016552 cast */
    /* @4016556 call */
    GM_SITE(vm, 198, 4016556);
    /* @4016564 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(1), VAL(16777215), VAL(0), VAL(0)));
    /* @4016568 call */
    GM_SITE(vm, 198, 4016568);
    /* @4016576 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    /* @4016580 constant */
    /* @4016584 cast */
    /* @4016588 constant */
    /* @4016592 cast */
    /* @4016596 constant */
    /* @4016600 cast */
    /* @4016604 constant */
    /* @4016608 cast */
    /* @4016612 call */
    GM_SITE(vm, 198, 4016612);
    /* @4016620 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(0), VAL(0), VAL(0), VAL(0)));
    /* @4016624 b */
    goto L_4016660;
    L_4016628: ;
    /* @4016628 load */
    /* @4016636 constant */
    /* @4016640 cmp */
    /* @4016644 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(0)))) goto L_4016660;
    /* @4016648 call */
    GM_SITE(vm, 198, 4016648);
    /* @4016656 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    L_4016660: ;
    /* @4016660 load */
    /* @4016668 constant */
    /* @4016672 cmp */
    /* @4016676 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_4016692;
    /* @4016680 constant */
    /* @4016684 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    L_4016692: ;
    return;
}
