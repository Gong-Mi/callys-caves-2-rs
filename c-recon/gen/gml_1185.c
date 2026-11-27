/* generated from CODE 1185 (gml_RoomCC_rm_mapview3_1185_Create), source start 5060836, end 5060880. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1185(GmVM* vm) {
    /* @5060836 load */
    /* @5060844 constant */
    /* @5060848 cmp */
    /* @5060852 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level11visited") == VAL(0)))) goto L_5060868;
    /* @5060856 call */
    GM_SITE(vm, 1185, 5060856);
    /* @5060864 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5060868: ;
    /* @5060868 constant */
    /* @5060872 store */
    GM_WRITE(vm, -1, "goto", VAL(14));
    L_5060880: ;
    return;
}
