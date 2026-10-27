/* generated from CODE 412 (gml_Object_obj_weaponchange_Step_0), source start 4536776, end 4536832. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0412(GmVM* vm) {
    Val v1;
    /* @4536776 load */
    /* @4536784 constant */
    /* @4536788 cmp */
    /* @4536792 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4536832;
    /* @4536796 constant */
    /* @4536800 cast */
    /* @4536804 call */
    GM_SITE(vm, 412, 4536804);
    /* @4536812 cast */
    /* @4536816 bf */
    v1 = BOOL(GM_CALL(vm, "mouse_check_button_pressed", 1, VAL(1)));
    if (!TRUTH(v1)) goto L_4536832;
    /* @4536820 call */
    GM_SITE(vm, 412, 4536820);
    /* @4536828 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4536832: ;
    return;
}
