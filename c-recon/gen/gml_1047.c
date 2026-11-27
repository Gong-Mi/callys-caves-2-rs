/* generated from CODE 1047 (gml_RoomCC_rm_map_1047_Create), source start 5054764, end 5054808. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1047(GmVM* vm) {
    /* @5054764 load */
    /* @5054772 constant */
    /* @5054776 cmp */
    /* @5054780 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room49visited") == VAL(0)))) goto L_5054796;
    /* @5054784 call */
    GM_SITE(vm, 1047, 5054784);
    /* @5054792 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5054796: ;
    /* @5054796 constant */
    /* @5054800 store */
    GM_WRITE(vm, -1, "goto", VAL(46));
    L_5054808: ;
    return;
}
