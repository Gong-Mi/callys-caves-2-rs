/* generated from CODE 167 (gml_Object_obj_boss2_Alarm_1), source start 3984056, end 3984328. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0167(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    Val v6;
    Val v7;
    Val v8;
    Val v9;
    Val v10;
    /* @3984056 load */
    /* @3984064 constant */
    /* @3984068 cmp */
    /* @3984072 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_3984080;
    /* @3984076 b */
    goto L_3984328;
    L_3984080: ;
    /* @3984080 load */
    /* @3984088 constant */
    /* @3984092 cmp */
    /* @3984096 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") != VAL(110)))) goto L_3984328;
    /* @3984100 constant */
    /* @3984104 cast */
    /* @3984108 call */
    GM_SITE(vm, 167, 3984108);
    /* @3984116 constant */
    /* @3984120 cmp */
    /* @3984124 bf */
    v1 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(32)) >= VAL(4));
    if (!TRUTH(v1)) goto L_3984132;
    /* @3984128 b */
    goto L_3984328;
    L_3984132: ;
    /* @3984132 constant */
    /* @3984136 cast */
    /* @3984140 call */
    GM_SITE(vm, 167, 3984140);
    /* @3984148 constant */
    /* @3984152 cmp */
    /* @3984156 bf */
    v2 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(32)) <= VAL(3));
    if (!TRUTH(v2)) goto L_3984328;
    /* @3984160 constant */
    /* @3984164 cast */
    /* @3984168 load */
    /* @3984176 constant */
    /* @3984180 add */
    /* @3984184 load */
    /* @3984192 constant */
    /* @3984196 add */
    /* @3984200 call */
    GM_SITE(vm, 167, 3984200);
    v3 = GM_ADD(GM_READ(vm, -1, "x"), VAL(100));
    v4 = GM_ADD(GM_READ(vm, -1, "y"), VAL(20));
    /* @3984208 store */
    v5 = GM_CALL(vm, "instance_create", 3, v3, v4, VAL(32));
    GM_WRITE(vm, -1, "bullet1", v5);
    /* @3984216 constant */
    /* @3984220 cast */
    /* @3984224 load */
    /* @3984232 constant */
    /* @3984236 add */
    /* @3984240 load */
    /* @3984248 constant */
    /* @3984252 sub */
    /* @3984256 call */
    GM_SITE(vm, 167, 3984256);
    v6 = GM_ADD(GM_READ(vm, -1, "y"), VAL(20));
    /* @3984264 store */
    v7 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(60)), v6, VAL(32));
    GM_WRITE(vm, -1, "bullet2", v7);
    /* @3984272 constant */
    /* @3984276 cast */
    /* @3984280 load */
    /* @3984288 constant */
    /* @3984292 add */
    /* @3984296 load */
    /* @3984304 constant */
    /* @3984308 add */
    /* @3984312 call */
    GM_SITE(vm, 167, 3984312);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(50));
    v9 = GM_ADD(GM_READ(vm, -1, "y"), VAL(20));
    /* @3984320 store */
    v10 = GM_CALL(vm, "instance_create", 3, v8, v9, VAL(32));
    GM_WRITE(vm, -1, "bullet3", v10);
    L_3984328: ;
    return;
}
