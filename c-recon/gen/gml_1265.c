/* generated from CODE 1265 (gml_RoomCC_rm_mapview0_1265_Create), source start 5064356, end 5064400. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1265(GmVM* vm) {
    /* @5064356 load */
    /* @5064364 constant */
    /* @5064368 cmp */
    /* @5064372 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room102visited") == VAL(0)))) goto L_5064388;
    /* @5064376 call */
    GM_SITE(vm, 1265, 5064376);
    /* @5064384 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5064388: ;
    /* @5064388 constant */
    /* @5064392 store */
    GM_WRITE(vm, -1, "goto", VAL(102));
    L_5064400: ;
    return;
}
