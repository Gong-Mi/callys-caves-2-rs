/* generated from CODE 1058 (gml_RoomCC_rm_map_1058_Create), source start 5055248, end 5055292. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1058(GmVM* vm) {
    /* @5055248 load */
    /* @5055256 constant */
    /* @5055260 cmp */
    /* @5055264 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boss6visited") == VAL(0)))) goto L_5055280;
    /* @5055268 call */
    GM_SITE(vm, 1058, 5055268);
    /* @5055276 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5055280: ;
    /* @5055280 constant */
    /* @5055284 store */
    GM_WRITE(vm, -1, "goto", VAL(104));
    L_5055292: ;
    return;
}
