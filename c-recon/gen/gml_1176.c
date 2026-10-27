/* generated from CODE 1176 (gml_RoomCC_rm_mapview3_1176_Create), source start 5060440, end 5060484. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1176(GmVM* vm) {
    /* @5060440 load */
    /* @5060448 constant */
    /* @5060452 cmp */
    /* @5060456 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level8avisited") == VAL(0)))) goto L_5060472;
    /* @5060460 call */
    GM_SITE(vm, 1176, 5060460);
    /* @5060468 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5060472: ;
    /* @5060472 constant */
    /* @5060476 store */
    GM_WRITE(vm, -1, "goto", VAL(9));
    L_5060484: ;
    return;
}
