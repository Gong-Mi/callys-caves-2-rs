/* generated from CODE 1335 (gml_RoomCC_rm_mapview0_1335_Create), source start 5067436, end 5067480. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1335(GmVM* vm) {
    /* @5067436 load */
    /* @5067444 constant */
    /* @5067448 cmp */
    /* @5067452 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room87visited") == VAL(0)))) goto L_5067468;
    /* @5067456 call */
    GM_SITE(vm, 1335, 5067456);
    /* @5067464 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5067468: ;
    /* @5067468 constant */
    /* @5067472 store */
    GM_WRITE(vm, -1, "goto", VAL(87));
    L_5067480: ;
    return;
}
