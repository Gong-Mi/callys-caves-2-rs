/* generated from CODE 1219 (gml_RoomCC_rm_mapview3_1219_Create), source start 5062332, end 5062376. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1219(GmVM* vm) {
    /* @5062332 load */
    /* @5062340 constant */
    /* @5062344 cmp */
    /* @5062348 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room83visited") == VAL(0)))) goto L_5062364;
    /* @5062352 call */
    GM_SITE(vm, 1219, 5062352);
    /* @5062360 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5062364: ;
    /* @5062364 constant */
    /* @5062368 store */
    GM_WRITE(vm, -1, "goto", VAL(83));
    L_5062376: ;
    return;
}
