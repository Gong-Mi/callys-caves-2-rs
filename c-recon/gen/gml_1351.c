/* generated from CODE 1351 (gml_RoomCC_rm_mapview0_1351_Create), source start 5068140, end 5068184. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1351(GmVM* vm) {
    /* @5068140 load */
    /* @5068148 constant */
    /* @5068152 cmp */
    /* @5068156 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "levelchallenge3visited") == VAL(0)))) goto L_5068172;
    /* @5068160 call */
    GM_SITE(vm, 1351, 5068160);
    /* @5068168 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5068172: ;
    /* @5068172 constant */
    /* @5068176 store */
    GM_WRITE(vm, -1, "goto", VAL(107));
    L_5068184: ;
    return;
}
