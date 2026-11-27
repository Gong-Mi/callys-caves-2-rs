/* generated from CODE 1102 (gml_RoomCC_rm_map_1102_Create), source start 5057184, end 5057228. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1102(GmVM* vm) {
    /* @5057184 load */
    /* @5057192 constant */
    /* @5057196 cmp */
    /* @5057200 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room75visited") == VAL(0)))) goto L_5057216;
    /* @5057204 call */
    GM_SITE(vm, 1102, 5057204);
    /* @5057212 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5057216: ;
    /* @5057216 constant */
    /* @5057220 store */
    GM_WRITE(vm, -1, "goto", VAL(74));
    L_5057228: ;
    return;
}
