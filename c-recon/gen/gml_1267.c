/* generated from CODE 1267 (gml_RoomCC_rm_mapview0_1267_Create), source start 5064444, end 5064488. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1267(GmVM* vm) {
    /* @5064444 load */
    /* @5064452 constant */
    /* @5064456 cmp */
    /* @5064460 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room54visited") == VAL(0)))) goto L_5064476;
    /* @5064464 call */
    GM_SITE(vm, 1267, 5064464);
    /* @5064472 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5064476: ;
    /* @5064476 constant */
    /* @5064480 store */
    GM_WRITE(vm, -1, "goto", VAL(52));
    L_5064488: ;
    return;
}
