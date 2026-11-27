/* generated from CODE 1285 (gml_RoomCC_rm_mapview0_1285_Create), source start 5065236, end 5065280. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1285(GmVM* vm) {
    /* @5065236 load */
    /* @5065244 constant */
    /* @5065248 cmp */
    /* @5065252 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room63visited") == VAL(0)))) goto L_5065268;
    /* @5065256 call */
    GM_SITE(vm, 1285, 5065256);
    /* @5065264 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5065268: ;
    /* @5065268 constant */
    /* @5065272 store */
    GM_WRITE(vm, -1, "goto", VAL(61));
    L_5065280: ;
    return;
}
