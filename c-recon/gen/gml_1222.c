/* generated from CODE 1222 (gml_RoomCC_rm_mapview3_1222_Create), source start 5062464, end 5062508. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1222(GmVM* vm) {
    /* @5062464 load */
    /* @5062472 constant */
    /* @5062476 cmp */
    /* @5062480 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room36visited") == VAL(0)))) goto L_5062496;
    /* @5062484 call */
    GM_SITE(vm, 1222, 5062484);
    /* @5062492 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5062496: ;
    /* @5062496 constant */
    /* @5062500 store */
    GM_WRITE(vm, -1, "goto", VAL(33));
    L_5062508: ;
    return;
}
