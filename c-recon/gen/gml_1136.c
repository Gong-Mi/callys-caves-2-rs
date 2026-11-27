/* generated from CODE 1136 (gml_RoomCC_rm_mapview3_1136_Create), source start 5058680, end 5058724. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1136(GmVM* vm) {
    /* @5058680 load */
    /* @5058688 constant */
    /* @5058692 cmp */
    /* @5058696 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room91visited") == VAL(0)))) goto L_5058712;
    /* @5058700 call */
    GM_SITE(vm, 1136, 5058700);
    /* @5058708 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5058712: ;
    /* @5058712 constant */
    /* @5058716 store */
    GM_WRITE(vm, -1, "goto", VAL(91));
    L_5058724: ;
    return;
}
