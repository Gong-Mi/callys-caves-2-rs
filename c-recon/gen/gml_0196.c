/* generated from CODE 196 (gml_Object_obj_boss4_Alarm_0), source start 4006448, end 4015584. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0196(GmVM* vm) {
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
    /* @4006448 load */
    /* @4006456 constant */
    /* @4006460 cmp */
    /* @4006464 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4006472;
    /* @4006468 b */
    goto L_4006528;
    L_4006472: ;
    /* @4006472 load */
    /* @4006480 constant */
    /* @4006484 cmp */
    /* @4006488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4006528;
    /* @4006492 constant */
    /* @4006496 cast */
    /* @4006500 constant */
    /* @4006504 cast */
    /* @4006508 constant */
    /* @4006512 cast */
    /* @4006516 call */
    GM_SITE(vm, 196, 4006516);
    /* @4006524 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(7), VAL(0), VAL(0)));
    L_4006528: ;
    /* @4006528 load */
    /* @4006536 constant */
    /* @4006540 cmp */
    /* @4006544 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpdrop") == VAL(1)))) goto L_4006592;
    /* @4006548 constant */
    /* @4006552 cast */
    /* @4006556 load */
    /* @4006564 constant */
    /* @4006568 sub */
    /* @4006572 load */
    /* @4006580 call */
    GM_SITE(vm, 196, 4006580);
    /* @4006588 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(62)));
    L_4006592: ;
    /* @4006592 constant */
    /* @4006596 store */
    GM_WRITE(vm, -5, "boss4dead", VAL(1));
    /* @4006604 load */
    /* @4006612 constant */
    /* @4006616 cmp */
    /* @4006620 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "gemdropenabled") == VAL(1)))) goto L_4006668;
    /* @4006624 constant */
    /* @4006628 cast */
    /* @4006632 load */
    /* @4006640 constant */
    /* @4006644 sub */
    /* @4006648 load */
    /* @4006656 call */
    GM_SITE(vm, 196, 4006656);
    /* @4006664 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(59)));
    L_4006668: ;
    /* @4006668 load */
    /* @4006676 constant */
    /* @4006680 cmp */
    /* @4006684 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "xpdrop") == VAL(1)))) goto L_4007712;
    /* @4006688 constant */
    /* @4006692 cast */
    /* @4006696 load */
    /* @4006704 constant */
    /* @4006708 sub */
    /* @4006712 load */
    /* @4006720 call */
    GM_SITE(vm, 196, 4006720);
    /* @4006728 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID", v1);
    /* @4006736 load */
    /* @4006744 cast */
    /* @4006748 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4006780;
    L_4006752: ;
    /* @4006752 constant */
    /* @4006756 cast */
    /* @4006760 load */
    /* @4006768 call */
    GM_SITE(vm, 196, 4006768);
    /* @4006776 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4006780: ;
    /* @4006780 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4006752;
    /* @4006784 constant */
    /* @4006788 cast */
    /* @4006792 load */
    /* @4006800 constant */
    /* @4006804 sub */
    /* @4006808 load */
    /* @4006816 constant */
    /* @4006820 add */
    /* @4006824 call */
    GM_SITE(vm, 196, 4006824);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(7));
    /* @4006832 store */
    v3 = GM_CALL(vm, "instance_create", 3, v2, (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID2", v3);
    /* @4006840 load */
    /* @4006848 cast */
    /* @4006852 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4006884;
    L_4006856: ;
    /* @4006856 constant */
    /* @4006860 cast */
    /* @4006864 load */
    /* @4006872 call */
    GM_SITE(vm, 196, 4006872);
    /* @4006880 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4006884: ;
    /* @4006884 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4006856;
    /* @4006888 constant */
    /* @4006892 cast */
    /* @4006896 load */
    /* @4006904 constant */
    /* @4006908 sub */
    /* @4006912 load */
    /* @4006920 constant */
    /* @4006924 sub */
    /* @4006928 call */
    GM_SITE(vm, 196, 4006928);
    /* @4006936 store */
    v4 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(7)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID3", v4);
    /* @4006944 load */
    /* @4006952 cast */
    /* @4006956 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4006988;
    L_4006960: ;
    /* @4006960 constant */
    /* @4006964 cast */
    /* @4006968 load */
    /* @4006976 call */
    GM_SITE(vm, 196, 4006976);
    /* @4006984 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4006988: ;
    /* @4006988 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4006960;
    /* @4006992 constant */
    /* @4006996 cast */
    /* @4007000 load */
    /* @4007008 constant */
    /* @4007012 sub */
    /* @4007016 load */
    /* @4007024 constant */
    /* @4007028 add */
    /* @4007032 call */
    GM_SITE(vm, 196, 4007032);
    v5 = GM_ADD(GM_READ(vm, -1, "x"), VAL(12));
    /* @4007040 store */
    v6 = GM_CALL(vm, "instance_create", 3, v5, (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID4", v6);
    /* @4007048 load */
    /* @4007056 cast */
    /* @4007060 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4007092;
    L_4007064: ;
    /* @4007064 constant */
    /* @4007068 cast */
    /* @4007072 load */
    /* @4007080 call */
    GM_SITE(vm, 196, 4007080);
    /* @4007088 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4007092: ;
    /* @4007092 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4007064;
    /* @4007096 constant */
    /* @4007100 cast */
    /* @4007104 load */
    /* @4007112 constant */
    /* @4007116 sub */
    /* @4007120 load */
    /* @4007128 constant */
    /* @4007132 sub */
    /* @4007136 call */
    GM_SITE(vm, 196, 4007136);
    /* @4007144 store */
    v7 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(12)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID5", v7);
    /* @4007152 load */
    /* @4007160 cast */
    /* @4007164 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4007196;
    L_4007168: ;
    /* @4007168 constant */
    /* @4007172 cast */
    /* @4007176 load */
    /* @4007184 call */
    GM_SITE(vm, 196, 4007184);
    /* @4007192 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4007196: ;
    /* @4007196 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4007168;
    /* @4007200 constant */
    /* @4007204 cast */
    /* @4007208 load */
    /* @4007216 constant */
    /* @4007220 sub */
    /* @4007224 load */
    /* @4007232 call */
    GM_SITE(vm, 196, 4007232);
    /* @4007240 store */
    v8 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID6", v8);
    /* @4007248 load */
    /* @4007256 cast */
    /* @4007260 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_4007292;
    L_4007264: ;
    /* @4007264 constant */
    /* @4007268 cast */
    /* @4007272 load */
    /* @4007280 call */
    GM_SITE(vm, 196, 4007280);
    /* @4007288 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4007292: ;
    /* @4007292 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4007264;
    /* @4007296 constant */
    /* @4007300 cast */
    /* @4007304 load */
    /* @4007312 constant */
    /* @4007316 sub */
    /* @4007320 load */
    /* @4007328 constant */
    /* @4007332 add */
    /* @4007336 call */
    GM_SITE(vm, 196, 4007336);
    v9 = GM_ADD(GM_READ(vm, -1, "x"), VAL(16));
    /* @4007344 store */
    v10 = GM_CALL(vm, "instance_create", 3, v9, (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID7", v10);
    /* @4007352 load */
    /* @4007360 cast */
    /* @4007364 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_4007396;
    L_4007368: ;
    /* @4007368 constant */
    /* @4007372 cast */
    /* @4007376 load */
    /* @4007384 call */
    GM_SITE(vm, 196, 4007384);
    /* @4007392 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4007396: ;
    /* @4007396 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4007368;
    /* @4007400 constant */
    /* @4007404 cast */
    /* @4007408 load */
    /* @4007416 constant */
    /* @4007420 sub */
    /* @4007424 load */
    /* @4007432 constant */
    /* @4007436 sub */
    /* @4007440 call */
    GM_SITE(vm, 196, 4007440);
    /* @4007448 store */
    v11 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(17)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID8", v11);
    /* @4007456 load */
    /* @4007464 cast */
    /* @4007468 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_4007500;
    L_4007472: ;
    /* @4007472 constant */
    /* @4007476 cast */
    /* @4007480 load */
    /* @4007488 call */
    GM_SITE(vm, 196, 4007488);
    /* @4007496 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4007500: ;
    /* @4007500 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4007472;
    /* @4007504 constant */
    /* @4007508 cast */
    /* @4007512 load */
    /* @4007520 constant */
    /* @4007524 sub */
    /* @4007528 load */
    /* @4007536 constant */
    /* @4007540 add */
    /* @4007544 call */
    GM_SITE(vm, 196, 4007544);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @4007552 store */
    v13 = GM_CALL(vm, "instance_create", 3, v12, (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID9", v13);
    /* @4007560 load */
    /* @4007568 cast */
    /* @4007572 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_4007604;
    L_4007576: ;
    /* @4007576 constant */
    /* @4007580 cast */
    /* @4007584 load */
    /* @4007592 call */
    GM_SITE(vm, 196, 4007592);
    /* @4007600 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4007604: ;
    /* @4007604 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4007576;
    /* @4007608 constant */
    /* @4007612 cast */
    /* @4007616 load */
    /* @4007624 constant */
    /* @4007628 sub */
    /* @4007632 load */
    /* @4007640 constant */
    /* @4007644 sub */
    /* @4007648 call */
    GM_SITE(vm, 196, 4007648);
    /* @4007656 store */
    v14 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(21)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID10", v14);
    /* @4007664 load */
    /* @4007672 cast */
    /* @4007676 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_4007708;
    L_4007680: ;
    /* @4007680 constant */
    /* @4007684 cast */
    /* @4007688 load */
    /* @4007696 call */
    GM_SITE(vm, 196, 4007696);
    /* @4007704 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4007708: ;
    /* @4007708 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4007680;
    L_4007712: ;
    /* @4007712 load */
    /* @4007720 constant */
    /* @4007724 cmp */
    /* @4007728 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(1)))) goto L_4008244;
    /* @4007732 constant */
    /* @4007736 cast */
    /* @4007740 load */
    /* @4007748 constant */
    /* @4007752 sub */
    /* @4007756 load */
    /* @4007764 call */
    GM_SITE(vm, 196, 4007764);
    /* @4007772 store */
    v15 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v15);
    /* @4007780 load */
    /* @4007788 cast */
    /* @4007792 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4007824;
    L_4007796: ;
    /* @4007796 constant */
    /* @4007800 cast */
    /* @4007804 load */
    /* @4007812 call */
    GM_SITE(vm, 196, 4007812);
    /* @4007820 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4007824: ;
    /* @4007824 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4007796;
    /* @4007828 constant */
    /* @4007832 cast */
    /* @4007836 load */
    /* @4007844 constant */
    /* @4007848 sub */
    /* @4007852 load */
    /* @4007860 constant */
    /* @4007864 add */
    /* @4007868 call */
    GM_SITE(vm, 196, 4007868);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4007876 store */
    v17 = GM_CALL(vm, "instance_create", 3, v16, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v17);
    /* @4007884 load */
    /* @4007892 cast */
    /* @4007896 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4007928;
    L_4007900: ;
    /* @4007900 constant */
    /* @4007904 cast */
    /* @4007908 load */
    /* @4007916 call */
    GM_SITE(vm, 196, 4007916);
    /* @4007924 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4007928: ;
    /* @4007928 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4007900;
    /* @4007932 constant */
    /* @4007936 cast */
    /* @4007940 load */
    /* @4007948 constant */
    /* @4007952 sub */
    /* @4007956 load */
    /* @4007964 constant */
    /* @4007968 sub */
    /* @4007972 call */
    GM_SITE(vm, 196, 4007972);
    /* @4007980 store */
    v18 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v18);
    /* @4007988 load */
    /* @4007996 cast */
    /* @4008000 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4008032;
    L_4008004: ;
    /* @4008004 constant */
    /* @4008008 cast */
    /* @4008012 load */
    /* @4008020 call */
    GM_SITE(vm, 196, 4008020);
    /* @4008028 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4008032: ;
    /* @4008032 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4008004;
    /* @4008036 constant */
    /* @4008040 cast */
    /* @4008044 load */
    /* @4008052 constant */
    /* @4008056 sub */
    /* @4008060 load */
    /* @4008068 constant */
    /* @4008072 add */
    /* @4008076 call */
    GM_SITE(vm, 196, 4008076);
    v19 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4008084 store */
    v20 = GM_CALL(vm, "instance_create", 3, v19, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v20);
    /* @4008092 load */
    /* @4008100 cast */
    /* @4008104 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4008136;
    L_4008108: ;
    /* @4008108 constant */
    /* @4008112 cast */
    /* @4008116 load */
    /* @4008124 call */
    GM_SITE(vm, 196, 4008124);
    /* @4008132 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4008136: ;
    /* @4008136 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4008108;
    /* @4008140 constant */
    /* @4008144 cast */
    /* @4008148 load */
    /* @4008156 constant */
    /* @4008160 sub */
    /* @4008164 load */
    /* @4008172 constant */
    /* @4008176 sub */
    /* @4008180 call */
    GM_SITE(vm, 196, 4008180);
    /* @4008188 store */
    v21 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v21);
    /* @4008196 load */
    /* @4008204 cast */
    /* @4008208 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4008240;
    L_4008212: ;
    /* @4008212 constant */
    /* @4008216 cast */
    /* @4008220 load */
    /* @4008228 call */
    GM_SITE(vm, 196, 4008228);
    /* @4008236 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4008240: ;
    /* @4008240 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4008212;
    L_4008244: ;
    /* @4008244 load */
    /* @4008252 constant */
    /* @4008256 cmp */
    /* @4008260 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(2)))) goto L_4009296;
    /* @4008264 constant */
    /* @4008268 cast */
    /* @4008272 load */
    /* @4008280 constant */
    /* @4008284 sub */
    /* @4008288 load */
    /* @4008296 call */
    GM_SITE(vm, 196, 4008296);
    /* @4008304 store */
    v22 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v22);
    /* @4008312 load */
    /* @4008320 cast */
    /* @4008324 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4008356;
    L_4008328: ;
    /* @4008328 constant */
    /* @4008332 cast */
    /* @4008336 load */
    /* @4008344 call */
    GM_SITE(vm, 196, 4008344);
    /* @4008352 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4008356: ;
    /* @4008356 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4008328;
    /* @4008360 constant */
    /* @4008364 cast */
    /* @4008368 load */
    /* @4008376 constant */
    /* @4008380 sub */
    /* @4008384 load */
    /* @4008392 constant */
    /* @4008396 add */
    /* @4008400 call */
    GM_SITE(vm, 196, 4008400);
    v23 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4008408 store */
    v24 = GM_CALL(vm, "instance_create", 3, v23, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v24);
    /* @4008416 load */
    /* @4008424 cast */
    /* @4008428 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4008460;
    L_4008432: ;
    /* @4008432 constant */
    /* @4008436 cast */
    /* @4008440 load */
    /* @4008448 call */
    GM_SITE(vm, 196, 4008448);
    /* @4008456 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4008460: ;
    /* @4008460 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4008432;
    /* @4008464 constant */
    /* @4008468 cast */
    /* @4008472 load */
    /* @4008480 constant */
    /* @4008484 sub */
    /* @4008488 load */
    /* @4008496 constant */
    /* @4008500 sub */
    /* @4008504 call */
    GM_SITE(vm, 196, 4008504);
    /* @4008512 store */
    v25 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v25);
    /* @4008520 load */
    /* @4008528 cast */
    /* @4008532 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4008564;
    L_4008536: ;
    /* @4008536 constant */
    /* @4008540 cast */
    /* @4008544 load */
    /* @4008552 call */
    GM_SITE(vm, 196, 4008552);
    /* @4008560 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4008564: ;
    /* @4008564 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4008536;
    /* @4008568 constant */
    /* @4008572 cast */
    /* @4008576 load */
    /* @4008584 constant */
    /* @4008588 sub */
    /* @4008592 load */
    /* @4008600 constant */
    /* @4008604 add */
    /* @4008608 call */
    GM_SITE(vm, 196, 4008608);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4008616 store */
    v27 = GM_CALL(vm, "instance_create", 3, v26, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v27);
    /* @4008624 load */
    /* @4008632 cast */
    /* @4008636 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4008668;
    L_4008640: ;
    /* @4008640 constant */
    /* @4008644 cast */
    /* @4008648 load */
    /* @4008656 call */
    GM_SITE(vm, 196, 4008656);
    /* @4008664 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4008668: ;
    /* @4008668 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4008640;
    /* @4008672 constant */
    /* @4008676 cast */
    /* @4008680 load */
    /* @4008688 constant */
    /* @4008692 sub */
    /* @4008696 load */
    /* @4008704 constant */
    /* @4008708 sub */
    /* @4008712 call */
    GM_SITE(vm, 196, 4008712);
    /* @4008720 store */
    v28 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v28);
    /* @4008728 load */
    /* @4008736 cast */
    /* @4008740 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4008772;
    L_4008744: ;
    /* @4008744 constant */
    /* @4008748 cast */
    /* @4008752 load */
    /* @4008760 call */
    GM_SITE(vm, 196, 4008760);
    /* @4008768 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4008772: ;
    /* @4008772 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4008744;
    /* @4008776 constant */
    /* @4008780 cast */
    /* @4008784 load */
    /* @4008792 constant */
    /* @4008796 sub */
    /* @4008800 load */
    /* @4008808 constant */
    /* @4008812 sub */
    /* @4008816 call */
    GM_SITE(vm, 196, 4008816);
    /* @4008824 store */
    v29 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v29);
    /* @4008832 load */
    /* @4008840 cast */
    /* @4008844 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_4008876;
    L_4008848: ;
    /* @4008848 constant */
    /* @4008852 cast */
    /* @4008856 load */
    /* @4008864 call */
    GM_SITE(vm, 196, 4008864);
    /* @4008872 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_4008876: ;
    /* @4008876 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4008848;
    /* @4008880 constant */
    /* @4008884 cast */
    /* @4008888 load */
    /* @4008896 constant */
    /* @4008900 sub */
    /* @4008904 load */
    /* @4008912 constant */
    /* @4008916 add */
    /* @4008920 call */
    GM_SITE(vm, 196, 4008920);
    v30 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @4008928 store */
    v31 = GM_CALL(vm, "instance_create", 3, v30, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v31);
    /* @4008936 load */
    /* @4008944 cast */
    /* @4008948 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_4008980;
    L_4008952: ;
    /* @4008952 constant */
    /* @4008956 cast */
    /* @4008960 load */
    /* @4008968 call */
    GM_SITE(vm, 196, 4008968);
    /* @4008976 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_4008980: ;
    /* @4008980 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4008952;
    /* @4008984 constant */
    /* @4008988 cast */
    /* @4008992 load */
    /* @4009000 constant */
    /* @4009004 sub */
    /* @4009008 load */
    /* @4009016 constant */
    /* @4009020 sub */
    /* @4009024 call */
    GM_SITE(vm, 196, 4009024);
    /* @4009032 store */
    v32 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v32);
    /* @4009040 load */
    /* @4009048 cast */
    /* @4009052 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_4009084;
    L_4009056: ;
    /* @4009056 constant */
    /* @4009060 cast */
    /* @4009064 load */
    /* @4009072 call */
    GM_SITE(vm, 196, 4009072);
    /* @4009080 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_4009084: ;
    /* @4009084 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4009056;
    /* @4009088 constant */
    /* @4009092 cast */
    /* @4009096 load */
    /* @4009104 constant */
    /* @4009108 sub */
    /* @4009112 load */
    /* @4009120 constant */
    /* @4009124 add */
    /* @4009128 call */
    GM_SITE(vm, 196, 4009128);
    v33 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @4009136 store */
    v34 = GM_CALL(vm, "instance_create", 3, v33, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v34);
    /* @4009144 load */
    /* @4009152 cast */
    /* @4009156 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_4009188;
    L_4009160: ;
    /* @4009160 constant */
    /* @4009164 cast */
    /* @4009168 load */
    /* @4009176 call */
    GM_SITE(vm, 196, 4009176);
    /* @4009184 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_4009188: ;
    /* @4009188 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4009160;
    /* @4009192 constant */
    /* @4009196 cast */
    /* @4009200 load */
    /* @4009208 constant */
    /* @4009212 sub */
    /* @4009216 load */
    /* @4009224 constant */
    /* @4009228 sub */
    /* @4009232 call */
    GM_SITE(vm, 196, 4009232);
    /* @4009240 store */
    v35 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v35);
    /* @4009248 load */
    /* @4009256 cast */
    /* @4009260 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_4009292;
    L_4009264: ;
    /* @4009264 constant */
    /* @4009268 cast */
    /* @4009272 load */
    /* @4009280 call */
    GM_SITE(vm, 196, 4009280);
    /* @4009288 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_4009292: ;
    /* @4009292 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4009264;
    L_4009296: ;
    /* @4009296 load */
    /* @4009304 constant */
    /* @4009308 cmp */
    /* @4009312 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(3)))) goto L_4010868;
    /* @4009316 constant */
    /* @4009320 cast */
    /* @4009324 load */
    /* @4009332 constant */
    /* @4009336 sub */
    /* @4009340 load */
    /* @4009348 call */
    GM_SITE(vm, 196, 4009348);
    /* @4009356 store */
    v36 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v36);
    /* @4009364 load */
    /* @4009372 cast */
    /* @4009376 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4009408;
    L_4009380: ;
    /* @4009380 constant */
    /* @4009384 cast */
    /* @4009388 load */
    /* @4009396 call */
    GM_SITE(vm, 196, 4009396);
    /* @4009404 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4009408: ;
    /* @4009408 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4009380;
    /* @4009412 constant */
    /* @4009416 cast */
    /* @4009420 load */
    /* @4009428 constant */
    /* @4009432 sub */
    /* @4009436 load */
    /* @4009444 constant */
    /* @4009448 add */
    /* @4009452 call */
    GM_SITE(vm, 196, 4009452);
    v37 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4009460 store */
    v38 = GM_CALL(vm, "instance_create", 3, v37, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v38);
    /* @4009468 load */
    /* @4009476 cast */
    /* @4009480 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4009512;
    L_4009484: ;
    /* @4009484 constant */
    /* @4009488 cast */
    /* @4009492 load */
    /* @4009500 call */
    GM_SITE(vm, 196, 4009500);
    /* @4009508 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4009512: ;
    /* @4009512 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4009484;
    /* @4009516 constant */
    /* @4009520 cast */
    /* @4009524 load */
    /* @4009532 constant */
    /* @4009536 sub */
    /* @4009540 load */
    /* @4009548 constant */
    /* @4009552 sub */
    /* @4009556 call */
    GM_SITE(vm, 196, 4009556);
    /* @4009564 store */
    v39 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v39);
    /* @4009572 load */
    /* @4009580 cast */
    /* @4009584 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4009616;
    L_4009588: ;
    /* @4009588 constant */
    /* @4009592 cast */
    /* @4009596 load */
    /* @4009604 call */
    GM_SITE(vm, 196, 4009604);
    /* @4009612 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4009616: ;
    /* @4009616 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4009588;
    /* @4009620 constant */
    /* @4009624 cast */
    /* @4009628 load */
    /* @4009636 constant */
    /* @4009640 sub */
    /* @4009644 load */
    /* @4009652 constant */
    /* @4009656 add */
    /* @4009660 call */
    GM_SITE(vm, 196, 4009660);
    v40 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4009668 store */
    v41 = GM_CALL(vm, "instance_create", 3, v40, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v41);
    /* @4009676 load */
    /* @4009684 cast */
    /* @4009688 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4009720;
    L_4009692: ;
    /* @4009692 constant */
    /* @4009696 cast */
    /* @4009700 load */
    /* @4009708 call */
    GM_SITE(vm, 196, 4009708);
    /* @4009716 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4009720: ;
    /* @4009720 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4009692;
    /* @4009724 constant */
    /* @4009728 cast */
    /* @4009732 load */
    /* @4009740 constant */
    /* @4009744 sub */
    /* @4009748 load */
    /* @4009756 constant */
    /* @4009760 sub */
    /* @4009764 call */
    GM_SITE(vm, 196, 4009764);
    /* @4009772 store */
    v42 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v42);
    /* @4009780 load */
    /* @4009788 cast */
    /* @4009792 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4009824;
    L_4009796: ;
    /* @4009796 constant */
    /* @4009800 cast */
    /* @4009804 load */
    /* @4009812 call */
    GM_SITE(vm, 196, 4009812);
    /* @4009820 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4009824: ;
    /* @4009824 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4009796;
    /* @4009828 constant */
    /* @4009832 cast */
    /* @4009836 load */
    /* @4009844 constant */
    /* @4009848 sub */
    /* @4009852 load */
    /* @4009860 constant */
    /* @4009864 sub */
    /* @4009868 call */
    GM_SITE(vm, 196, 4009868);
    /* @4009876 store */
    v43 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v43);
    /* @4009884 load */
    /* @4009892 cast */
    /* @4009896 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_4009928;
    L_4009900: ;
    /* @4009900 constant */
    /* @4009904 cast */
    /* @4009908 load */
    /* @4009916 call */
    GM_SITE(vm, 196, 4009916);
    /* @4009924 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_4009928: ;
    /* @4009928 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4009900;
    /* @4009932 constant */
    /* @4009936 cast */
    /* @4009940 load */
    /* @4009948 constant */
    /* @4009952 sub */
    /* @4009956 load */
    /* @4009964 constant */
    /* @4009968 add */
    /* @4009972 call */
    GM_SITE(vm, 196, 4009972);
    v44 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @4009980 store */
    v45 = GM_CALL(vm, "instance_create", 3, v44, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v45);
    /* @4009988 load */
    /* @4009996 cast */
    /* @4010000 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_4010032;
    L_4010004: ;
    /* @4010004 constant */
    /* @4010008 cast */
    /* @4010012 load */
    /* @4010020 call */
    GM_SITE(vm, 196, 4010020);
    /* @4010028 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_4010032: ;
    /* @4010032 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4010004;
    /* @4010036 constant */
    /* @4010040 cast */
    /* @4010044 load */
    /* @4010052 constant */
    /* @4010056 sub */
    /* @4010060 load */
    /* @4010068 constant */
    /* @4010072 sub */
    /* @4010076 call */
    GM_SITE(vm, 196, 4010076);
    /* @4010084 store */
    v46 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v46);
    /* @4010092 load */
    /* @4010100 cast */
    /* @4010104 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_4010136;
    L_4010108: ;
    /* @4010108 constant */
    /* @4010112 cast */
    /* @4010116 load */
    /* @4010124 call */
    GM_SITE(vm, 196, 4010124);
    /* @4010132 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_4010136: ;
    /* @4010136 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4010108;
    /* @4010140 constant */
    /* @4010144 cast */
    /* @4010148 load */
    /* @4010156 constant */
    /* @4010160 sub */
    /* @4010164 load */
    /* @4010172 constant */
    /* @4010176 add */
    /* @4010180 call */
    GM_SITE(vm, 196, 4010180);
    v47 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @4010188 store */
    v48 = GM_CALL(vm, "instance_create", 3, v47, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v48);
    /* @4010196 load */
    /* @4010204 cast */
    /* @4010208 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_4010240;
    L_4010212: ;
    /* @4010212 constant */
    /* @4010216 cast */
    /* @4010220 load */
    /* @4010228 call */
    GM_SITE(vm, 196, 4010228);
    /* @4010236 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_4010240: ;
    /* @4010240 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4010212;
    /* @4010244 constant */
    /* @4010248 cast */
    /* @4010252 load */
    /* @4010260 constant */
    /* @4010264 sub */
    /* @4010268 load */
    /* @4010276 constant */
    /* @4010280 sub */
    /* @4010284 call */
    GM_SITE(vm, 196, 4010284);
    /* @4010292 store */
    v49 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v49);
    /* @4010300 load */
    /* @4010308 cast */
    /* @4010312 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_4010344;
    L_4010316: ;
    /* @4010316 constant */
    /* @4010320 cast */
    /* @4010324 load */
    /* @4010332 call */
    GM_SITE(vm, 196, 4010332);
    /* @4010340 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_4010344: ;
    /* @4010344 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4010316;
    /* @4010348 constant */
    /* @4010352 cast */
    /* @4010356 load */
    /* @4010364 constant */
    /* @4010368 sub */
    /* @4010372 load */
    /* @4010380 constant */
    /* @4010384 add */
    /* @4010388 call */
    GM_SITE(vm, 196, 4010388);
    v50 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @4010396 store */
    v51 = GM_CALL(vm, "instance_create", 3, v50, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v51);
    /* @4010404 load */
    /* @4010412 cast */
    /* @4010416 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_4010448;
    L_4010420: ;
    /* @4010420 constant */
    /* @4010424 cast */
    /* @4010428 load */
    /* @4010436 call */
    GM_SITE(vm, 196, 4010436);
    /* @4010444 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_4010448: ;
    /* @4010448 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4010420;
    /* @4010452 constant */
    /* @4010456 cast */
    /* @4010460 load */
    /* @4010468 constant */
    /* @4010472 sub */
    /* @4010476 load */
    /* @4010484 constant */
    /* @4010488 add */
    /* @4010492 call */
    GM_SITE(vm, 196, 4010492);
    v52 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @4010500 store */
    v53 = GM_CALL(vm, "instance_create", 3, v52, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID12", v53);
    /* @4010508 load */
    /* @4010516 cast */
    /* @4010520 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID12")))) goto L_4010552;
    L_4010524: ;
    /* @4010524 constant */
    /* @4010528 cast */
    /* @4010532 load */
    /* @4010540 call */
    GM_SITE(vm, 196, 4010540);
    /* @4010548 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread12"), VAL(5)));
    L_4010552: ;
    /* @4010552 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4010524;
    /* @4010556 constant */
    /* @4010560 cast */
    /* @4010564 load */
    /* @4010572 constant */
    /* @4010576 sub */
    /* @4010580 load */
    /* @4010588 constant */
    /* @4010592 sub */
    /* @4010596 call */
    GM_SITE(vm, 196, 4010596);
    /* @4010604 store */
    v54 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID13", v54);
    /* @4010612 load */
    /* @4010620 cast */
    /* @4010624 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID13")))) goto L_4010656;
    L_4010628: ;
    /* @4010628 constant */
    /* @4010632 cast */
    /* @4010636 load */
    /* @4010644 call */
    GM_SITE(vm, 196, 4010644);
    /* @4010652 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread13"), VAL(5)));
    L_4010656: ;
    /* @4010656 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4010628;
    /* @4010660 constant */
    /* @4010664 cast */
    /* @4010668 load */
    /* @4010676 constant */
    /* @4010680 sub */
    /* @4010684 load */
    /* @4010692 constant */
    /* @4010696 add */
    /* @4010700 call */
    GM_SITE(vm, 196, 4010700);
    v55 = GM_ADD(GM_READ(vm, -1, "x"), VAL(12));
    /* @4010708 store */
    v56 = GM_CALL(vm, "instance_create", 3, v55, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID14", v56);
    /* @4010716 load */
    /* @4010724 cast */
    /* @4010728 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID14")))) goto L_4010760;
    L_4010732: ;
    /* @4010732 constant */
    /* @4010736 cast */
    /* @4010740 load */
    /* @4010748 call */
    GM_SITE(vm, 196, 4010748);
    /* @4010756 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread14"), VAL(5)));
    L_4010760: ;
    /* @4010760 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4010732;
    /* @4010764 constant */
    /* @4010768 cast */
    /* @4010772 load */
    /* @4010780 constant */
    /* @4010784 sub */
    /* @4010788 load */
    /* @4010796 constant */
    /* @4010800 sub */
    /* @4010804 call */
    GM_SITE(vm, 196, 4010804);
    /* @4010812 store */
    v57 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(12)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID15", v57);
    /* @4010820 load */
    /* @4010828 cast */
    /* @4010832 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID15")))) goto L_4010864;
    L_4010836: ;
    /* @4010836 constant */
    /* @4010840 cast */
    /* @4010844 load */
    /* @4010852 call */
    GM_SITE(vm, 196, 4010852);
    /* @4010860 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread15"), VAL(5)));
    L_4010864: ;
    /* @4010864 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4010836;
    L_4010868: ;
    /* @4010868 load */
    /* @4010876 constant */
    /* @4010880 cmp */
    /* @4010884 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(4)))) goto L_4012960;
    /* @4010888 constant */
    /* @4010892 cast */
    /* @4010896 load */
    /* @4010904 constant */
    /* @4010908 sub */
    /* @4010912 load */
    /* @4010920 call */
    GM_SITE(vm, 196, 4010920);
    /* @4010928 store */
    v58 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v58);
    /* @4010936 load */
    /* @4010944 cast */
    /* @4010948 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4010980;
    L_4010952: ;
    /* @4010952 constant */
    /* @4010956 cast */
    /* @4010960 load */
    /* @4010968 call */
    GM_SITE(vm, 196, 4010968);
    /* @4010976 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4010980: ;
    /* @4010980 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4010952;
    /* @4010984 constant */
    /* @4010988 cast */
    /* @4010992 load */
    /* @4011000 constant */
    /* @4011004 sub */
    /* @4011008 load */
    /* @4011016 constant */
    /* @4011020 add */
    /* @4011024 call */
    GM_SITE(vm, 196, 4011024);
    v59 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4011032 store */
    v60 = GM_CALL(vm, "instance_create", 3, v59, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v60);
    /* @4011040 load */
    /* @4011048 cast */
    /* @4011052 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4011084;
    L_4011056: ;
    /* @4011056 constant */
    /* @4011060 cast */
    /* @4011064 load */
    /* @4011072 call */
    GM_SITE(vm, 196, 4011072);
    /* @4011080 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4011084: ;
    /* @4011084 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4011056;
    /* @4011088 constant */
    /* @4011092 cast */
    /* @4011096 load */
    /* @4011104 constant */
    /* @4011108 sub */
    /* @4011112 load */
    /* @4011120 constant */
    /* @4011124 sub */
    /* @4011128 call */
    GM_SITE(vm, 196, 4011128);
    /* @4011136 store */
    v61 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v61);
    /* @4011144 load */
    /* @4011152 cast */
    /* @4011156 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4011188;
    L_4011160: ;
    /* @4011160 constant */
    /* @4011164 cast */
    /* @4011168 load */
    /* @4011176 call */
    GM_SITE(vm, 196, 4011176);
    /* @4011184 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4011188: ;
    /* @4011188 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4011160;
    /* @4011192 constant */
    /* @4011196 cast */
    /* @4011200 load */
    /* @4011208 constant */
    /* @4011212 sub */
    /* @4011216 load */
    /* @4011224 constant */
    /* @4011228 add */
    /* @4011232 call */
    GM_SITE(vm, 196, 4011232);
    v62 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4011240 store */
    v63 = GM_CALL(vm, "instance_create", 3, v62, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v63);
    /* @4011248 load */
    /* @4011256 cast */
    /* @4011260 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4011292;
    L_4011264: ;
    /* @4011264 constant */
    /* @4011268 cast */
    /* @4011272 load */
    /* @4011280 call */
    GM_SITE(vm, 196, 4011280);
    /* @4011288 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4011292: ;
    /* @4011292 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4011264;
    /* @4011296 constant */
    /* @4011300 cast */
    /* @4011304 load */
    /* @4011312 constant */
    /* @4011316 sub */
    /* @4011320 load */
    /* @4011328 constant */
    /* @4011332 sub */
    /* @4011336 call */
    GM_SITE(vm, 196, 4011336);
    /* @4011344 store */
    v64 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v64);
    /* @4011352 load */
    /* @4011360 cast */
    /* @4011364 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4011396;
    L_4011368: ;
    /* @4011368 constant */
    /* @4011372 cast */
    /* @4011376 load */
    /* @4011384 call */
    GM_SITE(vm, 196, 4011384);
    /* @4011392 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4011396: ;
    /* @4011396 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4011368;
    /* @4011400 constant */
    /* @4011404 cast */
    /* @4011408 load */
    /* @4011416 constant */
    /* @4011420 sub */
    /* @4011424 load */
    /* @4011432 constant */
    /* @4011436 add */
    /* @4011440 call */
    GM_SITE(vm, 196, 4011440);
    v65 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @4011448 store */
    v66 = GM_CALL(vm, "instance_create", 3, v65, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v66);
    /* @4011456 load */
    /* @4011464 cast */
    /* @4011468 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_4011500;
    L_4011472: ;
    /* @4011472 constant */
    /* @4011476 cast */
    /* @4011480 load */
    /* @4011488 call */
    GM_SITE(vm, 196, 4011488);
    /* @4011496 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_4011500: ;
    /* @4011500 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4011472;
    /* @4011504 constant */
    /* @4011508 cast */
    /* @4011512 load */
    /* @4011520 constant */
    /* @4011524 sub */
    /* @4011528 load */
    /* @4011536 constant */
    /* @4011540 add */
    /* @4011544 call */
    GM_SITE(vm, 196, 4011544);
    v67 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @4011552 store */
    v68 = GM_CALL(vm, "instance_create", 3, v67, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v68);
    /* @4011560 load */
    /* @4011568 cast */
    /* @4011572 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_4011604;
    L_4011576: ;
    /* @4011576 constant */
    /* @4011580 cast */
    /* @4011584 load */
    /* @4011592 call */
    GM_SITE(vm, 196, 4011592);
    /* @4011600 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_4011604: ;
    /* @4011604 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4011576;
    /* @4011608 constant */
    /* @4011612 cast */
    /* @4011616 load */
    /* @4011624 constant */
    /* @4011628 sub */
    /* @4011632 load */
    /* @4011640 constant */
    /* @4011644 sub */
    /* @4011648 call */
    GM_SITE(vm, 196, 4011648);
    /* @4011656 store */
    v69 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v69);
    /* @4011664 load */
    /* @4011672 cast */
    /* @4011676 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_4011708;
    L_4011680: ;
    /* @4011680 constant */
    /* @4011684 cast */
    /* @4011688 load */
    /* @4011696 call */
    GM_SITE(vm, 196, 4011696);
    /* @4011704 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_4011708: ;
    /* @4011708 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4011680;
    /* @4011712 constant */
    /* @4011716 cast */
    /* @4011720 load */
    /* @4011728 constant */
    /* @4011732 sub */
    /* @4011736 load */
    /* @4011744 constant */
    /* @4011748 add */
    /* @4011752 call */
    GM_SITE(vm, 196, 4011752);
    v70 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @4011760 store */
    v71 = GM_CALL(vm, "instance_create", 3, v70, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v71);
    /* @4011768 load */
    /* @4011776 cast */
    /* @4011780 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_4011812;
    L_4011784: ;
    /* @4011784 constant */
    /* @4011788 cast */
    /* @4011792 load */
    /* @4011800 call */
    GM_SITE(vm, 196, 4011800);
    /* @4011808 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_4011812: ;
    /* @4011812 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4011784;
    /* @4011816 constant */
    /* @4011820 cast */
    /* @4011824 load */
    /* @4011832 constant */
    /* @4011836 sub */
    /* @4011840 load */
    /* @4011848 constant */
    /* @4011852 sub */
    /* @4011856 call */
    GM_SITE(vm, 196, 4011856);
    /* @4011864 store */
    v72 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v72);
    /* @4011872 load */
    /* @4011880 cast */
    /* @4011884 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_4011916;
    L_4011888: ;
    /* @4011888 constant */
    /* @4011892 cast */
    /* @4011896 load */
    /* @4011904 call */
    GM_SITE(vm, 196, 4011904);
    /* @4011912 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_4011916: ;
    /* @4011916 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4011888;
    /* @4011920 constant */
    /* @4011924 cast */
    /* @4011928 load */
    /* @4011936 constant */
    /* @4011940 sub */
    /* @4011944 load */
    /* @4011952 constant */
    /* @4011956 sub */
    /* @4011960 call */
    GM_SITE(vm, 196, 4011960);
    /* @4011968 store */
    v73 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v73);
    /* @4011976 load */
    /* @4011984 cast */
    /* @4011988 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_4012020;
    L_4011992: ;
    /* @4011992 constant */
    /* @4011996 cast */
    /* @4012000 load */
    /* @4012008 call */
    GM_SITE(vm, 196, 4012008);
    /* @4012016 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_4012020: ;
    /* @4012020 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4011992;
    /* @4012024 constant */
    /* @4012028 cast */
    /* @4012032 load */
    /* @4012040 constant */
    /* @4012044 sub */
    /* @4012048 load */
    /* @4012056 constant */
    /* @4012060 add */
    /* @4012064 call */
    GM_SITE(vm, 196, 4012064);
    v74 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @4012072 store */
    v75 = GM_CALL(vm, "instance_create", 3, v74, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID12", v75);
    /* @4012080 load */
    /* @4012088 cast */
    /* @4012092 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID12")))) goto L_4012124;
    L_4012096: ;
    /* @4012096 constant */
    /* @4012100 cast */
    /* @4012104 load */
    /* @4012112 call */
    GM_SITE(vm, 196, 4012112);
    /* @4012120 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread12"), VAL(5)));
    L_4012124: ;
    /* @4012124 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4012096;
    /* @4012128 constant */
    /* @4012132 cast */
    /* @4012136 load */
    /* @4012144 constant */
    /* @4012148 sub */
    /* @4012152 load */
    /* @4012160 constant */
    /* @4012164 sub */
    /* @4012168 call */
    GM_SITE(vm, 196, 4012168);
    /* @4012176 store */
    v76 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID13", v76);
    /* @4012184 load */
    /* @4012192 cast */
    /* @4012196 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID13")))) goto L_4012228;
    L_4012200: ;
    /* @4012200 constant */
    /* @4012204 cast */
    /* @4012208 load */
    /* @4012216 call */
    GM_SITE(vm, 196, 4012216);
    /* @4012224 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread13"), VAL(5)));
    L_4012228: ;
    /* @4012228 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4012200;
    /* @4012232 constant */
    /* @4012236 cast */
    /* @4012240 load */
    /* @4012248 constant */
    /* @4012252 sub */
    /* @4012256 load */
    /* @4012264 constant */
    /* @4012268 add */
    /* @4012272 call */
    GM_SITE(vm, 196, 4012272);
    v77 = GM_ADD(GM_READ(vm, -1, "x"), VAL(12));
    /* @4012280 store */
    v78 = GM_CALL(vm, "instance_create", 3, v77, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID14", v78);
    /* @4012288 load */
    /* @4012296 cast */
    /* @4012300 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID14")))) goto L_4012332;
    L_4012304: ;
    /* @4012304 constant */
    /* @4012308 cast */
    /* @4012312 load */
    /* @4012320 call */
    GM_SITE(vm, 196, 4012320);
    /* @4012328 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread14"), VAL(5)));
    L_4012332: ;
    /* @4012332 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4012304;
    /* @4012336 constant */
    /* @4012340 cast */
    /* @4012344 load */
    /* @4012352 constant */
    /* @4012356 sub */
    /* @4012360 load */
    /* @4012368 constant */
    /* @4012372 sub */
    /* @4012376 call */
    GM_SITE(vm, 196, 4012376);
    /* @4012384 store */
    v79 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(12)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID15", v79);
    /* @4012392 load */
    /* @4012400 cast */
    /* @4012404 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID15")))) goto L_4012436;
    L_4012408: ;
    /* @4012408 constant */
    /* @4012412 cast */
    /* @4012416 load */
    /* @4012424 call */
    GM_SITE(vm, 196, 4012424);
    /* @4012432 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread15"), VAL(5)));
    L_4012436: ;
    /* @4012436 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4012408;
    /* @4012440 constant */
    /* @4012444 cast */
    /* @4012448 load */
    /* @4012456 constant */
    /* @4012460 sub */
    /* @4012464 load */
    /* @4012472 constant */
    /* @4012476 sub */
    /* @4012480 call */
    GM_SITE(vm, 196, 4012480);
    /* @4012488 store */
    v80 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID16", v80);
    /* @4012496 load */
    /* @4012504 cast */
    /* @4012508 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID16")))) goto L_4012540;
    L_4012512: ;
    /* @4012512 constant */
    /* @4012516 cast */
    /* @4012520 load */
    /* @4012528 call */
    GM_SITE(vm, 196, 4012528);
    /* @4012536 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread16"), VAL(5)));
    L_4012540: ;
    /* @4012540 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4012512;
    /* @4012544 constant */
    /* @4012548 cast */
    /* @4012552 load */
    /* @4012560 constant */
    /* @4012564 sub */
    /* @4012568 load */
    /* @4012576 constant */
    /* @4012580 add */
    /* @4012584 call */
    GM_SITE(vm, 196, 4012584);
    v81 = GM_ADD(GM_READ(vm, -1, "x"), VAL(14));
    /* @4012592 store */
    v82 = GM_CALL(vm, "instance_create", 3, v81, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID17", v82);
    /* @4012600 load */
    /* @4012608 cast */
    /* @4012612 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID17")))) goto L_4012644;
    L_4012616: ;
    /* @4012616 constant */
    /* @4012620 cast */
    /* @4012624 load */
    /* @4012632 call */
    GM_SITE(vm, 196, 4012632);
    /* @4012640 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread17"), VAL(5)));
    L_4012644: ;
    /* @4012644 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4012616;
    /* @4012648 constant */
    /* @4012652 cast */
    /* @4012656 load */
    /* @4012664 constant */
    /* @4012668 sub */
    /* @4012672 load */
    /* @4012680 constant */
    /* @4012684 sub */
    /* @4012688 call */
    GM_SITE(vm, 196, 4012688);
    /* @4012696 store */
    v83 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(14)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID18", v83);
    /* @4012704 load */
    /* @4012712 cast */
    /* @4012716 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID18")))) goto L_4012748;
    L_4012720: ;
    /* @4012720 constant */
    /* @4012724 cast */
    /* @4012728 load */
    /* @4012736 call */
    GM_SITE(vm, 196, 4012736);
    /* @4012744 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread18"), VAL(5)));
    L_4012748: ;
    /* @4012748 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4012720;
    /* @4012752 constant */
    /* @4012756 cast */
    /* @4012760 load */
    /* @4012768 constant */
    /* @4012772 sub */
    /* @4012776 load */
    /* @4012784 constant */
    /* @4012788 add */
    /* @4012792 call */
    GM_SITE(vm, 196, 4012792);
    v84 = GM_ADD(GM_READ(vm, -1, "x"), VAL(16));
    /* @4012800 store */
    v85 = GM_CALL(vm, "instance_create", 3, v84, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID19", v85);
    /* @4012808 load */
    /* @4012816 cast */
    /* @4012820 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID19")))) goto L_4012852;
    L_4012824: ;
    /* @4012824 constant */
    /* @4012828 cast */
    /* @4012832 load */
    /* @4012840 call */
    GM_SITE(vm, 196, 4012840);
    /* @4012848 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread19"), VAL(5)));
    L_4012852: ;
    /* @4012852 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4012824;
    /* @4012856 constant */
    /* @4012860 cast */
    /* @4012864 load */
    /* @4012872 constant */
    /* @4012876 sub */
    /* @4012880 load */
    /* @4012888 constant */
    /* @4012892 sub */
    /* @4012896 call */
    GM_SITE(vm, 196, 4012896);
    /* @4012904 store */
    v86 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(16)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID20", v86);
    /* @4012912 load */
    /* @4012920 cast */
    /* @4012924 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID20")))) goto L_4012956;
    L_4012928: ;
    /* @4012928 constant */
    /* @4012932 cast */
    /* @4012936 load */
    /* @4012944 call */
    GM_SITE(vm, 196, 4012944);
    /* @4012952 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread20"), VAL(5)));
    L_4012956: ;
    /* @4012956 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4012928;
    L_4012960: ;
    /* @4012960 load */
    /* @4012968 constant */
    /* @4012972 cmp */
    /* @4012976 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(5)))) goto L_4015572;
    /* @4012980 constant */
    /* @4012984 cast */
    /* @4012988 load */
    /* @4012996 constant */
    /* @4013000 sub */
    /* @4013004 load */
    /* @4013012 call */
    GM_SITE(vm, 196, 4013012);
    /* @4013020 store */
    v87 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v87);
    /* @4013028 load */
    /* @4013036 cast */
    /* @4013040 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4013072;
    L_4013044: ;
    /* @4013044 constant */
    /* @4013048 cast */
    /* @4013052 load */
    /* @4013060 call */
    GM_SITE(vm, 196, 4013060);
    /* @4013068 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4013072: ;
    /* @4013072 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4013044;
    /* @4013076 constant */
    /* @4013080 cast */
    /* @4013084 load */
    /* @4013092 constant */
    /* @4013096 sub */
    /* @4013100 load */
    /* @4013108 constant */
    /* @4013112 add */
    /* @4013116 call */
    GM_SITE(vm, 196, 4013116);
    v88 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4013124 store */
    v89 = GM_CALL(vm, "instance_create", 3, v88, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v89);
    /* @4013132 load */
    /* @4013140 cast */
    /* @4013144 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4013176;
    L_4013148: ;
    /* @4013148 constant */
    /* @4013152 cast */
    /* @4013156 load */
    /* @4013164 call */
    GM_SITE(vm, 196, 4013164);
    /* @4013172 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4013176: ;
    /* @4013176 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4013148;
    /* @4013180 constant */
    /* @4013184 cast */
    /* @4013188 load */
    /* @4013196 constant */
    /* @4013200 sub */
    /* @4013204 load */
    /* @4013212 constant */
    /* @4013216 sub */
    /* @4013220 call */
    GM_SITE(vm, 196, 4013220);
    /* @4013228 store */
    v90 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v90);
    /* @4013236 load */
    /* @4013244 cast */
    /* @4013248 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4013280;
    L_4013252: ;
    /* @4013252 constant */
    /* @4013256 cast */
    /* @4013260 load */
    /* @4013268 call */
    GM_SITE(vm, 196, 4013268);
    /* @4013276 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4013280: ;
    /* @4013280 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4013252;
    /* @4013284 constant */
    /* @4013288 cast */
    /* @4013292 load */
    /* @4013300 constant */
    /* @4013304 sub */
    /* @4013308 load */
    /* @4013316 constant */
    /* @4013320 add */
    /* @4013324 call */
    GM_SITE(vm, 196, 4013324);
    v91 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4013332 store */
    v92 = GM_CALL(vm, "instance_create", 3, v91, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v92);
    /* @4013340 load */
    /* @4013348 cast */
    /* @4013352 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4013384;
    L_4013356: ;
    /* @4013356 constant */
    /* @4013360 cast */
    /* @4013364 load */
    /* @4013372 call */
    GM_SITE(vm, 196, 4013372);
    /* @4013380 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4013384: ;
    /* @4013384 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4013356;
    /* @4013388 constant */
    /* @4013392 cast */
    /* @4013396 load */
    /* @4013404 constant */
    /* @4013408 sub */
    /* @4013412 load */
    /* @4013420 constant */
    /* @4013424 sub */
    /* @4013428 call */
    GM_SITE(vm, 196, 4013428);
    /* @4013436 store */
    v93 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v93);
    /* @4013444 load */
    /* @4013452 cast */
    /* @4013456 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4013488;
    L_4013460: ;
    /* @4013460 constant */
    /* @4013464 cast */
    /* @4013468 load */
    /* @4013476 call */
    GM_SITE(vm, 196, 4013476);
    /* @4013484 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4013488: ;
    /* @4013488 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4013460;
    /* @4013492 constant */
    /* @4013496 cast */
    /* @4013500 load */
    /* @4013508 constant */
    /* @4013512 sub */
    /* @4013516 load */
    /* @4013524 constant */
    /* @4013528 add */
    /* @4013532 call */
    GM_SITE(vm, 196, 4013532);
    v94 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @4013540 store */
    v95 = GM_CALL(vm, "instance_create", 3, v94, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v95);
    /* @4013548 load */
    /* @4013556 cast */
    /* @4013560 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_4013592;
    L_4013564: ;
    /* @4013564 constant */
    /* @4013568 cast */
    /* @4013572 load */
    /* @4013580 call */
    GM_SITE(vm, 196, 4013580);
    /* @4013588 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_4013592: ;
    /* @4013592 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4013564;
    /* @4013596 constant */
    /* @4013600 cast */
    /* @4013604 load */
    /* @4013612 constant */
    /* @4013616 sub */
    /* @4013620 load */
    /* @4013628 constant */
    /* @4013632 add */
    /* @4013636 call */
    GM_SITE(vm, 196, 4013636);
    v96 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @4013644 store */
    v97 = GM_CALL(vm, "instance_create", 3, v96, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v97);
    /* @4013652 load */
    /* @4013660 cast */
    /* @4013664 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_4013696;
    L_4013668: ;
    /* @4013668 constant */
    /* @4013672 cast */
    /* @4013676 load */
    /* @4013684 call */
    GM_SITE(vm, 196, 4013684);
    /* @4013692 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_4013696: ;
    /* @4013696 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4013668;
    /* @4013700 constant */
    /* @4013704 cast */
    /* @4013708 load */
    /* @4013716 constant */
    /* @4013720 sub */
    /* @4013724 load */
    /* @4013732 constant */
    /* @4013736 sub */
    /* @4013740 call */
    GM_SITE(vm, 196, 4013740);
    /* @4013748 store */
    v98 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v98);
    /* @4013756 load */
    /* @4013764 cast */
    /* @4013768 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_4013800;
    L_4013772: ;
    /* @4013772 constant */
    /* @4013776 cast */
    /* @4013780 load */
    /* @4013788 call */
    GM_SITE(vm, 196, 4013788);
    /* @4013796 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_4013800: ;
    /* @4013800 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4013772;
    /* @4013804 constant */
    /* @4013808 cast */
    /* @4013812 load */
    /* @4013820 constant */
    /* @4013824 sub */
    /* @4013828 load */
    /* @4013836 constant */
    /* @4013840 add */
    /* @4013844 call */
    GM_SITE(vm, 196, 4013844);
    v99 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @4013852 store */
    v100 = GM_CALL(vm, "instance_create", 3, v99, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v100);
    /* @4013860 load */
    /* @4013868 cast */
    /* @4013872 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_4013904;
    L_4013876: ;
    /* @4013876 constant */
    /* @4013880 cast */
    /* @4013884 load */
    /* @4013892 call */
    GM_SITE(vm, 196, 4013892);
    /* @4013900 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_4013904: ;
    /* @4013904 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4013876;
    /* @4013908 constant */
    /* @4013912 cast */
    /* @4013916 load */
    /* @4013924 constant */
    /* @4013928 sub */
    /* @4013932 load */
    /* @4013940 constant */
    /* @4013944 sub */
    /* @4013948 call */
    GM_SITE(vm, 196, 4013948);
    /* @4013956 store */
    v101 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v101);
    /* @4013964 load */
    /* @4013972 cast */
    /* @4013976 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_4014008;
    L_4013980: ;
    /* @4013980 constant */
    /* @4013984 cast */
    /* @4013988 load */
    /* @4013996 call */
    GM_SITE(vm, 196, 4013996);
    /* @4014004 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_4014008: ;
    /* @4014008 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4013980;
    /* @4014012 constant */
    /* @4014016 cast */
    /* @4014020 load */
    /* @4014028 constant */
    /* @4014032 sub */
    /* @4014036 load */
    /* @4014044 constant */
    /* @4014048 sub */
    /* @4014052 call */
    GM_SITE(vm, 196, 4014052);
    /* @4014060 store */
    v102 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v102);
    /* @4014068 load */
    /* @4014076 cast */
    /* @4014080 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_4014112;
    L_4014084: ;
    /* @4014084 constant */
    /* @4014088 cast */
    /* @4014092 load */
    /* @4014100 call */
    GM_SITE(vm, 196, 4014100);
    /* @4014108 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_4014112: ;
    /* @4014112 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4014084;
    /* @4014116 constant */
    /* @4014120 cast */
    /* @4014124 load */
    /* @4014132 constant */
    /* @4014136 sub */
    /* @4014140 load */
    /* @4014148 constant */
    /* @4014152 add */
    /* @4014156 call */
    GM_SITE(vm, 196, 4014156);
    v103 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @4014164 store */
    v104 = GM_CALL(vm, "instance_create", 3, v103, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID12", v104);
    /* @4014172 load */
    /* @4014180 cast */
    /* @4014184 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID12")))) goto L_4014216;
    L_4014188: ;
    /* @4014188 constant */
    /* @4014192 cast */
    /* @4014196 load */
    /* @4014204 call */
    GM_SITE(vm, 196, 4014204);
    /* @4014212 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread12"), VAL(5)));
    L_4014216: ;
    /* @4014216 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4014188;
    /* @4014220 constant */
    /* @4014224 cast */
    /* @4014228 load */
    /* @4014236 constant */
    /* @4014240 sub */
    /* @4014244 load */
    /* @4014252 constant */
    /* @4014256 sub */
    /* @4014260 call */
    GM_SITE(vm, 196, 4014260);
    /* @4014268 store */
    v105 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID13", v105);
    /* @4014276 load */
    /* @4014284 cast */
    /* @4014288 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID13")))) goto L_4014320;
    L_4014292: ;
    /* @4014292 constant */
    /* @4014296 cast */
    /* @4014300 load */
    /* @4014308 call */
    GM_SITE(vm, 196, 4014308);
    /* @4014316 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread13"), VAL(5)));
    L_4014320: ;
    /* @4014320 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4014292;
    /* @4014324 constant */
    /* @4014328 cast */
    /* @4014332 load */
    /* @4014340 constant */
    /* @4014344 sub */
    /* @4014348 load */
    /* @4014356 constant */
    /* @4014360 add */
    /* @4014364 call */
    GM_SITE(vm, 196, 4014364);
    v106 = GM_ADD(GM_READ(vm, -1, "x"), VAL(12));
    /* @4014372 store */
    v107 = GM_CALL(vm, "instance_create", 3, v106, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID14", v107);
    /* @4014380 load */
    /* @4014388 cast */
    /* @4014392 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID14")))) goto L_4014424;
    L_4014396: ;
    /* @4014396 constant */
    /* @4014400 cast */
    /* @4014404 load */
    /* @4014412 call */
    GM_SITE(vm, 196, 4014412);
    /* @4014420 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread14"), VAL(5)));
    L_4014424: ;
    /* @4014424 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4014396;
    /* @4014428 constant */
    /* @4014432 cast */
    /* @4014436 load */
    /* @4014444 constant */
    /* @4014448 sub */
    /* @4014452 load */
    /* @4014460 constant */
    /* @4014464 sub */
    /* @4014468 call */
    GM_SITE(vm, 196, 4014468);
    /* @4014476 store */
    v108 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(12)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID15", v108);
    /* @4014484 load */
    /* @4014492 cast */
    /* @4014496 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID15")))) goto L_4014528;
    L_4014500: ;
    /* @4014500 constant */
    /* @4014504 cast */
    /* @4014508 load */
    /* @4014516 call */
    GM_SITE(vm, 196, 4014516);
    /* @4014524 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread15"), VAL(5)));
    L_4014528: ;
    /* @4014528 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4014500;
    /* @4014532 constant */
    /* @4014536 cast */
    /* @4014540 load */
    /* @4014548 constant */
    /* @4014552 sub */
    /* @4014556 load */
    /* @4014564 constant */
    /* @4014568 add */
    /* @4014572 call */
    GM_SITE(vm, 196, 4014572);
    v109 = GM_ADD(GM_READ(vm, -1, "x"), VAL(15));
    /* @4014580 store */
    v110 = GM_CALL(vm, "instance_create", 3, v109, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID16", v110);
    /* @4014588 load */
    /* @4014596 cast */
    /* @4014600 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID16")))) goto L_4014632;
    L_4014604: ;
    /* @4014604 constant */
    /* @4014608 cast */
    /* @4014612 load */
    /* @4014620 call */
    GM_SITE(vm, 196, 4014620);
    /* @4014628 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread16"), VAL(5)));
    L_4014632: ;
    /* @4014632 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4014604;
    /* @4014636 constant */
    /* @4014640 cast */
    /* @4014644 load */
    /* @4014652 constant */
    /* @4014656 sub */
    /* @4014660 load */
    /* @4014668 constant */
    /* @4014672 add */
    /* @4014676 call */
    GM_SITE(vm, 196, 4014676);
    v111 = GM_ADD(GM_READ(vm, -1, "x"), VAL(14));
    /* @4014684 store */
    v112 = GM_CALL(vm, "instance_create", 3, v111, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID17", v112);
    /* @4014692 load */
    /* @4014700 cast */
    /* @4014704 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID17")))) goto L_4014736;
    L_4014708: ;
    /* @4014708 constant */
    /* @4014712 cast */
    /* @4014716 load */
    /* @4014724 call */
    GM_SITE(vm, 196, 4014724);
    /* @4014732 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread17"), VAL(5)));
    L_4014736: ;
    /* @4014736 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4014708;
    /* @4014740 constant */
    /* @4014744 cast */
    /* @4014748 load */
    /* @4014756 constant */
    /* @4014760 sub */
    /* @4014764 load */
    /* @4014772 constant */
    /* @4014776 sub */
    /* @4014780 call */
    GM_SITE(vm, 196, 4014780);
    /* @4014788 store */
    v113 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(14)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID18", v113);
    /* @4014796 load */
    /* @4014804 cast */
    /* @4014808 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID18")))) goto L_4014840;
    L_4014812: ;
    /* @4014812 constant */
    /* @4014816 cast */
    /* @4014820 load */
    /* @4014828 call */
    GM_SITE(vm, 196, 4014828);
    /* @4014836 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread18"), VAL(5)));
    L_4014840: ;
    /* @4014840 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4014812;
    /* @4014844 constant */
    /* @4014848 cast */
    /* @4014852 load */
    /* @4014860 constant */
    /* @4014864 sub */
    /* @4014868 load */
    /* @4014876 constant */
    /* @4014880 add */
    /* @4014884 call */
    GM_SITE(vm, 196, 4014884);
    v114 = GM_ADD(GM_READ(vm, -1, "x"), VAL(16));
    /* @4014892 store */
    v115 = GM_CALL(vm, "instance_create", 3, v114, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID19", v115);
    /* @4014900 load */
    /* @4014908 cast */
    /* @4014912 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID19")))) goto L_4014944;
    L_4014916: ;
    /* @4014916 constant */
    /* @4014920 cast */
    /* @4014924 load */
    /* @4014932 call */
    GM_SITE(vm, 196, 4014932);
    /* @4014940 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread19"), VAL(5)));
    L_4014944: ;
    /* @4014944 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4014916;
    /* @4014948 constant */
    /* @4014952 cast */
    /* @4014956 load */
    /* @4014964 constant */
    /* @4014968 sub */
    /* @4014972 load */
    /* @4014980 constant */
    /* @4014984 sub */
    /* @4014988 call */
    GM_SITE(vm, 196, 4014988);
    /* @4014996 store */
    v116 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(16)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID20", v116);
    /* @4015004 load */
    /* @4015012 cast */
    /* @4015016 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID20")))) goto L_4015048;
    L_4015020: ;
    /* @4015020 constant */
    /* @4015024 cast */
    /* @4015028 load */
    /* @4015036 call */
    GM_SITE(vm, 196, 4015036);
    /* @4015044 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread20"), VAL(5)));
    L_4015048: ;
    /* @4015048 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4015020;
    /* @4015052 constant */
    /* @4015056 cast */
    /* @4015060 load */
    /* @4015068 constant */
    /* @4015072 sub */
    /* @4015076 load */
    /* @4015084 constant */
    /* @4015088 sub */
    /* @4015092 call */
    GM_SITE(vm, 196, 4015092);
    /* @4015100 store */
    v117 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(15)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID21", v117);
    /* @4015108 load */
    /* @4015116 cast */
    /* @4015120 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID21")))) goto L_4015152;
    L_4015124: ;
    /* @4015124 constant */
    /* @4015128 cast */
    /* @4015132 load */
    /* @4015140 call */
    GM_SITE(vm, 196, 4015140);
    /* @4015148 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread21"), VAL(5)));
    L_4015152: ;
    /* @4015152 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4015124;
    /* @4015156 constant */
    /* @4015160 cast */
    /* @4015164 load */
    /* @4015172 constant */
    /* @4015176 sub */
    /* @4015180 load */
    /* @4015188 constant */
    /* @4015192 add */
    /* @4015196 call */
    GM_SITE(vm, 196, 4015196);
    v118 = GM_ADD(GM_READ(vm, -1, "x"), VAL(18));
    /* @4015204 store */
    v119 = GM_CALL(vm, "instance_create", 3, v118, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID22", v119);
    /* @4015212 load */
    /* @4015220 cast */
    /* @4015224 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID22")))) goto L_4015256;
    L_4015228: ;
    /* @4015228 constant */
    /* @4015232 cast */
    /* @4015236 load */
    /* @4015244 call */
    GM_SITE(vm, 196, 4015244);
    /* @4015252 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread22"), VAL(5)));
    L_4015256: ;
    /* @4015256 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4015228;
    /* @4015260 constant */
    /* @4015264 cast */
    /* @4015268 load */
    /* @4015276 constant */
    /* @4015280 sub */
    /* @4015284 load */
    /* @4015292 constant */
    /* @4015296 sub */
    /* @4015300 call */
    GM_SITE(vm, 196, 4015300);
    /* @4015308 store */
    v120 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(18)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID23", v120);
    /* @4015316 load */
    /* @4015324 cast */
    /* @4015328 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID23")))) goto L_4015360;
    L_4015332: ;
    /* @4015332 constant */
    /* @4015336 cast */
    /* @4015340 load */
    /* @4015348 call */
    GM_SITE(vm, 196, 4015348);
    /* @4015356 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread23"), VAL(5)));
    L_4015360: ;
    /* @4015360 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4015332;
    /* @4015364 constant */
    /* @4015368 cast */
    /* @4015372 load */
    /* @4015380 constant */
    /* @4015384 sub */
    /* @4015388 load */
    /* @4015396 constant */
    /* @4015400 add */
    /* @4015404 call */
    GM_SITE(vm, 196, 4015404);
    v121 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @4015412 store */
    v122 = GM_CALL(vm, "instance_create", 3, v121, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID24", v122);
    /* @4015420 load */
    /* @4015428 cast */
    /* @4015432 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID24")))) goto L_4015464;
    L_4015436: ;
    /* @4015436 constant */
    /* @4015440 cast */
    /* @4015444 load */
    /* @4015452 call */
    GM_SITE(vm, 196, 4015452);
    /* @4015460 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread24"), VAL(5)));
    L_4015464: ;
    /* @4015464 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4015436;
    /* @4015468 constant */
    /* @4015472 cast */
    /* @4015476 load */
    /* @4015484 constant */
    /* @4015488 sub */
    /* @4015492 load */
    /* @4015500 constant */
    /* @4015504 sub */
    /* @4015508 call */
    GM_SITE(vm, 196, 4015508);
    /* @4015516 store */
    v123 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(20)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID25", v123);
    /* @4015524 load */
    /* @4015532 cast */
    /* @4015536 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID25")))) goto L_4015568;
    L_4015540: ;
    /* @4015540 constant */
    /* @4015544 cast */
    /* @4015548 load */
    /* @4015556 call */
    GM_SITE(vm, 196, 4015556);
    /* @4015564 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread25"), VAL(5)));
    L_4015568: ;
    /* @4015568 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4015540;
    L_4015572: ;
    /* @4015572 call */
    GM_SITE(vm, 196, 4015572);
    /* @4015580 popz */
    (void)(GM_CALL(vm, "action_kill_object", 0));
    L_4015584: ;
    return;
}
