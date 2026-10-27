/* generated from CODE 1128 (gml_RoomCC_rm_map_1128_Create), source start 5058328, end 5058372. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1128(GmVM* vm) {
    /* @5058328 load */
    /* @5058336 constant */
    /* @5058340 cmp */
    /* @5058344 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "levelchallenge1visited") == VAL(0)))) goto L_5058360;
    /* @5058348 call */
    GM_SITE(vm, 1128, 5058348);
    /* @5058356 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5058360: ;
    /* @5058360 constant */
    /* @5058364 store */
    GM_WRITE(vm, -1, "goto", VAL(105));
    L_5058372: ;
    return;
}
