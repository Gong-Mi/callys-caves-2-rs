/* generated from CODE 1126 (gml_RoomCC_rm_map_1126_Create), source start 5058240, end 5058284. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1126(GmVM* vm) {
    /* @5058240 load */
    /* @5058248 constant */
    /* @5058252 cmp */
    /* @5058256 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room38visited") == VAL(0)))) goto L_5058272;
    /* @5058260 call */
    GM_SITE(vm, 1126, 5058260);
    /* @5058268 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5058272: ;
    /* @5058272 constant */
    /* @5058276 store */
    GM_WRITE(vm, -1, "goto", VAL(35));
    L_5058284: ;
    return;
}
