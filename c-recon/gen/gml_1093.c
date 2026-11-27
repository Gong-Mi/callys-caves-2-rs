/* generated from CODE 1093 (gml_RoomCC_rm_map_1093_Create), source start 5056788, end 5056832. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1093(GmVM* vm) {
    /* @5056788 load */
    /* @5056796 constant */
    /* @5056800 cmp */
    /* @5056804 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level13avisited") == VAL(0)))) goto L_5056820;
    /* @5056808 call */
    GM_SITE(vm, 1093, 5056808);
    /* @5056816 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5056820: ;
    /* @5056820 constant */
    /* @5056824 store */
    GM_WRITE(vm, -1, "goto", VAL(18));
    L_5056832: ;
    return;
}
