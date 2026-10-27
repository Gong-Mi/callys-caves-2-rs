/* generated from CODE 451 (gml_Object_obj_treasurechest_Collision_0), source start 4635824, end 4635872. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0451(GmVM* vm) {
    /* @4635824 constant */
    /* @4635828 cast */
    /* @4635832 load */
    /* @4635840 load */
    /* @4635848 call */
    GM_SITE(vm, 451, 4635848);
    /* @4635856 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(102)));
    /* @4635860 call */
    GM_SITE(vm, 451, 4635860);
    /* @4635868 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4635872: ;
    return;
}
