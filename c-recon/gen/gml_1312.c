/* generated from CODE 1312 (gml_RoomCC_rm_mapview0_1312_Create), source start 5066424, end 5066468. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1312(GmVM* vm) {
    /* @5066424 load */
    /* @5066432 constant */
    /* @5066436 cmp */
    /* @5066440 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room76visited") == VAL(0)))) goto L_5066456;
    /* @5066444 call */
    GM_SITE(vm, 1312, 5066444);
    /* @5066452 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5066456: ;
    /* @5066456 constant */
    /* @5066460 store */
    GM_WRITE(vm, -1, "goto", VAL(75));
    L_5066468: ;
    return;
}
