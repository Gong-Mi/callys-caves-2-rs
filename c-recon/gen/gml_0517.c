/* generated from CODE 517 (gml_Object_obj_pausebutton_Mouse_7), source start 4714540, end 4714600. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0517(GmVM* vm) {
    Val v1;
    /* @4714540 load */
    /* @4714548 constant */
    /* @4714552 add */
    /* @4714556 store */
    v1 = GM_ADD(GM_READ(vm, -5, "timespaused"), VAL(1));
    GM_WRITE(vm, -5, "timespaused", v1);
    /* @4714564 constant */
    /* @4714568 cast */
    /* @4714572 load */
    /* @4714580 load */
    /* @4714588 call */
    GM_SITE(vm, 517, 4714588);
    /* @4714596 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(118)));
    L_4714600: ;
    return;
}
