/* generated from CODE 1118 (gml_RoomCC_rm_map_1118_Create), source start 5057888, end 5057932. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1118(GmVM* vm) {
    /* @5057888 load */
    /* @5057896 constant */
    /* @5057900 cmp */
    /* @5057904 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room34visited") == VAL(0)))) goto L_5057920;
    /* @5057908 call */
    GM_SITE(vm, 1118, 5057908);
    /* @5057916 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5057920: ;
    /* @5057920 constant */
    /* @5057924 store */
    GM_WRITE(vm, -1, "goto", VAL(31));
    L_5057932: ;
    return;
}
