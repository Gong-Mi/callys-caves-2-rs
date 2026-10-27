/* generated from CODE 1325 (gml_RoomCC_rm_mapview0_1325_Create), source start 5066996, end 5067040. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1325(GmVM* vm) {
    /* @5066996 load */
    /* @5067004 constant */
    /* @5067008 cmp */
    /* @5067012 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boss5visited") == VAL(0)))) goto L_5067028;
    /* @5067016 call */
    GM_SITE(vm, 1325, 5067016);
    /* @5067024 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5067028: ;
    /* @5067028 constant */
    /* @5067032 store */
    GM_WRITE(vm, -1, "goto", VAL(82));
    L_5067040: ;
    return;
}
