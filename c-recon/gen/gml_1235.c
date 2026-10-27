/* generated from CODE 1235 (gml_RoomCC_rm_mapview3_1235_Create), source start 5063036, end 5063080. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1235(GmVM* vm) {
    /* @5063036 load */
    /* @5063044 constant */
    /* @5063048 cmp */
    /* @5063052 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room90visited") == VAL(0)))) goto L_5063068;
    /* @5063056 call */
    GM_SITE(vm, 1235, 5063056);
    /* @5063064 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5063068: ;
    /* @5063068 constant */
    /* @5063072 store */
    GM_WRITE(vm, -1, "goto", VAL(90));
    L_5063080: ;
    return;
}
