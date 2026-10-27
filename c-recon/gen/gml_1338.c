/* generated from CODE 1338 (gml_RoomCC_rm_mapview0_1338_Create), source start 5067568, end 5067612. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1338(GmVM* vm) {
    /* @5067568 load */
    /* @5067576 constant */
    /* @5067580 cmp */
    /* @5067584 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room40visited") == VAL(0)))) goto L_5067600;
    /* @5067588 call */
    GM_SITE(vm, 1338, 5067588);
    /* @5067596 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5067600: ;
    /* @5067600 constant */
    /* @5067604 store */
    GM_WRITE(vm, -1, "goto", VAL(37));
    L_5067612: ;
    return;
}
