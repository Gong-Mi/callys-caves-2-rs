/* generated from CODE 168 (gml_Object_obj_boss2_Alarm_0), source start 3984328, end 3993464. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0168(GmVM* vm) {
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
    /* @3984328 load */
    /* @3984336 constant */
    /* @3984340 cmp */
    /* @3984344 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3984352;
    /* @3984348 b */
    goto L_3984408;
    L_3984352: ;
    /* @3984352 load */
    /* @3984360 constant */
    /* @3984364 cmp */
    /* @3984368 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3984408;
    /* @3984372 constant */
    /* @3984376 cast */
    /* @3984380 constant */
    /* @3984384 cast */
    /* @3984388 constant */
    /* @3984392 cast */
    /* @3984396 call */
    GM_SITE(vm, 168, 3984396);
    /* @3984404 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(7), VAL(0), VAL(0)));
    L_3984408: ;
    /* @3984408 constant */
    /* @3984412 store */
    GM_WRITE(vm, -5, "boss2dead", VAL(1));
    /* @3984420 load */
    /* @3984428 constant */
    /* @3984432 cmp */
    /* @3984436 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "gemdropenabled") == VAL(1)))) goto L_3984484;
    /* @3984440 constant */
    /* @3984444 cast */
    /* @3984448 load */
    /* @3984456 constant */
    /* @3984460 sub */
    /* @3984464 load */
    /* @3984472 call */
    GM_SITE(vm, 168, 3984472);
    /* @3984480 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(59)));
    L_3984484: ;
    /* @3984484 load */
    /* @3984492 constant */
    /* @3984496 cmp */
    /* @3984500 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpdrop") == VAL(1)))) goto L_3984548;
    /* @3984504 constant */
    /* @3984508 cast */
    /* @3984512 load */
    /* @3984520 constant */
    /* @3984524 sub */
    /* @3984528 load */
    /* @3984536 call */
    GM_SITE(vm, 168, 3984536);
    /* @3984544 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(62)));
    L_3984548: ;
    /* @3984548 load */
    /* @3984556 constant */
    /* @3984560 cmp */
    /* @3984564 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "xpdrop") == VAL(1)))) goto L_3985592;
    /* @3984568 constant */
    /* @3984572 cast */
    /* @3984576 load */
    /* @3984584 constant */
    /* @3984588 sub */
    /* @3984592 load */
    /* @3984600 call */
    GM_SITE(vm, 168, 3984600);
    /* @3984608 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID", v1);
    /* @3984616 load */
    /* @3984624 cast */
    /* @3984628 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3984660;
    L_3984632: ;
    /* @3984632 constant */
    /* @3984636 cast */
    /* @3984640 load */
    /* @3984648 call */
    GM_SITE(vm, 168, 3984648);
    /* @3984656 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3984660: ;
    /* @3984660 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3984632;
    /* @3984664 constant */
    /* @3984668 cast */
    /* @3984672 load */
    /* @3984680 constant */
    /* @3984684 sub */
    /* @3984688 load */
    /* @3984696 constant */
    /* @3984700 add */
    /* @3984704 call */
    GM_SITE(vm, 168, 3984704);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(7));
    /* @3984712 store */
    v3 = GM_CALL(vm, "instance_create", 3, v2, (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID2", v3);
    /* @3984720 load */
    /* @3984728 cast */
    /* @3984732 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3984764;
    L_3984736: ;
    /* @3984736 constant */
    /* @3984740 cast */
    /* @3984744 load */
    /* @3984752 call */
    GM_SITE(vm, 168, 3984752);
    /* @3984760 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3984764: ;
    /* @3984764 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3984736;
    /* @3984768 constant */
    /* @3984772 cast */
    /* @3984776 load */
    /* @3984784 constant */
    /* @3984788 sub */
    /* @3984792 load */
    /* @3984800 constant */
    /* @3984804 sub */
    /* @3984808 call */
    GM_SITE(vm, 168, 3984808);
    /* @3984816 store */
    v4 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(7)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID3", v4);
    /* @3984824 load */
    /* @3984832 cast */
    /* @3984836 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3984868;
    L_3984840: ;
    /* @3984840 constant */
    /* @3984844 cast */
    /* @3984848 load */
    /* @3984856 call */
    GM_SITE(vm, 168, 3984856);
    /* @3984864 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3984868: ;
    /* @3984868 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3984840;
    /* @3984872 constant */
    /* @3984876 cast */
    /* @3984880 load */
    /* @3984888 constant */
    /* @3984892 sub */
    /* @3984896 load */
    /* @3984904 constant */
    /* @3984908 add */
    /* @3984912 call */
    GM_SITE(vm, 168, 3984912);
    v5 = GM_ADD(GM_READ(vm, -1, "x"), VAL(12));
    /* @3984920 store */
    v6 = GM_CALL(vm, "instance_create", 3, v5, (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID4", v6);
    /* @3984928 load */
    /* @3984936 cast */
    /* @3984940 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3984972;
    L_3984944: ;
    /* @3984944 constant */
    /* @3984948 cast */
    /* @3984952 load */
    /* @3984960 call */
    GM_SITE(vm, 168, 3984960);
    /* @3984968 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3984972: ;
    /* @3984972 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3984944;
    /* @3984976 constant */
    /* @3984980 cast */
    /* @3984984 load */
    /* @3984992 constant */
    /* @3984996 sub */
    /* @3985000 load */
    /* @3985008 constant */
    /* @3985012 sub */
    /* @3985016 call */
    GM_SITE(vm, 168, 3985016);
    /* @3985024 store */
    v7 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(12)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID5", v7);
    /* @3985032 load */
    /* @3985040 cast */
    /* @3985044 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3985076;
    L_3985048: ;
    /* @3985048 constant */
    /* @3985052 cast */
    /* @3985056 load */
    /* @3985064 call */
    GM_SITE(vm, 168, 3985064);
    /* @3985072 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3985076: ;
    /* @3985076 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3985048;
    /* @3985080 constant */
    /* @3985084 cast */
    /* @3985088 load */
    /* @3985096 constant */
    /* @3985100 sub */
    /* @3985104 load */
    /* @3985112 call */
    GM_SITE(vm, 168, 3985112);
    /* @3985120 store */
    v8 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID6", v8);
    /* @3985128 load */
    /* @3985136 cast */
    /* @3985140 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3985172;
    L_3985144: ;
    /* @3985144 constant */
    /* @3985148 cast */
    /* @3985152 load */
    /* @3985160 call */
    GM_SITE(vm, 168, 3985160);
    /* @3985168 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3985172: ;
    /* @3985172 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3985144;
    /* @3985176 constant */
    /* @3985180 cast */
    /* @3985184 load */
    /* @3985192 constant */
    /* @3985196 sub */
    /* @3985200 load */
    /* @3985208 constant */
    /* @3985212 add */
    /* @3985216 call */
    GM_SITE(vm, 168, 3985216);
    v9 = GM_ADD(GM_READ(vm, -1, "x"), VAL(16));
    /* @3985224 store */
    v10 = GM_CALL(vm, "instance_create", 3, v9, (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID7", v10);
    /* @3985232 load */
    /* @3985240 cast */
    /* @3985244 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3985276;
    L_3985248: ;
    /* @3985248 constant */
    /* @3985252 cast */
    /* @3985256 load */
    /* @3985264 call */
    GM_SITE(vm, 168, 3985264);
    /* @3985272 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3985276: ;
    /* @3985276 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3985248;
    /* @3985280 constant */
    /* @3985284 cast */
    /* @3985288 load */
    /* @3985296 constant */
    /* @3985300 sub */
    /* @3985304 load */
    /* @3985312 constant */
    /* @3985316 sub */
    /* @3985320 call */
    GM_SITE(vm, 168, 3985320);
    /* @3985328 store */
    v11 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(17)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID8", v11);
    /* @3985336 load */
    /* @3985344 cast */
    /* @3985348 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3985380;
    L_3985352: ;
    /* @3985352 constant */
    /* @3985356 cast */
    /* @3985360 load */
    /* @3985368 call */
    GM_SITE(vm, 168, 3985368);
    /* @3985376 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3985380: ;
    /* @3985380 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3985352;
    /* @3985384 constant */
    /* @3985388 cast */
    /* @3985392 load */
    /* @3985400 constant */
    /* @3985404 sub */
    /* @3985408 load */
    /* @3985416 constant */
    /* @3985420 add */
    /* @3985424 call */
    GM_SITE(vm, 168, 3985424);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @3985432 store */
    v13 = GM_CALL(vm, "instance_create", 3, v12, (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID9", v13);
    /* @3985440 load */
    /* @3985448 cast */
    /* @3985452 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3985484;
    L_3985456: ;
    /* @3985456 constant */
    /* @3985460 cast */
    /* @3985464 load */
    /* @3985472 call */
    GM_SITE(vm, 168, 3985472);
    /* @3985480 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3985484: ;
    /* @3985484 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3985456;
    /* @3985488 constant */
    /* @3985492 cast */
    /* @3985496 load */
    /* @3985504 constant */
    /* @3985508 sub */
    /* @3985512 load */
    /* @3985520 constant */
    /* @3985524 sub */
    /* @3985528 call */
    GM_SITE(vm, 168, 3985528);
    /* @3985536 store */
    v14 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(21)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID10", v14);
    /* @3985544 load */
    /* @3985552 cast */
    /* @3985556 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3985588;
    L_3985560: ;
    /* @3985560 constant */
    /* @3985564 cast */
    /* @3985568 load */
    /* @3985576 call */
    GM_SITE(vm, 168, 3985576);
    /* @3985584 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3985588: ;
    /* @3985588 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3985560;
    L_3985592: ;
    /* @3985592 load */
    /* @3985600 constant */
    /* @3985604 cmp */
    /* @3985608 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(1)))) goto L_3986124;
    /* @3985612 constant */
    /* @3985616 cast */
    /* @3985620 load */
    /* @3985628 constant */
    /* @3985632 sub */
    /* @3985636 load */
    /* @3985644 call */
    GM_SITE(vm, 168, 3985644);
    /* @3985652 store */
    v15 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v15);
    /* @3985660 load */
    /* @3985668 cast */
    /* @3985672 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3985704;
    L_3985676: ;
    /* @3985676 constant */
    /* @3985680 cast */
    /* @3985684 load */
    /* @3985692 call */
    GM_SITE(vm, 168, 3985692);
    /* @3985700 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3985704: ;
    /* @3985704 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3985676;
    /* @3985708 constant */
    /* @3985712 cast */
    /* @3985716 load */
    /* @3985724 constant */
    /* @3985728 sub */
    /* @3985732 load */
    /* @3985740 constant */
    /* @3985744 add */
    /* @3985748 call */
    GM_SITE(vm, 168, 3985748);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3985756 store */
    v17 = GM_CALL(vm, "instance_create", 3, v16, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v17);
    /* @3985764 load */
    /* @3985772 cast */
    /* @3985776 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3985808;
    L_3985780: ;
    /* @3985780 constant */
    /* @3985784 cast */
    /* @3985788 load */
    /* @3985796 call */
    GM_SITE(vm, 168, 3985796);
    /* @3985804 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3985808: ;
    /* @3985808 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3985780;
    /* @3985812 constant */
    /* @3985816 cast */
    /* @3985820 load */
    /* @3985828 constant */
    /* @3985832 sub */
    /* @3985836 load */
    /* @3985844 constant */
    /* @3985848 sub */
    /* @3985852 call */
    GM_SITE(vm, 168, 3985852);
    /* @3985860 store */
    v18 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v18);
    /* @3985868 load */
    /* @3985876 cast */
    /* @3985880 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3985912;
    L_3985884: ;
    /* @3985884 constant */
    /* @3985888 cast */
    /* @3985892 load */
    /* @3985900 call */
    GM_SITE(vm, 168, 3985900);
    /* @3985908 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3985912: ;
    /* @3985912 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3985884;
    /* @3985916 constant */
    /* @3985920 cast */
    /* @3985924 load */
    /* @3985932 constant */
    /* @3985936 sub */
    /* @3985940 load */
    /* @3985948 constant */
    /* @3985952 add */
    /* @3985956 call */
    GM_SITE(vm, 168, 3985956);
    v19 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3985964 store */
    v20 = GM_CALL(vm, "instance_create", 3, v19, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v20);
    /* @3985972 load */
    /* @3985980 cast */
    /* @3985984 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3986016;
    L_3985988: ;
    /* @3985988 constant */
    /* @3985992 cast */
    /* @3985996 load */
    /* @3986004 call */
    GM_SITE(vm, 168, 3986004);
    /* @3986012 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3986016: ;
    /* @3986016 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3985988;
    /* @3986020 constant */
    /* @3986024 cast */
    /* @3986028 load */
    /* @3986036 constant */
    /* @3986040 sub */
    /* @3986044 load */
    /* @3986052 constant */
    /* @3986056 sub */
    /* @3986060 call */
    GM_SITE(vm, 168, 3986060);
    /* @3986068 store */
    v21 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v21);
    /* @3986076 load */
    /* @3986084 cast */
    /* @3986088 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3986120;
    L_3986092: ;
    /* @3986092 constant */
    /* @3986096 cast */
    /* @3986100 load */
    /* @3986108 call */
    GM_SITE(vm, 168, 3986108);
    /* @3986116 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3986120: ;
    /* @3986120 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3986092;
    L_3986124: ;
    /* @3986124 load */
    /* @3986132 constant */
    /* @3986136 cmp */
    /* @3986140 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(2)))) goto L_3987176;
    /* @3986144 constant */
    /* @3986148 cast */
    /* @3986152 load */
    /* @3986160 constant */
    /* @3986164 sub */
    /* @3986168 load */
    /* @3986176 call */
    GM_SITE(vm, 168, 3986176);
    /* @3986184 store */
    v22 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v22);
    /* @3986192 load */
    /* @3986200 cast */
    /* @3986204 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3986236;
    L_3986208: ;
    /* @3986208 constant */
    /* @3986212 cast */
    /* @3986216 load */
    /* @3986224 call */
    GM_SITE(vm, 168, 3986224);
    /* @3986232 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3986236: ;
    /* @3986236 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3986208;
    /* @3986240 constant */
    /* @3986244 cast */
    /* @3986248 load */
    /* @3986256 constant */
    /* @3986260 sub */
    /* @3986264 load */
    /* @3986272 constant */
    /* @3986276 add */
    /* @3986280 call */
    GM_SITE(vm, 168, 3986280);
    v23 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3986288 store */
    v24 = GM_CALL(vm, "instance_create", 3, v23, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v24);
    /* @3986296 load */
    /* @3986304 cast */
    /* @3986308 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3986340;
    L_3986312: ;
    /* @3986312 constant */
    /* @3986316 cast */
    /* @3986320 load */
    /* @3986328 call */
    GM_SITE(vm, 168, 3986328);
    /* @3986336 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3986340: ;
    /* @3986340 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3986312;
    /* @3986344 constant */
    /* @3986348 cast */
    /* @3986352 load */
    /* @3986360 constant */
    /* @3986364 sub */
    /* @3986368 load */
    /* @3986376 constant */
    /* @3986380 sub */
    /* @3986384 call */
    GM_SITE(vm, 168, 3986384);
    /* @3986392 store */
    v25 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v25);
    /* @3986400 load */
    /* @3986408 cast */
    /* @3986412 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3986444;
    L_3986416: ;
    /* @3986416 constant */
    /* @3986420 cast */
    /* @3986424 load */
    /* @3986432 call */
    GM_SITE(vm, 168, 3986432);
    /* @3986440 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3986444: ;
    /* @3986444 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3986416;
    /* @3986448 constant */
    /* @3986452 cast */
    /* @3986456 load */
    /* @3986464 constant */
    /* @3986468 sub */
    /* @3986472 load */
    /* @3986480 constant */
    /* @3986484 add */
    /* @3986488 call */
    GM_SITE(vm, 168, 3986488);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3986496 store */
    v27 = GM_CALL(vm, "instance_create", 3, v26, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v27);
    /* @3986504 load */
    /* @3986512 cast */
    /* @3986516 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3986548;
    L_3986520: ;
    /* @3986520 constant */
    /* @3986524 cast */
    /* @3986528 load */
    /* @3986536 call */
    GM_SITE(vm, 168, 3986536);
    /* @3986544 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3986548: ;
    /* @3986548 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3986520;
    /* @3986552 constant */
    /* @3986556 cast */
    /* @3986560 load */
    /* @3986568 constant */
    /* @3986572 sub */
    /* @3986576 load */
    /* @3986584 constant */
    /* @3986588 sub */
    /* @3986592 call */
    GM_SITE(vm, 168, 3986592);
    /* @3986600 store */
    v28 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v28);
    /* @3986608 load */
    /* @3986616 cast */
    /* @3986620 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3986652;
    L_3986624: ;
    /* @3986624 constant */
    /* @3986628 cast */
    /* @3986632 load */
    /* @3986640 call */
    GM_SITE(vm, 168, 3986640);
    /* @3986648 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3986652: ;
    /* @3986652 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3986624;
    /* @3986656 constant */
    /* @3986660 cast */
    /* @3986664 load */
    /* @3986672 constant */
    /* @3986676 sub */
    /* @3986680 load */
    /* @3986688 constant */
    /* @3986692 sub */
    /* @3986696 call */
    GM_SITE(vm, 168, 3986696);
    /* @3986704 store */
    v29 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v29);
    /* @3986712 load */
    /* @3986720 cast */
    /* @3986724 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3986756;
    L_3986728: ;
    /* @3986728 constant */
    /* @3986732 cast */
    /* @3986736 load */
    /* @3986744 call */
    GM_SITE(vm, 168, 3986744);
    /* @3986752 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3986756: ;
    /* @3986756 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3986728;
    /* @3986760 constant */
    /* @3986764 cast */
    /* @3986768 load */
    /* @3986776 constant */
    /* @3986780 sub */
    /* @3986784 load */
    /* @3986792 constant */
    /* @3986796 add */
    /* @3986800 call */
    GM_SITE(vm, 168, 3986800);
    v30 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3986808 store */
    v31 = GM_CALL(vm, "instance_create", 3, v30, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v31);
    /* @3986816 load */
    /* @3986824 cast */
    /* @3986828 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3986860;
    L_3986832: ;
    /* @3986832 constant */
    /* @3986836 cast */
    /* @3986840 load */
    /* @3986848 call */
    GM_SITE(vm, 168, 3986848);
    /* @3986856 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3986860: ;
    /* @3986860 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3986832;
    /* @3986864 constant */
    /* @3986868 cast */
    /* @3986872 load */
    /* @3986880 constant */
    /* @3986884 sub */
    /* @3986888 load */
    /* @3986896 constant */
    /* @3986900 sub */
    /* @3986904 call */
    GM_SITE(vm, 168, 3986904);
    /* @3986912 store */
    v32 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v32);
    /* @3986920 load */
    /* @3986928 cast */
    /* @3986932 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3986964;
    L_3986936: ;
    /* @3986936 constant */
    /* @3986940 cast */
    /* @3986944 load */
    /* @3986952 call */
    GM_SITE(vm, 168, 3986952);
    /* @3986960 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3986964: ;
    /* @3986964 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3986936;
    /* @3986968 constant */
    /* @3986972 cast */
    /* @3986976 load */
    /* @3986984 constant */
    /* @3986988 sub */
    /* @3986992 load */
    /* @3987000 constant */
    /* @3987004 add */
    /* @3987008 call */
    GM_SITE(vm, 168, 3987008);
    v33 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3987016 store */
    v34 = GM_CALL(vm, "instance_create", 3, v33, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v34);
    /* @3987024 load */
    /* @3987032 cast */
    /* @3987036 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3987068;
    L_3987040: ;
    /* @3987040 constant */
    /* @3987044 cast */
    /* @3987048 load */
    /* @3987056 call */
    GM_SITE(vm, 168, 3987056);
    /* @3987064 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3987068: ;
    /* @3987068 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3987040;
    /* @3987072 constant */
    /* @3987076 cast */
    /* @3987080 load */
    /* @3987088 constant */
    /* @3987092 sub */
    /* @3987096 load */
    /* @3987104 constant */
    /* @3987108 sub */
    /* @3987112 call */
    GM_SITE(vm, 168, 3987112);
    /* @3987120 store */
    v35 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v35);
    /* @3987128 load */
    /* @3987136 cast */
    /* @3987140 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3987172;
    L_3987144: ;
    /* @3987144 constant */
    /* @3987148 cast */
    /* @3987152 load */
    /* @3987160 call */
    GM_SITE(vm, 168, 3987160);
    /* @3987168 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_3987172: ;
    /* @3987172 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3987144;
    L_3987176: ;
    /* @3987176 load */
    /* @3987184 constant */
    /* @3987188 cmp */
    /* @3987192 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(3)))) goto L_3988748;
    /* @3987196 constant */
    /* @3987200 cast */
    /* @3987204 load */
    /* @3987212 constant */
    /* @3987216 sub */
    /* @3987220 load */
    /* @3987228 call */
    GM_SITE(vm, 168, 3987228);
    /* @3987236 store */
    v36 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v36);
    /* @3987244 load */
    /* @3987252 cast */
    /* @3987256 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3987288;
    L_3987260: ;
    /* @3987260 constant */
    /* @3987264 cast */
    /* @3987268 load */
    /* @3987276 call */
    GM_SITE(vm, 168, 3987276);
    /* @3987284 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3987288: ;
    /* @3987288 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3987260;
    /* @3987292 constant */
    /* @3987296 cast */
    /* @3987300 load */
    /* @3987308 constant */
    /* @3987312 sub */
    /* @3987316 load */
    /* @3987324 constant */
    /* @3987328 add */
    /* @3987332 call */
    GM_SITE(vm, 168, 3987332);
    v37 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3987340 store */
    v38 = GM_CALL(vm, "instance_create", 3, v37, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v38);
    /* @3987348 load */
    /* @3987356 cast */
    /* @3987360 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3987392;
    L_3987364: ;
    /* @3987364 constant */
    /* @3987368 cast */
    /* @3987372 load */
    /* @3987380 call */
    GM_SITE(vm, 168, 3987380);
    /* @3987388 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3987392: ;
    /* @3987392 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3987364;
    /* @3987396 constant */
    /* @3987400 cast */
    /* @3987404 load */
    /* @3987412 constant */
    /* @3987416 sub */
    /* @3987420 load */
    /* @3987428 constant */
    /* @3987432 sub */
    /* @3987436 call */
    GM_SITE(vm, 168, 3987436);
    /* @3987444 store */
    v39 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v39);
    /* @3987452 load */
    /* @3987460 cast */
    /* @3987464 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3987496;
    L_3987468: ;
    /* @3987468 constant */
    /* @3987472 cast */
    /* @3987476 load */
    /* @3987484 call */
    GM_SITE(vm, 168, 3987484);
    /* @3987492 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3987496: ;
    /* @3987496 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3987468;
    /* @3987500 constant */
    /* @3987504 cast */
    /* @3987508 load */
    /* @3987516 constant */
    /* @3987520 sub */
    /* @3987524 load */
    /* @3987532 constant */
    /* @3987536 add */
    /* @3987540 call */
    GM_SITE(vm, 168, 3987540);
    v40 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3987548 store */
    v41 = GM_CALL(vm, "instance_create", 3, v40, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v41);
    /* @3987556 load */
    /* @3987564 cast */
    /* @3987568 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3987600;
    L_3987572: ;
    /* @3987572 constant */
    /* @3987576 cast */
    /* @3987580 load */
    /* @3987588 call */
    GM_SITE(vm, 168, 3987588);
    /* @3987596 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3987600: ;
    /* @3987600 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3987572;
    /* @3987604 constant */
    /* @3987608 cast */
    /* @3987612 load */
    /* @3987620 constant */
    /* @3987624 sub */
    /* @3987628 load */
    /* @3987636 constant */
    /* @3987640 sub */
    /* @3987644 call */
    GM_SITE(vm, 168, 3987644);
    /* @3987652 store */
    v42 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v42);
    /* @3987660 load */
    /* @3987668 cast */
    /* @3987672 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3987704;
    L_3987676: ;
    /* @3987676 constant */
    /* @3987680 cast */
    /* @3987684 load */
    /* @3987692 call */
    GM_SITE(vm, 168, 3987692);
    /* @3987700 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3987704: ;
    /* @3987704 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3987676;
    /* @3987708 constant */
    /* @3987712 cast */
    /* @3987716 load */
    /* @3987724 constant */
    /* @3987728 sub */
    /* @3987732 load */
    /* @3987740 constant */
    /* @3987744 sub */
    /* @3987748 call */
    GM_SITE(vm, 168, 3987748);
    /* @3987756 store */
    v43 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v43);
    /* @3987764 load */
    /* @3987772 cast */
    /* @3987776 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3987808;
    L_3987780: ;
    /* @3987780 constant */
    /* @3987784 cast */
    /* @3987788 load */
    /* @3987796 call */
    GM_SITE(vm, 168, 3987796);
    /* @3987804 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3987808: ;
    /* @3987808 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3987780;
    /* @3987812 constant */
    /* @3987816 cast */
    /* @3987820 load */
    /* @3987828 constant */
    /* @3987832 sub */
    /* @3987836 load */
    /* @3987844 constant */
    /* @3987848 add */
    /* @3987852 call */
    GM_SITE(vm, 168, 3987852);
    v44 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3987860 store */
    v45 = GM_CALL(vm, "instance_create", 3, v44, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v45);
    /* @3987868 load */
    /* @3987876 cast */
    /* @3987880 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3987912;
    L_3987884: ;
    /* @3987884 constant */
    /* @3987888 cast */
    /* @3987892 load */
    /* @3987900 call */
    GM_SITE(vm, 168, 3987900);
    /* @3987908 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3987912: ;
    /* @3987912 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3987884;
    /* @3987916 constant */
    /* @3987920 cast */
    /* @3987924 load */
    /* @3987932 constant */
    /* @3987936 sub */
    /* @3987940 load */
    /* @3987948 constant */
    /* @3987952 sub */
    /* @3987956 call */
    GM_SITE(vm, 168, 3987956);
    /* @3987964 store */
    v46 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v46);
    /* @3987972 load */
    /* @3987980 cast */
    /* @3987984 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3988016;
    L_3987988: ;
    /* @3987988 constant */
    /* @3987992 cast */
    /* @3987996 load */
    /* @3988004 call */
    GM_SITE(vm, 168, 3988004);
    /* @3988012 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3988016: ;
    /* @3988016 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3987988;
    /* @3988020 constant */
    /* @3988024 cast */
    /* @3988028 load */
    /* @3988036 constant */
    /* @3988040 sub */
    /* @3988044 load */
    /* @3988052 constant */
    /* @3988056 add */
    /* @3988060 call */
    GM_SITE(vm, 168, 3988060);
    v47 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3988068 store */
    v48 = GM_CALL(vm, "instance_create", 3, v47, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v48);
    /* @3988076 load */
    /* @3988084 cast */
    /* @3988088 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3988120;
    L_3988092: ;
    /* @3988092 constant */
    /* @3988096 cast */
    /* @3988100 load */
    /* @3988108 call */
    GM_SITE(vm, 168, 3988108);
    /* @3988116 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3988120: ;
    /* @3988120 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3988092;
    /* @3988124 constant */
    /* @3988128 cast */
    /* @3988132 load */
    /* @3988140 constant */
    /* @3988144 sub */
    /* @3988148 load */
    /* @3988156 constant */
    /* @3988160 sub */
    /* @3988164 call */
    GM_SITE(vm, 168, 3988164);
    /* @3988172 store */
    v49 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v49);
    /* @3988180 load */
    /* @3988188 cast */
    /* @3988192 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3988224;
    L_3988196: ;
    /* @3988196 constant */
    /* @3988200 cast */
    /* @3988204 load */
    /* @3988212 call */
    GM_SITE(vm, 168, 3988212);
    /* @3988220 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_3988224: ;
    /* @3988224 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3988196;
    /* @3988228 constant */
    /* @3988232 cast */
    /* @3988236 load */
    /* @3988244 constant */
    /* @3988248 sub */
    /* @3988252 load */
    /* @3988260 constant */
    /* @3988264 add */
    /* @3988268 call */
    GM_SITE(vm, 168, 3988268);
    v50 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @3988276 store */
    v51 = GM_CALL(vm, "instance_create", 3, v50, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v51);
    /* @3988284 load */
    /* @3988292 cast */
    /* @3988296 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_3988328;
    L_3988300: ;
    /* @3988300 constant */
    /* @3988304 cast */
    /* @3988308 load */
    /* @3988316 call */
    GM_SITE(vm, 168, 3988316);
    /* @3988324 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_3988328: ;
    /* @3988328 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3988300;
    /* @3988332 constant */
    /* @3988336 cast */
    /* @3988340 load */
    /* @3988348 constant */
    /* @3988352 sub */
    /* @3988356 load */
    /* @3988364 constant */
    /* @3988368 add */
    /* @3988372 call */
    GM_SITE(vm, 168, 3988372);
    v52 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @3988380 store */
    v53 = GM_CALL(vm, "instance_create", 3, v52, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID12", v53);
    /* @3988388 load */
    /* @3988396 cast */
    /* @3988400 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID12")))) goto L_3988432;
    L_3988404: ;
    /* @3988404 constant */
    /* @3988408 cast */
    /* @3988412 load */
    /* @3988420 call */
    GM_SITE(vm, 168, 3988420);
    /* @3988428 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread12"), VAL(5)));
    L_3988432: ;
    /* @3988432 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3988404;
    /* @3988436 constant */
    /* @3988440 cast */
    /* @3988444 load */
    /* @3988452 constant */
    /* @3988456 sub */
    /* @3988460 load */
    /* @3988468 constant */
    /* @3988472 sub */
    /* @3988476 call */
    GM_SITE(vm, 168, 3988476);
    /* @3988484 store */
    v54 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID13", v54);
    /* @3988492 load */
    /* @3988500 cast */
    /* @3988504 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID13")))) goto L_3988536;
    L_3988508: ;
    /* @3988508 constant */
    /* @3988512 cast */
    /* @3988516 load */
    /* @3988524 call */
    GM_SITE(vm, 168, 3988524);
    /* @3988532 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread13"), VAL(5)));
    L_3988536: ;
    /* @3988536 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3988508;
    /* @3988540 constant */
    /* @3988544 cast */
    /* @3988548 load */
    /* @3988556 constant */
    /* @3988560 sub */
    /* @3988564 load */
    /* @3988572 constant */
    /* @3988576 add */
    /* @3988580 call */
    GM_SITE(vm, 168, 3988580);
    v55 = GM_ADD(GM_READ(vm, -1, "x"), VAL(12));
    /* @3988588 store */
    v56 = GM_CALL(vm, "instance_create", 3, v55, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID14", v56);
    /* @3988596 load */
    /* @3988604 cast */
    /* @3988608 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID14")))) goto L_3988640;
    L_3988612: ;
    /* @3988612 constant */
    /* @3988616 cast */
    /* @3988620 load */
    /* @3988628 call */
    GM_SITE(vm, 168, 3988628);
    /* @3988636 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread14"), VAL(5)));
    L_3988640: ;
    /* @3988640 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3988612;
    /* @3988644 constant */
    /* @3988648 cast */
    /* @3988652 load */
    /* @3988660 constant */
    /* @3988664 sub */
    /* @3988668 load */
    /* @3988676 constant */
    /* @3988680 sub */
    /* @3988684 call */
    GM_SITE(vm, 168, 3988684);
    /* @3988692 store */
    v57 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(12)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID15", v57);
    /* @3988700 load */
    /* @3988708 cast */
    /* @3988712 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID15")))) goto L_3988744;
    L_3988716: ;
    /* @3988716 constant */
    /* @3988720 cast */
    /* @3988724 load */
    /* @3988732 call */
    GM_SITE(vm, 168, 3988732);
    /* @3988740 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread15"), VAL(5)));
    L_3988744: ;
    /* @3988744 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3988716;
    L_3988748: ;
    /* @3988748 load */
    /* @3988756 constant */
    /* @3988760 cmp */
    /* @3988764 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(4)))) goto L_3990840;
    /* @3988768 constant */
    /* @3988772 cast */
    /* @3988776 load */
    /* @3988784 constant */
    /* @3988788 sub */
    /* @3988792 load */
    /* @3988800 call */
    GM_SITE(vm, 168, 3988800);
    /* @3988808 store */
    v58 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v58);
    /* @3988816 load */
    /* @3988824 cast */
    /* @3988828 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3988860;
    L_3988832: ;
    /* @3988832 constant */
    /* @3988836 cast */
    /* @3988840 load */
    /* @3988848 call */
    GM_SITE(vm, 168, 3988848);
    /* @3988856 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3988860: ;
    /* @3988860 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3988832;
    /* @3988864 constant */
    /* @3988868 cast */
    /* @3988872 load */
    /* @3988880 constant */
    /* @3988884 sub */
    /* @3988888 load */
    /* @3988896 constant */
    /* @3988900 add */
    /* @3988904 call */
    GM_SITE(vm, 168, 3988904);
    v59 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3988912 store */
    v60 = GM_CALL(vm, "instance_create", 3, v59, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v60);
    /* @3988920 load */
    /* @3988928 cast */
    /* @3988932 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3988964;
    L_3988936: ;
    /* @3988936 constant */
    /* @3988940 cast */
    /* @3988944 load */
    /* @3988952 call */
    GM_SITE(vm, 168, 3988952);
    /* @3988960 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3988964: ;
    /* @3988964 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3988936;
    /* @3988968 constant */
    /* @3988972 cast */
    /* @3988976 load */
    /* @3988984 constant */
    /* @3988988 sub */
    /* @3988992 load */
    /* @3989000 constant */
    /* @3989004 sub */
    /* @3989008 call */
    GM_SITE(vm, 168, 3989008);
    /* @3989016 store */
    v61 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v61);
    /* @3989024 load */
    /* @3989032 cast */
    /* @3989036 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3989068;
    L_3989040: ;
    /* @3989040 constant */
    /* @3989044 cast */
    /* @3989048 load */
    /* @3989056 call */
    GM_SITE(vm, 168, 3989056);
    /* @3989064 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3989068: ;
    /* @3989068 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3989040;
    /* @3989072 constant */
    /* @3989076 cast */
    /* @3989080 load */
    /* @3989088 constant */
    /* @3989092 sub */
    /* @3989096 load */
    /* @3989104 constant */
    /* @3989108 add */
    /* @3989112 call */
    GM_SITE(vm, 168, 3989112);
    v62 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3989120 store */
    v63 = GM_CALL(vm, "instance_create", 3, v62, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v63);
    /* @3989128 load */
    /* @3989136 cast */
    /* @3989140 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3989172;
    L_3989144: ;
    /* @3989144 constant */
    /* @3989148 cast */
    /* @3989152 load */
    /* @3989160 call */
    GM_SITE(vm, 168, 3989160);
    /* @3989168 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3989172: ;
    /* @3989172 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3989144;
    /* @3989176 constant */
    /* @3989180 cast */
    /* @3989184 load */
    /* @3989192 constant */
    /* @3989196 sub */
    /* @3989200 load */
    /* @3989208 constant */
    /* @3989212 sub */
    /* @3989216 call */
    GM_SITE(vm, 168, 3989216);
    /* @3989224 store */
    v64 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v64);
    /* @3989232 load */
    /* @3989240 cast */
    /* @3989244 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3989276;
    L_3989248: ;
    /* @3989248 constant */
    /* @3989252 cast */
    /* @3989256 load */
    /* @3989264 call */
    GM_SITE(vm, 168, 3989264);
    /* @3989272 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3989276: ;
    /* @3989276 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3989248;
    /* @3989280 constant */
    /* @3989284 cast */
    /* @3989288 load */
    /* @3989296 constant */
    /* @3989300 sub */
    /* @3989304 load */
    /* @3989312 constant */
    /* @3989316 add */
    /* @3989320 call */
    GM_SITE(vm, 168, 3989320);
    v65 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @3989328 store */
    v66 = GM_CALL(vm, "instance_create", 3, v65, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v66);
    /* @3989336 load */
    /* @3989344 cast */
    /* @3989348 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3989380;
    L_3989352: ;
    /* @3989352 constant */
    /* @3989356 cast */
    /* @3989360 load */
    /* @3989368 call */
    GM_SITE(vm, 168, 3989368);
    /* @3989376 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3989380: ;
    /* @3989380 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3989352;
    /* @3989384 constant */
    /* @3989388 cast */
    /* @3989392 load */
    /* @3989400 constant */
    /* @3989404 sub */
    /* @3989408 load */
    /* @3989416 constant */
    /* @3989420 add */
    /* @3989424 call */
    GM_SITE(vm, 168, 3989424);
    v67 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3989432 store */
    v68 = GM_CALL(vm, "instance_create", 3, v67, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v68);
    /* @3989440 load */
    /* @3989448 cast */
    /* @3989452 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3989484;
    L_3989456: ;
    /* @3989456 constant */
    /* @3989460 cast */
    /* @3989464 load */
    /* @3989472 call */
    GM_SITE(vm, 168, 3989472);
    /* @3989480 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3989484: ;
    /* @3989484 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3989456;
    /* @3989488 constant */
    /* @3989492 cast */
    /* @3989496 load */
    /* @3989504 constant */
    /* @3989508 sub */
    /* @3989512 load */
    /* @3989520 constant */
    /* @3989524 sub */
    /* @3989528 call */
    GM_SITE(vm, 168, 3989528);
    /* @3989536 store */
    v69 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v69);
    /* @3989544 load */
    /* @3989552 cast */
    /* @3989556 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3989588;
    L_3989560: ;
    /* @3989560 constant */
    /* @3989564 cast */
    /* @3989568 load */
    /* @3989576 call */
    GM_SITE(vm, 168, 3989576);
    /* @3989584 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3989588: ;
    /* @3989588 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3989560;
    /* @3989592 constant */
    /* @3989596 cast */
    /* @3989600 load */
    /* @3989608 constant */
    /* @3989612 sub */
    /* @3989616 load */
    /* @3989624 constant */
    /* @3989628 add */
    /* @3989632 call */
    GM_SITE(vm, 168, 3989632);
    v70 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3989640 store */
    v71 = GM_CALL(vm, "instance_create", 3, v70, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v71);
    /* @3989648 load */
    /* @3989656 cast */
    /* @3989660 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3989692;
    L_3989664: ;
    /* @3989664 constant */
    /* @3989668 cast */
    /* @3989672 load */
    /* @3989680 call */
    GM_SITE(vm, 168, 3989680);
    /* @3989688 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3989692: ;
    /* @3989692 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3989664;
    /* @3989696 constant */
    /* @3989700 cast */
    /* @3989704 load */
    /* @3989712 constant */
    /* @3989716 sub */
    /* @3989720 load */
    /* @3989728 constant */
    /* @3989732 sub */
    /* @3989736 call */
    GM_SITE(vm, 168, 3989736);
    /* @3989744 store */
    v72 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v72);
    /* @3989752 load */
    /* @3989760 cast */
    /* @3989764 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3989796;
    L_3989768: ;
    /* @3989768 constant */
    /* @3989772 cast */
    /* @3989776 load */
    /* @3989784 call */
    GM_SITE(vm, 168, 3989784);
    /* @3989792 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_3989796: ;
    /* @3989796 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3989768;
    /* @3989800 constant */
    /* @3989804 cast */
    /* @3989808 load */
    /* @3989816 constant */
    /* @3989820 sub */
    /* @3989824 load */
    /* @3989832 constant */
    /* @3989836 sub */
    /* @3989840 call */
    GM_SITE(vm, 168, 3989840);
    /* @3989848 store */
    v73 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v73);
    /* @3989856 load */
    /* @3989864 cast */
    /* @3989868 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_3989900;
    L_3989872: ;
    /* @3989872 constant */
    /* @3989876 cast */
    /* @3989880 load */
    /* @3989888 call */
    GM_SITE(vm, 168, 3989888);
    /* @3989896 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_3989900: ;
    /* @3989900 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3989872;
    /* @3989904 constant */
    /* @3989908 cast */
    /* @3989912 load */
    /* @3989920 constant */
    /* @3989924 sub */
    /* @3989928 load */
    /* @3989936 constant */
    /* @3989940 add */
    /* @3989944 call */
    GM_SITE(vm, 168, 3989944);
    v74 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @3989952 store */
    v75 = GM_CALL(vm, "instance_create", 3, v74, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID12", v75);
    /* @3989960 load */
    /* @3989968 cast */
    /* @3989972 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID12")))) goto L_3990004;
    L_3989976: ;
    /* @3989976 constant */
    /* @3989980 cast */
    /* @3989984 load */
    /* @3989992 call */
    GM_SITE(vm, 168, 3989992);
    /* @3990000 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread12"), VAL(5)));
    L_3990004: ;
    /* @3990004 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3989976;
    /* @3990008 constant */
    /* @3990012 cast */
    /* @3990016 load */
    /* @3990024 constant */
    /* @3990028 sub */
    /* @3990032 load */
    /* @3990040 constant */
    /* @3990044 sub */
    /* @3990048 call */
    GM_SITE(vm, 168, 3990048);
    /* @3990056 store */
    v76 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID13", v76);
    /* @3990064 load */
    /* @3990072 cast */
    /* @3990076 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID13")))) goto L_3990108;
    L_3990080: ;
    /* @3990080 constant */
    /* @3990084 cast */
    /* @3990088 load */
    /* @3990096 call */
    GM_SITE(vm, 168, 3990096);
    /* @3990104 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread13"), VAL(5)));
    L_3990108: ;
    /* @3990108 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3990080;
    /* @3990112 constant */
    /* @3990116 cast */
    /* @3990120 load */
    /* @3990128 constant */
    /* @3990132 sub */
    /* @3990136 load */
    /* @3990144 constant */
    /* @3990148 add */
    /* @3990152 call */
    GM_SITE(vm, 168, 3990152);
    v77 = GM_ADD(GM_READ(vm, -1, "x"), VAL(12));
    /* @3990160 store */
    v78 = GM_CALL(vm, "instance_create", 3, v77, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID14", v78);
    /* @3990168 load */
    /* @3990176 cast */
    /* @3990180 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID14")))) goto L_3990212;
    L_3990184: ;
    /* @3990184 constant */
    /* @3990188 cast */
    /* @3990192 load */
    /* @3990200 call */
    GM_SITE(vm, 168, 3990200);
    /* @3990208 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread14"), VAL(5)));
    L_3990212: ;
    /* @3990212 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3990184;
    /* @3990216 constant */
    /* @3990220 cast */
    /* @3990224 load */
    /* @3990232 constant */
    /* @3990236 sub */
    /* @3990240 load */
    /* @3990248 constant */
    /* @3990252 sub */
    /* @3990256 call */
    GM_SITE(vm, 168, 3990256);
    /* @3990264 store */
    v79 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(12)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID15", v79);
    /* @3990272 load */
    /* @3990280 cast */
    /* @3990284 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID15")))) goto L_3990316;
    L_3990288: ;
    /* @3990288 constant */
    /* @3990292 cast */
    /* @3990296 load */
    /* @3990304 call */
    GM_SITE(vm, 168, 3990304);
    /* @3990312 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread15"), VAL(5)));
    L_3990316: ;
    /* @3990316 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3990288;
    /* @3990320 constant */
    /* @3990324 cast */
    /* @3990328 load */
    /* @3990336 constant */
    /* @3990340 sub */
    /* @3990344 load */
    /* @3990352 constant */
    /* @3990356 sub */
    /* @3990360 call */
    GM_SITE(vm, 168, 3990360);
    /* @3990368 store */
    v80 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID16", v80);
    /* @3990376 load */
    /* @3990384 cast */
    /* @3990388 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID16")))) goto L_3990420;
    L_3990392: ;
    /* @3990392 constant */
    /* @3990396 cast */
    /* @3990400 load */
    /* @3990408 call */
    GM_SITE(vm, 168, 3990408);
    /* @3990416 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread16"), VAL(5)));
    L_3990420: ;
    /* @3990420 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3990392;
    /* @3990424 constant */
    /* @3990428 cast */
    /* @3990432 load */
    /* @3990440 constant */
    /* @3990444 sub */
    /* @3990448 load */
    /* @3990456 constant */
    /* @3990460 add */
    /* @3990464 call */
    GM_SITE(vm, 168, 3990464);
    v81 = GM_ADD(GM_READ(vm, -1, "x"), VAL(14));
    /* @3990472 store */
    v82 = GM_CALL(vm, "instance_create", 3, v81, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID17", v82);
    /* @3990480 load */
    /* @3990488 cast */
    /* @3990492 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID17")))) goto L_3990524;
    L_3990496: ;
    /* @3990496 constant */
    /* @3990500 cast */
    /* @3990504 load */
    /* @3990512 call */
    GM_SITE(vm, 168, 3990512);
    /* @3990520 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread17"), VAL(5)));
    L_3990524: ;
    /* @3990524 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3990496;
    /* @3990528 constant */
    /* @3990532 cast */
    /* @3990536 load */
    /* @3990544 constant */
    /* @3990548 sub */
    /* @3990552 load */
    /* @3990560 constant */
    /* @3990564 sub */
    /* @3990568 call */
    GM_SITE(vm, 168, 3990568);
    /* @3990576 store */
    v83 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(14)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID18", v83);
    /* @3990584 load */
    /* @3990592 cast */
    /* @3990596 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID18")))) goto L_3990628;
    L_3990600: ;
    /* @3990600 constant */
    /* @3990604 cast */
    /* @3990608 load */
    /* @3990616 call */
    GM_SITE(vm, 168, 3990616);
    /* @3990624 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread18"), VAL(5)));
    L_3990628: ;
    /* @3990628 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3990600;
    /* @3990632 constant */
    /* @3990636 cast */
    /* @3990640 load */
    /* @3990648 constant */
    /* @3990652 sub */
    /* @3990656 load */
    /* @3990664 constant */
    /* @3990668 add */
    /* @3990672 call */
    GM_SITE(vm, 168, 3990672);
    v84 = GM_ADD(GM_READ(vm, -1, "x"), VAL(16));
    /* @3990680 store */
    v85 = GM_CALL(vm, "instance_create", 3, v84, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID19", v85);
    /* @3990688 load */
    /* @3990696 cast */
    /* @3990700 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID19")))) goto L_3990732;
    L_3990704: ;
    /* @3990704 constant */
    /* @3990708 cast */
    /* @3990712 load */
    /* @3990720 call */
    GM_SITE(vm, 168, 3990720);
    /* @3990728 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread19"), VAL(5)));
    L_3990732: ;
    /* @3990732 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3990704;
    /* @3990736 constant */
    /* @3990740 cast */
    /* @3990744 load */
    /* @3990752 constant */
    /* @3990756 sub */
    /* @3990760 load */
    /* @3990768 constant */
    /* @3990772 sub */
    /* @3990776 call */
    GM_SITE(vm, 168, 3990776);
    /* @3990784 store */
    v86 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(16)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID20", v86);
    /* @3990792 load */
    /* @3990800 cast */
    /* @3990804 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID20")))) goto L_3990836;
    L_3990808: ;
    /* @3990808 constant */
    /* @3990812 cast */
    /* @3990816 load */
    /* @3990824 call */
    GM_SITE(vm, 168, 3990824);
    /* @3990832 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread20"), VAL(5)));
    L_3990836: ;
    /* @3990836 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3990808;
    L_3990840: ;
    /* @3990840 load */
    /* @3990848 constant */
    /* @3990852 cmp */
    /* @3990856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(5)))) goto L_3993452;
    /* @3990860 constant */
    /* @3990864 cast */
    /* @3990868 load */
    /* @3990876 constant */
    /* @3990880 sub */
    /* @3990884 load */
    /* @3990892 call */
    GM_SITE(vm, 168, 3990892);
    /* @3990900 store */
    v87 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v87);
    /* @3990908 load */
    /* @3990916 cast */
    /* @3990920 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3990952;
    L_3990924: ;
    /* @3990924 constant */
    /* @3990928 cast */
    /* @3990932 load */
    /* @3990940 call */
    GM_SITE(vm, 168, 3990940);
    /* @3990948 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3990952: ;
    /* @3990952 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3990924;
    /* @3990956 constant */
    /* @3990960 cast */
    /* @3990964 load */
    /* @3990972 constant */
    /* @3990976 sub */
    /* @3990980 load */
    /* @3990988 constant */
    /* @3990992 add */
    /* @3990996 call */
    GM_SITE(vm, 168, 3990996);
    v88 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3991004 store */
    v89 = GM_CALL(vm, "instance_create", 3, v88, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v89);
    /* @3991012 load */
    /* @3991020 cast */
    /* @3991024 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3991056;
    L_3991028: ;
    /* @3991028 constant */
    /* @3991032 cast */
    /* @3991036 load */
    /* @3991044 call */
    GM_SITE(vm, 168, 3991044);
    /* @3991052 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3991056: ;
    /* @3991056 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3991028;
    /* @3991060 constant */
    /* @3991064 cast */
    /* @3991068 load */
    /* @3991076 constant */
    /* @3991080 sub */
    /* @3991084 load */
    /* @3991092 constant */
    /* @3991096 sub */
    /* @3991100 call */
    GM_SITE(vm, 168, 3991100);
    /* @3991108 store */
    v90 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v90);
    /* @3991116 load */
    /* @3991124 cast */
    /* @3991128 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3991160;
    L_3991132: ;
    /* @3991132 constant */
    /* @3991136 cast */
    /* @3991140 load */
    /* @3991148 call */
    GM_SITE(vm, 168, 3991148);
    /* @3991156 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3991160: ;
    /* @3991160 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3991132;
    /* @3991164 constant */
    /* @3991168 cast */
    /* @3991172 load */
    /* @3991180 constant */
    /* @3991184 sub */
    /* @3991188 load */
    /* @3991196 constant */
    /* @3991200 add */
    /* @3991204 call */
    GM_SITE(vm, 168, 3991204);
    v91 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3991212 store */
    v92 = GM_CALL(vm, "instance_create", 3, v91, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v92);
    /* @3991220 load */
    /* @3991228 cast */
    /* @3991232 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3991264;
    L_3991236: ;
    /* @3991236 constant */
    /* @3991240 cast */
    /* @3991244 load */
    /* @3991252 call */
    GM_SITE(vm, 168, 3991252);
    /* @3991260 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3991264: ;
    /* @3991264 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3991236;
    /* @3991268 constant */
    /* @3991272 cast */
    /* @3991276 load */
    /* @3991284 constant */
    /* @3991288 sub */
    /* @3991292 load */
    /* @3991300 constant */
    /* @3991304 sub */
    /* @3991308 call */
    GM_SITE(vm, 168, 3991308);
    /* @3991316 store */
    v93 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v93);
    /* @3991324 load */
    /* @3991332 cast */
    /* @3991336 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3991368;
    L_3991340: ;
    /* @3991340 constant */
    /* @3991344 cast */
    /* @3991348 load */
    /* @3991356 call */
    GM_SITE(vm, 168, 3991356);
    /* @3991364 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3991368: ;
    /* @3991368 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3991340;
    /* @3991372 constant */
    /* @3991376 cast */
    /* @3991380 load */
    /* @3991388 constant */
    /* @3991392 sub */
    /* @3991396 load */
    /* @3991404 constant */
    /* @3991408 add */
    /* @3991412 call */
    GM_SITE(vm, 168, 3991412);
    v94 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @3991420 store */
    v95 = GM_CALL(vm, "instance_create", 3, v94, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v95);
    /* @3991428 load */
    /* @3991436 cast */
    /* @3991440 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3991472;
    L_3991444: ;
    /* @3991444 constant */
    /* @3991448 cast */
    /* @3991452 load */
    /* @3991460 call */
    GM_SITE(vm, 168, 3991460);
    /* @3991468 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3991472: ;
    /* @3991472 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3991444;
    /* @3991476 constant */
    /* @3991480 cast */
    /* @3991484 load */
    /* @3991492 constant */
    /* @3991496 sub */
    /* @3991500 load */
    /* @3991508 constant */
    /* @3991512 add */
    /* @3991516 call */
    GM_SITE(vm, 168, 3991516);
    v96 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3991524 store */
    v97 = GM_CALL(vm, "instance_create", 3, v96, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v97);
    /* @3991532 load */
    /* @3991540 cast */
    /* @3991544 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3991576;
    L_3991548: ;
    /* @3991548 constant */
    /* @3991552 cast */
    /* @3991556 load */
    /* @3991564 call */
    GM_SITE(vm, 168, 3991564);
    /* @3991572 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3991576: ;
    /* @3991576 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3991548;
    /* @3991580 constant */
    /* @3991584 cast */
    /* @3991588 load */
    /* @3991596 constant */
    /* @3991600 sub */
    /* @3991604 load */
    /* @3991612 constant */
    /* @3991616 sub */
    /* @3991620 call */
    GM_SITE(vm, 168, 3991620);
    /* @3991628 store */
    v98 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v98);
    /* @3991636 load */
    /* @3991644 cast */
    /* @3991648 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3991680;
    L_3991652: ;
    /* @3991652 constant */
    /* @3991656 cast */
    /* @3991660 load */
    /* @3991668 call */
    GM_SITE(vm, 168, 3991668);
    /* @3991676 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3991680: ;
    /* @3991680 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3991652;
    /* @3991684 constant */
    /* @3991688 cast */
    /* @3991692 load */
    /* @3991700 constant */
    /* @3991704 sub */
    /* @3991708 load */
    /* @3991716 constant */
    /* @3991720 add */
    /* @3991724 call */
    GM_SITE(vm, 168, 3991724);
    v99 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3991732 store */
    v100 = GM_CALL(vm, "instance_create", 3, v99, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v100);
    /* @3991740 load */
    /* @3991748 cast */
    /* @3991752 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3991784;
    L_3991756: ;
    /* @3991756 constant */
    /* @3991760 cast */
    /* @3991764 load */
    /* @3991772 call */
    GM_SITE(vm, 168, 3991772);
    /* @3991780 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3991784: ;
    /* @3991784 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3991756;
    /* @3991788 constant */
    /* @3991792 cast */
    /* @3991796 load */
    /* @3991804 constant */
    /* @3991808 sub */
    /* @3991812 load */
    /* @3991820 constant */
    /* @3991824 sub */
    /* @3991828 call */
    GM_SITE(vm, 168, 3991828);
    /* @3991836 store */
    v101 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v101);
    /* @3991844 load */
    /* @3991852 cast */
    /* @3991856 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3991888;
    L_3991860: ;
    /* @3991860 constant */
    /* @3991864 cast */
    /* @3991868 load */
    /* @3991876 call */
    GM_SITE(vm, 168, 3991876);
    /* @3991884 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_3991888: ;
    /* @3991888 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3991860;
    /* @3991892 constant */
    /* @3991896 cast */
    /* @3991900 load */
    /* @3991908 constant */
    /* @3991912 sub */
    /* @3991916 load */
    /* @3991924 constant */
    /* @3991928 sub */
    /* @3991932 call */
    GM_SITE(vm, 168, 3991932);
    /* @3991940 store */
    v102 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v102);
    /* @3991948 load */
    /* @3991956 cast */
    /* @3991960 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_3991992;
    L_3991964: ;
    /* @3991964 constant */
    /* @3991968 cast */
    /* @3991972 load */
    /* @3991980 call */
    GM_SITE(vm, 168, 3991980);
    /* @3991988 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_3991992: ;
    /* @3991992 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3991964;
    /* @3991996 constant */
    /* @3992000 cast */
    /* @3992004 load */
    /* @3992012 constant */
    /* @3992016 sub */
    /* @3992020 load */
    /* @3992028 constant */
    /* @3992032 add */
    /* @3992036 call */
    GM_SITE(vm, 168, 3992036);
    v103 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @3992044 store */
    v104 = GM_CALL(vm, "instance_create", 3, v103, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID12", v104);
    /* @3992052 load */
    /* @3992060 cast */
    /* @3992064 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID12")))) goto L_3992096;
    L_3992068: ;
    /* @3992068 constant */
    /* @3992072 cast */
    /* @3992076 load */
    /* @3992084 call */
    GM_SITE(vm, 168, 3992084);
    /* @3992092 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread12"), VAL(5)));
    L_3992096: ;
    /* @3992096 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3992068;
    /* @3992100 constant */
    /* @3992104 cast */
    /* @3992108 load */
    /* @3992116 constant */
    /* @3992120 sub */
    /* @3992124 load */
    /* @3992132 constant */
    /* @3992136 sub */
    /* @3992140 call */
    GM_SITE(vm, 168, 3992140);
    /* @3992148 store */
    v105 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID13", v105);
    /* @3992156 load */
    /* @3992164 cast */
    /* @3992168 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID13")))) goto L_3992200;
    L_3992172: ;
    /* @3992172 constant */
    /* @3992176 cast */
    /* @3992180 load */
    /* @3992188 call */
    GM_SITE(vm, 168, 3992188);
    /* @3992196 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread13"), VAL(5)));
    L_3992200: ;
    /* @3992200 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3992172;
    /* @3992204 constant */
    /* @3992208 cast */
    /* @3992212 load */
    /* @3992220 constant */
    /* @3992224 sub */
    /* @3992228 load */
    /* @3992236 constant */
    /* @3992240 add */
    /* @3992244 call */
    GM_SITE(vm, 168, 3992244);
    v106 = GM_ADD(GM_READ(vm, -1, "x"), VAL(12));
    /* @3992252 store */
    v107 = GM_CALL(vm, "instance_create", 3, v106, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID14", v107);
    /* @3992260 load */
    /* @3992268 cast */
    /* @3992272 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID14")))) goto L_3992304;
    L_3992276: ;
    /* @3992276 constant */
    /* @3992280 cast */
    /* @3992284 load */
    /* @3992292 call */
    GM_SITE(vm, 168, 3992292);
    /* @3992300 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread14"), VAL(5)));
    L_3992304: ;
    /* @3992304 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3992276;
    /* @3992308 constant */
    /* @3992312 cast */
    /* @3992316 load */
    /* @3992324 constant */
    /* @3992328 sub */
    /* @3992332 load */
    /* @3992340 constant */
    /* @3992344 sub */
    /* @3992348 call */
    GM_SITE(vm, 168, 3992348);
    /* @3992356 store */
    v108 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(12)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID15", v108);
    /* @3992364 load */
    /* @3992372 cast */
    /* @3992376 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID15")))) goto L_3992408;
    L_3992380: ;
    /* @3992380 constant */
    /* @3992384 cast */
    /* @3992388 load */
    /* @3992396 call */
    GM_SITE(vm, 168, 3992396);
    /* @3992404 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread15"), VAL(5)));
    L_3992408: ;
    /* @3992408 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3992380;
    /* @3992412 constant */
    /* @3992416 cast */
    /* @3992420 load */
    /* @3992428 constant */
    /* @3992432 sub */
    /* @3992436 load */
    /* @3992444 constant */
    /* @3992448 add */
    /* @3992452 call */
    GM_SITE(vm, 168, 3992452);
    v109 = GM_ADD(GM_READ(vm, -1, "x"), VAL(15));
    /* @3992460 store */
    v110 = GM_CALL(vm, "instance_create", 3, v109, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID16", v110);
    /* @3992468 load */
    /* @3992476 cast */
    /* @3992480 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID16")))) goto L_3992512;
    L_3992484: ;
    /* @3992484 constant */
    /* @3992488 cast */
    /* @3992492 load */
    /* @3992500 call */
    GM_SITE(vm, 168, 3992500);
    /* @3992508 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread16"), VAL(5)));
    L_3992512: ;
    /* @3992512 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3992484;
    /* @3992516 constant */
    /* @3992520 cast */
    /* @3992524 load */
    /* @3992532 constant */
    /* @3992536 sub */
    /* @3992540 load */
    /* @3992548 constant */
    /* @3992552 add */
    /* @3992556 call */
    GM_SITE(vm, 168, 3992556);
    v111 = GM_ADD(GM_READ(vm, -1, "x"), VAL(14));
    /* @3992564 store */
    v112 = GM_CALL(vm, "instance_create", 3, v111, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID17", v112);
    /* @3992572 load */
    /* @3992580 cast */
    /* @3992584 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID17")))) goto L_3992616;
    L_3992588: ;
    /* @3992588 constant */
    /* @3992592 cast */
    /* @3992596 load */
    /* @3992604 call */
    GM_SITE(vm, 168, 3992604);
    /* @3992612 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread17"), VAL(5)));
    L_3992616: ;
    /* @3992616 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3992588;
    /* @3992620 constant */
    /* @3992624 cast */
    /* @3992628 load */
    /* @3992636 constant */
    /* @3992640 sub */
    /* @3992644 load */
    /* @3992652 constant */
    /* @3992656 sub */
    /* @3992660 call */
    GM_SITE(vm, 168, 3992660);
    /* @3992668 store */
    v113 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(14)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID18", v113);
    /* @3992676 load */
    /* @3992684 cast */
    /* @3992688 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID18")))) goto L_3992720;
    L_3992692: ;
    /* @3992692 constant */
    /* @3992696 cast */
    /* @3992700 load */
    /* @3992708 call */
    GM_SITE(vm, 168, 3992708);
    /* @3992716 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread18"), VAL(5)));
    L_3992720: ;
    /* @3992720 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3992692;
    /* @3992724 constant */
    /* @3992728 cast */
    /* @3992732 load */
    /* @3992740 constant */
    /* @3992744 sub */
    /* @3992748 load */
    /* @3992756 constant */
    /* @3992760 add */
    /* @3992764 call */
    GM_SITE(vm, 168, 3992764);
    v114 = GM_ADD(GM_READ(vm, -1, "x"), VAL(16));
    /* @3992772 store */
    v115 = GM_CALL(vm, "instance_create", 3, v114, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID19", v115);
    /* @3992780 load */
    /* @3992788 cast */
    /* @3992792 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID19")))) goto L_3992824;
    L_3992796: ;
    /* @3992796 constant */
    /* @3992800 cast */
    /* @3992804 load */
    /* @3992812 call */
    GM_SITE(vm, 168, 3992812);
    /* @3992820 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread19"), VAL(5)));
    L_3992824: ;
    /* @3992824 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3992796;
    /* @3992828 constant */
    /* @3992832 cast */
    /* @3992836 load */
    /* @3992844 constant */
    /* @3992848 sub */
    /* @3992852 load */
    /* @3992860 constant */
    /* @3992864 sub */
    /* @3992868 call */
    GM_SITE(vm, 168, 3992868);
    /* @3992876 store */
    v116 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(16)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID20", v116);
    /* @3992884 load */
    /* @3992892 cast */
    /* @3992896 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID20")))) goto L_3992928;
    L_3992900: ;
    /* @3992900 constant */
    /* @3992904 cast */
    /* @3992908 load */
    /* @3992916 call */
    GM_SITE(vm, 168, 3992916);
    /* @3992924 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread20"), VAL(5)));
    L_3992928: ;
    /* @3992928 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3992900;
    /* @3992932 constant */
    /* @3992936 cast */
    /* @3992940 load */
    /* @3992948 constant */
    /* @3992952 sub */
    /* @3992956 load */
    /* @3992964 constant */
    /* @3992968 sub */
    /* @3992972 call */
    GM_SITE(vm, 168, 3992972);
    /* @3992980 store */
    v117 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(15)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID21", v117);
    /* @3992988 load */
    /* @3992996 cast */
    /* @3993000 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID21")))) goto L_3993032;
    L_3993004: ;
    /* @3993004 constant */
    /* @3993008 cast */
    /* @3993012 load */
    /* @3993020 call */
    GM_SITE(vm, 168, 3993020);
    /* @3993028 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread21"), VAL(5)));
    L_3993032: ;
    /* @3993032 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3993004;
    /* @3993036 constant */
    /* @3993040 cast */
    /* @3993044 load */
    /* @3993052 constant */
    /* @3993056 sub */
    /* @3993060 load */
    /* @3993068 constant */
    /* @3993072 add */
    /* @3993076 call */
    GM_SITE(vm, 168, 3993076);
    v118 = GM_ADD(GM_READ(vm, -1, "x"), VAL(18));
    /* @3993084 store */
    v119 = GM_CALL(vm, "instance_create", 3, v118, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID22", v119);
    /* @3993092 load */
    /* @3993100 cast */
    /* @3993104 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID22")))) goto L_3993136;
    L_3993108: ;
    /* @3993108 constant */
    /* @3993112 cast */
    /* @3993116 load */
    /* @3993124 call */
    GM_SITE(vm, 168, 3993124);
    /* @3993132 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread22"), VAL(5)));
    L_3993136: ;
    /* @3993136 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3993108;
    /* @3993140 constant */
    /* @3993144 cast */
    /* @3993148 load */
    /* @3993156 constant */
    /* @3993160 sub */
    /* @3993164 load */
    /* @3993172 constant */
    /* @3993176 sub */
    /* @3993180 call */
    GM_SITE(vm, 168, 3993180);
    /* @3993188 store */
    v120 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(18)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID23", v120);
    /* @3993196 load */
    /* @3993204 cast */
    /* @3993208 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID23")))) goto L_3993240;
    L_3993212: ;
    /* @3993212 constant */
    /* @3993216 cast */
    /* @3993220 load */
    /* @3993228 call */
    GM_SITE(vm, 168, 3993228);
    /* @3993236 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread23"), VAL(5)));
    L_3993240: ;
    /* @3993240 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3993212;
    /* @3993244 constant */
    /* @3993248 cast */
    /* @3993252 load */
    /* @3993260 constant */
    /* @3993264 sub */
    /* @3993268 load */
    /* @3993276 constant */
    /* @3993280 add */
    /* @3993284 call */
    GM_SITE(vm, 168, 3993284);
    v121 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @3993292 store */
    v122 = GM_CALL(vm, "instance_create", 3, v121, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID24", v122);
    /* @3993300 load */
    /* @3993308 cast */
    /* @3993312 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID24")))) goto L_3993344;
    L_3993316: ;
    /* @3993316 constant */
    /* @3993320 cast */
    /* @3993324 load */
    /* @3993332 call */
    GM_SITE(vm, 168, 3993332);
    /* @3993340 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread24"), VAL(5)));
    L_3993344: ;
    /* @3993344 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3993316;
    /* @3993348 constant */
    /* @3993352 cast */
    /* @3993356 load */
    /* @3993364 constant */
    /* @3993368 sub */
    /* @3993372 load */
    /* @3993380 constant */
    /* @3993384 sub */
    /* @3993388 call */
    GM_SITE(vm, 168, 3993388);
    /* @3993396 store */
    v123 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(20)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID25", v123);
    /* @3993404 load */
    /* @3993412 cast */
    /* @3993416 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID25")))) goto L_3993448;
    L_3993420: ;
    /* @3993420 constant */
    /* @3993424 cast */
    /* @3993428 load */
    /* @3993436 call */
    GM_SITE(vm, 168, 3993436);
    /* @3993444 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread25"), VAL(5)));
    L_3993448: ;
    /* @3993448 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3993420;
    L_3993452: ;
    /* @3993452 call */
    GM_SITE(vm, 168, 3993452);
    /* @3993460 popz */
    (void)(GM_CALL(vm, "action_kill_object", 0));
    L_3993464: ;
    return;
}
