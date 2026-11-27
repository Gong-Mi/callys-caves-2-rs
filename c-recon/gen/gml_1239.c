/* generated from CODE 1239 (gml_RoomCC_rm_mapview3_1239_Create), source start 5063212, end 5063256. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1239(GmVM* vm) {
    /* @5063212 load */
    /* @5063220 constant */
    /* @5063224 cmp */
    /* @5063228 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "levelchallenge3visited") == VAL(0)))) goto L_5063244;
    /* @5063232 call */
    GM_SITE(vm, 1239, 5063232);
    /* @5063240 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5063244: ;
    /* @5063244 constant */
    /* @5063248 store */
    GM_WRITE(vm, -1, "goto", VAL(107));
    L_5063256: ;
    return;
}
