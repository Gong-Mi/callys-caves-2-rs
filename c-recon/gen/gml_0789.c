/* generated from CODE 789 (gml_Object_obj_finalbosspuff_Alarm_2), source start 5041380, end 5041592. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0789(GmVM* vm) {
    Val v1;
    Val v2;
    /* @5041380 constant */
    /* @5041384 cast */
    /* @5041388 load */
    /* @5041396 load */
    /* @5041404 constant */
    /* @5041408 add */
    /* @5041412 call */
    GM_SITE(vm, 789, 5041412);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(80));
    /* @5041420 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, GM_READ(vm, -1, "y"), VAL(190)));
    /* @5041424 constant */
    /* @5041428 cast */
    /* @5041432 load */
    /* @5041440 load */
    /* @5041448 constant */
    /* @5041452 sub */
    /* @5041456 call */
    GM_SITE(vm, 789, 5041456);
    /* @5041464 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(80)), GM_READ(vm, -1, "y"), VAL(190)));
    /* @5041468 constant */
    /* @5041472 cast */
    /* @5041476 load */
    /* @5041484 load */
    /* @5041492 constant */
    /* @5041496 add */
    /* @5041500 call */
    GM_SITE(vm, 789, 5041500);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(80));
    /* @5041508 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v2, GM_READ(vm, -1, "y"), VAL(190)));
    /* @5041512 constant */
    /* @5041516 cast */
    /* @5041520 load */
    /* @5041528 constant */
    /* @5041532 sub */
    /* @5041536 load */
    /* @5041544 call */
    GM_SITE(vm, 789, 5041544);
    /* @5041552 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(80)), VAL(190)));
    /* @5041556 constant */
    /* @5041560 cast */
    /* @5041564 load */
    /* @5041572 load */
    /* @5041580 call */
    GM_SITE(vm, 789, 5041580);
    /* @5041588 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(190)));
    L_5041592: ;
    return;
}
