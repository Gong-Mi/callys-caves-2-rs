/* generated from CODE 1081 (gml_RoomCC_rm_map_1081_Create), source start 5056260, end 5056304. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1081(GmVM* vm) {
    /* @5056260 load */
    /* @5056268 constant */
    /* @5056272 cmp */
    /* @5056276 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room65visited") == VAL(0)))) goto L_5056292;
    /* @5056280 call */
    GM_SITE(vm, 1081, 5056280);
    /* @5056288 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5056292: ;
    /* @5056292 constant */
    /* @5056296 store */
    GM_WRITE(vm, -1, "goto", VAL(63));
    L_5056304: ;
    return;
}
