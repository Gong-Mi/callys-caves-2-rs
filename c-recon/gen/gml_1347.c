/* generated from CODE 1347 (gml_RoomCC_rm_mapview0_1347_Create), source start 5067964, end 5068008. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1347(GmVM* vm) {
    /* @5067964 load */
    /* @5067972 constant */
    /* @5067976 cmp */
    /* @5067980 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boss6visited") == VAL(0)))) goto L_5067996;
    /* @5067984 call */
    GM_SITE(vm, 1347, 5067984);
    /* @5067992 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5067996: ;
    /* @5067996 constant */
    /* @5068000 store */
    GM_WRITE(vm, -1, "goto", VAL(104));
    L_5068008: ;
    return;
}
