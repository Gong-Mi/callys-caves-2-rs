/* generated from CODE 1065 (gml_RoomCC_rm_map_1065_Create), source start 5055556, end 5055600. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1065(GmVM* vm) {
    /* @5055556 load */
    /* @5055564 constant */
    /* @5055568 cmp */
    /* @5055572 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room57visited") == VAL(0)))) goto L_5055588;
    /* @5055576 call */
    GM_SITE(vm, 1065, 5055576);
    /* @5055584 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5055588: ;
    /* @5055588 constant */
    /* @5055592 store */
    GM_WRITE(vm, -1, "goto", VAL(55));
    L_5055600: ;
    return;
}
