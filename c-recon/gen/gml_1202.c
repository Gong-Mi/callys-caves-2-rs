/* generated from CODE 1202 (gml_RoomCC_rm_mapview3_1202_Create), source start 5061584, end 5061628. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1202(GmVM* vm) {
    /* @5061584 load */
    /* @5061592 constant */
    /* @5061596 cmp */
    /* @5061600 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room75visited") == VAL(0)))) goto L_5061616;
    /* @5061604 call */
    GM_SITE(vm, 1202, 5061604);
    /* @5061612 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5061616: ;
    /* @5061616 constant */
    /* @5061620 store */
    GM_WRITE(vm, -1, "goto", VAL(74));
    L_5061628: ;
    return;
}
