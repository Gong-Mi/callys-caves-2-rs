/* generated from CODE 1221 (gml_RoomCC_rm_mapview3_1221_Create), source start 5062420, end 5062464. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1221(GmVM* vm) {
    /* @5062420 load */
    /* @5062428 constant */
    /* @5062432 cmp */
    /* @5062436 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room84visited") == VAL(0)))) goto L_5062452;
    /* @5062440 call */
    GM_SITE(vm, 1221, 5062440);
    /* @5062448 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5062452: ;
    /* @5062452 constant */
    /* @5062456 store */
    GM_WRITE(vm, -1, "goto", VAL(84));
    L_5062464: ;
    return;
}
