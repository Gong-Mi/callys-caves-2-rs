/* generated from CODE 114 (gml_Object_obj_hulkingbandit_Alarm_6), source start 3942524, end 3942660. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0114(GmVM* vm) {
    Val v1;
    /* @3942524 constant */
    /* @3942528 store */
    GM_WRITE(vm, -1, "poisoned", VAL(1));
    /* @3942536 load */
    /* @3942544 constant */
    /* @3942556 sub */
    /* @3942560 store */
    GM_WRITE(vm, -1, "hphulkingbandit", (GM_READ(vm, -1, "hphulkingbandit") - VAL(0.25)));
    /* @3942568 constant */
    /* @3942572 cast */
    /* @3942576 load */
    /* @3942584 load */
    /* @3942592 call */
    GM_SITE(vm, 114, 3942592);
    /* @3942600 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v1);
    /* @3942608 constant */
    /* @3942620 load */
    /* @3942628 cast */
    /* @3942632 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(0.25));
    /* @3942640 constant */
    /* @3942644 constant */
    /* @3942648 constant */
    /* @3942652 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(6), VAL(30));
    L_3942660: ;
    return;
}
