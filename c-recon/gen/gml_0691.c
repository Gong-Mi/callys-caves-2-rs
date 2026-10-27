/* generated from CODE 691 (gml_Object_obj_maptile_Step_0), source start 5016872, end 5017220. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0691(GmVM* vm) {
    Val v1;
    Val v2;
    Val p5016972_0;
    Val v3;
    Val v4;
    Val v5;
    Val v6;
    Val v7;
    Val p5017156_0;
    Val v8;
    /* @5016872 constant */
    /* @5016876 cast */
    /* @5016880 load */
    /* @5016888 load */
    /* @5016896 constant */
    /* @5016900 sub */
    /* @5016904 call */
    GM_SITE(vm, 691, 5016904);
    /* @5016912 cast */
    /* @5016916 bf */
    v1 = BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(1)), GM_READ(vm, -1, "y"), VAL(160)));
    if (!TRUTH(v1)) goto L_5016968;
    /* @5016920 constant */
    /* @5016924 cast */
    /* @5016928 load */
    /* @5016936 load */
    /* @5016944 constant */
    /* @5016948 add */
    /* @5016952 call */
    GM_SITE(vm, 691, 5016952);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(1));
    /* @5016960 cast */
    /* @5016964 b */
    v3 = BOOL(GM_CALL(vm, "instance_place", 3, v2, GM_READ(vm, -1, "y"), VAL(160)));
    p5016972_0 = v3;
    goto L_5016972;
    L_5016968: ;
    /* @5016968 constant */
    p5016972_0 = VAL(0);
    L_5016972: ;
    /* @5016972 bf */
    if (!TRUTH(p5016972_0)) goto L_5016988;
    /* @5016976 constant */
    /* @5016980 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(172));
    L_5016988: ;
    /* @5016988 constant */
    /* @5016992 cast */
    /* @5016996 load */
    /* @5017004 load */
    /* @5017012 constant */
    /* @5017016 add */
    /* @5017020 call */
    GM_SITE(vm, 691, 5017020);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(1));
    /* @5017028 cast */
    /* @5017032 not */
    /* @5017036 bf */
    v5 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v4, GM_READ(vm, -1, "y"), VAL(160))));
    if (!TRUTH(v5)) goto L_5017052;
    /* @5017040 constant */
    /* @5017044 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(171));
    L_5017052: ;
    /* @5017052 constant */
    /* @5017056 cast */
    /* @5017060 load */
    /* @5017068 load */
    /* @5017076 constant */
    /* @5017080 add */
    /* @5017084 call */
    GM_SITE(vm, 691, 5017084);
    v6 = GM_ADD(GM_READ(vm, -1, "x"), VAL(1));
    /* @5017092 cast */
    /* @5017096 bf */
    v7 = BOOL(GM_CALL(vm, "instance_place", 3, v6, GM_READ(vm, -1, "y"), VAL(160)));
    if (!TRUTH(v7)) goto L_5017152;
    /* @5017100 constant */
    /* @5017104 cast */
    /* @5017108 load */
    /* @5017116 load */
    /* @5017124 constant */
    /* @5017128 sub */
    /* @5017132 call */
    GM_SITE(vm, 691, 5017132);
    /* @5017140 cast */
    /* @5017144 not */
    /* @5017148 b */
    v8 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(1)), GM_READ(vm, -1, "y"), VAL(160))));
    p5017156_0 = v8;
    goto L_5017156;
    L_5017152: ;
    /* @5017152 constant */
    p5017156_0 = VAL(0);
    L_5017156: ;
    /* @5017156 bf */
    if (!TRUTH(p5017156_0)) goto L_5017172;
    /* @5017160 constant */
    /* @5017164 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(173));
    L_5017172: ;
    /* @5017172 load */
    /* @5017180 cast */
    /* @5017184 load */
    /* @5017192 load */
    /* @5017200 cmp */
    /* @5017204 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "id")), "goto") == GM_READ(vm, -5, "roomcamefrom")))) goto L_5017220;
    /* @5017208 constant */
    /* @5017212 store */
    GM_WRITE(vm, -1, "image_blend", VAL(255));
    L_5017220: ;
    return;
}
