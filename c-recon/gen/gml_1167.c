/* generated from CODE 1167 (gml_RoomCC_rm_mapview3_1167_Create), source start 5060044, end 5060088. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1167(GmVM* vm) {
    /* @5060044 load */
    /* @5060052 constant */
    /* @5060056 cmp */
    /* @5060060 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room58visited") == VAL(0)))) goto L_5060076;
    /* @5060064 call */
    GM_SITE(vm, 1167, 5060064);
    /* @5060072 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5060076: ;
    /* @5060076 constant */
    /* @5060080 store */
    GM_WRITE(vm, -1, "goto", VAL(56));
    L_5060088: ;
    return;
}
