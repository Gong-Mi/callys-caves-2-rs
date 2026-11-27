/* generated from CODE 1135 (gml_RoomCC_rm_mapview3_1135_Create), source start 5058636, end 5058680. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1135(GmVM* vm) {
    /* @5058636 load */
    /* @5058644 constant */
    /* @5058648 cmp */
    /* @5058652 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room43visited") == VAL(0)))) goto L_5058668;
    /* @5058656 call */
    GM_SITE(vm, 1135, 5058656);
    /* @5058664 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5058668: ;
    /* @5058668 constant */
    /* @5058672 store */
    GM_WRITE(vm, -1, "goto", VAL(40));
    L_5058680: ;
    return;
}
