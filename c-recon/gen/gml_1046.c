/* generated from CODE 1046 (gml_RoomCC_rm_map_1046_Create), source start 5054720, end 5054764. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1046(GmVM* vm) {
    /* @5054720 load */
    /* @5054728 constant */
    /* @5054732 cmp */
    /* @5054736 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room97visited") == VAL(0)))) goto L_5054752;
    /* @5054740 call */
    GM_SITE(vm, 1046, 5054740);
    /* @5054748 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5054752: ;
    /* @5054752 constant */
    /* @5054756 store */
    GM_WRITE(vm, -1, "goto", VAL(97));
    L_5054764: ;
    return;
}
