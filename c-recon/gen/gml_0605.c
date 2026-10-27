/* generated from CODE 605 (gml_Object_obj_lloydtutorial7_Draw_0), source start 4911712, end 4920044. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0605(GmVM* vm) {
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
    Val p4920028_0;
    Val v121;
    /* @4911712 constant */
    /* @4911716 load */
    /* @4911724 cast */
    /* @4911728 load */
    /* @4911736 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4911744 constant */
    /* @4911748 load */
    /* @4911756 cast */
    /* @4911760 load */
    /* @4911768 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4911776 load */
    /* @4911784 constant */
    /* @4911788 cmp */
    /* @4911792 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4912320;
    /* @4911796 constant */
    /* @4911800 cast */
    /* @4911804 constant */
    /* @4911808 cast */
    /* @4911812 constant */
    /* @4911816 cast */
    /* @4911820 constant */
    /* @4911832 cast */
    /* @4911836 constant */
    /* @4911848 cast */
    /* @4911852 constant */
    /* @4911856 constant */
    /* @4911860 load */
    /* @4911868 constant */
    /* @4911872 constant */
    /* @4911876 load */
    /* @4911884 constant */
    /* @4911888 sub */
    /* @4911892 constant */
    /* @4911896 cast */
    /* @4911900 constant */
    /* @4911904 cast */
    /* @4911908 call */
    GM_SITE(vm, 605, 4911908);
    /* @4911916 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(0.96), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4911920 constant */
    /* @4911924 cast */
    /* @4911928 constant */
    /* @4911932 cast */
    /* @4911936 constant */
    /* @4911940 cast */
    /* @4911944 constant */
    /* @4911948 cast */
    /* @4911952 constant */
    /* @4911956 cast */
    /* @4911960 constant */
    /* @4911964 load */
    /* @4911972 cast */
    /* @4911976 load */
    /* @4911984 constant */
    /* @4911988 add */
    /* @4911992 constant */
    /* @4911996 load */
    /* @4912004 cast */
    /* @4912008 load */
    /* @4912016 constant */
    /* @4912020 add */
    /* @4912024 constant */
    /* @4912028 cast */
    /* @4912032 constant */
    /* @4912036 cast */
    /* @4912040 call */
    GM_SITE(vm, 605, 4912040);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4912048 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v1, v2, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4912052 constant */
    /* @4912056 cast */
    /* @4912060 constant */
    /* @4912064 cast */
    /* @4912068 constant */
    /* @4912072 cast */
    /* @4912076 constant */
    /* @4912080 cast */
    /* @4912084 constant */
    /* @4912088 cast */
    /* @4912092 constant */
    /* @4912096 load */
    /* @4912104 cast */
    /* @4912108 load */
    /* @4912116 constant */
    /* @4912120 add */
    /* @4912124 constant */
    /* @4912128 load */
    /* @4912136 cast */
    /* @4912140 load */
    /* @4912148 constant */
    /* @4912152 add */
    /* @4912156 constant */
    /* @4912160 cast */
    /* @4912164 constant */
    /* @4912168 cast */
    /* @4912172 call */
    GM_SITE(vm, 605, 4912172);
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4912180 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v3, v4, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4912184 load */
    /* @4912192 constant */
    /* @4912196 cmp */
    /* @4912200 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4912320;
    /* @4912204 constant */
    /* @4912208 cast */
    /* @4912212 call */
    GM_SITE(vm, 605, 4912212);
    /* @4912220 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4912224 constant */
    /* @4912232 cast */
    /* @4912236 call */
    GM_SITE(vm, 605, 4912236);
    /* @4912244 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4912248 string */
    /* @4912256 cast */
    /* @4912260 constant */
    /* @4912264 constant */
    /* @4912268 load */
    /* @4912276 constant */
    /* @4912280 add */
    /* @4912284 constant */
    /* @4912288 constant */
    /* @4912292 load */
    /* @4912300 constant */
    /* @4912304 add */
    /* @4912308 call */
    GM_SITE(vm, 605, 4912308);
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(150));
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(200));
    /* @4912316 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v5, v6, STR_REF(743)));
    L_4912320: ;
    /* @4912320 load */
    /* @4912328 constant */
    /* @4912332 cmp */
    /* @4912336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4912864;
    /* @4912340 constant */
    /* @4912344 cast */
    /* @4912348 constant */
    /* @4912352 cast */
    /* @4912356 constant */
    /* @4912360 cast */
    /* @4912364 constant */
    /* @4912376 cast */
    /* @4912380 constant */
    /* @4912392 cast */
    /* @4912396 constant */
    /* @4912400 constant */
    /* @4912404 load */
    /* @4912412 constant */
    /* @4912416 constant */
    /* @4912420 load */
    /* @4912428 constant */
    /* @4912432 sub */
    /* @4912436 constant */
    /* @4912440 cast */
    /* @4912444 constant */
    /* @4912448 cast */
    /* @4912452 call */
    GM_SITE(vm, 605, 4912452);
    /* @4912460 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(0.82), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4912464 constant */
    /* @4912468 cast */
    /* @4912472 constant */
    /* @4912476 cast */
    /* @4912480 constant */
    /* @4912484 cast */
    /* @4912488 constant */
    /* @4912492 cast */
    /* @4912496 constant */
    /* @4912500 cast */
    /* @4912504 constant */
    /* @4912508 load */
    /* @4912516 cast */
    /* @4912520 load */
    /* @4912528 constant */
    /* @4912532 add */
    /* @4912536 constant */
    /* @4912540 load */
    /* @4912548 cast */
    /* @4912552 load */
    /* @4912560 constant */
    /* @4912564 add */
    /* @4912568 constant */
    /* @4912572 cast */
    /* @4912576 constant */
    /* @4912580 cast */
    /* @4912584 call */
    GM_SITE(vm, 605, 4912584);
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4912592 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v7, v8, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4912596 constant */
    /* @4912600 cast */
    /* @4912604 constant */
    /* @4912608 cast */
    /* @4912612 constant */
    /* @4912616 cast */
    /* @4912620 constant */
    /* @4912624 cast */
    /* @4912628 constant */
    /* @4912632 cast */
    /* @4912636 constant */
    /* @4912640 load */
    /* @4912648 cast */
    /* @4912652 load */
    /* @4912660 constant */
    /* @4912664 add */
    /* @4912668 constant */
    /* @4912672 load */
    /* @4912680 cast */
    /* @4912684 load */
    /* @4912692 constant */
    /* @4912696 add */
    /* @4912700 constant */
    /* @4912704 cast */
    /* @4912708 constant */
    /* @4912712 cast */
    /* @4912716 call */
    GM_SITE(vm, 605, 4912716);
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(320));
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4912724 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v9, v10, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4912728 load */
    /* @4912736 constant */
    /* @4912740 cmp */
    /* @4912744 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4912864;
    /* @4912748 constant */
    /* @4912752 cast */
    /* @4912756 call */
    GM_SITE(vm, 605, 4912756);
    /* @4912764 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4912768 constant */
    /* @4912776 cast */
    /* @4912780 call */
    GM_SITE(vm, 605, 4912780);
    /* @4912788 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4912792 string */
    /* @4912800 cast */
    /* @4912804 constant */
    /* @4912808 constant */
    /* @4912812 load */
    /* @4912820 constant */
    /* @4912824 add */
    /* @4912828 constant */
    /* @4912832 constant */
    /* @4912836 load */
    /* @4912844 constant */
    /* @4912848 add */
    /* @4912852 call */
    GM_SITE(vm, 605, 4912852);
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(110));
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4912860 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v11, v12, STR_REF(743)));
    L_4912864: ;
    /* @4912864 load */
    /* @4912872 constant */
    /* @4912876 cmp */
    /* @4912880 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4913408;
    /* @4912884 constant */
    /* @4912888 cast */
    /* @4912892 constant */
    /* @4912896 cast */
    /* @4912900 constant */
    /* @4912904 cast */
    /* @4912908 constant */
    /* @4912920 cast */
    /* @4912924 constant */
    /* @4912936 cast */
    /* @4912940 constant */
    /* @4912944 constant */
    /* @4912948 load */
    /* @4912956 constant */
    /* @4912960 constant */
    /* @4912964 load */
    /* @4912972 constant */
    /* @4912976 sub */
    /* @4912980 constant */
    /* @4912984 cast */
    /* @4912988 constant */
    /* @4912992 cast */
    /* @4912996 call */
    GM_SITE(vm, 605, 4912996);
    /* @4913004 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4913008 constant */
    /* @4913012 cast */
    /* @4913016 constant */
    /* @4913020 cast */
    /* @4913024 constant */
    /* @4913028 cast */
    /* @4913032 constant */
    /* @4913036 cast */
    /* @4913040 constant */
    /* @4913044 cast */
    /* @4913048 constant */
    /* @4913052 load */
    /* @4913060 cast */
    /* @4913064 load */
    /* @4913072 constant */
    /* @4913076 add */
    /* @4913080 constant */
    /* @4913084 load */
    /* @4913092 cast */
    /* @4913096 load */
    /* @4913104 constant */
    /* @4913108 add */
    /* @4913112 constant */
    /* @4913116 cast */
    /* @4913120 constant */
    /* @4913124 cast */
    /* @4913128 call */
    GM_SITE(vm, 605, 4913128);
    v13 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4913136 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v13, v14, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4913140 constant */
    /* @4913144 cast */
    /* @4913148 constant */
    /* @4913152 cast */
    /* @4913156 constant */
    /* @4913160 cast */
    /* @4913164 constant */
    /* @4913168 cast */
    /* @4913172 constant */
    /* @4913176 cast */
    /* @4913180 constant */
    /* @4913184 load */
    /* @4913192 cast */
    /* @4913196 load */
    /* @4913204 constant */
    /* @4913208 add */
    /* @4913212 constant */
    /* @4913216 load */
    /* @4913224 cast */
    /* @4913228 load */
    /* @4913236 constant */
    /* @4913240 add */
    /* @4913244 constant */
    /* @4913248 cast */
    /* @4913252 constant */
    /* @4913256 cast */
    /* @4913260 call */
    GM_SITE(vm, 605, 4913260);
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4913268 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v15, v16, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4913272 load */
    /* @4913280 constant */
    /* @4913284 cmp */
    /* @4913288 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4913408;
    /* @4913292 constant */
    /* @4913296 cast */
    /* @4913300 call */
    GM_SITE(vm, 605, 4913300);
    /* @4913308 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4913312 constant */
    /* @4913320 cast */
    /* @4913324 call */
    GM_SITE(vm, 605, 4913324);
    /* @4913332 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4913336 string */
    /* @4913344 cast */
    /* @4913348 constant */
    /* @4913352 constant */
    /* @4913356 load */
    /* @4913364 constant */
    /* @4913368 add */
    /* @4913372 constant */
    /* @4913376 constant */
    /* @4913380 load */
    /* @4913388 constant */
    /* @4913392 add */
    /* @4913396 call */
    GM_SITE(vm, 605, 4913396);
    v17 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(180));
    v18 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(300));
    /* @4913404 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v17, v18, STR_REF(743)));
    L_4913408: ;
    /* @4913408 load */
    /* @4913416 constant */
    /* @4913420 cmp */
    /* @4913424 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4913952;
    /* @4913428 constant */
    /* @4913432 cast */
    /* @4913436 constant */
    /* @4913440 cast */
    /* @4913444 constant */
    /* @4913448 cast */
    /* @4913452 constant */
    /* @4913464 cast */
    /* @4913468 constant */
    /* @4913480 cast */
    /* @4913484 constant */
    /* @4913488 constant */
    /* @4913492 load */
    /* @4913500 constant */
    /* @4913504 constant */
    /* @4913508 load */
    /* @4913516 constant */
    /* @4913520 sub */
    /* @4913524 constant */
    /* @4913528 cast */
    /* @4913532 constant */
    /* @4913536 cast */
    /* @4913540 call */
    GM_SITE(vm, 605, 4913540);
    /* @4913548 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4913552 constant */
    /* @4913556 cast */
    /* @4913560 constant */
    /* @4913564 cast */
    /* @4913568 constant */
    /* @4913572 cast */
    /* @4913576 constant */
    /* @4913580 cast */
    /* @4913584 constant */
    /* @4913588 cast */
    /* @4913592 constant */
    /* @4913596 load */
    /* @4913604 cast */
    /* @4913608 load */
    /* @4913616 constant */
    /* @4913620 add */
    /* @4913624 constant */
    /* @4913628 load */
    /* @4913636 cast */
    /* @4913640 load */
    /* @4913648 constant */
    /* @4913652 add */
    /* @4913656 constant */
    /* @4913660 cast */
    /* @4913664 constant */
    /* @4913668 cast */
    /* @4913672 call */
    GM_SITE(vm, 605, 4913672);
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4913680 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v19, v20, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4913684 constant */
    /* @4913688 cast */
    /* @4913692 constant */
    /* @4913696 cast */
    /* @4913700 constant */
    /* @4913704 cast */
    /* @4913708 constant */
    /* @4913712 cast */
    /* @4913716 constant */
    /* @4913720 cast */
    /* @4913724 constant */
    /* @4913728 load */
    /* @4913736 cast */
    /* @4913740 load */
    /* @4913748 constant */
    /* @4913752 add */
    /* @4913756 constant */
    /* @4913760 load */
    /* @4913768 cast */
    /* @4913772 load */
    /* @4913780 constant */
    /* @4913784 add */
    /* @4913788 constant */
    /* @4913792 cast */
    /* @4913796 constant */
    /* @4913800 cast */
    /* @4913804 call */
    GM_SITE(vm, 605, 4913804);
    v21 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4913812 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v21, v22, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4913816 load */
    /* @4913824 constant */
    /* @4913828 cmp */
    /* @4913832 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4913952;
    /* @4913836 constant */
    /* @4913840 cast */
    /* @4913844 call */
    GM_SITE(vm, 605, 4913844);
    /* @4913852 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4913856 constant */
    /* @4913864 cast */
    /* @4913868 call */
    GM_SITE(vm, 605, 4913868);
    /* @4913876 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4913880 string */
    /* @4913888 cast */
    /* @4913892 constant */
    /* @4913896 constant */
    /* @4913900 load */
    /* @4913908 constant */
    /* @4913912 add */
    /* @4913916 constant */
    /* @4913920 constant */
    /* @4913924 load */
    /* @4913932 constant */
    /* @4913936 add */
    /* @4913940 call */
    GM_SITE(vm, 605, 4913940);
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(180));
    v24 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(300));
    /* @4913948 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v23, v24, STR_REF(743)));
    L_4913952: ;
    /* @4913952 load */
    /* @4913960 constant */
    /* @4913964 cmp */
    /* @4913968 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4914496;
    /* @4913972 constant */
    /* @4913976 cast */
    /* @4913980 constant */
    /* @4913984 cast */
    /* @4913988 constant */
    /* @4913992 cast */
    /* @4913996 constant */
    /* @4914008 cast */
    /* @4914012 constant */
    /* @4914024 cast */
    /* @4914028 constant */
    /* @4914032 constant */
    /* @4914036 load */
    /* @4914044 constant */
    /* @4914048 constant */
    /* @4914052 load */
    /* @4914060 constant */
    /* @4914064 sub */
    /* @4914068 constant */
    /* @4914072 cast */
    /* @4914076 constant */
    /* @4914080 cast */
    /* @4914084 call */
    GM_SITE(vm, 605, 4914084);
    /* @4914092 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(0.97), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4914096 constant */
    /* @4914100 cast */
    /* @4914104 constant */
    /* @4914108 cast */
    /* @4914112 constant */
    /* @4914116 cast */
    /* @4914120 constant */
    /* @4914124 cast */
    /* @4914128 constant */
    /* @4914132 cast */
    /* @4914136 constant */
    /* @4914140 load */
    /* @4914148 cast */
    /* @4914152 load */
    /* @4914160 constant */
    /* @4914164 add */
    /* @4914168 constant */
    /* @4914172 load */
    /* @4914180 cast */
    /* @4914184 load */
    /* @4914192 constant */
    /* @4914196 add */
    /* @4914200 constant */
    /* @4914204 cast */
    /* @4914208 constant */
    /* @4914212 cast */
    /* @4914216 call */
    GM_SITE(vm, 605, 4914216);
    v25 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v26 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4914224 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v25, v26, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4914228 constant */
    /* @4914232 cast */
    /* @4914236 constant */
    /* @4914240 cast */
    /* @4914244 constant */
    /* @4914248 cast */
    /* @4914252 constant */
    /* @4914256 cast */
    /* @4914260 constant */
    /* @4914264 cast */
    /* @4914268 constant */
    /* @4914272 load */
    /* @4914280 cast */
    /* @4914284 load */
    /* @4914292 constant */
    /* @4914296 add */
    /* @4914300 constant */
    /* @4914304 load */
    /* @4914312 cast */
    /* @4914316 load */
    /* @4914324 constant */
    /* @4914328 add */
    /* @4914332 constant */
    /* @4914336 cast */
    /* @4914340 constant */
    /* @4914344 cast */
    /* @4914348 call */
    GM_SITE(vm, 605, 4914348);
    v27 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v28 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4914356 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v27, v28, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4914360 load */
    /* @4914368 constant */
    /* @4914372 cmp */
    /* @4914376 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4914496;
    /* @4914380 constant */
    /* @4914384 cast */
    /* @4914388 call */
    GM_SITE(vm, 605, 4914388);
    /* @4914396 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4914400 constant */
    /* @4914408 cast */
    /* @4914412 call */
    GM_SITE(vm, 605, 4914412);
    /* @4914420 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4914424 string */
    /* @4914432 cast */
    /* @4914436 constant */
    /* @4914440 constant */
    /* @4914444 load */
    /* @4914452 constant */
    /* @4914456 add */
    /* @4914460 constant */
    /* @4914464 constant */
    /* @4914468 load */
    /* @4914476 constant */
    /* @4914480 add */
    /* @4914484 call */
    GM_SITE(vm, 605, 4914484);
    v29 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(150));
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(200));
    /* @4914492 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v29, v30, STR_REF(743)));
    L_4914496: ;
    /* @4914496 load */
    /* @4914504 constant */
    /* @4914508 cmp */
    /* @4914512 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4915040;
    /* @4914516 constant */
    /* @4914520 cast */
    /* @4914524 constant */
    /* @4914528 cast */
    /* @4914532 constant */
    /* @4914536 cast */
    /* @4914540 constant */
    /* @4914552 cast */
    /* @4914556 constant */
    /* @4914568 cast */
    /* @4914572 constant */
    /* @4914576 constant */
    /* @4914580 load */
    /* @4914588 constant */
    /* @4914592 constant */
    /* @4914596 load */
    /* @4914604 constant */
    /* @4914608 sub */
    /* @4914612 constant */
    /* @4914616 cast */
    /* @4914620 constant */
    /* @4914624 cast */
    /* @4914628 call */
    GM_SITE(vm, 605, 4914628);
    /* @4914636 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(1.06), VAL(0.86), VAL(0), VAL(-1), VAL(1)));
    /* @4914640 constant */
    /* @4914644 cast */
    /* @4914648 constant */
    /* @4914652 cast */
    /* @4914656 constant */
    /* @4914660 cast */
    /* @4914664 constant */
    /* @4914668 cast */
    /* @4914672 constant */
    /* @4914676 cast */
    /* @4914680 constant */
    /* @4914684 load */
    /* @4914692 cast */
    /* @4914696 load */
    /* @4914704 constant */
    /* @4914708 add */
    /* @4914712 constant */
    /* @4914716 load */
    /* @4914724 cast */
    /* @4914728 load */
    /* @4914736 constant */
    /* @4914740 add */
    /* @4914744 constant */
    /* @4914748 cast */
    /* @4914752 constant */
    /* @4914756 cast */
    /* @4914760 call */
    GM_SITE(vm, 605, 4914760);
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v32 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4914768 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v31, v32, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4914772 constant */
    /* @4914776 cast */
    /* @4914780 constant */
    /* @4914784 cast */
    /* @4914788 constant */
    /* @4914792 cast */
    /* @4914796 constant */
    /* @4914800 cast */
    /* @4914804 constant */
    /* @4914808 cast */
    /* @4914812 constant */
    /* @4914816 load */
    /* @4914824 cast */
    /* @4914828 load */
    /* @4914836 constant */
    /* @4914840 add */
    /* @4914844 constant */
    /* @4914848 load */
    /* @4914856 cast */
    /* @4914860 load */
    /* @4914868 constant */
    /* @4914872 add */
    /* @4914876 constant */
    /* @4914880 cast */
    /* @4914884 constant */
    /* @4914888 cast */
    /* @4914892 call */
    GM_SITE(vm, 605, 4914892);
    v33 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(390));
    v34 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4914900 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v33, v34, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4914904 load */
    /* @4914912 constant */
    /* @4914916 cmp */
    /* @4914920 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4915040;
    /* @4914924 constant */
    /* @4914928 cast */
    /* @4914932 call */
    GM_SITE(vm, 605, 4914932);
    /* @4914940 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4914944 constant */
    /* @4914952 cast */
    /* @4914956 call */
    GM_SITE(vm, 605, 4914956);
    /* @4914964 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4914968 string */
    /* @4914976 cast */
    /* @4914980 constant */
    /* @4914984 constant */
    /* @4914988 load */
    /* @4914996 constant */
    /* @4915000 add */
    /* @4915004 constant */
    /* @4915008 constant */
    /* @4915012 load */
    /* @4915020 constant */
    /* @4915024 add */
    /* @4915028 call */
    GM_SITE(vm, 605, 4915028);
    v35 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(160));
    v36 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(200));
    /* @4915036 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v35, v36, STR_REF(743)));
    L_4915040: ;
    /* @4915040 load */
    /* @4915048 constant */
    /* @4915052 cmp */
    /* @4915056 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel1") == VAL(1)))) goto L_4916500;
    /* @4915060 load */
    /* @4915068 constant */
    /* @4915072 cmp */
    /* @4915076 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4915300;
    /* @4915080 constant */
    /* @4915084 cast */
    /* @4915088 call */
    GM_SITE(vm, 605, 4915088);
    /* @4915096 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4915100 constant */
    /* @4915108 cast */
    /* @4915112 call */
    GM_SITE(vm, 605, 4915112);
    /* @4915120 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4915124 string */
    /* @4915132 cast */
    /* @4915136 constant */
    /* @4915140 load */
    /* @4915148 cast */
    /* @4915152 load */
    /* @4915160 constant */
    /* @4915164 add */
    /* @4915168 constant */
    /* @4915172 load */
    /* @4915180 cast */
    /* @4915184 load */
    /* @4915192 constant */
    /* @4915196 add */
    /* @4915200 call */
    GM_SITE(vm, 605, 4915200);
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4915208 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v37, v38, STR_REF(1086)));
    /* @4915212 string */
    /* @4915220 cast */
    /* @4915224 constant */
    /* @4915228 load */
    /* @4915236 cast */
    /* @4915240 load */
    /* @4915248 constant */
    /* @4915252 add */
    /* @4915256 constant */
    /* @4915260 load */
    /* @4915268 cast */
    /* @4915272 load */
    /* @4915280 constant */
    /* @4915284 add */
    /* @4915288 call */
    GM_SITE(vm, 605, 4915288);
    v39 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v40 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4915296 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, v40, STR_REF(1087)));
    L_4915300: ;
    /* @4915300 load */
    /* @4915308 constant */
    /* @4915312 cmp */
    /* @4915316 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4915540;
    /* @4915320 constant */
    /* @4915324 cast */
    /* @4915328 call */
    GM_SITE(vm, 605, 4915328);
    /* @4915336 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4915340 constant */
    /* @4915348 cast */
    /* @4915352 call */
    GM_SITE(vm, 605, 4915352);
    /* @4915360 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4915364 string */
    /* @4915372 cast */
    /* @4915376 constant */
    /* @4915380 load */
    /* @4915388 cast */
    /* @4915392 load */
    /* @4915400 constant */
    /* @4915404 add */
    /* @4915408 constant */
    /* @4915412 load */
    /* @4915420 cast */
    /* @4915424 load */
    /* @4915432 constant */
    /* @4915436 add */
    /* @4915440 call */
    GM_SITE(vm, 605, 4915440);
    v41 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v42 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4915448 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v41, v42, STR_REF(1086)));
    /* @4915452 string */
    /* @4915460 cast */
    /* @4915464 constant */
    /* @4915468 load */
    /* @4915476 cast */
    /* @4915480 load */
    /* @4915488 constant */
    /* @4915492 add */
    /* @4915496 constant */
    /* @4915500 load */
    /* @4915508 cast */
    /* @4915512 load */
    /* @4915520 constant */
    /* @4915524 add */
    /* @4915528 call */
    GM_SITE(vm, 605, 4915528);
    v43 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v44 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4915536 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v43, v44, STR_REF(1087)));
    L_4915540: ;
    /* @4915540 load */
    /* @4915548 constant */
    /* @4915552 cmp */
    /* @4915556 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4915780;
    /* @4915560 constant */
    /* @4915564 cast */
    /* @4915568 call */
    GM_SITE(vm, 605, 4915568);
    /* @4915576 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4915580 constant */
    /* @4915588 cast */
    /* @4915592 call */
    GM_SITE(vm, 605, 4915592);
    /* @4915600 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4915604 string */
    /* @4915612 cast */
    /* @4915616 constant */
    /* @4915620 load */
    /* @4915628 cast */
    /* @4915632 load */
    /* @4915640 constant */
    /* @4915644 add */
    /* @4915648 constant */
    /* @4915652 load */
    /* @4915660 cast */
    /* @4915664 load */
    /* @4915672 constant */
    /* @4915676 add */
    /* @4915680 call */
    GM_SITE(vm, 605, 4915680);
    v45 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v46 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4915688 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v45, v46, STR_REF(1086)));
    /* @4915692 string */
    /* @4915700 cast */
    /* @4915704 constant */
    /* @4915708 load */
    /* @4915716 cast */
    /* @4915720 load */
    /* @4915728 constant */
    /* @4915732 add */
    /* @4915736 constant */
    /* @4915740 load */
    /* @4915748 cast */
    /* @4915752 load */
    /* @4915760 constant */
    /* @4915764 add */
    /* @4915768 call */
    GM_SITE(vm, 605, 4915768);
    v47 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v48 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4915776 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v47, v48, STR_REF(1087)));
    L_4915780: ;
    /* @4915780 load */
    /* @4915788 constant */
    /* @4915792 cmp */
    /* @4915796 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4916020;
    /* @4915800 constant */
    /* @4915804 cast */
    /* @4915808 call */
    GM_SITE(vm, 605, 4915808);
    /* @4915816 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4915820 constant */
    /* @4915828 cast */
    /* @4915832 call */
    GM_SITE(vm, 605, 4915832);
    /* @4915840 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4915844 string */
    /* @4915852 cast */
    /* @4915856 constant */
    /* @4915860 load */
    /* @4915868 cast */
    /* @4915872 load */
    /* @4915880 constant */
    /* @4915884 add */
    /* @4915888 constant */
    /* @4915892 load */
    /* @4915900 cast */
    /* @4915904 load */
    /* @4915912 constant */
    /* @4915916 add */
    /* @4915920 call */
    GM_SITE(vm, 605, 4915920);
    v49 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v50 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4915928 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v49, v50, STR_REF(1086)));
    /* @4915932 string */
    /* @4915940 cast */
    /* @4915944 constant */
    /* @4915948 load */
    /* @4915956 cast */
    /* @4915960 load */
    /* @4915968 constant */
    /* @4915972 add */
    /* @4915976 constant */
    /* @4915980 load */
    /* @4915988 cast */
    /* @4915992 load */
    /* @4916000 constant */
    /* @4916004 add */
    /* @4916008 call */
    GM_SITE(vm, 605, 4916008);
    v51 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v52 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4916016 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v51, v52, STR_REF(1087)));
    L_4916020: ;
    /* @4916020 load */
    /* @4916028 constant */
    /* @4916032 cmp */
    /* @4916036 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4916260;
    /* @4916040 constant */
    /* @4916044 cast */
    /* @4916048 call */
    GM_SITE(vm, 605, 4916048);
    /* @4916056 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4916060 constant */
    /* @4916068 cast */
    /* @4916072 call */
    GM_SITE(vm, 605, 4916072);
    /* @4916080 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4916084 string */
    /* @4916092 cast */
    /* @4916096 constant */
    /* @4916100 load */
    /* @4916108 cast */
    /* @4916112 load */
    /* @4916120 constant */
    /* @4916124 add */
    /* @4916128 constant */
    /* @4916132 load */
    /* @4916140 cast */
    /* @4916144 load */
    /* @4916152 constant */
    /* @4916156 add */
    /* @4916160 call */
    GM_SITE(vm, 605, 4916160);
    v53 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v54 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4916168 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v53, v54, STR_REF(1086)));
    /* @4916172 string */
    /* @4916180 cast */
    /* @4916184 constant */
    /* @4916188 load */
    /* @4916196 cast */
    /* @4916200 load */
    /* @4916208 constant */
    /* @4916212 add */
    /* @4916216 constant */
    /* @4916220 load */
    /* @4916228 cast */
    /* @4916232 load */
    /* @4916240 constant */
    /* @4916244 add */
    /* @4916248 call */
    GM_SITE(vm, 605, 4916248);
    v55 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v56 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4916256 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v55, v56, STR_REF(1087)));
    L_4916260: ;
    /* @4916260 load */
    /* @4916268 constant */
    /* @4916272 cmp */
    /* @4916276 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4916500;
    /* @4916280 constant */
    /* @4916284 cast */
    /* @4916288 call */
    GM_SITE(vm, 605, 4916288);
    /* @4916296 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4916300 constant */
    /* @4916308 cast */
    /* @4916312 call */
    GM_SITE(vm, 605, 4916312);
    /* @4916320 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4916324 string */
    /* @4916332 cast */
    /* @4916336 constant */
    /* @4916340 load */
    /* @4916348 cast */
    /* @4916352 load */
    /* @4916360 constant */
    /* @4916364 add */
    /* @4916368 constant */
    /* @4916372 load */
    /* @4916380 cast */
    /* @4916384 load */
    /* @4916392 constant */
    /* @4916396 add */
    /* @4916400 call */
    GM_SITE(vm, 605, 4916400);
    v57 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v58 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4916408 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v57, v58, STR_REF(1086)));
    /* @4916412 string */
    /* @4916420 cast */
    /* @4916424 constant */
    /* @4916428 load */
    /* @4916436 cast */
    /* @4916440 load */
    /* @4916448 constant */
    /* @4916452 add */
    /* @4916456 constant */
    /* @4916460 load */
    /* @4916468 cast */
    /* @4916472 load */
    /* @4916480 constant */
    /* @4916484 add */
    /* @4916488 call */
    GM_SITE(vm, 605, 4916488);
    v59 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v60 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4916496 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v59, v60, STR_REF(1087)));
    L_4916500: ;
    /* @4916500 load */
    /* @4916508 constant */
    /* @4916512 cmp */
    /* @4916516 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel2") == VAL(1)))) goto L_4917960;
    /* @4916520 load */
    /* @4916528 constant */
    /* @4916532 cmp */
    /* @4916536 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4916760;
    /* @4916540 constant */
    /* @4916544 cast */
    /* @4916548 call */
    GM_SITE(vm, 605, 4916548);
    /* @4916556 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4916560 constant */
    /* @4916568 cast */
    /* @4916572 call */
    GM_SITE(vm, 605, 4916572);
    /* @4916580 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4916584 string */
    /* @4916592 cast */
    /* @4916596 constant */
    /* @4916600 load */
    /* @4916608 cast */
    /* @4916612 load */
    /* @4916620 constant */
    /* @4916624 add */
    /* @4916628 constant */
    /* @4916632 load */
    /* @4916640 cast */
    /* @4916644 load */
    /* @4916652 constant */
    /* @4916656 add */
    /* @4916660 call */
    GM_SITE(vm, 605, 4916660);
    v61 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v62 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4916668 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v61, v62, STR_REF(1088)));
    /* @4916672 string */
    /* @4916680 cast */
    /* @4916684 constant */
    /* @4916688 load */
    /* @4916696 cast */
    /* @4916700 load */
    /* @4916708 constant */
    /* @4916712 add */
    /* @4916716 constant */
    /* @4916720 load */
    /* @4916728 cast */
    /* @4916732 load */
    /* @4916740 constant */
    /* @4916744 add */
    /* @4916748 call */
    GM_SITE(vm, 605, 4916748);
    v63 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v64 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4916756 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v63, v64, STR_REF(1089)));
    L_4916760: ;
    /* @4916760 load */
    /* @4916768 constant */
    /* @4916772 cmp */
    /* @4916776 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4917000;
    /* @4916780 constant */
    /* @4916784 cast */
    /* @4916788 call */
    GM_SITE(vm, 605, 4916788);
    /* @4916796 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4916800 constant */
    /* @4916808 cast */
    /* @4916812 call */
    GM_SITE(vm, 605, 4916812);
    /* @4916820 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4916824 string */
    /* @4916832 cast */
    /* @4916836 constant */
    /* @4916840 load */
    /* @4916848 cast */
    /* @4916852 load */
    /* @4916860 constant */
    /* @4916864 add */
    /* @4916868 constant */
    /* @4916872 load */
    /* @4916880 cast */
    /* @4916884 load */
    /* @4916892 constant */
    /* @4916896 add */
    /* @4916900 call */
    GM_SITE(vm, 605, 4916900);
    v65 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v66 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4916908 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v65, v66, STR_REF(1088)));
    /* @4916912 string */
    /* @4916920 cast */
    /* @4916924 constant */
    /* @4916928 load */
    /* @4916936 cast */
    /* @4916940 load */
    /* @4916948 constant */
    /* @4916952 add */
    /* @4916956 constant */
    /* @4916960 load */
    /* @4916968 cast */
    /* @4916972 load */
    /* @4916980 constant */
    /* @4916984 add */
    /* @4916988 call */
    GM_SITE(vm, 605, 4916988);
    v67 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v68 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4916996 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v67, v68, STR_REF(1089)));
    L_4917000: ;
    /* @4917000 load */
    /* @4917008 constant */
    /* @4917012 cmp */
    /* @4917016 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4917240;
    /* @4917020 constant */
    /* @4917024 cast */
    /* @4917028 call */
    GM_SITE(vm, 605, 4917028);
    /* @4917036 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4917040 constant */
    /* @4917048 cast */
    /* @4917052 call */
    GM_SITE(vm, 605, 4917052);
    /* @4917060 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4917064 string */
    /* @4917072 cast */
    /* @4917076 constant */
    /* @4917080 load */
    /* @4917088 cast */
    /* @4917092 load */
    /* @4917100 constant */
    /* @4917104 add */
    /* @4917108 constant */
    /* @4917112 load */
    /* @4917120 cast */
    /* @4917124 load */
    /* @4917132 constant */
    /* @4917136 add */
    /* @4917140 call */
    GM_SITE(vm, 605, 4917140);
    v69 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v70 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4917148 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v69, v70, STR_REF(1088)));
    /* @4917152 string */
    /* @4917160 cast */
    /* @4917164 constant */
    /* @4917168 load */
    /* @4917176 cast */
    /* @4917180 load */
    /* @4917188 constant */
    /* @4917192 add */
    /* @4917196 constant */
    /* @4917200 load */
    /* @4917208 cast */
    /* @4917212 load */
    /* @4917220 constant */
    /* @4917224 add */
    /* @4917228 call */
    GM_SITE(vm, 605, 4917228);
    v71 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v72 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4917236 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v71, v72, STR_REF(1089)));
    L_4917240: ;
    /* @4917240 load */
    /* @4917248 constant */
    /* @4917252 cmp */
    /* @4917256 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4917480;
    /* @4917260 constant */
    /* @4917264 cast */
    /* @4917268 call */
    GM_SITE(vm, 605, 4917268);
    /* @4917276 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4917280 constant */
    /* @4917288 cast */
    /* @4917292 call */
    GM_SITE(vm, 605, 4917292);
    /* @4917300 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4917304 string */
    /* @4917312 cast */
    /* @4917316 constant */
    /* @4917320 load */
    /* @4917328 cast */
    /* @4917332 load */
    /* @4917340 constant */
    /* @4917344 add */
    /* @4917348 constant */
    /* @4917352 load */
    /* @4917360 cast */
    /* @4917364 load */
    /* @4917372 constant */
    /* @4917376 add */
    /* @4917380 call */
    GM_SITE(vm, 605, 4917380);
    v73 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v74 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4917388 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v73, v74, STR_REF(1088)));
    /* @4917392 string */
    /* @4917400 cast */
    /* @4917404 constant */
    /* @4917408 load */
    /* @4917416 cast */
    /* @4917420 load */
    /* @4917428 constant */
    /* @4917432 add */
    /* @4917436 constant */
    /* @4917440 load */
    /* @4917448 cast */
    /* @4917452 load */
    /* @4917460 constant */
    /* @4917464 add */
    /* @4917468 call */
    GM_SITE(vm, 605, 4917468);
    v75 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v76 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4917476 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v75, v76, STR_REF(1089)));
    L_4917480: ;
    /* @4917480 load */
    /* @4917488 constant */
    /* @4917492 cmp */
    /* @4917496 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4917720;
    /* @4917500 constant */
    /* @4917504 cast */
    /* @4917508 call */
    GM_SITE(vm, 605, 4917508);
    /* @4917516 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4917520 constant */
    /* @4917528 cast */
    /* @4917532 call */
    GM_SITE(vm, 605, 4917532);
    /* @4917540 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4917544 string */
    /* @4917552 cast */
    /* @4917556 constant */
    /* @4917560 load */
    /* @4917568 cast */
    /* @4917572 load */
    /* @4917580 constant */
    /* @4917584 add */
    /* @4917588 constant */
    /* @4917592 load */
    /* @4917600 cast */
    /* @4917604 load */
    /* @4917612 constant */
    /* @4917616 add */
    /* @4917620 call */
    GM_SITE(vm, 605, 4917620);
    v77 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v78 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4917628 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v77, v78, STR_REF(1088)));
    /* @4917632 string */
    /* @4917640 cast */
    /* @4917644 constant */
    /* @4917648 load */
    /* @4917656 cast */
    /* @4917660 load */
    /* @4917668 constant */
    /* @4917672 add */
    /* @4917676 constant */
    /* @4917680 load */
    /* @4917688 cast */
    /* @4917692 load */
    /* @4917700 constant */
    /* @4917704 add */
    /* @4917708 call */
    GM_SITE(vm, 605, 4917708);
    v79 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v80 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4917716 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v79, v80, STR_REF(1089)));
    L_4917720: ;
    /* @4917720 load */
    /* @4917728 constant */
    /* @4917732 cmp */
    /* @4917736 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4917960;
    /* @4917740 constant */
    /* @4917744 cast */
    /* @4917748 call */
    GM_SITE(vm, 605, 4917748);
    /* @4917756 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4917760 constant */
    /* @4917768 cast */
    /* @4917772 call */
    GM_SITE(vm, 605, 4917772);
    /* @4917780 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4917784 string */
    /* @4917792 cast */
    /* @4917796 constant */
    /* @4917800 load */
    /* @4917808 cast */
    /* @4917812 load */
    /* @4917820 constant */
    /* @4917824 add */
    /* @4917828 constant */
    /* @4917832 load */
    /* @4917840 cast */
    /* @4917844 load */
    /* @4917852 constant */
    /* @4917856 add */
    /* @4917860 call */
    GM_SITE(vm, 605, 4917860);
    v81 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v82 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4917868 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v81, v82, STR_REF(1088)));
    /* @4917872 string */
    /* @4917880 cast */
    /* @4917884 constant */
    /* @4917888 load */
    /* @4917896 cast */
    /* @4917900 load */
    /* @4917908 constant */
    /* @4917912 add */
    /* @4917916 constant */
    /* @4917920 load */
    /* @4917928 cast */
    /* @4917932 load */
    /* @4917940 constant */
    /* @4917944 add */
    /* @4917948 call */
    GM_SITE(vm, 605, 4917948);
    v83 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v84 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4917956 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v83, v84, STR_REF(1089)));
    L_4917960: ;
    /* @4917960 load */
    /* @4917968 constant */
    /* @4917972 cmp */
    /* @4917976 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel3") == VAL(1)))) goto L_4919972;
    /* @4917980 load */
    /* @4917988 constant */
    /* @4917992 cmp */
    /* @4917996 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4918312;
    /* @4918000 constant */
    /* @4918004 cast */
    /* @4918008 call */
    GM_SITE(vm, 605, 4918008);
    /* @4918016 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4918020 constant */
    /* @4918028 cast */
    /* @4918032 call */
    GM_SITE(vm, 605, 4918032);
    /* @4918040 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4918044 string */
    /* @4918052 cast */
    /* @4918056 constant */
    /* @4918060 load */
    /* @4918068 cast */
    /* @4918072 load */
    /* @4918080 constant */
    /* @4918084 add */
    /* @4918088 constant */
    /* @4918092 load */
    /* @4918100 cast */
    /* @4918104 load */
    /* @4918112 constant */
    /* @4918116 add */
    /* @4918120 call */
    GM_SITE(vm, 605, 4918120);
    v85 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v86 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4918128 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v85, v86, STR_REF(1090)));
    /* @4918132 string */
    /* @4918140 cast */
    /* @4918144 constant */
    /* @4918148 load */
    /* @4918156 cast */
    /* @4918160 load */
    /* @4918168 constant */
    /* @4918172 add */
    /* @4918176 constant */
    /* @4918180 load */
    /* @4918188 cast */
    /* @4918192 load */
    /* @4918200 constant */
    /* @4918204 add */
    /* @4918208 call */
    GM_SITE(vm, 605, 4918208);
    v87 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v88 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4918216 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v87, v88, STR_REF(1091)));
    /* @4918220 constant */
    /* @4918224 load */
    /* @4918232 cast */
    /* @4918236 load */
    /* @4918244 constant */
    /* @4918248 add */
    /* @4918252 constant */
    /* @4918256 load */
    /* @4918264 cast */
    /* @4918268 load */
    /* @4918276 constant */
    /* @4918280 add */
    /* @4918284 constant */
    /* @4918288 cast */
    /* @4918292 constant */
    /* @4918296 cast */
    /* @4918300 call */
    GM_SITE(vm, 605, 4918300);
    v89 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v90 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(90));
    /* @4918308 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(121), VAL(0), v89, v90));
    L_4918312: ;
    /* @4918312 load */
    /* @4918320 constant */
    /* @4918324 cmp */
    /* @4918328 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4918644;
    /* @4918332 constant */
    /* @4918336 cast */
    /* @4918340 call */
    GM_SITE(vm, 605, 4918340);
    /* @4918348 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4918352 constant */
    /* @4918360 cast */
    /* @4918364 call */
    GM_SITE(vm, 605, 4918364);
    /* @4918372 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4918376 string */
    /* @4918384 cast */
    /* @4918388 constant */
    /* @4918392 load */
    /* @4918400 cast */
    /* @4918404 load */
    /* @4918412 constant */
    /* @4918416 add */
    /* @4918420 constant */
    /* @4918424 load */
    /* @4918432 cast */
    /* @4918436 load */
    /* @4918444 constant */
    /* @4918448 add */
    /* @4918452 call */
    GM_SITE(vm, 605, 4918452);
    v91 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v92 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4918460 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v91, v92, STR_REF(1090)));
    /* @4918464 string */
    /* @4918472 cast */
    /* @4918476 constant */
    /* @4918480 load */
    /* @4918488 cast */
    /* @4918492 load */
    /* @4918500 constant */
    /* @4918504 add */
    /* @4918508 constant */
    /* @4918512 load */
    /* @4918520 cast */
    /* @4918524 load */
    /* @4918532 constant */
    /* @4918536 add */
    /* @4918540 call */
    GM_SITE(vm, 605, 4918540);
    v93 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v94 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4918548 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v93, v94, STR_REF(1091)));
    /* @4918552 constant */
    /* @4918556 load */
    /* @4918564 cast */
    /* @4918568 load */
    /* @4918576 constant */
    /* @4918580 add */
    /* @4918584 constant */
    /* @4918588 load */
    /* @4918596 cast */
    /* @4918600 load */
    /* @4918608 constant */
    /* @4918612 add */
    /* @4918616 constant */
    /* @4918620 cast */
    /* @4918624 constant */
    /* @4918628 cast */
    /* @4918632 call */
    GM_SITE(vm, 605, 4918632);
    v95 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v96 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(90));
    /* @4918640 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(121), VAL(0), v95, v96));
    L_4918644: ;
    /* @4918644 load */
    /* @4918652 constant */
    /* @4918656 cmp */
    /* @4918660 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4918976;
    /* @4918664 constant */
    /* @4918668 cast */
    /* @4918672 call */
    GM_SITE(vm, 605, 4918672);
    /* @4918680 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4918684 constant */
    /* @4918692 cast */
    /* @4918696 call */
    GM_SITE(vm, 605, 4918696);
    /* @4918704 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4918708 string */
    /* @4918716 cast */
    /* @4918720 constant */
    /* @4918724 load */
    /* @4918732 cast */
    /* @4918736 load */
    /* @4918744 constant */
    /* @4918748 add */
    /* @4918752 constant */
    /* @4918756 load */
    /* @4918764 cast */
    /* @4918768 load */
    /* @4918776 constant */
    /* @4918780 add */
    /* @4918784 call */
    GM_SITE(vm, 605, 4918784);
    v97 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v98 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4918792 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v97, v98, STR_REF(1090)));
    /* @4918796 string */
    /* @4918804 cast */
    /* @4918808 constant */
    /* @4918812 load */
    /* @4918820 cast */
    /* @4918824 load */
    /* @4918832 constant */
    /* @4918836 add */
    /* @4918840 constant */
    /* @4918844 load */
    /* @4918852 cast */
    /* @4918856 load */
    /* @4918864 constant */
    /* @4918868 add */
    /* @4918872 call */
    GM_SITE(vm, 605, 4918872);
    v99 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v100 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4918880 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v99, v100, STR_REF(1091)));
    /* @4918884 constant */
    /* @4918888 load */
    /* @4918896 cast */
    /* @4918900 load */
    /* @4918908 constant */
    /* @4918912 add */
    /* @4918916 constant */
    /* @4918920 load */
    /* @4918928 cast */
    /* @4918932 load */
    /* @4918940 constant */
    /* @4918944 add */
    /* @4918948 constant */
    /* @4918952 cast */
    /* @4918956 constant */
    /* @4918960 cast */
    /* @4918964 call */
    GM_SITE(vm, 605, 4918964);
    v101 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v102 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    /* @4918972 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(121), VAL(0), v101, v102));
    L_4918976: ;
    /* @4918976 load */
    /* @4918984 constant */
    /* @4918988 cmp */
    /* @4918992 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4919308;
    /* @4918996 constant */
    /* @4919000 cast */
    /* @4919004 call */
    GM_SITE(vm, 605, 4919004);
    /* @4919012 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4919016 constant */
    /* @4919024 cast */
    /* @4919028 call */
    GM_SITE(vm, 605, 4919028);
    /* @4919036 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4919040 string */
    /* @4919048 cast */
    /* @4919052 constant */
    /* @4919056 load */
    /* @4919064 cast */
    /* @4919068 load */
    /* @4919076 constant */
    /* @4919080 add */
    /* @4919084 constant */
    /* @4919088 load */
    /* @4919096 cast */
    /* @4919100 load */
    /* @4919108 constant */
    /* @4919112 add */
    /* @4919116 call */
    GM_SITE(vm, 605, 4919116);
    v103 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v104 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4919124 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v103, v104, STR_REF(1090)));
    /* @4919128 string */
    /* @4919136 cast */
    /* @4919140 constant */
    /* @4919144 load */
    /* @4919152 cast */
    /* @4919156 load */
    /* @4919164 constant */
    /* @4919168 add */
    /* @4919172 constant */
    /* @4919176 load */
    /* @4919184 cast */
    /* @4919188 load */
    /* @4919196 constant */
    /* @4919200 add */
    /* @4919204 call */
    GM_SITE(vm, 605, 4919204);
    v105 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v106 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4919212 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v105, v106, STR_REF(1091)));
    /* @4919216 constant */
    /* @4919220 load */
    /* @4919228 cast */
    /* @4919232 load */
    /* @4919240 constant */
    /* @4919244 add */
    /* @4919248 constant */
    /* @4919252 load */
    /* @4919260 cast */
    /* @4919264 load */
    /* @4919272 constant */
    /* @4919276 add */
    /* @4919280 constant */
    /* @4919284 cast */
    /* @4919288 constant */
    /* @4919292 cast */
    /* @4919296 call */
    GM_SITE(vm, 605, 4919296);
    v107 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v108 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    /* @4919304 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(121), VAL(0), v107, v108));
    L_4919308: ;
    /* @4919308 load */
    /* @4919316 constant */
    /* @4919320 cmp */
    /* @4919324 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4919640;
    /* @4919328 constant */
    /* @4919332 cast */
    /* @4919336 call */
    GM_SITE(vm, 605, 4919336);
    /* @4919344 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4919348 constant */
    /* @4919356 cast */
    /* @4919360 call */
    GM_SITE(vm, 605, 4919360);
    /* @4919368 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4919372 string */
    /* @4919380 cast */
    /* @4919384 constant */
    /* @4919388 load */
    /* @4919396 cast */
    /* @4919400 load */
    /* @4919408 constant */
    /* @4919412 add */
    /* @4919416 constant */
    /* @4919420 load */
    /* @4919428 cast */
    /* @4919432 load */
    /* @4919440 constant */
    /* @4919444 add */
    /* @4919448 call */
    GM_SITE(vm, 605, 4919448);
    v109 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v110 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4919456 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v109, v110, STR_REF(1090)));
    /* @4919460 string */
    /* @4919468 cast */
    /* @4919472 constant */
    /* @4919476 load */
    /* @4919484 cast */
    /* @4919488 load */
    /* @4919496 constant */
    /* @4919500 add */
    /* @4919504 constant */
    /* @4919508 load */
    /* @4919516 cast */
    /* @4919520 load */
    /* @4919528 constant */
    /* @4919532 add */
    /* @4919536 call */
    GM_SITE(vm, 605, 4919536);
    v111 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v112 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4919544 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v111, v112, STR_REF(1091)));
    /* @4919548 constant */
    /* @4919552 load */
    /* @4919560 cast */
    /* @4919564 load */
    /* @4919572 constant */
    /* @4919576 add */
    /* @4919580 constant */
    /* @4919584 load */
    /* @4919592 cast */
    /* @4919596 load */
    /* @4919604 constant */
    /* @4919608 add */
    /* @4919612 constant */
    /* @4919616 cast */
    /* @4919620 constant */
    /* @4919624 cast */
    /* @4919628 call */
    GM_SITE(vm, 605, 4919628);
    v113 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v114 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(90));
    /* @4919636 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(121), VAL(0), v113, v114));
    L_4919640: ;
    /* @4919640 load */
    /* @4919648 constant */
    /* @4919652 cmp */
    /* @4919656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4919972;
    /* @4919660 constant */
    /* @4919664 cast */
    /* @4919668 call */
    GM_SITE(vm, 605, 4919668);
    /* @4919676 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4919680 constant */
    /* @4919688 cast */
    /* @4919692 call */
    GM_SITE(vm, 605, 4919692);
    /* @4919700 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4919704 string */
    /* @4919712 cast */
    /* @4919716 constant */
    /* @4919720 load */
    /* @4919728 cast */
    /* @4919732 load */
    /* @4919740 constant */
    /* @4919744 add */
    /* @4919748 constant */
    /* @4919752 load */
    /* @4919760 cast */
    /* @4919764 load */
    /* @4919772 constant */
    /* @4919776 add */
    /* @4919780 call */
    GM_SITE(vm, 605, 4919780);
    v115 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v116 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4919788 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v115, v116, STR_REF(1090)));
    /* @4919792 string */
    /* @4919800 cast */
    /* @4919804 constant */
    /* @4919808 load */
    /* @4919816 cast */
    /* @4919820 load */
    /* @4919828 constant */
    /* @4919832 add */
    /* @4919836 constant */
    /* @4919840 load */
    /* @4919848 cast */
    /* @4919852 load */
    /* @4919860 constant */
    /* @4919864 add */
    /* @4919868 call */
    GM_SITE(vm, 605, 4919868);
    v117 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v118 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4919876 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v117, v118, STR_REF(1091)));
    /* @4919880 constant */
    /* @4919884 load */
    /* @4919892 cast */
    /* @4919896 load */
    /* @4919904 constant */
    /* @4919908 add */
    /* @4919912 constant */
    /* @4919916 load */
    /* @4919924 cast */
    /* @4919928 load */
    /* @4919936 constant */
    /* @4919940 add */
    /* @4919944 constant */
    /* @4919948 cast */
    /* @4919952 constant */
    /* @4919956 cast */
    /* @4919960 call */
    GM_SITE(vm, 605, 4919960);
    v119 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v120 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(90));
    /* @4919968 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(121), VAL(0), v119, v120));
    L_4919972: ;
    /* @4919972 load */
    /* @4919980 constant */
    /* @4919984 cmp */
    /* @4919988 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4920024;
    /* @4919992 constant */
    /* @4919996 cast */
    /* @4920000 constant */
    /* @4920004 cast */
    /* @4920008 call */
    GM_SITE(vm, 605, 4920008);
    /* @4920016 cast */
    /* @4920020 b */
    v121 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, VAL(0), VAL(1)));
    p4920028_0 = v121;
    goto L_4920028;
    L_4920024: ;
    /* @4920024 constant */
    p4920028_0 = VAL(0);
    L_4920028: ;
    /* @4920028 bf */
    if (!TRUTH(p4920028_0)) goto L_4920044;
    /* @4920032 call */
    GM_SITE(vm, 605, 4920032);
    /* @4920040 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4920044: ;
    return;
}
