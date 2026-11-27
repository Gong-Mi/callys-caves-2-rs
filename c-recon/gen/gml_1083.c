/* generated from CODE 1083 (gml_RoomCC_rm_map_1083_Create), source start 5056348, end 5056392. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1083(GmVM* vm) {
    /* @5056348 load */
    /* @5056356 constant */
    /* @5056360 cmp */
    /* @5056364 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level10visited") == VAL(0)))) goto L_5056380;
    /* @5056368 call */
    GM_SITE(vm, 1083, 5056368);
    /* @5056376 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5056380: ;
    /* @5056380 constant */
    /* @5056384 store */
    GM_WRITE(vm, -1, "goto", VAL(13));
    L_5056392: ;
    return;
}
