/* generated from CODE 1059 (gml_RoomCC_rm_map_1059_Create), source start 5055292, end 5055336. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1059(GmVM* vm) {
    /* @5055292 load */
    /* @5055300 constant */
    /* @5055304 cmp */
    /* @5055308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room54visited") == VAL(0)))) goto L_5055324;
    /* @5055312 call */
    GM_SITE(vm, 1059, 5055312);
    /* @5055320 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5055324: ;
    /* @5055324 constant */
    /* @5055328 store */
    GM_WRITE(vm, -1, "goto", VAL(52));
    L_5055336: ;
    return;
}
