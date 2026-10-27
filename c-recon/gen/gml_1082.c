/* generated from CODE 1082 (gml_RoomCC_rm_map_1082_Create), source start 5056304, end 5056348. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1082(GmVM* vm) {
    /* @5056304 load */
    /* @5056312 constant */
    /* @5056316 cmp */
    /* @5056320 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level9avisited") == VAL(0)))) goto L_5056336;
    /* @5056324 call */
    GM_SITE(vm, 1082, 5056324);
    /* @5056332 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5056336: ;
    /* @5056336 constant */
    /* @5056340 store */
    GM_WRITE(vm, -1, "goto", VAL(12));
    L_5056348: ;
    return;
}
