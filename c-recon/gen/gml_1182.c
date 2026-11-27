/* generated from CODE 1182 (gml_RoomCC_rm_mapview3_1182_Create), source start 5060704, end 5060748. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1182(GmVM* vm) {
    /* @5060704 load */
    /* @5060712 constant */
    /* @5060716 cmp */
    /* @5060720 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level9avisited") == VAL(0)))) goto L_5060736;
    /* @5060724 call */
    GM_SITE(vm, 1182, 5060724);
    /* @5060732 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5060736: ;
    /* @5060736 constant */
    /* @5060740 store */
    GM_WRITE(vm, -1, "goto", VAL(12));
    L_5060748: ;
    return;
}
