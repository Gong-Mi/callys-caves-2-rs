/* generated from CODE 1147 (gml_RoomCC_rm_mapview3_1147_Create), source start 5059164, end 5059208. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1147(GmVM* vm) {
    /* @5059164 load */
    /* @5059172 constant */
    /* @5059176 cmp */
    /* @5059180 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room49visited") == VAL(0)))) goto L_5059196;
    /* @5059184 call */
    GM_SITE(vm, 1147, 5059184);
    /* @5059192 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5059196: ;
    /* @5059196 constant */
    /* @5059200 store */
    GM_WRITE(vm, -1, "goto", VAL(46));
    L_5059208: ;
    return;
}
