/* generated from CODE 22 (gml_Object_obj_house_Alarm_5), source start 3862816, end 3862944. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0022(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3862816 constant */
    /* @3862820 cast */
    /* @3862824 load */
    /* @3862832 load */
    /* @3862840 call */
    GM_SITE(vm, 22, 3862840);
    /* @3862848 cast */
    /* @3862852 bf */
    v1 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0)));
    if (!TRUTH(v1)) goto L_3862880;
    /* @3862856 constant */
    /* @3862860 constant */
    /* @3862864 constant */
    /* @3862868 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(6), VAL(600));
    /* @3862876 b */
    goto L_3862944;
    L_3862880: ;
    /* @3862880 constant */
    /* @3862884 cast */
    /* @3862888 load */
    /* @3862896 load */
    /* @3862904 call */
    GM_SITE(vm, 22, 3862904);
    /* @3862912 cast */
    /* @3862916 not */
    /* @3862920 bf */
    v2 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0))));
    if (!TRUTH(v2)) goto L_3862944;
    /* @3862924 constant */
    /* @3862928 constant */
    /* @3862932 constant */
    /* @3862936 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(30));
    L_3862944: ;
    return;
}
