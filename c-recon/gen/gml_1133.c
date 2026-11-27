/* generated from CODE 1133 (gml_RoomCC_rm_mapview3_1133_Create), source start 5058548, end 5058592. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1133(GmVM* vm) {
    /* @5058548 load */
    /* @5058556 constant */
    /* @5058560 cmp */
    /* @5058564 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room94visited") == VAL(0)))) goto L_5058580;
    /* @5058568 call */
    GM_SITE(vm, 1133, 5058568);
    /* @5058576 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5058580: ;
    /* @5058580 constant */
    /* @5058584 store */
    GM_WRITE(vm, -1, "goto", VAL(94));
    L_5058592: ;
    return;
}
