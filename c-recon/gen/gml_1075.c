/* generated from CODE 1075 (gml_RoomCC_rm_map_1075_Create), source start 5055996, end 5056040. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1075(GmVM* vm) {
    /* @5055996 load */
    /* @5056004 constant */
    /* @5056008 cmp */
    /* @5056012 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room62visited") == VAL(0)))) goto L_5056028;
    /* @5056016 call */
    GM_SITE(vm, 1075, 5056016);
    /* @5056024 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5056028: ;
    /* @5056028 constant */
    /* @5056032 store */
    GM_WRITE(vm, -1, "goto", VAL(60));
    L_5056040: ;
    return;
}
