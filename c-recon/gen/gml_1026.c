/* generated from CODE 1026 (gml_RoomCC_rm_map_1026_Create), source start 5053840, end 5053884. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1026(GmVM* vm) {
    /* @5053840 load */
    /* @5053848 constant */
    /* @5053852 cmp */
    /* @5053856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room43visited") == VAL(0)))) goto L_5053872;
    /* @5053860 call */
    GM_SITE(vm, 1026, 5053860);
    /* @5053868 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5053872: ;
    /* @5053872 constant */
    /* @5053876 store */
    GM_WRITE(vm, -1, "goto", VAL(40));
    L_5053884: ;
    return;
}
