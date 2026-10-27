/* generated from CODE 1231 (gml_RoomCC_rm_mapview3_1231_Create), source start 5062860, end 5062904. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1231(GmVM* vm) {
    /* @5062860 load */
    /* @5062868 constant */
    /* @5062872 cmp */
    /* @5062876 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room89visited") == VAL(0)))) goto L_5062892;
    /* @5062880 call */
    GM_SITE(vm, 1231, 5062880);
    /* @5062888 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5062892: ;
    /* @5062892 constant */
    /* @5062896 store */
    GM_WRITE(vm, -1, "goto", VAL(89));
    L_5062904: ;
    return;
}
