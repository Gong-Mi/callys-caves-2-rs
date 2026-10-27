/* generated from CODE 1249 (gml_RoomCC_rm_mapview0_1249_Create), source start 5063652, end 5063696. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1249(GmVM* vm) {
    /* @5063652 load */
    /* @5063660 constant */
    /* @5063664 cmp */
    /* @5063668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room44visited") == VAL(0)))) goto L_5063684;
    /* @5063672 call */
    GM_SITE(vm, 1249, 5063672);
    /* @5063680 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5063684: ;
    /* @5063684 constant */
    /* @5063688 store */
    GM_WRITE(vm, -1, "goto", VAL(41));
    L_5063696: ;
    return;
}
