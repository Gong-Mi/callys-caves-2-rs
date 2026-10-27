/* generated from CODE 1330 (gml_RoomCC_rm_mapview0_1330_Create), source start 5067216, end 5067260. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1330(GmVM* vm) {
    /* @5067216 load */
    /* @5067224 constant */
    /* @5067228 cmp */
    /* @5067232 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room36visited") == VAL(0)))) goto L_5067248;
    /* @5067236 call */
    GM_SITE(vm, 1330, 5067236);
    /* @5067244 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5067248: ;
    /* @5067248 constant */
    /* @5067252 store */
    GM_WRITE(vm, -1, "goto", VAL(33));
    L_5067260: ;
    return;
}
