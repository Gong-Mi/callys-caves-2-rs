/* generated from CODE 77 (gml_Object_obj_skeleton_Alarm_0), source start 3911516, end 3916548. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0077(GmVM* vm) {
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
    /* @3911516 load */
    /* @3911524 constant */
    /* @3911528 cmp */
    /* @3911532 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3911540;
    /* @3911536 b */
    goto L_3911596;
    L_3911540: ;
    /* @3911540 load */
    /* @3911548 constant */
    /* @3911552 cmp */
    /* @3911556 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3911596;
    /* @3911560 constant */
    /* @3911564 cast */
    /* @3911568 constant */
    /* @3911572 cast */
    /* @3911576 constant */
    /* @3911580 cast */
    /* @3911584 call */
    GM_SITE(vm, 77, 3911584);
    /* @3911592 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(7), VAL(0), VAL(0)));
    L_3911596: ;
    /* @3911596 load */
    /* @3911604 constant */
    /* @3911608 cmp */
    /* @3911612 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpdrop") == VAL(1)))) goto L_3911660;
    /* @3911616 constant */
    /* @3911620 cast */
    /* @3911624 load */
    /* @3911632 constant */
    /* @3911636 sub */
    /* @3911640 load */
    /* @3911648 call */
    GM_SITE(vm, 77, 3911648);
    /* @3911656 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(62)));
    L_3911660: ;
    /* @3911660 load */
    /* @3911668 constant */
    /* @3911672 cmp */
    /* @3911676 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "gemdropenabled") == VAL(1)))) goto L_3911724;
    /* @3911680 constant */
    /* @3911684 cast */
    /* @3911688 load */
    /* @3911696 constant */
    /* @3911700 sub */
    /* @3911704 load */
    /* @3911712 call */
    GM_SITE(vm, 77, 3911712);
    /* @3911720 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(59)));
    L_3911724: ;
    /* @3911724 load */
    /* @3911732 constant */
    /* @3911736 cmp */
    /* @3911740 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "xpdrop") == VAL(1)))) goto L_3911840;
    /* @3911744 constant */
    /* @3911748 cast */
    /* @3911752 load */
    /* @3911760 constant */
    /* @3911764 sub */
    /* @3911768 load */
    /* @3911776 call */
    GM_SITE(vm, 77, 3911776);
    /* @3911784 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID", v1);
    /* @3911792 load */
    /* @3911800 cast */
    /* @3911804 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3911836;
    L_3911808: ;
    /* @3911808 constant */
    /* @3911812 cast */
    /* @3911816 load */
    /* @3911824 call */
    GM_SITE(vm, 77, 3911824);
    /* @3911832 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "xpspread"), VAL(5)));
    L_3911836: ;
    /* @3911836 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3911808;
    L_3911840: ;
    /* @3911840 constant */
    /* @3911844 cast */
    /* @3911848 call */
    GM_SITE(vm, 77, 3911848);
    /* @3911856 constant */
    /* @3911860 cmp */
    /* @3911864 bf */
    v2 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) >= VAL(20));
    if (!TRUTH(v2)) goto L_3911872;
    /* @3911868 b */
    goto L_3916536;
    L_3911872: ;
    /* @3911872 constant */
    /* @3911876 cast */
    /* @3911880 call */
    GM_SITE(vm, 77, 3911880);
    /* @3911888 constant */
    /* @3911892 cmp */
    /* @3911896 bf */
    v3 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) < VAL(20));
    if (!TRUTH(v3)) goto L_3916536;
    /* @3911900 load */
    /* @3911908 constant */
    /* @3911912 cmp */
    /* @3911916 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(1)))) goto L_3912432;
    /* @3911920 constant */
    /* @3911924 cast */
    /* @3911928 load */
    /* @3911936 constant */
    /* @3911940 sub */
    /* @3911944 load */
    /* @3911952 call */
    GM_SITE(vm, 77, 3911952);
    /* @3911960 store */
    v4 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v4);
    /* @3911968 load */
    /* @3911976 cast */
    /* @3911980 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3912012;
    L_3911984: ;
    /* @3911984 constant */
    /* @3911988 cast */
    /* @3911992 load */
    /* @3912000 call */
    GM_SITE(vm, 77, 3912000);
    /* @3912008 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3912012: ;
    /* @3912012 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3911984;
    /* @3912016 constant */
    /* @3912020 cast */
    /* @3912024 load */
    /* @3912032 constant */
    /* @3912036 sub */
    /* @3912040 load */
    /* @3912048 constant */
    /* @3912052 add */
    /* @3912056 call */
    GM_SITE(vm, 77, 3912056);
    v5 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3912064 store */
    v6 = GM_CALL(vm, "instance_create", 3, v5, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v6);
    /* @3912072 load */
    /* @3912080 cast */
    /* @3912084 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3912116;
    L_3912088: ;
    /* @3912088 constant */
    /* @3912092 cast */
    /* @3912096 load */
    /* @3912104 call */
    GM_SITE(vm, 77, 3912104);
    /* @3912112 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3912116: ;
    /* @3912116 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3912088;
    /* @3912120 constant */
    /* @3912124 cast */
    /* @3912128 load */
    /* @3912136 constant */
    /* @3912140 sub */
    /* @3912144 load */
    /* @3912152 constant */
    /* @3912156 sub */
    /* @3912160 call */
    GM_SITE(vm, 77, 3912160);
    /* @3912168 store */
    v7 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v7);
    /* @3912176 load */
    /* @3912184 cast */
    /* @3912188 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3912220;
    L_3912192: ;
    /* @3912192 constant */
    /* @3912196 cast */
    /* @3912200 load */
    /* @3912208 call */
    GM_SITE(vm, 77, 3912208);
    /* @3912216 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3912220: ;
    /* @3912220 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3912192;
    /* @3912224 constant */
    /* @3912228 cast */
    /* @3912232 load */
    /* @3912240 constant */
    /* @3912244 sub */
    /* @3912248 load */
    /* @3912256 constant */
    /* @3912260 add */
    /* @3912264 call */
    GM_SITE(vm, 77, 3912264);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3912272 store */
    v9 = GM_CALL(vm, "instance_create", 3, v8, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v9);
    /* @3912280 load */
    /* @3912288 cast */
    /* @3912292 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3912324;
    L_3912296: ;
    /* @3912296 constant */
    /* @3912300 cast */
    /* @3912304 load */
    /* @3912312 call */
    GM_SITE(vm, 77, 3912312);
    /* @3912320 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3912324: ;
    /* @3912324 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3912296;
    /* @3912328 constant */
    /* @3912332 cast */
    /* @3912336 load */
    /* @3912344 constant */
    /* @3912348 sub */
    /* @3912352 load */
    /* @3912360 constant */
    /* @3912364 sub */
    /* @3912368 call */
    GM_SITE(vm, 77, 3912368);
    /* @3912376 store */
    v10 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v10);
    /* @3912384 load */
    /* @3912392 cast */
    /* @3912396 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3912428;
    L_3912400: ;
    /* @3912400 constant */
    /* @3912404 cast */
    /* @3912408 load */
    /* @3912416 call */
    GM_SITE(vm, 77, 3912416);
    /* @3912424 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3912428: ;
    /* @3912428 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3912400;
    L_3912432: ;
    /* @3912432 load */
    /* @3912440 constant */
    /* @3912444 cmp */
    /* @3912448 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(2)))) goto L_3913172;
    /* @3912452 constant */
    /* @3912456 cast */
    /* @3912460 load */
    /* @3912468 constant */
    /* @3912472 sub */
    /* @3912476 load */
    /* @3912484 call */
    GM_SITE(vm, 77, 3912484);
    /* @3912492 store */
    v11 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v11);
    /* @3912500 load */
    /* @3912508 cast */
    /* @3912512 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3912544;
    L_3912516: ;
    /* @3912516 constant */
    /* @3912520 cast */
    /* @3912524 load */
    /* @3912532 call */
    GM_SITE(vm, 77, 3912532);
    /* @3912540 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3912544: ;
    /* @3912544 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3912516;
    /* @3912548 constant */
    /* @3912552 cast */
    /* @3912556 load */
    /* @3912564 constant */
    /* @3912568 sub */
    /* @3912572 load */
    /* @3912580 constant */
    /* @3912584 add */
    /* @3912588 call */
    GM_SITE(vm, 77, 3912588);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3912596 store */
    v13 = GM_CALL(vm, "instance_create", 3, v12, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v13);
    /* @3912604 load */
    /* @3912612 cast */
    /* @3912616 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3912648;
    L_3912620: ;
    /* @3912620 constant */
    /* @3912624 cast */
    /* @3912628 load */
    /* @3912636 call */
    GM_SITE(vm, 77, 3912636);
    /* @3912644 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3912648: ;
    /* @3912648 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3912620;
    /* @3912652 constant */
    /* @3912656 cast */
    /* @3912660 load */
    /* @3912668 constant */
    /* @3912672 sub */
    /* @3912676 load */
    /* @3912684 constant */
    /* @3912688 sub */
    /* @3912692 call */
    GM_SITE(vm, 77, 3912692);
    /* @3912700 store */
    v14 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v14);
    /* @3912708 load */
    /* @3912716 cast */
    /* @3912720 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3912752;
    L_3912724: ;
    /* @3912724 constant */
    /* @3912728 cast */
    /* @3912732 load */
    /* @3912740 call */
    GM_SITE(vm, 77, 3912740);
    /* @3912748 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3912752: ;
    /* @3912752 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3912724;
    /* @3912756 constant */
    /* @3912760 cast */
    /* @3912764 load */
    /* @3912772 constant */
    /* @3912776 sub */
    /* @3912780 load */
    /* @3912788 constant */
    /* @3912792 add */
    /* @3912796 call */
    GM_SITE(vm, 77, 3912796);
    v15 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3912804 store */
    v16 = GM_CALL(vm, "instance_create", 3, v15, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v16);
    /* @3912812 load */
    /* @3912820 cast */
    /* @3912824 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3912856;
    L_3912828: ;
    /* @3912828 constant */
    /* @3912832 cast */
    /* @3912836 load */
    /* @3912844 call */
    GM_SITE(vm, 77, 3912844);
    /* @3912852 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3912856: ;
    /* @3912856 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3912828;
    /* @3912860 constant */
    /* @3912864 cast */
    /* @3912868 load */
    /* @3912876 constant */
    /* @3912880 sub */
    /* @3912884 load */
    /* @3912892 constant */
    /* @3912896 sub */
    /* @3912900 call */
    GM_SITE(vm, 77, 3912900);
    /* @3912908 store */
    v17 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v17);
    /* @3912916 load */
    /* @3912924 cast */
    /* @3912928 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3912960;
    L_3912932: ;
    /* @3912932 constant */
    /* @3912936 cast */
    /* @3912940 load */
    /* @3912948 call */
    GM_SITE(vm, 77, 3912948);
    /* @3912956 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3912960: ;
    /* @3912960 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3912932;
    /* @3912964 constant */
    /* @3912968 cast */
    /* @3912972 load */
    /* @3912980 constant */
    /* @3912984 sub */
    /* @3912988 load */
    /* @3912996 constant */
    /* @3913000 sub */
    /* @3913004 call */
    GM_SITE(vm, 77, 3913004);
    /* @3913012 store */
    v18 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v18);
    /* @3913020 load */
    /* @3913028 cast */
    /* @3913032 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3913064;
    L_3913036: ;
    /* @3913036 constant */
    /* @3913040 cast */
    /* @3913044 load */
    /* @3913052 call */
    GM_SITE(vm, 77, 3913052);
    /* @3913060 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3913064: ;
    /* @3913064 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3913036;
    /* @3913068 constant */
    /* @3913072 cast */
    /* @3913076 load */
    /* @3913084 constant */
    /* @3913088 sub */
    /* @3913092 load */
    /* @3913100 constant */
    /* @3913104 add */
    /* @3913108 call */
    GM_SITE(vm, 77, 3913108);
    v19 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3913116 store */
    v20 = GM_CALL(vm, "instance_create", 3, v19, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v20);
    /* @3913124 load */
    /* @3913132 cast */
    /* @3913136 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3913168;
    L_3913140: ;
    /* @3913140 constant */
    /* @3913144 cast */
    /* @3913148 load */
    /* @3913156 call */
    GM_SITE(vm, 77, 3913156);
    /* @3913164 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3913168: ;
    /* @3913168 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3913140;
    L_3913172: ;
    /* @3913172 load */
    /* @3913180 constant */
    /* @3913184 cmp */
    /* @3913188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(3)))) goto L_3914016;
    /* @3913192 constant */
    /* @3913196 cast */
    /* @3913200 load */
    /* @3913208 constant */
    /* @3913212 sub */
    /* @3913216 load */
    /* @3913224 call */
    GM_SITE(vm, 77, 3913224);
    /* @3913232 store */
    v21 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v21);
    /* @3913240 load */
    /* @3913248 cast */
    /* @3913252 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3913284;
    L_3913256: ;
    /* @3913256 constant */
    /* @3913260 cast */
    /* @3913264 load */
    /* @3913272 call */
    GM_SITE(vm, 77, 3913272);
    /* @3913280 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3913284: ;
    /* @3913284 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3913256;
    /* @3913288 constant */
    /* @3913292 cast */
    /* @3913296 load */
    /* @3913304 constant */
    /* @3913308 sub */
    /* @3913312 load */
    /* @3913320 constant */
    /* @3913324 add */
    /* @3913328 call */
    GM_SITE(vm, 77, 3913328);
    v22 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3913336 store */
    v23 = GM_CALL(vm, "instance_create", 3, v22, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v23);
    /* @3913344 load */
    /* @3913352 cast */
    /* @3913356 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3913388;
    L_3913360: ;
    /* @3913360 constant */
    /* @3913364 cast */
    /* @3913368 load */
    /* @3913376 call */
    GM_SITE(vm, 77, 3913376);
    /* @3913384 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3913388: ;
    /* @3913388 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3913360;
    /* @3913392 constant */
    /* @3913396 cast */
    /* @3913400 load */
    /* @3913408 constant */
    /* @3913412 sub */
    /* @3913416 load */
    /* @3913424 constant */
    /* @3913428 sub */
    /* @3913432 call */
    GM_SITE(vm, 77, 3913432);
    /* @3913440 store */
    v24 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v24);
    /* @3913448 load */
    /* @3913456 cast */
    /* @3913460 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3913492;
    L_3913464: ;
    /* @3913464 constant */
    /* @3913468 cast */
    /* @3913472 load */
    /* @3913480 call */
    GM_SITE(vm, 77, 3913480);
    /* @3913488 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3913492: ;
    /* @3913492 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3913464;
    /* @3913496 constant */
    /* @3913500 cast */
    /* @3913504 load */
    /* @3913512 constant */
    /* @3913516 sub */
    /* @3913520 load */
    /* @3913528 constant */
    /* @3913532 add */
    /* @3913536 call */
    GM_SITE(vm, 77, 3913536);
    v25 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3913544 store */
    v26 = GM_CALL(vm, "instance_create", 3, v25, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v26);
    /* @3913552 load */
    /* @3913560 cast */
    /* @3913564 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3913596;
    L_3913568: ;
    /* @3913568 constant */
    /* @3913572 cast */
    /* @3913576 load */
    /* @3913584 call */
    GM_SITE(vm, 77, 3913584);
    /* @3913592 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3913596: ;
    /* @3913596 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3913568;
    /* @3913600 constant */
    /* @3913604 cast */
    /* @3913608 load */
    /* @3913616 constant */
    /* @3913620 sub */
    /* @3913624 load */
    /* @3913632 constant */
    /* @3913636 sub */
    /* @3913640 call */
    GM_SITE(vm, 77, 3913640);
    /* @3913648 store */
    v27 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v27);
    /* @3913656 load */
    /* @3913664 cast */
    /* @3913668 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3913700;
    L_3913672: ;
    /* @3913672 constant */
    /* @3913676 cast */
    /* @3913680 load */
    /* @3913688 call */
    GM_SITE(vm, 77, 3913688);
    /* @3913696 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3913700: ;
    /* @3913700 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3913672;
    /* @3913704 constant */
    /* @3913708 cast */
    /* @3913712 load */
    /* @3913720 constant */
    /* @3913724 sub */
    /* @3913728 load */
    /* @3913736 constant */
    /* @3913740 sub */
    /* @3913744 call */
    GM_SITE(vm, 77, 3913744);
    /* @3913752 store */
    v28 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v28);
    /* @3913760 load */
    /* @3913768 cast */
    /* @3913772 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3913804;
    L_3913776: ;
    /* @3913776 constant */
    /* @3913780 cast */
    /* @3913784 load */
    /* @3913792 call */
    GM_SITE(vm, 77, 3913792);
    /* @3913800 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3913804: ;
    /* @3913804 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3913776;
    /* @3913808 constant */
    /* @3913812 cast */
    /* @3913816 load */
    /* @3913824 constant */
    /* @3913828 sub */
    /* @3913832 load */
    /* @3913840 constant */
    /* @3913844 add */
    /* @3913848 call */
    GM_SITE(vm, 77, 3913848);
    v29 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3913856 store */
    v30 = GM_CALL(vm, "instance_create", 3, v29, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v30);
    /* @3913864 load */
    /* @3913872 cast */
    /* @3913876 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3913908;
    L_3913880: ;
    /* @3913880 constant */
    /* @3913884 cast */
    /* @3913888 load */
    /* @3913896 call */
    GM_SITE(vm, 77, 3913896);
    /* @3913904 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3913908: ;
    /* @3913908 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3913880;
    /* @3913912 constant */
    /* @3913916 cast */
    /* @3913920 load */
    /* @3913928 constant */
    /* @3913932 sub */
    /* @3913936 load */
    /* @3913944 constant */
    /* @3913948 sub */
    /* @3913952 call */
    GM_SITE(vm, 77, 3913952);
    /* @3913960 store */
    v31 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v31);
    /* @3913968 load */
    /* @3913976 cast */
    /* @3913980 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3914012;
    L_3913984: ;
    /* @3913984 constant */
    /* @3913988 cast */
    /* @3913992 load */
    /* @3914000 call */
    GM_SITE(vm, 77, 3914000);
    /* @3914008 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3914012: ;
    /* @3914012 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3913984;
    L_3914016: ;
    /* @3914016 load */
    /* @3914024 constant */
    /* @3914028 cmp */
    /* @3914032 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(4)))) goto L_3915172;
    /* @3914036 constant */
    /* @3914040 cast */
    /* @3914044 load */
    /* @3914052 constant */
    /* @3914056 sub */
    /* @3914060 load */
    /* @3914068 call */
    GM_SITE(vm, 77, 3914068);
    /* @3914076 store */
    v32 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v32);
    /* @3914084 load */
    /* @3914092 cast */
    /* @3914096 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3914128;
    L_3914100: ;
    /* @3914100 constant */
    /* @3914104 cast */
    /* @3914108 load */
    /* @3914116 call */
    GM_SITE(vm, 77, 3914116);
    /* @3914124 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3914128: ;
    /* @3914128 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3914100;
    /* @3914132 constant */
    /* @3914136 cast */
    /* @3914140 load */
    /* @3914148 constant */
    /* @3914152 sub */
    /* @3914156 load */
    /* @3914164 constant */
    /* @3914168 add */
    /* @3914172 call */
    GM_SITE(vm, 77, 3914172);
    v33 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3914180 store */
    v34 = GM_CALL(vm, "instance_create", 3, v33, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v34);
    /* @3914188 load */
    /* @3914196 cast */
    /* @3914200 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3914232;
    L_3914204: ;
    /* @3914204 constant */
    /* @3914208 cast */
    /* @3914212 load */
    /* @3914220 call */
    GM_SITE(vm, 77, 3914220);
    /* @3914228 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3914232: ;
    /* @3914232 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3914204;
    /* @3914236 constant */
    /* @3914240 cast */
    /* @3914244 load */
    /* @3914252 constant */
    /* @3914256 sub */
    /* @3914260 load */
    /* @3914268 constant */
    /* @3914272 sub */
    /* @3914276 call */
    GM_SITE(vm, 77, 3914276);
    /* @3914284 store */
    v35 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v35);
    /* @3914292 load */
    /* @3914300 cast */
    /* @3914304 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3914336;
    L_3914308: ;
    /* @3914308 constant */
    /* @3914312 cast */
    /* @3914316 load */
    /* @3914324 call */
    GM_SITE(vm, 77, 3914324);
    /* @3914332 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3914336: ;
    /* @3914336 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3914308;
    /* @3914340 constant */
    /* @3914344 cast */
    /* @3914348 load */
    /* @3914356 constant */
    /* @3914360 sub */
    /* @3914364 load */
    /* @3914372 constant */
    /* @3914376 add */
    /* @3914380 call */
    GM_SITE(vm, 77, 3914380);
    v36 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3914388 store */
    v37 = GM_CALL(vm, "instance_create", 3, v36, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v37);
    /* @3914396 load */
    /* @3914404 cast */
    /* @3914408 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3914440;
    L_3914412: ;
    /* @3914412 constant */
    /* @3914416 cast */
    /* @3914420 load */
    /* @3914428 call */
    GM_SITE(vm, 77, 3914428);
    /* @3914436 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3914440: ;
    /* @3914440 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3914412;
    /* @3914444 constant */
    /* @3914448 cast */
    /* @3914452 load */
    /* @3914460 constant */
    /* @3914464 sub */
    /* @3914468 load */
    /* @3914476 constant */
    /* @3914480 sub */
    /* @3914484 call */
    GM_SITE(vm, 77, 3914484);
    /* @3914492 store */
    v38 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v38);
    /* @3914500 load */
    /* @3914508 cast */
    /* @3914512 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3914544;
    L_3914516: ;
    /* @3914516 constant */
    /* @3914520 cast */
    /* @3914524 load */
    /* @3914532 call */
    GM_SITE(vm, 77, 3914532);
    /* @3914540 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3914544: ;
    /* @3914544 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3914516;
    /* @3914548 constant */
    /* @3914552 cast */
    /* @3914556 load */
    /* @3914564 constant */
    /* @3914568 sub */
    /* @3914572 load */
    /* @3914580 constant */
    /* @3914584 add */
    /* @3914588 call */
    GM_SITE(vm, 77, 3914588);
    v39 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @3914596 store */
    v40 = GM_CALL(vm, "instance_create", 3, v39, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v40);
    /* @3914604 load */
    /* @3914612 cast */
    /* @3914616 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3914648;
    L_3914620: ;
    /* @3914620 constant */
    /* @3914624 cast */
    /* @3914628 load */
    /* @3914636 call */
    GM_SITE(vm, 77, 3914636);
    /* @3914644 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3914648: ;
    /* @3914648 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3914620;
    /* @3914652 constant */
    /* @3914656 cast */
    /* @3914660 load */
    /* @3914668 constant */
    /* @3914672 sub */
    /* @3914676 load */
    /* @3914684 constant */
    /* @3914688 add */
    /* @3914692 call */
    GM_SITE(vm, 77, 3914692);
    v41 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3914700 store */
    v42 = GM_CALL(vm, "instance_create", 3, v41, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v42);
    /* @3914708 load */
    /* @3914716 cast */
    /* @3914720 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3914752;
    L_3914724: ;
    /* @3914724 constant */
    /* @3914728 cast */
    /* @3914732 load */
    /* @3914740 call */
    GM_SITE(vm, 77, 3914740);
    /* @3914748 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3914752: ;
    /* @3914752 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3914724;
    /* @3914756 constant */
    /* @3914760 cast */
    /* @3914764 load */
    /* @3914772 constant */
    /* @3914776 sub */
    /* @3914780 load */
    /* @3914788 constant */
    /* @3914792 sub */
    /* @3914796 call */
    GM_SITE(vm, 77, 3914796);
    /* @3914804 store */
    v43 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v43);
    /* @3914812 load */
    /* @3914820 cast */
    /* @3914824 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3914856;
    L_3914828: ;
    /* @3914828 constant */
    /* @3914832 cast */
    /* @3914836 load */
    /* @3914844 call */
    GM_SITE(vm, 77, 3914844);
    /* @3914852 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3914856: ;
    /* @3914856 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3914828;
    /* @3914860 constant */
    /* @3914864 cast */
    /* @3914868 load */
    /* @3914876 constant */
    /* @3914880 sub */
    /* @3914884 load */
    /* @3914892 constant */
    /* @3914896 add */
    /* @3914900 call */
    GM_SITE(vm, 77, 3914900);
    v44 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3914908 store */
    v45 = GM_CALL(vm, "instance_create", 3, v44, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v45);
    /* @3914916 load */
    /* @3914924 cast */
    /* @3914928 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3914960;
    L_3914932: ;
    /* @3914932 constant */
    /* @3914936 cast */
    /* @3914940 load */
    /* @3914948 call */
    GM_SITE(vm, 77, 3914948);
    /* @3914956 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3914960: ;
    /* @3914960 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3914932;
    /* @3914964 constant */
    /* @3914968 cast */
    /* @3914972 load */
    /* @3914980 constant */
    /* @3914984 sub */
    /* @3914988 load */
    /* @3914996 constant */
    /* @3915000 sub */
    /* @3915004 call */
    GM_SITE(vm, 77, 3915004);
    /* @3915012 store */
    v46 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v46);
    /* @3915020 load */
    /* @3915028 cast */
    /* @3915032 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3915064;
    L_3915036: ;
    /* @3915036 constant */
    /* @3915040 cast */
    /* @3915044 load */
    /* @3915052 call */
    GM_SITE(vm, 77, 3915052);
    /* @3915060 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_3915064: ;
    /* @3915064 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3915036;
    /* @3915068 constant */
    /* @3915072 cast */
    /* @3915076 load */
    /* @3915084 constant */
    /* @3915088 sub */
    /* @3915092 load */
    /* @3915100 constant */
    /* @3915104 sub */
    /* @3915108 call */
    GM_SITE(vm, 77, 3915108);
    /* @3915116 store */
    v47 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v47);
    /* @3915124 load */
    /* @3915132 cast */
    /* @3915136 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_3915168;
    L_3915140: ;
    /* @3915140 constant */
    /* @3915144 cast */
    /* @3915148 load */
    /* @3915156 call */
    GM_SITE(vm, 77, 3915156);
    /* @3915164 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_3915168: ;
    /* @3915168 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3915140;
    L_3915172: ;
    /* @3915172 load */
    /* @3915180 constant */
    /* @3915184 cmp */
    /* @3915188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(5)))) goto L_3916536;
    /* @3915192 constant */
    /* @3915196 cast */
    /* @3915200 load */
    /* @3915208 constant */
    /* @3915212 sub */
    /* @3915216 load */
    /* @3915224 call */
    GM_SITE(vm, 77, 3915224);
    /* @3915232 store */
    v48 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v48);
    /* @3915240 load */
    /* @3915248 cast */
    /* @3915252 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3915284;
    L_3915256: ;
    /* @3915256 constant */
    /* @3915260 cast */
    /* @3915264 load */
    /* @3915272 call */
    GM_SITE(vm, 77, 3915272);
    /* @3915280 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3915284: ;
    /* @3915284 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3915256;
    /* @3915288 constant */
    /* @3915292 cast */
    /* @3915296 load */
    /* @3915304 constant */
    /* @3915308 sub */
    /* @3915312 load */
    /* @3915320 constant */
    /* @3915324 add */
    /* @3915328 call */
    GM_SITE(vm, 77, 3915328);
    v49 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3915336 store */
    v50 = GM_CALL(vm, "instance_create", 3, v49, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v50);
    /* @3915344 load */
    /* @3915352 cast */
    /* @3915356 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3915388;
    L_3915360: ;
    /* @3915360 constant */
    /* @3915364 cast */
    /* @3915368 load */
    /* @3915376 call */
    GM_SITE(vm, 77, 3915376);
    /* @3915384 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3915388: ;
    /* @3915388 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3915360;
    /* @3915392 constant */
    /* @3915396 cast */
    /* @3915400 load */
    /* @3915408 constant */
    /* @3915412 sub */
    /* @3915416 load */
    /* @3915424 constant */
    /* @3915428 sub */
    /* @3915432 call */
    GM_SITE(vm, 77, 3915432);
    /* @3915440 store */
    v51 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v51);
    /* @3915448 load */
    /* @3915456 cast */
    /* @3915460 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3915492;
    L_3915464: ;
    /* @3915464 constant */
    /* @3915468 cast */
    /* @3915472 load */
    /* @3915480 call */
    GM_SITE(vm, 77, 3915480);
    /* @3915488 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3915492: ;
    /* @3915492 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3915464;
    /* @3915496 constant */
    /* @3915500 cast */
    /* @3915504 load */
    /* @3915512 constant */
    /* @3915516 sub */
    /* @3915520 load */
    /* @3915528 constant */
    /* @3915532 add */
    /* @3915536 call */
    GM_SITE(vm, 77, 3915536);
    v52 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3915544 store */
    v53 = GM_CALL(vm, "instance_create", 3, v52, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v53);
    /* @3915552 load */
    /* @3915560 cast */
    /* @3915564 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3915596;
    L_3915568: ;
    /* @3915568 constant */
    /* @3915572 cast */
    /* @3915576 load */
    /* @3915584 call */
    GM_SITE(vm, 77, 3915584);
    /* @3915592 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3915596: ;
    /* @3915596 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3915568;
    /* @3915600 constant */
    /* @3915604 cast */
    /* @3915608 load */
    /* @3915616 constant */
    /* @3915620 sub */
    /* @3915624 load */
    /* @3915632 constant */
    /* @3915636 sub */
    /* @3915640 call */
    GM_SITE(vm, 77, 3915640);
    /* @3915648 store */
    v54 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v54);
    /* @3915656 load */
    /* @3915664 cast */
    /* @3915668 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3915700;
    L_3915672: ;
    /* @3915672 constant */
    /* @3915676 cast */
    /* @3915680 load */
    /* @3915688 call */
    GM_SITE(vm, 77, 3915688);
    /* @3915696 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3915700: ;
    /* @3915700 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3915672;
    /* @3915704 constant */
    /* @3915708 cast */
    /* @3915712 load */
    /* @3915720 constant */
    /* @3915724 sub */
    /* @3915728 load */
    /* @3915736 constant */
    /* @3915740 add */
    /* @3915744 call */
    GM_SITE(vm, 77, 3915744);
    v55 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @3915752 store */
    v56 = GM_CALL(vm, "instance_create", 3, v55, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v56);
    /* @3915760 load */
    /* @3915768 cast */
    /* @3915772 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3915804;
    L_3915776: ;
    /* @3915776 constant */
    /* @3915780 cast */
    /* @3915784 load */
    /* @3915792 call */
    GM_SITE(vm, 77, 3915792);
    /* @3915800 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3915804: ;
    /* @3915804 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3915776;
    /* @3915808 constant */
    /* @3915812 cast */
    /* @3915816 load */
    /* @3915824 constant */
    /* @3915828 sub */
    /* @3915832 load */
    /* @3915840 constant */
    /* @3915844 add */
    /* @3915848 call */
    GM_SITE(vm, 77, 3915848);
    v57 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3915856 store */
    v58 = GM_CALL(vm, "instance_create", 3, v57, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v58);
    /* @3915864 load */
    /* @3915872 cast */
    /* @3915876 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3915908;
    L_3915880: ;
    /* @3915880 constant */
    /* @3915884 cast */
    /* @3915888 load */
    /* @3915896 call */
    GM_SITE(vm, 77, 3915896);
    /* @3915904 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3915908: ;
    /* @3915908 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3915880;
    /* @3915912 constant */
    /* @3915916 cast */
    /* @3915920 load */
    /* @3915928 constant */
    /* @3915932 sub */
    /* @3915936 load */
    /* @3915944 constant */
    /* @3915948 sub */
    /* @3915952 call */
    GM_SITE(vm, 77, 3915952);
    /* @3915960 store */
    v59 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v59);
    /* @3915968 load */
    /* @3915976 cast */
    /* @3915980 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3916012;
    L_3915984: ;
    /* @3915984 constant */
    /* @3915988 cast */
    /* @3915992 load */
    /* @3916000 call */
    GM_SITE(vm, 77, 3916000);
    /* @3916008 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3916012: ;
    /* @3916012 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3915984;
    /* @3916016 constant */
    /* @3916020 cast */
    /* @3916024 load */
    /* @3916032 constant */
    /* @3916036 sub */
    /* @3916040 load */
    /* @3916048 constant */
    /* @3916052 add */
    /* @3916056 call */
    GM_SITE(vm, 77, 3916056);
    v60 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3916064 store */
    v61 = GM_CALL(vm, "instance_create", 3, v60, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v61);
    /* @3916072 load */
    /* @3916080 cast */
    /* @3916084 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3916116;
    L_3916088: ;
    /* @3916088 constant */
    /* @3916092 cast */
    /* @3916096 load */
    /* @3916104 call */
    GM_SITE(vm, 77, 3916104);
    /* @3916112 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3916116: ;
    /* @3916116 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3916088;
    /* @3916120 constant */
    /* @3916124 cast */
    /* @3916128 load */
    /* @3916136 constant */
    /* @3916140 sub */
    /* @3916144 load */
    /* @3916152 constant */
    /* @3916156 sub */
    /* @3916160 call */
    GM_SITE(vm, 77, 3916160);
    /* @3916168 store */
    v62 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v62);
    /* @3916176 load */
    /* @3916184 cast */
    /* @3916188 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3916220;
    L_3916192: ;
    /* @3916192 constant */
    /* @3916196 cast */
    /* @3916200 load */
    /* @3916208 call */
    GM_SITE(vm, 77, 3916208);
    /* @3916216 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_3916220: ;
    /* @3916220 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3916192;
    /* @3916224 constant */
    /* @3916228 cast */
    /* @3916232 load */
    /* @3916240 constant */
    /* @3916244 sub */
    /* @3916248 load */
    /* @3916256 constant */
    /* @3916260 sub */
    /* @3916264 call */
    GM_SITE(vm, 77, 3916264);
    /* @3916272 store */
    v63 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v63);
    /* @3916280 load */
    /* @3916288 cast */
    /* @3916292 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_3916324;
    L_3916296: ;
    /* @3916296 constant */
    /* @3916300 cast */
    /* @3916304 load */
    /* @3916312 call */
    GM_SITE(vm, 77, 3916312);
    /* @3916320 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_3916324: ;
    /* @3916324 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3916296;
    /* @3916328 constant */
    /* @3916332 cast */
    /* @3916336 load */
    /* @3916344 constant */
    /* @3916348 sub */
    /* @3916352 load */
    /* @3916360 constant */
    /* @3916364 add */
    /* @3916368 call */
    GM_SITE(vm, 77, 3916368);
    v64 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @3916376 store */
    v65 = GM_CALL(vm, "instance_create", 3, v64, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID12", v65);
    /* @3916384 load */
    /* @3916392 cast */
    /* @3916396 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID12")))) goto L_3916428;
    L_3916400: ;
    /* @3916400 constant */
    /* @3916404 cast */
    /* @3916408 load */
    /* @3916416 call */
    GM_SITE(vm, 77, 3916416);
    /* @3916424 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread12"), VAL(5)));
    L_3916428: ;
    /* @3916428 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3916400;
    /* @3916432 constant */
    /* @3916436 cast */
    /* @3916440 load */
    /* @3916448 constant */
    /* @3916452 sub */
    /* @3916456 load */
    /* @3916464 constant */
    /* @3916468 sub */
    /* @3916472 call */
    GM_SITE(vm, 77, 3916472);
    /* @3916480 store */
    v66 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID13", v66);
    /* @3916488 load */
    /* @3916496 cast */
    /* @3916500 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID13")))) goto L_3916532;
    L_3916504: ;
    /* @3916504 constant */
    /* @3916508 cast */
    /* @3916512 load */
    /* @3916520 call */
    GM_SITE(vm, 77, 3916520);
    /* @3916528 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread13"), VAL(5)));
    L_3916532: ;
    /* @3916532 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3916504;
    L_3916536: ;
    /* @3916536 call */
    GM_SITE(vm, 77, 3916536);
    /* @3916544 popz */
    (void)(GM_CALL(vm, "action_kill_object", 0));
    L_3916548: ;
    return;
}
