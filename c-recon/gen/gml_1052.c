/* generated from CODE 1052 (gml_RoomCC_rm_map_1052_Create), source start 5054984, end 5055028. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1052(GmVM* vm) {
    /* @5054984 load */
    /* @5054992 constant */
    /* @5054996 cmp */
    /* @5055000 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room100visited") == VAL(0)))) goto L_5055016;
    /* @5055004 call */
    GM_SITE(vm, 1052, 5055004);
    /* @5055012 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5055016: ;
    /* @5055016 constant */
    /* @5055020 store */
    GM_WRITE(vm, -1, "goto", VAL(100));
    L_5055028: ;
    return;
}
