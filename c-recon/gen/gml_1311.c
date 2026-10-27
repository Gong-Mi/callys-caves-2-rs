/* generated from CODE 1311 (gml_RoomCC_rm_mapview0_1311_Create), source start 5066380, end 5066424. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1311(GmVM* vm) {
    /* @5066380 load */
    /* @5066388 constant */
    /* @5066392 cmp */
    /* @5066396 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level16visited") == VAL(0)))) goto L_5066412;
    /* @5066400 call */
    GM_SITE(vm, 1311, 5066400);
    /* @5066408 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5066412: ;
    /* @5066412 constant */
    /* @5066416 store */
    GM_WRITE(vm, -1, "goto", VAL(23));
    L_5066424: ;
    return;
}
