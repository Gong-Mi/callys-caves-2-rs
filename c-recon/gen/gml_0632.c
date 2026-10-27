/* generated from CODE 632 (gml_Object_obj_lloydtutorial11_Draw_0), source start 4945872, end 4957504. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0632(GmVM* vm) {
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
    Val p4957488_0;
    Val v169;
    /* @4945872 constant */
    /* @4945876 load */
    /* @4945884 cast */
    /* @4945888 load */
    /* @4945896 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4945904 constant */
    /* @4945908 load */
    /* @4945916 cast */
    /* @4945920 load */
    /* @4945928 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4945936 load */
    /* @4945944 constant */
    /* @4945948 cmp */
    /* @4945952 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4946480;
    /* @4945956 constant */
    /* @4945960 cast */
    /* @4945964 constant */
    /* @4945968 cast */
    /* @4945972 constant */
    /* @4945976 cast */
    /* @4945980 constant */
    /* @4945992 cast */
    /* @4945996 constant */
    /* @4946008 cast */
    /* @4946012 constant */
    /* @4946016 constant */
    /* @4946020 load */
    /* @4946028 constant */
    /* @4946032 constant */
    /* @4946036 load */
    /* @4946044 constant */
    /* @4946048 sub */
    /* @4946052 constant */
    /* @4946056 cast */
    /* @4946060 constant */
    /* @4946064 cast */
    /* @4946068 call */
    GM_SITE(vm, 632, 4946068);
    /* @4946076 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(0.96), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4946080 constant */
    /* @4946084 cast */
    /* @4946088 constant */
    /* @4946092 cast */
    /* @4946096 constant */
    /* @4946100 cast */
    /* @4946104 constant */
    /* @4946108 cast */
    /* @4946112 constant */
    /* @4946116 cast */
    /* @4946120 constant */
    /* @4946124 load */
    /* @4946132 cast */
    /* @4946136 load */
    /* @4946144 constant */
    /* @4946148 add */
    /* @4946152 constant */
    /* @4946156 load */
    /* @4946164 cast */
    /* @4946168 load */
    /* @4946176 constant */
    /* @4946180 add */
    /* @4946184 constant */
    /* @4946188 cast */
    /* @4946192 constant */
    /* @4946196 cast */
    /* @4946200 call */
    GM_SITE(vm, 632, 4946200);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4946208 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v1, v2, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4946212 constant */
    /* @4946216 cast */
    /* @4946220 constant */
    /* @4946224 cast */
    /* @4946228 constant */
    /* @4946232 cast */
    /* @4946236 constant */
    /* @4946240 cast */
    /* @4946244 constant */
    /* @4946248 cast */
    /* @4946252 constant */
    /* @4946256 load */
    /* @4946264 cast */
    /* @4946268 load */
    /* @4946276 constant */
    /* @4946280 add */
    /* @4946284 constant */
    /* @4946288 load */
    /* @4946296 cast */
    /* @4946300 load */
    /* @4946308 constant */
    /* @4946312 add */
    /* @4946316 constant */
    /* @4946320 cast */
    /* @4946324 constant */
    /* @4946328 cast */
    /* @4946332 call */
    GM_SITE(vm, 632, 4946332);
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4946340 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v3, v4, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4946344 load */
    /* @4946352 constant */
    /* @4946356 cmp */
    /* @4946360 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4946480;
    /* @4946364 constant */
    /* @4946368 cast */
    /* @4946372 call */
    GM_SITE(vm, 632, 4946372);
    /* @4946380 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4946384 constant */
    /* @4946392 cast */
    /* @4946396 call */
    GM_SITE(vm, 632, 4946396);
    /* @4946404 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4946408 string */
    /* @4946416 cast */
    /* @4946420 constant */
    /* @4946424 constant */
    /* @4946428 load */
    /* @4946436 constant */
    /* @4946440 add */
    /* @4946444 constant */
    /* @4946448 constant */
    /* @4946452 load */
    /* @4946460 constant */
    /* @4946464 add */
    /* @4946468 call */
    GM_SITE(vm, 632, 4946468);
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(150));
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(200));
    /* @4946476 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v5, v6, STR_REF(743)));
    L_4946480: ;
    /* @4946480 load */
    /* @4946488 constant */
    /* @4946492 cmp */
    /* @4946496 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4947024;
    /* @4946500 constant */
    /* @4946504 cast */
    /* @4946508 constant */
    /* @4946512 cast */
    /* @4946516 constant */
    /* @4946520 cast */
    /* @4946524 constant */
    /* @4946536 cast */
    /* @4946540 constant */
    /* @4946552 cast */
    /* @4946556 constant */
    /* @4946560 constant */
    /* @4946564 load */
    /* @4946572 constant */
    /* @4946576 constant */
    /* @4946580 load */
    /* @4946588 constant */
    /* @4946592 sub */
    /* @4946596 constant */
    /* @4946600 cast */
    /* @4946604 constant */
    /* @4946608 cast */
    /* @4946612 call */
    GM_SITE(vm, 632, 4946612);
    /* @4946620 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(0.82), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4946624 constant */
    /* @4946628 cast */
    /* @4946632 constant */
    /* @4946636 cast */
    /* @4946640 constant */
    /* @4946644 cast */
    /* @4946648 constant */
    /* @4946652 cast */
    /* @4946656 constant */
    /* @4946660 cast */
    /* @4946664 constant */
    /* @4946668 load */
    /* @4946676 cast */
    /* @4946680 load */
    /* @4946688 constant */
    /* @4946692 add */
    /* @4946696 constant */
    /* @4946700 load */
    /* @4946708 cast */
    /* @4946712 load */
    /* @4946720 constant */
    /* @4946724 add */
    /* @4946728 constant */
    /* @4946732 cast */
    /* @4946736 constant */
    /* @4946740 cast */
    /* @4946744 call */
    GM_SITE(vm, 632, 4946744);
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4946752 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v7, v8, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4946756 constant */
    /* @4946760 cast */
    /* @4946764 constant */
    /* @4946768 cast */
    /* @4946772 constant */
    /* @4946776 cast */
    /* @4946780 constant */
    /* @4946784 cast */
    /* @4946788 constant */
    /* @4946792 cast */
    /* @4946796 constant */
    /* @4946800 load */
    /* @4946808 cast */
    /* @4946812 load */
    /* @4946820 constant */
    /* @4946824 add */
    /* @4946828 constant */
    /* @4946832 load */
    /* @4946840 cast */
    /* @4946844 load */
    /* @4946852 constant */
    /* @4946856 add */
    /* @4946860 constant */
    /* @4946864 cast */
    /* @4946868 constant */
    /* @4946872 cast */
    /* @4946876 call */
    GM_SITE(vm, 632, 4946876);
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(320));
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4946884 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v9, v10, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4946888 load */
    /* @4946896 constant */
    /* @4946900 cmp */
    /* @4946904 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4947024;
    /* @4946908 constant */
    /* @4946912 cast */
    /* @4946916 call */
    GM_SITE(vm, 632, 4946916);
    /* @4946924 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4946928 constant */
    /* @4946936 cast */
    /* @4946940 call */
    GM_SITE(vm, 632, 4946940);
    /* @4946948 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4946952 string */
    /* @4946960 cast */
    /* @4946964 constant */
    /* @4946968 constant */
    /* @4946972 load */
    /* @4946980 constant */
    /* @4946984 add */
    /* @4946988 constant */
    /* @4946992 constant */
    /* @4946996 load */
    /* @4947004 constant */
    /* @4947008 add */
    /* @4947012 call */
    GM_SITE(vm, 632, 4947012);
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(110));
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4947020 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v11, v12, STR_REF(743)));
    L_4947024: ;
    /* @4947024 load */
    /* @4947032 constant */
    /* @4947036 cmp */
    /* @4947040 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4947568;
    /* @4947044 constant */
    /* @4947048 cast */
    /* @4947052 constant */
    /* @4947056 cast */
    /* @4947060 constant */
    /* @4947064 cast */
    /* @4947068 constant */
    /* @4947080 cast */
    /* @4947084 constant */
    /* @4947096 cast */
    /* @4947100 constant */
    /* @4947104 constant */
    /* @4947108 load */
    /* @4947116 constant */
    /* @4947120 constant */
    /* @4947124 load */
    /* @4947132 constant */
    /* @4947136 sub */
    /* @4947140 constant */
    /* @4947144 cast */
    /* @4947148 constant */
    /* @4947152 cast */
    /* @4947156 call */
    GM_SITE(vm, 632, 4947156);
    /* @4947164 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4947168 constant */
    /* @4947172 cast */
    /* @4947176 constant */
    /* @4947180 cast */
    /* @4947184 constant */
    /* @4947188 cast */
    /* @4947192 constant */
    /* @4947196 cast */
    /* @4947200 constant */
    /* @4947204 cast */
    /* @4947208 constant */
    /* @4947212 load */
    /* @4947220 cast */
    /* @4947224 load */
    /* @4947232 constant */
    /* @4947236 add */
    /* @4947240 constant */
    /* @4947244 load */
    /* @4947252 cast */
    /* @4947256 load */
    /* @4947264 constant */
    /* @4947268 add */
    /* @4947272 constant */
    /* @4947276 cast */
    /* @4947280 constant */
    /* @4947284 cast */
    /* @4947288 call */
    GM_SITE(vm, 632, 4947288);
    v13 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4947296 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v13, v14, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4947300 constant */
    /* @4947304 cast */
    /* @4947308 constant */
    /* @4947312 cast */
    /* @4947316 constant */
    /* @4947320 cast */
    /* @4947324 constant */
    /* @4947328 cast */
    /* @4947332 constant */
    /* @4947336 cast */
    /* @4947340 constant */
    /* @4947344 load */
    /* @4947352 cast */
    /* @4947356 load */
    /* @4947364 constant */
    /* @4947368 add */
    /* @4947372 constant */
    /* @4947376 load */
    /* @4947384 cast */
    /* @4947388 load */
    /* @4947396 constant */
    /* @4947400 add */
    /* @4947404 constant */
    /* @4947408 cast */
    /* @4947412 constant */
    /* @4947416 cast */
    /* @4947420 call */
    GM_SITE(vm, 632, 4947420);
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4947428 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v15, v16, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4947432 load */
    /* @4947440 constant */
    /* @4947444 cmp */
    /* @4947448 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4947568;
    /* @4947452 constant */
    /* @4947456 cast */
    /* @4947460 call */
    GM_SITE(vm, 632, 4947460);
    /* @4947468 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4947472 constant */
    /* @4947480 cast */
    /* @4947484 call */
    GM_SITE(vm, 632, 4947484);
    /* @4947492 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4947496 string */
    /* @4947504 cast */
    /* @4947508 constant */
    /* @4947512 constant */
    /* @4947516 load */
    /* @4947524 constant */
    /* @4947528 add */
    /* @4947532 constant */
    /* @4947536 constant */
    /* @4947540 load */
    /* @4947548 constant */
    /* @4947552 add */
    /* @4947556 call */
    GM_SITE(vm, 632, 4947556);
    v17 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(180));
    v18 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(300));
    /* @4947564 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v17, v18, STR_REF(743)));
    L_4947568: ;
    /* @4947568 load */
    /* @4947576 constant */
    /* @4947580 cmp */
    /* @4947584 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4948112;
    /* @4947588 constant */
    /* @4947592 cast */
    /* @4947596 constant */
    /* @4947600 cast */
    /* @4947604 constant */
    /* @4947608 cast */
    /* @4947612 constant */
    /* @4947624 cast */
    /* @4947628 constant */
    /* @4947640 cast */
    /* @4947644 constant */
    /* @4947648 constant */
    /* @4947652 load */
    /* @4947660 constant */
    /* @4947664 constant */
    /* @4947668 load */
    /* @4947676 constant */
    /* @4947680 sub */
    /* @4947684 constant */
    /* @4947688 cast */
    /* @4947692 constant */
    /* @4947696 cast */
    /* @4947700 call */
    GM_SITE(vm, 632, 4947700);
    /* @4947708 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4947712 constant */
    /* @4947716 cast */
    /* @4947720 constant */
    /* @4947724 cast */
    /* @4947728 constant */
    /* @4947732 cast */
    /* @4947736 constant */
    /* @4947740 cast */
    /* @4947744 constant */
    /* @4947748 cast */
    /* @4947752 constant */
    /* @4947756 load */
    /* @4947764 cast */
    /* @4947768 load */
    /* @4947776 constant */
    /* @4947780 add */
    /* @4947784 constant */
    /* @4947788 load */
    /* @4947796 cast */
    /* @4947800 load */
    /* @4947808 constant */
    /* @4947812 add */
    /* @4947816 constant */
    /* @4947820 cast */
    /* @4947824 constant */
    /* @4947828 cast */
    /* @4947832 call */
    GM_SITE(vm, 632, 4947832);
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4947840 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v19, v20, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4947844 constant */
    /* @4947848 cast */
    /* @4947852 constant */
    /* @4947856 cast */
    /* @4947860 constant */
    /* @4947864 cast */
    /* @4947868 constant */
    /* @4947872 cast */
    /* @4947876 constant */
    /* @4947880 cast */
    /* @4947884 constant */
    /* @4947888 load */
    /* @4947896 cast */
    /* @4947900 load */
    /* @4947908 constant */
    /* @4947912 add */
    /* @4947916 constant */
    /* @4947920 load */
    /* @4947928 cast */
    /* @4947932 load */
    /* @4947940 constant */
    /* @4947944 add */
    /* @4947948 constant */
    /* @4947952 cast */
    /* @4947956 constant */
    /* @4947960 cast */
    /* @4947964 call */
    GM_SITE(vm, 632, 4947964);
    v21 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4947972 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v21, v22, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4947976 load */
    /* @4947984 constant */
    /* @4947988 cmp */
    /* @4947992 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4948112;
    /* @4947996 constant */
    /* @4948000 cast */
    /* @4948004 call */
    GM_SITE(vm, 632, 4948004);
    /* @4948012 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4948016 constant */
    /* @4948024 cast */
    /* @4948028 call */
    GM_SITE(vm, 632, 4948028);
    /* @4948036 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4948040 string */
    /* @4948048 cast */
    /* @4948052 constant */
    /* @4948056 constant */
    /* @4948060 load */
    /* @4948068 constant */
    /* @4948072 add */
    /* @4948076 constant */
    /* @4948080 constant */
    /* @4948084 load */
    /* @4948092 constant */
    /* @4948096 add */
    /* @4948100 call */
    GM_SITE(vm, 632, 4948100);
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(180));
    v24 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(300));
    /* @4948108 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v23, v24, STR_REF(743)));
    L_4948112: ;
    /* @4948112 load */
    /* @4948120 constant */
    /* @4948124 cmp */
    /* @4948128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4948656;
    /* @4948132 constant */
    /* @4948136 cast */
    /* @4948140 constant */
    /* @4948144 cast */
    /* @4948148 constant */
    /* @4948152 cast */
    /* @4948156 constant */
    /* @4948168 cast */
    /* @4948172 constant */
    /* @4948184 cast */
    /* @4948188 constant */
    /* @4948192 constant */
    /* @4948196 load */
    /* @4948204 constant */
    /* @4948208 constant */
    /* @4948212 load */
    /* @4948220 constant */
    /* @4948224 sub */
    /* @4948228 constant */
    /* @4948232 cast */
    /* @4948236 constant */
    /* @4948240 cast */
    /* @4948244 call */
    GM_SITE(vm, 632, 4948244);
    /* @4948252 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(0.97), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4948256 constant */
    /* @4948260 cast */
    /* @4948264 constant */
    /* @4948268 cast */
    /* @4948272 constant */
    /* @4948276 cast */
    /* @4948280 constant */
    /* @4948284 cast */
    /* @4948288 constant */
    /* @4948292 cast */
    /* @4948296 constant */
    /* @4948300 load */
    /* @4948308 cast */
    /* @4948312 load */
    /* @4948320 constant */
    /* @4948324 add */
    /* @4948328 constant */
    /* @4948332 load */
    /* @4948340 cast */
    /* @4948344 load */
    /* @4948352 constant */
    /* @4948356 add */
    /* @4948360 constant */
    /* @4948364 cast */
    /* @4948368 constant */
    /* @4948372 cast */
    /* @4948376 call */
    GM_SITE(vm, 632, 4948376);
    v25 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v26 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4948384 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v25, v26, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4948388 constant */
    /* @4948392 cast */
    /* @4948396 constant */
    /* @4948400 cast */
    /* @4948404 constant */
    /* @4948408 cast */
    /* @4948412 constant */
    /* @4948416 cast */
    /* @4948420 constant */
    /* @4948424 cast */
    /* @4948428 constant */
    /* @4948432 load */
    /* @4948440 cast */
    /* @4948444 load */
    /* @4948452 constant */
    /* @4948456 add */
    /* @4948460 constant */
    /* @4948464 load */
    /* @4948472 cast */
    /* @4948476 load */
    /* @4948484 constant */
    /* @4948488 add */
    /* @4948492 constant */
    /* @4948496 cast */
    /* @4948500 constant */
    /* @4948504 cast */
    /* @4948508 call */
    GM_SITE(vm, 632, 4948508);
    v27 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v28 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4948516 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v27, v28, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4948520 load */
    /* @4948528 constant */
    /* @4948532 cmp */
    /* @4948536 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4948656;
    /* @4948540 constant */
    /* @4948544 cast */
    /* @4948548 call */
    GM_SITE(vm, 632, 4948548);
    /* @4948556 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4948560 constant */
    /* @4948568 cast */
    /* @4948572 call */
    GM_SITE(vm, 632, 4948572);
    /* @4948580 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4948584 string */
    /* @4948592 cast */
    /* @4948596 constant */
    /* @4948600 constant */
    /* @4948604 load */
    /* @4948612 constant */
    /* @4948616 add */
    /* @4948620 constant */
    /* @4948624 constant */
    /* @4948628 load */
    /* @4948636 constant */
    /* @4948640 add */
    /* @4948644 call */
    GM_SITE(vm, 632, 4948644);
    v29 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(150));
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(200));
    /* @4948652 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v29, v30, STR_REF(743)));
    L_4948656: ;
    /* @4948656 load */
    /* @4948664 constant */
    /* @4948668 cmp */
    /* @4948672 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4949200;
    /* @4948676 constant */
    /* @4948680 cast */
    /* @4948684 constant */
    /* @4948688 cast */
    /* @4948692 constant */
    /* @4948696 cast */
    /* @4948700 constant */
    /* @4948712 cast */
    /* @4948716 constant */
    /* @4948728 cast */
    /* @4948732 constant */
    /* @4948736 constant */
    /* @4948740 load */
    /* @4948748 constant */
    /* @4948752 constant */
    /* @4948756 load */
    /* @4948764 constant */
    /* @4948768 sub */
    /* @4948772 constant */
    /* @4948776 cast */
    /* @4948780 constant */
    /* @4948784 cast */
    /* @4948788 call */
    GM_SITE(vm, 632, 4948788);
    /* @4948796 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(1.06), VAL(0.86), VAL(0), VAL(-1), VAL(1)));
    /* @4948800 constant */
    /* @4948804 cast */
    /* @4948808 constant */
    /* @4948812 cast */
    /* @4948816 constant */
    /* @4948820 cast */
    /* @4948824 constant */
    /* @4948828 cast */
    /* @4948832 constant */
    /* @4948836 cast */
    /* @4948840 constant */
    /* @4948844 load */
    /* @4948852 cast */
    /* @4948856 load */
    /* @4948864 constant */
    /* @4948868 add */
    /* @4948872 constant */
    /* @4948876 load */
    /* @4948884 cast */
    /* @4948888 load */
    /* @4948896 constant */
    /* @4948900 add */
    /* @4948904 constant */
    /* @4948908 cast */
    /* @4948912 constant */
    /* @4948916 cast */
    /* @4948920 call */
    GM_SITE(vm, 632, 4948920);
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v32 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4948928 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v31, v32, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4948932 constant */
    /* @4948936 cast */
    /* @4948940 constant */
    /* @4948944 cast */
    /* @4948948 constant */
    /* @4948952 cast */
    /* @4948956 constant */
    /* @4948960 cast */
    /* @4948964 constant */
    /* @4948968 cast */
    /* @4948972 constant */
    /* @4948976 load */
    /* @4948984 cast */
    /* @4948988 load */
    /* @4948996 constant */
    /* @4949000 add */
    /* @4949004 constant */
    /* @4949008 load */
    /* @4949016 cast */
    /* @4949020 load */
    /* @4949028 constant */
    /* @4949032 add */
    /* @4949036 constant */
    /* @4949040 cast */
    /* @4949044 constant */
    /* @4949048 cast */
    /* @4949052 call */
    GM_SITE(vm, 632, 4949052);
    v33 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(390));
    v34 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4949060 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v33, v34, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4949064 load */
    /* @4949072 constant */
    /* @4949076 cmp */
    /* @4949080 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4949200;
    /* @4949084 constant */
    /* @4949088 cast */
    /* @4949092 call */
    GM_SITE(vm, 632, 4949092);
    /* @4949100 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4949104 constant */
    /* @4949112 cast */
    /* @4949116 call */
    GM_SITE(vm, 632, 4949116);
    /* @4949124 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4949128 string */
    /* @4949136 cast */
    /* @4949140 constant */
    /* @4949144 constant */
    /* @4949148 load */
    /* @4949156 constant */
    /* @4949160 add */
    /* @4949164 constant */
    /* @4949168 constant */
    /* @4949172 load */
    /* @4949180 constant */
    /* @4949184 add */
    /* @4949188 call */
    GM_SITE(vm, 632, 4949188);
    v35 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(160));
    v36 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(200));
    /* @4949196 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v35, v36, STR_REF(743)));
    L_4949200: ;
    /* @4949200 load */
    /* @4949208 constant */
    /* @4949212 cmp */
    /* @4949216 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel1") == VAL(1)))) goto L_4950660;
    /* @4949220 load */
    /* @4949228 constant */
    /* @4949232 cmp */
    /* @4949236 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4949460;
    /* @4949240 constant */
    /* @4949244 cast */
    /* @4949248 call */
    GM_SITE(vm, 632, 4949248);
    /* @4949256 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4949260 constant */
    /* @4949268 cast */
    /* @4949272 call */
    GM_SITE(vm, 632, 4949272);
    /* @4949280 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4949284 string */
    /* @4949292 cast */
    /* @4949296 constant */
    /* @4949300 load */
    /* @4949308 cast */
    /* @4949312 load */
    /* @4949320 constant */
    /* @4949324 add */
    /* @4949328 constant */
    /* @4949332 load */
    /* @4949340 cast */
    /* @4949344 load */
    /* @4949352 constant */
    /* @4949356 add */
    /* @4949360 call */
    GM_SITE(vm, 632, 4949360);
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4949368 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v37, v38, STR_REF(1110)));
    /* @4949372 string */
    /* @4949380 cast */
    /* @4949384 constant */
    /* @4949388 load */
    /* @4949396 cast */
    /* @4949400 load */
    /* @4949408 constant */
    /* @4949412 add */
    /* @4949416 constant */
    /* @4949420 load */
    /* @4949428 cast */
    /* @4949432 load */
    /* @4949440 constant */
    /* @4949444 add */
    /* @4949448 call */
    GM_SITE(vm, 632, 4949448);
    v39 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v40 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4949456 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, v40, STR_REF(1111)));
    L_4949460: ;
    /* @4949460 load */
    /* @4949468 constant */
    /* @4949472 cmp */
    /* @4949476 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4949700;
    /* @4949480 constant */
    /* @4949484 cast */
    /* @4949488 call */
    GM_SITE(vm, 632, 4949488);
    /* @4949496 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4949500 constant */
    /* @4949508 cast */
    /* @4949512 call */
    GM_SITE(vm, 632, 4949512);
    /* @4949520 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4949524 string */
    /* @4949532 cast */
    /* @4949536 constant */
    /* @4949540 load */
    /* @4949548 cast */
    /* @4949552 load */
    /* @4949560 constant */
    /* @4949564 add */
    /* @4949568 constant */
    /* @4949572 load */
    /* @4949580 cast */
    /* @4949584 load */
    /* @4949592 constant */
    /* @4949596 add */
    /* @4949600 call */
    GM_SITE(vm, 632, 4949600);
    v41 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v42 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4949608 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v41, v42, STR_REF(1110)));
    /* @4949612 string */
    /* @4949620 cast */
    /* @4949624 constant */
    /* @4949628 load */
    /* @4949636 cast */
    /* @4949640 load */
    /* @4949648 constant */
    /* @4949652 add */
    /* @4949656 constant */
    /* @4949660 load */
    /* @4949668 cast */
    /* @4949672 load */
    /* @4949680 constant */
    /* @4949684 add */
    /* @4949688 call */
    GM_SITE(vm, 632, 4949688);
    v43 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v44 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4949696 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v43, v44, STR_REF(1111)));
    L_4949700: ;
    /* @4949700 load */
    /* @4949708 constant */
    /* @4949712 cmp */
    /* @4949716 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4949940;
    /* @4949720 constant */
    /* @4949724 cast */
    /* @4949728 call */
    GM_SITE(vm, 632, 4949728);
    /* @4949736 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4949740 constant */
    /* @4949748 cast */
    /* @4949752 call */
    GM_SITE(vm, 632, 4949752);
    /* @4949760 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4949764 string */
    /* @4949772 cast */
    /* @4949776 constant */
    /* @4949780 load */
    /* @4949788 cast */
    /* @4949792 load */
    /* @4949800 constant */
    /* @4949804 add */
    /* @4949808 constant */
    /* @4949812 load */
    /* @4949820 cast */
    /* @4949824 load */
    /* @4949832 constant */
    /* @4949836 add */
    /* @4949840 call */
    GM_SITE(vm, 632, 4949840);
    v45 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v46 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4949848 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v45, v46, STR_REF(1110)));
    /* @4949852 string */
    /* @4949860 cast */
    /* @4949864 constant */
    /* @4949868 load */
    /* @4949876 cast */
    /* @4949880 load */
    /* @4949888 constant */
    /* @4949892 add */
    /* @4949896 constant */
    /* @4949900 load */
    /* @4949908 cast */
    /* @4949912 load */
    /* @4949920 constant */
    /* @4949924 add */
    /* @4949928 call */
    GM_SITE(vm, 632, 4949928);
    v47 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v48 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4949936 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v47, v48, STR_REF(1111)));
    L_4949940: ;
    /* @4949940 load */
    /* @4949948 constant */
    /* @4949952 cmp */
    /* @4949956 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4950180;
    /* @4949960 constant */
    /* @4949964 cast */
    /* @4949968 call */
    GM_SITE(vm, 632, 4949968);
    /* @4949976 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4949980 constant */
    /* @4949988 cast */
    /* @4949992 call */
    GM_SITE(vm, 632, 4949992);
    /* @4950000 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4950004 string */
    /* @4950012 cast */
    /* @4950016 constant */
    /* @4950020 load */
    /* @4950028 cast */
    /* @4950032 load */
    /* @4950040 constant */
    /* @4950044 add */
    /* @4950048 constant */
    /* @4950052 load */
    /* @4950060 cast */
    /* @4950064 load */
    /* @4950072 constant */
    /* @4950076 add */
    /* @4950080 call */
    GM_SITE(vm, 632, 4950080);
    v49 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v50 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4950088 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v49, v50, STR_REF(1110)));
    /* @4950092 string */
    /* @4950100 cast */
    /* @4950104 constant */
    /* @4950108 load */
    /* @4950116 cast */
    /* @4950120 load */
    /* @4950128 constant */
    /* @4950132 add */
    /* @4950136 constant */
    /* @4950140 load */
    /* @4950148 cast */
    /* @4950152 load */
    /* @4950160 constant */
    /* @4950164 add */
    /* @4950168 call */
    GM_SITE(vm, 632, 4950168);
    v51 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v52 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4950176 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v51, v52, STR_REF(1111)));
    L_4950180: ;
    /* @4950180 load */
    /* @4950188 constant */
    /* @4950192 cmp */
    /* @4950196 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4950420;
    /* @4950200 constant */
    /* @4950204 cast */
    /* @4950208 call */
    GM_SITE(vm, 632, 4950208);
    /* @4950216 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4950220 constant */
    /* @4950228 cast */
    /* @4950232 call */
    GM_SITE(vm, 632, 4950232);
    /* @4950240 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4950244 string */
    /* @4950252 cast */
    /* @4950256 constant */
    /* @4950260 load */
    /* @4950268 cast */
    /* @4950272 load */
    /* @4950280 constant */
    /* @4950284 add */
    /* @4950288 constant */
    /* @4950292 load */
    /* @4950300 cast */
    /* @4950304 load */
    /* @4950312 constant */
    /* @4950316 add */
    /* @4950320 call */
    GM_SITE(vm, 632, 4950320);
    v53 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v54 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4950328 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v53, v54, STR_REF(1110)));
    /* @4950332 string */
    /* @4950340 cast */
    /* @4950344 constant */
    /* @4950348 load */
    /* @4950356 cast */
    /* @4950360 load */
    /* @4950368 constant */
    /* @4950372 add */
    /* @4950376 constant */
    /* @4950380 load */
    /* @4950388 cast */
    /* @4950392 load */
    /* @4950400 constant */
    /* @4950404 add */
    /* @4950408 call */
    GM_SITE(vm, 632, 4950408);
    v55 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v56 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4950416 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v55, v56, STR_REF(1111)));
    L_4950420: ;
    /* @4950420 load */
    /* @4950428 constant */
    /* @4950432 cmp */
    /* @4950436 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4950660;
    /* @4950440 constant */
    /* @4950444 cast */
    /* @4950448 call */
    GM_SITE(vm, 632, 4950448);
    /* @4950456 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4950460 constant */
    /* @4950468 cast */
    /* @4950472 call */
    GM_SITE(vm, 632, 4950472);
    /* @4950480 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4950484 string */
    /* @4950492 cast */
    /* @4950496 constant */
    /* @4950500 load */
    /* @4950508 cast */
    /* @4950512 load */
    /* @4950520 constant */
    /* @4950524 add */
    /* @4950528 constant */
    /* @4950532 load */
    /* @4950540 cast */
    /* @4950544 load */
    /* @4950552 constant */
    /* @4950556 add */
    /* @4950560 call */
    GM_SITE(vm, 632, 4950560);
    v57 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v58 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4950568 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v57, v58, STR_REF(1110)));
    /* @4950572 string */
    /* @4950580 cast */
    /* @4950584 constant */
    /* @4950588 load */
    /* @4950596 cast */
    /* @4950600 load */
    /* @4950608 constant */
    /* @4950612 add */
    /* @4950616 constant */
    /* @4950620 load */
    /* @4950628 cast */
    /* @4950632 load */
    /* @4950640 constant */
    /* @4950644 add */
    /* @4950648 call */
    GM_SITE(vm, 632, 4950648);
    v59 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v60 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4950656 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v59, v60, STR_REF(1111)));
    L_4950660: ;
    /* @4950660 load */
    /* @4950668 constant */
    /* @4950672 cmp */
    /* @4950676 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel2") == VAL(1)))) goto L_4952120;
    /* @4950680 load */
    /* @4950688 constant */
    /* @4950692 cmp */
    /* @4950696 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4950920;
    /* @4950700 constant */
    /* @4950704 cast */
    /* @4950708 call */
    GM_SITE(vm, 632, 4950708);
    /* @4950716 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4950720 constant */
    /* @4950728 cast */
    /* @4950732 call */
    GM_SITE(vm, 632, 4950732);
    /* @4950740 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4950744 string */
    /* @4950752 cast */
    /* @4950756 constant */
    /* @4950760 load */
    /* @4950768 cast */
    /* @4950772 load */
    /* @4950780 constant */
    /* @4950784 add */
    /* @4950788 constant */
    /* @4950792 load */
    /* @4950800 cast */
    /* @4950804 load */
    /* @4950812 constant */
    /* @4950816 add */
    /* @4950820 call */
    GM_SITE(vm, 632, 4950820);
    v61 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v62 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4950828 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v61, v62, STR_REF(1112)));
    /* @4950832 string */
    /* @4950840 cast */
    /* @4950844 constant */
    /* @4950848 load */
    /* @4950856 cast */
    /* @4950860 load */
    /* @4950868 constant */
    /* @4950872 add */
    /* @4950876 constant */
    /* @4950880 load */
    /* @4950888 cast */
    /* @4950892 load */
    /* @4950900 constant */
    /* @4950904 add */
    /* @4950908 call */
    GM_SITE(vm, 632, 4950908);
    v63 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v64 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4950916 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v63, v64, STR_REF(1113)));
    L_4950920: ;
    /* @4950920 load */
    /* @4950928 constant */
    /* @4950932 cmp */
    /* @4950936 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4951160;
    /* @4950940 constant */
    /* @4950944 cast */
    /* @4950948 call */
    GM_SITE(vm, 632, 4950948);
    /* @4950956 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4950960 constant */
    /* @4950968 cast */
    /* @4950972 call */
    GM_SITE(vm, 632, 4950972);
    /* @4950980 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4950984 string */
    /* @4950992 cast */
    /* @4950996 constant */
    /* @4951000 load */
    /* @4951008 cast */
    /* @4951012 load */
    /* @4951020 constant */
    /* @4951024 add */
    /* @4951028 constant */
    /* @4951032 load */
    /* @4951040 cast */
    /* @4951044 load */
    /* @4951052 constant */
    /* @4951056 add */
    /* @4951060 call */
    GM_SITE(vm, 632, 4951060);
    v65 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v66 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    /* @4951068 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v65, v66, STR_REF(1112)));
    /* @4951072 string */
    /* @4951080 cast */
    /* @4951084 constant */
    /* @4951088 load */
    /* @4951096 cast */
    /* @4951100 load */
    /* @4951108 constant */
    /* @4951112 add */
    /* @4951116 constant */
    /* @4951120 load */
    /* @4951128 cast */
    /* @4951132 load */
    /* @4951140 constant */
    /* @4951144 add */
    /* @4951148 call */
    GM_SITE(vm, 632, 4951148);
    v67 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v68 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(140));
    /* @4951156 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v67, v68, STR_REF(1113)));
    L_4951160: ;
    /* @4951160 load */
    /* @4951168 constant */
    /* @4951172 cmp */
    /* @4951176 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4951400;
    /* @4951180 constant */
    /* @4951184 cast */
    /* @4951188 call */
    GM_SITE(vm, 632, 4951188);
    /* @4951196 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4951200 constant */
    /* @4951208 cast */
    /* @4951212 call */
    GM_SITE(vm, 632, 4951212);
    /* @4951220 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4951224 string */
    /* @4951232 cast */
    /* @4951236 constant */
    /* @4951240 load */
    /* @4951248 cast */
    /* @4951252 load */
    /* @4951260 constant */
    /* @4951264 add */
    /* @4951268 constant */
    /* @4951272 load */
    /* @4951280 cast */
    /* @4951284 load */
    /* @4951292 constant */
    /* @4951296 add */
    /* @4951300 call */
    GM_SITE(vm, 632, 4951300);
    v69 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v70 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4951308 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v69, v70, STR_REF(1112)));
    /* @4951312 string */
    /* @4951320 cast */
    /* @4951324 constant */
    /* @4951328 load */
    /* @4951336 cast */
    /* @4951340 load */
    /* @4951348 constant */
    /* @4951352 add */
    /* @4951356 constant */
    /* @4951360 load */
    /* @4951368 cast */
    /* @4951372 load */
    /* @4951380 constant */
    /* @4951384 add */
    /* @4951388 call */
    GM_SITE(vm, 632, 4951388);
    v71 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v72 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4951396 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v71, v72, STR_REF(1113)));
    L_4951400: ;
    /* @4951400 load */
    /* @4951408 constant */
    /* @4951412 cmp */
    /* @4951416 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4951640;
    /* @4951420 constant */
    /* @4951424 cast */
    /* @4951428 call */
    GM_SITE(vm, 632, 4951428);
    /* @4951436 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4951440 constant */
    /* @4951448 cast */
    /* @4951452 call */
    GM_SITE(vm, 632, 4951452);
    /* @4951460 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4951464 string */
    /* @4951472 cast */
    /* @4951476 constant */
    /* @4951480 load */
    /* @4951488 cast */
    /* @4951492 load */
    /* @4951500 constant */
    /* @4951504 add */
    /* @4951508 constant */
    /* @4951512 load */
    /* @4951520 cast */
    /* @4951524 load */
    /* @4951532 constant */
    /* @4951536 add */
    /* @4951540 call */
    GM_SITE(vm, 632, 4951540);
    v73 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v74 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4951548 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v73, v74, STR_REF(1112)));
    /* @4951552 string */
    /* @4951560 cast */
    /* @4951564 constant */
    /* @4951568 load */
    /* @4951576 cast */
    /* @4951580 load */
    /* @4951588 constant */
    /* @4951592 add */
    /* @4951596 constant */
    /* @4951600 load */
    /* @4951608 cast */
    /* @4951612 load */
    /* @4951620 constant */
    /* @4951624 add */
    /* @4951628 call */
    GM_SITE(vm, 632, 4951628);
    v75 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v76 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4951636 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v75, v76, STR_REF(1113)));
    L_4951640: ;
    /* @4951640 load */
    /* @4951648 constant */
    /* @4951652 cmp */
    /* @4951656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4951880;
    /* @4951660 constant */
    /* @4951664 cast */
    /* @4951668 call */
    GM_SITE(vm, 632, 4951668);
    /* @4951676 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4951680 constant */
    /* @4951688 cast */
    /* @4951692 call */
    GM_SITE(vm, 632, 4951692);
    /* @4951700 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4951704 string */
    /* @4951712 cast */
    /* @4951716 constant */
    /* @4951720 load */
    /* @4951728 cast */
    /* @4951732 load */
    /* @4951740 constant */
    /* @4951744 add */
    /* @4951748 constant */
    /* @4951752 load */
    /* @4951760 cast */
    /* @4951764 load */
    /* @4951772 constant */
    /* @4951776 add */
    /* @4951780 call */
    GM_SITE(vm, 632, 4951780);
    v77 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v78 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4951788 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v77, v78, STR_REF(1112)));
    /* @4951792 string */
    /* @4951800 cast */
    /* @4951804 constant */
    /* @4951808 load */
    /* @4951816 cast */
    /* @4951820 load */
    /* @4951828 constant */
    /* @4951832 add */
    /* @4951836 constant */
    /* @4951840 load */
    /* @4951848 cast */
    /* @4951852 load */
    /* @4951860 constant */
    /* @4951864 add */
    /* @4951868 call */
    GM_SITE(vm, 632, 4951868);
    v79 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v80 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4951876 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v79, v80, STR_REF(1113)));
    L_4951880: ;
    /* @4951880 load */
    /* @4951888 constant */
    /* @4951892 cmp */
    /* @4951896 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4952120;
    /* @4951900 constant */
    /* @4951904 cast */
    /* @4951908 call */
    GM_SITE(vm, 632, 4951908);
    /* @4951916 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4951920 constant */
    /* @4951928 cast */
    /* @4951932 call */
    GM_SITE(vm, 632, 4951932);
    /* @4951940 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4951944 string */
    /* @4951952 cast */
    /* @4951956 constant */
    /* @4951960 load */
    /* @4951968 cast */
    /* @4951972 load */
    /* @4951980 constant */
    /* @4951984 add */
    /* @4951988 constant */
    /* @4951992 load */
    /* @4952000 cast */
    /* @4952004 load */
    /* @4952012 constant */
    /* @4952016 add */
    /* @4952020 call */
    GM_SITE(vm, 632, 4952020);
    v81 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v82 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4952028 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v81, v82, STR_REF(1112)));
    /* @4952032 string */
    /* @4952040 cast */
    /* @4952044 constant */
    /* @4952048 load */
    /* @4952056 cast */
    /* @4952060 load */
    /* @4952068 constant */
    /* @4952072 add */
    /* @4952076 constant */
    /* @4952080 load */
    /* @4952088 cast */
    /* @4952092 load */
    /* @4952100 constant */
    /* @4952104 add */
    /* @4952108 call */
    GM_SITE(vm, 632, 4952108);
    v83 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v84 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4952116 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v83, v84, STR_REF(1113)));
    L_4952120: ;
    /* @4952120 load */
    /* @4952128 constant */
    /* @4952132 cmp */
    /* @4952136 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel3") == VAL(1)))) goto L_4953580;
    /* @4952140 load */
    /* @4952148 constant */
    /* @4952152 cmp */
    /* @4952156 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4952380;
    /* @4952160 constant */
    /* @4952164 cast */
    /* @4952168 call */
    GM_SITE(vm, 632, 4952168);
    /* @4952176 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4952180 constant */
    /* @4952188 cast */
    /* @4952192 call */
    GM_SITE(vm, 632, 4952192);
    /* @4952200 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4952204 string */
    /* @4952212 cast */
    /* @4952216 constant */
    /* @4952220 load */
    /* @4952228 cast */
    /* @4952232 load */
    /* @4952240 constant */
    /* @4952244 add */
    /* @4952248 constant */
    /* @4952252 load */
    /* @4952260 cast */
    /* @4952264 load */
    /* @4952272 constant */
    /* @4952276 add */
    /* @4952280 call */
    GM_SITE(vm, 632, 4952280);
    v85 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v86 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4952288 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v85, v86, STR_REF(1114)));
    /* @4952292 string */
    /* @4952300 cast */
    /* @4952304 constant */
    /* @4952308 load */
    /* @4952316 cast */
    /* @4952320 load */
    /* @4952328 constant */
    /* @4952332 add */
    /* @4952336 constant */
    /* @4952340 load */
    /* @4952348 cast */
    /* @4952352 load */
    /* @4952360 constant */
    /* @4952364 add */
    /* @4952368 call */
    GM_SITE(vm, 632, 4952368);
    v87 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v88 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4952376 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v87, v88, STR_REF(1115)));
    L_4952380: ;
    /* @4952380 load */
    /* @4952388 constant */
    /* @4952392 cmp */
    /* @4952396 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4952620;
    /* @4952400 constant */
    /* @4952404 cast */
    /* @4952408 call */
    GM_SITE(vm, 632, 4952408);
    /* @4952416 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4952420 constant */
    /* @4952428 cast */
    /* @4952432 call */
    GM_SITE(vm, 632, 4952432);
    /* @4952440 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4952444 string */
    /* @4952452 cast */
    /* @4952456 constant */
    /* @4952460 load */
    /* @4952468 cast */
    /* @4952472 load */
    /* @4952480 constant */
    /* @4952484 add */
    /* @4952488 constant */
    /* @4952492 load */
    /* @4952500 cast */
    /* @4952504 load */
    /* @4952512 constant */
    /* @4952516 add */
    /* @4952520 call */
    GM_SITE(vm, 632, 4952520);
    v89 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v90 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4952528 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v89, v90, STR_REF(1114)));
    /* @4952532 string */
    /* @4952540 cast */
    /* @4952544 constant */
    /* @4952548 load */
    /* @4952556 cast */
    /* @4952560 load */
    /* @4952568 constant */
    /* @4952572 add */
    /* @4952576 constant */
    /* @4952580 load */
    /* @4952588 cast */
    /* @4952592 load */
    /* @4952600 constant */
    /* @4952604 add */
    /* @4952608 call */
    GM_SITE(vm, 632, 4952608);
    v91 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v92 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4952616 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v91, v92, STR_REF(1115)));
    L_4952620: ;
    /* @4952620 load */
    /* @4952628 constant */
    /* @4952632 cmp */
    /* @4952636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4952860;
    /* @4952640 constant */
    /* @4952644 cast */
    /* @4952648 call */
    GM_SITE(vm, 632, 4952648);
    /* @4952656 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4952660 constant */
    /* @4952668 cast */
    /* @4952672 call */
    GM_SITE(vm, 632, 4952672);
    /* @4952680 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4952684 string */
    /* @4952692 cast */
    /* @4952696 constant */
    /* @4952700 load */
    /* @4952708 cast */
    /* @4952712 load */
    /* @4952720 constant */
    /* @4952724 add */
    /* @4952728 constant */
    /* @4952732 load */
    /* @4952740 cast */
    /* @4952744 load */
    /* @4952752 constant */
    /* @4952756 add */
    /* @4952760 call */
    GM_SITE(vm, 632, 4952760);
    v93 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v94 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4952768 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v93, v94, STR_REF(1114)));
    /* @4952772 string */
    /* @4952780 cast */
    /* @4952784 constant */
    /* @4952788 load */
    /* @4952796 cast */
    /* @4952800 load */
    /* @4952808 constant */
    /* @4952812 add */
    /* @4952816 constant */
    /* @4952820 load */
    /* @4952828 cast */
    /* @4952832 load */
    /* @4952840 constant */
    /* @4952844 add */
    /* @4952848 call */
    GM_SITE(vm, 632, 4952848);
    v95 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v96 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4952856 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v95, v96, STR_REF(1115)));
    L_4952860: ;
    /* @4952860 load */
    /* @4952868 constant */
    /* @4952872 cmp */
    /* @4952876 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4953100;
    /* @4952880 constant */
    /* @4952884 cast */
    /* @4952888 call */
    GM_SITE(vm, 632, 4952888);
    /* @4952896 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4952900 constant */
    /* @4952908 cast */
    /* @4952912 call */
    GM_SITE(vm, 632, 4952912);
    /* @4952920 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4952924 string */
    /* @4952932 cast */
    /* @4952936 constant */
    /* @4952940 load */
    /* @4952948 cast */
    /* @4952952 load */
    /* @4952960 constant */
    /* @4952964 add */
    /* @4952968 constant */
    /* @4952972 load */
    /* @4952980 cast */
    /* @4952984 load */
    /* @4952992 constant */
    /* @4952996 add */
    /* @4953000 call */
    GM_SITE(vm, 632, 4953000);
    v97 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v98 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4953008 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v97, v98, STR_REF(1114)));
    /* @4953012 string */
    /* @4953020 cast */
    /* @4953024 constant */
    /* @4953028 load */
    /* @4953036 cast */
    /* @4953040 load */
    /* @4953048 constant */
    /* @4953052 add */
    /* @4953056 constant */
    /* @4953060 load */
    /* @4953068 cast */
    /* @4953072 load */
    /* @4953080 constant */
    /* @4953084 add */
    /* @4953088 call */
    GM_SITE(vm, 632, 4953088);
    v99 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v100 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4953096 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v99, v100, STR_REF(1115)));
    L_4953100: ;
    /* @4953100 load */
    /* @4953108 constant */
    /* @4953112 cmp */
    /* @4953116 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4953340;
    /* @4953120 constant */
    /* @4953124 cast */
    /* @4953128 call */
    GM_SITE(vm, 632, 4953128);
    /* @4953136 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4953140 constant */
    /* @4953148 cast */
    /* @4953152 call */
    GM_SITE(vm, 632, 4953152);
    /* @4953160 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4953164 string */
    /* @4953172 cast */
    /* @4953176 constant */
    /* @4953180 load */
    /* @4953188 cast */
    /* @4953192 load */
    /* @4953200 constant */
    /* @4953204 add */
    /* @4953208 constant */
    /* @4953212 load */
    /* @4953220 cast */
    /* @4953224 load */
    /* @4953232 constant */
    /* @4953236 add */
    /* @4953240 call */
    GM_SITE(vm, 632, 4953240);
    v101 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v102 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4953248 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v101, v102, STR_REF(1114)));
    /* @4953252 string */
    /* @4953260 cast */
    /* @4953264 constant */
    /* @4953268 load */
    /* @4953276 cast */
    /* @4953280 load */
    /* @4953288 constant */
    /* @4953292 add */
    /* @4953296 constant */
    /* @4953300 load */
    /* @4953308 cast */
    /* @4953312 load */
    /* @4953320 constant */
    /* @4953324 add */
    /* @4953328 call */
    GM_SITE(vm, 632, 4953328);
    v103 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v104 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4953336 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v103, v104, STR_REF(1115)));
    L_4953340: ;
    /* @4953340 load */
    /* @4953348 constant */
    /* @4953352 cmp */
    /* @4953356 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4953580;
    /* @4953360 constant */
    /* @4953364 cast */
    /* @4953368 call */
    GM_SITE(vm, 632, 4953368);
    /* @4953376 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4953380 constant */
    /* @4953388 cast */
    /* @4953392 call */
    GM_SITE(vm, 632, 4953392);
    /* @4953400 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4953404 string */
    /* @4953412 cast */
    /* @4953416 constant */
    /* @4953420 load */
    /* @4953428 cast */
    /* @4953432 load */
    /* @4953440 constant */
    /* @4953444 add */
    /* @4953448 constant */
    /* @4953452 load */
    /* @4953460 cast */
    /* @4953464 load */
    /* @4953472 constant */
    /* @4953476 add */
    /* @4953480 call */
    GM_SITE(vm, 632, 4953480);
    v105 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v106 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4953488 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v105, v106, STR_REF(1114)));
    /* @4953492 string */
    /* @4953500 cast */
    /* @4953504 constant */
    /* @4953508 load */
    /* @4953516 cast */
    /* @4953520 load */
    /* @4953528 constant */
    /* @4953532 add */
    /* @4953536 constant */
    /* @4953540 load */
    /* @4953548 cast */
    /* @4953552 load */
    /* @4953560 constant */
    /* @4953564 add */
    /* @4953568 call */
    GM_SITE(vm, 632, 4953568);
    v107 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v108 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4953576 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v107, v108, STR_REF(1115)));
    L_4953580: ;
    /* @4953580 load */
    /* @4953588 constant */
    /* @4953592 cmp */
    /* @4953596 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel4") == VAL(1)))) goto L_4955040;
    /* @4953600 load */
    /* @4953608 constant */
    /* @4953612 cmp */
    /* @4953616 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4953840;
    /* @4953620 constant */
    /* @4953624 cast */
    /* @4953628 call */
    GM_SITE(vm, 632, 4953628);
    /* @4953636 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4953640 constant */
    /* @4953648 cast */
    /* @4953652 call */
    GM_SITE(vm, 632, 4953652);
    /* @4953660 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4953664 string */
    /* @4953672 cast */
    /* @4953676 constant */
    /* @4953680 load */
    /* @4953688 cast */
    /* @4953692 load */
    /* @4953700 constant */
    /* @4953704 add */
    /* @4953708 constant */
    /* @4953712 load */
    /* @4953720 cast */
    /* @4953724 load */
    /* @4953732 constant */
    /* @4953736 add */
    /* @4953740 call */
    GM_SITE(vm, 632, 4953740);
    v109 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v110 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4953748 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v109, v110, STR_REF(1116)));
    /* @4953752 string */
    /* @4953760 cast */
    /* @4953764 constant */
    /* @4953768 load */
    /* @4953776 cast */
    /* @4953780 load */
    /* @4953788 constant */
    /* @4953792 add */
    /* @4953796 constant */
    /* @4953800 load */
    /* @4953808 cast */
    /* @4953812 load */
    /* @4953820 constant */
    /* @4953824 add */
    /* @4953828 call */
    GM_SITE(vm, 632, 4953828);
    v111 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v112 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4953836 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v111, v112, STR_REF(1117)));
    L_4953840: ;
    /* @4953840 load */
    /* @4953848 constant */
    /* @4953852 cmp */
    /* @4953856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4954080;
    /* @4953860 constant */
    /* @4953864 cast */
    /* @4953868 call */
    GM_SITE(vm, 632, 4953868);
    /* @4953876 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4953880 constant */
    /* @4953888 cast */
    /* @4953892 call */
    GM_SITE(vm, 632, 4953892);
    /* @4953900 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4953904 string */
    /* @4953912 cast */
    /* @4953916 constant */
    /* @4953920 load */
    /* @4953928 cast */
    /* @4953932 load */
    /* @4953940 constant */
    /* @4953944 add */
    /* @4953948 constant */
    /* @4953952 load */
    /* @4953960 cast */
    /* @4953964 load */
    /* @4953972 constant */
    /* @4953976 add */
    /* @4953980 call */
    GM_SITE(vm, 632, 4953980);
    v113 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v114 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4953988 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v113, v114, STR_REF(1116)));
    /* @4953992 string */
    /* @4954000 cast */
    /* @4954004 constant */
    /* @4954008 load */
    /* @4954016 cast */
    /* @4954020 load */
    /* @4954028 constant */
    /* @4954032 add */
    /* @4954036 constant */
    /* @4954040 load */
    /* @4954048 cast */
    /* @4954052 load */
    /* @4954060 constant */
    /* @4954064 add */
    /* @4954068 call */
    GM_SITE(vm, 632, 4954068);
    v115 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v116 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4954076 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v115, v116, STR_REF(1117)));
    L_4954080: ;
    /* @4954080 load */
    /* @4954088 constant */
    /* @4954092 cmp */
    /* @4954096 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4954320;
    /* @4954100 constant */
    /* @4954104 cast */
    /* @4954108 call */
    GM_SITE(vm, 632, 4954108);
    /* @4954116 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4954120 constant */
    /* @4954128 cast */
    /* @4954132 call */
    GM_SITE(vm, 632, 4954132);
    /* @4954140 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4954144 string */
    /* @4954152 cast */
    /* @4954156 constant */
    /* @4954160 load */
    /* @4954168 cast */
    /* @4954172 load */
    /* @4954180 constant */
    /* @4954184 add */
    /* @4954188 constant */
    /* @4954192 load */
    /* @4954200 cast */
    /* @4954204 load */
    /* @4954212 constant */
    /* @4954216 add */
    /* @4954220 call */
    GM_SITE(vm, 632, 4954220);
    v117 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v118 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4954228 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v117, v118, STR_REF(1116)));
    /* @4954232 string */
    /* @4954240 cast */
    /* @4954244 constant */
    /* @4954248 load */
    /* @4954256 cast */
    /* @4954260 load */
    /* @4954268 constant */
    /* @4954272 add */
    /* @4954276 constant */
    /* @4954280 load */
    /* @4954288 cast */
    /* @4954292 load */
    /* @4954300 constant */
    /* @4954304 add */
    /* @4954308 call */
    GM_SITE(vm, 632, 4954308);
    v119 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v120 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4954316 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v119, v120, STR_REF(1117)));
    L_4954320: ;
    /* @4954320 load */
    /* @4954328 constant */
    /* @4954332 cmp */
    /* @4954336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4954560;
    /* @4954340 constant */
    /* @4954344 cast */
    /* @4954348 call */
    GM_SITE(vm, 632, 4954348);
    /* @4954356 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4954360 constant */
    /* @4954368 cast */
    /* @4954372 call */
    GM_SITE(vm, 632, 4954372);
    /* @4954380 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4954384 string */
    /* @4954392 cast */
    /* @4954396 constant */
    /* @4954400 load */
    /* @4954408 cast */
    /* @4954412 load */
    /* @4954420 constant */
    /* @4954424 add */
    /* @4954428 constant */
    /* @4954432 load */
    /* @4954440 cast */
    /* @4954444 load */
    /* @4954452 constant */
    /* @4954456 add */
    /* @4954460 call */
    GM_SITE(vm, 632, 4954460);
    v121 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v122 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4954468 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v121, v122, STR_REF(1116)));
    /* @4954472 string */
    /* @4954480 cast */
    /* @4954484 constant */
    /* @4954488 load */
    /* @4954496 cast */
    /* @4954500 load */
    /* @4954508 constant */
    /* @4954512 add */
    /* @4954516 constant */
    /* @4954520 load */
    /* @4954528 cast */
    /* @4954532 load */
    /* @4954540 constant */
    /* @4954544 add */
    /* @4954548 call */
    GM_SITE(vm, 632, 4954548);
    v123 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v124 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4954556 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v123, v124, STR_REF(1117)));
    L_4954560: ;
    /* @4954560 load */
    /* @4954568 constant */
    /* @4954572 cmp */
    /* @4954576 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4954800;
    /* @4954580 constant */
    /* @4954584 cast */
    /* @4954588 call */
    GM_SITE(vm, 632, 4954588);
    /* @4954596 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4954600 constant */
    /* @4954608 cast */
    /* @4954612 call */
    GM_SITE(vm, 632, 4954612);
    /* @4954620 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4954624 string */
    /* @4954632 cast */
    /* @4954636 constant */
    /* @4954640 load */
    /* @4954648 cast */
    /* @4954652 load */
    /* @4954660 constant */
    /* @4954664 add */
    /* @4954668 constant */
    /* @4954672 load */
    /* @4954680 cast */
    /* @4954684 load */
    /* @4954692 constant */
    /* @4954696 add */
    /* @4954700 call */
    GM_SITE(vm, 632, 4954700);
    v125 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v126 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4954708 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v125, v126, STR_REF(1116)));
    /* @4954712 string */
    /* @4954720 cast */
    /* @4954724 constant */
    /* @4954728 load */
    /* @4954736 cast */
    /* @4954740 load */
    /* @4954748 constant */
    /* @4954752 add */
    /* @4954756 constant */
    /* @4954760 load */
    /* @4954768 cast */
    /* @4954772 load */
    /* @4954780 constant */
    /* @4954784 add */
    /* @4954788 call */
    GM_SITE(vm, 632, 4954788);
    v127 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v128 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4954796 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v127, v128, STR_REF(1117)));
    L_4954800: ;
    /* @4954800 load */
    /* @4954808 constant */
    /* @4954812 cmp */
    /* @4954816 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4955040;
    /* @4954820 constant */
    /* @4954824 cast */
    /* @4954828 call */
    GM_SITE(vm, 632, 4954828);
    /* @4954836 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4954840 constant */
    /* @4954848 cast */
    /* @4954852 call */
    GM_SITE(vm, 632, 4954852);
    /* @4954860 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4954864 string */
    /* @4954872 cast */
    /* @4954876 constant */
    /* @4954880 load */
    /* @4954888 cast */
    /* @4954892 load */
    /* @4954900 constant */
    /* @4954904 add */
    /* @4954908 constant */
    /* @4954912 load */
    /* @4954920 cast */
    /* @4954924 load */
    /* @4954932 constant */
    /* @4954936 add */
    /* @4954940 call */
    GM_SITE(vm, 632, 4954940);
    v129 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v130 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4954948 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v129, v130, STR_REF(1116)));
    /* @4954952 string */
    /* @4954960 cast */
    /* @4954964 constant */
    /* @4954968 load */
    /* @4954976 cast */
    /* @4954980 load */
    /* @4954988 constant */
    /* @4954992 add */
    /* @4954996 constant */
    /* @4955000 load */
    /* @4955008 cast */
    /* @4955012 load */
    /* @4955020 constant */
    /* @4955024 add */
    /* @4955028 call */
    GM_SITE(vm, 632, 4955028);
    v131 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v132 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4955036 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v131, v132, STR_REF(1117)));
    L_4955040: ;
    /* @4955040 load */
    /* @4955048 constant */
    /* @4955052 cmp */
    /* @4955056 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel5") == VAL(1)))) goto L_4956500;
    /* @4955060 load */
    /* @4955068 constant */
    /* @4955072 cmp */
    /* @4955076 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4955300;
    /* @4955080 constant */
    /* @4955084 cast */
    /* @4955088 call */
    GM_SITE(vm, 632, 4955088);
    /* @4955096 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4955100 constant */
    /* @4955108 cast */
    /* @4955112 call */
    GM_SITE(vm, 632, 4955112);
    /* @4955120 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4955124 string */
    /* @4955132 cast */
    /* @4955136 constant */
    /* @4955140 load */
    /* @4955148 cast */
    /* @4955152 load */
    /* @4955160 constant */
    /* @4955164 add */
    /* @4955168 constant */
    /* @4955172 load */
    /* @4955180 cast */
    /* @4955184 load */
    /* @4955192 constant */
    /* @4955196 add */
    /* @4955200 call */
    GM_SITE(vm, 632, 4955200);
    v133 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v134 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4955208 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v133, v134, STR_REF(1118)));
    /* @4955212 string */
    /* @4955220 cast */
    /* @4955224 constant */
    /* @4955228 load */
    /* @4955236 cast */
    /* @4955240 load */
    /* @4955248 constant */
    /* @4955252 add */
    /* @4955256 constant */
    /* @4955260 load */
    /* @4955268 cast */
    /* @4955272 load */
    /* @4955280 constant */
    /* @4955284 add */
    /* @4955288 call */
    GM_SITE(vm, 632, 4955288);
    v135 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v136 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4955296 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v135, v136, STR_REF(1119)));
    L_4955300: ;
    /* @4955300 load */
    /* @4955308 constant */
    /* @4955312 cmp */
    /* @4955316 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4955540;
    /* @4955320 constant */
    /* @4955324 cast */
    /* @4955328 call */
    GM_SITE(vm, 632, 4955328);
    /* @4955336 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4955340 constant */
    /* @4955348 cast */
    /* @4955352 call */
    GM_SITE(vm, 632, 4955352);
    /* @4955360 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4955364 string */
    /* @4955372 cast */
    /* @4955376 constant */
    /* @4955380 load */
    /* @4955388 cast */
    /* @4955392 load */
    /* @4955400 constant */
    /* @4955404 add */
    /* @4955408 constant */
    /* @4955412 load */
    /* @4955420 cast */
    /* @4955424 load */
    /* @4955432 constant */
    /* @4955436 add */
    /* @4955440 call */
    GM_SITE(vm, 632, 4955440);
    v137 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    v138 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    /* @4955448 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v137, v138, STR_REF(1118)));
    /* @4955452 string */
    /* @4955460 cast */
    /* @4955464 constant */
    /* @4955468 load */
    /* @4955476 cast */
    /* @4955480 load */
    /* @4955488 constant */
    /* @4955492 add */
    /* @4955496 constant */
    /* @4955500 load */
    /* @4955508 cast */
    /* @4955512 load */
    /* @4955520 constant */
    /* @4955524 add */
    /* @4955528 call */
    GM_SITE(vm, 632, 4955528);
    v139 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    v140 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(140));
    /* @4955536 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v139, v140, STR_REF(1119)));
    L_4955540: ;
    /* @4955540 load */
    /* @4955548 constant */
    /* @4955552 cmp */
    /* @4955556 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4955780;
    /* @4955560 constant */
    /* @4955564 cast */
    /* @4955568 call */
    GM_SITE(vm, 632, 4955568);
    /* @4955576 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4955580 constant */
    /* @4955588 cast */
    /* @4955592 call */
    GM_SITE(vm, 632, 4955592);
    /* @4955600 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4955604 string */
    /* @4955612 cast */
    /* @4955616 constant */
    /* @4955620 load */
    /* @4955628 cast */
    /* @4955632 load */
    /* @4955640 constant */
    /* @4955644 add */
    /* @4955648 constant */
    /* @4955652 load */
    /* @4955660 cast */
    /* @4955664 load */
    /* @4955672 constant */
    /* @4955676 add */
    /* @4955680 call */
    GM_SITE(vm, 632, 4955680);
    v141 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v142 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4955688 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v141, v142, STR_REF(1118)));
    /* @4955692 string */
    /* @4955700 cast */
    /* @4955704 constant */
    /* @4955708 load */
    /* @4955716 cast */
    /* @4955720 load */
    /* @4955728 constant */
    /* @4955732 add */
    /* @4955736 constant */
    /* @4955740 load */
    /* @4955748 cast */
    /* @4955752 load */
    /* @4955760 constant */
    /* @4955764 add */
    /* @4955768 call */
    GM_SITE(vm, 632, 4955768);
    v143 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v144 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4955776 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v143, v144, STR_REF(1119)));
    L_4955780: ;
    /* @4955780 load */
    /* @4955788 constant */
    /* @4955792 cmp */
    /* @4955796 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4956020;
    /* @4955800 constant */
    /* @4955804 cast */
    /* @4955808 call */
    GM_SITE(vm, 632, 4955808);
    /* @4955816 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4955820 constant */
    /* @4955828 cast */
    /* @4955832 call */
    GM_SITE(vm, 632, 4955832);
    /* @4955840 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4955844 string */
    /* @4955852 cast */
    /* @4955856 constant */
    /* @4955860 load */
    /* @4955868 cast */
    /* @4955872 load */
    /* @4955880 constant */
    /* @4955884 add */
    /* @4955888 constant */
    /* @4955892 load */
    /* @4955900 cast */
    /* @4955904 load */
    /* @4955912 constant */
    /* @4955916 add */
    /* @4955920 call */
    GM_SITE(vm, 632, 4955920);
    v145 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v146 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4955928 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v145, v146, STR_REF(1118)));
    /* @4955932 string */
    /* @4955940 cast */
    /* @4955944 constant */
    /* @4955948 load */
    /* @4955956 cast */
    /* @4955960 load */
    /* @4955968 constant */
    /* @4955972 add */
    /* @4955976 constant */
    /* @4955980 load */
    /* @4955988 cast */
    /* @4955992 load */
    /* @4956000 constant */
    /* @4956004 add */
    /* @4956008 call */
    GM_SITE(vm, 632, 4956008);
    v147 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v148 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4956016 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v147, v148, STR_REF(1119)));
    L_4956020: ;
    /* @4956020 load */
    /* @4956028 constant */
    /* @4956032 cmp */
    /* @4956036 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4956260;
    /* @4956040 constant */
    /* @4956044 cast */
    /* @4956048 call */
    GM_SITE(vm, 632, 4956048);
    /* @4956056 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4956060 constant */
    /* @4956068 cast */
    /* @4956072 call */
    GM_SITE(vm, 632, 4956072);
    /* @4956080 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4956084 string */
    /* @4956092 cast */
    /* @4956096 constant */
    /* @4956100 load */
    /* @4956108 cast */
    /* @4956112 load */
    /* @4956120 constant */
    /* @4956124 add */
    /* @4956128 constant */
    /* @4956132 load */
    /* @4956140 cast */
    /* @4956144 load */
    /* @4956152 constant */
    /* @4956156 add */
    /* @4956160 call */
    GM_SITE(vm, 632, 4956160);
    v149 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v150 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4956168 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v149, v150, STR_REF(1118)));
    /* @4956172 string */
    /* @4956180 cast */
    /* @4956184 constant */
    /* @4956188 load */
    /* @4956196 cast */
    /* @4956200 load */
    /* @4956208 constant */
    /* @4956212 add */
    /* @4956216 constant */
    /* @4956220 load */
    /* @4956228 cast */
    /* @4956232 load */
    /* @4956240 constant */
    /* @4956244 add */
    /* @4956248 call */
    GM_SITE(vm, 632, 4956248);
    v151 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v152 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4956256 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v151, v152, STR_REF(1119)));
    L_4956260: ;
    /* @4956260 load */
    /* @4956268 constant */
    /* @4956272 cmp */
    /* @4956276 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4956500;
    /* @4956280 constant */
    /* @4956284 cast */
    /* @4956288 call */
    GM_SITE(vm, 632, 4956288);
    /* @4956296 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4956300 constant */
    /* @4956308 cast */
    /* @4956312 call */
    GM_SITE(vm, 632, 4956312);
    /* @4956320 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4956324 string */
    /* @4956332 cast */
    /* @4956336 constant */
    /* @4956340 load */
    /* @4956348 cast */
    /* @4956352 load */
    /* @4956360 constant */
    /* @4956364 add */
    /* @4956368 constant */
    /* @4956372 load */
    /* @4956380 cast */
    /* @4956384 load */
    /* @4956392 constant */
    /* @4956396 add */
    /* @4956400 call */
    GM_SITE(vm, 632, 4956400);
    v153 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v154 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4956408 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v153, v154, STR_REF(1118)));
    /* @4956412 string */
    /* @4956420 cast */
    /* @4956424 constant */
    /* @4956428 load */
    /* @4956436 cast */
    /* @4956440 load */
    /* @4956448 constant */
    /* @4956452 add */
    /* @4956456 constant */
    /* @4956460 load */
    /* @4956468 cast */
    /* @4956472 load */
    /* @4956480 constant */
    /* @4956484 add */
    /* @4956488 call */
    GM_SITE(vm, 632, 4956488);
    v155 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v156 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4956496 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v155, v156, STR_REF(1119)));
    L_4956500: ;
    /* @4956500 load */
    /* @4956508 constant */
    /* @4956512 cmp */
    /* @4956516 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel6") == VAL(1)))) goto L_4957432;
    /* @4956520 load */
    /* @4956528 constant */
    /* @4956532 cmp */
    /* @4956536 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4956672;
    /* @4956540 constant */
    /* @4956544 cast */
    /* @4956548 call */
    GM_SITE(vm, 632, 4956548);
    /* @4956556 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4956560 constant */
    /* @4956568 cast */
    /* @4956572 call */
    GM_SITE(vm, 632, 4956572);
    /* @4956580 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4956584 string */
    /* @4956592 cast */
    /* @4956596 constant */
    /* @4956600 load */
    /* @4956608 cast */
    /* @4956612 load */
    /* @4956620 constant */
    /* @4956624 add */
    /* @4956628 constant */
    /* @4956632 load */
    /* @4956640 cast */
    /* @4956644 load */
    /* @4956652 constant */
    /* @4956656 add */
    /* @4956660 call */
    GM_SITE(vm, 632, 4956660);
    v157 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v158 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4956668 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v157, v158, STR_REF(1120)));
    L_4956672: ;
    /* @4956672 load */
    /* @4956680 constant */
    /* @4956684 cmp */
    /* @4956688 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4956824;
    /* @4956692 constant */
    /* @4956696 cast */
    /* @4956700 call */
    GM_SITE(vm, 632, 4956700);
    /* @4956708 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4956712 constant */
    /* @4956720 cast */
    /* @4956724 call */
    GM_SITE(vm, 632, 4956724);
    /* @4956732 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4956736 string */
    /* @4956744 cast */
    /* @4956748 constant */
    /* @4956752 load */
    /* @4956760 cast */
    /* @4956764 load */
    /* @4956772 constant */
    /* @4956776 add */
    /* @4956780 constant */
    /* @4956784 load */
    /* @4956792 cast */
    /* @4956796 load */
    /* @4956804 constant */
    /* @4956808 add */
    /* @4956812 call */
    GM_SITE(vm, 632, 4956812);
    v159 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v160 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4956820 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v159, v160, STR_REF(1120)));
    L_4956824: ;
    /* @4956824 load */
    /* @4956832 constant */
    /* @4956836 cmp */
    /* @4956840 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4956976;
    /* @4956844 constant */
    /* @4956848 cast */
    /* @4956852 call */
    GM_SITE(vm, 632, 4956852);
    /* @4956860 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4956864 constant */
    /* @4956872 cast */
    /* @4956876 call */
    GM_SITE(vm, 632, 4956876);
    /* @4956884 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4956888 string */
    /* @4956896 cast */
    /* @4956900 constant */
    /* @4956904 load */
    /* @4956912 cast */
    /* @4956916 load */
    /* @4956924 constant */
    /* @4956928 add */
    /* @4956932 constant */
    /* @4956936 load */
    /* @4956944 cast */
    /* @4956948 load */
    /* @4956956 constant */
    /* @4956960 add */
    /* @4956964 call */
    GM_SITE(vm, 632, 4956964);
    v161 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v162 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4956972 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v161, v162, STR_REF(1120)));
    L_4956976: ;
    /* @4956976 load */
    /* @4956984 constant */
    /* @4956988 cmp */
    /* @4956992 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4957128;
    /* @4956996 constant */
    /* @4957000 cast */
    /* @4957004 call */
    GM_SITE(vm, 632, 4957004);
    /* @4957012 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4957016 constant */
    /* @4957024 cast */
    /* @4957028 call */
    GM_SITE(vm, 632, 4957028);
    /* @4957036 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4957040 string */
    /* @4957048 cast */
    /* @4957052 constant */
    /* @4957056 load */
    /* @4957064 cast */
    /* @4957068 load */
    /* @4957076 constant */
    /* @4957080 add */
    /* @4957084 constant */
    /* @4957088 load */
    /* @4957096 cast */
    /* @4957100 load */
    /* @4957108 constant */
    /* @4957112 add */
    /* @4957116 call */
    GM_SITE(vm, 632, 4957116);
    v163 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v164 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4957124 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v163, v164, STR_REF(1120)));
    L_4957128: ;
    /* @4957128 load */
    /* @4957136 constant */
    /* @4957140 cmp */
    /* @4957144 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4957280;
    /* @4957148 constant */
    /* @4957152 cast */
    /* @4957156 call */
    GM_SITE(vm, 632, 4957156);
    /* @4957164 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4957168 constant */
    /* @4957176 cast */
    /* @4957180 call */
    GM_SITE(vm, 632, 4957180);
    /* @4957188 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4957192 string */
    /* @4957200 cast */
    /* @4957204 constant */
    /* @4957208 load */
    /* @4957216 cast */
    /* @4957220 load */
    /* @4957228 constant */
    /* @4957232 add */
    /* @4957236 constant */
    /* @4957240 load */
    /* @4957248 cast */
    /* @4957252 load */
    /* @4957260 constant */
    /* @4957264 add */
    /* @4957268 call */
    GM_SITE(vm, 632, 4957268);
    v165 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v166 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4957276 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v165, v166, STR_REF(1120)));
    L_4957280: ;
    /* @4957280 load */
    /* @4957288 constant */
    /* @4957292 cmp */
    /* @4957296 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4957432;
    /* @4957300 constant */
    /* @4957304 cast */
    /* @4957308 call */
    GM_SITE(vm, 632, 4957308);
    /* @4957316 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4957320 constant */
    /* @4957328 cast */
    /* @4957332 call */
    GM_SITE(vm, 632, 4957332);
    /* @4957340 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4957344 string */
    /* @4957352 cast */
    /* @4957356 constant */
    /* @4957360 load */
    /* @4957368 cast */
    /* @4957372 load */
    /* @4957380 constant */
    /* @4957384 add */
    /* @4957388 constant */
    /* @4957392 load */
    /* @4957400 cast */
    /* @4957404 load */
    /* @4957412 constant */
    /* @4957416 add */
    /* @4957420 call */
    GM_SITE(vm, 632, 4957420);
    v167 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v168 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4957428 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v167, v168, STR_REF(1120)));
    L_4957432: ;
    /* @4957432 load */
    /* @4957440 constant */
    /* @4957444 cmp */
    /* @4957448 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4957484;
    /* @4957452 constant */
    /* @4957456 cast */
    /* @4957460 constant */
    /* @4957464 cast */
    /* @4957468 call */
    GM_SITE(vm, 632, 4957468);
    /* @4957476 cast */
    /* @4957480 b */
    v169 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, VAL(0), VAL(1)));
    p4957488_0 = v169;
    goto L_4957488;
    L_4957484: ;
    /* @4957484 constant */
    p4957488_0 = VAL(0);
    L_4957488: ;
    /* @4957488 bf */
    if (!TRUTH(p4957488_0)) goto L_4957504;
    /* @4957492 call */
    GM_SITE(vm, 632, 4957492);
    /* @4957500 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4957504: ;
    return;
}
