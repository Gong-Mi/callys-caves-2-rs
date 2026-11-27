/* generated from CODE 174 (gml_Object_obj_boss3_Alarm_10), source start 3995008, end 3995144. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0174(GmVM* vm) {
    Val v1;
    /* @3995008 constant */
    /* @3995012 store */
    GM_WRITE(vm, -1, "poisoned", VAL(1));
    /* @3995020 load */
    /* @3995028 constant */
    /* @3995040 sub */
    /* @3995044 store */
    GM_WRITE(vm, -1, "hpboss3", (GM_READ(vm, -1, "hpboss3") - VAL(0.25)));
    /* @3995052 constant */
    /* @3995056 cast */
    /* @3995060 load */
    /* @3995068 load */
    /* @3995076 call */
    GM_SITE(vm, 174, 3995076);
    /* @3995084 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v1);
    /* @3995092 constant */
    /* @3995104 load */
    /* @3995112 cast */
    /* @3995116 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(0.25));
    /* @3995124 constant */
    /* @3995128 constant */
    /* @3995132 constant */
    /* @3995136 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(10), VAL(30));
    L_3995144: ;
    return;
}
