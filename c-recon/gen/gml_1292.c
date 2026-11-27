/* generated from CODE 1292 (gml_RoomCC_rm_mapview0_1292_Create), source start 5065544, end 5065588. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1292(GmVM* vm) {
    /* @5065544 load */
    /* @5065552 constant */
    /* @5065556 cmp */
    /* @5065560 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room66visited") == VAL(0)))) goto L_5065576;
    /* @5065564 call */
    GM_SITE(vm, 1292, 5065564);
    /* @5065572 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5065576: ;
    /* @5065576 constant */
    /* @5065580 store */
    GM_WRITE(vm, -1, "goto", VAL(65));
    L_5065588: ;
    return;
}
