/* generated from CODE 1171 (gml_RoomCC_rm_mapview3_1171_Create), source start 5060220, end 5060264. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1171(GmVM* vm) {
    /* @5060220 load */
    /* @5060228 constant */
    /* @5060232 cmp */
    /* @5060236 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room60visited") == VAL(0)))) goto L_5060252;
    /* @5060240 call */
    GM_SITE(vm, 1171, 5060240);
    /* @5060248 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5060252: ;
    /* @5060252 constant */
    /* @5060256 store */
    GM_WRITE(vm, -1, "goto", VAL(58));
    L_5060264: ;
    return;
}
