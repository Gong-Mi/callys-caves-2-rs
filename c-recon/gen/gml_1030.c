/* generated from CODE 1030 (gml_RoomCC_rm_map_1030_Create), source start 5054016, end 5054060. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1030(GmVM* vm) {
    /* @5054016 load */
    /* @5054024 constant */
    /* @5054028 cmp */
    /* @5054032 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room92visited") == VAL(0)))) goto L_5054048;
    /* @5054036 call */
    GM_SITE(vm, 1030, 5054036);
    /* @5054044 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5054048: ;
    /* @5054048 constant */
    /* @5054052 store */
    GM_WRITE(vm, -1, "goto", VAL(92));
    L_5054060: ;
    return;
}
