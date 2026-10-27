/* generated from CODE 1110 (gml_RoomCC_rm_map_1110_Create), source start 5057536, end 5057580. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1110(GmVM* vm) {
    /* @5057536 load */
    /* @5057544 constant */
    /* @5057548 cmp */
    /* @5057552 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boss2visited") == VAL(0)))) goto L_5057568;
    /* @5057556 call */
    GM_SITE(vm, 1110, 5057556);
    /* @5057564 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5057568: ;
    /* @5057568 constant */
    /* @5057572 store */
    GM_WRITE(vm, -1, "goto", VAL(27));
    L_5057580: ;
    return;
}
