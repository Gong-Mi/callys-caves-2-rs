/* generated from CODE 1139 (gml_RoomCC_rm_mapview3_1139_Create), source start 5058812, end 5058856. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1139(GmVM* vm) {
    /* @5058812 load */
    /* @5058820 constant */
    /* @5058824 cmp */
    /* @5058828 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room92visited") == VAL(0)))) goto L_5058844;
    /* @5058832 call */
    GM_SITE(vm, 1139, 5058832);
    /* @5058840 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5058844: ;
    /* @5058844 constant */
    /* @5058848 store */
    GM_WRITE(vm, -1, "goto", VAL(92));
    L_5058856: ;
    return;
}
