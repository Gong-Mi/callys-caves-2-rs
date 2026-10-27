/* generated from CODE 1172 (gml_RoomCC_rm_mapview3_1172_Create), source start 5060264, end 5060308. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1172(GmVM* vm) {
    /* @5060264 load */
    /* @5060272 constant */
    /* @5060276 cmp */
    /* @5060280 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level7visited") == VAL(0)))) goto L_5060296;
    /* @5060284 call */
    GM_SITE(vm, 1172, 5060284);
    /* @5060292 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5060296: ;
    /* @5060296 constant */
    /* @5060300 store */
    GM_WRITE(vm, -1, "goto", VAL(7));
    L_5060308: ;
    return;
}
