/* generated from CODE 1070 (gml_RoomCC_rm_map_1070_Create), source start 5055776, end 5055820. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1070(GmVM* vm) {
    /* @5055776 load */
    /* @5055784 constant */
    /* @5055788 cmp */
    /* @5055792 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level6visited") == VAL(0)))) goto L_5055808;
    /* @5055796 call */
    GM_SITE(vm, 1070, 5055796);
    /* @5055804 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5055808: ;
    /* @5055808 constant */
    /* @5055812 store */
    GM_WRITE(vm, -1, "goto", VAL(6));
    L_5055820: ;
    return;
}
