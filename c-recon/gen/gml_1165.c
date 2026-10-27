/* generated from CODE 1165 (gml_RoomCC_rm_mapview3_1165_Create), source start 5059956, end 5060000. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1165(GmVM* vm) {
    /* @5059956 load */
    /* @5059964 constant */
    /* @5059968 cmp */
    /* @5059972 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room57visited") == VAL(0)))) goto L_5059988;
    /* @5059976 call */
    GM_SITE(vm, 1165, 5059976);
    /* @5059984 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5059988: ;
    /* @5059988 constant */
    /* @5059992 store */
    GM_WRITE(vm, -1, "goto", VAL(55));
    L_5060000: ;
    return;
}
