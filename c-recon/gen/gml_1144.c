/* generated from CODE 1144 (gml_RoomCC_rm_mapview3_1144_Create), source start 5059032, end 5059076. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1144(GmVM* vm) {
    /* @5059032 load */
    /* @5059040 constant */
    /* @5059044 cmp */
    /* @5059048 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room96visited") == VAL(0)))) goto L_5059064;
    /* @5059052 call */
    GM_SITE(vm, 1144, 5059052);
    /* @5059060 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5059064: ;
    /* @5059064 constant */
    /* @5059068 store */
    GM_WRITE(vm, -1, "goto", VAL(96));
    L_5059076: ;
    return;
}
