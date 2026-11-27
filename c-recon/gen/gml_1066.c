/* generated from CODE 1066 (gml_RoomCC_rm_map_1066_Create), source start 5055600, end 5055644. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1066(GmVM* vm) {
    /* @5055600 load */
    /* @5055608 constant */
    /* @5055612 cmp */
    /* @5055616 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level4visited") == VAL(0)))) goto L_5055632;
    /* @5055620 call */
    GM_SITE(vm, 1066, 5055620);
    /* @5055628 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5055632: ;
    /* @5055632 constant */
    /* @5055636 store */
    GM_WRITE(vm, -1, "goto", VAL(4));
    L_5055644: ;
    return;
}
