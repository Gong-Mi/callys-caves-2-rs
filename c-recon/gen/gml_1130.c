/* generated from CODE 1130 (gml_RoomCC_rm_map_1130_Create), source start 5058416, end 5058460. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1130(GmVM* vm) {
    /* @5058416 load */
    /* @5058424 constant */
    /* @5058428 cmp */
    /* @5058432 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "levelchallenge3visited") == VAL(0)))) goto L_5058448;
    /* @5058436 call */
    GM_SITE(vm, 1130, 5058436);
    /* @5058444 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5058448: ;
    /* @5058448 constant */
    /* @5058452 store */
    GM_WRITE(vm, -1, "goto", VAL(107));
    L_5058460: ;
    return;
}
