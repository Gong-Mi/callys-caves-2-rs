/* generated from CODE 1159 (gml_RoomCC_rm_mapview3_1159_Create), source start 5059692, end 5059736. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1159(GmVM* vm) {
    /* @5059692 load */
    /* @5059700 constant */
    /* @5059704 cmp */
    /* @5059708 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room54visited") == VAL(0)))) goto L_5059724;
    /* @5059712 call */
    GM_SITE(vm, 1159, 5059712);
    /* @5059720 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5059724: ;
    /* @5059724 constant */
    /* @5059728 store */
    GM_WRITE(vm, -1, "goto", VAL(52));
    L_5059736: ;
    return;
}
