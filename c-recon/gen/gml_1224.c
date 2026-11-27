/* generated from CODE 1224 (gml_RoomCC_rm_mapview3_1224_Create), source start 5062552, end 5062596. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1224(GmVM* vm) {
    /* @5062552 load */
    /* @5062560 constant */
    /* @5062564 cmp */
    /* @5062568 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room37visited") == VAL(0)))) goto L_5062584;
    /* @5062572 call */
    GM_SITE(vm, 1224, 5062572);
    /* @5062580 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5062584: ;
    /* @5062584 constant */
    /* @5062588 store */
    GM_WRITE(vm, -1, "goto", VAL(34));
    L_5062596: ;
    return;
}
