/* generated from CODE 1122 (gml_RoomCC_rm_map_1122_Create), source start 5058064, end 5058108. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1122(GmVM* vm) {
    /* @5058064 load */
    /* @5058072 constant */
    /* @5058076 cmp */
    /* @5058080 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room36visited") == VAL(0)))) goto L_5058096;
    /* @5058084 call */
    GM_SITE(vm, 1122, 5058084);
    /* @5058092 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5058096: ;
    /* @5058096 constant */
    /* @5058100 store */
    GM_WRITE(vm, -1, "goto", VAL(33));
    L_5058108: ;
    return;
}
