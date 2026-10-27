/* generated from CODE 1264 (gml_RoomCC_rm_mapview0_1264_Create), source start 5064312, end 5064356. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1264(GmVM* vm) {
    /* @5064312 load */
    /* @5064320 constant */
    /* @5064324 cmp */
    /* @5064328 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room52visited") == VAL(0)))) goto L_5064344;
    /* @5064332 call */
    GM_SITE(vm, 1264, 5064332);
    /* @5064340 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5064344: ;
    /* @5064344 constant */
    /* @5064348 store */
    GM_WRITE(vm, -1, "goto", VAL(50));
    L_5064356: ;
    return;
}
