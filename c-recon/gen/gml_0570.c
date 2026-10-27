/* generated from CODE 570 (gml_Object_obj_lloydtutorial2_Draw_0), source start 4862272, end 4870052. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0570(GmVM* vm) {
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
    Val p4870036_0;
    Val v109;
    /* @4862272 constant */
    /* @4862276 load */
    /* @4862284 cast */
    /* @4862288 load */
    /* @4862296 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4862304 constant */
    /* @4862308 load */
    /* @4862316 cast */
    /* @4862320 load */
    /* @4862328 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4862336 load */
    /* @4862344 constant */
    /* @4862348 cmp */
    /* @4862352 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4862880;
    /* @4862356 constant */
    /* @4862360 cast */
    /* @4862364 constant */
    /* @4862368 cast */
    /* @4862372 constant */
    /* @4862376 cast */
    /* @4862380 constant */
    /* @4862392 cast */
    /* @4862396 constant */
    /* @4862408 cast */
    /* @4862412 constant */
    /* @4862416 constant */
    /* @4862420 load */
    /* @4862428 constant */
    /* @4862432 constant */
    /* @4862436 load */
    /* @4862444 constant */
    /* @4862448 sub */
    /* @4862452 constant */
    /* @4862456 cast */
    /* @4862460 constant */
    /* @4862464 cast */
    /* @4862468 call */
    GM_SITE(vm, 570, 4862468);
    /* @4862476 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(0.96), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4862480 constant */
    /* @4862484 cast */
    /* @4862488 constant */
    /* @4862492 cast */
    /* @4862496 constant */
    /* @4862500 cast */
    /* @4862504 constant */
    /* @4862508 cast */
    /* @4862512 constant */
    /* @4862516 cast */
    /* @4862520 constant */
    /* @4862524 load */
    /* @4862532 cast */
    /* @4862536 load */
    /* @4862544 constant */
    /* @4862548 add */
    /* @4862552 constant */
    /* @4862556 load */
    /* @4862564 cast */
    /* @4862568 load */
    /* @4862576 constant */
    /* @4862580 add */
    /* @4862584 constant */
    /* @4862588 cast */
    /* @4862592 constant */
    /* @4862596 cast */
    /* @4862600 call */
    GM_SITE(vm, 570, 4862600);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4862608 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v1, v2, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4862612 constant */
    /* @4862616 cast */
    /* @4862620 constant */
    /* @4862624 cast */
    /* @4862628 constant */
    /* @4862632 cast */
    /* @4862636 constant */
    /* @4862640 cast */
    /* @4862644 constant */
    /* @4862648 cast */
    /* @4862652 constant */
    /* @4862656 load */
    /* @4862664 cast */
    /* @4862668 load */
    /* @4862676 constant */
    /* @4862680 add */
    /* @4862684 constant */
    /* @4862688 load */
    /* @4862696 cast */
    /* @4862700 load */
    /* @4862708 constant */
    /* @4862712 add */
    /* @4862716 constant */
    /* @4862720 cast */
    /* @4862724 constant */
    /* @4862728 cast */
    /* @4862732 call */
    GM_SITE(vm, 570, 4862732);
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4862740 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v3, v4, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4862744 load */
    /* @4862752 constant */
    /* @4862756 cmp */
    /* @4862760 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4862880;
    /* @4862764 constant */
    /* @4862768 cast */
    /* @4862772 call */
    GM_SITE(vm, 570, 4862772);
    /* @4862780 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4862784 constant */
    /* @4862792 cast */
    /* @4862796 call */
    GM_SITE(vm, 570, 4862796);
    /* @4862804 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4862808 string */
    /* @4862816 cast */
    /* @4862820 constant */
    /* @4862824 constant */
    /* @4862828 load */
    /* @4862836 constant */
    /* @4862840 add */
    /* @4862844 constant */
    /* @4862848 constant */
    /* @4862852 load */
    /* @4862860 constant */
    /* @4862864 add */
    /* @4862868 call */
    GM_SITE(vm, 570, 4862868);
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(150));
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(200));
    /* @4862876 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v5, v6, STR_REF(743)));
    L_4862880: ;
    /* @4862880 load */
    /* @4862888 constant */
    /* @4862892 cmp */
    /* @4862896 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4863424;
    /* @4862900 constant */
    /* @4862904 cast */
    /* @4862908 constant */
    /* @4862912 cast */
    /* @4862916 constant */
    /* @4862920 cast */
    /* @4862924 constant */
    /* @4862936 cast */
    /* @4862940 constant */
    /* @4862952 cast */
    /* @4862956 constant */
    /* @4862960 constant */
    /* @4862964 load */
    /* @4862972 constant */
    /* @4862976 constant */
    /* @4862980 load */
    /* @4862988 constant */
    /* @4862992 sub */
    /* @4862996 constant */
    /* @4863000 cast */
    /* @4863004 constant */
    /* @4863008 cast */
    /* @4863012 call */
    GM_SITE(vm, 570, 4863012);
    /* @4863020 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(0.82), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4863024 constant */
    /* @4863028 cast */
    /* @4863032 constant */
    /* @4863036 cast */
    /* @4863040 constant */
    /* @4863044 cast */
    /* @4863048 constant */
    /* @4863052 cast */
    /* @4863056 constant */
    /* @4863060 cast */
    /* @4863064 constant */
    /* @4863068 load */
    /* @4863076 cast */
    /* @4863080 load */
    /* @4863088 constant */
    /* @4863092 add */
    /* @4863096 constant */
    /* @4863100 load */
    /* @4863108 cast */
    /* @4863112 load */
    /* @4863120 constant */
    /* @4863124 add */
    /* @4863128 constant */
    /* @4863132 cast */
    /* @4863136 constant */
    /* @4863140 cast */
    /* @4863144 call */
    GM_SITE(vm, 570, 4863144);
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4863152 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v7, v8, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4863156 constant */
    /* @4863160 cast */
    /* @4863164 constant */
    /* @4863168 cast */
    /* @4863172 constant */
    /* @4863176 cast */
    /* @4863180 constant */
    /* @4863184 cast */
    /* @4863188 constant */
    /* @4863192 cast */
    /* @4863196 constant */
    /* @4863200 load */
    /* @4863208 cast */
    /* @4863212 load */
    /* @4863220 constant */
    /* @4863224 add */
    /* @4863228 constant */
    /* @4863232 load */
    /* @4863240 cast */
    /* @4863244 load */
    /* @4863252 constant */
    /* @4863256 add */
    /* @4863260 constant */
    /* @4863264 cast */
    /* @4863268 constant */
    /* @4863272 cast */
    /* @4863276 call */
    GM_SITE(vm, 570, 4863276);
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(320));
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4863284 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v9, v10, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4863288 load */
    /* @4863296 constant */
    /* @4863300 cmp */
    /* @4863304 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4863424;
    /* @4863308 constant */
    /* @4863312 cast */
    /* @4863316 call */
    GM_SITE(vm, 570, 4863316);
    /* @4863324 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4863328 constant */
    /* @4863336 cast */
    /* @4863340 call */
    GM_SITE(vm, 570, 4863340);
    /* @4863348 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4863352 string */
    /* @4863360 cast */
    /* @4863364 constant */
    /* @4863368 constant */
    /* @4863372 load */
    /* @4863380 constant */
    /* @4863384 add */
    /* @4863388 constant */
    /* @4863392 constant */
    /* @4863396 load */
    /* @4863404 constant */
    /* @4863408 add */
    /* @4863412 call */
    GM_SITE(vm, 570, 4863412);
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(110));
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4863420 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v11, v12, STR_REF(743)));
    L_4863424: ;
    /* @4863424 load */
    /* @4863432 constant */
    /* @4863436 cmp */
    /* @4863440 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4863968;
    /* @4863444 constant */
    /* @4863448 cast */
    /* @4863452 constant */
    /* @4863456 cast */
    /* @4863460 constant */
    /* @4863464 cast */
    /* @4863468 constant */
    /* @4863480 cast */
    /* @4863484 constant */
    /* @4863496 cast */
    /* @4863500 constant */
    /* @4863504 constant */
    /* @4863508 load */
    /* @4863516 constant */
    /* @4863520 constant */
    /* @4863524 load */
    /* @4863532 constant */
    /* @4863536 sub */
    /* @4863540 constant */
    /* @4863544 cast */
    /* @4863548 constant */
    /* @4863552 cast */
    /* @4863556 call */
    GM_SITE(vm, 570, 4863556);
    /* @4863564 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4863568 constant */
    /* @4863572 cast */
    /* @4863576 constant */
    /* @4863580 cast */
    /* @4863584 constant */
    /* @4863588 cast */
    /* @4863592 constant */
    /* @4863596 cast */
    /* @4863600 constant */
    /* @4863604 cast */
    /* @4863608 constant */
    /* @4863612 load */
    /* @4863620 cast */
    /* @4863624 load */
    /* @4863632 constant */
    /* @4863636 add */
    /* @4863640 constant */
    /* @4863644 load */
    /* @4863652 cast */
    /* @4863656 load */
    /* @4863664 constant */
    /* @4863668 add */
    /* @4863672 constant */
    /* @4863676 cast */
    /* @4863680 constant */
    /* @4863684 cast */
    /* @4863688 call */
    GM_SITE(vm, 570, 4863688);
    v13 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4863696 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v13, v14, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4863700 constant */
    /* @4863704 cast */
    /* @4863708 constant */
    /* @4863712 cast */
    /* @4863716 constant */
    /* @4863720 cast */
    /* @4863724 constant */
    /* @4863728 cast */
    /* @4863732 constant */
    /* @4863736 cast */
    /* @4863740 constant */
    /* @4863744 load */
    /* @4863752 cast */
    /* @4863756 load */
    /* @4863764 constant */
    /* @4863768 add */
    /* @4863772 constant */
    /* @4863776 load */
    /* @4863784 cast */
    /* @4863788 load */
    /* @4863796 constant */
    /* @4863800 add */
    /* @4863804 constant */
    /* @4863808 cast */
    /* @4863812 constant */
    /* @4863816 cast */
    /* @4863820 call */
    GM_SITE(vm, 570, 4863820);
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4863828 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v15, v16, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4863832 load */
    /* @4863840 constant */
    /* @4863844 cmp */
    /* @4863848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4863968;
    /* @4863852 constant */
    /* @4863856 cast */
    /* @4863860 call */
    GM_SITE(vm, 570, 4863860);
    /* @4863868 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4863872 constant */
    /* @4863880 cast */
    /* @4863884 call */
    GM_SITE(vm, 570, 4863884);
    /* @4863892 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4863896 string */
    /* @4863904 cast */
    /* @4863908 constant */
    /* @4863912 constant */
    /* @4863916 load */
    /* @4863924 constant */
    /* @4863928 add */
    /* @4863932 constant */
    /* @4863936 constant */
    /* @4863940 load */
    /* @4863948 constant */
    /* @4863952 add */
    /* @4863956 call */
    GM_SITE(vm, 570, 4863956);
    v17 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(180));
    v18 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(300));
    /* @4863964 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v17, v18, STR_REF(743)));
    L_4863968: ;
    /* @4863968 load */
    /* @4863976 constant */
    /* @4863980 cmp */
    /* @4863984 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4864512;
    /* @4863988 constant */
    /* @4863992 cast */
    /* @4863996 constant */
    /* @4864000 cast */
    /* @4864004 constant */
    /* @4864008 cast */
    /* @4864012 constant */
    /* @4864024 cast */
    /* @4864028 constant */
    /* @4864040 cast */
    /* @4864044 constant */
    /* @4864048 constant */
    /* @4864052 load */
    /* @4864060 constant */
    /* @4864064 constant */
    /* @4864068 load */
    /* @4864076 constant */
    /* @4864080 sub */
    /* @4864084 constant */
    /* @4864088 cast */
    /* @4864092 constant */
    /* @4864096 cast */
    /* @4864100 call */
    GM_SITE(vm, 570, 4864100);
    /* @4864108 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4864112 constant */
    /* @4864116 cast */
    /* @4864120 constant */
    /* @4864124 cast */
    /* @4864128 constant */
    /* @4864132 cast */
    /* @4864136 constant */
    /* @4864140 cast */
    /* @4864144 constant */
    /* @4864148 cast */
    /* @4864152 constant */
    /* @4864156 load */
    /* @4864164 cast */
    /* @4864168 load */
    /* @4864176 constant */
    /* @4864180 add */
    /* @4864184 constant */
    /* @4864188 load */
    /* @4864196 cast */
    /* @4864200 load */
    /* @4864208 constant */
    /* @4864212 add */
    /* @4864216 constant */
    /* @4864220 cast */
    /* @4864224 constant */
    /* @4864228 cast */
    /* @4864232 call */
    GM_SITE(vm, 570, 4864232);
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4864240 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v19, v20, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4864244 constant */
    /* @4864248 cast */
    /* @4864252 constant */
    /* @4864256 cast */
    /* @4864260 constant */
    /* @4864264 cast */
    /* @4864268 constant */
    /* @4864272 cast */
    /* @4864276 constant */
    /* @4864280 cast */
    /* @4864284 constant */
    /* @4864288 load */
    /* @4864296 cast */
    /* @4864300 load */
    /* @4864308 constant */
    /* @4864312 add */
    /* @4864316 constant */
    /* @4864320 load */
    /* @4864328 cast */
    /* @4864332 load */
    /* @4864340 constant */
    /* @4864344 add */
    /* @4864348 constant */
    /* @4864352 cast */
    /* @4864356 constant */
    /* @4864360 cast */
    /* @4864364 call */
    GM_SITE(vm, 570, 4864364);
    v21 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4864372 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v21, v22, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4864376 load */
    /* @4864384 constant */
    /* @4864388 cmp */
    /* @4864392 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4864512;
    /* @4864396 constant */
    /* @4864400 cast */
    /* @4864404 call */
    GM_SITE(vm, 570, 4864404);
    /* @4864412 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4864416 constant */
    /* @4864424 cast */
    /* @4864428 call */
    GM_SITE(vm, 570, 4864428);
    /* @4864436 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4864440 string */
    /* @4864448 cast */
    /* @4864452 constant */
    /* @4864456 constant */
    /* @4864460 load */
    /* @4864468 constant */
    /* @4864472 add */
    /* @4864476 constant */
    /* @4864480 constant */
    /* @4864484 load */
    /* @4864492 constant */
    /* @4864496 add */
    /* @4864500 call */
    GM_SITE(vm, 570, 4864500);
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(180));
    v24 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(300));
    /* @4864508 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v23, v24, STR_REF(743)));
    L_4864512: ;
    /* @4864512 load */
    /* @4864520 constant */
    /* @4864524 cmp */
    /* @4864528 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4865056;
    /* @4864532 constant */
    /* @4864536 cast */
    /* @4864540 constant */
    /* @4864544 cast */
    /* @4864548 constant */
    /* @4864552 cast */
    /* @4864556 constant */
    /* @4864568 cast */
    /* @4864572 constant */
    /* @4864584 cast */
    /* @4864588 constant */
    /* @4864592 constant */
    /* @4864596 load */
    /* @4864604 constant */
    /* @4864608 constant */
    /* @4864612 load */
    /* @4864620 constant */
    /* @4864624 sub */
    /* @4864628 constant */
    /* @4864632 cast */
    /* @4864636 constant */
    /* @4864640 cast */
    /* @4864644 call */
    GM_SITE(vm, 570, 4864644);
    /* @4864652 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(0.97), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4864656 constant */
    /* @4864660 cast */
    /* @4864664 constant */
    /* @4864668 cast */
    /* @4864672 constant */
    /* @4864676 cast */
    /* @4864680 constant */
    /* @4864684 cast */
    /* @4864688 constant */
    /* @4864692 cast */
    /* @4864696 constant */
    /* @4864700 load */
    /* @4864708 cast */
    /* @4864712 load */
    /* @4864720 constant */
    /* @4864724 add */
    /* @4864728 constant */
    /* @4864732 load */
    /* @4864740 cast */
    /* @4864744 load */
    /* @4864752 constant */
    /* @4864756 add */
    /* @4864760 constant */
    /* @4864764 cast */
    /* @4864768 constant */
    /* @4864772 cast */
    /* @4864776 call */
    GM_SITE(vm, 570, 4864776);
    v25 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v26 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4864784 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v25, v26, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4864788 constant */
    /* @4864792 cast */
    /* @4864796 constant */
    /* @4864800 cast */
    /* @4864804 constant */
    /* @4864808 cast */
    /* @4864812 constant */
    /* @4864816 cast */
    /* @4864820 constant */
    /* @4864824 cast */
    /* @4864828 constant */
    /* @4864832 load */
    /* @4864840 cast */
    /* @4864844 load */
    /* @4864852 constant */
    /* @4864856 add */
    /* @4864860 constant */
    /* @4864864 load */
    /* @4864872 cast */
    /* @4864876 load */
    /* @4864884 constant */
    /* @4864888 add */
    /* @4864892 constant */
    /* @4864896 cast */
    /* @4864900 constant */
    /* @4864904 cast */
    /* @4864908 call */
    GM_SITE(vm, 570, 4864908);
    v27 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v28 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4864916 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v27, v28, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4864920 load */
    /* @4864928 constant */
    /* @4864932 cmp */
    /* @4864936 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4865056;
    /* @4864940 constant */
    /* @4864944 cast */
    /* @4864948 call */
    GM_SITE(vm, 570, 4864948);
    /* @4864956 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4864960 constant */
    /* @4864968 cast */
    /* @4864972 call */
    GM_SITE(vm, 570, 4864972);
    /* @4864980 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4864984 string */
    /* @4864992 cast */
    /* @4864996 constant */
    /* @4865000 constant */
    /* @4865004 load */
    /* @4865012 constant */
    /* @4865016 add */
    /* @4865020 constant */
    /* @4865024 constant */
    /* @4865028 load */
    /* @4865036 constant */
    /* @4865040 add */
    /* @4865044 call */
    GM_SITE(vm, 570, 4865044);
    v29 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(150));
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(200));
    /* @4865052 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v29, v30, STR_REF(743)));
    L_4865056: ;
    /* @4865056 load */
    /* @4865064 constant */
    /* @4865068 cmp */
    /* @4865072 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4865600;
    /* @4865076 constant */
    /* @4865080 cast */
    /* @4865084 constant */
    /* @4865088 cast */
    /* @4865092 constant */
    /* @4865096 cast */
    /* @4865100 constant */
    /* @4865112 cast */
    /* @4865116 constant */
    /* @4865128 cast */
    /* @4865132 constant */
    /* @4865136 constant */
    /* @4865140 load */
    /* @4865148 constant */
    /* @4865152 constant */
    /* @4865156 load */
    /* @4865164 constant */
    /* @4865168 sub */
    /* @4865172 constant */
    /* @4865176 cast */
    /* @4865180 constant */
    /* @4865184 cast */
    /* @4865188 call */
    GM_SITE(vm, 570, 4865188);
    /* @4865196 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(1.06), VAL(0.86), VAL(0), VAL(-1), VAL(1)));
    /* @4865200 constant */
    /* @4865204 cast */
    /* @4865208 constant */
    /* @4865212 cast */
    /* @4865216 constant */
    /* @4865220 cast */
    /* @4865224 constant */
    /* @4865228 cast */
    /* @4865232 constant */
    /* @4865236 cast */
    /* @4865240 constant */
    /* @4865244 load */
    /* @4865252 cast */
    /* @4865256 load */
    /* @4865264 constant */
    /* @4865268 add */
    /* @4865272 constant */
    /* @4865276 load */
    /* @4865284 cast */
    /* @4865288 load */
    /* @4865296 constant */
    /* @4865300 add */
    /* @4865304 constant */
    /* @4865308 cast */
    /* @4865312 constant */
    /* @4865316 cast */
    /* @4865320 call */
    GM_SITE(vm, 570, 4865320);
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v32 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4865328 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v31, v32, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4865332 constant */
    /* @4865336 cast */
    /* @4865340 constant */
    /* @4865344 cast */
    /* @4865348 constant */
    /* @4865352 cast */
    /* @4865356 constant */
    /* @4865360 cast */
    /* @4865364 constant */
    /* @4865368 cast */
    /* @4865372 constant */
    /* @4865376 load */
    /* @4865384 cast */
    /* @4865388 load */
    /* @4865396 constant */
    /* @4865400 add */
    /* @4865404 constant */
    /* @4865408 load */
    /* @4865416 cast */
    /* @4865420 load */
    /* @4865428 constant */
    /* @4865432 add */
    /* @4865436 constant */
    /* @4865440 cast */
    /* @4865444 constant */
    /* @4865448 cast */
    /* @4865452 call */
    GM_SITE(vm, 570, 4865452);
    v33 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(390));
    v34 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4865460 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v33, v34, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4865464 load */
    /* @4865472 constant */
    /* @4865476 cmp */
    /* @4865480 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4865600;
    /* @4865484 constant */
    /* @4865488 cast */
    /* @4865492 call */
    GM_SITE(vm, 570, 4865492);
    /* @4865500 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4865504 constant */
    /* @4865512 cast */
    /* @4865516 call */
    GM_SITE(vm, 570, 4865516);
    /* @4865524 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4865528 string */
    /* @4865536 cast */
    /* @4865540 constant */
    /* @4865544 constant */
    /* @4865548 load */
    /* @4865556 constant */
    /* @4865560 add */
    /* @4865564 constant */
    /* @4865568 constant */
    /* @4865572 load */
    /* @4865580 constant */
    /* @4865584 add */
    /* @4865588 call */
    GM_SITE(vm, 570, 4865588);
    v35 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(160));
    v36 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(200));
    /* @4865596 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v35, v36, STR_REF(743)));
    L_4865600: ;
    /* @4865600 load */
    /* @4865608 constant */
    /* @4865612 cmp */
    /* @4865616 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel1") == VAL(1)))) goto L_4867060;
    /* @4865620 load */
    /* @4865628 constant */
    /* @4865632 cmp */
    /* @4865636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4865860;
    /* @4865640 constant */
    /* @4865644 cast */
    /* @4865648 call */
    GM_SITE(vm, 570, 4865648);
    /* @4865656 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4865660 constant */
    /* @4865668 cast */
    /* @4865672 call */
    GM_SITE(vm, 570, 4865672);
    /* @4865680 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4865684 string */
    /* @4865692 cast */
    /* @4865696 constant */
    /* @4865700 load */
    /* @4865708 cast */
    /* @4865712 load */
    /* @4865720 constant */
    /* @4865724 add */
    /* @4865728 constant */
    /* @4865732 load */
    /* @4865740 cast */
    /* @4865744 load */
    /* @4865752 constant */
    /* @4865756 add */
    /* @4865760 call */
    GM_SITE(vm, 570, 4865760);
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4865768 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v37, v38, STR_REF(1048)));
    /* @4865772 string */
    /* @4865780 cast */
    /* @4865784 constant */
    /* @4865788 load */
    /* @4865796 cast */
    /* @4865800 load */
    /* @4865808 constant */
    /* @4865812 add */
    /* @4865816 constant */
    /* @4865820 load */
    /* @4865828 cast */
    /* @4865832 load */
    /* @4865840 constant */
    /* @4865844 add */
    /* @4865848 call */
    GM_SITE(vm, 570, 4865848);
    v39 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v40 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4865856 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, v40, STR_REF(1049)));
    L_4865860: ;
    /* @4865860 load */
    /* @4865868 constant */
    /* @4865872 cmp */
    /* @4865876 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4866100;
    /* @4865880 constant */
    /* @4865884 cast */
    /* @4865888 call */
    GM_SITE(vm, 570, 4865888);
    /* @4865896 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4865900 constant */
    /* @4865908 cast */
    /* @4865912 call */
    GM_SITE(vm, 570, 4865912);
    /* @4865920 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4865924 string */
    /* @4865932 cast */
    /* @4865936 constant */
    /* @4865940 load */
    /* @4865948 cast */
    /* @4865952 load */
    /* @4865960 constant */
    /* @4865964 add */
    /* @4865968 constant */
    /* @4865972 load */
    /* @4865980 cast */
    /* @4865984 load */
    /* @4865992 constant */
    /* @4865996 add */
    /* @4866000 call */
    GM_SITE(vm, 570, 4866000);
    v41 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v42 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4866008 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v41, v42, STR_REF(1048)));
    /* @4866012 string */
    /* @4866020 cast */
    /* @4866024 constant */
    /* @4866028 load */
    /* @4866036 cast */
    /* @4866040 load */
    /* @4866048 constant */
    /* @4866052 add */
    /* @4866056 constant */
    /* @4866060 load */
    /* @4866068 cast */
    /* @4866072 load */
    /* @4866080 constant */
    /* @4866084 add */
    /* @4866088 call */
    GM_SITE(vm, 570, 4866088);
    v43 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v44 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4866096 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v43, v44, STR_REF(1049)));
    L_4866100: ;
    /* @4866100 load */
    /* @4866108 constant */
    /* @4866112 cmp */
    /* @4866116 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4866340;
    /* @4866120 constant */
    /* @4866124 cast */
    /* @4866128 call */
    GM_SITE(vm, 570, 4866128);
    /* @4866136 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4866140 constant */
    /* @4866148 cast */
    /* @4866152 call */
    GM_SITE(vm, 570, 4866152);
    /* @4866160 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4866164 string */
    /* @4866172 cast */
    /* @4866176 constant */
    /* @4866180 load */
    /* @4866188 cast */
    /* @4866192 load */
    /* @4866200 constant */
    /* @4866204 add */
    /* @4866208 constant */
    /* @4866212 load */
    /* @4866220 cast */
    /* @4866224 load */
    /* @4866232 constant */
    /* @4866236 add */
    /* @4866240 call */
    GM_SITE(vm, 570, 4866240);
    v45 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v46 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4866248 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v45, v46, STR_REF(1048)));
    /* @4866252 string */
    /* @4866260 cast */
    /* @4866264 constant */
    /* @4866268 load */
    /* @4866276 cast */
    /* @4866280 load */
    /* @4866288 constant */
    /* @4866292 add */
    /* @4866296 constant */
    /* @4866300 load */
    /* @4866308 cast */
    /* @4866312 load */
    /* @4866320 constant */
    /* @4866324 add */
    /* @4866328 call */
    GM_SITE(vm, 570, 4866328);
    v47 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v48 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4866336 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v47, v48, STR_REF(1049)));
    L_4866340: ;
    /* @4866340 load */
    /* @4866348 constant */
    /* @4866352 cmp */
    /* @4866356 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4866580;
    /* @4866360 constant */
    /* @4866364 cast */
    /* @4866368 call */
    GM_SITE(vm, 570, 4866368);
    /* @4866376 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4866380 constant */
    /* @4866388 cast */
    /* @4866392 call */
    GM_SITE(vm, 570, 4866392);
    /* @4866400 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4866404 string */
    /* @4866412 cast */
    /* @4866416 constant */
    /* @4866420 load */
    /* @4866428 cast */
    /* @4866432 load */
    /* @4866440 constant */
    /* @4866444 add */
    /* @4866448 constant */
    /* @4866452 load */
    /* @4866460 cast */
    /* @4866464 load */
    /* @4866472 constant */
    /* @4866476 add */
    /* @4866480 call */
    GM_SITE(vm, 570, 4866480);
    v49 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v50 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4866488 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v49, v50, STR_REF(1048)));
    /* @4866492 string */
    /* @4866500 cast */
    /* @4866504 constant */
    /* @4866508 load */
    /* @4866516 cast */
    /* @4866520 load */
    /* @4866528 constant */
    /* @4866532 add */
    /* @4866536 constant */
    /* @4866540 load */
    /* @4866548 cast */
    /* @4866552 load */
    /* @4866560 constant */
    /* @4866564 add */
    /* @4866568 call */
    GM_SITE(vm, 570, 4866568);
    v51 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v52 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4866576 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v51, v52, STR_REF(1049)));
    L_4866580: ;
    /* @4866580 load */
    /* @4866588 constant */
    /* @4866592 cmp */
    /* @4866596 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4866820;
    /* @4866600 constant */
    /* @4866604 cast */
    /* @4866608 call */
    GM_SITE(vm, 570, 4866608);
    /* @4866616 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4866620 constant */
    /* @4866628 cast */
    /* @4866632 call */
    GM_SITE(vm, 570, 4866632);
    /* @4866640 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4866644 string */
    /* @4866652 cast */
    /* @4866656 constant */
    /* @4866660 load */
    /* @4866668 cast */
    /* @4866672 load */
    /* @4866680 constant */
    /* @4866684 add */
    /* @4866688 constant */
    /* @4866692 load */
    /* @4866700 cast */
    /* @4866704 load */
    /* @4866712 constant */
    /* @4866716 add */
    /* @4866720 call */
    GM_SITE(vm, 570, 4866720);
    v53 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v54 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4866728 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v53, v54, STR_REF(1048)));
    /* @4866732 string */
    /* @4866740 cast */
    /* @4866744 constant */
    /* @4866748 load */
    /* @4866756 cast */
    /* @4866760 load */
    /* @4866768 constant */
    /* @4866772 add */
    /* @4866776 constant */
    /* @4866780 load */
    /* @4866788 cast */
    /* @4866792 load */
    /* @4866800 constant */
    /* @4866804 add */
    /* @4866808 call */
    GM_SITE(vm, 570, 4866808);
    v55 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v56 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4866816 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v55, v56, STR_REF(1049)));
    L_4866820: ;
    /* @4866820 load */
    /* @4866828 constant */
    /* @4866832 cmp */
    /* @4866836 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4867060;
    /* @4866840 constant */
    /* @4866844 cast */
    /* @4866848 call */
    GM_SITE(vm, 570, 4866848);
    /* @4866856 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4866860 constant */
    /* @4866868 cast */
    /* @4866872 call */
    GM_SITE(vm, 570, 4866872);
    /* @4866880 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4866884 string */
    /* @4866892 cast */
    /* @4866896 constant */
    /* @4866900 load */
    /* @4866908 cast */
    /* @4866912 load */
    /* @4866920 constant */
    /* @4866924 add */
    /* @4866928 constant */
    /* @4866932 load */
    /* @4866940 cast */
    /* @4866944 load */
    /* @4866952 constant */
    /* @4866956 add */
    /* @4866960 call */
    GM_SITE(vm, 570, 4866960);
    v57 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v58 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4866968 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v57, v58, STR_REF(1048)));
    /* @4866972 string */
    /* @4866980 cast */
    /* @4866984 constant */
    /* @4866988 load */
    /* @4866996 cast */
    /* @4867000 load */
    /* @4867008 constant */
    /* @4867012 add */
    /* @4867016 constant */
    /* @4867020 load */
    /* @4867028 cast */
    /* @4867032 load */
    /* @4867040 constant */
    /* @4867044 add */
    /* @4867048 call */
    GM_SITE(vm, 570, 4867048);
    v59 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v60 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4867056 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v59, v60, STR_REF(1049)));
    L_4867060: ;
    /* @4867060 load */
    /* @4867068 constant */
    /* @4867072 cmp */
    /* @4867076 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel2") == VAL(1)))) goto L_4868520;
    /* @4867080 load */
    /* @4867088 constant */
    /* @4867092 cmp */
    /* @4867096 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4867320;
    /* @4867100 constant */
    /* @4867104 cast */
    /* @4867108 call */
    GM_SITE(vm, 570, 4867108);
    /* @4867116 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4867120 constant */
    /* @4867128 cast */
    /* @4867132 call */
    GM_SITE(vm, 570, 4867132);
    /* @4867140 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4867144 string */
    /* @4867152 cast */
    /* @4867156 constant */
    /* @4867160 load */
    /* @4867168 cast */
    /* @4867172 load */
    /* @4867180 constant */
    /* @4867184 add */
    /* @4867188 constant */
    /* @4867192 load */
    /* @4867200 cast */
    /* @4867204 load */
    /* @4867212 constant */
    /* @4867216 add */
    /* @4867220 call */
    GM_SITE(vm, 570, 4867220);
    v61 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v62 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4867228 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v61, v62, STR_REF(1050)));
    /* @4867232 string */
    /* @4867240 cast */
    /* @4867244 constant */
    /* @4867248 load */
    /* @4867256 cast */
    /* @4867260 load */
    /* @4867268 constant */
    /* @4867272 add */
    /* @4867276 constant */
    /* @4867280 load */
    /* @4867288 cast */
    /* @4867292 load */
    /* @4867300 constant */
    /* @4867304 add */
    /* @4867308 call */
    GM_SITE(vm, 570, 4867308);
    v63 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v64 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4867316 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v63, v64, STR_REF(1051)));
    L_4867320: ;
    /* @4867320 load */
    /* @4867328 constant */
    /* @4867332 cmp */
    /* @4867336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4867560;
    /* @4867340 constant */
    /* @4867344 cast */
    /* @4867348 call */
    GM_SITE(vm, 570, 4867348);
    /* @4867356 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4867360 constant */
    /* @4867368 cast */
    /* @4867372 call */
    GM_SITE(vm, 570, 4867372);
    /* @4867380 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4867384 string */
    /* @4867392 cast */
    /* @4867396 constant */
    /* @4867400 load */
    /* @4867408 cast */
    /* @4867412 load */
    /* @4867420 constant */
    /* @4867424 add */
    /* @4867428 constant */
    /* @4867432 load */
    /* @4867440 cast */
    /* @4867444 load */
    /* @4867452 constant */
    /* @4867456 add */
    /* @4867460 call */
    GM_SITE(vm, 570, 4867460);
    v65 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v66 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4867468 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v65, v66, STR_REF(1050)));
    /* @4867472 string */
    /* @4867480 cast */
    /* @4867484 constant */
    /* @4867488 load */
    /* @4867496 cast */
    /* @4867500 load */
    /* @4867508 constant */
    /* @4867512 add */
    /* @4867516 constant */
    /* @4867520 load */
    /* @4867528 cast */
    /* @4867532 load */
    /* @4867540 constant */
    /* @4867544 add */
    /* @4867548 call */
    GM_SITE(vm, 570, 4867548);
    v67 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v68 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4867556 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v67, v68, STR_REF(1051)));
    L_4867560: ;
    /* @4867560 load */
    /* @4867568 constant */
    /* @4867572 cmp */
    /* @4867576 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4867800;
    /* @4867580 constant */
    /* @4867584 cast */
    /* @4867588 call */
    GM_SITE(vm, 570, 4867588);
    /* @4867596 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4867600 constant */
    /* @4867608 cast */
    /* @4867612 call */
    GM_SITE(vm, 570, 4867612);
    /* @4867620 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4867624 string */
    /* @4867632 cast */
    /* @4867636 constant */
    /* @4867640 load */
    /* @4867648 cast */
    /* @4867652 load */
    /* @4867660 constant */
    /* @4867664 add */
    /* @4867668 constant */
    /* @4867672 load */
    /* @4867680 cast */
    /* @4867684 load */
    /* @4867692 constant */
    /* @4867696 add */
    /* @4867700 call */
    GM_SITE(vm, 570, 4867700);
    v69 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v70 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4867708 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v69, v70, STR_REF(1050)));
    /* @4867712 string */
    /* @4867720 cast */
    /* @4867724 constant */
    /* @4867728 load */
    /* @4867736 cast */
    /* @4867740 load */
    /* @4867748 constant */
    /* @4867752 add */
    /* @4867756 constant */
    /* @4867760 load */
    /* @4867768 cast */
    /* @4867772 load */
    /* @4867780 constant */
    /* @4867784 add */
    /* @4867788 call */
    GM_SITE(vm, 570, 4867788);
    v71 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v72 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4867796 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v71, v72, STR_REF(1051)));
    L_4867800: ;
    /* @4867800 load */
    /* @4867808 constant */
    /* @4867812 cmp */
    /* @4867816 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4868040;
    /* @4867820 constant */
    /* @4867824 cast */
    /* @4867828 call */
    GM_SITE(vm, 570, 4867828);
    /* @4867836 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4867840 constant */
    /* @4867848 cast */
    /* @4867852 call */
    GM_SITE(vm, 570, 4867852);
    /* @4867860 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4867864 string */
    /* @4867872 cast */
    /* @4867876 constant */
    /* @4867880 load */
    /* @4867888 cast */
    /* @4867892 load */
    /* @4867900 constant */
    /* @4867904 add */
    /* @4867908 constant */
    /* @4867912 load */
    /* @4867920 cast */
    /* @4867924 load */
    /* @4867932 constant */
    /* @4867936 add */
    /* @4867940 call */
    GM_SITE(vm, 570, 4867940);
    v73 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v74 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4867948 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v73, v74, STR_REF(1050)));
    /* @4867952 string */
    /* @4867960 cast */
    /* @4867964 constant */
    /* @4867968 load */
    /* @4867976 cast */
    /* @4867980 load */
    /* @4867988 constant */
    /* @4867992 add */
    /* @4867996 constant */
    /* @4868000 load */
    /* @4868008 cast */
    /* @4868012 load */
    /* @4868020 constant */
    /* @4868024 add */
    /* @4868028 call */
    GM_SITE(vm, 570, 4868028);
    v75 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v76 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4868036 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v75, v76, STR_REF(1051)));
    L_4868040: ;
    /* @4868040 load */
    /* @4868048 constant */
    /* @4868052 cmp */
    /* @4868056 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4868280;
    /* @4868060 constant */
    /* @4868064 cast */
    /* @4868068 call */
    GM_SITE(vm, 570, 4868068);
    /* @4868076 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4868080 constant */
    /* @4868088 cast */
    /* @4868092 call */
    GM_SITE(vm, 570, 4868092);
    /* @4868100 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4868104 string */
    /* @4868112 cast */
    /* @4868116 constant */
    /* @4868120 load */
    /* @4868128 cast */
    /* @4868132 load */
    /* @4868140 constant */
    /* @4868144 add */
    /* @4868148 constant */
    /* @4868152 load */
    /* @4868160 cast */
    /* @4868164 load */
    /* @4868172 constant */
    /* @4868176 add */
    /* @4868180 call */
    GM_SITE(vm, 570, 4868180);
    v77 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v78 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4868188 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v77, v78, STR_REF(1050)));
    /* @4868192 string */
    /* @4868200 cast */
    /* @4868204 constant */
    /* @4868208 load */
    /* @4868216 cast */
    /* @4868220 load */
    /* @4868228 constant */
    /* @4868232 add */
    /* @4868236 constant */
    /* @4868240 load */
    /* @4868248 cast */
    /* @4868252 load */
    /* @4868260 constant */
    /* @4868264 add */
    /* @4868268 call */
    GM_SITE(vm, 570, 4868268);
    v79 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v80 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4868276 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v79, v80, STR_REF(1051)));
    L_4868280: ;
    /* @4868280 load */
    /* @4868288 constant */
    /* @4868292 cmp */
    /* @4868296 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4868520;
    /* @4868300 constant */
    /* @4868304 cast */
    /* @4868308 call */
    GM_SITE(vm, 570, 4868308);
    /* @4868316 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4868320 constant */
    /* @4868328 cast */
    /* @4868332 call */
    GM_SITE(vm, 570, 4868332);
    /* @4868340 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4868344 string */
    /* @4868352 cast */
    /* @4868356 constant */
    /* @4868360 load */
    /* @4868368 cast */
    /* @4868372 load */
    /* @4868380 constant */
    /* @4868384 add */
    /* @4868388 constant */
    /* @4868392 load */
    /* @4868400 cast */
    /* @4868404 load */
    /* @4868412 constant */
    /* @4868416 add */
    /* @4868420 call */
    GM_SITE(vm, 570, 4868420);
    v81 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v82 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4868428 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v81, v82, STR_REF(1050)));
    /* @4868432 string */
    /* @4868440 cast */
    /* @4868444 constant */
    /* @4868448 load */
    /* @4868456 cast */
    /* @4868460 load */
    /* @4868468 constant */
    /* @4868472 add */
    /* @4868476 constant */
    /* @4868480 load */
    /* @4868488 cast */
    /* @4868492 load */
    /* @4868500 constant */
    /* @4868504 add */
    /* @4868508 call */
    GM_SITE(vm, 570, 4868508);
    v83 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v84 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4868516 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v83, v84, STR_REF(1051)));
    L_4868520: ;
    /* @4868520 load */
    /* @4868528 constant */
    /* @4868532 cmp */
    /* @4868536 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel3") == VAL(1)))) goto L_4869980;
    /* @4868540 load */
    /* @4868548 constant */
    /* @4868552 cmp */
    /* @4868556 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4868780;
    /* @4868560 constant */
    /* @4868564 cast */
    /* @4868568 call */
    GM_SITE(vm, 570, 4868568);
    /* @4868576 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4868580 constant */
    /* @4868588 cast */
    /* @4868592 call */
    GM_SITE(vm, 570, 4868592);
    /* @4868600 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4868604 string */
    /* @4868612 cast */
    /* @4868616 constant */
    /* @4868620 load */
    /* @4868628 cast */
    /* @4868632 load */
    /* @4868640 constant */
    /* @4868644 add */
    /* @4868648 constant */
    /* @4868652 load */
    /* @4868660 cast */
    /* @4868664 load */
    /* @4868672 constant */
    /* @4868676 add */
    /* @4868680 call */
    GM_SITE(vm, 570, 4868680);
    v85 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v86 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4868688 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v85, v86, STR_REF(1052)));
    /* @4868692 string */
    /* @4868700 cast */
    /* @4868704 constant */
    /* @4868708 load */
    /* @4868716 cast */
    /* @4868720 load */
    /* @4868728 constant */
    /* @4868732 add */
    /* @4868736 constant */
    /* @4868740 load */
    /* @4868748 cast */
    /* @4868752 load */
    /* @4868760 constant */
    /* @4868764 add */
    /* @4868768 call */
    GM_SITE(vm, 570, 4868768);
    v87 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v88 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4868776 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v87, v88, STR_REF(1053)));
    L_4868780: ;
    /* @4868780 load */
    /* @4868788 constant */
    /* @4868792 cmp */
    /* @4868796 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4869020;
    /* @4868800 constant */
    /* @4868804 cast */
    /* @4868808 call */
    GM_SITE(vm, 570, 4868808);
    /* @4868816 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4868820 constant */
    /* @4868828 cast */
    /* @4868832 call */
    GM_SITE(vm, 570, 4868832);
    /* @4868840 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4868844 string */
    /* @4868852 cast */
    /* @4868856 constant */
    /* @4868860 load */
    /* @4868868 cast */
    /* @4868872 load */
    /* @4868880 constant */
    /* @4868884 add */
    /* @4868888 constant */
    /* @4868892 load */
    /* @4868900 cast */
    /* @4868904 load */
    /* @4868912 constant */
    /* @4868916 add */
    /* @4868920 call */
    GM_SITE(vm, 570, 4868920);
    v89 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v90 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4868928 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v89, v90, STR_REF(1052)));
    /* @4868932 string */
    /* @4868940 cast */
    /* @4868944 constant */
    /* @4868948 load */
    /* @4868956 cast */
    /* @4868960 load */
    /* @4868968 constant */
    /* @4868972 add */
    /* @4868976 constant */
    /* @4868980 load */
    /* @4868988 cast */
    /* @4868992 load */
    /* @4869000 constant */
    /* @4869004 add */
    /* @4869008 call */
    GM_SITE(vm, 570, 4869008);
    v91 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v92 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4869016 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v91, v92, STR_REF(1053)));
    L_4869020: ;
    /* @4869020 load */
    /* @4869028 constant */
    /* @4869032 cmp */
    /* @4869036 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4869260;
    /* @4869040 constant */
    /* @4869044 cast */
    /* @4869048 call */
    GM_SITE(vm, 570, 4869048);
    /* @4869056 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4869060 constant */
    /* @4869068 cast */
    /* @4869072 call */
    GM_SITE(vm, 570, 4869072);
    /* @4869080 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4869084 string */
    /* @4869092 cast */
    /* @4869096 constant */
    /* @4869100 load */
    /* @4869108 cast */
    /* @4869112 load */
    /* @4869120 constant */
    /* @4869124 add */
    /* @4869128 constant */
    /* @4869132 load */
    /* @4869140 cast */
    /* @4869144 load */
    /* @4869152 constant */
    /* @4869156 add */
    /* @4869160 call */
    GM_SITE(vm, 570, 4869160);
    v93 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v94 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4869168 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v93, v94, STR_REF(1052)));
    /* @4869172 string */
    /* @4869180 cast */
    /* @4869184 constant */
    /* @4869188 load */
    /* @4869196 cast */
    /* @4869200 load */
    /* @4869208 constant */
    /* @4869212 add */
    /* @4869216 constant */
    /* @4869220 load */
    /* @4869228 cast */
    /* @4869232 load */
    /* @4869240 constant */
    /* @4869244 add */
    /* @4869248 call */
    GM_SITE(vm, 570, 4869248);
    v95 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v96 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4869256 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v95, v96, STR_REF(1053)));
    L_4869260: ;
    /* @4869260 load */
    /* @4869268 constant */
    /* @4869272 cmp */
    /* @4869276 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4869500;
    /* @4869280 constant */
    /* @4869284 cast */
    /* @4869288 call */
    GM_SITE(vm, 570, 4869288);
    /* @4869296 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4869300 constant */
    /* @4869308 cast */
    /* @4869312 call */
    GM_SITE(vm, 570, 4869312);
    /* @4869320 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4869324 string */
    /* @4869332 cast */
    /* @4869336 constant */
    /* @4869340 load */
    /* @4869348 cast */
    /* @4869352 load */
    /* @4869360 constant */
    /* @4869364 add */
    /* @4869368 constant */
    /* @4869372 load */
    /* @4869380 cast */
    /* @4869384 load */
    /* @4869392 constant */
    /* @4869396 add */
    /* @4869400 call */
    GM_SITE(vm, 570, 4869400);
    v97 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v98 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4869408 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v97, v98, STR_REF(1052)));
    /* @4869412 string */
    /* @4869420 cast */
    /* @4869424 constant */
    /* @4869428 load */
    /* @4869436 cast */
    /* @4869440 load */
    /* @4869448 constant */
    /* @4869452 add */
    /* @4869456 constant */
    /* @4869460 load */
    /* @4869468 cast */
    /* @4869472 load */
    /* @4869480 constant */
    /* @4869484 add */
    /* @4869488 call */
    GM_SITE(vm, 570, 4869488);
    v99 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v100 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4869496 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v99, v100, STR_REF(1053)));
    L_4869500: ;
    /* @4869500 load */
    /* @4869508 constant */
    /* @4869512 cmp */
    /* @4869516 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4869740;
    /* @4869520 constant */
    /* @4869524 cast */
    /* @4869528 call */
    GM_SITE(vm, 570, 4869528);
    /* @4869536 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4869540 constant */
    /* @4869548 cast */
    /* @4869552 call */
    GM_SITE(vm, 570, 4869552);
    /* @4869560 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4869564 string */
    /* @4869572 cast */
    /* @4869576 constant */
    /* @4869580 load */
    /* @4869588 cast */
    /* @4869592 load */
    /* @4869600 constant */
    /* @4869604 add */
    /* @4869608 constant */
    /* @4869612 load */
    /* @4869620 cast */
    /* @4869624 load */
    /* @4869632 constant */
    /* @4869636 add */
    /* @4869640 call */
    GM_SITE(vm, 570, 4869640);
    v101 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v102 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4869648 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v101, v102, STR_REF(1052)));
    /* @4869652 string */
    /* @4869660 cast */
    /* @4869664 constant */
    /* @4869668 load */
    /* @4869676 cast */
    /* @4869680 load */
    /* @4869688 constant */
    /* @4869692 add */
    /* @4869696 constant */
    /* @4869700 load */
    /* @4869708 cast */
    /* @4869712 load */
    /* @4869720 constant */
    /* @4869724 add */
    /* @4869728 call */
    GM_SITE(vm, 570, 4869728);
    v103 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v104 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4869736 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v103, v104, STR_REF(1053)));
    L_4869740: ;
    /* @4869740 load */
    /* @4869748 constant */
    /* @4869752 cmp */
    /* @4869756 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4869980;
    /* @4869760 constant */
    /* @4869764 cast */
    /* @4869768 call */
    GM_SITE(vm, 570, 4869768);
    /* @4869776 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4869780 constant */
    /* @4869788 cast */
    /* @4869792 call */
    GM_SITE(vm, 570, 4869792);
    /* @4869800 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4869804 string */
    /* @4869812 cast */
    /* @4869816 constant */
    /* @4869820 load */
    /* @4869828 cast */
    /* @4869832 load */
    /* @4869840 constant */
    /* @4869844 add */
    /* @4869848 constant */
    /* @4869852 load */
    /* @4869860 cast */
    /* @4869864 load */
    /* @4869872 constant */
    /* @4869876 add */
    /* @4869880 call */
    GM_SITE(vm, 570, 4869880);
    v105 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v106 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4869888 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v105, v106, STR_REF(1052)));
    /* @4869892 string */
    /* @4869900 cast */
    /* @4869904 constant */
    /* @4869908 load */
    /* @4869916 cast */
    /* @4869920 load */
    /* @4869928 constant */
    /* @4869932 add */
    /* @4869936 constant */
    /* @4869940 load */
    /* @4869948 cast */
    /* @4869952 load */
    /* @4869960 constant */
    /* @4869964 add */
    /* @4869968 call */
    GM_SITE(vm, 570, 4869968);
    v107 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v108 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4869976 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v107, v108, STR_REF(1053)));
    L_4869980: ;
    /* @4869980 load */
    /* @4869988 constant */
    /* @4869992 cmp */
    /* @4869996 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4870032;
    /* @4870000 constant */
    /* @4870004 cast */
    /* @4870008 constant */
    /* @4870012 cast */
    /* @4870016 call */
    GM_SITE(vm, 570, 4870016);
    /* @4870024 cast */
    /* @4870028 b */
    v109 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, VAL(0), VAL(1)));
    p4870036_0 = v109;
    goto L_4870036;
    L_4870032: ;
    /* @4870032 constant */
    p4870036_0 = VAL(0);
    L_4870036: ;
    /* @4870036 bf */
    if (!TRUTH(p4870036_0)) goto L_4870052;
    /* @4870040 call */
    GM_SITE(vm, 570, 4870040);
    /* @4870048 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4870052: ;
    return;
}
