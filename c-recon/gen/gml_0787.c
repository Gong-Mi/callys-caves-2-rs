/* generated from CODE 787 (gml_Object_obj_finalbosspuff_Destroy_0), source start 5041328, end 5041368. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0787(GmVM* vm) {
    /* @5041328 constant */
    /* @5041332 cast */
    /* @5041336 call */
    GM_SITE(vm, 787, 5041336);
    /* @5041344 popz */
    (void)(GM_CALL(vm, "instance_deactivate_object", 1, VAL(0)));
    /* @5041348 constant */
    /* @5041352 cast */
    /* @5041356 call */
    GM_SITE(vm, 787, 5041356);
    /* @5041364 popz */
    (void)(GM_CALL(vm, "room_goto", 1, VAL(110)));
    L_5041368: ;
    return;
}
