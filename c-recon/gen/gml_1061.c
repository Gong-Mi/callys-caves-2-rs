/* generated from CODE 1061 (gml_RoomCC_rm_map_1061_Create), source start 5055380, end 5055424. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1061(GmVM* vm) {
    /* @5055380 load */
    /* @5055388 constant */
    /* @5055392 cmp */
    /* @5055396 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room55visited") == VAL(0)))) goto L_5055412;
    /* @5055400 call */
    GM_SITE(vm, 1061, 5055400);
    /* @5055408 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5055412: ;
    /* @5055412 constant */
    /* @5055416 store */
    GM_WRITE(vm, -1, "goto", VAL(53));
    L_5055424: ;
    return;
}
