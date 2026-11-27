/* generated from CODE 1188 (gml_RoomCC_rm_mapview3_1188_Create), source start 5060968, end 5061012. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1188(GmVM* vm) {
    /* @5060968 load */
    /* @5060976 constant */
    /* @5060980 cmp */
    /* @5060984 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room68visited") == VAL(0)))) goto L_5061000;
    /* @5060988 call */
    GM_SITE(vm, 1188, 5060988);
    /* @5060996 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5061000: ;
    /* @5061000 constant */
    /* @5061004 store */
    GM_WRITE(vm, -1, "goto", VAL(67));
    L_5061012: ;
    return;
}
