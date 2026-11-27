/* generated from CODE 1156 (gml_RoomCC_rm_mapview3_1156_Create), source start 5059560, end 5059604. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1156(GmVM* vm) {
    /* @5059560 load */
    /* @5059568 constant */
    /* @5059572 cmp */
    /* @5059576 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room102visited") == VAL(0)))) goto L_5059592;
    /* @5059580 call */
    GM_SITE(vm, 1156, 5059580);
    /* @5059588 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5059592: ;
    /* @5059592 constant */
    /* @5059596 store */
    GM_WRITE(vm, -1, "goto", VAL(102));
    L_5059604: ;
    return;
}
