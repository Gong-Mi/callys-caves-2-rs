/* generated from CODE 1027 (gml_RoomCC_rm_map_1027_Create), source start 5053884, end 5053928. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1027(GmVM* vm) {
    /* @5053884 load */
    /* @5053892 constant */
    /* @5053896 cmp */
    /* @5053900 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room91visited") == VAL(0)))) goto L_5053916;
    /* @5053904 call */
    GM_SITE(vm, 1027, 5053904);
    /* @5053912 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5053916: ;
    /* @5053916 constant */
    /* @5053920 store */
    GM_WRITE(vm, -1, "goto", VAL(91));
    L_5053928: ;
    return;
}
