/* generated from CODE 1132 (gml_RoomCC_rm_map_1132_Create), source start 5058504, end 5058548. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1132(GmVM* vm) {
    /* @5058504 load */
    /* @5058512 constant */
    /* @5058516 cmp */
    /* @5058520 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "levelchallenge5visited") == VAL(0)))) goto L_5058536;
    /* @5058524 call */
    GM_SITE(vm, 1132, 5058524);
    /* @5058532 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5058536: ;
    /* @5058536 constant */
    /* @5058540 store */
    GM_WRITE(vm, -1, "goto", VAL(109));
    L_5058548: ;
    return;
}
