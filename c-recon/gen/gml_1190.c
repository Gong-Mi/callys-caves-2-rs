/* generated from CODE 1190 (gml_RoomCC_rm_mapview3_1190_Create), source start 5061056, end 5061100. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1190(GmVM* vm) {
    /* @5061056 load */
    /* @5061064 constant */
    /* @5061068 cmp */
    /* @5061072 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room69visited") == VAL(0)))) goto L_5061088;
    /* @5061076 call */
    GM_SITE(vm, 1190, 5061076);
    /* @5061084 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5061088: ;
    /* @5061088 constant */
    /* @5061092 store */
    GM_WRITE(vm, -1, "goto", VAL(68));
    L_5061100: ;
    return;
}
