/* generated from CODE 407 (gml_Object_obj_foundweapon_Step_0), source start 4520044, end 4520100. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0407(GmVM* vm) {
    Val v1;
    /* @4520044 load */
    /* @4520052 constant */
    /* @4520056 cmp */
    /* @4520060 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4520100;
    /* @4520064 constant */
    /* @4520068 cast */
    /* @4520072 call */
    GM_SITE(vm, 407, 4520072);
    /* @4520080 cast */
    /* @4520084 bf */
    v1 = BOOL(GM_CALL(vm, "mouse_check_button_pressed", 1, VAL(1)));
    if (!TRUTH(v1)) goto L_4520100;
    /* @4520088 call */
    GM_SITE(vm, 407, 4520088);
    /* @4520096 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4520100: ;
    return;
}
