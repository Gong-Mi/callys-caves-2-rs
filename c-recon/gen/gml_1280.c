/* generated from CODE 1280 (gml_RoomCC_rm_mapview0_1280_Create), source start 5065016, end 5065060. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1280(GmVM* vm) {
    /* @5065016 load */
    /* @5065024 constant */
    /* @5065028 cmp */
    /* @5065032 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level7visited") == VAL(0)))) goto L_5065048;
    /* @5065036 call */
    GM_SITE(vm, 1280, 5065036);
    /* @5065044 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5065048: ;
    /* @5065048 constant */
    /* @5065052 store */
    GM_WRITE(vm, -1, "goto", VAL(7));
    L_5065060: ;
    return;
}
