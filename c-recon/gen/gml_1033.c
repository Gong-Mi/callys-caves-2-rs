/* generated from CODE 1033 (gml_RoomCC_rm_map_1033_Create), source start 5054148, end 5054192. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1033(GmVM* vm) {
    /* @5054148 load */
    /* @5054156 constant */
    /* @5054160 cmp */
    /* @5054164 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room46visited") == VAL(0)))) goto L_5054180;
    /* @5054168 call */
    GM_SITE(vm, 1033, 5054168);
    /* @5054176 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5054180: ;
    /* @5054180 constant */
    /* @5054184 store */
    GM_WRITE(vm, -1, "goto", VAL(43));
    L_5054192: ;
    return;
}
