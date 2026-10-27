/* generated from CODE 1125 (gml_RoomCC_rm_map_1125_Create), source start 5058196, end 5058240. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1125(GmVM* vm) {
    /* @5058196 load */
    /* @5058204 constant */
    /* @5058208 cmp */
    /* @5058212 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room86visited") == VAL(0)))) goto L_5058228;
    /* @5058216 call */
    GM_SITE(vm, 1125, 5058216);
    /* @5058224 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5058228: ;
    /* @5058228 constant */
    /* @5058232 store */
    GM_WRITE(vm, -1, "goto", VAL(86));
    L_5058240: ;
    return;
}
