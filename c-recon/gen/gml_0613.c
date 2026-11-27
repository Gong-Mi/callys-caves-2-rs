/* generated from CODE 613 (gml_Object_obj_lloydtutorial8_Draw_0), source start 4920760, end 4931460. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0613(GmVM* vm) {
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
    Val p4931444_0;
    Val v157;
    /* @4920760 constant */
    /* @4920764 load */
    /* @4920772 cast */
    /* @4920776 load */
    /* @4920784 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4920792 constant */
    /* @4920796 load */
    /* @4920804 cast */
    /* @4920808 load */
    /* @4920816 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4920824 load */
    /* @4920832 constant */
    /* @4920836 cmp */
    /* @4920840 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4921368;
    /* @4920844 constant */
    /* @4920848 cast */
    /* @4920852 constant */
    /* @4920856 cast */
    /* @4920860 constant */
    /* @4920864 cast */
    /* @4920868 constant */
    /* @4920880 cast */
    /* @4920884 constant */
    /* @4920896 cast */
    /* @4920900 constant */
    /* @4920904 constant */
    /* @4920908 load */
    /* @4920916 constant */
    /* @4920920 constant */
    /* @4920924 load */
    /* @4920932 constant */
    /* @4920936 sub */
    /* @4920940 constant */
    /* @4920944 cast */
    /* @4920948 constant */
    /* @4920952 cast */
    /* @4920956 call */
    GM_SITE(vm, 613, 4920956);
    /* @4920964 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(0.96), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4920968 constant */
    /* @4920972 cast */
    /* @4920976 constant */
    /* @4920980 cast */
    /* @4920984 constant */
    /* @4920988 cast */
    /* @4920992 constant */
    /* @4920996 cast */
    /* @4921000 constant */
    /* @4921004 cast */
    /* @4921008 constant */
    /* @4921012 load */
    /* @4921020 cast */
    /* @4921024 load */
    /* @4921032 constant */
    /* @4921036 add */
    /* @4921040 constant */
    /* @4921044 load */
    /* @4921052 cast */
    /* @4921056 load */
    /* @4921064 constant */
    /* @4921068 add */
    /* @4921072 constant */
    /* @4921076 cast */
    /* @4921080 constant */
    /* @4921084 cast */
    /* @4921088 call */
    GM_SITE(vm, 613, 4921088);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4921096 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v1, v2, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4921100 constant */
    /* @4921104 cast */
    /* @4921108 constant */
    /* @4921112 cast */
    /* @4921116 constant */
    /* @4921120 cast */
    /* @4921124 constant */
    /* @4921128 cast */
    /* @4921132 constant */
    /* @4921136 cast */
    /* @4921140 constant */
    /* @4921144 load */
    /* @4921152 cast */
    /* @4921156 load */
    /* @4921164 constant */
    /* @4921168 add */
    /* @4921172 constant */
    /* @4921176 load */
    /* @4921184 cast */
    /* @4921188 load */
    /* @4921196 constant */
    /* @4921200 add */
    /* @4921204 constant */
    /* @4921208 cast */
    /* @4921212 constant */
    /* @4921216 cast */
    /* @4921220 call */
    GM_SITE(vm, 613, 4921220);
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4921228 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v3, v4, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4921232 load */
    /* @4921240 constant */
    /* @4921244 cmp */
    /* @4921248 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4921368;
    /* @4921252 constant */
    /* @4921256 cast */
    /* @4921260 call */
    GM_SITE(vm, 613, 4921260);
    /* @4921268 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4921272 constant */
    /* @4921280 cast */
    /* @4921284 call */
    GM_SITE(vm, 613, 4921284);
    /* @4921292 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4921296 string */
    /* @4921304 cast */
    /* @4921308 constant */
    /* @4921312 constant */
    /* @4921316 load */
    /* @4921324 constant */
    /* @4921328 add */
    /* @4921332 constant */
    /* @4921336 constant */
    /* @4921340 load */
    /* @4921348 constant */
    /* @4921352 add */
    /* @4921356 call */
    GM_SITE(vm, 613, 4921356);
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(150));
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(200));
    /* @4921364 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v5, v6, STR_REF(743)));
    L_4921368: ;
    /* @4921368 load */
    /* @4921376 constant */
    /* @4921380 cmp */
    /* @4921384 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4921912;
    /* @4921388 constant */
    /* @4921392 cast */
    /* @4921396 constant */
    /* @4921400 cast */
    /* @4921404 constant */
    /* @4921408 cast */
    /* @4921412 constant */
    /* @4921424 cast */
    /* @4921428 constant */
    /* @4921440 cast */
    /* @4921444 constant */
    /* @4921448 constant */
    /* @4921452 load */
    /* @4921460 constant */
    /* @4921464 constant */
    /* @4921468 load */
    /* @4921476 constant */
    /* @4921480 sub */
    /* @4921484 constant */
    /* @4921488 cast */
    /* @4921492 constant */
    /* @4921496 cast */
    /* @4921500 call */
    GM_SITE(vm, 613, 4921500);
    /* @4921508 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(0.82), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4921512 constant */
    /* @4921516 cast */
    /* @4921520 constant */
    /* @4921524 cast */
    /* @4921528 constant */
    /* @4921532 cast */
    /* @4921536 constant */
    /* @4921540 cast */
    /* @4921544 constant */
    /* @4921548 cast */
    /* @4921552 constant */
    /* @4921556 load */
    /* @4921564 cast */
    /* @4921568 load */
    /* @4921576 constant */
    /* @4921580 add */
    /* @4921584 constant */
    /* @4921588 load */
    /* @4921596 cast */
    /* @4921600 load */
    /* @4921608 constant */
    /* @4921612 add */
    /* @4921616 constant */
    /* @4921620 cast */
    /* @4921624 constant */
    /* @4921628 cast */
    /* @4921632 call */
    GM_SITE(vm, 613, 4921632);
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4921640 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v7, v8, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4921644 constant */
    /* @4921648 cast */
    /* @4921652 constant */
    /* @4921656 cast */
    /* @4921660 constant */
    /* @4921664 cast */
    /* @4921668 constant */
    /* @4921672 cast */
    /* @4921676 constant */
    /* @4921680 cast */
    /* @4921684 constant */
    /* @4921688 load */
    /* @4921696 cast */
    /* @4921700 load */
    /* @4921708 constant */
    /* @4921712 add */
    /* @4921716 constant */
    /* @4921720 load */
    /* @4921728 cast */
    /* @4921732 load */
    /* @4921740 constant */
    /* @4921744 add */
    /* @4921748 constant */
    /* @4921752 cast */
    /* @4921756 constant */
    /* @4921760 cast */
    /* @4921764 call */
    GM_SITE(vm, 613, 4921764);
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(320));
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4921772 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v9, v10, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4921776 load */
    /* @4921784 constant */
    /* @4921788 cmp */
    /* @4921792 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4921912;
    /* @4921796 constant */
    /* @4921800 cast */
    /* @4921804 call */
    GM_SITE(vm, 613, 4921804);
    /* @4921812 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4921816 constant */
    /* @4921824 cast */
    /* @4921828 call */
    GM_SITE(vm, 613, 4921828);
    /* @4921836 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4921840 string */
    /* @4921848 cast */
    /* @4921852 constant */
    /* @4921856 constant */
    /* @4921860 load */
    /* @4921868 constant */
    /* @4921872 add */
    /* @4921876 constant */
    /* @4921880 constant */
    /* @4921884 load */
    /* @4921892 constant */
    /* @4921896 add */
    /* @4921900 call */
    GM_SITE(vm, 613, 4921900);
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(110));
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4921908 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v11, v12, STR_REF(743)));
    L_4921912: ;
    /* @4921912 load */
    /* @4921920 constant */
    /* @4921924 cmp */
    /* @4921928 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4922456;
    /* @4921932 constant */
    /* @4921936 cast */
    /* @4921940 constant */
    /* @4921944 cast */
    /* @4921948 constant */
    /* @4921952 cast */
    /* @4921956 constant */
    /* @4921968 cast */
    /* @4921972 constant */
    /* @4921984 cast */
    /* @4921988 constant */
    /* @4921992 constant */
    /* @4921996 load */
    /* @4922004 constant */
    /* @4922008 constant */
    /* @4922012 load */
    /* @4922020 constant */
    /* @4922024 sub */
    /* @4922028 constant */
    /* @4922032 cast */
    /* @4922036 constant */
    /* @4922040 cast */
    /* @4922044 call */
    GM_SITE(vm, 613, 4922044);
    /* @4922052 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4922056 constant */
    /* @4922060 cast */
    /* @4922064 constant */
    /* @4922068 cast */
    /* @4922072 constant */
    /* @4922076 cast */
    /* @4922080 constant */
    /* @4922084 cast */
    /* @4922088 constant */
    /* @4922092 cast */
    /* @4922096 constant */
    /* @4922100 load */
    /* @4922108 cast */
    /* @4922112 load */
    /* @4922120 constant */
    /* @4922124 add */
    /* @4922128 constant */
    /* @4922132 load */
    /* @4922140 cast */
    /* @4922144 load */
    /* @4922152 constant */
    /* @4922156 add */
    /* @4922160 constant */
    /* @4922164 cast */
    /* @4922168 constant */
    /* @4922172 cast */
    /* @4922176 call */
    GM_SITE(vm, 613, 4922176);
    v13 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4922184 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v13, v14, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4922188 constant */
    /* @4922192 cast */
    /* @4922196 constant */
    /* @4922200 cast */
    /* @4922204 constant */
    /* @4922208 cast */
    /* @4922212 constant */
    /* @4922216 cast */
    /* @4922220 constant */
    /* @4922224 cast */
    /* @4922228 constant */
    /* @4922232 load */
    /* @4922240 cast */
    /* @4922244 load */
    /* @4922252 constant */
    /* @4922256 add */
    /* @4922260 constant */
    /* @4922264 load */
    /* @4922272 cast */
    /* @4922276 load */
    /* @4922284 constant */
    /* @4922288 add */
    /* @4922292 constant */
    /* @4922296 cast */
    /* @4922300 constant */
    /* @4922304 cast */
    /* @4922308 call */
    GM_SITE(vm, 613, 4922308);
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4922316 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v15, v16, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4922320 load */
    /* @4922328 constant */
    /* @4922332 cmp */
    /* @4922336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4922456;
    /* @4922340 constant */
    /* @4922344 cast */
    /* @4922348 call */
    GM_SITE(vm, 613, 4922348);
    /* @4922356 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4922360 constant */
    /* @4922368 cast */
    /* @4922372 call */
    GM_SITE(vm, 613, 4922372);
    /* @4922380 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4922384 string */
    /* @4922392 cast */
    /* @4922396 constant */
    /* @4922400 constant */
    /* @4922404 load */
    /* @4922412 constant */
    /* @4922416 add */
    /* @4922420 constant */
    /* @4922424 constant */
    /* @4922428 load */
    /* @4922436 constant */
    /* @4922440 add */
    /* @4922444 call */
    GM_SITE(vm, 613, 4922444);
    v17 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(180));
    v18 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(300));
    /* @4922452 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v17, v18, STR_REF(743)));
    L_4922456: ;
    /* @4922456 load */
    /* @4922464 constant */
    /* @4922468 cmp */
    /* @4922472 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4923000;
    /* @4922476 constant */
    /* @4922480 cast */
    /* @4922484 constant */
    /* @4922488 cast */
    /* @4922492 constant */
    /* @4922496 cast */
    /* @4922500 constant */
    /* @4922512 cast */
    /* @4922516 constant */
    /* @4922528 cast */
    /* @4922532 constant */
    /* @4922536 constant */
    /* @4922540 load */
    /* @4922548 constant */
    /* @4922552 constant */
    /* @4922556 load */
    /* @4922564 constant */
    /* @4922568 sub */
    /* @4922572 constant */
    /* @4922576 cast */
    /* @4922580 constant */
    /* @4922584 cast */
    /* @4922588 call */
    GM_SITE(vm, 613, 4922588);
    /* @4922596 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4922600 constant */
    /* @4922604 cast */
    /* @4922608 constant */
    /* @4922612 cast */
    /* @4922616 constant */
    /* @4922620 cast */
    /* @4922624 constant */
    /* @4922628 cast */
    /* @4922632 constant */
    /* @4922636 cast */
    /* @4922640 constant */
    /* @4922644 load */
    /* @4922652 cast */
    /* @4922656 load */
    /* @4922664 constant */
    /* @4922668 add */
    /* @4922672 constant */
    /* @4922676 load */
    /* @4922684 cast */
    /* @4922688 load */
    /* @4922696 constant */
    /* @4922700 add */
    /* @4922704 constant */
    /* @4922708 cast */
    /* @4922712 constant */
    /* @4922716 cast */
    /* @4922720 call */
    GM_SITE(vm, 613, 4922720);
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4922728 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v19, v20, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4922732 constant */
    /* @4922736 cast */
    /* @4922740 constant */
    /* @4922744 cast */
    /* @4922748 constant */
    /* @4922752 cast */
    /* @4922756 constant */
    /* @4922760 cast */
    /* @4922764 constant */
    /* @4922768 cast */
    /* @4922772 constant */
    /* @4922776 load */
    /* @4922784 cast */
    /* @4922788 load */
    /* @4922796 constant */
    /* @4922800 add */
    /* @4922804 constant */
    /* @4922808 load */
    /* @4922816 cast */
    /* @4922820 load */
    /* @4922828 constant */
    /* @4922832 add */
    /* @4922836 constant */
    /* @4922840 cast */
    /* @4922844 constant */
    /* @4922848 cast */
    /* @4922852 call */
    GM_SITE(vm, 613, 4922852);
    v21 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4922860 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v21, v22, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4922864 load */
    /* @4922872 constant */
    /* @4922876 cmp */
    /* @4922880 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4923000;
    /* @4922884 constant */
    /* @4922888 cast */
    /* @4922892 call */
    GM_SITE(vm, 613, 4922892);
    /* @4922900 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4922904 constant */
    /* @4922912 cast */
    /* @4922916 call */
    GM_SITE(vm, 613, 4922916);
    /* @4922924 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4922928 string */
    /* @4922936 cast */
    /* @4922940 constant */
    /* @4922944 constant */
    /* @4922948 load */
    /* @4922956 constant */
    /* @4922960 add */
    /* @4922964 constant */
    /* @4922968 constant */
    /* @4922972 load */
    /* @4922980 constant */
    /* @4922984 add */
    /* @4922988 call */
    GM_SITE(vm, 613, 4922988);
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(180));
    v24 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(300));
    /* @4922996 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v23, v24, STR_REF(743)));
    L_4923000: ;
    /* @4923000 load */
    /* @4923008 constant */
    /* @4923012 cmp */
    /* @4923016 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4923544;
    /* @4923020 constant */
    /* @4923024 cast */
    /* @4923028 constant */
    /* @4923032 cast */
    /* @4923036 constant */
    /* @4923040 cast */
    /* @4923044 constant */
    /* @4923056 cast */
    /* @4923060 constant */
    /* @4923072 cast */
    /* @4923076 constant */
    /* @4923080 constant */
    /* @4923084 load */
    /* @4923092 constant */
    /* @4923096 constant */
    /* @4923100 load */
    /* @4923108 constant */
    /* @4923112 sub */
    /* @4923116 constant */
    /* @4923120 cast */
    /* @4923124 constant */
    /* @4923128 cast */
    /* @4923132 call */
    GM_SITE(vm, 613, 4923132);
    /* @4923140 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(0.97), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4923144 constant */
    /* @4923148 cast */
    /* @4923152 constant */
    /* @4923156 cast */
    /* @4923160 constant */
    /* @4923164 cast */
    /* @4923168 constant */
    /* @4923172 cast */
    /* @4923176 constant */
    /* @4923180 cast */
    /* @4923184 constant */
    /* @4923188 load */
    /* @4923196 cast */
    /* @4923200 load */
    /* @4923208 constant */
    /* @4923212 add */
    /* @4923216 constant */
    /* @4923220 load */
    /* @4923228 cast */
    /* @4923232 load */
    /* @4923240 constant */
    /* @4923244 add */
    /* @4923248 constant */
    /* @4923252 cast */
    /* @4923256 constant */
    /* @4923260 cast */
    /* @4923264 call */
    GM_SITE(vm, 613, 4923264);
    v25 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v26 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4923272 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v25, v26, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4923276 constant */
    /* @4923280 cast */
    /* @4923284 constant */
    /* @4923288 cast */
    /* @4923292 constant */
    /* @4923296 cast */
    /* @4923300 constant */
    /* @4923304 cast */
    /* @4923308 constant */
    /* @4923312 cast */
    /* @4923316 constant */
    /* @4923320 load */
    /* @4923328 cast */
    /* @4923332 load */
    /* @4923340 constant */
    /* @4923344 add */
    /* @4923348 constant */
    /* @4923352 load */
    /* @4923360 cast */
    /* @4923364 load */
    /* @4923372 constant */
    /* @4923376 add */
    /* @4923380 constant */
    /* @4923384 cast */
    /* @4923388 constant */
    /* @4923392 cast */
    /* @4923396 call */
    GM_SITE(vm, 613, 4923396);
    v27 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v28 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4923404 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v27, v28, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4923408 load */
    /* @4923416 constant */
    /* @4923420 cmp */
    /* @4923424 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4923544;
    /* @4923428 constant */
    /* @4923432 cast */
    /* @4923436 call */
    GM_SITE(vm, 613, 4923436);
    /* @4923444 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4923448 constant */
    /* @4923456 cast */
    /* @4923460 call */
    GM_SITE(vm, 613, 4923460);
    /* @4923468 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4923472 string */
    /* @4923480 cast */
    /* @4923484 constant */
    /* @4923488 constant */
    /* @4923492 load */
    /* @4923500 constant */
    /* @4923504 add */
    /* @4923508 constant */
    /* @4923512 constant */
    /* @4923516 load */
    /* @4923524 constant */
    /* @4923528 add */
    /* @4923532 call */
    GM_SITE(vm, 613, 4923532);
    v29 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(150));
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(200));
    /* @4923540 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v29, v30, STR_REF(743)));
    L_4923544: ;
    /* @4923544 load */
    /* @4923552 constant */
    /* @4923556 cmp */
    /* @4923560 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4924088;
    /* @4923564 constant */
    /* @4923568 cast */
    /* @4923572 constant */
    /* @4923576 cast */
    /* @4923580 constant */
    /* @4923584 cast */
    /* @4923588 constant */
    /* @4923600 cast */
    /* @4923604 constant */
    /* @4923616 cast */
    /* @4923620 constant */
    /* @4923624 constant */
    /* @4923628 load */
    /* @4923636 constant */
    /* @4923640 constant */
    /* @4923644 load */
    /* @4923652 constant */
    /* @4923656 sub */
    /* @4923660 constant */
    /* @4923664 cast */
    /* @4923668 constant */
    /* @4923672 cast */
    /* @4923676 call */
    GM_SITE(vm, 613, 4923676);
    /* @4923684 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(1.06), VAL(0.86), VAL(0), VAL(-1), VAL(1)));
    /* @4923688 constant */
    /* @4923692 cast */
    /* @4923696 constant */
    /* @4923700 cast */
    /* @4923704 constant */
    /* @4923708 cast */
    /* @4923712 constant */
    /* @4923716 cast */
    /* @4923720 constant */
    /* @4923724 cast */
    /* @4923728 constant */
    /* @4923732 load */
    /* @4923740 cast */
    /* @4923744 load */
    /* @4923752 constant */
    /* @4923756 add */
    /* @4923760 constant */
    /* @4923764 load */
    /* @4923772 cast */
    /* @4923776 load */
    /* @4923784 constant */
    /* @4923788 add */
    /* @4923792 constant */
    /* @4923796 cast */
    /* @4923800 constant */
    /* @4923804 cast */
    /* @4923808 call */
    GM_SITE(vm, 613, 4923808);
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v32 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4923816 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v31, v32, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4923820 constant */
    /* @4923824 cast */
    /* @4923828 constant */
    /* @4923832 cast */
    /* @4923836 constant */
    /* @4923840 cast */
    /* @4923844 constant */
    /* @4923848 cast */
    /* @4923852 constant */
    /* @4923856 cast */
    /* @4923860 constant */
    /* @4923864 load */
    /* @4923872 cast */
    /* @4923876 load */
    /* @4923884 constant */
    /* @4923888 add */
    /* @4923892 constant */
    /* @4923896 load */
    /* @4923904 cast */
    /* @4923908 load */
    /* @4923916 constant */
    /* @4923920 add */
    /* @4923924 constant */
    /* @4923928 cast */
    /* @4923932 constant */
    /* @4923936 cast */
    /* @4923940 call */
    GM_SITE(vm, 613, 4923940);
    v33 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(390));
    v34 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4923948 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v33, v34, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4923952 load */
    /* @4923960 constant */
    /* @4923964 cmp */
    /* @4923968 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4924088;
    /* @4923972 constant */
    /* @4923976 cast */
    /* @4923980 call */
    GM_SITE(vm, 613, 4923980);
    /* @4923988 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4923992 constant */
    /* @4924000 cast */
    /* @4924004 call */
    GM_SITE(vm, 613, 4924004);
    /* @4924012 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4924016 string */
    /* @4924024 cast */
    /* @4924028 constant */
    /* @4924032 constant */
    /* @4924036 load */
    /* @4924044 constant */
    /* @4924048 add */
    /* @4924052 constant */
    /* @4924056 constant */
    /* @4924060 load */
    /* @4924068 constant */
    /* @4924072 add */
    /* @4924076 call */
    GM_SITE(vm, 613, 4924076);
    v35 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(160));
    v36 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(200));
    /* @4924084 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v35, v36, STR_REF(743)));
    L_4924088: ;
    /* @4924088 load */
    /* @4924096 constant */
    /* @4924100 cmp */
    /* @4924104 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel1") == VAL(1)))) goto L_4925548;
    /* @4924108 load */
    /* @4924116 constant */
    /* @4924120 cmp */
    /* @4924124 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4924348;
    /* @4924128 constant */
    /* @4924132 cast */
    /* @4924136 call */
    GM_SITE(vm, 613, 4924136);
    /* @4924144 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4924148 constant */
    /* @4924156 cast */
    /* @4924160 call */
    GM_SITE(vm, 613, 4924160);
    /* @4924168 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4924172 string */
    /* @4924180 cast */
    /* @4924184 constant */
    /* @4924188 load */
    /* @4924196 cast */
    /* @4924200 load */
    /* @4924208 constant */
    /* @4924212 add */
    /* @4924216 constant */
    /* @4924220 load */
    /* @4924228 cast */
    /* @4924232 load */
    /* @4924240 constant */
    /* @4924244 add */
    /* @4924248 call */
    GM_SITE(vm, 613, 4924248);
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4924256 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v37, v38, STR_REF(1092)));
    /* @4924260 string */
    /* @4924268 cast */
    /* @4924272 constant */
    /* @4924276 load */
    /* @4924284 cast */
    /* @4924288 load */
    /* @4924296 constant */
    /* @4924300 add */
    /* @4924304 constant */
    /* @4924308 load */
    /* @4924316 cast */
    /* @4924320 load */
    /* @4924328 constant */
    /* @4924332 add */
    /* @4924336 call */
    GM_SITE(vm, 613, 4924336);
    v39 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v40 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4924344 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, v40, STR_REF(1093)));
    L_4924348: ;
    /* @4924348 load */
    /* @4924356 constant */
    /* @4924360 cmp */
    /* @4924364 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4924588;
    /* @4924368 constant */
    /* @4924372 cast */
    /* @4924376 call */
    GM_SITE(vm, 613, 4924376);
    /* @4924384 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4924388 constant */
    /* @4924396 cast */
    /* @4924400 call */
    GM_SITE(vm, 613, 4924400);
    /* @4924408 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4924412 string */
    /* @4924420 cast */
    /* @4924424 constant */
    /* @4924428 load */
    /* @4924436 cast */
    /* @4924440 load */
    /* @4924448 constant */
    /* @4924452 add */
    /* @4924456 constant */
    /* @4924460 load */
    /* @4924468 cast */
    /* @4924472 load */
    /* @4924480 constant */
    /* @4924484 add */
    /* @4924488 call */
    GM_SITE(vm, 613, 4924488);
    v41 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v42 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4924496 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v41, v42, STR_REF(1092)));
    /* @4924500 string */
    /* @4924508 cast */
    /* @4924512 constant */
    /* @4924516 load */
    /* @4924524 cast */
    /* @4924528 load */
    /* @4924536 constant */
    /* @4924540 add */
    /* @4924544 constant */
    /* @4924548 load */
    /* @4924556 cast */
    /* @4924560 load */
    /* @4924568 constant */
    /* @4924572 add */
    /* @4924576 call */
    GM_SITE(vm, 613, 4924576);
    v43 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v44 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4924584 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v43, v44, STR_REF(1093)));
    L_4924588: ;
    /* @4924588 load */
    /* @4924596 constant */
    /* @4924600 cmp */
    /* @4924604 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4924828;
    /* @4924608 constant */
    /* @4924612 cast */
    /* @4924616 call */
    GM_SITE(vm, 613, 4924616);
    /* @4924624 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4924628 constant */
    /* @4924636 cast */
    /* @4924640 call */
    GM_SITE(vm, 613, 4924640);
    /* @4924648 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4924652 string */
    /* @4924660 cast */
    /* @4924664 constant */
    /* @4924668 load */
    /* @4924676 cast */
    /* @4924680 load */
    /* @4924688 constant */
    /* @4924692 add */
    /* @4924696 constant */
    /* @4924700 load */
    /* @4924708 cast */
    /* @4924712 load */
    /* @4924720 constant */
    /* @4924724 add */
    /* @4924728 call */
    GM_SITE(vm, 613, 4924728);
    v45 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v46 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4924736 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v45, v46, STR_REF(1092)));
    /* @4924740 string */
    /* @4924748 cast */
    /* @4924752 constant */
    /* @4924756 load */
    /* @4924764 cast */
    /* @4924768 load */
    /* @4924776 constant */
    /* @4924780 add */
    /* @4924784 constant */
    /* @4924788 load */
    /* @4924796 cast */
    /* @4924800 load */
    /* @4924808 constant */
    /* @4924812 add */
    /* @4924816 call */
    GM_SITE(vm, 613, 4924816);
    v47 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v48 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4924824 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v47, v48, STR_REF(1093)));
    L_4924828: ;
    /* @4924828 load */
    /* @4924836 constant */
    /* @4924840 cmp */
    /* @4924844 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4925068;
    /* @4924848 constant */
    /* @4924852 cast */
    /* @4924856 call */
    GM_SITE(vm, 613, 4924856);
    /* @4924864 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4924868 constant */
    /* @4924876 cast */
    /* @4924880 call */
    GM_SITE(vm, 613, 4924880);
    /* @4924888 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4924892 string */
    /* @4924900 cast */
    /* @4924904 constant */
    /* @4924908 load */
    /* @4924916 cast */
    /* @4924920 load */
    /* @4924928 constant */
    /* @4924932 add */
    /* @4924936 constant */
    /* @4924940 load */
    /* @4924948 cast */
    /* @4924952 load */
    /* @4924960 constant */
    /* @4924964 add */
    /* @4924968 call */
    GM_SITE(vm, 613, 4924968);
    v49 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v50 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4924976 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v49, v50, STR_REF(1092)));
    /* @4924980 string */
    /* @4924988 cast */
    /* @4924992 constant */
    /* @4924996 load */
    /* @4925004 cast */
    /* @4925008 load */
    /* @4925016 constant */
    /* @4925020 add */
    /* @4925024 constant */
    /* @4925028 load */
    /* @4925036 cast */
    /* @4925040 load */
    /* @4925048 constant */
    /* @4925052 add */
    /* @4925056 call */
    GM_SITE(vm, 613, 4925056);
    v51 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v52 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4925064 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v51, v52, STR_REF(1093)));
    L_4925068: ;
    /* @4925068 load */
    /* @4925076 constant */
    /* @4925080 cmp */
    /* @4925084 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4925308;
    /* @4925088 constant */
    /* @4925092 cast */
    /* @4925096 call */
    GM_SITE(vm, 613, 4925096);
    /* @4925104 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4925108 constant */
    /* @4925116 cast */
    /* @4925120 call */
    GM_SITE(vm, 613, 4925120);
    /* @4925128 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4925132 string */
    /* @4925140 cast */
    /* @4925144 constant */
    /* @4925148 load */
    /* @4925156 cast */
    /* @4925160 load */
    /* @4925168 constant */
    /* @4925172 add */
    /* @4925176 constant */
    /* @4925180 load */
    /* @4925188 cast */
    /* @4925192 load */
    /* @4925200 constant */
    /* @4925204 add */
    /* @4925208 call */
    GM_SITE(vm, 613, 4925208);
    v53 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v54 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4925216 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v53, v54, STR_REF(1092)));
    /* @4925220 string */
    /* @4925228 cast */
    /* @4925232 constant */
    /* @4925236 load */
    /* @4925244 cast */
    /* @4925248 load */
    /* @4925256 constant */
    /* @4925260 add */
    /* @4925264 constant */
    /* @4925268 load */
    /* @4925276 cast */
    /* @4925280 load */
    /* @4925288 constant */
    /* @4925292 add */
    /* @4925296 call */
    GM_SITE(vm, 613, 4925296);
    v55 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v56 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4925304 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v55, v56, STR_REF(1093)));
    L_4925308: ;
    /* @4925308 load */
    /* @4925316 constant */
    /* @4925320 cmp */
    /* @4925324 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4925548;
    /* @4925328 constant */
    /* @4925332 cast */
    /* @4925336 call */
    GM_SITE(vm, 613, 4925336);
    /* @4925344 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4925348 constant */
    /* @4925356 cast */
    /* @4925360 call */
    GM_SITE(vm, 613, 4925360);
    /* @4925368 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4925372 string */
    /* @4925380 cast */
    /* @4925384 constant */
    /* @4925388 load */
    /* @4925396 cast */
    /* @4925400 load */
    /* @4925408 constant */
    /* @4925412 add */
    /* @4925416 constant */
    /* @4925420 load */
    /* @4925428 cast */
    /* @4925432 load */
    /* @4925440 constant */
    /* @4925444 add */
    /* @4925448 call */
    GM_SITE(vm, 613, 4925448);
    v57 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v58 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4925456 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v57, v58, STR_REF(1092)));
    /* @4925460 string */
    /* @4925468 cast */
    /* @4925472 constant */
    /* @4925476 load */
    /* @4925484 cast */
    /* @4925488 load */
    /* @4925496 constant */
    /* @4925500 add */
    /* @4925504 constant */
    /* @4925508 load */
    /* @4925516 cast */
    /* @4925520 load */
    /* @4925528 constant */
    /* @4925532 add */
    /* @4925536 call */
    GM_SITE(vm, 613, 4925536);
    v59 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v60 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4925544 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v59, v60, STR_REF(1093)));
    L_4925548: ;
    /* @4925548 load */
    /* @4925556 constant */
    /* @4925560 cmp */
    /* @4925564 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel2") == VAL(1)))) goto L_4927008;
    /* @4925568 load */
    /* @4925576 constant */
    /* @4925580 cmp */
    /* @4925584 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4925808;
    /* @4925588 constant */
    /* @4925592 cast */
    /* @4925596 call */
    GM_SITE(vm, 613, 4925596);
    /* @4925604 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4925608 constant */
    /* @4925616 cast */
    /* @4925620 call */
    GM_SITE(vm, 613, 4925620);
    /* @4925628 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4925632 string */
    /* @4925640 cast */
    /* @4925644 constant */
    /* @4925648 load */
    /* @4925656 cast */
    /* @4925660 load */
    /* @4925668 constant */
    /* @4925672 add */
    /* @4925676 constant */
    /* @4925680 load */
    /* @4925688 cast */
    /* @4925692 load */
    /* @4925700 constant */
    /* @4925704 add */
    /* @4925708 call */
    GM_SITE(vm, 613, 4925708);
    v61 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    v62 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4925716 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v61, v62, STR_REF(1094)));
    /* @4925720 string */
    /* @4925728 cast */
    /* @4925732 constant */
    /* @4925736 load */
    /* @4925744 cast */
    /* @4925748 load */
    /* @4925756 constant */
    /* @4925760 add */
    /* @4925764 constant */
    /* @4925768 load */
    /* @4925776 cast */
    /* @4925780 load */
    /* @4925788 constant */
    /* @4925792 add */
    /* @4925796 call */
    GM_SITE(vm, 613, 4925796);
    v63 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v64 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4925804 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v63, v64, STR_REF(1095)));
    L_4925808: ;
    /* @4925808 load */
    /* @4925816 constant */
    /* @4925820 cmp */
    /* @4925824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4926048;
    /* @4925828 constant */
    /* @4925832 cast */
    /* @4925836 call */
    GM_SITE(vm, 613, 4925836);
    /* @4925844 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4925848 constant */
    /* @4925856 cast */
    /* @4925860 call */
    GM_SITE(vm, 613, 4925860);
    /* @4925868 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4925872 string */
    /* @4925880 cast */
    /* @4925884 constant */
    /* @4925888 load */
    /* @4925896 cast */
    /* @4925900 load */
    /* @4925908 constant */
    /* @4925912 add */
    /* @4925916 constant */
    /* @4925920 load */
    /* @4925928 cast */
    /* @4925932 load */
    /* @4925940 constant */
    /* @4925944 add */
    /* @4925948 call */
    GM_SITE(vm, 613, 4925948);
    v65 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(160));
    v66 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    /* @4925956 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v65, v66, STR_REF(1094)));
    /* @4925960 string */
    /* @4925968 cast */
    /* @4925972 constant */
    /* @4925976 load */
    /* @4925984 cast */
    /* @4925988 load */
    /* @4925996 constant */
    /* @4926000 add */
    /* @4926004 constant */
    /* @4926008 load */
    /* @4926016 cast */
    /* @4926020 load */
    /* @4926028 constant */
    /* @4926032 add */
    /* @4926036 call */
    GM_SITE(vm, 613, 4926036);
    v67 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    v68 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(140));
    /* @4926044 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v67, v68, STR_REF(1095)));
    L_4926048: ;
    /* @4926048 load */
    /* @4926056 constant */
    /* @4926060 cmp */
    /* @4926064 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4926288;
    /* @4926068 constant */
    /* @4926072 cast */
    /* @4926076 call */
    GM_SITE(vm, 613, 4926076);
    /* @4926084 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4926088 constant */
    /* @4926096 cast */
    /* @4926100 call */
    GM_SITE(vm, 613, 4926100);
    /* @4926108 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4926112 string */
    /* @4926120 cast */
    /* @4926124 constant */
    /* @4926128 load */
    /* @4926136 cast */
    /* @4926140 load */
    /* @4926148 constant */
    /* @4926152 add */
    /* @4926156 constant */
    /* @4926160 load */
    /* @4926168 cast */
    /* @4926172 load */
    /* @4926180 constant */
    /* @4926184 add */
    /* @4926188 call */
    GM_SITE(vm, 613, 4926188);
    v69 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v70 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4926196 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v69, v70, STR_REF(1094)));
    /* @4926200 string */
    /* @4926208 cast */
    /* @4926212 constant */
    /* @4926216 load */
    /* @4926224 cast */
    /* @4926228 load */
    /* @4926236 constant */
    /* @4926240 add */
    /* @4926244 constant */
    /* @4926248 load */
    /* @4926256 cast */
    /* @4926260 load */
    /* @4926268 constant */
    /* @4926272 add */
    /* @4926276 call */
    GM_SITE(vm, 613, 4926276);
    v71 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v72 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4926284 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v71, v72, STR_REF(1095)));
    L_4926288: ;
    /* @4926288 load */
    /* @4926296 constant */
    /* @4926300 cmp */
    /* @4926304 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4926528;
    /* @4926308 constant */
    /* @4926312 cast */
    /* @4926316 call */
    GM_SITE(vm, 613, 4926316);
    /* @4926324 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4926328 constant */
    /* @4926336 cast */
    /* @4926340 call */
    GM_SITE(vm, 613, 4926340);
    /* @4926348 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4926352 string */
    /* @4926360 cast */
    /* @4926364 constant */
    /* @4926368 load */
    /* @4926376 cast */
    /* @4926380 load */
    /* @4926388 constant */
    /* @4926392 add */
    /* @4926396 constant */
    /* @4926400 load */
    /* @4926408 cast */
    /* @4926412 load */
    /* @4926420 constant */
    /* @4926424 add */
    /* @4926428 call */
    GM_SITE(vm, 613, 4926428);
    v73 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v74 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4926436 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v73, v74, STR_REF(1094)));
    /* @4926440 string */
    /* @4926448 cast */
    /* @4926452 constant */
    /* @4926456 load */
    /* @4926464 cast */
    /* @4926468 load */
    /* @4926476 constant */
    /* @4926480 add */
    /* @4926484 constant */
    /* @4926488 load */
    /* @4926496 cast */
    /* @4926500 load */
    /* @4926508 constant */
    /* @4926512 add */
    /* @4926516 call */
    GM_SITE(vm, 613, 4926516);
    v75 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v76 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4926524 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v75, v76, STR_REF(1095)));
    L_4926528: ;
    /* @4926528 load */
    /* @4926536 constant */
    /* @4926540 cmp */
    /* @4926544 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4926768;
    /* @4926548 constant */
    /* @4926552 cast */
    /* @4926556 call */
    GM_SITE(vm, 613, 4926556);
    /* @4926564 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4926568 constant */
    /* @4926576 cast */
    /* @4926580 call */
    GM_SITE(vm, 613, 4926580);
    /* @4926588 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4926592 string */
    /* @4926600 cast */
    /* @4926604 constant */
    /* @4926608 load */
    /* @4926616 cast */
    /* @4926620 load */
    /* @4926628 constant */
    /* @4926632 add */
    /* @4926636 constant */
    /* @4926640 load */
    /* @4926648 cast */
    /* @4926652 load */
    /* @4926660 constant */
    /* @4926664 add */
    /* @4926668 call */
    GM_SITE(vm, 613, 4926668);
    v77 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    v78 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4926676 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v77, v78, STR_REF(1094)));
    /* @4926680 string */
    /* @4926688 cast */
    /* @4926692 constant */
    /* @4926696 load */
    /* @4926704 cast */
    /* @4926708 load */
    /* @4926716 constant */
    /* @4926720 add */
    /* @4926724 constant */
    /* @4926728 load */
    /* @4926736 cast */
    /* @4926740 load */
    /* @4926748 constant */
    /* @4926752 add */
    /* @4926756 call */
    GM_SITE(vm, 613, 4926756);
    v79 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v80 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4926764 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v79, v80, STR_REF(1095)));
    L_4926768: ;
    /* @4926768 load */
    /* @4926776 constant */
    /* @4926780 cmp */
    /* @4926784 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4927008;
    /* @4926788 constant */
    /* @4926792 cast */
    /* @4926796 call */
    GM_SITE(vm, 613, 4926796);
    /* @4926804 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4926808 constant */
    /* @4926816 cast */
    /* @4926820 call */
    GM_SITE(vm, 613, 4926820);
    /* @4926828 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4926832 string */
    /* @4926840 cast */
    /* @4926844 constant */
    /* @4926848 load */
    /* @4926856 cast */
    /* @4926860 load */
    /* @4926868 constant */
    /* @4926872 add */
    /* @4926876 constant */
    /* @4926880 load */
    /* @4926888 cast */
    /* @4926892 load */
    /* @4926900 constant */
    /* @4926904 add */
    /* @4926908 call */
    GM_SITE(vm, 613, 4926908);
    v81 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    v82 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4926916 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v81, v82, STR_REF(1094)));
    /* @4926920 string */
    /* @4926928 cast */
    /* @4926932 constant */
    /* @4926936 load */
    /* @4926944 cast */
    /* @4926948 load */
    /* @4926956 constant */
    /* @4926960 add */
    /* @4926964 constant */
    /* @4926968 load */
    /* @4926976 cast */
    /* @4926980 load */
    /* @4926988 constant */
    /* @4926992 add */
    /* @4926996 call */
    GM_SITE(vm, 613, 4926996);
    v83 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v84 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4927004 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v83, v84, STR_REF(1095)));
    L_4927008: ;
    /* @4927008 load */
    /* @4927016 constant */
    /* @4927020 cmp */
    /* @4927024 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel3") == VAL(1)))) goto L_4928468;
    /* @4927028 load */
    /* @4927036 constant */
    /* @4927040 cmp */
    /* @4927044 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4927268;
    /* @4927048 constant */
    /* @4927052 cast */
    /* @4927056 call */
    GM_SITE(vm, 613, 4927056);
    /* @4927064 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4927068 constant */
    /* @4927076 cast */
    /* @4927080 call */
    GM_SITE(vm, 613, 4927080);
    /* @4927088 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4927092 string */
    /* @4927100 cast */
    /* @4927104 constant */
    /* @4927108 load */
    /* @4927116 cast */
    /* @4927120 load */
    /* @4927128 constant */
    /* @4927132 add */
    /* @4927136 constant */
    /* @4927140 load */
    /* @4927148 cast */
    /* @4927152 load */
    /* @4927160 constant */
    /* @4927164 add */
    /* @4927168 call */
    GM_SITE(vm, 613, 4927168);
    v85 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v86 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4927176 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v85, v86, STR_REF(1096)));
    /* @4927180 string */
    /* @4927188 cast */
    /* @4927192 constant */
    /* @4927196 load */
    /* @4927204 cast */
    /* @4927208 load */
    /* @4927216 constant */
    /* @4927220 add */
    /* @4927224 constant */
    /* @4927228 load */
    /* @4927236 cast */
    /* @4927240 load */
    /* @4927248 constant */
    /* @4927252 add */
    /* @4927256 call */
    GM_SITE(vm, 613, 4927256);
    v87 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v88 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4927264 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v87, v88, STR_REF(1097)));
    L_4927268: ;
    /* @4927268 load */
    /* @4927276 constant */
    /* @4927280 cmp */
    /* @4927284 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4927508;
    /* @4927288 constant */
    /* @4927292 cast */
    /* @4927296 call */
    GM_SITE(vm, 613, 4927296);
    /* @4927304 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4927308 constant */
    /* @4927316 cast */
    /* @4927320 call */
    GM_SITE(vm, 613, 4927320);
    /* @4927328 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4927332 string */
    /* @4927340 cast */
    /* @4927344 constant */
    /* @4927348 load */
    /* @4927356 cast */
    /* @4927360 load */
    /* @4927368 constant */
    /* @4927372 add */
    /* @4927376 constant */
    /* @4927380 load */
    /* @4927388 cast */
    /* @4927392 load */
    /* @4927400 constant */
    /* @4927404 add */
    /* @4927408 call */
    GM_SITE(vm, 613, 4927408);
    v89 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v90 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4927416 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v89, v90, STR_REF(1096)));
    /* @4927420 string */
    /* @4927428 cast */
    /* @4927432 constant */
    /* @4927436 load */
    /* @4927444 cast */
    /* @4927448 load */
    /* @4927456 constant */
    /* @4927460 add */
    /* @4927464 constant */
    /* @4927468 load */
    /* @4927476 cast */
    /* @4927480 load */
    /* @4927488 constant */
    /* @4927492 add */
    /* @4927496 call */
    GM_SITE(vm, 613, 4927496);
    v91 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v92 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4927504 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v91, v92, STR_REF(1097)));
    L_4927508: ;
    /* @4927508 load */
    /* @4927516 constant */
    /* @4927520 cmp */
    /* @4927524 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4927748;
    /* @4927528 constant */
    /* @4927532 cast */
    /* @4927536 call */
    GM_SITE(vm, 613, 4927536);
    /* @4927544 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4927548 constant */
    /* @4927556 cast */
    /* @4927560 call */
    GM_SITE(vm, 613, 4927560);
    /* @4927568 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4927572 string */
    /* @4927580 cast */
    /* @4927584 constant */
    /* @4927588 load */
    /* @4927596 cast */
    /* @4927600 load */
    /* @4927608 constant */
    /* @4927612 add */
    /* @4927616 constant */
    /* @4927620 load */
    /* @4927628 cast */
    /* @4927632 load */
    /* @4927640 constant */
    /* @4927644 add */
    /* @4927648 call */
    GM_SITE(vm, 613, 4927648);
    v93 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v94 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4927656 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v93, v94, STR_REF(1096)));
    /* @4927660 string */
    /* @4927668 cast */
    /* @4927672 constant */
    /* @4927676 load */
    /* @4927684 cast */
    /* @4927688 load */
    /* @4927696 constant */
    /* @4927700 add */
    /* @4927704 constant */
    /* @4927708 load */
    /* @4927716 cast */
    /* @4927720 load */
    /* @4927728 constant */
    /* @4927732 add */
    /* @4927736 call */
    GM_SITE(vm, 613, 4927736);
    v95 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v96 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4927744 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v95, v96, STR_REF(1097)));
    L_4927748: ;
    /* @4927748 load */
    /* @4927756 constant */
    /* @4927760 cmp */
    /* @4927764 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4927988;
    /* @4927768 constant */
    /* @4927772 cast */
    /* @4927776 call */
    GM_SITE(vm, 613, 4927776);
    /* @4927784 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4927788 constant */
    /* @4927796 cast */
    /* @4927800 call */
    GM_SITE(vm, 613, 4927800);
    /* @4927808 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4927812 string */
    /* @4927820 cast */
    /* @4927824 constant */
    /* @4927828 load */
    /* @4927836 cast */
    /* @4927840 load */
    /* @4927848 constant */
    /* @4927852 add */
    /* @4927856 constant */
    /* @4927860 load */
    /* @4927868 cast */
    /* @4927872 load */
    /* @4927880 constant */
    /* @4927884 add */
    /* @4927888 call */
    GM_SITE(vm, 613, 4927888);
    v97 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v98 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4927896 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v97, v98, STR_REF(1096)));
    /* @4927900 string */
    /* @4927908 cast */
    /* @4927912 constant */
    /* @4927916 load */
    /* @4927924 cast */
    /* @4927928 load */
    /* @4927936 constant */
    /* @4927940 add */
    /* @4927944 constant */
    /* @4927948 load */
    /* @4927956 cast */
    /* @4927960 load */
    /* @4927968 constant */
    /* @4927972 add */
    /* @4927976 call */
    GM_SITE(vm, 613, 4927976);
    v99 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v100 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4927984 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v99, v100, STR_REF(1097)));
    L_4927988: ;
    /* @4927988 load */
    /* @4927996 constant */
    /* @4928000 cmp */
    /* @4928004 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4928228;
    /* @4928008 constant */
    /* @4928012 cast */
    /* @4928016 call */
    GM_SITE(vm, 613, 4928016);
    /* @4928024 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4928028 constant */
    /* @4928036 cast */
    /* @4928040 call */
    GM_SITE(vm, 613, 4928040);
    /* @4928048 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4928052 string */
    /* @4928060 cast */
    /* @4928064 constant */
    /* @4928068 load */
    /* @4928076 cast */
    /* @4928080 load */
    /* @4928088 constant */
    /* @4928092 add */
    /* @4928096 constant */
    /* @4928100 load */
    /* @4928108 cast */
    /* @4928112 load */
    /* @4928120 constant */
    /* @4928124 add */
    /* @4928128 call */
    GM_SITE(vm, 613, 4928128);
    v101 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v102 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4928136 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v101, v102, STR_REF(1096)));
    /* @4928140 string */
    /* @4928148 cast */
    /* @4928152 constant */
    /* @4928156 load */
    /* @4928164 cast */
    /* @4928168 load */
    /* @4928176 constant */
    /* @4928180 add */
    /* @4928184 constant */
    /* @4928188 load */
    /* @4928196 cast */
    /* @4928200 load */
    /* @4928208 constant */
    /* @4928212 add */
    /* @4928216 call */
    GM_SITE(vm, 613, 4928216);
    v103 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v104 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4928224 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v103, v104, STR_REF(1097)));
    L_4928228: ;
    /* @4928228 load */
    /* @4928236 constant */
    /* @4928240 cmp */
    /* @4928244 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4928468;
    /* @4928248 constant */
    /* @4928252 cast */
    /* @4928256 call */
    GM_SITE(vm, 613, 4928256);
    /* @4928264 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4928268 constant */
    /* @4928276 cast */
    /* @4928280 call */
    GM_SITE(vm, 613, 4928280);
    /* @4928288 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4928292 string */
    /* @4928300 cast */
    /* @4928304 constant */
    /* @4928308 load */
    /* @4928316 cast */
    /* @4928320 load */
    /* @4928328 constant */
    /* @4928332 add */
    /* @4928336 constant */
    /* @4928340 load */
    /* @4928348 cast */
    /* @4928352 load */
    /* @4928360 constant */
    /* @4928364 add */
    /* @4928368 call */
    GM_SITE(vm, 613, 4928368);
    v105 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v106 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4928376 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v105, v106, STR_REF(1096)));
    /* @4928380 string */
    /* @4928388 cast */
    /* @4928392 constant */
    /* @4928396 load */
    /* @4928404 cast */
    /* @4928408 load */
    /* @4928416 constant */
    /* @4928420 add */
    /* @4928424 constant */
    /* @4928428 load */
    /* @4928436 cast */
    /* @4928440 load */
    /* @4928448 constant */
    /* @4928452 add */
    /* @4928456 call */
    GM_SITE(vm, 613, 4928456);
    v107 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v108 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4928464 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v107, v108, STR_REF(1097)));
    L_4928468: ;
    /* @4928468 load */
    /* @4928476 constant */
    /* @4928480 cmp */
    /* @4928484 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel4") == VAL(1)))) goto L_4929928;
    /* @4928488 load */
    /* @4928496 constant */
    /* @4928500 cmp */
    /* @4928504 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4928728;
    /* @4928508 constant */
    /* @4928512 cast */
    /* @4928516 call */
    GM_SITE(vm, 613, 4928516);
    /* @4928524 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4928528 constant */
    /* @4928536 cast */
    /* @4928540 call */
    GM_SITE(vm, 613, 4928540);
    /* @4928548 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4928552 string */
    /* @4928560 cast */
    /* @4928564 constant */
    /* @4928568 load */
    /* @4928576 cast */
    /* @4928580 load */
    /* @4928588 constant */
    /* @4928592 add */
    /* @4928596 constant */
    /* @4928600 load */
    /* @4928608 cast */
    /* @4928612 load */
    /* @4928620 constant */
    /* @4928624 add */
    /* @4928628 call */
    GM_SITE(vm, 613, 4928628);
    v109 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v110 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4928636 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v109, v110, STR_REF(1098)));
    /* @4928640 string */
    /* @4928648 cast */
    /* @4928652 constant */
    /* @4928656 load */
    /* @4928664 cast */
    /* @4928668 load */
    /* @4928676 constant */
    /* @4928680 add */
    /* @4928684 constant */
    /* @4928688 load */
    /* @4928696 cast */
    /* @4928700 load */
    /* @4928708 constant */
    /* @4928712 add */
    /* @4928716 call */
    GM_SITE(vm, 613, 4928716);
    v111 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v112 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4928724 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v111, v112, STR_REF(1099)));
    L_4928728: ;
    /* @4928728 load */
    /* @4928736 constant */
    /* @4928740 cmp */
    /* @4928744 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4928968;
    /* @4928748 constant */
    /* @4928752 cast */
    /* @4928756 call */
    GM_SITE(vm, 613, 4928756);
    /* @4928764 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4928768 constant */
    /* @4928776 cast */
    /* @4928780 call */
    GM_SITE(vm, 613, 4928780);
    /* @4928788 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4928792 string */
    /* @4928800 cast */
    /* @4928804 constant */
    /* @4928808 load */
    /* @4928816 cast */
    /* @4928820 load */
    /* @4928828 constant */
    /* @4928832 add */
    /* @4928836 constant */
    /* @4928840 load */
    /* @4928848 cast */
    /* @4928852 load */
    /* @4928860 constant */
    /* @4928864 add */
    /* @4928868 call */
    GM_SITE(vm, 613, 4928868);
    v113 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v114 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4928876 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v113, v114, STR_REF(1098)));
    /* @4928880 string */
    /* @4928888 cast */
    /* @4928892 constant */
    /* @4928896 load */
    /* @4928904 cast */
    /* @4928908 load */
    /* @4928916 constant */
    /* @4928920 add */
    /* @4928924 constant */
    /* @4928928 load */
    /* @4928936 cast */
    /* @4928940 load */
    /* @4928948 constant */
    /* @4928952 add */
    /* @4928956 call */
    GM_SITE(vm, 613, 4928956);
    v115 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v116 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4928964 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v115, v116, STR_REF(1099)));
    L_4928968: ;
    /* @4928968 load */
    /* @4928976 constant */
    /* @4928980 cmp */
    /* @4928984 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4929208;
    /* @4928988 constant */
    /* @4928992 cast */
    /* @4928996 call */
    GM_SITE(vm, 613, 4928996);
    /* @4929004 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4929008 constant */
    /* @4929016 cast */
    /* @4929020 call */
    GM_SITE(vm, 613, 4929020);
    /* @4929028 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4929032 string */
    /* @4929040 cast */
    /* @4929044 constant */
    /* @4929048 load */
    /* @4929056 cast */
    /* @4929060 load */
    /* @4929068 constant */
    /* @4929072 add */
    /* @4929076 constant */
    /* @4929080 load */
    /* @4929088 cast */
    /* @4929092 load */
    /* @4929100 constant */
    /* @4929104 add */
    /* @4929108 call */
    GM_SITE(vm, 613, 4929108);
    v117 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v118 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4929116 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v117, v118, STR_REF(1098)));
    /* @4929120 string */
    /* @4929128 cast */
    /* @4929132 constant */
    /* @4929136 load */
    /* @4929144 cast */
    /* @4929148 load */
    /* @4929156 constant */
    /* @4929160 add */
    /* @4929164 constant */
    /* @4929168 load */
    /* @4929176 cast */
    /* @4929180 load */
    /* @4929188 constant */
    /* @4929192 add */
    /* @4929196 call */
    GM_SITE(vm, 613, 4929196);
    v119 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v120 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4929204 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v119, v120, STR_REF(1099)));
    L_4929208: ;
    /* @4929208 load */
    /* @4929216 constant */
    /* @4929220 cmp */
    /* @4929224 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4929448;
    /* @4929228 constant */
    /* @4929232 cast */
    /* @4929236 call */
    GM_SITE(vm, 613, 4929236);
    /* @4929244 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4929248 constant */
    /* @4929256 cast */
    /* @4929260 call */
    GM_SITE(vm, 613, 4929260);
    /* @4929268 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4929272 string */
    /* @4929280 cast */
    /* @4929284 constant */
    /* @4929288 load */
    /* @4929296 cast */
    /* @4929300 load */
    /* @4929308 constant */
    /* @4929312 add */
    /* @4929316 constant */
    /* @4929320 load */
    /* @4929328 cast */
    /* @4929332 load */
    /* @4929340 constant */
    /* @4929344 add */
    /* @4929348 call */
    GM_SITE(vm, 613, 4929348);
    v121 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v122 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4929356 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v121, v122, STR_REF(1098)));
    /* @4929360 string */
    /* @4929368 cast */
    /* @4929372 constant */
    /* @4929376 load */
    /* @4929384 cast */
    /* @4929388 load */
    /* @4929396 constant */
    /* @4929400 add */
    /* @4929404 constant */
    /* @4929408 load */
    /* @4929416 cast */
    /* @4929420 load */
    /* @4929428 constant */
    /* @4929432 add */
    /* @4929436 call */
    GM_SITE(vm, 613, 4929436);
    v123 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v124 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4929444 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v123, v124, STR_REF(1099)));
    L_4929448: ;
    /* @4929448 load */
    /* @4929456 constant */
    /* @4929460 cmp */
    /* @4929464 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4929688;
    /* @4929468 constant */
    /* @4929472 cast */
    /* @4929476 call */
    GM_SITE(vm, 613, 4929476);
    /* @4929484 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4929488 constant */
    /* @4929496 cast */
    /* @4929500 call */
    GM_SITE(vm, 613, 4929500);
    /* @4929508 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4929512 string */
    /* @4929520 cast */
    /* @4929524 constant */
    /* @4929528 load */
    /* @4929536 cast */
    /* @4929540 load */
    /* @4929548 constant */
    /* @4929552 add */
    /* @4929556 constant */
    /* @4929560 load */
    /* @4929568 cast */
    /* @4929572 load */
    /* @4929580 constant */
    /* @4929584 add */
    /* @4929588 call */
    GM_SITE(vm, 613, 4929588);
    v125 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v126 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4929596 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v125, v126, STR_REF(1098)));
    /* @4929600 string */
    /* @4929608 cast */
    /* @4929612 constant */
    /* @4929616 load */
    /* @4929624 cast */
    /* @4929628 load */
    /* @4929636 constant */
    /* @4929640 add */
    /* @4929644 constant */
    /* @4929648 load */
    /* @4929656 cast */
    /* @4929660 load */
    /* @4929668 constant */
    /* @4929672 add */
    /* @4929676 call */
    GM_SITE(vm, 613, 4929676);
    v127 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v128 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4929684 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v127, v128, STR_REF(1099)));
    L_4929688: ;
    /* @4929688 load */
    /* @4929696 constant */
    /* @4929700 cmp */
    /* @4929704 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4929928;
    /* @4929708 constant */
    /* @4929712 cast */
    /* @4929716 call */
    GM_SITE(vm, 613, 4929716);
    /* @4929724 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4929728 constant */
    /* @4929736 cast */
    /* @4929740 call */
    GM_SITE(vm, 613, 4929740);
    /* @4929748 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4929752 string */
    /* @4929760 cast */
    /* @4929764 constant */
    /* @4929768 load */
    /* @4929776 cast */
    /* @4929780 load */
    /* @4929788 constant */
    /* @4929792 add */
    /* @4929796 constant */
    /* @4929800 load */
    /* @4929808 cast */
    /* @4929812 load */
    /* @4929820 constant */
    /* @4929824 add */
    /* @4929828 call */
    GM_SITE(vm, 613, 4929828);
    v129 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v130 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4929836 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v129, v130, STR_REF(1098)));
    /* @4929840 string */
    /* @4929848 cast */
    /* @4929852 constant */
    /* @4929856 load */
    /* @4929864 cast */
    /* @4929868 load */
    /* @4929876 constant */
    /* @4929880 add */
    /* @4929884 constant */
    /* @4929888 load */
    /* @4929896 cast */
    /* @4929900 load */
    /* @4929908 constant */
    /* @4929912 add */
    /* @4929916 call */
    GM_SITE(vm, 613, 4929916);
    v131 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v132 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4929924 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v131, v132, STR_REF(1099)));
    L_4929928: ;
    /* @4929928 load */
    /* @4929936 constant */
    /* @4929940 cmp */
    /* @4929944 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel5") == VAL(1)))) goto L_4931388;
    /* @4929948 load */
    /* @4929956 constant */
    /* @4929960 cmp */
    /* @4929964 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4930188;
    /* @4929968 constant */
    /* @4929972 cast */
    /* @4929976 call */
    GM_SITE(vm, 613, 4929976);
    /* @4929984 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4929988 constant */
    /* @4929996 cast */
    /* @4930000 call */
    GM_SITE(vm, 613, 4930000);
    /* @4930008 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4930012 string */
    /* @4930020 cast */
    /* @4930024 constant */
    /* @4930028 load */
    /* @4930036 cast */
    /* @4930040 load */
    /* @4930048 constant */
    /* @4930052 add */
    /* @4930056 constant */
    /* @4930060 load */
    /* @4930068 cast */
    /* @4930072 load */
    /* @4930080 constant */
    /* @4930084 add */
    /* @4930088 call */
    GM_SITE(vm, 613, 4930088);
    v133 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v134 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4930096 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v133, v134, STR_REF(1100)));
    /* @4930100 string */
    /* @4930108 cast */
    /* @4930112 constant */
    /* @4930116 load */
    /* @4930124 cast */
    /* @4930128 load */
    /* @4930136 constant */
    /* @4930140 add */
    /* @4930144 constant */
    /* @4930148 load */
    /* @4930156 cast */
    /* @4930160 load */
    /* @4930168 constant */
    /* @4930172 add */
    /* @4930176 call */
    GM_SITE(vm, 613, 4930176);
    v135 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v136 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4930184 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v135, v136, STR_REF(1101)));
    L_4930188: ;
    /* @4930188 load */
    /* @4930196 constant */
    /* @4930200 cmp */
    /* @4930204 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4930428;
    /* @4930208 constant */
    /* @4930212 cast */
    /* @4930216 call */
    GM_SITE(vm, 613, 4930216);
    /* @4930224 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4930228 constant */
    /* @4930236 cast */
    /* @4930240 call */
    GM_SITE(vm, 613, 4930240);
    /* @4930248 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4930252 string */
    /* @4930260 cast */
    /* @4930264 constant */
    /* @4930268 load */
    /* @4930276 cast */
    /* @4930280 load */
    /* @4930288 constant */
    /* @4930292 add */
    /* @4930296 constant */
    /* @4930300 load */
    /* @4930308 cast */
    /* @4930312 load */
    /* @4930320 constant */
    /* @4930324 add */
    /* @4930328 call */
    GM_SITE(vm, 613, 4930328);
    v137 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v138 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4930336 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v137, v138, STR_REF(1100)));
    /* @4930340 string */
    /* @4930348 cast */
    /* @4930352 constant */
    /* @4930356 load */
    /* @4930364 cast */
    /* @4930368 load */
    /* @4930376 constant */
    /* @4930380 add */
    /* @4930384 constant */
    /* @4930388 load */
    /* @4930396 cast */
    /* @4930400 load */
    /* @4930408 constant */
    /* @4930412 add */
    /* @4930416 call */
    GM_SITE(vm, 613, 4930416);
    v139 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v140 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4930424 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v139, v140, STR_REF(1101)));
    L_4930428: ;
    /* @4930428 load */
    /* @4930436 constant */
    /* @4930440 cmp */
    /* @4930444 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4930668;
    /* @4930448 constant */
    /* @4930452 cast */
    /* @4930456 call */
    GM_SITE(vm, 613, 4930456);
    /* @4930464 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4930468 constant */
    /* @4930476 cast */
    /* @4930480 call */
    GM_SITE(vm, 613, 4930480);
    /* @4930488 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4930492 string */
    /* @4930500 cast */
    /* @4930504 constant */
    /* @4930508 load */
    /* @4930516 cast */
    /* @4930520 load */
    /* @4930528 constant */
    /* @4930532 add */
    /* @4930536 constant */
    /* @4930540 load */
    /* @4930548 cast */
    /* @4930552 load */
    /* @4930560 constant */
    /* @4930564 add */
    /* @4930568 call */
    GM_SITE(vm, 613, 4930568);
    v141 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v142 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4930576 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v141, v142, STR_REF(1100)));
    /* @4930580 string */
    /* @4930588 cast */
    /* @4930592 constant */
    /* @4930596 load */
    /* @4930604 cast */
    /* @4930608 load */
    /* @4930616 constant */
    /* @4930620 add */
    /* @4930624 constant */
    /* @4930628 load */
    /* @4930636 cast */
    /* @4930640 load */
    /* @4930648 constant */
    /* @4930652 add */
    /* @4930656 call */
    GM_SITE(vm, 613, 4930656);
    v143 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v144 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4930664 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v143, v144, STR_REF(1101)));
    L_4930668: ;
    /* @4930668 load */
    /* @4930676 constant */
    /* @4930680 cmp */
    /* @4930684 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4930908;
    /* @4930688 constant */
    /* @4930692 cast */
    /* @4930696 call */
    GM_SITE(vm, 613, 4930696);
    /* @4930704 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4930708 constant */
    /* @4930716 cast */
    /* @4930720 call */
    GM_SITE(vm, 613, 4930720);
    /* @4930728 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4930732 string */
    /* @4930740 cast */
    /* @4930744 constant */
    /* @4930748 load */
    /* @4930756 cast */
    /* @4930760 load */
    /* @4930768 constant */
    /* @4930772 add */
    /* @4930776 constant */
    /* @4930780 load */
    /* @4930788 cast */
    /* @4930792 load */
    /* @4930800 constant */
    /* @4930804 add */
    /* @4930808 call */
    GM_SITE(vm, 613, 4930808);
    v145 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v146 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4930816 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v145, v146, STR_REF(1100)));
    /* @4930820 string */
    /* @4930828 cast */
    /* @4930832 constant */
    /* @4930836 load */
    /* @4930844 cast */
    /* @4930848 load */
    /* @4930856 constant */
    /* @4930860 add */
    /* @4930864 constant */
    /* @4930868 load */
    /* @4930876 cast */
    /* @4930880 load */
    /* @4930888 constant */
    /* @4930892 add */
    /* @4930896 call */
    GM_SITE(vm, 613, 4930896);
    v147 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v148 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4930904 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v147, v148, STR_REF(1101)));
    L_4930908: ;
    /* @4930908 load */
    /* @4930916 constant */
    /* @4930920 cmp */
    /* @4930924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4931148;
    /* @4930928 constant */
    /* @4930932 cast */
    /* @4930936 call */
    GM_SITE(vm, 613, 4930936);
    /* @4930944 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4930948 constant */
    /* @4930956 cast */
    /* @4930960 call */
    GM_SITE(vm, 613, 4930960);
    /* @4930968 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4930972 string */
    /* @4930980 cast */
    /* @4930984 constant */
    /* @4930988 load */
    /* @4930996 cast */
    /* @4931000 load */
    /* @4931008 constant */
    /* @4931012 add */
    /* @4931016 constant */
    /* @4931020 load */
    /* @4931028 cast */
    /* @4931032 load */
    /* @4931040 constant */
    /* @4931044 add */
    /* @4931048 call */
    GM_SITE(vm, 613, 4931048);
    v149 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v150 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4931056 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v149, v150, STR_REF(1100)));
    /* @4931060 string */
    /* @4931068 cast */
    /* @4931072 constant */
    /* @4931076 load */
    /* @4931084 cast */
    /* @4931088 load */
    /* @4931096 constant */
    /* @4931100 add */
    /* @4931104 constant */
    /* @4931108 load */
    /* @4931116 cast */
    /* @4931120 load */
    /* @4931128 constant */
    /* @4931132 add */
    /* @4931136 call */
    GM_SITE(vm, 613, 4931136);
    v151 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v152 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4931144 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v151, v152, STR_REF(1101)));
    L_4931148: ;
    /* @4931148 load */
    /* @4931156 constant */
    /* @4931160 cmp */
    /* @4931164 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4931388;
    /* @4931168 constant */
    /* @4931172 cast */
    /* @4931176 call */
    GM_SITE(vm, 613, 4931176);
    /* @4931184 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4931188 constant */
    /* @4931196 cast */
    /* @4931200 call */
    GM_SITE(vm, 613, 4931200);
    /* @4931208 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4931212 string */
    /* @4931220 cast */
    /* @4931224 constant */
    /* @4931228 load */
    /* @4931236 cast */
    /* @4931240 load */
    /* @4931248 constant */
    /* @4931252 add */
    /* @4931256 constant */
    /* @4931260 load */
    /* @4931268 cast */
    /* @4931272 load */
    /* @4931280 constant */
    /* @4931284 add */
    /* @4931288 call */
    GM_SITE(vm, 613, 4931288);
    v153 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v154 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4931296 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v153, v154, STR_REF(1100)));
    /* @4931300 string */
    /* @4931308 cast */
    /* @4931312 constant */
    /* @4931316 load */
    /* @4931324 cast */
    /* @4931328 load */
    /* @4931336 constant */
    /* @4931340 add */
    /* @4931344 constant */
    /* @4931348 load */
    /* @4931356 cast */
    /* @4931360 load */
    /* @4931368 constant */
    /* @4931372 add */
    /* @4931376 call */
    GM_SITE(vm, 613, 4931376);
    v155 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v156 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4931384 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v155, v156, STR_REF(1101)));
    L_4931388: ;
    /* @4931388 load */
    /* @4931396 constant */
    /* @4931400 cmp */
    /* @4931404 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4931440;
    /* @4931408 constant */
    /* @4931412 cast */
    /* @4931416 constant */
    /* @4931420 cast */
    /* @4931424 call */
    GM_SITE(vm, 613, 4931424);
    /* @4931432 cast */
    /* @4931436 b */
    v157 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, VAL(0), VAL(1)));
    p4931444_0 = v157;
    goto L_4931444;
    L_4931440: ;
    /* @4931440 constant */
    p4931444_0 = VAL(0);
    L_4931444: ;
    /* @4931444 bf */
    if (!TRUTH(p4931444_0)) goto L_4931460;
    /* @4931448 call */
    GM_SITE(vm, 613, 4931448);
    /* @4931456 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4931460: ;
    return;
}
