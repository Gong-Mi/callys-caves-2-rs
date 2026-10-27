/* generated from CODE 1028 (gml_RoomCC_rm_map_1028_Create), source start 5053928, end 5053972. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1028(GmVM* vm) {
    /* @5053928 load */
    /* @5053936 constant */
    /* @5053940 cmp */
    /* @5053944 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room45visited") == VAL(0)))) goto L_5053960;
    /* @5053948 call */
    GM_SITE(vm, 1028, 5053948);
    /* @5053956 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5053960: ;
    /* @5053960 constant */
    /* @5053964 store */
    GM_WRITE(vm, -1, "goto", VAL(42));
    L_5053972: ;
    return;
}
