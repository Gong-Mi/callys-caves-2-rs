/* generated from CODE 452 (gml_Object_obj_finalchest_Create_0), source start 4635872, end 4635932. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0452(GmVM* vm) {
    Val v1;
    /* @4635872 constant */
    /* @4635876 cast */
    /* @4635880 constant */
    /* @4635884 cast */
    /* @4635888 constant */
    /* @4635892 cast */
    /* @4635896 constant */
    /* @4635900 cast */
    /* @4635904 call */
    GM_SITE(vm, 452, 4635904);
    /* @4635912 store */
    v1 = GM_CALL(vm, "choose", 4, VAL(1), VAL(2), VAL(3), VAL(4));
    GM_WRITE(vm, -1, "chestcontents", v1);
    /* @4635920 constant */
    /* @4635924 store */
    GM_WRITE(vm, -1, "touched", VAL(0));
    L_4635932: ;
    return;
}
