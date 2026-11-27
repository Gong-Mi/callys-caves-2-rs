/* generated from CODE 1055 (gml_RoomCC_rm_map_1055_Create), source start 5055116, end 5055160. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1055(GmVM* vm) {
    /* @5055116 load */
    /* @5055124 constant */
    /* @5055128 cmp */
    /* @5055132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room52visited") == VAL(0)))) goto L_5055148;
    /* @5055136 call */
    GM_SITE(vm, 1055, 5055136);
    /* @5055144 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5055148: ;
    /* @5055148 constant */
    /* @5055152 store */
    GM_WRITE(vm, -1, "goto", VAL(50));
    L_5055160: ;
    return;
}
