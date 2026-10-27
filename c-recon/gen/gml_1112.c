/* generated from CODE 1112 (gml_RoomCC_rm_map_1112_Create), source start 5057624, end 5057668. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1112(GmVM* vm) {
    /* @5057624 load */
    /* @5057632 constant */
    /* @5057636 cmp */
    /* @5057640 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room31visited") == VAL(0)))) goto L_5057656;
    /* @5057644 call */
    GM_SITE(vm, 1112, 5057644);
    /* @5057652 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5057656: ;
    /* @5057656 constant */
    /* @5057660 store */
    GM_WRITE(vm, -1, "goto", VAL(28));
    L_5057668: ;
    return;
}
