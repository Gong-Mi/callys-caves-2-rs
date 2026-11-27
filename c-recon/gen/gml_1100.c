/* generated from CODE 1100 (gml_RoomCC_rm_map_1100_Create), source start 5057096, end 5057140. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1100(GmVM* vm) {
    /* @5057096 load */
    /* @5057104 constant */
    /* @5057108 cmp */
    /* @5057112 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room74visited") == VAL(0)))) goto L_5057128;
    /* @5057116 call */
    GM_SITE(vm, 1100, 5057116);
    /* @5057124 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5057128: ;
    /* @5057128 constant */
    /* @5057132 store */
    GM_WRITE(vm, -1, "goto", VAL(73));
    L_5057140: ;
    return;
}
