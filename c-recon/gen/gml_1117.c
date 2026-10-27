/* generated from CODE 1117 (gml_RoomCC_rm_map_1117_Create), source start 5057844, end 5057888. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1117(GmVM* vm) {
    /* @5057844 load */
    /* @5057852 constant */
    /* @5057856 cmp */
    /* @5057860 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boss5visited") == VAL(0)))) goto L_5057876;
    /* @5057864 call */
    GM_SITE(vm, 1117, 5057864);
    /* @5057872 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5057876: ;
    /* @5057876 constant */
    /* @5057880 store */
    GM_WRITE(vm, -1, "goto", VAL(82));
    L_5057888: ;
    return;
}
