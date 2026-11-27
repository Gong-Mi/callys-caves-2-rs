/* generated from CODE 543 (gml_Object_obj_youhavedied_Mouse_7), source start 4841236, end 4841268. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0543(GmVM* vm) {
    /* @4841236 load */
    /* @4841244 constant */
    /* @4841248 cmp */
    /* @4841252 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4841268;
    /* @4841256 call */
    GM_SITE(vm, 543, 4841256);
    /* @4841264 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4841268: ;
    return;
}
