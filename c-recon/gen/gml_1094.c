/* generated from CODE 1094 (gml_RoomCC_rm_map_1094_Create), source start 5056832, end 5056876. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1094(GmVM* vm) {
    /* @5056832 load */
    /* @5056840 constant */
    /* @5056844 cmp */
    /* @5056848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room71visited") == VAL(0)))) goto L_5056864;
    /* @5056852 call */
    GM_SITE(vm, 1094, 5056852);
    /* @5056860 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5056864: ;
    /* @5056864 constant */
    /* @5056868 store */
    GM_WRITE(vm, -1, "goto", VAL(70));
    L_5056876: ;
    return;
}
