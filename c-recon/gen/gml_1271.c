/* generated from CODE 1271 (gml_RoomCC_rm_mapview0_1271_Create), source start 5064620, end 5064664. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1271(GmVM* vm) {
    /* @5064620 load */
    /* @5064628 constant */
    /* @5064632 cmp */
    /* @5064636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room56visited") == VAL(0)))) goto L_5064652;
    /* @5064640 call */
    GM_SITE(vm, 1271, 5064640);
    /* @5064648 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5064652: ;
    /* @5064652 constant */
    /* @5064656 store */
    GM_WRITE(vm, -1, "goto", VAL(54));
    L_5064664: ;
    return;
}
