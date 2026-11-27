/* generated from CODE 250 (gml_Object_obj_slime_Alarm_2), source start 4042056, end 4046528. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0250(GmVM* vm) {
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
    /* @4042056 load */
    /* @4042064 constant */
    /* @4042068 cmp */
    /* @4042072 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4042080;
    /* @4042076 b */
    goto L_4042136;
    L_4042080: ;
    /* @4042080 load */
    /* @4042088 constant */
    /* @4042092 cmp */
    /* @4042096 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4042136;
    /* @4042100 constant */
    /* @4042104 cast */
    /* @4042108 constant */
    /* @4042112 cast */
    /* @4042116 constant */
    /* @4042120 cast */
    /* @4042124 call */
    GM_SITE(vm, 250, 4042124);
    /* @4042132 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(7), VAL(0), VAL(0)));
    L_4042136: ;
    /* @4042136 load */
    /* @4042144 constant */
    /* @4042148 cmp */
    /* @4042152 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpdrop") == VAL(1)))) goto L_4042200;
    /* @4042156 constant */
    /* @4042160 cast */
    /* @4042164 load */
    /* @4042172 constant */
    /* @4042176 sub */
    /* @4042180 load */
    /* @4042188 call */
    GM_SITE(vm, 250, 4042188);
    /* @4042196 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(62)));
    L_4042200: ;
    /* @4042200 load */
    /* @4042208 constant */
    /* @4042212 cmp */
    /* @4042216 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "gemdropenabled") == VAL(1)))) goto L_4042264;
    /* @4042220 constant */
    /* @4042224 cast */
    /* @4042228 load */
    /* @4042236 constant */
    /* @4042240 sub */
    /* @4042244 load */
    /* @4042252 call */
    GM_SITE(vm, 250, 4042252);
    /* @4042260 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(59)));
    L_4042264: ;
    /* @4042264 load */
    /* @4042272 constant */
    /* @4042276 cmp */
    /* @4042280 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpdrop") == VAL(1)))) goto L_4042328;
    /* @4042284 constant */
    /* @4042288 cast */
    /* @4042292 load */
    /* @4042300 constant */
    /* @4042304 sub */
    /* @4042308 load */
    /* @4042316 call */
    GM_SITE(vm, 250, 4042316);
    /* @4042324 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(20)), VAL(62)));
    L_4042328: ;
    /* @4042328 load */
    /* @4042336 constant */
    /* @4042340 cmp */
    /* @4042344 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "xpdrop") == VAL(1)))) goto L_4042444;
    /* @4042348 constant */
    /* @4042352 cast */
    /* @4042356 load */
    /* @4042364 constant */
    /* @4042368 sub */
    /* @4042372 load */
    /* @4042380 call */
    GM_SITE(vm, 250, 4042380);
    /* @4042388 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID", v1);
    /* @4042396 load */
    /* @4042404 cast */
    /* @4042408 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4042440;
    L_4042412: ;
    /* @4042412 constant */
    /* @4042416 cast */
    /* @4042420 load */
    /* @4042428 call */
    GM_SITE(vm, 250, 4042428);
    /* @4042436 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "xpspread"), VAL(5)));
    L_4042440: ;
    /* @4042440 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4042412;
    L_4042444: ;
    /* @4042444 constant */
    /* @4042448 cast */
    /* @4042452 call */
    GM_SITE(vm, 250, 4042452);
    /* @4042460 constant */
    /* @4042464 cmp */
    /* @4042468 bf */
    v2 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) >= VAL(20));
    if (!TRUTH(v2)) goto L_4042476;
    /* @4042472 b */
    goto L_4046516;
    L_4042476: ;
    /* @4042476 constant */
    /* @4042480 cast */
    /* @4042484 call */
    GM_SITE(vm, 250, 4042484);
    /* @4042492 constant */
    /* @4042496 cmp */
    /* @4042500 bf */
    v3 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) < VAL(20));
    if (!TRUTH(v3)) goto L_4046516;
    /* @4042504 load */
    /* @4042512 constant */
    /* @4042516 cmp */
    /* @4042520 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(1)))) goto L_4042828;
    /* @4042524 constant */
    /* @4042528 cast */
    /* @4042532 load */
    /* @4042540 constant */
    /* @4042544 sub */
    /* @4042548 load */
    /* @4042556 call */
    GM_SITE(vm, 250, 4042556);
    /* @4042564 store */
    v4 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v4);
    /* @4042572 load */
    /* @4042580 cast */
    /* @4042584 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4042616;
    L_4042588: ;
    /* @4042588 constant */
    /* @4042592 cast */
    /* @4042596 load */
    /* @4042604 call */
    GM_SITE(vm, 250, 4042604);
    /* @4042612 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4042616: ;
    /* @4042616 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4042588;
    /* @4042620 constant */
    /* @4042624 cast */
    /* @4042628 load */
    /* @4042636 constant */
    /* @4042640 sub */
    /* @4042644 load */
    /* @4042652 constant */
    /* @4042656 add */
    /* @4042660 call */
    GM_SITE(vm, 250, 4042660);
    v5 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4042668 store */
    v6 = GM_CALL(vm, "instance_create", 3, v5, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v6);
    /* @4042676 load */
    /* @4042684 cast */
    /* @4042688 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4042720;
    L_4042692: ;
    /* @4042692 constant */
    /* @4042696 cast */
    /* @4042700 load */
    /* @4042708 call */
    GM_SITE(vm, 250, 4042708);
    /* @4042716 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4042720: ;
    /* @4042720 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4042692;
    /* @4042724 constant */
    /* @4042728 cast */
    /* @4042732 load */
    /* @4042740 constant */
    /* @4042744 sub */
    /* @4042748 load */
    /* @4042756 constant */
    /* @4042760 sub */
    /* @4042764 call */
    GM_SITE(vm, 250, 4042764);
    /* @4042772 store */
    v7 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v7);
    /* @4042780 load */
    /* @4042788 cast */
    /* @4042792 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4042824;
    L_4042796: ;
    /* @4042796 constant */
    /* @4042800 cast */
    /* @4042804 load */
    /* @4042812 call */
    GM_SITE(vm, 250, 4042812);
    /* @4042820 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4042824: ;
    /* @4042824 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4042796;
    L_4042828: ;
    /* @4042828 load */
    /* @4042836 constant */
    /* @4042840 cmp */
    /* @4042844 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(2)))) goto L_4043360;
    /* @4042848 constant */
    /* @4042852 cast */
    /* @4042856 load */
    /* @4042864 constant */
    /* @4042868 sub */
    /* @4042872 load */
    /* @4042880 call */
    GM_SITE(vm, 250, 4042880);
    /* @4042888 store */
    v8 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v8);
    /* @4042896 load */
    /* @4042904 cast */
    /* @4042908 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4042940;
    L_4042912: ;
    /* @4042912 constant */
    /* @4042916 cast */
    /* @4042920 load */
    /* @4042928 call */
    GM_SITE(vm, 250, 4042928);
    /* @4042936 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4042940: ;
    /* @4042940 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4042912;
    /* @4042944 constant */
    /* @4042948 cast */
    /* @4042952 load */
    /* @4042960 constant */
    /* @4042964 sub */
    /* @4042968 load */
    /* @4042976 constant */
    /* @4042980 add */
    /* @4042984 call */
    GM_SITE(vm, 250, 4042984);
    v9 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4042992 store */
    v10 = GM_CALL(vm, "instance_create", 3, v9, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v10);
    /* @4043000 load */
    /* @4043008 cast */
    /* @4043012 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4043044;
    L_4043016: ;
    /* @4043016 constant */
    /* @4043020 cast */
    /* @4043024 load */
    /* @4043032 call */
    GM_SITE(vm, 250, 4043032);
    /* @4043040 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4043044: ;
    /* @4043044 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4043016;
    /* @4043048 constant */
    /* @4043052 cast */
    /* @4043056 load */
    /* @4043064 constant */
    /* @4043068 sub */
    /* @4043072 load */
    /* @4043080 constant */
    /* @4043084 sub */
    /* @4043088 call */
    GM_SITE(vm, 250, 4043088);
    /* @4043096 store */
    v11 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v11);
    /* @4043104 load */
    /* @4043112 cast */
    /* @4043116 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4043148;
    L_4043120: ;
    /* @4043120 constant */
    /* @4043124 cast */
    /* @4043128 load */
    /* @4043136 call */
    GM_SITE(vm, 250, 4043136);
    /* @4043144 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4043148: ;
    /* @4043148 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4043120;
    /* @4043152 constant */
    /* @4043156 cast */
    /* @4043160 load */
    /* @4043168 constant */
    /* @4043172 sub */
    /* @4043176 load */
    /* @4043184 constant */
    /* @4043188 add */
    /* @4043192 call */
    GM_SITE(vm, 250, 4043192);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4043200 store */
    v13 = GM_CALL(vm, "instance_create", 3, v12, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v13);
    /* @4043208 load */
    /* @4043216 cast */
    /* @4043220 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4043252;
    L_4043224: ;
    /* @4043224 constant */
    /* @4043228 cast */
    /* @4043232 load */
    /* @4043240 call */
    GM_SITE(vm, 250, 4043240);
    /* @4043248 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4043252: ;
    /* @4043252 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4043224;
    /* @4043256 constant */
    /* @4043260 cast */
    /* @4043264 load */
    /* @4043272 constant */
    /* @4043276 sub */
    /* @4043280 load */
    /* @4043288 constant */
    /* @4043292 sub */
    /* @4043296 call */
    GM_SITE(vm, 250, 4043296);
    /* @4043304 store */
    v14 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v14);
    /* @4043312 load */
    /* @4043320 cast */
    /* @4043324 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4043356;
    L_4043328: ;
    /* @4043328 constant */
    /* @4043332 cast */
    /* @4043336 load */
    /* @4043344 call */
    GM_SITE(vm, 250, 4043344);
    /* @4043352 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4043356: ;
    /* @4043356 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4043328;
    L_4043360: ;
    /* @4043360 load */
    /* @4043368 constant */
    /* @4043372 cmp */
    /* @4043376 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(3)))) goto L_4044308;
    /* @4043380 constant */
    /* @4043384 cast */
    /* @4043388 load */
    /* @4043396 constant */
    /* @4043400 sub */
    /* @4043404 load */
    /* @4043412 call */
    GM_SITE(vm, 250, 4043412);
    /* @4043420 store */
    v15 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v15);
    /* @4043428 load */
    /* @4043436 cast */
    /* @4043440 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4043472;
    L_4043444: ;
    /* @4043444 constant */
    /* @4043448 cast */
    /* @4043452 load */
    /* @4043460 call */
    GM_SITE(vm, 250, 4043460);
    /* @4043468 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4043472: ;
    /* @4043472 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4043444;
    /* @4043476 constant */
    /* @4043480 cast */
    /* @4043484 load */
    /* @4043492 constant */
    /* @4043496 sub */
    /* @4043500 load */
    /* @4043508 constant */
    /* @4043512 add */
    /* @4043516 call */
    GM_SITE(vm, 250, 4043516);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4043524 store */
    v17 = GM_CALL(vm, "instance_create", 3, v16, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v17);
    /* @4043532 load */
    /* @4043540 cast */
    /* @4043544 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4043576;
    L_4043548: ;
    /* @4043548 constant */
    /* @4043552 cast */
    /* @4043556 load */
    /* @4043564 call */
    GM_SITE(vm, 250, 4043564);
    /* @4043572 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4043576: ;
    /* @4043576 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4043548;
    /* @4043580 constant */
    /* @4043584 cast */
    /* @4043588 load */
    /* @4043596 constant */
    /* @4043600 sub */
    /* @4043604 load */
    /* @4043612 constant */
    /* @4043616 sub */
    /* @4043620 call */
    GM_SITE(vm, 250, 4043620);
    /* @4043628 store */
    v18 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v18);
    /* @4043636 load */
    /* @4043644 cast */
    /* @4043648 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4043680;
    L_4043652: ;
    /* @4043652 constant */
    /* @4043656 cast */
    /* @4043660 load */
    /* @4043668 call */
    GM_SITE(vm, 250, 4043668);
    /* @4043676 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4043680: ;
    /* @4043680 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4043652;
    /* @4043684 constant */
    /* @4043688 cast */
    /* @4043692 load */
    /* @4043700 constant */
    /* @4043704 sub */
    /* @4043708 load */
    /* @4043716 constant */
    /* @4043720 add */
    /* @4043724 call */
    GM_SITE(vm, 250, 4043724);
    v19 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4043732 store */
    v20 = GM_CALL(vm, "instance_create", 3, v19, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v20);
    /* @4043740 load */
    /* @4043748 cast */
    /* @4043752 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4043784;
    L_4043756: ;
    /* @4043756 constant */
    /* @4043760 cast */
    /* @4043764 load */
    /* @4043772 call */
    GM_SITE(vm, 250, 4043772);
    /* @4043780 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4043784: ;
    /* @4043784 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4043756;
    /* @4043788 constant */
    /* @4043792 cast */
    /* @4043796 load */
    /* @4043804 constant */
    /* @4043808 sub */
    /* @4043812 load */
    /* @4043820 constant */
    /* @4043824 sub */
    /* @4043828 call */
    GM_SITE(vm, 250, 4043828);
    /* @4043836 store */
    v21 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v21);
    /* @4043844 load */
    /* @4043852 cast */
    /* @4043856 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4043888;
    L_4043860: ;
    /* @4043860 constant */
    /* @4043864 cast */
    /* @4043868 load */
    /* @4043876 call */
    GM_SITE(vm, 250, 4043876);
    /* @4043884 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4043888: ;
    /* @4043888 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4043860;
    /* @4043892 constant */
    /* @4043896 cast */
    /* @4043900 load */
    /* @4043908 constant */
    /* @4043912 sub */
    /* @4043916 load */
    /* @4043924 constant */
    /* @4043928 sub */
    /* @4043932 call */
    GM_SITE(vm, 250, 4043932);
    /* @4043940 store */
    v22 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v22);
    /* @4043948 load */
    /* @4043956 cast */
    /* @4043960 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_4043992;
    L_4043964: ;
    /* @4043964 constant */
    /* @4043968 cast */
    /* @4043972 load */
    /* @4043980 call */
    GM_SITE(vm, 250, 4043980);
    /* @4043988 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_4043992: ;
    /* @4043992 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4043964;
    /* @4043996 constant */
    /* @4044000 cast */
    /* @4044004 load */
    /* @4044012 constant */
    /* @4044016 sub */
    /* @4044020 load */
    /* @4044028 constant */
    /* @4044032 add */
    /* @4044036 call */
    GM_SITE(vm, 250, 4044036);
    v23 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @4044044 store */
    v24 = GM_CALL(vm, "instance_create", 3, v23, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v24);
    /* @4044052 load */
    /* @4044060 cast */
    /* @4044064 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_4044096;
    L_4044068: ;
    /* @4044068 constant */
    /* @4044072 cast */
    /* @4044076 load */
    /* @4044084 call */
    GM_SITE(vm, 250, 4044084);
    /* @4044092 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_4044096: ;
    /* @4044096 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4044068;
    /* @4044100 constant */
    /* @4044104 cast */
    /* @4044108 load */
    /* @4044116 constant */
    /* @4044120 sub */
    /* @4044124 load */
    /* @4044132 constant */
    /* @4044136 sub */
    /* @4044140 call */
    GM_SITE(vm, 250, 4044140);
    /* @4044148 store */
    v25 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v25);
    /* @4044156 load */
    /* @4044164 cast */
    /* @4044168 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_4044200;
    L_4044172: ;
    /* @4044172 constant */
    /* @4044176 cast */
    /* @4044180 load */
    /* @4044188 call */
    GM_SITE(vm, 250, 4044188);
    /* @4044196 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_4044200: ;
    /* @4044200 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4044172;
    /* @4044204 constant */
    /* @4044208 cast */
    /* @4044212 load */
    /* @4044220 constant */
    /* @4044224 sub */
    /* @4044228 load */
    /* @4044236 constant */
    /* @4044240 add */
    /* @4044244 call */
    GM_SITE(vm, 250, 4044244);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @4044252 store */
    v27 = GM_CALL(vm, "instance_create", 3, v26, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v27);
    /* @4044260 load */
    /* @4044268 cast */
    /* @4044272 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_4044304;
    L_4044276: ;
    /* @4044276 constant */
    /* @4044280 cast */
    /* @4044284 load */
    /* @4044292 call */
    GM_SITE(vm, 250, 4044292);
    /* @4044300 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_4044304: ;
    /* @4044304 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4044276;
    L_4044308: ;
    /* @4044308 load */
    /* @4044316 constant */
    /* @4044320 cmp */
    /* @4044324 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(4)))) goto L_4045360;
    /* @4044328 constant */
    /* @4044332 cast */
    /* @4044336 load */
    /* @4044344 constant */
    /* @4044348 sub */
    /* @4044352 load */
    /* @4044360 call */
    GM_SITE(vm, 250, 4044360);
    /* @4044368 store */
    v28 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v28);
    /* @4044376 load */
    /* @4044384 cast */
    /* @4044388 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4044420;
    L_4044392: ;
    /* @4044392 constant */
    /* @4044396 cast */
    /* @4044400 load */
    /* @4044408 call */
    GM_SITE(vm, 250, 4044408);
    /* @4044416 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4044420: ;
    /* @4044420 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4044392;
    /* @4044424 constant */
    /* @4044428 cast */
    /* @4044432 load */
    /* @4044440 constant */
    /* @4044444 sub */
    /* @4044448 load */
    /* @4044456 constant */
    /* @4044460 add */
    /* @4044464 call */
    GM_SITE(vm, 250, 4044464);
    v29 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4044472 store */
    v30 = GM_CALL(vm, "instance_create", 3, v29, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v30);
    /* @4044480 load */
    /* @4044488 cast */
    /* @4044492 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4044524;
    L_4044496: ;
    /* @4044496 constant */
    /* @4044500 cast */
    /* @4044504 load */
    /* @4044512 call */
    GM_SITE(vm, 250, 4044512);
    /* @4044520 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4044524: ;
    /* @4044524 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4044496;
    /* @4044528 constant */
    /* @4044532 cast */
    /* @4044536 load */
    /* @4044544 constant */
    /* @4044548 sub */
    /* @4044552 load */
    /* @4044560 constant */
    /* @4044564 sub */
    /* @4044568 call */
    GM_SITE(vm, 250, 4044568);
    /* @4044576 store */
    v31 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v31);
    /* @4044584 load */
    /* @4044592 cast */
    /* @4044596 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4044628;
    L_4044600: ;
    /* @4044600 constant */
    /* @4044604 cast */
    /* @4044608 load */
    /* @4044616 call */
    GM_SITE(vm, 250, 4044616);
    /* @4044624 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4044628: ;
    /* @4044628 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4044600;
    /* @4044632 constant */
    /* @4044636 cast */
    /* @4044640 load */
    /* @4044648 constant */
    /* @4044652 sub */
    /* @4044656 load */
    /* @4044664 constant */
    /* @4044668 add */
    /* @4044672 call */
    GM_SITE(vm, 250, 4044672);
    v32 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4044680 store */
    v33 = GM_CALL(vm, "instance_create", 3, v32, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v33);
    /* @4044688 load */
    /* @4044696 cast */
    /* @4044700 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4044732;
    L_4044704: ;
    /* @4044704 constant */
    /* @4044708 cast */
    /* @4044712 load */
    /* @4044720 call */
    GM_SITE(vm, 250, 4044720);
    /* @4044728 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4044732: ;
    /* @4044732 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4044704;
    /* @4044736 constant */
    /* @4044740 cast */
    /* @4044744 load */
    /* @4044752 constant */
    /* @4044756 sub */
    /* @4044760 load */
    /* @4044768 constant */
    /* @4044772 sub */
    /* @4044776 call */
    GM_SITE(vm, 250, 4044776);
    /* @4044784 store */
    v34 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v34);
    /* @4044792 load */
    /* @4044800 cast */
    /* @4044804 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4044836;
    L_4044808: ;
    /* @4044808 constant */
    /* @4044812 cast */
    /* @4044816 load */
    /* @4044824 call */
    GM_SITE(vm, 250, 4044824);
    /* @4044832 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4044836: ;
    /* @4044836 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4044808;
    /* @4044840 constant */
    /* @4044844 cast */
    /* @4044848 load */
    /* @4044856 constant */
    /* @4044860 sub */
    /* @4044864 load */
    /* @4044872 constant */
    /* @4044876 add */
    /* @4044880 call */
    GM_SITE(vm, 250, 4044880);
    v35 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @4044888 store */
    v36 = GM_CALL(vm, "instance_create", 3, v35, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v36);
    /* @4044896 load */
    /* @4044904 cast */
    /* @4044908 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_4044940;
    L_4044912: ;
    /* @4044912 constant */
    /* @4044916 cast */
    /* @4044920 load */
    /* @4044928 call */
    GM_SITE(vm, 250, 4044928);
    /* @4044936 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_4044940: ;
    /* @4044940 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4044912;
    /* @4044944 constant */
    /* @4044948 cast */
    /* @4044952 load */
    /* @4044960 constant */
    /* @4044964 sub */
    /* @4044968 load */
    /* @4044976 constant */
    /* @4044980 add */
    /* @4044984 call */
    GM_SITE(vm, 250, 4044984);
    v37 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @4044992 store */
    v38 = GM_CALL(vm, "instance_create", 3, v37, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v38);
    /* @4045000 load */
    /* @4045008 cast */
    /* @4045012 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_4045044;
    L_4045016: ;
    /* @4045016 constant */
    /* @4045020 cast */
    /* @4045024 load */
    /* @4045032 call */
    GM_SITE(vm, 250, 4045032);
    /* @4045040 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_4045044: ;
    /* @4045044 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4045016;
    /* @4045048 constant */
    /* @4045052 cast */
    /* @4045056 load */
    /* @4045064 constant */
    /* @4045068 sub */
    /* @4045072 load */
    /* @4045080 constant */
    /* @4045084 sub */
    /* @4045088 call */
    GM_SITE(vm, 250, 4045088);
    /* @4045096 store */
    v39 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v39);
    /* @4045104 load */
    /* @4045112 cast */
    /* @4045116 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_4045148;
    L_4045120: ;
    /* @4045120 constant */
    /* @4045124 cast */
    /* @4045128 load */
    /* @4045136 call */
    GM_SITE(vm, 250, 4045136);
    /* @4045144 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_4045148: ;
    /* @4045148 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4045120;
    /* @4045152 constant */
    /* @4045156 cast */
    /* @4045160 load */
    /* @4045168 constant */
    /* @4045172 sub */
    /* @4045176 load */
    /* @4045184 constant */
    /* @4045188 add */
    /* @4045192 call */
    GM_SITE(vm, 250, 4045192);
    v40 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @4045200 store */
    v41 = GM_CALL(vm, "instance_create", 3, v40, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v41);
    /* @4045208 load */
    /* @4045216 cast */
    /* @4045220 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_4045252;
    L_4045224: ;
    /* @4045224 constant */
    /* @4045228 cast */
    /* @4045232 load */
    /* @4045240 call */
    GM_SITE(vm, 250, 4045240);
    /* @4045248 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_4045252: ;
    /* @4045252 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4045224;
    /* @4045256 constant */
    /* @4045260 cast */
    /* @4045264 load */
    /* @4045272 constant */
    /* @4045276 sub */
    /* @4045280 load */
    /* @4045288 constant */
    /* @4045292 sub */
    /* @4045296 call */
    GM_SITE(vm, 250, 4045296);
    /* @4045304 store */
    v42 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v42);
    /* @4045312 load */
    /* @4045320 cast */
    /* @4045324 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_4045356;
    L_4045328: ;
    /* @4045328 constant */
    /* @4045332 cast */
    /* @4045336 load */
    /* @4045344 call */
    GM_SITE(vm, 250, 4045344);
    /* @4045352 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_4045356: ;
    /* @4045356 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4045328;
    L_4045360: ;
    /* @4045360 load */
    /* @4045368 constant */
    /* @4045372 cmp */
    /* @4045376 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(5)))) goto L_4046516;
    /* @4045380 constant */
    /* @4045384 cast */
    /* @4045388 load */
    /* @4045396 constant */
    /* @4045400 sub */
    /* @4045404 load */
    /* @4045412 call */
    GM_SITE(vm, 250, 4045412);
    /* @4045420 store */
    v43 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v43);
    /* @4045428 load */
    /* @4045436 cast */
    /* @4045440 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4045472;
    L_4045444: ;
    /* @4045444 constant */
    /* @4045448 cast */
    /* @4045452 load */
    /* @4045460 call */
    GM_SITE(vm, 250, 4045460);
    /* @4045468 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4045472: ;
    /* @4045472 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4045444;
    /* @4045476 constant */
    /* @4045480 cast */
    /* @4045484 load */
    /* @4045492 constant */
    /* @4045496 sub */
    /* @4045500 load */
    /* @4045508 constant */
    /* @4045512 add */
    /* @4045516 call */
    GM_SITE(vm, 250, 4045516);
    v44 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4045524 store */
    v45 = GM_CALL(vm, "instance_create", 3, v44, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v45);
    /* @4045532 load */
    /* @4045540 cast */
    /* @4045544 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4045576;
    L_4045548: ;
    /* @4045548 constant */
    /* @4045552 cast */
    /* @4045556 load */
    /* @4045564 call */
    GM_SITE(vm, 250, 4045564);
    /* @4045572 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4045576: ;
    /* @4045576 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4045548;
    /* @4045580 constant */
    /* @4045584 cast */
    /* @4045588 load */
    /* @4045596 constant */
    /* @4045600 sub */
    /* @4045604 load */
    /* @4045612 constant */
    /* @4045616 sub */
    /* @4045620 call */
    GM_SITE(vm, 250, 4045620);
    /* @4045628 store */
    v46 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v46);
    /* @4045636 load */
    /* @4045644 cast */
    /* @4045648 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4045680;
    L_4045652: ;
    /* @4045652 constant */
    /* @4045656 cast */
    /* @4045660 load */
    /* @4045668 call */
    GM_SITE(vm, 250, 4045668);
    /* @4045676 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4045680: ;
    /* @4045680 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4045652;
    /* @4045684 constant */
    /* @4045688 cast */
    /* @4045692 load */
    /* @4045700 constant */
    /* @4045704 sub */
    /* @4045708 load */
    /* @4045716 constant */
    /* @4045720 add */
    /* @4045724 call */
    GM_SITE(vm, 250, 4045724);
    v47 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4045732 store */
    v48 = GM_CALL(vm, "instance_create", 3, v47, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v48);
    /* @4045740 load */
    /* @4045748 cast */
    /* @4045752 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4045784;
    L_4045756: ;
    /* @4045756 constant */
    /* @4045760 cast */
    /* @4045764 load */
    /* @4045772 call */
    GM_SITE(vm, 250, 4045772);
    /* @4045780 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4045784: ;
    /* @4045784 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4045756;
    /* @4045788 constant */
    /* @4045792 cast */
    /* @4045796 load */
    /* @4045804 constant */
    /* @4045808 sub */
    /* @4045812 load */
    /* @4045820 constant */
    /* @4045824 sub */
    /* @4045828 call */
    GM_SITE(vm, 250, 4045828);
    /* @4045836 store */
    v49 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v49);
    /* @4045844 load */
    /* @4045852 cast */
    /* @4045856 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4045888;
    L_4045860: ;
    /* @4045860 constant */
    /* @4045864 cast */
    /* @4045868 load */
    /* @4045876 call */
    GM_SITE(vm, 250, 4045876);
    /* @4045884 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4045888: ;
    /* @4045888 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4045860;
    /* @4045892 constant */
    /* @4045896 cast */
    /* @4045900 load */
    /* @4045908 constant */
    /* @4045912 sub */
    /* @4045916 load */
    /* @4045924 constant */
    /* @4045928 add */
    /* @4045932 call */
    GM_SITE(vm, 250, 4045932);
    v50 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @4045940 store */
    v51 = GM_CALL(vm, "instance_create", 3, v50, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v51);
    /* @4045948 load */
    /* @4045956 cast */
    /* @4045960 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_4045992;
    L_4045964: ;
    /* @4045964 constant */
    /* @4045968 cast */
    /* @4045972 load */
    /* @4045980 call */
    GM_SITE(vm, 250, 4045980);
    /* @4045988 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_4045992: ;
    /* @4045992 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4045964;
    /* @4045996 constant */
    /* @4046000 cast */
    /* @4046004 load */
    /* @4046012 constant */
    /* @4046016 sub */
    /* @4046020 load */
    /* @4046028 constant */
    /* @4046032 add */
    /* @4046036 call */
    GM_SITE(vm, 250, 4046036);
    v52 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @4046044 store */
    v53 = GM_CALL(vm, "instance_create", 3, v52, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v53);
    /* @4046052 load */
    /* @4046060 cast */
    /* @4046064 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_4046096;
    L_4046068: ;
    /* @4046068 constant */
    /* @4046072 cast */
    /* @4046076 load */
    /* @4046084 call */
    GM_SITE(vm, 250, 4046084);
    /* @4046092 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_4046096: ;
    /* @4046096 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4046068;
    /* @4046100 constant */
    /* @4046104 cast */
    /* @4046108 load */
    /* @4046116 constant */
    /* @4046120 sub */
    /* @4046124 load */
    /* @4046132 constant */
    /* @4046136 sub */
    /* @4046140 call */
    GM_SITE(vm, 250, 4046140);
    /* @4046148 store */
    v54 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v54);
    /* @4046156 load */
    /* @4046164 cast */
    /* @4046168 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_4046200;
    L_4046172: ;
    /* @4046172 constant */
    /* @4046176 cast */
    /* @4046180 load */
    /* @4046188 call */
    GM_SITE(vm, 250, 4046188);
    /* @4046196 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_4046200: ;
    /* @4046200 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4046172;
    /* @4046204 constant */
    /* @4046208 cast */
    /* @4046212 load */
    /* @4046220 constant */
    /* @4046224 sub */
    /* @4046228 load */
    /* @4046236 constant */
    /* @4046240 add */
    /* @4046244 call */
    GM_SITE(vm, 250, 4046244);
    v55 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @4046252 store */
    v56 = GM_CALL(vm, "instance_create", 3, v55, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v56);
    /* @4046260 load */
    /* @4046268 cast */
    /* @4046272 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_4046304;
    L_4046276: ;
    /* @4046276 constant */
    /* @4046280 cast */
    /* @4046284 load */
    /* @4046292 call */
    GM_SITE(vm, 250, 4046292);
    /* @4046300 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_4046304: ;
    /* @4046304 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4046276;
    /* @4046308 constant */
    /* @4046312 cast */
    /* @4046316 load */
    /* @4046324 constant */
    /* @4046328 sub */
    /* @4046332 load */
    /* @4046340 constant */
    /* @4046344 sub */
    /* @4046348 call */
    GM_SITE(vm, 250, 4046348);
    /* @4046356 store */
    v57 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v57);
    /* @4046364 load */
    /* @4046372 cast */
    /* @4046376 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_4046408;
    L_4046380: ;
    /* @4046380 constant */
    /* @4046384 cast */
    /* @4046388 load */
    /* @4046396 call */
    GM_SITE(vm, 250, 4046396);
    /* @4046404 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_4046408: ;
    /* @4046408 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4046380;
    /* @4046412 constant */
    /* @4046416 cast */
    /* @4046420 load */
    /* @4046428 constant */
    /* @4046432 sub */
    /* @4046436 load */
    /* @4046444 constant */
    /* @4046448 sub */
    /* @4046452 call */
    GM_SITE(vm, 250, 4046452);
    /* @4046460 store */
    v58 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v58);
    /* @4046468 load */
    /* @4046476 cast */
    /* @4046480 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_4046512;
    L_4046484: ;
    /* @4046484 constant */
    /* @4046488 cast */
    /* @4046492 load */
    /* @4046500 call */
    GM_SITE(vm, 250, 4046500);
    /* @4046508 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_4046512: ;
    /* @4046512 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4046484;
    L_4046516: ;
    /* @4046516 call */
    GM_SITE(vm, 250, 4046516);
    /* @4046524 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4046528: ;
    return;
}
