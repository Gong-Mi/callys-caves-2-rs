/* generated from CODE 1193 (gml_RoomCC_rm_mapview3_1193_Create), source start 5061188, end 5061232. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1193(GmVM* vm) {
    /* @5061188 load */
    /* @5061196 constant */
    /* @5061200 cmp */
    /* @5061204 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level13avisited") == VAL(0)))) goto L_5061220;
    /* @5061208 call */
    GM_SITE(vm, 1193, 5061208);
    /* @5061216 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5061220: ;
    /* @5061220 constant */
    /* @5061224 store */
    GM_WRITE(vm, -1, "goto", VAL(18));
    L_5061232: ;
    return;
}
