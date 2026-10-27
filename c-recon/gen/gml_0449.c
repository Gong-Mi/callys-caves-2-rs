/* generated from CODE 449 (gml_Object_obj_treasurechest_Create_0), source start 4635740, end 4635800. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0449(GmVM* vm) {
    Val v1;
    /* @4635740 constant */
    /* @4635744 cast */
    /* @4635748 constant */
    /* @4635752 cast */
    /* @4635756 constant */
    /* @4635760 cast */
    /* @4635764 constant */
    /* @4635768 cast */
    /* @4635772 call */
    GM_SITE(vm, 449, 4635772);
    /* @4635780 store */
    v1 = GM_CALL(vm, "choose", 4, VAL(1), VAL(2), VAL(3), VAL(4));
    GM_WRITE(vm, -1, "chestcontents", v1);
    /* @4635788 constant */
    /* @4635792 store */
    GM_WRITE(vm, -1, "touched", VAL(0));
    L_4635800: ;
    return;
}
