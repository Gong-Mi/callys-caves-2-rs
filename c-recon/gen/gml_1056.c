/* generated from CODE 1056 (gml_RoomCC_rm_map_1056_Create), source start 5055160, end 5055204. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1056(GmVM* vm) {
    /* @5055160 load */
    /* @5055168 constant */
    /* @5055172 cmp */
    /* @5055176 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room102visited") == VAL(0)))) goto L_5055192;
    /* @5055180 call */
    GM_SITE(vm, 1056, 5055180);
    /* @5055188 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5055192: ;
    /* @5055192 constant */
    /* @5055196 store */
    GM_WRITE(vm, -1, "goto", VAL(102));
    L_5055204: ;
    return;
}
