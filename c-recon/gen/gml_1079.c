/* generated from CODE 1079 (gml_RoomCC_rm_map_1079_Create), source start 5056172, end 5056216. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1079(GmVM* vm) {
    /* @5056172 load */
    /* @5056180 constant */
    /* @5056184 cmp */
    /* @5056188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room64visited") == VAL(0)))) goto L_5056204;
    /* @5056192 call */
    GM_SITE(vm, 1079, 5056192);
    /* @5056200 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5056204: ;
    /* @5056204 constant */
    /* @5056208 store */
    GM_WRITE(vm, -1, "goto", VAL(62));
    L_5056216: ;
    return;
}
