/* generated from CODE 146 (gml_Object_obj_ghost_Destroy_0), source start 3966332, end 3966416. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0146(GmVM* vm) {
    Val v1;
    Val v2;
    v1 = GM_ADD(GM_READ(vm, -5, "ghostskilled"), VAL(1));
    GM_WRITE(vm, -5, "ghostskilled", v1);
    v2 = GM_ADD(GM_READ(vm, -5, "enemieskilled"), VAL(1));
    GM_WRITE(vm, -5, "enemieskilled", v2);
    GM_SITE(vm, 146, 3966404);
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(187)));
    L_3966416: ;
    return;
}
