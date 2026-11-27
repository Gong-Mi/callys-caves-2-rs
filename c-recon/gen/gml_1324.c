/* generated from CODE 1324 (gml_RoomCC_rm_mapview0_1324_Create), source start 5066952, end 5066996. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1324(GmVM* vm) {
    /* @5066952 load */
    /* @5066960 constant */
    /* @5066964 cmp */
    /* @5066968 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room33visited") == VAL(0)))) goto L_5066984;
    /* @5066972 call */
    GM_SITE(vm, 1324, 5066972);
    /* @5066980 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5066984: ;
    /* @5066984 constant */
    /* @5066988 store */
    GM_WRITE(vm, -1, "goto", VAL(30));
    L_5066996: ;
    return;
}
