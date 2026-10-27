/* generated from CODE 1253 (gml_RoomCC_rm_mapview0_1253_Create), source start 5063828, end 5063872. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1253(GmVM* vm) {
    /* @5063828 load */
    /* @5063836 constant */
    /* @5063840 cmp */
    /* @5063844 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room96visited") == VAL(0)))) goto L_5063860;
    /* @5063848 call */
    GM_SITE(vm, 1253, 5063848);
    /* @5063856 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5063860: ;
    /* @5063860 constant */
    /* @5063864 store */
    GM_WRITE(vm, -1, "goto", VAL(96));
    L_5063872: ;
    return;
}
