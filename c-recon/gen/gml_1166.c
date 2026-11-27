/* generated from CODE 1166 (gml_RoomCC_rm_mapview3_1166_Create), source start 5060000, end 5060044. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1166(GmVM* vm) {
    /* @5060000 load */
    /* @5060008 constant */
    /* @5060012 cmp */
    /* @5060016 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level4visited") == VAL(0)))) goto L_5060032;
    /* @5060020 call */
    GM_SITE(vm, 1166, 5060020);
    /* @5060028 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5060032: ;
    /* @5060032 constant */
    /* @5060036 store */
    GM_WRITE(vm, -1, "goto", VAL(4));
    L_5060044: ;
    return;
}
