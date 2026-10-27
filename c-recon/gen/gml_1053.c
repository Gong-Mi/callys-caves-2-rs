/* generated from CODE 1053 (gml_RoomCC_rm_map_1053_Create), source start 5055028, end 5055072. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1053(GmVM* vm) {
    /* @5055028 load */
    /* @5055036 constant */
    /* @5055040 cmp */
    /* @5055044 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room51visited") == VAL(0)))) goto L_5055060;
    /* @5055048 call */
    GM_SITE(vm, 1053, 5055048);
    /* @5055056 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5055060: ;
    /* @5055060 constant */
    /* @5055064 store */
    GM_WRITE(vm, -1, "goto", VAL(49));
    L_5055072: ;
    return;
}
