/* generated from CODE 1344 (gml_RoomCC_rm_mapview0_1344_Create), source start 5067832, end 5067876. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1344(GmVM* vm) {
    /* @5067832 load */
    /* @5067840 constant */
    /* @5067844 cmp */
    /* @5067848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room103visited") == VAL(0)))) goto L_5067864;
    /* @5067852 call */
    GM_SITE(vm, 1344, 5067852);
    /* @5067860 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5067864: ;
    /* @5067864 constant */
    /* @5067868 store */
    GM_WRITE(vm, -1, "goto", VAL(103));
    L_5067876: ;
    return;
}
