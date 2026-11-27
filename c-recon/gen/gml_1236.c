/* generated from CODE 1236 (gml_RoomCC_rm_mapview3_1236_Create), source start 5063080, end 5063124. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1236(GmVM* vm) {
    /* @5063080 load */
    /* @5063088 constant */
    /* @5063092 cmp */
    /* @5063096 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room103visited") == VAL(0)))) goto L_5063112;
    /* @5063100 call */
    GM_SITE(vm, 1236, 5063100);
    /* @5063108 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5063112: ;
    /* @5063112 constant */
    /* @5063116 store */
    GM_WRITE(vm, -1, "goto", VAL(103));
    L_5063124: ;
    return;
}
