/* generated from CODE 1247 (gml_RoomCC_rm_mapview0_1247_Create), source start 5063564, end 5063608. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1247(GmVM* vm) {
    /* @5063564 load */
    /* @5063572 constant */
    /* @5063576 cmp */
    /* @5063580 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room95visited") == VAL(0)))) goto L_5063596;
    /* @5063584 call */
    GM_SITE(vm, 1247, 5063584);
    /* @5063592 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5063596: ;
    /* @5063596 constant */
    /* @5063600 store */
    GM_WRITE(vm, -1, "goto", VAL(95));
    L_5063608: ;
    return;
}
