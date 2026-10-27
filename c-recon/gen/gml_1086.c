/* generated from CODE 1086 (gml_RoomCC_rm_map_1086_Create), source start 5056480, end 5056524. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1086(GmVM* vm) {
    /* @5056480 load */
    /* @5056488 constant */
    /* @5056492 cmp */
    /* @5056496 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room67visited") == VAL(0)))) goto L_5056512;
    /* @5056500 call */
    GM_SITE(vm, 1086, 5056500);
    /* @5056508 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5056512: ;
    /* @5056512 constant */
    /* @5056516 store */
    GM_WRITE(vm, -1, "goto", VAL(66));
    L_5056524: ;
    return;
}
