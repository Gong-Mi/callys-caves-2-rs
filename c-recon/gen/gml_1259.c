/* generated from CODE 1259 (gml_RoomCC_rm_mapview0_1259_Create), source start 5064092, end 5064136. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1259(GmVM* vm) {
    /* @5064092 load */
    /* @5064100 constant */
    /* @5064104 cmp */
    /* @5064108 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room99visited") == VAL(0)))) goto L_5064124;
    /* @5064112 call */
    GM_SITE(vm, 1259, 5064112);
    /* @5064120 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5064124: ;
    /* @5064124 constant */
    /* @5064128 store */
    GM_WRITE(vm, -1, "goto", VAL(99));
    L_5064136: ;
    return;
}
