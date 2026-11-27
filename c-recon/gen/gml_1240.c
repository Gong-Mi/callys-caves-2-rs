/* generated from CODE 1240 (gml_RoomCC_rm_mapview3_1240_Create), source start 5063256, end 5063300. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1240(GmVM* vm) {
    /* @5063256 load */
    /* @5063264 constant */
    /* @5063268 cmp */
    /* @5063272 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "levelchallenge4visited") == VAL(0)))) goto L_5063288;
    /* @5063276 call */
    GM_SITE(vm, 1240, 5063276);
    /* @5063284 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5063288: ;
    /* @5063288 constant */
    /* @5063292 store */
    GM_WRITE(vm, -1, "goto", VAL(108));
    L_5063300: ;
    return;
}
