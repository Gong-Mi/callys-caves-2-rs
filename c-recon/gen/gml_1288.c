/* generated from CODE 1288 (gml_RoomCC_rm_mapview0_1288_Create), source start 5065368, end 5065412. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1288(GmVM* vm) {
    /* @5065368 load */
    /* @5065376 constant */
    /* @5065380 cmp */
    /* @5065384 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level9visited") == VAL(0)))) goto L_5065400;
    /* @5065388 call */
    GM_SITE(vm, 1288, 5065388);
    /* @5065396 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5065400: ;
    /* @5065400 constant */
    /* @5065404 store */
    GM_WRITE(vm, -1, "goto", VAL(11));
    L_5065412: ;
    return;
}
