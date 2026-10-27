/* generated from CODE 1260 (gml_RoomCC_rm_mapview0_1260_Create), source start 5064136, end 5064180. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1260(GmVM* vm) {
    /* @5064136 load */
    /* @5064144 constant */
    /* @5064148 cmp */
    /* @5064152 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boss3visited") == VAL(0)))) goto L_5064168;
    /* @5064156 call */
    GM_SITE(vm, 1260, 5064156);
    /* @5064164 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5064168: ;
    /* @5064168 constant */
    /* @5064172 store */
    GM_WRITE(vm, -1, "goto", VAL(48));
    L_5064180: ;
    return;
}
