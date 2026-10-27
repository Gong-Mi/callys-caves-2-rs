/* generated from CODE 1333 (gml_RoomCC_rm_mapview0_1333_Create), source start 5067348, end 5067392. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1333(GmVM* vm) {
    /* @5067348 load */
    /* @5067356 constant */
    /* @5067360 cmp */
    /* @5067364 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room86visited") == VAL(0)))) goto L_5067380;
    /* @5067368 call */
    GM_SITE(vm, 1333, 5067368);
    /* @5067376 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5067380: ;
    /* @5067380 constant */
    /* @5067384 store */
    GM_WRITE(vm, -1, "goto", VAL(86));
    L_5067392: ;
    return;
}
