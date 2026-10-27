/* generated from CODE 1107 (gml_RoomCC_rm_map_1107_Create), source start 5057404, end 5057448. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1107(GmVM* vm) {
    /* @5057404 load */
    /* @5057412 constant */
    /* @5057416 cmp */
    /* @5057420 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level17visited") == VAL(0)))) goto L_5057436;
    /* @5057424 call */
    GM_SITE(vm, 1107, 5057424);
    /* @5057432 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5057436: ;
    /* @5057436 constant */
    /* @5057440 store */
    GM_WRITE(vm, -1, "goto", VAL(25));
    L_5057448: ;
    return;
}
