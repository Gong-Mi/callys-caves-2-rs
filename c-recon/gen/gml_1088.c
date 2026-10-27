/* generated from CODE 1088 (gml_RoomCC_rm_map_1088_Create), source start 5056568, end 5056612. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1088(GmVM* vm) {
    /* @5056568 load */
    /* @5056576 constant */
    /* @5056580 cmp */
    /* @5056584 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room68visited") == VAL(0)))) goto L_5056600;
    /* @5056588 call */
    GM_SITE(vm, 1088, 5056588);
    /* @5056596 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5056600: ;
    /* @5056600 constant */
    /* @5056604 store */
    GM_WRITE(vm, -1, "goto", VAL(67));
    L_5056612: ;
    return;
}
