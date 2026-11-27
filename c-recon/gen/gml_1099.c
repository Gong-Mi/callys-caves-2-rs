/* generated from CODE 1099 (gml_RoomCC_rm_map_1099_Create), source start 5057052, end 5057096. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1099(GmVM* vm) {
    /* @5057052 load */
    /* @5057060 constant */
    /* @5057064 cmp */
    /* @5057068 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level15visited") == VAL(0)))) goto L_5057084;
    /* @5057072 call */
    GM_SITE(vm, 1099, 5057072);
    /* @5057080 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5057084: ;
    /* @5057084 constant */
    /* @5057088 store */
    GM_WRITE(vm, -1, "goto", VAL(21));
    L_5057096: ;
    return;
}
