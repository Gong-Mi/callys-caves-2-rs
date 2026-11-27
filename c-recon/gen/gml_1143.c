/* generated from CODE 1143 (gml_RoomCC_rm_mapview3_1143_Create), source start 5058988, end 5059032. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1143(GmVM* vm) {
    /* @5058988 load */
    /* @5058996 constant */
    /* @5059000 cmp */
    /* @5059004 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room47visited") == VAL(0)))) goto L_5059020;
    /* @5059008 call */
    GM_SITE(vm, 1143, 5059008);
    /* @5059016 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5059020: ;
    /* @5059020 constant */
    /* @5059024 store */
    GM_WRITE(vm, -1, "goto", VAL(44));
    L_5059032: ;
    return;
}
