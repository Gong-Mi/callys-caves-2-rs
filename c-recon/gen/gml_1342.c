/* generated from CODE 1342 (gml_RoomCC_rm_mapview0_1342_Create), source start 5067744, end 5067788. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1342(GmVM* vm) {
    /* @5067744 load */
    /* @5067752 constant */
    /* @5067756 cmp */
    /* @5067760 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room78visited") == VAL(0)))) goto L_5067776;
    /* @5067764 call */
    GM_SITE(vm, 1342, 5067764);
    /* @5067772 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5067776: ;
    /* @5067776 constant */
    /* @5067780 store */
    GM_WRITE(vm, -1, "goto", VAL(77));
    L_5067788: ;
    return;
}
