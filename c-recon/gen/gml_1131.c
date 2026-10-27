/* generated from CODE 1131 (gml_RoomCC_rm_map_1131_Create), source start 5058460, end 5058504. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1131(GmVM* vm) {
    /* @5058460 load */
    /* @5058468 constant */
    /* @5058472 cmp */
    /* @5058476 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "levelchallenge4visited") == VAL(0)))) goto L_5058492;
    /* @5058480 call */
    GM_SITE(vm, 1131, 5058480);
    /* @5058488 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5058492: ;
    /* @5058492 constant */
    /* @5058496 store */
    GM_WRITE(vm, -1, "goto", VAL(108));
    L_5058504: ;
    return;
}
