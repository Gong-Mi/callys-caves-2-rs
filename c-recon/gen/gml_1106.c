/* generated from CODE 1106 (gml_RoomCC_rm_map_1106_Create), source start 5057360, end 5057404. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1106(GmVM* vm) {
    /* @5057360 load */
    /* @5057368 constant */
    /* @5057372 cmp */
    /* @5057376 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room77visited") == VAL(0)))) goto L_5057392;
    /* @5057380 call */
    GM_SITE(vm, 1106, 5057380);
    /* @5057388 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5057392: ;
    /* @5057392 constant */
    /* @5057396 store */
    GM_WRITE(vm, -1, "goto", VAL(76));
    L_5057404: ;
    return;
}
