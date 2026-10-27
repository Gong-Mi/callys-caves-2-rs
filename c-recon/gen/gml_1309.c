/* generated from CODE 1309 (gml_RoomCC_rm_mapview0_1309_Create), source start 5066292, end 5066336. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1309(GmVM* vm) {
    /* @5066292 load */
    /* @5066300 constant */
    /* @5066304 cmp */
    /* @5066308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level15avisited") == VAL(0)))) goto L_5066324;
    /* @5066312 call */
    GM_SITE(vm, 1309, 5066312);
    /* @5066320 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5066324: ;
    /* @5066324 constant */
    /* @5066328 store */
    GM_WRITE(vm, -1, "goto", VAL(22));
    L_5066336: ;
    return;
}
