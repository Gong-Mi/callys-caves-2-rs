/* generated from CODE 1084 (gml_RoomCC_rm_map_1084_Create), source start 5056392, end 5056436. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1084(GmVM* vm) {
    /* @5056392 load */
    /* @5056400 constant */
    /* @5056404 cmp */
    /* @5056408 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room66visited") == VAL(0)))) goto L_5056424;
    /* @5056412 call */
    GM_SITE(vm, 1084, 5056412);
    /* @5056420 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5056424: ;
    /* @5056424 constant */
    /* @5056428 store */
    GM_WRITE(vm, -1, "goto", VAL(65));
    L_5056436: ;
    return;
}
