/* generated from CODE 1276 (gml_RoomCC_rm_mapview0_1276_Create), source start 5064840, end 5064884. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1276(GmVM* vm) {
    /* @5064840 load */
    /* @5064848 constant */
    /* @5064852 cmp */
    /* @5064856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level5visited") == VAL(0)))) goto L_5064872;
    /* @5064860 call */
    GM_SITE(vm, 1276, 5064860);
    /* @5064868 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5064872: ;
    /* @5064872 constant */
    /* @5064876 store */
    GM_WRITE(vm, -1, "goto", VAL(5));
    L_5064884: ;
    return;
}
