/* generated from CODE 1158 (gml_RoomCC_rm_mapview3_1158_Create), source start 5059648, end 5059692. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1158(GmVM* vm) {
    /* @5059648 load */
    /* @5059656 constant */
    /* @5059660 cmp */
    /* @5059664 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boss6visited") == VAL(0)))) goto L_5059680;
    /* @5059668 call */
    GM_SITE(vm, 1158, 5059668);
    /* @5059676 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5059680: ;
    /* @5059680 constant */
    /* @5059684 store */
    GM_WRITE(vm, -1, "goto", VAL(104));
    L_5059692: ;
    return;
}
