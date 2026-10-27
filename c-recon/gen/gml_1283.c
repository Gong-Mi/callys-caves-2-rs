/* generated from CODE 1283 (gml_RoomCC_rm_mapview0_1283_Create), source start 5065148, end 5065192. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1283(GmVM* vm) {
    /* @5065148 load */
    /* @5065156 constant */
    /* @5065160 cmp */
    /* @5065164 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room62visited") == VAL(0)))) goto L_5065180;
    /* @5065168 call */
    GM_SITE(vm, 1283, 5065168);
    /* @5065176 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5065180: ;
    /* @5065180 constant */
    /* @5065184 store */
    GM_WRITE(vm, -1, "goto", VAL(60));
    L_5065192: ;
    return;
}
