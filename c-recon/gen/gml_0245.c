/* generated from CODE 245 (gml_Object_obj_slime_Destroy_0), source start 4041772, end 4041856. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0245(GmVM* vm) {
    Val v1;
    Val v2;
    v1 = GM_ADD(GM_READ(vm, -5, "greenslimeskilled"), VAL(1));
    GM_WRITE(vm, -5, "greenslimeskilled", v1);
    v2 = GM_ADD(GM_READ(vm, -5, "enemieskilled"), VAL(1));
    GM_WRITE(vm, -5, "enemieskilled", v2);
    GM_SITE(vm, 245, 4041844);
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(187)));
    L_4041856: ;
    return;
}
