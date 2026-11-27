/* generated from CODE 1233 (gml_RoomCC_rm_mapview3_1233_Create), source start 5062948, end 5062992. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1233(GmVM* vm) {
    /* @5062948 load */
    /* @5062956 constant */
    /* @5062960 cmp */
    /* @5062964 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boss4visited") == VAL(0)))) goto L_5062980;
    /* @5062968 call */
    GM_SITE(vm, 1233, 5062968);
    /* @5062976 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5062980: ;
    /* @5062980 constant */
    /* @5062984 store */
    GM_WRITE(vm, -1, "goto", VAL(64));
    L_5062992: ;
    return;
}
