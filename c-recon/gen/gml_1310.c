/* generated from CODE 1310 (gml_RoomCC_rm_mapview0_1310_Create), source start 5066336, end 5066380. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1310(GmVM* vm) {
    /* @5066336 load */
    /* @5066344 constant */
    /* @5066348 cmp */
    /* @5066352 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room75visited") == VAL(0)))) goto L_5066368;
    /* @5066356 call */
    GM_SITE(vm, 1310, 5066356);
    /* @5066364 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5066368: ;
    /* @5066368 constant */
    /* @5066372 store */
    GM_WRITE(vm, -1, "goto", VAL(74));
    L_5066380: ;
    return;
}
