/* generated from CODE 1029 (gml_RoomCC_rm_map_1029_Create), source start 5053972, end 5054016. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1029(GmVM* vm) {
    /* @5053972 load */
    /* @5053980 constant */
    /* @5053984 cmp */
    /* @5053988 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room95visited") == VAL(0)))) goto L_5054004;
    /* @5053992 call */
    GM_SITE(vm, 1029, 5053992);
    /* @5054000 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5054004: ;
    /* @5054004 constant */
    /* @5054008 store */
    GM_WRITE(vm, -1, "goto", VAL(95));
    L_5054016: ;
    return;
}
