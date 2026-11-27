/* generated from CODE 1178 (gml_RoomCC_rm_mapview3_1178_Create), source start 5060528, end 5060572. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1178(GmVM* vm) {
    /* @5060528 load */
    /* @5060536 constant */
    /* @5060540 cmp */
    /* @5060544 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boss1visited") == VAL(0)))) goto L_5060560;
    /* @5060548 call */
    GM_SITE(vm, 1178, 5060548);
    /* @5060556 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5060560: ;
    /* @5060560 constant */
    /* @5060564 store */
    GM_WRITE(vm, -1, "goto", VAL(10));
    L_5060572: ;
    return;
}
