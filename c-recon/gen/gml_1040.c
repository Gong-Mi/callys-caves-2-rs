/* generated from CODE 1040 (gml_RoomCC_rm_map_1040_Create), source start 5054456, end 5054500. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1040(GmVM* vm) {
    /* @5054456 load */
    /* @5054464 constant */
    /* @5054468 cmp */
    /* @5054472 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room39visited") == VAL(0)))) goto L_5054488;
    /* @5054476 call */
    GM_SITE(vm, 1040, 5054476);
    /* @5054484 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5054488: ;
    /* @5054488 constant */
    /* @5054492 store */
    GM_WRITE(vm, -1, "goto", VAL(36));
    L_5054500: ;
    return;
}
