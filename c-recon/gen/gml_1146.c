/* generated from CODE 1146 (gml_RoomCC_rm_mapview3_1146_Create), source start 5059120, end 5059164. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1146(GmVM* vm) {
    /* @5059120 load */
    /* @5059128 constant */
    /* @5059132 cmp */
    /* @5059136 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room97visited") == VAL(0)))) goto L_5059152;
    /* @5059140 call */
    GM_SITE(vm, 1146, 5059140);
    /* @5059148 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5059152: ;
    /* @5059152 constant */
    /* @5059156 store */
    GM_WRITE(vm, -1, "goto", VAL(97));
    L_5059164: ;
    return;
}
