/* generated from CODE 1286 (gml_RoomCC_rm_mapview0_1286_Create), source start 5065280, end 5065324. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1286(GmVM* vm) {
    /* @5065280 load */
    /* @5065288 constant */
    /* @5065292 cmp */
    /* @5065296 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boss1visited") == VAL(0)))) goto L_5065312;
    /* @5065300 call */
    GM_SITE(vm, 1286, 5065300);
    /* @5065308 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5065312: ;
    /* @5065312 constant */
    /* @5065316 store */
    GM_WRITE(vm, -1, "goto", VAL(10));
    L_5065324: ;
    return;
}
