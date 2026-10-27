/* generated from CODE 1217 (gml_RoomCC_rm_mapview3_1217_Create), source start 5062244, end 5062288. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1217(GmVM* vm) {
    /* @5062244 load */
    /* @5062252 constant */
    /* @5062256 cmp */
    /* @5062260 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boss5visited") == VAL(0)))) goto L_5062276;
    /* @5062264 call */
    GM_SITE(vm, 1217, 5062264);
    /* @5062272 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5062276: ;
    /* @5062276 constant */
    /* @5062280 store */
    GM_WRITE(vm, -1, "goto", VAL(82));
    L_5062288: ;
    return;
}
