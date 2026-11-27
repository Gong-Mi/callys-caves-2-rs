/* generated from CODE 1200 (gml_RoomCC_rm_mapview3_1200_Create), source start 5061496, end 5061540. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1200(GmVM* vm) {
    /* @5061496 load */
    /* @5061504 constant */
    /* @5061508 cmp */
    /* @5061512 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room74visited") == VAL(0)))) goto L_5061528;
    /* @5061516 call */
    GM_SITE(vm, 1200, 5061516);
    /* @5061524 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5061528: ;
    /* @5061528 constant */
    /* @5061532 store */
    GM_WRITE(vm, -1, "goto", VAL(73));
    L_5061540: ;
    return;
}
