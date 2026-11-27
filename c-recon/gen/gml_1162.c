/* generated from CODE 1162 (gml_RoomCC_rm_mapview3_1162_Create), source start 5059824, end 5059868. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1162(GmVM* vm) {
    /* @5059824 load */
    /* @5059832 constant */
    /* @5059836 cmp */
    /* @5059840 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level2visited") == VAL(0)))) goto L_5059856;
    /* @5059844 call */
    GM_SITE(vm, 1162, 5059844);
    /* @5059852 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5059856: ;
    /* @5059856 constant */
    /* @5059860 store */
    GM_WRITE(vm, -1, "goto", VAL(2));
    L_5059868: ;
    return;
}
