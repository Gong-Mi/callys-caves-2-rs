/* generated from CODE 1293 (gml_RoomCC_rm_mapview0_1293_Create), source start 5065588, end 5065632. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1293(GmVM* vm) {
    /* @5065588 load */
    /* @5065596 constant */
    /* @5065600 cmp */
    /* @5065604 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level11visited") == VAL(0)))) goto L_5065620;
    /* @5065608 call */
    GM_SITE(vm, 1293, 5065608);
    /* @5065616 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5065620: ;
    /* @5065620 constant */
    /* @5065624 store */
    GM_WRITE(vm, -1, "goto", VAL(14));
    L_5065632: ;
    return;
}
