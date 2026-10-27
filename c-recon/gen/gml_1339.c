/* generated from CODE 1339 (gml_RoomCC_rm_mapview0_1339_Create), source start 5067612, end 5067656. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1339(GmVM* vm) {
    /* @5067612 load */
    /* @5067620 constant */
    /* @5067624 cmp */
    /* @5067628 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room89visited") == VAL(0)))) goto L_5067644;
    /* @5067632 call */
    GM_SITE(vm, 1339, 5067632);
    /* @5067640 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5067644: ;
    /* @5067644 constant */
    /* @5067648 store */
    GM_WRITE(vm, -1, "goto", VAL(89));
    L_5067656: ;
    return;
}
