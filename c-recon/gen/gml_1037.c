/* generated from CODE 1037 (gml_RoomCC_rm_map_1037_Create), source start 5054324, end 5054368. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1037(GmVM* vm) {
    /* @5054324 load */
    /* @5054332 constant */
    /* @5054336 cmp */
    /* @5054340 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room88visited") == VAL(0)))) goto L_5054356;
    /* @5054344 call */
    GM_SITE(vm, 1037, 5054344);
    /* @5054352 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5054356: ;
    /* @5054356 constant */
    /* @5054360 store */
    GM_WRITE(vm, -1, "goto", VAL(88));
    L_5054368: ;
    return;
}
