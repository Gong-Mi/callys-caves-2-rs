/* generated from CODE 1268 (gml_RoomCC_rm_mapview0_1268_Create), source start 5064488, end 5064532. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1268(GmVM* vm) {
    /* @5064488 load */
    /* @5064496 constant */
    /* @5064500 cmp */
    /* @5064504 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level1visited") == VAL(0)))) goto L_5064520;
    /* @5064508 call */
    GM_SITE(vm, 1268, 5064508);
    /* @5064516 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5064520: ;
    /* @5064520 constant */
    /* @5064524 store */
    GM_WRITE(vm, -1, "goto", VAL(1));
    L_5064532: ;
    return;
}
