/* generated from CODE 1036 (gml_RoomCC_rm_map_1036_Create), source start 5054280, end 5054324. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1036(GmVM* vm) {
    /* @5054280 load */
    /* @5054288 constant */
    /* @5054292 cmp */
    /* @5054296 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room89visited") == VAL(0)))) goto L_5054312;
    /* @5054300 call */
    GM_SITE(vm, 1036, 5054300);
    /* @5054308 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5054312: ;
    /* @5054312 constant */
    /* @5054316 store */
    GM_WRITE(vm, -1, "goto", VAL(89));
    L_5054324: ;
    return;
}
