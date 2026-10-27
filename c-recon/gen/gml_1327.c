/* generated from CODE 1327 (gml_RoomCC_rm_mapview0_1327_Create), source start 5067084, end 5067128. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1327(GmVM* vm) {
    /* @5067084 load */
    /* @5067092 constant */
    /* @5067096 cmp */
    /* @5067100 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room83visited") == VAL(0)))) goto L_5067116;
    /* @5067104 call */
    GM_SITE(vm, 1327, 5067104);
    /* @5067112 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5067116: ;
    /* @5067116 constant */
    /* @5067120 store */
    GM_WRITE(vm, -1, "goto", VAL(83));
    L_5067128: ;
    return;
}
