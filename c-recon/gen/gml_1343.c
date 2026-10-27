/* generated from CODE 1343 (gml_RoomCC_rm_mapview0_1343_Create), source start 5067788, end 5067832. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1343(GmVM* vm) {
    /* @5067788 load */
    /* @5067796 constant */
    /* @5067800 cmp */
    /* @5067804 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room90visited") == VAL(0)))) goto L_5067820;
    /* @5067808 call */
    GM_SITE(vm, 1343, 5067808);
    /* @5067816 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5067820: ;
    /* @5067820 constant */
    /* @5067824 store */
    GM_WRITE(vm, -1, "goto", VAL(90));
    L_5067832: ;
    return;
}
