/* generated from CODE 1198 (gml_RoomCC_rm_mapview3_1198_Create), source start 5061408, end 5061452. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1198(GmVM* vm) {
    /* @5061408 load */
    /* @5061416 constant */
    /* @5061420 cmp */
    /* @5061424 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room73visited") == VAL(0)))) goto L_5061440;
    /* @5061428 call */
    GM_SITE(vm, 1198, 5061428);
    /* @5061436 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5061440: ;
    /* @5061440 constant */
    /* @5061444 store */
    GM_WRITE(vm, -1, "goto", VAL(72));
    L_5061452: ;
    return;
}
