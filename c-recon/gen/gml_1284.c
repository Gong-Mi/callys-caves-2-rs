/* generated from CODE 1284 (gml_RoomCC_rm_mapview0_1284_Create), source start 5065192, end 5065236. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1284(GmVM* vm) {
    /* @5065192 load */
    /* @5065200 constant */
    /* @5065204 cmp */
    /* @5065208 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level8avisited") == VAL(0)))) goto L_5065224;
    /* @5065212 call */
    GM_SITE(vm, 1284, 5065212);
    /* @5065220 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5065224: ;
    /* @5065224 constant */
    /* @5065228 store */
    GM_WRITE(vm, -1, "goto", VAL(9));
    L_5065236: ;
    return;
}
