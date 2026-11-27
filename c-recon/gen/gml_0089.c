/* generated from CODE 89 (gml_Object_obj_firehulk_Step_0), source start 3924484, end 3926116. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0089(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val p3924844_0;
    Val v4;
    Val v5;
    Val v6;
    Val p3924960_0;
    Val v7;
    Val v8;
    Val p3925076_0;
    Val v9;
    Val v10;
    Val v11;
    Val v12;
    Val v13;
    Val v14;
    Val v15;
    Val v16;
    Val v17;
    Val p3925276_0;
    Val v18;
    Val v19;
    Val v20;
    Val v21;
    Val v22;
    Val v23;
    Val p3925428_0;
    Val v24;
    Val v25;
    Val v26;
    Val v27;
    Val v28;
    Val v29;
    Val p3925628_0;
    Val v30;
    Val v31;
    Val v32;
    Val v33;
    Val v34;
    Val v35;
    Val p3925780_0;
    Val v36;
    /* @3924484 load */
    /* @3924492 constant */
    /* @3924496 cmp */
    /* @3924500 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpfirehulk") >= VAL(0)))) goto L_3924524;
    /* @3924504 constant */
    /* @3924508 constant */
    /* @3924512 constant */
    /* @3924516 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(0));
    L_3924524: ;
    /* @3924524 load */
    /* @3924532 constant */
    /* @3924536 cmp */
    /* @3924540 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpfirehulk") <= VAL(0)))) goto L_3924564;
    /* @3924544 constant */
    /* @3924548 constant */
    /* @3924552 constant */
    /* @3924556 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    L_3924564: ;
    /* @3924564 constant */
    /* @3924568 cast */
    /* @3924572 load */
    /* @3924580 constant */
    /* @3924584 add */
    /* @3924588 load */
    /* @3924596 call */
    GM_SITE(vm, 89, 3924596);
    v1 = GM_ADD(GM_READ(vm, -1, "y"), VAL(2));
    /* @3924604 cast */
    /* @3924608 bf */
    v2 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v1, VAL(34)));
    if (!TRUTH(v2)) goto L_3924652;
    /* @3924612 constant */
    /* @3924616 store */
    GM_WRITE(vm, -1, "gravity", VAL(0));
    /* @3924624 constant */
    /* @3924628 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @3924636 constant */
    /* @3924640 store */
    GM_WRITE(vm, -1, "falling", VAL(0));
    /* @3924648 b */
    goto L_3924684;
    L_3924652: ;
    /* @3924652 constant */
    /* @3924664 store */
    GM_WRITE(vm, -1, "gravity", VAL(0.6));
    /* @3924672 constant */
    /* @3924676 store */
    GM_WRITE(vm, -1, "falling", VAL(1));
    L_3924684: ;
    /* @3924684 load */
    /* @3924692 constant */
    /* @3924696 cmp */
    /* @3924700 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3924728;
    /* @3924704 constant */
    /* @3924708 store */
    GM_WRITE(vm, -1, "hspeed", VAL(2));
    /* @3924716 constant */
    /* @3924720 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(1));
    L_3924728: ;
    /* @3924728 load */
    /* @3924736 constant */
    /* @3924740 cmp */
    /* @3924744 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3924772;
    /* @3924748 constant */
    /* @3924752 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-2));
    /* @3924760 constant */
    /* @3924764 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    L_3924772: ;
    /* @3924772 constant */
    /* @3924776 cast */
    /* @3924780 call */
    GM_SITE(vm, 89, 3924780);
    /* @3924788 constant */
    /* @3924792 cmp */
    /* @3924796 bf */
    v3 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(50));
    if (!TRUTH(v3)) goto L_3924860;
    /* @3924800 load */
    /* @3924808 constant */
    /* @3924812 cmp */
    /* @3924816 bt */
    if (TRUTH(NUMBOOL(GM_READ(vm, 0, "invulnerable") == VAL(1)))) goto L_3924840;
    /* @3924820 load */
    /* @3924828 constant */
    /* @3924832 cmp */
    /* @3924836 b */
    p3924844_0 = NUMBOOL(GM_READ(vm, 0, "invulnerable2") == VAL(1));
    goto L_3924844;
    L_3924840: ;
    /* @3924840 constant */
    p3924844_0 = VAL(1);
    L_3924844: ;
    /* @3924844 bf */
    if (!TRUTH(p3924844_0)) goto L_3924860;
    /* @3924848 constant */
    /* @3924852 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3924860: ;
    /* @3924860 constant */
    /* @3924864 cast */
    /* @3924868 load */
    /* @3924876 load */
    /* @3924884 constant */
    /* @3924888 add */
    /* @3924892 call */
    GM_SITE(vm, 89, 3924892);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @3924900 cast */
    /* @3924904 bt */
    v5 = BOOL(GM_CALL(vm, "instance_place", 3, v4, GM_READ(vm, -1, "y"), VAL(4)));
    if (TRUTH(v5)) goto L_3924956;
    /* @3924908 constant */
    /* @3924912 cast */
    /* @3924916 load */
    /* @3924924 load */
    /* @3924932 constant */
    /* @3924936 add */
    /* @3924940 call */
    GM_SITE(vm, 89, 3924940);
    v6 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @3924948 cast */
    /* @3924952 b */
    v7 = BOOL(GM_CALL(vm, "instance_place", 3, v6, GM_READ(vm, -1, "y"), VAL(6)));
    p3924960_0 = v7;
    goto L_3924960;
    L_3924956: ;
    /* @3924956 constant */
    p3924960_0 = VAL(1);
    L_3924960: ;
    /* @3924960 bf */
    if (!TRUTH(p3924960_0)) goto L_3924976;
    /* @3924964 constant */
    /* @3924968 store */
    GM_WRITE(vm, -1, "facing", VAL(1));
    L_3924976: ;
    /* @3924976 constant */
    /* @3924980 cast */
    /* @3924984 load */
    /* @3924992 load */
    /* @3925000 constant */
    /* @3925004 sub */
    /* @3925008 call */
    GM_SITE(vm, 89, 3925008);
    /* @3925016 cast */
    /* @3925020 bt */
    v8 = BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(5)), GM_READ(vm, -1, "y"), VAL(4)));
    if (TRUTH(v8)) goto L_3925072;
    /* @3925024 constant */
    /* @3925028 cast */
    /* @3925032 load */
    /* @3925040 load */
    /* @3925048 constant */
    /* @3925052 sub */
    /* @3925056 call */
    GM_SITE(vm, 89, 3925056);
    /* @3925064 cast */
    /* @3925068 b */
    v9 = BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(5)), GM_READ(vm, -1, "y"), VAL(6)));
    p3925076_0 = v9;
    goto L_3925076;
    L_3925072: ;
    /* @3925072 constant */
    p3925076_0 = VAL(1);
    L_3925076: ;
    /* @3925076 bf */
    if (!TRUTH(p3925076_0)) goto L_3925092;
    /* @3925080 constant */
    /* @3925084 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    L_3925092: ;
    /* @3925092 constant */
    /* @3925096 cast */
    /* @3925100 load */
    /* @3925108 constant */
    /* @3925112 add */
    /* @3925116 load */
    /* @3925124 constant */
    /* @3925128 add */
    /* @3925132 call */
    GM_SITE(vm, 89, 3925132);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(50));
    v11 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3925140 cast */
    /* @3925144 not */
    /* @3925148 bf */
    v12 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v10, v11, VAL(4))));
    if (!TRUTH(v12)) goto L_3925272;
    /* @3925152 constant */
    /* @3925156 cast */
    /* @3925160 load */
    /* @3925168 constant */
    /* @3925172 add */
    /* @3925176 load */
    /* @3925184 constant */
    /* @3925188 add */
    /* @3925192 call */
    GM_SITE(vm, 89, 3925192);
    v13 = GM_ADD(GM_READ(vm, -1, "x"), VAL(50));
    v14 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3925200 cast */
    /* @3925204 not */
    /* @3925208 bf */
    v15 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v13, v14, VAL(6))));
    if (!TRUTH(v15)) goto L_3925272;
    /* @3925212 constant */
    /* @3925216 cast */
    /* @3925220 load */
    /* @3925228 constant */
    /* @3925232 add */
    /* @3925236 load */
    /* @3925244 constant */
    /* @3925248 add */
    /* @3925252 call */
    GM_SITE(vm, 89, 3925252);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(50));
    v17 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3925260 cast */
    /* @3925264 not */
    /* @3925268 b */
    v18 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v16, v17, VAL(7))));
    p3925276_0 = v18;
    goto L_3925276;
    L_3925272: ;
    /* @3925272 constant */
    p3925276_0 = VAL(0);
    L_3925276: ;
    /* @3925276 bf */
    if (!TRUTH(p3925276_0)) goto L_3925444;
    /* @3925280 constant */
    /* @3925284 cast */
    /* @3925288 load */
    /* @3925296 constant */
    /* @3925300 add */
    /* @3925304 load */
    /* @3925312 call */
    GM_SITE(vm, 89, 3925312);
    v19 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3925320 cast */
    /* @3925324 bt */
    v20 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v19, VAL(4)));
    if (TRUTH(v20)) goto L_3925424;
    /* @3925328 constant */
    /* @3925332 cast */
    /* @3925336 load */
    /* @3925344 constant */
    /* @3925348 add */
    /* @3925352 load */
    /* @3925360 call */
    GM_SITE(vm, 89, 3925360);
    v21 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3925368 cast */
    /* @3925372 bt */
    v22 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v21, VAL(6)));
    if (TRUTH(v22)) goto L_3925424;
    /* @3925376 constant */
    /* @3925380 cast */
    /* @3925384 load */
    /* @3925392 constant */
    /* @3925396 add */
    /* @3925400 load */
    /* @3925408 call */
    GM_SITE(vm, 89, 3925408);
    v23 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3925416 cast */
    /* @3925420 b */
    v24 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v23, VAL(7)));
    p3925428_0 = v24;
    goto L_3925428;
    L_3925424: ;
    /* @3925424 constant */
    p3925428_0 = VAL(1);
    L_3925428: ;
    /* @3925428 bf */
    if (!TRUTH(p3925428_0)) goto L_3925444;
    /* @3925432 constant */
    /* @3925436 store */
    GM_WRITE(vm, -1, "facing", VAL(1));
    L_3925444: ;
    /* @3925444 constant */
    /* @3925448 cast */
    /* @3925452 load */
    /* @3925460 constant */
    /* @3925464 add */
    /* @3925468 load */
    /* @3925476 constant */
    /* @3925480 sub */
    /* @3925484 call */
    GM_SITE(vm, 89, 3925484);
    v25 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3925492 cast */
    /* @3925496 not */
    /* @3925500 bf */
    v26 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(50)), v25, VAL(4))));
    if (!TRUTH(v26)) goto L_3925624;
    /* @3925504 constant */
    /* @3925508 cast */
    /* @3925512 load */
    /* @3925520 constant */
    /* @3925524 add */
    /* @3925528 load */
    /* @3925536 constant */
    /* @3925540 sub */
    /* @3925544 call */
    GM_SITE(vm, 89, 3925544);
    v27 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3925552 cast */
    /* @3925556 not */
    /* @3925560 bf */
    v28 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(50)), v27, VAL(6))));
    if (!TRUTH(v28)) goto L_3925624;
    /* @3925564 constant */
    /* @3925568 cast */
    /* @3925572 load */
    /* @3925580 constant */
    /* @3925584 add */
    /* @3925588 load */
    /* @3925596 constant */
    /* @3925600 sub */
    /* @3925604 call */
    GM_SITE(vm, 89, 3925604);
    v29 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3925612 cast */
    /* @3925616 not */
    /* @3925620 b */
    v30 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(50)), v29, VAL(7))));
    p3925628_0 = v30;
    goto L_3925628;
    L_3925624: ;
    /* @3925624 constant */
    p3925628_0 = VAL(0);
    L_3925628: ;
    /* @3925628 bf */
    if (!TRUTH(p3925628_0)) goto L_3925796;
    /* @3925632 constant */
    /* @3925636 cast */
    /* @3925640 load */
    /* @3925648 constant */
    /* @3925652 add */
    /* @3925656 load */
    /* @3925664 call */
    GM_SITE(vm, 89, 3925664);
    v31 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3925672 cast */
    /* @3925676 bt */
    v32 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v31, VAL(4)));
    if (TRUTH(v32)) goto L_3925776;
    /* @3925680 constant */
    /* @3925684 cast */
    /* @3925688 load */
    /* @3925696 constant */
    /* @3925700 add */
    /* @3925704 load */
    /* @3925712 call */
    GM_SITE(vm, 89, 3925712);
    v33 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3925720 cast */
    /* @3925724 bt */
    v34 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v33, VAL(6)));
    if (TRUTH(v34)) goto L_3925776;
    /* @3925728 constant */
    /* @3925732 cast */
    /* @3925736 load */
    /* @3925744 constant */
    /* @3925748 add */
    /* @3925752 load */
    /* @3925760 call */
    GM_SITE(vm, 89, 3925760);
    v35 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3925768 cast */
    /* @3925772 b */
    v36 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v35, VAL(7)));
    p3925780_0 = v36;
    goto L_3925780;
    L_3925776: ;
    /* @3925776 constant */
    p3925780_0 = VAL(1);
    L_3925780: ;
    /* @3925780 bf */
    if (!TRUTH(p3925780_0)) goto L_3925796;
    /* @3925784 constant */
    /* @3925788 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    L_3925796: ;
    /* @3925796 load */
    /* @3925804 constant */
    /* @3925808 cmp */
    /* @3925812 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpfirehulkfrozen") == VAL(1)))) goto L_3925860;
    /* @3925816 constant */
    /* @3925824 store */
    GM_WRITE(vm, -1, "image_blend", VAL(16711680));
    /* @3925832 constant */
    /* @3925836 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3925844 constant */
    /* @3925848 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @3925856 b */
    goto L_3925876;
    L_3925860: ;
    /* @3925860 constant */
    /* @3925868 store */
    GM_WRITE(vm, -1, "image_blend", VAL(16777215));
    L_3925876: ;
    /* @3925876 load */
    /* @3925884 constant */
    /* @3925888 cmp */
    /* @3925892 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "stunned") == VAL(1)))) goto L_3925908;
    /* @3925896 constant */
    /* @3925900 store */
    GM_WRITE(vm, -1, "image_blend", VAL(255));
    L_3925908: ;
    /* @3925908 load */
    /* @3925916 constant */
    /* @3925920 cmp */
    /* @3925924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "swordstunned") == VAL(1)))) goto L_3925964;
    /* @3925928 constant */
    /* @3925932 store */
    GM_WRITE(vm, -1, "image_blend", VAL(255));
    /* @3925940 constant */
    /* @3925944 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3925952 constant */
    /* @3925956 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_3925964: ;
    /* @3925964 load */
    /* @3925972 load */
    /* @3925980 cmp */
    /* @3925984 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "x") > GM_READ(vm, -1, "x")))) goto L_3926000;
    /* @3925988 constant */
    /* @3925992 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(1));
    L_3926000: ;
    /* @3926000 load */
    /* @3926008 load */
    /* @3926016 cmp */
    /* @3926020 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "x") < GM_READ(vm, -1, "x")))) goto L_3926036;
    /* @3926024 constant */
    /* @3926028 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    L_3926036: ;
    /* @3926036 load */
    /* @3926044 constant */
    /* @3926048 cmp */
    /* @3926052 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "poisoned") == VAL(1)))) goto L_3926072;
    /* @3926056 constant */
    /* @3926064 store */
    GM_WRITE(vm, -1, "image_blend", VAL(32768));
    L_3926072: ;
    /* @3926072 load */
    /* @3926080 constant */
    /* @3926084 cmp */
    /* @3926088 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_3926116;
    /* @3926092 constant */
    /* @3926096 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3926104 constant */
    /* @3926108 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_3926116: ;
    return;
}
