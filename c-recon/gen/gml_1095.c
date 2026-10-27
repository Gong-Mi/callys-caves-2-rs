/* generated from CODE 1095 (gml_RoomCC_rm_map_1095_Create), source start 5056876, end 5056920. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1095(GmVM* vm) {
    /* @5056876 load */
    /* @5056884 constant */
    /* @5056888 cmp */
    /* @5056892 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level14visited") == VAL(0)))) goto L_5056908;
    /* @5056896 call */
    GM_SITE(vm, 1095, 5056896);
    /* @5056904 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5056908: ;
    /* @5056908 constant */
    /* @5056912 store */
    GM_WRITE(vm, -1, "goto", VAL(19));
    L_5056920: ;
    return;
}
