/* generated from CODE 1142 (gml_RoomCC_rm_mapview3_1142_Create), source start 5058944, end 5058988. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1142(GmVM* vm) {
    /* @5058944 load */
    /* @5058952 constant */
    /* @5058956 cmp */
    /* @5058960 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room46visited") == VAL(0)))) goto L_5058976;
    /* @5058964 call */
    GM_SITE(vm, 1142, 5058964);
    /* @5058972 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5058976: ;
    /* @5058976 constant */
    /* @5058980 store */
    GM_WRITE(vm, -1, "goto", VAL(43));
    L_5058988: ;
    return;
}
