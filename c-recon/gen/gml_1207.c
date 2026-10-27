/* generated from CODE 1207 (gml_RoomCC_rm_mapview3_1207_Create), source start 5061804, end 5061848. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1207(GmVM* vm) {
    /* @5061804 load */
    /* @5061812 constant */
    /* @5061816 cmp */
    /* @5061820 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level17visited") == VAL(0)))) goto L_5061836;
    /* @5061824 call */
    GM_SITE(vm, 1207, 5061824);
    /* @5061832 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5061836: ;
    /* @5061836 constant */
    /* @5061840 store */
    GM_WRITE(vm, -1, "goto", VAL(25));
    L_5061848: ;
    return;
}
