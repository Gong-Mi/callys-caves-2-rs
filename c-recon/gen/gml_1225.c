/* generated from CODE 1225 (gml_RoomCC_rm_mapview3_1225_Create), source start 5062596, end 5062640. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1225(GmVM* vm) {
    /* @5062596 load */
    /* @5062604 constant */
    /* @5062608 cmp */
    /* @5062612 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room86visited") == VAL(0)))) goto L_5062628;
    /* @5062616 call */
    GM_SITE(vm, 1225, 5062616);
    /* @5062624 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5062628: ;
    /* @5062628 constant */
    /* @5062632 store */
    GM_WRITE(vm, -1, "goto", VAL(86));
    L_5062640: ;
    return;
}
