/* generated from CODE 1256 (gml_RoomCC_rm_mapview0_1256_Create), source start 5063960, end 5064004. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1256(GmVM* vm) {
    /* @5063960 load */
    /* @5063968 constant */
    /* @5063972 cmp */
    /* @5063976 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room49visited") == VAL(0)))) goto L_5063992;
    /* @5063980 call */
    GM_SITE(vm, 1256, 5063980);
    /* @5063988 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5063992: ;
    /* @5063992 constant */
    /* @5063996 store */
    GM_WRITE(vm, -1, "goto", VAL(46));
    L_5064004: ;
    return;
}
