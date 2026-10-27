/* generated from CODE 1191 (gml_RoomCC_rm_mapview3_1191_Create), source start 5061100, end 5061144. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1191(GmVM* vm) {
    /* @5061100 load */
    /* @5061108 constant */
    /* @5061112 cmp */
    /* @5061116 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level13visited") == VAL(0)))) goto L_5061132;
    /* @5061120 call */
    GM_SITE(vm, 1191, 5061120);
    /* @5061128 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5061132: ;
    /* @5061132 constant */
    /* @5061136 store */
    GM_WRITE(vm, -1, "goto", VAL(17));
    L_5061144: ;
    return;
}
