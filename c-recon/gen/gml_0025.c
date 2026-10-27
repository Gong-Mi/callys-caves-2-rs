/* generated from CODE 25 (gml_Object_obj_house_Alarm_2), source start 3863200, end 3863328. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0025(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3863200 constant */
    /* @3863204 cast */
    /* @3863208 load */
    /* @3863216 load */
    /* @3863224 call */
    GM_SITE(vm, 25, 3863224);
    /* @3863232 cast */
    /* @3863236 bf */
    v1 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0)));
    if (!TRUTH(v1)) goto L_3863264;
    /* @3863240 constant */
    /* @3863244 constant */
    /* @3863248 constant */
    /* @3863252 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(600));
    /* @3863260 b */
    goto L_3863328;
    L_3863264: ;
    /* @3863264 constant */
    /* @3863268 cast */
    /* @3863272 load */
    /* @3863280 load */
    /* @3863288 call */
    GM_SITE(vm, 25, 3863288);
    /* @3863296 cast */
    /* @3863300 not */
    /* @3863304 bf */
    v2 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0))));
    if (!TRUTH(v2)) goto L_3863328;
    /* @3863308 constant */
    /* @3863312 constant */
    /* @3863316 constant */
    /* @3863320 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(30));
    L_3863328: ;
    return;
}
