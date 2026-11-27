/* generated from CODE 1277 (gml_RoomCC_rm_mapview0_1277_Create), source start 5064884, end 5064928. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1277(GmVM* vm) {
    /* @5064884 load */
    /* @5064892 constant */
    /* @5064896 cmp */
    /* @5064900 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room59visited") == VAL(0)))) goto L_5064916;
    /* @5064904 call */
    GM_SITE(vm, 1277, 5064904);
    /* @5064912 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5064916: ;
    /* @5064916 constant */
    /* @5064920 store */
    GM_WRITE(vm, -1, "goto", VAL(57));
    L_5064928: ;
    return;
}
