/* generated from CODE 1303 (gml_RoomCC_rm_mapview0_1303_Create), source start 5066028, end 5066072. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1303(GmVM* vm) {
    /* @5066028 load */
    /* @5066036 constant */
    /* @5066040 cmp */
    /* @5066044 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level14visited") == VAL(0)))) goto L_5066060;
    /* @5066048 call */
    GM_SITE(vm, 1303, 5066048);
    /* @5066056 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5066060: ;
    /* @5066060 constant */
    /* @5066064 store */
    GM_WRITE(vm, -1, "goto", VAL(19));
    L_5066072: ;
    return;
}
