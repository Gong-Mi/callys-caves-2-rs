/* generated from CODE 467 (gml_Object_obj_dodged_Draw_0), source start 4644504, end 4644616. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0467(GmVM* vm) {
    /* @4644504 constant */
    /* @4644508 cast */
    /* @4644512 call */
    GM_SITE(vm, 467, 4644512);
    /* @4644520 popz */
    (void)(GM_CALL(vm, "draw_set_alpha", 1, VAL(1)));
    /* @4644524 constant */
    /* @4644532 cast */
    /* @4644536 call */
    GM_SITE(vm, 467, 4644536);
    /* @4644544 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4644548 constant */
    /* @4644552 cast */
    /* @4644556 call */
    GM_SITE(vm, 467, 4644556);
    /* @4644564 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4644568 string */
    /* @4644576 cast */
    /* @4644580 load */
    /* @4644588 constant */
    /* @4644592 sub */
    /* @4644596 load */
    /* @4644604 call */
    GM_SITE(vm, 467, 4644604);
    /* @4644612 popz */
    (void)(GM_CALL(vm, "draw_text", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(20)), STR_REF(856)));
    L_4644616: ;
    return;
}
