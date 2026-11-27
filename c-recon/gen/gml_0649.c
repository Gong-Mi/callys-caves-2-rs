/* generated from CODE 649 (gml_Object_obj_lloydtutorial13_Draw_0), source start 4971140, end 4981864. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0649(GmVM* vm) {
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
    Val p4981848_0;
    Val v157;
    /* @4971140 constant */
    /* @4971144 load */
    /* @4971152 cast */
    /* @4971156 load */
    /* @4971164 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4971172 constant */
    /* @4971176 load */
    /* @4971184 cast */
    /* @4971188 load */
    /* @4971196 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4971204 load */
    /* @4971212 constant */
    /* @4971216 cmp */
    /* @4971220 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4971748;
    /* @4971224 constant */
    /* @4971228 cast */
    /* @4971232 constant */
    /* @4971236 cast */
    /* @4971240 constant */
    /* @4971244 cast */
    /* @4971248 constant */
    /* @4971260 cast */
    /* @4971264 constant */
    /* @4971276 cast */
    /* @4971280 constant */
    /* @4971284 constant */
    /* @4971288 load */
    /* @4971296 constant */
    /* @4971300 constant */
    /* @4971304 load */
    /* @4971312 constant */
    /* @4971316 sub */
    /* @4971320 constant */
    /* @4971324 cast */
    /* @4971328 constant */
    /* @4971332 cast */
    /* @4971336 call */
    GM_SITE(vm, 649, 4971336);
    /* @4971344 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(0.96), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4971348 constant */
    /* @4971352 cast */
    /* @4971356 constant */
    /* @4971360 cast */
    /* @4971364 constant */
    /* @4971368 cast */
    /* @4971372 constant */
    /* @4971376 cast */
    /* @4971380 constant */
    /* @4971384 cast */
    /* @4971388 constant */
    /* @4971392 load */
    /* @4971400 cast */
    /* @4971404 load */
    /* @4971412 constant */
    /* @4971416 add */
    /* @4971420 constant */
    /* @4971424 load */
    /* @4971432 cast */
    /* @4971436 load */
    /* @4971444 constant */
    /* @4971448 add */
    /* @4971452 constant */
    /* @4971456 cast */
    /* @4971460 constant */
    /* @4971464 cast */
    /* @4971468 call */
    GM_SITE(vm, 649, 4971468);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4971476 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v1, v2, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4971480 constant */
    /* @4971484 cast */
    /* @4971488 constant */
    /* @4971492 cast */
    /* @4971496 constant */
    /* @4971500 cast */
    /* @4971504 constant */
    /* @4971508 cast */
    /* @4971512 constant */
    /* @4971516 cast */
    /* @4971520 constant */
    /* @4971524 load */
    /* @4971532 cast */
    /* @4971536 load */
    /* @4971544 constant */
    /* @4971548 add */
    /* @4971552 constant */
    /* @4971556 load */
    /* @4971564 cast */
    /* @4971568 load */
    /* @4971576 constant */
    /* @4971580 add */
    /* @4971584 constant */
    /* @4971588 cast */
    /* @4971592 constant */
    /* @4971596 cast */
    /* @4971600 call */
    GM_SITE(vm, 649, 4971600);
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4971608 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v3, v4, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4971612 load */
    /* @4971620 constant */
    /* @4971624 cmp */
    /* @4971628 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4971748;
    /* @4971632 constant */
    /* @4971636 cast */
    /* @4971640 call */
    GM_SITE(vm, 649, 4971640);
    /* @4971648 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4971652 constant */
    /* @4971660 cast */
    /* @4971664 call */
    GM_SITE(vm, 649, 4971664);
    /* @4971672 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4971676 string */
    /* @4971684 cast */
    /* @4971688 constant */
    /* @4971692 constant */
    /* @4971696 load */
    /* @4971704 constant */
    /* @4971708 add */
    /* @4971712 constant */
    /* @4971716 constant */
    /* @4971720 load */
    /* @4971728 constant */
    /* @4971732 add */
    /* @4971736 call */
    GM_SITE(vm, 649, 4971736);
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(150));
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(200));
    /* @4971744 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v5, v6, STR_REF(743)));
    L_4971748: ;
    /* @4971748 load */
    /* @4971756 constant */
    /* @4971760 cmp */
    /* @4971764 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4972292;
    /* @4971768 constant */
    /* @4971772 cast */
    /* @4971776 constant */
    /* @4971780 cast */
    /* @4971784 constant */
    /* @4971788 cast */
    /* @4971792 constant */
    /* @4971804 cast */
    /* @4971808 constant */
    /* @4971820 cast */
    /* @4971824 constant */
    /* @4971828 constant */
    /* @4971832 load */
    /* @4971840 constant */
    /* @4971844 constant */
    /* @4971848 load */
    /* @4971856 constant */
    /* @4971860 sub */
    /* @4971864 constant */
    /* @4971868 cast */
    /* @4971872 constant */
    /* @4971876 cast */
    /* @4971880 call */
    GM_SITE(vm, 649, 4971880);
    /* @4971888 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(0.82), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4971892 constant */
    /* @4971896 cast */
    /* @4971900 constant */
    /* @4971904 cast */
    /* @4971908 constant */
    /* @4971912 cast */
    /* @4971916 constant */
    /* @4971920 cast */
    /* @4971924 constant */
    /* @4971928 cast */
    /* @4971932 constant */
    /* @4971936 load */
    /* @4971944 cast */
    /* @4971948 load */
    /* @4971956 constant */
    /* @4971960 add */
    /* @4971964 constant */
    /* @4971968 load */
    /* @4971976 cast */
    /* @4971980 load */
    /* @4971988 constant */
    /* @4971992 add */
    /* @4971996 constant */
    /* @4972000 cast */
    /* @4972004 constant */
    /* @4972008 cast */
    /* @4972012 call */
    GM_SITE(vm, 649, 4972012);
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4972020 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v7, v8, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4972024 constant */
    /* @4972028 cast */
    /* @4972032 constant */
    /* @4972036 cast */
    /* @4972040 constant */
    /* @4972044 cast */
    /* @4972048 constant */
    /* @4972052 cast */
    /* @4972056 constant */
    /* @4972060 cast */
    /* @4972064 constant */
    /* @4972068 load */
    /* @4972076 cast */
    /* @4972080 load */
    /* @4972088 constant */
    /* @4972092 add */
    /* @4972096 constant */
    /* @4972100 load */
    /* @4972108 cast */
    /* @4972112 load */
    /* @4972120 constant */
    /* @4972124 add */
    /* @4972128 constant */
    /* @4972132 cast */
    /* @4972136 constant */
    /* @4972140 cast */
    /* @4972144 call */
    GM_SITE(vm, 649, 4972144);
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(320));
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4972152 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v9, v10, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4972156 load */
    /* @4972164 constant */
    /* @4972168 cmp */
    /* @4972172 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4972292;
    /* @4972176 constant */
    /* @4972180 cast */
    /* @4972184 call */
    GM_SITE(vm, 649, 4972184);
    /* @4972192 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4972196 constant */
    /* @4972204 cast */
    /* @4972208 call */
    GM_SITE(vm, 649, 4972208);
    /* @4972216 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4972220 string */
    /* @4972228 cast */
    /* @4972232 constant */
    /* @4972236 constant */
    /* @4972240 load */
    /* @4972248 constant */
    /* @4972252 add */
    /* @4972256 constant */
    /* @4972260 constant */
    /* @4972264 load */
    /* @4972272 constant */
    /* @4972276 add */
    /* @4972280 call */
    GM_SITE(vm, 649, 4972280);
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(110));
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4972288 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v11, v12, STR_REF(743)));
    L_4972292: ;
    /* @4972292 load */
    /* @4972300 constant */
    /* @4972304 cmp */
    /* @4972308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4972836;
    /* @4972312 constant */
    /* @4972316 cast */
    /* @4972320 constant */
    /* @4972324 cast */
    /* @4972328 constant */
    /* @4972332 cast */
    /* @4972336 constant */
    /* @4972348 cast */
    /* @4972352 constant */
    /* @4972364 cast */
    /* @4972368 constant */
    /* @4972372 constant */
    /* @4972376 load */
    /* @4972384 constant */
    /* @4972388 constant */
    /* @4972392 load */
    /* @4972400 constant */
    /* @4972404 sub */
    /* @4972408 constant */
    /* @4972412 cast */
    /* @4972416 constant */
    /* @4972420 cast */
    /* @4972424 call */
    GM_SITE(vm, 649, 4972424);
    /* @4972432 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4972436 constant */
    /* @4972440 cast */
    /* @4972444 constant */
    /* @4972448 cast */
    /* @4972452 constant */
    /* @4972456 cast */
    /* @4972460 constant */
    /* @4972464 cast */
    /* @4972468 constant */
    /* @4972472 cast */
    /* @4972476 constant */
    /* @4972480 load */
    /* @4972488 cast */
    /* @4972492 load */
    /* @4972500 constant */
    /* @4972504 add */
    /* @4972508 constant */
    /* @4972512 load */
    /* @4972520 cast */
    /* @4972524 load */
    /* @4972532 constant */
    /* @4972536 add */
    /* @4972540 constant */
    /* @4972544 cast */
    /* @4972548 constant */
    /* @4972552 cast */
    /* @4972556 call */
    GM_SITE(vm, 649, 4972556);
    v13 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4972564 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v13, v14, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4972568 constant */
    /* @4972572 cast */
    /* @4972576 constant */
    /* @4972580 cast */
    /* @4972584 constant */
    /* @4972588 cast */
    /* @4972592 constant */
    /* @4972596 cast */
    /* @4972600 constant */
    /* @4972604 cast */
    /* @4972608 constant */
    /* @4972612 load */
    /* @4972620 cast */
    /* @4972624 load */
    /* @4972632 constant */
    /* @4972636 add */
    /* @4972640 constant */
    /* @4972644 load */
    /* @4972652 cast */
    /* @4972656 load */
    /* @4972664 constant */
    /* @4972668 add */
    /* @4972672 constant */
    /* @4972676 cast */
    /* @4972680 constant */
    /* @4972684 cast */
    /* @4972688 call */
    GM_SITE(vm, 649, 4972688);
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4972696 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v15, v16, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4972700 load */
    /* @4972708 constant */
    /* @4972712 cmp */
    /* @4972716 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4972836;
    /* @4972720 constant */
    /* @4972724 cast */
    /* @4972728 call */
    GM_SITE(vm, 649, 4972728);
    /* @4972736 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4972740 constant */
    /* @4972748 cast */
    /* @4972752 call */
    GM_SITE(vm, 649, 4972752);
    /* @4972760 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4972764 string */
    /* @4972772 cast */
    /* @4972776 constant */
    /* @4972780 constant */
    /* @4972784 load */
    /* @4972792 constant */
    /* @4972796 add */
    /* @4972800 constant */
    /* @4972804 constant */
    /* @4972808 load */
    /* @4972816 constant */
    /* @4972820 add */
    /* @4972824 call */
    GM_SITE(vm, 649, 4972824);
    v17 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(180));
    v18 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(300));
    /* @4972832 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v17, v18, STR_REF(743)));
    L_4972836: ;
    /* @4972836 load */
    /* @4972844 constant */
    /* @4972848 cmp */
    /* @4972852 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4973380;
    /* @4972856 constant */
    /* @4972860 cast */
    /* @4972864 constant */
    /* @4972868 cast */
    /* @4972872 constant */
    /* @4972876 cast */
    /* @4972880 constant */
    /* @4972892 cast */
    /* @4972896 constant */
    /* @4972908 cast */
    /* @4972912 constant */
    /* @4972916 constant */
    /* @4972920 load */
    /* @4972928 constant */
    /* @4972932 constant */
    /* @4972936 load */
    /* @4972944 constant */
    /* @4972948 sub */
    /* @4972952 constant */
    /* @4972956 cast */
    /* @4972960 constant */
    /* @4972964 cast */
    /* @4972968 call */
    GM_SITE(vm, 649, 4972968);
    /* @4972976 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4972980 constant */
    /* @4972984 cast */
    /* @4972988 constant */
    /* @4972992 cast */
    /* @4972996 constant */
    /* @4973000 cast */
    /* @4973004 constant */
    /* @4973008 cast */
    /* @4973012 constant */
    /* @4973016 cast */
    /* @4973020 constant */
    /* @4973024 load */
    /* @4973032 cast */
    /* @4973036 load */
    /* @4973044 constant */
    /* @4973048 add */
    /* @4973052 constant */
    /* @4973056 load */
    /* @4973064 cast */
    /* @4973068 load */
    /* @4973076 constant */
    /* @4973080 add */
    /* @4973084 constant */
    /* @4973088 cast */
    /* @4973092 constant */
    /* @4973096 cast */
    /* @4973100 call */
    GM_SITE(vm, 649, 4973100);
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4973108 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v19, v20, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4973112 constant */
    /* @4973116 cast */
    /* @4973120 constant */
    /* @4973124 cast */
    /* @4973128 constant */
    /* @4973132 cast */
    /* @4973136 constant */
    /* @4973140 cast */
    /* @4973144 constant */
    /* @4973148 cast */
    /* @4973152 constant */
    /* @4973156 load */
    /* @4973164 cast */
    /* @4973168 load */
    /* @4973176 constant */
    /* @4973180 add */
    /* @4973184 constant */
    /* @4973188 load */
    /* @4973196 cast */
    /* @4973200 load */
    /* @4973208 constant */
    /* @4973212 add */
    /* @4973216 constant */
    /* @4973220 cast */
    /* @4973224 constant */
    /* @4973228 cast */
    /* @4973232 call */
    GM_SITE(vm, 649, 4973232);
    v21 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4973240 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v21, v22, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4973244 load */
    /* @4973252 constant */
    /* @4973256 cmp */
    /* @4973260 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4973380;
    /* @4973264 constant */
    /* @4973268 cast */
    /* @4973272 call */
    GM_SITE(vm, 649, 4973272);
    /* @4973280 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4973284 constant */
    /* @4973292 cast */
    /* @4973296 call */
    GM_SITE(vm, 649, 4973296);
    /* @4973304 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4973308 string */
    /* @4973316 cast */
    /* @4973320 constant */
    /* @4973324 constant */
    /* @4973328 load */
    /* @4973336 constant */
    /* @4973340 add */
    /* @4973344 constant */
    /* @4973348 constant */
    /* @4973352 load */
    /* @4973360 constant */
    /* @4973364 add */
    /* @4973368 call */
    GM_SITE(vm, 649, 4973368);
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(180));
    v24 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(300));
    /* @4973376 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v23, v24, STR_REF(743)));
    L_4973380: ;
    /* @4973380 load */
    /* @4973388 constant */
    /* @4973392 cmp */
    /* @4973396 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4973924;
    /* @4973400 constant */
    /* @4973404 cast */
    /* @4973408 constant */
    /* @4973412 cast */
    /* @4973416 constant */
    /* @4973420 cast */
    /* @4973424 constant */
    /* @4973436 cast */
    /* @4973440 constant */
    /* @4973452 cast */
    /* @4973456 constant */
    /* @4973460 constant */
    /* @4973464 load */
    /* @4973472 constant */
    /* @4973476 constant */
    /* @4973480 load */
    /* @4973488 constant */
    /* @4973492 sub */
    /* @4973496 constant */
    /* @4973500 cast */
    /* @4973504 constant */
    /* @4973508 cast */
    /* @4973512 call */
    GM_SITE(vm, 649, 4973512);
    /* @4973520 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(0.97), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4973524 constant */
    /* @4973528 cast */
    /* @4973532 constant */
    /* @4973536 cast */
    /* @4973540 constant */
    /* @4973544 cast */
    /* @4973548 constant */
    /* @4973552 cast */
    /* @4973556 constant */
    /* @4973560 cast */
    /* @4973564 constant */
    /* @4973568 load */
    /* @4973576 cast */
    /* @4973580 load */
    /* @4973588 constant */
    /* @4973592 add */
    /* @4973596 constant */
    /* @4973600 load */
    /* @4973608 cast */
    /* @4973612 load */
    /* @4973620 constant */
    /* @4973624 add */
    /* @4973628 constant */
    /* @4973632 cast */
    /* @4973636 constant */
    /* @4973640 cast */
    /* @4973644 call */
    GM_SITE(vm, 649, 4973644);
    v25 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v26 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4973652 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v25, v26, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4973656 constant */
    /* @4973660 cast */
    /* @4973664 constant */
    /* @4973668 cast */
    /* @4973672 constant */
    /* @4973676 cast */
    /* @4973680 constant */
    /* @4973684 cast */
    /* @4973688 constant */
    /* @4973692 cast */
    /* @4973696 constant */
    /* @4973700 load */
    /* @4973708 cast */
    /* @4973712 load */
    /* @4973720 constant */
    /* @4973724 add */
    /* @4973728 constant */
    /* @4973732 load */
    /* @4973740 cast */
    /* @4973744 load */
    /* @4973752 constant */
    /* @4973756 add */
    /* @4973760 constant */
    /* @4973764 cast */
    /* @4973768 constant */
    /* @4973772 cast */
    /* @4973776 call */
    GM_SITE(vm, 649, 4973776);
    v27 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v28 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4973784 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v27, v28, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4973788 load */
    /* @4973796 constant */
    /* @4973800 cmp */
    /* @4973804 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4973924;
    /* @4973808 constant */
    /* @4973812 cast */
    /* @4973816 call */
    GM_SITE(vm, 649, 4973816);
    /* @4973824 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4973828 constant */
    /* @4973836 cast */
    /* @4973840 call */
    GM_SITE(vm, 649, 4973840);
    /* @4973848 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4973852 string */
    /* @4973860 cast */
    /* @4973864 constant */
    /* @4973868 constant */
    /* @4973872 load */
    /* @4973880 constant */
    /* @4973884 add */
    /* @4973888 constant */
    /* @4973892 constant */
    /* @4973896 load */
    /* @4973904 constant */
    /* @4973908 add */
    /* @4973912 call */
    GM_SITE(vm, 649, 4973912);
    v29 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(150));
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(200));
    /* @4973920 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v29, v30, STR_REF(743)));
    L_4973924: ;
    /* @4973924 load */
    /* @4973932 constant */
    /* @4973936 cmp */
    /* @4973940 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4974468;
    /* @4973944 constant */
    /* @4973948 cast */
    /* @4973952 constant */
    /* @4973956 cast */
    /* @4973960 constant */
    /* @4973964 cast */
    /* @4973968 constant */
    /* @4973980 cast */
    /* @4973984 constant */
    /* @4973996 cast */
    /* @4974000 constant */
    /* @4974004 constant */
    /* @4974008 load */
    /* @4974016 constant */
    /* @4974020 constant */
    /* @4974024 load */
    /* @4974032 constant */
    /* @4974036 sub */
    /* @4974040 constant */
    /* @4974044 cast */
    /* @4974048 constant */
    /* @4974052 cast */
    /* @4974056 call */
    GM_SITE(vm, 649, 4974056);
    /* @4974064 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(1.06), VAL(0.86), VAL(0), VAL(-1), VAL(1)));
    /* @4974068 constant */
    /* @4974072 cast */
    /* @4974076 constant */
    /* @4974080 cast */
    /* @4974084 constant */
    /* @4974088 cast */
    /* @4974092 constant */
    /* @4974096 cast */
    /* @4974100 constant */
    /* @4974104 cast */
    /* @4974108 constant */
    /* @4974112 load */
    /* @4974120 cast */
    /* @4974124 load */
    /* @4974132 constant */
    /* @4974136 add */
    /* @4974140 constant */
    /* @4974144 load */
    /* @4974152 cast */
    /* @4974156 load */
    /* @4974164 constant */
    /* @4974168 add */
    /* @4974172 constant */
    /* @4974176 cast */
    /* @4974180 constant */
    /* @4974184 cast */
    /* @4974188 call */
    GM_SITE(vm, 649, 4974188);
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v32 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4974196 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v31, v32, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4974200 constant */
    /* @4974204 cast */
    /* @4974208 constant */
    /* @4974212 cast */
    /* @4974216 constant */
    /* @4974220 cast */
    /* @4974224 constant */
    /* @4974228 cast */
    /* @4974232 constant */
    /* @4974236 cast */
    /* @4974240 constant */
    /* @4974244 load */
    /* @4974252 cast */
    /* @4974256 load */
    /* @4974264 constant */
    /* @4974268 add */
    /* @4974272 constant */
    /* @4974276 load */
    /* @4974284 cast */
    /* @4974288 load */
    /* @4974296 constant */
    /* @4974300 add */
    /* @4974304 constant */
    /* @4974308 cast */
    /* @4974312 constant */
    /* @4974316 cast */
    /* @4974320 call */
    GM_SITE(vm, 649, 4974320);
    v33 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(390));
    v34 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4974328 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v33, v34, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4974332 load */
    /* @4974340 constant */
    /* @4974344 cmp */
    /* @4974348 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4974468;
    /* @4974352 constant */
    /* @4974356 cast */
    /* @4974360 call */
    GM_SITE(vm, 649, 4974360);
    /* @4974368 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4974372 constant */
    /* @4974380 cast */
    /* @4974384 call */
    GM_SITE(vm, 649, 4974384);
    /* @4974392 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4974396 string */
    /* @4974404 cast */
    /* @4974408 constant */
    /* @4974412 constant */
    /* @4974416 load */
    /* @4974424 constant */
    /* @4974428 add */
    /* @4974432 constant */
    /* @4974436 constant */
    /* @4974440 load */
    /* @4974448 constant */
    /* @4974452 add */
    /* @4974456 call */
    GM_SITE(vm, 649, 4974456);
    v35 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(160));
    v36 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(200));
    /* @4974464 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v35, v36, STR_REF(743)));
    L_4974468: ;
    /* @4974468 load */
    /* @4974476 constant */
    /* @4974480 cmp */
    /* @4974484 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel1") == VAL(1)))) goto L_4975928;
    /* @4974488 load */
    /* @4974496 constant */
    /* @4974500 cmp */
    /* @4974504 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4974728;
    /* @4974508 constant */
    /* @4974512 cast */
    /* @4974516 call */
    GM_SITE(vm, 649, 4974516);
    /* @4974524 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4974528 constant */
    /* @4974536 cast */
    /* @4974540 call */
    GM_SITE(vm, 649, 4974540);
    /* @4974548 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4974552 string */
    /* @4974560 cast */
    /* @4974564 constant */
    /* @4974568 load */
    /* @4974576 cast */
    /* @4974580 load */
    /* @4974588 constant */
    /* @4974592 add */
    /* @4974596 constant */
    /* @4974600 load */
    /* @4974608 cast */
    /* @4974612 load */
    /* @4974620 constant */
    /* @4974624 add */
    /* @4974628 call */
    GM_SITE(vm, 649, 4974628);
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4974636 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v37, v38, STR_REF(1133)));
    /* @4974640 string */
    /* @4974648 cast */
    /* @4974652 constant */
    /* @4974656 load */
    /* @4974664 cast */
    /* @4974668 load */
    /* @4974676 constant */
    /* @4974680 add */
    /* @4974684 constant */
    /* @4974688 load */
    /* @4974696 cast */
    /* @4974700 load */
    /* @4974708 constant */
    /* @4974712 add */
    /* @4974716 call */
    GM_SITE(vm, 649, 4974716);
    v39 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v40 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4974724 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, v40, STR_REF(1134)));
    L_4974728: ;
    /* @4974728 load */
    /* @4974736 constant */
    /* @4974740 cmp */
    /* @4974744 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4974968;
    /* @4974748 constant */
    /* @4974752 cast */
    /* @4974756 call */
    GM_SITE(vm, 649, 4974756);
    /* @4974764 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4974768 constant */
    /* @4974776 cast */
    /* @4974780 call */
    GM_SITE(vm, 649, 4974780);
    /* @4974788 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4974792 string */
    /* @4974800 cast */
    /* @4974804 constant */
    /* @4974808 load */
    /* @4974816 cast */
    /* @4974820 load */
    /* @4974828 constant */
    /* @4974832 add */
    /* @4974836 constant */
    /* @4974840 load */
    /* @4974848 cast */
    /* @4974852 load */
    /* @4974860 constant */
    /* @4974864 add */
    /* @4974868 call */
    GM_SITE(vm, 649, 4974868);
    v41 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v42 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4974876 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v41, v42, STR_REF(1133)));
    /* @4974880 string */
    /* @4974888 cast */
    /* @4974892 constant */
    /* @4974896 load */
    /* @4974904 cast */
    /* @4974908 load */
    /* @4974916 constant */
    /* @4974920 add */
    /* @4974924 constant */
    /* @4974928 load */
    /* @4974936 cast */
    /* @4974940 load */
    /* @4974948 constant */
    /* @4974952 add */
    /* @4974956 call */
    GM_SITE(vm, 649, 4974956);
    v43 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v44 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4974964 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v43, v44, STR_REF(1134)));
    L_4974968: ;
    /* @4974968 load */
    /* @4974976 constant */
    /* @4974980 cmp */
    /* @4974984 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4975208;
    /* @4974988 constant */
    /* @4974992 cast */
    /* @4974996 call */
    GM_SITE(vm, 649, 4974996);
    /* @4975004 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4975008 constant */
    /* @4975016 cast */
    /* @4975020 call */
    GM_SITE(vm, 649, 4975020);
    /* @4975028 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4975032 string */
    /* @4975040 cast */
    /* @4975044 constant */
    /* @4975048 load */
    /* @4975056 cast */
    /* @4975060 load */
    /* @4975068 constant */
    /* @4975072 add */
    /* @4975076 constant */
    /* @4975080 load */
    /* @4975088 cast */
    /* @4975092 load */
    /* @4975100 constant */
    /* @4975104 add */
    /* @4975108 call */
    GM_SITE(vm, 649, 4975108);
    v45 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v46 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4975116 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v45, v46, STR_REF(1133)));
    /* @4975120 string */
    /* @4975128 cast */
    /* @4975132 constant */
    /* @4975136 load */
    /* @4975144 cast */
    /* @4975148 load */
    /* @4975156 constant */
    /* @4975160 add */
    /* @4975164 constant */
    /* @4975168 load */
    /* @4975176 cast */
    /* @4975180 load */
    /* @4975188 constant */
    /* @4975192 add */
    /* @4975196 call */
    GM_SITE(vm, 649, 4975196);
    v47 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v48 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4975204 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v47, v48, STR_REF(1134)));
    L_4975208: ;
    /* @4975208 load */
    /* @4975216 constant */
    /* @4975220 cmp */
    /* @4975224 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4975448;
    /* @4975228 constant */
    /* @4975232 cast */
    /* @4975236 call */
    GM_SITE(vm, 649, 4975236);
    /* @4975244 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4975248 constant */
    /* @4975256 cast */
    /* @4975260 call */
    GM_SITE(vm, 649, 4975260);
    /* @4975268 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4975272 string */
    /* @4975280 cast */
    /* @4975284 constant */
    /* @4975288 load */
    /* @4975296 cast */
    /* @4975300 load */
    /* @4975308 constant */
    /* @4975312 add */
    /* @4975316 constant */
    /* @4975320 load */
    /* @4975328 cast */
    /* @4975332 load */
    /* @4975340 constant */
    /* @4975344 add */
    /* @4975348 call */
    GM_SITE(vm, 649, 4975348);
    v49 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v50 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4975356 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v49, v50, STR_REF(1133)));
    /* @4975360 string */
    /* @4975368 cast */
    /* @4975372 constant */
    /* @4975376 load */
    /* @4975384 cast */
    /* @4975388 load */
    /* @4975396 constant */
    /* @4975400 add */
    /* @4975404 constant */
    /* @4975408 load */
    /* @4975416 cast */
    /* @4975420 load */
    /* @4975428 constant */
    /* @4975432 add */
    /* @4975436 call */
    GM_SITE(vm, 649, 4975436);
    v51 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v52 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4975444 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v51, v52, STR_REF(1134)));
    L_4975448: ;
    /* @4975448 load */
    /* @4975456 constant */
    /* @4975460 cmp */
    /* @4975464 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4975688;
    /* @4975468 constant */
    /* @4975472 cast */
    /* @4975476 call */
    GM_SITE(vm, 649, 4975476);
    /* @4975484 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4975488 constant */
    /* @4975496 cast */
    /* @4975500 call */
    GM_SITE(vm, 649, 4975500);
    /* @4975508 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4975512 string */
    /* @4975520 cast */
    /* @4975524 constant */
    /* @4975528 load */
    /* @4975536 cast */
    /* @4975540 load */
    /* @4975548 constant */
    /* @4975552 add */
    /* @4975556 constant */
    /* @4975560 load */
    /* @4975568 cast */
    /* @4975572 load */
    /* @4975580 constant */
    /* @4975584 add */
    /* @4975588 call */
    GM_SITE(vm, 649, 4975588);
    v53 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v54 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4975596 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v53, v54, STR_REF(1133)));
    /* @4975600 string */
    /* @4975608 cast */
    /* @4975612 constant */
    /* @4975616 load */
    /* @4975624 cast */
    /* @4975628 load */
    /* @4975636 constant */
    /* @4975640 add */
    /* @4975644 constant */
    /* @4975648 load */
    /* @4975656 cast */
    /* @4975660 load */
    /* @4975668 constant */
    /* @4975672 add */
    /* @4975676 call */
    GM_SITE(vm, 649, 4975676);
    v55 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v56 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4975684 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v55, v56, STR_REF(1134)));
    L_4975688: ;
    /* @4975688 load */
    /* @4975696 constant */
    /* @4975700 cmp */
    /* @4975704 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4975928;
    /* @4975708 constant */
    /* @4975712 cast */
    /* @4975716 call */
    GM_SITE(vm, 649, 4975716);
    /* @4975724 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4975728 constant */
    /* @4975736 cast */
    /* @4975740 call */
    GM_SITE(vm, 649, 4975740);
    /* @4975748 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4975752 string */
    /* @4975760 cast */
    /* @4975764 constant */
    /* @4975768 load */
    /* @4975776 cast */
    /* @4975780 load */
    /* @4975788 constant */
    /* @4975792 add */
    /* @4975796 constant */
    /* @4975800 load */
    /* @4975808 cast */
    /* @4975812 load */
    /* @4975820 constant */
    /* @4975824 add */
    /* @4975828 call */
    GM_SITE(vm, 649, 4975828);
    v57 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v58 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4975836 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v57, v58, STR_REF(1133)));
    /* @4975840 string */
    /* @4975848 cast */
    /* @4975852 constant */
    /* @4975856 load */
    /* @4975864 cast */
    /* @4975868 load */
    /* @4975876 constant */
    /* @4975880 add */
    /* @4975884 constant */
    /* @4975888 load */
    /* @4975896 cast */
    /* @4975900 load */
    /* @4975908 constant */
    /* @4975912 add */
    /* @4975916 call */
    GM_SITE(vm, 649, 4975916);
    v59 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v60 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4975924 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v59, v60, STR_REF(1134)));
    L_4975928: ;
    /* @4975928 load */
    /* @4975936 constant */
    /* @4975940 cmp */
    /* @4975944 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel2") == VAL(1)))) goto L_4976860;
    /* @4975948 load */
    /* @4975956 constant */
    /* @4975960 cmp */
    /* @4975964 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4976100;
    /* @4975968 constant */
    /* @4975972 cast */
    /* @4975976 call */
    GM_SITE(vm, 649, 4975976);
    /* @4975984 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4975988 constant */
    /* @4975996 cast */
    /* @4976000 call */
    GM_SITE(vm, 649, 4976000);
    /* @4976008 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4976012 string */
    /* @4976020 cast */
    /* @4976024 constant */
    /* @4976028 load */
    /* @4976036 cast */
    /* @4976040 load */
    /* @4976048 constant */
    /* @4976052 add */
    /* @4976056 constant */
    /* @4976060 load */
    /* @4976068 cast */
    /* @4976072 load */
    /* @4976080 constant */
    /* @4976084 add */
    /* @4976088 call */
    GM_SITE(vm, 649, 4976088);
    v61 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(190));
    v62 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4976096 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v61, v62, STR_REF(1135)));
    L_4976100: ;
    /* @4976100 load */
    /* @4976108 constant */
    /* @4976112 cmp */
    /* @4976116 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4976252;
    /* @4976120 constant */
    /* @4976124 cast */
    /* @4976128 call */
    GM_SITE(vm, 649, 4976128);
    /* @4976136 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4976140 constant */
    /* @4976148 cast */
    /* @4976152 call */
    GM_SITE(vm, 649, 4976152);
    /* @4976160 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4976164 string */
    /* @4976172 cast */
    /* @4976176 constant */
    /* @4976180 load */
    /* @4976188 cast */
    /* @4976192 load */
    /* @4976200 constant */
    /* @4976204 add */
    /* @4976208 constant */
    /* @4976212 load */
    /* @4976220 cast */
    /* @4976224 load */
    /* @4976232 constant */
    /* @4976236 add */
    /* @4976240 call */
    GM_SITE(vm, 649, 4976240);
    v63 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(140));
    v64 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    /* @4976248 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v63, v64, STR_REF(1135)));
    L_4976252: ;
    /* @4976252 load */
    /* @4976260 constant */
    /* @4976264 cmp */
    /* @4976268 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4976404;
    /* @4976272 constant */
    /* @4976276 cast */
    /* @4976280 call */
    GM_SITE(vm, 649, 4976280);
    /* @4976288 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4976292 constant */
    /* @4976300 cast */
    /* @4976304 call */
    GM_SITE(vm, 649, 4976304);
    /* @4976312 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4976316 string */
    /* @4976324 cast */
    /* @4976328 constant */
    /* @4976332 load */
    /* @4976340 cast */
    /* @4976344 load */
    /* @4976352 constant */
    /* @4976356 add */
    /* @4976360 constant */
    /* @4976364 load */
    /* @4976372 cast */
    /* @4976376 load */
    /* @4976384 constant */
    /* @4976388 add */
    /* @4976392 call */
    GM_SITE(vm, 649, 4976392);
    v65 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v66 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4976400 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v65, v66, STR_REF(1135)));
    L_4976404: ;
    /* @4976404 load */
    /* @4976412 constant */
    /* @4976416 cmp */
    /* @4976420 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4976556;
    /* @4976424 constant */
    /* @4976428 cast */
    /* @4976432 call */
    GM_SITE(vm, 649, 4976432);
    /* @4976440 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4976444 constant */
    /* @4976452 cast */
    /* @4976456 call */
    GM_SITE(vm, 649, 4976456);
    /* @4976464 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4976468 string */
    /* @4976476 cast */
    /* @4976480 constant */
    /* @4976484 load */
    /* @4976492 cast */
    /* @4976496 load */
    /* @4976504 constant */
    /* @4976508 add */
    /* @4976512 constant */
    /* @4976516 load */
    /* @4976524 cast */
    /* @4976528 load */
    /* @4976536 constant */
    /* @4976540 add */
    /* @4976544 call */
    GM_SITE(vm, 649, 4976544);
    v67 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v68 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4976552 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v67, v68, STR_REF(1135)));
    L_4976556: ;
    /* @4976556 load */
    /* @4976564 constant */
    /* @4976568 cmp */
    /* @4976572 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4976708;
    /* @4976576 constant */
    /* @4976580 cast */
    /* @4976584 call */
    GM_SITE(vm, 649, 4976584);
    /* @4976592 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4976596 constant */
    /* @4976604 cast */
    /* @4976608 call */
    GM_SITE(vm, 649, 4976608);
    /* @4976616 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4976620 string */
    /* @4976628 cast */
    /* @4976632 constant */
    /* @4976636 load */
    /* @4976644 cast */
    /* @4976648 load */
    /* @4976656 constant */
    /* @4976660 add */
    /* @4976664 constant */
    /* @4976668 load */
    /* @4976676 cast */
    /* @4976680 load */
    /* @4976688 constant */
    /* @4976692 add */
    /* @4976696 call */
    GM_SITE(vm, 649, 4976696);
    v69 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(190));
    v70 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4976704 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v69, v70, STR_REF(1135)));
    L_4976708: ;
    /* @4976708 load */
    /* @4976716 constant */
    /* @4976720 cmp */
    /* @4976724 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4976860;
    /* @4976728 constant */
    /* @4976732 cast */
    /* @4976736 call */
    GM_SITE(vm, 649, 4976736);
    /* @4976744 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4976748 constant */
    /* @4976756 cast */
    /* @4976760 call */
    GM_SITE(vm, 649, 4976760);
    /* @4976768 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4976772 string */
    /* @4976780 cast */
    /* @4976784 constant */
    /* @4976788 load */
    /* @4976796 cast */
    /* @4976800 load */
    /* @4976808 constant */
    /* @4976812 add */
    /* @4976816 constant */
    /* @4976820 load */
    /* @4976828 cast */
    /* @4976832 load */
    /* @4976840 constant */
    /* @4976844 add */
    /* @4976848 call */
    GM_SITE(vm, 649, 4976848);
    v71 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(190));
    v72 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4976856 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v71, v72, STR_REF(1135)));
    L_4976860: ;
    /* @4976860 load */
    /* @4976868 constant */
    /* @4976872 cmp */
    /* @4976876 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel3") == VAL(1)))) goto L_4978320;
    /* @4976880 load */
    /* @4976888 constant */
    /* @4976892 cmp */
    /* @4976896 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4977120;
    /* @4976900 constant */
    /* @4976904 cast */
    /* @4976908 call */
    GM_SITE(vm, 649, 4976908);
    /* @4976916 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4976920 constant */
    /* @4976928 cast */
    /* @4976932 call */
    GM_SITE(vm, 649, 4976932);
    /* @4976940 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4976944 string */
    /* @4976952 cast */
    /* @4976956 constant */
    /* @4976960 load */
    /* @4976968 cast */
    /* @4976972 load */
    /* @4976980 constant */
    /* @4976984 add */
    /* @4976988 constant */
    /* @4976992 load */
    /* @4977000 cast */
    /* @4977004 load */
    /* @4977012 constant */
    /* @4977016 add */
    /* @4977020 call */
    GM_SITE(vm, 649, 4977020);
    v73 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v74 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4977028 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v73, v74, STR_REF(1136)));
    /* @4977032 string */
    /* @4977040 cast */
    /* @4977044 constant */
    /* @4977048 load */
    /* @4977056 cast */
    /* @4977060 load */
    /* @4977068 constant */
    /* @4977072 add */
    /* @4977076 constant */
    /* @4977080 load */
    /* @4977088 cast */
    /* @4977092 load */
    /* @4977100 constant */
    /* @4977104 add */
    /* @4977108 call */
    GM_SITE(vm, 649, 4977108);
    v75 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v76 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4977116 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v75, v76, STR_REF(1137)));
    L_4977120: ;
    /* @4977120 load */
    /* @4977128 constant */
    /* @4977132 cmp */
    /* @4977136 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4977360;
    /* @4977140 constant */
    /* @4977144 cast */
    /* @4977148 call */
    GM_SITE(vm, 649, 4977148);
    /* @4977156 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4977160 constant */
    /* @4977168 cast */
    /* @4977172 call */
    GM_SITE(vm, 649, 4977172);
    /* @4977180 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4977184 string */
    /* @4977192 cast */
    /* @4977196 constant */
    /* @4977200 load */
    /* @4977208 cast */
    /* @4977212 load */
    /* @4977220 constant */
    /* @4977224 add */
    /* @4977228 constant */
    /* @4977232 load */
    /* @4977240 cast */
    /* @4977244 load */
    /* @4977252 constant */
    /* @4977256 add */
    /* @4977260 call */
    GM_SITE(vm, 649, 4977260);
    v77 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v78 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4977268 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v77, v78, STR_REF(1136)));
    /* @4977272 string */
    /* @4977280 cast */
    /* @4977284 constant */
    /* @4977288 load */
    /* @4977296 cast */
    /* @4977300 load */
    /* @4977308 constant */
    /* @4977312 add */
    /* @4977316 constant */
    /* @4977320 load */
    /* @4977328 cast */
    /* @4977332 load */
    /* @4977340 constant */
    /* @4977344 add */
    /* @4977348 call */
    GM_SITE(vm, 649, 4977348);
    v79 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v80 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4977356 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v79, v80, STR_REF(1137)));
    L_4977360: ;
    /* @4977360 load */
    /* @4977368 constant */
    /* @4977372 cmp */
    /* @4977376 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4977600;
    /* @4977380 constant */
    /* @4977384 cast */
    /* @4977388 call */
    GM_SITE(vm, 649, 4977388);
    /* @4977396 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4977400 constant */
    /* @4977408 cast */
    /* @4977412 call */
    GM_SITE(vm, 649, 4977412);
    /* @4977420 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4977424 string */
    /* @4977432 cast */
    /* @4977436 constant */
    /* @4977440 load */
    /* @4977448 cast */
    /* @4977452 load */
    /* @4977460 constant */
    /* @4977464 add */
    /* @4977468 constant */
    /* @4977472 load */
    /* @4977480 cast */
    /* @4977484 load */
    /* @4977492 constant */
    /* @4977496 add */
    /* @4977500 call */
    GM_SITE(vm, 649, 4977500);
    v81 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v82 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4977508 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v81, v82, STR_REF(1136)));
    /* @4977512 string */
    /* @4977520 cast */
    /* @4977524 constant */
    /* @4977528 load */
    /* @4977536 cast */
    /* @4977540 load */
    /* @4977548 constant */
    /* @4977552 add */
    /* @4977556 constant */
    /* @4977560 load */
    /* @4977568 cast */
    /* @4977572 load */
    /* @4977580 constant */
    /* @4977584 add */
    /* @4977588 call */
    GM_SITE(vm, 649, 4977588);
    v83 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v84 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4977596 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v83, v84, STR_REF(1137)));
    L_4977600: ;
    /* @4977600 load */
    /* @4977608 constant */
    /* @4977612 cmp */
    /* @4977616 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4977840;
    /* @4977620 constant */
    /* @4977624 cast */
    /* @4977628 call */
    GM_SITE(vm, 649, 4977628);
    /* @4977636 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4977640 constant */
    /* @4977648 cast */
    /* @4977652 call */
    GM_SITE(vm, 649, 4977652);
    /* @4977660 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4977664 string */
    /* @4977672 cast */
    /* @4977676 constant */
    /* @4977680 load */
    /* @4977688 cast */
    /* @4977692 load */
    /* @4977700 constant */
    /* @4977704 add */
    /* @4977708 constant */
    /* @4977712 load */
    /* @4977720 cast */
    /* @4977724 load */
    /* @4977732 constant */
    /* @4977736 add */
    /* @4977740 call */
    GM_SITE(vm, 649, 4977740);
    v85 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v86 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4977748 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v85, v86, STR_REF(1136)));
    /* @4977752 string */
    /* @4977760 cast */
    /* @4977764 constant */
    /* @4977768 load */
    /* @4977776 cast */
    /* @4977780 load */
    /* @4977788 constant */
    /* @4977792 add */
    /* @4977796 constant */
    /* @4977800 load */
    /* @4977808 cast */
    /* @4977812 load */
    /* @4977820 constant */
    /* @4977824 add */
    /* @4977828 call */
    GM_SITE(vm, 649, 4977828);
    v87 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v88 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4977836 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v87, v88, STR_REF(1137)));
    L_4977840: ;
    /* @4977840 load */
    /* @4977848 constant */
    /* @4977852 cmp */
    /* @4977856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4978080;
    /* @4977860 constant */
    /* @4977864 cast */
    /* @4977868 call */
    GM_SITE(vm, 649, 4977868);
    /* @4977876 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4977880 constant */
    /* @4977888 cast */
    /* @4977892 call */
    GM_SITE(vm, 649, 4977892);
    /* @4977900 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4977904 string */
    /* @4977912 cast */
    /* @4977916 constant */
    /* @4977920 load */
    /* @4977928 cast */
    /* @4977932 load */
    /* @4977940 constant */
    /* @4977944 add */
    /* @4977948 constant */
    /* @4977952 load */
    /* @4977960 cast */
    /* @4977964 load */
    /* @4977972 constant */
    /* @4977976 add */
    /* @4977980 call */
    GM_SITE(vm, 649, 4977980);
    v89 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v90 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4977988 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v89, v90, STR_REF(1136)));
    /* @4977992 string */
    /* @4978000 cast */
    /* @4978004 constant */
    /* @4978008 load */
    /* @4978016 cast */
    /* @4978020 load */
    /* @4978028 constant */
    /* @4978032 add */
    /* @4978036 constant */
    /* @4978040 load */
    /* @4978048 cast */
    /* @4978052 load */
    /* @4978060 constant */
    /* @4978064 add */
    /* @4978068 call */
    GM_SITE(vm, 649, 4978068);
    v91 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v92 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4978076 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v91, v92, STR_REF(1137)));
    L_4978080: ;
    /* @4978080 load */
    /* @4978088 constant */
    /* @4978092 cmp */
    /* @4978096 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4978320;
    /* @4978100 constant */
    /* @4978104 cast */
    /* @4978108 call */
    GM_SITE(vm, 649, 4978108);
    /* @4978116 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4978120 constant */
    /* @4978128 cast */
    /* @4978132 call */
    GM_SITE(vm, 649, 4978132);
    /* @4978140 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4978144 string */
    /* @4978152 cast */
    /* @4978156 constant */
    /* @4978160 load */
    /* @4978168 cast */
    /* @4978172 load */
    /* @4978180 constant */
    /* @4978184 add */
    /* @4978188 constant */
    /* @4978192 load */
    /* @4978200 cast */
    /* @4978204 load */
    /* @4978212 constant */
    /* @4978216 add */
    /* @4978220 call */
    GM_SITE(vm, 649, 4978220);
    v93 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v94 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4978228 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v93, v94, STR_REF(1136)));
    /* @4978232 string */
    /* @4978240 cast */
    /* @4978244 constant */
    /* @4978248 load */
    /* @4978256 cast */
    /* @4978260 load */
    /* @4978268 constant */
    /* @4978272 add */
    /* @4978276 constant */
    /* @4978280 load */
    /* @4978288 cast */
    /* @4978292 load */
    /* @4978300 constant */
    /* @4978304 add */
    /* @4978308 call */
    GM_SITE(vm, 649, 4978308);
    v95 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v96 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4978316 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v95, v96, STR_REF(1137)));
    L_4978320: ;
    /* @4978320 load */
    /* @4978328 constant */
    /* @4978332 cmp */
    /* @4978336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel4") == VAL(1)))) goto L_4979780;
    /* @4978340 load */
    /* @4978348 constant */
    /* @4978352 cmp */
    /* @4978356 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4978580;
    /* @4978360 constant */
    /* @4978364 cast */
    /* @4978368 call */
    GM_SITE(vm, 649, 4978368);
    /* @4978376 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4978380 constant */
    /* @4978388 cast */
    /* @4978392 call */
    GM_SITE(vm, 649, 4978392);
    /* @4978400 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4978404 string */
    /* @4978412 cast */
    /* @4978416 constant */
    /* @4978420 load */
    /* @4978428 cast */
    /* @4978432 load */
    /* @4978440 constant */
    /* @4978444 add */
    /* @4978448 constant */
    /* @4978452 load */
    /* @4978460 cast */
    /* @4978464 load */
    /* @4978472 constant */
    /* @4978476 add */
    /* @4978480 call */
    GM_SITE(vm, 649, 4978480);
    v97 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v98 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4978488 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v97, v98, STR_REF(1138)));
    /* @4978492 string */
    /* @4978500 cast */
    /* @4978504 constant */
    /* @4978508 load */
    /* @4978516 cast */
    /* @4978520 load */
    /* @4978528 constant */
    /* @4978532 add */
    /* @4978536 constant */
    /* @4978540 load */
    /* @4978548 cast */
    /* @4978552 load */
    /* @4978560 constant */
    /* @4978564 add */
    /* @4978568 call */
    GM_SITE(vm, 649, 4978568);
    v99 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v100 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4978576 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v99, v100, STR_REF(1139)));
    L_4978580: ;
    /* @4978580 load */
    /* @4978588 constant */
    /* @4978592 cmp */
    /* @4978596 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4978820;
    /* @4978600 constant */
    /* @4978604 cast */
    /* @4978608 call */
    GM_SITE(vm, 649, 4978608);
    /* @4978616 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4978620 constant */
    /* @4978628 cast */
    /* @4978632 call */
    GM_SITE(vm, 649, 4978632);
    /* @4978640 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4978644 string */
    /* @4978652 cast */
    /* @4978656 constant */
    /* @4978660 load */
    /* @4978668 cast */
    /* @4978672 load */
    /* @4978680 constant */
    /* @4978684 add */
    /* @4978688 constant */
    /* @4978692 load */
    /* @4978700 cast */
    /* @4978704 load */
    /* @4978712 constant */
    /* @4978716 add */
    /* @4978720 call */
    GM_SITE(vm, 649, 4978720);
    v101 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v102 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4978728 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v101, v102, STR_REF(1138)));
    /* @4978732 string */
    /* @4978740 cast */
    /* @4978744 constant */
    /* @4978748 load */
    /* @4978756 cast */
    /* @4978760 load */
    /* @4978768 constant */
    /* @4978772 add */
    /* @4978776 constant */
    /* @4978780 load */
    /* @4978788 cast */
    /* @4978792 load */
    /* @4978800 constant */
    /* @4978804 add */
    /* @4978808 call */
    GM_SITE(vm, 649, 4978808);
    v103 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v104 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4978816 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v103, v104, STR_REF(1139)));
    L_4978820: ;
    /* @4978820 load */
    /* @4978828 constant */
    /* @4978832 cmp */
    /* @4978836 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4979060;
    /* @4978840 constant */
    /* @4978844 cast */
    /* @4978848 call */
    GM_SITE(vm, 649, 4978848);
    /* @4978856 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4978860 constant */
    /* @4978868 cast */
    /* @4978872 call */
    GM_SITE(vm, 649, 4978872);
    /* @4978880 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4978884 string */
    /* @4978892 cast */
    /* @4978896 constant */
    /* @4978900 load */
    /* @4978908 cast */
    /* @4978912 load */
    /* @4978920 constant */
    /* @4978924 add */
    /* @4978928 constant */
    /* @4978932 load */
    /* @4978940 cast */
    /* @4978944 load */
    /* @4978952 constant */
    /* @4978956 add */
    /* @4978960 call */
    GM_SITE(vm, 649, 4978960);
    v105 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v106 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4978968 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v105, v106, STR_REF(1138)));
    /* @4978972 string */
    /* @4978980 cast */
    /* @4978984 constant */
    /* @4978988 load */
    /* @4978996 cast */
    /* @4979000 load */
    /* @4979008 constant */
    /* @4979012 add */
    /* @4979016 constant */
    /* @4979020 load */
    /* @4979028 cast */
    /* @4979032 load */
    /* @4979040 constant */
    /* @4979044 add */
    /* @4979048 call */
    GM_SITE(vm, 649, 4979048);
    v107 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v108 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4979056 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v107, v108, STR_REF(1139)));
    L_4979060: ;
    /* @4979060 load */
    /* @4979068 constant */
    /* @4979072 cmp */
    /* @4979076 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4979300;
    /* @4979080 constant */
    /* @4979084 cast */
    /* @4979088 call */
    GM_SITE(vm, 649, 4979088);
    /* @4979096 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4979100 constant */
    /* @4979108 cast */
    /* @4979112 call */
    GM_SITE(vm, 649, 4979112);
    /* @4979120 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4979124 string */
    /* @4979132 cast */
    /* @4979136 constant */
    /* @4979140 load */
    /* @4979148 cast */
    /* @4979152 load */
    /* @4979160 constant */
    /* @4979164 add */
    /* @4979168 constant */
    /* @4979172 load */
    /* @4979180 cast */
    /* @4979184 load */
    /* @4979192 constant */
    /* @4979196 add */
    /* @4979200 call */
    GM_SITE(vm, 649, 4979200);
    v109 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v110 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4979208 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v109, v110, STR_REF(1138)));
    /* @4979212 string */
    /* @4979220 cast */
    /* @4979224 constant */
    /* @4979228 load */
    /* @4979236 cast */
    /* @4979240 load */
    /* @4979248 constant */
    /* @4979252 add */
    /* @4979256 constant */
    /* @4979260 load */
    /* @4979268 cast */
    /* @4979272 load */
    /* @4979280 constant */
    /* @4979284 add */
    /* @4979288 call */
    GM_SITE(vm, 649, 4979288);
    v111 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v112 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4979296 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v111, v112, STR_REF(1139)));
    L_4979300: ;
    /* @4979300 load */
    /* @4979308 constant */
    /* @4979312 cmp */
    /* @4979316 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4979540;
    /* @4979320 constant */
    /* @4979324 cast */
    /* @4979328 call */
    GM_SITE(vm, 649, 4979328);
    /* @4979336 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4979340 constant */
    /* @4979348 cast */
    /* @4979352 call */
    GM_SITE(vm, 649, 4979352);
    /* @4979360 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4979364 string */
    /* @4979372 cast */
    /* @4979376 constant */
    /* @4979380 load */
    /* @4979388 cast */
    /* @4979392 load */
    /* @4979400 constant */
    /* @4979404 add */
    /* @4979408 constant */
    /* @4979412 load */
    /* @4979420 cast */
    /* @4979424 load */
    /* @4979432 constant */
    /* @4979436 add */
    /* @4979440 call */
    GM_SITE(vm, 649, 4979440);
    v113 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v114 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4979448 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v113, v114, STR_REF(1138)));
    /* @4979452 string */
    /* @4979460 cast */
    /* @4979464 constant */
    /* @4979468 load */
    /* @4979476 cast */
    /* @4979480 load */
    /* @4979488 constant */
    /* @4979492 add */
    /* @4979496 constant */
    /* @4979500 load */
    /* @4979508 cast */
    /* @4979512 load */
    /* @4979520 constant */
    /* @4979524 add */
    /* @4979528 call */
    GM_SITE(vm, 649, 4979528);
    v115 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v116 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4979536 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v115, v116, STR_REF(1139)));
    L_4979540: ;
    /* @4979540 load */
    /* @4979548 constant */
    /* @4979552 cmp */
    /* @4979556 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4979780;
    /* @4979560 constant */
    /* @4979564 cast */
    /* @4979568 call */
    GM_SITE(vm, 649, 4979568);
    /* @4979576 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4979580 constant */
    /* @4979588 cast */
    /* @4979592 call */
    GM_SITE(vm, 649, 4979592);
    /* @4979600 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4979604 string */
    /* @4979612 cast */
    /* @4979616 constant */
    /* @4979620 load */
    /* @4979628 cast */
    /* @4979632 load */
    /* @4979640 constant */
    /* @4979644 add */
    /* @4979648 constant */
    /* @4979652 load */
    /* @4979660 cast */
    /* @4979664 load */
    /* @4979672 constant */
    /* @4979676 add */
    /* @4979680 call */
    GM_SITE(vm, 649, 4979680);
    v117 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v118 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4979688 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v117, v118, STR_REF(1138)));
    /* @4979692 string */
    /* @4979700 cast */
    /* @4979704 constant */
    /* @4979708 load */
    /* @4979716 cast */
    /* @4979720 load */
    /* @4979728 constant */
    /* @4979732 add */
    /* @4979736 constant */
    /* @4979740 load */
    /* @4979748 cast */
    /* @4979752 load */
    /* @4979760 constant */
    /* @4979764 add */
    /* @4979768 call */
    GM_SITE(vm, 649, 4979768);
    v119 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v120 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4979776 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v119, v120, STR_REF(1139)));
    L_4979780: ;
    /* @4979780 load */
    /* @4979788 constant */
    /* @4979792 cmp */
    /* @4979796 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel5") == VAL(1)))) goto L_4981792;
    /* @4979800 load */
    /* @4979808 constant */
    /* @4979812 cmp */
    /* @4979816 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4980132;
    /* @4979820 constant */
    /* @4979824 cast */
    /* @4979828 call */
    GM_SITE(vm, 649, 4979828);
    /* @4979836 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4979840 constant */
    /* @4979848 cast */
    /* @4979852 call */
    GM_SITE(vm, 649, 4979852);
    /* @4979860 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4979864 string */
    /* @4979872 cast */
    /* @4979876 constant */
    /* @4979880 load */
    /* @4979888 cast */
    /* @4979892 load */
    /* @4979900 constant */
    /* @4979904 add */
    /* @4979908 constant */
    /* @4979912 load */
    /* @4979920 cast */
    /* @4979924 load */
    /* @4979932 constant */
    /* @4979936 add */
    /* @4979940 call */
    GM_SITE(vm, 649, 4979940);
    v121 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v122 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4979948 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v121, v122, STR_REF(1140)));
    /* @4979952 string */
    /* @4979960 cast */
    /* @4979964 constant */
    /* @4979968 load */
    /* @4979976 cast */
    /* @4979980 load */
    /* @4979988 constant */
    /* @4979992 add */
    /* @4979996 constant */
    /* @4980000 load */
    /* @4980008 cast */
    /* @4980012 load */
    /* @4980020 constant */
    /* @4980024 add */
    /* @4980028 call */
    GM_SITE(vm, 649, 4980028);
    v123 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v124 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4980036 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v123, v124, STR_REF(1141)));
    /* @4980040 constant */
    /* @4980044 load */
    /* @4980052 cast */
    /* @4980056 load */
    /* @4980064 constant */
    /* @4980068 add */
    /* @4980072 constant */
    /* @4980076 load */
    /* @4980084 cast */
    /* @4980088 load */
    /* @4980096 constant */
    /* @4980100 add */
    /* @4980104 constant */
    /* @4980108 cast */
    /* @4980112 constant */
    /* @4980116 cast */
    /* @4980120 call */
    GM_SITE(vm, 649, 4980120);
    v125 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v126 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(90));
    /* @4980128 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(157), VAL(0), v125, v126));
    L_4980132: ;
    /* @4980132 load */
    /* @4980140 constant */
    /* @4980144 cmp */
    /* @4980148 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4980464;
    /* @4980152 constant */
    /* @4980156 cast */
    /* @4980160 call */
    GM_SITE(vm, 649, 4980160);
    /* @4980168 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4980172 constant */
    /* @4980180 cast */
    /* @4980184 call */
    GM_SITE(vm, 649, 4980184);
    /* @4980192 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4980196 string */
    /* @4980204 cast */
    /* @4980208 constant */
    /* @4980212 load */
    /* @4980220 cast */
    /* @4980224 load */
    /* @4980232 constant */
    /* @4980236 add */
    /* @4980240 constant */
    /* @4980244 load */
    /* @4980252 cast */
    /* @4980256 load */
    /* @4980264 constant */
    /* @4980268 add */
    /* @4980272 call */
    GM_SITE(vm, 649, 4980272);
    v127 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v128 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4980280 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v127, v128, STR_REF(1140)));
    /* @4980284 string */
    /* @4980292 cast */
    /* @4980296 constant */
    /* @4980300 load */
    /* @4980308 cast */
    /* @4980312 load */
    /* @4980320 constant */
    /* @4980324 add */
    /* @4980328 constant */
    /* @4980332 load */
    /* @4980340 cast */
    /* @4980344 load */
    /* @4980352 constant */
    /* @4980356 add */
    /* @4980360 call */
    GM_SITE(vm, 649, 4980360);
    v129 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v130 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4980368 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v129, v130, STR_REF(1141)));
    /* @4980372 constant */
    /* @4980376 load */
    /* @4980384 cast */
    /* @4980388 load */
    /* @4980396 constant */
    /* @4980400 add */
    /* @4980404 constant */
    /* @4980408 load */
    /* @4980416 cast */
    /* @4980420 load */
    /* @4980428 constant */
    /* @4980432 add */
    /* @4980436 constant */
    /* @4980440 cast */
    /* @4980444 constant */
    /* @4980448 cast */
    /* @4980452 call */
    GM_SITE(vm, 649, 4980452);
    v131 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v132 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(90));
    /* @4980460 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(157), VAL(0), v131, v132));
    L_4980464: ;
    /* @4980464 load */
    /* @4980472 constant */
    /* @4980476 cmp */
    /* @4980480 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4980796;
    /* @4980484 constant */
    /* @4980488 cast */
    /* @4980492 call */
    GM_SITE(vm, 649, 4980492);
    /* @4980500 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4980504 constant */
    /* @4980512 cast */
    /* @4980516 call */
    GM_SITE(vm, 649, 4980516);
    /* @4980524 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4980528 string */
    /* @4980536 cast */
    /* @4980540 constant */
    /* @4980544 load */
    /* @4980552 cast */
    /* @4980556 load */
    /* @4980564 constant */
    /* @4980568 add */
    /* @4980572 constant */
    /* @4980576 load */
    /* @4980584 cast */
    /* @4980588 load */
    /* @4980596 constant */
    /* @4980600 add */
    /* @4980604 call */
    GM_SITE(vm, 649, 4980604);
    v133 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v134 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4980612 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v133, v134, STR_REF(1140)));
    /* @4980616 string */
    /* @4980624 cast */
    /* @4980628 constant */
    /* @4980632 load */
    /* @4980640 cast */
    /* @4980644 load */
    /* @4980652 constant */
    /* @4980656 add */
    /* @4980660 constant */
    /* @4980664 load */
    /* @4980672 cast */
    /* @4980676 load */
    /* @4980684 constant */
    /* @4980688 add */
    /* @4980692 call */
    GM_SITE(vm, 649, 4980692);
    v135 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v136 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4980700 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v135, v136, STR_REF(1141)));
    /* @4980704 constant */
    /* @4980708 load */
    /* @4980716 cast */
    /* @4980720 load */
    /* @4980728 constant */
    /* @4980732 add */
    /* @4980736 constant */
    /* @4980740 load */
    /* @4980748 cast */
    /* @4980752 load */
    /* @4980760 constant */
    /* @4980764 add */
    /* @4980768 constant */
    /* @4980772 cast */
    /* @4980776 constant */
    /* @4980780 cast */
    /* @4980784 call */
    GM_SITE(vm, 649, 4980784);
    v137 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v138 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    /* @4980792 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(157), VAL(0), v137, v138));
    L_4980796: ;
    /* @4980796 load */
    /* @4980804 constant */
    /* @4980808 cmp */
    /* @4980812 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4981128;
    /* @4980816 constant */
    /* @4980820 cast */
    /* @4980824 call */
    GM_SITE(vm, 649, 4980824);
    /* @4980832 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4980836 constant */
    /* @4980844 cast */
    /* @4980848 call */
    GM_SITE(vm, 649, 4980848);
    /* @4980856 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4980860 string */
    /* @4980868 cast */
    /* @4980872 constant */
    /* @4980876 load */
    /* @4980884 cast */
    /* @4980888 load */
    /* @4980896 constant */
    /* @4980900 add */
    /* @4980904 constant */
    /* @4980908 load */
    /* @4980916 cast */
    /* @4980920 load */
    /* @4980928 constant */
    /* @4980932 add */
    /* @4980936 call */
    GM_SITE(vm, 649, 4980936);
    v139 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v140 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4980944 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v139, v140, STR_REF(1140)));
    /* @4980948 string */
    /* @4980956 cast */
    /* @4980960 constant */
    /* @4980964 load */
    /* @4980972 cast */
    /* @4980976 load */
    /* @4980984 constant */
    /* @4980988 add */
    /* @4980992 constant */
    /* @4980996 load */
    /* @4981004 cast */
    /* @4981008 load */
    /* @4981016 constant */
    /* @4981020 add */
    /* @4981024 call */
    GM_SITE(vm, 649, 4981024);
    v141 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v142 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4981032 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v141, v142, STR_REF(1141)));
    /* @4981036 constant */
    /* @4981040 load */
    /* @4981048 cast */
    /* @4981052 load */
    /* @4981060 constant */
    /* @4981064 add */
    /* @4981068 constant */
    /* @4981072 load */
    /* @4981080 cast */
    /* @4981084 load */
    /* @4981092 constant */
    /* @4981096 add */
    /* @4981100 constant */
    /* @4981104 cast */
    /* @4981108 constant */
    /* @4981112 cast */
    /* @4981116 call */
    GM_SITE(vm, 649, 4981116);
    v143 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v144 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    /* @4981124 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(157), VAL(0), v143, v144));
    L_4981128: ;
    /* @4981128 load */
    /* @4981136 constant */
    /* @4981140 cmp */
    /* @4981144 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4981460;
    /* @4981148 constant */
    /* @4981152 cast */
    /* @4981156 call */
    GM_SITE(vm, 649, 4981156);
    /* @4981164 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4981168 constant */
    /* @4981176 cast */
    /* @4981180 call */
    GM_SITE(vm, 649, 4981180);
    /* @4981188 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4981192 string */
    /* @4981200 cast */
    /* @4981204 constant */
    /* @4981208 load */
    /* @4981216 cast */
    /* @4981220 load */
    /* @4981228 constant */
    /* @4981232 add */
    /* @4981236 constant */
    /* @4981240 load */
    /* @4981248 cast */
    /* @4981252 load */
    /* @4981260 constant */
    /* @4981264 add */
    /* @4981268 call */
    GM_SITE(vm, 649, 4981268);
    v145 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v146 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4981276 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v145, v146, STR_REF(1140)));
    /* @4981280 string */
    /* @4981288 cast */
    /* @4981292 constant */
    /* @4981296 load */
    /* @4981304 cast */
    /* @4981308 load */
    /* @4981316 constant */
    /* @4981320 add */
    /* @4981324 constant */
    /* @4981328 load */
    /* @4981336 cast */
    /* @4981340 load */
    /* @4981348 constant */
    /* @4981352 add */
    /* @4981356 call */
    GM_SITE(vm, 649, 4981356);
    v147 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v148 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4981364 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v147, v148, STR_REF(1141)));
    /* @4981368 constant */
    /* @4981372 load */
    /* @4981380 cast */
    /* @4981384 load */
    /* @4981392 constant */
    /* @4981396 add */
    /* @4981400 constant */
    /* @4981404 load */
    /* @4981412 cast */
    /* @4981416 load */
    /* @4981424 constant */
    /* @4981428 add */
    /* @4981432 constant */
    /* @4981436 cast */
    /* @4981440 constant */
    /* @4981444 cast */
    /* @4981448 call */
    GM_SITE(vm, 649, 4981448);
    v149 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v150 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(90));
    /* @4981456 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(157), VAL(0), v149, v150));
    L_4981460: ;
    /* @4981460 load */
    /* @4981468 constant */
    /* @4981472 cmp */
    /* @4981476 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4981792;
    /* @4981480 constant */
    /* @4981484 cast */
    /* @4981488 call */
    GM_SITE(vm, 649, 4981488);
    /* @4981496 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4981500 constant */
    /* @4981508 cast */
    /* @4981512 call */
    GM_SITE(vm, 649, 4981512);
    /* @4981520 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4981524 string */
    /* @4981532 cast */
    /* @4981536 constant */
    /* @4981540 load */
    /* @4981548 cast */
    /* @4981552 load */
    /* @4981560 constant */
    /* @4981564 add */
    /* @4981568 constant */
    /* @4981572 load */
    /* @4981580 cast */
    /* @4981584 load */
    /* @4981592 constant */
    /* @4981596 add */
    /* @4981600 call */
    GM_SITE(vm, 649, 4981600);
    v151 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v152 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4981608 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v151, v152, STR_REF(1140)));
    /* @4981612 string */
    /* @4981620 cast */
    /* @4981624 constant */
    /* @4981628 load */
    /* @4981636 cast */
    /* @4981640 load */
    /* @4981648 constant */
    /* @4981652 add */
    /* @4981656 constant */
    /* @4981660 load */
    /* @4981668 cast */
    /* @4981672 load */
    /* @4981680 constant */
    /* @4981684 add */
    /* @4981688 call */
    GM_SITE(vm, 649, 4981688);
    v153 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v154 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4981696 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v153, v154, STR_REF(1141)));
    /* @4981700 constant */
    /* @4981704 load */
    /* @4981712 cast */
    /* @4981716 load */
    /* @4981724 constant */
    /* @4981728 add */
    /* @4981732 constant */
    /* @4981736 load */
    /* @4981744 cast */
    /* @4981748 load */
    /* @4981756 constant */
    /* @4981760 add */
    /* @4981764 constant */
    /* @4981768 cast */
    /* @4981772 constant */
    /* @4981776 cast */
    /* @4981780 call */
    GM_SITE(vm, 649, 4981780);
    v155 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v156 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(90));
    /* @4981788 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(157), VAL(0), v155, v156));
    L_4981792: ;
    /* @4981792 load */
    /* @4981800 constant */
    /* @4981804 cmp */
    /* @4981808 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4981844;
    /* @4981812 constant */
    /* @4981816 cast */
    /* @4981820 constant */
    /* @4981824 cast */
    /* @4981828 call */
    GM_SITE(vm, 649, 4981828);
    /* @4981836 cast */
    /* @4981840 b */
    v157 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, VAL(0), VAL(1)));
    p4981848_0 = v157;
    goto L_4981848;
    L_4981844: ;
    /* @4981844 constant */
    p4981848_0 = VAL(0);
    L_4981848: ;
    /* @4981848 bf */
    if (!TRUTH(p4981848_0)) goto L_4981864;
    /* @4981852 call */
    GM_SITE(vm, 649, 4981852);
    /* @4981860 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4981864: ;
    return;
}
