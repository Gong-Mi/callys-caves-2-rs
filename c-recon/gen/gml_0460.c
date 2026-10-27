/* generated from CODE 460 (gml_Object_obj_damage_Step_0), source start 4642760, end 4642824. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0460(GmVM* vm) {
    /* @4642760 load */
    /* @4642768 constant */
    /* @4642780 sub */
    /* @4642784 store */
    GM_WRITE(vm, -1, "alpha", (GM_READ(vm, -1, "alpha") - VAL(0.04)));
    /* @4642792 load */
    /* @4642800 constant */
    /* @4642804 cmp */
    /* @4642808 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "alpha") < VAL(0)))) goto L_4642824;
    /* @4642812 call */
    GM_SITE(vm, 460, 4642812);
    /* @4642820 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4642824: ;
    return;
}
