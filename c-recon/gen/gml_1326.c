/* generated from CODE 1326 (gml_RoomCC_rm_mapview0_1326_Create), source start 5067040, end 5067084. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1326(GmVM* vm) {
    /* @5067040 load */
    /* @5067048 constant */
    /* @5067052 cmp */
    /* @5067056 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room34visited") == VAL(0)))) goto L_5067072;
    /* @5067060 call */
    GM_SITE(vm, 1326, 5067060);
    /* @5067068 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5067072: ;
    /* @5067072 constant */
    /* @5067076 store */
    GM_WRITE(vm, -1, "goto", VAL(31));
    L_5067084: ;
    return;
}
