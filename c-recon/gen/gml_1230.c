/* generated from CODE 1230 (gml_RoomCC_rm_mapview3_1230_Create), source start 5062816, end 5062860. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1230(GmVM* vm) {
    /* @5062816 load */
    /* @5062824 constant */
    /* @5062828 cmp */
    /* @5062832 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room40visited") == VAL(0)))) goto L_5062848;
    /* @5062836 call */
    GM_SITE(vm, 1230, 5062836);
    /* @5062844 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5062848: ;
    /* @5062848 constant */
    /* @5062852 store */
    GM_WRITE(vm, -1, "goto", VAL(37));
    L_5062860: ;
    return;
}
