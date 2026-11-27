/* generated from CODE 1119 (gml_RoomCC_rm_map_1119_Create), source start 5057932, end 5057976. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1119(GmVM* vm) {
    /* @5057932 load */
    /* @5057940 constant */
    /* @5057944 cmp */
    /* @5057948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room83visited") == VAL(0)))) goto L_5057964;
    /* @5057952 call */
    GM_SITE(vm, 1119, 5057952);
    /* @5057960 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5057964: ;
    /* @5057964 constant */
    /* @5057968 store */
    GM_WRITE(vm, -1, "goto", VAL(83));
    L_5057976: ;
    return;
}
