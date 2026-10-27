/* generated from CODE 1348 (gml_RoomCC_rm_mapview0_1348_Create), source start 5068008, end 5068052. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1348(GmVM* vm) {
    /* @5068008 load */
    /* @5068016 constant */
    /* @5068020 cmp */
    /* @5068024 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boss6visited") == VAL(0)))) goto L_5068040;
    /* @5068028 call */
    GM_SITE(vm, 1348, 5068028);
    /* @5068036 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5068040: ;
    /* @5068040 constant */
    /* @5068044 store */
    GM_WRITE(vm, -1, "goto", VAL(104));
    L_5068052: ;
    return;
}
