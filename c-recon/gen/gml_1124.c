/* generated from CODE 1124 (gml_RoomCC_rm_map_1124_Create), source start 5058152, end 5058196. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1124(GmVM* vm) {
    /* @5058152 load */
    /* @5058160 constant */
    /* @5058164 cmp */
    /* @5058168 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room37visited") == VAL(0)))) goto L_5058184;
    /* @5058172 call */
    GM_SITE(vm, 1124, 5058172);
    /* @5058180 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5058184: ;
    /* @5058184 constant */
    /* @5058188 store */
    GM_WRITE(vm, -1, "goto", VAL(34));
    L_5058196: ;
    return;
}
