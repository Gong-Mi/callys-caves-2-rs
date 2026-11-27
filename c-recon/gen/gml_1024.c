/* generated from CODE 1024 (gml_RoomCC_rm_map_1024_Create), source start 5053752, end 5053796. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1024(GmVM* vm) {
    /* @5053752 load */
    /* @5053760 constant */
    /* @5053764 cmp */
    /* @5053768 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room94visited") == VAL(0)))) goto L_5053784;
    /* @5053772 call */
    GM_SITE(vm, 1024, 5053772);
    /* @5053780 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5053784: ;
    /* @5053784 constant */
    /* @5053788 store */
    GM_WRITE(vm, -1, "goto", VAL(94));
    L_5053796: ;
    return;
}
