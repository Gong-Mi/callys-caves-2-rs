/* generated from CODE 1258 (gml_RoomCC_rm_mapview0_1258_Create), source start 5064048, end 5064092. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1258(GmVM* vm) {
    /* @5064048 load */
    /* @5064056 constant */
    /* @5064060 cmp */
    /* @5064064 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room50visited") == VAL(0)))) goto L_5064080;
    /* @5064068 call */
    GM_SITE(vm, 1258, 5064068);
    /* @5064076 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5064080: ;
    /* @5064080 constant */
    /* @5064084 store */
    GM_WRITE(vm, -1, "goto", VAL(47));
    L_5064092: ;
    return;
}
