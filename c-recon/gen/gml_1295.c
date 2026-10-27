/* generated from CODE 1295 (gml_RoomCC_rm_mapview0_1295_Create), source start 5065676, end 5065720. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1295(GmVM* vm) {
    /* @5065676 load */
    /* @5065684 constant */
    /* @5065688 cmp */
    /* @5065692 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level11avisited") == VAL(0)))) goto L_5065708;
    /* @5065696 call */
    GM_SITE(vm, 1295, 5065696);
    /* @5065704 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5065708: ;
    /* @5065708 constant */
    /* @5065712 store */
    GM_WRITE(vm, -1, "goto", VAL(15));
    L_5065720: ;
    return;
}
