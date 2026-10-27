/* generated from CODE 1189 (gml_RoomCC_rm_mapview3_1189_Create), source start 5061012, end 5061056. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1189(GmVM* vm) {
    /* @5061012 load */
    /* @5061020 constant */
    /* @5061024 cmp */
    /* @5061028 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level12visited") == VAL(0)))) goto L_5061044;
    /* @5061032 call */
    GM_SITE(vm, 1189, 5061032);
    /* @5061040 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5061044: ;
    /* @5061044 constant */
    /* @5061048 store */
    GM_WRITE(vm, -1, "goto", VAL(16));
    L_5061056: ;
    return;
}
