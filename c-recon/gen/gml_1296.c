/* generated from CODE 1296 (gml_RoomCC_rm_mapview0_1296_Create), source start 5065720, end 5065764. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1296(GmVM* vm) {
    /* @5065720 load */
    /* @5065728 constant */
    /* @5065732 cmp */
    /* @5065736 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room68visited") == VAL(0)))) goto L_5065752;
    /* @5065740 call */
    GM_SITE(vm, 1296, 5065740);
    /* @5065748 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5065752: ;
    /* @5065752 constant */
    /* @5065756 store */
    GM_WRITE(vm, -1, "goto", VAL(67));
    L_5065764: ;
    return;
}
