/* generated from CODE 1332 (gml_RoomCC_rm_mapview0_1332_Create), source start 5067304, end 5067348. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1332(GmVM* vm) {
    /* @5067304 load */
    /* @5067312 constant */
    /* @5067316 cmp */
    /* @5067320 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room37visited") == VAL(0)))) goto L_5067336;
    /* @5067324 call */
    GM_SITE(vm, 1332, 5067324);
    /* @5067332 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5067336: ;
    /* @5067336 constant */
    /* @5067340 store */
    GM_WRITE(vm, -1, "goto", VAL(34));
    L_5067348: ;
    return;
}
