/* generated from CODE 1194 (gml_RoomCC_rm_mapview3_1194_Create), source start 5061232, end 5061276. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1194(GmVM* vm) {
    /* @5061232 load */
    /* @5061240 constant */
    /* @5061244 cmp */
    /* @5061248 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room71visited") == VAL(0)))) goto L_5061264;
    /* @5061252 call */
    GM_SITE(vm, 1194, 5061252);
    /* @5061260 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5061264: ;
    /* @5061264 constant */
    /* @5061268 store */
    GM_WRITE(vm, -1, "goto", VAL(70));
    L_5061276: ;
    return;
}
