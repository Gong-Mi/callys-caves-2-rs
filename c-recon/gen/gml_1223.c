/* generated from CODE 1223 (gml_RoomCC_rm_mapview3_1223_Create), source start 5062508, end 5062552. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1223(GmVM* vm) {
    /* @5062508 load */
    /* @5062516 constant */
    /* @5062520 cmp */
    /* @5062524 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room85visited") == VAL(0)))) goto L_5062540;
    /* @5062528 call */
    GM_SITE(vm, 1223, 5062528);
    /* @5062536 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5062540: ;
    /* @5062540 constant */
    /* @5062544 store */
    GM_WRITE(vm, -1, "goto", VAL(85));
    L_5062552: ;
    return;
}
