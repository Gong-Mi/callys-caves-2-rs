/* generated from CODE 1032 (gml_RoomCC_rm_map_1032_Create), source start 5054104, end 5054148. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1032(GmVM* vm) {
    /* @5054104 load */
    /* @5054112 constant */
    /* @5054116 cmp */
    /* @5054120 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room93visited") == VAL(0)))) goto L_5054136;
    /* @5054124 call */
    GM_SITE(vm, 1032, 5054124);
    /* @5054132 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5054136: ;
    /* @5054136 constant */
    /* @5054140 store */
    GM_WRITE(vm, -1, "goto", VAL(93));
    L_5054148: ;
    return;
}
