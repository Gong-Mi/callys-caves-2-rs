/* generated from CODE 1180 (gml_RoomCC_rm_mapview3_1180_Create), source start 5060616, end 5060660. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1180(GmVM* vm) {
    /* @5060616 load */
    /* @5060624 constant */
    /* @5060628 cmp */
    /* @5060632 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level9visited") == VAL(0)))) goto L_5060648;
    /* @5060636 call */
    GM_SITE(vm, 1180, 5060636);
    /* @5060644 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5060648: ;
    /* @5060648 constant */
    /* @5060652 store */
    GM_WRITE(vm, -1, "goto", VAL(11));
    L_5060660: ;
    return;
}
