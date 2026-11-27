/* generated from CODE 1152 (gml_RoomCC_rm_mapview3_1152_Create), source start 5059384, end 5059428. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1152(GmVM* vm) {
    /* @5059384 load */
    /* @5059392 constant */
    /* @5059396 cmp */
    /* @5059400 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room100visited") == VAL(0)))) goto L_5059416;
    /* @5059404 call */
    GM_SITE(vm, 1152, 5059404);
    /* @5059412 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5059416: ;
    /* @5059416 constant */
    /* @5059420 store */
    GM_WRITE(vm, -1, "goto", VAL(100));
    L_5059428: ;
    return;
}
