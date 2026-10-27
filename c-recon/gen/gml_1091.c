/* generated from CODE 1091 (gml_RoomCC_rm_map_1091_Create), source start 5056700, end 5056744. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1091(GmVM* vm) {
    /* @5056700 load */
    /* @5056708 constant */
    /* @5056712 cmp */
    /* @5056716 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level13visited") == VAL(0)))) goto L_5056732;
    /* @5056720 call */
    GM_SITE(vm, 1091, 5056720);
    /* @5056728 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5056732: ;
    /* @5056732 constant */
    /* @5056736 store */
    GM_WRITE(vm, -1, "goto", VAL(17));
    L_5056744: ;
    return;
}
