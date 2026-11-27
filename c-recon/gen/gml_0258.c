/* generated from CODE 258 (gml_Object_obj_fireslime_Alarm_6), source start 4048976, end 4049112. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0258(GmVM* vm) {
    Val v1;
    /* @4048976 constant */
    /* @4048980 store */
    GM_WRITE(vm, -1, "poisoned", VAL(1));
    /* @4048988 load */
    /* @4048996 constant */
    /* @4049008 sub */
    /* @4049012 store */
    GM_WRITE(vm, -1, "hpfireslime", (GM_READ(vm, -1, "hpfireslime") - VAL(0.25)));
    /* @4049020 constant */
    /* @4049024 cast */
    /* @4049028 load */
    /* @4049036 load */
    /* @4049044 call */
    GM_SITE(vm, 258, 4049044);
    /* @4049052 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v1);
    /* @4049060 constant */
    /* @4049072 load */
    /* @4049080 cast */
    /* @4049084 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(0.25));
    /* @4049092 constant */
    /* @4049096 constant */
    /* @4049100 constant */
    /* @4049104 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(6), VAL(30));
    L_4049112: ;
    return;
}
