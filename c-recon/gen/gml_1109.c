/* generated from CODE 1109 (gml_RoomCC_rm_map_1109_Create), source start 5057492, end 5057536. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1109(GmVM* vm) {
    /* @5057492 load */
    /* @5057500 constant */
    /* @5057504 cmp */
    /* @5057508 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room79visited") == VAL(0)))) goto L_5057524;
    /* @5057512 call */
    GM_SITE(vm, 1109, 5057512);
    /* @5057520 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5057524: ;
    /* @5057524 constant */
    /* @5057528 store */
    GM_WRITE(vm, -1, "goto", VAL(78));
    L_5057536: ;
    return;
}
