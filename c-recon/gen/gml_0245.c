/* generated from CODE 245 (gml_Object_obj_slime_Destroy_0), source start 4041772, end 4041856. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0245(GmVM* vm) {
    GM_WRITE(vm, -5, "greenslimeskilled", GM_ADD(GM_READ(vm, -5, "greenslimeskilled"), VAL(1)));
    GM_WRITE(vm, -5, "enemieskilled", GM_ADD(GM_READ(vm, -5, "enemieskilled"), VAL(1)));
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(187)));
    L_4041856: ;
    return;
}
