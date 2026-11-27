/* generated from CODE 93 (gml_Object_obj_zombie_Alarm_6), source start 3927140, end 3927276. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0093(GmVM* vm) {
    Val v1;
    /* @3927140 constant */
    /* @3927144 store */
    GM_WRITE(vm, -1, "poisoned", VAL(1));
    /* @3927152 load */
    /* @3927160 constant */
    /* @3927172 sub */
    /* @3927176 store */
    GM_WRITE(vm, -1, "hpzombie", (GM_READ(vm, -1, "hpzombie") - VAL(0.25)));
    /* @3927184 constant */
    /* @3927188 cast */
    /* @3927192 load */
    /* @3927200 load */
    /* @3927208 call */
    GM_SITE(vm, 93, 3927208);
    /* @3927216 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v1);
    /* @3927224 constant */
    /* @3927236 load */
    /* @3927244 cast */
    /* @3927248 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(0.25));
    /* @3927256 constant */
    /* @3927260 constant */
    /* @3927264 constant */
    /* @3927268 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(6), VAL(30));
    L_3927276: ;
    return;
}
