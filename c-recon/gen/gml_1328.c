/* generated from CODE 1328 (gml_RoomCC_rm_mapview0_1328_Create), source start 5067128, end 5067172. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1328(GmVM* vm) {
    /* @5067128 load */
    /* @5067136 constant */
    /* @5067140 cmp */
    /* @5067144 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room35visited") == VAL(0)))) goto L_5067160;
    /* @5067148 call */
    GM_SITE(vm, 1328, 5067148);
    /* @5067156 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5067160: ;
    /* @5067160 constant */
    /* @5067164 store */
    GM_WRITE(vm, -1, "goto", VAL(32));
    L_5067172: ;
    return;
}
