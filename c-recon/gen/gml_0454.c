/* generated from CODE 454 (gml_Object_obj_finalchest_Collision_0), source start 4635956, end 4636004. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0454(GmVM* vm) {
    /* @4635956 constant */
    /* @4635960 cast */
    /* @4635964 load */
    /* @4635972 load */
    /* @4635980 call */
    GM_SITE(vm, 454, 4635980);
    /* @4635988 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(162)));
    /* @4635992 call */
    GM_SITE(vm, 454, 4635992);
    /* @4636000 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4636004: ;
    return;
}
