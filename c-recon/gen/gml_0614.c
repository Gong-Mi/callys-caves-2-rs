/* generated from CODE 614 (gml_Object_obj_lloydtutorial9_Create_0), source start 4931460, end 4931604. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0614(GmVM* vm) {
    /* @4931460 constant */
    /* @4931464 cast */
    /* @4931468 call */
    GM_SITE(vm, 614, 4931468);
    /* @4931476 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(1)));
    /* @4931480 constant */
    /* @4931484 store */
    GM_WRITE(vm, -1, "taplock", VAL(0));
    /* @4931492 constant */
    /* @4931496 store */
    GM_WRITE(vm, -1, "drawpanel1", VAL(1));
    /* @4931504 constant */
    /* @4931508 store */
    GM_WRITE(vm, -1, "drawpanel2", VAL(0));
    /* @4931516 constant */
    /* @4931520 store */
    GM_WRITE(vm, -1, "drawpanel3", VAL(0));
    /* @4931528 constant */
    /* @4931532 store */
    GM_WRITE(vm, -1, "drawpanel4", VAL(0));
    /* @4931540 constant */
    /* @4931544 store */
    GM_WRITE(vm, -1, "drawpanel5", VAL(0));
    /* @4931552 constant */
    /* @4931556 store */
    GM_WRITE(vm, -1, "drawpanel6", VAL(0));
    /* @4931564 constant */
    /* @4931568 constant */
    /* @4931572 constant */
    /* @4931576 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(100));
    /* @4931584 constant */
    /* @4931588 constant */
    /* @4931592 constant */
    /* @4931596 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(5), VAL(200));
    L_4931604: ;
    return;
}
