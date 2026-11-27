/* generated from CODE 1035 (gml_RoomCC_rm_map_1035_Create), source start 5054236, end 5054280. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1035(GmVM* vm) {
    /* @5054236 load */
    /* @5054244 constant */
    /* @5054248 cmp */
    /* @5054252 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room40visited") == VAL(0)))) goto L_5054268;
    /* @5054256 call */
    GM_SITE(vm, 1035, 5054256);
    /* @5054264 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5054268: ;
    /* @5054268 constant */
    /* @5054272 store */
    GM_WRITE(vm, -1, "goto", VAL(37));
    L_5054280: ;
    return;
}
