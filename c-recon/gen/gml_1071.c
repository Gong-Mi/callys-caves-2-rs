/* generated from CODE 1071 (gml_RoomCC_rm_map_1071_Create), source start 5055820, end 5055864. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1071(GmVM* vm) {
    /* @5055820 load */
    /* @5055828 constant */
    /* @5055832 cmp */
    /* @5055836 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room60visited") == VAL(0)))) goto L_5055852;
    /* @5055840 call */
    GM_SITE(vm, 1071, 5055840);
    /* @5055848 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5055852: ;
    /* @5055852 constant */
    /* @5055856 store */
    GM_WRITE(vm, -1, "goto", VAL(58));
    L_5055864: ;
    return;
}
