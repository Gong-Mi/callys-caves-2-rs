/* generated from CODE 1175 (gml_RoomCC_rm_mapview3_1175_Create), source start 5060396, end 5060440. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1175(GmVM* vm) {
    /* @5060396 load */
    /* @5060404 constant */
    /* @5060408 cmp */
    /* @5060412 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room62visited") == VAL(0)))) goto L_5060428;
    /* @5060416 call */
    GM_SITE(vm, 1175, 5060416);
    /* @5060424 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5060428: ;
    /* @5060428 constant */
    /* @5060432 store */
    GM_WRITE(vm, -1, "goto", VAL(60));
    L_5060440: ;
    return;
}
