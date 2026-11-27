/* generated from CODE 584 (gml_Object_obj_lloydtutorial5_Create_0), source start 4888396, end 4888600. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0584(GmVM* vm) {
    /* @4888396 constant */
    /* @4888400 cast */
    /* @4888404 call */
    GM_SITE(vm, 584, 4888404);
    /* @4888412 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(1)));
    /* @4888416 constant */
    /* @4888420 store */
    GM_WRITE(vm, -1, "taplock", VAL(0));
    /* @4888428 constant */
    /* @4888432 store */
    GM_WRITE(vm, -1, "drawpanel1", VAL(1));
    /* @4888440 constant */
    /* @4888444 store */
    GM_WRITE(vm, -1, "drawpanel2", VAL(0));
    /* @4888452 constant */
    /* @4888456 store */
    GM_WRITE(vm, -1, "drawpanel3", VAL(0));
    /* @4888464 constant */
    /* @4888468 store */
    GM_WRITE(vm, -1, "drawpanel4", VAL(0));
    /* @4888476 constant */
    /* @4888480 store */
    GM_WRITE(vm, -1, "drawpanel5", VAL(0));
    /* @4888488 constant */
    /* @4888492 store */
    GM_WRITE(vm, -1, "drawpanel6", VAL(0));
    /* @4888500 constant */
    /* @4888504 constant */
    /* @4888508 constant */
    /* @4888512 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(100));
    /* @4888520 constant */
    /* @4888524 constant */
    /* @4888528 constant */
    /* @4888532 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(200));
    /* @4888540 constant */
    /* @4888544 constant */
    /* @4888548 constant */
    /* @4888552 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(300));
    /* @4888560 constant */
    /* @4888564 constant */
    /* @4888568 constant */
    /* @4888572 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(400));
    /* @4888580 constant */
    /* @4888584 constant */
    /* @4888588 constant */
    /* @4888592 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(5), VAL(500));
    L_4888600: ;
    return;
}
