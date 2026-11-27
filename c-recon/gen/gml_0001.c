/* generated from CODE 1 (gml_Object_obj_player_Alarm_11), source start 3764272, end 3764368. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0001(GmVM* vm) {
    Val p3764320_0;
    Val v1;
    /* @3764272 load */
    /* @3764280 load */
    /* @3764288 cmp */
    /* @3764292 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "health1") != GM_READ(vm, -5, "maxhp")))) goto L_3764316;
    /* @3764296 load */
    /* @3764304 constant */
    /* @3764308 cmp */
    /* @3764312 b */
    p3764320_0 = NUMBOOL(GM_READ(vm, -5, "healthregenbought") == VAL(1));
    goto L_3764320;
    L_3764316: ;
    /* @3764316 constant */
    p3764320_0 = VAL(0);
    L_3764320: ;
    /* @3764320 bf */
    if (!TRUTH(p3764320_0)) goto L_3764348;
    /* @3764324 load */
    /* @3764332 constant */
    /* @3764336 add */
    /* @3764340 store */
    v1 = GM_ADD(GM_READ(vm, -5, "health1"), VAL(1));
    GM_WRITE(vm, -5, "health1", v1);
    L_3764348: ;
    /* @3764348 constant */
    /* @3764352 constant */
    /* @3764356 constant */
    /* @3764360 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(11), VAL(300));
    L_3764368: ;
    return;
}
