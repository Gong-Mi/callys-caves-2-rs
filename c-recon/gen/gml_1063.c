/* generated from CODE 1063 (gml_RoomCC_rm_map_1063_Create), source start 5055468, end 5055512. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1063(GmVM* vm) {
    /* @5055468 load */
    /* @5055476 constant */
    /* @5055480 cmp */
    /* @5055484 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room56visited") == VAL(0)))) goto L_5055500;
    /* @5055488 call */
    GM_SITE(vm, 1063, 5055488);
    /* @5055496 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5055500: ;
    /* @5055500 constant */
    /* @5055504 store */
    GM_WRITE(vm, -1, "goto", VAL(54));
    L_5055512: ;
    return;
}
