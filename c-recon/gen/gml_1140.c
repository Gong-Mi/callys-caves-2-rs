/* generated from CODE 1140 (gml_RoomCC_rm_mapview3_1140_Create), source start 5058856, end 5058900. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1140(GmVM* vm) {
    /* @5058856 load */
    /* @5058864 constant */
    /* @5058868 cmp */
    /* @5058872 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room44visited") == VAL(0)))) goto L_5058888;
    /* @5058876 call */
    GM_SITE(vm, 1140, 5058876);
    /* @5058884 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5058888: ;
    /* @5058888 constant */
    /* @5058892 store */
    GM_WRITE(vm, -1, "goto", VAL(41));
    L_5058900: ;
    return;
}
