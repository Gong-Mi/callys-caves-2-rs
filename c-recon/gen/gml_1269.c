/* generated from CODE 1269 (gml_RoomCC_rm_mapview0_1269_Create), source start 5064532, end 5064576. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1269(GmVM* vm) {
    /* @5064532 load */
    /* @5064540 constant */
    /* @5064544 cmp */
    /* @5064548 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room55visited") == VAL(0)))) goto L_5064564;
    /* @5064552 call */
    GM_SITE(vm, 1269, 5064552);
    /* @5064560 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5064564: ;
    /* @5064564 constant */
    /* @5064568 store */
    GM_WRITE(vm, -1, "goto", VAL(53));
    L_5064576: ;
    return;
}
