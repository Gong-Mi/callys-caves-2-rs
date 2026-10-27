/* generated from CODE 1196 (gml_RoomCC_rm_mapview3_1196_Create), source start 5061320, end 5061364. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1196(GmVM* vm) {
    /* @5061320 load */
    /* @5061328 constant */
    /* @5061332 cmp */
    /* @5061336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room72visited") == VAL(0)))) goto L_5061352;
    /* @5061340 call */
    GM_SITE(vm, 1196, 5061340);
    /* @5061348 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5061352: ;
    /* @5061352 constant */
    /* @5061356 store */
    GM_WRITE(vm, -1, "goto", VAL(71));
    L_5061364: ;
    return;
}
