/* generated from CODE 1266 (gml_RoomCC_rm_mapview0_1266_Create), source start 5064400, end 5064444. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1266(GmVM* vm) {
    /* @5064400 load */
    /* @5064408 constant */
    /* @5064412 cmp */
    /* @5064416 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room53visited") == VAL(0)))) goto L_5064432;
    /* @5064420 call */
    GM_SITE(vm, 1266, 5064420);
    /* @5064428 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5064432: ;
    /* @5064432 constant */
    /* @5064436 store */
    GM_WRITE(vm, -1, "goto", VAL(51));
    L_5064444: ;
    return;
}
