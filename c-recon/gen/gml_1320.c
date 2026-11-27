/* generated from CODE 1320 (gml_RoomCC_rm_mapview0_1320_Create), source start 5066776, end 5066820. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1320(GmVM* vm) {
    /* @5066776 load */
    /* @5066784 constant */
    /* @5066788 cmp */
    /* @5066792 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room31visited") == VAL(0)))) goto L_5066808;
    /* @5066796 call */
    GM_SITE(vm, 1320, 5066796);
    /* @5066804 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5066808: ;
    /* @5066808 constant */
    /* @5066812 store */
    GM_WRITE(vm, -1, "goto", VAL(28));
    L_5066820: ;
    return;
}
