/* generated from CODE 1216 (gml_RoomCC_rm_mapview3_1216_Create), source start 5062200, end 5062244. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1216(GmVM* vm) {
    /* @5062200 load */
    /* @5062208 constant */
    /* @5062212 cmp */
    /* @5062216 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room33visited") == VAL(0)))) goto L_5062232;
    /* @5062220 call */
    GM_SITE(vm, 1216, 5062220);
    /* @5062228 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5062232: ;
    /* @5062232 constant */
    /* @5062236 store */
    GM_WRITE(vm, -1, "goto", VAL(30));
    L_5062244: ;
    return;
}
