/* generated from CODE 1064 (gml_RoomCC_rm_map_1064_Create), source start 5055512, end 5055556. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1064(GmVM* vm) {
    /* @5055512 load */
    /* @5055520 constant */
    /* @5055524 cmp */
    /* @5055528 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level3visited") == VAL(0)))) goto L_5055544;
    /* @5055532 call */
    GM_SITE(vm, 1064, 5055532);
    /* @5055540 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5055544: ;
    /* @5055544 constant */
    /* @5055548 store */
    GM_WRITE(vm, -1, "goto", VAL(3));
    L_5055556: ;
    return;
}
