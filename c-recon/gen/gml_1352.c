/* generated from CODE 1352 (gml_RoomCC_rm_mapview0_1352_Create), source start 5068184, end 5068228. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1352(GmVM* vm) {
    /* @5068184 load */
    /* @5068192 constant */
    /* @5068196 cmp */
    /* @5068200 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "levelchallenge4visited") == VAL(0)))) goto L_5068216;
    /* @5068204 call */
    GM_SITE(vm, 1352, 5068204);
    /* @5068212 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5068216: ;
    /* @5068216 constant */
    /* @5068220 store */
    GM_WRITE(vm, -1, "goto", VAL(108));
    L_5068228: ;
    return;
}
