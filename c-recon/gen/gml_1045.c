/* generated from CODE 1045 (gml_RoomCC_rm_map_1045_Create), source start 5054676, end 5054720. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1045(GmVM* vm) {
    /* @5054676 load */
    /* @5054684 constant */
    /* @5054688 cmp */
    /* @5054692 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room48visited") == VAL(0)))) goto L_5054708;
    /* @5054696 call */
    GM_SITE(vm, 1045, 5054696);
    /* @5054704 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5054708: ;
    /* @5054708 constant */
    /* @5054712 store */
    GM_WRITE(vm, -1, "goto", VAL(45));
    L_5054720: ;
    return;
}
