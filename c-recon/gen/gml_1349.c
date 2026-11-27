/* generated from CODE 1349 (gml_RoomCC_rm_mapview0_1349_Create), source start 5068052, end 5068096. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1349(GmVM* vm) {
    /* @5068052 load */
    /* @5068060 constant */
    /* @5068064 cmp */
    /* @5068068 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "levelchallenge1visited") == VAL(0)))) goto L_5068084;
    /* @5068072 call */
    GM_SITE(vm, 1349, 5068072);
    /* @5068080 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5068084: ;
    /* @5068084 constant */
    /* @5068088 store */
    GM_WRITE(vm, -1, "goto", VAL(105));
    L_5068096: ;
    return;
}
