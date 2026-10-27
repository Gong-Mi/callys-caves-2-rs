/* generated from CODE 1304 (gml_RoomCC_rm_mapview0_1304_Create), source start 5066072, end 5066116. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1304(GmVM* vm) {
    /* @5066072 load */
    /* @5066080 constant */
    /* @5066084 cmp */
    /* @5066088 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room72visited") == VAL(0)))) goto L_5066104;
    /* @5066092 call */
    GM_SITE(vm, 1304, 5066092);
    /* @5066100 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5066104: ;
    /* @5066104 constant */
    /* @5066108 store */
    GM_WRITE(vm, -1, "goto", VAL(71));
    L_5066116: ;
    return;
}
