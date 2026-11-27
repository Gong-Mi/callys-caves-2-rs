/* generated from CODE 1270 (gml_RoomCC_rm_mapview0_1270_Create), source start 5064576, end 5064620. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1270(GmVM* vm) {
    /* @5064576 load */
    /* @5064584 constant */
    /* @5064588 cmp */
    /* @5064592 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level2visited") == VAL(0)))) goto L_5064608;
    /* @5064596 call */
    GM_SITE(vm, 1270, 5064596);
    /* @5064604 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5064608: ;
    /* @5064608 constant */
    /* @5064612 store */
    GM_WRITE(vm, -1, "goto", VAL(2));
    L_5064620: ;
    return;
}
