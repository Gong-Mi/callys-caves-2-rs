/* generated from CODE 1244 (gml_RoomCC_rm_mapview0_1244_Create), source start 5063432, end 5063476. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1244(GmVM* vm) {
    /* @5063432 load */
    /* @5063440 constant */
    /* @5063444 cmp */
    /* @5063448 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room43visited") == VAL(0)))) goto L_5063464;
    /* @5063452 call */
    GM_SITE(vm, 1244, 5063452);
    /* @5063460 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5063464: ;
    /* @5063464 constant */
    /* @5063468 store */
    GM_WRITE(vm, -1, "goto", VAL(40));
    L_5063476: ;
    return;
}
