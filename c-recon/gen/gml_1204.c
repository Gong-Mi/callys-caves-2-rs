/* generated from CODE 1204 (gml_RoomCC_rm_mapview3_1204_Create), source start 5061672, end 5061716. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1204(GmVM* vm) {
    /* @5061672 load */
    /* @5061680 constant */
    /* @5061684 cmp */
    /* @5061688 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room76visited") == VAL(0)))) goto L_5061704;
    /* @5061692 call */
    GM_SITE(vm, 1204, 5061692);
    /* @5061700 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5061704: ;
    /* @5061704 constant */
    /* @5061708 store */
    GM_WRITE(vm, -1, "goto", VAL(75));
    L_5061716: ;
    return;
}
