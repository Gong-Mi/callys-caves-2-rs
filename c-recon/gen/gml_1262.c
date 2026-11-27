/* generated from CODE 1262 (gml_RoomCC_rm_mapview0_1262_Create), source start 5064224, end 5064268. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1262(GmVM* vm) {
    /* @5064224 load */
    /* @5064232 constant */
    /* @5064236 cmp */
    /* @5064240 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room51visited") == VAL(0)))) goto L_5064256;
    /* @5064244 call */
    GM_SITE(vm, 1262, 5064244);
    /* @5064252 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5064256: ;
    /* @5064256 constant */
    /* @5064260 store */
    GM_WRITE(vm, -1, "goto", VAL(49));
    L_5064268: ;
    return;
}
