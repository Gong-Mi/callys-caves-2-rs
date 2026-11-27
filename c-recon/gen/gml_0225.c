/* generated from CODE 225 (gml_Object_obj_finalboss_Alarm_3), source start 4029880, end 4030204. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0225(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    /* @4029880 load */
    /* @4029888 constant */
    /* @4029892 cmp */
    /* @4029896 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") != VAL(110)))) goto L_4030204;
    /* @4029900 constant */
    /* @4029904 cast */
    /* @4029908 load */
    /* @4029916 load */
    /* @4029924 constant */
    /* @4029928 sub */
    /* @4029932 call */
    GM_SITE(vm, 225, 4029932);
    /* @4029940 store */
    v1 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(100)), GM_READ(vm, -1, "y"), VAL(50));
    GM_WRITE(vm, -1, "bullet1", v1);
    /* @4029948 constant */
    /* @4029952 load */
    /* @4029960 cast */
    /* @4029964 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "bullet1")), "direction", VAL(180));
    /* @4029972 constant */
    /* @4029976 cast */
    /* @4029980 load */
    /* @4029988 constant */
    /* @4029992 sub */
    /* @4029996 load */
    /* @4030004 constant */
    /* @4030008 sub */
    /* @4030012 call */
    GM_SITE(vm, 225, 4030012);
    /* @4030020 store */
    v2 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(80)), (GM_READ(vm, -1, "y") - VAL(20)), VAL(50));
    GM_WRITE(vm, -1, "bullet2", v2);
    /* @4030028 constant */
    /* @4030032 load */
    /* @4030040 cast */
    /* @4030044 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "bullet2")), "direction", VAL(135));
    /* @4030052 constant */
    /* @4030056 cast */
    /* @4030060 load */
    /* @4030068 constant */
    /* @4030072 add */
    /* @4030076 load */
    /* @4030084 constant */
    /* @4030088 sub */
    /* @4030092 call */
    GM_SITE(vm, 225, 4030092);
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(20));
    /* @4030100 store */
    v4 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(80)), v3, VAL(50));
    GM_WRITE(vm, -1, "bullet3", v4);
    /* @4030108 constant */
    /* @4030112 load */
    /* @4030120 cast */
    /* @4030124 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "bullet3")), "direction", VAL(225));
    /* @4030132 constant */
    /* @4030136 cast */
    /* @4030140 load */
    /* @4030148 constant */
    /* @4030152 sub */
    /* @4030156 load */
    /* @4030164 call */
    GM_SITE(vm, 225, 4030164);
    /* @4030172 store */
    v5 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(20)), VAL(50));
    GM_WRITE(vm, -1, "bullet4", v5);
    /* @4030180 constant */
    /* @4030184 load */
    /* @4030192 cast */
    /* @4030196 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "bullet4")), "direction", VAL(90));
    L_4030204: ;
    return;
}
