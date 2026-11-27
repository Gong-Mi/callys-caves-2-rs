/* generated from CODE 1031 (gml_RoomCC_rm_map_1031_Create), source start 5054060, end 5054104. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1031(GmVM* vm) {
    /* @5054060 load */
    /* @5054068 constant */
    /* @5054072 cmp */
    /* @5054076 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room44visited") == VAL(0)))) goto L_5054092;
    /* @5054080 call */
    GM_SITE(vm, 1031, 5054080);
    /* @5054088 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5054092: ;
    /* @5054092 constant */
    /* @5054096 store */
    GM_WRITE(vm, -1, "goto", VAL(41));
    L_5054104: ;
    return;
}
