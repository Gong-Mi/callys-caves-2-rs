/* generated from CODE 1254 (gml_RoomCC_rm_mapview0_1254_Create), source start 5063872, end 5063916. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1254(GmVM* vm) {
    /* @5063872 load */
    /* @5063880 constant */
    /* @5063884 cmp */
    /* @5063888 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room48visited") == VAL(0)))) goto L_5063904;
    /* @5063892 call */
    GM_SITE(vm, 1254, 5063892);
    /* @5063900 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5063904: ;
    /* @5063904 constant */
    /* @5063908 store */
    GM_WRITE(vm, -1, "goto", VAL(45));
    L_5063916: ;
    return;
}
