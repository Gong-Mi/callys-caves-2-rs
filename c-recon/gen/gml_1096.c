/* generated from CODE 1096 (gml_RoomCC_rm_map_1096_Create), source start 5056920, end 5056964. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1096(GmVM* vm) {
    /* @5056920 load */
    /* @5056928 constant */
    /* @5056932 cmp */
    /* @5056936 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room72visited") == VAL(0)))) goto L_5056952;
    /* @5056940 call */
    GM_SITE(vm, 1096, 5056940);
    /* @5056948 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5056952: ;
    /* @5056952 constant */
    /* @5056956 store */
    GM_WRITE(vm, -1, "goto", VAL(71));
    L_5056964: ;
    return;
}
