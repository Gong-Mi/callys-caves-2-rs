/* generated from CODE 1243 (gml_RoomCC_rm_mapview0_1243_Create), source start 5063388, end 5063432. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1243(GmVM* vm) {
    /* @5063388 load */
    /* @5063396 constant */
    /* @5063400 cmp */
    /* @5063404 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room42visited") == VAL(0)))) goto L_5063420;
    /* @5063408 call */
    GM_SITE(vm, 1243, 5063408);
    /* @5063416 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5063420: ;
    /* @5063420 constant */
    /* @5063424 store */
    GM_WRITE(vm, -1, "goto", VAL(39));
    L_5063432: ;
    return;
}
