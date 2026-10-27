/* generated from CODE 257 (gml_Object_obj_fireslime_Destroy_0), source start 4048892, end 4048976. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0257(GmVM* vm) {
    Val v1;
    Val v2;
    v1 = GM_ADD(GM_READ(vm, -5, "fireslimeskilled"), VAL(1));
    GM_WRITE(vm, -5, "fireslimeskilled", v1);
    v2 = GM_ADD(GM_READ(vm, -5, "enemieskilled"), VAL(1));
    GM_WRITE(vm, -5, "enemieskilled", v2);
    GM_SITE(vm, 257, 4048964);
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(187)));
    L_4048976: ;
    return;
}
