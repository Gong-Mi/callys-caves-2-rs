/* generated from CODE 1317 (gml_RoomCC_rm_mapview0_1317_Create), source start 5066644, end 5066688. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1317(GmVM* vm) {
    /* @5066644 load */
    /* @5066652 constant */
    /* @5066656 cmp */
    /* @5066660 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room79visited") == VAL(0)))) goto L_5066676;
    /* @5066664 call */
    GM_SITE(vm, 1317, 5066664);
    /* @5066672 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5066676: ;
    /* @5066676 constant */
    /* @5066680 store */
    GM_WRITE(vm, -1, "goto", VAL(78));
    L_5066688: ;
    return;
}
