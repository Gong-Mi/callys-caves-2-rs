/* generated from CODE 1212 (gml_RoomCC_rm_mapview3_1212_Create), source start 5062024, end 5062068. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1212(GmVM* vm) {
    /* @5062024 load */
    /* @5062032 constant */
    /* @5062036 cmp */
    /* @5062040 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room31visited") == VAL(0)))) goto L_5062056;
    /* @5062044 call */
    GM_SITE(vm, 1212, 5062044);
    /* @5062052 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5062056: ;
    /* @5062056 constant */
    /* @5062060 store */
    GM_WRITE(vm, -1, "goto", VAL(28));
    L_5062068: ;
    return;
}
