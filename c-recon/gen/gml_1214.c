/* generated from CODE 1214 (gml_RoomCC_rm_mapview3_1214_Create), source start 5062112, end 5062156. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1214(GmVM* vm) {
    /* @5062112 load */
    /* @5062120 constant */
    /* @5062124 cmp */
    /* @5062128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room32visited") == VAL(0)))) goto L_5062144;
    /* @5062132 call */
    GM_SITE(vm, 1214, 5062132);
    /* @5062140 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5062144: ;
    /* @5062144 constant */
    /* @5062148 store */
    GM_WRITE(vm, -1, "goto", VAL(29));
    L_5062156: ;
    return;
}
