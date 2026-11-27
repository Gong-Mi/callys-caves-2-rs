/* generated from CODE 222 (gml_Object_obj_finalboss_Alarm_6), source start 4029668, end 4029804. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0222(GmVM* vm) {
    Val v1;
    /* @4029668 constant */
    /* @4029672 store */
    GM_WRITE(vm, -1, "poisoned", VAL(1));
    /* @4029680 load */
    /* @4029688 constant */
    /* @4029700 sub */
    /* @4029704 store */
    GM_WRITE(vm, -1, "hpfinalboss", (GM_READ(vm, -1, "hpfinalboss") - VAL(0.25)));
    /* @4029712 constant */
    /* @4029716 cast */
    /* @4029720 load */
    /* @4029728 load */
    /* @4029736 call */
    GM_SITE(vm, 222, 4029736);
    /* @4029744 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v1);
    /* @4029752 constant */
    /* @4029764 load */
    /* @4029772 cast */
    /* @4029776 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(0.25));
    /* @4029784 constant */
    /* @4029788 constant */
    /* @4029792 constant */
    /* @4029796 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(6), VAL(30));
    L_4029804: ;
    return;
}
