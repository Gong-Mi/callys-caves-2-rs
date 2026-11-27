/* generated from CODE 1129 (gml_RoomCC_rm_map_1129_Create), source start 5058372, end 5058416. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1129(GmVM* vm) {
    /* @5058372 load */
    /* @5058380 constant */
    /* @5058384 cmp */
    /* @5058388 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "levelchallenge2visited") == VAL(0)))) goto L_5058404;
    /* @5058392 call */
    GM_SITE(vm, 1129, 5058392);
    /* @5058400 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5058404: ;
    /* @5058404 constant */
    /* @5058408 store */
    GM_WRITE(vm, -1, "goto", VAL(106));
    L_5058416: ;
    return;
}
