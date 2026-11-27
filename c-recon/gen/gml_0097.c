/* generated from CODE 97 (gml_Object_obj_zombie_Alarm_0), source start 3927340, end 3931916. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0097(GmVM* vm) {
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
    Val v11;
    Val v12;
    Val v13;
    Val v14;
    Val v15;
    Val v16;
    Val v17;
    Val v18;
    Val v19;
    Val v20;
    Val v21;
    Val v22;
    Val v23;
    Val v24;
    Val v25;
    Val v26;
    Val v27;
    Val v28;
    Val v29;
    Val v30;
    Val v31;
    Val v32;
    Val v33;
    Val v34;
    Val v35;
    Val v36;
    Val v37;
    Val v38;
    Val v39;
    Val v40;
    Val v41;
    Val v42;
    Val v43;
    Val v44;
    Val v45;
    Val v46;
    Val v47;
    Val v48;
    Val v49;
    Val v50;
    Val v51;
    Val v52;
    Val v53;
    Val v54;
    Val v55;
    Val v56;
    Val v57;
    Val v58;
    Val v59;
    Val v60;
    Val v61;
    Val v62;
    /* @3927340 load */
    /* @3927348 constant */
    /* @3927352 cmp */
    /* @3927356 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3927364;
    /* @3927360 b */
    goto L_3927420;
    L_3927364: ;
    /* @3927364 load */
    /* @3927372 constant */
    /* @3927376 cmp */
    /* @3927380 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3927420;
    /* @3927384 constant */
    /* @3927388 cast */
    /* @3927392 constant */
    /* @3927396 cast */
    /* @3927400 constant */
    /* @3927404 cast */
    /* @3927408 call */
    GM_SITE(vm, 97, 3927408);
    /* @3927416 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(7), VAL(0), VAL(0)));
    L_3927420: ;
    /* @3927420 load */
    /* @3927428 constant */
    /* @3927432 cmp */
    /* @3927436 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "gemdropenabled") == VAL(1)))) goto L_3927484;
    /* @3927440 constant */
    /* @3927444 cast */
    /* @3927448 load */
    /* @3927456 constant */
    /* @3927460 sub */
    /* @3927464 load */
    /* @3927472 call */
    GM_SITE(vm, 97, 3927472);
    /* @3927480 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(59)));
    L_3927484: ;
    /* @3927484 load */
    /* @3927492 constant */
    /* @3927496 cmp */
    /* @3927500 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpdrop") == VAL(1)))) goto L_3927548;
    /* @3927504 constant */
    /* @3927508 cast */
    /* @3927512 load */
    /* @3927520 constant */
    /* @3927524 sub */
    /* @3927528 load */
    /* @3927536 call */
    GM_SITE(vm, 97, 3927536);
    /* @3927544 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(62)));
    L_3927548: ;
    /* @3927548 load */
    /* @3927556 constant */
    /* @3927560 cmp */
    /* @3927564 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "xpdrop") == VAL(1)))) goto L_3927664;
    /* @3927568 constant */
    /* @3927572 cast */
    /* @3927576 load */
    /* @3927584 constant */
    /* @3927588 sub */
    /* @3927592 load */
    /* @3927600 call */
    GM_SITE(vm, 97, 3927600);
    /* @3927608 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID", v1);
    /* @3927616 load */
    /* @3927624 cast */
    /* @3927628 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3927660;
    L_3927632: ;
    /* @3927632 constant */
    /* @3927636 cast */
    /* @3927640 load */
    /* @3927648 call */
    GM_SITE(vm, 97, 3927648);
    /* @3927656 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "xpspread"), VAL(5)));
    L_3927660: ;
    /* @3927660 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3927632;
    L_3927664: ;
    /* @3927664 constant */
    /* @3927668 cast */
    /* @3927672 call */
    GM_SITE(vm, 97, 3927672);
    /* @3927680 constant */
    /* @3927684 cmp */
    /* @3927688 bf */
    v2 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) >= VAL(20));
    if (!TRUTH(v2)) goto L_3927696;
    /* @3927692 b */
    goto L_3931904;
    L_3927696: ;
    /* @3927696 constant */
    /* @3927700 cast */
    /* @3927704 call */
    GM_SITE(vm, 97, 3927704);
    /* @3927712 constant */
    /* @3927716 cmp */
    /* @3927720 bf */
    v3 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) < VAL(20));
    if (!TRUTH(v3)) goto L_3931904;
    /* @3927724 load */
    /* @3927732 constant */
    /* @3927736 cmp */
    /* @3927740 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(1)))) goto L_3928256;
    /* @3927744 constant */
    /* @3927748 cast */
    /* @3927752 load */
    /* @3927760 constant */
    /* @3927764 sub */
    /* @3927768 load */
    /* @3927776 call */
    GM_SITE(vm, 97, 3927776);
    /* @3927784 store */
    v4 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v4);
    /* @3927792 load */
    /* @3927800 cast */
    /* @3927804 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3927836;
    L_3927808: ;
    /* @3927808 constant */
    /* @3927812 cast */
    /* @3927816 load */
    /* @3927824 call */
    GM_SITE(vm, 97, 3927824);
    /* @3927832 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3927836: ;
    /* @3927836 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3927808;
    /* @3927840 constant */
    /* @3927844 cast */
    /* @3927848 load */
    /* @3927856 constant */
    /* @3927860 sub */
    /* @3927864 load */
    /* @3927872 constant */
    /* @3927876 add */
    /* @3927880 call */
    GM_SITE(vm, 97, 3927880);
    v5 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3927888 store */
    v6 = GM_CALL(vm, "instance_create", 3, v5, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v6);
    /* @3927896 load */
    /* @3927904 cast */
    /* @3927908 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3927940;
    L_3927912: ;
    /* @3927912 constant */
    /* @3927916 cast */
    /* @3927920 load */
    /* @3927928 call */
    GM_SITE(vm, 97, 3927928);
    /* @3927936 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3927940: ;
    /* @3927940 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3927912;
    /* @3927944 constant */
    /* @3927948 cast */
    /* @3927952 load */
    /* @3927960 constant */
    /* @3927964 sub */
    /* @3927968 load */
    /* @3927976 constant */
    /* @3927980 sub */
    /* @3927984 call */
    GM_SITE(vm, 97, 3927984);
    /* @3927992 store */
    v7 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v7);
    /* @3928000 load */
    /* @3928008 cast */
    /* @3928012 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3928044;
    L_3928016: ;
    /* @3928016 constant */
    /* @3928020 cast */
    /* @3928024 load */
    /* @3928032 call */
    GM_SITE(vm, 97, 3928032);
    /* @3928040 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3928044: ;
    /* @3928044 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3928016;
    /* @3928048 constant */
    /* @3928052 cast */
    /* @3928056 load */
    /* @3928064 constant */
    /* @3928068 sub */
    /* @3928072 load */
    /* @3928080 constant */
    /* @3928084 add */
    /* @3928088 call */
    GM_SITE(vm, 97, 3928088);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3928096 store */
    v9 = GM_CALL(vm, "instance_create", 3, v8, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v9);
    /* @3928104 load */
    /* @3928112 cast */
    /* @3928116 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3928148;
    L_3928120: ;
    /* @3928120 constant */
    /* @3928124 cast */
    /* @3928128 load */
    /* @3928136 call */
    GM_SITE(vm, 97, 3928136);
    /* @3928144 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3928148: ;
    /* @3928148 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3928120;
    /* @3928152 constant */
    /* @3928156 cast */
    /* @3928160 load */
    /* @3928168 constant */
    /* @3928172 sub */
    /* @3928176 load */
    /* @3928184 constant */
    /* @3928188 sub */
    /* @3928192 call */
    GM_SITE(vm, 97, 3928192);
    /* @3928200 store */
    v10 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v10);
    /* @3928208 load */
    /* @3928216 cast */
    /* @3928220 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3928252;
    L_3928224: ;
    /* @3928224 constant */
    /* @3928228 cast */
    /* @3928232 load */
    /* @3928240 call */
    GM_SITE(vm, 97, 3928240);
    /* @3928248 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3928252: ;
    /* @3928252 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3928224;
    L_3928256: ;
    /* @3928256 load */
    /* @3928264 constant */
    /* @3928268 cmp */
    /* @3928272 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(2)))) goto L_3928948;
    /* @3928276 constant */
    /* @3928280 cast */
    /* @3928284 load */
    /* @3928292 constant */
    /* @3928296 sub */
    /* @3928300 load */
    /* @3928308 call */
    GM_SITE(vm, 97, 3928308);
    /* @3928316 store */
    v11 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v11);
    /* @3928324 load */
    /* @3928332 cast */
    /* @3928336 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3928368;
    L_3928340: ;
    /* @3928340 constant */
    /* @3928344 cast */
    /* @3928348 load */
    /* @3928356 call */
    GM_SITE(vm, 97, 3928356);
    /* @3928364 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3928368: ;
    /* @3928368 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3928340;
    /* @3928372 constant */
    /* @3928376 cast */
    /* @3928380 load */
    /* @3928388 constant */
    /* @3928392 sub */
    /* @3928396 load */
    /* @3928404 constant */
    /* @3928408 add */
    /* @3928412 call */
    GM_SITE(vm, 97, 3928412);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3928420 store */
    v13 = GM_CALL(vm, "instance_create", 3, v12, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v13);
    /* @3928428 load */
    /* @3928436 cast */
    /* @3928440 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3928472;
    L_3928444: ;
    /* @3928444 constant */
    /* @3928448 cast */
    /* @3928452 load */
    /* @3928460 call */
    GM_SITE(vm, 97, 3928460);
    /* @3928468 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3928472: ;
    /* @3928472 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3928444;
    /* @3928476 constant */
    /* @3928480 cast */
    /* @3928484 load */
    /* @3928492 constant */
    /* @3928496 sub */
    /* @3928500 load */
    /* @3928508 constant */
    /* @3928512 sub */
    /* @3928516 call */
    GM_SITE(vm, 97, 3928516);
    /* @3928524 store */
    v14 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v14);
    /* @3928532 load */
    /* @3928540 cast */
    /* @3928544 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3928576;
    L_3928548: ;
    /* @3928548 constant */
    /* @3928552 cast */
    /* @3928556 load */
    /* @3928564 call */
    GM_SITE(vm, 97, 3928564);
    /* @3928572 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3928576: ;
    /* @3928576 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3928548;
    /* @3928580 constant */
    /* @3928584 cast */
    /* @3928588 load */
    /* @3928596 constant */
    /* @3928600 sub */
    /* @3928604 load */
    /* @3928612 constant */
    /* @3928616 add */
    /* @3928620 call */
    GM_SITE(vm, 97, 3928620);
    v15 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3928628 store */
    v16 = GM_CALL(vm, "instance_create", 3, v15, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v16);
    /* @3928636 load */
    /* @3928644 cast */
    /* @3928648 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3928680;
    L_3928652: ;
    /* @3928652 constant */
    /* @3928656 cast */
    /* @3928660 load */
    /* @3928668 call */
    GM_SITE(vm, 97, 3928668);
    /* @3928676 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3928680: ;
    /* @3928680 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3928652;
    /* @3928684 constant */
    /* @3928688 cast */
    /* @3928692 load */
    /* @3928700 constant */
    /* @3928704 sub */
    /* @3928708 load */
    /* @3928716 constant */
    /* @3928720 sub */
    /* @3928724 call */
    GM_SITE(vm, 97, 3928724);
    /* @3928732 store */
    v17 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v17);
    /* @3928740 load */
    /* @3928748 cast */
    /* @3928752 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3928784;
    L_3928756: ;
    /* @3928756 constant */
    /* @3928760 cast */
    /* @3928764 load */
    /* @3928772 call */
    GM_SITE(vm, 97, 3928772);
    /* @3928780 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3928784: ;
    /* @3928784 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3928756;
    /* @3928788 constant */
    /* @3928792 cast */
    /* @3928796 load */
    /* @3928804 constant */
    /* @3928808 sub */
    /* @3928812 load */
    /* @3928820 constant */
    /* @3928824 sub */
    /* @3928828 call */
    GM_SITE(vm, 97, 3928828);
    /* @3928836 store */
    v18 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v18);
    /* @3928844 load */
    /* @3928852 cast */
    /* @3928856 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3928888;
    L_3928860: ;
    /* @3928860 constant */
    /* @3928864 cast */
    /* @3928868 load */
    /* @3928876 call */
    GM_SITE(vm, 97, 3928876);
    /* @3928884 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3928888: ;
    /* @3928888 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3928860;
    /* @3928892 constant */
    /* @3928896 cast */
    /* @3928900 load */
    /* @3928908 constant */
    /* @3928912 sub */
    /* @3928916 load */
    /* @3928924 constant */
    /* @3928928 add */
    /* @3928932 call */
    GM_SITE(vm, 97, 3928932);
    v19 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3928940 store */
    v20 = GM_CALL(vm, "instance_create", 3, v19, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v20);
    L_3928948: ;
    /* @3928948 load */
    /* @3928956 constant */
    /* @3928960 cmp */
    /* @3928964 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(3)))) goto L_3929640;
    /* @3928968 constant */
    /* @3928972 cast */
    /* @3928976 load */
    /* @3928984 constant */
    /* @3928988 sub */
    /* @3928992 load */
    /* @3929000 call */
    GM_SITE(vm, 97, 3929000);
    /* @3929008 store */
    v21 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v21);
    /* @3929016 load */
    /* @3929024 cast */
    /* @3929028 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3929060;
    L_3929032: ;
    /* @3929032 constant */
    /* @3929036 cast */
    /* @3929040 load */
    /* @3929048 call */
    GM_SITE(vm, 97, 3929048);
    /* @3929056 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3929060: ;
    /* @3929060 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3929032;
    /* @3929064 constant */
    /* @3929068 cast */
    /* @3929072 load */
    /* @3929080 constant */
    /* @3929084 sub */
    /* @3929088 load */
    /* @3929096 constant */
    /* @3929100 add */
    /* @3929104 call */
    GM_SITE(vm, 97, 3929104);
    v22 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3929112 store */
    v23 = GM_CALL(vm, "instance_create", 3, v22, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v23);
    /* @3929120 load */
    /* @3929128 cast */
    /* @3929132 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3929164;
    L_3929136: ;
    /* @3929136 constant */
    /* @3929140 cast */
    /* @3929144 load */
    /* @3929152 call */
    GM_SITE(vm, 97, 3929152);
    /* @3929160 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3929164: ;
    /* @3929164 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3929136;
    /* @3929168 constant */
    /* @3929172 cast */
    /* @3929176 load */
    /* @3929184 constant */
    /* @3929188 sub */
    /* @3929192 load */
    /* @3929200 constant */
    /* @3929204 sub */
    /* @3929208 call */
    GM_SITE(vm, 97, 3929208);
    /* @3929216 store */
    v24 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v24);
    /* @3929224 load */
    /* @3929232 cast */
    /* @3929236 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3929268;
    L_3929240: ;
    /* @3929240 constant */
    /* @3929244 cast */
    /* @3929248 load */
    /* @3929256 call */
    GM_SITE(vm, 97, 3929256);
    /* @3929264 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3929268: ;
    /* @3929268 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3929240;
    /* @3929272 constant */
    /* @3929276 cast */
    /* @3929280 load */
    /* @3929288 constant */
    /* @3929292 sub */
    /* @3929296 load */
    /* @3929304 constant */
    /* @3929308 add */
    /* @3929312 call */
    GM_SITE(vm, 97, 3929312);
    v25 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3929320 store */
    v26 = GM_CALL(vm, "instance_create", 3, v25, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v26);
    /* @3929328 load */
    /* @3929336 cast */
    /* @3929340 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3929372;
    L_3929344: ;
    /* @3929344 constant */
    /* @3929348 cast */
    /* @3929352 load */
    /* @3929360 call */
    GM_SITE(vm, 97, 3929360);
    /* @3929368 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3929372: ;
    /* @3929372 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3929344;
    /* @3929376 constant */
    /* @3929380 cast */
    /* @3929384 load */
    /* @3929392 constant */
    /* @3929396 sub */
    /* @3929400 load */
    /* @3929408 constant */
    /* @3929412 sub */
    /* @3929416 call */
    GM_SITE(vm, 97, 3929416);
    /* @3929424 store */
    v27 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v27);
    /* @3929432 load */
    /* @3929440 cast */
    /* @3929444 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3929476;
    L_3929448: ;
    /* @3929448 constant */
    /* @3929452 cast */
    /* @3929456 load */
    /* @3929464 call */
    GM_SITE(vm, 97, 3929464);
    /* @3929472 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3929476: ;
    /* @3929476 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3929448;
    /* @3929480 constant */
    /* @3929484 cast */
    /* @3929488 load */
    /* @3929496 constant */
    /* @3929500 sub */
    /* @3929504 load */
    /* @3929512 constant */
    /* @3929516 sub */
    /* @3929520 call */
    GM_SITE(vm, 97, 3929520);
    /* @3929528 store */
    v28 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v28);
    /* @3929536 load */
    /* @3929544 cast */
    /* @3929548 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3929580;
    L_3929552: ;
    /* @3929552 constant */
    /* @3929556 cast */
    /* @3929560 load */
    /* @3929568 call */
    GM_SITE(vm, 97, 3929568);
    /* @3929576 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3929580: ;
    /* @3929580 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3929552;
    /* @3929584 constant */
    /* @3929588 cast */
    /* @3929592 load */
    /* @3929600 constant */
    /* @3929604 sub */
    /* @3929608 load */
    /* @3929616 constant */
    /* @3929620 add */
    /* @3929624 call */
    GM_SITE(vm, 97, 3929624);
    v29 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3929632 store */
    v30 = GM_CALL(vm, "instance_create", 3, v29, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v30);
    L_3929640: ;
    /* @3929640 load */
    /* @3929648 constant */
    /* @3929652 cmp */
    /* @3929656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(4)))) goto L_3930748;
    /* @3929660 constant */
    /* @3929664 cast */
    /* @3929668 load */
    /* @3929676 constant */
    /* @3929680 sub */
    /* @3929684 load */
    /* @3929692 call */
    GM_SITE(vm, 97, 3929692);
    /* @3929700 store */
    v31 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v31);
    /* @3929708 load */
    /* @3929716 cast */
    /* @3929720 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3929752;
    L_3929724: ;
    /* @3929724 constant */
    /* @3929728 cast */
    /* @3929732 load */
    /* @3929740 call */
    GM_SITE(vm, 97, 3929740);
    /* @3929748 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3929752: ;
    /* @3929752 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3929724;
    /* @3929756 constant */
    /* @3929760 cast */
    /* @3929764 load */
    /* @3929772 constant */
    /* @3929776 sub */
    /* @3929780 load */
    /* @3929788 constant */
    /* @3929792 add */
    /* @3929796 call */
    GM_SITE(vm, 97, 3929796);
    v32 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3929804 store */
    v33 = GM_CALL(vm, "instance_create", 3, v32, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v33);
    /* @3929812 load */
    /* @3929820 cast */
    /* @3929824 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3929856;
    L_3929828: ;
    /* @3929828 constant */
    /* @3929832 cast */
    /* @3929836 load */
    /* @3929844 call */
    GM_SITE(vm, 97, 3929844);
    /* @3929852 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3929856: ;
    /* @3929856 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3929828;
    /* @3929860 constant */
    /* @3929864 cast */
    /* @3929868 load */
    /* @3929876 constant */
    /* @3929880 sub */
    /* @3929884 load */
    /* @3929892 constant */
    /* @3929896 sub */
    /* @3929900 call */
    GM_SITE(vm, 97, 3929900);
    /* @3929908 store */
    v34 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v34);
    /* @3929916 load */
    /* @3929924 cast */
    /* @3929928 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3929960;
    L_3929932: ;
    /* @3929932 constant */
    /* @3929936 cast */
    /* @3929940 load */
    /* @3929948 call */
    GM_SITE(vm, 97, 3929948);
    /* @3929956 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3929960: ;
    /* @3929960 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3929932;
    /* @3929964 constant */
    /* @3929968 cast */
    /* @3929972 load */
    /* @3929980 constant */
    /* @3929984 sub */
    /* @3929988 load */
    /* @3929996 constant */
    /* @3930000 add */
    /* @3930004 call */
    GM_SITE(vm, 97, 3930004);
    v35 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3930012 store */
    v36 = GM_CALL(vm, "instance_create", 3, v35, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v36);
    /* @3930020 load */
    /* @3930028 cast */
    /* @3930032 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3930064;
    L_3930036: ;
    /* @3930036 constant */
    /* @3930040 cast */
    /* @3930044 load */
    /* @3930052 call */
    GM_SITE(vm, 97, 3930052);
    /* @3930060 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3930064: ;
    /* @3930064 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3930036;
    /* @3930068 constant */
    /* @3930072 cast */
    /* @3930076 load */
    /* @3930084 constant */
    /* @3930088 sub */
    /* @3930092 load */
    /* @3930100 constant */
    /* @3930104 sub */
    /* @3930108 call */
    GM_SITE(vm, 97, 3930108);
    /* @3930116 store */
    v37 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v37);
    /* @3930124 load */
    /* @3930132 cast */
    /* @3930136 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3930168;
    L_3930140: ;
    /* @3930140 constant */
    /* @3930144 cast */
    /* @3930148 load */
    /* @3930156 call */
    GM_SITE(vm, 97, 3930156);
    /* @3930164 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3930168: ;
    /* @3930168 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3930140;
    /* @3930172 constant */
    /* @3930176 cast */
    /* @3930180 load */
    /* @3930188 constant */
    /* @3930192 sub */
    /* @3930196 load */
    /* @3930204 constant */
    /* @3930208 add */
    /* @3930212 call */
    GM_SITE(vm, 97, 3930212);
    v38 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @3930220 store */
    v39 = GM_CALL(vm, "instance_create", 3, v38, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v39);
    /* @3930228 load */
    /* @3930236 cast */
    /* @3930240 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3930272;
    L_3930244: ;
    /* @3930244 constant */
    /* @3930248 cast */
    /* @3930252 load */
    /* @3930260 call */
    GM_SITE(vm, 97, 3930260);
    /* @3930268 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3930272: ;
    /* @3930272 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3930244;
    /* @3930276 constant */
    /* @3930280 cast */
    /* @3930284 load */
    /* @3930292 constant */
    /* @3930296 sub */
    /* @3930300 load */
    /* @3930308 constant */
    /* @3930312 add */
    /* @3930316 call */
    GM_SITE(vm, 97, 3930316);
    v40 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3930324 store */
    v41 = GM_CALL(vm, "instance_create", 3, v40, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v41);
    /* @3930332 load */
    /* @3930340 cast */
    /* @3930344 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3930376;
    L_3930348: ;
    /* @3930348 constant */
    /* @3930352 cast */
    /* @3930356 load */
    /* @3930364 call */
    GM_SITE(vm, 97, 3930364);
    /* @3930372 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3930376: ;
    /* @3930376 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3930348;
    /* @3930380 constant */
    /* @3930384 cast */
    /* @3930388 load */
    /* @3930396 constant */
    /* @3930400 sub */
    /* @3930404 load */
    /* @3930412 constant */
    /* @3930416 sub */
    /* @3930420 call */
    GM_SITE(vm, 97, 3930420);
    /* @3930428 store */
    v42 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v42);
    /* @3930436 load */
    /* @3930444 cast */
    /* @3930448 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3930480;
    L_3930452: ;
    /* @3930452 constant */
    /* @3930456 cast */
    /* @3930460 load */
    /* @3930468 call */
    GM_SITE(vm, 97, 3930468);
    /* @3930476 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3930480: ;
    /* @3930480 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3930452;
    /* @3930484 constant */
    /* @3930488 cast */
    /* @3930492 load */
    /* @3930500 constant */
    /* @3930504 sub */
    /* @3930508 load */
    /* @3930516 constant */
    /* @3930520 add */
    /* @3930524 call */
    GM_SITE(vm, 97, 3930524);
    v43 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3930532 store */
    v44 = GM_CALL(vm, "instance_create", 3, v43, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v44);
    /* @3930540 load */
    /* @3930548 cast */
    /* @3930552 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3930584;
    L_3930556: ;
    /* @3930556 constant */
    /* @3930560 cast */
    /* @3930564 load */
    /* @3930572 call */
    GM_SITE(vm, 97, 3930572);
    /* @3930580 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3930584: ;
    /* @3930584 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3930556;
    /* @3930588 constant */
    /* @3930592 cast */
    /* @3930596 load */
    /* @3930604 constant */
    /* @3930608 sub */
    /* @3930612 load */
    /* @3930620 constant */
    /* @3930624 sub */
    /* @3930628 call */
    GM_SITE(vm, 97, 3930628);
    /* @3930636 store */
    v45 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v45);
    /* @3930644 load */
    /* @3930652 cast */
    /* @3930656 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3930688;
    L_3930660: ;
    /* @3930660 constant */
    /* @3930664 cast */
    /* @3930668 load */
    /* @3930676 call */
    GM_SITE(vm, 97, 3930676);
    /* @3930684 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_3930688: ;
    /* @3930688 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3930660;
    /* @3930692 constant */
    /* @3930696 cast */
    /* @3930700 load */
    /* @3930708 constant */
    /* @3930712 sub */
    /* @3930716 load */
    /* @3930724 constant */
    /* @3930728 sub */
    /* @3930732 call */
    GM_SITE(vm, 97, 3930732);
    /* @3930740 store */
    v46 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v46);
    L_3930748: ;
    /* @3930748 load */
    /* @3930756 constant */
    /* @3930760 cmp */
    /* @3930764 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(5)))) goto L_3931904;
    /* @3930768 constant */
    /* @3930772 cast */
    /* @3930776 load */
    /* @3930784 constant */
    /* @3930788 sub */
    /* @3930792 load */
    /* @3930800 call */
    GM_SITE(vm, 97, 3930800);
    /* @3930808 store */
    v47 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v47);
    /* @3930816 load */
    /* @3930824 cast */
    /* @3930828 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3930860;
    L_3930832: ;
    /* @3930832 constant */
    /* @3930836 cast */
    /* @3930840 load */
    /* @3930848 call */
    GM_SITE(vm, 97, 3930848);
    /* @3930856 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3930860: ;
    /* @3930860 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3930832;
    /* @3930864 constant */
    /* @3930868 cast */
    /* @3930872 load */
    /* @3930880 constant */
    /* @3930884 sub */
    /* @3930888 load */
    /* @3930896 constant */
    /* @3930900 add */
    /* @3930904 call */
    GM_SITE(vm, 97, 3930904);
    v48 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3930912 store */
    v49 = GM_CALL(vm, "instance_create", 3, v48, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v49);
    /* @3930920 load */
    /* @3930928 cast */
    /* @3930932 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3930964;
    L_3930936: ;
    /* @3930936 constant */
    /* @3930940 cast */
    /* @3930944 load */
    /* @3930952 call */
    GM_SITE(vm, 97, 3930952);
    /* @3930960 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3930964: ;
    /* @3930964 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3930936;
    /* @3930968 constant */
    /* @3930972 cast */
    /* @3930976 load */
    /* @3930984 constant */
    /* @3930988 sub */
    /* @3930992 load */
    /* @3931000 constant */
    /* @3931004 sub */
    /* @3931008 call */
    GM_SITE(vm, 97, 3931008);
    /* @3931016 store */
    v50 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v50);
    /* @3931024 load */
    /* @3931032 cast */
    /* @3931036 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3931068;
    L_3931040: ;
    /* @3931040 constant */
    /* @3931044 cast */
    /* @3931048 load */
    /* @3931056 call */
    GM_SITE(vm, 97, 3931056);
    /* @3931064 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3931068: ;
    /* @3931068 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3931040;
    /* @3931072 constant */
    /* @3931076 cast */
    /* @3931080 load */
    /* @3931088 constant */
    /* @3931092 sub */
    /* @3931096 load */
    /* @3931104 constant */
    /* @3931108 add */
    /* @3931112 call */
    GM_SITE(vm, 97, 3931112);
    v51 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3931120 store */
    v52 = GM_CALL(vm, "instance_create", 3, v51, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v52);
    /* @3931128 load */
    /* @3931136 cast */
    /* @3931140 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3931172;
    L_3931144: ;
    /* @3931144 constant */
    /* @3931148 cast */
    /* @3931152 load */
    /* @3931160 call */
    GM_SITE(vm, 97, 3931160);
    /* @3931168 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3931172: ;
    /* @3931172 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3931144;
    /* @3931176 constant */
    /* @3931180 cast */
    /* @3931184 load */
    /* @3931192 constant */
    /* @3931196 sub */
    /* @3931200 load */
    /* @3931208 constant */
    /* @3931212 sub */
    /* @3931216 call */
    GM_SITE(vm, 97, 3931216);
    /* @3931224 store */
    v53 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v53);
    /* @3931232 load */
    /* @3931240 cast */
    /* @3931244 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3931276;
    L_3931248: ;
    /* @3931248 constant */
    /* @3931252 cast */
    /* @3931256 load */
    /* @3931264 call */
    GM_SITE(vm, 97, 3931264);
    /* @3931272 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3931276: ;
    /* @3931276 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3931248;
    /* @3931280 constant */
    /* @3931284 cast */
    /* @3931288 load */
    /* @3931296 constant */
    /* @3931300 sub */
    /* @3931304 load */
    /* @3931312 constant */
    /* @3931316 add */
    /* @3931320 call */
    GM_SITE(vm, 97, 3931320);
    v54 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @3931328 store */
    v55 = GM_CALL(vm, "instance_create", 3, v54, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v55);
    /* @3931336 load */
    /* @3931344 cast */
    /* @3931348 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3931380;
    L_3931352: ;
    /* @3931352 constant */
    /* @3931356 cast */
    /* @3931360 load */
    /* @3931368 call */
    GM_SITE(vm, 97, 3931368);
    /* @3931376 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3931380: ;
    /* @3931380 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3931352;
    /* @3931384 constant */
    /* @3931388 cast */
    /* @3931392 load */
    /* @3931400 constant */
    /* @3931404 sub */
    /* @3931408 load */
    /* @3931416 constant */
    /* @3931420 add */
    /* @3931424 call */
    GM_SITE(vm, 97, 3931424);
    v56 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3931432 store */
    v57 = GM_CALL(vm, "instance_create", 3, v56, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v57);
    /* @3931440 load */
    /* @3931448 cast */
    /* @3931452 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3931484;
    L_3931456: ;
    /* @3931456 constant */
    /* @3931460 cast */
    /* @3931464 load */
    /* @3931472 call */
    GM_SITE(vm, 97, 3931472);
    /* @3931480 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3931484: ;
    /* @3931484 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3931456;
    /* @3931488 constant */
    /* @3931492 cast */
    /* @3931496 load */
    /* @3931504 constant */
    /* @3931508 sub */
    /* @3931512 load */
    /* @3931520 constant */
    /* @3931524 sub */
    /* @3931528 call */
    GM_SITE(vm, 97, 3931528);
    /* @3931536 store */
    v58 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v58);
    /* @3931544 load */
    /* @3931552 cast */
    /* @3931556 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3931588;
    L_3931560: ;
    /* @3931560 constant */
    /* @3931564 cast */
    /* @3931568 load */
    /* @3931576 call */
    GM_SITE(vm, 97, 3931576);
    /* @3931584 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3931588: ;
    /* @3931588 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3931560;
    /* @3931592 constant */
    /* @3931596 cast */
    /* @3931600 load */
    /* @3931608 constant */
    /* @3931612 sub */
    /* @3931616 load */
    /* @3931624 constant */
    /* @3931628 add */
    /* @3931632 call */
    GM_SITE(vm, 97, 3931632);
    v59 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3931640 store */
    v60 = GM_CALL(vm, "instance_create", 3, v59, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v60);
    /* @3931648 load */
    /* @3931656 cast */
    /* @3931660 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3931692;
    L_3931664: ;
    /* @3931664 constant */
    /* @3931668 cast */
    /* @3931672 load */
    /* @3931680 call */
    GM_SITE(vm, 97, 3931680);
    /* @3931688 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3931692: ;
    /* @3931692 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3931664;
    /* @3931696 constant */
    /* @3931700 cast */
    /* @3931704 load */
    /* @3931712 constant */
    /* @3931716 sub */
    /* @3931720 load */
    /* @3931728 constant */
    /* @3931732 sub */
    /* @3931736 call */
    GM_SITE(vm, 97, 3931736);
    /* @3931744 store */
    v61 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v61);
    /* @3931752 load */
    /* @3931760 cast */
    /* @3931764 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3931796;
    L_3931768: ;
    /* @3931768 constant */
    /* @3931772 cast */
    /* @3931776 load */
    /* @3931784 call */
    GM_SITE(vm, 97, 3931784);
    /* @3931792 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_3931796: ;
    /* @3931796 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3931768;
    /* @3931800 constant */
    /* @3931804 cast */
    /* @3931808 load */
    /* @3931816 constant */
    /* @3931820 sub */
    /* @3931824 load */
    /* @3931832 constant */
    /* @3931836 sub */
    /* @3931840 call */
    GM_SITE(vm, 97, 3931840);
    /* @3931848 store */
    v62 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v62);
    /* @3931856 load */
    /* @3931864 cast */
    /* @3931868 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_3931900;
    L_3931872: ;
    /* @3931872 constant */
    /* @3931876 cast */
    /* @3931880 load */
    /* @3931888 call */
    GM_SITE(vm, 97, 3931888);
    /* @3931896 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_3931900: ;
    /* @3931900 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3931872;
    L_3931904: ;
    /* @3931904 call */
    GM_SITE(vm, 97, 3931904);
    /* @3931912 popz */
    (void)(GM_CALL(vm, "action_kill_object", 0));
    L_3931916: ;
    return;
}
