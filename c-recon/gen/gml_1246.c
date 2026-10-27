/* generated from CODE 1246 (gml_RoomCC_rm_mapview0_1246_Create), source start 5063520, end 5063564. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1246(GmVM* vm) {
    /* @5063520 load */
    /* @5063528 constant */
    /* @5063532 cmp */
    /* @5063536 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room45visited") == VAL(0)))) goto L_5063552;
    /* @5063540 call */
    GM_SITE(vm, 1246, 5063540);
    /* @5063548 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5063552: ;
    /* @5063552 constant */
    /* @5063556 store */
    GM_WRITE(vm, -1, "goto", VAL(42));
    L_5063564: ;
    return;
}
