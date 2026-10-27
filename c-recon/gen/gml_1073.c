/* generated from CODE 1073 (gml_RoomCC_rm_map_1073_Create), source start 5055908, end 5055952. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1073(GmVM* vm) {
    /* @5055908 load */
    /* @5055916 constant */
    /* @5055920 cmp */
    /* @5055924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room61visited") == VAL(0)))) goto L_5055940;
    /* @5055928 call */
    GM_SITE(vm, 1073, 5055928);
    /* @5055936 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5055940: ;
    /* @5055940 constant */
    /* @5055944 store */
    GM_WRITE(vm, -1, "goto", VAL(59));
    L_5055952: ;
    return;
}
