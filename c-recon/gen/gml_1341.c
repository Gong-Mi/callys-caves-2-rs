/* generated from CODE 1341 (gml_RoomCC_rm_mapview0_1341_Create), source start 5067700, end 5067744. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1341(GmVM* vm) {
    /* @5067700 load */
    /* @5067708 constant */
    /* @5067712 cmp */
    /* @5067716 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boss4visited") == VAL(0)))) goto L_5067732;
    /* @5067720 call */
    GM_SITE(vm, 1341, 5067720);
    /* @5067728 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5067732: ;
    /* @5067732 constant */
    /* @5067736 store */
    GM_WRITE(vm, -1, "goto", VAL(64));
    L_5067744: ;
    return;
}
