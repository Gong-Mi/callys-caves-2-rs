/* generated from CODE 1275 (gml_RoomCC_rm_mapview0_1275_Create), source start 5064796, end 5064840. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1275(GmVM* vm) {
    /* @5064796 load */
    /* @5064804 constant */
    /* @5064808 cmp */
    /* @5064812 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room58visited") == VAL(0)))) goto L_5064828;
    /* @5064816 call */
    GM_SITE(vm, 1275, 5064816);
    /* @5064824 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5064828: ;
    /* @5064828 constant */
    /* @5064832 store */
    GM_WRITE(vm, -1, "goto", VAL(56));
    L_5064840: ;
    return;
}
