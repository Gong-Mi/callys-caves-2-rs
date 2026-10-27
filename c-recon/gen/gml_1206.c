/* generated from CODE 1206 (gml_RoomCC_rm_mapview3_1206_Create), source start 5061760, end 5061804. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1206(GmVM* vm) {
    /* @5061760 load */
    /* @5061768 constant */
    /* @5061772 cmp */
    /* @5061776 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room77visited") == VAL(0)))) goto L_5061792;
    /* @5061780 call */
    GM_SITE(vm, 1206, 5061780);
    /* @5061788 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5061792: ;
    /* @5061792 constant */
    /* @5061796 store */
    GM_WRITE(vm, -1, "goto", VAL(76));
    L_5061804: ;
    return;
}
