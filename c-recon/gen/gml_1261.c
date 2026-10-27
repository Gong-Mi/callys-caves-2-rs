/* generated from CODE 1261 (gml_RoomCC_rm_mapview0_1261_Create), source start 5064180, end 5064224. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1261(GmVM* vm) {
    /* @5064180 load */
    /* @5064188 constant */
    /* @5064192 cmp */
    /* @5064196 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room100visited") == VAL(0)))) goto L_5064212;
    /* @5064200 call */
    GM_SITE(vm, 1261, 5064200);
    /* @5064208 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5064212: ;
    /* @5064212 constant */
    /* @5064216 store */
    GM_WRITE(vm, -1, "goto", VAL(100));
    L_5064224: ;
    return;
}
