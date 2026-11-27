/* generated from CODE 1272 (gml_RoomCC_rm_mapview0_1272_Create), source start 5064664, end 5064708. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1272(GmVM* vm) {
    /* @5064664 load */
    /* @5064672 constant */
    /* @5064676 cmp */
    /* @5064680 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level3visited") == VAL(0)))) goto L_5064696;
    /* @5064684 call */
    GM_SITE(vm, 1272, 5064684);
    /* @5064692 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5064696: ;
    /* @5064696 constant */
    /* @5064700 store */
    GM_WRITE(vm, -1, "goto", VAL(3));
    L_5064708: ;
    return;
}
