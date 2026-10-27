/* generated from CODE 1173 (gml_RoomCC_rm_mapview3_1173_Create), source start 5060308, end 5060352. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1173(GmVM* vm) {
    /* @5060308 load */
    /* @5060316 constant */
    /* @5060320 cmp */
    /* @5060324 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room61visited") == VAL(0)))) goto L_5060340;
    /* @5060328 call */
    GM_SITE(vm, 1173, 5060328);
    /* @5060336 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5060340: ;
    /* @5060340 constant */
    /* @5060344 store */
    GM_WRITE(vm, -1, "goto", VAL(59));
    L_5060352: ;
    return;
}
