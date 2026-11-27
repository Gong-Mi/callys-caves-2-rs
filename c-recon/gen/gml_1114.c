/* generated from CODE 1114 (gml_RoomCC_rm_map_1114_Create), source start 5057712, end 5057756. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1114(GmVM* vm) {
    /* @5057712 load */
    /* @5057720 constant */
    /* @5057724 cmp */
    /* @5057728 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room32visited") == VAL(0)))) goto L_5057744;
    /* @5057732 call */
    GM_SITE(vm, 1114, 5057732);
    /* @5057740 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5057744: ;
    /* @5057744 constant */
    /* @5057748 store */
    GM_WRITE(vm, -1, "goto", VAL(29));
    L_5057756: ;
    return;
}
