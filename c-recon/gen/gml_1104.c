/* generated from CODE 1104 (gml_RoomCC_rm_map_1104_Create), source start 5057272, end 5057316. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1104(GmVM* vm) {
    /* @5057272 load */
    /* @5057280 constant */
    /* @5057284 cmp */
    /* @5057288 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room76visited") == VAL(0)))) goto L_5057304;
    /* @5057292 call */
    GM_SITE(vm, 1104, 5057292);
    /* @5057300 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5057304: ;
    /* @5057304 constant */
    /* @5057308 store */
    GM_WRITE(vm, -1, "goto", VAL(75));
    L_5057316: ;
    return;
}
