/* generated from CODE 1042 (gml_RoomCC_rm_map_1042_Create), source start 5054544, end 5054588. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1042(GmVM* vm) {
    /* @5054544 load */
    /* @5054552 constant */
    /* @5054556 cmp */
    /* @5054560 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room90visited") == VAL(0)))) goto L_5054576;
    /* @5054564 call */
    GM_SITE(vm, 1042, 5054564);
    /* @5054572 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5054576: ;
    /* @5054576 constant */
    /* @5054580 store */
    GM_WRITE(vm, -1, "goto", VAL(90));
    L_5054588: ;
    return;
}
