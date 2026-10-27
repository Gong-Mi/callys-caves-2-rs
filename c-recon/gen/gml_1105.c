/* generated from CODE 1105 (gml_RoomCC_rm_map_1105_Create), source start 5057316, end 5057360. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1105(GmVM* vm) {
    /* @5057316 load */
    /* @5057324 constant */
    /* @5057328 cmp */
    /* @5057332 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level16avisited") == VAL(0)))) goto L_5057348;
    /* @5057336 call */
    GM_SITE(vm, 1105, 5057336);
    /* @5057344 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5057348: ;
    /* @5057348 constant */
    /* @5057352 store */
    GM_WRITE(vm, -1, "goto", VAL(24));
    L_5057360: ;
    return;
}
