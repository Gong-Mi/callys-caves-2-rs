/* generated from CODE 1174 (gml_RoomCC_rm_mapview3_1174_Create), source start 5060352, end 5060396. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1174(GmVM* vm) {
    /* @5060352 load */
    /* @5060360 constant */
    /* @5060364 cmp */
    /* @5060368 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level8visited") == VAL(0)))) goto L_5060384;
    /* @5060372 call */
    GM_SITE(vm, 1174, 5060372);
    /* @5060380 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5060384: ;
    /* @5060384 constant */
    /* @5060388 store */
    GM_WRITE(vm, -1, "goto", VAL(8));
    L_5060396: ;
    return;
}
