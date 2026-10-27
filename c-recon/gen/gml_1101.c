/* generated from CODE 1101 (gml_RoomCC_rm_map_1101_Create), source start 5057140, end 5057184. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1101(GmVM* vm) {
    /* @5057140 load */
    /* @5057148 constant */
    /* @5057152 cmp */
    /* @5057156 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level15avisited") == VAL(0)))) goto L_5057172;
    /* @5057160 call */
    GM_SITE(vm, 1101, 5057160);
    /* @5057168 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5057172: ;
    /* @5057172 constant */
    /* @5057176 store */
    GM_WRITE(vm, -1, "goto", VAL(22));
    L_5057184: ;
    return;
}
