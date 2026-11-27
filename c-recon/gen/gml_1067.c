/* generated from CODE 1067 (gml_RoomCC_rm_map_1067_Create), source start 5055644, end 5055688. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1067(GmVM* vm) {
    /* @5055644 load */
    /* @5055652 constant */
    /* @5055656 cmp */
    /* @5055660 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room58visited") == VAL(0)))) goto L_5055676;
    /* @5055664 call */
    GM_SITE(vm, 1067, 5055664);
    /* @5055672 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5055676: ;
    /* @5055676 constant */
    /* @5055680 store */
    GM_WRITE(vm, -1, "goto", VAL(56));
    L_5055688: ;
    return;
}
