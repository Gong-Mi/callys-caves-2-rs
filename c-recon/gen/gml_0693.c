/* generated from CODE 693 (gml_Object_obj_maptile_Draw_0), source start 5018084, end 5018208. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0693(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    /* @5018084 call */
    GM_SITE(vm, 693, 5018084);
    /* @5018092 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    /* @5018096 constant */
    /* @5018100 cast */
    /* @5018104 call */
    GM_SITE(vm, 693, 5018104);
    /* @5018112 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5018116 constant */
    /* @5018124 cast */
    /* @5018128 call */
    GM_SITE(vm, 693, 5018128);
    /* @5018136 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5018140 load */
    /* @5018148 call */
    GM_SITE(vm, 693, 5018148);
    /* @5018156 call */
    GM_SITE(vm, 693, 5018156);
    v1 = GM_CALL(vm, "string", 1, GM_READ(vm, -2, "goto"));
    /* @5018164 load */
    /* @5018172 constant */
    /* @5018176 add */
    /* @5018180 load */
    /* @5018188 constant */
    /* @5018192 add */
    /* @5018196 call */
    GM_SITE(vm, 693, 5018196);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(8));
    v4 = GM_CALL(vm, "string_digits", 1, v1);
    /* @5018204 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v2, v3, v4));
    L_5018208: ;
    return;
}
