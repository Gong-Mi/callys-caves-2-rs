/* generated from CODE 583 (gml_Object_obj_lloydtutorial4_Draw_0), source start 4877672, end 4888396. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0583(GmVM* vm) {
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
    Val p4888380_0;
    Val v157;
    /* @4877672 constant */
    /* @4877676 load */
    /* @4877684 cast */
    /* @4877688 load */
    /* @4877696 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4877704 constant */
    /* @4877708 load */
    /* @4877716 cast */
    /* @4877720 load */
    /* @4877728 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4877736 load */
    /* @4877744 constant */
    /* @4877748 cmp */
    /* @4877752 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4878280;
    /* @4877756 constant */
    /* @4877760 cast */
    /* @4877764 constant */
    /* @4877768 cast */
    /* @4877772 constant */
    /* @4877776 cast */
    /* @4877780 constant */
    /* @4877792 cast */
    /* @4877796 constant */
    /* @4877808 cast */
    /* @4877812 constant */
    /* @4877816 constant */
    /* @4877820 load */
    /* @4877828 constant */
    /* @4877832 constant */
    /* @4877836 load */
    /* @4877844 constant */
    /* @4877848 sub */
    /* @4877852 constant */
    /* @4877856 cast */
    /* @4877860 constant */
    /* @4877864 cast */
    /* @4877868 call */
    GM_SITE(vm, 583, 4877868);
    /* @4877876 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(0.96), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4877880 constant */
    /* @4877884 cast */
    /* @4877888 constant */
    /* @4877892 cast */
    /* @4877896 constant */
    /* @4877900 cast */
    /* @4877904 constant */
    /* @4877908 cast */
    /* @4877912 constant */
    /* @4877916 cast */
    /* @4877920 constant */
    /* @4877924 load */
    /* @4877932 cast */
    /* @4877936 load */
    /* @4877944 constant */
    /* @4877948 add */
    /* @4877952 constant */
    /* @4877956 load */
    /* @4877964 cast */
    /* @4877968 load */
    /* @4877976 constant */
    /* @4877980 add */
    /* @4877984 constant */
    /* @4877988 cast */
    /* @4877992 constant */
    /* @4877996 cast */
    /* @4878000 call */
    GM_SITE(vm, 583, 4878000);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4878008 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v1, v2, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4878012 constant */
    /* @4878016 cast */
    /* @4878020 constant */
    /* @4878024 cast */
    /* @4878028 constant */
    /* @4878032 cast */
    /* @4878036 constant */
    /* @4878040 cast */
    /* @4878044 constant */
    /* @4878048 cast */
    /* @4878052 constant */
    /* @4878056 load */
    /* @4878064 cast */
    /* @4878068 load */
    /* @4878076 constant */
    /* @4878080 add */
    /* @4878084 constant */
    /* @4878088 load */
    /* @4878096 cast */
    /* @4878100 load */
    /* @4878108 constant */
    /* @4878112 add */
    /* @4878116 constant */
    /* @4878120 cast */
    /* @4878124 constant */
    /* @4878128 cast */
    /* @4878132 call */
    GM_SITE(vm, 583, 4878132);
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4878140 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v3, v4, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4878144 load */
    /* @4878152 constant */
    /* @4878156 cmp */
    /* @4878160 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4878280;
    /* @4878164 constant */
    /* @4878168 cast */
    /* @4878172 call */
    GM_SITE(vm, 583, 4878172);
    /* @4878180 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4878184 constant */
    /* @4878192 cast */
    /* @4878196 call */
    GM_SITE(vm, 583, 4878196);
    /* @4878204 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4878208 string */
    /* @4878216 cast */
    /* @4878220 constant */
    /* @4878224 constant */
    /* @4878228 load */
    /* @4878236 constant */
    /* @4878240 add */
    /* @4878244 constant */
    /* @4878248 constant */
    /* @4878252 load */
    /* @4878260 constant */
    /* @4878264 add */
    /* @4878268 call */
    GM_SITE(vm, 583, 4878268);
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(150));
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(200));
    /* @4878276 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v5, v6, STR_REF(743)));
    L_4878280: ;
    /* @4878280 load */
    /* @4878288 constant */
    /* @4878292 cmp */
    /* @4878296 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4878824;
    /* @4878300 constant */
    /* @4878304 cast */
    /* @4878308 constant */
    /* @4878312 cast */
    /* @4878316 constant */
    /* @4878320 cast */
    /* @4878324 constant */
    /* @4878336 cast */
    /* @4878340 constant */
    /* @4878352 cast */
    /* @4878356 constant */
    /* @4878360 constant */
    /* @4878364 load */
    /* @4878372 constant */
    /* @4878376 constant */
    /* @4878380 load */
    /* @4878388 constant */
    /* @4878392 sub */
    /* @4878396 constant */
    /* @4878400 cast */
    /* @4878404 constant */
    /* @4878408 cast */
    /* @4878412 call */
    GM_SITE(vm, 583, 4878412);
    /* @4878420 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(0.82), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4878424 constant */
    /* @4878428 cast */
    /* @4878432 constant */
    /* @4878436 cast */
    /* @4878440 constant */
    /* @4878444 cast */
    /* @4878448 constant */
    /* @4878452 cast */
    /* @4878456 constant */
    /* @4878460 cast */
    /* @4878464 constant */
    /* @4878468 load */
    /* @4878476 cast */
    /* @4878480 load */
    /* @4878488 constant */
    /* @4878492 add */
    /* @4878496 constant */
    /* @4878500 load */
    /* @4878508 cast */
    /* @4878512 load */
    /* @4878520 constant */
    /* @4878524 add */
    /* @4878528 constant */
    /* @4878532 cast */
    /* @4878536 constant */
    /* @4878540 cast */
    /* @4878544 call */
    GM_SITE(vm, 583, 4878544);
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4878552 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v7, v8, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4878556 constant */
    /* @4878560 cast */
    /* @4878564 constant */
    /* @4878568 cast */
    /* @4878572 constant */
    /* @4878576 cast */
    /* @4878580 constant */
    /* @4878584 cast */
    /* @4878588 constant */
    /* @4878592 cast */
    /* @4878596 constant */
    /* @4878600 load */
    /* @4878608 cast */
    /* @4878612 load */
    /* @4878620 constant */
    /* @4878624 add */
    /* @4878628 constant */
    /* @4878632 load */
    /* @4878640 cast */
    /* @4878644 load */
    /* @4878652 constant */
    /* @4878656 add */
    /* @4878660 constant */
    /* @4878664 cast */
    /* @4878668 constant */
    /* @4878672 cast */
    /* @4878676 call */
    GM_SITE(vm, 583, 4878676);
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(320));
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4878684 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v9, v10, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4878688 load */
    /* @4878696 constant */
    /* @4878700 cmp */
    /* @4878704 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4878824;
    /* @4878708 constant */
    /* @4878712 cast */
    /* @4878716 call */
    GM_SITE(vm, 583, 4878716);
    /* @4878724 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4878728 constant */
    /* @4878736 cast */
    /* @4878740 call */
    GM_SITE(vm, 583, 4878740);
    /* @4878748 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4878752 string */
    /* @4878760 cast */
    /* @4878764 constant */
    /* @4878768 constant */
    /* @4878772 load */
    /* @4878780 constant */
    /* @4878784 add */
    /* @4878788 constant */
    /* @4878792 constant */
    /* @4878796 load */
    /* @4878804 constant */
    /* @4878808 add */
    /* @4878812 call */
    GM_SITE(vm, 583, 4878812);
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(110));
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4878820 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v11, v12, STR_REF(743)));
    L_4878824: ;
    /* @4878824 load */
    /* @4878832 constant */
    /* @4878836 cmp */
    /* @4878840 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4879368;
    /* @4878844 constant */
    /* @4878848 cast */
    /* @4878852 constant */
    /* @4878856 cast */
    /* @4878860 constant */
    /* @4878864 cast */
    /* @4878868 constant */
    /* @4878880 cast */
    /* @4878884 constant */
    /* @4878896 cast */
    /* @4878900 constant */
    /* @4878904 constant */
    /* @4878908 load */
    /* @4878916 constant */
    /* @4878920 constant */
    /* @4878924 load */
    /* @4878932 constant */
    /* @4878936 sub */
    /* @4878940 constant */
    /* @4878944 cast */
    /* @4878948 constant */
    /* @4878952 cast */
    /* @4878956 call */
    GM_SITE(vm, 583, 4878956);
    /* @4878964 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4878968 constant */
    /* @4878972 cast */
    /* @4878976 constant */
    /* @4878980 cast */
    /* @4878984 constant */
    /* @4878988 cast */
    /* @4878992 constant */
    /* @4878996 cast */
    /* @4879000 constant */
    /* @4879004 cast */
    /* @4879008 constant */
    /* @4879012 load */
    /* @4879020 cast */
    /* @4879024 load */
    /* @4879032 constant */
    /* @4879036 add */
    /* @4879040 constant */
    /* @4879044 load */
    /* @4879052 cast */
    /* @4879056 load */
    /* @4879064 constant */
    /* @4879068 add */
    /* @4879072 constant */
    /* @4879076 cast */
    /* @4879080 constant */
    /* @4879084 cast */
    /* @4879088 call */
    GM_SITE(vm, 583, 4879088);
    v13 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4879096 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v13, v14, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4879100 constant */
    /* @4879104 cast */
    /* @4879108 constant */
    /* @4879112 cast */
    /* @4879116 constant */
    /* @4879120 cast */
    /* @4879124 constant */
    /* @4879128 cast */
    /* @4879132 constant */
    /* @4879136 cast */
    /* @4879140 constant */
    /* @4879144 load */
    /* @4879152 cast */
    /* @4879156 load */
    /* @4879164 constant */
    /* @4879168 add */
    /* @4879172 constant */
    /* @4879176 load */
    /* @4879184 cast */
    /* @4879188 load */
    /* @4879196 constant */
    /* @4879200 add */
    /* @4879204 constant */
    /* @4879208 cast */
    /* @4879212 constant */
    /* @4879216 cast */
    /* @4879220 call */
    GM_SITE(vm, 583, 4879220);
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4879228 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v15, v16, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4879232 load */
    /* @4879240 constant */
    /* @4879244 cmp */
    /* @4879248 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4879368;
    /* @4879252 constant */
    /* @4879256 cast */
    /* @4879260 call */
    GM_SITE(vm, 583, 4879260);
    /* @4879268 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4879272 constant */
    /* @4879280 cast */
    /* @4879284 call */
    GM_SITE(vm, 583, 4879284);
    /* @4879292 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4879296 string */
    /* @4879304 cast */
    /* @4879308 constant */
    /* @4879312 constant */
    /* @4879316 load */
    /* @4879324 constant */
    /* @4879328 add */
    /* @4879332 constant */
    /* @4879336 constant */
    /* @4879340 load */
    /* @4879348 constant */
    /* @4879352 add */
    /* @4879356 call */
    GM_SITE(vm, 583, 4879356);
    v17 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(180));
    v18 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(300));
    /* @4879364 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v17, v18, STR_REF(743)));
    L_4879368: ;
    /* @4879368 load */
    /* @4879376 constant */
    /* @4879380 cmp */
    /* @4879384 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4879912;
    /* @4879388 constant */
    /* @4879392 cast */
    /* @4879396 constant */
    /* @4879400 cast */
    /* @4879404 constant */
    /* @4879408 cast */
    /* @4879412 constant */
    /* @4879424 cast */
    /* @4879428 constant */
    /* @4879440 cast */
    /* @4879444 constant */
    /* @4879448 constant */
    /* @4879452 load */
    /* @4879460 constant */
    /* @4879464 constant */
    /* @4879468 load */
    /* @4879476 constant */
    /* @4879480 sub */
    /* @4879484 constant */
    /* @4879488 cast */
    /* @4879492 constant */
    /* @4879496 cast */
    /* @4879500 call */
    GM_SITE(vm, 583, 4879500);
    /* @4879508 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4879512 constant */
    /* @4879516 cast */
    /* @4879520 constant */
    /* @4879524 cast */
    /* @4879528 constant */
    /* @4879532 cast */
    /* @4879536 constant */
    /* @4879540 cast */
    /* @4879544 constant */
    /* @4879548 cast */
    /* @4879552 constant */
    /* @4879556 load */
    /* @4879564 cast */
    /* @4879568 load */
    /* @4879576 constant */
    /* @4879580 add */
    /* @4879584 constant */
    /* @4879588 load */
    /* @4879596 cast */
    /* @4879600 load */
    /* @4879608 constant */
    /* @4879612 add */
    /* @4879616 constant */
    /* @4879620 cast */
    /* @4879624 constant */
    /* @4879628 cast */
    /* @4879632 call */
    GM_SITE(vm, 583, 4879632);
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4879640 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v19, v20, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4879644 constant */
    /* @4879648 cast */
    /* @4879652 constant */
    /* @4879656 cast */
    /* @4879660 constant */
    /* @4879664 cast */
    /* @4879668 constant */
    /* @4879672 cast */
    /* @4879676 constant */
    /* @4879680 cast */
    /* @4879684 constant */
    /* @4879688 load */
    /* @4879696 cast */
    /* @4879700 load */
    /* @4879708 constant */
    /* @4879712 add */
    /* @4879716 constant */
    /* @4879720 load */
    /* @4879728 cast */
    /* @4879732 load */
    /* @4879740 constant */
    /* @4879744 add */
    /* @4879748 constant */
    /* @4879752 cast */
    /* @4879756 constant */
    /* @4879760 cast */
    /* @4879764 call */
    GM_SITE(vm, 583, 4879764);
    v21 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4879772 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v21, v22, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4879776 load */
    /* @4879784 constant */
    /* @4879788 cmp */
    /* @4879792 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4879912;
    /* @4879796 constant */
    /* @4879800 cast */
    /* @4879804 call */
    GM_SITE(vm, 583, 4879804);
    /* @4879812 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4879816 constant */
    /* @4879824 cast */
    /* @4879828 call */
    GM_SITE(vm, 583, 4879828);
    /* @4879836 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4879840 string */
    /* @4879848 cast */
    /* @4879852 constant */
    /* @4879856 constant */
    /* @4879860 load */
    /* @4879868 constant */
    /* @4879872 add */
    /* @4879876 constant */
    /* @4879880 constant */
    /* @4879884 load */
    /* @4879892 constant */
    /* @4879896 add */
    /* @4879900 call */
    GM_SITE(vm, 583, 4879900);
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(180));
    v24 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(300));
    /* @4879908 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v23, v24, STR_REF(743)));
    L_4879912: ;
    /* @4879912 load */
    /* @4879920 constant */
    /* @4879924 cmp */
    /* @4879928 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4880456;
    /* @4879932 constant */
    /* @4879936 cast */
    /* @4879940 constant */
    /* @4879944 cast */
    /* @4879948 constant */
    /* @4879952 cast */
    /* @4879956 constant */
    /* @4879968 cast */
    /* @4879972 constant */
    /* @4879984 cast */
    /* @4879988 constant */
    /* @4879992 constant */
    /* @4879996 load */
    /* @4880004 constant */
    /* @4880008 constant */
    /* @4880012 load */
    /* @4880020 constant */
    /* @4880024 sub */
    /* @4880028 constant */
    /* @4880032 cast */
    /* @4880036 constant */
    /* @4880040 cast */
    /* @4880044 call */
    GM_SITE(vm, 583, 4880044);
    /* @4880052 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(0.95), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4880056 constant */
    /* @4880060 cast */
    /* @4880064 constant */
    /* @4880068 cast */
    /* @4880072 constant */
    /* @4880076 cast */
    /* @4880080 constant */
    /* @4880084 cast */
    /* @4880088 constant */
    /* @4880092 cast */
    /* @4880096 constant */
    /* @4880100 load */
    /* @4880108 cast */
    /* @4880112 load */
    /* @4880120 constant */
    /* @4880124 add */
    /* @4880128 constant */
    /* @4880132 load */
    /* @4880140 cast */
    /* @4880144 load */
    /* @4880152 constant */
    /* @4880156 add */
    /* @4880160 constant */
    /* @4880164 cast */
    /* @4880168 constant */
    /* @4880172 cast */
    /* @4880176 call */
    GM_SITE(vm, 583, 4880176);
    v25 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v26 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4880184 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v25, v26, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4880188 constant */
    /* @4880192 cast */
    /* @4880196 constant */
    /* @4880200 cast */
    /* @4880204 constant */
    /* @4880208 cast */
    /* @4880212 constant */
    /* @4880216 cast */
    /* @4880220 constant */
    /* @4880224 cast */
    /* @4880228 constant */
    /* @4880232 load */
    /* @4880240 cast */
    /* @4880244 load */
    /* @4880252 constant */
    /* @4880256 add */
    /* @4880260 constant */
    /* @4880264 load */
    /* @4880272 cast */
    /* @4880276 load */
    /* @4880284 constant */
    /* @4880288 add */
    /* @4880292 constant */
    /* @4880296 cast */
    /* @4880300 constant */
    /* @4880304 cast */
    /* @4880308 call */
    GM_SITE(vm, 583, 4880308);
    v27 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v28 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4880316 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v27, v28, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4880320 load */
    /* @4880328 constant */
    /* @4880332 cmp */
    /* @4880336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4880456;
    /* @4880340 constant */
    /* @4880344 cast */
    /* @4880348 call */
    GM_SITE(vm, 583, 4880348);
    /* @4880356 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4880360 constant */
    /* @4880368 cast */
    /* @4880372 call */
    GM_SITE(vm, 583, 4880372);
    /* @4880380 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4880384 string */
    /* @4880392 cast */
    /* @4880396 constant */
    /* @4880400 constant */
    /* @4880404 load */
    /* @4880412 constant */
    /* @4880416 add */
    /* @4880420 constant */
    /* @4880424 constant */
    /* @4880428 load */
    /* @4880436 constant */
    /* @4880440 add */
    /* @4880444 call */
    GM_SITE(vm, 583, 4880444);
    v29 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(150));
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(200));
    /* @4880452 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v29, v30, STR_REF(743)));
    L_4880456: ;
    /* @4880456 load */
    /* @4880464 constant */
    /* @4880468 cmp */
    /* @4880472 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4881000;
    /* @4880476 constant */
    /* @4880480 cast */
    /* @4880484 constant */
    /* @4880488 cast */
    /* @4880492 constant */
    /* @4880496 cast */
    /* @4880500 constant */
    /* @4880512 cast */
    /* @4880516 constant */
    /* @4880528 cast */
    /* @4880532 constant */
    /* @4880536 constant */
    /* @4880540 load */
    /* @4880548 constant */
    /* @4880552 constant */
    /* @4880556 load */
    /* @4880564 constant */
    /* @4880568 sub */
    /* @4880572 constant */
    /* @4880576 cast */
    /* @4880580 constant */
    /* @4880584 cast */
    /* @4880588 call */
    GM_SITE(vm, 583, 4880588);
    /* @4880596 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(1.06), VAL(0.86), VAL(0), VAL(-1), VAL(1)));
    /* @4880600 constant */
    /* @4880604 cast */
    /* @4880608 constant */
    /* @4880612 cast */
    /* @4880616 constant */
    /* @4880620 cast */
    /* @4880624 constant */
    /* @4880628 cast */
    /* @4880632 constant */
    /* @4880636 cast */
    /* @4880640 constant */
    /* @4880644 load */
    /* @4880652 cast */
    /* @4880656 load */
    /* @4880664 constant */
    /* @4880668 add */
    /* @4880672 constant */
    /* @4880676 load */
    /* @4880684 cast */
    /* @4880688 load */
    /* @4880696 constant */
    /* @4880700 add */
    /* @4880704 constant */
    /* @4880708 cast */
    /* @4880712 constant */
    /* @4880716 cast */
    /* @4880720 call */
    GM_SITE(vm, 583, 4880720);
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v32 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4880728 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v31, v32, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4880732 constant */
    /* @4880736 cast */
    /* @4880740 constant */
    /* @4880744 cast */
    /* @4880748 constant */
    /* @4880752 cast */
    /* @4880756 constant */
    /* @4880760 cast */
    /* @4880764 constant */
    /* @4880768 cast */
    /* @4880772 constant */
    /* @4880776 load */
    /* @4880784 cast */
    /* @4880788 load */
    /* @4880796 constant */
    /* @4880800 add */
    /* @4880804 constant */
    /* @4880808 load */
    /* @4880816 cast */
    /* @4880820 load */
    /* @4880828 constant */
    /* @4880832 add */
    /* @4880836 constant */
    /* @4880840 cast */
    /* @4880844 constant */
    /* @4880848 cast */
    /* @4880852 call */
    GM_SITE(vm, 583, 4880852);
    v33 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(390));
    v34 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4880860 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v33, v34, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4880864 load */
    /* @4880872 constant */
    /* @4880876 cmp */
    /* @4880880 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4881000;
    /* @4880884 constant */
    /* @4880888 cast */
    /* @4880892 call */
    GM_SITE(vm, 583, 4880892);
    /* @4880900 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4880904 constant */
    /* @4880912 cast */
    /* @4880916 call */
    GM_SITE(vm, 583, 4880916);
    /* @4880924 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4880928 string */
    /* @4880936 cast */
    /* @4880940 constant */
    /* @4880944 constant */
    /* @4880948 load */
    /* @4880956 constant */
    /* @4880960 add */
    /* @4880964 constant */
    /* @4880968 constant */
    /* @4880972 load */
    /* @4880980 constant */
    /* @4880984 add */
    /* @4880988 call */
    GM_SITE(vm, 583, 4880988);
    v35 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(160));
    v36 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(200));
    /* @4880996 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v35, v36, STR_REF(743)));
    L_4881000: ;
    /* @4881000 load */
    /* @4881008 constant */
    /* @4881012 cmp */
    /* @4881016 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel1") == VAL(1)))) goto L_4882460;
    /* @4881020 load */
    /* @4881028 constant */
    /* @4881032 cmp */
    /* @4881036 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4881260;
    /* @4881040 constant */
    /* @4881044 cast */
    /* @4881048 call */
    GM_SITE(vm, 583, 4881048);
    /* @4881056 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4881060 constant */
    /* @4881068 cast */
    /* @4881072 call */
    GM_SITE(vm, 583, 4881072);
    /* @4881080 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4881084 string */
    /* @4881092 cast */
    /* @4881096 constant */
    /* @4881100 load */
    /* @4881108 cast */
    /* @4881112 load */
    /* @4881120 constant */
    /* @4881124 add */
    /* @4881128 constant */
    /* @4881132 load */
    /* @4881140 cast */
    /* @4881144 load */
    /* @4881152 constant */
    /* @4881156 add */
    /* @4881160 call */
    GM_SITE(vm, 583, 4881160);
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4881168 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v37, v38, STR_REF(1058)));
    /* @4881172 string */
    /* @4881180 cast */
    /* @4881184 constant */
    /* @4881188 load */
    /* @4881196 cast */
    /* @4881200 load */
    /* @4881208 constant */
    /* @4881212 add */
    /* @4881216 constant */
    /* @4881220 load */
    /* @4881228 cast */
    /* @4881232 load */
    /* @4881240 constant */
    /* @4881244 add */
    /* @4881248 call */
    GM_SITE(vm, 583, 4881248);
    v39 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v40 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4881256 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, v40, STR_REF(1059)));
    L_4881260: ;
    /* @4881260 load */
    /* @4881268 constant */
    /* @4881272 cmp */
    /* @4881276 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4881500;
    /* @4881280 constant */
    /* @4881284 cast */
    /* @4881288 call */
    GM_SITE(vm, 583, 4881288);
    /* @4881296 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4881300 constant */
    /* @4881308 cast */
    /* @4881312 call */
    GM_SITE(vm, 583, 4881312);
    /* @4881320 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4881324 string */
    /* @4881332 cast */
    /* @4881336 constant */
    /* @4881340 load */
    /* @4881348 cast */
    /* @4881352 load */
    /* @4881360 constant */
    /* @4881364 add */
    /* @4881368 constant */
    /* @4881372 load */
    /* @4881380 cast */
    /* @4881384 load */
    /* @4881392 constant */
    /* @4881396 add */
    /* @4881400 call */
    GM_SITE(vm, 583, 4881400);
    v41 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v42 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4881408 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v41, v42, STR_REF(1058)));
    /* @4881412 string */
    /* @4881420 cast */
    /* @4881424 constant */
    /* @4881428 load */
    /* @4881436 cast */
    /* @4881440 load */
    /* @4881448 constant */
    /* @4881452 add */
    /* @4881456 constant */
    /* @4881460 load */
    /* @4881468 cast */
    /* @4881472 load */
    /* @4881480 constant */
    /* @4881484 add */
    /* @4881488 call */
    GM_SITE(vm, 583, 4881488);
    v43 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v44 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4881496 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v43, v44, STR_REF(1059)));
    L_4881500: ;
    /* @4881500 load */
    /* @4881508 constant */
    /* @4881512 cmp */
    /* @4881516 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4881740;
    /* @4881520 constant */
    /* @4881524 cast */
    /* @4881528 call */
    GM_SITE(vm, 583, 4881528);
    /* @4881536 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4881540 constant */
    /* @4881548 cast */
    /* @4881552 call */
    GM_SITE(vm, 583, 4881552);
    /* @4881560 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4881564 string */
    /* @4881572 cast */
    /* @4881576 constant */
    /* @4881580 load */
    /* @4881588 cast */
    /* @4881592 load */
    /* @4881600 constant */
    /* @4881604 add */
    /* @4881608 constant */
    /* @4881612 load */
    /* @4881620 cast */
    /* @4881624 load */
    /* @4881632 constant */
    /* @4881636 add */
    /* @4881640 call */
    GM_SITE(vm, 583, 4881640);
    v45 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v46 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4881648 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v45, v46, STR_REF(1058)));
    /* @4881652 string */
    /* @4881660 cast */
    /* @4881664 constant */
    /* @4881668 load */
    /* @4881676 cast */
    /* @4881680 load */
    /* @4881688 constant */
    /* @4881692 add */
    /* @4881696 constant */
    /* @4881700 load */
    /* @4881708 cast */
    /* @4881712 load */
    /* @4881720 constant */
    /* @4881724 add */
    /* @4881728 call */
    GM_SITE(vm, 583, 4881728);
    v47 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v48 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4881736 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v47, v48, STR_REF(1059)));
    L_4881740: ;
    /* @4881740 load */
    /* @4881748 constant */
    /* @4881752 cmp */
    /* @4881756 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4881980;
    /* @4881760 constant */
    /* @4881764 cast */
    /* @4881768 call */
    GM_SITE(vm, 583, 4881768);
    /* @4881776 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4881780 constant */
    /* @4881788 cast */
    /* @4881792 call */
    GM_SITE(vm, 583, 4881792);
    /* @4881800 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4881804 string */
    /* @4881812 cast */
    /* @4881816 constant */
    /* @4881820 load */
    /* @4881828 cast */
    /* @4881832 load */
    /* @4881840 constant */
    /* @4881844 add */
    /* @4881848 constant */
    /* @4881852 load */
    /* @4881860 cast */
    /* @4881864 load */
    /* @4881872 constant */
    /* @4881876 add */
    /* @4881880 call */
    GM_SITE(vm, 583, 4881880);
    v49 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v50 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4881888 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v49, v50, STR_REF(1058)));
    /* @4881892 string */
    /* @4881900 cast */
    /* @4881904 constant */
    /* @4881908 load */
    /* @4881916 cast */
    /* @4881920 load */
    /* @4881928 constant */
    /* @4881932 add */
    /* @4881936 constant */
    /* @4881940 load */
    /* @4881948 cast */
    /* @4881952 load */
    /* @4881960 constant */
    /* @4881964 add */
    /* @4881968 call */
    GM_SITE(vm, 583, 4881968);
    v51 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v52 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4881976 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v51, v52, STR_REF(1059)));
    L_4881980: ;
    /* @4881980 load */
    /* @4881988 constant */
    /* @4881992 cmp */
    /* @4881996 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4882220;
    /* @4882000 constant */
    /* @4882004 cast */
    /* @4882008 call */
    GM_SITE(vm, 583, 4882008);
    /* @4882016 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4882020 constant */
    /* @4882028 cast */
    /* @4882032 call */
    GM_SITE(vm, 583, 4882032);
    /* @4882040 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4882044 string */
    /* @4882052 cast */
    /* @4882056 constant */
    /* @4882060 load */
    /* @4882068 cast */
    /* @4882072 load */
    /* @4882080 constant */
    /* @4882084 add */
    /* @4882088 constant */
    /* @4882092 load */
    /* @4882100 cast */
    /* @4882104 load */
    /* @4882112 constant */
    /* @4882116 add */
    /* @4882120 call */
    GM_SITE(vm, 583, 4882120);
    v53 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v54 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4882128 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v53, v54, STR_REF(1058)));
    /* @4882132 string */
    /* @4882140 cast */
    /* @4882144 constant */
    /* @4882148 load */
    /* @4882156 cast */
    /* @4882160 load */
    /* @4882168 constant */
    /* @4882172 add */
    /* @4882176 constant */
    /* @4882180 load */
    /* @4882188 cast */
    /* @4882192 load */
    /* @4882200 constant */
    /* @4882204 add */
    /* @4882208 call */
    GM_SITE(vm, 583, 4882208);
    v55 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v56 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4882216 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v55, v56, STR_REF(1059)));
    L_4882220: ;
    /* @4882220 load */
    /* @4882228 constant */
    /* @4882232 cmp */
    /* @4882236 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4882460;
    /* @4882240 constant */
    /* @4882244 cast */
    /* @4882248 call */
    GM_SITE(vm, 583, 4882248);
    /* @4882256 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4882260 constant */
    /* @4882268 cast */
    /* @4882272 call */
    GM_SITE(vm, 583, 4882272);
    /* @4882280 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4882284 string */
    /* @4882292 cast */
    /* @4882296 constant */
    /* @4882300 load */
    /* @4882308 cast */
    /* @4882312 load */
    /* @4882320 constant */
    /* @4882324 add */
    /* @4882328 constant */
    /* @4882332 load */
    /* @4882340 cast */
    /* @4882344 load */
    /* @4882352 constant */
    /* @4882356 add */
    /* @4882360 call */
    GM_SITE(vm, 583, 4882360);
    v57 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v58 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4882368 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v57, v58, STR_REF(1058)));
    /* @4882372 string */
    /* @4882380 cast */
    /* @4882384 constant */
    /* @4882388 load */
    /* @4882396 cast */
    /* @4882400 load */
    /* @4882408 constant */
    /* @4882412 add */
    /* @4882416 constant */
    /* @4882420 load */
    /* @4882428 cast */
    /* @4882432 load */
    /* @4882440 constant */
    /* @4882444 add */
    /* @4882448 call */
    GM_SITE(vm, 583, 4882448);
    v59 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v60 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4882456 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v59, v60, STR_REF(1059)));
    L_4882460: ;
    /* @4882460 load */
    /* @4882468 constant */
    /* @4882472 cmp */
    /* @4882476 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel2") == VAL(1)))) goto L_4883920;
    /* @4882480 load */
    /* @4882488 constant */
    /* @4882492 cmp */
    /* @4882496 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4882720;
    /* @4882500 constant */
    /* @4882504 cast */
    /* @4882508 call */
    GM_SITE(vm, 583, 4882508);
    /* @4882516 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4882520 constant */
    /* @4882528 cast */
    /* @4882532 call */
    GM_SITE(vm, 583, 4882532);
    /* @4882540 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4882544 string */
    /* @4882552 cast */
    /* @4882556 constant */
    /* @4882560 load */
    /* @4882568 cast */
    /* @4882572 load */
    /* @4882580 constant */
    /* @4882584 add */
    /* @4882588 constant */
    /* @4882592 load */
    /* @4882600 cast */
    /* @4882604 load */
    /* @4882612 constant */
    /* @4882616 add */
    /* @4882620 call */
    GM_SITE(vm, 583, 4882620);
    v61 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v62 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4882628 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v61, v62, STR_REF(1060)));
    /* @4882632 string */
    /* @4882640 cast */
    /* @4882644 constant */
    /* @4882648 load */
    /* @4882656 cast */
    /* @4882660 load */
    /* @4882668 constant */
    /* @4882672 add */
    /* @4882676 constant */
    /* @4882680 load */
    /* @4882688 cast */
    /* @4882692 load */
    /* @4882700 constant */
    /* @4882704 add */
    /* @4882708 call */
    GM_SITE(vm, 583, 4882708);
    v63 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v64 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4882716 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v63, v64, STR_REF(1061)));
    L_4882720: ;
    /* @4882720 load */
    /* @4882728 constant */
    /* @4882732 cmp */
    /* @4882736 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4882960;
    /* @4882740 constant */
    /* @4882744 cast */
    /* @4882748 call */
    GM_SITE(vm, 583, 4882748);
    /* @4882756 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4882760 constant */
    /* @4882768 cast */
    /* @4882772 call */
    GM_SITE(vm, 583, 4882772);
    /* @4882780 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4882784 string */
    /* @4882792 cast */
    /* @4882796 constant */
    /* @4882800 load */
    /* @4882808 cast */
    /* @4882812 load */
    /* @4882820 constant */
    /* @4882824 add */
    /* @4882828 constant */
    /* @4882832 load */
    /* @4882840 cast */
    /* @4882844 load */
    /* @4882852 constant */
    /* @4882856 add */
    /* @4882860 call */
    GM_SITE(vm, 583, 4882860);
    v65 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v66 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    /* @4882868 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v65, v66, STR_REF(1060)));
    /* @4882872 string */
    /* @4882880 cast */
    /* @4882884 constant */
    /* @4882888 load */
    /* @4882896 cast */
    /* @4882900 load */
    /* @4882908 constant */
    /* @4882912 add */
    /* @4882916 constant */
    /* @4882920 load */
    /* @4882928 cast */
    /* @4882932 load */
    /* @4882940 constant */
    /* @4882944 add */
    /* @4882948 call */
    GM_SITE(vm, 583, 4882948);
    v67 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v68 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(140));
    /* @4882956 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v67, v68, STR_REF(1061)));
    L_4882960: ;
    /* @4882960 load */
    /* @4882968 constant */
    /* @4882972 cmp */
    /* @4882976 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4883200;
    /* @4882980 constant */
    /* @4882984 cast */
    /* @4882988 call */
    GM_SITE(vm, 583, 4882988);
    /* @4882996 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4883000 constant */
    /* @4883008 cast */
    /* @4883012 call */
    GM_SITE(vm, 583, 4883012);
    /* @4883020 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4883024 string */
    /* @4883032 cast */
    /* @4883036 constant */
    /* @4883040 load */
    /* @4883048 cast */
    /* @4883052 load */
    /* @4883060 constant */
    /* @4883064 add */
    /* @4883068 constant */
    /* @4883072 load */
    /* @4883080 cast */
    /* @4883084 load */
    /* @4883092 constant */
    /* @4883096 add */
    /* @4883100 call */
    GM_SITE(vm, 583, 4883100);
    v69 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v70 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4883108 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v69, v70, STR_REF(1060)));
    /* @4883112 string */
    /* @4883120 cast */
    /* @4883124 constant */
    /* @4883128 load */
    /* @4883136 cast */
    /* @4883140 load */
    /* @4883148 constant */
    /* @4883152 add */
    /* @4883156 constant */
    /* @4883160 load */
    /* @4883168 cast */
    /* @4883172 load */
    /* @4883180 constant */
    /* @4883184 add */
    /* @4883188 call */
    GM_SITE(vm, 583, 4883188);
    v71 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v72 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4883196 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v71, v72, STR_REF(1061)));
    L_4883200: ;
    /* @4883200 load */
    /* @4883208 constant */
    /* @4883212 cmp */
    /* @4883216 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4883440;
    /* @4883220 constant */
    /* @4883224 cast */
    /* @4883228 call */
    GM_SITE(vm, 583, 4883228);
    /* @4883236 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4883240 constant */
    /* @4883248 cast */
    /* @4883252 call */
    GM_SITE(vm, 583, 4883252);
    /* @4883260 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4883264 string */
    /* @4883272 cast */
    /* @4883276 constant */
    /* @4883280 load */
    /* @4883288 cast */
    /* @4883292 load */
    /* @4883300 constant */
    /* @4883304 add */
    /* @4883308 constant */
    /* @4883312 load */
    /* @4883320 cast */
    /* @4883324 load */
    /* @4883332 constant */
    /* @4883336 add */
    /* @4883340 call */
    GM_SITE(vm, 583, 4883340);
    v73 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v74 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4883348 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v73, v74, STR_REF(1060)));
    /* @4883352 string */
    /* @4883360 cast */
    /* @4883364 constant */
    /* @4883368 load */
    /* @4883376 cast */
    /* @4883380 load */
    /* @4883388 constant */
    /* @4883392 add */
    /* @4883396 constant */
    /* @4883400 load */
    /* @4883408 cast */
    /* @4883412 load */
    /* @4883420 constant */
    /* @4883424 add */
    /* @4883428 call */
    GM_SITE(vm, 583, 4883428);
    v75 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v76 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4883436 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v75, v76, STR_REF(1061)));
    L_4883440: ;
    /* @4883440 load */
    /* @4883448 constant */
    /* @4883452 cmp */
    /* @4883456 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4883680;
    /* @4883460 constant */
    /* @4883464 cast */
    /* @4883468 call */
    GM_SITE(vm, 583, 4883468);
    /* @4883476 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4883480 constant */
    /* @4883488 cast */
    /* @4883492 call */
    GM_SITE(vm, 583, 4883492);
    /* @4883500 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4883504 string */
    /* @4883512 cast */
    /* @4883516 constant */
    /* @4883520 load */
    /* @4883528 cast */
    /* @4883532 load */
    /* @4883540 constant */
    /* @4883544 add */
    /* @4883548 constant */
    /* @4883552 load */
    /* @4883560 cast */
    /* @4883564 load */
    /* @4883572 constant */
    /* @4883576 add */
    /* @4883580 call */
    GM_SITE(vm, 583, 4883580);
    v77 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v78 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4883588 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v77, v78, STR_REF(1060)));
    /* @4883592 string */
    /* @4883600 cast */
    /* @4883604 constant */
    /* @4883608 load */
    /* @4883616 cast */
    /* @4883620 load */
    /* @4883628 constant */
    /* @4883632 add */
    /* @4883636 constant */
    /* @4883640 load */
    /* @4883648 cast */
    /* @4883652 load */
    /* @4883660 constant */
    /* @4883664 add */
    /* @4883668 call */
    GM_SITE(vm, 583, 4883668);
    v79 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v80 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4883676 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v79, v80, STR_REF(1061)));
    L_4883680: ;
    /* @4883680 load */
    /* @4883688 constant */
    /* @4883692 cmp */
    /* @4883696 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4883920;
    /* @4883700 constant */
    /* @4883704 cast */
    /* @4883708 call */
    GM_SITE(vm, 583, 4883708);
    /* @4883716 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4883720 constant */
    /* @4883728 cast */
    /* @4883732 call */
    GM_SITE(vm, 583, 4883732);
    /* @4883740 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4883744 string */
    /* @4883752 cast */
    /* @4883756 constant */
    /* @4883760 load */
    /* @4883768 cast */
    /* @4883772 load */
    /* @4883780 constant */
    /* @4883784 add */
    /* @4883788 constant */
    /* @4883792 load */
    /* @4883800 cast */
    /* @4883804 load */
    /* @4883812 constant */
    /* @4883816 add */
    /* @4883820 call */
    GM_SITE(vm, 583, 4883820);
    v81 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v82 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4883828 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v81, v82, STR_REF(1060)));
    /* @4883832 string */
    /* @4883840 cast */
    /* @4883844 constant */
    /* @4883848 load */
    /* @4883856 cast */
    /* @4883860 load */
    /* @4883868 constant */
    /* @4883872 add */
    /* @4883876 constant */
    /* @4883880 load */
    /* @4883888 cast */
    /* @4883892 load */
    /* @4883900 constant */
    /* @4883904 add */
    /* @4883908 call */
    GM_SITE(vm, 583, 4883908);
    v83 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v84 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4883916 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v83, v84, STR_REF(1061)));
    L_4883920: ;
    /* @4883920 load */
    /* @4883928 constant */
    /* @4883932 cmp */
    /* @4883936 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel3") == VAL(1)))) goto L_4885380;
    /* @4883940 load */
    /* @4883948 constant */
    /* @4883952 cmp */
    /* @4883956 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4884180;
    /* @4883960 constant */
    /* @4883964 cast */
    /* @4883968 call */
    GM_SITE(vm, 583, 4883968);
    /* @4883976 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4883980 constant */
    /* @4883988 cast */
    /* @4883992 call */
    GM_SITE(vm, 583, 4883992);
    /* @4884000 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4884004 string */
    /* @4884012 cast */
    /* @4884016 constant */
    /* @4884020 load */
    /* @4884028 cast */
    /* @4884032 load */
    /* @4884040 constant */
    /* @4884044 add */
    /* @4884048 constant */
    /* @4884052 load */
    /* @4884060 cast */
    /* @4884064 load */
    /* @4884072 constant */
    /* @4884076 add */
    /* @4884080 call */
    GM_SITE(vm, 583, 4884080);
    v85 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v86 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4884088 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v85, v86, STR_REF(1062)));
    /* @4884092 string */
    /* @4884100 cast */
    /* @4884104 constant */
    /* @4884108 load */
    /* @4884116 cast */
    /* @4884120 load */
    /* @4884128 constant */
    /* @4884132 add */
    /* @4884136 constant */
    /* @4884140 load */
    /* @4884148 cast */
    /* @4884152 load */
    /* @4884160 constant */
    /* @4884164 add */
    /* @4884168 call */
    GM_SITE(vm, 583, 4884168);
    v87 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v88 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4884176 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v87, v88, STR_REF(1063)));
    L_4884180: ;
    /* @4884180 load */
    /* @4884188 constant */
    /* @4884192 cmp */
    /* @4884196 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4884420;
    /* @4884200 constant */
    /* @4884204 cast */
    /* @4884208 call */
    GM_SITE(vm, 583, 4884208);
    /* @4884216 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4884220 constant */
    /* @4884228 cast */
    /* @4884232 call */
    GM_SITE(vm, 583, 4884232);
    /* @4884240 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4884244 string */
    /* @4884252 cast */
    /* @4884256 constant */
    /* @4884260 load */
    /* @4884268 cast */
    /* @4884272 load */
    /* @4884280 constant */
    /* @4884284 add */
    /* @4884288 constant */
    /* @4884292 load */
    /* @4884300 cast */
    /* @4884304 load */
    /* @4884312 constant */
    /* @4884316 add */
    /* @4884320 call */
    GM_SITE(vm, 583, 4884320);
    v89 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v90 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4884328 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v89, v90, STR_REF(1062)));
    /* @4884332 string */
    /* @4884340 cast */
    /* @4884344 constant */
    /* @4884348 load */
    /* @4884356 cast */
    /* @4884360 load */
    /* @4884368 constant */
    /* @4884372 add */
    /* @4884376 constant */
    /* @4884380 load */
    /* @4884388 cast */
    /* @4884392 load */
    /* @4884400 constant */
    /* @4884404 add */
    /* @4884408 call */
    GM_SITE(vm, 583, 4884408);
    v91 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v92 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4884416 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v91, v92, STR_REF(1063)));
    L_4884420: ;
    /* @4884420 load */
    /* @4884428 constant */
    /* @4884432 cmp */
    /* @4884436 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4884660;
    /* @4884440 constant */
    /* @4884444 cast */
    /* @4884448 call */
    GM_SITE(vm, 583, 4884448);
    /* @4884456 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4884460 constant */
    /* @4884468 cast */
    /* @4884472 call */
    GM_SITE(vm, 583, 4884472);
    /* @4884480 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4884484 string */
    /* @4884492 cast */
    /* @4884496 constant */
    /* @4884500 load */
    /* @4884508 cast */
    /* @4884512 load */
    /* @4884520 constant */
    /* @4884524 add */
    /* @4884528 constant */
    /* @4884532 load */
    /* @4884540 cast */
    /* @4884544 load */
    /* @4884552 constant */
    /* @4884556 add */
    /* @4884560 call */
    GM_SITE(vm, 583, 4884560);
    v93 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v94 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4884568 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v93, v94, STR_REF(1062)));
    /* @4884572 string */
    /* @4884580 cast */
    /* @4884584 constant */
    /* @4884588 load */
    /* @4884596 cast */
    /* @4884600 load */
    /* @4884608 constant */
    /* @4884612 add */
    /* @4884616 constant */
    /* @4884620 load */
    /* @4884628 cast */
    /* @4884632 load */
    /* @4884640 constant */
    /* @4884644 add */
    /* @4884648 call */
    GM_SITE(vm, 583, 4884648);
    v95 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v96 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4884656 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v95, v96, STR_REF(1063)));
    L_4884660: ;
    /* @4884660 load */
    /* @4884668 constant */
    /* @4884672 cmp */
    /* @4884676 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4884900;
    /* @4884680 constant */
    /* @4884684 cast */
    /* @4884688 call */
    GM_SITE(vm, 583, 4884688);
    /* @4884696 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4884700 constant */
    /* @4884708 cast */
    /* @4884712 call */
    GM_SITE(vm, 583, 4884712);
    /* @4884720 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4884724 string */
    /* @4884732 cast */
    /* @4884736 constant */
    /* @4884740 load */
    /* @4884748 cast */
    /* @4884752 load */
    /* @4884760 constant */
    /* @4884764 add */
    /* @4884768 constant */
    /* @4884772 load */
    /* @4884780 cast */
    /* @4884784 load */
    /* @4884792 constant */
    /* @4884796 add */
    /* @4884800 call */
    GM_SITE(vm, 583, 4884800);
    v97 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v98 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4884808 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v97, v98, STR_REF(1062)));
    /* @4884812 string */
    /* @4884820 cast */
    /* @4884824 constant */
    /* @4884828 load */
    /* @4884836 cast */
    /* @4884840 load */
    /* @4884848 constant */
    /* @4884852 add */
    /* @4884856 constant */
    /* @4884860 load */
    /* @4884868 cast */
    /* @4884872 load */
    /* @4884880 constant */
    /* @4884884 add */
    /* @4884888 call */
    GM_SITE(vm, 583, 4884888);
    v99 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v100 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4884896 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v99, v100, STR_REF(1063)));
    L_4884900: ;
    /* @4884900 load */
    /* @4884908 constant */
    /* @4884912 cmp */
    /* @4884916 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4885140;
    /* @4884920 constant */
    /* @4884924 cast */
    /* @4884928 call */
    GM_SITE(vm, 583, 4884928);
    /* @4884936 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4884940 constant */
    /* @4884948 cast */
    /* @4884952 call */
    GM_SITE(vm, 583, 4884952);
    /* @4884960 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4884964 string */
    /* @4884972 cast */
    /* @4884976 constant */
    /* @4884980 load */
    /* @4884988 cast */
    /* @4884992 load */
    /* @4885000 constant */
    /* @4885004 add */
    /* @4885008 constant */
    /* @4885012 load */
    /* @4885020 cast */
    /* @4885024 load */
    /* @4885032 constant */
    /* @4885036 add */
    /* @4885040 call */
    GM_SITE(vm, 583, 4885040);
    v101 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v102 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4885048 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v101, v102, STR_REF(1062)));
    /* @4885052 string */
    /* @4885060 cast */
    /* @4885064 constant */
    /* @4885068 load */
    /* @4885076 cast */
    /* @4885080 load */
    /* @4885088 constant */
    /* @4885092 add */
    /* @4885096 constant */
    /* @4885100 load */
    /* @4885108 cast */
    /* @4885112 load */
    /* @4885120 constant */
    /* @4885124 add */
    /* @4885128 call */
    GM_SITE(vm, 583, 4885128);
    v103 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v104 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4885136 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v103, v104, STR_REF(1063)));
    L_4885140: ;
    /* @4885140 load */
    /* @4885148 constant */
    /* @4885152 cmp */
    /* @4885156 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4885380;
    /* @4885160 constant */
    /* @4885164 cast */
    /* @4885168 call */
    GM_SITE(vm, 583, 4885168);
    /* @4885176 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4885180 constant */
    /* @4885188 cast */
    /* @4885192 call */
    GM_SITE(vm, 583, 4885192);
    /* @4885200 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4885204 string */
    /* @4885212 cast */
    /* @4885216 constant */
    /* @4885220 load */
    /* @4885228 cast */
    /* @4885232 load */
    /* @4885240 constant */
    /* @4885244 add */
    /* @4885248 constant */
    /* @4885252 load */
    /* @4885260 cast */
    /* @4885264 load */
    /* @4885272 constant */
    /* @4885276 add */
    /* @4885280 call */
    GM_SITE(vm, 583, 4885280);
    v105 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v106 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4885288 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v105, v106, STR_REF(1062)));
    /* @4885292 string */
    /* @4885300 cast */
    /* @4885304 constant */
    /* @4885308 load */
    /* @4885316 cast */
    /* @4885320 load */
    /* @4885328 constant */
    /* @4885332 add */
    /* @4885336 constant */
    /* @4885340 load */
    /* @4885348 cast */
    /* @4885352 load */
    /* @4885360 constant */
    /* @4885364 add */
    /* @4885368 call */
    GM_SITE(vm, 583, 4885368);
    v107 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v108 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4885376 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v107, v108, STR_REF(1063)));
    L_4885380: ;
    /* @4885380 load */
    /* @4885388 constant */
    /* @4885392 cmp */
    /* @4885396 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel4") == VAL(1)))) goto L_4886840;
    /* @4885400 load */
    /* @4885408 constant */
    /* @4885412 cmp */
    /* @4885416 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4885640;
    /* @4885420 constant */
    /* @4885424 cast */
    /* @4885428 call */
    GM_SITE(vm, 583, 4885428);
    /* @4885436 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4885440 constant */
    /* @4885448 cast */
    /* @4885452 call */
    GM_SITE(vm, 583, 4885452);
    /* @4885460 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4885464 string */
    /* @4885472 cast */
    /* @4885476 constant */
    /* @4885480 load */
    /* @4885488 cast */
    /* @4885492 load */
    /* @4885500 constant */
    /* @4885504 add */
    /* @4885508 constant */
    /* @4885512 load */
    /* @4885520 cast */
    /* @4885524 load */
    /* @4885532 constant */
    /* @4885536 add */
    /* @4885540 call */
    GM_SITE(vm, 583, 4885540);
    v109 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v110 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4885548 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v109, v110, STR_REF(1064)));
    /* @4885552 string */
    /* @4885560 cast */
    /* @4885564 constant */
    /* @4885568 load */
    /* @4885576 cast */
    /* @4885580 load */
    /* @4885588 constant */
    /* @4885592 add */
    /* @4885596 constant */
    /* @4885600 load */
    /* @4885608 cast */
    /* @4885612 load */
    /* @4885620 constant */
    /* @4885624 add */
    /* @4885628 call */
    GM_SITE(vm, 583, 4885628);
    v111 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v112 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4885636 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v111, v112, STR_REF(1065)));
    L_4885640: ;
    /* @4885640 load */
    /* @4885648 constant */
    /* @4885652 cmp */
    /* @4885656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4885880;
    /* @4885660 constant */
    /* @4885664 cast */
    /* @4885668 call */
    GM_SITE(vm, 583, 4885668);
    /* @4885676 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4885680 constant */
    /* @4885688 cast */
    /* @4885692 call */
    GM_SITE(vm, 583, 4885692);
    /* @4885700 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4885704 string */
    /* @4885712 cast */
    /* @4885716 constant */
    /* @4885720 load */
    /* @4885728 cast */
    /* @4885732 load */
    /* @4885740 constant */
    /* @4885744 add */
    /* @4885748 constant */
    /* @4885752 load */
    /* @4885760 cast */
    /* @4885764 load */
    /* @4885772 constant */
    /* @4885776 add */
    /* @4885780 call */
    GM_SITE(vm, 583, 4885780);
    v113 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v114 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4885788 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v113, v114, STR_REF(1064)));
    /* @4885792 string */
    /* @4885800 cast */
    /* @4885804 constant */
    /* @4885808 load */
    /* @4885816 cast */
    /* @4885820 load */
    /* @4885828 constant */
    /* @4885832 add */
    /* @4885836 constant */
    /* @4885840 load */
    /* @4885848 cast */
    /* @4885852 load */
    /* @4885860 constant */
    /* @4885864 add */
    /* @4885868 call */
    GM_SITE(vm, 583, 4885868);
    v115 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v116 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4885876 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v115, v116, STR_REF(1065)));
    L_4885880: ;
    /* @4885880 load */
    /* @4885888 constant */
    /* @4885892 cmp */
    /* @4885896 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4886120;
    /* @4885900 constant */
    /* @4885904 cast */
    /* @4885908 call */
    GM_SITE(vm, 583, 4885908);
    /* @4885916 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4885920 constant */
    /* @4885928 cast */
    /* @4885932 call */
    GM_SITE(vm, 583, 4885932);
    /* @4885940 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4885944 string */
    /* @4885952 cast */
    /* @4885956 constant */
    /* @4885960 load */
    /* @4885968 cast */
    /* @4885972 load */
    /* @4885980 constant */
    /* @4885984 add */
    /* @4885988 constant */
    /* @4885992 load */
    /* @4886000 cast */
    /* @4886004 load */
    /* @4886012 constant */
    /* @4886016 add */
    /* @4886020 call */
    GM_SITE(vm, 583, 4886020);
    v117 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v118 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4886028 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v117, v118, STR_REF(1064)));
    /* @4886032 string */
    /* @4886040 cast */
    /* @4886044 constant */
    /* @4886048 load */
    /* @4886056 cast */
    /* @4886060 load */
    /* @4886068 constant */
    /* @4886072 add */
    /* @4886076 constant */
    /* @4886080 load */
    /* @4886088 cast */
    /* @4886092 load */
    /* @4886100 constant */
    /* @4886104 add */
    /* @4886108 call */
    GM_SITE(vm, 583, 4886108);
    v119 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v120 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4886116 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v119, v120, STR_REF(1065)));
    L_4886120: ;
    /* @4886120 load */
    /* @4886128 constant */
    /* @4886132 cmp */
    /* @4886136 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4886360;
    /* @4886140 constant */
    /* @4886144 cast */
    /* @4886148 call */
    GM_SITE(vm, 583, 4886148);
    /* @4886156 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4886160 constant */
    /* @4886168 cast */
    /* @4886172 call */
    GM_SITE(vm, 583, 4886172);
    /* @4886180 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4886184 string */
    /* @4886192 cast */
    /* @4886196 constant */
    /* @4886200 load */
    /* @4886208 cast */
    /* @4886212 load */
    /* @4886220 constant */
    /* @4886224 add */
    /* @4886228 constant */
    /* @4886232 load */
    /* @4886240 cast */
    /* @4886244 load */
    /* @4886252 constant */
    /* @4886256 add */
    /* @4886260 call */
    GM_SITE(vm, 583, 4886260);
    v121 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v122 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4886268 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v121, v122, STR_REF(1064)));
    /* @4886272 string */
    /* @4886280 cast */
    /* @4886284 constant */
    /* @4886288 load */
    /* @4886296 cast */
    /* @4886300 load */
    /* @4886308 constant */
    /* @4886312 add */
    /* @4886316 constant */
    /* @4886320 load */
    /* @4886328 cast */
    /* @4886332 load */
    /* @4886340 constant */
    /* @4886344 add */
    /* @4886348 call */
    GM_SITE(vm, 583, 4886348);
    v123 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v124 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4886356 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v123, v124, STR_REF(1065)));
    L_4886360: ;
    /* @4886360 load */
    /* @4886368 constant */
    /* @4886372 cmp */
    /* @4886376 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4886600;
    /* @4886380 constant */
    /* @4886384 cast */
    /* @4886388 call */
    GM_SITE(vm, 583, 4886388);
    /* @4886396 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4886400 constant */
    /* @4886408 cast */
    /* @4886412 call */
    GM_SITE(vm, 583, 4886412);
    /* @4886420 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4886424 string */
    /* @4886432 cast */
    /* @4886436 constant */
    /* @4886440 load */
    /* @4886448 cast */
    /* @4886452 load */
    /* @4886460 constant */
    /* @4886464 add */
    /* @4886468 constant */
    /* @4886472 load */
    /* @4886480 cast */
    /* @4886484 load */
    /* @4886492 constant */
    /* @4886496 add */
    /* @4886500 call */
    GM_SITE(vm, 583, 4886500);
    v125 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v126 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4886508 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v125, v126, STR_REF(1064)));
    /* @4886512 string */
    /* @4886520 cast */
    /* @4886524 constant */
    /* @4886528 load */
    /* @4886536 cast */
    /* @4886540 load */
    /* @4886548 constant */
    /* @4886552 add */
    /* @4886556 constant */
    /* @4886560 load */
    /* @4886568 cast */
    /* @4886572 load */
    /* @4886580 constant */
    /* @4886584 add */
    /* @4886588 call */
    GM_SITE(vm, 583, 4886588);
    v127 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v128 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4886596 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v127, v128, STR_REF(1065)));
    L_4886600: ;
    /* @4886600 load */
    /* @4886608 constant */
    /* @4886612 cmp */
    /* @4886616 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4886840;
    /* @4886620 constant */
    /* @4886624 cast */
    /* @4886628 call */
    GM_SITE(vm, 583, 4886628);
    /* @4886636 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4886640 constant */
    /* @4886648 cast */
    /* @4886652 call */
    GM_SITE(vm, 583, 4886652);
    /* @4886660 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4886664 string */
    /* @4886672 cast */
    /* @4886676 constant */
    /* @4886680 load */
    /* @4886688 cast */
    /* @4886692 load */
    /* @4886700 constant */
    /* @4886704 add */
    /* @4886708 constant */
    /* @4886712 load */
    /* @4886720 cast */
    /* @4886724 load */
    /* @4886732 constant */
    /* @4886736 add */
    /* @4886740 call */
    GM_SITE(vm, 583, 4886740);
    v129 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v130 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4886748 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v129, v130, STR_REF(1064)));
    /* @4886752 string */
    /* @4886760 cast */
    /* @4886764 constant */
    /* @4886768 load */
    /* @4886776 cast */
    /* @4886780 load */
    /* @4886788 constant */
    /* @4886792 add */
    /* @4886796 constant */
    /* @4886800 load */
    /* @4886808 cast */
    /* @4886812 load */
    /* @4886820 constant */
    /* @4886824 add */
    /* @4886828 call */
    GM_SITE(vm, 583, 4886828);
    v131 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v132 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4886836 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v131, v132, STR_REF(1065)));
    L_4886840: ;
    /* @4886840 load */
    /* @4886848 constant */
    /* @4886852 cmp */
    /* @4886856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel5") == VAL(1)))) goto L_4888324;
    /* @4886860 load */
    /* @4886868 constant */
    /* @4886872 cmp */
    /* @4886876 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4887104;
    /* @4886880 constant */
    /* @4886884 cast */
    /* @4886888 call */
    GM_SITE(vm, 583, 4886888);
    /* @4886896 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4886900 constant */
    /* @4886908 cast */
    /* @4886912 call */
    GM_SITE(vm, 583, 4886912);
    /* @4886920 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4886924 string */
    /* @4886932 cast */
    /* @4886936 constant */
    /* @4886940 load */
    /* @4886948 cast */
    /* @4886952 load */
    /* @4886960 constant */
    /* @4886964 add */
    /* @4886968 constant */
    /* @4886972 load */
    /* @4886980 cast */
    /* @4886984 load */
    /* @4886992 constant */
    /* @4886996 add */
    /* @4887000 call */
    GM_SITE(vm, 583, 4887000);
    v133 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v134 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4887008 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v133, v134, STR_REF(1066)));
    /* @4887012 constant */
    /* @4887016 load */
    /* @4887024 cast */
    /* @4887028 load */
    /* @4887036 constant */
    /* @4887040 add */
    /* @4887044 constant */
    /* @4887048 load */
    /* @4887056 cast */
    /* @4887060 load */
    /* @4887068 constant */
    /* @4887072 add */
    /* @4887076 constant */
    /* @4887080 cast */
    /* @4887084 constant */
    /* @4887088 cast */
    /* @4887092 call */
    GM_SITE(vm, 583, 4887092);
    v135 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v136 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4887100 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(122), VAL(0), v135, v136));
    L_4887104: ;
    /* @4887104 load */
    /* @4887112 constant */
    /* @4887116 cmp */
    /* @4887120 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4887348;
    /* @4887124 constant */
    /* @4887128 cast */
    /* @4887132 call */
    GM_SITE(vm, 583, 4887132);
    /* @4887140 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4887144 constant */
    /* @4887152 cast */
    /* @4887156 call */
    GM_SITE(vm, 583, 4887156);
    /* @4887164 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4887168 string */
    /* @4887176 cast */
    /* @4887180 constant */
    /* @4887184 load */
    /* @4887192 cast */
    /* @4887196 load */
    /* @4887204 constant */
    /* @4887208 add */
    /* @4887212 constant */
    /* @4887216 load */
    /* @4887224 cast */
    /* @4887228 load */
    /* @4887236 constant */
    /* @4887240 add */
    /* @4887244 call */
    GM_SITE(vm, 583, 4887244);
    v137 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v138 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4887252 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v137, v138, STR_REF(1066)));
    /* @4887256 constant */
    /* @4887260 load */
    /* @4887268 cast */
    /* @4887272 load */
    /* @4887280 constant */
    /* @4887284 add */
    /* @4887288 constant */
    /* @4887292 load */
    /* @4887300 cast */
    /* @4887304 load */
    /* @4887312 constant */
    /* @4887316 add */
    /* @4887320 constant */
    /* @4887324 cast */
    /* @4887328 constant */
    /* @4887332 cast */
    /* @4887336 call */
    GM_SITE(vm, 583, 4887336);
    v139 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v140 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4887344 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(122), VAL(0), v139, v140));
    L_4887348: ;
    /* @4887348 load */
    /* @4887356 constant */
    /* @4887360 cmp */
    /* @4887364 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4887592;
    /* @4887368 constant */
    /* @4887372 cast */
    /* @4887376 call */
    GM_SITE(vm, 583, 4887376);
    /* @4887384 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4887388 constant */
    /* @4887396 cast */
    /* @4887400 call */
    GM_SITE(vm, 583, 4887400);
    /* @4887408 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4887412 string */
    /* @4887420 cast */
    /* @4887424 constant */
    /* @4887428 load */
    /* @4887436 cast */
    /* @4887440 load */
    /* @4887448 constant */
    /* @4887452 add */
    /* @4887456 constant */
    /* @4887460 load */
    /* @4887468 cast */
    /* @4887472 load */
    /* @4887480 constant */
    /* @4887484 add */
    /* @4887488 call */
    GM_SITE(vm, 583, 4887488);
    v141 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v142 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4887496 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v141, v142, STR_REF(1066)));
    /* @4887500 constant */
    /* @4887504 load */
    /* @4887512 cast */
    /* @4887516 load */
    /* @4887524 constant */
    /* @4887528 add */
    /* @4887532 constant */
    /* @4887536 load */
    /* @4887544 cast */
    /* @4887548 load */
    /* @4887556 constant */
    /* @4887560 add */
    /* @4887564 constant */
    /* @4887568 cast */
    /* @4887572 constant */
    /* @4887576 cast */
    /* @4887580 call */
    GM_SITE(vm, 583, 4887580);
    v143 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v144 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(110));
    /* @4887588 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(122), VAL(0), v143, v144));
    L_4887592: ;
    /* @4887592 load */
    /* @4887600 constant */
    /* @4887604 cmp */
    /* @4887608 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4887836;
    /* @4887612 constant */
    /* @4887616 cast */
    /* @4887620 call */
    GM_SITE(vm, 583, 4887620);
    /* @4887628 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4887632 constant */
    /* @4887640 cast */
    /* @4887644 call */
    GM_SITE(vm, 583, 4887644);
    /* @4887652 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4887656 string */
    /* @4887664 cast */
    /* @4887668 constant */
    /* @4887672 load */
    /* @4887680 cast */
    /* @4887684 load */
    /* @4887692 constant */
    /* @4887696 add */
    /* @4887700 constant */
    /* @4887704 load */
    /* @4887712 cast */
    /* @4887716 load */
    /* @4887724 constant */
    /* @4887728 add */
    /* @4887732 call */
    GM_SITE(vm, 583, 4887732);
    v145 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v146 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4887740 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v145, v146, STR_REF(1066)));
    /* @4887744 constant */
    /* @4887748 load */
    /* @4887756 cast */
    /* @4887760 load */
    /* @4887768 constant */
    /* @4887772 add */
    /* @4887776 constant */
    /* @4887780 load */
    /* @4887788 cast */
    /* @4887792 load */
    /* @4887800 constant */
    /* @4887804 add */
    /* @4887808 constant */
    /* @4887812 cast */
    /* @4887816 constant */
    /* @4887820 cast */
    /* @4887824 call */
    GM_SITE(vm, 583, 4887824);
    v147 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v148 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(110));
    /* @4887832 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(122), VAL(0), v147, v148));
    L_4887836: ;
    /* @4887836 load */
    /* @4887844 constant */
    /* @4887848 cmp */
    /* @4887852 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4888080;
    /* @4887856 constant */
    /* @4887860 cast */
    /* @4887864 call */
    GM_SITE(vm, 583, 4887864);
    /* @4887872 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4887876 constant */
    /* @4887884 cast */
    /* @4887888 call */
    GM_SITE(vm, 583, 4887888);
    /* @4887896 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4887900 string */
    /* @4887908 cast */
    /* @4887912 constant */
    /* @4887916 load */
    /* @4887924 cast */
    /* @4887928 load */
    /* @4887936 constant */
    /* @4887940 add */
    /* @4887944 constant */
    /* @4887948 load */
    /* @4887956 cast */
    /* @4887960 load */
    /* @4887968 constant */
    /* @4887972 add */
    /* @4887976 call */
    GM_SITE(vm, 583, 4887976);
    v149 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v150 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4887984 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v149, v150, STR_REF(1066)));
    /* @4887988 constant */
    /* @4887992 load */
    /* @4888000 cast */
    /* @4888004 load */
    /* @4888012 constant */
    /* @4888016 add */
    /* @4888020 constant */
    /* @4888024 load */
    /* @4888032 cast */
    /* @4888036 load */
    /* @4888044 constant */
    /* @4888048 add */
    /* @4888052 constant */
    /* @4888056 cast */
    /* @4888060 constant */
    /* @4888064 cast */
    /* @4888068 call */
    GM_SITE(vm, 583, 4888068);
    v151 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v152 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4888076 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(122), VAL(0), v151, v152));
    L_4888080: ;
    /* @4888080 load */
    /* @4888088 constant */
    /* @4888092 cmp */
    /* @4888096 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4888324;
    /* @4888100 constant */
    /* @4888104 cast */
    /* @4888108 call */
    GM_SITE(vm, 583, 4888108);
    /* @4888116 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4888120 constant */
    /* @4888128 cast */
    /* @4888132 call */
    GM_SITE(vm, 583, 4888132);
    /* @4888140 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4888144 string */
    /* @4888152 cast */
    /* @4888156 constant */
    /* @4888160 load */
    /* @4888168 cast */
    /* @4888172 load */
    /* @4888180 constant */
    /* @4888184 add */
    /* @4888188 constant */
    /* @4888192 load */
    /* @4888200 cast */
    /* @4888204 load */
    /* @4888212 constant */
    /* @4888216 add */
    /* @4888220 call */
    GM_SITE(vm, 583, 4888220);
    v153 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v154 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4888228 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v153, v154, STR_REF(1066)));
    /* @4888232 constant */
    /* @4888236 load */
    /* @4888244 cast */
    /* @4888248 load */
    /* @4888256 constant */
    /* @4888260 add */
    /* @4888264 constant */
    /* @4888268 load */
    /* @4888276 cast */
    /* @4888280 load */
    /* @4888288 constant */
    /* @4888292 add */
    /* @4888296 constant */
    /* @4888300 cast */
    /* @4888304 constant */
    /* @4888308 cast */
    /* @4888312 call */
    GM_SITE(vm, 583, 4888312);
    v155 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v156 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4888320 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(122), VAL(0), v155, v156));
    L_4888324: ;
    /* @4888324 load */
    /* @4888332 constant */
    /* @4888336 cmp */
    /* @4888340 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4888376;
    /* @4888344 constant */
    /* @4888348 cast */
    /* @4888352 constant */
    /* @4888356 cast */
    /* @4888360 call */
    GM_SITE(vm, 583, 4888360);
    /* @4888368 cast */
    /* @4888372 b */
    v157 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, VAL(0), VAL(1)));
    p4888380_0 = v157;
    goto L_4888380;
    L_4888376: ;
    /* @4888376 constant */
    p4888380_0 = VAL(0);
    L_4888380: ;
    /* @4888380 bf */
    if (!TRUTH(p4888380_0)) goto L_4888396;
    /* @4888384 call */
    GM_SITE(vm, 583, 4888384);
    /* @4888392 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4888396: ;
    return;
}
