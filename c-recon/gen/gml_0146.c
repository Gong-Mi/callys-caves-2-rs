/* generated from CODE 146 (gml_Object_obj_ghost_Destroy_0), source start 3966332, end 3966416. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0146(GmVM* vm) {
    GM_WRITE(vm, -5, "ghostskilled", GM_ADD(GM_READ(vm, -5, "ghostskilled"), VAL(1)));
    GM_WRITE(vm, -5, "enemieskilled", GM_ADD(GM_READ(vm, -5, "enemieskilled"), VAL(1)));
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(187)));
    L_3966416: ;
    return;
}
