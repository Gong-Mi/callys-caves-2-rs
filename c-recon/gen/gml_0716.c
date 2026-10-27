/* generated from CODE 716 (gml_Object_obj_endmusic_Draw_0), source start 5022980, end 5032832. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0716(GmVM* vm) {
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
    Val v205;
    Val v206;
    Val v207;
    Val v208;
    Val v209;
    Val v210;
    Val v211;
    Val v212;
    Val v213;
    Val v214;
    Val v215;
    Val v216;
    /* @5022980 load */
    /* @5022988 constant */
    /* @5022992 cmp */
    /* @5022996 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawcredit1") == VAL(1)))) goto L_5023616;
    /* @5023000 constant */
    /* @5023004 cast */
    /* @5023008 call */
    GM_SITE(vm, 716, 5023008);
    /* @5023016 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @5023020 constant */
    /* @5023028 cast */
    /* @5023032 call */
    GM_SITE(vm, 716, 5023032);
    /* @5023040 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5023044 load */
    /* @5023052 constant */
    /* @5023056 cmp */
    /* @5023060 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_5023140;
    /* @5023064 string */
    /* @5023072 cast */
    /* @5023076 constant */
    /* @5023080 constant */
    /* @5023084 load */
    /* @5023092 constant */
    /* @5023096 add */
    /* @5023100 constant */
    /* @5023104 constant */
    /* @5023108 load */
    /* @5023116 constant */
    /* @5023120 add */
    /* @5023124 call */
    GM_SITE(vm, 716, 5023124);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(40));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(160));
    /* @5023132 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, v2, STR_REF(1179)));
    /* @5023136 b */
    goto L_5023616;
    L_5023140: ;
    /* @5023140 load */
    /* @5023148 constant */
    /* @5023152 cmp */
    /* @5023156 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_5023236;
    /* @5023160 string */
    /* @5023168 cast */
    /* @5023172 constant */
    /* @5023176 constant */
    /* @5023180 load */
    /* @5023188 constant */
    /* @5023192 add */
    /* @5023196 constant */
    /* @5023200 constant */
    /* @5023204 load */
    /* @5023212 constant */
    /* @5023216 add */
    /* @5023220 call */
    GM_SITE(vm, 716, 5023220);
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(10));
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(160));
    /* @5023228 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v3, v4, STR_REF(1179)));
    /* @5023232 b */
    goto L_5023616;
    L_5023236: ;
    /* @5023236 load */
    /* @5023244 constant */
    /* @5023248 cmp */
    /* @5023252 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_5023332;
    /* @5023256 string */
    /* @5023264 cast */
    /* @5023268 constant */
    /* @5023272 constant */
    /* @5023276 load */
    /* @5023284 constant */
    /* @5023288 add */
    /* @5023292 constant */
    /* @5023296 constant */
    /* @5023300 load */
    /* @5023308 constant */
    /* @5023312 add */
    /* @5023316 call */
    GM_SITE(vm, 716, 5023316);
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(115));
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(50));
    /* @5023324 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v5, v6, STR_REF(1179)));
    /* @5023328 b */
    goto L_5023616;
    L_5023332: ;
    /* @5023332 load */
    /* @5023340 constant */
    /* @5023344 cmp */
    /* @5023348 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_5023428;
    /* @5023352 string */
    /* @5023360 cast */
    /* @5023364 constant */
    /* @5023368 constant */
    /* @5023372 load */
    /* @5023380 constant */
    /* @5023384 add */
    /* @5023388 constant */
    /* @5023392 constant */
    /* @5023396 load */
    /* @5023404 constant */
    /* @5023408 add */
    /* @5023412 call */
    GM_SITE(vm, 716, 5023412);
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(115));
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(50));
    /* @5023420 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v7, v8, STR_REF(1179)));
    /* @5023424 b */
    goto L_5023616;
    L_5023428: ;
    /* @5023428 load */
    /* @5023436 constant */
    /* @5023440 cmp */
    /* @5023444 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_5023524;
    /* @5023448 string */
    /* @5023456 cast */
    /* @5023460 constant */
    /* @5023464 constant */
    /* @5023468 load */
    /* @5023476 constant */
    /* @5023480 add */
    /* @5023484 constant */
    /* @5023488 constant */
    /* @5023492 load */
    /* @5023500 constant */
    /* @5023504 add */
    /* @5023508 call */
    GM_SITE(vm, 716, 5023508);
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(40));
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(160));
    /* @5023516 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v9, v10, STR_REF(1179)));
    /* @5023520 b */
    goto L_5023616;
    L_5023524: ;
    /* @5023524 load */
    /* @5023532 constant */
    /* @5023536 cmp */
    /* @5023540 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_5023616;
    /* @5023544 string */
    /* @5023552 cast */
    /* @5023556 constant */
    /* @5023560 constant */
    /* @5023564 load */
    /* @5023572 constant */
    /* @5023576 add */
    /* @5023580 constant */
    /* @5023584 constant */
    /* @5023588 load */
    /* @5023596 constant */
    /* @5023600 add */
    /* @5023604 call */
    GM_SITE(vm, 716, 5023604);
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(40));
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(160));
    /* @5023612 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v11, v12, STR_REF(1179)));
    L_5023616: ;
    /* @5023616 load */
    /* @5023624 constant */
    /* @5023628 cmp */
    /* @5023632 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawcredit2") == VAL(1)))) goto L_5024252;
    /* @5023636 constant */
    /* @5023640 cast */
    /* @5023644 call */
    GM_SITE(vm, 716, 5023644);
    /* @5023652 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @5023656 constant */
    /* @5023664 cast */
    /* @5023668 call */
    GM_SITE(vm, 716, 5023668);
    /* @5023676 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5023680 load */
    /* @5023688 constant */
    /* @5023692 cmp */
    /* @5023696 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_5023776;
    /* @5023700 string */
    /* @5023708 cast */
    /* @5023712 constant */
    /* @5023716 constant */
    /* @5023720 load */
    /* @5023728 constant */
    /* @5023732 add */
    /* @5023736 constant */
    /* @5023740 constant */
    /* @5023744 load */
    /* @5023752 constant */
    /* @5023756 add */
    /* @5023760 call */
    GM_SITE(vm, 716, 5023760);
    v13 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(40));
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(160));
    /* @5023768 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v13, v14, STR_REF(1180)));
    /* @5023772 b */
    goto L_5024252;
    L_5023776: ;
    /* @5023776 load */
    /* @5023784 constant */
    /* @5023788 cmp */
    /* @5023792 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_5023872;
    /* @5023796 string */
    /* @5023804 cast */
    /* @5023808 constant */
    /* @5023812 constant */
    /* @5023816 load */
    /* @5023824 constant */
    /* @5023828 add */
    /* @5023832 constant */
    /* @5023836 constant */
    /* @5023840 load */
    /* @5023848 constant */
    /* @5023852 add */
    /* @5023856 call */
    GM_SITE(vm, 716, 5023856);
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(10));
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(160));
    /* @5023864 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v15, v16, STR_REF(1181)));
    /* @5023868 b */
    goto L_5024252;
    L_5023872: ;
    /* @5023872 load */
    /* @5023880 constant */
    /* @5023884 cmp */
    /* @5023888 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_5023968;
    /* @5023892 string */
    /* @5023900 cast */
    /* @5023904 constant */
    /* @5023908 constant */
    /* @5023912 load */
    /* @5023920 constant */
    /* @5023924 add */
    /* @5023928 constant */
    /* @5023932 constant */
    /* @5023936 load */
    /* @5023944 constant */
    /* @5023948 add */
    /* @5023952 call */
    GM_SITE(vm, 716, 5023952);
    v17 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(115));
    v18 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(50));
    /* @5023960 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v17, v18, STR_REF(1180)));
    /* @5023964 b */
    goto L_5024252;
    L_5023968: ;
    /* @5023968 load */
    /* @5023976 constant */
    /* @5023980 cmp */
    /* @5023984 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_5024064;
    /* @5023988 string */
    /* @5023996 cast */
    /* @5024000 constant */
    /* @5024004 constant */
    /* @5024008 load */
    /* @5024016 constant */
    /* @5024020 add */
    /* @5024024 constant */
    /* @5024028 constant */
    /* @5024032 load */
    /* @5024040 constant */
    /* @5024044 add */
    /* @5024048 call */
    GM_SITE(vm, 716, 5024048);
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(115));
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(50));
    /* @5024056 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v19, v20, STR_REF(1180)));
    /* @5024060 b */
    goto L_5024252;
    L_5024064: ;
    /* @5024064 load */
    /* @5024072 constant */
    /* @5024076 cmp */
    /* @5024080 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_5024160;
    /* @5024084 string */
    /* @5024092 cast */
    /* @5024096 constant */
    /* @5024100 constant */
    /* @5024104 load */
    /* @5024112 constant */
    /* @5024116 add */
    /* @5024120 constant */
    /* @5024124 constant */
    /* @5024128 load */
    /* @5024136 constant */
    /* @5024140 add */
    /* @5024144 call */
    GM_SITE(vm, 716, 5024144);
    v21 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(40));
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(160));
    /* @5024152 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v21, v22, STR_REF(1180)));
    /* @5024156 b */
    goto L_5024252;
    L_5024160: ;
    /* @5024160 load */
    /* @5024168 constant */
    /* @5024172 cmp */
    /* @5024176 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_5024252;
    /* @5024180 string */
    /* @5024188 cast */
    /* @5024192 constant */
    /* @5024196 constant */
    /* @5024200 load */
    /* @5024208 constant */
    /* @5024212 add */
    /* @5024216 constant */
    /* @5024220 constant */
    /* @5024224 load */
    /* @5024232 constant */
    /* @5024236 add */
    /* @5024240 call */
    GM_SITE(vm, 716, 5024240);
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(40));
    v24 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(160));
    /* @5024248 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v23, v24, STR_REF(1180)));
    L_5024252: ;
    /* @5024252 load */
    /* @5024260 constant */
    /* @5024264 cmp */
    /* @5024268 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawcredit3") == VAL(1)))) goto L_5025176;
    /* @5024272 constant */
    /* @5024276 cast */
    /* @5024280 call */
    GM_SITE(vm, 716, 5024280);
    /* @5024288 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @5024292 constant */
    /* @5024300 cast */
    /* @5024304 call */
    GM_SITE(vm, 716, 5024304);
    /* @5024312 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5024316 load */
    /* @5024324 constant */
    /* @5024328 cmp */
    /* @5024332 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_5024484;
    /* @5024336 string */
    /* @5024344 cast */
    /* @5024348 constant */
    /* @5024352 constant */
    /* @5024356 load */
    /* @5024364 constant */
    /* @5024368 add */
    /* @5024372 constant */
    /* @5024376 constant */
    /* @5024380 load */
    /* @5024388 constant */
    /* @5024392 add */
    /* @5024396 call */
    GM_SITE(vm, 716, 5024396);
    v25 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(40));
    v26 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(160));
    /* @5024404 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v25, v26, STR_REF(1182)));
    /* @5024408 string */
    /* @5024416 cast */
    /* @5024420 constant */
    /* @5024424 constant */
    /* @5024428 load */
    /* @5024436 constant */
    /* @5024440 add */
    /* @5024444 constant */
    /* @5024448 constant */
    /* @5024452 load */
    /* @5024460 constant */
    /* @5024464 add */
    /* @5024468 call */
    GM_SITE(vm, 716, 5024468);
    v27 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(250));
    v28 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(160));
    /* @5024476 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v27, v28, STR_REF(1183)));
    /* @5024480 b */
    goto L_5025176;
    L_5024484: ;
    /* @5024484 load */
    /* @5024492 constant */
    /* @5024496 cmp */
    /* @5024500 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_5024652;
    /* @5024504 string */
    /* @5024512 cast */
    /* @5024516 constant */
    /* @5024520 constant */
    /* @5024524 load */
    /* @5024532 constant */
    /* @5024536 add */
    /* @5024540 constant */
    /* @5024544 constant */
    /* @5024548 load */
    /* @5024556 constant */
    /* @5024560 add */
    /* @5024564 call */
    GM_SITE(vm, 716, 5024564);
    v29 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(10));
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(160));
    /* @5024572 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v29, v30, STR_REF(1184)));
    /* @5024576 string */
    /* @5024584 cast */
    /* @5024588 constant */
    /* @5024592 constant */
    /* @5024596 load */
    /* @5024604 constant */
    /* @5024608 add */
    /* @5024612 constant */
    /* @5024616 constant */
    /* @5024620 load */
    /* @5024628 constant */
    /* @5024632 add */
    /* @5024636 call */
    GM_SITE(vm, 716, 5024636);
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(220));
    v32 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(160));
    /* @5024644 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v31, v32, STR_REF(1185)));
    /* @5024648 b */
    goto L_5025176;
    L_5024652: ;
    /* @5024652 load */
    /* @5024660 constant */
    /* @5024664 cmp */
    /* @5024668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_5024748;
    /* @5024672 string */
    /* @5024680 cast */
    /* @5024684 constant */
    /* @5024688 constant */
    /* @5024692 load */
    /* @5024700 constant */
    /* @5024704 add */
    /* @5024708 constant */
    /* @5024712 constant */
    /* @5024716 load */
    /* @5024724 constant */
    /* @5024728 add */
    /* @5024732 call */
    GM_SITE(vm, 716, 5024732);
    v33 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(80));
    v34 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(50));
    /* @5024740 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v33, v34, STR_REF(1186)));
    /* @5024744 b */
    goto L_5025176;
    L_5024748: ;
    /* @5024748 load */
    /* @5024756 constant */
    /* @5024760 cmp */
    /* @5024764 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_5024844;
    /* @5024768 string */
    /* @5024776 cast */
    /* @5024780 constant */
    /* @5024784 constant */
    /* @5024788 load */
    /* @5024796 constant */
    /* @5024800 add */
    /* @5024804 constant */
    /* @5024808 constant */
    /* @5024812 load */
    /* @5024820 constant */
    /* @5024824 add */
    /* @5024828 call */
    GM_SITE(vm, 716, 5024828);
    v35 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(80));
    v36 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(50));
    /* @5024836 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v35, v36, STR_REF(1186)));
    /* @5024840 b */
    goto L_5025176;
    L_5024844: ;
    /* @5024844 load */
    /* @5024852 constant */
    /* @5024856 cmp */
    /* @5024860 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_5025012;
    /* @5024864 string */
    /* @5024872 cast */
    /* @5024876 constant */
    /* @5024880 constant */
    /* @5024884 load */
    /* @5024892 constant */
    /* @5024896 add */
    /* @5024900 constant */
    /* @5024904 constant */
    /* @5024908 load */
    /* @5024916 constant */
    /* @5024920 add */
    /* @5024924 call */
    GM_SITE(vm, 716, 5024924);
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(40));
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(160));
    /* @5024932 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v37, v38, STR_REF(1182)));
    /* @5024936 string */
    /* @5024944 cast */
    /* @5024948 constant */
    /* @5024952 constant */
    /* @5024956 load */
    /* @5024964 constant */
    /* @5024968 add */
    /* @5024972 constant */
    /* @5024976 constant */
    /* @5024980 load */
    /* @5024988 constant */
    /* @5024992 add */
    /* @5024996 call */
    GM_SITE(vm, 716, 5024996);
    v39 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(250));
    v40 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(160));
    /* @5025004 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, v40, STR_REF(1183)));
    /* @5025008 b */
    goto L_5025176;
    L_5025012: ;
    /* @5025012 load */
    /* @5025020 constant */
    /* @5025024 cmp */
    /* @5025028 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_5025176;
    /* @5025032 string */
    /* @5025040 cast */
    /* @5025044 constant */
    /* @5025048 constant */
    /* @5025052 load */
    /* @5025060 constant */
    /* @5025064 add */
    /* @5025068 constant */
    /* @5025072 constant */
    /* @5025076 load */
    /* @5025084 constant */
    /* @5025088 add */
    /* @5025092 call */
    GM_SITE(vm, 716, 5025092);
    v41 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(40));
    v42 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(160));
    /* @5025100 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v41, v42, STR_REF(1182)));
    /* @5025104 string */
    /* @5025112 cast */
    /* @5025116 constant */
    /* @5025120 constant */
    /* @5025124 load */
    /* @5025132 constant */
    /* @5025136 add */
    /* @5025140 constant */
    /* @5025144 constant */
    /* @5025148 load */
    /* @5025156 constant */
    /* @5025160 add */
    /* @5025164 call */
    GM_SITE(vm, 716, 5025164);
    v43 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(250));
    v44 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(160));
    /* @5025172 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v43, v44, STR_REF(1187)));
    L_5025176: ;
    /* @5025176 load */
    /* @5025184 constant */
    /* @5025188 cmp */
    /* @5025192 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawcredit4") == VAL(1)))) goto L_5026388;
    /* @5025196 constant */
    /* @5025200 cast */
    /* @5025204 call */
    GM_SITE(vm, 716, 5025204);
    /* @5025212 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @5025216 constant */
    /* @5025224 cast */
    /* @5025228 call */
    GM_SITE(vm, 716, 5025228);
    /* @5025236 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5025240 load */
    /* @5025248 constant */
    /* @5025252 cmp */
    /* @5025256 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_5025480;
    /* @5025260 string */
    /* @5025268 cast */
    /* @5025272 constant */
    /* @5025276 constant */
    /* @5025280 load */
    /* @5025288 constant */
    /* @5025292 add */
    /* @5025296 constant */
    /* @5025300 constant */
    /* @5025304 load */
    /* @5025312 constant */
    /* @5025316 add */
    /* @5025320 call */
    GM_SITE(vm, 716, 5025320);
    v45 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(40));
    v46 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(130));
    /* @5025328 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v45, v46, STR_REF(1188)));
    /* @5025332 string */
    /* @5025340 cast */
    /* @5025344 constant */
    /* @5025348 constant */
    /* @5025352 load */
    /* @5025360 constant */
    /* @5025364 add */
    /* @5025368 constant */
    /* @5025372 constant */
    /* @5025376 load */
    /* @5025384 constant */
    /* @5025388 add */
    /* @5025392 call */
    GM_SITE(vm, 716, 5025392);
    v47 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(40));
    v48 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(160));
    /* @5025400 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v47, v48, STR_REF(1189)));
    /* @5025404 string */
    /* @5025412 cast */
    /* @5025416 constant */
    /* @5025420 constant */
    /* @5025424 load */
    /* @5025432 constant */
    /* @5025436 add */
    /* @5025440 constant */
    /* @5025444 constant */
    /* @5025448 load */
    /* @5025456 constant */
    /* @5025460 add */
    /* @5025464 call */
    GM_SITE(vm, 716, 5025464);
    v49 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(250));
    v50 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(130));
    /* @5025472 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v49, v50, STR_REF(1190)));
    /* @5025476 b */
    goto L_5026388;
    L_5025480: ;
    /* @5025480 load */
    /* @5025488 constant */
    /* @5025492 cmp */
    /* @5025496 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_5025720;
    /* @5025500 string */
    /* @5025508 cast */
    /* @5025512 constant */
    /* @5025516 constant */
    /* @5025520 load */
    /* @5025528 constant */
    /* @5025532 add */
    /* @5025536 constant */
    /* @5025540 constant */
    /* @5025544 load */
    /* @5025552 constant */
    /* @5025556 add */
    /* @5025560 call */
    GM_SITE(vm, 716, 5025560);
    v51 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(5));
    v52 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(130));
    /* @5025568 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v51, v52, STR_REF(1188)));
    /* @5025572 string */
    /* @5025580 cast */
    /* @5025584 constant */
    /* @5025588 constant */
    /* @5025592 load */
    /* @5025600 constant */
    /* @5025604 add */
    /* @5025608 constant */
    /* @5025612 constant */
    /* @5025616 load */
    /* @5025624 constant */
    /* @5025628 add */
    /* @5025632 call */
    GM_SITE(vm, 716, 5025632);
    v53 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(5));
    v54 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(160));
    /* @5025640 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v53, v54, STR_REF(1191)));
    /* @5025644 string */
    /* @5025652 cast */
    /* @5025656 constant */
    /* @5025660 constant */
    /* @5025664 load */
    /* @5025672 constant */
    /* @5025676 add */
    /* @5025680 constant */
    /* @5025684 constant */
    /* @5025688 load */
    /* @5025696 constant */
    /* @5025700 add */
    /* @5025704 call */
    GM_SITE(vm, 716, 5025704);
    v55 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(220));
    v56 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(130));
    /* @5025712 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v55, v56, STR_REF(1192)));
    /* @5025716 b */
    goto L_5026388;
    L_5025720: ;
    /* @5025720 load */
    /* @5025728 constant */
    /* @5025732 cmp */
    /* @5025736 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_5025816;
    /* @5025740 string */
    /* @5025748 cast */
    /* @5025752 constant */
    /* @5025756 constant */
    /* @5025760 load */
    /* @5025768 constant */
    /* @5025772 add */
    /* @5025776 constant */
    /* @5025780 constant */
    /* @5025784 load */
    /* @5025792 constant */
    /* @5025796 add */
    /* @5025800 call */
    GM_SITE(vm, 716, 5025800);
    v57 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(40));
    v58 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(50));
    /* @5025808 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v57, v58, STR_REF(1193)));
    /* @5025812 b */
    goto L_5026388;
    L_5025816: ;
    /* @5025816 load */
    /* @5025824 constant */
    /* @5025828 cmp */
    /* @5025832 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_5025912;
    /* @5025836 string */
    /* @5025844 cast */
    /* @5025848 constant */
    /* @5025852 constant */
    /* @5025856 load */
    /* @5025864 constant */
    /* @5025868 add */
    /* @5025872 constant */
    /* @5025876 constant */
    /* @5025880 load */
    /* @5025888 constant */
    /* @5025892 add */
    /* @5025896 call */
    GM_SITE(vm, 716, 5025896);
    v59 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(40));
    v60 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(50));
    /* @5025904 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v59, v60, STR_REF(1193)));
    /* @5025908 b */
    goto L_5026388;
    L_5025912: ;
    /* @5025912 load */
    /* @5025920 constant */
    /* @5025924 cmp */
    /* @5025928 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_5026152;
    /* @5025932 string */
    /* @5025940 cast */
    /* @5025944 constant */
    /* @5025948 constant */
    /* @5025952 load */
    /* @5025960 constant */
    /* @5025964 add */
    /* @5025968 constant */
    /* @5025972 constant */
    /* @5025976 load */
    /* @5025984 constant */
    /* @5025988 add */
    /* @5025992 call */
    GM_SITE(vm, 716, 5025992);
    v61 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(40));
    v62 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(130));
    /* @5026000 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v61, v62, STR_REF(1188)));
    /* @5026004 string */
    /* @5026012 cast */
    /* @5026016 constant */
    /* @5026020 constant */
    /* @5026024 load */
    /* @5026032 constant */
    /* @5026036 add */
    /* @5026040 constant */
    /* @5026044 constant */
    /* @5026048 load */
    /* @5026056 constant */
    /* @5026060 add */
    /* @5026064 call */
    GM_SITE(vm, 716, 5026064);
    v63 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(40));
    v64 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(160));
    /* @5026072 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v63, v64, STR_REF(1189)));
    /* @5026076 string */
    /* @5026084 cast */
    /* @5026088 constant */
    /* @5026092 constant */
    /* @5026096 load */
    /* @5026104 constant */
    /* @5026108 add */
    /* @5026112 constant */
    /* @5026116 constant */
    /* @5026120 load */
    /* @5026128 constant */
    /* @5026132 add */
    /* @5026136 call */
    GM_SITE(vm, 716, 5026136);
    v65 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(250));
    v66 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(130));
    /* @5026144 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v65, v66, STR_REF(1190)));
    /* @5026148 b */
    goto L_5026388;
    L_5026152: ;
    /* @5026152 load */
    /* @5026160 constant */
    /* @5026164 cmp */
    /* @5026168 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_5026388;
    /* @5026172 string */
    /* @5026180 cast */
    /* @5026184 constant */
    /* @5026188 constant */
    /* @5026192 load */
    /* @5026200 constant */
    /* @5026204 add */
    /* @5026208 constant */
    /* @5026212 constant */
    /* @5026216 load */
    /* @5026224 constant */
    /* @5026228 add */
    /* @5026232 call */
    GM_SITE(vm, 716, 5026232);
    v67 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(40));
    v68 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(130));
    /* @5026240 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v67, v68, STR_REF(1188)));
    /* @5026244 string */
    /* @5026252 cast */
    /* @5026256 constant */
    /* @5026260 constant */
    /* @5026264 load */
    /* @5026272 constant */
    /* @5026276 add */
    /* @5026280 constant */
    /* @5026284 constant */
    /* @5026288 load */
    /* @5026296 constant */
    /* @5026300 add */
    /* @5026304 call */
    GM_SITE(vm, 716, 5026304);
    v69 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(40));
    v70 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(160));
    /* @5026312 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v69, v70, STR_REF(1189)));
    /* @5026316 string */
    /* @5026324 cast */
    /* @5026328 constant */
    /* @5026332 constant */
    /* @5026336 load */
    /* @5026344 constant */
    /* @5026348 add */
    /* @5026352 constant */
    /* @5026356 constant */
    /* @5026360 load */
    /* @5026368 constant */
    /* @5026372 add */
    /* @5026376 call */
    GM_SITE(vm, 716, 5026376);
    v71 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(250));
    v72 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(130));
    /* @5026384 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v71, v72, STR_REF(1194)));
    L_5026388: ;
    /* @5026388 load */
    /* @5026396 constant */
    /* @5026400 cmp */
    /* @5026404 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawcredit5") == VAL(1)))) goto L_5028440;
    /* @5026408 constant */
    /* @5026412 cast */
    /* @5026416 call */
    GM_SITE(vm, 716, 5026416);
    /* @5026424 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @5026428 constant */
    /* @5026436 cast */
    /* @5026440 call */
    GM_SITE(vm, 716, 5026440);
    /* @5026448 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5026452 load */
    /* @5026460 constant */
    /* @5026464 cmp */
    /* @5026468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_5026784;
    /* @5026472 constant */
    /* @5026476 cast */
    /* @5026480 call */
    GM_SITE(vm, 716, 5026480);
    /* @5026488 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5026492 string */
    /* @5026500 cast */
    /* @5026504 constant */
    /* @5026508 constant */
    /* @5026512 load */
    /* @5026520 constant */
    /* @5026524 add */
    /* @5026528 constant */
    /* @5026532 constant */
    /* @5026536 load */
    /* @5026544 constant */
    /* @5026548 add */
    /* @5026552 call */
    GM_SITE(vm, 716, 5026552);
    v73 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(60));
    v74 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(135));
    /* @5026560 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v73, v74, STR_REF(1195)));
    /* @5026564 string */
    /* @5026572 cast */
    /* @5026576 constant */
    /* @5026580 constant */
    /* @5026584 load */
    /* @5026592 constant */
    /* @5026596 add */
    /* @5026600 constant */
    /* @5026604 constant */
    /* @5026608 load */
    /* @5026616 constant */
    /* @5026620 add */
    /* @5026624 call */
    GM_SITE(vm, 716, 5026624);
    v75 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(280));
    v76 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(120));
    /* @5026632 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v75, v76, STR_REF(1196)));
    /* @5026636 string */
    /* @5026644 cast */
    /* @5026648 constant */
    /* @5026652 constant */
    /* @5026656 load */
    /* @5026664 constant */
    /* @5026668 add */
    /* @5026672 constant */
    /* @5026676 constant */
    /* @5026680 load */
    /* @5026688 constant */
    /* @5026692 add */
    /* @5026696 call */
    GM_SITE(vm, 716, 5026696);
    v77 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(280));
    v78 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(135));
    /* @5026704 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v77, v78, STR_REF(1197)));
    /* @5026708 string */
    /* @5026716 cast */
    /* @5026720 constant */
    /* @5026724 constant */
    /* @5026728 load */
    /* @5026736 constant */
    /* @5026740 add */
    /* @5026744 constant */
    /* @5026748 constant */
    /* @5026752 load */
    /* @5026760 constant */
    /* @5026764 add */
    /* @5026768 call */
    GM_SITE(vm, 716, 5026768);
    v79 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(280));
    v80 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(150));
    /* @5026776 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v79, v80, STR_REF(1198)));
    /* @5026780 b */
    goto L_5028440;
    L_5026784: ;
    /* @5026784 load */
    /* @5026792 constant */
    /* @5026796 cmp */
    /* @5026800 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_5027116;
    /* @5026804 constant */
    /* @5026808 cast */
    /* @5026812 call */
    GM_SITE(vm, 716, 5026812);
    /* @5026820 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5026824 string */
    /* @5026832 cast */
    /* @5026836 constant */
    /* @5026840 constant */
    /* @5026844 load */
    /* @5026852 constant */
    /* @5026856 add */
    /* @5026860 constant */
    /* @5026864 constant */
    /* @5026868 load */
    /* @5026876 constant */
    /* @5026880 add */
    /* @5026884 call */
    GM_SITE(vm, 716, 5026884);
    v81 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(60));
    v82 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(140));
    /* @5026892 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v81, v82, STR_REF(1195)));
    /* @5026896 string */
    /* @5026904 cast */
    /* @5026908 constant */
    /* @5026912 constant */
    /* @5026916 load */
    /* @5026924 constant */
    /* @5026928 add */
    /* @5026932 constant */
    /* @5026936 constant */
    /* @5026940 load */
    /* @5026948 constant */
    /* @5026952 add */
    /* @5026956 call */
    GM_SITE(vm, 716, 5026956);
    v83 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(240));
    v84 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(125));
    /* @5026964 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v83, v84, STR_REF(1196)));
    /* @5026968 string */
    /* @5026976 cast */
    /* @5026980 constant */
    /* @5026984 constant */
    /* @5026988 load */
    /* @5026996 constant */
    /* @5027000 add */
    /* @5027004 constant */
    /* @5027008 constant */
    /* @5027012 load */
    /* @5027020 constant */
    /* @5027024 add */
    /* @5027028 call */
    GM_SITE(vm, 716, 5027028);
    v85 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(240));
    v86 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(140));
    /* @5027036 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v85, v86, STR_REF(1197)));
    /* @5027040 string */
    /* @5027048 cast */
    /* @5027052 constant */
    /* @5027056 constant */
    /* @5027060 load */
    /* @5027068 constant */
    /* @5027072 add */
    /* @5027076 constant */
    /* @5027080 constant */
    /* @5027084 load */
    /* @5027092 constant */
    /* @5027096 add */
    /* @5027100 call */
    GM_SITE(vm, 716, 5027100);
    v87 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(240));
    v88 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(155));
    /* @5027108 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v87, v88, STR_REF(1198)));
    /* @5027112 b */
    goto L_5028440;
    L_5027116: ;
    /* @5027116 load */
    /* @5027124 constant */
    /* @5027128 cmp */
    /* @5027132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_5027448;
    /* @5027136 constant */
    /* @5027140 cast */
    /* @5027144 call */
    GM_SITE(vm, 716, 5027144);
    /* @5027152 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @5027156 string */
    /* @5027164 cast */
    /* @5027168 constant */
    /* @5027172 constant */
    /* @5027176 load */
    /* @5027184 constant */
    /* @5027188 add */
    /* @5027192 constant */
    /* @5027196 constant */
    /* @5027200 load */
    /* @5027208 constant */
    /* @5027212 add */
    /* @5027216 call */
    GM_SITE(vm, 716, 5027216);
    v89 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(115));
    v90 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(70));
    /* @5027224 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v89, v90, STR_REF(1195)));
    /* @5027228 string */
    /* @5027236 cast */
    /* @5027240 constant */
    /* @5027244 constant */
    /* @5027248 load */
    /* @5027256 constant */
    /* @5027260 add */
    /* @5027264 constant */
    /* @5027268 constant */
    /* @5027272 load */
    /* @5027280 constant */
    /* @5027284 add */
    /* @5027288 call */
    GM_SITE(vm, 716, 5027288);
    v91 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(280));
    v92 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(40));
    /* @5027296 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v91, v92, STR_REF(1196)));
    /* @5027300 string */
    /* @5027308 cast */
    /* @5027312 constant */
    /* @5027316 constant */
    /* @5027320 load */
    /* @5027328 constant */
    /* @5027332 add */
    /* @5027336 constant */
    /* @5027340 constant */
    /* @5027344 load */
    /* @5027352 constant */
    /* @5027356 add */
    /* @5027360 call */
    GM_SITE(vm, 716, 5027360);
    v93 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(280));
    v94 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(70));
    /* @5027368 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v93, v94, STR_REF(1197)));
    /* @5027372 string */
    /* @5027380 cast */
    /* @5027384 constant */
    /* @5027388 constant */
    /* @5027392 load */
    /* @5027400 constant */
    /* @5027404 add */
    /* @5027408 constant */
    /* @5027412 constant */
    /* @5027416 load */
    /* @5027424 constant */
    /* @5027428 add */
    /* @5027432 call */
    GM_SITE(vm, 716, 5027432);
    v95 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(280));
    v96 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(100));
    /* @5027440 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v95, v96, STR_REF(1198)));
    /* @5027444 b */
    goto L_5028440;
    L_5027448: ;
    /* @5027448 load */
    /* @5027456 constant */
    /* @5027460 cmp */
    /* @5027464 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_5027780;
    /* @5027468 constant */
    /* @5027472 cast */
    /* @5027476 call */
    GM_SITE(vm, 716, 5027476);
    /* @5027484 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @5027488 string */
    /* @5027496 cast */
    /* @5027500 constant */
    /* @5027504 constant */
    /* @5027508 load */
    /* @5027516 constant */
    /* @5027520 add */
    /* @5027524 constant */
    /* @5027528 constant */
    /* @5027532 load */
    /* @5027540 constant */
    /* @5027544 add */
    /* @5027548 call */
    GM_SITE(vm, 716, 5027548);
    v97 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(115));
    v98 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(70));
    /* @5027556 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v97, v98, STR_REF(1195)));
    /* @5027560 string */
    /* @5027568 cast */
    /* @5027572 constant */
    /* @5027576 constant */
    /* @5027580 load */
    /* @5027588 constant */
    /* @5027592 add */
    /* @5027596 constant */
    /* @5027600 constant */
    /* @5027604 load */
    /* @5027612 constant */
    /* @5027616 add */
    /* @5027620 call */
    GM_SITE(vm, 716, 5027620);
    v99 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(280));
    v100 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(40));
    /* @5027628 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v99, v100, STR_REF(1196)));
    /* @5027632 string */
    /* @5027640 cast */
    /* @5027644 constant */
    /* @5027648 constant */
    /* @5027652 load */
    /* @5027660 constant */
    /* @5027664 add */
    /* @5027668 constant */
    /* @5027672 constant */
    /* @5027676 load */
    /* @5027684 constant */
    /* @5027688 add */
    /* @5027692 call */
    GM_SITE(vm, 716, 5027692);
    v101 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(280));
    v102 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(70));
    /* @5027700 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v101, v102, STR_REF(1197)));
    /* @5027704 string */
    /* @5027712 cast */
    /* @5027716 constant */
    /* @5027720 constant */
    /* @5027724 load */
    /* @5027732 constant */
    /* @5027736 add */
    /* @5027740 constant */
    /* @5027744 constant */
    /* @5027748 load */
    /* @5027756 constant */
    /* @5027760 add */
    /* @5027764 call */
    GM_SITE(vm, 716, 5027764);
    v103 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(280));
    v104 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(100));
    /* @5027772 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v103, v104, STR_REF(1198)));
    /* @5027776 b */
    goto L_5028440;
    L_5027780: ;
    /* @5027780 load */
    /* @5027788 constant */
    /* @5027792 cmp */
    /* @5027796 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_5028112;
    /* @5027800 constant */
    /* @5027804 cast */
    /* @5027808 call */
    GM_SITE(vm, 716, 5027808);
    /* @5027816 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5027820 string */
    /* @5027828 cast */
    /* @5027832 constant */
    /* @5027836 constant */
    /* @5027840 load */
    /* @5027848 constant */
    /* @5027852 add */
    /* @5027856 constant */
    /* @5027860 constant */
    /* @5027864 load */
    /* @5027872 constant */
    /* @5027876 add */
    /* @5027880 call */
    GM_SITE(vm, 716, 5027880);
    v105 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(60));
    v106 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(135));
    /* @5027888 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v105, v106, STR_REF(1195)));
    /* @5027892 string */
    /* @5027900 cast */
    /* @5027904 constant */
    /* @5027908 constant */
    /* @5027912 load */
    /* @5027920 constant */
    /* @5027924 add */
    /* @5027928 constant */
    /* @5027932 constant */
    /* @5027936 load */
    /* @5027944 constant */
    /* @5027948 add */
    /* @5027952 call */
    GM_SITE(vm, 716, 5027952);
    v107 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(280));
    v108 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(120));
    /* @5027960 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v107, v108, STR_REF(1196)));
    /* @5027964 string */
    /* @5027972 cast */
    /* @5027976 constant */
    /* @5027980 constant */
    /* @5027984 load */
    /* @5027992 constant */
    /* @5027996 add */
    /* @5028000 constant */
    /* @5028004 constant */
    /* @5028008 load */
    /* @5028016 constant */
    /* @5028020 add */
    /* @5028024 call */
    GM_SITE(vm, 716, 5028024);
    v109 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(280));
    v110 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(135));
    /* @5028032 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v109, v110, STR_REF(1197)));
    /* @5028036 string */
    /* @5028044 cast */
    /* @5028048 constant */
    /* @5028052 constant */
    /* @5028056 load */
    /* @5028064 constant */
    /* @5028068 add */
    /* @5028072 constant */
    /* @5028076 constant */
    /* @5028080 load */
    /* @5028088 constant */
    /* @5028092 add */
    /* @5028096 call */
    GM_SITE(vm, 716, 5028096);
    v111 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(280));
    v112 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(150));
    /* @5028104 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v111, v112, STR_REF(1198)));
    /* @5028108 b */
    goto L_5028440;
    L_5028112: ;
    /* @5028112 load */
    /* @5028120 constant */
    /* @5028124 cmp */
    /* @5028128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_5028440;
    /* @5028132 constant */
    /* @5028136 cast */
    /* @5028140 call */
    GM_SITE(vm, 716, 5028140);
    /* @5028148 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5028152 string */
    /* @5028160 cast */
    /* @5028164 constant */
    /* @5028168 constant */
    /* @5028172 load */
    /* @5028180 constant */
    /* @5028184 add */
    /* @5028188 constant */
    /* @5028192 constant */
    /* @5028196 load */
    /* @5028204 constant */
    /* @5028208 add */
    /* @5028212 call */
    GM_SITE(vm, 716, 5028212);
    v113 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(60));
    v114 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(155));
    /* @5028220 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v113, v114, STR_REF(1195)));
    /* @5028224 string */
    /* @5028232 cast */
    /* @5028236 constant */
    /* @5028240 constant */
    /* @5028244 load */
    /* @5028252 constant */
    /* @5028256 add */
    /* @5028260 constant */
    /* @5028264 constant */
    /* @5028268 load */
    /* @5028276 constant */
    /* @5028280 add */
    /* @5028284 call */
    GM_SITE(vm, 716, 5028284);
    v115 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(280));
    v116 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(140));
    /* @5028292 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v115, v116, STR_REF(1196)));
    /* @5028296 string */
    /* @5028304 cast */
    /* @5028308 constant */
    /* @5028312 constant */
    /* @5028316 load */
    /* @5028324 constant */
    /* @5028328 add */
    /* @5028332 constant */
    /* @5028336 constant */
    /* @5028340 load */
    /* @5028348 constant */
    /* @5028352 add */
    /* @5028356 call */
    GM_SITE(vm, 716, 5028356);
    v117 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(280));
    v118 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(155));
    /* @5028364 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v117, v118, STR_REF(1197)));
    /* @5028368 string */
    /* @5028376 cast */
    /* @5028380 constant */
    /* @5028384 constant */
    /* @5028388 load */
    /* @5028396 constant */
    /* @5028400 add */
    /* @5028404 constant */
    /* @5028408 constant */
    /* @5028412 load */
    /* @5028420 constant */
    /* @5028424 add */
    /* @5028428 call */
    GM_SITE(vm, 716, 5028428);
    v119 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(280));
    v120 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(170));
    /* @5028436 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v119, v120, STR_REF(1198)));
    L_5028440: ;
    /* @5028440 load */
    /* @5028448 constant */
    /* @5028452 cmp */
    /* @5028456 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawcredit6") == VAL(1)))) goto L_5030492;
    /* @5028460 constant */
    /* @5028464 cast */
    /* @5028468 call */
    GM_SITE(vm, 716, 5028468);
    /* @5028476 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @5028480 constant */
    /* @5028488 cast */
    /* @5028492 call */
    GM_SITE(vm, 716, 5028492);
    /* @5028500 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5028504 load */
    /* @5028512 constant */
    /* @5028516 cmp */
    /* @5028520 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_5028836;
    /* @5028524 constant */
    /* @5028528 cast */
    /* @5028532 call */
    GM_SITE(vm, 716, 5028532);
    /* @5028540 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5028544 string */
    /* @5028552 cast */
    /* @5028556 constant */
    /* @5028560 constant */
    /* @5028564 load */
    /* @5028572 constant */
    /* @5028576 add */
    /* @5028580 constant */
    /* @5028584 constant */
    /* @5028588 load */
    /* @5028596 constant */
    /* @5028600 add */
    /* @5028604 call */
    GM_SITE(vm, 716, 5028604);
    v121 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(280));
    v122 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(120));
    /* @5028612 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v121, v122, STR_REF(1199)));
    /* @5028616 string */
    /* @5028624 cast */
    /* @5028628 constant */
    /* @5028632 constant */
    /* @5028636 load */
    /* @5028644 constant */
    /* @5028648 add */
    /* @5028652 constant */
    /* @5028656 constant */
    /* @5028660 load */
    /* @5028668 constant */
    /* @5028672 add */
    /* @5028676 call */
    GM_SITE(vm, 716, 5028676);
    v123 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(280));
    v124 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(150));
    /* @5028684 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v123, v124, STR_REF(1200)));
    /* @5028688 string */
    /* @5028696 cast */
    /* @5028700 constant */
    /* @5028704 constant */
    /* @5028708 load */
    /* @5028716 constant */
    /* @5028720 add */
    /* @5028724 constant */
    /* @5028728 constant */
    /* @5028732 load */
    /* @5028740 constant */
    /* @5028744 add */
    /* @5028748 call */
    GM_SITE(vm, 716, 5028748);
    v125 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(80));
    v126 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(120));
    /* @5028756 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v125, v126, STR_REF(1201)));
    /* @5028760 string */
    /* @5028768 cast */
    /* @5028772 constant */
    /* @5028776 constant */
    /* @5028780 load */
    /* @5028788 constant */
    /* @5028792 add */
    /* @5028796 constant */
    /* @5028800 constant */
    /* @5028804 load */
    /* @5028812 constant */
    /* @5028816 add */
    /* @5028820 call */
    GM_SITE(vm, 716, 5028820);
    v127 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(80));
    v128 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(150));
    /* @5028828 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v127, v128, STR_REF(1202)));
    /* @5028832 b */
    goto L_5030492;
    L_5028836: ;
    /* @5028836 load */
    /* @5028844 constant */
    /* @5028848 cmp */
    /* @5028852 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_5029168;
    /* @5028856 constant */
    /* @5028860 cast */
    /* @5028864 call */
    GM_SITE(vm, 716, 5028864);
    /* @5028872 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5028876 string */
    /* @5028884 cast */
    /* @5028888 constant */
    /* @5028892 constant */
    /* @5028896 load */
    /* @5028904 constant */
    /* @5028908 add */
    /* @5028912 constant */
    /* @5028916 constant */
    /* @5028920 load */
    /* @5028928 constant */
    /* @5028932 add */
    /* @5028936 call */
    GM_SITE(vm, 716, 5028936);
    v129 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(240));
    v130 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(125));
    /* @5028944 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v129, v130, STR_REF(1199)));
    /* @5028948 string */
    /* @5028956 cast */
    /* @5028960 constant */
    /* @5028964 constant */
    /* @5028968 load */
    /* @5028976 constant */
    /* @5028980 add */
    /* @5028984 constant */
    /* @5028988 constant */
    /* @5028992 load */
    /* @5029000 constant */
    /* @5029004 add */
    /* @5029008 call */
    GM_SITE(vm, 716, 5029008);
    v131 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(240));
    v132 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(155));
    /* @5029016 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v131, v132, STR_REF(1200)));
    /* @5029020 string */
    /* @5029028 cast */
    /* @5029032 constant */
    /* @5029036 constant */
    /* @5029040 load */
    /* @5029048 constant */
    /* @5029052 add */
    /* @5029056 constant */
    /* @5029060 constant */
    /* @5029064 load */
    /* @5029072 constant */
    /* @5029076 add */
    /* @5029080 call */
    GM_SITE(vm, 716, 5029080);
    v133 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(60));
    v134 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(125));
    /* @5029088 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v133, v134, STR_REF(1201)));
    /* @5029092 string */
    /* @5029100 cast */
    /* @5029104 constant */
    /* @5029108 constant */
    /* @5029112 load */
    /* @5029120 constant */
    /* @5029124 add */
    /* @5029128 constant */
    /* @5029132 constant */
    /* @5029136 load */
    /* @5029144 constant */
    /* @5029148 add */
    /* @5029152 call */
    GM_SITE(vm, 716, 5029152);
    v135 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(60));
    v136 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(155));
    /* @5029160 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v135, v136, STR_REF(1202)));
    /* @5029164 b */
    goto L_5030492;
    L_5029168: ;
    /* @5029168 load */
    /* @5029176 constant */
    /* @5029180 cmp */
    /* @5029184 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_5029500;
    /* @5029188 constant */
    /* @5029192 cast */
    /* @5029196 call */
    GM_SITE(vm, 716, 5029196);
    /* @5029204 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @5029208 string */
    /* @5029216 cast */
    /* @5029220 constant */
    /* @5029224 constant */
    /* @5029228 load */
    /* @5029236 constant */
    /* @5029240 add */
    /* @5029244 constant */
    /* @5029248 constant */
    /* @5029252 load */
    /* @5029260 constant */
    /* @5029264 add */
    /* @5029268 call */
    GM_SITE(vm, 716, 5029268);
    v137 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(70));
    v138 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(40));
    /* @5029276 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v137, v138, STR_REF(1201)));
    /* @5029280 string */
    /* @5029288 cast */
    /* @5029292 constant */
    /* @5029296 constant */
    /* @5029300 load */
    /* @5029308 constant */
    /* @5029312 add */
    /* @5029316 constant */
    /* @5029320 constant */
    /* @5029324 load */
    /* @5029332 constant */
    /* @5029336 add */
    /* @5029340 call */
    GM_SITE(vm, 716, 5029340);
    v139 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(70));
    v140 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(70));
    /* @5029348 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v139, v140, STR_REF(1202)));
    /* @5029352 string */
    /* @5029360 cast */
    /* @5029364 constant */
    /* @5029368 constant */
    /* @5029372 load */
    /* @5029380 constant */
    /* @5029384 add */
    /* @5029388 constant */
    /* @5029392 constant */
    /* @5029396 load */
    /* @5029404 constant */
    /* @5029408 add */
    /* @5029412 call */
    GM_SITE(vm, 716, 5029412);
    v141 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(280));
    v142 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(40));
    /* @5029420 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v141, v142, STR_REF(1199)));
    /* @5029424 string */
    /* @5029432 cast */
    /* @5029436 constant */
    /* @5029440 constant */
    /* @5029444 load */
    /* @5029452 constant */
    /* @5029456 add */
    /* @5029460 constant */
    /* @5029464 constant */
    /* @5029468 load */
    /* @5029476 constant */
    /* @5029480 add */
    /* @5029484 call */
    GM_SITE(vm, 716, 5029484);
    v143 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(280));
    v144 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(70));
    /* @5029492 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v143, v144, STR_REF(1203)));
    /* @5029496 b */
    goto L_5030492;
    L_5029500: ;
    /* @5029500 load */
    /* @5029508 constant */
    /* @5029512 cmp */
    /* @5029516 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_5029832;
    /* @5029520 constant */
    /* @5029524 cast */
    /* @5029528 call */
    GM_SITE(vm, 716, 5029528);
    /* @5029536 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @5029540 string */
    /* @5029548 cast */
    /* @5029552 constant */
    /* @5029556 constant */
    /* @5029560 load */
    /* @5029568 constant */
    /* @5029572 add */
    /* @5029576 constant */
    /* @5029580 constant */
    /* @5029584 load */
    /* @5029592 constant */
    /* @5029596 add */
    /* @5029600 call */
    GM_SITE(vm, 716, 5029600);
    v145 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(280));
    v146 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(40));
    /* @5029608 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v145, v146, STR_REF(1199)));
    /* @5029612 string */
    /* @5029620 cast */
    /* @5029624 constant */
    /* @5029628 constant */
    /* @5029632 load */
    /* @5029640 constant */
    /* @5029644 add */
    /* @5029648 constant */
    /* @5029652 constant */
    /* @5029656 load */
    /* @5029664 constant */
    /* @5029668 add */
    /* @5029672 call */
    GM_SITE(vm, 716, 5029672);
    v147 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(280));
    v148 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(70));
    /* @5029680 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v147, v148, STR_REF(1203)));
    /* @5029684 string */
    /* @5029692 cast */
    /* @5029696 constant */
    /* @5029700 constant */
    /* @5029704 load */
    /* @5029712 constant */
    /* @5029716 add */
    /* @5029720 constant */
    /* @5029724 constant */
    /* @5029728 load */
    /* @5029736 constant */
    /* @5029740 add */
    /* @5029744 call */
    GM_SITE(vm, 716, 5029744);
    v149 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(70));
    v150 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(40));
    /* @5029752 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v149, v150, STR_REF(1201)));
    /* @5029756 string */
    /* @5029764 cast */
    /* @5029768 constant */
    /* @5029772 constant */
    /* @5029776 load */
    /* @5029784 constant */
    /* @5029788 add */
    /* @5029792 constant */
    /* @5029796 constant */
    /* @5029800 load */
    /* @5029808 constant */
    /* @5029812 add */
    /* @5029816 call */
    GM_SITE(vm, 716, 5029816);
    v151 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(70));
    v152 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(70));
    /* @5029824 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v151, v152, STR_REF(1202)));
    /* @5029828 b */
    goto L_5030492;
    L_5029832: ;
    /* @5029832 load */
    /* @5029840 constant */
    /* @5029844 cmp */
    /* @5029848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_5030164;
    /* @5029852 constant */
    /* @5029856 cast */
    /* @5029860 call */
    GM_SITE(vm, 716, 5029860);
    /* @5029868 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5029872 string */
    /* @5029880 cast */
    /* @5029884 constant */
    /* @5029888 constant */
    /* @5029892 load */
    /* @5029900 constant */
    /* @5029904 add */
    /* @5029908 constant */
    /* @5029912 constant */
    /* @5029916 load */
    /* @5029924 constant */
    /* @5029928 add */
    /* @5029932 call */
    GM_SITE(vm, 716, 5029932);
    v153 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(280));
    v154 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(120));
    /* @5029940 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v153, v154, STR_REF(1199)));
    /* @5029944 string */
    /* @5029952 cast */
    /* @5029956 constant */
    /* @5029960 constant */
    /* @5029964 load */
    /* @5029972 constant */
    /* @5029976 add */
    /* @5029980 constant */
    /* @5029984 constant */
    /* @5029988 load */
    /* @5029996 constant */
    /* @5030000 add */
    /* @5030004 call */
    GM_SITE(vm, 716, 5030004);
    v155 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(280));
    v156 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(150));
    /* @5030012 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v155, v156, STR_REF(1200)));
    /* @5030016 string */
    /* @5030024 cast */
    /* @5030028 constant */
    /* @5030032 constant */
    /* @5030036 load */
    /* @5030044 constant */
    /* @5030048 add */
    /* @5030052 constant */
    /* @5030056 constant */
    /* @5030060 load */
    /* @5030068 constant */
    /* @5030072 add */
    /* @5030076 call */
    GM_SITE(vm, 716, 5030076);
    v157 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(80));
    v158 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(120));
    /* @5030084 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v157, v158, STR_REF(1201)));
    /* @5030088 string */
    /* @5030096 cast */
    /* @5030100 constant */
    /* @5030104 constant */
    /* @5030108 load */
    /* @5030116 constant */
    /* @5030120 add */
    /* @5030124 constant */
    /* @5030128 constant */
    /* @5030132 load */
    /* @5030140 constant */
    /* @5030144 add */
    /* @5030148 call */
    GM_SITE(vm, 716, 5030148);
    v159 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(80));
    v160 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(150));
    /* @5030156 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v159, v160, STR_REF(1202)));
    /* @5030160 b */
    goto L_5030492;
    L_5030164: ;
    /* @5030164 load */
    /* @5030172 constant */
    /* @5030176 cmp */
    /* @5030180 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_5030492;
    /* @5030184 constant */
    /* @5030188 cast */
    /* @5030192 call */
    GM_SITE(vm, 716, 5030192);
    /* @5030200 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5030204 string */
    /* @5030212 cast */
    /* @5030216 constant */
    /* @5030220 constant */
    /* @5030224 load */
    /* @5030232 constant */
    /* @5030236 add */
    /* @5030240 constant */
    /* @5030244 constant */
    /* @5030248 load */
    /* @5030256 constant */
    /* @5030260 add */
    /* @5030264 call */
    GM_SITE(vm, 716, 5030264);
    v161 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(280));
    v162 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(140));
    /* @5030272 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v161, v162, STR_REF(1199)));
    /* @5030276 string */
    /* @5030284 cast */
    /* @5030288 constant */
    /* @5030292 constant */
    /* @5030296 load */
    /* @5030304 constant */
    /* @5030308 add */
    /* @5030312 constant */
    /* @5030316 constant */
    /* @5030320 load */
    /* @5030328 constant */
    /* @5030332 add */
    /* @5030336 call */
    GM_SITE(vm, 716, 5030336);
    v163 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(280));
    v164 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(170));
    /* @5030344 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v163, v164, STR_REF(1200)));
    /* @5030348 string */
    /* @5030356 cast */
    /* @5030360 constant */
    /* @5030364 constant */
    /* @5030368 load */
    /* @5030376 constant */
    /* @5030380 add */
    /* @5030384 constant */
    /* @5030388 constant */
    /* @5030392 load */
    /* @5030400 constant */
    /* @5030404 add */
    /* @5030408 call */
    GM_SITE(vm, 716, 5030408);
    v165 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(80));
    v166 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(140));
    /* @5030416 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v165, v166, STR_REF(1201)));
    /* @5030420 string */
    /* @5030428 cast */
    /* @5030432 constant */
    /* @5030436 constant */
    /* @5030440 load */
    /* @5030448 constant */
    /* @5030452 add */
    /* @5030456 constant */
    /* @5030460 constant */
    /* @5030464 load */
    /* @5030472 constant */
    /* @5030476 add */
    /* @5030480 call */
    GM_SITE(vm, 716, 5030480);
    v167 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(80));
    v168 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(170));
    /* @5030488 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v167, v168, STR_REF(1202)));
    L_5030492: ;
    /* @5030492 load */
    /* @5030500 constant */
    /* @5030504 cmp */
    /* @5030508 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawcredit7") == VAL(1)))) goto L_5031560;
    /* @5030512 constant */
    /* @5030516 cast */
    /* @5030520 call */
    GM_SITE(vm, 716, 5030520);
    /* @5030528 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @5030532 constant */
    /* @5030540 cast */
    /* @5030544 call */
    GM_SITE(vm, 716, 5030544);
    /* @5030552 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5030556 load */
    /* @5030564 constant */
    /* @5030568 cmp */
    /* @5030572 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_5030724;
    /* @5030576 string */
    /* @5030584 cast */
    /* @5030588 constant */
    /* @5030592 constant */
    /* @5030596 load */
    /* @5030604 constant */
    /* @5030608 add */
    /* @5030612 constant */
    /* @5030616 constant */
    /* @5030620 load */
    /* @5030628 constant */
    /* @5030632 add */
    /* @5030636 call */
    GM_SITE(vm, 716, 5030636);
    v169 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(40));
    v170 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(130));
    /* @5030644 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v169, v170, STR_REF(1204)));
    /* @5030648 string */
    /* @5030656 cast */
    /* @5030660 constant */
    /* @5030664 constant */
    /* @5030668 load */
    /* @5030676 constant */
    /* @5030680 add */
    /* @5030684 constant */
    /* @5030688 constant */
    /* @5030692 load */
    /* @5030700 constant */
    /* @5030704 add */
    /* @5030708 call */
    GM_SITE(vm, 716, 5030708);
    v171 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(114));
    v172 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(160));
    /* @5030716 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v171, v172, STR_REF(1205)));
    /* @5030720 b */
    goto L_5031560;
    L_5030724: ;
    /* @5030724 load */
    /* @5030732 constant */
    /* @5030736 cmp */
    /* @5030740 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_5030892;
    /* @5030744 string */
    /* @5030752 cast */
    /* @5030756 constant */
    /* @5030760 constant */
    /* @5030764 load */
    /* @5030772 constant */
    /* @5030776 add */
    /* @5030780 constant */
    /* @5030784 constant */
    /* @5030788 load */
    /* @5030796 constant */
    /* @5030800 add */
    /* @5030804 call */
    GM_SITE(vm, 716, 5030804);
    v173 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(10));
    v174 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(130));
    /* @5030812 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v173, v174, STR_REF(1204)));
    /* @5030816 string */
    /* @5030824 cast */
    /* @5030828 constant */
    /* @5030832 constant */
    /* @5030836 load */
    /* @5030844 constant */
    /* @5030848 add */
    /* @5030852 constant */
    /* @5030856 constant */
    /* @5030860 load */
    /* @5030868 constant */
    /* @5030872 add */
    /* @5030876 call */
    GM_SITE(vm, 716, 5030876);
    v175 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(10));
    v176 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(160));
    /* @5030884 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v175, v176, STR_REF(1206)));
    /* @5030888 b */
    goto L_5031560;
    L_5030892: ;
    /* @5030892 load */
    /* @5030900 constant */
    /* @5030904 cmp */
    /* @5030908 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_5031060;
    /* @5030912 string */
    /* @5030920 cast */
    /* @5030924 constant */
    /* @5030928 constant */
    /* @5030932 load */
    /* @5030940 constant */
    /* @5030944 add */
    /* @5030948 constant */
    /* @5030952 constant */
    /* @5030956 load */
    /* @5030964 constant */
    /* @5030968 add */
    /* @5030972 call */
    GM_SITE(vm, 716, 5030972);
    v177 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(115));
    v178 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(40));
    /* @5030980 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v177, v178, STR_REF(1204)));
    /* @5030984 string */
    /* @5030992 cast */
    /* @5030996 constant */
    /* @5031000 constant */
    /* @5031004 load */
    /* @5031012 constant */
    /* @5031016 add */
    /* @5031020 constant */
    /* @5031024 constant */
    /* @5031028 load */
    /* @5031036 constant */
    /* @5031040 add */
    /* @5031044 call */
    GM_SITE(vm, 716, 5031044);
    v179 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(115));
    v180 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(70));
    /* @5031052 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v179, v180, STR_REF(1207)));
    /* @5031056 b */
    goto L_5031560;
    L_5031060: ;
    /* @5031060 load */
    /* @5031068 constant */
    /* @5031072 cmp */
    /* @5031076 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_5031228;
    /* @5031080 string */
    /* @5031088 cast */
    /* @5031092 constant */
    /* @5031096 constant */
    /* @5031100 load */
    /* @5031108 constant */
    /* @5031112 add */
    /* @5031116 constant */
    /* @5031120 constant */
    /* @5031124 load */
    /* @5031132 constant */
    /* @5031136 add */
    /* @5031140 call */
    GM_SITE(vm, 716, 5031140);
    v181 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(115));
    v182 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(40));
    /* @5031148 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v181, v182, STR_REF(1204)));
    /* @5031152 string */
    /* @5031160 cast */
    /* @5031164 constant */
    /* @5031168 constant */
    /* @5031172 load */
    /* @5031180 constant */
    /* @5031184 add */
    /* @5031188 constant */
    /* @5031192 constant */
    /* @5031196 load */
    /* @5031204 constant */
    /* @5031208 add */
    /* @5031212 call */
    GM_SITE(vm, 716, 5031212);
    v183 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(115));
    v184 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(70));
    /* @5031220 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v183, v184, STR_REF(1207)));
    /* @5031224 b */
    goto L_5031560;
    L_5031228: ;
    /* @5031228 load */
    /* @5031236 constant */
    /* @5031240 cmp */
    /* @5031244 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_5031396;
    /* @5031248 string */
    /* @5031256 cast */
    /* @5031260 constant */
    /* @5031264 constant */
    /* @5031268 load */
    /* @5031276 constant */
    /* @5031280 add */
    /* @5031284 constant */
    /* @5031288 constant */
    /* @5031292 load */
    /* @5031300 constant */
    /* @5031304 add */
    /* @5031308 call */
    GM_SITE(vm, 716, 5031308);
    v185 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(40));
    v186 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(130));
    /* @5031316 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v185, v186, STR_REF(1204)));
    /* @5031320 string */
    /* @5031328 cast */
    /* @5031332 constant */
    /* @5031336 constant */
    /* @5031340 load */
    /* @5031348 constant */
    /* @5031352 add */
    /* @5031356 constant */
    /* @5031360 constant */
    /* @5031364 load */
    /* @5031372 constant */
    /* @5031376 add */
    /* @5031380 call */
    GM_SITE(vm, 716, 5031380);
    v187 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(114));
    v188 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(160));
    /* @5031388 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v187, v188, STR_REF(1205)));
    /* @5031392 b */
    goto L_5031560;
    L_5031396: ;
    /* @5031396 load */
    /* @5031404 constant */
    /* @5031408 cmp */
    /* @5031412 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_5031560;
    /* @5031416 string */
    /* @5031424 cast */
    /* @5031428 constant */
    /* @5031432 constant */
    /* @5031436 load */
    /* @5031444 constant */
    /* @5031448 add */
    /* @5031452 constant */
    /* @5031456 constant */
    /* @5031460 load */
    /* @5031468 constant */
    /* @5031472 add */
    /* @5031476 call */
    GM_SITE(vm, 716, 5031476);
    v189 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(40));
    v190 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(130));
    /* @5031484 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v189, v190, STR_REF(1204)));
    /* @5031488 string */
    /* @5031496 cast */
    /* @5031500 constant */
    /* @5031504 constant */
    /* @5031508 load */
    /* @5031516 constant */
    /* @5031520 add */
    /* @5031524 constant */
    /* @5031528 constant */
    /* @5031532 load */
    /* @5031540 constant */
    /* @5031544 add */
    /* @5031548 call */
    GM_SITE(vm, 716, 5031548);
    v191 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(114));
    v192 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(160));
    /* @5031556 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v191, v192, STR_REF(1208)));
    L_5031560: ;
    /* @5031560 load */
    /* @5031568 constant */
    /* @5031572 cmp */
    /* @5031576 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawcredit8") == VAL(1)))) goto L_5032196;
    /* @5031580 constant */
    /* @5031584 cast */
    /* @5031588 call */
    GM_SITE(vm, 716, 5031588);
    /* @5031596 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @5031600 constant */
    /* @5031608 cast */
    /* @5031612 call */
    GM_SITE(vm, 716, 5031612);
    /* @5031620 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5031624 load */
    /* @5031632 constant */
    /* @5031636 cmp */
    /* @5031640 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_5031720;
    /* @5031644 string */
    /* @5031652 cast */
    /* @5031656 constant */
    /* @5031660 constant */
    /* @5031664 load */
    /* @5031672 constant */
    /* @5031676 add */
    /* @5031680 constant */
    /* @5031684 constant */
    /* @5031688 load */
    /* @5031696 constant */
    /* @5031700 add */
    /* @5031704 call */
    GM_SITE(vm, 716, 5031704);
    v193 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(40));
    v194 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(160));
    /* @5031712 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v193, v194, STR_REF(1209)));
    /* @5031716 b */
    goto L_5032196;
    L_5031720: ;
    /* @5031720 load */
    /* @5031728 constant */
    /* @5031732 cmp */
    /* @5031736 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_5031816;
    /* @5031740 string */
    /* @5031748 cast */
    /* @5031752 constant */
    /* @5031756 constant */
    /* @5031760 load */
    /* @5031768 constant */
    /* @5031772 add */
    /* @5031776 constant */
    /* @5031780 constant */
    /* @5031784 load */
    /* @5031792 constant */
    /* @5031796 add */
    /* @5031800 call */
    GM_SITE(vm, 716, 5031800);
    v195 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(10));
    v196 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(160));
    /* @5031808 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v195, v196, STR_REF(1209)));
    /* @5031812 b */
    goto L_5032196;
    L_5031816: ;
    /* @5031816 load */
    /* @5031824 constant */
    /* @5031828 cmp */
    /* @5031832 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_5031912;
    /* @5031836 string */
    /* @5031844 cast */
    /* @5031848 constant */
    /* @5031852 constant */
    /* @5031856 load */
    /* @5031864 constant */
    /* @5031868 add */
    /* @5031872 constant */
    /* @5031876 constant */
    /* @5031880 load */
    /* @5031888 constant */
    /* @5031892 add */
    /* @5031896 call */
    GM_SITE(vm, 716, 5031896);
    v197 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(115));
    v198 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(50));
    /* @5031904 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v197, v198, STR_REF(1210)));
    /* @5031908 b */
    goto L_5032196;
    L_5031912: ;
    /* @5031912 load */
    /* @5031920 constant */
    /* @5031924 cmp */
    /* @5031928 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_5032008;
    /* @5031932 string */
    /* @5031940 cast */
    /* @5031944 constant */
    /* @5031948 constant */
    /* @5031952 load */
    /* @5031960 constant */
    /* @5031964 add */
    /* @5031968 constant */
    /* @5031972 constant */
    /* @5031976 load */
    /* @5031984 constant */
    /* @5031988 add */
    /* @5031992 call */
    GM_SITE(vm, 716, 5031992);
    v199 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(115));
    v200 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(50));
    /* @5032000 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v199, v200, STR_REF(1210)));
    /* @5032004 b */
    goto L_5032196;
    L_5032008: ;
    /* @5032008 load */
    /* @5032016 constant */
    /* @5032020 cmp */
    /* @5032024 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_5032104;
    /* @5032028 string */
    /* @5032036 cast */
    /* @5032040 constant */
    /* @5032044 constant */
    /* @5032048 load */
    /* @5032056 constant */
    /* @5032060 add */
    /* @5032064 constant */
    /* @5032068 constant */
    /* @5032072 load */
    /* @5032080 constant */
    /* @5032084 add */
    /* @5032088 call */
    GM_SITE(vm, 716, 5032088);
    v201 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(40));
    v202 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(160));
    /* @5032096 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v201, v202, STR_REF(1211)));
    /* @5032100 b */
    goto L_5032196;
    L_5032104: ;
    /* @5032104 load */
    /* @5032112 constant */
    /* @5032116 cmp */
    /* @5032120 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_5032196;
    /* @5032124 string */
    /* @5032132 cast */
    /* @5032136 constant */
    /* @5032140 constant */
    /* @5032144 load */
    /* @5032152 constant */
    /* @5032156 add */
    /* @5032160 constant */
    /* @5032164 constant */
    /* @5032168 load */
    /* @5032176 constant */
    /* @5032180 add */
    /* @5032184 call */
    GM_SITE(vm, 716, 5032184);
    v203 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(40));
    v204 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(160));
    /* @5032192 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v203, v204, STR_REF(1212)));
    L_5032196: ;
    /* @5032196 load */
    /* @5032204 constant */
    /* @5032208 cmp */
    /* @5032212 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawcredit9") == VAL(1)))) goto L_5032832;
    /* @5032216 constant */
    /* @5032220 cast */
    /* @5032224 call */
    GM_SITE(vm, 716, 5032224);
    /* @5032232 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @5032236 constant */
    /* @5032244 cast */
    /* @5032248 call */
    GM_SITE(vm, 716, 5032248);
    /* @5032256 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5032260 load */
    /* @5032268 constant */
    /* @5032272 cmp */
    /* @5032276 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_5032356;
    /* @5032280 string */
    /* @5032288 cast */
    /* @5032292 constant */
    /* @5032296 constant */
    /* @5032300 load */
    /* @5032308 constant */
    /* @5032312 add */
    /* @5032316 constant */
    /* @5032320 constant */
    /* @5032324 load */
    /* @5032332 constant */
    /* @5032336 add */
    /* @5032340 call */
    GM_SITE(vm, 716, 5032340);
    v205 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(40));
    v206 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(160));
    /* @5032348 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v205, v206, STR_REF(1213)));
    /* @5032352 b */
    goto L_5032832;
    L_5032356: ;
    /* @5032356 load */
    /* @5032364 constant */
    /* @5032368 cmp */
    /* @5032372 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_5032452;
    /* @5032376 string */
    /* @5032384 cast */
    /* @5032388 constant */
    /* @5032392 constant */
    /* @5032396 load */
    /* @5032404 constant */
    /* @5032408 add */
    /* @5032412 constant */
    /* @5032416 constant */
    /* @5032420 load */
    /* @5032428 constant */
    /* @5032432 add */
    /* @5032436 call */
    GM_SITE(vm, 716, 5032436);
    v207 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(10));
    v208 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(160));
    /* @5032444 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v207, v208, STR_REF(1213)));
    /* @5032448 b */
    goto L_5032832;
    L_5032452: ;
    /* @5032452 load */
    /* @5032460 constant */
    /* @5032464 cmp */
    /* @5032468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_5032548;
    /* @5032472 string */
    /* @5032480 cast */
    /* @5032484 constant */
    /* @5032488 constant */
    /* @5032492 load */
    /* @5032500 constant */
    /* @5032504 add */
    /* @5032508 constant */
    /* @5032512 constant */
    /* @5032516 load */
    /* @5032524 constant */
    /* @5032528 add */
    /* @5032532 call */
    GM_SITE(vm, 716, 5032532);
    v209 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(115));
    v210 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(50));
    /* @5032540 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v209, v210, STR_REF(1213)));
    /* @5032544 b */
    goto L_5032832;
    L_5032548: ;
    /* @5032548 load */
    /* @5032556 constant */
    /* @5032560 cmp */
    /* @5032564 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_5032644;
    /* @5032568 string */
    /* @5032576 cast */
    /* @5032580 constant */
    /* @5032584 constant */
    /* @5032588 load */
    /* @5032596 constant */
    /* @5032600 add */
    /* @5032604 constant */
    /* @5032608 constant */
    /* @5032612 load */
    /* @5032620 constant */
    /* @5032624 add */
    /* @5032628 call */
    GM_SITE(vm, 716, 5032628);
    v211 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(115));
    v212 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(50));
    /* @5032636 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v211, v212, STR_REF(1213)));
    /* @5032640 b */
    goto L_5032832;
    L_5032644: ;
    /* @5032644 load */
    /* @5032652 constant */
    /* @5032656 cmp */
    /* @5032660 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_5032740;
    /* @5032664 string */
    /* @5032672 cast */
    /* @5032676 constant */
    /* @5032680 constant */
    /* @5032684 load */
    /* @5032692 constant */
    /* @5032696 add */
    /* @5032700 constant */
    /* @5032704 constant */
    /* @5032708 load */
    /* @5032716 constant */
    /* @5032720 add */
    /* @5032724 call */
    GM_SITE(vm, 716, 5032724);
    v213 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(40));
    v214 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(160));
    /* @5032732 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v213, v214, STR_REF(1213)));
    /* @5032736 b */
    goto L_5032832;
    L_5032740: ;
    /* @5032740 load */
    /* @5032748 constant */
    /* @5032752 cmp */
    /* @5032756 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_5032832;
    /* @5032760 string */
    /* @5032768 cast */
    /* @5032772 constant */
    /* @5032776 constant */
    /* @5032780 load */
    /* @5032788 constant */
    /* @5032792 add */
    /* @5032796 constant */
    /* @5032800 constant */
    /* @5032804 load */
    /* @5032812 constant */
    /* @5032816 add */
    /* @5032820 call */
    GM_SITE(vm, 716, 5032820);
    v215 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(40));
    v216 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(160));
    /* @5032828 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v215, v216, STR_REF(1213)));
    L_5032832: ;
    return;
}
