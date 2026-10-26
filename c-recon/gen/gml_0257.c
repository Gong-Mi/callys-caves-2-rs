/* generated from CODE 257 (gml_Object_obj_fireslime_Destroy_0), source start 4048892, end 4048976. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0257(GmVM* vm) {
    GM_WRITE(vm, -5, "fireslimeskilled", GM_ADD(GM_READ(vm, -5, "fireslimeskilled"), VAL(1)));
    GM_WRITE(vm, -5, "enemieskilled", GM_ADD(GM_READ(vm, -5, "enemieskilled"), VAL(1)));
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(187)));
    L_4048976: ;
    return;
}
