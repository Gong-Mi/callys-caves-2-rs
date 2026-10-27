/* generated from CODE 1321 (gml_RoomCC_rm_mapview0_1321_Create), source start 5066820, end 5066864. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1321(GmVM* vm) {
    /* @5066820 load */
    /* @5066828 constant */
    /* @5066832 cmp */
    /* @5066836 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room81visited") == VAL(0)))) goto L_5066852;
    /* @5066840 call */
    GM_SITE(vm, 1321, 5066840);
    /* @5066848 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5066852: ;
    /* @5066852 constant */
    /* @5066856 store */
    GM_WRITE(vm, -1, "goto", VAL(80));
    L_5066864: ;
    return;
}
