/* generated from CODE 1215 (gml_RoomCC_rm_mapview3_1215_Create), source start 5062156, end 5062200. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1215(GmVM* vm) {
    /* @5062156 load */
    /* @5062164 constant */
    /* @5062168 cmp */
    /* @5062172 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room82visited") == VAL(0)))) goto L_5062188;
    /* @5062176 call */
    GM_SITE(vm, 1215, 5062176);
    /* @5062184 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5062188: ;
    /* @5062188 constant */
    /* @5062192 store */
    GM_WRITE(vm, -1, "goto", VAL(81));
    L_5062200: ;
    return;
}
