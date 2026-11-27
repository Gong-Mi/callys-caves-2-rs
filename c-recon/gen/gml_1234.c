/* generated from CODE 1234 (gml_RoomCC_rm_mapview3_1234_Create), source start 5062992, end 5063036. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1234(GmVM* vm) {
    /* @5062992 load */
    /* @5063000 constant */
    /* @5063004 cmp */
    /* @5063008 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room78visited") == VAL(0)))) goto L_5063024;
    /* @5063012 call */
    GM_SITE(vm, 1234, 5063012);
    /* @5063020 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5063024: ;
    /* @5063024 constant */
    /* @5063028 store */
    GM_WRITE(vm, -1, "goto", VAL(77));
    L_5063036: ;
    return;
}
