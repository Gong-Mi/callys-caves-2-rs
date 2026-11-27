/* generated from CODE 1314 (gml_RoomCC_rm_mapview0_1314_Create), source start 5066512, end 5066556. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1314(GmVM* vm) {
    /* @5066512 load */
    /* @5066520 constant */
    /* @5066524 cmp */
    /* @5066528 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room77visited") == VAL(0)))) goto L_5066544;
    /* @5066532 call */
    GM_SITE(vm, 1314, 5066532);
    /* @5066540 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5066544: ;
    /* @5066544 constant */
    /* @5066548 store */
    GM_WRITE(vm, -1, "goto", VAL(76));
    L_5066556: ;
    return;
}
