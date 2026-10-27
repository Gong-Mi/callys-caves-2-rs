/* generated from CODE 109 (gml_Object_obj_shooter2_Alarm_0), source start 3934932, end 3940820. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0109(GmVM* vm) {
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
    Val v63;
    Val v64;
    Val v65;
    Val v66;
    Val v67;
    Val v68;
    Val v69;
    Val v70;
    Val v71;
    Val v72;
    Val v73;
    Val v74;
    Val v75;
    Val v76;
    Val v77;
    /* @3934932 load */
    /* @3934940 constant */
    /* @3934944 cmp */
    /* @3934948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3934956;
    /* @3934952 b */
    goto L_3935012;
    L_3934956: ;
    /* @3934956 load */
    /* @3934964 constant */
    /* @3934968 cmp */
    /* @3934972 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3935012;
    /* @3934976 constant */
    /* @3934980 cast */
    /* @3934984 constant */
    /* @3934988 cast */
    /* @3934992 constant */
    /* @3934996 cast */
    /* @3935000 call */
    GM_SITE(vm, 109, 3935000);
    /* @3935008 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(7), VAL(0), VAL(0)));
    L_3935012: ;
    /* @3935012 load */
    /* @3935020 constant */
    /* @3935024 cmp */
    /* @3935028 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "gemdropenabled") == VAL(1)))) goto L_3935076;
    /* @3935032 constant */
    /* @3935036 cast */
    /* @3935040 load */
    /* @3935048 constant */
    /* @3935052 sub */
    /* @3935056 load */
    /* @3935064 call */
    GM_SITE(vm, 109, 3935064);
    /* @3935072 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(59)));
    L_3935076: ;
    /* @3935076 load */
    /* @3935084 constant */
    /* @3935088 cmp */
    /* @3935092 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpdrop") == VAL(1)))) goto L_3935140;
    /* @3935096 constant */
    /* @3935100 cast */
    /* @3935104 load */
    /* @3935112 constant */
    /* @3935116 sub */
    /* @3935120 load */
    /* @3935128 call */
    GM_SITE(vm, 109, 3935128);
    /* @3935136 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(62)));
    L_3935140: ;
    /* @3935140 load */
    /* @3935148 constant */
    /* @3935152 cmp */
    /* @3935156 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "xpdrop") == VAL(1)))) goto L_3935256;
    /* @3935160 constant */
    /* @3935164 cast */
    /* @3935168 load */
    /* @3935176 constant */
    /* @3935180 sub */
    /* @3935184 load */
    /* @3935192 call */
    GM_SITE(vm, 109, 3935192);
    /* @3935200 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID", v1);
    /* @3935208 load */
    /* @3935216 cast */
    /* @3935220 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3935252;
    L_3935224: ;
    /* @3935224 constant */
    /* @3935228 cast */
    /* @3935232 load */
    /* @3935240 call */
    GM_SITE(vm, 109, 3935240);
    /* @3935248 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "xpspread"), VAL(5)));
    L_3935252: ;
    /* @3935252 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3935224;
    L_3935256: ;
    /* @3935256 load */
    /* @3935264 constant */
    /* @3935268 cmp */
    /* @3935272 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "xpdrop") == VAL(2)))) goto L_3935476;
    /* @3935276 constant */
    /* @3935280 cast */
    /* @3935284 load */
    /* @3935292 constant */
    /* @3935296 sub */
    /* @3935300 load */
    /* @3935308 call */
    GM_SITE(vm, 109, 3935308);
    /* @3935316 store */
    v2 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID", v2);
    /* @3935324 load */
    /* @3935332 cast */
    /* @3935336 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3935368;
    L_3935340: ;
    /* @3935340 constant */
    /* @3935344 cast */
    /* @3935348 load */
    /* @3935356 call */
    GM_SITE(vm, 109, 3935356);
    /* @3935364 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "xpspread"), VAL(5)));
    L_3935368: ;
    /* @3935368 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3935340;
    /* @3935372 constant */
    /* @3935376 cast */
    /* @3935380 load */
    /* @3935388 constant */
    /* @3935392 sub */
    /* @3935396 load */
    /* @3935404 constant */
    /* @3935408 add */
    /* @3935412 call */
    GM_SITE(vm, 109, 3935412);
    v3 = GM_ADD(GM_READ(vm, -1, "x"), VAL(7));
    /* @3935420 store */
    v4 = GM_CALL(vm, "instance_create", 3, v3, (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID2", v4);
    /* @3935428 load */
    /* @3935436 cast */
    /* @3935440 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3935472;
    L_3935444: ;
    /* @3935444 constant */
    /* @3935448 cast */
    /* @3935452 load */
    /* @3935460 call */
    GM_SITE(vm, 109, 3935460);
    /* @3935468 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "xpspread2"), VAL(5)));
    L_3935472: ;
    /* @3935472 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3935444;
    L_3935476: ;
    /* @3935476 load */
    /* @3935484 constant */
    /* @3935488 cmp */
    /* @3935492 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "xpdrop") == VAL(3)))) goto L_3935800;
    /* @3935496 constant */
    /* @3935500 cast */
    /* @3935504 load */
    /* @3935512 constant */
    /* @3935516 sub */
    /* @3935520 load */
    /* @3935528 call */
    GM_SITE(vm, 109, 3935528);
    /* @3935536 store */
    v5 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID", v5);
    /* @3935544 load */
    /* @3935552 cast */
    /* @3935556 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3935588;
    L_3935560: ;
    /* @3935560 constant */
    /* @3935564 cast */
    /* @3935568 load */
    /* @3935576 call */
    GM_SITE(vm, 109, 3935576);
    /* @3935584 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "xpspread"), VAL(5)));
    L_3935588: ;
    /* @3935588 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3935560;
    /* @3935592 constant */
    /* @3935596 cast */
    /* @3935600 load */
    /* @3935608 constant */
    /* @3935612 sub */
    /* @3935616 load */
    /* @3935624 constant */
    /* @3935628 add */
    /* @3935632 call */
    GM_SITE(vm, 109, 3935632);
    v6 = GM_ADD(GM_READ(vm, -1, "x"), VAL(7));
    /* @3935640 store */
    v7 = GM_CALL(vm, "instance_create", 3, v6, (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID2", v7);
    /* @3935648 load */
    /* @3935656 cast */
    /* @3935660 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3935692;
    L_3935664: ;
    /* @3935664 constant */
    /* @3935668 cast */
    /* @3935672 load */
    /* @3935680 call */
    GM_SITE(vm, 109, 3935680);
    /* @3935688 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "xpspread2"), VAL(5)));
    L_3935692: ;
    /* @3935692 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3935664;
    /* @3935696 constant */
    /* @3935700 cast */
    /* @3935704 load */
    /* @3935712 constant */
    /* @3935716 sub */
    /* @3935720 load */
    /* @3935728 constant */
    /* @3935732 sub */
    /* @3935736 call */
    GM_SITE(vm, 109, 3935736);
    /* @3935744 store */
    v8 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(7)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID3", v8);
    /* @3935752 load */
    /* @3935760 cast */
    /* @3935764 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3935796;
    L_3935768: ;
    /* @3935768 constant */
    /* @3935772 cast */
    /* @3935776 load */
    /* @3935784 call */
    GM_SITE(vm, 109, 3935784);
    /* @3935792 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "xpspread3"), VAL(5)));
    L_3935796: ;
    /* @3935796 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3935768;
    L_3935800: ;
    /* @3935800 constant */
    /* @3935804 cast */
    /* @3935808 call */
    GM_SITE(vm, 109, 3935808);
    /* @3935816 constant */
    /* @3935820 cmp */
    /* @3935824 bf */
    v9 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) >= VAL(20));
    if (!TRUTH(v9)) goto L_3935832;
    /* @3935828 b */
    goto L_3940808;
    L_3935832: ;
    /* @3935832 constant */
    /* @3935836 cast */
    /* @3935840 call */
    GM_SITE(vm, 109, 3935840);
    /* @3935848 constant */
    /* @3935852 cmp */
    /* @3935856 bf */
    v10 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) < VAL(20));
    if (!TRUTH(v10)) goto L_3940808;
    /* @3935860 load */
    /* @3935868 constant */
    /* @3935872 cmp */
    /* @3935876 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(1)))) goto L_3936392;
    /* @3935880 constant */
    /* @3935884 cast */
    /* @3935888 load */
    /* @3935896 constant */
    /* @3935900 sub */
    /* @3935904 load */
    /* @3935912 call */
    GM_SITE(vm, 109, 3935912);
    /* @3935920 store */
    v11 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v11);
    /* @3935928 load */
    /* @3935936 cast */
    /* @3935940 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3935972;
    L_3935944: ;
    /* @3935944 constant */
    /* @3935948 cast */
    /* @3935952 load */
    /* @3935960 call */
    GM_SITE(vm, 109, 3935960);
    /* @3935968 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3935972: ;
    /* @3935972 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3935944;
    /* @3935976 constant */
    /* @3935980 cast */
    /* @3935984 load */
    /* @3935992 constant */
    /* @3935996 sub */
    /* @3936000 load */
    /* @3936008 constant */
    /* @3936012 add */
    /* @3936016 call */
    GM_SITE(vm, 109, 3936016);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3936024 store */
    v13 = GM_CALL(vm, "instance_create", 3, v12, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v13);
    /* @3936032 load */
    /* @3936040 cast */
    /* @3936044 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3936076;
    L_3936048: ;
    /* @3936048 constant */
    /* @3936052 cast */
    /* @3936056 load */
    /* @3936064 call */
    GM_SITE(vm, 109, 3936064);
    /* @3936072 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3936076: ;
    /* @3936076 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3936048;
    /* @3936080 constant */
    /* @3936084 cast */
    /* @3936088 load */
    /* @3936096 constant */
    /* @3936100 sub */
    /* @3936104 load */
    /* @3936112 constant */
    /* @3936116 sub */
    /* @3936120 call */
    GM_SITE(vm, 109, 3936120);
    /* @3936128 store */
    v14 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v14);
    /* @3936136 load */
    /* @3936144 cast */
    /* @3936148 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3936180;
    L_3936152: ;
    /* @3936152 constant */
    /* @3936156 cast */
    /* @3936160 load */
    /* @3936168 call */
    GM_SITE(vm, 109, 3936168);
    /* @3936176 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3936180: ;
    /* @3936180 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3936152;
    /* @3936184 constant */
    /* @3936188 cast */
    /* @3936192 load */
    /* @3936200 constant */
    /* @3936204 sub */
    /* @3936208 load */
    /* @3936216 constant */
    /* @3936220 add */
    /* @3936224 call */
    GM_SITE(vm, 109, 3936224);
    v15 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3936232 store */
    v16 = GM_CALL(vm, "instance_create", 3, v15, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v16);
    /* @3936240 load */
    /* @3936248 cast */
    /* @3936252 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3936284;
    L_3936256: ;
    /* @3936256 constant */
    /* @3936260 cast */
    /* @3936264 load */
    /* @3936272 call */
    GM_SITE(vm, 109, 3936272);
    /* @3936280 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3936284: ;
    /* @3936284 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3936256;
    /* @3936288 constant */
    /* @3936292 cast */
    /* @3936296 load */
    /* @3936304 constant */
    /* @3936308 sub */
    /* @3936312 load */
    /* @3936320 constant */
    /* @3936324 sub */
    /* @3936328 call */
    GM_SITE(vm, 109, 3936328);
    /* @3936336 store */
    v17 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v17);
    /* @3936344 load */
    /* @3936352 cast */
    /* @3936356 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3936388;
    L_3936360: ;
    /* @3936360 constant */
    /* @3936364 cast */
    /* @3936368 load */
    /* @3936376 call */
    GM_SITE(vm, 109, 3936376);
    /* @3936384 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3936388: ;
    /* @3936388 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3936360;
    L_3936392: ;
    /* @3936392 load */
    /* @3936400 constant */
    /* @3936404 cmp */
    /* @3936408 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(2)))) goto L_3937444;
    /* @3936412 constant */
    /* @3936416 cast */
    /* @3936420 load */
    /* @3936428 constant */
    /* @3936432 sub */
    /* @3936436 load */
    /* @3936444 call */
    GM_SITE(vm, 109, 3936444);
    /* @3936452 store */
    v18 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v18);
    /* @3936460 load */
    /* @3936468 cast */
    /* @3936472 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3936504;
    L_3936476: ;
    /* @3936476 constant */
    /* @3936480 cast */
    /* @3936484 load */
    /* @3936492 call */
    GM_SITE(vm, 109, 3936492);
    /* @3936500 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3936504: ;
    /* @3936504 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3936476;
    /* @3936508 constant */
    /* @3936512 cast */
    /* @3936516 load */
    /* @3936524 constant */
    /* @3936528 sub */
    /* @3936532 load */
    /* @3936540 constant */
    /* @3936544 add */
    /* @3936548 call */
    GM_SITE(vm, 109, 3936548);
    v19 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3936556 store */
    v20 = GM_CALL(vm, "instance_create", 3, v19, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v20);
    /* @3936564 load */
    /* @3936572 cast */
    /* @3936576 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3936608;
    L_3936580: ;
    /* @3936580 constant */
    /* @3936584 cast */
    /* @3936588 load */
    /* @3936596 call */
    GM_SITE(vm, 109, 3936596);
    /* @3936604 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3936608: ;
    /* @3936608 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3936580;
    /* @3936612 constant */
    /* @3936616 cast */
    /* @3936620 load */
    /* @3936628 constant */
    /* @3936632 sub */
    /* @3936636 load */
    /* @3936644 constant */
    /* @3936648 sub */
    /* @3936652 call */
    GM_SITE(vm, 109, 3936652);
    /* @3936660 store */
    v21 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v21);
    /* @3936668 load */
    /* @3936676 cast */
    /* @3936680 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3936712;
    L_3936684: ;
    /* @3936684 constant */
    /* @3936688 cast */
    /* @3936692 load */
    /* @3936700 call */
    GM_SITE(vm, 109, 3936700);
    /* @3936708 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3936712: ;
    /* @3936712 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3936684;
    /* @3936716 constant */
    /* @3936720 cast */
    /* @3936724 load */
    /* @3936732 constant */
    /* @3936736 sub */
    /* @3936740 load */
    /* @3936748 constant */
    /* @3936752 add */
    /* @3936756 call */
    GM_SITE(vm, 109, 3936756);
    v22 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3936764 store */
    v23 = GM_CALL(vm, "instance_create", 3, v22, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v23);
    /* @3936772 load */
    /* @3936780 cast */
    /* @3936784 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3936816;
    L_3936788: ;
    /* @3936788 constant */
    /* @3936792 cast */
    /* @3936796 load */
    /* @3936804 call */
    GM_SITE(vm, 109, 3936804);
    /* @3936812 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3936816: ;
    /* @3936816 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3936788;
    /* @3936820 constant */
    /* @3936824 cast */
    /* @3936828 load */
    /* @3936836 constant */
    /* @3936840 sub */
    /* @3936844 load */
    /* @3936852 constant */
    /* @3936856 sub */
    /* @3936860 call */
    GM_SITE(vm, 109, 3936860);
    /* @3936868 store */
    v24 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v24);
    /* @3936876 load */
    /* @3936884 cast */
    /* @3936888 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3936920;
    L_3936892: ;
    /* @3936892 constant */
    /* @3936896 cast */
    /* @3936900 load */
    /* @3936908 call */
    GM_SITE(vm, 109, 3936908);
    /* @3936916 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3936920: ;
    /* @3936920 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3936892;
    /* @3936924 constant */
    /* @3936928 cast */
    /* @3936932 load */
    /* @3936940 constant */
    /* @3936944 sub */
    /* @3936948 load */
    /* @3936956 constant */
    /* @3936960 sub */
    /* @3936964 call */
    GM_SITE(vm, 109, 3936964);
    /* @3936972 store */
    v25 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v25);
    /* @3936980 load */
    /* @3936988 cast */
    /* @3936992 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3937024;
    L_3936996: ;
    /* @3936996 constant */
    /* @3937000 cast */
    /* @3937004 load */
    /* @3937012 call */
    GM_SITE(vm, 109, 3937012);
    /* @3937020 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3937024: ;
    /* @3937024 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3936996;
    /* @3937028 constant */
    /* @3937032 cast */
    /* @3937036 load */
    /* @3937044 constant */
    /* @3937048 sub */
    /* @3937052 load */
    /* @3937060 constant */
    /* @3937064 add */
    /* @3937068 call */
    GM_SITE(vm, 109, 3937068);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3937076 store */
    v27 = GM_CALL(vm, "instance_create", 3, v26, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v27);
    /* @3937084 load */
    /* @3937092 cast */
    /* @3937096 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3937128;
    L_3937100: ;
    /* @3937100 constant */
    /* @3937104 cast */
    /* @3937108 load */
    /* @3937116 call */
    GM_SITE(vm, 109, 3937116);
    /* @3937124 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3937128: ;
    /* @3937128 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3937100;
    /* @3937132 constant */
    /* @3937136 cast */
    /* @3937140 load */
    /* @3937148 constant */
    /* @3937152 sub */
    /* @3937156 load */
    /* @3937164 constant */
    /* @3937168 sub */
    /* @3937172 call */
    GM_SITE(vm, 109, 3937172);
    /* @3937180 store */
    v28 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v28);
    /* @3937188 load */
    /* @3937196 cast */
    /* @3937200 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3937232;
    L_3937204: ;
    /* @3937204 constant */
    /* @3937208 cast */
    /* @3937212 load */
    /* @3937220 call */
    GM_SITE(vm, 109, 3937220);
    /* @3937228 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3937232: ;
    /* @3937232 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3937204;
    /* @3937236 constant */
    /* @3937240 cast */
    /* @3937244 load */
    /* @3937252 constant */
    /* @3937256 sub */
    /* @3937260 load */
    /* @3937268 constant */
    /* @3937272 add */
    /* @3937276 call */
    GM_SITE(vm, 109, 3937276);
    v29 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3937284 store */
    v30 = GM_CALL(vm, "instance_create", 3, v29, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v30);
    /* @3937292 load */
    /* @3937300 cast */
    /* @3937304 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3937336;
    L_3937308: ;
    /* @3937308 constant */
    /* @3937312 cast */
    /* @3937316 load */
    /* @3937324 call */
    GM_SITE(vm, 109, 3937324);
    /* @3937332 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3937336: ;
    /* @3937336 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3937308;
    /* @3937340 constant */
    /* @3937344 cast */
    /* @3937348 load */
    /* @3937356 constant */
    /* @3937360 sub */
    /* @3937364 load */
    /* @3937372 constant */
    /* @3937376 sub */
    /* @3937380 call */
    GM_SITE(vm, 109, 3937380);
    /* @3937388 store */
    v31 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v31);
    /* @3937396 load */
    /* @3937404 cast */
    /* @3937408 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3937440;
    L_3937412: ;
    /* @3937412 constant */
    /* @3937416 cast */
    /* @3937420 load */
    /* @3937428 call */
    GM_SITE(vm, 109, 3937428);
    /* @3937436 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_3937440: ;
    /* @3937440 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3937412;
    L_3937444: ;
    /* @3937444 load */
    /* @3937452 constant */
    /* @3937456 cmp */
    /* @3937460 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(3)))) goto L_3938288;
    /* @3937464 constant */
    /* @3937468 cast */
    /* @3937472 load */
    /* @3937480 constant */
    /* @3937484 sub */
    /* @3937488 load */
    /* @3937496 call */
    GM_SITE(vm, 109, 3937496);
    /* @3937504 store */
    v32 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v32);
    /* @3937512 load */
    /* @3937520 cast */
    /* @3937524 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3937556;
    L_3937528: ;
    /* @3937528 constant */
    /* @3937532 cast */
    /* @3937536 load */
    /* @3937544 call */
    GM_SITE(vm, 109, 3937544);
    /* @3937552 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3937556: ;
    /* @3937556 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3937528;
    /* @3937560 constant */
    /* @3937564 cast */
    /* @3937568 load */
    /* @3937576 constant */
    /* @3937580 sub */
    /* @3937584 load */
    /* @3937592 constant */
    /* @3937596 add */
    /* @3937600 call */
    GM_SITE(vm, 109, 3937600);
    v33 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3937608 store */
    v34 = GM_CALL(vm, "instance_create", 3, v33, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v34);
    /* @3937616 load */
    /* @3937624 cast */
    /* @3937628 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3937660;
    L_3937632: ;
    /* @3937632 constant */
    /* @3937636 cast */
    /* @3937640 load */
    /* @3937648 call */
    GM_SITE(vm, 109, 3937648);
    /* @3937656 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3937660: ;
    /* @3937660 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3937632;
    /* @3937664 constant */
    /* @3937668 cast */
    /* @3937672 load */
    /* @3937680 constant */
    /* @3937684 sub */
    /* @3937688 load */
    /* @3937696 constant */
    /* @3937700 sub */
    /* @3937704 call */
    GM_SITE(vm, 109, 3937704);
    /* @3937712 store */
    v35 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v35);
    /* @3937720 load */
    /* @3937728 cast */
    /* @3937732 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3937764;
    L_3937736: ;
    /* @3937736 constant */
    /* @3937740 cast */
    /* @3937744 load */
    /* @3937752 call */
    GM_SITE(vm, 109, 3937752);
    /* @3937760 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3937764: ;
    /* @3937764 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3937736;
    /* @3937768 constant */
    /* @3937772 cast */
    /* @3937776 load */
    /* @3937784 constant */
    /* @3937788 sub */
    /* @3937792 load */
    /* @3937800 constant */
    /* @3937804 add */
    /* @3937808 call */
    GM_SITE(vm, 109, 3937808);
    v36 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3937816 store */
    v37 = GM_CALL(vm, "instance_create", 3, v36, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v37);
    /* @3937824 load */
    /* @3937832 cast */
    /* @3937836 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3937868;
    L_3937840: ;
    /* @3937840 constant */
    /* @3937844 cast */
    /* @3937848 load */
    /* @3937856 call */
    GM_SITE(vm, 109, 3937856);
    /* @3937864 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3937868: ;
    /* @3937868 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3937840;
    /* @3937872 constant */
    /* @3937876 cast */
    /* @3937880 load */
    /* @3937888 constant */
    /* @3937892 sub */
    /* @3937896 load */
    /* @3937904 constant */
    /* @3937908 sub */
    /* @3937912 call */
    GM_SITE(vm, 109, 3937912);
    /* @3937920 store */
    v38 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v38);
    /* @3937928 load */
    /* @3937936 cast */
    /* @3937940 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3937972;
    L_3937944: ;
    /* @3937944 constant */
    /* @3937948 cast */
    /* @3937952 load */
    /* @3937960 call */
    GM_SITE(vm, 109, 3937960);
    /* @3937968 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3937972: ;
    /* @3937972 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3937944;
    /* @3937976 constant */
    /* @3937980 cast */
    /* @3937984 load */
    /* @3937992 constant */
    /* @3937996 sub */
    /* @3938000 load */
    /* @3938008 constant */
    /* @3938012 sub */
    /* @3938016 call */
    GM_SITE(vm, 109, 3938016);
    /* @3938024 store */
    v39 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v39);
    /* @3938032 load */
    /* @3938040 cast */
    /* @3938044 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3938076;
    L_3938048: ;
    /* @3938048 constant */
    /* @3938052 cast */
    /* @3938056 load */
    /* @3938064 call */
    GM_SITE(vm, 109, 3938064);
    /* @3938072 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3938076: ;
    /* @3938076 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3938048;
    /* @3938080 constant */
    /* @3938084 cast */
    /* @3938088 load */
    /* @3938096 constant */
    /* @3938100 sub */
    /* @3938104 load */
    /* @3938112 constant */
    /* @3938116 add */
    /* @3938120 call */
    GM_SITE(vm, 109, 3938120);
    v40 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3938128 store */
    v41 = GM_CALL(vm, "instance_create", 3, v40, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v41);
    /* @3938136 load */
    /* @3938144 cast */
    /* @3938148 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3938180;
    L_3938152: ;
    /* @3938152 constant */
    /* @3938156 cast */
    /* @3938160 load */
    /* @3938168 call */
    GM_SITE(vm, 109, 3938168);
    /* @3938176 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3938180: ;
    /* @3938180 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3938152;
    /* @3938184 constant */
    /* @3938188 cast */
    /* @3938192 load */
    /* @3938200 constant */
    /* @3938204 sub */
    /* @3938208 load */
    /* @3938216 constant */
    /* @3938220 sub */
    /* @3938224 call */
    GM_SITE(vm, 109, 3938224);
    /* @3938232 store */
    v42 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v42);
    /* @3938240 load */
    /* @3938248 cast */
    /* @3938252 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3938284;
    L_3938256: ;
    /* @3938256 constant */
    /* @3938260 cast */
    /* @3938264 load */
    /* @3938272 call */
    GM_SITE(vm, 109, 3938272);
    /* @3938280 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3938284: ;
    /* @3938284 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3938256;
    L_3938288: ;
    /* @3938288 load */
    /* @3938296 constant */
    /* @3938300 cmp */
    /* @3938304 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(4)))) goto L_3939444;
    /* @3938308 constant */
    /* @3938312 cast */
    /* @3938316 load */
    /* @3938324 constant */
    /* @3938328 sub */
    /* @3938332 load */
    /* @3938340 call */
    GM_SITE(vm, 109, 3938340);
    /* @3938348 store */
    v43 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v43);
    /* @3938356 load */
    /* @3938364 cast */
    /* @3938368 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3938400;
    L_3938372: ;
    /* @3938372 constant */
    /* @3938376 cast */
    /* @3938380 load */
    /* @3938388 call */
    GM_SITE(vm, 109, 3938388);
    /* @3938396 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3938400: ;
    /* @3938400 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3938372;
    /* @3938404 constant */
    /* @3938408 cast */
    /* @3938412 load */
    /* @3938420 constant */
    /* @3938424 sub */
    /* @3938428 load */
    /* @3938436 constant */
    /* @3938440 add */
    /* @3938444 call */
    GM_SITE(vm, 109, 3938444);
    v44 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3938452 store */
    v45 = GM_CALL(vm, "instance_create", 3, v44, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v45);
    /* @3938460 load */
    /* @3938468 cast */
    /* @3938472 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3938504;
    L_3938476: ;
    /* @3938476 constant */
    /* @3938480 cast */
    /* @3938484 load */
    /* @3938492 call */
    GM_SITE(vm, 109, 3938492);
    /* @3938500 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3938504: ;
    /* @3938504 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3938476;
    /* @3938508 constant */
    /* @3938512 cast */
    /* @3938516 load */
    /* @3938524 constant */
    /* @3938528 sub */
    /* @3938532 load */
    /* @3938540 constant */
    /* @3938544 sub */
    /* @3938548 call */
    GM_SITE(vm, 109, 3938548);
    /* @3938556 store */
    v46 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v46);
    /* @3938564 load */
    /* @3938572 cast */
    /* @3938576 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3938608;
    L_3938580: ;
    /* @3938580 constant */
    /* @3938584 cast */
    /* @3938588 load */
    /* @3938596 call */
    GM_SITE(vm, 109, 3938596);
    /* @3938604 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3938608: ;
    /* @3938608 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3938580;
    /* @3938612 constant */
    /* @3938616 cast */
    /* @3938620 load */
    /* @3938628 constant */
    /* @3938632 sub */
    /* @3938636 load */
    /* @3938644 constant */
    /* @3938648 add */
    /* @3938652 call */
    GM_SITE(vm, 109, 3938652);
    v47 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3938660 store */
    v48 = GM_CALL(vm, "instance_create", 3, v47, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v48);
    /* @3938668 load */
    /* @3938676 cast */
    /* @3938680 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3938712;
    L_3938684: ;
    /* @3938684 constant */
    /* @3938688 cast */
    /* @3938692 load */
    /* @3938700 call */
    GM_SITE(vm, 109, 3938700);
    /* @3938708 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3938712: ;
    /* @3938712 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3938684;
    /* @3938716 constant */
    /* @3938720 cast */
    /* @3938724 load */
    /* @3938732 constant */
    /* @3938736 sub */
    /* @3938740 load */
    /* @3938748 constant */
    /* @3938752 sub */
    /* @3938756 call */
    GM_SITE(vm, 109, 3938756);
    /* @3938764 store */
    v49 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v49);
    /* @3938772 load */
    /* @3938780 cast */
    /* @3938784 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3938816;
    L_3938788: ;
    /* @3938788 constant */
    /* @3938792 cast */
    /* @3938796 load */
    /* @3938804 call */
    GM_SITE(vm, 109, 3938804);
    /* @3938812 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3938816: ;
    /* @3938816 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3938788;
    /* @3938820 constant */
    /* @3938824 cast */
    /* @3938828 load */
    /* @3938836 constant */
    /* @3938840 sub */
    /* @3938844 load */
    /* @3938852 constant */
    /* @3938856 add */
    /* @3938860 call */
    GM_SITE(vm, 109, 3938860);
    v50 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @3938868 store */
    v51 = GM_CALL(vm, "instance_create", 3, v50, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v51);
    /* @3938876 load */
    /* @3938884 cast */
    /* @3938888 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3938920;
    L_3938892: ;
    /* @3938892 constant */
    /* @3938896 cast */
    /* @3938900 load */
    /* @3938908 call */
    GM_SITE(vm, 109, 3938908);
    /* @3938916 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3938920: ;
    /* @3938920 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3938892;
    /* @3938924 constant */
    /* @3938928 cast */
    /* @3938932 load */
    /* @3938940 constant */
    /* @3938944 sub */
    /* @3938948 load */
    /* @3938956 constant */
    /* @3938960 add */
    /* @3938964 call */
    GM_SITE(vm, 109, 3938964);
    v52 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3938972 store */
    v53 = GM_CALL(vm, "instance_create", 3, v52, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v53);
    /* @3938980 load */
    /* @3938988 cast */
    /* @3938992 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3939024;
    L_3938996: ;
    /* @3938996 constant */
    /* @3939000 cast */
    /* @3939004 load */
    /* @3939012 call */
    GM_SITE(vm, 109, 3939012);
    /* @3939020 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3939024: ;
    /* @3939024 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3938996;
    /* @3939028 constant */
    /* @3939032 cast */
    /* @3939036 load */
    /* @3939044 constant */
    /* @3939048 sub */
    /* @3939052 load */
    /* @3939060 constant */
    /* @3939064 sub */
    /* @3939068 call */
    GM_SITE(vm, 109, 3939068);
    /* @3939076 store */
    v54 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v54);
    /* @3939084 load */
    /* @3939092 cast */
    /* @3939096 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3939128;
    L_3939100: ;
    /* @3939100 constant */
    /* @3939104 cast */
    /* @3939108 load */
    /* @3939116 call */
    GM_SITE(vm, 109, 3939116);
    /* @3939124 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3939128: ;
    /* @3939128 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3939100;
    /* @3939132 constant */
    /* @3939136 cast */
    /* @3939140 load */
    /* @3939148 constant */
    /* @3939152 sub */
    /* @3939156 load */
    /* @3939164 constant */
    /* @3939168 add */
    /* @3939172 call */
    GM_SITE(vm, 109, 3939172);
    v55 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3939180 store */
    v56 = GM_CALL(vm, "instance_create", 3, v55, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v56);
    /* @3939188 load */
    /* @3939196 cast */
    /* @3939200 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3939232;
    L_3939204: ;
    /* @3939204 constant */
    /* @3939208 cast */
    /* @3939212 load */
    /* @3939220 call */
    GM_SITE(vm, 109, 3939220);
    /* @3939228 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3939232: ;
    /* @3939232 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3939204;
    /* @3939236 constant */
    /* @3939240 cast */
    /* @3939244 load */
    /* @3939252 constant */
    /* @3939256 sub */
    /* @3939260 load */
    /* @3939268 constant */
    /* @3939272 sub */
    /* @3939276 call */
    GM_SITE(vm, 109, 3939276);
    /* @3939284 store */
    v57 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v57);
    /* @3939292 load */
    /* @3939300 cast */
    /* @3939304 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3939336;
    L_3939308: ;
    /* @3939308 constant */
    /* @3939312 cast */
    /* @3939316 load */
    /* @3939324 call */
    GM_SITE(vm, 109, 3939324);
    /* @3939332 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_3939336: ;
    /* @3939336 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3939308;
    /* @3939340 constant */
    /* @3939344 cast */
    /* @3939348 load */
    /* @3939356 constant */
    /* @3939360 sub */
    /* @3939364 load */
    /* @3939372 constant */
    /* @3939376 sub */
    /* @3939380 call */
    GM_SITE(vm, 109, 3939380);
    /* @3939388 store */
    v58 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v58);
    /* @3939396 load */
    /* @3939404 cast */
    /* @3939408 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_3939440;
    L_3939412: ;
    /* @3939412 constant */
    /* @3939416 cast */
    /* @3939420 load */
    /* @3939428 call */
    GM_SITE(vm, 109, 3939428);
    /* @3939436 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_3939440: ;
    /* @3939440 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3939412;
    L_3939444: ;
    /* @3939444 load */
    /* @3939452 constant */
    /* @3939456 cmp */
    /* @3939460 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(5)))) goto L_3940808;
    /* @3939464 constant */
    /* @3939468 cast */
    /* @3939472 load */
    /* @3939480 constant */
    /* @3939484 sub */
    /* @3939488 load */
    /* @3939496 call */
    GM_SITE(vm, 109, 3939496);
    /* @3939504 store */
    v59 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v59);
    /* @3939512 load */
    /* @3939520 cast */
    /* @3939524 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3939556;
    L_3939528: ;
    /* @3939528 constant */
    /* @3939532 cast */
    /* @3939536 load */
    /* @3939544 call */
    GM_SITE(vm, 109, 3939544);
    /* @3939552 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3939556: ;
    /* @3939556 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3939528;
    /* @3939560 constant */
    /* @3939564 cast */
    /* @3939568 load */
    /* @3939576 constant */
    /* @3939580 sub */
    /* @3939584 load */
    /* @3939592 constant */
    /* @3939596 add */
    /* @3939600 call */
    GM_SITE(vm, 109, 3939600);
    v60 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3939608 store */
    v61 = GM_CALL(vm, "instance_create", 3, v60, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v61);
    /* @3939616 load */
    /* @3939624 cast */
    /* @3939628 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3939660;
    L_3939632: ;
    /* @3939632 constant */
    /* @3939636 cast */
    /* @3939640 load */
    /* @3939648 call */
    GM_SITE(vm, 109, 3939648);
    /* @3939656 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3939660: ;
    /* @3939660 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3939632;
    /* @3939664 constant */
    /* @3939668 cast */
    /* @3939672 load */
    /* @3939680 constant */
    /* @3939684 sub */
    /* @3939688 load */
    /* @3939696 constant */
    /* @3939700 sub */
    /* @3939704 call */
    GM_SITE(vm, 109, 3939704);
    /* @3939712 store */
    v62 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v62);
    /* @3939720 load */
    /* @3939728 cast */
    /* @3939732 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3939764;
    L_3939736: ;
    /* @3939736 constant */
    /* @3939740 cast */
    /* @3939744 load */
    /* @3939752 call */
    GM_SITE(vm, 109, 3939752);
    /* @3939760 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3939764: ;
    /* @3939764 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3939736;
    /* @3939768 constant */
    /* @3939772 cast */
    /* @3939776 load */
    /* @3939784 constant */
    /* @3939788 sub */
    /* @3939792 load */
    /* @3939800 constant */
    /* @3939804 add */
    /* @3939808 call */
    GM_SITE(vm, 109, 3939808);
    v63 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3939816 store */
    v64 = GM_CALL(vm, "instance_create", 3, v63, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v64);
    /* @3939824 load */
    /* @3939832 cast */
    /* @3939836 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3939868;
    L_3939840: ;
    /* @3939840 constant */
    /* @3939844 cast */
    /* @3939848 load */
    /* @3939856 call */
    GM_SITE(vm, 109, 3939856);
    /* @3939864 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3939868: ;
    /* @3939868 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3939840;
    /* @3939872 constant */
    /* @3939876 cast */
    /* @3939880 load */
    /* @3939888 constant */
    /* @3939892 sub */
    /* @3939896 load */
    /* @3939904 constant */
    /* @3939908 sub */
    /* @3939912 call */
    GM_SITE(vm, 109, 3939912);
    /* @3939920 store */
    v65 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v65);
    /* @3939928 load */
    /* @3939936 cast */
    /* @3939940 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3939972;
    L_3939944: ;
    /* @3939944 constant */
    /* @3939948 cast */
    /* @3939952 load */
    /* @3939960 call */
    GM_SITE(vm, 109, 3939960);
    /* @3939968 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3939972: ;
    /* @3939972 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3939944;
    /* @3939976 constant */
    /* @3939980 cast */
    /* @3939984 load */
    /* @3939992 constant */
    /* @3939996 sub */
    /* @3940000 load */
    /* @3940008 constant */
    /* @3940012 add */
    /* @3940016 call */
    GM_SITE(vm, 109, 3940016);
    v66 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @3940024 store */
    v67 = GM_CALL(vm, "instance_create", 3, v66, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v67);
    /* @3940032 load */
    /* @3940040 cast */
    /* @3940044 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3940076;
    L_3940048: ;
    /* @3940048 constant */
    /* @3940052 cast */
    /* @3940056 load */
    /* @3940064 call */
    GM_SITE(vm, 109, 3940064);
    /* @3940072 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3940076: ;
    /* @3940076 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3940048;
    /* @3940080 constant */
    /* @3940084 cast */
    /* @3940088 load */
    /* @3940096 constant */
    /* @3940100 sub */
    /* @3940104 load */
    /* @3940112 constant */
    /* @3940116 add */
    /* @3940120 call */
    GM_SITE(vm, 109, 3940120);
    v68 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3940128 store */
    v69 = GM_CALL(vm, "instance_create", 3, v68, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v69);
    /* @3940136 load */
    /* @3940144 cast */
    /* @3940148 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3940180;
    L_3940152: ;
    /* @3940152 constant */
    /* @3940156 cast */
    /* @3940160 load */
    /* @3940168 call */
    GM_SITE(vm, 109, 3940168);
    /* @3940176 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3940180: ;
    /* @3940180 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3940152;
    /* @3940184 constant */
    /* @3940188 cast */
    /* @3940192 load */
    /* @3940200 constant */
    /* @3940204 sub */
    /* @3940208 load */
    /* @3940216 constant */
    /* @3940220 sub */
    /* @3940224 call */
    GM_SITE(vm, 109, 3940224);
    /* @3940232 store */
    v70 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v70);
    /* @3940240 load */
    /* @3940248 cast */
    /* @3940252 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3940284;
    L_3940256: ;
    /* @3940256 constant */
    /* @3940260 cast */
    /* @3940264 load */
    /* @3940272 call */
    GM_SITE(vm, 109, 3940272);
    /* @3940280 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3940284: ;
    /* @3940284 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3940256;
    /* @3940288 constant */
    /* @3940292 cast */
    /* @3940296 load */
    /* @3940304 constant */
    /* @3940308 sub */
    /* @3940312 load */
    /* @3940320 constant */
    /* @3940324 add */
    /* @3940328 call */
    GM_SITE(vm, 109, 3940328);
    v71 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3940336 store */
    v72 = GM_CALL(vm, "instance_create", 3, v71, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v72);
    /* @3940344 load */
    /* @3940352 cast */
    /* @3940356 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3940388;
    L_3940360: ;
    /* @3940360 constant */
    /* @3940364 cast */
    /* @3940368 load */
    /* @3940376 call */
    GM_SITE(vm, 109, 3940376);
    /* @3940384 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3940388: ;
    /* @3940388 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3940360;
    /* @3940392 constant */
    /* @3940396 cast */
    /* @3940400 load */
    /* @3940408 constant */
    /* @3940412 sub */
    /* @3940416 load */
    /* @3940424 constant */
    /* @3940428 sub */
    /* @3940432 call */
    GM_SITE(vm, 109, 3940432);
    /* @3940440 store */
    v73 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v73);
    /* @3940448 load */
    /* @3940456 cast */
    /* @3940460 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3940492;
    L_3940464: ;
    /* @3940464 constant */
    /* @3940468 cast */
    /* @3940472 load */
    /* @3940480 call */
    GM_SITE(vm, 109, 3940480);
    /* @3940488 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_3940492: ;
    /* @3940492 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3940464;
    /* @3940496 constant */
    /* @3940500 cast */
    /* @3940504 load */
    /* @3940512 constant */
    /* @3940516 sub */
    /* @3940520 load */
    /* @3940528 constant */
    /* @3940532 sub */
    /* @3940536 call */
    GM_SITE(vm, 109, 3940536);
    /* @3940544 store */
    v74 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v74);
    /* @3940552 load */
    /* @3940560 cast */
    /* @3940564 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_3940596;
    L_3940568: ;
    /* @3940568 constant */
    /* @3940572 cast */
    /* @3940576 load */
    /* @3940584 call */
    GM_SITE(vm, 109, 3940584);
    /* @3940592 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_3940596: ;
    /* @3940596 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3940568;
    /* @3940600 constant */
    /* @3940604 cast */
    /* @3940608 load */
    /* @3940616 constant */
    /* @3940620 sub */
    /* @3940624 load */
    /* @3940632 constant */
    /* @3940636 add */
    /* @3940640 call */
    GM_SITE(vm, 109, 3940640);
    v75 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @3940648 store */
    v76 = GM_CALL(vm, "instance_create", 3, v75, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID12", v76);
    /* @3940656 load */
    /* @3940664 cast */
    /* @3940668 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID12")))) goto L_3940700;
    L_3940672: ;
    /* @3940672 constant */
    /* @3940676 cast */
    /* @3940680 load */
    /* @3940688 call */
    GM_SITE(vm, 109, 3940688);
    /* @3940696 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread12"), VAL(5)));
    L_3940700: ;
    /* @3940700 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3940672;
    /* @3940704 constant */
    /* @3940708 cast */
    /* @3940712 load */
    /* @3940720 constant */
    /* @3940724 sub */
    /* @3940728 load */
    /* @3940736 constant */
    /* @3940740 sub */
    /* @3940744 call */
    GM_SITE(vm, 109, 3940744);
    /* @3940752 store */
    v77 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID13", v77);
    /* @3940760 load */
    /* @3940768 cast */
    /* @3940772 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID13")))) goto L_3940804;
    L_3940776: ;
    /* @3940776 constant */
    /* @3940780 cast */
    /* @3940784 load */
    /* @3940792 call */
    GM_SITE(vm, 109, 3940792);
    /* @3940800 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread13"), VAL(5)));
    L_3940804: ;
    /* @3940804 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3940776;
    L_3940808: ;
    /* @3940808 call */
    GM_SITE(vm, 109, 3940808);
    /* @3940816 popz */
    (void)(GM_CALL(vm, "action_kill_object", 0));
    L_3940820: ;
    return;
}
