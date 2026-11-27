/* generated from CODE 1151 (gml_RoomCC_rm_mapview3_1151_Create), source start 5059340, end 5059384. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1151(GmVM* vm) {
    /* @5059340 load */
    /* @5059348 constant */
    /* @5059352 cmp */
    /* @5059356 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boss3visited") == VAL(0)))) goto L_5059372;
    /* @5059360 call */
    GM_SITE(vm, 1151, 5059360);
    /* @5059368 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5059372: ;
    /* @5059372 constant */
    /* @5059376 store */
    GM_WRITE(vm, -1, "goto", VAL(48));
    L_5059384: ;
    return;
}
