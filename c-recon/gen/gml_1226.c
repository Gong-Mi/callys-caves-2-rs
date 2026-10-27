/* generated from CODE 1226 (gml_RoomCC_rm_mapview3_1226_Create), source start 5062640, end 5062684. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1226(GmVM* vm) {
    /* @5062640 load */
    /* @5062648 constant */
    /* @5062652 cmp */
    /* @5062656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room38visited") == VAL(0)))) goto L_5062672;
    /* @5062660 call */
    GM_SITE(vm, 1226, 5062660);
    /* @5062668 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5062672: ;
    /* @5062672 constant */
    /* @5062676 store */
    GM_WRITE(vm, -1, "goto", VAL(35));
    L_5062684: ;
    return;
}
