/* generated from CODE 1072 (gml_RoomCC_rm_map_1072_Create), source start 5055864, end 5055908. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1072(GmVM* vm) {
    /* @5055864 load */
    /* @5055872 constant */
    /* @5055876 cmp */
    /* @5055880 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level7visited") == VAL(0)))) goto L_5055896;
    /* @5055884 call */
    GM_SITE(vm, 1072, 5055884);
    /* @5055892 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5055896: ;
    /* @5055896 constant */
    /* @5055900 store */
    GM_WRITE(vm, -1, "goto", VAL(7));
    L_5055908: ;
    return;
}
