/* generated from CODE 1245 (gml_RoomCC_rm_mapview0_1245_Create), source start 5063476, end 5063520. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1245(GmVM* vm) {
    /* @5063476 load */
    /* @5063484 constant */
    /* @5063488 cmp */
    /* @5063492 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room91visited") == VAL(0)))) goto L_5063508;
    /* @5063496 call */
    GM_SITE(vm, 1245, 5063496);
    /* @5063504 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5063508: ;
    /* @5063508 constant */
    /* @5063512 store */
    GM_WRITE(vm, -1, "goto", VAL(91));
    L_5063520: ;
    return;
}
