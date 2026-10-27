/* generated from CODE 564 (gml_Object_obj_lloydtutorial1_Draw_0), source start 4848428, end 4861644. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0564(GmVM* vm) {
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
    Val v157;
    Val v158;
    Val v159;
    Val v160;
    Val v161;
    Val v162;
    Val v163;
    Val v164;
    Val v165;
    Val v166;
    Val v167;
    Val v168;
    Val v169;
    Val v170;
    Val v171;
    Val v172;
    Val v173;
    Val v174;
    Val v175;
    Val v176;
    Val v177;
    Val v178;
    Val v179;
    Val v180;
    Val v181;
    Val v182;
    Val v183;
    Val v184;
    Val v185;
    Val v186;
    Val v187;
    Val v188;
    Val v189;
    Val v190;
    Val v191;
    Val v192;
    Val v193;
    Val v194;
    Val v195;
    Val v196;
    Val v197;
    Val v198;
    Val v199;
    Val v200;
    Val v201;
    Val v202;
    Val v203;
    Val v204;
    Val p4861628_0;
    Val v205;
    /* @4848428 constant */
    /* @4848432 load */
    /* @4848440 cast */
    /* @4848444 load */
    /* @4848452 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4848460 constant */
    /* @4848464 load */
    /* @4848472 cast */
    /* @4848476 load */
    /* @4848484 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4848492 load */
    /* @4848500 constant */
    /* @4848504 cmp */
    /* @4848508 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4849036;
    /* @4848512 constant */
    /* @4848516 cast */
    /* @4848520 constant */
    /* @4848524 cast */
    /* @4848528 constant */
    /* @4848532 cast */
    /* @4848536 constant */
    /* @4848548 cast */
    /* @4848552 constant */
    /* @4848564 cast */
    /* @4848568 constant */
    /* @4848572 constant */
    /* @4848576 load */
    /* @4848584 constant */
    /* @4848588 constant */
    /* @4848592 load */
    /* @4848600 constant */
    /* @4848604 sub */
    /* @4848608 constant */
    /* @4848612 cast */
    /* @4848616 constant */
    /* @4848620 cast */
    /* @4848624 call */
    GM_SITE(vm, 564, 4848624);
    /* @4848632 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(0.96), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4848636 constant */
    /* @4848640 cast */
    /* @4848644 constant */
    /* @4848648 cast */
    /* @4848652 constant */
    /* @4848656 cast */
    /* @4848660 constant */
    /* @4848664 cast */
    /* @4848668 constant */
    /* @4848672 cast */
    /* @4848676 constant */
    /* @4848680 load */
    /* @4848688 cast */
    /* @4848692 load */
    /* @4848700 constant */
    /* @4848704 add */
    /* @4848708 constant */
    /* @4848712 load */
    /* @4848720 cast */
    /* @4848724 load */
    /* @4848732 constant */
    /* @4848736 add */
    /* @4848740 constant */
    /* @4848744 cast */
    /* @4848748 constant */
    /* @4848752 cast */
    /* @4848756 call */
    GM_SITE(vm, 564, 4848756);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4848764 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v1, v2, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4848768 constant */
    /* @4848772 cast */
    /* @4848776 constant */
    /* @4848780 cast */
    /* @4848784 constant */
    /* @4848788 cast */
    /* @4848792 constant */
    /* @4848796 cast */
    /* @4848800 constant */
    /* @4848804 cast */
    /* @4848808 constant */
    /* @4848812 load */
    /* @4848820 cast */
    /* @4848824 load */
    /* @4848832 constant */
    /* @4848836 add */
    /* @4848840 constant */
    /* @4848844 load */
    /* @4848852 cast */
    /* @4848856 load */
    /* @4848864 constant */
    /* @4848868 add */
    /* @4848872 constant */
    /* @4848876 cast */
    /* @4848880 constant */
    /* @4848884 cast */
    /* @4848888 call */
    GM_SITE(vm, 564, 4848888);
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4848896 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v3, v4, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4848900 load */
    /* @4848908 constant */
    /* @4848912 cmp */
    /* @4848916 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4849036;
    /* @4848920 constant */
    /* @4848924 cast */
    /* @4848928 call */
    GM_SITE(vm, 564, 4848928);
    /* @4848936 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4848940 constant */
    /* @4848948 cast */
    /* @4848952 call */
    GM_SITE(vm, 564, 4848952);
    /* @4848960 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4848964 string */
    /* @4848972 cast */
    /* @4848976 constant */
    /* @4848980 constant */
    /* @4848984 load */
    /* @4848992 constant */
    /* @4848996 add */
    /* @4849000 constant */
    /* @4849004 constant */
    /* @4849008 load */
    /* @4849016 constant */
    /* @4849020 add */
    /* @4849024 call */
    GM_SITE(vm, 564, 4849024);
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(150));
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(200));
    /* @4849032 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v5, v6, STR_REF(743)));
    L_4849036: ;
    /* @4849036 load */
    /* @4849044 constant */
    /* @4849048 cmp */
    /* @4849052 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4849580;
    /* @4849056 constant */
    /* @4849060 cast */
    /* @4849064 constant */
    /* @4849068 cast */
    /* @4849072 constant */
    /* @4849076 cast */
    /* @4849080 constant */
    /* @4849092 cast */
    /* @4849096 constant */
    /* @4849108 cast */
    /* @4849112 constant */
    /* @4849116 constant */
    /* @4849120 load */
    /* @4849128 constant */
    /* @4849132 constant */
    /* @4849136 load */
    /* @4849144 constant */
    /* @4849148 sub */
    /* @4849152 constant */
    /* @4849156 cast */
    /* @4849160 constant */
    /* @4849164 cast */
    /* @4849168 call */
    GM_SITE(vm, 564, 4849168);
    /* @4849176 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(0.82), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4849180 constant */
    /* @4849184 cast */
    /* @4849188 constant */
    /* @4849192 cast */
    /* @4849196 constant */
    /* @4849200 cast */
    /* @4849204 constant */
    /* @4849208 cast */
    /* @4849212 constant */
    /* @4849216 cast */
    /* @4849220 constant */
    /* @4849224 load */
    /* @4849232 cast */
    /* @4849236 load */
    /* @4849244 constant */
    /* @4849248 add */
    /* @4849252 constant */
    /* @4849256 load */
    /* @4849264 cast */
    /* @4849268 load */
    /* @4849276 constant */
    /* @4849280 add */
    /* @4849284 constant */
    /* @4849288 cast */
    /* @4849292 constant */
    /* @4849296 cast */
    /* @4849300 call */
    GM_SITE(vm, 564, 4849300);
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4849308 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v7, v8, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4849312 constant */
    /* @4849316 cast */
    /* @4849320 constant */
    /* @4849324 cast */
    /* @4849328 constant */
    /* @4849332 cast */
    /* @4849336 constant */
    /* @4849340 cast */
    /* @4849344 constant */
    /* @4849348 cast */
    /* @4849352 constant */
    /* @4849356 load */
    /* @4849364 cast */
    /* @4849368 load */
    /* @4849376 constant */
    /* @4849380 add */
    /* @4849384 constant */
    /* @4849388 load */
    /* @4849396 cast */
    /* @4849400 load */
    /* @4849408 constant */
    /* @4849412 add */
    /* @4849416 constant */
    /* @4849420 cast */
    /* @4849424 constant */
    /* @4849428 cast */
    /* @4849432 call */
    GM_SITE(vm, 564, 4849432);
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(320));
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4849440 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v9, v10, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4849444 load */
    /* @4849452 constant */
    /* @4849456 cmp */
    /* @4849460 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4849580;
    /* @4849464 constant */
    /* @4849468 cast */
    /* @4849472 call */
    GM_SITE(vm, 564, 4849472);
    /* @4849480 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4849484 constant */
    /* @4849492 cast */
    /* @4849496 call */
    GM_SITE(vm, 564, 4849496);
    /* @4849504 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4849508 string */
    /* @4849516 cast */
    /* @4849520 constant */
    /* @4849524 constant */
    /* @4849528 load */
    /* @4849536 constant */
    /* @4849540 add */
    /* @4849544 constant */
    /* @4849548 constant */
    /* @4849552 load */
    /* @4849560 constant */
    /* @4849564 add */
    /* @4849568 call */
    GM_SITE(vm, 564, 4849568);
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(110));
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4849576 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v11, v12, STR_REF(743)));
    L_4849580: ;
    /* @4849580 load */
    /* @4849588 constant */
    /* @4849592 cmp */
    /* @4849596 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4850124;
    /* @4849600 constant */
    /* @4849604 cast */
    /* @4849608 constant */
    /* @4849612 cast */
    /* @4849616 constant */
    /* @4849620 cast */
    /* @4849624 constant */
    /* @4849636 cast */
    /* @4849640 constant */
    /* @4849652 cast */
    /* @4849656 constant */
    /* @4849660 constant */
    /* @4849664 load */
    /* @4849672 constant */
    /* @4849676 constant */
    /* @4849680 load */
    /* @4849688 constant */
    /* @4849692 sub */
    /* @4849696 constant */
    /* @4849700 cast */
    /* @4849704 constant */
    /* @4849708 cast */
    /* @4849712 call */
    GM_SITE(vm, 564, 4849712);
    /* @4849720 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4849724 constant */
    /* @4849728 cast */
    /* @4849732 constant */
    /* @4849736 cast */
    /* @4849740 constant */
    /* @4849744 cast */
    /* @4849748 constant */
    /* @4849752 cast */
    /* @4849756 constant */
    /* @4849760 cast */
    /* @4849764 constant */
    /* @4849768 load */
    /* @4849776 cast */
    /* @4849780 load */
    /* @4849788 constant */
    /* @4849792 add */
    /* @4849796 constant */
    /* @4849800 load */
    /* @4849808 cast */
    /* @4849812 load */
    /* @4849820 constant */
    /* @4849824 add */
    /* @4849828 constant */
    /* @4849832 cast */
    /* @4849836 constant */
    /* @4849840 cast */
    /* @4849844 call */
    GM_SITE(vm, 564, 4849844);
    v13 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4849852 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v13, v14, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4849856 constant */
    /* @4849860 cast */
    /* @4849864 constant */
    /* @4849868 cast */
    /* @4849872 constant */
    /* @4849876 cast */
    /* @4849880 constant */
    /* @4849884 cast */
    /* @4849888 constant */
    /* @4849892 cast */
    /* @4849896 constant */
    /* @4849900 load */
    /* @4849908 cast */
    /* @4849912 load */
    /* @4849920 constant */
    /* @4849924 add */
    /* @4849928 constant */
    /* @4849932 load */
    /* @4849940 cast */
    /* @4849944 load */
    /* @4849952 constant */
    /* @4849956 add */
    /* @4849960 constant */
    /* @4849964 cast */
    /* @4849968 constant */
    /* @4849972 cast */
    /* @4849976 call */
    GM_SITE(vm, 564, 4849976);
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4849984 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v15, v16, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4849988 load */
    /* @4849996 constant */
    /* @4850000 cmp */
    /* @4850004 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4850124;
    /* @4850008 constant */
    /* @4850012 cast */
    /* @4850016 call */
    GM_SITE(vm, 564, 4850016);
    /* @4850024 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4850028 constant */
    /* @4850036 cast */
    /* @4850040 call */
    GM_SITE(vm, 564, 4850040);
    /* @4850048 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4850052 string */
    /* @4850060 cast */
    /* @4850064 constant */
    /* @4850068 constant */
    /* @4850072 load */
    /* @4850080 constant */
    /* @4850084 add */
    /* @4850088 constant */
    /* @4850092 constant */
    /* @4850096 load */
    /* @4850104 constant */
    /* @4850108 add */
    /* @4850112 call */
    GM_SITE(vm, 564, 4850112);
    v17 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(180));
    v18 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(300));
    /* @4850120 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v17, v18, STR_REF(743)));
    L_4850124: ;
    /* @4850124 load */
    /* @4850132 constant */
    /* @4850136 cmp */
    /* @4850140 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4850668;
    /* @4850144 constant */
    /* @4850148 cast */
    /* @4850152 constant */
    /* @4850156 cast */
    /* @4850160 constant */
    /* @4850164 cast */
    /* @4850168 constant */
    /* @4850180 cast */
    /* @4850184 constant */
    /* @4850196 cast */
    /* @4850200 constant */
    /* @4850204 constant */
    /* @4850208 load */
    /* @4850216 constant */
    /* @4850220 constant */
    /* @4850224 load */
    /* @4850232 constant */
    /* @4850236 sub */
    /* @4850240 constant */
    /* @4850244 cast */
    /* @4850248 constant */
    /* @4850252 cast */
    /* @4850256 call */
    GM_SITE(vm, 564, 4850256);
    /* @4850264 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4850268 constant */
    /* @4850272 cast */
    /* @4850276 constant */
    /* @4850280 cast */
    /* @4850284 constant */
    /* @4850288 cast */
    /* @4850292 constant */
    /* @4850296 cast */
    /* @4850300 constant */
    /* @4850304 cast */
    /* @4850308 constant */
    /* @4850312 load */
    /* @4850320 cast */
    /* @4850324 load */
    /* @4850332 constant */
    /* @4850336 add */
    /* @4850340 constant */
    /* @4850344 load */
    /* @4850352 cast */
    /* @4850356 load */
    /* @4850364 constant */
    /* @4850368 add */
    /* @4850372 constant */
    /* @4850376 cast */
    /* @4850380 constant */
    /* @4850384 cast */
    /* @4850388 call */
    GM_SITE(vm, 564, 4850388);
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4850396 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v19, v20, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4850400 constant */
    /* @4850404 cast */
    /* @4850408 constant */
    /* @4850412 cast */
    /* @4850416 constant */
    /* @4850420 cast */
    /* @4850424 constant */
    /* @4850428 cast */
    /* @4850432 constant */
    /* @4850436 cast */
    /* @4850440 constant */
    /* @4850444 load */
    /* @4850452 cast */
    /* @4850456 load */
    /* @4850464 constant */
    /* @4850468 add */
    /* @4850472 constant */
    /* @4850476 load */
    /* @4850484 cast */
    /* @4850488 load */
    /* @4850496 constant */
    /* @4850500 add */
    /* @4850504 constant */
    /* @4850508 cast */
    /* @4850512 constant */
    /* @4850516 cast */
    /* @4850520 call */
    GM_SITE(vm, 564, 4850520);
    v21 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4850528 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v21, v22, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4850532 load */
    /* @4850540 constant */
    /* @4850544 cmp */
    /* @4850548 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4850668;
    /* @4850552 constant */
    /* @4850556 cast */
    /* @4850560 call */
    GM_SITE(vm, 564, 4850560);
    /* @4850568 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4850572 constant */
    /* @4850580 cast */
    /* @4850584 call */
    GM_SITE(vm, 564, 4850584);
    /* @4850592 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4850596 string */
    /* @4850604 cast */
    /* @4850608 constant */
    /* @4850612 constant */
    /* @4850616 load */
    /* @4850624 constant */
    /* @4850628 add */
    /* @4850632 constant */
    /* @4850636 constant */
    /* @4850640 load */
    /* @4850648 constant */
    /* @4850652 add */
    /* @4850656 call */
    GM_SITE(vm, 564, 4850656);
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(180));
    v24 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(300));
    /* @4850664 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v23, v24, STR_REF(743)));
    L_4850668: ;
    /* @4850668 load */
    /* @4850676 constant */
    /* @4850680 cmp */
    /* @4850684 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4851212;
    /* @4850688 constant */
    /* @4850692 cast */
    /* @4850696 constant */
    /* @4850700 cast */
    /* @4850704 constant */
    /* @4850708 cast */
    /* @4850712 constant */
    /* @4850724 cast */
    /* @4850728 constant */
    /* @4850740 cast */
    /* @4850744 constant */
    /* @4850748 constant */
    /* @4850752 load */
    /* @4850760 constant */
    /* @4850764 constant */
    /* @4850768 load */
    /* @4850776 constant */
    /* @4850780 sub */
    /* @4850784 constant */
    /* @4850788 cast */
    /* @4850792 constant */
    /* @4850796 cast */
    /* @4850800 call */
    GM_SITE(vm, 564, 4850800);
    /* @4850808 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(0.97), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4850812 constant */
    /* @4850816 cast */
    /* @4850820 constant */
    /* @4850824 cast */
    /* @4850828 constant */
    /* @4850832 cast */
    /* @4850836 constant */
    /* @4850840 cast */
    /* @4850844 constant */
    /* @4850848 cast */
    /* @4850852 constant */
    /* @4850856 load */
    /* @4850864 cast */
    /* @4850868 load */
    /* @4850876 constant */
    /* @4850880 add */
    /* @4850884 constant */
    /* @4850888 load */
    /* @4850896 cast */
    /* @4850900 load */
    /* @4850908 constant */
    /* @4850912 add */
    /* @4850916 constant */
    /* @4850920 cast */
    /* @4850924 constant */
    /* @4850928 cast */
    /* @4850932 call */
    GM_SITE(vm, 564, 4850932);
    v25 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v26 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4850940 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v25, v26, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4850944 constant */
    /* @4850948 cast */
    /* @4850952 constant */
    /* @4850956 cast */
    /* @4850960 constant */
    /* @4850964 cast */
    /* @4850968 constant */
    /* @4850972 cast */
    /* @4850976 constant */
    /* @4850980 cast */
    /* @4850984 constant */
    /* @4850988 load */
    /* @4850996 cast */
    /* @4851000 load */
    /* @4851008 constant */
    /* @4851012 add */
    /* @4851016 constant */
    /* @4851020 load */
    /* @4851028 cast */
    /* @4851032 load */
    /* @4851040 constant */
    /* @4851044 add */
    /* @4851048 constant */
    /* @4851052 cast */
    /* @4851056 constant */
    /* @4851060 cast */
    /* @4851064 call */
    GM_SITE(vm, 564, 4851064);
    v27 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v28 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4851072 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v27, v28, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4851076 load */
    /* @4851084 constant */
    /* @4851088 cmp */
    /* @4851092 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4851212;
    /* @4851096 constant */
    /* @4851100 cast */
    /* @4851104 call */
    GM_SITE(vm, 564, 4851104);
    /* @4851112 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4851116 constant */
    /* @4851124 cast */
    /* @4851128 call */
    GM_SITE(vm, 564, 4851128);
    /* @4851136 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4851140 string */
    /* @4851148 cast */
    /* @4851152 constant */
    /* @4851156 constant */
    /* @4851160 load */
    /* @4851168 constant */
    /* @4851172 add */
    /* @4851176 constant */
    /* @4851180 constant */
    /* @4851184 load */
    /* @4851192 constant */
    /* @4851196 add */
    /* @4851200 call */
    GM_SITE(vm, 564, 4851200);
    v29 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(150));
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(200));
    /* @4851208 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v29, v30, STR_REF(743)));
    L_4851212: ;
    /* @4851212 load */
    /* @4851220 constant */
    /* @4851224 cmp */
    /* @4851228 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4851756;
    /* @4851232 constant */
    /* @4851236 cast */
    /* @4851240 constant */
    /* @4851244 cast */
    /* @4851248 constant */
    /* @4851252 cast */
    /* @4851256 constant */
    /* @4851268 cast */
    /* @4851272 constant */
    /* @4851284 cast */
    /* @4851288 constant */
    /* @4851292 constant */
    /* @4851296 load */
    /* @4851304 constant */
    /* @4851308 constant */
    /* @4851312 load */
    /* @4851320 constant */
    /* @4851324 sub */
    /* @4851328 constant */
    /* @4851332 cast */
    /* @4851336 constant */
    /* @4851340 cast */
    /* @4851344 call */
    GM_SITE(vm, 564, 4851344);
    /* @4851352 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(1.06), VAL(0.86), VAL(0), VAL(-1), VAL(1)));
    /* @4851356 constant */
    /* @4851360 cast */
    /* @4851364 constant */
    /* @4851368 cast */
    /* @4851372 constant */
    /* @4851376 cast */
    /* @4851380 constant */
    /* @4851384 cast */
    /* @4851388 constant */
    /* @4851392 cast */
    /* @4851396 constant */
    /* @4851400 load */
    /* @4851408 cast */
    /* @4851412 load */
    /* @4851420 constant */
    /* @4851424 add */
    /* @4851428 constant */
    /* @4851432 load */
    /* @4851440 cast */
    /* @4851444 load */
    /* @4851452 constant */
    /* @4851456 add */
    /* @4851460 constant */
    /* @4851464 cast */
    /* @4851468 constant */
    /* @4851472 cast */
    /* @4851476 call */
    GM_SITE(vm, 564, 4851476);
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v32 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4851484 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v31, v32, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4851488 constant */
    /* @4851492 cast */
    /* @4851496 constant */
    /* @4851500 cast */
    /* @4851504 constant */
    /* @4851508 cast */
    /* @4851512 constant */
    /* @4851516 cast */
    /* @4851520 constant */
    /* @4851524 cast */
    /* @4851528 constant */
    /* @4851532 load */
    /* @4851540 cast */
    /* @4851544 load */
    /* @4851552 constant */
    /* @4851556 add */
    /* @4851560 constant */
    /* @4851564 load */
    /* @4851572 cast */
    /* @4851576 load */
    /* @4851584 constant */
    /* @4851588 add */
    /* @4851592 constant */
    /* @4851596 cast */
    /* @4851600 constant */
    /* @4851604 cast */
    /* @4851608 call */
    GM_SITE(vm, 564, 4851608);
    v33 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(390));
    v34 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4851616 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v33, v34, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4851620 load */
    /* @4851628 constant */
    /* @4851632 cmp */
    /* @4851636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4851756;
    /* @4851640 constant */
    /* @4851644 cast */
    /* @4851648 call */
    GM_SITE(vm, 564, 4851648);
    /* @4851656 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4851660 constant */
    /* @4851668 cast */
    /* @4851672 call */
    GM_SITE(vm, 564, 4851672);
    /* @4851680 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4851684 string */
    /* @4851692 cast */
    /* @4851696 constant */
    /* @4851700 constant */
    /* @4851704 load */
    /* @4851712 constant */
    /* @4851716 add */
    /* @4851720 constant */
    /* @4851724 constant */
    /* @4851728 load */
    /* @4851736 constant */
    /* @4851740 add */
    /* @4851744 call */
    GM_SITE(vm, 564, 4851744);
    v35 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(160));
    v36 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(200));
    /* @4851752 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v35, v36, STR_REF(743)));
    L_4851756: ;
    /* @4851756 load */
    /* @4851764 constant */
    /* @4851768 cmp */
    /* @4851772 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel1") == VAL(1)))) goto L_4853216;
    /* @4851776 load */
    /* @4851784 constant */
    /* @4851788 cmp */
    /* @4851792 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4852016;
    /* @4851796 constant */
    /* @4851800 cast */
    /* @4851804 call */
    GM_SITE(vm, 564, 4851804);
    /* @4851812 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4851816 constant */
    /* @4851824 cast */
    /* @4851828 call */
    GM_SITE(vm, 564, 4851828);
    /* @4851836 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4851840 string */
    /* @4851848 cast */
    /* @4851852 constant */
    /* @4851856 load */
    /* @4851864 cast */
    /* @4851868 load */
    /* @4851876 constant */
    /* @4851880 add */
    /* @4851884 constant */
    /* @4851888 load */
    /* @4851896 cast */
    /* @4851900 load */
    /* @4851908 constant */
    /* @4851912 add */
    /* @4851916 call */
    GM_SITE(vm, 564, 4851916);
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4851924 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v37, v38, STR_REF(1036)));
    /* @4851928 string */
    /* @4851936 cast */
    /* @4851940 constant */
    /* @4851944 load */
    /* @4851952 cast */
    /* @4851956 load */
    /* @4851964 constant */
    /* @4851968 add */
    /* @4851972 constant */
    /* @4851976 load */
    /* @4851984 cast */
    /* @4851988 load */
    /* @4851996 constant */
    /* @4852000 add */
    /* @4852004 call */
    GM_SITE(vm, 564, 4852004);
    v39 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v40 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4852012 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, v40, STR_REF(1037)));
    L_4852016: ;
    /* @4852016 load */
    /* @4852024 constant */
    /* @4852028 cmp */
    /* @4852032 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4852256;
    /* @4852036 constant */
    /* @4852040 cast */
    /* @4852044 call */
    GM_SITE(vm, 564, 4852044);
    /* @4852052 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4852056 constant */
    /* @4852064 cast */
    /* @4852068 call */
    GM_SITE(vm, 564, 4852068);
    /* @4852076 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4852080 string */
    /* @4852088 cast */
    /* @4852092 constant */
    /* @4852096 load */
    /* @4852104 cast */
    /* @4852108 load */
    /* @4852116 constant */
    /* @4852120 add */
    /* @4852124 constant */
    /* @4852128 load */
    /* @4852136 cast */
    /* @4852140 load */
    /* @4852148 constant */
    /* @4852152 add */
    /* @4852156 call */
    GM_SITE(vm, 564, 4852156);
    v41 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v42 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4852164 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v41, v42, STR_REF(1036)));
    /* @4852168 string */
    /* @4852176 cast */
    /* @4852180 constant */
    /* @4852184 load */
    /* @4852192 cast */
    /* @4852196 load */
    /* @4852204 constant */
    /* @4852208 add */
    /* @4852212 constant */
    /* @4852216 load */
    /* @4852224 cast */
    /* @4852228 load */
    /* @4852236 constant */
    /* @4852240 add */
    /* @4852244 call */
    GM_SITE(vm, 564, 4852244);
    v43 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v44 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4852252 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v43, v44, STR_REF(1037)));
    L_4852256: ;
    /* @4852256 load */
    /* @4852264 constant */
    /* @4852268 cmp */
    /* @4852272 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4852496;
    /* @4852276 constant */
    /* @4852280 cast */
    /* @4852284 call */
    GM_SITE(vm, 564, 4852284);
    /* @4852292 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4852296 constant */
    /* @4852304 cast */
    /* @4852308 call */
    GM_SITE(vm, 564, 4852308);
    /* @4852316 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4852320 string */
    /* @4852328 cast */
    /* @4852332 constant */
    /* @4852336 load */
    /* @4852344 cast */
    /* @4852348 load */
    /* @4852356 constant */
    /* @4852360 add */
    /* @4852364 constant */
    /* @4852368 load */
    /* @4852376 cast */
    /* @4852380 load */
    /* @4852388 constant */
    /* @4852392 add */
    /* @4852396 call */
    GM_SITE(vm, 564, 4852396);
    v45 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v46 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4852404 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v45, v46, STR_REF(1036)));
    /* @4852408 string */
    /* @4852416 cast */
    /* @4852420 constant */
    /* @4852424 load */
    /* @4852432 cast */
    /* @4852436 load */
    /* @4852444 constant */
    /* @4852448 add */
    /* @4852452 constant */
    /* @4852456 load */
    /* @4852464 cast */
    /* @4852468 load */
    /* @4852476 constant */
    /* @4852480 add */
    /* @4852484 call */
    GM_SITE(vm, 564, 4852484);
    v47 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v48 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4852492 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v47, v48, STR_REF(1037)));
    L_4852496: ;
    /* @4852496 load */
    /* @4852504 constant */
    /* @4852508 cmp */
    /* @4852512 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4852736;
    /* @4852516 constant */
    /* @4852520 cast */
    /* @4852524 call */
    GM_SITE(vm, 564, 4852524);
    /* @4852532 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4852536 constant */
    /* @4852544 cast */
    /* @4852548 call */
    GM_SITE(vm, 564, 4852548);
    /* @4852556 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4852560 string */
    /* @4852568 cast */
    /* @4852572 constant */
    /* @4852576 load */
    /* @4852584 cast */
    /* @4852588 load */
    /* @4852596 constant */
    /* @4852600 add */
    /* @4852604 constant */
    /* @4852608 load */
    /* @4852616 cast */
    /* @4852620 load */
    /* @4852628 constant */
    /* @4852632 add */
    /* @4852636 call */
    GM_SITE(vm, 564, 4852636);
    v49 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v50 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4852644 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v49, v50, STR_REF(1036)));
    /* @4852648 string */
    /* @4852656 cast */
    /* @4852660 constant */
    /* @4852664 load */
    /* @4852672 cast */
    /* @4852676 load */
    /* @4852684 constant */
    /* @4852688 add */
    /* @4852692 constant */
    /* @4852696 load */
    /* @4852704 cast */
    /* @4852708 load */
    /* @4852716 constant */
    /* @4852720 add */
    /* @4852724 call */
    GM_SITE(vm, 564, 4852724);
    v51 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v52 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4852732 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v51, v52, STR_REF(1037)));
    L_4852736: ;
    /* @4852736 load */
    /* @4852744 constant */
    /* @4852748 cmp */
    /* @4852752 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4852976;
    /* @4852756 constant */
    /* @4852760 cast */
    /* @4852764 call */
    GM_SITE(vm, 564, 4852764);
    /* @4852772 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4852776 constant */
    /* @4852784 cast */
    /* @4852788 call */
    GM_SITE(vm, 564, 4852788);
    /* @4852796 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4852800 string */
    /* @4852808 cast */
    /* @4852812 constant */
    /* @4852816 load */
    /* @4852824 cast */
    /* @4852828 load */
    /* @4852836 constant */
    /* @4852840 add */
    /* @4852844 constant */
    /* @4852848 load */
    /* @4852856 cast */
    /* @4852860 load */
    /* @4852868 constant */
    /* @4852872 add */
    /* @4852876 call */
    GM_SITE(vm, 564, 4852876);
    v53 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v54 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4852884 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v53, v54, STR_REF(1036)));
    /* @4852888 string */
    /* @4852896 cast */
    /* @4852900 constant */
    /* @4852904 load */
    /* @4852912 cast */
    /* @4852916 load */
    /* @4852924 constant */
    /* @4852928 add */
    /* @4852932 constant */
    /* @4852936 load */
    /* @4852944 cast */
    /* @4852948 load */
    /* @4852956 constant */
    /* @4852960 add */
    /* @4852964 call */
    GM_SITE(vm, 564, 4852964);
    v55 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v56 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4852972 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v55, v56, STR_REF(1037)));
    L_4852976: ;
    /* @4852976 load */
    /* @4852984 constant */
    /* @4852988 cmp */
    /* @4852992 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4853216;
    /* @4852996 constant */
    /* @4853000 cast */
    /* @4853004 call */
    GM_SITE(vm, 564, 4853004);
    /* @4853012 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4853016 constant */
    /* @4853024 cast */
    /* @4853028 call */
    GM_SITE(vm, 564, 4853028);
    /* @4853036 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4853040 string */
    /* @4853048 cast */
    /* @4853052 constant */
    /* @4853056 load */
    /* @4853064 cast */
    /* @4853068 load */
    /* @4853076 constant */
    /* @4853080 add */
    /* @4853084 constant */
    /* @4853088 load */
    /* @4853096 cast */
    /* @4853100 load */
    /* @4853108 constant */
    /* @4853112 add */
    /* @4853116 call */
    GM_SITE(vm, 564, 4853116);
    v57 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v58 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4853124 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v57, v58, STR_REF(1036)));
    /* @4853128 string */
    /* @4853136 cast */
    /* @4853140 constant */
    /* @4853144 load */
    /* @4853152 cast */
    /* @4853156 load */
    /* @4853164 constant */
    /* @4853168 add */
    /* @4853172 constant */
    /* @4853176 load */
    /* @4853184 cast */
    /* @4853188 load */
    /* @4853196 constant */
    /* @4853200 add */
    /* @4853204 call */
    GM_SITE(vm, 564, 4853204);
    v59 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v60 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4853212 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v59, v60, STR_REF(1037)));
    L_4853216: ;
    /* @4853216 load */
    /* @4853224 constant */
    /* @4853228 cmp */
    /* @4853232 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel2") == VAL(1)))) goto L_4855732;
    /* @4853236 load */
    /* @4853244 constant */
    /* @4853248 cmp */
    /* @4853252 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4853652;
    /* @4853256 constant */
    /* @4853260 cast */
    /* @4853264 call */
    GM_SITE(vm, 564, 4853264);
    /* @4853272 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4853276 constant */
    /* @4853284 cast */
    /* @4853288 call */
    GM_SITE(vm, 564, 4853288);
    /* @4853296 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4853300 string */
    /* @4853308 cast */
    /* @4853312 constant */
    /* @4853316 load */
    /* @4853324 cast */
    /* @4853328 load */
    /* @4853336 constant */
    /* @4853340 add */
    /* @4853344 constant */
    /* @4853348 load */
    /* @4853356 cast */
    /* @4853360 load */
    /* @4853368 constant */
    /* @4853372 add */
    /* @4853376 call */
    GM_SITE(vm, 564, 4853376);
    v61 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v62 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4853384 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v61, v62, STR_REF(1036)));
    /* @4853388 string */
    /* @4853396 cast */
    /* @4853400 constant */
    /* @4853404 load */
    /* @4853412 cast */
    /* @4853416 load */
    /* @4853424 constant */
    /* @4853428 add */
    /* @4853432 constant */
    /* @4853436 load */
    /* @4853444 cast */
    /* @4853448 load */
    /* @4853456 constant */
    /* @4853460 add */
    /* @4853464 call */
    GM_SITE(vm, 564, 4853464);
    v63 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v64 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4853472 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v63, v64, STR_REF(1037)));
    /* @4853476 string */
    /* @4853484 cast */
    /* @4853488 constant */
    /* @4853492 load */
    /* @4853500 cast */
    /* @4853504 load */
    /* @4853512 constant */
    /* @4853516 add */
    /* @4853520 constant */
    /* @4853524 load */
    /* @4853532 cast */
    /* @4853536 load */
    /* @4853544 constant */
    /* @4853548 add */
    /* @4853552 call */
    GM_SITE(vm, 564, 4853552);
    v65 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v66 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4853560 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v65, v66, STR_REF(1038)));
    /* @4853564 string */
    /* @4853572 cast */
    /* @4853576 constant */
    /* @4853580 load */
    /* @4853588 cast */
    /* @4853592 load */
    /* @4853600 constant */
    /* @4853604 add */
    /* @4853608 constant */
    /* @4853612 load */
    /* @4853620 cast */
    /* @4853624 load */
    /* @4853632 constant */
    /* @4853636 add */
    /* @4853640 call */
    GM_SITE(vm, 564, 4853640);
    v67 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v68 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4853648 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v67, v68, STR_REF(1039)));
    L_4853652: ;
    /* @4853652 load */
    /* @4853660 constant */
    /* @4853664 cmp */
    /* @4853668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4854068;
    /* @4853672 constant */
    /* @4853676 cast */
    /* @4853680 call */
    GM_SITE(vm, 564, 4853680);
    /* @4853688 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4853692 constant */
    /* @4853700 cast */
    /* @4853704 call */
    GM_SITE(vm, 564, 4853704);
    /* @4853712 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4853716 string */
    /* @4853724 cast */
    /* @4853728 constant */
    /* @4853732 load */
    /* @4853740 cast */
    /* @4853744 load */
    /* @4853752 constant */
    /* @4853756 add */
    /* @4853760 constant */
    /* @4853764 load */
    /* @4853772 cast */
    /* @4853776 load */
    /* @4853784 constant */
    /* @4853788 add */
    /* @4853792 call */
    GM_SITE(vm, 564, 4853792);
    v69 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v70 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4853800 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v69, v70, STR_REF(1036)));
    /* @4853804 string */
    /* @4853812 cast */
    /* @4853816 constant */
    /* @4853820 load */
    /* @4853828 cast */
    /* @4853832 load */
    /* @4853840 constant */
    /* @4853844 add */
    /* @4853848 constant */
    /* @4853852 load */
    /* @4853860 cast */
    /* @4853864 load */
    /* @4853872 constant */
    /* @4853876 add */
    /* @4853880 call */
    GM_SITE(vm, 564, 4853880);
    v71 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v72 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4853888 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v71, v72, STR_REF(1037)));
    /* @4853892 string */
    /* @4853900 cast */
    /* @4853904 constant */
    /* @4853908 load */
    /* @4853916 cast */
    /* @4853920 load */
    /* @4853928 constant */
    /* @4853932 add */
    /* @4853936 constant */
    /* @4853940 load */
    /* @4853948 cast */
    /* @4853952 load */
    /* @4853960 constant */
    /* @4853964 add */
    /* @4853968 call */
    GM_SITE(vm, 564, 4853968);
    v73 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v74 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    /* @4853976 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v73, v74, STR_REF(1038)));
    /* @4853980 string */
    /* @4853988 cast */
    /* @4853992 constant */
    /* @4853996 load */
    /* @4854004 cast */
    /* @4854008 load */
    /* @4854016 constant */
    /* @4854020 add */
    /* @4854024 constant */
    /* @4854028 load */
    /* @4854036 cast */
    /* @4854040 load */
    /* @4854048 constant */
    /* @4854052 add */
    /* @4854056 call */
    GM_SITE(vm, 564, 4854056);
    v75 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v76 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(140));
    /* @4854064 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v75, v76, STR_REF(1039)));
    L_4854068: ;
    /* @4854068 load */
    /* @4854076 constant */
    /* @4854080 cmp */
    /* @4854084 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4854484;
    /* @4854088 constant */
    /* @4854092 cast */
    /* @4854096 call */
    GM_SITE(vm, 564, 4854096);
    /* @4854104 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4854108 constant */
    /* @4854116 cast */
    /* @4854120 call */
    GM_SITE(vm, 564, 4854120);
    /* @4854128 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4854132 string */
    /* @4854140 cast */
    /* @4854144 constant */
    /* @4854148 load */
    /* @4854156 cast */
    /* @4854160 load */
    /* @4854168 constant */
    /* @4854172 add */
    /* @4854176 constant */
    /* @4854180 load */
    /* @4854188 cast */
    /* @4854192 load */
    /* @4854200 constant */
    /* @4854204 add */
    /* @4854208 call */
    GM_SITE(vm, 564, 4854208);
    v77 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v78 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4854216 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v77, v78, STR_REF(1036)));
    /* @4854220 string */
    /* @4854228 cast */
    /* @4854232 constant */
    /* @4854236 load */
    /* @4854244 cast */
    /* @4854248 load */
    /* @4854256 constant */
    /* @4854260 add */
    /* @4854264 constant */
    /* @4854268 load */
    /* @4854276 cast */
    /* @4854280 load */
    /* @4854288 constant */
    /* @4854292 add */
    /* @4854296 call */
    GM_SITE(vm, 564, 4854296);
    v79 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v80 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4854304 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v79, v80, STR_REF(1037)));
    /* @4854308 string */
    /* @4854316 cast */
    /* @4854320 constant */
    /* @4854324 load */
    /* @4854332 cast */
    /* @4854336 load */
    /* @4854344 constant */
    /* @4854348 add */
    /* @4854352 constant */
    /* @4854356 load */
    /* @4854364 cast */
    /* @4854368 load */
    /* @4854376 constant */
    /* @4854380 add */
    /* @4854384 call */
    GM_SITE(vm, 564, 4854384);
    v81 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v82 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4854392 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v81, v82, STR_REF(1038)));
    /* @4854396 string */
    /* @4854404 cast */
    /* @4854408 constant */
    /* @4854412 load */
    /* @4854420 cast */
    /* @4854424 load */
    /* @4854432 constant */
    /* @4854436 add */
    /* @4854440 constant */
    /* @4854444 load */
    /* @4854452 cast */
    /* @4854456 load */
    /* @4854464 constant */
    /* @4854468 add */
    /* @4854472 call */
    GM_SITE(vm, 564, 4854472);
    v83 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v84 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4854480 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v83, v84, STR_REF(1039)));
    L_4854484: ;
    /* @4854484 load */
    /* @4854492 constant */
    /* @4854496 cmp */
    /* @4854500 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4854900;
    /* @4854504 constant */
    /* @4854508 cast */
    /* @4854512 call */
    GM_SITE(vm, 564, 4854512);
    /* @4854520 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4854524 constant */
    /* @4854532 cast */
    /* @4854536 call */
    GM_SITE(vm, 564, 4854536);
    /* @4854544 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4854548 string */
    /* @4854556 cast */
    /* @4854560 constant */
    /* @4854564 load */
    /* @4854572 cast */
    /* @4854576 load */
    /* @4854584 constant */
    /* @4854588 add */
    /* @4854592 constant */
    /* @4854596 load */
    /* @4854604 cast */
    /* @4854608 load */
    /* @4854616 constant */
    /* @4854620 add */
    /* @4854624 call */
    GM_SITE(vm, 564, 4854624);
    v85 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v86 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4854632 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v85, v86, STR_REF(1036)));
    /* @4854636 string */
    /* @4854644 cast */
    /* @4854648 constant */
    /* @4854652 load */
    /* @4854660 cast */
    /* @4854664 load */
    /* @4854672 constant */
    /* @4854676 add */
    /* @4854680 constant */
    /* @4854684 load */
    /* @4854692 cast */
    /* @4854696 load */
    /* @4854704 constant */
    /* @4854708 add */
    /* @4854712 call */
    GM_SITE(vm, 564, 4854712);
    v87 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v88 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4854720 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v87, v88, STR_REF(1037)));
    /* @4854724 string */
    /* @4854732 cast */
    /* @4854736 constant */
    /* @4854740 load */
    /* @4854748 cast */
    /* @4854752 load */
    /* @4854760 constant */
    /* @4854764 add */
    /* @4854768 constant */
    /* @4854772 load */
    /* @4854780 cast */
    /* @4854784 load */
    /* @4854792 constant */
    /* @4854796 add */
    /* @4854800 call */
    GM_SITE(vm, 564, 4854800);
    v89 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v90 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4854808 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v89, v90, STR_REF(1038)));
    /* @4854812 string */
    /* @4854820 cast */
    /* @4854824 constant */
    /* @4854828 load */
    /* @4854836 cast */
    /* @4854840 load */
    /* @4854848 constant */
    /* @4854852 add */
    /* @4854856 constant */
    /* @4854860 load */
    /* @4854868 cast */
    /* @4854872 load */
    /* @4854880 constant */
    /* @4854884 add */
    /* @4854888 call */
    GM_SITE(vm, 564, 4854888);
    v91 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v92 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4854896 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v91, v92, STR_REF(1039)));
    L_4854900: ;
    /* @4854900 load */
    /* @4854908 constant */
    /* @4854912 cmp */
    /* @4854916 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4855316;
    /* @4854920 constant */
    /* @4854924 cast */
    /* @4854928 call */
    GM_SITE(vm, 564, 4854928);
    /* @4854936 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4854940 constant */
    /* @4854948 cast */
    /* @4854952 call */
    GM_SITE(vm, 564, 4854952);
    /* @4854960 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4854964 string */
    /* @4854972 cast */
    /* @4854976 constant */
    /* @4854980 load */
    /* @4854988 cast */
    /* @4854992 load */
    /* @4855000 constant */
    /* @4855004 add */
    /* @4855008 constant */
    /* @4855012 load */
    /* @4855020 cast */
    /* @4855024 load */
    /* @4855032 constant */
    /* @4855036 add */
    /* @4855040 call */
    GM_SITE(vm, 564, 4855040);
    v93 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v94 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4855048 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v93, v94, STR_REF(1036)));
    /* @4855052 string */
    /* @4855060 cast */
    /* @4855064 constant */
    /* @4855068 load */
    /* @4855076 cast */
    /* @4855080 load */
    /* @4855088 constant */
    /* @4855092 add */
    /* @4855096 constant */
    /* @4855100 load */
    /* @4855108 cast */
    /* @4855112 load */
    /* @4855120 constant */
    /* @4855124 add */
    /* @4855128 call */
    GM_SITE(vm, 564, 4855128);
    v95 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v96 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4855136 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v95, v96, STR_REF(1037)));
    /* @4855140 string */
    /* @4855148 cast */
    /* @4855152 constant */
    /* @4855156 load */
    /* @4855164 cast */
    /* @4855168 load */
    /* @4855176 constant */
    /* @4855180 add */
    /* @4855184 constant */
    /* @4855188 load */
    /* @4855196 cast */
    /* @4855200 load */
    /* @4855208 constant */
    /* @4855212 add */
    /* @4855216 call */
    GM_SITE(vm, 564, 4855216);
    v97 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v98 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4855224 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v97, v98, STR_REF(1038)));
    /* @4855228 string */
    /* @4855236 cast */
    /* @4855240 constant */
    /* @4855244 load */
    /* @4855252 cast */
    /* @4855256 load */
    /* @4855264 constant */
    /* @4855268 add */
    /* @4855272 constant */
    /* @4855276 load */
    /* @4855284 cast */
    /* @4855288 load */
    /* @4855296 constant */
    /* @4855300 add */
    /* @4855304 call */
    GM_SITE(vm, 564, 4855304);
    v99 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v100 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4855312 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v99, v100, STR_REF(1039)));
    L_4855316: ;
    /* @4855316 load */
    /* @4855324 constant */
    /* @4855328 cmp */
    /* @4855332 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4855732;
    /* @4855336 constant */
    /* @4855340 cast */
    /* @4855344 call */
    GM_SITE(vm, 564, 4855344);
    /* @4855352 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4855356 constant */
    /* @4855364 cast */
    /* @4855368 call */
    GM_SITE(vm, 564, 4855368);
    /* @4855376 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4855380 string */
    /* @4855388 cast */
    /* @4855392 constant */
    /* @4855396 load */
    /* @4855404 cast */
    /* @4855408 load */
    /* @4855416 constant */
    /* @4855420 add */
    /* @4855424 constant */
    /* @4855428 load */
    /* @4855436 cast */
    /* @4855440 load */
    /* @4855448 constant */
    /* @4855452 add */
    /* @4855456 call */
    GM_SITE(vm, 564, 4855456);
    v101 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v102 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4855464 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v101, v102, STR_REF(1036)));
    /* @4855468 string */
    /* @4855476 cast */
    /* @4855480 constant */
    /* @4855484 load */
    /* @4855492 cast */
    /* @4855496 load */
    /* @4855504 constant */
    /* @4855508 add */
    /* @4855512 constant */
    /* @4855516 load */
    /* @4855524 cast */
    /* @4855528 load */
    /* @4855536 constant */
    /* @4855540 add */
    /* @4855544 call */
    GM_SITE(vm, 564, 4855544);
    v103 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v104 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4855552 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v103, v104, STR_REF(1037)));
    /* @4855556 string */
    /* @4855564 cast */
    /* @4855568 constant */
    /* @4855572 load */
    /* @4855580 cast */
    /* @4855584 load */
    /* @4855592 constant */
    /* @4855596 add */
    /* @4855600 constant */
    /* @4855604 load */
    /* @4855612 cast */
    /* @4855616 load */
    /* @4855624 constant */
    /* @4855628 add */
    /* @4855632 call */
    GM_SITE(vm, 564, 4855632);
    v105 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v106 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4855640 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v105, v106, STR_REF(1038)));
    /* @4855644 string */
    /* @4855652 cast */
    /* @4855656 constant */
    /* @4855660 load */
    /* @4855668 cast */
    /* @4855672 load */
    /* @4855680 constant */
    /* @4855684 add */
    /* @4855688 constant */
    /* @4855692 load */
    /* @4855700 cast */
    /* @4855704 load */
    /* @4855712 constant */
    /* @4855716 add */
    /* @4855720 call */
    GM_SITE(vm, 564, 4855720);
    v107 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v108 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4855728 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v107, v108, STR_REF(1039)));
    L_4855732: ;
    /* @4855732 load */
    /* @4855740 constant */
    /* @4855744 cmp */
    /* @4855748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel3") == VAL(1)))) goto L_4857192;
    /* @4855752 load */
    /* @4855760 constant */
    /* @4855764 cmp */
    /* @4855768 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4855992;
    /* @4855772 constant */
    /* @4855776 cast */
    /* @4855780 call */
    GM_SITE(vm, 564, 4855780);
    /* @4855788 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4855792 constant */
    /* @4855800 cast */
    /* @4855804 call */
    GM_SITE(vm, 564, 4855804);
    /* @4855812 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4855816 string */
    /* @4855824 cast */
    /* @4855828 constant */
    /* @4855832 load */
    /* @4855840 cast */
    /* @4855844 load */
    /* @4855852 constant */
    /* @4855856 add */
    /* @4855860 constant */
    /* @4855864 load */
    /* @4855872 cast */
    /* @4855876 load */
    /* @4855884 constant */
    /* @4855888 add */
    /* @4855892 call */
    GM_SITE(vm, 564, 4855892);
    v109 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v110 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4855900 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v109, v110, STR_REF(1040)));
    /* @4855904 string */
    /* @4855912 cast */
    /* @4855916 constant */
    /* @4855920 load */
    /* @4855928 cast */
    /* @4855932 load */
    /* @4855940 constant */
    /* @4855944 add */
    /* @4855948 constant */
    /* @4855952 load */
    /* @4855960 cast */
    /* @4855964 load */
    /* @4855972 constant */
    /* @4855976 add */
    /* @4855980 call */
    GM_SITE(vm, 564, 4855980);
    v111 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v112 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4855988 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v111, v112, STR_REF(1041)));
    L_4855992: ;
    /* @4855992 load */
    /* @4856000 constant */
    /* @4856004 cmp */
    /* @4856008 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4856232;
    /* @4856012 constant */
    /* @4856016 cast */
    /* @4856020 call */
    GM_SITE(vm, 564, 4856020);
    /* @4856028 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4856032 constant */
    /* @4856040 cast */
    /* @4856044 call */
    GM_SITE(vm, 564, 4856044);
    /* @4856052 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4856056 string */
    /* @4856064 cast */
    /* @4856068 constant */
    /* @4856072 load */
    /* @4856080 cast */
    /* @4856084 load */
    /* @4856092 constant */
    /* @4856096 add */
    /* @4856100 constant */
    /* @4856104 load */
    /* @4856112 cast */
    /* @4856116 load */
    /* @4856124 constant */
    /* @4856128 add */
    /* @4856132 call */
    GM_SITE(vm, 564, 4856132);
    v113 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v114 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4856140 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v113, v114, STR_REF(1040)));
    /* @4856144 string */
    /* @4856152 cast */
    /* @4856156 constant */
    /* @4856160 load */
    /* @4856168 cast */
    /* @4856172 load */
    /* @4856180 constant */
    /* @4856184 add */
    /* @4856188 constant */
    /* @4856192 load */
    /* @4856200 cast */
    /* @4856204 load */
    /* @4856212 constant */
    /* @4856216 add */
    /* @4856220 call */
    GM_SITE(vm, 564, 4856220);
    v115 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v116 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4856228 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v115, v116, STR_REF(1041)));
    L_4856232: ;
    /* @4856232 load */
    /* @4856240 constant */
    /* @4856244 cmp */
    /* @4856248 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4856472;
    /* @4856252 constant */
    /* @4856256 cast */
    /* @4856260 call */
    GM_SITE(vm, 564, 4856260);
    /* @4856268 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4856272 constant */
    /* @4856280 cast */
    /* @4856284 call */
    GM_SITE(vm, 564, 4856284);
    /* @4856292 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4856296 string */
    /* @4856304 cast */
    /* @4856308 constant */
    /* @4856312 load */
    /* @4856320 cast */
    /* @4856324 load */
    /* @4856332 constant */
    /* @4856336 add */
    /* @4856340 constant */
    /* @4856344 load */
    /* @4856352 cast */
    /* @4856356 load */
    /* @4856364 constant */
    /* @4856368 add */
    /* @4856372 call */
    GM_SITE(vm, 564, 4856372);
    v117 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v118 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4856380 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v117, v118, STR_REF(1040)));
    /* @4856384 string */
    /* @4856392 cast */
    /* @4856396 constant */
    /* @4856400 load */
    /* @4856408 cast */
    /* @4856412 load */
    /* @4856420 constant */
    /* @4856424 add */
    /* @4856428 constant */
    /* @4856432 load */
    /* @4856440 cast */
    /* @4856444 load */
    /* @4856452 constant */
    /* @4856456 add */
    /* @4856460 call */
    GM_SITE(vm, 564, 4856460);
    v119 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v120 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4856468 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v119, v120, STR_REF(1041)));
    L_4856472: ;
    /* @4856472 load */
    /* @4856480 constant */
    /* @4856484 cmp */
    /* @4856488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4856712;
    /* @4856492 constant */
    /* @4856496 cast */
    /* @4856500 call */
    GM_SITE(vm, 564, 4856500);
    /* @4856508 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4856512 constant */
    /* @4856520 cast */
    /* @4856524 call */
    GM_SITE(vm, 564, 4856524);
    /* @4856532 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4856536 string */
    /* @4856544 cast */
    /* @4856548 constant */
    /* @4856552 load */
    /* @4856560 cast */
    /* @4856564 load */
    /* @4856572 constant */
    /* @4856576 add */
    /* @4856580 constant */
    /* @4856584 load */
    /* @4856592 cast */
    /* @4856596 load */
    /* @4856604 constant */
    /* @4856608 add */
    /* @4856612 call */
    GM_SITE(vm, 564, 4856612);
    v121 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v122 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4856620 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v121, v122, STR_REF(1040)));
    /* @4856624 string */
    /* @4856632 cast */
    /* @4856636 constant */
    /* @4856640 load */
    /* @4856648 cast */
    /* @4856652 load */
    /* @4856660 constant */
    /* @4856664 add */
    /* @4856668 constant */
    /* @4856672 load */
    /* @4856680 cast */
    /* @4856684 load */
    /* @4856692 constant */
    /* @4856696 add */
    /* @4856700 call */
    GM_SITE(vm, 564, 4856700);
    v123 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v124 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4856708 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v123, v124, STR_REF(1041)));
    L_4856712: ;
    /* @4856712 load */
    /* @4856720 constant */
    /* @4856724 cmp */
    /* @4856728 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4856952;
    /* @4856732 constant */
    /* @4856736 cast */
    /* @4856740 call */
    GM_SITE(vm, 564, 4856740);
    /* @4856748 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4856752 constant */
    /* @4856760 cast */
    /* @4856764 call */
    GM_SITE(vm, 564, 4856764);
    /* @4856772 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4856776 string */
    /* @4856784 cast */
    /* @4856788 constant */
    /* @4856792 load */
    /* @4856800 cast */
    /* @4856804 load */
    /* @4856812 constant */
    /* @4856816 add */
    /* @4856820 constant */
    /* @4856824 load */
    /* @4856832 cast */
    /* @4856836 load */
    /* @4856844 constant */
    /* @4856848 add */
    /* @4856852 call */
    GM_SITE(vm, 564, 4856852);
    v125 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v126 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4856860 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v125, v126, STR_REF(1040)));
    /* @4856864 string */
    /* @4856872 cast */
    /* @4856876 constant */
    /* @4856880 load */
    /* @4856888 cast */
    /* @4856892 load */
    /* @4856900 constant */
    /* @4856904 add */
    /* @4856908 constant */
    /* @4856912 load */
    /* @4856920 cast */
    /* @4856924 load */
    /* @4856932 constant */
    /* @4856936 add */
    /* @4856940 call */
    GM_SITE(vm, 564, 4856940);
    v127 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v128 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4856948 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v127, v128, STR_REF(1041)));
    L_4856952: ;
    /* @4856952 load */
    /* @4856960 constant */
    /* @4856964 cmp */
    /* @4856968 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4857192;
    /* @4856972 constant */
    /* @4856976 cast */
    /* @4856980 call */
    GM_SITE(vm, 564, 4856980);
    /* @4856988 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4856992 constant */
    /* @4857000 cast */
    /* @4857004 call */
    GM_SITE(vm, 564, 4857004);
    /* @4857012 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4857016 string */
    /* @4857024 cast */
    /* @4857028 constant */
    /* @4857032 load */
    /* @4857040 cast */
    /* @4857044 load */
    /* @4857052 constant */
    /* @4857056 add */
    /* @4857060 constant */
    /* @4857064 load */
    /* @4857072 cast */
    /* @4857076 load */
    /* @4857084 constant */
    /* @4857088 add */
    /* @4857092 call */
    GM_SITE(vm, 564, 4857092);
    v129 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v130 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4857100 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v129, v130, STR_REF(1040)));
    /* @4857104 string */
    /* @4857112 cast */
    /* @4857116 constant */
    /* @4857120 load */
    /* @4857128 cast */
    /* @4857132 load */
    /* @4857140 constant */
    /* @4857144 add */
    /* @4857148 constant */
    /* @4857152 load */
    /* @4857160 cast */
    /* @4857164 load */
    /* @4857172 constant */
    /* @4857176 add */
    /* @4857180 call */
    GM_SITE(vm, 564, 4857180);
    v131 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v132 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4857188 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v131, v132, STR_REF(1041)));
    L_4857192: ;
    /* @4857192 load */
    /* @4857200 constant */
    /* @4857204 cmp */
    /* @4857208 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel4") == VAL(1)))) goto L_4858652;
    /* @4857212 load */
    /* @4857220 constant */
    /* @4857224 cmp */
    /* @4857228 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4857452;
    /* @4857232 constant */
    /* @4857236 cast */
    /* @4857240 call */
    GM_SITE(vm, 564, 4857240);
    /* @4857248 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4857252 constant */
    /* @4857260 cast */
    /* @4857264 call */
    GM_SITE(vm, 564, 4857264);
    /* @4857272 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4857276 string */
    /* @4857284 cast */
    /* @4857288 constant */
    /* @4857292 load */
    /* @4857300 cast */
    /* @4857304 load */
    /* @4857312 constant */
    /* @4857316 add */
    /* @4857320 constant */
    /* @4857324 load */
    /* @4857332 cast */
    /* @4857336 load */
    /* @4857344 constant */
    /* @4857348 add */
    /* @4857352 call */
    GM_SITE(vm, 564, 4857352);
    v133 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v134 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4857360 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v133, v134, STR_REF(1042)));
    /* @4857364 string */
    /* @4857372 cast */
    /* @4857376 constant */
    /* @4857380 load */
    /* @4857388 cast */
    /* @4857392 load */
    /* @4857400 constant */
    /* @4857404 add */
    /* @4857408 constant */
    /* @4857412 load */
    /* @4857420 cast */
    /* @4857424 load */
    /* @4857432 constant */
    /* @4857436 add */
    /* @4857440 call */
    GM_SITE(vm, 564, 4857440);
    v135 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v136 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4857448 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v135, v136, STR_REF(1043)));
    L_4857452: ;
    /* @4857452 load */
    /* @4857460 constant */
    /* @4857464 cmp */
    /* @4857468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4857692;
    /* @4857472 constant */
    /* @4857476 cast */
    /* @4857480 call */
    GM_SITE(vm, 564, 4857480);
    /* @4857488 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4857492 constant */
    /* @4857500 cast */
    /* @4857504 call */
    GM_SITE(vm, 564, 4857504);
    /* @4857512 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4857516 string */
    /* @4857524 cast */
    /* @4857528 constant */
    /* @4857532 load */
    /* @4857540 cast */
    /* @4857544 load */
    /* @4857552 constant */
    /* @4857556 add */
    /* @4857560 constant */
    /* @4857564 load */
    /* @4857572 cast */
    /* @4857576 load */
    /* @4857584 constant */
    /* @4857588 add */
    /* @4857592 call */
    GM_SITE(vm, 564, 4857592);
    v137 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v138 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4857600 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v137, v138, STR_REF(1042)));
    /* @4857604 string */
    /* @4857612 cast */
    /* @4857616 constant */
    /* @4857620 load */
    /* @4857628 cast */
    /* @4857632 load */
    /* @4857640 constant */
    /* @4857644 add */
    /* @4857648 constant */
    /* @4857652 load */
    /* @4857660 cast */
    /* @4857664 load */
    /* @4857672 constant */
    /* @4857676 add */
    /* @4857680 call */
    GM_SITE(vm, 564, 4857680);
    v139 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v140 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4857688 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v139, v140, STR_REF(1043)));
    L_4857692: ;
    /* @4857692 load */
    /* @4857700 constant */
    /* @4857704 cmp */
    /* @4857708 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4857932;
    /* @4857712 constant */
    /* @4857716 cast */
    /* @4857720 call */
    GM_SITE(vm, 564, 4857720);
    /* @4857728 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4857732 constant */
    /* @4857740 cast */
    /* @4857744 call */
    GM_SITE(vm, 564, 4857744);
    /* @4857752 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4857756 string */
    /* @4857764 cast */
    /* @4857768 constant */
    /* @4857772 load */
    /* @4857780 cast */
    /* @4857784 load */
    /* @4857792 constant */
    /* @4857796 add */
    /* @4857800 constant */
    /* @4857804 load */
    /* @4857812 cast */
    /* @4857816 load */
    /* @4857824 constant */
    /* @4857828 add */
    /* @4857832 call */
    GM_SITE(vm, 564, 4857832);
    v141 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v142 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4857840 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v141, v142, STR_REF(1042)));
    /* @4857844 string */
    /* @4857852 cast */
    /* @4857856 constant */
    /* @4857860 load */
    /* @4857868 cast */
    /* @4857872 load */
    /* @4857880 constant */
    /* @4857884 add */
    /* @4857888 constant */
    /* @4857892 load */
    /* @4857900 cast */
    /* @4857904 load */
    /* @4857912 constant */
    /* @4857916 add */
    /* @4857920 call */
    GM_SITE(vm, 564, 4857920);
    v143 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v144 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4857928 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v143, v144, STR_REF(1043)));
    L_4857932: ;
    /* @4857932 load */
    /* @4857940 constant */
    /* @4857944 cmp */
    /* @4857948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4858172;
    /* @4857952 constant */
    /* @4857956 cast */
    /* @4857960 call */
    GM_SITE(vm, 564, 4857960);
    /* @4857968 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4857972 constant */
    /* @4857980 cast */
    /* @4857984 call */
    GM_SITE(vm, 564, 4857984);
    /* @4857992 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4857996 string */
    /* @4858004 cast */
    /* @4858008 constant */
    /* @4858012 load */
    /* @4858020 cast */
    /* @4858024 load */
    /* @4858032 constant */
    /* @4858036 add */
    /* @4858040 constant */
    /* @4858044 load */
    /* @4858052 cast */
    /* @4858056 load */
    /* @4858064 constant */
    /* @4858068 add */
    /* @4858072 call */
    GM_SITE(vm, 564, 4858072);
    v145 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v146 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4858080 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v145, v146, STR_REF(1042)));
    /* @4858084 string */
    /* @4858092 cast */
    /* @4858096 constant */
    /* @4858100 load */
    /* @4858108 cast */
    /* @4858112 load */
    /* @4858120 constant */
    /* @4858124 add */
    /* @4858128 constant */
    /* @4858132 load */
    /* @4858140 cast */
    /* @4858144 load */
    /* @4858152 constant */
    /* @4858156 add */
    /* @4858160 call */
    GM_SITE(vm, 564, 4858160);
    v147 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v148 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4858168 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v147, v148, STR_REF(1043)));
    L_4858172: ;
    /* @4858172 load */
    /* @4858180 constant */
    /* @4858184 cmp */
    /* @4858188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4858412;
    /* @4858192 constant */
    /* @4858196 cast */
    /* @4858200 call */
    GM_SITE(vm, 564, 4858200);
    /* @4858208 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4858212 constant */
    /* @4858220 cast */
    /* @4858224 call */
    GM_SITE(vm, 564, 4858224);
    /* @4858232 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4858236 string */
    /* @4858244 cast */
    /* @4858248 constant */
    /* @4858252 load */
    /* @4858260 cast */
    /* @4858264 load */
    /* @4858272 constant */
    /* @4858276 add */
    /* @4858280 constant */
    /* @4858284 load */
    /* @4858292 cast */
    /* @4858296 load */
    /* @4858304 constant */
    /* @4858308 add */
    /* @4858312 call */
    GM_SITE(vm, 564, 4858312);
    v149 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v150 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4858320 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v149, v150, STR_REF(1042)));
    /* @4858324 string */
    /* @4858332 cast */
    /* @4858336 constant */
    /* @4858340 load */
    /* @4858348 cast */
    /* @4858352 load */
    /* @4858360 constant */
    /* @4858364 add */
    /* @4858368 constant */
    /* @4858372 load */
    /* @4858380 cast */
    /* @4858384 load */
    /* @4858392 constant */
    /* @4858396 add */
    /* @4858400 call */
    GM_SITE(vm, 564, 4858400);
    v151 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v152 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4858408 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v151, v152, STR_REF(1043)));
    L_4858412: ;
    /* @4858412 load */
    /* @4858420 constant */
    /* @4858424 cmp */
    /* @4858428 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4858652;
    /* @4858432 constant */
    /* @4858436 cast */
    /* @4858440 call */
    GM_SITE(vm, 564, 4858440);
    /* @4858448 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4858452 constant */
    /* @4858460 cast */
    /* @4858464 call */
    GM_SITE(vm, 564, 4858464);
    /* @4858472 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4858476 string */
    /* @4858484 cast */
    /* @4858488 constant */
    /* @4858492 load */
    /* @4858500 cast */
    /* @4858504 load */
    /* @4858512 constant */
    /* @4858516 add */
    /* @4858520 constant */
    /* @4858524 load */
    /* @4858532 cast */
    /* @4858536 load */
    /* @4858544 constant */
    /* @4858548 add */
    /* @4858552 call */
    GM_SITE(vm, 564, 4858552);
    v153 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v154 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4858560 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v153, v154, STR_REF(1042)));
    /* @4858564 string */
    /* @4858572 cast */
    /* @4858576 constant */
    /* @4858580 load */
    /* @4858588 cast */
    /* @4858592 load */
    /* @4858600 constant */
    /* @4858604 add */
    /* @4858608 constant */
    /* @4858612 load */
    /* @4858620 cast */
    /* @4858624 load */
    /* @4858632 constant */
    /* @4858636 add */
    /* @4858640 call */
    GM_SITE(vm, 564, 4858640);
    v155 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v156 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4858648 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v155, v156, STR_REF(1043)));
    L_4858652: ;
    /* @4858652 load */
    /* @4858660 constant */
    /* @4858664 cmp */
    /* @4858668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel5") == VAL(1)))) goto L_4860112;
    /* @4858672 load */
    /* @4858680 constant */
    /* @4858684 cmp */
    /* @4858688 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4858912;
    /* @4858692 constant */
    /* @4858696 cast */
    /* @4858700 call */
    GM_SITE(vm, 564, 4858700);
    /* @4858708 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4858712 constant */
    /* @4858720 cast */
    /* @4858724 call */
    GM_SITE(vm, 564, 4858724);
    /* @4858732 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4858736 string */
    /* @4858744 cast */
    /* @4858748 constant */
    /* @4858752 load */
    /* @4858760 cast */
    /* @4858764 load */
    /* @4858772 constant */
    /* @4858776 add */
    /* @4858780 constant */
    /* @4858784 load */
    /* @4858792 cast */
    /* @4858796 load */
    /* @4858804 constant */
    /* @4858808 add */
    /* @4858812 call */
    GM_SITE(vm, 564, 4858812);
    v157 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v158 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4858820 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v157, v158, STR_REF(1044)));
    /* @4858824 string */
    /* @4858832 cast */
    /* @4858836 constant */
    /* @4858840 load */
    /* @4858848 cast */
    /* @4858852 load */
    /* @4858860 constant */
    /* @4858864 add */
    /* @4858868 constant */
    /* @4858872 load */
    /* @4858880 cast */
    /* @4858884 load */
    /* @4858892 constant */
    /* @4858896 add */
    /* @4858900 call */
    GM_SITE(vm, 564, 4858900);
    v159 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v160 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4858908 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v159, v160, STR_REF(1045)));
    L_4858912: ;
    /* @4858912 load */
    /* @4858920 constant */
    /* @4858924 cmp */
    /* @4858928 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4859152;
    /* @4858932 constant */
    /* @4858936 cast */
    /* @4858940 call */
    GM_SITE(vm, 564, 4858940);
    /* @4858948 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4858952 constant */
    /* @4858960 cast */
    /* @4858964 call */
    GM_SITE(vm, 564, 4858964);
    /* @4858972 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4858976 string */
    /* @4858984 cast */
    /* @4858988 constant */
    /* @4858992 load */
    /* @4859000 cast */
    /* @4859004 load */
    /* @4859012 constant */
    /* @4859016 add */
    /* @4859020 constant */
    /* @4859024 load */
    /* @4859032 cast */
    /* @4859036 load */
    /* @4859044 constant */
    /* @4859048 add */
    /* @4859052 call */
    GM_SITE(vm, 564, 4859052);
    v161 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v162 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    /* @4859060 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v161, v162, STR_REF(1044)));
    /* @4859064 string */
    /* @4859072 cast */
    /* @4859076 constant */
    /* @4859080 load */
    /* @4859088 cast */
    /* @4859092 load */
    /* @4859100 constant */
    /* @4859104 add */
    /* @4859108 constant */
    /* @4859112 load */
    /* @4859120 cast */
    /* @4859124 load */
    /* @4859132 constant */
    /* @4859136 add */
    /* @4859140 call */
    GM_SITE(vm, 564, 4859140);
    v163 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v164 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(140));
    /* @4859148 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v163, v164, STR_REF(1045)));
    L_4859152: ;
    /* @4859152 load */
    /* @4859160 constant */
    /* @4859164 cmp */
    /* @4859168 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4859392;
    /* @4859172 constant */
    /* @4859176 cast */
    /* @4859180 call */
    GM_SITE(vm, 564, 4859180);
    /* @4859188 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4859192 constant */
    /* @4859200 cast */
    /* @4859204 call */
    GM_SITE(vm, 564, 4859204);
    /* @4859212 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4859216 string */
    /* @4859224 cast */
    /* @4859228 constant */
    /* @4859232 load */
    /* @4859240 cast */
    /* @4859244 load */
    /* @4859252 constant */
    /* @4859256 add */
    /* @4859260 constant */
    /* @4859264 load */
    /* @4859272 cast */
    /* @4859276 load */
    /* @4859284 constant */
    /* @4859288 add */
    /* @4859292 call */
    GM_SITE(vm, 564, 4859292);
    v165 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    v166 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4859300 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v165, v166, STR_REF(1044)));
    /* @4859304 string */
    /* @4859312 cast */
    /* @4859316 constant */
    /* @4859320 load */
    /* @4859328 cast */
    /* @4859332 load */
    /* @4859340 constant */
    /* @4859344 add */
    /* @4859348 constant */
    /* @4859352 load */
    /* @4859360 cast */
    /* @4859364 load */
    /* @4859372 constant */
    /* @4859376 add */
    /* @4859380 call */
    GM_SITE(vm, 564, 4859380);
    v167 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    v168 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4859388 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v167, v168, STR_REF(1045)));
    L_4859392: ;
    /* @4859392 load */
    /* @4859400 constant */
    /* @4859404 cmp */
    /* @4859408 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4859632;
    /* @4859412 constant */
    /* @4859416 cast */
    /* @4859420 call */
    GM_SITE(vm, 564, 4859420);
    /* @4859428 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4859432 constant */
    /* @4859440 cast */
    /* @4859444 call */
    GM_SITE(vm, 564, 4859444);
    /* @4859452 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4859456 string */
    /* @4859464 cast */
    /* @4859468 constant */
    /* @4859472 load */
    /* @4859480 cast */
    /* @4859484 load */
    /* @4859492 constant */
    /* @4859496 add */
    /* @4859500 constant */
    /* @4859504 load */
    /* @4859512 cast */
    /* @4859516 load */
    /* @4859524 constant */
    /* @4859528 add */
    /* @4859532 call */
    GM_SITE(vm, 564, 4859532);
    v169 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    v170 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4859540 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v169, v170, STR_REF(1044)));
    /* @4859544 string */
    /* @4859552 cast */
    /* @4859556 constant */
    /* @4859560 load */
    /* @4859568 cast */
    /* @4859572 load */
    /* @4859580 constant */
    /* @4859584 add */
    /* @4859588 constant */
    /* @4859592 load */
    /* @4859600 cast */
    /* @4859604 load */
    /* @4859612 constant */
    /* @4859616 add */
    /* @4859620 call */
    GM_SITE(vm, 564, 4859620);
    v171 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    v172 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4859628 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v171, v172, STR_REF(1045)));
    L_4859632: ;
    /* @4859632 load */
    /* @4859640 constant */
    /* @4859644 cmp */
    /* @4859648 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4859872;
    /* @4859652 constant */
    /* @4859656 cast */
    /* @4859660 call */
    GM_SITE(vm, 564, 4859660);
    /* @4859668 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4859672 constant */
    /* @4859680 cast */
    /* @4859684 call */
    GM_SITE(vm, 564, 4859684);
    /* @4859692 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4859696 string */
    /* @4859704 cast */
    /* @4859708 constant */
    /* @4859712 load */
    /* @4859720 cast */
    /* @4859724 load */
    /* @4859732 constant */
    /* @4859736 add */
    /* @4859740 constant */
    /* @4859744 load */
    /* @4859752 cast */
    /* @4859756 load */
    /* @4859764 constant */
    /* @4859768 add */
    /* @4859772 call */
    GM_SITE(vm, 564, 4859772);
    v173 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v174 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4859780 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v173, v174, STR_REF(1044)));
    /* @4859784 string */
    /* @4859792 cast */
    /* @4859796 constant */
    /* @4859800 load */
    /* @4859808 cast */
    /* @4859812 load */
    /* @4859820 constant */
    /* @4859824 add */
    /* @4859828 constant */
    /* @4859832 load */
    /* @4859840 cast */
    /* @4859844 load */
    /* @4859852 constant */
    /* @4859856 add */
    /* @4859860 call */
    GM_SITE(vm, 564, 4859860);
    v175 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v176 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4859868 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v175, v176, STR_REF(1045)));
    L_4859872: ;
    /* @4859872 load */
    /* @4859880 constant */
    /* @4859884 cmp */
    /* @4859888 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4860112;
    /* @4859892 constant */
    /* @4859896 cast */
    /* @4859900 call */
    GM_SITE(vm, 564, 4859900);
    /* @4859908 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4859912 constant */
    /* @4859920 cast */
    /* @4859924 call */
    GM_SITE(vm, 564, 4859924);
    /* @4859932 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4859936 string */
    /* @4859944 cast */
    /* @4859948 constant */
    /* @4859952 load */
    /* @4859960 cast */
    /* @4859964 load */
    /* @4859972 constant */
    /* @4859976 add */
    /* @4859980 constant */
    /* @4859984 load */
    /* @4859992 cast */
    /* @4859996 load */
    /* @4860004 constant */
    /* @4860008 add */
    /* @4860012 call */
    GM_SITE(vm, 564, 4860012);
    v177 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v178 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4860020 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v177, v178, STR_REF(1044)));
    /* @4860024 string */
    /* @4860032 cast */
    /* @4860036 constant */
    /* @4860040 load */
    /* @4860048 cast */
    /* @4860052 load */
    /* @4860060 constant */
    /* @4860064 add */
    /* @4860068 constant */
    /* @4860072 load */
    /* @4860080 cast */
    /* @4860084 load */
    /* @4860092 constant */
    /* @4860096 add */
    /* @4860100 call */
    GM_SITE(vm, 564, 4860100);
    v179 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v180 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4860108 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v179, v180, STR_REF(1045)));
    L_4860112: ;
    /* @4860112 load */
    /* @4860120 constant */
    /* @4860124 cmp */
    /* @4860128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel6") == VAL(1)))) goto L_4861572;
    /* @4860132 load */
    /* @4860140 constant */
    /* @4860144 cmp */
    /* @4860148 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4860372;
    /* @4860152 constant */
    /* @4860156 cast */
    /* @4860160 call */
    GM_SITE(vm, 564, 4860160);
    /* @4860168 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4860172 constant */
    /* @4860180 cast */
    /* @4860184 call */
    GM_SITE(vm, 564, 4860184);
    /* @4860192 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4860196 string */
    /* @4860204 cast */
    /* @4860208 constant */
    /* @4860212 load */
    /* @4860220 cast */
    /* @4860224 load */
    /* @4860232 constant */
    /* @4860236 add */
    /* @4860240 constant */
    /* @4860244 load */
    /* @4860252 cast */
    /* @4860256 load */
    /* @4860264 constant */
    /* @4860268 add */
    /* @4860272 call */
    GM_SITE(vm, 564, 4860272);
    v181 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v182 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4860280 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v181, v182, STR_REF(1046)));
    /* @4860284 string */
    /* @4860292 cast */
    /* @4860296 constant */
    /* @4860300 load */
    /* @4860308 cast */
    /* @4860312 load */
    /* @4860320 constant */
    /* @4860324 add */
    /* @4860328 constant */
    /* @4860332 load */
    /* @4860340 cast */
    /* @4860344 load */
    /* @4860352 constant */
    /* @4860356 add */
    /* @4860360 call */
    GM_SITE(vm, 564, 4860360);
    v183 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v184 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4860368 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v183, v184, STR_REF(1047)));
    L_4860372: ;
    /* @4860372 load */
    /* @4860380 constant */
    /* @4860384 cmp */
    /* @4860388 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4860612;
    /* @4860392 constant */
    /* @4860396 cast */
    /* @4860400 call */
    GM_SITE(vm, 564, 4860400);
    /* @4860408 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4860412 constant */
    /* @4860420 cast */
    /* @4860424 call */
    GM_SITE(vm, 564, 4860424);
    /* @4860432 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4860436 string */
    /* @4860444 cast */
    /* @4860448 constant */
    /* @4860452 load */
    /* @4860460 cast */
    /* @4860464 load */
    /* @4860472 constant */
    /* @4860476 add */
    /* @4860480 constant */
    /* @4860484 load */
    /* @4860492 cast */
    /* @4860496 load */
    /* @4860504 constant */
    /* @4860508 add */
    /* @4860512 call */
    GM_SITE(vm, 564, 4860512);
    v185 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v186 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4860520 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v185, v186, STR_REF(1046)));
    /* @4860524 string */
    /* @4860532 cast */
    /* @4860536 constant */
    /* @4860540 load */
    /* @4860548 cast */
    /* @4860552 load */
    /* @4860560 constant */
    /* @4860564 add */
    /* @4860568 constant */
    /* @4860572 load */
    /* @4860580 cast */
    /* @4860584 load */
    /* @4860592 constant */
    /* @4860596 add */
    /* @4860600 call */
    GM_SITE(vm, 564, 4860600);
    v187 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v188 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4860608 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v187, v188, STR_REF(1047)));
    L_4860612: ;
    /* @4860612 load */
    /* @4860620 constant */
    /* @4860624 cmp */
    /* @4860628 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4860852;
    /* @4860632 constant */
    /* @4860636 cast */
    /* @4860640 call */
    GM_SITE(vm, 564, 4860640);
    /* @4860648 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4860652 constant */
    /* @4860660 cast */
    /* @4860664 call */
    GM_SITE(vm, 564, 4860664);
    /* @4860672 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4860676 string */
    /* @4860684 cast */
    /* @4860688 constant */
    /* @4860692 load */
    /* @4860700 cast */
    /* @4860704 load */
    /* @4860712 constant */
    /* @4860716 add */
    /* @4860720 constant */
    /* @4860724 load */
    /* @4860732 cast */
    /* @4860736 load */
    /* @4860744 constant */
    /* @4860748 add */
    /* @4860752 call */
    GM_SITE(vm, 564, 4860752);
    v189 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v190 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4860760 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v189, v190, STR_REF(1046)));
    /* @4860764 string */
    /* @4860772 cast */
    /* @4860776 constant */
    /* @4860780 load */
    /* @4860788 cast */
    /* @4860792 load */
    /* @4860800 constant */
    /* @4860804 add */
    /* @4860808 constant */
    /* @4860812 load */
    /* @4860820 cast */
    /* @4860824 load */
    /* @4860832 constant */
    /* @4860836 add */
    /* @4860840 call */
    GM_SITE(vm, 564, 4860840);
    v191 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v192 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4860848 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v191, v192, STR_REF(1047)));
    L_4860852: ;
    /* @4860852 load */
    /* @4860860 constant */
    /* @4860864 cmp */
    /* @4860868 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4861092;
    /* @4860872 constant */
    /* @4860876 cast */
    /* @4860880 call */
    GM_SITE(vm, 564, 4860880);
    /* @4860888 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4860892 constant */
    /* @4860900 cast */
    /* @4860904 call */
    GM_SITE(vm, 564, 4860904);
    /* @4860912 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4860916 string */
    /* @4860924 cast */
    /* @4860928 constant */
    /* @4860932 load */
    /* @4860940 cast */
    /* @4860944 load */
    /* @4860952 constant */
    /* @4860956 add */
    /* @4860960 constant */
    /* @4860964 load */
    /* @4860972 cast */
    /* @4860976 load */
    /* @4860984 constant */
    /* @4860988 add */
    /* @4860992 call */
    GM_SITE(vm, 564, 4860992);
    v193 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v194 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4861000 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v193, v194, STR_REF(1046)));
    /* @4861004 string */
    /* @4861012 cast */
    /* @4861016 constant */
    /* @4861020 load */
    /* @4861028 cast */
    /* @4861032 load */
    /* @4861040 constant */
    /* @4861044 add */
    /* @4861048 constant */
    /* @4861052 load */
    /* @4861060 cast */
    /* @4861064 load */
    /* @4861072 constant */
    /* @4861076 add */
    /* @4861080 call */
    GM_SITE(vm, 564, 4861080);
    v195 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v196 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4861088 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v195, v196, STR_REF(1047)));
    L_4861092: ;
    /* @4861092 load */
    /* @4861100 constant */
    /* @4861104 cmp */
    /* @4861108 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4861332;
    /* @4861112 constant */
    /* @4861116 cast */
    /* @4861120 call */
    GM_SITE(vm, 564, 4861120);
    /* @4861128 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4861132 constant */
    /* @4861140 cast */
    /* @4861144 call */
    GM_SITE(vm, 564, 4861144);
    /* @4861152 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4861156 string */
    /* @4861164 cast */
    /* @4861168 constant */
    /* @4861172 load */
    /* @4861180 cast */
    /* @4861184 load */
    /* @4861192 constant */
    /* @4861196 add */
    /* @4861200 constant */
    /* @4861204 load */
    /* @4861212 cast */
    /* @4861216 load */
    /* @4861224 constant */
    /* @4861228 add */
    /* @4861232 call */
    GM_SITE(vm, 564, 4861232);
    v197 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v198 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4861240 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v197, v198, STR_REF(1046)));
    /* @4861244 string */
    /* @4861252 cast */
    /* @4861256 constant */
    /* @4861260 load */
    /* @4861268 cast */
    /* @4861272 load */
    /* @4861280 constant */
    /* @4861284 add */
    /* @4861288 constant */
    /* @4861292 load */
    /* @4861300 cast */
    /* @4861304 load */
    /* @4861312 constant */
    /* @4861316 add */
    /* @4861320 call */
    GM_SITE(vm, 564, 4861320);
    v199 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v200 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4861328 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v199, v200, STR_REF(1047)));
    L_4861332: ;
    /* @4861332 load */
    /* @4861340 constant */
    /* @4861344 cmp */
    /* @4861348 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4861572;
    /* @4861352 constant */
    /* @4861356 cast */
    /* @4861360 call */
    GM_SITE(vm, 564, 4861360);
    /* @4861368 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4861372 constant */
    /* @4861380 cast */
    /* @4861384 call */
    GM_SITE(vm, 564, 4861384);
    /* @4861392 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4861396 string */
    /* @4861404 cast */
    /* @4861408 constant */
    /* @4861412 load */
    /* @4861420 cast */
    /* @4861424 load */
    /* @4861432 constant */
    /* @4861436 add */
    /* @4861440 constant */
    /* @4861444 load */
    /* @4861452 cast */
    /* @4861456 load */
    /* @4861464 constant */
    /* @4861468 add */
    /* @4861472 call */
    GM_SITE(vm, 564, 4861472);
    v201 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v202 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4861480 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v201, v202, STR_REF(1046)));
    /* @4861484 string */
    /* @4861492 cast */
    /* @4861496 constant */
    /* @4861500 load */
    /* @4861508 cast */
    /* @4861512 load */
    /* @4861520 constant */
    /* @4861524 add */
    /* @4861528 constant */
    /* @4861532 load */
    /* @4861540 cast */
    /* @4861544 load */
    /* @4861552 constant */
    /* @4861556 add */
    /* @4861560 call */
    GM_SITE(vm, 564, 4861560);
    v203 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v204 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4861568 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v203, v204, STR_REF(1047)));
    L_4861572: ;
    /* @4861572 load */
    /* @4861580 constant */
    /* @4861584 cmp */
    /* @4861588 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4861624;
    /* @4861592 constant */
    /* @4861596 cast */
    /* @4861600 constant */
    /* @4861604 cast */
    /* @4861608 call */
    GM_SITE(vm, 564, 4861608);
    /* @4861616 cast */
    /* @4861620 b */
    v205 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, VAL(0), VAL(1)));
    p4861628_0 = v205;
    goto L_4861628;
    L_4861624: ;
    /* @4861624 constant */
    p4861628_0 = VAL(0);
    L_4861628: ;
    /* @4861628 bf */
    if (!TRUTH(p4861628_0)) goto L_4861644;
    /* @4861632 call */
    GM_SITE(vm, 564, 4861632);
    /* @4861640 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4861644: ;
    return;
}
