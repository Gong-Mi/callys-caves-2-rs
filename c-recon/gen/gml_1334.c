/* generated from CODE 1334 (gml_RoomCC_rm_mapview0_1334_Create), source start 5067392, end 5067436. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1334(GmVM* vm) {
    /* @5067392 load */
    /* @5067400 constant */
    /* @5067404 cmp */
    /* @5067408 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room38visited") == VAL(0)))) goto L_5067424;
    /* @5067412 call */
    GM_SITE(vm, 1334, 5067412);
    /* @5067420 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5067424: ;
    /* @5067424 constant */
    /* @5067428 store */
    GM_WRITE(vm, -1, "goto", VAL(35));
    L_5067436: ;
    return;
}
