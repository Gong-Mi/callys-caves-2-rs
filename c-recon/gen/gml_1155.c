/* generated from CODE 1155 (gml_RoomCC_rm_mapview3_1155_Create), source start 5059516, end 5059560. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1155(GmVM* vm) {
    /* @5059516 load */
    /* @5059524 constant */
    /* @5059528 cmp */
    /* @5059532 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room52visited") == VAL(0)))) goto L_5059548;
    /* @5059536 call */
    GM_SITE(vm, 1155, 5059536);
    /* @5059544 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5059548: ;
    /* @5059548 constant */
    /* @5059552 store */
    GM_WRITE(vm, -1, "goto", VAL(50));
    L_5059560: ;
    return;
}
