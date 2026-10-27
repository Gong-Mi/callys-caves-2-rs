/* generated from CODE 1301 (gml_RoomCC_rm_mapview0_1301_Create), source start 5065940, end 5065984. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1301(GmVM* vm) {
    /* @5065940 load */
    /* @5065948 constant */
    /* @5065952 cmp */
    /* @5065956 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level13avisited") == VAL(0)))) goto L_5065972;
    /* @5065960 call */
    GM_SITE(vm, 1301, 5065960);
    /* @5065968 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5065972: ;
    /* @5065972 constant */
    /* @5065976 store */
    GM_WRITE(vm, -1, "goto", VAL(18));
    L_5065984: ;
    return;
}
