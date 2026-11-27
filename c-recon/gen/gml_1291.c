/* generated from CODE 1291 (gml_RoomCC_rm_mapview0_1291_Create), source start 5065500, end 5065544. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1291(GmVM* vm) {
    /* @5065500 load */
    /* @5065508 constant */
    /* @5065512 cmp */
    /* @5065516 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level10visited") == VAL(0)))) goto L_5065532;
    /* @5065520 call */
    GM_SITE(vm, 1291, 5065520);
    /* @5065528 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5065532: ;
    /* @5065532 constant */
    /* @5065536 store */
    GM_WRITE(vm, -1, "goto", VAL(13));
    L_5065544: ;
    return;
}
