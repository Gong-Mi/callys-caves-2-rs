/* generated from CODE 1220 (gml_RoomCC_rm_mapview3_1220_Create), source start 5062376, end 5062420. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1220(GmVM* vm) {
    /* @5062376 load */
    /* @5062384 constant */
    /* @5062388 cmp */
    /* @5062392 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room35visited") == VAL(0)))) goto L_5062408;
    /* @5062396 call */
    GM_SITE(vm, 1220, 5062396);
    /* @5062404 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5062408: ;
    /* @5062408 constant */
    /* @5062412 store */
    GM_WRITE(vm, -1, "goto", VAL(32));
    L_5062420: ;
    return;
}
