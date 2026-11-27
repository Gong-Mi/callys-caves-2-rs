/* generated from CODE 1168 (gml_RoomCC_rm_mapview3_1168_Create), source start 5060088, end 5060132. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1168(GmVM* vm) {
    /* @5060088 load */
    /* @5060096 constant */
    /* @5060100 cmp */
    /* @5060104 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level5visited") == VAL(0)))) goto L_5060120;
    /* @5060108 call */
    GM_SITE(vm, 1168, 5060108);
    /* @5060116 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5060120: ;
    /* @5060120 constant */
    /* @5060124 store */
    GM_WRITE(vm, -1, "goto", VAL(5));
    L_5060132: ;
    return;
}
