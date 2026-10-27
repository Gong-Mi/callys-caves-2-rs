/* generated from CODE 132 (gml_Object_obj_enemy2_Alarm_0), source start 3951696, end 3956368. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0132(GmVM* vm) {
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
    /* @3951696 load */
    /* @3951704 constant */
    /* @3951708 cmp */
    /* @3951712 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3951720;
    /* @3951716 b */
    goto L_3951776;
    L_3951720: ;
    /* @3951720 load */
    /* @3951728 constant */
    /* @3951732 cmp */
    /* @3951736 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3951776;
    /* @3951740 constant */
    /* @3951744 cast */
    /* @3951748 constant */
    /* @3951752 cast */
    /* @3951756 constant */
    /* @3951760 cast */
    /* @3951764 call */
    GM_SITE(vm, 132, 3951764);
    /* @3951772 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(7), VAL(0), VAL(0)));
    L_3951776: ;
    /* @3951776 load */
    /* @3951784 constant */
    /* @3951788 cmp */
    /* @3951792 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "gemdropenabled") == VAL(1)))) goto L_3951840;
    /* @3951796 constant */
    /* @3951800 cast */
    /* @3951804 load */
    /* @3951812 constant */
    /* @3951816 sub */
    /* @3951820 load */
    /* @3951828 call */
    GM_SITE(vm, 132, 3951828);
    /* @3951836 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(59)));
    L_3951840: ;
    /* @3951840 load */
    /* @3951848 constant */
    /* @3951852 cmp */
    /* @3951856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpdrop") == VAL(1)))) goto L_3951904;
    /* @3951860 constant */
    /* @3951864 cast */
    /* @3951868 load */
    /* @3951876 constant */
    /* @3951880 sub */
    /* @3951884 load */
    /* @3951892 call */
    GM_SITE(vm, 132, 3951892);
    /* @3951900 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(62)));
    L_3951904: ;
    /* @3951904 load */
    /* @3951912 constant */
    /* @3951916 cmp */
    /* @3951920 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "xpdrop") == VAL(1)))) goto L_3952020;
    /* @3951924 constant */
    /* @3951928 cast */
    /* @3951932 load */
    /* @3951940 constant */
    /* @3951944 sub */
    /* @3951948 load */
    /* @3951956 call */
    GM_SITE(vm, 132, 3951956);
    /* @3951964 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID", v1);
    /* @3951972 load */
    /* @3951980 cast */
    /* @3951984 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3952016;
    L_3951988: ;
    /* @3951988 constant */
    /* @3951992 cast */
    /* @3951996 load */
    /* @3952004 call */
    GM_SITE(vm, 132, 3952004);
    /* @3952012 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "xpspread"), VAL(5)));
    L_3952016: ;
    /* @3952016 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3951988;
    L_3952020: ;
    /* @3952020 constant */
    /* @3952024 cast */
    /* @3952028 call */
    GM_SITE(vm, 132, 3952028);
    /* @3952036 constant */
    /* @3952040 cmp */
    /* @3952044 bf */
    v2 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) >= VAL(20));
    if (!TRUTH(v2)) goto L_3952052;
    /* @3952048 b */
    goto L_3956356;
    L_3952052: ;
    /* @3952052 constant */
    /* @3952056 cast */
    /* @3952060 call */
    GM_SITE(vm, 132, 3952060);
    /* @3952068 constant */
    /* @3952072 cmp */
    /* @3952076 bf */
    v3 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) < VAL(20));
    if (!TRUTH(v3)) goto L_3956356;
    /* @3952080 load */
    /* @3952088 constant */
    /* @3952092 cmp */
    /* @3952096 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(1)))) goto L_3952612;
    /* @3952100 constant */
    /* @3952104 cast */
    /* @3952108 load */
    /* @3952116 constant */
    /* @3952120 sub */
    /* @3952124 load */
    /* @3952132 call */
    GM_SITE(vm, 132, 3952132);
    /* @3952140 store */
    v4 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v4);
    /* @3952148 load */
    /* @3952156 cast */
    /* @3952160 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3952192;
    L_3952164: ;
    /* @3952164 constant */
    /* @3952168 cast */
    /* @3952172 load */
    /* @3952180 call */
    GM_SITE(vm, 132, 3952180);
    /* @3952188 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3952192: ;
    /* @3952192 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3952164;
    /* @3952196 constant */
    /* @3952200 cast */
    /* @3952204 load */
    /* @3952212 constant */
    /* @3952216 sub */
    /* @3952220 load */
    /* @3952228 constant */
    /* @3952232 add */
    /* @3952236 call */
    GM_SITE(vm, 132, 3952236);
    v5 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3952244 store */
    v6 = GM_CALL(vm, "instance_create", 3, v5, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v6);
    /* @3952252 load */
    /* @3952260 cast */
    /* @3952264 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3952296;
    L_3952268: ;
    /* @3952268 constant */
    /* @3952272 cast */
    /* @3952276 load */
    /* @3952284 call */
    GM_SITE(vm, 132, 3952284);
    /* @3952292 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3952296: ;
    /* @3952296 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3952268;
    /* @3952300 constant */
    /* @3952304 cast */
    /* @3952308 load */
    /* @3952316 constant */
    /* @3952320 sub */
    /* @3952324 load */
    /* @3952332 constant */
    /* @3952336 sub */
    /* @3952340 call */
    GM_SITE(vm, 132, 3952340);
    /* @3952348 store */
    v7 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v7);
    /* @3952356 load */
    /* @3952364 cast */
    /* @3952368 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3952400;
    L_3952372: ;
    /* @3952372 constant */
    /* @3952376 cast */
    /* @3952380 load */
    /* @3952388 call */
    GM_SITE(vm, 132, 3952388);
    /* @3952396 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3952400: ;
    /* @3952400 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3952372;
    /* @3952404 constant */
    /* @3952408 cast */
    /* @3952412 load */
    /* @3952420 constant */
    /* @3952424 sub */
    /* @3952428 load */
    /* @3952436 constant */
    /* @3952440 add */
    /* @3952444 call */
    GM_SITE(vm, 132, 3952444);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3952452 store */
    v9 = GM_CALL(vm, "instance_create", 3, v8, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v9);
    /* @3952460 load */
    /* @3952468 cast */
    /* @3952472 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3952504;
    L_3952476: ;
    /* @3952476 constant */
    /* @3952480 cast */
    /* @3952484 load */
    /* @3952492 call */
    GM_SITE(vm, 132, 3952492);
    /* @3952500 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3952504: ;
    /* @3952504 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3952476;
    /* @3952508 constant */
    /* @3952512 cast */
    /* @3952516 load */
    /* @3952524 constant */
    /* @3952528 sub */
    /* @3952532 load */
    /* @3952540 constant */
    /* @3952544 sub */
    /* @3952548 call */
    GM_SITE(vm, 132, 3952548);
    /* @3952556 store */
    v10 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v10);
    /* @3952564 load */
    /* @3952572 cast */
    /* @3952576 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3952608;
    L_3952580: ;
    /* @3952580 constant */
    /* @3952584 cast */
    /* @3952588 load */
    /* @3952596 call */
    GM_SITE(vm, 132, 3952596);
    /* @3952604 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3952608: ;
    /* @3952608 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3952580;
    L_3952612: ;
    /* @3952612 load */
    /* @3952620 constant */
    /* @3952624 cmp */
    /* @3952628 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(2)))) goto L_3953248;
    /* @3952632 constant */
    /* @3952636 cast */
    /* @3952640 load */
    /* @3952648 constant */
    /* @3952652 sub */
    /* @3952656 load */
    /* @3952664 call */
    GM_SITE(vm, 132, 3952664);
    /* @3952672 store */
    v11 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v11);
    /* @3952680 load */
    /* @3952688 cast */
    /* @3952692 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3952724;
    L_3952696: ;
    /* @3952696 constant */
    /* @3952700 cast */
    /* @3952704 load */
    /* @3952712 call */
    GM_SITE(vm, 132, 3952712);
    /* @3952720 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3952724: ;
    /* @3952724 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3952696;
    /* @3952728 constant */
    /* @3952732 cast */
    /* @3952736 load */
    /* @3952744 constant */
    /* @3952748 sub */
    /* @3952752 load */
    /* @3952760 constant */
    /* @3952764 add */
    /* @3952768 call */
    GM_SITE(vm, 132, 3952768);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3952776 store */
    v13 = GM_CALL(vm, "instance_create", 3, v12, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v13);
    /* @3952784 load */
    /* @3952792 cast */
    /* @3952796 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3952828;
    L_3952800: ;
    /* @3952800 constant */
    /* @3952804 cast */
    /* @3952808 load */
    /* @3952816 call */
    GM_SITE(vm, 132, 3952816);
    /* @3952824 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3952828: ;
    /* @3952828 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3952800;
    /* @3952832 constant */
    /* @3952836 cast */
    /* @3952840 load */
    /* @3952848 constant */
    /* @3952852 sub */
    /* @3952856 load */
    /* @3952864 constant */
    /* @3952868 sub */
    /* @3952872 call */
    GM_SITE(vm, 132, 3952872);
    /* @3952880 store */
    v14 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v14);
    /* @3952888 load */
    /* @3952896 cast */
    /* @3952900 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3952932;
    L_3952904: ;
    /* @3952904 constant */
    /* @3952908 cast */
    /* @3952912 load */
    /* @3952920 call */
    GM_SITE(vm, 132, 3952920);
    /* @3952928 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3952932: ;
    /* @3952932 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3952904;
    /* @3952936 constant */
    /* @3952940 cast */
    /* @3952944 load */
    /* @3952952 constant */
    /* @3952956 sub */
    /* @3952960 load */
    /* @3952968 constant */
    /* @3952972 add */
    /* @3952976 call */
    GM_SITE(vm, 132, 3952976);
    v15 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3952984 store */
    v16 = GM_CALL(vm, "instance_create", 3, v15, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v16);
    /* @3952992 load */
    /* @3953000 cast */
    /* @3953004 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3953036;
    L_3953008: ;
    /* @3953008 constant */
    /* @3953012 cast */
    /* @3953016 load */
    /* @3953024 call */
    GM_SITE(vm, 132, 3953024);
    /* @3953032 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3953036: ;
    /* @3953036 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3953008;
    /* @3953040 constant */
    /* @3953044 cast */
    /* @3953048 load */
    /* @3953056 constant */
    /* @3953060 sub */
    /* @3953064 load */
    /* @3953072 constant */
    /* @3953076 sub */
    /* @3953080 call */
    GM_SITE(vm, 132, 3953080);
    /* @3953088 store */
    v17 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v17);
    /* @3953096 load */
    /* @3953104 cast */
    /* @3953108 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3953140;
    L_3953112: ;
    /* @3953112 constant */
    /* @3953116 cast */
    /* @3953120 load */
    /* @3953128 call */
    GM_SITE(vm, 132, 3953128);
    /* @3953136 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3953140: ;
    /* @3953140 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3953112;
    /* @3953144 constant */
    /* @3953148 cast */
    /* @3953152 load */
    /* @3953160 constant */
    /* @3953164 sub */
    /* @3953168 load */
    /* @3953176 constant */
    /* @3953180 sub */
    /* @3953184 call */
    GM_SITE(vm, 132, 3953184);
    /* @3953192 store */
    v18 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v18);
    /* @3953200 load */
    /* @3953208 cast */
    /* @3953212 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3953244;
    L_3953216: ;
    /* @3953216 constant */
    /* @3953220 cast */
    /* @3953224 load */
    /* @3953232 call */
    GM_SITE(vm, 132, 3953232);
    /* @3953240 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3953244: ;
    /* @3953244 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3953216;
    L_3953248: ;
    /* @3953248 load */
    /* @3953256 constant */
    /* @3953260 cmp */
    /* @3953264 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(3)))) goto L_3954148;
    /* @3953268 constant */
    /* @3953272 cast */
    /* @3953276 load */
    /* @3953284 constant */
    /* @3953288 sub */
    /* @3953292 load */
    /* @3953300 call */
    GM_SITE(vm, 132, 3953300);
    /* @3953308 store */
    v19 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v19);
    /* @3953316 load */
    /* @3953324 cast */
    /* @3953328 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3953360;
    L_3953332: ;
    /* @3953332 constant */
    /* @3953336 cast */
    /* @3953340 load */
    /* @3953348 call */
    GM_SITE(vm, 132, 3953348);
    /* @3953356 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3953360: ;
    /* @3953360 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3953332;
    /* @3953364 constant */
    /* @3953368 cast */
    /* @3953372 load */
    /* @3953380 constant */
    /* @3953384 sub */
    /* @3953388 load */
    /* @3953396 constant */
    /* @3953400 add */
    /* @3953404 call */
    GM_SITE(vm, 132, 3953404);
    v20 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3953412 store */
    v21 = GM_CALL(vm, "instance_create", 3, v20, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v21);
    /* @3953420 load */
    /* @3953428 cast */
    /* @3953432 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3953464;
    L_3953436: ;
    /* @3953436 constant */
    /* @3953440 cast */
    /* @3953444 load */
    /* @3953452 call */
    GM_SITE(vm, 132, 3953452);
    /* @3953460 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3953464: ;
    /* @3953464 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3953436;
    /* @3953468 constant */
    /* @3953472 cast */
    /* @3953476 load */
    /* @3953484 constant */
    /* @3953488 sub */
    /* @3953492 load */
    /* @3953500 constant */
    /* @3953504 sub */
    /* @3953508 call */
    GM_SITE(vm, 132, 3953508);
    /* @3953516 store */
    v22 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v22);
    /* @3953524 load */
    /* @3953532 cast */
    /* @3953536 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3953568;
    L_3953540: ;
    /* @3953540 constant */
    /* @3953544 cast */
    /* @3953548 load */
    /* @3953556 call */
    GM_SITE(vm, 132, 3953556);
    /* @3953564 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3953568: ;
    /* @3953568 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3953540;
    /* @3953572 constant */
    /* @3953576 cast */
    /* @3953580 load */
    /* @3953588 constant */
    /* @3953592 sub */
    /* @3953596 load */
    /* @3953604 constant */
    /* @3953608 add */
    /* @3953612 call */
    GM_SITE(vm, 132, 3953612);
    v23 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3953620 store */
    v24 = GM_CALL(vm, "instance_create", 3, v23, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v24);
    /* @3953628 load */
    /* @3953636 cast */
    /* @3953640 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3953672;
    L_3953644: ;
    /* @3953644 constant */
    /* @3953648 cast */
    /* @3953652 load */
    /* @3953660 call */
    GM_SITE(vm, 132, 3953660);
    /* @3953668 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3953672: ;
    /* @3953672 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3953644;
    /* @3953676 constant */
    /* @3953680 cast */
    /* @3953684 load */
    /* @3953692 constant */
    /* @3953696 sub */
    /* @3953700 load */
    /* @3953708 constant */
    /* @3953712 sub */
    /* @3953716 call */
    GM_SITE(vm, 132, 3953716);
    /* @3953724 store */
    v25 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v25);
    /* @3953732 load */
    /* @3953740 cast */
    /* @3953744 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3953776;
    L_3953748: ;
    /* @3953748 constant */
    /* @3953752 cast */
    /* @3953756 load */
    /* @3953764 call */
    GM_SITE(vm, 132, 3953764);
    /* @3953772 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3953776: ;
    /* @3953776 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3953748;
    /* @3953780 constant */
    /* @3953784 cast */
    /* @3953788 load */
    /* @3953796 constant */
    /* @3953800 sub */
    /* @3953804 load */
    /* @3953812 constant */
    /* @3953816 sub */
    /* @3953820 call */
    GM_SITE(vm, 132, 3953820);
    /* @3953828 store */
    v26 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v26);
    /* @3953836 load */
    /* @3953844 cast */
    /* @3953848 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3953880;
    L_3953852: ;
    /* @3953852 constant */
    /* @3953856 cast */
    /* @3953860 load */
    /* @3953868 call */
    GM_SITE(vm, 132, 3953868);
    /* @3953876 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3953880: ;
    /* @3953880 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3953852;
    /* @3953884 constant */
    /* @3953888 cast */
    /* @3953892 load */
    /* @3953900 constant */
    /* @3953904 sub */
    /* @3953908 load */
    /* @3953916 constant */
    /* @3953920 add */
    /* @3953924 call */
    GM_SITE(vm, 132, 3953924);
    v27 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3953932 store */
    v28 = GM_CALL(vm, "instance_create", 3, v27, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v28);
    /* @3953940 load */
    /* @3953948 cast */
    /* @3953952 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3953984;
    L_3953956: ;
    /* @3953956 constant */
    /* @3953960 cast */
    /* @3953964 load */
    /* @3953972 call */
    GM_SITE(vm, 132, 3953972);
    /* @3953980 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3953984: ;
    /* @3953984 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3953956;
    /* @3953988 constant */
    /* @3953992 cast */
    /* @3953996 load */
    /* @3954004 constant */
    /* @3954008 sub */
    /* @3954012 load */
    /* @3954020 constant */
    /* @3954024 sub */
    /* @3954028 call */
    GM_SITE(vm, 132, 3954028);
    /* @3954036 store */
    v29 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v29);
    /* @3954044 load */
    /* @3954052 cast */
    /* @3954056 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3954088;
    L_3954060: ;
    /* @3954060 constant */
    /* @3954064 cast */
    /* @3954068 load */
    /* @3954076 call */
    GM_SITE(vm, 132, 3954076);
    /* @3954084 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3954088: ;
    /* @3954088 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3954060;
    /* @3954092 constant */
    /* @3954096 cast */
    /* @3954100 load */
    /* @3954108 constant */
    /* @3954112 sub */
    /* @3954116 load */
    /* @3954124 constant */
    /* @3954128 add */
    /* @3954132 call */
    GM_SITE(vm, 132, 3954132);
    v30 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3954140 store */
    v31 = GM_CALL(vm, "instance_create", 3, v30, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v31);
    L_3954148: ;
    /* @3954148 load */
    /* @3954156 constant */
    /* @3954160 cmp */
    /* @3954164 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(4)))) goto L_3955304;
    /* @3954168 constant */
    /* @3954172 cast */
    /* @3954176 load */
    /* @3954184 constant */
    /* @3954188 sub */
    /* @3954192 load */
    /* @3954200 call */
    GM_SITE(vm, 132, 3954200);
    /* @3954208 store */
    v32 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v32);
    /* @3954216 load */
    /* @3954224 cast */
    /* @3954228 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3954260;
    L_3954232: ;
    /* @3954232 constant */
    /* @3954236 cast */
    /* @3954240 load */
    /* @3954248 call */
    GM_SITE(vm, 132, 3954248);
    /* @3954256 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3954260: ;
    /* @3954260 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3954232;
    /* @3954264 constant */
    /* @3954268 cast */
    /* @3954272 load */
    /* @3954280 constant */
    /* @3954284 sub */
    /* @3954288 load */
    /* @3954296 constant */
    /* @3954300 add */
    /* @3954304 call */
    GM_SITE(vm, 132, 3954304);
    v33 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3954312 store */
    v34 = GM_CALL(vm, "instance_create", 3, v33, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v34);
    /* @3954320 load */
    /* @3954328 cast */
    /* @3954332 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3954364;
    L_3954336: ;
    /* @3954336 constant */
    /* @3954340 cast */
    /* @3954344 load */
    /* @3954352 call */
    GM_SITE(vm, 132, 3954352);
    /* @3954360 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3954364: ;
    /* @3954364 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3954336;
    /* @3954368 constant */
    /* @3954372 cast */
    /* @3954376 load */
    /* @3954384 constant */
    /* @3954388 sub */
    /* @3954392 load */
    /* @3954400 constant */
    /* @3954404 sub */
    /* @3954408 call */
    GM_SITE(vm, 132, 3954408);
    /* @3954416 store */
    v35 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v35);
    /* @3954424 load */
    /* @3954432 cast */
    /* @3954436 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3954468;
    L_3954440: ;
    /* @3954440 constant */
    /* @3954444 cast */
    /* @3954448 load */
    /* @3954456 call */
    GM_SITE(vm, 132, 3954456);
    /* @3954464 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3954468: ;
    /* @3954468 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3954440;
    /* @3954472 constant */
    /* @3954476 cast */
    /* @3954480 load */
    /* @3954488 constant */
    /* @3954492 sub */
    /* @3954496 load */
    /* @3954504 constant */
    /* @3954508 add */
    /* @3954512 call */
    GM_SITE(vm, 132, 3954512);
    v36 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3954520 store */
    v37 = GM_CALL(vm, "instance_create", 3, v36, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v37);
    /* @3954528 load */
    /* @3954536 cast */
    /* @3954540 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3954572;
    L_3954544: ;
    /* @3954544 constant */
    /* @3954548 cast */
    /* @3954552 load */
    /* @3954560 call */
    GM_SITE(vm, 132, 3954560);
    /* @3954568 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3954572: ;
    /* @3954572 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3954544;
    /* @3954576 constant */
    /* @3954580 cast */
    /* @3954584 load */
    /* @3954592 constant */
    /* @3954596 sub */
    /* @3954600 load */
    /* @3954608 constant */
    /* @3954612 sub */
    /* @3954616 call */
    GM_SITE(vm, 132, 3954616);
    /* @3954624 store */
    v38 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v38);
    /* @3954632 load */
    /* @3954640 cast */
    /* @3954644 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3954676;
    L_3954648: ;
    /* @3954648 constant */
    /* @3954652 cast */
    /* @3954656 load */
    /* @3954664 call */
    GM_SITE(vm, 132, 3954664);
    /* @3954672 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3954676: ;
    /* @3954676 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3954648;
    /* @3954680 constant */
    /* @3954684 cast */
    /* @3954688 load */
    /* @3954696 constant */
    /* @3954700 sub */
    /* @3954704 load */
    /* @3954712 constant */
    /* @3954716 add */
    /* @3954720 call */
    GM_SITE(vm, 132, 3954720);
    v39 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @3954728 store */
    v40 = GM_CALL(vm, "instance_create", 3, v39, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v40);
    /* @3954736 load */
    /* @3954744 cast */
    /* @3954748 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3954780;
    L_3954752: ;
    /* @3954752 constant */
    /* @3954756 cast */
    /* @3954760 load */
    /* @3954768 call */
    GM_SITE(vm, 132, 3954768);
    /* @3954776 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3954780: ;
    /* @3954780 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3954752;
    /* @3954784 constant */
    /* @3954788 cast */
    /* @3954792 load */
    /* @3954800 constant */
    /* @3954804 sub */
    /* @3954808 load */
    /* @3954816 constant */
    /* @3954820 add */
    /* @3954824 call */
    GM_SITE(vm, 132, 3954824);
    v41 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3954832 store */
    v42 = GM_CALL(vm, "instance_create", 3, v41, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v42);
    /* @3954840 load */
    /* @3954848 cast */
    /* @3954852 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3954884;
    L_3954856: ;
    /* @3954856 constant */
    /* @3954860 cast */
    /* @3954864 load */
    /* @3954872 call */
    GM_SITE(vm, 132, 3954872);
    /* @3954880 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3954884: ;
    /* @3954884 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3954856;
    /* @3954888 constant */
    /* @3954892 cast */
    /* @3954896 load */
    /* @3954904 constant */
    /* @3954908 sub */
    /* @3954912 load */
    /* @3954920 constant */
    /* @3954924 sub */
    /* @3954928 call */
    GM_SITE(vm, 132, 3954928);
    /* @3954936 store */
    v43 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v43);
    /* @3954944 load */
    /* @3954952 cast */
    /* @3954956 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3954988;
    L_3954960: ;
    /* @3954960 constant */
    /* @3954964 cast */
    /* @3954968 load */
    /* @3954976 call */
    GM_SITE(vm, 132, 3954976);
    /* @3954984 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3954988: ;
    /* @3954988 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3954960;
    /* @3954992 constant */
    /* @3954996 cast */
    /* @3955000 load */
    /* @3955008 constant */
    /* @3955012 sub */
    /* @3955016 load */
    /* @3955024 constant */
    /* @3955028 add */
    /* @3955032 call */
    GM_SITE(vm, 132, 3955032);
    v44 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3955040 store */
    v45 = GM_CALL(vm, "instance_create", 3, v44, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v45);
    /* @3955048 load */
    /* @3955056 cast */
    /* @3955060 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3955092;
    L_3955064: ;
    /* @3955064 constant */
    /* @3955068 cast */
    /* @3955072 load */
    /* @3955080 call */
    GM_SITE(vm, 132, 3955080);
    /* @3955088 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3955092: ;
    /* @3955092 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3955064;
    /* @3955096 constant */
    /* @3955100 cast */
    /* @3955104 load */
    /* @3955112 constant */
    /* @3955116 sub */
    /* @3955120 load */
    /* @3955128 constant */
    /* @3955132 sub */
    /* @3955136 call */
    GM_SITE(vm, 132, 3955136);
    /* @3955144 store */
    v46 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v46);
    /* @3955152 load */
    /* @3955160 cast */
    /* @3955164 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3955196;
    L_3955168: ;
    /* @3955168 constant */
    /* @3955172 cast */
    /* @3955176 load */
    /* @3955184 call */
    GM_SITE(vm, 132, 3955184);
    /* @3955192 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_3955196: ;
    /* @3955196 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3955168;
    /* @3955200 constant */
    /* @3955204 cast */
    /* @3955208 load */
    /* @3955216 constant */
    /* @3955220 sub */
    /* @3955224 load */
    /* @3955232 constant */
    /* @3955236 sub */
    /* @3955240 call */
    GM_SITE(vm, 132, 3955240);
    /* @3955248 store */
    v47 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v47);
    /* @3955256 load */
    /* @3955264 cast */
    /* @3955268 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_3955300;
    L_3955272: ;
    /* @3955272 constant */
    /* @3955276 cast */
    /* @3955280 load */
    /* @3955288 call */
    GM_SITE(vm, 132, 3955288);
    /* @3955296 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_3955300: ;
    /* @3955300 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3955272;
    L_3955304: ;
    /* @3955304 load */
    /* @3955312 constant */
    /* @3955316 cmp */
    /* @3955320 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(5)))) goto L_3956356;
    /* @3955324 constant */
    /* @3955328 cast */
    /* @3955332 load */
    /* @3955340 constant */
    /* @3955344 sub */
    /* @3955348 load */
    /* @3955356 call */
    GM_SITE(vm, 132, 3955356);
    /* @3955364 store */
    v48 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v48);
    /* @3955372 load */
    /* @3955380 cast */
    /* @3955384 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3955416;
    L_3955388: ;
    /* @3955388 constant */
    /* @3955392 cast */
    /* @3955396 load */
    /* @3955404 call */
    GM_SITE(vm, 132, 3955404);
    /* @3955412 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3955416: ;
    /* @3955416 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3955388;
    /* @3955420 constant */
    /* @3955424 cast */
    /* @3955428 load */
    /* @3955436 constant */
    /* @3955440 sub */
    /* @3955444 load */
    /* @3955452 constant */
    /* @3955456 add */
    /* @3955460 call */
    GM_SITE(vm, 132, 3955460);
    v49 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3955468 store */
    v50 = GM_CALL(vm, "instance_create", 3, v49, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v50);
    /* @3955476 load */
    /* @3955484 cast */
    /* @3955488 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3955520;
    L_3955492: ;
    /* @3955492 constant */
    /* @3955496 cast */
    /* @3955500 load */
    /* @3955508 call */
    GM_SITE(vm, 132, 3955508);
    /* @3955516 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3955520: ;
    /* @3955520 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3955492;
    /* @3955524 constant */
    /* @3955528 cast */
    /* @3955532 load */
    /* @3955540 constant */
    /* @3955544 sub */
    /* @3955548 load */
    /* @3955556 constant */
    /* @3955560 sub */
    /* @3955564 call */
    GM_SITE(vm, 132, 3955564);
    /* @3955572 store */
    v51 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v51);
    /* @3955580 load */
    /* @3955588 cast */
    /* @3955592 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3955624;
    L_3955596: ;
    /* @3955596 constant */
    /* @3955600 cast */
    /* @3955604 load */
    /* @3955612 call */
    GM_SITE(vm, 132, 3955612);
    /* @3955620 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3955624: ;
    /* @3955624 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3955596;
    /* @3955628 constant */
    /* @3955632 cast */
    /* @3955636 load */
    /* @3955644 constant */
    /* @3955648 sub */
    /* @3955652 load */
    /* @3955660 constant */
    /* @3955664 add */
    /* @3955668 call */
    GM_SITE(vm, 132, 3955668);
    v52 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3955676 store */
    v53 = GM_CALL(vm, "instance_create", 3, v52, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v53);
    /* @3955684 load */
    /* @3955692 cast */
    /* @3955696 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3955728;
    L_3955700: ;
    /* @3955700 constant */
    /* @3955704 cast */
    /* @3955708 load */
    /* @3955716 call */
    GM_SITE(vm, 132, 3955716);
    /* @3955724 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3955728: ;
    /* @3955728 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3955700;
    /* @3955732 constant */
    /* @3955736 cast */
    /* @3955740 load */
    /* @3955748 constant */
    /* @3955752 sub */
    /* @3955756 load */
    /* @3955764 constant */
    /* @3955768 sub */
    /* @3955772 call */
    GM_SITE(vm, 132, 3955772);
    /* @3955780 store */
    v54 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v54);
    /* @3955788 load */
    /* @3955796 cast */
    /* @3955800 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3955832;
    L_3955804: ;
    /* @3955804 constant */
    /* @3955808 cast */
    /* @3955812 load */
    /* @3955820 call */
    GM_SITE(vm, 132, 3955820);
    /* @3955828 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3955832: ;
    /* @3955832 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3955804;
    /* @3955836 constant */
    /* @3955840 cast */
    /* @3955844 load */
    /* @3955852 constant */
    /* @3955856 sub */
    /* @3955860 load */
    /* @3955868 constant */
    /* @3955872 add */
    /* @3955876 call */
    GM_SITE(vm, 132, 3955876);
    v55 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @3955884 store */
    v56 = GM_CALL(vm, "instance_create", 3, v55, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v56);
    /* @3955892 load */
    /* @3955900 cast */
    /* @3955904 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3955936;
    L_3955908: ;
    /* @3955908 constant */
    /* @3955912 cast */
    /* @3955916 load */
    /* @3955924 call */
    GM_SITE(vm, 132, 3955924);
    /* @3955932 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3955936: ;
    /* @3955936 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3955908;
    /* @3955940 constant */
    /* @3955944 cast */
    /* @3955948 load */
    /* @3955956 constant */
    /* @3955960 sub */
    /* @3955964 load */
    /* @3955972 constant */
    /* @3955976 add */
    /* @3955980 call */
    GM_SITE(vm, 132, 3955980);
    v57 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3955988 store */
    v58 = GM_CALL(vm, "instance_create", 3, v57, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v58);
    /* @3955996 load */
    /* @3956004 cast */
    /* @3956008 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3956040;
    L_3956012: ;
    /* @3956012 constant */
    /* @3956016 cast */
    /* @3956020 load */
    /* @3956028 call */
    GM_SITE(vm, 132, 3956028);
    /* @3956036 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3956040: ;
    /* @3956040 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3956012;
    /* @3956044 constant */
    /* @3956048 cast */
    /* @3956052 load */
    /* @3956060 constant */
    /* @3956064 sub */
    /* @3956068 load */
    /* @3956076 constant */
    /* @3956080 sub */
    /* @3956084 call */
    GM_SITE(vm, 132, 3956084);
    /* @3956092 store */
    v59 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v59);
    /* @3956100 load */
    /* @3956108 cast */
    /* @3956112 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3956144;
    L_3956116: ;
    /* @3956116 constant */
    /* @3956120 cast */
    /* @3956124 load */
    /* @3956132 call */
    GM_SITE(vm, 132, 3956132);
    /* @3956140 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3956144: ;
    /* @3956144 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3956116;
    /* @3956148 constant */
    /* @3956152 cast */
    /* @3956156 load */
    /* @3956164 constant */
    /* @3956168 sub */
    /* @3956172 load */
    /* @3956180 constant */
    /* @3956184 add */
    /* @3956188 call */
    GM_SITE(vm, 132, 3956188);
    v60 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3956196 store */
    v61 = GM_CALL(vm, "instance_create", 3, v60, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v61);
    /* @3956204 load */
    /* @3956212 cast */
    /* @3956216 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3956248;
    L_3956220: ;
    /* @3956220 constant */
    /* @3956224 cast */
    /* @3956228 load */
    /* @3956236 call */
    GM_SITE(vm, 132, 3956236);
    /* @3956244 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3956248: ;
    /* @3956248 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3956220;
    /* @3956252 constant */
    /* @3956256 cast */
    /* @3956260 load */
    /* @3956268 constant */
    /* @3956272 sub */
    /* @3956276 load */
    /* @3956284 constant */
    /* @3956288 sub */
    /* @3956292 call */
    GM_SITE(vm, 132, 3956292);
    /* @3956300 store */
    v62 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v62);
    /* @3956308 load */
    /* @3956316 cast */
    /* @3956320 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3956352;
    L_3956324: ;
    /* @3956324 constant */
    /* @3956328 cast */
    /* @3956332 load */
    /* @3956340 call */
    GM_SITE(vm, 132, 3956340);
    /* @3956348 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_3956352: ;
    /* @3956352 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3956324;
    L_3956356: ;
    /* @3956356 call */
    GM_SITE(vm, 132, 3956356);
    /* @3956364 popz */
    (void)(GM_CALL(vm, "action_kill_object", 0));
    L_3956368: ;
    return;
}
