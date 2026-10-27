/* generated from CODE 1038 (gml_RoomCC_rm_map_1038_Create), source start 5054368, end 5054412. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1038(GmVM* vm) {
    /* @5054368 load */
    /* @5054376 constant */
    /* @5054380 cmp */
    /* @5054384 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room41visited") == VAL(0)))) goto L_5054400;
    /* @5054388 call */
    GM_SITE(vm, 1038, 5054388);
    /* @5054396 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5054400: ;
    /* @5054400 constant */
    /* @5054404 store */
    GM_WRITE(vm, -1, "goto", VAL(38));
    L_5054412: ;
    return;
}
