/* generated from CODE 1043 (gml_RoomCC_rm_map_1043_Create), source start 5054588, end 5054632. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1043(GmVM* vm) {
    /* @5054588 load */
    /* @5054596 constant */
    /* @5054600 cmp */
    /* @5054604 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room103visited") == VAL(0)))) goto L_5054620;
    /* @5054608 call */
    GM_SITE(vm, 1043, 5054608);
    /* @5054616 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5054620: ;
    /* @5054620 constant */
    /* @5054624 store */
    GM_WRITE(vm, -1, "goto", VAL(103));
    L_5054632: ;
    return;
}
