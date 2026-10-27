/* generated from CODE 1232 (gml_RoomCC_rm_mapview3_1232_Create), source start 5062904, end 5062948. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1232(GmVM* vm) {
    /* @5062904 load */
    /* @5062912 constant */
    /* @5062916 cmp */
    /* @5062920 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room41visited") == VAL(0)))) goto L_5062936;
    /* @5062924 call */
    GM_SITE(vm, 1232, 5062924);
    /* @5062932 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5062936: ;
    /* @5062936 constant */
    /* @5062940 store */
    GM_WRITE(vm, -1, "goto", VAL(38));
    L_5062948: ;
    return;
}
