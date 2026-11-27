/* generated from CODE 463 (gml_Object_obj_weaponname_Step_0), source start 4643396, end 4643460. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0463(GmVM* vm) {
    /* @4643396 load */
    /* @4643404 constant */
    /* @4643416 sub */
    /* @4643420 store */
    GM_WRITE(vm, -1, "alpha", (GM_READ(vm, -1, "alpha") - VAL(0.04)));
    /* @4643428 load */
    /* @4643436 constant */
    /* @4643440 cmp */
    /* @4643444 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "alpha") < VAL(0)))) goto L_4643460;
    /* @4643448 call */
    GM_SITE(vm, 463, 4643448);
    /* @4643456 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4643460: ;
    return;
}
