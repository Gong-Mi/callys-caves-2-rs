/* generated from CODE 60 (gml_Object_obj_shooter1_Alarm_6), source start 3903216, end 3903352. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0060(GmVM* vm) {
    Val v1;
    /* @3903216 constant */
    /* @3903220 store */
    GM_WRITE(vm, -1, "poisoned", VAL(1));
    /* @3903228 load */
    /* @3903236 constant */
    /* @3903248 sub */
    /* @3903252 store */
    GM_WRITE(vm, -1, "hpshooter1", (GM_READ(vm, -1, "hpshooter1") - VAL(0.25)));
    /* @3903260 constant */
    /* @3903264 cast */
    /* @3903268 load */
    /* @3903276 load */
    /* @3903284 call */
    GM_SITE(vm, 60, 3903284);
    /* @3903292 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v1);
    /* @3903300 constant */
    /* @3903312 load */
    /* @3903320 cast */
    /* @3903324 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(0.25));
    /* @3903332 constant */
    /* @3903336 constant */
    /* @3903340 constant */
    /* @3903344 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(6), VAL(30));
    L_3903352: ;
    return;
}
