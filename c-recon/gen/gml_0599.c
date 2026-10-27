/* generated from CODE 599 (gml_Object_obj_lloydtutorial6_Draw_0), source start 4900384, end 4911084. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0599(GmVM* vm) {
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
    Val v124;
    Val v125;
    Val v126;
    Val v127;
    Val v128;
    Val v129;
    Val v130;
    Val v131;
    Val v132;
    Val v133;
    Val v134;
    Val v135;
    Val v136;
    Val v137;
    Val v138;
    Val v139;
    Val v140;
    Val v141;
    Val v142;
    Val v143;
    Val v144;
    Val v145;
    Val v146;
    Val v147;
    Val v148;
    Val v149;
    Val v150;
    Val v151;
    Val v152;
    Val v153;
    Val v154;
    Val v155;
    Val v156;
    Val p4911068_0;
    Val v157;
    /* @4900384 constant */
    /* @4900388 load */
    /* @4900396 cast */
    /* @4900400 load */
    /* @4900408 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4900416 constant */
    /* @4900420 load */
    /* @4900428 cast */
    /* @4900432 load */
    /* @4900440 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4900448 load */
    /* @4900456 constant */
    /* @4900460 cmp */
    /* @4900464 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4900992;
    /* @4900468 constant */
    /* @4900472 cast */
    /* @4900476 constant */
    /* @4900480 cast */
    /* @4900484 constant */
    /* @4900488 cast */
    /* @4900492 constant */
    /* @4900504 cast */
    /* @4900508 constant */
    /* @4900520 cast */
    /* @4900524 constant */
    /* @4900528 constant */
    /* @4900532 load */
    /* @4900540 constant */
    /* @4900544 constant */
    /* @4900548 load */
    /* @4900556 constant */
    /* @4900560 sub */
    /* @4900564 constant */
    /* @4900568 cast */
    /* @4900572 constant */
    /* @4900576 cast */
    /* @4900580 call */
    GM_SITE(vm, 599, 4900580);
    /* @4900588 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(0.96), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4900592 constant */
    /* @4900596 cast */
    /* @4900600 constant */
    /* @4900604 cast */
    /* @4900608 constant */
    /* @4900612 cast */
    /* @4900616 constant */
    /* @4900620 cast */
    /* @4900624 constant */
    /* @4900628 cast */
    /* @4900632 constant */
    /* @4900636 load */
    /* @4900644 cast */
    /* @4900648 load */
    /* @4900656 constant */
    /* @4900660 add */
    /* @4900664 constant */
    /* @4900668 load */
    /* @4900676 cast */
    /* @4900680 load */
    /* @4900688 constant */
    /* @4900692 add */
    /* @4900696 constant */
    /* @4900700 cast */
    /* @4900704 constant */
    /* @4900708 cast */
    /* @4900712 call */
    GM_SITE(vm, 599, 4900712);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4900720 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v1, v2, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4900724 constant */
    /* @4900728 cast */
    /* @4900732 constant */
    /* @4900736 cast */
    /* @4900740 constant */
    /* @4900744 cast */
    /* @4900748 constant */
    /* @4900752 cast */
    /* @4900756 constant */
    /* @4900760 cast */
    /* @4900764 constant */
    /* @4900768 load */
    /* @4900776 cast */
    /* @4900780 load */
    /* @4900788 constant */
    /* @4900792 add */
    /* @4900796 constant */
    /* @4900800 load */
    /* @4900808 cast */
    /* @4900812 load */
    /* @4900820 constant */
    /* @4900824 add */
    /* @4900828 constant */
    /* @4900832 cast */
    /* @4900836 constant */
    /* @4900840 cast */
    /* @4900844 call */
    GM_SITE(vm, 599, 4900844);
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4900852 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v3, v4, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4900856 load */
    /* @4900864 constant */
    /* @4900868 cmp */
    /* @4900872 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4900992;
    /* @4900876 constant */
    /* @4900880 cast */
    /* @4900884 call */
    GM_SITE(vm, 599, 4900884);
    /* @4900892 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4900896 constant */
    /* @4900904 cast */
    /* @4900908 call */
    GM_SITE(vm, 599, 4900908);
    /* @4900916 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4900920 string */
    /* @4900928 cast */
    /* @4900932 constant */
    /* @4900936 constant */
    /* @4900940 load */
    /* @4900948 constant */
    /* @4900952 add */
    /* @4900956 constant */
    /* @4900960 constant */
    /* @4900964 load */
    /* @4900972 constant */
    /* @4900976 add */
    /* @4900980 call */
    GM_SITE(vm, 599, 4900980);
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(150));
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(200));
    /* @4900988 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v5, v6, STR_REF(743)));
    L_4900992: ;
    /* @4900992 load */
    /* @4901000 constant */
    /* @4901004 cmp */
    /* @4901008 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4901536;
    /* @4901012 constant */
    /* @4901016 cast */
    /* @4901020 constant */
    /* @4901024 cast */
    /* @4901028 constant */
    /* @4901032 cast */
    /* @4901036 constant */
    /* @4901048 cast */
    /* @4901052 constant */
    /* @4901064 cast */
    /* @4901068 constant */
    /* @4901072 constant */
    /* @4901076 load */
    /* @4901084 constant */
    /* @4901088 constant */
    /* @4901092 load */
    /* @4901100 constant */
    /* @4901104 sub */
    /* @4901108 constant */
    /* @4901112 cast */
    /* @4901116 constant */
    /* @4901120 cast */
    /* @4901124 call */
    GM_SITE(vm, 599, 4901124);
    /* @4901132 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(0.82), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4901136 constant */
    /* @4901140 cast */
    /* @4901144 constant */
    /* @4901148 cast */
    /* @4901152 constant */
    /* @4901156 cast */
    /* @4901160 constant */
    /* @4901164 cast */
    /* @4901168 constant */
    /* @4901172 cast */
    /* @4901176 constant */
    /* @4901180 load */
    /* @4901188 cast */
    /* @4901192 load */
    /* @4901200 constant */
    /* @4901204 add */
    /* @4901208 constant */
    /* @4901212 load */
    /* @4901220 cast */
    /* @4901224 load */
    /* @4901232 constant */
    /* @4901236 add */
    /* @4901240 constant */
    /* @4901244 cast */
    /* @4901248 constant */
    /* @4901252 cast */
    /* @4901256 call */
    GM_SITE(vm, 599, 4901256);
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4901264 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v7, v8, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4901268 constant */
    /* @4901272 cast */
    /* @4901276 constant */
    /* @4901280 cast */
    /* @4901284 constant */
    /* @4901288 cast */
    /* @4901292 constant */
    /* @4901296 cast */
    /* @4901300 constant */
    /* @4901304 cast */
    /* @4901308 constant */
    /* @4901312 load */
    /* @4901320 cast */
    /* @4901324 load */
    /* @4901332 constant */
    /* @4901336 add */
    /* @4901340 constant */
    /* @4901344 load */
    /* @4901352 cast */
    /* @4901356 load */
    /* @4901364 constant */
    /* @4901368 add */
    /* @4901372 constant */
    /* @4901376 cast */
    /* @4901380 constant */
    /* @4901384 cast */
    /* @4901388 call */
    GM_SITE(vm, 599, 4901388);
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(320));
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4901396 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v9, v10, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4901400 load */
    /* @4901408 constant */
    /* @4901412 cmp */
    /* @4901416 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4901536;
    /* @4901420 constant */
    /* @4901424 cast */
    /* @4901428 call */
    GM_SITE(vm, 599, 4901428);
    /* @4901436 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4901440 constant */
    /* @4901448 cast */
    /* @4901452 call */
    GM_SITE(vm, 599, 4901452);
    /* @4901460 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4901464 string */
    /* @4901472 cast */
    /* @4901476 constant */
    /* @4901480 constant */
    /* @4901484 load */
    /* @4901492 constant */
    /* @4901496 add */
    /* @4901500 constant */
    /* @4901504 constant */
    /* @4901508 load */
    /* @4901516 constant */
    /* @4901520 add */
    /* @4901524 call */
    GM_SITE(vm, 599, 4901524);
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(110));
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4901532 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v11, v12, STR_REF(743)));
    L_4901536: ;
    /* @4901536 load */
    /* @4901544 constant */
    /* @4901548 cmp */
    /* @4901552 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4902080;
    /* @4901556 constant */
    /* @4901560 cast */
    /* @4901564 constant */
    /* @4901568 cast */
    /* @4901572 constant */
    /* @4901576 cast */
    /* @4901580 constant */
    /* @4901592 cast */
    /* @4901596 constant */
    /* @4901608 cast */
    /* @4901612 constant */
    /* @4901616 constant */
    /* @4901620 load */
    /* @4901628 constant */
    /* @4901632 constant */
    /* @4901636 load */
    /* @4901644 constant */
    /* @4901648 sub */
    /* @4901652 constant */
    /* @4901656 cast */
    /* @4901660 constant */
    /* @4901664 cast */
    /* @4901668 call */
    GM_SITE(vm, 599, 4901668);
    /* @4901676 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4901680 constant */
    /* @4901684 cast */
    /* @4901688 constant */
    /* @4901692 cast */
    /* @4901696 constant */
    /* @4901700 cast */
    /* @4901704 constant */
    /* @4901708 cast */
    /* @4901712 constant */
    /* @4901716 cast */
    /* @4901720 constant */
    /* @4901724 load */
    /* @4901732 cast */
    /* @4901736 load */
    /* @4901744 constant */
    /* @4901748 add */
    /* @4901752 constant */
    /* @4901756 load */
    /* @4901764 cast */
    /* @4901768 load */
    /* @4901776 constant */
    /* @4901780 add */
    /* @4901784 constant */
    /* @4901788 cast */
    /* @4901792 constant */
    /* @4901796 cast */
    /* @4901800 call */
    GM_SITE(vm, 599, 4901800);
    v13 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4901808 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v13, v14, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4901812 constant */
    /* @4901816 cast */
    /* @4901820 constant */
    /* @4901824 cast */
    /* @4901828 constant */
    /* @4901832 cast */
    /* @4901836 constant */
    /* @4901840 cast */
    /* @4901844 constant */
    /* @4901848 cast */
    /* @4901852 constant */
    /* @4901856 load */
    /* @4901864 cast */
    /* @4901868 load */
    /* @4901876 constant */
    /* @4901880 add */
    /* @4901884 constant */
    /* @4901888 load */
    /* @4901896 cast */
    /* @4901900 load */
    /* @4901908 constant */
    /* @4901912 add */
    /* @4901916 constant */
    /* @4901920 cast */
    /* @4901924 constant */
    /* @4901928 cast */
    /* @4901932 call */
    GM_SITE(vm, 599, 4901932);
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4901940 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v15, v16, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4901944 load */
    /* @4901952 constant */
    /* @4901956 cmp */
    /* @4901960 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4902080;
    /* @4901964 constant */
    /* @4901968 cast */
    /* @4901972 call */
    GM_SITE(vm, 599, 4901972);
    /* @4901980 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4901984 constant */
    /* @4901992 cast */
    /* @4901996 call */
    GM_SITE(vm, 599, 4901996);
    /* @4902004 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4902008 string */
    /* @4902016 cast */
    /* @4902020 constant */
    /* @4902024 constant */
    /* @4902028 load */
    /* @4902036 constant */
    /* @4902040 add */
    /* @4902044 constant */
    /* @4902048 constant */
    /* @4902052 load */
    /* @4902060 constant */
    /* @4902064 add */
    /* @4902068 call */
    GM_SITE(vm, 599, 4902068);
    v17 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(180));
    v18 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(300));
    /* @4902076 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v17, v18, STR_REF(743)));
    L_4902080: ;
    /* @4902080 load */
    /* @4902088 constant */
    /* @4902092 cmp */
    /* @4902096 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4902624;
    /* @4902100 constant */
    /* @4902104 cast */
    /* @4902108 constant */
    /* @4902112 cast */
    /* @4902116 constant */
    /* @4902120 cast */
    /* @4902124 constant */
    /* @4902136 cast */
    /* @4902140 constant */
    /* @4902152 cast */
    /* @4902156 constant */
    /* @4902160 constant */
    /* @4902164 load */
    /* @4902172 constant */
    /* @4902176 constant */
    /* @4902180 load */
    /* @4902188 constant */
    /* @4902192 sub */
    /* @4902196 constant */
    /* @4902200 cast */
    /* @4902204 constant */
    /* @4902208 cast */
    /* @4902212 call */
    GM_SITE(vm, 599, 4902212);
    /* @4902220 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4902224 constant */
    /* @4902228 cast */
    /* @4902232 constant */
    /* @4902236 cast */
    /* @4902240 constant */
    /* @4902244 cast */
    /* @4902248 constant */
    /* @4902252 cast */
    /* @4902256 constant */
    /* @4902260 cast */
    /* @4902264 constant */
    /* @4902268 load */
    /* @4902276 cast */
    /* @4902280 load */
    /* @4902288 constant */
    /* @4902292 add */
    /* @4902296 constant */
    /* @4902300 load */
    /* @4902308 cast */
    /* @4902312 load */
    /* @4902320 constant */
    /* @4902324 add */
    /* @4902328 constant */
    /* @4902332 cast */
    /* @4902336 constant */
    /* @4902340 cast */
    /* @4902344 call */
    GM_SITE(vm, 599, 4902344);
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4902352 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v19, v20, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4902356 constant */
    /* @4902360 cast */
    /* @4902364 constant */
    /* @4902368 cast */
    /* @4902372 constant */
    /* @4902376 cast */
    /* @4902380 constant */
    /* @4902384 cast */
    /* @4902388 constant */
    /* @4902392 cast */
    /* @4902396 constant */
    /* @4902400 load */
    /* @4902408 cast */
    /* @4902412 load */
    /* @4902420 constant */
    /* @4902424 add */
    /* @4902428 constant */
    /* @4902432 load */
    /* @4902440 cast */
    /* @4902444 load */
    /* @4902452 constant */
    /* @4902456 add */
    /* @4902460 constant */
    /* @4902464 cast */
    /* @4902468 constant */
    /* @4902472 cast */
    /* @4902476 call */
    GM_SITE(vm, 599, 4902476);
    v21 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4902484 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v21, v22, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4902488 load */
    /* @4902496 constant */
    /* @4902500 cmp */
    /* @4902504 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4902624;
    /* @4902508 constant */
    /* @4902512 cast */
    /* @4902516 call */
    GM_SITE(vm, 599, 4902516);
    /* @4902524 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4902528 constant */
    /* @4902536 cast */
    /* @4902540 call */
    GM_SITE(vm, 599, 4902540);
    /* @4902548 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4902552 string */
    /* @4902560 cast */
    /* @4902564 constant */
    /* @4902568 constant */
    /* @4902572 load */
    /* @4902580 constant */
    /* @4902584 add */
    /* @4902588 constant */
    /* @4902592 constant */
    /* @4902596 load */
    /* @4902604 constant */
    /* @4902608 add */
    /* @4902612 call */
    GM_SITE(vm, 599, 4902612);
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(180));
    v24 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(300));
    /* @4902620 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v23, v24, STR_REF(743)));
    L_4902624: ;
    /* @4902624 load */
    /* @4902632 constant */
    /* @4902636 cmp */
    /* @4902640 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4903168;
    /* @4902644 constant */
    /* @4902648 cast */
    /* @4902652 constant */
    /* @4902656 cast */
    /* @4902660 constant */
    /* @4902664 cast */
    /* @4902668 constant */
    /* @4902680 cast */
    /* @4902684 constant */
    /* @4902696 cast */
    /* @4902700 constant */
    /* @4902704 constant */
    /* @4902708 load */
    /* @4902716 constant */
    /* @4902720 constant */
    /* @4902724 load */
    /* @4902732 constant */
    /* @4902736 sub */
    /* @4902740 constant */
    /* @4902744 cast */
    /* @4902748 constant */
    /* @4902752 cast */
    /* @4902756 call */
    GM_SITE(vm, 599, 4902756);
    /* @4902764 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(0.97), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4902768 constant */
    /* @4902772 cast */
    /* @4902776 constant */
    /* @4902780 cast */
    /* @4902784 constant */
    /* @4902788 cast */
    /* @4902792 constant */
    /* @4902796 cast */
    /* @4902800 constant */
    /* @4902804 cast */
    /* @4902808 constant */
    /* @4902812 load */
    /* @4902820 cast */
    /* @4902824 load */
    /* @4902832 constant */
    /* @4902836 add */
    /* @4902840 constant */
    /* @4902844 load */
    /* @4902852 cast */
    /* @4902856 load */
    /* @4902864 constant */
    /* @4902868 add */
    /* @4902872 constant */
    /* @4902876 cast */
    /* @4902880 constant */
    /* @4902884 cast */
    /* @4902888 call */
    GM_SITE(vm, 599, 4902888);
    v25 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v26 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4902896 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v25, v26, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4902900 constant */
    /* @4902904 cast */
    /* @4902908 constant */
    /* @4902912 cast */
    /* @4902916 constant */
    /* @4902920 cast */
    /* @4902924 constant */
    /* @4902928 cast */
    /* @4902932 constant */
    /* @4902936 cast */
    /* @4902940 constant */
    /* @4902944 load */
    /* @4902952 cast */
    /* @4902956 load */
    /* @4902964 constant */
    /* @4902968 add */
    /* @4902972 constant */
    /* @4902976 load */
    /* @4902984 cast */
    /* @4902988 load */
    /* @4902996 constant */
    /* @4903000 add */
    /* @4903004 constant */
    /* @4903008 cast */
    /* @4903012 constant */
    /* @4903016 cast */
    /* @4903020 call */
    GM_SITE(vm, 599, 4903020);
    v27 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v28 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4903028 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v27, v28, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4903032 load */
    /* @4903040 constant */
    /* @4903044 cmp */
    /* @4903048 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4903168;
    /* @4903052 constant */
    /* @4903056 cast */
    /* @4903060 call */
    GM_SITE(vm, 599, 4903060);
    /* @4903068 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4903072 constant */
    /* @4903080 cast */
    /* @4903084 call */
    GM_SITE(vm, 599, 4903084);
    /* @4903092 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4903096 string */
    /* @4903104 cast */
    /* @4903108 constant */
    /* @4903112 constant */
    /* @4903116 load */
    /* @4903124 constant */
    /* @4903128 add */
    /* @4903132 constant */
    /* @4903136 constant */
    /* @4903140 load */
    /* @4903148 constant */
    /* @4903152 add */
    /* @4903156 call */
    GM_SITE(vm, 599, 4903156);
    v29 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(150));
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(200));
    /* @4903164 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v29, v30, STR_REF(743)));
    L_4903168: ;
    /* @4903168 load */
    /* @4903176 constant */
    /* @4903180 cmp */
    /* @4903184 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4903712;
    /* @4903188 constant */
    /* @4903192 cast */
    /* @4903196 constant */
    /* @4903200 cast */
    /* @4903204 constant */
    /* @4903208 cast */
    /* @4903212 constant */
    /* @4903224 cast */
    /* @4903228 constant */
    /* @4903240 cast */
    /* @4903244 constant */
    /* @4903248 constant */
    /* @4903252 load */
    /* @4903260 constant */
    /* @4903264 constant */
    /* @4903268 load */
    /* @4903276 constant */
    /* @4903280 sub */
    /* @4903284 constant */
    /* @4903288 cast */
    /* @4903292 constant */
    /* @4903296 cast */
    /* @4903300 call */
    GM_SITE(vm, 599, 4903300);
    /* @4903308 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(1.06), VAL(0.86), VAL(0), VAL(-1), VAL(1)));
    /* @4903312 constant */
    /* @4903316 cast */
    /* @4903320 constant */
    /* @4903324 cast */
    /* @4903328 constant */
    /* @4903332 cast */
    /* @4903336 constant */
    /* @4903340 cast */
    /* @4903344 constant */
    /* @4903348 cast */
    /* @4903352 constant */
    /* @4903356 load */
    /* @4903364 cast */
    /* @4903368 load */
    /* @4903376 constant */
    /* @4903380 add */
    /* @4903384 constant */
    /* @4903388 load */
    /* @4903396 cast */
    /* @4903400 load */
    /* @4903408 constant */
    /* @4903412 add */
    /* @4903416 constant */
    /* @4903420 cast */
    /* @4903424 constant */
    /* @4903428 cast */
    /* @4903432 call */
    GM_SITE(vm, 599, 4903432);
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v32 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4903440 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v31, v32, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4903444 constant */
    /* @4903448 cast */
    /* @4903452 constant */
    /* @4903456 cast */
    /* @4903460 constant */
    /* @4903464 cast */
    /* @4903468 constant */
    /* @4903472 cast */
    /* @4903476 constant */
    /* @4903480 cast */
    /* @4903484 constant */
    /* @4903488 load */
    /* @4903496 cast */
    /* @4903500 load */
    /* @4903508 constant */
    /* @4903512 add */
    /* @4903516 constant */
    /* @4903520 load */
    /* @4903528 cast */
    /* @4903532 load */
    /* @4903540 constant */
    /* @4903544 add */
    /* @4903548 constant */
    /* @4903552 cast */
    /* @4903556 constant */
    /* @4903560 cast */
    /* @4903564 call */
    GM_SITE(vm, 599, 4903564);
    v33 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(390));
    v34 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4903572 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v33, v34, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4903576 load */
    /* @4903584 constant */
    /* @4903588 cmp */
    /* @4903592 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4903712;
    /* @4903596 constant */
    /* @4903600 cast */
    /* @4903604 call */
    GM_SITE(vm, 599, 4903604);
    /* @4903612 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4903616 constant */
    /* @4903624 cast */
    /* @4903628 call */
    GM_SITE(vm, 599, 4903628);
    /* @4903636 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4903640 string */
    /* @4903648 cast */
    /* @4903652 constant */
    /* @4903656 constant */
    /* @4903660 load */
    /* @4903668 constant */
    /* @4903672 add */
    /* @4903676 constant */
    /* @4903680 constant */
    /* @4903684 load */
    /* @4903692 constant */
    /* @4903696 add */
    /* @4903700 call */
    GM_SITE(vm, 599, 4903700);
    v35 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(160));
    v36 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(200));
    /* @4903708 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v35, v36, STR_REF(743)));
    L_4903712: ;
    /* @4903712 load */
    /* @4903720 constant */
    /* @4903724 cmp */
    /* @4903728 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel1") == VAL(1)))) goto L_4905172;
    /* @4903732 load */
    /* @4903740 constant */
    /* @4903744 cmp */
    /* @4903748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4903972;
    /* @4903752 constant */
    /* @4903756 cast */
    /* @4903760 call */
    GM_SITE(vm, 599, 4903760);
    /* @4903768 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4903772 constant */
    /* @4903780 cast */
    /* @4903784 call */
    GM_SITE(vm, 599, 4903784);
    /* @4903792 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4903796 string */
    /* @4903804 cast */
    /* @4903808 constant */
    /* @4903812 load */
    /* @4903820 cast */
    /* @4903824 load */
    /* @4903832 constant */
    /* @4903836 add */
    /* @4903840 constant */
    /* @4903844 load */
    /* @4903852 cast */
    /* @4903856 load */
    /* @4903864 constant */
    /* @4903868 add */
    /* @4903872 call */
    GM_SITE(vm, 599, 4903872);
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4903880 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v37, v38, STR_REF(1075)));
    /* @4903884 string */
    /* @4903892 cast */
    /* @4903896 constant */
    /* @4903900 load */
    /* @4903908 cast */
    /* @4903912 load */
    /* @4903920 constant */
    /* @4903924 add */
    /* @4903928 constant */
    /* @4903932 load */
    /* @4903940 cast */
    /* @4903944 load */
    /* @4903952 constant */
    /* @4903956 add */
    /* @4903960 call */
    GM_SITE(vm, 599, 4903960);
    v39 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v40 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4903968 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, v40, STR_REF(1076)));
    L_4903972: ;
    /* @4903972 load */
    /* @4903980 constant */
    /* @4903984 cmp */
    /* @4903988 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4904212;
    /* @4903992 constant */
    /* @4903996 cast */
    /* @4904000 call */
    GM_SITE(vm, 599, 4904000);
    /* @4904008 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4904012 constant */
    /* @4904020 cast */
    /* @4904024 call */
    GM_SITE(vm, 599, 4904024);
    /* @4904032 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4904036 string */
    /* @4904044 cast */
    /* @4904048 constant */
    /* @4904052 load */
    /* @4904060 cast */
    /* @4904064 load */
    /* @4904072 constant */
    /* @4904076 add */
    /* @4904080 constant */
    /* @4904084 load */
    /* @4904092 cast */
    /* @4904096 load */
    /* @4904104 constant */
    /* @4904108 add */
    /* @4904112 call */
    GM_SITE(vm, 599, 4904112);
    v41 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v42 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4904120 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v41, v42, STR_REF(1077)));
    /* @4904124 string */
    /* @4904132 cast */
    /* @4904136 constant */
    /* @4904140 load */
    /* @4904148 cast */
    /* @4904152 load */
    /* @4904160 constant */
    /* @4904164 add */
    /* @4904168 constant */
    /* @4904172 load */
    /* @4904180 cast */
    /* @4904184 load */
    /* @4904192 constant */
    /* @4904196 add */
    /* @4904200 call */
    GM_SITE(vm, 599, 4904200);
    v43 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v44 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4904208 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v43, v44, STR_REF(1076)));
    L_4904212: ;
    /* @4904212 load */
    /* @4904220 constant */
    /* @4904224 cmp */
    /* @4904228 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4904452;
    /* @4904232 constant */
    /* @4904236 cast */
    /* @4904240 call */
    GM_SITE(vm, 599, 4904240);
    /* @4904248 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4904252 constant */
    /* @4904260 cast */
    /* @4904264 call */
    GM_SITE(vm, 599, 4904264);
    /* @4904272 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4904276 string */
    /* @4904284 cast */
    /* @4904288 constant */
    /* @4904292 load */
    /* @4904300 cast */
    /* @4904304 load */
    /* @4904312 constant */
    /* @4904316 add */
    /* @4904320 constant */
    /* @4904324 load */
    /* @4904332 cast */
    /* @4904336 load */
    /* @4904344 constant */
    /* @4904348 add */
    /* @4904352 call */
    GM_SITE(vm, 599, 4904352);
    v45 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v46 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4904360 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v45, v46, STR_REF(1075)));
    /* @4904364 string */
    /* @4904372 cast */
    /* @4904376 constant */
    /* @4904380 load */
    /* @4904388 cast */
    /* @4904392 load */
    /* @4904400 constant */
    /* @4904404 add */
    /* @4904408 constant */
    /* @4904412 load */
    /* @4904420 cast */
    /* @4904424 load */
    /* @4904432 constant */
    /* @4904436 add */
    /* @4904440 call */
    GM_SITE(vm, 599, 4904440);
    v47 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v48 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4904448 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v47, v48, STR_REF(1076)));
    L_4904452: ;
    /* @4904452 load */
    /* @4904460 constant */
    /* @4904464 cmp */
    /* @4904468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4904692;
    /* @4904472 constant */
    /* @4904476 cast */
    /* @4904480 call */
    GM_SITE(vm, 599, 4904480);
    /* @4904488 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4904492 constant */
    /* @4904500 cast */
    /* @4904504 call */
    GM_SITE(vm, 599, 4904504);
    /* @4904512 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4904516 string */
    /* @4904524 cast */
    /* @4904528 constant */
    /* @4904532 load */
    /* @4904540 cast */
    /* @4904544 load */
    /* @4904552 constant */
    /* @4904556 add */
    /* @4904560 constant */
    /* @4904564 load */
    /* @4904572 cast */
    /* @4904576 load */
    /* @4904584 constant */
    /* @4904588 add */
    /* @4904592 call */
    GM_SITE(vm, 599, 4904592);
    v49 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v50 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4904600 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v49, v50, STR_REF(1075)));
    /* @4904604 string */
    /* @4904612 cast */
    /* @4904616 constant */
    /* @4904620 load */
    /* @4904628 cast */
    /* @4904632 load */
    /* @4904640 constant */
    /* @4904644 add */
    /* @4904648 constant */
    /* @4904652 load */
    /* @4904660 cast */
    /* @4904664 load */
    /* @4904672 constant */
    /* @4904676 add */
    /* @4904680 call */
    GM_SITE(vm, 599, 4904680);
    v51 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v52 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4904688 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v51, v52, STR_REF(1076)));
    L_4904692: ;
    /* @4904692 load */
    /* @4904700 constant */
    /* @4904704 cmp */
    /* @4904708 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4904932;
    /* @4904712 constant */
    /* @4904716 cast */
    /* @4904720 call */
    GM_SITE(vm, 599, 4904720);
    /* @4904728 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4904732 constant */
    /* @4904740 cast */
    /* @4904744 call */
    GM_SITE(vm, 599, 4904744);
    /* @4904752 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4904756 string */
    /* @4904764 cast */
    /* @4904768 constant */
    /* @4904772 load */
    /* @4904780 cast */
    /* @4904784 load */
    /* @4904792 constant */
    /* @4904796 add */
    /* @4904800 constant */
    /* @4904804 load */
    /* @4904812 cast */
    /* @4904816 load */
    /* @4904824 constant */
    /* @4904828 add */
    /* @4904832 call */
    GM_SITE(vm, 599, 4904832);
    v53 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v54 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4904840 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v53, v54, STR_REF(1075)));
    /* @4904844 string */
    /* @4904852 cast */
    /* @4904856 constant */
    /* @4904860 load */
    /* @4904868 cast */
    /* @4904872 load */
    /* @4904880 constant */
    /* @4904884 add */
    /* @4904888 constant */
    /* @4904892 load */
    /* @4904900 cast */
    /* @4904904 load */
    /* @4904912 constant */
    /* @4904916 add */
    /* @4904920 call */
    GM_SITE(vm, 599, 4904920);
    v55 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v56 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4904928 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v55, v56, STR_REF(1076)));
    L_4904932: ;
    /* @4904932 load */
    /* @4904940 constant */
    /* @4904944 cmp */
    /* @4904948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4905172;
    /* @4904952 constant */
    /* @4904956 cast */
    /* @4904960 call */
    GM_SITE(vm, 599, 4904960);
    /* @4904968 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4904972 constant */
    /* @4904980 cast */
    /* @4904984 call */
    GM_SITE(vm, 599, 4904984);
    /* @4904992 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4904996 string */
    /* @4905004 cast */
    /* @4905008 constant */
    /* @4905012 load */
    /* @4905020 cast */
    /* @4905024 load */
    /* @4905032 constant */
    /* @4905036 add */
    /* @4905040 constant */
    /* @4905044 load */
    /* @4905052 cast */
    /* @4905056 load */
    /* @4905064 constant */
    /* @4905068 add */
    /* @4905072 call */
    GM_SITE(vm, 599, 4905072);
    v57 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v58 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4905080 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v57, v58, STR_REF(1075)));
    /* @4905084 string */
    /* @4905092 cast */
    /* @4905096 constant */
    /* @4905100 load */
    /* @4905108 cast */
    /* @4905112 load */
    /* @4905120 constant */
    /* @4905124 add */
    /* @4905128 constant */
    /* @4905132 load */
    /* @4905140 cast */
    /* @4905144 load */
    /* @4905152 constant */
    /* @4905156 add */
    /* @4905160 call */
    GM_SITE(vm, 599, 4905160);
    v59 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v60 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4905168 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v59, v60, STR_REF(1076)));
    L_4905172: ;
    /* @4905172 load */
    /* @4905180 constant */
    /* @4905184 cmp */
    /* @4905188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel2") == VAL(1)))) goto L_4906632;
    /* @4905192 load */
    /* @4905200 constant */
    /* @4905204 cmp */
    /* @4905208 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4905432;
    /* @4905212 constant */
    /* @4905216 cast */
    /* @4905220 call */
    GM_SITE(vm, 599, 4905220);
    /* @4905228 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4905232 constant */
    /* @4905240 cast */
    /* @4905244 call */
    GM_SITE(vm, 599, 4905244);
    /* @4905252 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4905256 string */
    /* @4905264 cast */
    /* @4905268 constant */
    /* @4905272 load */
    /* @4905280 cast */
    /* @4905284 load */
    /* @4905292 constant */
    /* @4905296 add */
    /* @4905300 constant */
    /* @4905304 load */
    /* @4905312 cast */
    /* @4905316 load */
    /* @4905324 constant */
    /* @4905328 add */
    /* @4905332 call */
    GM_SITE(vm, 599, 4905332);
    v61 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v62 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4905340 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v61, v62, STR_REF(1078)));
    /* @4905344 string */
    /* @4905352 cast */
    /* @4905356 constant */
    /* @4905360 load */
    /* @4905368 cast */
    /* @4905372 load */
    /* @4905380 constant */
    /* @4905384 add */
    /* @4905388 constant */
    /* @4905392 load */
    /* @4905400 cast */
    /* @4905404 load */
    /* @4905412 constant */
    /* @4905416 add */
    /* @4905420 call */
    GM_SITE(vm, 599, 4905420);
    v63 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v64 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4905428 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v63, v64, STR_REF(1079)));
    L_4905432: ;
    /* @4905432 load */
    /* @4905440 constant */
    /* @4905444 cmp */
    /* @4905448 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4905672;
    /* @4905452 constant */
    /* @4905456 cast */
    /* @4905460 call */
    GM_SITE(vm, 599, 4905460);
    /* @4905468 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4905472 constant */
    /* @4905480 cast */
    /* @4905484 call */
    GM_SITE(vm, 599, 4905484);
    /* @4905492 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4905496 string */
    /* @4905504 cast */
    /* @4905508 constant */
    /* @4905512 load */
    /* @4905520 cast */
    /* @4905524 load */
    /* @4905532 constant */
    /* @4905536 add */
    /* @4905540 constant */
    /* @4905544 load */
    /* @4905552 cast */
    /* @4905556 load */
    /* @4905564 constant */
    /* @4905568 add */
    /* @4905572 call */
    GM_SITE(vm, 599, 4905572);
    v65 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v66 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4905580 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v65, v66, STR_REF(1078)));
    /* @4905584 string */
    /* @4905592 cast */
    /* @4905596 constant */
    /* @4905600 load */
    /* @4905608 cast */
    /* @4905612 load */
    /* @4905620 constant */
    /* @4905624 add */
    /* @4905628 constant */
    /* @4905632 load */
    /* @4905640 cast */
    /* @4905644 load */
    /* @4905652 constant */
    /* @4905656 add */
    /* @4905660 call */
    GM_SITE(vm, 599, 4905660);
    v67 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v68 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4905668 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v67, v68, STR_REF(1079)));
    L_4905672: ;
    /* @4905672 load */
    /* @4905680 constant */
    /* @4905684 cmp */
    /* @4905688 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4905912;
    /* @4905692 constant */
    /* @4905696 cast */
    /* @4905700 call */
    GM_SITE(vm, 599, 4905700);
    /* @4905708 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4905712 constant */
    /* @4905720 cast */
    /* @4905724 call */
    GM_SITE(vm, 599, 4905724);
    /* @4905732 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4905736 string */
    /* @4905744 cast */
    /* @4905748 constant */
    /* @4905752 load */
    /* @4905760 cast */
    /* @4905764 load */
    /* @4905772 constant */
    /* @4905776 add */
    /* @4905780 constant */
    /* @4905784 load */
    /* @4905792 cast */
    /* @4905796 load */
    /* @4905804 constant */
    /* @4905808 add */
    /* @4905812 call */
    GM_SITE(vm, 599, 4905812);
    v69 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v70 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4905820 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v69, v70, STR_REF(1078)));
    /* @4905824 string */
    /* @4905832 cast */
    /* @4905836 constant */
    /* @4905840 load */
    /* @4905848 cast */
    /* @4905852 load */
    /* @4905860 constant */
    /* @4905864 add */
    /* @4905868 constant */
    /* @4905872 load */
    /* @4905880 cast */
    /* @4905884 load */
    /* @4905892 constant */
    /* @4905896 add */
    /* @4905900 call */
    GM_SITE(vm, 599, 4905900);
    v71 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v72 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4905908 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v71, v72, STR_REF(1079)));
    L_4905912: ;
    /* @4905912 load */
    /* @4905920 constant */
    /* @4905924 cmp */
    /* @4905928 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4906152;
    /* @4905932 constant */
    /* @4905936 cast */
    /* @4905940 call */
    GM_SITE(vm, 599, 4905940);
    /* @4905948 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4905952 constant */
    /* @4905960 cast */
    /* @4905964 call */
    GM_SITE(vm, 599, 4905964);
    /* @4905972 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4905976 string */
    /* @4905984 cast */
    /* @4905988 constant */
    /* @4905992 load */
    /* @4906000 cast */
    /* @4906004 load */
    /* @4906012 constant */
    /* @4906016 add */
    /* @4906020 constant */
    /* @4906024 load */
    /* @4906032 cast */
    /* @4906036 load */
    /* @4906044 constant */
    /* @4906048 add */
    /* @4906052 call */
    GM_SITE(vm, 599, 4906052);
    v73 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v74 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4906060 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v73, v74, STR_REF(1078)));
    /* @4906064 string */
    /* @4906072 cast */
    /* @4906076 constant */
    /* @4906080 load */
    /* @4906088 cast */
    /* @4906092 load */
    /* @4906100 constant */
    /* @4906104 add */
    /* @4906108 constant */
    /* @4906112 load */
    /* @4906120 cast */
    /* @4906124 load */
    /* @4906132 constant */
    /* @4906136 add */
    /* @4906140 call */
    GM_SITE(vm, 599, 4906140);
    v75 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v76 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4906148 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v75, v76, STR_REF(1079)));
    L_4906152: ;
    /* @4906152 load */
    /* @4906160 constant */
    /* @4906164 cmp */
    /* @4906168 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4906392;
    /* @4906172 constant */
    /* @4906176 cast */
    /* @4906180 call */
    GM_SITE(vm, 599, 4906180);
    /* @4906188 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4906192 constant */
    /* @4906200 cast */
    /* @4906204 call */
    GM_SITE(vm, 599, 4906204);
    /* @4906212 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4906216 string */
    /* @4906224 cast */
    /* @4906228 constant */
    /* @4906232 load */
    /* @4906240 cast */
    /* @4906244 load */
    /* @4906252 constant */
    /* @4906256 add */
    /* @4906260 constant */
    /* @4906264 load */
    /* @4906272 cast */
    /* @4906276 load */
    /* @4906284 constant */
    /* @4906288 add */
    /* @4906292 call */
    GM_SITE(vm, 599, 4906292);
    v77 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v78 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4906300 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v77, v78, STR_REF(1078)));
    /* @4906304 string */
    /* @4906312 cast */
    /* @4906316 constant */
    /* @4906320 load */
    /* @4906328 cast */
    /* @4906332 load */
    /* @4906340 constant */
    /* @4906344 add */
    /* @4906348 constant */
    /* @4906352 load */
    /* @4906360 cast */
    /* @4906364 load */
    /* @4906372 constant */
    /* @4906376 add */
    /* @4906380 call */
    GM_SITE(vm, 599, 4906380);
    v79 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v80 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4906388 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v79, v80, STR_REF(1079)));
    L_4906392: ;
    /* @4906392 load */
    /* @4906400 constant */
    /* @4906404 cmp */
    /* @4906408 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4906632;
    /* @4906412 constant */
    /* @4906416 cast */
    /* @4906420 call */
    GM_SITE(vm, 599, 4906420);
    /* @4906428 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4906432 constant */
    /* @4906440 cast */
    /* @4906444 call */
    GM_SITE(vm, 599, 4906444);
    /* @4906452 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4906456 string */
    /* @4906464 cast */
    /* @4906468 constant */
    /* @4906472 load */
    /* @4906480 cast */
    /* @4906484 load */
    /* @4906492 constant */
    /* @4906496 add */
    /* @4906500 constant */
    /* @4906504 load */
    /* @4906512 cast */
    /* @4906516 load */
    /* @4906524 constant */
    /* @4906528 add */
    /* @4906532 call */
    GM_SITE(vm, 599, 4906532);
    v81 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v82 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4906540 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v81, v82, STR_REF(1078)));
    /* @4906544 string */
    /* @4906552 cast */
    /* @4906556 constant */
    /* @4906560 load */
    /* @4906568 cast */
    /* @4906572 load */
    /* @4906580 constant */
    /* @4906584 add */
    /* @4906588 constant */
    /* @4906592 load */
    /* @4906600 cast */
    /* @4906604 load */
    /* @4906612 constant */
    /* @4906616 add */
    /* @4906620 call */
    GM_SITE(vm, 599, 4906620);
    v83 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v84 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4906628 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v83, v84, STR_REF(1079)));
    L_4906632: ;
    /* @4906632 load */
    /* @4906640 constant */
    /* @4906644 cmp */
    /* @4906648 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel3") == VAL(1)))) goto L_4908092;
    /* @4906652 load */
    /* @4906660 constant */
    /* @4906664 cmp */
    /* @4906668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4906892;
    /* @4906672 constant */
    /* @4906676 cast */
    /* @4906680 call */
    GM_SITE(vm, 599, 4906680);
    /* @4906688 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4906692 constant */
    /* @4906700 cast */
    /* @4906704 call */
    GM_SITE(vm, 599, 4906704);
    /* @4906712 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4906716 string */
    /* @4906724 cast */
    /* @4906728 constant */
    /* @4906732 load */
    /* @4906740 cast */
    /* @4906744 load */
    /* @4906752 constant */
    /* @4906756 add */
    /* @4906760 constant */
    /* @4906764 load */
    /* @4906772 cast */
    /* @4906776 load */
    /* @4906784 constant */
    /* @4906788 add */
    /* @4906792 call */
    GM_SITE(vm, 599, 4906792);
    v85 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v86 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4906800 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v85, v86, STR_REF(1080)));
    /* @4906804 string */
    /* @4906812 cast */
    /* @4906816 constant */
    /* @4906820 load */
    /* @4906828 cast */
    /* @4906832 load */
    /* @4906840 constant */
    /* @4906844 add */
    /* @4906848 constant */
    /* @4906852 load */
    /* @4906860 cast */
    /* @4906864 load */
    /* @4906872 constant */
    /* @4906876 add */
    /* @4906880 call */
    GM_SITE(vm, 599, 4906880);
    v87 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v88 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4906888 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v87, v88, STR_REF(1081)));
    L_4906892: ;
    /* @4906892 load */
    /* @4906900 constant */
    /* @4906904 cmp */
    /* @4906908 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4907132;
    /* @4906912 constant */
    /* @4906916 cast */
    /* @4906920 call */
    GM_SITE(vm, 599, 4906920);
    /* @4906928 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4906932 constant */
    /* @4906940 cast */
    /* @4906944 call */
    GM_SITE(vm, 599, 4906944);
    /* @4906952 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4906956 string */
    /* @4906964 cast */
    /* @4906968 constant */
    /* @4906972 load */
    /* @4906980 cast */
    /* @4906984 load */
    /* @4906992 constant */
    /* @4906996 add */
    /* @4907000 constant */
    /* @4907004 load */
    /* @4907012 cast */
    /* @4907016 load */
    /* @4907024 constant */
    /* @4907028 add */
    /* @4907032 call */
    GM_SITE(vm, 599, 4907032);
    v89 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v90 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4907040 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v89, v90, STR_REF(1080)));
    /* @4907044 string */
    /* @4907052 cast */
    /* @4907056 constant */
    /* @4907060 load */
    /* @4907068 cast */
    /* @4907072 load */
    /* @4907080 constant */
    /* @4907084 add */
    /* @4907088 constant */
    /* @4907092 load */
    /* @4907100 cast */
    /* @4907104 load */
    /* @4907112 constant */
    /* @4907116 add */
    /* @4907120 call */
    GM_SITE(vm, 599, 4907120);
    v91 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v92 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4907128 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v91, v92, STR_REF(1081)));
    L_4907132: ;
    /* @4907132 load */
    /* @4907140 constant */
    /* @4907144 cmp */
    /* @4907148 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4907372;
    /* @4907152 constant */
    /* @4907156 cast */
    /* @4907160 call */
    GM_SITE(vm, 599, 4907160);
    /* @4907168 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4907172 constant */
    /* @4907180 cast */
    /* @4907184 call */
    GM_SITE(vm, 599, 4907184);
    /* @4907192 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4907196 string */
    /* @4907204 cast */
    /* @4907208 constant */
    /* @4907212 load */
    /* @4907220 cast */
    /* @4907224 load */
    /* @4907232 constant */
    /* @4907236 add */
    /* @4907240 constant */
    /* @4907244 load */
    /* @4907252 cast */
    /* @4907256 load */
    /* @4907264 constant */
    /* @4907268 add */
    /* @4907272 call */
    GM_SITE(vm, 599, 4907272);
    v93 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v94 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4907280 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v93, v94, STR_REF(1080)));
    /* @4907284 string */
    /* @4907292 cast */
    /* @4907296 constant */
    /* @4907300 load */
    /* @4907308 cast */
    /* @4907312 load */
    /* @4907320 constant */
    /* @4907324 add */
    /* @4907328 constant */
    /* @4907332 load */
    /* @4907340 cast */
    /* @4907344 load */
    /* @4907352 constant */
    /* @4907356 add */
    /* @4907360 call */
    GM_SITE(vm, 599, 4907360);
    v95 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v96 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4907368 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v95, v96, STR_REF(1081)));
    L_4907372: ;
    /* @4907372 load */
    /* @4907380 constant */
    /* @4907384 cmp */
    /* @4907388 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4907612;
    /* @4907392 constant */
    /* @4907396 cast */
    /* @4907400 call */
    GM_SITE(vm, 599, 4907400);
    /* @4907408 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4907412 constant */
    /* @4907420 cast */
    /* @4907424 call */
    GM_SITE(vm, 599, 4907424);
    /* @4907432 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4907436 string */
    /* @4907444 cast */
    /* @4907448 constant */
    /* @4907452 load */
    /* @4907460 cast */
    /* @4907464 load */
    /* @4907472 constant */
    /* @4907476 add */
    /* @4907480 constant */
    /* @4907484 load */
    /* @4907492 cast */
    /* @4907496 load */
    /* @4907504 constant */
    /* @4907508 add */
    /* @4907512 call */
    GM_SITE(vm, 599, 4907512);
    v97 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v98 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4907520 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v97, v98, STR_REF(1080)));
    /* @4907524 string */
    /* @4907532 cast */
    /* @4907536 constant */
    /* @4907540 load */
    /* @4907548 cast */
    /* @4907552 load */
    /* @4907560 constant */
    /* @4907564 add */
    /* @4907568 constant */
    /* @4907572 load */
    /* @4907580 cast */
    /* @4907584 load */
    /* @4907592 constant */
    /* @4907596 add */
    /* @4907600 call */
    GM_SITE(vm, 599, 4907600);
    v99 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v100 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4907608 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v99, v100, STR_REF(1081)));
    L_4907612: ;
    /* @4907612 load */
    /* @4907620 constant */
    /* @4907624 cmp */
    /* @4907628 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4907852;
    /* @4907632 constant */
    /* @4907636 cast */
    /* @4907640 call */
    GM_SITE(vm, 599, 4907640);
    /* @4907648 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4907652 constant */
    /* @4907660 cast */
    /* @4907664 call */
    GM_SITE(vm, 599, 4907664);
    /* @4907672 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4907676 string */
    /* @4907684 cast */
    /* @4907688 constant */
    /* @4907692 load */
    /* @4907700 cast */
    /* @4907704 load */
    /* @4907712 constant */
    /* @4907716 add */
    /* @4907720 constant */
    /* @4907724 load */
    /* @4907732 cast */
    /* @4907736 load */
    /* @4907744 constant */
    /* @4907748 add */
    /* @4907752 call */
    GM_SITE(vm, 599, 4907752);
    v101 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v102 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4907760 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v101, v102, STR_REF(1080)));
    /* @4907764 string */
    /* @4907772 cast */
    /* @4907776 constant */
    /* @4907780 load */
    /* @4907788 cast */
    /* @4907792 load */
    /* @4907800 constant */
    /* @4907804 add */
    /* @4907808 constant */
    /* @4907812 load */
    /* @4907820 cast */
    /* @4907824 load */
    /* @4907832 constant */
    /* @4907836 add */
    /* @4907840 call */
    GM_SITE(vm, 599, 4907840);
    v103 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v104 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4907848 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v103, v104, STR_REF(1081)));
    L_4907852: ;
    /* @4907852 load */
    /* @4907860 constant */
    /* @4907864 cmp */
    /* @4907868 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4908092;
    /* @4907872 constant */
    /* @4907876 cast */
    /* @4907880 call */
    GM_SITE(vm, 599, 4907880);
    /* @4907888 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4907892 constant */
    /* @4907900 cast */
    /* @4907904 call */
    GM_SITE(vm, 599, 4907904);
    /* @4907912 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4907916 string */
    /* @4907924 cast */
    /* @4907928 constant */
    /* @4907932 load */
    /* @4907940 cast */
    /* @4907944 load */
    /* @4907952 constant */
    /* @4907956 add */
    /* @4907960 constant */
    /* @4907964 load */
    /* @4907972 cast */
    /* @4907976 load */
    /* @4907984 constant */
    /* @4907988 add */
    /* @4907992 call */
    GM_SITE(vm, 599, 4907992);
    v105 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v106 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4908000 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v105, v106, STR_REF(1080)));
    /* @4908004 string */
    /* @4908012 cast */
    /* @4908016 constant */
    /* @4908020 load */
    /* @4908028 cast */
    /* @4908032 load */
    /* @4908040 constant */
    /* @4908044 add */
    /* @4908048 constant */
    /* @4908052 load */
    /* @4908060 cast */
    /* @4908064 load */
    /* @4908072 constant */
    /* @4908076 add */
    /* @4908080 call */
    GM_SITE(vm, 599, 4908080);
    v107 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v108 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4908088 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v107, v108, STR_REF(1081)));
    L_4908092: ;
    /* @4908092 load */
    /* @4908100 constant */
    /* @4908104 cmp */
    /* @4908108 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel4") == VAL(1)))) goto L_4909552;
    /* @4908112 load */
    /* @4908120 constant */
    /* @4908124 cmp */
    /* @4908128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4908352;
    /* @4908132 constant */
    /* @4908136 cast */
    /* @4908140 call */
    GM_SITE(vm, 599, 4908140);
    /* @4908148 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4908152 constant */
    /* @4908160 cast */
    /* @4908164 call */
    GM_SITE(vm, 599, 4908164);
    /* @4908172 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4908176 string */
    /* @4908184 cast */
    /* @4908188 constant */
    /* @4908192 load */
    /* @4908200 cast */
    /* @4908204 load */
    /* @4908212 constant */
    /* @4908216 add */
    /* @4908220 constant */
    /* @4908224 load */
    /* @4908232 cast */
    /* @4908236 load */
    /* @4908244 constant */
    /* @4908248 add */
    /* @4908252 call */
    GM_SITE(vm, 599, 4908252);
    v109 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v110 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4908260 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v109, v110, STR_REF(1082)));
    /* @4908264 string */
    /* @4908272 cast */
    /* @4908276 constant */
    /* @4908280 load */
    /* @4908288 cast */
    /* @4908292 load */
    /* @4908300 constant */
    /* @4908304 add */
    /* @4908308 constant */
    /* @4908312 load */
    /* @4908320 cast */
    /* @4908324 load */
    /* @4908332 constant */
    /* @4908336 add */
    /* @4908340 call */
    GM_SITE(vm, 599, 4908340);
    v111 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v112 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4908348 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v111, v112, STR_REF(1083)));
    L_4908352: ;
    /* @4908352 load */
    /* @4908360 constant */
    /* @4908364 cmp */
    /* @4908368 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4908592;
    /* @4908372 constant */
    /* @4908376 cast */
    /* @4908380 call */
    GM_SITE(vm, 599, 4908380);
    /* @4908388 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4908392 constant */
    /* @4908400 cast */
    /* @4908404 call */
    GM_SITE(vm, 599, 4908404);
    /* @4908412 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4908416 string */
    /* @4908424 cast */
    /* @4908428 constant */
    /* @4908432 load */
    /* @4908440 cast */
    /* @4908444 load */
    /* @4908452 constant */
    /* @4908456 add */
    /* @4908460 constant */
    /* @4908464 load */
    /* @4908472 cast */
    /* @4908476 load */
    /* @4908484 constant */
    /* @4908488 add */
    /* @4908492 call */
    GM_SITE(vm, 599, 4908492);
    v113 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v114 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4908500 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v113, v114, STR_REF(1082)));
    /* @4908504 string */
    /* @4908512 cast */
    /* @4908516 constant */
    /* @4908520 load */
    /* @4908528 cast */
    /* @4908532 load */
    /* @4908540 constant */
    /* @4908544 add */
    /* @4908548 constant */
    /* @4908552 load */
    /* @4908560 cast */
    /* @4908564 load */
    /* @4908572 constant */
    /* @4908576 add */
    /* @4908580 call */
    GM_SITE(vm, 599, 4908580);
    v115 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v116 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4908588 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v115, v116, STR_REF(1083)));
    L_4908592: ;
    /* @4908592 load */
    /* @4908600 constant */
    /* @4908604 cmp */
    /* @4908608 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4908832;
    /* @4908612 constant */
    /* @4908616 cast */
    /* @4908620 call */
    GM_SITE(vm, 599, 4908620);
    /* @4908628 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4908632 constant */
    /* @4908640 cast */
    /* @4908644 call */
    GM_SITE(vm, 599, 4908644);
    /* @4908652 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4908656 string */
    /* @4908664 cast */
    /* @4908668 constant */
    /* @4908672 load */
    /* @4908680 cast */
    /* @4908684 load */
    /* @4908692 constant */
    /* @4908696 add */
    /* @4908700 constant */
    /* @4908704 load */
    /* @4908712 cast */
    /* @4908716 load */
    /* @4908724 constant */
    /* @4908728 add */
    /* @4908732 call */
    GM_SITE(vm, 599, 4908732);
    v117 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v118 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4908740 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v117, v118, STR_REF(1082)));
    /* @4908744 string */
    /* @4908752 cast */
    /* @4908756 constant */
    /* @4908760 load */
    /* @4908768 cast */
    /* @4908772 load */
    /* @4908780 constant */
    /* @4908784 add */
    /* @4908788 constant */
    /* @4908792 load */
    /* @4908800 cast */
    /* @4908804 load */
    /* @4908812 constant */
    /* @4908816 add */
    /* @4908820 call */
    GM_SITE(vm, 599, 4908820);
    v119 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v120 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4908828 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v119, v120, STR_REF(1083)));
    L_4908832: ;
    /* @4908832 load */
    /* @4908840 constant */
    /* @4908844 cmp */
    /* @4908848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4909072;
    /* @4908852 constant */
    /* @4908856 cast */
    /* @4908860 call */
    GM_SITE(vm, 599, 4908860);
    /* @4908868 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4908872 constant */
    /* @4908880 cast */
    /* @4908884 call */
    GM_SITE(vm, 599, 4908884);
    /* @4908892 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4908896 string */
    /* @4908904 cast */
    /* @4908908 constant */
    /* @4908912 load */
    /* @4908920 cast */
    /* @4908924 load */
    /* @4908932 constant */
    /* @4908936 add */
    /* @4908940 constant */
    /* @4908944 load */
    /* @4908952 cast */
    /* @4908956 load */
    /* @4908964 constant */
    /* @4908968 add */
    /* @4908972 call */
    GM_SITE(vm, 599, 4908972);
    v121 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v122 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4908980 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v121, v122, STR_REF(1082)));
    /* @4908984 string */
    /* @4908992 cast */
    /* @4908996 constant */
    /* @4909000 load */
    /* @4909008 cast */
    /* @4909012 load */
    /* @4909020 constant */
    /* @4909024 add */
    /* @4909028 constant */
    /* @4909032 load */
    /* @4909040 cast */
    /* @4909044 load */
    /* @4909052 constant */
    /* @4909056 add */
    /* @4909060 call */
    GM_SITE(vm, 599, 4909060);
    v123 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v124 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4909068 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v123, v124, STR_REF(1083)));
    L_4909072: ;
    /* @4909072 load */
    /* @4909080 constant */
    /* @4909084 cmp */
    /* @4909088 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4909312;
    /* @4909092 constant */
    /* @4909096 cast */
    /* @4909100 call */
    GM_SITE(vm, 599, 4909100);
    /* @4909108 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4909112 constant */
    /* @4909120 cast */
    /* @4909124 call */
    GM_SITE(vm, 599, 4909124);
    /* @4909132 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4909136 string */
    /* @4909144 cast */
    /* @4909148 constant */
    /* @4909152 load */
    /* @4909160 cast */
    /* @4909164 load */
    /* @4909172 constant */
    /* @4909176 add */
    /* @4909180 constant */
    /* @4909184 load */
    /* @4909192 cast */
    /* @4909196 load */
    /* @4909204 constant */
    /* @4909208 add */
    /* @4909212 call */
    GM_SITE(vm, 599, 4909212);
    v125 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v126 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4909220 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v125, v126, STR_REF(1082)));
    /* @4909224 string */
    /* @4909232 cast */
    /* @4909236 constant */
    /* @4909240 load */
    /* @4909248 cast */
    /* @4909252 load */
    /* @4909260 constant */
    /* @4909264 add */
    /* @4909268 constant */
    /* @4909272 load */
    /* @4909280 cast */
    /* @4909284 load */
    /* @4909292 constant */
    /* @4909296 add */
    /* @4909300 call */
    GM_SITE(vm, 599, 4909300);
    v127 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v128 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4909308 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v127, v128, STR_REF(1083)));
    L_4909312: ;
    /* @4909312 load */
    /* @4909320 constant */
    /* @4909324 cmp */
    /* @4909328 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4909552;
    /* @4909332 constant */
    /* @4909336 cast */
    /* @4909340 call */
    GM_SITE(vm, 599, 4909340);
    /* @4909348 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4909352 constant */
    /* @4909360 cast */
    /* @4909364 call */
    GM_SITE(vm, 599, 4909364);
    /* @4909372 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4909376 string */
    /* @4909384 cast */
    /* @4909388 constant */
    /* @4909392 load */
    /* @4909400 cast */
    /* @4909404 load */
    /* @4909412 constant */
    /* @4909416 add */
    /* @4909420 constant */
    /* @4909424 load */
    /* @4909432 cast */
    /* @4909436 load */
    /* @4909444 constant */
    /* @4909448 add */
    /* @4909452 call */
    GM_SITE(vm, 599, 4909452);
    v129 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v130 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4909460 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v129, v130, STR_REF(1082)));
    /* @4909464 string */
    /* @4909472 cast */
    /* @4909476 constant */
    /* @4909480 load */
    /* @4909488 cast */
    /* @4909492 load */
    /* @4909500 constant */
    /* @4909504 add */
    /* @4909508 constant */
    /* @4909512 load */
    /* @4909520 cast */
    /* @4909524 load */
    /* @4909532 constant */
    /* @4909536 add */
    /* @4909540 call */
    GM_SITE(vm, 599, 4909540);
    v131 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v132 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4909548 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v131, v132, STR_REF(1083)));
    L_4909552: ;
    /* @4909552 load */
    /* @4909560 constant */
    /* @4909564 cmp */
    /* @4909568 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel5") == VAL(1)))) goto L_4911012;
    /* @4909572 load */
    /* @4909580 constant */
    /* @4909584 cmp */
    /* @4909588 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4909812;
    /* @4909592 constant */
    /* @4909596 cast */
    /* @4909600 call */
    GM_SITE(vm, 599, 4909600);
    /* @4909608 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4909612 constant */
    /* @4909620 cast */
    /* @4909624 call */
    GM_SITE(vm, 599, 4909624);
    /* @4909632 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4909636 string */
    /* @4909644 cast */
    /* @4909648 constant */
    /* @4909652 load */
    /* @4909660 cast */
    /* @4909664 load */
    /* @4909672 constant */
    /* @4909676 add */
    /* @4909680 constant */
    /* @4909684 load */
    /* @4909692 cast */
    /* @4909696 load */
    /* @4909704 constant */
    /* @4909708 add */
    /* @4909712 call */
    GM_SITE(vm, 599, 4909712);
    v133 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v134 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4909720 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v133, v134, STR_REF(1084)));
    /* @4909724 string */
    /* @4909732 cast */
    /* @4909736 constant */
    /* @4909740 load */
    /* @4909748 cast */
    /* @4909752 load */
    /* @4909760 constant */
    /* @4909764 add */
    /* @4909768 constant */
    /* @4909772 load */
    /* @4909780 cast */
    /* @4909784 load */
    /* @4909792 constant */
    /* @4909796 add */
    /* @4909800 call */
    GM_SITE(vm, 599, 4909800);
    v135 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v136 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4909808 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v135, v136, STR_REF(1085)));
    L_4909812: ;
    /* @4909812 load */
    /* @4909820 constant */
    /* @4909824 cmp */
    /* @4909828 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4910052;
    /* @4909832 constant */
    /* @4909836 cast */
    /* @4909840 call */
    GM_SITE(vm, 599, 4909840);
    /* @4909848 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4909852 constant */
    /* @4909860 cast */
    /* @4909864 call */
    GM_SITE(vm, 599, 4909864);
    /* @4909872 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4909876 string */
    /* @4909884 cast */
    /* @4909888 constant */
    /* @4909892 load */
    /* @4909900 cast */
    /* @4909904 load */
    /* @4909912 constant */
    /* @4909916 add */
    /* @4909920 constant */
    /* @4909924 load */
    /* @4909932 cast */
    /* @4909936 load */
    /* @4909944 constant */
    /* @4909948 add */
    /* @4909952 call */
    GM_SITE(vm, 599, 4909952);
    v137 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v138 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4909960 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v137, v138, STR_REF(1084)));
    /* @4909964 string */
    /* @4909972 cast */
    /* @4909976 constant */
    /* @4909980 load */
    /* @4909988 cast */
    /* @4909992 load */
    /* @4910000 constant */
    /* @4910004 add */
    /* @4910008 constant */
    /* @4910012 load */
    /* @4910020 cast */
    /* @4910024 load */
    /* @4910032 constant */
    /* @4910036 add */
    /* @4910040 call */
    GM_SITE(vm, 599, 4910040);
    v139 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v140 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4910048 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v139, v140, STR_REF(1085)));
    L_4910052: ;
    /* @4910052 load */
    /* @4910060 constant */
    /* @4910064 cmp */
    /* @4910068 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4910292;
    /* @4910072 constant */
    /* @4910076 cast */
    /* @4910080 call */
    GM_SITE(vm, 599, 4910080);
    /* @4910088 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4910092 constant */
    /* @4910100 cast */
    /* @4910104 call */
    GM_SITE(vm, 599, 4910104);
    /* @4910112 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4910116 string */
    /* @4910124 cast */
    /* @4910128 constant */
    /* @4910132 load */
    /* @4910140 cast */
    /* @4910144 load */
    /* @4910152 constant */
    /* @4910156 add */
    /* @4910160 constant */
    /* @4910164 load */
    /* @4910172 cast */
    /* @4910176 load */
    /* @4910184 constant */
    /* @4910188 add */
    /* @4910192 call */
    GM_SITE(vm, 599, 4910192);
    v141 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v142 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4910200 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v141, v142, STR_REF(1084)));
    /* @4910204 string */
    /* @4910212 cast */
    /* @4910216 constant */
    /* @4910220 load */
    /* @4910228 cast */
    /* @4910232 load */
    /* @4910240 constant */
    /* @4910244 add */
    /* @4910248 constant */
    /* @4910252 load */
    /* @4910260 cast */
    /* @4910264 load */
    /* @4910272 constant */
    /* @4910276 add */
    /* @4910280 call */
    GM_SITE(vm, 599, 4910280);
    v143 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v144 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4910288 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v143, v144, STR_REF(1085)));
    L_4910292: ;
    /* @4910292 load */
    /* @4910300 constant */
    /* @4910304 cmp */
    /* @4910308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4910532;
    /* @4910312 constant */
    /* @4910316 cast */
    /* @4910320 call */
    GM_SITE(vm, 599, 4910320);
    /* @4910328 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4910332 constant */
    /* @4910340 cast */
    /* @4910344 call */
    GM_SITE(vm, 599, 4910344);
    /* @4910352 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4910356 string */
    /* @4910364 cast */
    /* @4910368 constant */
    /* @4910372 load */
    /* @4910380 cast */
    /* @4910384 load */
    /* @4910392 constant */
    /* @4910396 add */
    /* @4910400 constant */
    /* @4910404 load */
    /* @4910412 cast */
    /* @4910416 load */
    /* @4910424 constant */
    /* @4910428 add */
    /* @4910432 call */
    GM_SITE(vm, 599, 4910432);
    v145 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v146 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4910440 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v145, v146, STR_REF(1084)));
    /* @4910444 string */
    /* @4910452 cast */
    /* @4910456 constant */
    /* @4910460 load */
    /* @4910468 cast */
    /* @4910472 load */
    /* @4910480 constant */
    /* @4910484 add */
    /* @4910488 constant */
    /* @4910492 load */
    /* @4910500 cast */
    /* @4910504 load */
    /* @4910512 constant */
    /* @4910516 add */
    /* @4910520 call */
    GM_SITE(vm, 599, 4910520);
    v147 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v148 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4910528 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v147, v148, STR_REF(1085)));
    L_4910532: ;
    /* @4910532 load */
    /* @4910540 constant */
    /* @4910544 cmp */
    /* @4910548 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4910772;
    /* @4910552 constant */
    /* @4910556 cast */
    /* @4910560 call */
    GM_SITE(vm, 599, 4910560);
    /* @4910568 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4910572 constant */
    /* @4910580 cast */
    /* @4910584 call */
    GM_SITE(vm, 599, 4910584);
    /* @4910592 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4910596 string */
    /* @4910604 cast */
    /* @4910608 constant */
    /* @4910612 load */
    /* @4910620 cast */
    /* @4910624 load */
    /* @4910632 constant */
    /* @4910636 add */
    /* @4910640 constant */
    /* @4910644 load */
    /* @4910652 cast */
    /* @4910656 load */
    /* @4910664 constant */
    /* @4910668 add */
    /* @4910672 call */
    GM_SITE(vm, 599, 4910672);
    v149 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v150 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4910680 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v149, v150, STR_REF(1084)));
    /* @4910684 string */
    /* @4910692 cast */
    /* @4910696 constant */
    /* @4910700 load */
    /* @4910708 cast */
    /* @4910712 load */
    /* @4910720 constant */
    /* @4910724 add */
    /* @4910728 constant */
    /* @4910732 load */
    /* @4910740 cast */
    /* @4910744 load */
    /* @4910752 constant */
    /* @4910756 add */
    /* @4910760 call */
    GM_SITE(vm, 599, 4910760);
    v151 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v152 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4910768 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v151, v152, STR_REF(1085)));
    L_4910772: ;
    /* @4910772 load */
    /* @4910780 constant */
    /* @4910784 cmp */
    /* @4910788 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4911012;
    /* @4910792 constant */
    /* @4910796 cast */
    /* @4910800 call */
    GM_SITE(vm, 599, 4910800);
    /* @4910808 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4910812 constant */
    /* @4910820 cast */
    /* @4910824 call */
    GM_SITE(vm, 599, 4910824);
    /* @4910832 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4910836 string */
    /* @4910844 cast */
    /* @4910848 constant */
    /* @4910852 load */
    /* @4910860 cast */
    /* @4910864 load */
    /* @4910872 constant */
    /* @4910876 add */
    /* @4910880 constant */
    /* @4910884 load */
    /* @4910892 cast */
    /* @4910896 load */
    /* @4910904 constant */
    /* @4910908 add */
    /* @4910912 call */
    GM_SITE(vm, 599, 4910912);
    v153 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v154 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4910920 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v153, v154, STR_REF(1084)));
    /* @4910924 string */
    /* @4910932 cast */
    /* @4910936 constant */
    /* @4910940 load */
    /* @4910948 cast */
    /* @4910952 load */
    /* @4910960 constant */
    /* @4910964 add */
    /* @4910968 constant */
    /* @4910972 load */
    /* @4910980 cast */
    /* @4910984 load */
    /* @4910992 constant */
    /* @4910996 add */
    /* @4911000 call */
    GM_SITE(vm, 599, 4911000);
    v155 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v156 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4911008 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v155, v156, STR_REF(1085)));
    L_4911012: ;
    /* @4911012 load */
    /* @4911020 constant */
    /* @4911024 cmp */
    /* @4911028 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4911064;
    /* @4911032 constant */
    /* @4911036 cast */
    /* @4911040 constant */
    /* @4911044 cast */
    /* @4911048 call */
    GM_SITE(vm, 599, 4911048);
    /* @4911056 cast */
    /* @4911060 b */
    v157 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, VAL(0), VAL(1)));
    p4911068_0 = v157;
    goto L_4911068;
    L_4911064: ;
    /* @4911064 constant */
    p4911068_0 = VAL(0);
    L_4911068: ;
    /* @4911068 bf */
    if (!TRUTH(p4911068_0)) goto L_4911084;
    /* @4911072 call */
    GM_SITE(vm, 599, 4911072);
    /* @4911080 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4911084: ;
    return;
}
