/* generated from CODE 1250 (gml_RoomCC_rm_mapview0_1250_Create), source start 5063696, end 5063740. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1250(GmVM* vm) {
    /* @5063696 load */
    /* @5063704 constant */
    /* @5063708 cmp */
    /* @5063712 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room93visited") == VAL(0)))) goto L_5063728;
    /* @5063716 call */
    GM_SITE(vm, 1250, 5063716);
    /* @5063724 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5063728: ;
    /* @5063728 constant */
    /* @5063732 store */
    GM_WRITE(vm, -1, "goto", VAL(93));
    L_5063740: ;
    return;
}
