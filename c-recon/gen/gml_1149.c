/* generated from CODE 1149 (gml_RoomCC_rm_mapview3_1149_Create), source start 5059252, end 5059296. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1149(GmVM* vm) {
    /* @5059252 load */
    /* @5059260 constant */
    /* @5059264 cmp */
    /* @5059268 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room50visited") == VAL(0)))) goto L_5059284;
    /* @5059272 call */
    GM_SITE(vm, 1149, 5059272);
    /* @5059280 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5059284: ;
    /* @5059284 constant */
    /* @5059288 store */
    GM_WRITE(vm, -1, "goto", VAL(47));
    L_5059296: ;
    return;
}
