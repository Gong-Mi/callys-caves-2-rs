/* generated from CODE 1148 (gml_RoomCC_rm_mapview3_1148_Create), source start 5059208, end 5059252. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1148(GmVM* vm) {
    /* @5059208 load */
    /* @5059216 constant */
    /* @5059220 cmp */
    /* @5059224 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room98visited") == VAL(0)))) goto L_5059240;
    /* @5059228 call */
    GM_SITE(vm, 1148, 5059228);
    /* @5059236 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5059240: ;
    /* @5059240 constant */
    /* @5059244 store */
    GM_WRITE(vm, -1, "goto", VAL(98));
    L_5059252: ;
    return;
}
