/* generated from CODE 1255 (gml_RoomCC_rm_mapview0_1255_Create), source start 5063916, end 5063960. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1255(GmVM* vm) {
    /* @5063916 load */
    /* @5063924 constant */
    /* @5063928 cmp */
    /* @5063932 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room97visited") == VAL(0)))) goto L_5063948;
    /* @5063936 call */
    GM_SITE(vm, 1255, 5063936);
    /* @5063944 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5063948: ;
    /* @5063948 constant */
    /* @5063952 store */
    GM_WRITE(vm, -1, "goto", VAL(97));
    L_5063960: ;
    return;
}
