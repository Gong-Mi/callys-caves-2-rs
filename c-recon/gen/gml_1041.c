/* generated from CODE 1041 (gml_RoomCC_rm_map_1041_Create), source start 5054500, end 5054544. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1041(GmVM* vm) {
    /* @5054500 load */
    /* @5054508 constant */
    /* @5054512 cmp */
    /* @5054516 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room78visited") == VAL(0)))) goto L_5054532;
    /* @5054520 call */
    GM_SITE(vm, 1041, 5054520);
    /* @5054528 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5054532: ;
    /* @5054532 constant */
    /* @5054536 store */
    GM_WRITE(vm, -1, "goto", VAL(77));
    L_5054544: ;
    return;
}
