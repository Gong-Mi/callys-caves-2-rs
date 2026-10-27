/* generated from CODE 78 (gml_Object_obj_skeleton_Step_0), source start 3916548, end 3918084. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0078(GmVM* vm) {
    Val v1;
    Val p3916788_0;
    Val v2;
    Val v3;
    Val v4;
    Val p3916920_0;
    Val v5;
    Val v6;
    Val p3917052_0;
    Val v7;
    Val v8;
    Val v9;
    Val v10;
    Val v11;
    Val v12;
    Val v13;
    Val v14;
    Val v15;
    Val p3917252_0;
    Val v16;
    Val v17;
    Val v18;
    Val v19;
    Val v20;
    Val v21;
    Val p3917404_0;
    Val v22;
    Val v23;
    Val v24;
    Val v25;
    Val v26;
    Val v27;
    Val p3917604_0;
    Val v28;
    Val v29;
    Val v30;
    Val v31;
    Val v32;
    Val v33;
    Val p3917756_0;
    Val v34;
    Val v35;
    Val v36;
    /* @3916548 load */
    /* @3916556 constant */
    /* @3916560 cmp */
    /* @3916564 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpskeleton") >= VAL(0)))) goto L_3916588;
    /* @3916568 constant */
    /* @3916572 constant */
    /* @3916576 constant */
    /* @3916580 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(0));
    L_3916588: ;
    /* @3916588 load */
    /* @3916596 constant */
    /* @3916600 cmp */
    /* @3916604 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpskeleton") <= VAL(0)))) goto L_3916628;
    /* @3916608 constant */
    /* @3916612 constant */
    /* @3916616 constant */
    /* @3916620 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    L_3916628: ;
    /* @3916628 load */
    /* @3916636 constant */
    /* @3916640 cmp */
    /* @3916644 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3916672;
    /* @3916648 constant */
    /* @3916652 store */
    GM_WRITE(vm, -1, "hspeed", VAL(3));
    /* @3916660 constant */
    /* @3916664 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(1));
    L_3916672: ;
    /* @3916672 load */
    /* @3916680 constant */
    /* @3916684 cmp */
    /* @3916688 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3916716;
    /* @3916692 constant */
    /* @3916696 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-3));
    /* @3916704 constant */
    /* @3916708 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    L_3916716: ;
    /* @3916716 constant */
    /* @3916720 cast */
    /* @3916724 call */
    GM_SITE(vm, 78, 3916724);
    /* @3916732 constant */
    /* @3916736 cmp */
    /* @3916740 bf */
    v1 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(50));
    if (!TRUTH(v1)) goto L_3916804;
    /* @3916744 load */
    /* @3916752 constant */
    /* @3916756 cmp */
    /* @3916760 bt */
    if (TRUTH(NUMBOOL(GM_READ(vm, 0, "invulnerable") == VAL(1)))) goto L_3916784;
    /* @3916764 load */
    /* @3916772 constant */
    /* @3916776 cmp */
    /* @3916780 b */
    p3916788_0 = NUMBOOL(GM_READ(vm, 0, "invulnerable2") == VAL(1));
    goto L_3916788;
    L_3916784: ;
    /* @3916784 constant */
    p3916788_0 = VAL(1);
    L_3916788: ;
    /* @3916788 bf */
    if (!TRUTH(p3916788_0)) goto L_3916804;
    /* @3916792 constant */
    /* @3916796 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3916804: ;
    /* @3916804 constant */
    /* @3916808 cast */
    /* @3916812 load */
    /* @3916820 constant */
    /* @3916824 sub */
    /* @3916828 load */
    /* @3916836 constant */
    /* @3916840 add */
    /* @3916844 call */
    GM_SITE(vm, 78, 3916844);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @3916852 cast */
    /* @3916856 bt */
    v3 = BOOL(GM_CALL(vm, "instance_place", 3, v2, (GM_READ(vm, -1, "y") - VAL(4)), VAL(4)));
    if (TRUTH(v3)) goto L_3916916;
    /* @3916860 constant */
    /* @3916864 cast */
    /* @3916868 load */
    /* @3916876 constant */
    /* @3916880 sub */
    /* @3916884 load */
    /* @3916892 constant */
    /* @3916896 add */
    /* @3916900 call */
    GM_SITE(vm, 78, 3916900);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @3916908 cast */
    /* @3916912 b */
    v5 = BOOL(GM_CALL(vm, "instance_place", 3, v4, (GM_READ(vm, -1, "y") - VAL(4)), VAL(6)));
    p3916920_0 = v5;
    goto L_3916920;
    L_3916916: ;
    /* @3916916 constant */
    p3916920_0 = VAL(1);
    L_3916920: ;
    /* @3916920 bf */
    if (!TRUTH(p3916920_0)) goto L_3916936;
    /* @3916924 constant */
    /* @3916928 store */
    GM_WRITE(vm, -1, "facing", VAL(1));
    L_3916936: ;
    /* @3916936 constant */
    /* @3916940 cast */
    /* @3916944 load */
    /* @3916952 constant */
    /* @3916956 sub */
    /* @3916960 load */
    /* @3916968 constant */
    /* @3916972 sub */
    /* @3916976 call */
    GM_SITE(vm, 78, 3916976);
    /* @3916984 cast */
    /* @3916988 bt */
    v6 = BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(4)), VAL(4)));
    if (TRUTH(v6)) goto L_3917048;
    /* @3916992 constant */
    /* @3916996 cast */
    /* @3917000 load */
    /* @3917008 constant */
    /* @3917012 sub */
    /* @3917016 load */
    /* @3917024 constant */
    /* @3917028 sub */
    /* @3917032 call */
    GM_SITE(vm, 78, 3917032);
    /* @3917040 cast */
    /* @3917044 b */
    v7 = BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(4)), VAL(6)));
    p3917052_0 = v7;
    goto L_3917052;
    L_3917048: ;
    /* @3917048 constant */
    p3917052_0 = VAL(1);
    L_3917052: ;
    /* @3917052 bf */
    if (!TRUTH(p3917052_0)) goto L_3917068;
    /* @3917056 constant */
    /* @3917060 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    L_3917068: ;
    /* @3917068 constant */
    /* @3917072 cast */
    /* @3917076 load */
    /* @3917084 constant */
    /* @3917088 add */
    /* @3917092 load */
    /* @3917100 constant */
    /* @3917104 add */
    /* @3917108 call */
    GM_SITE(vm, 78, 3917108);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(27));
    v9 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3917116 cast */
    /* @3917120 not */
    /* @3917124 bf */
    v10 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v8, v9, VAL(4))));
    if (!TRUTH(v10)) goto L_3917248;
    /* @3917128 constant */
    /* @3917132 cast */
    /* @3917136 load */
    /* @3917144 constant */
    /* @3917148 add */
    /* @3917152 load */
    /* @3917160 constant */
    /* @3917164 add */
    /* @3917168 call */
    GM_SITE(vm, 78, 3917168);
    v11 = GM_ADD(GM_READ(vm, -1, "x"), VAL(27));
    v12 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3917176 cast */
    /* @3917180 not */
    /* @3917184 bf */
    v13 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v11, v12, VAL(6))));
    if (!TRUTH(v13)) goto L_3917248;
    /* @3917188 constant */
    /* @3917192 cast */
    /* @3917196 load */
    /* @3917204 constant */
    /* @3917208 add */
    /* @3917212 load */
    /* @3917220 constant */
    /* @3917224 add */
    /* @3917228 call */
    GM_SITE(vm, 78, 3917228);
    v14 = GM_ADD(GM_READ(vm, -1, "x"), VAL(27));
    v15 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3917236 cast */
    /* @3917240 not */
    /* @3917244 b */
    v16 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v14, v15, VAL(7))));
    p3917252_0 = v16;
    goto L_3917252;
    L_3917248: ;
    /* @3917248 constant */
    p3917252_0 = VAL(0);
    L_3917252: ;
    /* @3917252 bf */
    if (!TRUTH(p3917252_0)) goto L_3917420;
    /* @3917256 constant */
    /* @3917260 cast */
    /* @3917264 load */
    /* @3917272 constant */
    /* @3917276 add */
    /* @3917280 load */
    /* @3917288 call */
    GM_SITE(vm, 78, 3917288);
    v17 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3917296 cast */
    /* @3917300 bt */
    v18 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v17, VAL(4)));
    if (TRUTH(v18)) goto L_3917400;
    /* @3917304 constant */
    /* @3917308 cast */
    /* @3917312 load */
    /* @3917320 constant */
    /* @3917324 add */
    /* @3917328 load */
    /* @3917336 call */
    GM_SITE(vm, 78, 3917336);
    v19 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3917344 cast */
    /* @3917348 bt */
    v20 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v19, VAL(6)));
    if (TRUTH(v20)) goto L_3917400;
    /* @3917352 constant */
    /* @3917356 cast */
    /* @3917360 load */
    /* @3917368 constant */
    /* @3917372 add */
    /* @3917376 load */
    /* @3917384 call */
    GM_SITE(vm, 78, 3917384);
    v21 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3917392 cast */
    /* @3917396 b */
    v22 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v21, VAL(7)));
    p3917404_0 = v22;
    goto L_3917404;
    L_3917400: ;
    /* @3917400 constant */
    p3917404_0 = VAL(1);
    L_3917404: ;
    /* @3917404 bf */
    if (!TRUTH(p3917404_0)) goto L_3917420;
    /* @3917408 constant */
    /* @3917412 store */
    GM_WRITE(vm, -1, "facing", VAL(1));
    L_3917420: ;
    /* @3917420 constant */
    /* @3917424 cast */
    /* @3917428 load */
    /* @3917436 constant */
    /* @3917440 add */
    /* @3917444 load */
    /* @3917452 constant */
    /* @3917456 sub */
    /* @3917460 call */
    GM_SITE(vm, 78, 3917460);
    v23 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3917468 cast */
    /* @3917472 not */
    /* @3917476 bf */
    v24 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(26)), v23, VAL(4))));
    if (!TRUTH(v24)) goto L_3917600;
    /* @3917480 constant */
    /* @3917484 cast */
    /* @3917488 load */
    /* @3917496 constant */
    /* @3917500 add */
    /* @3917504 load */
    /* @3917512 constant */
    /* @3917516 sub */
    /* @3917520 call */
    GM_SITE(vm, 78, 3917520);
    v25 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3917528 cast */
    /* @3917532 not */
    /* @3917536 bf */
    v26 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(26)), v25, VAL(6))));
    if (!TRUTH(v26)) goto L_3917600;
    /* @3917540 constant */
    /* @3917544 cast */
    /* @3917548 load */
    /* @3917556 constant */
    /* @3917560 add */
    /* @3917564 load */
    /* @3917572 constant */
    /* @3917576 sub */
    /* @3917580 call */
    GM_SITE(vm, 78, 3917580);
    v27 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3917588 cast */
    /* @3917592 not */
    /* @3917596 b */
    v28 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(26)), v27, VAL(7))));
    p3917604_0 = v28;
    goto L_3917604;
    L_3917600: ;
    /* @3917600 constant */
    p3917604_0 = VAL(0);
    L_3917604: ;
    /* @3917604 bf */
    if (!TRUTH(p3917604_0)) goto L_3917772;
    /* @3917608 constant */
    /* @3917612 cast */
    /* @3917616 load */
    /* @3917624 constant */
    /* @3917628 add */
    /* @3917632 load */
    /* @3917640 call */
    GM_SITE(vm, 78, 3917640);
    v29 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3917648 cast */
    /* @3917652 bt */
    v30 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v29, VAL(4)));
    if (TRUTH(v30)) goto L_3917752;
    /* @3917656 constant */
    /* @3917660 cast */
    /* @3917664 load */
    /* @3917672 constant */
    /* @3917676 add */
    /* @3917680 load */
    /* @3917688 call */
    GM_SITE(vm, 78, 3917688);
    v31 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3917696 cast */
    /* @3917700 bt */
    v32 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v31, VAL(6)));
    if (TRUTH(v32)) goto L_3917752;
    /* @3917704 constant */
    /* @3917708 cast */
    /* @3917712 load */
    /* @3917720 constant */
    /* @3917724 add */
    /* @3917728 load */
    /* @3917736 call */
    GM_SITE(vm, 78, 3917736);
    v33 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3917744 cast */
    /* @3917748 b */
    v34 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v33, VAL(7)));
    p3917756_0 = v34;
    goto L_3917756;
    L_3917752: ;
    /* @3917752 constant */
    p3917756_0 = VAL(1);
    L_3917756: ;
    /* @3917756 bf */
    if (!TRUTH(p3917756_0)) goto L_3917772;
    /* @3917760 constant */
    /* @3917764 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    L_3917772: ;
    /* @3917772 load */
    /* @3917780 constant */
    /* @3917784 cmp */
    /* @3917788 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "stunned") == VAL(1)))) goto L_3917804;
    /* @3917792 constant */
    /* @3917796 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(112));
    L_3917804: ;
    /* @3917804 load */
    /* @3917812 constant */
    /* @3917816 cmp */
    /* @3917820 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "swordstunned") == VAL(1)))) goto L_3917860;
    /* @3917824 constant */
    /* @3917828 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(112));
    /* @3917836 constant */
    /* @3917840 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3917848 constant */
    /* @3917852 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_3917860: ;
    /* @3917860 load */
    /* @3917868 constant */
    /* @3917872 cmp */
    /* @3917876 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "poisoned") == VAL(1)))) goto L_3917896;
    /* @3917880 constant */
    /* @3917888 store */
    GM_WRITE(vm, -1, "image_blend", VAL(32768));
    L_3917896: ;
    /* @3917896 load */
    /* @3917904 constant */
    /* @3917908 cmp */
    /* @3917912 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_3917952;
    /* @3917916 constant */
    /* @3917920 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3917928 constant */
    /* @3917932 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @3917940 constant */
    /* @3917944 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(111));
    L_3917952: ;
    /* @3917952 constant */
    /* @3917956 store */
    GM_WRITE(vm, -1, "mask_index", VAL(111));
    /* @3917964 constant */
    /* @3917968 cast */
    /* @3917972 load */
    /* @3917980 constant */
    /* @3917984 add */
    /* @3917988 load */
    /* @3917996 call */
    GM_SITE(vm, 78, 3917996);
    v35 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @3918004 cast */
    /* @3918008 bf */
    v36 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v35, VAL(34)));
    if (!TRUTH(v36)) goto L_3918052;
    /* @3918012 constant */
    /* @3918016 store */
    GM_WRITE(vm, -1, "gravity", VAL(0));
    /* @3918024 constant */
    /* @3918028 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @3918036 constant */
    /* @3918040 store */
    GM_WRITE(vm, -1, "falling", VAL(0));
    /* @3918048 b */
    goto L_3918084;
    L_3918052: ;
    /* @3918052 constant */
    /* @3918064 store */
    GM_WRITE(vm, -1, "gravity", VAL(0.6));
    /* @3918072 constant */
    /* @3918076 store */
    GM_WRITE(vm, -1, "falling", VAL(1));
    L_3918084: ;
    return;
}
