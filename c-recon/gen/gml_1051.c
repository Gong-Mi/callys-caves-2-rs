/* generated from CODE 1051 (gml_RoomCC_rm_map_1051_Create), source start 5054940, end 5054984. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1051(GmVM* vm) {
    /* @5054940 load */
    /* @5054948 constant */
    /* @5054952 cmp */
    /* @5054956 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boss3visited") == VAL(0)))) goto L_5054972;
    /* @5054960 call */
    GM_SITE(vm, 1051, 5054960);
    /* @5054968 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5054972: ;
    /* @5054972 constant */
    /* @5054976 store */
    GM_WRITE(vm, -1, "goto", VAL(48));
    L_5054984: ;
    return;
}
