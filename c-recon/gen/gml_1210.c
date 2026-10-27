/* generated from CODE 1210 (gml_RoomCC_rm_mapview3_1210_Create), source start 5061936, end 5061980. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1210(GmVM* vm) {
    /* @5061936 load */
    /* @5061944 constant */
    /* @5061948 cmp */
    /* @5061952 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boss2visited") == VAL(0)))) goto L_5061968;
    /* @5061956 call */
    GM_SITE(vm, 1210, 5061956);
    /* @5061964 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5061968: ;
    /* @5061968 constant */
    /* @5061972 store */
    GM_WRITE(vm, -1, "goto", VAL(27));
    L_5061980: ;
    return;
}
