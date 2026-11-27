/* generated from CODE 1274 (gml_RoomCC_rm_mapview0_1274_Create), source start 5064752, end 5064796. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1274(GmVM* vm) {
    /* @5064752 load */
    /* @5064760 constant */
    /* @5064764 cmp */
    /* @5064768 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level4visited") == VAL(0)))) goto L_5064784;
    /* @5064772 call */
    GM_SITE(vm, 1274, 5064772);
    /* @5064780 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5064784: ;
    /* @5064784 constant */
    /* @5064788 store */
    GM_WRITE(vm, -1, "goto", VAL(4));
    L_5064796: ;
    return;
}
