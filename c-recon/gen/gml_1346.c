/* generated from CODE 1346 (gml_RoomCC_rm_mapview0_1346_Create), source start 5067920, end 5067964. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1346(GmVM* vm) {
    /* @5067920 load */
    /* @5067928 constant */
    /* @5067932 cmp */
    /* @5067936 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boss6visited") == VAL(0)))) goto L_5067952;
    /* @5067940 call */
    GM_SITE(vm, 1346, 5067940);
    /* @5067948 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5067952: ;
    /* @5067952 constant */
    /* @5067956 store */
    GM_WRITE(vm, -1, "goto", VAL(104));
    L_5067964: ;
    return;
}
