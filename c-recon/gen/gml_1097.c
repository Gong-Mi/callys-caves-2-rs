/* generated from CODE 1097 (gml_RoomCC_rm_map_1097_Create), source start 5056964, end 5057008. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1097(GmVM* vm) {
    /* @5056964 load */
    /* @5056972 constant */
    /* @5056976 cmp */
    /* @5056980 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level14avisited") == VAL(0)))) goto L_5056996;
    /* @5056984 call */
    GM_SITE(vm, 1097, 5056984);
    /* @5056992 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5056996: ;
    /* @5056996 constant */
    /* @5057000 store */
    GM_WRITE(vm, -1, "goto", VAL(20));
    L_5057008: ;
    return;
}
