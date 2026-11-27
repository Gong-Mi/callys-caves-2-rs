/* generated from CODE 1170 (gml_RoomCC_rm_mapview3_1170_Create), source start 5060176, end 5060220. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1170(GmVM* vm) {
    /* @5060176 load */
    /* @5060184 constant */
    /* @5060188 cmp */
    /* @5060192 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level6visited") == VAL(0)))) goto L_5060208;
    /* @5060196 call */
    GM_SITE(vm, 1170, 5060196);
    /* @5060204 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5060208: ;
    /* @5060208 constant */
    /* @5060212 store */
    GM_WRITE(vm, -1, "goto", VAL(6));
    L_5060220: ;
    return;
}
