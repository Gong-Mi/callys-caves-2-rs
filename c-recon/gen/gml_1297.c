/* generated from CODE 1297 (gml_RoomCC_rm_mapview0_1297_Create), source start 5065764, end 5065808. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1297(GmVM* vm) {
    /* @5065764 load */
    /* @5065772 constant */
    /* @5065776 cmp */
    /* @5065780 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level12visited") == VAL(0)))) goto L_5065796;
    /* @5065784 call */
    GM_SITE(vm, 1297, 5065784);
    /* @5065792 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5065796: ;
    /* @5065796 constant */
    /* @5065800 store */
    GM_WRITE(vm, -1, "goto", VAL(16));
    L_5065808: ;
    return;
}
