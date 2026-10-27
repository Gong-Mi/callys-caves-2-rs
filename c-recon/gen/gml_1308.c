/* generated from CODE 1308 (gml_RoomCC_rm_mapview0_1308_Create), source start 5066248, end 5066292. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1308(GmVM* vm) {
    /* @5066248 load */
    /* @5066256 constant */
    /* @5066260 cmp */
    /* @5066264 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room74visited") == VAL(0)))) goto L_5066280;
    /* @5066268 call */
    GM_SITE(vm, 1308, 5066268);
    /* @5066276 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5066280: ;
    /* @5066280 constant */
    /* @5066284 store */
    GM_WRITE(vm, -1, "goto", VAL(73));
    L_5066292: ;
    return;
}
