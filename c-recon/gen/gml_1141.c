/* generated from CODE 1141 (gml_RoomCC_rm_mapview3_1141_Create), source start 5058900, end 5058944. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1141(GmVM* vm) {
    /* @5058900 load */
    /* @5058908 constant */
    /* @5058912 cmp */
    /* @5058916 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room93visited") == VAL(0)))) goto L_5058932;
    /* @5058920 call */
    GM_SITE(vm, 1141, 5058920);
    /* @5058928 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5058932: ;
    /* @5058932 constant */
    /* @5058936 store */
    GM_WRITE(vm, -1, "goto", VAL(93));
    L_5058944: ;
    return;
}
