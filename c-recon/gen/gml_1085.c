/* generated from CODE 1085 (gml_RoomCC_rm_map_1085_Create), source start 5056436, end 5056480. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1085(GmVM* vm) {
    /* @5056436 load */
    /* @5056444 constant */
    /* @5056448 cmp */
    /* @5056452 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level11visited") == VAL(0)))) goto L_5056468;
    /* @5056456 call */
    GM_SITE(vm, 1085, 5056456);
    /* @5056464 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5056468: ;
    /* @5056468 constant */
    /* @5056472 store */
    GM_WRITE(vm, -1, "goto", VAL(14));
    L_5056480: ;
    return;
}
