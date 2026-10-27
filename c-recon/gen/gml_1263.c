/* generated from CODE 1263 (gml_RoomCC_rm_mapview0_1263_Create), source start 5064268, end 5064312. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1263(GmVM* vm) {
    /* @5064268 load */
    /* @5064276 constant */
    /* @5064280 cmp */
    /* @5064284 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room101visited") == VAL(0)))) goto L_5064300;
    /* @5064288 call */
    GM_SITE(vm, 1263, 5064288);
    /* @5064296 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5064300: ;
    /* @5064300 constant */
    /* @5064304 store */
    GM_WRITE(vm, -1, "goto", VAL(101));
    L_5064312: ;
    return;
}
