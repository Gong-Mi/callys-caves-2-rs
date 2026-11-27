/* generated from CODE 1157 (gml_RoomCC_rm_mapview3_1157_Create), source start 5059604, end 5059648. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1157(GmVM* vm) {
    /* @5059604 load */
    /* @5059612 constant */
    /* @5059616 cmp */
    /* @5059620 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room53visited") == VAL(0)))) goto L_5059636;
    /* @5059624 call */
    GM_SITE(vm, 1157, 5059624);
    /* @5059632 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5059636: ;
    /* @5059636 constant */
    /* @5059640 store */
    GM_WRITE(vm, -1, "goto", VAL(51));
    L_5059648: ;
    return;
}
