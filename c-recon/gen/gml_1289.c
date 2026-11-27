/* generated from CODE 1289 (gml_RoomCC_rm_mapview0_1289_Create), source start 5065412, end 5065456. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1289(GmVM* vm) {
    /* @5065412 load */
    /* @5065420 constant */
    /* @5065424 cmp */
    /* @5065428 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room65visited") == VAL(0)))) goto L_5065444;
    /* @5065432 call */
    GM_SITE(vm, 1289, 5065432);
    /* @5065440 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5065444: ;
    /* @5065444 constant */
    /* @5065448 store */
    GM_WRITE(vm, -1, "goto", VAL(63));
    L_5065456: ;
    return;
}
