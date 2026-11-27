/* generated from CODE 1062 (gml_RoomCC_rm_map_1062_Create), source start 5055424, end 5055468. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1062(GmVM* vm) {
    /* @5055424 load */
    /* @5055432 constant */
    /* @5055436 cmp */
    /* @5055440 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level2visited") == VAL(0)))) goto L_5055456;
    /* @5055444 call */
    GM_SITE(vm, 1062, 5055444);
    /* @5055452 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5055456: ;
    /* @5055456 constant */
    /* @5055460 store */
    GM_WRITE(vm, -1, "goto", VAL(2));
    L_5055468: ;
    return;
}
