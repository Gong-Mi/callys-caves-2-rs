/* generated from CODE 1298 (gml_RoomCC_rm_mapview0_1298_Create), source start 5065808, end 5065852. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1298(GmVM* vm) {
    /* @5065808 load */
    /* @5065816 constant */
    /* @5065820 cmp */
    /* @5065824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room69visited") == VAL(0)))) goto L_5065840;
    /* @5065828 call */
    GM_SITE(vm, 1298, 5065828);
    /* @5065836 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5065840: ;
    /* @5065840 constant */
    /* @5065844 store */
    GM_WRITE(vm, -1, "goto", VAL(68));
    L_5065852: ;
    return;
}
