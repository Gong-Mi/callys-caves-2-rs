/* generated from CODE 1069 (gml_RoomCC_rm_map_1069_Create), source start 5055732, end 5055776. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1069(GmVM* vm) {
    /* @5055732 load */
    /* @5055740 constant */
    /* @5055744 cmp */
    /* @5055748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room59visited") == VAL(0)))) goto L_5055764;
    /* @5055752 call */
    GM_SITE(vm, 1069, 5055752);
    /* @5055760 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5055764: ;
    /* @5055764 constant */
    /* @5055768 store */
    GM_WRITE(vm, -1, "goto", VAL(57));
    L_5055776: ;
    return;
}
