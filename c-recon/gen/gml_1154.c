/* generated from CODE 1154 (gml_RoomCC_rm_mapview3_1154_Create), source start 5059472, end 5059516. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1154(GmVM* vm) {
    /* @5059472 load */
    /* @5059480 constant */
    /* @5059484 cmp */
    /* @5059488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room101visited") == VAL(0)))) goto L_5059504;
    /* @5059492 call */
    GM_SITE(vm, 1154, 5059492);
    /* @5059500 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5059504: ;
    /* @5059504 constant */
    /* @5059508 store */
    GM_WRITE(vm, -1, "goto", VAL(101));
    L_5059516: ;
    return;
}
