/* generated from CODE 786 (gml_Object_obj_finalbosspuff_Create_0), source start 5040976, end 5041328. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0786(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    /* @5040976 constant */
    /* @5040980 cast */
    /* @5040984 call */
    GM_SITE(vm, 786, 5040984);
    /* @5040992 cast */
    /* @5040996 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(130)));
    if (!TRUTH(v1)) goto L_5041024;
    /* @5041000 constant */
    /* @5041004 pushenv */
    if (!GM_PUSHENV(vm, VAL(130))) goto L_5041020;
    L_5041008: ;
    /* @5041008 call */
    GM_SITE(vm, 786, 5041008);
    /* @5041016 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5041020: ;
    /* @5041020 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_5041008;
    L_5041024: ;
    /* @5041024 constant */
    /* @5041028 cast */
    /* @5041032 call */
    GM_SITE(vm, 786, 5041032);
    /* @5041040 cast */
    /* @5041044 bf */
    v2 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(131)));
    if (!TRUTH(v2)) goto L_5041072;
    /* @5041048 constant */
    /* @5041052 pushenv */
    if (!GM_PUSHENV(vm, VAL(131))) goto L_5041068;
    L_5041056: ;
    /* @5041056 call */
    GM_SITE(vm, 786, 5041056);
    /* @5041064 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5041068: ;
    /* @5041068 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_5041056;
    L_5041072: ;
    /* @5041072 constant */
    /* @5041076 cast */
    /* @5041080 load */
    /* @5041088 load */
    /* @5041096 constant */
    /* @5041100 add */
    /* @5041104 call */
    GM_SITE(vm, 786, 5041104);
    v3 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @5041112 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v3, GM_READ(vm, -1, "y"), VAL(190)));
    /* @5041116 constant */
    /* @5041120 cast */
    /* @5041124 load */
    /* @5041132 load */
    /* @5041140 constant */
    /* @5041144 sub */
    /* @5041148 call */
    GM_SITE(vm, 786, 5041148);
    /* @5041156 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(20)), GM_READ(vm, -1, "y"), VAL(190)));
    /* @5041160 constant */
    /* @5041164 cast */
    /* @5041168 load */
    /* @5041176 constant */
    /* @5041180 add */
    /* @5041184 load */
    /* @5041192 call */
    GM_SITE(vm, 786, 5041192);
    v4 = GM_ADD(GM_READ(vm, -1, "y"), VAL(20));
    /* @5041200 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), v4, VAL(190)));
    /* @5041204 constant */
    /* @5041208 cast */
    /* @5041212 load */
    /* @5041220 constant */
    /* @5041224 sub */
    /* @5041228 load */
    /* @5041236 call */
    GM_SITE(vm, 786, 5041236);
    /* @5041244 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(20)), VAL(190)));
    /* @5041248 constant */
    /* @5041252 constant */
    /* @5041256 constant */
    /* @5041260 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(10));
    /* @5041268 constant */
    /* @5041272 constant */
    /* @5041276 constant */
    /* @5041280 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(20));
    /* @5041288 constant */
    /* @5041292 constant */
    /* @5041296 constant */
    /* @5041300 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(30));
    /* @5041308 constant */
    /* @5041312 constant */
    /* @5041316 constant */
    /* @5041320 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(129));
    L_5041328: ;
    return;
}
