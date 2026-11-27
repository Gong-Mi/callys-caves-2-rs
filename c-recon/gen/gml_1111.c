/* generated from CODE 1111 (gml_RoomCC_rm_map_1111_Create), source start 5057580, end 5057624. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1111(GmVM* vm) {
    /* @5057580 load */
    /* @5057588 constant */
    /* @5057592 cmp */
    /* @5057596 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room80visited") == VAL(0)))) goto L_5057612;
    /* @5057600 call */
    GM_SITE(vm, 1111, 5057600);
    /* @5057608 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5057612: ;
    /* @5057612 constant */
    /* @5057616 store */
    GM_WRITE(vm, -1, "goto", VAL(79));
    L_5057624: ;
    return;
}
