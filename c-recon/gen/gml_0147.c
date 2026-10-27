/* generated from CODE 147 (gml_Object_obj_ghost_Alarm_6), source start 3966416, end 3966552. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0147(GmVM* vm) {
    Val v1;
    /* @3966416 constant */
    /* @3966420 store */
    GM_WRITE(vm, -1, "poisoned", VAL(1));
    /* @3966428 load */
    /* @3966436 constant */
    /* @3966448 sub */
    /* @3966452 store */
    GM_WRITE(vm, -1, "hpghost", (GM_READ(vm, -1, "hpghost") - VAL(0.25)));
    /* @3966460 constant */
    /* @3966464 cast */
    /* @3966468 load */
    /* @3966476 load */
    /* @3966484 call */
    GM_SITE(vm, 147, 3966484);
    /* @3966492 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v1);
    /* @3966500 constant */
    /* @3966512 load */
    /* @3966520 cast */
    /* @3966524 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(0.25));
    /* @3966532 constant */
    /* @3966536 constant */
    /* @3966540 constant */
    /* @3966544 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(6), VAL(30));
    L_3966552: ;
    return;
}
