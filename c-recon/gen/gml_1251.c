/* generated from CODE 1251 (gml_RoomCC_rm_mapview0_1251_Create), source start 5063740, end 5063784. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1251(GmVM* vm) {
    /* @5063740 load */
    /* @5063748 constant */
    /* @5063752 cmp */
    /* @5063756 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room46visited") == VAL(0)))) goto L_5063772;
    /* @5063760 call */
    GM_SITE(vm, 1251, 5063760);
    /* @5063768 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5063772: ;
    /* @5063772 constant */
    /* @5063776 store */
    GM_WRITE(vm, -1, "goto", VAL(43));
    L_5063784: ;
    return;
}
