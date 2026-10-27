/* generated from CODE 1273 (gml_RoomCC_rm_mapview0_1273_Create), source start 5064708, end 5064752. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1273(GmVM* vm) {
    /* @5064708 load */
    /* @5064716 constant */
    /* @5064720 cmp */
    /* @5064724 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room57visited") == VAL(0)))) goto L_5064740;
    /* @5064728 call */
    GM_SITE(vm, 1273, 5064728);
    /* @5064736 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5064740: ;
    /* @5064740 constant */
    /* @5064744 store */
    GM_WRITE(vm, -1, "goto", VAL(55));
    L_5064752: ;
    return;
}
