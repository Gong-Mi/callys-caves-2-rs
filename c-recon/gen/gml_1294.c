/* generated from CODE 1294 (gml_RoomCC_rm_mapview0_1294_Create), source start 5065632, end 5065676. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1294(GmVM* vm) {
    /* @5065632 load */
    /* @5065640 constant */
    /* @5065644 cmp */
    /* @5065648 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room67visited") == VAL(0)))) goto L_5065664;
    /* @5065652 call */
    GM_SITE(vm, 1294, 5065652);
    /* @5065660 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5065664: ;
    /* @5065664 constant */
    /* @5065668 store */
    GM_WRITE(vm, -1, "goto", VAL(66));
    L_5065676: ;
    return;
}
