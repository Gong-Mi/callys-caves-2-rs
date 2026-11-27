/* generated from CODE 120 (gml_Object_obj_hulkingbandit_Alarm_0), source start 3943584, end 3948200. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0120(GmVM* vm) {
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
    /* @3943584 load */
    /* @3943592 constant */
    /* @3943596 cmp */
    /* @3943600 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3943608;
    /* @3943604 b */
    goto L_3943664;
    L_3943608: ;
    /* @3943608 load */
    /* @3943616 constant */
    /* @3943620 cmp */
    /* @3943624 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3943664;
    /* @3943628 constant */
    /* @3943632 cast */
    /* @3943636 constant */
    /* @3943640 cast */
    /* @3943644 constant */
    /* @3943648 cast */
    /* @3943652 call */
    GM_SITE(vm, 120, 3943652);
    /* @3943660 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(7), VAL(0), VAL(0)));
    L_3943664: ;
    /* @3943664 load */
    /* @3943672 constant */
    /* @3943676 cmp */
    /* @3943680 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "gemdropenabled") == VAL(1)))) goto L_3943728;
    /* @3943684 constant */
    /* @3943688 cast */
    /* @3943692 load */
    /* @3943700 constant */
    /* @3943704 sub */
    /* @3943708 load */
    /* @3943716 call */
    GM_SITE(vm, 120, 3943716);
    /* @3943724 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(59)));
    L_3943728: ;
    /* @3943728 load */
    /* @3943736 constant */
    /* @3943740 cmp */
    /* @3943744 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpdrop") == VAL(1)))) goto L_3943792;
    /* @3943748 constant */
    /* @3943752 cast */
    /* @3943756 load */
    /* @3943764 constant */
    /* @3943768 sub */
    /* @3943772 load */
    /* @3943780 call */
    GM_SITE(vm, 120, 3943780);
    /* @3943788 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(62)));
    L_3943792: ;
    /* @3943792 load */
    /* @3943800 constant */
    /* @3943804 cmp */
    /* @3943808 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "xpdrop") == VAL(1)))) goto L_3943908;
    /* @3943812 constant */
    /* @3943816 cast */
    /* @3943820 load */
    /* @3943828 constant */
    /* @3943832 sub */
    /* @3943836 load */
    /* @3943844 call */
    GM_SITE(vm, 120, 3943844);
    /* @3943852 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID", v1);
    /* @3943860 load */
    /* @3943868 cast */
    /* @3943872 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3943904;
    L_3943876: ;
    /* @3943876 constant */
    /* @3943880 cast */
    /* @3943884 load */
    /* @3943892 call */
    GM_SITE(vm, 120, 3943892);
    /* @3943900 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "xpspread"), VAL(5)));
    L_3943904: ;
    /* @3943904 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3943876;
    L_3943908: ;
    /* @3943908 constant */
    /* @3943912 cast */
    /* @3943916 call */
    GM_SITE(vm, 120, 3943916);
    /* @3943924 constant */
    /* @3943928 cmp */
    /* @3943932 bf */
    v2 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) >= VAL(20));
    if (!TRUTH(v2)) goto L_3943940;
    /* @3943936 b */
    goto L_3948188;
    L_3943940: ;
    /* @3943940 constant */
    /* @3943944 cast */
    /* @3943948 call */
    GM_SITE(vm, 120, 3943948);
    /* @3943956 constant */
    /* @3943960 cmp */
    /* @3943964 bf */
    v3 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) < VAL(20));
    if (!TRUTH(v3)) goto L_3948188;
    /* @3943968 load */
    /* @3943976 constant */
    /* @3943980 cmp */
    /* @3943984 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(1)))) goto L_3944500;
    /* @3943988 constant */
    /* @3943992 cast */
    /* @3943996 load */
    /* @3944004 constant */
    /* @3944008 sub */
    /* @3944012 load */
    /* @3944020 call */
    GM_SITE(vm, 120, 3944020);
    /* @3944028 store */
    v4 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v4);
    /* @3944036 load */
    /* @3944044 cast */
    /* @3944048 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3944080;
    L_3944052: ;
    /* @3944052 constant */
    /* @3944056 cast */
    /* @3944060 load */
    /* @3944068 call */
    GM_SITE(vm, 120, 3944068);
    /* @3944076 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3944080: ;
    /* @3944080 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3944052;
    /* @3944084 constant */
    /* @3944088 cast */
    /* @3944092 load */
    /* @3944100 constant */
    /* @3944104 sub */
    /* @3944108 load */
    /* @3944116 constant */
    /* @3944120 add */
    /* @3944124 call */
    GM_SITE(vm, 120, 3944124);
    v5 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3944132 store */
    v6 = GM_CALL(vm, "instance_create", 3, v5, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v6);
    /* @3944140 load */
    /* @3944148 cast */
    /* @3944152 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3944184;
    L_3944156: ;
    /* @3944156 constant */
    /* @3944160 cast */
    /* @3944164 load */
    /* @3944172 call */
    GM_SITE(vm, 120, 3944172);
    /* @3944180 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3944184: ;
    /* @3944184 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3944156;
    /* @3944188 constant */
    /* @3944192 cast */
    /* @3944196 load */
    /* @3944204 constant */
    /* @3944208 sub */
    /* @3944212 load */
    /* @3944220 constant */
    /* @3944224 sub */
    /* @3944228 call */
    GM_SITE(vm, 120, 3944228);
    /* @3944236 store */
    v7 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v7);
    /* @3944244 load */
    /* @3944252 cast */
    /* @3944256 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3944288;
    L_3944260: ;
    /* @3944260 constant */
    /* @3944264 cast */
    /* @3944268 load */
    /* @3944276 call */
    GM_SITE(vm, 120, 3944276);
    /* @3944284 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3944288: ;
    /* @3944288 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3944260;
    /* @3944292 constant */
    /* @3944296 cast */
    /* @3944300 load */
    /* @3944308 constant */
    /* @3944312 sub */
    /* @3944316 load */
    /* @3944324 constant */
    /* @3944328 add */
    /* @3944332 call */
    GM_SITE(vm, 120, 3944332);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3944340 store */
    v9 = GM_CALL(vm, "instance_create", 3, v8, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v9);
    /* @3944348 load */
    /* @3944356 cast */
    /* @3944360 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3944392;
    L_3944364: ;
    /* @3944364 constant */
    /* @3944368 cast */
    /* @3944372 load */
    /* @3944380 call */
    GM_SITE(vm, 120, 3944380);
    /* @3944388 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3944392: ;
    /* @3944392 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3944364;
    /* @3944396 constant */
    /* @3944400 cast */
    /* @3944404 load */
    /* @3944412 constant */
    /* @3944416 sub */
    /* @3944420 load */
    /* @3944428 constant */
    /* @3944432 sub */
    /* @3944436 call */
    GM_SITE(vm, 120, 3944436);
    /* @3944444 store */
    v10 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v10);
    /* @3944452 load */
    /* @3944460 cast */
    /* @3944464 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3944496;
    L_3944468: ;
    /* @3944468 constant */
    /* @3944472 cast */
    /* @3944476 load */
    /* @3944484 call */
    GM_SITE(vm, 120, 3944484);
    /* @3944492 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3944496: ;
    /* @3944496 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3944468;
    L_3944500: ;
    /* @3944500 load */
    /* @3944508 constant */
    /* @3944512 cmp */
    /* @3944516 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(2)))) goto L_3945240;
    /* @3944520 constant */
    /* @3944524 cast */
    /* @3944528 load */
    /* @3944536 constant */
    /* @3944540 sub */
    /* @3944544 load */
    /* @3944552 call */
    GM_SITE(vm, 120, 3944552);
    /* @3944560 store */
    v11 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v11);
    /* @3944568 load */
    /* @3944576 cast */
    /* @3944580 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3944612;
    L_3944584: ;
    /* @3944584 constant */
    /* @3944588 cast */
    /* @3944592 load */
    /* @3944600 call */
    GM_SITE(vm, 120, 3944600);
    /* @3944608 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3944612: ;
    /* @3944612 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3944584;
    /* @3944616 constant */
    /* @3944620 cast */
    /* @3944624 load */
    /* @3944632 constant */
    /* @3944636 sub */
    /* @3944640 load */
    /* @3944648 constant */
    /* @3944652 add */
    /* @3944656 call */
    GM_SITE(vm, 120, 3944656);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3944664 store */
    v13 = GM_CALL(vm, "instance_create", 3, v12, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v13);
    /* @3944672 load */
    /* @3944680 cast */
    /* @3944684 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3944716;
    L_3944688: ;
    /* @3944688 constant */
    /* @3944692 cast */
    /* @3944696 load */
    /* @3944704 call */
    GM_SITE(vm, 120, 3944704);
    /* @3944712 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3944716: ;
    /* @3944716 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3944688;
    /* @3944720 constant */
    /* @3944724 cast */
    /* @3944728 load */
    /* @3944736 constant */
    /* @3944740 sub */
    /* @3944744 load */
    /* @3944752 constant */
    /* @3944756 sub */
    /* @3944760 call */
    GM_SITE(vm, 120, 3944760);
    /* @3944768 store */
    v14 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v14);
    /* @3944776 load */
    /* @3944784 cast */
    /* @3944788 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3944820;
    L_3944792: ;
    /* @3944792 constant */
    /* @3944796 cast */
    /* @3944800 load */
    /* @3944808 call */
    GM_SITE(vm, 120, 3944808);
    /* @3944816 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3944820: ;
    /* @3944820 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3944792;
    /* @3944824 constant */
    /* @3944828 cast */
    /* @3944832 load */
    /* @3944840 constant */
    /* @3944844 sub */
    /* @3944848 load */
    /* @3944856 constant */
    /* @3944860 add */
    /* @3944864 call */
    GM_SITE(vm, 120, 3944864);
    v15 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3944872 store */
    v16 = GM_CALL(vm, "instance_create", 3, v15, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v16);
    /* @3944880 load */
    /* @3944888 cast */
    /* @3944892 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3944924;
    L_3944896: ;
    /* @3944896 constant */
    /* @3944900 cast */
    /* @3944904 load */
    /* @3944912 call */
    GM_SITE(vm, 120, 3944912);
    /* @3944920 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3944924: ;
    /* @3944924 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3944896;
    /* @3944928 constant */
    /* @3944932 cast */
    /* @3944936 load */
    /* @3944944 constant */
    /* @3944948 sub */
    /* @3944952 load */
    /* @3944960 constant */
    /* @3944964 sub */
    /* @3944968 call */
    GM_SITE(vm, 120, 3944968);
    /* @3944976 store */
    v17 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v17);
    /* @3944984 load */
    /* @3944992 cast */
    /* @3944996 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3945028;
    L_3945000: ;
    /* @3945000 constant */
    /* @3945004 cast */
    /* @3945008 load */
    /* @3945016 call */
    GM_SITE(vm, 120, 3945016);
    /* @3945024 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3945028: ;
    /* @3945028 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3945000;
    /* @3945032 constant */
    /* @3945036 cast */
    /* @3945040 load */
    /* @3945048 constant */
    /* @3945052 sub */
    /* @3945056 load */
    /* @3945064 constant */
    /* @3945068 sub */
    /* @3945072 call */
    GM_SITE(vm, 120, 3945072);
    /* @3945080 store */
    v18 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v18);
    /* @3945088 load */
    /* @3945096 cast */
    /* @3945100 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3945132;
    L_3945104: ;
    /* @3945104 constant */
    /* @3945108 cast */
    /* @3945112 load */
    /* @3945120 call */
    GM_SITE(vm, 120, 3945120);
    /* @3945128 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3945132: ;
    /* @3945132 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3945104;
    /* @3945136 constant */
    /* @3945140 cast */
    /* @3945144 load */
    /* @3945152 constant */
    /* @3945156 sub */
    /* @3945160 load */
    /* @3945168 constant */
    /* @3945172 add */
    /* @3945176 call */
    GM_SITE(vm, 120, 3945176);
    v19 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3945184 store */
    v20 = GM_CALL(vm, "instance_create", 3, v19, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v20);
    /* @3945192 load */
    /* @3945200 cast */
    /* @3945204 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3945236;
    L_3945208: ;
    /* @3945208 constant */
    /* @3945212 cast */
    /* @3945216 load */
    /* @3945224 call */
    GM_SITE(vm, 120, 3945224);
    /* @3945232 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3945236: ;
    /* @3945236 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3945208;
    L_3945240: ;
    /* @3945240 load */
    /* @3945248 constant */
    /* @3945252 cmp */
    /* @3945256 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(3)))) goto L_3946084;
    /* @3945260 constant */
    /* @3945264 cast */
    /* @3945268 load */
    /* @3945276 constant */
    /* @3945280 sub */
    /* @3945284 load */
    /* @3945292 call */
    GM_SITE(vm, 120, 3945292);
    /* @3945300 store */
    v21 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v21);
    /* @3945308 load */
    /* @3945316 cast */
    /* @3945320 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3945352;
    L_3945324: ;
    /* @3945324 constant */
    /* @3945328 cast */
    /* @3945332 load */
    /* @3945340 call */
    GM_SITE(vm, 120, 3945340);
    /* @3945348 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3945352: ;
    /* @3945352 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3945324;
    /* @3945356 constant */
    /* @3945360 cast */
    /* @3945364 load */
    /* @3945372 constant */
    /* @3945376 sub */
    /* @3945380 load */
    /* @3945388 constant */
    /* @3945392 add */
    /* @3945396 call */
    GM_SITE(vm, 120, 3945396);
    v22 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3945404 store */
    v23 = GM_CALL(vm, "instance_create", 3, v22, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v23);
    /* @3945412 load */
    /* @3945420 cast */
    /* @3945424 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3945456;
    L_3945428: ;
    /* @3945428 constant */
    /* @3945432 cast */
    /* @3945436 load */
    /* @3945444 call */
    GM_SITE(vm, 120, 3945444);
    /* @3945452 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3945456: ;
    /* @3945456 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3945428;
    /* @3945460 constant */
    /* @3945464 cast */
    /* @3945468 load */
    /* @3945476 constant */
    /* @3945480 sub */
    /* @3945484 load */
    /* @3945492 constant */
    /* @3945496 sub */
    /* @3945500 call */
    GM_SITE(vm, 120, 3945500);
    /* @3945508 store */
    v24 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v24);
    /* @3945516 load */
    /* @3945524 cast */
    /* @3945528 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3945560;
    L_3945532: ;
    /* @3945532 constant */
    /* @3945536 cast */
    /* @3945540 load */
    /* @3945548 call */
    GM_SITE(vm, 120, 3945548);
    /* @3945556 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3945560: ;
    /* @3945560 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3945532;
    /* @3945564 constant */
    /* @3945568 cast */
    /* @3945572 load */
    /* @3945580 constant */
    /* @3945584 sub */
    /* @3945588 load */
    /* @3945596 constant */
    /* @3945600 add */
    /* @3945604 call */
    GM_SITE(vm, 120, 3945604);
    v25 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3945612 store */
    v26 = GM_CALL(vm, "instance_create", 3, v25, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v26);
    /* @3945620 load */
    /* @3945628 cast */
    /* @3945632 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3945664;
    L_3945636: ;
    /* @3945636 constant */
    /* @3945640 cast */
    /* @3945644 load */
    /* @3945652 call */
    GM_SITE(vm, 120, 3945652);
    /* @3945660 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3945664: ;
    /* @3945664 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3945636;
    /* @3945668 constant */
    /* @3945672 cast */
    /* @3945676 load */
    /* @3945684 constant */
    /* @3945688 sub */
    /* @3945692 load */
    /* @3945700 constant */
    /* @3945704 sub */
    /* @3945708 call */
    GM_SITE(vm, 120, 3945708);
    /* @3945716 store */
    v27 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v27);
    /* @3945724 load */
    /* @3945732 cast */
    /* @3945736 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3945768;
    L_3945740: ;
    /* @3945740 constant */
    /* @3945744 cast */
    /* @3945748 load */
    /* @3945756 call */
    GM_SITE(vm, 120, 3945756);
    /* @3945764 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3945768: ;
    /* @3945768 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3945740;
    /* @3945772 constant */
    /* @3945776 cast */
    /* @3945780 load */
    /* @3945788 constant */
    /* @3945792 sub */
    /* @3945796 load */
    /* @3945804 constant */
    /* @3945808 sub */
    /* @3945812 call */
    GM_SITE(vm, 120, 3945812);
    /* @3945820 store */
    v28 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v28);
    /* @3945828 load */
    /* @3945836 cast */
    /* @3945840 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3945872;
    L_3945844: ;
    /* @3945844 constant */
    /* @3945848 cast */
    /* @3945852 load */
    /* @3945860 call */
    GM_SITE(vm, 120, 3945860);
    /* @3945868 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3945872: ;
    /* @3945872 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3945844;
    /* @3945876 constant */
    /* @3945880 cast */
    /* @3945884 load */
    /* @3945892 constant */
    /* @3945896 sub */
    /* @3945900 load */
    /* @3945908 constant */
    /* @3945912 add */
    /* @3945916 call */
    GM_SITE(vm, 120, 3945916);
    v29 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3945924 store */
    v30 = GM_CALL(vm, "instance_create", 3, v29, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v30);
    /* @3945932 load */
    /* @3945940 cast */
    /* @3945944 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3945976;
    L_3945948: ;
    /* @3945948 constant */
    /* @3945952 cast */
    /* @3945956 load */
    /* @3945964 call */
    GM_SITE(vm, 120, 3945964);
    /* @3945972 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3945976: ;
    /* @3945976 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3945948;
    /* @3945980 constant */
    /* @3945984 cast */
    /* @3945988 load */
    /* @3945996 constant */
    /* @3946000 sub */
    /* @3946004 load */
    /* @3946012 constant */
    /* @3946016 sub */
    /* @3946020 call */
    GM_SITE(vm, 120, 3946020);
    /* @3946028 store */
    v31 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v31);
    /* @3946036 load */
    /* @3946044 cast */
    /* @3946048 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3946080;
    L_3946052: ;
    /* @3946052 constant */
    /* @3946056 cast */
    /* @3946060 load */
    /* @3946068 call */
    GM_SITE(vm, 120, 3946068);
    /* @3946076 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3946080: ;
    /* @3946080 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3946052;
    L_3946084: ;
    /* @3946084 load */
    /* @3946092 constant */
    /* @3946096 cmp */
    /* @3946100 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(4)))) goto L_3947240;
    /* @3946104 constant */
    /* @3946108 cast */
    /* @3946112 load */
    /* @3946120 constant */
    /* @3946124 sub */
    /* @3946128 load */
    /* @3946136 call */
    GM_SITE(vm, 120, 3946136);
    /* @3946144 store */
    v32 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v32);
    /* @3946152 load */
    /* @3946160 cast */
    /* @3946164 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3946196;
    L_3946168: ;
    /* @3946168 constant */
    /* @3946172 cast */
    /* @3946176 load */
    /* @3946184 call */
    GM_SITE(vm, 120, 3946184);
    /* @3946192 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3946196: ;
    /* @3946196 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3946168;
    /* @3946200 constant */
    /* @3946204 cast */
    /* @3946208 load */
    /* @3946216 constant */
    /* @3946220 sub */
    /* @3946224 load */
    /* @3946232 constant */
    /* @3946236 add */
    /* @3946240 call */
    GM_SITE(vm, 120, 3946240);
    v33 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3946248 store */
    v34 = GM_CALL(vm, "instance_create", 3, v33, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v34);
    /* @3946256 load */
    /* @3946264 cast */
    /* @3946268 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3946300;
    L_3946272: ;
    /* @3946272 constant */
    /* @3946276 cast */
    /* @3946280 load */
    /* @3946288 call */
    GM_SITE(vm, 120, 3946288);
    /* @3946296 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3946300: ;
    /* @3946300 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3946272;
    /* @3946304 constant */
    /* @3946308 cast */
    /* @3946312 load */
    /* @3946320 constant */
    /* @3946324 sub */
    /* @3946328 load */
    /* @3946336 constant */
    /* @3946340 sub */
    /* @3946344 call */
    GM_SITE(vm, 120, 3946344);
    /* @3946352 store */
    v35 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v35);
    /* @3946360 load */
    /* @3946368 cast */
    /* @3946372 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3946404;
    L_3946376: ;
    /* @3946376 constant */
    /* @3946380 cast */
    /* @3946384 load */
    /* @3946392 call */
    GM_SITE(vm, 120, 3946392);
    /* @3946400 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3946404: ;
    /* @3946404 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3946376;
    /* @3946408 constant */
    /* @3946412 cast */
    /* @3946416 load */
    /* @3946424 constant */
    /* @3946428 sub */
    /* @3946432 load */
    /* @3946440 constant */
    /* @3946444 add */
    /* @3946448 call */
    GM_SITE(vm, 120, 3946448);
    v36 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3946456 store */
    v37 = GM_CALL(vm, "instance_create", 3, v36, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v37);
    /* @3946464 load */
    /* @3946472 cast */
    /* @3946476 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3946508;
    L_3946480: ;
    /* @3946480 constant */
    /* @3946484 cast */
    /* @3946488 load */
    /* @3946496 call */
    GM_SITE(vm, 120, 3946496);
    /* @3946504 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3946508: ;
    /* @3946508 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3946480;
    /* @3946512 constant */
    /* @3946516 cast */
    /* @3946520 load */
    /* @3946528 constant */
    /* @3946532 sub */
    /* @3946536 load */
    /* @3946544 constant */
    /* @3946548 sub */
    /* @3946552 call */
    GM_SITE(vm, 120, 3946552);
    /* @3946560 store */
    v38 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v38);
    /* @3946568 load */
    /* @3946576 cast */
    /* @3946580 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3946612;
    L_3946584: ;
    /* @3946584 constant */
    /* @3946588 cast */
    /* @3946592 load */
    /* @3946600 call */
    GM_SITE(vm, 120, 3946600);
    /* @3946608 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3946612: ;
    /* @3946612 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3946584;
    /* @3946616 constant */
    /* @3946620 cast */
    /* @3946624 load */
    /* @3946632 constant */
    /* @3946636 sub */
    /* @3946640 load */
    /* @3946648 constant */
    /* @3946652 add */
    /* @3946656 call */
    GM_SITE(vm, 120, 3946656);
    v39 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @3946664 store */
    v40 = GM_CALL(vm, "instance_create", 3, v39, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v40);
    /* @3946672 load */
    /* @3946680 cast */
    /* @3946684 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3946716;
    L_3946688: ;
    /* @3946688 constant */
    /* @3946692 cast */
    /* @3946696 load */
    /* @3946704 call */
    GM_SITE(vm, 120, 3946704);
    /* @3946712 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3946716: ;
    /* @3946716 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3946688;
    /* @3946720 constant */
    /* @3946724 cast */
    /* @3946728 load */
    /* @3946736 constant */
    /* @3946740 sub */
    /* @3946744 load */
    /* @3946752 constant */
    /* @3946756 add */
    /* @3946760 call */
    GM_SITE(vm, 120, 3946760);
    v41 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3946768 store */
    v42 = GM_CALL(vm, "instance_create", 3, v41, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v42);
    /* @3946776 load */
    /* @3946784 cast */
    /* @3946788 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3946820;
    L_3946792: ;
    /* @3946792 constant */
    /* @3946796 cast */
    /* @3946800 load */
    /* @3946808 call */
    GM_SITE(vm, 120, 3946808);
    /* @3946816 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3946820: ;
    /* @3946820 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3946792;
    /* @3946824 constant */
    /* @3946828 cast */
    /* @3946832 load */
    /* @3946840 constant */
    /* @3946844 sub */
    /* @3946848 load */
    /* @3946856 constant */
    /* @3946860 sub */
    /* @3946864 call */
    GM_SITE(vm, 120, 3946864);
    /* @3946872 store */
    v43 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v43);
    /* @3946880 load */
    /* @3946888 cast */
    /* @3946892 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3946924;
    L_3946896: ;
    /* @3946896 constant */
    /* @3946900 cast */
    /* @3946904 load */
    /* @3946912 call */
    GM_SITE(vm, 120, 3946912);
    /* @3946920 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3946924: ;
    /* @3946924 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3946896;
    /* @3946928 constant */
    /* @3946932 cast */
    /* @3946936 load */
    /* @3946944 constant */
    /* @3946948 sub */
    /* @3946952 load */
    /* @3946960 constant */
    /* @3946964 add */
    /* @3946968 call */
    GM_SITE(vm, 120, 3946968);
    v44 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3946976 store */
    v45 = GM_CALL(vm, "instance_create", 3, v44, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v45);
    /* @3946984 load */
    /* @3946992 cast */
    /* @3946996 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3947028;
    L_3947000: ;
    /* @3947000 constant */
    /* @3947004 cast */
    /* @3947008 load */
    /* @3947016 call */
    GM_SITE(vm, 120, 3947016);
    /* @3947024 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3947028: ;
    /* @3947028 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3947000;
    /* @3947032 constant */
    /* @3947036 cast */
    /* @3947040 load */
    /* @3947048 constant */
    /* @3947052 sub */
    /* @3947056 load */
    /* @3947064 constant */
    /* @3947068 sub */
    /* @3947072 call */
    GM_SITE(vm, 120, 3947072);
    /* @3947080 store */
    v46 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v46);
    /* @3947088 load */
    /* @3947096 cast */
    /* @3947100 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3947132;
    L_3947104: ;
    /* @3947104 constant */
    /* @3947108 cast */
    /* @3947112 load */
    /* @3947120 call */
    GM_SITE(vm, 120, 3947120);
    /* @3947128 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_3947132: ;
    /* @3947132 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3947104;
    /* @3947136 constant */
    /* @3947140 cast */
    /* @3947144 load */
    /* @3947152 constant */
    /* @3947156 sub */
    /* @3947160 load */
    /* @3947168 constant */
    /* @3947172 sub */
    /* @3947176 call */
    GM_SITE(vm, 120, 3947176);
    /* @3947184 store */
    v47 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v47);
    /* @3947192 load */
    /* @3947200 cast */
    /* @3947204 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_3947236;
    L_3947208: ;
    /* @3947208 constant */
    /* @3947212 cast */
    /* @3947216 load */
    /* @3947224 call */
    GM_SITE(vm, 120, 3947224);
    /* @3947232 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_3947236: ;
    /* @3947236 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3947208;
    L_3947240: ;
    /* @3947240 load */
    /* @3947248 constant */
    /* @3947252 cmp */
    /* @3947256 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(5)))) goto L_3948188;
    /* @3947260 constant */
    /* @3947264 cast */
    /* @3947268 load */
    /* @3947276 constant */
    /* @3947280 sub */
    /* @3947284 load */
    /* @3947292 call */
    GM_SITE(vm, 120, 3947292);
    /* @3947300 store */
    v48 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v48);
    /* @3947308 load */
    /* @3947316 cast */
    /* @3947320 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3947352;
    L_3947324: ;
    /* @3947324 constant */
    /* @3947328 cast */
    /* @3947332 load */
    /* @3947340 call */
    GM_SITE(vm, 120, 3947340);
    /* @3947348 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3947352: ;
    /* @3947352 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3947324;
    /* @3947356 constant */
    /* @3947360 cast */
    /* @3947364 load */
    /* @3947372 constant */
    /* @3947376 sub */
    /* @3947380 load */
    /* @3947388 constant */
    /* @3947392 add */
    /* @3947396 call */
    GM_SITE(vm, 120, 3947396);
    v49 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3947404 store */
    v50 = GM_CALL(vm, "instance_create", 3, v49, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v50);
    /* @3947412 load */
    /* @3947420 cast */
    /* @3947424 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3947456;
    L_3947428: ;
    /* @3947428 constant */
    /* @3947432 cast */
    /* @3947436 load */
    /* @3947444 call */
    GM_SITE(vm, 120, 3947444);
    /* @3947452 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3947456: ;
    /* @3947456 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3947428;
    /* @3947460 constant */
    /* @3947464 cast */
    /* @3947468 load */
    /* @3947476 constant */
    /* @3947480 sub */
    /* @3947484 load */
    /* @3947492 constant */
    /* @3947496 sub */
    /* @3947500 call */
    GM_SITE(vm, 120, 3947500);
    /* @3947508 store */
    v51 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v51);
    /* @3947516 load */
    /* @3947524 cast */
    /* @3947528 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3947560;
    L_3947532: ;
    /* @3947532 constant */
    /* @3947536 cast */
    /* @3947540 load */
    /* @3947548 call */
    GM_SITE(vm, 120, 3947548);
    /* @3947556 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3947560: ;
    /* @3947560 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3947532;
    /* @3947564 constant */
    /* @3947568 cast */
    /* @3947572 load */
    /* @3947580 constant */
    /* @3947584 sub */
    /* @3947588 load */
    /* @3947596 constant */
    /* @3947600 add */
    /* @3947604 call */
    GM_SITE(vm, 120, 3947604);
    v52 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3947612 store */
    v53 = GM_CALL(vm, "instance_create", 3, v52, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v53);
    /* @3947620 load */
    /* @3947628 cast */
    /* @3947632 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3947664;
    L_3947636: ;
    /* @3947636 constant */
    /* @3947640 cast */
    /* @3947644 load */
    /* @3947652 call */
    GM_SITE(vm, 120, 3947652);
    /* @3947660 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3947664: ;
    /* @3947664 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3947636;
    /* @3947668 constant */
    /* @3947672 cast */
    /* @3947676 load */
    /* @3947684 constant */
    /* @3947688 sub */
    /* @3947692 load */
    /* @3947700 constant */
    /* @3947704 sub */
    /* @3947708 call */
    GM_SITE(vm, 120, 3947708);
    /* @3947716 store */
    v54 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v54);
    /* @3947724 load */
    /* @3947732 cast */
    /* @3947736 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3947768;
    L_3947740: ;
    /* @3947740 constant */
    /* @3947744 cast */
    /* @3947748 load */
    /* @3947756 call */
    GM_SITE(vm, 120, 3947756);
    /* @3947764 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3947768: ;
    /* @3947768 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3947740;
    /* @3947772 constant */
    /* @3947776 cast */
    /* @3947780 load */
    /* @3947788 constant */
    /* @3947792 sub */
    /* @3947796 load */
    /* @3947804 constant */
    /* @3947808 add */
    /* @3947812 call */
    GM_SITE(vm, 120, 3947812);
    v55 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @3947820 store */
    v56 = GM_CALL(vm, "instance_create", 3, v55, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v56);
    /* @3947828 load */
    /* @3947836 cast */
    /* @3947840 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3947872;
    L_3947844: ;
    /* @3947844 constant */
    /* @3947848 cast */
    /* @3947852 load */
    /* @3947860 call */
    GM_SITE(vm, 120, 3947860);
    /* @3947868 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3947872: ;
    /* @3947872 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3947844;
    /* @3947876 constant */
    /* @3947880 cast */
    /* @3947884 load */
    /* @3947892 constant */
    /* @3947896 sub */
    /* @3947900 load */
    /* @3947908 constant */
    /* @3947912 add */
    /* @3947916 call */
    GM_SITE(vm, 120, 3947916);
    v57 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3947924 store */
    v58 = GM_CALL(vm, "instance_create", 3, v57, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v58);
    /* @3947932 load */
    /* @3947940 cast */
    /* @3947944 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3947976;
    L_3947948: ;
    /* @3947948 constant */
    /* @3947952 cast */
    /* @3947956 load */
    /* @3947964 call */
    GM_SITE(vm, 120, 3947964);
    /* @3947972 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3947976: ;
    /* @3947976 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3947948;
    /* @3947980 constant */
    /* @3947984 cast */
    /* @3947988 load */
    /* @3947996 constant */
    /* @3948000 sub */
    /* @3948004 load */
    /* @3948012 constant */
    /* @3948016 sub */
    /* @3948020 call */
    GM_SITE(vm, 120, 3948020);
    /* @3948028 store */
    v59 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v59);
    /* @3948036 load */
    /* @3948044 cast */
    /* @3948048 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3948080;
    L_3948052: ;
    /* @3948052 constant */
    /* @3948056 cast */
    /* @3948060 load */
    /* @3948068 call */
    GM_SITE(vm, 120, 3948068);
    /* @3948076 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3948080: ;
    /* @3948080 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3948052;
    /* @3948084 constant */
    /* @3948088 cast */
    /* @3948092 load */
    /* @3948100 constant */
    /* @3948104 sub */
    /* @3948108 load */
    /* @3948116 constant */
    /* @3948120 add */
    /* @3948124 call */
    GM_SITE(vm, 120, 3948124);
    v60 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3948132 store */
    v61 = GM_CALL(vm, "instance_create", 3, v60, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v61);
    /* @3948140 load */
    /* @3948148 cast */
    /* @3948152 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3948184;
    L_3948156: ;
    /* @3948156 constant */
    /* @3948160 cast */
    /* @3948164 load */
    /* @3948172 call */
    GM_SITE(vm, 120, 3948172);
    /* @3948180 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3948184: ;
    /* @3948184 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3948156;
    L_3948188: ;
    /* @3948188 call */
    GM_SITE(vm, 120, 3948188);
    /* @3948196 popz */
    (void)(GM_CALL(vm, "action_kill_object", 0));
    L_3948200: ;
    return;
}
