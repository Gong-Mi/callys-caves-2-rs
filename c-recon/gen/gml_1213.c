/* generated from CODE 1213 (gml_RoomCC_rm_mapview3_1213_Create), source start 5062068, end 5062112. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1213(GmVM* vm) {
    /* @5062068 load */
    /* @5062076 constant */
    /* @5062080 cmp */
    /* @5062084 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room81visited") == VAL(0)))) goto L_5062100;
    /* @5062088 call */
    GM_SITE(vm, 1213, 5062088);
    /* @5062096 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5062100: ;
    /* @5062100 constant */
    /* @5062104 store */
    GM_WRITE(vm, -1, "goto", VAL(80));
    L_5062112: ;
    return;
}
