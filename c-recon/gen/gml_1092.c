/* generated from CODE 1092 (gml_RoomCC_rm_map_1092_Create), source start 5056744, end 5056788. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1092(GmVM* vm) {
    /* @5056744 load */
    /* @5056752 constant */
    /* @5056756 cmp */
    /* @5056760 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room70visited") == VAL(0)))) goto L_5056776;
    /* @5056764 call */
    GM_SITE(vm, 1092, 5056764);
    /* @5056772 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5056776: ;
    /* @5056776 constant */
    /* @5056780 store */
    GM_WRITE(vm, -1, "goto", VAL(69));
    L_5056788: ;
    return;
}
