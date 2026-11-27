/* generated from CODE 1179 (gml_RoomCC_rm_mapview3_1179_Create), source start 5060572, end 5060616. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1179(GmVM* vm) {
    /* @5060572 load */
    /* @5060580 constant */
    /* @5060584 cmp */
    /* @5060588 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room64visited") == VAL(0)))) goto L_5060604;
    /* @5060592 call */
    GM_SITE(vm, 1179, 5060592);
    /* @5060600 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5060604: ;
    /* @5060604 constant */
    /* @5060608 store */
    GM_WRITE(vm, -1, "goto", VAL(62));
    L_5060616: ;
    return;
}
