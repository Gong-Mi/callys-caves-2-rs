/* generated from CODE 1057 (gml_RoomCC_rm_map_1057_Create), source start 5055204, end 5055248. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1057(GmVM* vm) {
    /* @5055204 load */
    /* @5055212 constant */
    /* @5055216 cmp */
    /* @5055220 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room53visited") == VAL(0)))) goto L_5055236;
    /* @5055224 call */
    GM_SITE(vm, 1057, 5055224);
    /* @5055232 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5055236: ;
    /* @5055236 constant */
    /* @5055240 store */
    GM_WRITE(vm, -1, "goto", VAL(51));
    L_5055248: ;
    return;
}
