/* generated from CODE 1169 (gml_RoomCC_rm_mapview3_1169_Create), source start 5060132, end 5060176. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1169(GmVM* vm) {
    /* @5060132 load */
    /* @5060140 constant */
    /* @5060144 cmp */
    /* @5060148 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room59visited") == VAL(0)))) goto L_5060164;
    /* @5060152 call */
    GM_SITE(vm, 1169, 5060152);
    /* @5060160 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5060164: ;
    /* @5060164 constant */
    /* @5060168 store */
    GM_WRITE(vm, -1, "goto", VAL(57));
    L_5060176: ;
    return;
}
