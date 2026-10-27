/* generated from CODE 1329 (gml_RoomCC_rm_mapview0_1329_Create), source start 5067172, end 5067216. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1329(GmVM* vm) {
    /* @5067172 load */
    /* @5067180 constant */
    /* @5067184 cmp */
    /* @5067188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room84visited") == VAL(0)))) goto L_5067204;
    /* @5067192 call */
    GM_SITE(vm, 1329, 5067192);
    /* @5067200 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5067204: ;
    /* @5067204 constant */
    /* @5067208 store */
    GM_WRITE(vm, -1, "goto", VAL(84));
    L_5067216: ;
    return;
}
