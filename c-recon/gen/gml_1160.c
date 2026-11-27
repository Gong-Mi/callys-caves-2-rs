/* generated from CODE 1160 (gml_RoomCC_rm_mapview3_1160_Create), source start 5059736, end 5059780. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1160(GmVM* vm) {
    /* @5059736 load */
    /* @5059744 constant */
    /* @5059748 cmp */
    /* @5059752 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level1visited") == VAL(0)))) goto L_5059768;
    /* @5059756 call */
    GM_SITE(vm, 1160, 5059756);
    /* @5059764 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5059768: ;
    /* @5059768 constant */
    /* @5059772 store */
    GM_WRITE(vm, -1, "goto", VAL(1));
    L_5059780: ;
    return;
}
