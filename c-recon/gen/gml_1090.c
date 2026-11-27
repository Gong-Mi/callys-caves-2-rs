/* generated from CODE 1090 (gml_RoomCC_rm_map_1090_Create), source start 5056656, end 5056700. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1090(GmVM* vm) {
    /* @5056656 load */
    /* @5056664 constant */
    /* @5056668 cmp */
    /* @5056672 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room69visited") == VAL(0)))) goto L_5056688;
    /* @5056676 call */
    GM_SITE(vm, 1090, 5056676);
    /* @5056684 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5056688: ;
    /* @5056688 constant */
    /* @5056692 store */
    GM_WRITE(vm, -1, "goto", VAL(68));
    L_5056700: ;
    return;
}
