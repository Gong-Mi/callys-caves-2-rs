/* generated from CODE 1229 (gml_RoomCC_rm_mapview3_1229_Create), source start 5062772, end 5062816. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1229(GmVM* vm) {
    /* @5062772 load */
    /* @5062780 constant */
    /* @5062784 cmp */
    /* @5062788 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room88visited") == VAL(0)))) goto L_5062804;
    /* @5062792 call */
    GM_SITE(vm, 1229, 5062792);
    /* @5062800 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5062804: ;
    /* @5062804 constant */
    /* @5062808 store */
    GM_WRITE(vm, -1, "goto", VAL(88));
    L_5062816: ;
    return;
}
