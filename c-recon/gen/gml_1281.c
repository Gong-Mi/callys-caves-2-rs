/* generated from CODE 1281 (gml_RoomCC_rm_mapview0_1281_Create), source start 5065060, end 5065104. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1281(GmVM* vm) {
    /* @5065060 load */
    /* @5065068 constant */
    /* @5065072 cmp */
    /* @5065076 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room61visited") == VAL(0)))) goto L_5065092;
    /* @5065080 call */
    GM_SITE(vm, 1281, 5065080);
    /* @5065088 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5065092: ;
    /* @5065092 constant */
    /* @5065096 store */
    GM_WRITE(vm, -1, "goto", VAL(59));
    L_5065104: ;
    return;
}
