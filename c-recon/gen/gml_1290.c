/* generated from CODE 1290 (gml_RoomCC_rm_mapview0_1290_Create), source start 5065456, end 5065500. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1290(GmVM* vm) {
    /* @5065456 load */
    /* @5065464 constant */
    /* @5065468 cmp */
    /* @5065472 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level9avisited") == VAL(0)))) goto L_5065488;
    /* @5065476 call */
    GM_SITE(vm, 1290, 5065476);
    /* @5065484 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5065488: ;
    /* @5065488 constant */
    /* @5065492 store */
    GM_WRITE(vm, -1, "goto", VAL(12));
    L_5065500: ;
    return;
}
