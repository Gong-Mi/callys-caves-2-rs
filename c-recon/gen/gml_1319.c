/* generated from CODE 1319 (gml_RoomCC_rm_mapview0_1319_Create), source start 5066732, end 5066776. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1319(GmVM* vm) {
    /* @5066732 load */
    /* @5066740 constant */
    /* @5066744 cmp */
    /* @5066748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room80visited") == VAL(0)))) goto L_5066764;
    /* @5066752 call */
    GM_SITE(vm, 1319, 5066752);
    /* @5066760 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5066764: ;
    /* @5066764 constant */
    /* @5066768 store */
    GM_WRITE(vm, -1, "goto", VAL(79));
    L_5066776: ;
    return;
}
