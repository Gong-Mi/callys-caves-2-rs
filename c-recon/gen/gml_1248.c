/* generated from CODE 1248 (gml_RoomCC_rm_mapview0_1248_Create), source start 5063608, end 5063652. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1248(GmVM* vm) {
    /* @5063608 load */
    /* @5063616 constant */
    /* @5063620 cmp */
    /* @5063624 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room92visited") == VAL(0)))) goto L_5063640;
    /* @5063628 call */
    GM_SITE(vm, 1248, 5063628);
    /* @5063636 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5063640: ;
    /* @5063640 constant */
    /* @5063644 store */
    GM_WRITE(vm, -1, "goto", VAL(92));
    L_5063652: ;
    return;
}
