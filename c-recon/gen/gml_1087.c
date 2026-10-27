/* generated from CODE 1087 (gml_RoomCC_rm_map_1087_Create), source start 5056524, end 5056568. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1087(GmVM* vm) {
    /* @5056524 load */
    /* @5056532 constant */
    /* @5056536 cmp */
    /* @5056540 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level11avisited") == VAL(0)))) goto L_5056556;
    /* @5056544 call */
    GM_SITE(vm, 1087, 5056544);
    /* @5056552 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5056556: ;
    /* @5056556 constant */
    /* @5056560 store */
    GM_WRITE(vm, -1, "goto", VAL(15));
    L_5056568: ;
    return;
}
