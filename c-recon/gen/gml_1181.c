/* generated from CODE 1181 (gml_RoomCC_rm_mapview3_1181_Create), source start 5060660, end 5060704. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1181(GmVM* vm) {
    /* @5060660 load */
    /* @5060668 constant */
    /* @5060672 cmp */
    /* @5060676 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room65visited") == VAL(0)))) goto L_5060692;
    /* @5060680 call */
    GM_SITE(vm, 1181, 5060680);
    /* @5060688 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5060692: ;
    /* @5060692 constant */
    /* @5060696 store */
    GM_WRITE(vm, -1, "goto", VAL(63));
    L_5060704: ;
    return;
}
