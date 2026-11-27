/* generated from CODE 175 (gml_Object_obj_boss3_Alarm_9), source start 3995144, end 3995320. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0175(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    /* @3995144 constant */
    /* @3995148 cast */
    /* @3995152 call */
    GM_SITE(vm, 175, 3995152);
    /* @3995160 constant */
    /* @3995164 cmp */
    /* @3995168 bf */
    v1 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(24)) >= VAL(2));
    if (!TRUTH(v1)) goto L_3995176;
    /* @3995172 b */
    goto L_3995320;
    L_3995176: ;
    /* @3995176 constant */
    /* @3995180 cast */
    /* @3995184 call */
    GM_SITE(vm, 175, 3995184);
    /* @3995192 constant */
    /* @3995196 cmp */
    /* @3995200 bf */
    v2 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(32)) < VAL(2));
    if (!TRUTH(v2)) goto L_3995320;
    /* @3995204 constant */
    /* @3995208 cast */
    /* @3995212 load */
    /* @3995220 load */
    /* @3995228 constant */
    /* @3995232 sub */
    /* @3995236 call */
    GM_SITE(vm, 175, 3995236);
    /* @3995244 store */
    v3 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(70)), GM_READ(vm, -1, "y"), VAL(24));
    GM_WRITE(vm, -1, "bullet1", v3);
    /* @3995252 constant */
    /* @3995256 cast */
    /* @3995260 load */
    /* @3995268 load */
    /* @3995276 constant */
    /* @3995280 add */
    /* @3995284 call */
    GM_SITE(vm, 175, 3995284);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(70));
    /* @3995292 store */
    v5 = GM_CALL(vm, "instance_create", 3, v4, GM_READ(vm, -1, "y"), VAL(24));
    GM_WRITE(vm, -1, "bullet2", v5);
    /* @3995300 constant */
    /* @3995304 constant */
    /* @3995308 constant */
    /* @3995312 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(9), VAL(200));
    L_3995320: ;
    return;
}
