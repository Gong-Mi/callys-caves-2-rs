/* generated from CODE 1054 (gml_RoomCC_rm_map_1054_Create), source start 5055072, end 5055116. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1054(GmVM* vm) {
    /* @5055072 load */
    /* @5055080 constant */
    /* @5055084 cmp */
    /* @5055088 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room101visited") == VAL(0)))) goto L_5055104;
    /* @5055092 call */
    GM_SITE(vm, 1054, 5055092);
    /* @5055100 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5055104: ;
    /* @5055104 constant */
    /* @5055108 store */
    GM_WRITE(vm, -1, "goto", VAL(101));
    L_5055116: ;
    return;
}
