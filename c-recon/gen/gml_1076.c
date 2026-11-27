/* generated from CODE 1076 (gml_RoomCC_rm_map_1076_Create), source start 5056040, end 5056084. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1076(GmVM* vm) {
    /* @5056040 load */
    /* @5056048 constant */
    /* @5056052 cmp */
    /* @5056056 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level8avisited") == VAL(0)))) goto L_5056072;
    /* @5056060 call */
    GM_SITE(vm, 1076, 5056060);
    /* @5056068 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5056072: ;
    /* @5056072 constant */
    /* @5056076 store */
    GM_WRITE(vm, -1, "goto", VAL(9));
    L_5056084: ;
    return;
}
