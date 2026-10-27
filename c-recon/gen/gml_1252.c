/* generated from CODE 1252 (gml_RoomCC_rm_mapview0_1252_Create), source start 5063784, end 5063828. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1252(GmVM* vm) {
    /* @5063784 load */
    /* @5063792 constant */
    /* @5063796 cmp */
    /* @5063800 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room47visited") == VAL(0)))) goto L_5063816;
    /* @5063804 call */
    GM_SITE(vm, 1252, 5063804);
    /* @5063812 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5063816: ;
    /* @5063816 constant */
    /* @5063820 store */
    GM_WRITE(vm, -1, "goto", VAL(44));
    L_5063828: ;
    return;
}
