/* generated from CODE 1127 (gml_RoomCC_rm_map_1127_Create), source start 5058284, end 5058328. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1127(GmVM* vm) {
    /* @5058284 load */
    /* @5058292 constant */
    /* @5058296 cmp */
    /* @5058300 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room87visited") == VAL(0)))) goto L_5058316;
    /* @5058304 call */
    GM_SITE(vm, 1127, 5058304);
    /* @5058312 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5058316: ;
    /* @5058316 constant */
    /* @5058320 store */
    GM_WRITE(vm, -1, "goto", VAL(87));
    L_5058328: ;
    return;
}
