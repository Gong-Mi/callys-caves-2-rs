/* generated from CODE 1282 (gml_RoomCC_rm_mapview0_1282_Create), source start 5065104, end 5065148. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1282(GmVM* vm) {
    /* @5065104 load */
    /* @5065112 constant */
    /* @5065116 cmp */
    /* @5065120 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level8visited") == VAL(0)))) goto L_5065136;
    /* @5065124 call */
    GM_SITE(vm, 1282, 5065124);
    /* @5065132 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5065136: ;
    /* @5065136 constant */
    /* @5065140 store */
    GM_WRITE(vm, -1, "goto", VAL(8));
    L_5065148: ;
    return;
}
