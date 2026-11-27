/* generated from CODE 1322 (gml_RoomCC_rm_mapview0_1322_Create), source start 5066864, end 5066908. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1322(GmVM* vm) {
    /* @5066864 load */
    /* @5066872 constant */
    /* @5066876 cmp */
    /* @5066880 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room32visited") == VAL(0)))) goto L_5066896;
    /* @5066884 call */
    GM_SITE(vm, 1322, 5066884);
    /* @5066892 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5066896: ;
    /* @5066896 constant */
    /* @5066900 store */
    GM_WRITE(vm, -1, "goto", VAL(29));
    L_5066908: ;
    return;
}
