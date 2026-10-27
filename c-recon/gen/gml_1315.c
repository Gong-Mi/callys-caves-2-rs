/* generated from CODE 1315 (gml_RoomCC_rm_mapview0_1315_Create), source start 5066556, end 5066600. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1315(GmVM* vm) {
    /* @5066556 load */
    /* @5066564 constant */
    /* @5066568 cmp */
    /* @5066572 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level17visited") == VAL(0)))) goto L_5066588;
    /* @5066576 call */
    GM_SITE(vm, 1315, 5066576);
    /* @5066584 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5066588: ;
    /* @5066588 constant */
    /* @5066592 store */
    GM_WRITE(vm, -1, "goto", VAL(25));
    L_5066600: ;
    return;
}
