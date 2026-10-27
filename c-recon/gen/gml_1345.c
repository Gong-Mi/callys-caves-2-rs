/* generated from CODE 1345 (gml_RoomCC_rm_mapview0_1345_Create), source start 5067876, end 5067920. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1345(GmVM* vm) {
    /* @5067876 load */
    /* @5067884 constant */
    /* @5067888 cmp */
    /* @5067892 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boss6visited") == VAL(0)))) goto L_5067908;
    /* @5067896 call */
    GM_SITE(vm, 1345, 5067896);
    /* @5067904 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5067908: ;
    /* @5067908 constant */
    /* @5067912 store */
    GM_WRITE(vm, -1, "goto", VAL(104));
    L_5067920: ;
    return;
}
