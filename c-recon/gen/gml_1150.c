/* generated from CODE 1150 (gml_RoomCC_rm_mapview3_1150_Create), source start 5059296, end 5059340. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1150(GmVM* vm) {
    /* @5059296 load */
    /* @5059304 constant */
    /* @5059308 cmp */
    /* @5059312 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room99visited") == VAL(0)))) goto L_5059328;
    /* @5059316 call */
    GM_SITE(vm, 1150, 5059316);
    /* @5059324 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5059328: ;
    /* @5059328 constant */
    /* @5059332 store */
    GM_WRITE(vm, -1, "goto", VAL(99));
    L_5059340: ;
    return;
}
