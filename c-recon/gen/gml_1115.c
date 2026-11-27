/* generated from CODE 1115 (gml_RoomCC_rm_map_1115_Create), source start 5057756, end 5057800. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1115(GmVM* vm) {
    /* @5057756 load */
    /* @5057764 constant */
    /* @5057768 cmp */
    /* @5057772 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room82visited") == VAL(0)))) goto L_5057788;
    /* @5057776 call */
    GM_SITE(vm, 1115, 5057776);
    /* @5057784 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5057788: ;
    /* @5057788 constant */
    /* @5057792 store */
    GM_WRITE(vm, -1, "goto", VAL(81));
    L_5057800: ;
    return;
}
