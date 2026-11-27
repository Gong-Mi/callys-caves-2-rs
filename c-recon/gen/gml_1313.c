/* generated from CODE 1313 (gml_RoomCC_rm_mapview0_1313_Create), source start 5066468, end 5066512. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1313(GmVM* vm) {
    /* @5066468 load */
    /* @5066476 constant */
    /* @5066480 cmp */
    /* @5066484 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level16avisited") == VAL(0)))) goto L_5066500;
    /* @5066488 call */
    GM_SITE(vm, 1313, 5066488);
    /* @5066496 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5066500: ;
    /* @5066500 constant */
    /* @5066504 store */
    GM_WRITE(vm, -1, "goto", VAL(24));
    L_5066512: ;
    return;
}
