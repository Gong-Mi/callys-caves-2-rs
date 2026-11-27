/* generated from CODE 1177 (gml_RoomCC_rm_mapview3_1177_Create), source start 5060484, end 5060528. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1177(GmVM* vm) {
    /* @5060484 load */
    /* @5060492 constant */
    /* @5060496 cmp */
    /* @5060500 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room63visited") == VAL(0)))) goto L_5060516;
    /* @5060504 call */
    GM_SITE(vm, 1177, 5060504);
    /* @5060512 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5060516: ;
    /* @5060516 constant */
    /* @5060520 store */
    GM_WRITE(vm, -1, "goto", VAL(61));
    L_5060528: ;
    return;
}
