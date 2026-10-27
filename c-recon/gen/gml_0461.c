/* generated from CODE 461 (gml_Object_obj_damage_Draw_0), source start 4642824, end 4642928. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0461(GmVM* vm) {
    /* @4642824 constant */
    /* @4642828 cast */
    /* @4642832 call */
    GM_SITE(vm, 461, 4642832);
    /* @4642840 popz */
    (void)(GM_CALL(vm, "draw_set_alpha", 1, VAL(1)));
    /* @4642844 constant */
    /* @4642848 cast */
    /* @4642852 call */
    GM_SITE(vm, 461, 4642852);
    /* @4642860 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(255)));
    /* @4642864 constant */
    /* @4642868 cast */
    /* @4642872 call */
    GM_SITE(vm, 461, 4642872);
    /* @4642880 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4642884 load */
    /* @4642892 load */
    /* @4642900 constant */
    /* @4642904 sub */
    /* @4642908 load */
    /* @4642916 call */
    GM_SITE(vm, 461, 4642916);
    /* @4642924 popz */
    (void)(GM_CALL(vm, "draw_text", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(20)), GM_READ(vm, -1, "damage")));
    L_4642928: ;
    return;
}
