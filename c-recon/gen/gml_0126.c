/* generated from CODE 126 (gml_Object_obj_enemy2_Alarm_6), source start 3951060, end 3951196. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0126(GmVM* vm) {
    Val v1;
    /* @3951060 constant */
    /* @3951064 store */
    GM_WRITE(vm, -1, "poisoned", VAL(1));
    /* @3951072 load */
    /* @3951080 constant */
    /* @3951092 sub */
    /* @3951096 store */
    GM_WRITE(vm, -1, "hptwo", (GM_READ(vm, -1, "hptwo") - VAL(0.25)));
    /* @3951104 constant */
    /* @3951108 cast */
    /* @3951112 load */
    /* @3951120 load */
    /* @3951128 call */
    GM_SITE(vm, 126, 3951128);
    /* @3951136 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v1);
    /* @3951144 constant */
    /* @3951156 load */
    /* @3951164 cast */
    /* @3951168 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(0.25));
    /* @3951176 constant */
    /* @3951180 constant */
    /* @3951184 constant */
    /* @3951188 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(6), VAL(30));
    L_3951196: ;
    return;
}
