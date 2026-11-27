/* generated from CODE 1123 (gml_RoomCC_rm_map_1123_Create), source start 5058108, end 5058152. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1123(GmVM* vm) {
    /* @5058108 load */
    /* @5058116 constant */
    /* @5058120 cmp */
    /* @5058124 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room85visited") == VAL(0)))) goto L_5058140;
    /* @5058128 call */
    GM_SITE(vm, 1123, 5058128);
    /* @5058136 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5058140: ;
    /* @5058140 constant */
    /* @5058144 store */
    GM_WRITE(vm, -1, "goto", VAL(85));
    L_5058152: ;
    return;
}
