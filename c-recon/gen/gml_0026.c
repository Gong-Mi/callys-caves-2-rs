/* generated from CODE 26 (gml_Object_obj_house_Alarm_1), source start 3863328, end 3863456. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0026(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3863328 constant */
    /* @3863332 cast */
    /* @3863336 load */
    /* @3863344 load */
    /* @3863352 call */
    GM_SITE(vm, 26, 3863352);
    /* @3863360 cast */
    /* @3863364 bf */
    v1 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0)));
    if (!TRUTH(v1)) goto L_3863392;
    /* @3863368 constant */
    /* @3863372 constant */
    /* @3863376 constant */
    /* @3863380 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(600));
    /* @3863388 b */
    goto L_3863456;
    L_3863392: ;
    /* @3863392 constant */
    /* @3863396 cast */
    /* @3863400 load */
    /* @3863408 load */
    /* @3863416 call */
    GM_SITE(vm, 26, 3863416);
    /* @3863424 cast */
    /* @3863428 not */
    /* @3863432 bf */
    v2 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0))));
    if (!TRUTH(v2)) goto L_3863456;
    /* @3863436 constant */
    /* @3863440 constant */
    /* @3863444 constant */
    /* @3863448 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(30));
    L_3863456: ;
    return;
}
