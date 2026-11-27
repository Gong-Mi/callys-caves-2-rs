/* generated from CODE 1305 (gml_RoomCC_rm_mapview0_1305_Create), source start 5066116, end 5066160. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1305(GmVM* vm) {
    /* @5066116 load */
    /* @5066124 constant */
    /* @5066128 cmp */
    /* @5066132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level14avisited") == VAL(0)))) goto L_5066148;
    /* @5066136 call */
    GM_SITE(vm, 1305, 5066136);
    /* @5066144 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5066148: ;
    /* @5066148 constant */
    /* @5066152 store */
    GM_WRITE(vm, -1, "goto", VAL(20));
    L_5066160: ;
    return;
}
