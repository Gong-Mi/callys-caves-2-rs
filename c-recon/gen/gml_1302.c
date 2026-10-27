/* generated from CODE 1302 (gml_RoomCC_rm_mapview0_1302_Create), source start 5065984, end 5066028. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1302(GmVM* vm) {
    /* @5065984 load */
    /* @5065992 constant */
    /* @5065996 cmp */
    /* @5066000 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room71visited") == VAL(0)))) goto L_5066016;
    /* @5066004 call */
    GM_SITE(vm, 1302, 5066004);
    /* @5066012 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5066016: ;
    /* @5066016 constant */
    /* @5066020 store */
    GM_WRITE(vm, -1, "goto", VAL(70));
    L_5066028: ;
    return;
}
