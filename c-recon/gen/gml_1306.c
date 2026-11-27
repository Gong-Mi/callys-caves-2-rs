/* generated from CODE 1306 (gml_RoomCC_rm_mapview0_1306_Create), source start 5066160, end 5066204. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1306(GmVM* vm) {
    /* @5066160 load */
    /* @5066168 constant */
    /* @5066172 cmp */
    /* @5066176 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room73visited") == VAL(0)))) goto L_5066192;
    /* @5066180 call */
    GM_SITE(vm, 1306, 5066180);
    /* @5066188 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5066192: ;
    /* @5066192 constant */
    /* @5066196 store */
    GM_WRITE(vm, -1, "goto", VAL(72));
    L_5066204: ;
    return;
}
