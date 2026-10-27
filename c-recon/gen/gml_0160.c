/* generated from CODE 160 (gml_Object_obj_trex_Alarm_0), source start 3973280, end 3982416. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0160(GmVM* vm) {
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
    Val v78;
    Val v79;
    Val v80;
    Val v81;
    Val v82;
    Val v83;
    Val v84;
    Val v85;
    Val v86;
    Val v87;
    Val v88;
    Val v89;
    Val v90;
    Val v91;
    Val v92;
    Val v93;
    Val v94;
    Val v95;
    Val v96;
    Val v97;
    Val v98;
    Val v99;
    Val v100;
    Val v101;
    Val v102;
    Val v103;
    Val v104;
    Val v105;
    Val v106;
    Val v107;
    Val v108;
    Val v109;
    Val v110;
    Val v111;
    Val v112;
    Val v113;
    Val v114;
    Val v115;
    Val v116;
    Val v117;
    Val v118;
    Val v119;
    Val v120;
    Val v121;
    Val v122;
    Val v123;
    /* @3973280 load */
    /* @3973288 constant */
    /* @3973292 cmp */
    /* @3973296 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3973304;
    /* @3973300 b */
    goto L_3973360;
    L_3973304: ;
    /* @3973304 load */
    /* @3973312 constant */
    /* @3973316 cmp */
    /* @3973320 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3973360;
    /* @3973324 constant */
    /* @3973328 cast */
    /* @3973332 constant */
    /* @3973336 cast */
    /* @3973340 constant */
    /* @3973344 cast */
    /* @3973348 call */
    GM_SITE(vm, 160, 3973348);
    /* @3973356 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(7), VAL(0), VAL(0)));
    L_3973360: ;
    /* @3973360 constant */
    /* @3973364 store */
    GM_WRITE(vm, -5, "boss1dead", VAL(1));
    /* @3973372 load */
    /* @3973380 constant */
    /* @3973384 cmp */
    /* @3973388 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "gemdropenabled") == VAL(1)))) goto L_3973436;
    /* @3973392 constant */
    /* @3973396 cast */
    /* @3973400 load */
    /* @3973408 constant */
    /* @3973412 sub */
    /* @3973416 load */
    /* @3973424 call */
    GM_SITE(vm, 160, 3973424);
    /* @3973432 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(59)));
    L_3973436: ;
    /* @3973436 load */
    /* @3973444 constant */
    /* @3973448 cmp */
    /* @3973452 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpdrop") == VAL(1)))) goto L_3973500;
    /* @3973456 constant */
    /* @3973460 cast */
    /* @3973464 load */
    /* @3973472 constant */
    /* @3973476 sub */
    /* @3973480 load */
    /* @3973488 call */
    GM_SITE(vm, 160, 3973488);
    /* @3973496 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(62)));
    L_3973500: ;
    /* @3973500 load */
    /* @3973508 constant */
    /* @3973512 cmp */
    /* @3973516 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "xpdrop") == VAL(1)))) goto L_3974544;
    /* @3973520 constant */
    /* @3973524 cast */
    /* @3973528 load */
    /* @3973536 constant */
    /* @3973540 sub */
    /* @3973544 load */
    /* @3973552 call */
    GM_SITE(vm, 160, 3973552);
    /* @3973560 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID", v1);
    /* @3973568 load */
    /* @3973576 cast */
    /* @3973580 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3973612;
    L_3973584: ;
    /* @3973584 constant */
    /* @3973588 cast */
    /* @3973592 load */
    /* @3973600 call */
    GM_SITE(vm, 160, 3973600);
    /* @3973608 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3973612: ;
    /* @3973612 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3973584;
    /* @3973616 constant */
    /* @3973620 cast */
    /* @3973624 load */
    /* @3973632 constant */
    /* @3973636 sub */
    /* @3973640 load */
    /* @3973648 constant */
    /* @3973652 add */
    /* @3973656 call */
    GM_SITE(vm, 160, 3973656);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(7));
    /* @3973664 store */
    v3 = GM_CALL(vm, "instance_create", 3, v2, (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID2", v3);
    /* @3973672 load */
    /* @3973680 cast */
    /* @3973684 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3973716;
    L_3973688: ;
    /* @3973688 constant */
    /* @3973692 cast */
    /* @3973696 load */
    /* @3973704 call */
    GM_SITE(vm, 160, 3973704);
    /* @3973712 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3973716: ;
    /* @3973716 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3973688;
    /* @3973720 constant */
    /* @3973724 cast */
    /* @3973728 load */
    /* @3973736 constant */
    /* @3973740 sub */
    /* @3973744 load */
    /* @3973752 constant */
    /* @3973756 sub */
    /* @3973760 call */
    GM_SITE(vm, 160, 3973760);
    /* @3973768 store */
    v4 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(7)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID3", v4);
    /* @3973776 load */
    /* @3973784 cast */
    /* @3973788 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3973820;
    L_3973792: ;
    /* @3973792 constant */
    /* @3973796 cast */
    /* @3973800 load */
    /* @3973808 call */
    GM_SITE(vm, 160, 3973808);
    /* @3973816 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3973820: ;
    /* @3973820 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3973792;
    /* @3973824 constant */
    /* @3973828 cast */
    /* @3973832 load */
    /* @3973840 constant */
    /* @3973844 sub */
    /* @3973848 load */
    /* @3973856 constant */
    /* @3973860 add */
    /* @3973864 call */
    GM_SITE(vm, 160, 3973864);
    v5 = GM_ADD(GM_READ(vm, -1, "x"), VAL(12));
    /* @3973872 store */
    v6 = GM_CALL(vm, "instance_create", 3, v5, (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID4", v6);
    /* @3973880 load */
    /* @3973888 cast */
    /* @3973892 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3973924;
    L_3973896: ;
    /* @3973896 constant */
    /* @3973900 cast */
    /* @3973904 load */
    /* @3973912 call */
    GM_SITE(vm, 160, 3973912);
    /* @3973920 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3973924: ;
    /* @3973924 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3973896;
    /* @3973928 constant */
    /* @3973932 cast */
    /* @3973936 load */
    /* @3973944 constant */
    /* @3973948 sub */
    /* @3973952 load */
    /* @3973960 constant */
    /* @3973964 sub */
    /* @3973968 call */
    GM_SITE(vm, 160, 3973968);
    /* @3973976 store */
    v7 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(12)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID5", v7);
    /* @3973984 load */
    /* @3973992 cast */
    /* @3973996 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3974028;
    L_3974000: ;
    /* @3974000 constant */
    /* @3974004 cast */
    /* @3974008 load */
    /* @3974016 call */
    GM_SITE(vm, 160, 3974016);
    /* @3974024 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3974028: ;
    /* @3974028 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3974000;
    /* @3974032 constant */
    /* @3974036 cast */
    /* @3974040 load */
    /* @3974048 constant */
    /* @3974052 sub */
    /* @3974056 load */
    /* @3974064 call */
    GM_SITE(vm, 160, 3974064);
    /* @3974072 store */
    v8 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID6", v8);
    /* @3974080 load */
    /* @3974088 cast */
    /* @3974092 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3974124;
    L_3974096: ;
    /* @3974096 constant */
    /* @3974100 cast */
    /* @3974104 load */
    /* @3974112 call */
    GM_SITE(vm, 160, 3974112);
    /* @3974120 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3974124: ;
    /* @3974124 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3974096;
    /* @3974128 constant */
    /* @3974132 cast */
    /* @3974136 load */
    /* @3974144 constant */
    /* @3974148 sub */
    /* @3974152 load */
    /* @3974160 constant */
    /* @3974164 add */
    /* @3974168 call */
    GM_SITE(vm, 160, 3974168);
    v9 = GM_ADD(GM_READ(vm, -1, "x"), VAL(16));
    /* @3974176 store */
    v10 = GM_CALL(vm, "instance_create", 3, v9, (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID7", v10);
    /* @3974184 load */
    /* @3974192 cast */
    /* @3974196 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3974228;
    L_3974200: ;
    /* @3974200 constant */
    /* @3974204 cast */
    /* @3974208 load */
    /* @3974216 call */
    GM_SITE(vm, 160, 3974216);
    /* @3974224 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3974228: ;
    /* @3974228 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3974200;
    /* @3974232 constant */
    /* @3974236 cast */
    /* @3974240 load */
    /* @3974248 constant */
    /* @3974252 sub */
    /* @3974256 load */
    /* @3974264 constant */
    /* @3974268 sub */
    /* @3974272 call */
    GM_SITE(vm, 160, 3974272);
    /* @3974280 store */
    v11 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(17)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID8", v11);
    /* @3974288 load */
    /* @3974296 cast */
    /* @3974300 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3974332;
    L_3974304: ;
    /* @3974304 constant */
    /* @3974308 cast */
    /* @3974312 load */
    /* @3974320 call */
    GM_SITE(vm, 160, 3974320);
    /* @3974328 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3974332: ;
    /* @3974332 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3974304;
    /* @3974336 constant */
    /* @3974340 cast */
    /* @3974344 load */
    /* @3974352 constant */
    /* @3974356 sub */
    /* @3974360 load */
    /* @3974368 constant */
    /* @3974372 add */
    /* @3974376 call */
    GM_SITE(vm, 160, 3974376);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @3974384 store */
    v13 = GM_CALL(vm, "instance_create", 3, v12, (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID9", v13);
    /* @3974392 load */
    /* @3974400 cast */
    /* @3974404 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3974436;
    L_3974408: ;
    /* @3974408 constant */
    /* @3974412 cast */
    /* @3974416 load */
    /* @3974424 call */
    GM_SITE(vm, 160, 3974424);
    /* @3974432 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3974436: ;
    /* @3974436 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3974408;
    /* @3974440 constant */
    /* @3974444 cast */
    /* @3974448 load */
    /* @3974456 constant */
    /* @3974460 sub */
    /* @3974464 load */
    /* @3974472 constant */
    /* @3974476 sub */
    /* @3974480 call */
    GM_SITE(vm, 160, 3974480);
    /* @3974488 store */
    v14 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(21)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID10", v14);
    /* @3974496 load */
    /* @3974504 cast */
    /* @3974508 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3974540;
    L_3974512: ;
    /* @3974512 constant */
    /* @3974516 cast */
    /* @3974520 load */
    /* @3974528 call */
    GM_SITE(vm, 160, 3974528);
    /* @3974536 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3974540: ;
    /* @3974540 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3974512;
    L_3974544: ;
    /* @3974544 load */
    /* @3974552 constant */
    /* @3974556 cmp */
    /* @3974560 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(1)))) goto L_3975076;
    /* @3974564 constant */
    /* @3974568 cast */
    /* @3974572 load */
    /* @3974580 constant */
    /* @3974584 sub */
    /* @3974588 load */
    /* @3974596 call */
    GM_SITE(vm, 160, 3974596);
    /* @3974604 store */
    v15 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v15);
    /* @3974612 load */
    /* @3974620 cast */
    /* @3974624 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3974656;
    L_3974628: ;
    /* @3974628 constant */
    /* @3974632 cast */
    /* @3974636 load */
    /* @3974644 call */
    GM_SITE(vm, 160, 3974644);
    /* @3974652 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3974656: ;
    /* @3974656 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3974628;
    /* @3974660 constant */
    /* @3974664 cast */
    /* @3974668 load */
    /* @3974676 constant */
    /* @3974680 sub */
    /* @3974684 load */
    /* @3974692 constant */
    /* @3974696 add */
    /* @3974700 call */
    GM_SITE(vm, 160, 3974700);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3974708 store */
    v17 = GM_CALL(vm, "instance_create", 3, v16, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v17);
    /* @3974716 load */
    /* @3974724 cast */
    /* @3974728 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3974760;
    L_3974732: ;
    /* @3974732 constant */
    /* @3974736 cast */
    /* @3974740 load */
    /* @3974748 call */
    GM_SITE(vm, 160, 3974748);
    /* @3974756 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3974760: ;
    /* @3974760 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3974732;
    /* @3974764 constant */
    /* @3974768 cast */
    /* @3974772 load */
    /* @3974780 constant */
    /* @3974784 sub */
    /* @3974788 load */
    /* @3974796 constant */
    /* @3974800 sub */
    /* @3974804 call */
    GM_SITE(vm, 160, 3974804);
    /* @3974812 store */
    v18 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v18);
    /* @3974820 load */
    /* @3974828 cast */
    /* @3974832 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3974864;
    L_3974836: ;
    /* @3974836 constant */
    /* @3974840 cast */
    /* @3974844 load */
    /* @3974852 call */
    GM_SITE(vm, 160, 3974852);
    /* @3974860 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3974864: ;
    /* @3974864 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3974836;
    /* @3974868 constant */
    /* @3974872 cast */
    /* @3974876 load */
    /* @3974884 constant */
    /* @3974888 sub */
    /* @3974892 load */
    /* @3974900 constant */
    /* @3974904 add */
    /* @3974908 call */
    GM_SITE(vm, 160, 3974908);
    v19 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3974916 store */
    v20 = GM_CALL(vm, "instance_create", 3, v19, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v20);
    /* @3974924 load */
    /* @3974932 cast */
    /* @3974936 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3974968;
    L_3974940: ;
    /* @3974940 constant */
    /* @3974944 cast */
    /* @3974948 load */
    /* @3974956 call */
    GM_SITE(vm, 160, 3974956);
    /* @3974964 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3974968: ;
    /* @3974968 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3974940;
    /* @3974972 constant */
    /* @3974976 cast */
    /* @3974980 load */
    /* @3974988 constant */
    /* @3974992 sub */
    /* @3974996 load */
    /* @3975004 constant */
    /* @3975008 sub */
    /* @3975012 call */
    GM_SITE(vm, 160, 3975012);
    /* @3975020 store */
    v21 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v21);
    /* @3975028 load */
    /* @3975036 cast */
    /* @3975040 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3975072;
    L_3975044: ;
    /* @3975044 constant */
    /* @3975048 cast */
    /* @3975052 load */
    /* @3975060 call */
    GM_SITE(vm, 160, 3975060);
    /* @3975068 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3975072: ;
    /* @3975072 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3975044;
    L_3975076: ;
    /* @3975076 load */
    /* @3975084 constant */
    /* @3975088 cmp */
    /* @3975092 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(2)))) goto L_3976128;
    /* @3975096 constant */
    /* @3975100 cast */
    /* @3975104 load */
    /* @3975112 constant */
    /* @3975116 sub */
    /* @3975120 load */
    /* @3975128 call */
    GM_SITE(vm, 160, 3975128);
    /* @3975136 store */
    v22 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v22);
    /* @3975144 load */
    /* @3975152 cast */
    /* @3975156 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3975188;
    L_3975160: ;
    /* @3975160 constant */
    /* @3975164 cast */
    /* @3975168 load */
    /* @3975176 call */
    GM_SITE(vm, 160, 3975176);
    /* @3975184 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3975188: ;
    /* @3975188 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3975160;
    /* @3975192 constant */
    /* @3975196 cast */
    /* @3975200 load */
    /* @3975208 constant */
    /* @3975212 sub */
    /* @3975216 load */
    /* @3975224 constant */
    /* @3975228 add */
    /* @3975232 call */
    GM_SITE(vm, 160, 3975232);
    v23 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3975240 store */
    v24 = GM_CALL(vm, "instance_create", 3, v23, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v24);
    /* @3975248 load */
    /* @3975256 cast */
    /* @3975260 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3975292;
    L_3975264: ;
    /* @3975264 constant */
    /* @3975268 cast */
    /* @3975272 load */
    /* @3975280 call */
    GM_SITE(vm, 160, 3975280);
    /* @3975288 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3975292: ;
    /* @3975292 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3975264;
    /* @3975296 constant */
    /* @3975300 cast */
    /* @3975304 load */
    /* @3975312 constant */
    /* @3975316 sub */
    /* @3975320 load */
    /* @3975328 constant */
    /* @3975332 sub */
    /* @3975336 call */
    GM_SITE(vm, 160, 3975336);
    /* @3975344 store */
    v25 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v25);
    /* @3975352 load */
    /* @3975360 cast */
    /* @3975364 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3975396;
    L_3975368: ;
    /* @3975368 constant */
    /* @3975372 cast */
    /* @3975376 load */
    /* @3975384 call */
    GM_SITE(vm, 160, 3975384);
    /* @3975392 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3975396: ;
    /* @3975396 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3975368;
    /* @3975400 constant */
    /* @3975404 cast */
    /* @3975408 load */
    /* @3975416 constant */
    /* @3975420 sub */
    /* @3975424 load */
    /* @3975432 constant */
    /* @3975436 add */
    /* @3975440 call */
    GM_SITE(vm, 160, 3975440);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3975448 store */
    v27 = GM_CALL(vm, "instance_create", 3, v26, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v27);
    /* @3975456 load */
    /* @3975464 cast */
    /* @3975468 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3975500;
    L_3975472: ;
    /* @3975472 constant */
    /* @3975476 cast */
    /* @3975480 load */
    /* @3975488 call */
    GM_SITE(vm, 160, 3975488);
    /* @3975496 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3975500: ;
    /* @3975500 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3975472;
    /* @3975504 constant */
    /* @3975508 cast */
    /* @3975512 load */
    /* @3975520 constant */
    /* @3975524 sub */
    /* @3975528 load */
    /* @3975536 constant */
    /* @3975540 sub */
    /* @3975544 call */
    GM_SITE(vm, 160, 3975544);
    /* @3975552 store */
    v28 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v28);
    /* @3975560 load */
    /* @3975568 cast */
    /* @3975572 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3975604;
    L_3975576: ;
    /* @3975576 constant */
    /* @3975580 cast */
    /* @3975584 load */
    /* @3975592 call */
    GM_SITE(vm, 160, 3975592);
    /* @3975600 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3975604: ;
    /* @3975604 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3975576;
    /* @3975608 constant */
    /* @3975612 cast */
    /* @3975616 load */
    /* @3975624 constant */
    /* @3975628 sub */
    /* @3975632 load */
    /* @3975640 constant */
    /* @3975644 sub */
    /* @3975648 call */
    GM_SITE(vm, 160, 3975648);
    /* @3975656 store */
    v29 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v29);
    /* @3975664 load */
    /* @3975672 cast */
    /* @3975676 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3975708;
    L_3975680: ;
    /* @3975680 constant */
    /* @3975684 cast */
    /* @3975688 load */
    /* @3975696 call */
    GM_SITE(vm, 160, 3975696);
    /* @3975704 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3975708: ;
    /* @3975708 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3975680;
    /* @3975712 constant */
    /* @3975716 cast */
    /* @3975720 load */
    /* @3975728 constant */
    /* @3975732 sub */
    /* @3975736 load */
    /* @3975744 constant */
    /* @3975748 add */
    /* @3975752 call */
    GM_SITE(vm, 160, 3975752);
    v30 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3975760 store */
    v31 = GM_CALL(vm, "instance_create", 3, v30, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v31);
    /* @3975768 load */
    /* @3975776 cast */
    /* @3975780 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3975812;
    L_3975784: ;
    /* @3975784 constant */
    /* @3975788 cast */
    /* @3975792 load */
    /* @3975800 call */
    GM_SITE(vm, 160, 3975800);
    /* @3975808 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3975812: ;
    /* @3975812 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3975784;
    /* @3975816 constant */
    /* @3975820 cast */
    /* @3975824 load */
    /* @3975832 constant */
    /* @3975836 sub */
    /* @3975840 load */
    /* @3975848 constant */
    /* @3975852 sub */
    /* @3975856 call */
    GM_SITE(vm, 160, 3975856);
    /* @3975864 store */
    v32 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v32);
    /* @3975872 load */
    /* @3975880 cast */
    /* @3975884 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3975916;
    L_3975888: ;
    /* @3975888 constant */
    /* @3975892 cast */
    /* @3975896 load */
    /* @3975904 call */
    GM_SITE(vm, 160, 3975904);
    /* @3975912 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3975916: ;
    /* @3975916 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3975888;
    /* @3975920 constant */
    /* @3975924 cast */
    /* @3975928 load */
    /* @3975936 constant */
    /* @3975940 sub */
    /* @3975944 load */
    /* @3975952 constant */
    /* @3975956 add */
    /* @3975960 call */
    GM_SITE(vm, 160, 3975960);
    v33 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3975968 store */
    v34 = GM_CALL(vm, "instance_create", 3, v33, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v34);
    /* @3975976 load */
    /* @3975984 cast */
    /* @3975988 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3976020;
    L_3975992: ;
    /* @3975992 constant */
    /* @3975996 cast */
    /* @3976000 load */
    /* @3976008 call */
    GM_SITE(vm, 160, 3976008);
    /* @3976016 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3976020: ;
    /* @3976020 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3975992;
    /* @3976024 constant */
    /* @3976028 cast */
    /* @3976032 load */
    /* @3976040 constant */
    /* @3976044 sub */
    /* @3976048 load */
    /* @3976056 constant */
    /* @3976060 sub */
    /* @3976064 call */
    GM_SITE(vm, 160, 3976064);
    /* @3976072 store */
    v35 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v35);
    /* @3976080 load */
    /* @3976088 cast */
    /* @3976092 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3976124;
    L_3976096: ;
    /* @3976096 constant */
    /* @3976100 cast */
    /* @3976104 load */
    /* @3976112 call */
    GM_SITE(vm, 160, 3976112);
    /* @3976120 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_3976124: ;
    /* @3976124 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3976096;
    L_3976128: ;
    /* @3976128 load */
    /* @3976136 constant */
    /* @3976140 cmp */
    /* @3976144 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(3)))) goto L_3977700;
    /* @3976148 constant */
    /* @3976152 cast */
    /* @3976156 load */
    /* @3976164 constant */
    /* @3976168 sub */
    /* @3976172 load */
    /* @3976180 call */
    GM_SITE(vm, 160, 3976180);
    /* @3976188 store */
    v36 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v36);
    /* @3976196 load */
    /* @3976204 cast */
    /* @3976208 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3976240;
    L_3976212: ;
    /* @3976212 constant */
    /* @3976216 cast */
    /* @3976220 load */
    /* @3976228 call */
    GM_SITE(vm, 160, 3976228);
    /* @3976236 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3976240: ;
    /* @3976240 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3976212;
    /* @3976244 constant */
    /* @3976248 cast */
    /* @3976252 load */
    /* @3976260 constant */
    /* @3976264 sub */
    /* @3976268 load */
    /* @3976276 constant */
    /* @3976280 add */
    /* @3976284 call */
    GM_SITE(vm, 160, 3976284);
    v37 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3976292 store */
    v38 = GM_CALL(vm, "instance_create", 3, v37, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v38);
    /* @3976300 load */
    /* @3976308 cast */
    /* @3976312 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3976344;
    L_3976316: ;
    /* @3976316 constant */
    /* @3976320 cast */
    /* @3976324 load */
    /* @3976332 call */
    GM_SITE(vm, 160, 3976332);
    /* @3976340 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3976344: ;
    /* @3976344 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3976316;
    /* @3976348 constant */
    /* @3976352 cast */
    /* @3976356 load */
    /* @3976364 constant */
    /* @3976368 sub */
    /* @3976372 load */
    /* @3976380 constant */
    /* @3976384 sub */
    /* @3976388 call */
    GM_SITE(vm, 160, 3976388);
    /* @3976396 store */
    v39 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v39);
    /* @3976404 load */
    /* @3976412 cast */
    /* @3976416 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3976448;
    L_3976420: ;
    /* @3976420 constant */
    /* @3976424 cast */
    /* @3976428 load */
    /* @3976436 call */
    GM_SITE(vm, 160, 3976436);
    /* @3976444 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3976448: ;
    /* @3976448 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3976420;
    /* @3976452 constant */
    /* @3976456 cast */
    /* @3976460 load */
    /* @3976468 constant */
    /* @3976472 sub */
    /* @3976476 load */
    /* @3976484 constant */
    /* @3976488 add */
    /* @3976492 call */
    GM_SITE(vm, 160, 3976492);
    v40 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3976500 store */
    v41 = GM_CALL(vm, "instance_create", 3, v40, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v41);
    /* @3976508 load */
    /* @3976516 cast */
    /* @3976520 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3976552;
    L_3976524: ;
    /* @3976524 constant */
    /* @3976528 cast */
    /* @3976532 load */
    /* @3976540 call */
    GM_SITE(vm, 160, 3976540);
    /* @3976548 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3976552: ;
    /* @3976552 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3976524;
    /* @3976556 constant */
    /* @3976560 cast */
    /* @3976564 load */
    /* @3976572 constant */
    /* @3976576 sub */
    /* @3976580 load */
    /* @3976588 constant */
    /* @3976592 sub */
    /* @3976596 call */
    GM_SITE(vm, 160, 3976596);
    /* @3976604 store */
    v42 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v42);
    /* @3976612 load */
    /* @3976620 cast */
    /* @3976624 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3976656;
    L_3976628: ;
    /* @3976628 constant */
    /* @3976632 cast */
    /* @3976636 load */
    /* @3976644 call */
    GM_SITE(vm, 160, 3976644);
    /* @3976652 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3976656: ;
    /* @3976656 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3976628;
    /* @3976660 constant */
    /* @3976664 cast */
    /* @3976668 load */
    /* @3976676 constant */
    /* @3976680 sub */
    /* @3976684 load */
    /* @3976692 constant */
    /* @3976696 sub */
    /* @3976700 call */
    GM_SITE(vm, 160, 3976700);
    /* @3976708 store */
    v43 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v43);
    /* @3976716 load */
    /* @3976724 cast */
    /* @3976728 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3976760;
    L_3976732: ;
    /* @3976732 constant */
    /* @3976736 cast */
    /* @3976740 load */
    /* @3976748 call */
    GM_SITE(vm, 160, 3976748);
    /* @3976756 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3976760: ;
    /* @3976760 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3976732;
    /* @3976764 constant */
    /* @3976768 cast */
    /* @3976772 load */
    /* @3976780 constant */
    /* @3976784 sub */
    /* @3976788 load */
    /* @3976796 constant */
    /* @3976800 add */
    /* @3976804 call */
    GM_SITE(vm, 160, 3976804);
    v44 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3976812 store */
    v45 = GM_CALL(vm, "instance_create", 3, v44, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v45);
    /* @3976820 load */
    /* @3976828 cast */
    /* @3976832 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3976864;
    L_3976836: ;
    /* @3976836 constant */
    /* @3976840 cast */
    /* @3976844 load */
    /* @3976852 call */
    GM_SITE(vm, 160, 3976852);
    /* @3976860 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3976864: ;
    /* @3976864 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3976836;
    /* @3976868 constant */
    /* @3976872 cast */
    /* @3976876 load */
    /* @3976884 constant */
    /* @3976888 sub */
    /* @3976892 load */
    /* @3976900 constant */
    /* @3976904 sub */
    /* @3976908 call */
    GM_SITE(vm, 160, 3976908);
    /* @3976916 store */
    v46 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v46);
    /* @3976924 load */
    /* @3976932 cast */
    /* @3976936 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3976968;
    L_3976940: ;
    /* @3976940 constant */
    /* @3976944 cast */
    /* @3976948 load */
    /* @3976956 call */
    GM_SITE(vm, 160, 3976956);
    /* @3976964 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3976968: ;
    /* @3976968 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3976940;
    /* @3976972 constant */
    /* @3976976 cast */
    /* @3976980 load */
    /* @3976988 constant */
    /* @3976992 sub */
    /* @3976996 load */
    /* @3977004 constant */
    /* @3977008 add */
    /* @3977012 call */
    GM_SITE(vm, 160, 3977012);
    v47 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3977020 store */
    v48 = GM_CALL(vm, "instance_create", 3, v47, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v48);
    /* @3977028 load */
    /* @3977036 cast */
    /* @3977040 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3977072;
    L_3977044: ;
    /* @3977044 constant */
    /* @3977048 cast */
    /* @3977052 load */
    /* @3977060 call */
    GM_SITE(vm, 160, 3977060);
    /* @3977068 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3977072: ;
    /* @3977072 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3977044;
    /* @3977076 constant */
    /* @3977080 cast */
    /* @3977084 load */
    /* @3977092 constant */
    /* @3977096 sub */
    /* @3977100 load */
    /* @3977108 constant */
    /* @3977112 sub */
    /* @3977116 call */
    GM_SITE(vm, 160, 3977116);
    /* @3977124 store */
    v49 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v49);
    /* @3977132 load */
    /* @3977140 cast */
    /* @3977144 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3977176;
    L_3977148: ;
    /* @3977148 constant */
    /* @3977152 cast */
    /* @3977156 load */
    /* @3977164 call */
    GM_SITE(vm, 160, 3977164);
    /* @3977172 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_3977176: ;
    /* @3977176 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3977148;
    /* @3977180 constant */
    /* @3977184 cast */
    /* @3977188 load */
    /* @3977196 constant */
    /* @3977200 sub */
    /* @3977204 load */
    /* @3977212 constant */
    /* @3977216 add */
    /* @3977220 call */
    GM_SITE(vm, 160, 3977220);
    v50 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @3977228 store */
    v51 = GM_CALL(vm, "instance_create", 3, v50, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v51);
    /* @3977236 load */
    /* @3977244 cast */
    /* @3977248 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_3977280;
    L_3977252: ;
    /* @3977252 constant */
    /* @3977256 cast */
    /* @3977260 load */
    /* @3977268 call */
    GM_SITE(vm, 160, 3977268);
    /* @3977276 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_3977280: ;
    /* @3977280 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3977252;
    /* @3977284 constant */
    /* @3977288 cast */
    /* @3977292 load */
    /* @3977300 constant */
    /* @3977304 sub */
    /* @3977308 load */
    /* @3977316 constant */
    /* @3977320 add */
    /* @3977324 call */
    GM_SITE(vm, 160, 3977324);
    v52 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @3977332 store */
    v53 = GM_CALL(vm, "instance_create", 3, v52, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID12", v53);
    /* @3977340 load */
    /* @3977348 cast */
    /* @3977352 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID12")))) goto L_3977384;
    L_3977356: ;
    /* @3977356 constant */
    /* @3977360 cast */
    /* @3977364 load */
    /* @3977372 call */
    GM_SITE(vm, 160, 3977372);
    /* @3977380 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread12"), VAL(5)));
    L_3977384: ;
    /* @3977384 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3977356;
    /* @3977388 constant */
    /* @3977392 cast */
    /* @3977396 load */
    /* @3977404 constant */
    /* @3977408 sub */
    /* @3977412 load */
    /* @3977420 constant */
    /* @3977424 sub */
    /* @3977428 call */
    GM_SITE(vm, 160, 3977428);
    /* @3977436 store */
    v54 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID13", v54);
    /* @3977444 load */
    /* @3977452 cast */
    /* @3977456 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID13")))) goto L_3977488;
    L_3977460: ;
    /* @3977460 constant */
    /* @3977464 cast */
    /* @3977468 load */
    /* @3977476 call */
    GM_SITE(vm, 160, 3977476);
    /* @3977484 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread13"), VAL(5)));
    L_3977488: ;
    /* @3977488 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3977460;
    /* @3977492 constant */
    /* @3977496 cast */
    /* @3977500 load */
    /* @3977508 constant */
    /* @3977512 sub */
    /* @3977516 load */
    /* @3977524 constant */
    /* @3977528 add */
    /* @3977532 call */
    GM_SITE(vm, 160, 3977532);
    v55 = GM_ADD(GM_READ(vm, -1, "x"), VAL(12));
    /* @3977540 store */
    v56 = GM_CALL(vm, "instance_create", 3, v55, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID14", v56);
    /* @3977548 load */
    /* @3977556 cast */
    /* @3977560 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID14")))) goto L_3977592;
    L_3977564: ;
    /* @3977564 constant */
    /* @3977568 cast */
    /* @3977572 load */
    /* @3977580 call */
    GM_SITE(vm, 160, 3977580);
    /* @3977588 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread14"), VAL(5)));
    L_3977592: ;
    /* @3977592 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3977564;
    /* @3977596 constant */
    /* @3977600 cast */
    /* @3977604 load */
    /* @3977612 constant */
    /* @3977616 sub */
    /* @3977620 load */
    /* @3977628 constant */
    /* @3977632 sub */
    /* @3977636 call */
    GM_SITE(vm, 160, 3977636);
    /* @3977644 store */
    v57 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(12)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID15", v57);
    /* @3977652 load */
    /* @3977660 cast */
    /* @3977664 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID15")))) goto L_3977696;
    L_3977668: ;
    /* @3977668 constant */
    /* @3977672 cast */
    /* @3977676 load */
    /* @3977684 call */
    GM_SITE(vm, 160, 3977684);
    /* @3977692 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread15"), VAL(5)));
    L_3977696: ;
    /* @3977696 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3977668;
    L_3977700: ;
    /* @3977700 load */
    /* @3977708 constant */
    /* @3977712 cmp */
    /* @3977716 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(4)))) goto L_3979792;
    /* @3977720 constant */
    /* @3977724 cast */
    /* @3977728 load */
    /* @3977736 constant */
    /* @3977740 sub */
    /* @3977744 load */
    /* @3977752 call */
    GM_SITE(vm, 160, 3977752);
    /* @3977760 store */
    v58 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v58);
    /* @3977768 load */
    /* @3977776 cast */
    /* @3977780 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3977812;
    L_3977784: ;
    /* @3977784 constant */
    /* @3977788 cast */
    /* @3977792 load */
    /* @3977800 call */
    GM_SITE(vm, 160, 3977800);
    /* @3977808 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3977812: ;
    /* @3977812 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3977784;
    /* @3977816 constant */
    /* @3977820 cast */
    /* @3977824 load */
    /* @3977832 constant */
    /* @3977836 sub */
    /* @3977840 load */
    /* @3977848 constant */
    /* @3977852 add */
    /* @3977856 call */
    GM_SITE(vm, 160, 3977856);
    v59 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3977864 store */
    v60 = GM_CALL(vm, "instance_create", 3, v59, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v60);
    /* @3977872 load */
    /* @3977880 cast */
    /* @3977884 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3977916;
    L_3977888: ;
    /* @3977888 constant */
    /* @3977892 cast */
    /* @3977896 load */
    /* @3977904 call */
    GM_SITE(vm, 160, 3977904);
    /* @3977912 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3977916: ;
    /* @3977916 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3977888;
    /* @3977920 constant */
    /* @3977924 cast */
    /* @3977928 load */
    /* @3977936 constant */
    /* @3977940 sub */
    /* @3977944 load */
    /* @3977952 constant */
    /* @3977956 sub */
    /* @3977960 call */
    GM_SITE(vm, 160, 3977960);
    /* @3977968 store */
    v61 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v61);
    /* @3977976 load */
    /* @3977984 cast */
    /* @3977988 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3978020;
    L_3977992: ;
    /* @3977992 constant */
    /* @3977996 cast */
    /* @3978000 load */
    /* @3978008 call */
    GM_SITE(vm, 160, 3978008);
    /* @3978016 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3978020: ;
    /* @3978020 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3977992;
    /* @3978024 constant */
    /* @3978028 cast */
    /* @3978032 load */
    /* @3978040 constant */
    /* @3978044 sub */
    /* @3978048 load */
    /* @3978056 constant */
    /* @3978060 add */
    /* @3978064 call */
    GM_SITE(vm, 160, 3978064);
    v62 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3978072 store */
    v63 = GM_CALL(vm, "instance_create", 3, v62, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v63);
    /* @3978080 load */
    /* @3978088 cast */
    /* @3978092 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3978124;
    L_3978096: ;
    /* @3978096 constant */
    /* @3978100 cast */
    /* @3978104 load */
    /* @3978112 call */
    GM_SITE(vm, 160, 3978112);
    /* @3978120 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3978124: ;
    /* @3978124 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3978096;
    /* @3978128 constant */
    /* @3978132 cast */
    /* @3978136 load */
    /* @3978144 constant */
    /* @3978148 sub */
    /* @3978152 load */
    /* @3978160 constant */
    /* @3978164 sub */
    /* @3978168 call */
    GM_SITE(vm, 160, 3978168);
    /* @3978176 store */
    v64 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v64);
    /* @3978184 load */
    /* @3978192 cast */
    /* @3978196 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3978228;
    L_3978200: ;
    /* @3978200 constant */
    /* @3978204 cast */
    /* @3978208 load */
    /* @3978216 call */
    GM_SITE(vm, 160, 3978216);
    /* @3978224 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3978228: ;
    /* @3978228 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3978200;
    /* @3978232 constant */
    /* @3978236 cast */
    /* @3978240 load */
    /* @3978248 constant */
    /* @3978252 sub */
    /* @3978256 load */
    /* @3978264 constant */
    /* @3978268 add */
    /* @3978272 call */
    GM_SITE(vm, 160, 3978272);
    v65 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @3978280 store */
    v66 = GM_CALL(vm, "instance_create", 3, v65, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v66);
    /* @3978288 load */
    /* @3978296 cast */
    /* @3978300 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3978332;
    L_3978304: ;
    /* @3978304 constant */
    /* @3978308 cast */
    /* @3978312 load */
    /* @3978320 call */
    GM_SITE(vm, 160, 3978320);
    /* @3978328 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3978332: ;
    /* @3978332 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3978304;
    /* @3978336 constant */
    /* @3978340 cast */
    /* @3978344 load */
    /* @3978352 constant */
    /* @3978356 sub */
    /* @3978360 load */
    /* @3978368 constant */
    /* @3978372 add */
    /* @3978376 call */
    GM_SITE(vm, 160, 3978376);
    v67 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3978384 store */
    v68 = GM_CALL(vm, "instance_create", 3, v67, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v68);
    /* @3978392 load */
    /* @3978400 cast */
    /* @3978404 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3978436;
    L_3978408: ;
    /* @3978408 constant */
    /* @3978412 cast */
    /* @3978416 load */
    /* @3978424 call */
    GM_SITE(vm, 160, 3978424);
    /* @3978432 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3978436: ;
    /* @3978436 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3978408;
    /* @3978440 constant */
    /* @3978444 cast */
    /* @3978448 load */
    /* @3978456 constant */
    /* @3978460 sub */
    /* @3978464 load */
    /* @3978472 constant */
    /* @3978476 sub */
    /* @3978480 call */
    GM_SITE(vm, 160, 3978480);
    /* @3978488 store */
    v69 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v69);
    /* @3978496 load */
    /* @3978504 cast */
    /* @3978508 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3978540;
    L_3978512: ;
    /* @3978512 constant */
    /* @3978516 cast */
    /* @3978520 load */
    /* @3978528 call */
    GM_SITE(vm, 160, 3978528);
    /* @3978536 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3978540: ;
    /* @3978540 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3978512;
    /* @3978544 constant */
    /* @3978548 cast */
    /* @3978552 load */
    /* @3978560 constant */
    /* @3978564 sub */
    /* @3978568 load */
    /* @3978576 constant */
    /* @3978580 add */
    /* @3978584 call */
    GM_SITE(vm, 160, 3978584);
    v70 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3978592 store */
    v71 = GM_CALL(vm, "instance_create", 3, v70, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v71);
    /* @3978600 load */
    /* @3978608 cast */
    /* @3978612 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3978644;
    L_3978616: ;
    /* @3978616 constant */
    /* @3978620 cast */
    /* @3978624 load */
    /* @3978632 call */
    GM_SITE(vm, 160, 3978632);
    /* @3978640 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3978644: ;
    /* @3978644 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3978616;
    /* @3978648 constant */
    /* @3978652 cast */
    /* @3978656 load */
    /* @3978664 constant */
    /* @3978668 sub */
    /* @3978672 load */
    /* @3978680 constant */
    /* @3978684 sub */
    /* @3978688 call */
    GM_SITE(vm, 160, 3978688);
    /* @3978696 store */
    v72 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v72);
    /* @3978704 load */
    /* @3978712 cast */
    /* @3978716 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3978748;
    L_3978720: ;
    /* @3978720 constant */
    /* @3978724 cast */
    /* @3978728 load */
    /* @3978736 call */
    GM_SITE(vm, 160, 3978736);
    /* @3978744 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_3978748: ;
    /* @3978748 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3978720;
    /* @3978752 constant */
    /* @3978756 cast */
    /* @3978760 load */
    /* @3978768 constant */
    /* @3978772 sub */
    /* @3978776 load */
    /* @3978784 constant */
    /* @3978788 sub */
    /* @3978792 call */
    GM_SITE(vm, 160, 3978792);
    /* @3978800 store */
    v73 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v73);
    /* @3978808 load */
    /* @3978816 cast */
    /* @3978820 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_3978852;
    L_3978824: ;
    /* @3978824 constant */
    /* @3978828 cast */
    /* @3978832 load */
    /* @3978840 call */
    GM_SITE(vm, 160, 3978840);
    /* @3978848 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_3978852: ;
    /* @3978852 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3978824;
    /* @3978856 constant */
    /* @3978860 cast */
    /* @3978864 load */
    /* @3978872 constant */
    /* @3978876 sub */
    /* @3978880 load */
    /* @3978888 constant */
    /* @3978892 add */
    /* @3978896 call */
    GM_SITE(vm, 160, 3978896);
    v74 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @3978904 store */
    v75 = GM_CALL(vm, "instance_create", 3, v74, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID12", v75);
    /* @3978912 load */
    /* @3978920 cast */
    /* @3978924 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID12")))) goto L_3978956;
    L_3978928: ;
    /* @3978928 constant */
    /* @3978932 cast */
    /* @3978936 load */
    /* @3978944 call */
    GM_SITE(vm, 160, 3978944);
    /* @3978952 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread12"), VAL(5)));
    L_3978956: ;
    /* @3978956 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3978928;
    /* @3978960 constant */
    /* @3978964 cast */
    /* @3978968 load */
    /* @3978976 constant */
    /* @3978980 sub */
    /* @3978984 load */
    /* @3978992 constant */
    /* @3978996 sub */
    /* @3979000 call */
    GM_SITE(vm, 160, 3979000);
    /* @3979008 store */
    v76 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID13", v76);
    /* @3979016 load */
    /* @3979024 cast */
    /* @3979028 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID13")))) goto L_3979060;
    L_3979032: ;
    /* @3979032 constant */
    /* @3979036 cast */
    /* @3979040 load */
    /* @3979048 call */
    GM_SITE(vm, 160, 3979048);
    /* @3979056 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread13"), VAL(5)));
    L_3979060: ;
    /* @3979060 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3979032;
    /* @3979064 constant */
    /* @3979068 cast */
    /* @3979072 load */
    /* @3979080 constant */
    /* @3979084 sub */
    /* @3979088 load */
    /* @3979096 constant */
    /* @3979100 add */
    /* @3979104 call */
    GM_SITE(vm, 160, 3979104);
    v77 = GM_ADD(GM_READ(vm, -1, "x"), VAL(12));
    /* @3979112 store */
    v78 = GM_CALL(vm, "instance_create", 3, v77, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID14", v78);
    /* @3979120 load */
    /* @3979128 cast */
    /* @3979132 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID14")))) goto L_3979164;
    L_3979136: ;
    /* @3979136 constant */
    /* @3979140 cast */
    /* @3979144 load */
    /* @3979152 call */
    GM_SITE(vm, 160, 3979152);
    /* @3979160 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread14"), VAL(5)));
    L_3979164: ;
    /* @3979164 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3979136;
    /* @3979168 constant */
    /* @3979172 cast */
    /* @3979176 load */
    /* @3979184 constant */
    /* @3979188 sub */
    /* @3979192 load */
    /* @3979200 constant */
    /* @3979204 sub */
    /* @3979208 call */
    GM_SITE(vm, 160, 3979208);
    /* @3979216 store */
    v79 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(12)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID15", v79);
    /* @3979224 load */
    /* @3979232 cast */
    /* @3979236 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID15")))) goto L_3979268;
    L_3979240: ;
    /* @3979240 constant */
    /* @3979244 cast */
    /* @3979248 load */
    /* @3979256 call */
    GM_SITE(vm, 160, 3979256);
    /* @3979264 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread15"), VAL(5)));
    L_3979268: ;
    /* @3979268 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3979240;
    /* @3979272 constant */
    /* @3979276 cast */
    /* @3979280 load */
    /* @3979288 constant */
    /* @3979292 sub */
    /* @3979296 load */
    /* @3979304 constant */
    /* @3979308 sub */
    /* @3979312 call */
    GM_SITE(vm, 160, 3979312);
    /* @3979320 store */
    v80 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID16", v80);
    /* @3979328 load */
    /* @3979336 cast */
    /* @3979340 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID16")))) goto L_3979372;
    L_3979344: ;
    /* @3979344 constant */
    /* @3979348 cast */
    /* @3979352 load */
    /* @3979360 call */
    GM_SITE(vm, 160, 3979360);
    /* @3979368 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread16"), VAL(5)));
    L_3979372: ;
    /* @3979372 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3979344;
    /* @3979376 constant */
    /* @3979380 cast */
    /* @3979384 load */
    /* @3979392 constant */
    /* @3979396 sub */
    /* @3979400 load */
    /* @3979408 constant */
    /* @3979412 add */
    /* @3979416 call */
    GM_SITE(vm, 160, 3979416);
    v81 = GM_ADD(GM_READ(vm, -1, "x"), VAL(14));
    /* @3979424 store */
    v82 = GM_CALL(vm, "instance_create", 3, v81, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID17", v82);
    /* @3979432 load */
    /* @3979440 cast */
    /* @3979444 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID17")))) goto L_3979476;
    L_3979448: ;
    /* @3979448 constant */
    /* @3979452 cast */
    /* @3979456 load */
    /* @3979464 call */
    GM_SITE(vm, 160, 3979464);
    /* @3979472 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread17"), VAL(5)));
    L_3979476: ;
    /* @3979476 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3979448;
    /* @3979480 constant */
    /* @3979484 cast */
    /* @3979488 load */
    /* @3979496 constant */
    /* @3979500 sub */
    /* @3979504 load */
    /* @3979512 constant */
    /* @3979516 sub */
    /* @3979520 call */
    GM_SITE(vm, 160, 3979520);
    /* @3979528 store */
    v83 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(14)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID18", v83);
    /* @3979536 load */
    /* @3979544 cast */
    /* @3979548 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID18")))) goto L_3979580;
    L_3979552: ;
    /* @3979552 constant */
    /* @3979556 cast */
    /* @3979560 load */
    /* @3979568 call */
    GM_SITE(vm, 160, 3979568);
    /* @3979576 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread18"), VAL(5)));
    L_3979580: ;
    /* @3979580 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3979552;
    /* @3979584 constant */
    /* @3979588 cast */
    /* @3979592 load */
    /* @3979600 constant */
    /* @3979604 sub */
    /* @3979608 load */
    /* @3979616 constant */
    /* @3979620 add */
    /* @3979624 call */
    GM_SITE(vm, 160, 3979624);
    v84 = GM_ADD(GM_READ(vm, -1, "x"), VAL(16));
    /* @3979632 store */
    v85 = GM_CALL(vm, "instance_create", 3, v84, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID19", v85);
    /* @3979640 load */
    /* @3979648 cast */
    /* @3979652 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID19")))) goto L_3979684;
    L_3979656: ;
    /* @3979656 constant */
    /* @3979660 cast */
    /* @3979664 load */
    /* @3979672 call */
    GM_SITE(vm, 160, 3979672);
    /* @3979680 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread19"), VAL(5)));
    L_3979684: ;
    /* @3979684 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3979656;
    /* @3979688 constant */
    /* @3979692 cast */
    /* @3979696 load */
    /* @3979704 constant */
    /* @3979708 sub */
    /* @3979712 load */
    /* @3979720 constant */
    /* @3979724 sub */
    /* @3979728 call */
    GM_SITE(vm, 160, 3979728);
    /* @3979736 store */
    v86 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(16)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID20", v86);
    /* @3979744 load */
    /* @3979752 cast */
    /* @3979756 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID20")))) goto L_3979788;
    L_3979760: ;
    /* @3979760 constant */
    /* @3979764 cast */
    /* @3979768 load */
    /* @3979776 call */
    GM_SITE(vm, 160, 3979776);
    /* @3979784 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread20"), VAL(5)));
    L_3979788: ;
    /* @3979788 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3979760;
    L_3979792: ;
    /* @3979792 load */
    /* @3979800 constant */
    /* @3979804 cmp */
    /* @3979808 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(5)))) goto L_3982404;
    /* @3979812 constant */
    /* @3979816 cast */
    /* @3979820 load */
    /* @3979828 constant */
    /* @3979832 sub */
    /* @3979836 load */
    /* @3979844 call */
    GM_SITE(vm, 160, 3979844);
    /* @3979852 store */
    v87 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v87);
    /* @3979860 load */
    /* @3979868 cast */
    /* @3979872 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3979904;
    L_3979876: ;
    /* @3979876 constant */
    /* @3979880 cast */
    /* @3979884 load */
    /* @3979892 call */
    GM_SITE(vm, 160, 3979892);
    /* @3979900 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3979904: ;
    /* @3979904 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3979876;
    /* @3979908 constant */
    /* @3979912 cast */
    /* @3979916 load */
    /* @3979924 constant */
    /* @3979928 sub */
    /* @3979932 load */
    /* @3979940 constant */
    /* @3979944 add */
    /* @3979948 call */
    GM_SITE(vm, 160, 3979948);
    v88 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3979956 store */
    v89 = GM_CALL(vm, "instance_create", 3, v88, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v89);
    /* @3979964 load */
    /* @3979972 cast */
    /* @3979976 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3980008;
    L_3979980: ;
    /* @3979980 constant */
    /* @3979984 cast */
    /* @3979988 load */
    /* @3979996 call */
    GM_SITE(vm, 160, 3979996);
    /* @3980004 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3980008: ;
    /* @3980008 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3979980;
    /* @3980012 constant */
    /* @3980016 cast */
    /* @3980020 load */
    /* @3980028 constant */
    /* @3980032 sub */
    /* @3980036 load */
    /* @3980044 constant */
    /* @3980048 sub */
    /* @3980052 call */
    GM_SITE(vm, 160, 3980052);
    /* @3980060 store */
    v90 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v90);
    /* @3980068 load */
    /* @3980076 cast */
    /* @3980080 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3980112;
    L_3980084: ;
    /* @3980084 constant */
    /* @3980088 cast */
    /* @3980092 load */
    /* @3980100 call */
    GM_SITE(vm, 160, 3980100);
    /* @3980108 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3980112: ;
    /* @3980112 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3980084;
    /* @3980116 constant */
    /* @3980120 cast */
    /* @3980124 load */
    /* @3980132 constant */
    /* @3980136 sub */
    /* @3980140 load */
    /* @3980148 constant */
    /* @3980152 add */
    /* @3980156 call */
    GM_SITE(vm, 160, 3980156);
    v91 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3980164 store */
    v92 = GM_CALL(vm, "instance_create", 3, v91, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v92);
    /* @3980172 load */
    /* @3980180 cast */
    /* @3980184 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3980216;
    L_3980188: ;
    /* @3980188 constant */
    /* @3980192 cast */
    /* @3980196 load */
    /* @3980204 call */
    GM_SITE(vm, 160, 3980204);
    /* @3980212 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3980216: ;
    /* @3980216 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3980188;
    /* @3980220 constant */
    /* @3980224 cast */
    /* @3980228 load */
    /* @3980236 constant */
    /* @3980240 sub */
    /* @3980244 load */
    /* @3980252 constant */
    /* @3980256 sub */
    /* @3980260 call */
    GM_SITE(vm, 160, 3980260);
    /* @3980268 store */
    v93 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v93);
    /* @3980276 load */
    /* @3980284 cast */
    /* @3980288 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3980320;
    L_3980292: ;
    /* @3980292 constant */
    /* @3980296 cast */
    /* @3980300 load */
    /* @3980308 call */
    GM_SITE(vm, 160, 3980308);
    /* @3980316 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3980320: ;
    /* @3980320 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3980292;
    /* @3980324 constant */
    /* @3980328 cast */
    /* @3980332 load */
    /* @3980340 constant */
    /* @3980344 sub */
    /* @3980348 load */
    /* @3980356 constant */
    /* @3980360 add */
    /* @3980364 call */
    GM_SITE(vm, 160, 3980364);
    v94 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @3980372 store */
    v95 = GM_CALL(vm, "instance_create", 3, v94, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v95);
    /* @3980380 load */
    /* @3980388 cast */
    /* @3980392 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3980424;
    L_3980396: ;
    /* @3980396 constant */
    /* @3980400 cast */
    /* @3980404 load */
    /* @3980412 call */
    GM_SITE(vm, 160, 3980412);
    /* @3980420 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3980424: ;
    /* @3980424 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3980396;
    /* @3980428 constant */
    /* @3980432 cast */
    /* @3980436 load */
    /* @3980444 constant */
    /* @3980448 sub */
    /* @3980452 load */
    /* @3980460 constant */
    /* @3980464 add */
    /* @3980468 call */
    GM_SITE(vm, 160, 3980468);
    v96 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3980476 store */
    v97 = GM_CALL(vm, "instance_create", 3, v96, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v97);
    /* @3980484 load */
    /* @3980492 cast */
    /* @3980496 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3980528;
    L_3980500: ;
    /* @3980500 constant */
    /* @3980504 cast */
    /* @3980508 load */
    /* @3980516 call */
    GM_SITE(vm, 160, 3980516);
    /* @3980524 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3980528: ;
    /* @3980528 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3980500;
    /* @3980532 constant */
    /* @3980536 cast */
    /* @3980540 load */
    /* @3980548 constant */
    /* @3980552 sub */
    /* @3980556 load */
    /* @3980564 constant */
    /* @3980568 sub */
    /* @3980572 call */
    GM_SITE(vm, 160, 3980572);
    /* @3980580 store */
    v98 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v98);
    /* @3980588 load */
    /* @3980596 cast */
    /* @3980600 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3980632;
    L_3980604: ;
    /* @3980604 constant */
    /* @3980608 cast */
    /* @3980612 load */
    /* @3980620 call */
    GM_SITE(vm, 160, 3980620);
    /* @3980628 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3980632: ;
    /* @3980632 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3980604;
    /* @3980636 constant */
    /* @3980640 cast */
    /* @3980644 load */
    /* @3980652 constant */
    /* @3980656 sub */
    /* @3980660 load */
    /* @3980668 constant */
    /* @3980672 add */
    /* @3980676 call */
    GM_SITE(vm, 160, 3980676);
    v99 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3980684 store */
    v100 = GM_CALL(vm, "instance_create", 3, v99, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v100);
    /* @3980692 load */
    /* @3980700 cast */
    /* @3980704 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3980736;
    L_3980708: ;
    /* @3980708 constant */
    /* @3980712 cast */
    /* @3980716 load */
    /* @3980724 call */
    GM_SITE(vm, 160, 3980724);
    /* @3980732 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3980736: ;
    /* @3980736 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3980708;
    /* @3980740 constant */
    /* @3980744 cast */
    /* @3980748 load */
    /* @3980756 constant */
    /* @3980760 sub */
    /* @3980764 load */
    /* @3980772 constant */
    /* @3980776 sub */
    /* @3980780 call */
    GM_SITE(vm, 160, 3980780);
    /* @3980788 store */
    v101 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v101);
    /* @3980796 load */
    /* @3980804 cast */
    /* @3980808 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3980840;
    L_3980812: ;
    /* @3980812 constant */
    /* @3980816 cast */
    /* @3980820 load */
    /* @3980828 call */
    GM_SITE(vm, 160, 3980828);
    /* @3980836 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_3980840: ;
    /* @3980840 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3980812;
    /* @3980844 constant */
    /* @3980848 cast */
    /* @3980852 load */
    /* @3980860 constant */
    /* @3980864 sub */
    /* @3980868 load */
    /* @3980876 constant */
    /* @3980880 sub */
    /* @3980884 call */
    GM_SITE(vm, 160, 3980884);
    /* @3980892 store */
    v102 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v102);
    /* @3980900 load */
    /* @3980908 cast */
    /* @3980912 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_3980944;
    L_3980916: ;
    /* @3980916 constant */
    /* @3980920 cast */
    /* @3980924 load */
    /* @3980932 call */
    GM_SITE(vm, 160, 3980932);
    /* @3980940 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_3980944: ;
    /* @3980944 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3980916;
    /* @3980948 constant */
    /* @3980952 cast */
    /* @3980956 load */
    /* @3980964 constant */
    /* @3980968 sub */
    /* @3980972 load */
    /* @3980980 constant */
    /* @3980984 add */
    /* @3980988 call */
    GM_SITE(vm, 160, 3980988);
    v103 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @3980996 store */
    v104 = GM_CALL(vm, "instance_create", 3, v103, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID12", v104);
    /* @3981004 load */
    /* @3981012 cast */
    /* @3981016 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID12")))) goto L_3981048;
    L_3981020: ;
    /* @3981020 constant */
    /* @3981024 cast */
    /* @3981028 load */
    /* @3981036 call */
    GM_SITE(vm, 160, 3981036);
    /* @3981044 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread12"), VAL(5)));
    L_3981048: ;
    /* @3981048 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3981020;
    /* @3981052 constant */
    /* @3981056 cast */
    /* @3981060 load */
    /* @3981068 constant */
    /* @3981072 sub */
    /* @3981076 load */
    /* @3981084 constant */
    /* @3981088 sub */
    /* @3981092 call */
    GM_SITE(vm, 160, 3981092);
    /* @3981100 store */
    v105 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID13", v105);
    /* @3981108 load */
    /* @3981116 cast */
    /* @3981120 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID13")))) goto L_3981152;
    L_3981124: ;
    /* @3981124 constant */
    /* @3981128 cast */
    /* @3981132 load */
    /* @3981140 call */
    GM_SITE(vm, 160, 3981140);
    /* @3981148 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread13"), VAL(5)));
    L_3981152: ;
    /* @3981152 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3981124;
    /* @3981156 constant */
    /* @3981160 cast */
    /* @3981164 load */
    /* @3981172 constant */
    /* @3981176 sub */
    /* @3981180 load */
    /* @3981188 constant */
    /* @3981192 add */
    /* @3981196 call */
    GM_SITE(vm, 160, 3981196);
    v106 = GM_ADD(GM_READ(vm, -1, "x"), VAL(12));
    /* @3981204 store */
    v107 = GM_CALL(vm, "instance_create", 3, v106, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID14", v107);
    /* @3981212 load */
    /* @3981220 cast */
    /* @3981224 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID14")))) goto L_3981256;
    L_3981228: ;
    /* @3981228 constant */
    /* @3981232 cast */
    /* @3981236 load */
    /* @3981244 call */
    GM_SITE(vm, 160, 3981244);
    /* @3981252 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread14"), VAL(5)));
    L_3981256: ;
    /* @3981256 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3981228;
    /* @3981260 constant */
    /* @3981264 cast */
    /* @3981268 load */
    /* @3981276 constant */
    /* @3981280 sub */
    /* @3981284 load */
    /* @3981292 constant */
    /* @3981296 sub */
    /* @3981300 call */
    GM_SITE(vm, 160, 3981300);
    /* @3981308 store */
    v108 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(12)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID15", v108);
    /* @3981316 load */
    /* @3981324 cast */
    /* @3981328 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID15")))) goto L_3981360;
    L_3981332: ;
    /* @3981332 constant */
    /* @3981336 cast */
    /* @3981340 load */
    /* @3981348 call */
    GM_SITE(vm, 160, 3981348);
    /* @3981356 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread15"), VAL(5)));
    L_3981360: ;
    /* @3981360 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3981332;
    /* @3981364 constant */
    /* @3981368 cast */
    /* @3981372 load */
    /* @3981380 constant */
    /* @3981384 sub */
    /* @3981388 load */
    /* @3981396 constant */
    /* @3981400 add */
    /* @3981404 call */
    GM_SITE(vm, 160, 3981404);
    v109 = GM_ADD(GM_READ(vm, -1, "x"), VAL(15));
    /* @3981412 store */
    v110 = GM_CALL(vm, "instance_create", 3, v109, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID16", v110);
    /* @3981420 load */
    /* @3981428 cast */
    /* @3981432 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID16")))) goto L_3981464;
    L_3981436: ;
    /* @3981436 constant */
    /* @3981440 cast */
    /* @3981444 load */
    /* @3981452 call */
    GM_SITE(vm, 160, 3981452);
    /* @3981460 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread16"), VAL(5)));
    L_3981464: ;
    /* @3981464 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3981436;
    /* @3981468 constant */
    /* @3981472 cast */
    /* @3981476 load */
    /* @3981484 constant */
    /* @3981488 sub */
    /* @3981492 load */
    /* @3981500 constant */
    /* @3981504 add */
    /* @3981508 call */
    GM_SITE(vm, 160, 3981508);
    v111 = GM_ADD(GM_READ(vm, -1, "x"), VAL(14));
    /* @3981516 store */
    v112 = GM_CALL(vm, "instance_create", 3, v111, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID17", v112);
    /* @3981524 load */
    /* @3981532 cast */
    /* @3981536 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID17")))) goto L_3981568;
    L_3981540: ;
    /* @3981540 constant */
    /* @3981544 cast */
    /* @3981548 load */
    /* @3981556 call */
    GM_SITE(vm, 160, 3981556);
    /* @3981564 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread17"), VAL(5)));
    L_3981568: ;
    /* @3981568 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3981540;
    /* @3981572 constant */
    /* @3981576 cast */
    /* @3981580 load */
    /* @3981588 constant */
    /* @3981592 sub */
    /* @3981596 load */
    /* @3981604 constant */
    /* @3981608 sub */
    /* @3981612 call */
    GM_SITE(vm, 160, 3981612);
    /* @3981620 store */
    v113 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(14)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID18", v113);
    /* @3981628 load */
    /* @3981636 cast */
    /* @3981640 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID18")))) goto L_3981672;
    L_3981644: ;
    /* @3981644 constant */
    /* @3981648 cast */
    /* @3981652 load */
    /* @3981660 call */
    GM_SITE(vm, 160, 3981660);
    /* @3981668 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread18"), VAL(5)));
    L_3981672: ;
    /* @3981672 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3981644;
    /* @3981676 constant */
    /* @3981680 cast */
    /* @3981684 load */
    /* @3981692 constant */
    /* @3981696 sub */
    /* @3981700 load */
    /* @3981708 constant */
    /* @3981712 add */
    /* @3981716 call */
    GM_SITE(vm, 160, 3981716);
    v114 = GM_ADD(GM_READ(vm, -1, "x"), VAL(16));
    /* @3981724 store */
    v115 = GM_CALL(vm, "instance_create", 3, v114, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID19", v115);
    /* @3981732 load */
    /* @3981740 cast */
    /* @3981744 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID19")))) goto L_3981776;
    L_3981748: ;
    /* @3981748 constant */
    /* @3981752 cast */
    /* @3981756 load */
    /* @3981764 call */
    GM_SITE(vm, 160, 3981764);
    /* @3981772 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread19"), VAL(5)));
    L_3981776: ;
    /* @3981776 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3981748;
    /* @3981780 constant */
    /* @3981784 cast */
    /* @3981788 load */
    /* @3981796 constant */
    /* @3981800 sub */
    /* @3981804 load */
    /* @3981812 constant */
    /* @3981816 sub */
    /* @3981820 call */
    GM_SITE(vm, 160, 3981820);
    /* @3981828 store */
    v116 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(16)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID20", v116);
    /* @3981836 load */
    /* @3981844 cast */
    /* @3981848 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID20")))) goto L_3981880;
    L_3981852: ;
    /* @3981852 constant */
    /* @3981856 cast */
    /* @3981860 load */
    /* @3981868 call */
    GM_SITE(vm, 160, 3981868);
    /* @3981876 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread20"), VAL(5)));
    L_3981880: ;
    /* @3981880 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3981852;
    /* @3981884 constant */
    /* @3981888 cast */
    /* @3981892 load */
    /* @3981900 constant */
    /* @3981904 sub */
    /* @3981908 load */
    /* @3981916 constant */
    /* @3981920 sub */
    /* @3981924 call */
    GM_SITE(vm, 160, 3981924);
    /* @3981932 store */
    v117 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(15)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID21", v117);
    /* @3981940 load */
    /* @3981948 cast */
    /* @3981952 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID21")))) goto L_3981984;
    L_3981956: ;
    /* @3981956 constant */
    /* @3981960 cast */
    /* @3981964 load */
    /* @3981972 call */
    GM_SITE(vm, 160, 3981972);
    /* @3981980 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread21"), VAL(5)));
    L_3981984: ;
    /* @3981984 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3981956;
    /* @3981988 constant */
    /* @3981992 cast */
    /* @3981996 load */
    /* @3982004 constant */
    /* @3982008 sub */
    /* @3982012 load */
    /* @3982020 constant */
    /* @3982024 add */
    /* @3982028 call */
    GM_SITE(vm, 160, 3982028);
    v118 = GM_ADD(GM_READ(vm, -1, "x"), VAL(18));
    /* @3982036 store */
    v119 = GM_CALL(vm, "instance_create", 3, v118, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID22", v119);
    /* @3982044 load */
    /* @3982052 cast */
    /* @3982056 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID22")))) goto L_3982088;
    L_3982060: ;
    /* @3982060 constant */
    /* @3982064 cast */
    /* @3982068 load */
    /* @3982076 call */
    GM_SITE(vm, 160, 3982076);
    /* @3982084 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread22"), VAL(5)));
    L_3982088: ;
    /* @3982088 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3982060;
    /* @3982092 constant */
    /* @3982096 cast */
    /* @3982100 load */
    /* @3982108 constant */
    /* @3982112 sub */
    /* @3982116 load */
    /* @3982124 constant */
    /* @3982128 sub */
    /* @3982132 call */
    GM_SITE(vm, 160, 3982132);
    /* @3982140 store */
    v120 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(18)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID23", v120);
    /* @3982148 load */
    /* @3982156 cast */
    /* @3982160 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID23")))) goto L_3982192;
    L_3982164: ;
    /* @3982164 constant */
    /* @3982168 cast */
    /* @3982172 load */
    /* @3982180 call */
    GM_SITE(vm, 160, 3982180);
    /* @3982188 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread23"), VAL(5)));
    L_3982192: ;
    /* @3982192 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3982164;
    /* @3982196 constant */
    /* @3982200 cast */
    /* @3982204 load */
    /* @3982212 constant */
    /* @3982216 sub */
    /* @3982220 load */
    /* @3982228 constant */
    /* @3982232 add */
    /* @3982236 call */
    GM_SITE(vm, 160, 3982236);
    v121 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @3982244 store */
    v122 = GM_CALL(vm, "instance_create", 3, v121, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID24", v122);
    /* @3982252 load */
    /* @3982260 cast */
    /* @3982264 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID24")))) goto L_3982296;
    L_3982268: ;
    /* @3982268 constant */
    /* @3982272 cast */
    /* @3982276 load */
    /* @3982284 call */
    GM_SITE(vm, 160, 3982284);
    /* @3982292 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread24"), VAL(5)));
    L_3982296: ;
    /* @3982296 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3982268;
    /* @3982300 constant */
    /* @3982304 cast */
    /* @3982308 load */
    /* @3982316 constant */
    /* @3982320 sub */
    /* @3982324 load */
    /* @3982332 constant */
    /* @3982336 sub */
    /* @3982340 call */
    GM_SITE(vm, 160, 3982340);
    /* @3982348 store */
    v123 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(20)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID25", v123);
    /* @3982356 load */
    /* @3982364 cast */
    /* @3982368 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID25")))) goto L_3982400;
    L_3982372: ;
    /* @3982372 constant */
    /* @3982376 cast */
    /* @3982380 load */
    /* @3982388 call */
    GM_SITE(vm, 160, 3982388);
    /* @3982396 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread25"), VAL(5)));
    L_3982400: ;
    /* @3982400 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3982372;
    L_3982404: ;
    /* @3982404 call */
    GM_SITE(vm, 160, 3982404);
    /* @3982412 popz */
    (void)(GM_CALL(vm, "action_kill_object", 0));
    L_3982416: ;
    return;
}
