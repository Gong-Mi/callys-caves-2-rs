/* generated from CODE 1134 (gml_RoomCC_rm_mapview3_1134_Create), source start 5058592, end 5058636. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1134(GmVM* vm) {
    /* @5058592 load */
    /* @5058600 constant */
    /* @5058604 cmp */
    /* @5058608 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room42visited") == VAL(0)))) goto L_5058624;
    /* @5058612 call */
    GM_SITE(vm, 1134, 5058612);
    /* @5058620 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5058624: ;
    /* @5058624 constant */
    /* @5058628 store */
    GM_WRITE(vm, -1, "goto", VAL(39));
    L_5058636: ;
    return;
}
