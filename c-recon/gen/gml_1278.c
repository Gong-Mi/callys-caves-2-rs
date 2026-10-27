/* generated from CODE 1278 (gml_RoomCC_rm_mapview0_1278_Create), source start 5064928, end 5064972. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1278(GmVM* vm) {
    /* @5064928 load */
    /* @5064936 constant */
    /* @5064940 cmp */
    /* @5064944 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level6visited") == VAL(0)))) goto L_5064960;
    /* @5064948 call */
    GM_SITE(vm, 1278, 5064948);
    /* @5064956 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5064960: ;
    /* @5064960 constant */
    /* @5064964 store */
    GM_WRITE(vm, -1, "goto", VAL(6));
    L_5064972: ;
    return;
}
