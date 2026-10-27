/* generated from CODE 1183 (gml_RoomCC_rm_mapview3_1183_Create), source start 5060748, end 5060792. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1183(GmVM* vm) {
    /* @5060748 load */
    /* @5060756 constant */
    /* @5060760 cmp */
    /* @5060764 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level10visited") == VAL(0)))) goto L_5060780;
    /* @5060768 call */
    GM_SITE(vm, 1183, 5060768);
    /* @5060776 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5060780: ;
    /* @5060780 constant */
    /* @5060784 store */
    GM_WRITE(vm, -1, "goto", VAL(13));
    L_5060792: ;
    return;
}
