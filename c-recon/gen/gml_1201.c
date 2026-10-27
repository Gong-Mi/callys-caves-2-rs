/* generated from CODE 1201 (gml_RoomCC_rm_mapview3_1201_Create), source start 5061540, end 5061584. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1201(GmVM* vm) {
    /* @5061540 load */
    /* @5061548 constant */
    /* @5061552 cmp */
    /* @5061556 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level15avisited") == VAL(0)))) goto L_5061572;
    /* @5061560 call */
    GM_SITE(vm, 1201, 5061560);
    /* @5061568 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5061572: ;
    /* @5061572 constant */
    /* @5061576 store */
    GM_WRITE(vm, -1, "goto", VAL(22));
    L_5061584: ;
    return;
}
