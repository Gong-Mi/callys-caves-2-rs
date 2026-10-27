/* generated from CODE 1279 (gml_RoomCC_rm_mapview0_1279_Create), source start 5064972, end 5065016. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1279(GmVM* vm) {
    /* @5064972 load */
    /* @5064980 constant */
    /* @5064984 cmp */
    /* @5064988 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room60visited") == VAL(0)))) goto L_5065004;
    /* @5064992 call */
    GM_SITE(vm, 1279, 5064992);
    /* @5065000 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5065004: ;
    /* @5065004 constant */
    /* @5065008 store */
    GM_WRITE(vm, -1, "goto", VAL(58));
    L_5065016: ;
    return;
}
