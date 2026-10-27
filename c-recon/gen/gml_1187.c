/* generated from CODE 1187 (gml_RoomCC_rm_mapview3_1187_Create), source start 5060924, end 5060968. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1187(GmVM* vm) {
    /* @5060924 load */
    /* @5060932 constant */
    /* @5060936 cmp */
    /* @5060940 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level11avisited") == VAL(0)))) goto L_5060956;
    /* @5060944 call */
    GM_SITE(vm, 1187, 5060944);
    /* @5060952 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5060956: ;
    /* @5060956 constant */
    /* @5060960 store */
    GM_WRITE(vm, -1, "goto", VAL(15));
    L_5060968: ;
    return;
}
