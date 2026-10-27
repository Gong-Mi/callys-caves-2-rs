/* generated from CODE 1318 (gml_RoomCC_rm_mapview0_1318_Create), source start 5066688, end 5066732. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1318(GmVM* vm) {
    /* @5066688 load */
    /* @5066696 constant */
    /* @5066700 cmp */
    /* @5066704 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boss2visited") == VAL(0)))) goto L_5066720;
    /* @5066708 call */
    GM_SITE(vm, 1318, 5066708);
    /* @5066716 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5066720: ;
    /* @5066720 constant */
    /* @5066724 store */
    GM_WRITE(vm, -1, "goto", VAL(27));
    L_5066732: ;
    return;
}
