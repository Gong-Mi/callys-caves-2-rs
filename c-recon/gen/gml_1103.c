/* generated from CODE 1103 (gml_RoomCC_rm_map_1103_Create), source start 5057228, end 5057272. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1103(GmVM* vm) {
    /* @5057228 load */
    /* @5057236 constant */
    /* @5057240 cmp */
    /* @5057244 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level16visited") == VAL(0)))) goto L_5057260;
    /* @5057248 call */
    GM_SITE(vm, 1103, 5057248);
    /* @5057256 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5057260: ;
    /* @5057260 constant */
    /* @5057264 store */
    GM_WRITE(vm, -1, "goto", VAL(23));
    L_5057272: ;
    return;
}
