/* generated from CODE 1209 (gml_RoomCC_rm_mapview3_1209_Create), source start 5061892, end 5061936. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1209(GmVM* vm) {
    /* @5061892 load */
    /* @5061900 constant */
    /* @5061904 cmp */
    /* @5061908 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room79visited") == VAL(0)))) goto L_5061924;
    /* @5061912 call */
    GM_SITE(vm, 1209, 5061912);
    /* @5061920 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5061924: ;
    /* @5061924 constant */
    /* @5061928 store */
    GM_WRITE(vm, -1, "goto", VAL(78));
    L_5061936: ;
    return;
}
