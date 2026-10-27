/* generated from CODE 1074 (gml_RoomCC_rm_map_1074_Create), source start 5055952, end 5055996. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1074(GmVM* vm) {
    /* @5055952 load */
    /* @5055960 constant */
    /* @5055964 cmp */
    /* @5055968 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level8visited") == VAL(0)))) goto L_5055984;
    /* @5055972 call */
    GM_SITE(vm, 1074, 5055972);
    /* @5055980 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5055984: ;
    /* @5055984 constant */
    /* @5055988 store */
    GM_WRITE(vm, -1, "goto", VAL(8));
    L_5055996: ;
    return;
}
