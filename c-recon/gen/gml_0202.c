/* generated from CODE 202 (gml_Object_obj_boss5_Alarm_10), source start 4017176, end 4017312. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0202(GmVM* vm) {
    Val v1;
    /* @4017176 constant */
    /* @4017180 store */
    GM_WRITE(vm, -1, "poisoned", VAL(1));
    /* @4017188 load */
    /* @4017196 constant */
    /* @4017208 sub */
    /* @4017212 store */
    GM_WRITE(vm, -1, "hpboss5", (GM_READ(vm, -1, "hpboss5") - VAL(0.25)));
    /* @4017220 constant */
    /* @4017224 cast */
    /* @4017228 load */
    /* @4017236 load */
    /* @4017244 call */
    GM_SITE(vm, 202, 4017244);
    /* @4017252 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v1);
    /* @4017260 constant */
    /* @4017272 load */
    /* @4017280 cast */
    /* @4017284 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(0.25));
    /* @4017292 constant */
    /* @4017296 constant */
    /* @4017300 constant */
    /* @4017304 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(10), VAL(30));
    L_4017312: ;
    return;
}
