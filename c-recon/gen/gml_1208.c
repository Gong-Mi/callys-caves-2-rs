/* generated from CODE 1208 (gml_RoomCC_rm_mapview3_1208_Create), source start 5061848, end 5061892. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1208(GmVM* vm) {
    /* @5061848 load */
    /* @5061856 constant */
    /* @5061860 cmp */
    /* @5061864 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level17avisited") == VAL(0)))) goto L_5061880;
    /* @5061868 call */
    GM_SITE(vm, 1208, 5061868);
    /* @5061876 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5061880: ;
    /* @5061880 constant */
    /* @5061884 store */
    GM_WRITE(vm, -1, "goto", VAL(26));
    L_5061892: ;
    return;
}
