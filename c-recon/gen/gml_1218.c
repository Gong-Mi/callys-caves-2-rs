/* generated from CODE 1218 (gml_RoomCC_rm_mapview3_1218_Create), source start 5062288, end 5062332. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1218(GmVM* vm) {
    /* @5062288 load */
    /* @5062296 constant */
    /* @5062300 cmp */
    /* @5062304 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room34visited") == VAL(0)))) goto L_5062320;
    /* @5062308 call */
    GM_SITE(vm, 1218, 5062308);
    /* @5062316 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5062320: ;
    /* @5062320 constant */
    /* @5062324 store */
    GM_WRITE(vm, -1, "goto", VAL(31));
    L_5062332: ;
    return;
}
