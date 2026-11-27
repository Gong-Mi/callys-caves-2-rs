/* generated from CODE 455 (gml_Object_obj_treasurechestopen_Create_0), source start 4636004, end 4636096. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0455(GmVM* vm) {
    Val v1;
    /* @4636004 constant */
    /* @4636008 cast */
    /* @4636012 constant */
    /* @4636016 cast */
    /* @4636020 constant */
    /* @4636024 cast */
    /* @4636028 constant */
    /* @4636032 cast */
    /* @4636036 constant */
    /* @4636040 cast */
    /* @4636044 constant */
    /* @4636048 cast */
    /* @4636052 constant */
    /* @4636056 cast */
    /* @4636060 call */
    GM_SITE(vm, 455, 4636060);
    /* @4636068 store */
    v1 = GM_CALL(vm, "choose", 7, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5), VAL(6), VAL(7));
    GM_WRITE(vm, -1, "chestcontents", v1);
    /* @4636076 constant */
    /* @4636080 constant */
    /* @4636084 constant */
    /* @4636088 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(20));
    L_4636096: ;
    return;
}
