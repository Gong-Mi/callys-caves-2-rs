/* generated from CODE 1121 (gml_RoomCC_rm_map_1121_Create), source start 5058020, end 5058064. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1121(GmVM* vm) {
    /* @5058020 load */
    /* @5058028 constant */
    /* @5058032 cmp */
    /* @5058036 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room84visited") == VAL(0)))) goto L_5058052;
    /* @5058040 call */
    GM_SITE(vm, 1121, 5058040);
    /* @5058048 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5058052: ;
    /* @5058052 constant */
    /* @5058056 store */
    GM_WRITE(vm, -1, "goto", VAL(84));
    L_5058064: ;
    return;
}
