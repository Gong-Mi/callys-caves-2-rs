/* generated from CODE 1108 (gml_RoomCC_rm_map_1108_Create), source start 5057448, end 5057492. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1108(GmVM* vm) {
    /* @5057448 load */
    /* @5057456 constant */
    /* @5057460 cmp */
    /* @5057464 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level17avisited") == VAL(0)))) goto L_5057480;
    /* @5057468 call */
    GM_SITE(vm, 1108, 5057468);
    /* @5057476 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5057480: ;
    /* @5057480 constant */
    /* @5057484 store */
    GM_WRITE(vm, -1, "goto", VAL(26));
    L_5057492: ;
    return;
}
