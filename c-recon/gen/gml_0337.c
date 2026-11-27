/* generated from CODE 337 (gml_Object_obj_bone_Create_0), source start 4196048, end 4196108. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0337(GmVM* vm) {
    Val v1;
    /* @4196048 load */
    /* @4196056 load */
    /* @4196064 load */
    /* @4196072 load */
    /* @4196080 call */
    GM_SITE(vm, 337, 4196080);
    /* @4196088 store */
    v1 = GM_CALL(vm, "point_direction", 4, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, 0, "x"), GM_READ(vm, 0, "y"));
    GM_WRITE(vm, -1, "direction", v1);
    /* @4196096 constant */
    /* @4196100 store */
    GM_WRITE(vm, -1, "speed", VAL(6));
    L_4196108: ;
    return;
}
