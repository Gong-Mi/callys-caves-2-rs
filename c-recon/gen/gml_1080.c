/* generated from CODE 1080 (gml_RoomCC_rm_map_1080_Create), source start 5056216, end 5056260. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1080(GmVM* vm) {
    /* @5056216 load */
    /* @5056224 constant */
    /* @5056228 cmp */
    /* @5056232 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level9visited") == VAL(0)))) goto L_5056248;
    /* @5056236 call */
    GM_SITE(vm, 1080, 5056236);
    /* @5056244 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5056248: ;
    /* @5056248 constant */
    /* @5056252 store */
    GM_WRITE(vm, -1, "goto", VAL(11));
    L_5056260: ;
    return;
}
