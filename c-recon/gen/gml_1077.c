/* generated from CODE 1077 (gml_RoomCC_rm_map_1077_Create), source start 5056084, end 5056128. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1077(GmVM* vm) {
    /* @5056084 load */
    /* @5056092 constant */
    /* @5056096 cmp */
    /* @5056100 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room63visited") == VAL(0)))) goto L_5056116;
    /* @5056104 call */
    GM_SITE(vm, 1077, 5056104);
    /* @5056112 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5056116: ;
    /* @5056116 constant */
    /* @5056120 store */
    GM_WRITE(vm, -1, "goto", VAL(61));
    L_5056128: ;
    return;
}
