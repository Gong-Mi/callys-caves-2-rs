/* generated from CODE 82 (gml_Object_obj_firehulk_Alarm_7), source start 3919060, end 3919196. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0082(GmVM* vm) {
    Val v1;
    /* @3919060 constant */
    /* @3919064 store */
    GM_WRITE(vm, -1, "poisoned", VAL(1));
    /* @3919072 load */
    /* @3919080 constant */
    /* @3919092 sub */
    /* @3919096 store */
    GM_WRITE(vm, -1, "hpfirehulk", (GM_READ(vm, -1, "hpfirehulk") - VAL(0.25)));
    /* @3919104 constant */
    /* @3919108 cast */
    /* @3919112 load */
    /* @3919120 load */
    /* @3919128 call */
    GM_SITE(vm, 82, 3919128);
    /* @3919136 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v1);
    /* @3919144 constant */
    /* @3919156 load */
    /* @3919164 cast */
    /* @3919168 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(0.25));
    /* @3919176 constant */
    /* @3919180 constant */
    /* @3919184 constant */
    /* @3919188 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(30));
    L_3919196: ;
    return;
}
