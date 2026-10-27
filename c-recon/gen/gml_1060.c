/* generated from CODE 1060 (gml_RoomCC_rm_map_1060_Create), source start 5055336, end 5055380. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1060(GmVM* vm) {
    /* @5055336 load */
    /* @5055344 constant */
    /* @5055348 cmp */
    /* @5055352 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level1visited") == VAL(0)))) goto L_5055368;
    /* @5055356 call */
    GM_SITE(vm, 1060, 5055356);
    /* @5055364 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5055368: ;
    /* @5055368 constant */
    /* @5055372 store */
    GM_WRITE(vm, -1, "goto", VAL(1));
    L_5055380: ;
    return;
}
