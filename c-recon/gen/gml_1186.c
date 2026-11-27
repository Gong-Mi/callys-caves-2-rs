/* generated from CODE 1186 (gml_RoomCC_rm_mapview3_1186_Create), source start 5060880, end 5060924. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1186(GmVM* vm) {
    /* @5060880 load */
    /* @5060888 constant */
    /* @5060892 cmp */
    /* @5060896 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room67visited") == VAL(0)))) goto L_5060912;
    /* @5060900 call */
    GM_SITE(vm, 1186, 5060900);
    /* @5060908 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5060912: ;
    /* @5060912 constant */
    /* @5060916 store */
    GM_WRITE(vm, -1, "goto", VAL(66));
    L_5060924: ;
    return;
}
