/* generated from CODE 1113 (gml_RoomCC_rm_map_1113_Create), source start 5057668, end 5057712. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1113(GmVM* vm) {
    /* @5057668 load */
    /* @5057676 constant */
    /* @5057680 cmp */
    /* @5057684 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room81visited") == VAL(0)))) goto L_5057700;
    /* @5057688 call */
    GM_SITE(vm, 1113, 5057688);
    /* @5057696 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5057700: ;
    /* @5057700 constant */
    /* @5057704 store */
    GM_WRITE(vm, -1, "goto", VAL(80));
    L_5057712: ;
    return;
}
