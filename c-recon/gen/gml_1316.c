/* generated from CODE 1316 (gml_RoomCC_rm_mapview0_1316_Create), source start 5066600, end 5066644. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1316(GmVM* vm) {
    /* @5066600 load */
    /* @5066608 constant */
    /* @5066612 cmp */
    /* @5066616 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level17avisited") == VAL(0)))) goto L_5066632;
    /* @5066620 call */
    GM_SITE(vm, 1316, 5066620);
    /* @5066628 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5066632: ;
    /* @5066632 constant */
    /* @5066636 store */
    GM_WRITE(vm, -1, "goto", VAL(26));
    L_5066644: ;
    return;
}
