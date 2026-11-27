/* generated from CODE 1184 (gml_RoomCC_rm_mapview3_1184_Create), source start 5060792, end 5060836. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1184(GmVM* vm) {
    /* @5060792 load */
    /* @5060800 constant */
    /* @5060804 cmp */
    /* @5060808 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room66visited") == VAL(0)))) goto L_5060824;
    /* @5060812 call */
    GM_SITE(vm, 1184, 5060812);
    /* @5060820 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5060824: ;
    /* @5060824 constant */
    /* @5060828 store */
    GM_WRITE(vm, -1, "goto", VAL(65));
    L_5060836: ;
    return;
}
