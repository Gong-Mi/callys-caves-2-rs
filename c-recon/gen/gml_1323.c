/* generated from CODE 1323 (gml_RoomCC_rm_mapview0_1323_Create), source start 5066908, end 5066952. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1323(GmVM* vm) {
    /* @5066908 load */
    /* @5066916 constant */
    /* @5066920 cmp */
    /* @5066924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room82visited") == VAL(0)))) goto L_5066940;
    /* @5066928 call */
    GM_SITE(vm, 1323, 5066928);
    /* @5066936 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5066940: ;
    /* @5066940 constant */
    /* @5066944 store */
    GM_WRITE(vm, -1, "goto", VAL(81));
    L_5066952: ;
    return;
}
