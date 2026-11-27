/* generated from CODE 110 (gml_Object_obj_shooter2_Step_0), source start 3940820, end 3941392. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0110(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3940820 load */
    /* @3940828 constant */
    /* @3940832 cmp */
    /* @3940836 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpshooter2") >= VAL(0)))) goto L_3940860;
    /* @3940840 constant */
    /* @3940844 constant */
    /* @3940848 constant */
    /* @3940852 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(0));
    L_3940860: ;
    /* @3940860 load */
    /* @3940868 constant */
    /* @3940872 cmp */
    /* @3940876 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpshooter2") <= VAL(0)))) goto L_3940900;
    /* @3940880 constant */
    /* @3940884 constant */
    /* @3940888 constant */
    /* @3940892 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    L_3940900: ;
    /* @3940900 constant */
    /* @3940904 cast */
    /* @3940908 load */
    /* @3940916 constant */
    /* @3940920 add */
    /* @3940924 load */
    /* @3940932 call */
    GM_SITE(vm, 110, 3940932);
    v1 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @3940940 cast */
    /* @3940944 bf */
    v2 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v1, VAL(34)));
    if (!TRUTH(v2)) goto L_3940976;
    /* @3940948 constant */
    /* @3940952 store */
    GM_WRITE(vm, -1, "gravity", VAL(0));
    /* @3940960 constant */
    /* @3940964 store */
    GM_WRITE(vm, -1, "falling", VAL(0));
    /* @3940972 b */
    goto L_3941008;
    L_3940976: ;
    /* @3940976 constant */
    /* @3940988 store */
    GM_WRITE(vm, -1, "gravity", VAL(0.6));
    /* @3940996 constant */
    /* @3941000 store */
    GM_WRITE(vm, -1, "falling", VAL(1));
    L_3941008: ;
    /* @3941008 load */
    /* @3941016 constant */
    /* @3941020 cmp */
    /* @3941024 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3941040;
    /* @3941028 constant */
    /* @3941032 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(1));
    L_3941040: ;
    /* @3941040 load */
    /* @3941048 constant */
    /* @3941052 cmp */
    /* @3941056 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3941072;
    /* @3941060 constant */
    /* @3941064 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    L_3941072: ;
    /* @3941072 load */
    /* @3941080 load */
    /* @3941088 cmp */
    /* @3941092 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "x") >= GM_READ(vm, -1, "x")))) goto L_3941108;
    /* @3941096 constant */
    /* @3941100 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    L_3941108: ;
    /* @3941108 load */
    /* @3941116 load */
    /* @3941124 cmp */
    /* @3941128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "x") <= GM_READ(vm, -1, "x")))) goto L_3941144;
    /* @3941132 constant */
    /* @3941136 store */
    GM_WRITE(vm, -1, "facing", VAL(1));
    L_3941144: ;
    /* @3941144 load */
    /* @3941152 constant */
    /* @3941156 cmp */
    /* @3941160 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpshooter2frozen") == VAL(1)))) goto L_3941208;
    /* @3941164 constant */
    /* @3941172 store */
    GM_WRITE(vm, -1, "image_blend", VAL(16711680));
    /* @3941180 constant */
    /* @3941184 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3941192 constant */
    /* @3941196 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @3941204 b */
    goto L_3941224;
    L_3941208: ;
    /* @3941208 constant */
    /* @3941216 store */
    GM_WRITE(vm, -1, "image_blend", VAL(16777215));
    L_3941224: ;
    /* @3941224 load */
    /* @3941232 constant */
    /* @3941236 cmp */
    /* @3941240 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "stunned") == VAL(1)))) goto L_3941256;
    /* @3941244 constant */
    /* @3941248 store */
    GM_WRITE(vm, -1, "image_blend", VAL(255));
    L_3941256: ;
    /* @3941256 load */
    /* @3941264 constant */
    /* @3941268 cmp */
    /* @3941272 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "swordstunned") == VAL(1)))) goto L_3941312;
    /* @3941276 constant */
    /* @3941280 store */
    GM_WRITE(vm, -1, "image_blend", VAL(255));
    /* @3941288 constant */
    /* @3941292 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3941300 constant */
    /* @3941304 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_3941312: ;
    /* @3941312 load */
    /* @3941320 constant */
    /* @3941324 cmp */
    /* @3941328 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "poisoned") == VAL(1)))) goto L_3941348;
    /* @3941332 constant */
    /* @3941340 store */
    GM_WRITE(vm, -1, "image_blend", VAL(32768));
    L_3941348: ;
    /* @3941348 load */
    /* @3941356 constant */
    /* @3941360 cmp */
    /* @3941364 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_3941392;
    /* @3941368 constant */
    /* @3941372 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3941380 constant */
    /* @3941384 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_3941392: ;
    return;
}
