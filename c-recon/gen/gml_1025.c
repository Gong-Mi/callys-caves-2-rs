/* generated from CODE 1025 (gml_RoomCC_rm_map_1025_Create), source start 5053796, end 5053840. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1025(GmVM* vm) {
    /* @5053796 load */
    /* @5053804 constant */
    /* @5053808 cmp */
    /* @5053812 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room42visited") == VAL(0)))) goto L_5053828;
    /* @5053816 call */
    GM_SITE(vm, 1025, 5053816);
    /* @5053824 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5053828: ;
    /* @5053828 constant */
    /* @5053832 store */
    GM_WRITE(vm, -1, "goto", VAL(39));
    L_5053840: ;
    return;
}
