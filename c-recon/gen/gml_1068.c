/* generated from CODE 1068 (gml_RoomCC_rm_map_1068_Create), source start 5055688, end 5055732. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1068(GmVM* vm) {
    /* @5055688 load */
    /* @5055696 constant */
    /* @5055700 cmp */
    /* @5055704 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level5visited") == VAL(0)))) goto L_5055720;
    /* @5055708 call */
    GM_SITE(vm, 1068, 5055708);
    /* @5055716 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5055720: ;
    /* @5055720 constant */
    /* @5055724 store */
    GM_WRITE(vm, -1, "goto", VAL(5));
    L_5055732: ;
    return;
}
