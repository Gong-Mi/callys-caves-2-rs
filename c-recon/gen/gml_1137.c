/* generated from CODE 1137 (gml_RoomCC_rm_mapview3_1137_Create), source start 5058724, end 5058768. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1137(GmVM* vm) {
    /* @5058724 load */
    /* @5058732 constant */
    /* @5058736 cmp */
    /* @5058740 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room45visited") == VAL(0)))) goto L_5058756;
    /* @5058744 call */
    GM_SITE(vm, 1137, 5058744);
    /* @5058752 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5058756: ;
    /* @5058756 constant */
    /* @5058760 store */
    GM_WRITE(vm, -1, "goto", VAL(42));
    L_5058768: ;
    return;
}
