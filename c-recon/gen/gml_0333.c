/* generated from CODE 333 (gml_Object_obj_fireprojectile_Create_0), source start 4194208, end 4194268. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0333(GmVM* vm) {
    Val v1;
    /* @4194208 load */
    /* @4194216 load */
    /* @4194224 load */
    /* @4194232 load */
    /* @4194240 call */
    GM_SITE(vm, 333, 4194240);
    /* @4194248 store */
    v1 = GM_CALL(vm, "point_direction", 4, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, 0, "x"), GM_READ(vm, 0, "y"));
    GM_WRITE(vm, -1, "direction", v1);
    /* @4194256 constant */
    /* @4194260 store */
    GM_WRITE(vm, -1, "speed", VAL(8));
    L_4194268: ;
    return;
}
