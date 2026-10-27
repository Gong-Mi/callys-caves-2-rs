/* generated from CODE 1257 (gml_RoomCC_rm_mapview0_1257_Create), source start 5064004, end 5064048. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1257(GmVM* vm) {
    /* @5064004 load */
    /* @5064012 constant */
    /* @5064016 cmp */
    /* @5064020 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room98visited") == VAL(0)))) goto L_5064036;
    /* @5064024 call */
    GM_SITE(vm, 1257, 5064024);
    /* @5064032 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5064036: ;
    /* @5064036 constant */
    /* @5064040 store */
    GM_WRITE(vm, -1, "goto", VAL(98));
    L_5064048: ;
    return;
}
