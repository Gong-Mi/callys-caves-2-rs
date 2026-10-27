/* generated from CODE 1331 (gml_RoomCC_rm_mapview0_1331_Create), source start 5067260, end 5067304. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1331(GmVM* vm) {
    /* @5067260 load */
    /* @5067268 constant */
    /* @5067272 cmp */
    /* @5067276 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room85visited") == VAL(0)))) goto L_5067292;
    /* @5067280 call */
    GM_SITE(vm, 1331, 5067280);
    /* @5067288 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5067292: ;
    /* @5067292 constant */
    /* @5067296 store */
    GM_WRITE(vm, -1, "goto", VAL(85));
    L_5067304: ;
    return;
}
