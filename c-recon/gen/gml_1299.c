/* generated from CODE 1299 (gml_RoomCC_rm_mapview0_1299_Create), source start 5065852, end 5065896. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1299(GmVM* vm) {
    /* @5065852 load */
    /* @5065860 constant */
    /* @5065864 cmp */
    /* @5065868 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level13visited") == VAL(0)))) goto L_5065884;
    /* @5065872 call */
    GM_SITE(vm, 1299, 5065872);
    /* @5065880 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5065884: ;
    /* @5065884 constant */
    /* @5065888 store */
    GM_WRITE(vm, -1, "goto", VAL(17));
    L_5065896: ;
    return;
}
