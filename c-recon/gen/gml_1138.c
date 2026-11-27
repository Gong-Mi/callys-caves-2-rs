/* generated from CODE 1138 (gml_RoomCC_rm_mapview3_1138_Create), source start 5058768, end 5058812. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1138(GmVM* vm) {
    /* @5058768 load */
    /* @5058776 constant */
    /* @5058780 cmp */
    /* @5058784 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room95visited") == VAL(0)))) goto L_5058800;
    /* @5058788 call */
    GM_SITE(vm, 1138, 5058788);
    /* @5058796 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5058800: ;
    /* @5058800 constant */
    /* @5058804 store */
    GM_WRITE(vm, -1, "goto", VAL(95));
    L_5058812: ;
    return;
}
