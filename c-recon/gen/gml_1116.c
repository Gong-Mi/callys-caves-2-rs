/* generated from CODE 1116 (gml_RoomCC_rm_map_1116_Create), source start 5057800, end 5057844. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1116(GmVM* vm) {
    /* @5057800 load */
    /* @5057808 constant */
    /* @5057812 cmp */
    /* @5057816 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room33visited") == VAL(0)))) goto L_5057832;
    /* @5057820 call */
    GM_SITE(vm, 1116, 5057820);
    /* @5057828 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5057832: ;
    /* @5057832 constant */
    /* @5057836 store */
    GM_WRITE(vm, -1, "goto", VAL(30));
    L_5057844: ;
    return;
}
