/* generated from CODE 466 (gml_Object_obj_dodged_Step_0), source start 4644440, end 4644504. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0466(GmVM* vm) {
    /* @4644440 load */
    /* @4644448 constant */
    /* @4644460 sub */
    /* @4644464 store */
    GM_WRITE(vm, -1, "alpha", (GM_READ(vm, -1, "alpha") - VAL(0.04)));
    /* @4644472 load */
    /* @4644480 constant */
    /* @4644484 cmp */
    /* @4644488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "alpha") < VAL(0)))) goto L_4644504;
    /* @4644492 call */
    GM_SITE(vm, 466, 4644492);
    /* @4644500 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4644504: ;
    return;
}
