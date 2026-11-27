/* generated from CODE 1337 (gml_RoomCC_rm_mapview0_1337_Create), source start 5067524, end 5067568. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1337(GmVM* vm) {
    /* @5067524 load */
    /* @5067532 constant */
    /* @5067536 cmp */
    /* @5067540 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room88visited") == VAL(0)))) goto L_5067556;
    /* @5067544 call */
    GM_SITE(vm, 1337, 5067544);
    /* @5067552 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5067556: ;
    /* @5067556 constant */
    /* @5067560 store */
    GM_WRITE(vm, -1, "goto", VAL(88));
    L_5067568: ;
    return;
}
