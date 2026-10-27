/* generated from CODE 1353 (gml_RoomCC_rm_mapview0_1353_Create), source start 5068228, end 5068272. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1353(GmVM* vm) {
    /* @5068228 load */
    /* @5068236 constant */
    /* @5068240 cmp */
    /* @5068244 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "levelchallenge5visited") == VAL(0)))) goto L_5068260;
    /* @5068248 call */
    GM_SITE(vm, 1353, 5068248);
    /* @5068256 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5068260: ;
    /* @5068260 constant */
    /* @5068264 store */
    GM_WRITE(vm, -1, "goto", VAL(109));
    L_5068272: ;
    return;
}
