/* generated from CODE 1078 (gml_RoomCC_rm_map_1078_Create), source start 5056128, end 5056172. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1078(GmVM* vm) {
    /* @5056128 load */
    /* @5056136 constant */
    /* @5056140 cmp */
    /* @5056144 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boss1visited") == VAL(0)))) goto L_5056160;
    /* @5056148 call */
    GM_SITE(vm, 1078, 5056148);
    /* @5056156 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5056160: ;
    /* @5056160 constant */
    /* @5056164 store */
    GM_WRITE(vm, -1, "goto", VAL(10));
    L_5056172: ;
    return;
}
