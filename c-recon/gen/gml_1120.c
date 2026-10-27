/* generated from CODE 1120 (gml_RoomCC_rm_map_1120_Create), source start 5057976, end 5058020. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1120(GmVM* vm) {
    /* @5057976 load */
    /* @5057984 constant */
    /* @5057988 cmp */
    /* @5057992 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room35visited") == VAL(0)))) goto L_5058008;
    /* @5057996 call */
    GM_SITE(vm, 1120, 5057996);
    /* @5058004 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5058008: ;
    /* @5058008 constant */
    /* @5058012 store */
    GM_WRITE(vm, -1, "goto", VAL(32));
    L_5058020: ;
    return;
}
