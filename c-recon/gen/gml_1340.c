/* generated from CODE 1340 (gml_RoomCC_rm_mapview0_1340_Create), source start 5067656, end 5067700. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1340(GmVM* vm) {
    /* @5067656 load */
    /* @5067664 constant */
    /* @5067668 cmp */
    /* @5067672 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room41visited") == VAL(0)))) goto L_5067688;
    /* @5067676 call */
    GM_SITE(vm, 1340, 5067676);
    /* @5067684 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5067688: ;
    /* @5067688 constant */
    /* @5067692 store */
    GM_WRITE(vm, -1, "goto", VAL(38));
    L_5067700: ;
    return;
}
