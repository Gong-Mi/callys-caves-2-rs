/* generated from CODE 1199 (gml_RoomCC_rm_mapview3_1199_Create), source start 5061452, end 5061496. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1199(GmVM* vm) {
    /* @5061452 load */
    /* @5061460 constant */
    /* @5061464 cmp */
    /* @5061468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level15visited") == VAL(0)))) goto L_5061484;
    /* @5061472 call */
    GM_SITE(vm, 1199, 5061472);
    /* @5061480 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5061484: ;
    /* @5061484 constant */
    /* @5061488 store */
    GM_WRITE(vm, -1, "goto", VAL(21));
    L_5061496: ;
    return;
}
