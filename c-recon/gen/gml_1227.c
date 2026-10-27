/* generated from CODE 1227 (gml_RoomCC_rm_mapview3_1227_Create), source start 5062684, end 5062728. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1227(GmVM* vm) {
    /* @5062684 load */
    /* @5062692 constant */
    /* @5062696 cmp */
    /* @5062700 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room87visited") == VAL(0)))) goto L_5062716;
    /* @5062704 call */
    GM_SITE(vm, 1227, 5062704);
    /* @5062712 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5062716: ;
    /* @5062716 constant */
    /* @5062720 store */
    GM_WRITE(vm, -1, "goto", VAL(87));
    L_5062728: ;
    return;
}
