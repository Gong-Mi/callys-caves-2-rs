/* generated from CODE 1205 (gml_RoomCC_rm_mapview3_1205_Create), source start 5061716, end 5061760. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1205(GmVM* vm) {
    /* @5061716 load */
    /* @5061724 constant */
    /* @5061728 cmp */
    /* @5061732 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level16avisited") == VAL(0)))) goto L_5061748;
    /* @5061736 call */
    GM_SITE(vm, 1205, 5061736);
    /* @5061744 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5061748: ;
    /* @5061748 constant */
    /* @5061752 store */
    GM_WRITE(vm, -1, "goto", VAL(24));
    L_5061760: ;
    return;
}
