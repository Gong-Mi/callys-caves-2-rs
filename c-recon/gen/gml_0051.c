/* generated from CODE 51 (gml_Object_obj_knifebandit_Alarm_6), source start 3896240, end 3896376. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0051(GmVM* vm) {
    Val v1;
    /* @3896240 constant */
    /* @3896244 store */
    GM_WRITE(vm, -1, "poisoned", VAL(1));
    /* @3896252 load */
    /* @3896260 constant */
    /* @3896272 sub */
    /* @3896276 store */
    GM_WRITE(vm, -1, "hpknife", (GM_READ(vm, -1, "hpknife") - VAL(0.25)));
    /* @3896284 constant */
    /* @3896288 cast */
    /* @3896292 load */
    /* @3896300 load */
    /* @3896308 call */
    GM_SITE(vm, 51, 3896308);
    /* @3896316 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v1);
    /* @3896324 constant */
    /* @3896336 load */
    /* @3896344 cast */
    /* @3896348 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(0.25));
    /* @3896356 constant */
    /* @3896360 constant */
    /* @3896364 constant */
    /* @3896368 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(6), VAL(30));
    L_3896376: ;
    return;
}
