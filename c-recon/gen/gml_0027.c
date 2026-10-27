/* generated from CODE 27 (gml_Object_obj_house_Alarm_0), source start 3863456, end 3863584. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0027(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3863456 constant */
    /* @3863460 cast */
    /* @3863464 load */
    /* @3863472 load */
    /* @3863480 call */
    GM_SITE(vm, 27, 3863480);
    /* @3863488 cast */
    /* @3863492 bf */
    v1 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0)));
    if (!TRUTH(v1)) goto L_3863520;
    /* @3863496 constant */
    /* @3863500 constant */
    /* @3863504 constant */
    /* @3863508 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(600));
    /* @3863516 b */
    goto L_3863584;
    L_3863520: ;
    /* @3863520 constant */
    /* @3863524 cast */
    /* @3863528 load */
    /* @3863536 load */
    /* @3863544 call */
    GM_SITE(vm, 27, 3863544);
    /* @3863552 cast */
    /* @3863556 not */
    /* @3863560 bf */
    v2 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0))));
    if (!TRUTH(v2)) goto L_3863584;
    /* @3863564 constant */
    /* @3863568 constant */
    /* @3863572 constant */
    /* @3863576 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(30));
    L_3863584: ;
    return;
}
