/* generated from CODE 24 (gml_Object_obj_house_Alarm_3), source start 3863072, end 3863200. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0024(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3863072 constant */
    /* @3863076 cast */
    /* @3863080 load */
    /* @3863088 load */
    /* @3863096 call */
    GM_SITE(vm, 24, 3863096);
    /* @3863104 cast */
    /* @3863108 bf */
    v1 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0)));
    if (!TRUTH(v1)) goto L_3863136;
    /* @3863112 constant */
    /* @3863116 constant */
    /* @3863120 constant */
    /* @3863124 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(600));
    /* @3863132 b */
    goto L_3863200;
    L_3863136: ;
    /* @3863136 constant */
    /* @3863140 cast */
    /* @3863144 load */
    /* @3863152 load */
    /* @3863160 call */
    GM_SITE(vm, 24, 3863160);
    /* @3863168 cast */
    /* @3863172 not */
    /* @3863176 bf */
    v2 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0))));
    if (!TRUTH(v2)) goto L_3863200;
    /* @3863180 constant */
    /* @3863184 constant */
    /* @3863188 constant */
    /* @3863192 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(30));
    L_3863200: ;
    return;
}
