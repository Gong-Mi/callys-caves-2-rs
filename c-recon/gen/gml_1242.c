/* generated from CODE 1242 (gml_RoomCC_rm_mapview0_1242_Create), source start 5063344, end 5063388. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1242(GmVM* vm) {
    /* @5063344 load */
    /* @5063352 constant */
    /* @5063356 cmp */
    /* @5063360 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room94visited") == VAL(0)))) goto L_5063376;
    /* @5063364 call */
    GM_SITE(vm, 1242, 5063364);
    /* @5063372 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5063376: ;
    /* @5063376 constant */
    /* @5063380 store */
    GM_WRITE(vm, -1, "goto", VAL(94));
    L_5063388: ;
    return;
}
