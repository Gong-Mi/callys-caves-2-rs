/* generated from CODE 23 (gml_Object_obj_house_Alarm_4), source start 3862944, end 3863072. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0023(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3862944 constant */
    /* @3862948 cast */
    /* @3862952 load */
    /* @3862960 load */
    /* @3862968 call */
    GM_SITE(vm, 23, 3862968);
    /* @3862976 cast */
    /* @3862980 bf */
    v1 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0)));
    if (!TRUTH(v1)) goto L_3863008;
    /* @3862984 constant */
    /* @3862988 constant */
    /* @3862992 constant */
    /* @3862996 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(5), VAL(600));
    /* @3863004 b */
    goto L_3863072;
    L_3863008: ;
    /* @3863008 constant */
    /* @3863012 cast */
    /* @3863016 load */
    /* @3863024 load */
    /* @3863032 call */
    GM_SITE(vm, 23, 3863032);
    /* @3863040 cast */
    /* @3863044 not */
    /* @3863048 bf */
    v2 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0))));
    if (!TRUTH(v2)) goto L_3863072;
    /* @3863052 constant */
    /* @3863056 constant */
    /* @3863060 constant */
    /* @3863064 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(30));
    L_3863072: ;
    return;
}
