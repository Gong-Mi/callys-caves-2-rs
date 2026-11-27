/* generated from CODE 1034 (gml_RoomCC_rm_map_1034_Create), source start 5054192, end 5054236. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1034(GmVM* vm) {
    /* @5054192 load */
    /* @5054200 constant */
    /* @5054204 cmp */
    /* @5054208 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room47visited") == VAL(0)))) goto L_5054224;
    /* @5054212 call */
    GM_SITE(vm, 1034, 5054212);
    /* @5054220 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5054224: ;
    /* @5054224 constant */
    /* @5054228 store */
    GM_WRITE(vm, -1, "goto", VAL(44));
    L_5054236: ;
    return;
}
