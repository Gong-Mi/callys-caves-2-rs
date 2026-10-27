/* generated from CODE 1044 (gml_RoomCC_rm_map_1044_Create), source start 5054632, end 5054676. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1044(GmVM* vm) {
    /* @5054632 load */
    /* @5054640 constant */
    /* @5054644 cmp */
    /* @5054648 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room96visited") == VAL(0)))) goto L_5054664;
    /* @5054652 call */
    GM_SITE(vm, 1044, 5054652);
    /* @5054660 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5054664: ;
    /* @5054664 constant */
    /* @5054668 store */
    GM_WRITE(vm, -1, "goto", VAL(96));
    L_5054676: ;
    return;
}
