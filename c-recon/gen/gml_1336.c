/* generated from CODE 1336 (gml_RoomCC_rm_mapview0_1336_Create), source start 5067480, end 5067524. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1336(GmVM* vm) {
    /* @5067480 load */
    /* @5067488 constant */
    /* @5067492 cmp */
    /* @5067496 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room39visited") == VAL(0)))) goto L_5067512;
    /* @5067500 call */
    GM_SITE(vm, 1336, 5067500);
    /* @5067508 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5067512: ;
    /* @5067512 constant */
    /* @5067516 store */
    GM_WRITE(vm, -1, "goto", VAL(36));
    L_5067524: ;
    return;
}
