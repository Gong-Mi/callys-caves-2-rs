/* generated from CODE 1197 (gml_RoomCC_rm_mapview3_1197_Create), source start 5061364, end 5061408. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1197(GmVM* vm) {
    /* @5061364 load */
    /* @5061372 constant */
    /* @5061376 cmp */
    /* @5061380 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level14avisited") == VAL(0)))) goto L_5061396;
    /* @5061384 call */
    GM_SITE(vm, 1197, 5061384);
    /* @5061392 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5061396: ;
    /* @5061396 constant */
    /* @5061400 store */
    GM_WRITE(vm, -1, "goto", VAL(20));
    L_5061408: ;
    return;
}
