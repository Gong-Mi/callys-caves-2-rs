/* generated from CODE 693 (gml_Object_obj_maptile_Draw_0), source start 5018084, end 5018208. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0693(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    GM_SITE(vm, 693, 5018084);
    (void)(GM_CALL(vm, "draw_self", 0));
    GM_SITE(vm, 693, 5018104);
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    GM_SITE(vm, 693, 5018128);
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    GM_SITE(vm, 693, 5018148);
    GM_SITE(vm, 693, 5018156);
    v1 = GM_CALL(vm, "string", 1, GM_READ(vm, -2, "goto"));
    GM_SITE(vm, 693, 5018196);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(8));
    v4 = GM_CALL(vm, "string_digits", 1, v1);
    (void)(GM_CALL(vm, "draw_text", 3, v2, v3, v4));
    L_5018208: ;
    return;
}
