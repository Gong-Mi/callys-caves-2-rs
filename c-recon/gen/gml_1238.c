/* generated from CODE 1238 (gml_RoomCC_rm_mapview3_1238_Create), source start 5063168, end 5063212. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1238(GmVM* vm) {
    /* @5063168 load */
    /* @5063176 constant */
    /* @5063180 cmp */
    /* @5063184 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "levelchallenge2visited") == VAL(0)))) goto L_5063200;
    /* @5063188 call */
    GM_SITE(vm, 1238, 5063188);
    /* @5063196 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5063200: ;
    /* @5063200 constant */
    /* @5063204 store */
    GM_WRITE(vm, -1, "goto", VAL(106));
    L_5063212: ;
    return;
}
