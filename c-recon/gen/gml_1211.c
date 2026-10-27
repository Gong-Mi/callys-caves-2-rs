/* generated from CODE 1211 (gml_RoomCC_rm_mapview3_1211_Create), source start 5061980, end 5062024. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1211(GmVM* vm) {
    /* @5061980 load */
    /* @5061988 constant */
    /* @5061992 cmp */
    /* @5061996 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room80visited") == VAL(0)))) goto L_5062012;
    /* @5062000 call */
    GM_SITE(vm, 1211, 5062000);
    /* @5062008 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5062012: ;
    /* @5062012 constant */
    /* @5062016 store */
    GM_WRITE(vm, -1, "goto", VAL(79));
    L_5062024: ;
    return;
}
