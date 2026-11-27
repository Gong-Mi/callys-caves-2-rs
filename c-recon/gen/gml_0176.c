/* generated from CODE 176 (gml_Object_obj_boss3_Alarm_8), source start 3995320, end 3995388. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0176(GmVM* vm) {
    Val v1;
    /* @3995320 constant */
    /* @3995324 cast */
    /* @3995328 load */
    /* @3995336 load */
    /* @3995344 constant */
    /* @3995348 sub */
    /* @3995352 call */
    GM_SITE(vm, 176, 3995352);
    /* @3995360 store */
    v1 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(50)), GM_READ(vm, -1, "y"), VAL(55));
    GM_WRITE(vm, -1, "bullet1", v1);
    /* @3995368 constant */
    /* @3995372 constant */
    /* @3995376 constant */
    /* @3995380 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(30));
    L_3995388: ;
    return;
}
