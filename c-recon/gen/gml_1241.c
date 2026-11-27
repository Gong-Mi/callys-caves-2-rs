/* generated from CODE 1241 (gml_RoomCC_rm_mapview3_1241_Create), source start 5063300, end 5063344. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1241(GmVM* vm) {
    /* @5063300 load */
    /* @5063308 constant */
    /* @5063312 cmp */
    /* @5063316 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "levelchallenge5visited") == VAL(0)))) goto L_5063332;
    /* @5063320 call */
    GM_SITE(vm, 1241, 5063320);
    /* @5063328 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5063332: ;
    /* @5063332 constant */
    /* @5063336 store */
    GM_WRITE(vm, -1, "goto", VAL(109));
    L_5063344: ;
    return;
}
