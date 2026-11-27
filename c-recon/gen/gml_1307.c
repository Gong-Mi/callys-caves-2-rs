/* generated from CODE 1307 (gml_RoomCC_rm_mapview0_1307_Create), source start 5066204, end 5066248. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1307(GmVM* vm) {
    /* @5066204 load */
    /* @5066212 constant */
    /* @5066216 cmp */
    /* @5066220 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level15visited") == VAL(0)))) goto L_5066236;
    /* @5066224 call */
    GM_SITE(vm, 1307, 5066224);
    /* @5066232 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5066236: ;
    /* @5066236 constant */
    /* @5066240 store */
    GM_WRITE(vm, -1, "goto", VAL(21));
    L_5066248: ;
    return;
}
