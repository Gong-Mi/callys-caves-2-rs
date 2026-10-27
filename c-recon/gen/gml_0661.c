/* generated from CODE 661 (gml_Object_obj_lloydtutorial15_Draw_0), source start 4988000, end 5001868. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0661(GmVM* vm) {
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
    Val p5001852_0;
    Val v205;
    /* @4988000 constant */
    /* @4988004 load */
    /* @4988012 cast */
    /* @4988016 load */
    /* @4988024 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4988032 constant */
    /* @4988036 load */
    /* @4988044 cast */
    /* @4988048 load */
    /* @4988056 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4988064 load */
    /* @4988072 constant */
    /* @4988076 cmp */
    /* @4988080 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4988608;
    /* @4988084 constant */
    /* @4988088 cast */
    /* @4988092 constant */
    /* @4988096 cast */
    /* @4988100 constant */
    /* @4988104 cast */
    /* @4988108 constant */
    /* @4988120 cast */
    /* @4988124 constant */
    /* @4988136 cast */
    /* @4988140 constant */
    /* @4988144 constant */
    /* @4988148 load */
    /* @4988156 constant */
    /* @4988160 constant */
    /* @4988164 load */
    /* @4988172 constant */
    /* @4988176 sub */
    /* @4988180 constant */
    /* @4988184 cast */
    /* @4988188 constant */
    /* @4988192 cast */
    /* @4988196 call */
    GM_SITE(vm, 661, 4988196);
    /* @4988204 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(0.96), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4988208 constant */
    /* @4988212 cast */
    /* @4988216 constant */
    /* @4988220 cast */
    /* @4988224 constant */
    /* @4988228 cast */
    /* @4988232 constant */
    /* @4988236 cast */
    /* @4988240 constant */
    /* @4988244 cast */
    /* @4988248 constant */
    /* @4988252 load */
    /* @4988260 cast */
    /* @4988264 load */
    /* @4988272 constant */
    /* @4988276 add */
    /* @4988280 constant */
    /* @4988284 load */
    /* @4988292 cast */
    /* @4988296 load */
    /* @4988304 constant */
    /* @4988308 add */
    /* @4988312 constant */
    /* @4988316 cast */
    /* @4988320 constant */
    /* @4988324 cast */
    /* @4988328 call */
    GM_SITE(vm, 661, 4988328);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4988336 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v1, v2, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4988340 constant */
    /* @4988344 cast */
    /* @4988348 constant */
    /* @4988352 cast */
    /* @4988356 constant */
    /* @4988360 cast */
    /* @4988364 constant */
    /* @4988368 cast */
    /* @4988372 constant */
    /* @4988376 cast */
    /* @4988380 constant */
    /* @4988384 load */
    /* @4988392 cast */
    /* @4988396 load */
    /* @4988404 constant */
    /* @4988408 add */
    /* @4988412 constant */
    /* @4988416 load */
    /* @4988424 cast */
    /* @4988428 load */
    /* @4988436 constant */
    /* @4988440 add */
    /* @4988444 constant */
    /* @4988448 cast */
    /* @4988452 constant */
    /* @4988456 cast */
    /* @4988460 call */
    GM_SITE(vm, 661, 4988460);
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4988468 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v3, v4, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4988472 load */
    /* @4988480 constant */
    /* @4988484 cmp */
    /* @4988488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4988608;
    /* @4988492 constant */
    /* @4988496 cast */
    /* @4988500 call */
    GM_SITE(vm, 661, 4988500);
    /* @4988508 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4988512 constant */
    /* @4988520 cast */
    /* @4988524 call */
    GM_SITE(vm, 661, 4988524);
    /* @4988532 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4988536 string */
    /* @4988544 cast */
    /* @4988548 constant */
    /* @4988552 constant */
    /* @4988556 load */
    /* @4988564 constant */
    /* @4988568 add */
    /* @4988572 constant */
    /* @4988576 constant */
    /* @4988580 load */
    /* @4988588 constant */
    /* @4988592 add */
    /* @4988596 call */
    GM_SITE(vm, 661, 4988596);
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(150));
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(200));
    /* @4988604 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v5, v6, STR_REF(743)));
    L_4988608: ;
    /* @4988608 load */
    /* @4988616 constant */
    /* @4988620 cmp */
    /* @4988624 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4989152;
    /* @4988628 constant */
    /* @4988632 cast */
    /* @4988636 constant */
    /* @4988640 cast */
    /* @4988644 constant */
    /* @4988648 cast */
    /* @4988652 constant */
    /* @4988664 cast */
    /* @4988668 constant */
    /* @4988680 cast */
    /* @4988684 constant */
    /* @4988688 constant */
    /* @4988692 load */
    /* @4988700 constant */
    /* @4988704 constant */
    /* @4988708 load */
    /* @4988716 constant */
    /* @4988720 sub */
    /* @4988724 constant */
    /* @4988728 cast */
    /* @4988732 constant */
    /* @4988736 cast */
    /* @4988740 call */
    GM_SITE(vm, 661, 4988740);
    /* @4988748 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(0.82), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4988752 constant */
    /* @4988756 cast */
    /* @4988760 constant */
    /* @4988764 cast */
    /* @4988768 constant */
    /* @4988772 cast */
    /* @4988776 constant */
    /* @4988780 cast */
    /* @4988784 constant */
    /* @4988788 cast */
    /* @4988792 constant */
    /* @4988796 load */
    /* @4988804 cast */
    /* @4988808 load */
    /* @4988816 constant */
    /* @4988820 add */
    /* @4988824 constant */
    /* @4988828 load */
    /* @4988836 cast */
    /* @4988840 load */
    /* @4988848 constant */
    /* @4988852 add */
    /* @4988856 constant */
    /* @4988860 cast */
    /* @4988864 constant */
    /* @4988868 cast */
    /* @4988872 call */
    GM_SITE(vm, 661, 4988872);
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4988880 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v7, v8, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4988884 constant */
    /* @4988888 cast */
    /* @4988892 constant */
    /* @4988896 cast */
    /* @4988900 constant */
    /* @4988904 cast */
    /* @4988908 constant */
    /* @4988912 cast */
    /* @4988916 constant */
    /* @4988920 cast */
    /* @4988924 constant */
    /* @4988928 load */
    /* @4988936 cast */
    /* @4988940 load */
    /* @4988948 constant */
    /* @4988952 add */
    /* @4988956 constant */
    /* @4988960 load */
    /* @4988968 cast */
    /* @4988972 load */
    /* @4988980 constant */
    /* @4988984 add */
    /* @4988988 constant */
    /* @4988992 cast */
    /* @4988996 constant */
    /* @4989000 cast */
    /* @4989004 call */
    GM_SITE(vm, 661, 4989004);
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(320));
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4989012 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v9, v10, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4989016 load */
    /* @4989024 constant */
    /* @4989028 cmp */
    /* @4989032 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4989152;
    /* @4989036 constant */
    /* @4989040 cast */
    /* @4989044 call */
    GM_SITE(vm, 661, 4989044);
    /* @4989052 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4989056 constant */
    /* @4989064 cast */
    /* @4989068 call */
    GM_SITE(vm, 661, 4989068);
    /* @4989076 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4989080 string */
    /* @4989088 cast */
    /* @4989092 constant */
    /* @4989096 constant */
    /* @4989100 load */
    /* @4989108 constant */
    /* @4989112 add */
    /* @4989116 constant */
    /* @4989120 constant */
    /* @4989124 load */
    /* @4989132 constant */
    /* @4989136 add */
    /* @4989140 call */
    GM_SITE(vm, 661, 4989140);
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(110));
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4989148 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v11, v12, STR_REF(743)));
    L_4989152: ;
    /* @4989152 load */
    /* @4989160 constant */
    /* @4989164 cmp */
    /* @4989168 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4989696;
    /* @4989172 constant */
    /* @4989176 cast */
    /* @4989180 constant */
    /* @4989184 cast */
    /* @4989188 constant */
    /* @4989192 cast */
    /* @4989196 constant */
    /* @4989208 cast */
    /* @4989212 constant */
    /* @4989224 cast */
    /* @4989228 constant */
    /* @4989232 constant */
    /* @4989236 load */
    /* @4989244 constant */
    /* @4989248 constant */
    /* @4989252 load */
    /* @4989260 constant */
    /* @4989264 sub */
    /* @4989268 constant */
    /* @4989272 cast */
    /* @4989276 constant */
    /* @4989280 cast */
    /* @4989284 call */
    GM_SITE(vm, 661, 4989284);
    /* @4989292 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4989296 constant */
    /* @4989300 cast */
    /* @4989304 constant */
    /* @4989308 cast */
    /* @4989312 constant */
    /* @4989316 cast */
    /* @4989320 constant */
    /* @4989324 cast */
    /* @4989328 constant */
    /* @4989332 cast */
    /* @4989336 constant */
    /* @4989340 load */
    /* @4989348 cast */
    /* @4989352 load */
    /* @4989360 constant */
    /* @4989364 add */
    /* @4989368 constant */
    /* @4989372 load */
    /* @4989380 cast */
    /* @4989384 load */
    /* @4989392 constant */
    /* @4989396 add */
    /* @4989400 constant */
    /* @4989404 cast */
    /* @4989408 constant */
    /* @4989412 cast */
    /* @4989416 call */
    GM_SITE(vm, 661, 4989416);
    v13 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4989424 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v13, v14, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4989428 constant */
    /* @4989432 cast */
    /* @4989436 constant */
    /* @4989440 cast */
    /* @4989444 constant */
    /* @4989448 cast */
    /* @4989452 constant */
    /* @4989456 cast */
    /* @4989460 constant */
    /* @4989464 cast */
    /* @4989468 constant */
    /* @4989472 load */
    /* @4989480 cast */
    /* @4989484 load */
    /* @4989492 constant */
    /* @4989496 add */
    /* @4989500 constant */
    /* @4989504 load */
    /* @4989512 cast */
    /* @4989516 load */
    /* @4989524 constant */
    /* @4989528 add */
    /* @4989532 constant */
    /* @4989536 cast */
    /* @4989540 constant */
    /* @4989544 cast */
    /* @4989548 call */
    GM_SITE(vm, 661, 4989548);
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4989556 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v15, v16, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4989560 load */
    /* @4989568 constant */
    /* @4989572 cmp */
    /* @4989576 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4989696;
    /* @4989580 constant */
    /* @4989584 cast */
    /* @4989588 call */
    GM_SITE(vm, 661, 4989588);
    /* @4989596 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4989600 constant */
    /* @4989608 cast */
    /* @4989612 call */
    GM_SITE(vm, 661, 4989612);
    /* @4989620 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4989624 string */
    /* @4989632 cast */
    /* @4989636 constant */
    /* @4989640 constant */
    /* @4989644 load */
    /* @4989652 constant */
    /* @4989656 add */
    /* @4989660 constant */
    /* @4989664 constant */
    /* @4989668 load */
    /* @4989676 constant */
    /* @4989680 add */
    /* @4989684 call */
    GM_SITE(vm, 661, 4989684);
    v17 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(180));
    v18 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(300));
    /* @4989692 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v17, v18, STR_REF(743)));
    L_4989696: ;
    /* @4989696 load */
    /* @4989704 constant */
    /* @4989708 cmp */
    /* @4989712 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4990240;
    /* @4989716 constant */
    /* @4989720 cast */
    /* @4989724 constant */
    /* @4989728 cast */
    /* @4989732 constant */
    /* @4989736 cast */
    /* @4989740 constant */
    /* @4989752 cast */
    /* @4989756 constant */
    /* @4989768 cast */
    /* @4989772 constant */
    /* @4989776 constant */
    /* @4989780 load */
    /* @4989788 constant */
    /* @4989792 constant */
    /* @4989796 load */
    /* @4989804 constant */
    /* @4989808 sub */
    /* @4989812 constant */
    /* @4989816 cast */
    /* @4989820 constant */
    /* @4989824 cast */
    /* @4989828 call */
    GM_SITE(vm, 661, 4989828);
    /* @4989836 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4989840 constant */
    /* @4989844 cast */
    /* @4989848 constant */
    /* @4989852 cast */
    /* @4989856 constant */
    /* @4989860 cast */
    /* @4989864 constant */
    /* @4989868 cast */
    /* @4989872 constant */
    /* @4989876 cast */
    /* @4989880 constant */
    /* @4989884 load */
    /* @4989892 cast */
    /* @4989896 load */
    /* @4989904 constant */
    /* @4989908 add */
    /* @4989912 constant */
    /* @4989916 load */
    /* @4989924 cast */
    /* @4989928 load */
    /* @4989936 constant */
    /* @4989940 add */
    /* @4989944 constant */
    /* @4989948 cast */
    /* @4989952 constant */
    /* @4989956 cast */
    /* @4989960 call */
    GM_SITE(vm, 661, 4989960);
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4989968 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v19, v20, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4989972 constant */
    /* @4989976 cast */
    /* @4989980 constant */
    /* @4989984 cast */
    /* @4989988 constant */
    /* @4989992 cast */
    /* @4989996 constant */
    /* @4990000 cast */
    /* @4990004 constant */
    /* @4990008 cast */
    /* @4990012 constant */
    /* @4990016 load */
    /* @4990024 cast */
    /* @4990028 load */
    /* @4990036 constant */
    /* @4990040 add */
    /* @4990044 constant */
    /* @4990048 load */
    /* @4990056 cast */
    /* @4990060 load */
    /* @4990068 constant */
    /* @4990072 add */
    /* @4990076 constant */
    /* @4990080 cast */
    /* @4990084 constant */
    /* @4990088 cast */
    /* @4990092 call */
    GM_SITE(vm, 661, 4990092);
    v21 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4990100 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v21, v22, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4990104 load */
    /* @4990112 constant */
    /* @4990116 cmp */
    /* @4990120 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4990240;
    /* @4990124 constant */
    /* @4990128 cast */
    /* @4990132 call */
    GM_SITE(vm, 661, 4990132);
    /* @4990140 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4990144 constant */
    /* @4990152 cast */
    /* @4990156 call */
    GM_SITE(vm, 661, 4990156);
    /* @4990164 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4990168 string */
    /* @4990176 cast */
    /* @4990180 constant */
    /* @4990184 constant */
    /* @4990188 load */
    /* @4990196 constant */
    /* @4990200 add */
    /* @4990204 constant */
    /* @4990208 constant */
    /* @4990212 load */
    /* @4990220 constant */
    /* @4990224 add */
    /* @4990228 call */
    GM_SITE(vm, 661, 4990228);
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(180));
    v24 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(300));
    /* @4990236 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v23, v24, STR_REF(743)));
    L_4990240: ;
    /* @4990240 load */
    /* @4990248 constant */
    /* @4990252 cmp */
    /* @4990256 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4990784;
    /* @4990260 constant */
    /* @4990264 cast */
    /* @4990268 constant */
    /* @4990272 cast */
    /* @4990276 constant */
    /* @4990280 cast */
    /* @4990284 constant */
    /* @4990296 cast */
    /* @4990300 constant */
    /* @4990312 cast */
    /* @4990316 constant */
    /* @4990320 constant */
    /* @4990324 load */
    /* @4990332 constant */
    /* @4990336 constant */
    /* @4990340 load */
    /* @4990348 constant */
    /* @4990352 sub */
    /* @4990356 constant */
    /* @4990360 cast */
    /* @4990364 constant */
    /* @4990368 cast */
    /* @4990372 call */
    GM_SITE(vm, 661, 4990372);
    /* @4990380 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(0.97), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4990384 constant */
    /* @4990388 cast */
    /* @4990392 constant */
    /* @4990396 cast */
    /* @4990400 constant */
    /* @4990404 cast */
    /* @4990408 constant */
    /* @4990412 cast */
    /* @4990416 constant */
    /* @4990420 cast */
    /* @4990424 constant */
    /* @4990428 load */
    /* @4990436 cast */
    /* @4990440 load */
    /* @4990448 constant */
    /* @4990452 add */
    /* @4990456 constant */
    /* @4990460 load */
    /* @4990468 cast */
    /* @4990472 load */
    /* @4990480 constant */
    /* @4990484 add */
    /* @4990488 constant */
    /* @4990492 cast */
    /* @4990496 constant */
    /* @4990500 cast */
    /* @4990504 call */
    GM_SITE(vm, 661, 4990504);
    v25 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v26 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4990512 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v25, v26, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4990516 constant */
    /* @4990520 cast */
    /* @4990524 constant */
    /* @4990528 cast */
    /* @4990532 constant */
    /* @4990536 cast */
    /* @4990540 constant */
    /* @4990544 cast */
    /* @4990548 constant */
    /* @4990552 cast */
    /* @4990556 constant */
    /* @4990560 load */
    /* @4990568 cast */
    /* @4990572 load */
    /* @4990580 constant */
    /* @4990584 add */
    /* @4990588 constant */
    /* @4990592 load */
    /* @4990600 cast */
    /* @4990604 load */
    /* @4990612 constant */
    /* @4990616 add */
    /* @4990620 constant */
    /* @4990624 cast */
    /* @4990628 constant */
    /* @4990632 cast */
    /* @4990636 call */
    GM_SITE(vm, 661, 4990636);
    v27 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v28 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4990644 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v27, v28, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4990648 load */
    /* @4990656 constant */
    /* @4990660 cmp */
    /* @4990664 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4990784;
    /* @4990668 constant */
    /* @4990672 cast */
    /* @4990676 call */
    GM_SITE(vm, 661, 4990676);
    /* @4990684 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4990688 constant */
    /* @4990696 cast */
    /* @4990700 call */
    GM_SITE(vm, 661, 4990700);
    /* @4990708 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4990712 string */
    /* @4990720 cast */
    /* @4990724 constant */
    /* @4990728 constant */
    /* @4990732 load */
    /* @4990740 constant */
    /* @4990744 add */
    /* @4990748 constant */
    /* @4990752 constant */
    /* @4990756 load */
    /* @4990764 constant */
    /* @4990768 add */
    /* @4990772 call */
    GM_SITE(vm, 661, 4990772);
    v29 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(150));
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(200));
    /* @4990780 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v29, v30, STR_REF(743)));
    L_4990784: ;
    /* @4990784 load */
    /* @4990792 constant */
    /* @4990796 cmp */
    /* @4990800 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4991328;
    /* @4990804 constant */
    /* @4990808 cast */
    /* @4990812 constant */
    /* @4990816 cast */
    /* @4990820 constant */
    /* @4990824 cast */
    /* @4990828 constant */
    /* @4990840 cast */
    /* @4990844 constant */
    /* @4990856 cast */
    /* @4990860 constant */
    /* @4990864 constant */
    /* @4990868 load */
    /* @4990876 constant */
    /* @4990880 constant */
    /* @4990884 load */
    /* @4990892 constant */
    /* @4990896 sub */
    /* @4990900 constant */
    /* @4990904 cast */
    /* @4990908 constant */
    /* @4990912 cast */
    /* @4990916 call */
    GM_SITE(vm, 661, 4990916);
    /* @4990924 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(1.06), VAL(0.86), VAL(0), VAL(-1), VAL(1)));
    /* @4990928 constant */
    /* @4990932 cast */
    /* @4990936 constant */
    /* @4990940 cast */
    /* @4990944 constant */
    /* @4990948 cast */
    /* @4990952 constant */
    /* @4990956 cast */
    /* @4990960 constant */
    /* @4990964 cast */
    /* @4990968 constant */
    /* @4990972 load */
    /* @4990980 cast */
    /* @4990984 load */
    /* @4990992 constant */
    /* @4990996 add */
    /* @4991000 constant */
    /* @4991004 load */
    /* @4991012 cast */
    /* @4991016 load */
    /* @4991024 constant */
    /* @4991028 add */
    /* @4991032 constant */
    /* @4991036 cast */
    /* @4991040 constant */
    /* @4991044 cast */
    /* @4991048 call */
    GM_SITE(vm, 661, 4991048);
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v32 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4991056 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v31, v32, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4991060 constant */
    /* @4991064 cast */
    /* @4991068 constant */
    /* @4991072 cast */
    /* @4991076 constant */
    /* @4991080 cast */
    /* @4991084 constant */
    /* @4991088 cast */
    /* @4991092 constant */
    /* @4991096 cast */
    /* @4991100 constant */
    /* @4991104 load */
    /* @4991112 cast */
    /* @4991116 load */
    /* @4991124 constant */
    /* @4991128 add */
    /* @4991132 constant */
    /* @4991136 load */
    /* @4991144 cast */
    /* @4991148 load */
    /* @4991156 constant */
    /* @4991160 add */
    /* @4991164 constant */
    /* @4991168 cast */
    /* @4991172 constant */
    /* @4991176 cast */
    /* @4991180 call */
    GM_SITE(vm, 661, 4991180);
    v33 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(390));
    v34 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4991188 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v33, v34, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4991192 load */
    /* @4991200 constant */
    /* @4991204 cmp */
    /* @4991208 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4991328;
    /* @4991212 constant */
    /* @4991216 cast */
    /* @4991220 call */
    GM_SITE(vm, 661, 4991220);
    /* @4991228 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4991232 constant */
    /* @4991240 cast */
    /* @4991244 call */
    GM_SITE(vm, 661, 4991244);
    /* @4991252 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4991256 string */
    /* @4991264 cast */
    /* @4991268 constant */
    /* @4991272 constant */
    /* @4991276 load */
    /* @4991284 constant */
    /* @4991288 add */
    /* @4991292 constant */
    /* @4991296 constant */
    /* @4991300 load */
    /* @4991308 constant */
    /* @4991312 add */
    /* @4991316 call */
    GM_SITE(vm, 661, 4991316);
    v35 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(160));
    v36 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(200));
    /* @4991324 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v35, v36, STR_REF(743)));
    L_4991328: ;
    /* @4991328 load */
    /* @4991336 constant */
    /* @4991340 cmp */
    /* @4991344 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel1") == VAL(1)))) goto L_4992788;
    /* @4991348 load */
    /* @4991356 constant */
    /* @4991360 cmp */
    /* @4991364 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4991588;
    /* @4991368 constant */
    /* @4991372 cast */
    /* @4991376 call */
    GM_SITE(vm, 661, 4991376);
    /* @4991384 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4991388 constant */
    /* @4991396 cast */
    /* @4991400 call */
    GM_SITE(vm, 661, 4991400);
    /* @4991408 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4991412 string */
    /* @4991420 cast */
    /* @4991424 constant */
    /* @4991428 load */
    /* @4991436 cast */
    /* @4991440 load */
    /* @4991448 constant */
    /* @4991452 add */
    /* @4991456 constant */
    /* @4991460 load */
    /* @4991468 cast */
    /* @4991472 load */
    /* @4991480 constant */
    /* @4991484 add */
    /* @4991488 call */
    GM_SITE(vm, 661, 4991488);
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4991496 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v37, v38, STR_REF(1144)));
    /* @4991500 string */
    /* @4991508 cast */
    /* @4991512 constant */
    /* @4991516 load */
    /* @4991524 cast */
    /* @4991528 load */
    /* @4991536 constant */
    /* @4991540 add */
    /* @4991544 constant */
    /* @4991548 load */
    /* @4991556 cast */
    /* @4991560 load */
    /* @4991568 constant */
    /* @4991572 add */
    /* @4991576 call */
    GM_SITE(vm, 661, 4991576);
    v39 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v40 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4991584 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, v40, STR_REF(1145)));
    L_4991588: ;
    /* @4991588 load */
    /* @4991596 constant */
    /* @4991600 cmp */
    /* @4991604 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4991828;
    /* @4991608 constant */
    /* @4991612 cast */
    /* @4991616 call */
    GM_SITE(vm, 661, 4991616);
    /* @4991624 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4991628 constant */
    /* @4991636 cast */
    /* @4991640 call */
    GM_SITE(vm, 661, 4991640);
    /* @4991648 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4991652 string */
    /* @4991660 cast */
    /* @4991664 constant */
    /* @4991668 load */
    /* @4991676 cast */
    /* @4991680 load */
    /* @4991688 constant */
    /* @4991692 add */
    /* @4991696 constant */
    /* @4991700 load */
    /* @4991708 cast */
    /* @4991712 load */
    /* @4991720 constant */
    /* @4991724 add */
    /* @4991728 call */
    GM_SITE(vm, 661, 4991728);
    v41 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v42 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4991736 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v41, v42, STR_REF(1144)));
    /* @4991740 string */
    /* @4991748 cast */
    /* @4991752 constant */
    /* @4991756 load */
    /* @4991764 cast */
    /* @4991768 load */
    /* @4991776 constant */
    /* @4991780 add */
    /* @4991784 constant */
    /* @4991788 load */
    /* @4991796 cast */
    /* @4991800 load */
    /* @4991808 constant */
    /* @4991812 add */
    /* @4991816 call */
    GM_SITE(vm, 661, 4991816);
    v43 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v44 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4991824 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v43, v44, STR_REF(1145)));
    L_4991828: ;
    /* @4991828 load */
    /* @4991836 constant */
    /* @4991840 cmp */
    /* @4991844 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4992068;
    /* @4991848 constant */
    /* @4991852 cast */
    /* @4991856 call */
    GM_SITE(vm, 661, 4991856);
    /* @4991864 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4991868 constant */
    /* @4991876 cast */
    /* @4991880 call */
    GM_SITE(vm, 661, 4991880);
    /* @4991888 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4991892 string */
    /* @4991900 cast */
    /* @4991904 constant */
    /* @4991908 load */
    /* @4991916 cast */
    /* @4991920 load */
    /* @4991928 constant */
    /* @4991932 add */
    /* @4991936 constant */
    /* @4991940 load */
    /* @4991948 cast */
    /* @4991952 load */
    /* @4991960 constant */
    /* @4991964 add */
    /* @4991968 call */
    GM_SITE(vm, 661, 4991968);
    v45 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v46 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4991976 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v45, v46, STR_REF(1144)));
    /* @4991980 string */
    /* @4991988 cast */
    /* @4991992 constant */
    /* @4991996 load */
    /* @4992004 cast */
    /* @4992008 load */
    /* @4992016 constant */
    /* @4992020 add */
    /* @4992024 constant */
    /* @4992028 load */
    /* @4992036 cast */
    /* @4992040 load */
    /* @4992048 constant */
    /* @4992052 add */
    /* @4992056 call */
    GM_SITE(vm, 661, 4992056);
    v47 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v48 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4992064 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v47, v48, STR_REF(1145)));
    L_4992068: ;
    /* @4992068 load */
    /* @4992076 constant */
    /* @4992080 cmp */
    /* @4992084 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4992308;
    /* @4992088 constant */
    /* @4992092 cast */
    /* @4992096 call */
    GM_SITE(vm, 661, 4992096);
    /* @4992104 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4992108 constant */
    /* @4992116 cast */
    /* @4992120 call */
    GM_SITE(vm, 661, 4992120);
    /* @4992128 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4992132 string */
    /* @4992140 cast */
    /* @4992144 constant */
    /* @4992148 load */
    /* @4992156 cast */
    /* @4992160 load */
    /* @4992168 constant */
    /* @4992172 add */
    /* @4992176 constant */
    /* @4992180 load */
    /* @4992188 cast */
    /* @4992192 load */
    /* @4992200 constant */
    /* @4992204 add */
    /* @4992208 call */
    GM_SITE(vm, 661, 4992208);
    v49 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v50 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4992216 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v49, v50, STR_REF(1144)));
    /* @4992220 string */
    /* @4992228 cast */
    /* @4992232 constant */
    /* @4992236 load */
    /* @4992244 cast */
    /* @4992248 load */
    /* @4992256 constant */
    /* @4992260 add */
    /* @4992264 constant */
    /* @4992268 load */
    /* @4992276 cast */
    /* @4992280 load */
    /* @4992288 constant */
    /* @4992292 add */
    /* @4992296 call */
    GM_SITE(vm, 661, 4992296);
    v51 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v52 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4992304 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v51, v52, STR_REF(1145)));
    L_4992308: ;
    /* @4992308 load */
    /* @4992316 constant */
    /* @4992320 cmp */
    /* @4992324 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4992548;
    /* @4992328 constant */
    /* @4992332 cast */
    /* @4992336 call */
    GM_SITE(vm, 661, 4992336);
    /* @4992344 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4992348 constant */
    /* @4992356 cast */
    /* @4992360 call */
    GM_SITE(vm, 661, 4992360);
    /* @4992368 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4992372 string */
    /* @4992380 cast */
    /* @4992384 constant */
    /* @4992388 load */
    /* @4992396 cast */
    /* @4992400 load */
    /* @4992408 constant */
    /* @4992412 add */
    /* @4992416 constant */
    /* @4992420 load */
    /* @4992428 cast */
    /* @4992432 load */
    /* @4992440 constant */
    /* @4992444 add */
    /* @4992448 call */
    GM_SITE(vm, 661, 4992448);
    v53 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v54 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4992456 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v53, v54, STR_REF(1144)));
    /* @4992460 string */
    /* @4992468 cast */
    /* @4992472 constant */
    /* @4992476 load */
    /* @4992484 cast */
    /* @4992488 load */
    /* @4992496 constant */
    /* @4992500 add */
    /* @4992504 constant */
    /* @4992508 load */
    /* @4992516 cast */
    /* @4992520 load */
    /* @4992528 constant */
    /* @4992532 add */
    /* @4992536 call */
    GM_SITE(vm, 661, 4992536);
    v55 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v56 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4992544 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v55, v56, STR_REF(1145)));
    L_4992548: ;
    /* @4992548 load */
    /* @4992556 constant */
    /* @4992560 cmp */
    /* @4992564 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4992788;
    /* @4992568 constant */
    /* @4992572 cast */
    /* @4992576 call */
    GM_SITE(vm, 661, 4992576);
    /* @4992584 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4992588 constant */
    /* @4992596 cast */
    /* @4992600 call */
    GM_SITE(vm, 661, 4992600);
    /* @4992608 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4992612 string */
    /* @4992620 cast */
    /* @4992624 constant */
    /* @4992628 load */
    /* @4992636 cast */
    /* @4992640 load */
    /* @4992648 constant */
    /* @4992652 add */
    /* @4992656 constant */
    /* @4992660 load */
    /* @4992668 cast */
    /* @4992672 load */
    /* @4992680 constant */
    /* @4992684 add */
    /* @4992688 call */
    GM_SITE(vm, 661, 4992688);
    v57 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v58 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4992696 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v57, v58, STR_REF(1144)));
    /* @4992700 string */
    /* @4992708 cast */
    /* @4992712 constant */
    /* @4992716 load */
    /* @4992724 cast */
    /* @4992728 load */
    /* @4992736 constant */
    /* @4992740 add */
    /* @4992744 constant */
    /* @4992748 load */
    /* @4992756 cast */
    /* @4992760 load */
    /* @4992768 constant */
    /* @4992772 add */
    /* @4992776 call */
    GM_SITE(vm, 661, 4992776);
    v59 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v60 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4992784 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v59, v60, STR_REF(1145)));
    L_4992788: ;
    /* @4992788 load */
    /* @4992796 constant */
    /* @4992800 cmp */
    /* @4992804 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel2") == VAL(1)))) goto L_4994248;
    /* @4992808 load */
    /* @4992816 constant */
    /* @4992820 cmp */
    /* @4992824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4993048;
    /* @4992828 constant */
    /* @4992832 cast */
    /* @4992836 call */
    GM_SITE(vm, 661, 4992836);
    /* @4992844 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4992848 constant */
    /* @4992856 cast */
    /* @4992860 call */
    GM_SITE(vm, 661, 4992860);
    /* @4992868 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4992872 string */
    /* @4992880 cast */
    /* @4992884 constant */
    /* @4992888 load */
    /* @4992896 cast */
    /* @4992900 load */
    /* @4992908 constant */
    /* @4992912 add */
    /* @4992916 constant */
    /* @4992920 load */
    /* @4992928 cast */
    /* @4992932 load */
    /* @4992940 constant */
    /* @4992944 add */
    /* @4992948 call */
    GM_SITE(vm, 661, 4992948);
    v61 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    v62 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4992956 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v61, v62, STR_REF(1146)));
    /* @4992960 string */
    /* @4992968 cast */
    /* @4992972 constant */
    /* @4992976 load */
    /* @4992984 cast */
    /* @4992988 load */
    /* @4992996 constant */
    /* @4993000 add */
    /* @4993004 constant */
    /* @4993008 load */
    /* @4993016 cast */
    /* @4993020 load */
    /* @4993028 constant */
    /* @4993032 add */
    /* @4993036 call */
    GM_SITE(vm, 661, 4993036);
    v63 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    v64 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4993044 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v63, v64, STR_REF(1147)));
    L_4993048: ;
    /* @4993048 load */
    /* @4993056 constant */
    /* @4993060 cmp */
    /* @4993064 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4993288;
    /* @4993068 constant */
    /* @4993072 cast */
    /* @4993076 call */
    GM_SITE(vm, 661, 4993076);
    /* @4993084 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4993088 constant */
    /* @4993096 cast */
    /* @4993100 call */
    GM_SITE(vm, 661, 4993100);
    /* @4993108 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4993112 string */
    /* @4993120 cast */
    /* @4993124 constant */
    /* @4993128 load */
    /* @4993136 cast */
    /* @4993140 load */
    /* @4993148 constant */
    /* @4993152 add */
    /* @4993156 constant */
    /* @4993160 load */
    /* @4993168 cast */
    /* @4993172 load */
    /* @4993180 constant */
    /* @4993184 add */
    /* @4993188 call */
    GM_SITE(vm, 661, 4993188);
    v65 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v66 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    /* @4993196 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v65, v66, STR_REF(1146)));
    /* @4993200 string */
    /* @4993208 cast */
    /* @4993212 constant */
    /* @4993216 load */
    /* @4993224 cast */
    /* @4993228 load */
    /* @4993236 constant */
    /* @4993240 add */
    /* @4993244 constant */
    /* @4993248 load */
    /* @4993256 cast */
    /* @4993260 load */
    /* @4993268 constant */
    /* @4993272 add */
    /* @4993276 call */
    GM_SITE(vm, 661, 4993276);
    v67 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v68 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(140));
    /* @4993284 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v67, v68, STR_REF(1147)));
    L_4993288: ;
    /* @4993288 load */
    /* @4993296 constant */
    /* @4993300 cmp */
    /* @4993304 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4993528;
    /* @4993308 constant */
    /* @4993312 cast */
    /* @4993316 call */
    GM_SITE(vm, 661, 4993316);
    /* @4993324 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4993328 constant */
    /* @4993336 cast */
    /* @4993340 call */
    GM_SITE(vm, 661, 4993340);
    /* @4993348 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4993352 string */
    /* @4993360 cast */
    /* @4993364 constant */
    /* @4993368 load */
    /* @4993376 cast */
    /* @4993380 load */
    /* @4993388 constant */
    /* @4993392 add */
    /* @4993396 constant */
    /* @4993400 load */
    /* @4993408 cast */
    /* @4993412 load */
    /* @4993420 constant */
    /* @4993424 add */
    /* @4993428 call */
    GM_SITE(vm, 661, 4993428);
    v69 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v70 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4993436 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v69, v70, STR_REF(1146)));
    /* @4993440 string */
    /* @4993448 cast */
    /* @4993452 constant */
    /* @4993456 load */
    /* @4993464 cast */
    /* @4993468 load */
    /* @4993476 constant */
    /* @4993480 add */
    /* @4993484 constant */
    /* @4993488 load */
    /* @4993496 cast */
    /* @4993500 load */
    /* @4993508 constant */
    /* @4993512 add */
    /* @4993516 call */
    GM_SITE(vm, 661, 4993516);
    v71 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v72 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4993524 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v71, v72, STR_REF(1147)));
    L_4993528: ;
    /* @4993528 load */
    /* @4993536 constant */
    /* @4993540 cmp */
    /* @4993544 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4993768;
    /* @4993548 constant */
    /* @4993552 cast */
    /* @4993556 call */
    GM_SITE(vm, 661, 4993556);
    /* @4993564 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4993568 constant */
    /* @4993576 cast */
    /* @4993580 call */
    GM_SITE(vm, 661, 4993580);
    /* @4993588 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4993592 string */
    /* @4993600 cast */
    /* @4993604 constant */
    /* @4993608 load */
    /* @4993616 cast */
    /* @4993620 load */
    /* @4993628 constant */
    /* @4993632 add */
    /* @4993636 constant */
    /* @4993640 load */
    /* @4993648 cast */
    /* @4993652 load */
    /* @4993660 constant */
    /* @4993664 add */
    /* @4993668 call */
    GM_SITE(vm, 661, 4993668);
    v73 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v74 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4993676 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v73, v74, STR_REF(1146)));
    /* @4993680 string */
    /* @4993688 cast */
    /* @4993692 constant */
    /* @4993696 load */
    /* @4993704 cast */
    /* @4993708 load */
    /* @4993716 constant */
    /* @4993720 add */
    /* @4993724 constant */
    /* @4993728 load */
    /* @4993736 cast */
    /* @4993740 load */
    /* @4993748 constant */
    /* @4993752 add */
    /* @4993756 call */
    GM_SITE(vm, 661, 4993756);
    v75 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v76 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4993764 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v75, v76, STR_REF(1147)));
    L_4993768: ;
    /* @4993768 load */
    /* @4993776 constant */
    /* @4993780 cmp */
    /* @4993784 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4994008;
    /* @4993788 constant */
    /* @4993792 cast */
    /* @4993796 call */
    GM_SITE(vm, 661, 4993796);
    /* @4993804 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4993808 constant */
    /* @4993816 cast */
    /* @4993820 call */
    GM_SITE(vm, 661, 4993820);
    /* @4993828 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4993832 string */
    /* @4993840 cast */
    /* @4993844 constant */
    /* @4993848 load */
    /* @4993856 cast */
    /* @4993860 load */
    /* @4993868 constant */
    /* @4993872 add */
    /* @4993876 constant */
    /* @4993880 load */
    /* @4993888 cast */
    /* @4993892 load */
    /* @4993900 constant */
    /* @4993904 add */
    /* @4993908 call */
    GM_SITE(vm, 661, 4993908);
    v77 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    v78 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4993916 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v77, v78, STR_REF(1146)));
    /* @4993920 string */
    /* @4993928 cast */
    /* @4993932 constant */
    /* @4993936 load */
    /* @4993944 cast */
    /* @4993948 load */
    /* @4993956 constant */
    /* @4993960 add */
    /* @4993964 constant */
    /* @4993968 load */
    /* @4993976 cast */
    /* @4993980 load */
    /* @4993988 constant */
    /* @4993992 add */
    /* @4993996 call */
    GM_SITE(vm, 661, 4993996);
    v79 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    v80 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4994004 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v79, v80, STR_REF(1147)));
    L_4994008: ;
    /* @4994008 load */
    /* @4994016 constant */
    /* @4994020 cmp */
    /* @4994024 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4994248;
    /* @4994028 constant */
    /* @4994032 cast */
    /* @4994036 call */
    GM_SITE(vm, 661, 4994036);
    /* @4994044 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4994048 constant */
    /* @4994056 cast */
    /* @4994060 call */
    GM_SITE(vm, 661, 4994060);
    /* @4994068 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4994072 string */
    /* @4994080 cast */
    /* @4994084 constant */
    /* @4994088 load */
    /* @4994096 cast */
    /* @4994100 load */
    /* @4994108 constant */
    /* @4994112 add */
    /* @4994116 constant */
    /* @4994120 load */
    /* @4994128 cast */
    /* @4994132 load */
    /* @4994140 constant */
    /* @4994144 add */
    /* @4994148 call */
    GM_SITE(vm, 661, 4994148);
    v81 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    v82 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4994156 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v81, v82, STR_REF(1146)));
    /* @4994160 string */
    /* @4994168 cast */
    /* @4994172 constant */
    /* @4994176 load */
    /* @4994184 cast */
    /* @4994188 load */
    /* @4994196 constant */
    /* @4994200 add */
    /* @4994204 constant */
    /* @4994208 load */
    /* @4994216 cast */
    /* @4994220 load */
    /* @4994228 constant */
    /* @4994232 add */
    /* @4994236 call */
    GM_SITE(vm, 661, 4994236);
    v83 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    v84 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4994244 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v83, v84, STR_REF(1147)));
    L_4994248: ;
    /* @4994248 load */
    /* @4994256 constant */
    /* @4994260 cmp */
    /* @4994264 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel3") == VAL(1)))) goto L_4995708;
    /* @4994268 load */
    /* @4994276 constant */
    /* @4994280 cmp */
    /* @4994284 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4994508;
    /* @4994288 constant */
    /* @4994292 cast */
    /* @4994296 call */
    GM_SITE(vm, 661, 4994296);
    /* @4994304 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4994308 constant */
    /* @4994316 cast */
    /* @4994320 call */
    GM_SITE(vm, 661, 4994320);
    /* @4994328 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4994332 string */
    /* @4994340 cast */
    /* @4994344 constant */
    /* @4994348 load */
    /* @4994356 cast */
    /* @4994360 load */
    /* @4994368 constant */
    /* @4994372 add */
    /* @4994376 constant */
    /* @4994380 load */
    /* @4994388 cast */
    /* @4994392 load */
    /* @4994400 constant */
    /* @4994404 add */
    /* @4994408 call */
    GM_SITE(vm, 661, 4994408);
    v85 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v86 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4994416 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v85, v86, STR_REF(1148)));
    /* @4994420 string */
    /* @4994428 cast */
    /* @4994432 constant */
    /* @4994436 load */
    /* @4994444 cast */
    /* @4994448 load */
    /* @4994456 constant */
    /* @4994460 add */
    /* @4994464 constant */
    /* @4994468 load */
    /* @4994476 cast */
    /* @4994480 load */
    /* @4994488 constant */
    /* @4994492 add */
    /* @4994496 call */
    GM_SITE(vm, 661, 4994496);
    v87 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v88 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4994504 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v87, v88, STR_REF(1149)));
    L_4994508: ;
    /* @4994508 load */
    /* @4994516 constant */
    /* @4994520 cmp */
    /* @4994524 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4994748;
    /* @4994528 constant */
    /* @4994532 cast */
    /* @4994536 call */
    GM_SITE(vm, 661, 4994536);
    /* @4994544 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4994548 constant */
    /* @4994556 cast */
    /* @4994560 call */
    GM_SITE(vm, 661, 4994560);
    /* @4994568 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4994572 string */
    /* @4994580 cast */
    /* @4994584 constant */
    /* @4994588 load */
    /* @4994596 cast */
    /* @4994600 load */
    /* @4994608 constant */
    /* @4994612 add */
    /* @4994616 constant */
    /* @4994620 load */
    /* @4994628 cast */
    /* @4994632 load */
    /* @4994640 constant */
    /* @4994644 add */
    /* @4994648 call */
    GM_SITE(vm, 661, 4994648);
    v89 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v90 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4994656 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v89, v90, STR_REF(1148)));
    /* @4994660 string */
    /* @4994668 cast */
    /* @4994672 constant */
    /* @4994676 load */
    /* @4994684 cast */
    /* @4994688 load */
    /* @4994696 constant */
    /* @4994700 add */
    /* @4994704 constant */
    /* @4994708 load */
    /* @4994716 cast */
    /* @4994720 load */
    /* @4994728 constant */
    /* @4994732 add */
    /* @4994736 call */
    GM_SITE(vm, 661, 4994736);
    v91 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v92 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4994744 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v91, v92, STR_REF(1149)));
    L_4994748: ;
    /* @4994748 load */
    /* @4994756 constant */
    /* @4994760 cmp */
    /* @4994764 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4994988;
    /* @4994768 constant */
    /* @4994772 cast */
    /* @4994776 call */
    GM_SITE(vm, 661, 4994776);
    /* @4994784 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4994788 constant */
    /* @4994796 cast */
    /* @4994800 call */
    GM_SITE(vm, 661, 4994800);
    /* @4994808 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4994812 string */
    /* @4994820 cast */
    /* @4994824 constant */
    /* @4994828 load */
    /* @4994836 cast */
    /* @4994840 load */
    /* @4994848 constant */
    /* @4994852 add */
    /* @4994856 constant */
    /* @4994860 load */
    /* @4994868 cast */
    /* @4994872 load */
    /* @4994880 constant */
    /* @4994884 add */
    /* @4994888 call */
    GM_SITE(vm, 661, 4994888);
    v93 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v94 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4994896 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v93, v94, STR_REF(1148)));
    /* @4994900 string */
    /* @4994908 cast */
    /* @4994912 constant */
    /* @4994916 load */
    /* @4994924 cast */
    /* @4994928 load */
    /* @4994936 constant */
    /* @4994940 add */
    /* @4994944 constant */
    /* @4994948 load */
    /* @4994956 cast */
    /* @4994960 load */
    /* @4994968 constant */
    /* @4994972 add */
    /* @4994976 call */
    GM_SITE(vm, 661, 4994976);
    v95 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v96 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4994984 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v95, v96, STR_REF(1149)));
    L_4994988: ;
    /* @4994988 load */
    /* @4994996 constant */
    /* @4995000 cmp */
    /* @4995004 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4995228;
    /* @4995008 constant */
    /* @4995012 cast */
    /* @4995016 call */
    GM_SITE(vm, 661, 4995016);
    /* @4995024 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4995028 constant */
    /* @4995036 cast */
    /* @4995040 call */
    GM_SITE(vm, 661, 4995040);
    /* @4995048 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4995052 string */
    /* @4995060 cast */
    /* @4995064 constant */
    /* @4995068 load */
    /* @4995076 cast */
    /* @4995080 load */
    /* @4995088 constant */
    /* @4995092 add */
    /* @4995096 constant */
    /* @4995100 load */
    /* @4995108 cast */
    /* @4995112 load */
    /* @4995120 constant */
    /* @4995124 add */
    /* @4995128 call */
    GM_SITE(vm, 661, 4995128);
    v97 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v98 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4995136 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v97, v98, STR_REF(1148)));
    /* @4995140 string */
    /* @4995148 cast */
    /* @4995152 constant */
    /* @4995156 load */
    /* @4995164 cast */
    /* @4995168 load */
    /* @4995176 constant */
    /* @4995180 add */
    /* @4995184 constant */
    /* @4995188 load */
    /* @4995196 cast */
    /* @4995200 load */
    /* @4995208 constant */
    /* @4995212 add */
    /* @4995216 call */
    GM_SITE(vm, 661, 4995216);
    v99 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v100 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4995224 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v99, v100, STR_REF(1149)));
    L_4995228: ;
    /* @4995228 load */
    /* @4995236 constant */
    /* @4995240 cmp */
    /* @4995244 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4995468;
    /* @4995248 constant */
    /* @4995252 cast */
    /* @4995256 call */
    GM_SITE(vm, 661, 4995256);
    /* @4995264 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4995268 constant */
    /* @4995276 cast */
    /* @4995280 call */
    GM_SITE(vm, 661, 4995280);
    /* @4995288 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4995292 string */
    /* @4995300 cast */
    /* @4995304 constant */
    /* @4995308 load */
    /* @4995316 cast */
    /* @4995320 load */
    /* @4995328 constant */
    /* @4995332 add */
    /* @4995336 constant */
    /* @4995340 load */
    /* @4995348 cast */
    /* @4995352 load */
    /* @4995360 constant */
    /* @4995364 add */
    /* @4995368 call */
    GM_SITE(vm, 661, 4995368);
    v101 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v102 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4995376 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v101, v102, STR_REF(1148)));
    /* @4995380 string */
    /* @4995388 cast */
    /* @4995392 constant */
    /* @4995396 load */
    /* @4995404 cast */
    /* @4995408 load */
    /* @4995416 constant */
    /* @4995420 add */
    /* @4995424 constant */
    /* @4995428 load */
    /* @4995436 cast */
    /* @4995440 load */
    /* @4995448 constant */
    /* @4995452 add */
    /* @4995456 call */
    GM_SITE(vm, 661, 4995456);
    v103 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v104 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4995464 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v103, v104, STR_REF(1149)));
    L_4995468: ;
    /* @4995468 load */
    /* @4995476 constant */
    /* @4995480 cmp */
    /* @4995484 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4995708;
    /* @4995488 constant */
    /* @4995492 cast */
    /* @4995496 call */
    GM_SITE(vm, 661, 4995496);
    /* @4995504 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4995508 constant */
    /* @4995516 cast */
    /* @4995520 call */
    GM_SITE(vm, 661, 4995520);
    /* @4995528 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4995532 string */
    /* @4995540 cast */
    /* @4995544 constant */
    /* @4995548 load */
    /* @4995556 cast */
    /* @4995560 load */
    /* @4995568 constant */
    /* @4995572 add */
    /* @4995576 constant */
    /* @4995580 load */
    /* @4995588 cast */
    /* @4995592 load */
    /* @4995600 constant */
    /* @4995604 add */
    /* @4995608 call */
    GM_SITE(vm, 661, 4995608);
    v105 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v106 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4995616 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v105, v106, STR_REF(1148)));
    /* @4995620 string */
    /* @4995628 cast */
    /* @4995632 constant */
    /* @4995636 load */
    /* @4995644 cast */
    /* @4995648 load */
    /* @4995656 constant */
    /* @4995660 add */
    /* @4995664 constant */
    /* @4995668 load */
    /* @4995676 cast */
    /* @4995680 load */
    /* @4995688 constant */
    /* @4995692 add */
    /* @4995696 call */
    GM_SITE(vm, 661, 4995696);
    v107 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v108 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4995704 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v107, v108, STR_REF(1149)));
    L_4995708: ;
    /* @4995708 load */
    /* @4995716 constant */
    /* @4995720 cmp */
    /* @4995724 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel4") == VAL(1)))) goto L_4997168;
    /* @4995728 load */
    /* @4995736 constant */
    /* @4995740 cmp */
    /* @4995744 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4995968;
    /* @4995748 constant */
    /* @4995752 cast */
    /* @4995756 call */
    GM_SITE(vm, 661, 4995756);
    /* @4995764 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4995768 constant */
    /* @4995776 cast */
    /* @4995780 call */
    GM_SITE(vm, 661, 4995780);
    /* @4995788 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4995792 string */
    /* @4995800 cast */
    /* @4995804 constant */
    /* @4995808 load */
    /* @4995816 cast */
    /* @4995820 load */
    /* @4995828 constant */
    /* @4995832 add */
    /* @4995836 constant */
    /* @4995840 load */
    /* @4995848 cast */
    /* @4995852 load */
    /* @4995860 constant */
    /* @4995864 add */
    /* @4995868 call */
    GM_SITE(vm, 661, 4995868);
    v109 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v110 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4995876 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v109, v110, STR_REF(1150)));
    /* @4995880 string */
    /* @4995888 cast */
    /* @4995892 constant */
    /* @4995896 load */
    /* @4995904 cast */
    /* @4995908 load */
    /* @4995916 constant */
    /* @4995920 add */
    /* @4995924 constant */
    /* @4995928 load */
    /* @4995936 cast */
    /* @4995940 load */
    /* @4995948 constant */
    /* @4995952 add */
    /* @4995956 call */
    GM_SITE(vm, 661, 4995956);
    v111 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v112 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4995964 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v111, v112, STR_REF(1151)));
    L_4995968: ;
    /* @4995968 load */
    /* @4995976 constant */
    /* @4995980 cmp */
    /* @4995984 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4996208;
    /* @4995988 constant */
    /* @4995992 cast */
    /* @4995996 call */
    GM_SITE(vm, 661, 4995996);
    /* @4996004 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4996008 constant */
    /* @4996016 cast */
    /* @4996020 call */
    GM_SITE(vm, 661, 4996020);
    /* @4996028 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4996032 string */
    /* @4996040 cast */
    /* @4996044 constant */
    /* @4996048 load */
    /* @4996056 cast */
    /* @4996060 load */
    /* @4996068 constant */
    /* @4996072 add */
    /* @4996076 constant */
    /* @4996080 load */
    /* @4996088 cast */
    /* @4996092 load */
    /* @4996100 constant */
    /* @4996104 add */
    /* @4996108 call */
    GM_SITE(vm, 661, 4996108);
    v113 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v114 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4996116 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v113, v114, STR_REF(1150)));
    /* @4996120 string */
    /* @4996128 cast */
    /* @4996132 constant */
    /* @4996136 load */
    /* @4996144 cast */
    /* @4996148 load */
    /* @4996156 constant */
    /* @4996160 add */
    /* @4996164 constant */
    /* @4996168 load */
    /* @4996176 cast */
    /* @4996180 load */
    /* @4996188 constant */
    /* @4996192 add */
    /* @4996196 call */
    GM_SITE(vm, 661, 4996196);
    v115 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v116 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4996204 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v115, v116, STR_REF(1151)));
    L_4996208: ;
    /* @4996208 load */
    /* @4996216 constant */
    /* @4996220 cmp */
    /* @4996224 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4996448;
    /* @4996228 constant */
    /* @4996232 cast */
    /* @4996236 call */
    GM_SITE(vm, 661, 4996236);
    /* @4996244 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4996248 constant */
    /* @4996256 cast */
    /* @4996260 call */
    GM_SITE(vm, 661, 4996260);
    /* @4996268 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4996272 string */
    /* @4996280 cast */
    /* @4996284 constant */
    /* @4996288 load */
    /* @4996296 cast */
    /* @4996300 load */
    /* @4996308 constant */
    /* @4996312 add */
    /* @4996316 constant */
    /* @4996320 load */
    /* @4996328 cast */
    /* @4996332 load */
    /* @4996340 constant */
    /* @4996344 add */
    /* @4996348 call */
    GM_SITE(vm, 661, 4996348);
    v117 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v118 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4996356 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v117, v118, STR_REF(1150)));
    /* @4996360 string */
    /* @4996368 cast */
    /* @4996372 constant */
    /* @4996376 load */
    /* @4996384 cast */
    /* @4996388 load */
    /* @4996396 constant */
    /* @4996400 add */
    /* @4996404 constant */
    /* @4996408 load */
    /* @4996416 cast */
    /* @4996420 load */
    /* @4996428 constant */
    /* @4996432 add */
    /* @4996436 call */
    GM_SITE(vm, 661, 4996436);
    v119 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v120 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4996444 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v119, v120, STR_REF(1151)));
    L_4996448: ;
    /* @4996448 load */
    /* @4996456 constant */
    /* @4996460 cmp */
    /* @4996464 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4996688;
    /* @4996468 constant */
    /* @4996472 cast */
    /* @4996476 call */
    GM_SITE(vm, 661, 4996476);
    /* @4996484 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4996488 constant */
    /* @4996496 cast */
    /* @4996500 call */
    GM_SITE(vm, 661, 4996500);
    /* @4996508 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4996512 string */
    /* @4996520 cast */
    /* @4996524 constant */
    /* @4996528 load */
    /* @4996536 cast */
    /* @4996540 load */
    /* @4996548 constant */
    /* @4996552 add */
    /* @4996556 constant */
    /* @4996560 load */
    /* @4996568 cast */
    /* @4996572 load */
    /* @4996580 constant */
    /* @4996584 add */
    /* @4996588 call */
    GM_SITE(vm, 661, 4996588);
    v121 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v122 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4996596 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v121, v122, STR_REF(1150)));
    /* @4996600 string */
    /* @4996608 cast */
    /* @4996612 constant */
    /* @4996616 load */
    /* @4996624 cast */
    /* @4996628 load */
    /* @4996636 constant */
    /* @4996640 add */
    /* @4996644 constant */
    /* @4996648 load */
    /* @4996656 cast */
    /* @4996660 load */
    /* @4996668 constant */
    /* @4996672 add */
    /* @4996676 call */
    GM_SITE(vm, 661, 4996676);
    v123 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v124 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4996684 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v123, v124, STR_REF(1151)));
    L_4996688: ;
    /* @4996688 load */
    /* @4996696 constant */
    /* @4996700 cmp */
    /* @4996704 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4996928;
    /* @4996708 constant */
    /* @4996712 cast */
    /* @4996716 call */
    GM_SITE(vm, 661, 4996716);
    /* @4996724 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4996728 constant */
    /* @4996736 cast */
    /* @4996740 call */
    GM_SITE(vm, 661, 4996740);
    /* @4996748 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4996752 string */
    /* @4996760 cast */
    /* @4996764 constant */
    /* @4996768 load */
    /* @4996776 cast */
    /* @4996780 load */
    /* @4996788 constant */
    /* @4996792 add */
    /* @4996796 constant */
    /* @4996800 load */
    /* @4996808 cast */
    /* @4996812 load */
    /* @4996820 constant */
    /* @4996824 add */
    /* @4996828 call */
    GM_SITE(vm, 661, 4996828);
    v125 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v126 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4996836 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v125, v126, STR_REF(1150)));
    /* @4996840 string */
    /* @4996848 cast */
    /* @4996852 constant */
    /* @4996856 load */
    /* @4996864 cast */
    /* @4996868 load */
    /* @4996876 constant */
    /* @4996880 add */
    /* @4996884 constant */
    /* @4996888 load */
    /* @4996896 cast */
    /* @4996900 load */
    /* @4996908 constant */
    /* @4996912 add */
    /* @4996916 call */
    GM_SITE(vm, 661, 4996916);
    v127 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v128 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4996924 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v127, v128, STR_REF(1151)));
    L_4996928: ;
    /* @4996928 load */
    /* @4996936 constant */
    /* @4996940 cmp */
    /* @4996944 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4997168;
    /* @4996948 constant */
    /* @4996952 cast */
    /* @4996956 call */
    GM_SITE(vm, 661, 4996956);
    /* @4996964 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4996968 constant */
    /* @4996976 cast */
    /* @4996980 call */
    GM_SITE(vm, 661, 4996980);
    /* @4996988 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4996992 string */
    /* @4997000 cast */
    /* @4997004 constant */
    /* @4997008 load */
    /* @4997016 cast */
    /* @4997020 load */
    /* @4997028 constant */
    /* @4997032 add */
    /* @4997036 constant */
    /* @4997040 load */
    /* @4997048 cast */
    /* @4997052 load */
    /* @4997060 constant */
    /* @4997064 add */
    /* @4997068 call */
    GM_SITE(vm, 661, 4997068);
    v129 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v130 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4997076 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v129, v130, STR_REF(1150)));
    /* @4997080 string */
    /* @4997088 cast */
    /* @4997092 constant */
    /* @4997096 load */
    /* @4997104 cast */
    /* @4997108 load */
    /* @4997116 constant */
    /* @4997120 add */
    /* @4997124 constant */
    /* @4997128 load */
    /* @4997136 cast */
    /* @4997140 load */
    /* @4997148 constant */
    /* @4997152 add */
    /* @4997156 call */
    GM_SITE(vm, 661, 4997156);
    v131 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v132 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4997164 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v131, v132, STR_REF(1151)));
    L_4997168: ;
    /* @4997168 load */
    /* @4997176 constant */
    /* @4997180 cmp */
    /* @4997184 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel5") == VAL(1)))) goto L_5001796;
    /* @4997188 load */
    /* @4997196 constant */
    /* @4997200 cmp */
    /* @4997204 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4997956;
    /* @4997208 constant */
    /* @4997212 cast */
    /* @4997216 call */
    GM_SITE(vm, 661, 4997216);
    /* @4997224 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4997228 constant */
    /* @4997236 cast */
    /* @4997240 call */
    GM_SITE(vm, 661, 4997240);
    /* @4997248 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4997252 string */
    /* @4997260 cast */
    /* @4997264 constant */
    /* @4997268 load */
    /* @4997276 cast */
    /* @4997280 load */
    /* @4997288 constant */
    /* @4997292 add */
    /* @4997296 constant */
    /* @4997300 load */
    /* @4997308 cast */
    /* @4997312 load */
    /* @4997320 constant */
    /* @4997324 add */
    /* @4997328 call */
    GM_SITE(vm, 661, 4997328);
    v133 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v134 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4997336 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v133, v134, STR_REF(1152)));
    /* @4997340 string */
    /* @4997348 cast */
    /* @4997352 constant */
    /* @4997356 load */
    /* @4997364 cast */
    /* @4997368 load */
    /* @4997376 constant */
    /* @4997380 add */
    /* @4997384 constant */
    /* @4997388 load */
    /* @4997396 cast */
    /* @4997400 load */
    /* @4997408 constant */
    /* @4997412 add */
    /* @4997416 call */
    GM_SITE(vm, 661, 4997416);
    v135 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v136 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4997424 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v135, v136, STR_REF(1153)));
    /* @4997428 constant */
    /* @4997432 cast */
    /* @4997436 constant */
    /* @4997440 cast */
    /* @4997444 constant */
    /* @4997448 cast */
    /* @4997452 constant */
    /* @4997456 cast */
    /* @4997460 constant */
    /* @4997464 cast */
    /* @4997468 constant */
    /* @4997472 load */
    /* @4997480 cast */
    /* @4997484 load */
    /* @4997492 constant */
    /* @4997496 add */
    /* @4997500 constant */
    /* @4997504 load */
    /* @4997512 cast */
    /* @4997516 load */
    /* @4997524 constant */
    /* @4997528 add */
    /* @4997532 constant */
    /* @4997536 cast */
    /* @4997540 constant */
    /* @4997544 cast */
    /* @4997548 call */
    GM_SITE(vm, 661, 4997548);
    v137 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v138 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    /* @4997556 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(125), VAL(0), v137, v138, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4997560 constant */
    /* @4997564 cast */
    /* @4997568 constant */
    /* @4997572 cast */
    /* @4997576 constant */
    /* @4997580 cast */
    /* @4997584 constant */
    /* @4997588 cast */
    /* @4997592 constant */
    /* @4997596 cast */
    /* @4997600 constant */
    /* @4997604 load */
    /* @4997612 cast */
    /* @4997616 load */
    /* @4997624 constant */
    /* @4997628 add */
    /* @4997632 constant */
    /* @4997636 load */
    /* @4997644 cast */
    /* @4997648 load */
    /* @4997656 constant */
    /* @4997660 add */
    /* @4997664 constant */
    /* @4997668 cast */
    /* @4997672 constant */
    /* @4997676 cast */
    /* @4997680 call */
    GM_SITE(vm, 661, 4997680);
    v139 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(190));
    v140 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    /* @4997688 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(125), VAL(1), v139, v140, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4997692 constant */
    /* @4997696 cast */
    /* @4997700 constant */
    /* @4997704 cast */
    /* @4997708 constant */
    /* @4997712 cast */
    /* @4997716 constant */
    /* @4997720 cast */
    /* @4997724 constant */
    /* @4997728 cast */
    /* @4997732 constant */
    /* @4997736 load */
    /* @4997744 cast */
    /* @4997748 load */
    /* @4997756 constant */
    /* @4997760 add */
    /* @4997764 constant */
    /* @4997768 load */
    /* @4997776 cast */
    /* @4997780 load */
    /* @4997788 constant */
    /* @4997792 add */
    /* @4997796 constant */
    /* @4997800 cast */
    /* @4997804 constant */
    /* @4997808 cast */
    /* @4997812 call */
    GM_SITE(vm, 661, 4997812);
    v141 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    v142 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    /* @4997820 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(125), VAL(2), v141, v142, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4997824 constant */
    /* @4997828 cast */
    /* @4997832 constant */
    /* @4997836 cast */
    /* @4997840 constant */
    /* @4997844 cast */
    /* @4997848 constant */
    /* @4997852 cast */
    /* @4997856 constant */
    /* @4997860 cast */
    /* @4997864 constant */
    /* @4997868 load */
    /* @4997876 cast */
    /* @4997880 load */
    /* @4997888 constant */
    /* @4997892 add */
    /* @4997896 constant */
    /* @4997900 load */
    /* @4997908 cast */
    /* @4997912 load */
    /* @4997920 constant */
    /* @4997924 add */
    /* @4997928 constant */
    /* @4997932 cast */
    /* @4997936 constant */
    /* @4997940 cast */
    /* @4997944 call */
    GM_SITE(vm, 661, 4997944);
    v143 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(290));
    v144 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    /* @4997952 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(125), VAL(3), v143, v144, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    L_4997956: ;
    /* @4997956 load */
    /* @4997964 constant */
    /* @4997968 cmp */
    /* @4997972 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4998724;
    /* @4997976 constant */
    /* @4997980 cast */
    /* @4997984 call */
    GM_SITE(vm, 661, 4997984);
    /* @4997992 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4997996 constant */
    /* @4998004 cast */
    /* @4998008 call */
    GM_SITE(vm, 661, 4998008);
    /* @4998016 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4998020 string */
    /* @4998028 cast */
    /* @4998032 constant */
    /* @4998036 load */
    /* @4998044 cast */
    /* @4998048 load */
    /* @4998056 constant */
    /* @4998060 add */
    /* @4998064 constant */
    /* @4998068 load */
    /* @4998076 cast */
    /* @4998080 load */
    /* @4998088 constant */
    /* @4998092 add */
    /* @4998096 call */
    GM_SITE(vm, 661, 4998096);
    v145 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v146 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4998104 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v145, v146, STR_REF(1152)));
    /* @4998108 string */
    /* @4998116 cast */
    /* @4998120 constant */
    /* @4998124 load */
    /* @4998132 cast */
    /* @4998136 load */
    /* @4998144 constant */
    /* @4998148 add */
    /* @4998152 constant */
    /* @4998156 load */
    /* @4998164 cast */
    /* @4998168 load */
    /* @4998176 constant */
    /* @4998180 add */
    /* @4998184 call */
    GM_SITE(vm, 661, 4998184);
    v147 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v148 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4998192 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v147, v148, STR_REF(1153)));
    /* @4998196 constant */
    /* @4998200 cast */
    /* @4998204 constant */
    /* @4998208 cast */
    /* @4998212 constant */
    /* @4998216 cast */
    /* @4998220 constant */
    /* @4998224 cast */
    /* @4998228 constant */
    /* @4998232 cast */
    /* @4998236 constant */
    /* @4998240 load */
    /* @4998248 cast */
    /* @4998252 load */
    /* @4998260 constant */
    /* @4998264 add */
    /* @4998268 constant */
    /* @4998272 load */
    /* @4998280 cast */
    /* @4998284 load */
    /* @4998292 constant */
    /* @4998296 add */
    /* @4998300 constant */
    /* @4998304 cast */
    /* @4998308 constant */
    /* @4998312 cast */
    /* @4998316 call */
    GM_SITE(vm, 661, 4998316);
    v149 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v150 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    /* @4998324 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(125), VAL(0), v149, v150, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4998328 constant */
    /* @4998332 cast */
    /* @4998336 constant */
    /* @4998340 cast */
    /* @4998344 constant */
    /* @4998348 cast */
    /* @4998352 constant */
    /* @4998356 cast */
    /* @4998360 constant */
    /* @4998364 cast */
    /* @4998368 constant */
    /* @4998372 load */
    /* @4998380 cast */
    /* @4998384 load */
    /* @4998392 constant */
    /* @4998396 add */
    /* @4998400 constant */
    /* @4998404 load */
    /* @4998412 cast */
    /* @4998416 load */
    /* @4998424 constant */
    /* @4998428 add */
    /* @4998432 constant */
    /* @4998436 cast */
    /* @4998440 constant */
    /* @4998444 cast */
    /* @4998448 call */
    GM_SITE(vm, 661, 4998448);
    v151 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(190));
    v152 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    /* @4998456 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(125), VAL(1), v151, v152, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4998460 constant */
    /* @4998464 cast */
    /* @4998468 constant */
    /* @4998472 cast */
    /* @4998476 constant */
    /* @4998480 cast */
    /* @4998484 constant */
    /* @4998488 cast */
    /* @4998492 constant */
    /* @4998496 cast */
    /* @4998500 constant */
    /* @4998504 load */
    /* @4998512 cast */
    /* @4998516 load */
    /* @4998524 constant */
    /* @4998528 add */
    /* @4998532 constant */
    /* @4998536 load */
    /* @4998544 cast */
    /* @4998548 load */
    /* @4998556 constant */
    /* @4998560 add */
    /* @4998564 constant */
    /* @4998568 cast */
    /* @4998572 constant */
    /* @4998576 cast */
    /* @4998580 call */
    GM_SITE(vm, 661, 4998580);
    v153 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    v154 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    /* @4998588 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(125), VAL(2), v153, v154, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4998592 constant */
    /* @4998596 cast */
    /* @4998600 constant */
    /* @4998604 cast */
    /* @4998608 constant */
    /* @4998612 cast */
    /* @4998616 constant */
    /* @4998620 cast */
    /* @4998624 constant */
    /* @4998628 cast */
    /* @4998632 constant */
    /* @4998636 load */
    /* @4998644 cast */
    /* @4998648 load */
    /* @4998656 constant */
    /* @4998660 add */
    /* @4998664 constant */
    /* @4998668 load */
    /* @4998676 cast */
    /* @4998680 load */
    /* @4998688 constant */
    /* @4998692 add */
    /* @4998696 constant */
    /* @4998700 cast */
    /* @4998704 constant */
    /* @4998708 cast */
    /* @4998712 call */
    GM_SITE(vm, 661, 4998712);
    v155 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(290));
    v156 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    /* @4998720 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(125), VAL(3), v155, v156, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    L_4998724: ;
    /* @4998724 load */
    /* @4998732 constant */
    /* @4998736 cmp */
    /* @4998740 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4999492;
    /* @4998744 constant */
    /* @4998748 cast */
    /* @4998752 call */
    GM_SITE(vm, 661, 4998752);
    /* @4998760 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4998764 constant */
    /* @4998772 cast */
    /* @4998776 call */
    GM_SITE(vm, 661, 4998776);
    /* @4998784 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4998788 string */
    /* @4998796 cast */
    /* @4998800 constant */
    /* @4998804 load */
    /* @4998812 cast */
    /* @4998816 load */
    /* @4998824 constant */
    /* @4998828 add */
    /* @4998832 constant */
    /* @4998836 load */
    /* @4998844 cast */
    /* @4998848 load */
    /* @4998856 constant */
    /* @4998860 add */
    /* @4998864 call */
    GM_SITE(vm, 661, 4998864);
    v157 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v158 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4998872 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v157, v158, STR_REF(1152)));
    /* @4998876 string */
    /* @4998884 cast */
    /* @4998888 constant */
    /* @4998892 load */
    /* @4998900 cast */
    /* @4998904 load */
    /* @4998912 constant */
    /* @4998916 add */
    /* @4998920 constant */
    /* @4998924 load */
    /* @4998932 cast */
    /* @4998936 load */
    /* @4998944 constant */
    /* @4998948 add */
    /* @4998952 call */
    GM_SITE(vm, 661, 4998952);
    v159 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v160 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4998960 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v159, v160, STR_REF(1153)));
    /* @4998964 constant */
    /* @4998968 cast */
    /* @4998972 constant */
    /* @4998976 cast */
    /* @4998980 constant */
    /* @4998984 cast */
    /* @4998988 constant */
    /* @4998992 cast */
    /* @4998996 constant */
    /* @4999000 cast */
    /* @4999004 constant */
    /* @4999008 load */
    /* @4999016 cast */
    /* @4999020 load */
    /* @4999028 constant */
    /* @4999032 add */
    /* @4999036 constant */
    /* @4999040 load */
    /* @4999048 cast */
    /* @4999052 load */
    /* @4999060 constant */
    /* @4999064 add */
    /* @4999068 constant */
    /* @4999072 cast */
    /* @4999076 constant */
    /* @4999080 cast */
    /* @4999084 call */
    GM_SITE(vm, 661, 4999084);
    v161 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    v162 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(160));
    /* @4999092 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(125), VAL(0), v161, v162, VAL(4), VAL(4), VAL(0), VAL(-1), VAL(1)));
    /* @4999096 constant */
    /* @4999100 cast */
    /* @4999104 constant */
    /* @4999108 cast */
    /* @4999112 constant */
    /* @4999116 cast */
    /* @4999120 constant */
    /* @4999124 cast */
    /* @4999128 constant */
    /* @4999132 cast */
    /* @4999136 constant */
    /* @4999140 load */
    /* @4999148 cast */
    /* @4999152 load */
    /* @4999160 constant */
    /* @4999164 add */
    /* @4999168 constant */
    /* @4999172 load */
    /* @4999180 cast */
    /* @4999184 load */
    /* @4999192 constant */
    /* @4999196 add */
    /* @4999200 constant */
    /* @4999204 cast */
    /* @4999208 constant */
    /* @4999212 cast */
    /* @4999216 call */
    GM_SITE(vm, 661, 4999216);
    v163 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(230));
    v164 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(160));
    /* @4999224 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(125), VAL(1), v163, v164, VAL(4), VAL(4), VAL(0), VAL(-1), VAL(1)));
    /* @4999228 constant */
    /* @4999232 cast */
    /* @4999236 constant */
    /* @4999240 cast */
    /* @4999244 constant */
    /* @4999248 cast */
    /* @4999252 constant */
    /* @4999256 cast */
    /* @4999260 constant */
    /* @4999264 cast */
    /* @4999268 constant */
    /* @4999272 load */
    /* @4999280 cast */
    /* @4999284 load */
    /* @4999292 constant */
    /* @4999296 add */
    /* @4999300 constant */
    /* @4999304 load */
    /* @4999312 cast */
    /* @4999316 load */
    /* @4999324 constant */
    /* @4999328 add */
    /* @4999332 constant */
    /* @4999336 cast */
    /* @4999340 constant */
    /* @4999344 cast */
    /* @4999348 call */
    GM_SITE(vm, 661, 4999348);
    v165 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(300));
    v166 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(160));
    /* @4999356 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(125), VAL(2), v165, v166, VAL(4), VAL(4), VAL(0), VAL(-1), VAL(1)));
    /* @4999360 constant */
    /* @4999364 cast */
    /* @4999368 constant */
    /* @4999372 cast */
    /* @4999376 constant */
    /* @4999380 cast */
    /* @4999384 constant */
    /* @4999388 cast */
    /* @4999392 constant */
    /* @4999396 cast */
    /* @4999400 constant */
    /* @4999404 load */
    /* @4999412 cast */
    /* @4999416 load */
    /* @4999424 constant */
    /* @4999428 add */
    /* @4999432 constant */
    /* @4999436 load */
    /* @4999444 cast */
    /* @4999448 load */
    /* @4999456 constant */
    /* @4999460 add */
    /* @4999464 constant */
    /* @4999468 cast */
    /* @4999472 constant */
    /* @4999476 cast */
    /* @4999480 call */
    GM_SITE(vm, 661, 4999480);
    v167 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(360));
    v168 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(160));
    /* @4999488 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(125), VAL(3), v167, v168, VAL(4), VAL(4), VAL(0), VAL(-1), VAL(1)));
    L_4999492: ;
    /* @4999492 load */
    /* @4999500 constant */
    /* @4999504 cmp */
    /* @4999508 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_5000260;
    /* @4999512 constant */
    /* @4999516 cast */
    /* @4999520 call */
    GM_SITE(vm, 661, 4999520);
    /* @4999528 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4999532 constant */
    /* @4999540 cast */
    /* @4999544 call */
    GM_SITE(vm, 661, 4999544);
    /* @4999552 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4999556 string */
    /* @4999564 cast */
    /* @4999568 constant */
    /* @4999572 load */
    /* @4999580 cast */
    /* @4999584 load */
    /* @4999592 constant */
    /* @4999596 add */
    /* @4999600 constant */
    /* @4999604 load */
    /* @4999612 cast */
    /* @4999616 load */
    /* @4999624 constant */
    /* @4999628 add */
    /* @4999632 call */
    GM_SITE(vm, 661, 4999632);
    v169 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v170 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4999640 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v169, v170, STR_REF(1152)));
    /* @4999644 string */
    /* @4999652 cast */
    /* @4999656 constant */
    /* @4999660 load */
    /* @4999668 cast */
    /* @4999672 load */
    /* @4999680 constant */
    /* @4999684 add */
    /* @4999688 constant */
    /* @4999692 load */
    /* @4999700 cast */
    /* @4999704 load */
    /* @4999712 constant */
    /* @4999716 add */
    /* @4999720 call */
    GM_SITE(vm, 661, 4999720);
    v171 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v172 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4999728 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v171, v172, STR_REF(1153)));
    /* @4999732 constant */
    /* @4999736 cast */
    /* @4999740 constant */
    /* @4999744 cast */
    /* @4999748 constant */
    /* @4999752 cast */
    /* @4999756 constant */
    /* @4999760 cast */
    /* @4999764 constant */
    /* @4999768 cast */
    /* @4999772 constant */
    /* @4999776 load */
    /* @4999784 cast */
    /* @4999788 load */
    /* @4999796 constant */
    /* @4999800 add */
    /* @4999804 constant */
    /* @4999808 load */
    /* @4999816 cast */
    /* @4999820 load */
    /* @4999828 constant */
    /* @4999832 add */
    /* @4999836 constant */
    /* @4999840 cast */
    /* @4999844 constant */
    /* @4999848 cast */
    /* @4999852 call */
    GM_SITE(vm, 661, 4999852);
    v173 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    v174 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(160));
    /* @4999860 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(125), VAL(0), v173, v174, VAL(4), VAL(4), VAL(0), VAL(-1), VAL(1)));
    /* @4999864 constant */
    /* @4999868 cast */
    /* @4999872 constant */
    /* @4999876 cast */
    /* @4999880 constant */
    /* @4999884 cast */
    /* @4999888 constant */
    /* @4999892 cast */
    /* @4999896 constant */
    /* @4999900 cast */
    /* @4999904 constant */
    /* @4999908 load */
    /* @4999916 cast */
    /* @4999920 load */
    /* @4999928 constant */
    /* @4999932 add */
    /* @4999936 constant */
    /* @4999940 load */
    /* @4999948 cast */
    /* @4999952 load */
    /* @4999960 constant */
    /* @4999964 add */
    /* @4999968 constant */
    /* @4999972 cast */
    /* @4999976 constant */
    /* @4999980 cast */
    /* @4999984 call */
    GM_SITE(vm, 661, 4999984);
    v175 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(230));
    v176 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(160));
    /* @4999992 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(125), VAL(1), v175, v176, VAL(4), VAL(4), VAL(0), VAL(-1), VAL(1)));
    /* @4999996 constant */
    /* @5000000 cast */
    /* @5000004 constant */
    /* @5000008 cast */
    /* @5000012 constant */
    /* @5000016 cast */
    /* @5000020 constant */
    /* @5000024 cast */
    /* @5000028 constant */
    /* @5000032 cast */
    /* @5000036 constant */
    /* @5000040 load */
    /* @5000048 cast */
    /* @5000052 load */
    /* @5000060 constant */
    /* @5000064 add */
    /* @5000068 constant */
    /* @5000072 load */
    /* @5000080 cast */
    /* @5000084 load */
    /* @5000092 constant */
    /* @5000096 add */
    /* @5000100 constant */
    /* @5000104 cast */
    /* @5000108 constant */
    /* @5000112 cast */
    /* @5000116 call */
    GM_SITE(vm, 661, 5000116);
    v177 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(300));
    v178 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(160));
    /* @5000124 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(125), VAL(2), v177, v178, VAL(4), VAL(4), VAL(0), VAL(-1), VAL(1)));
    /* @5000128 constant */
    /* @5000132 cast */
    /* @5000136 constant */
    /* @5000140 cast */
    /* @5000144 constant */
    /* @5000148 cast */
    /* @5000152 constant */
    /* @5000156 cast */
    /* @5000160 constant */
    /* @5000164 cast */
    /* @5000168 constant */
    /* @5000172 load */
    /* @5000180 cast */
    /* @5000184 load */
    /* @5000192 constant */
    /* @5000196 add */
    /* @5000200 constant */
    /* @5000204 load */
    /* @5000212 cast */
    /* @5000216 load */
    /* @5000224 constant */
    /* @5000228 add */
    /* @5000232 constant */
    /* @5000236 cast */
    /* @5000240 constant */
    /* @5000244 cast */
    /* @5000248 call */
    GM_SITE(vm, 661, 5000248);
    v179 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(360));
    v180 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(160));
    /* @5000256 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(125), VAL(3), v179, v180, VAL(4), VAL(4), VAL(0), VAL(-1), VAL(1)));
    L_5000260: ;
    /* @5000260 load */
    /* @5000268 constant */
    /* @5000272 cmp */
    /* @5000276 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_5001028;
    /* @5000280 constant */
    /* @5000284 cast */
    /* @5000288 call */
    GM_SITE(vm, 661, 5000288);
    /* @5000296 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5000300 constant */
    /* @5000308 cast */
    /* @5000312 call */
    GM_SITE(vm, 661, 5000312);
    /* @5000320 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5000324 string */
    /* @5000332 cast */
    /* @5000336 constant */
    /* @5000340 load */
    /* @5000348 cast */
    /* @5000352 load */
    /* @5000360 constant */
    /* @5000364 add */
    /* @5000368 constant */
    /* @5000372 load */
    /* @5000380 cast */
    /* @5000384 load */
    /* @5000392 constant */
    /* @5000396 add */
    /* @5000400 call */
    GM_SITE(vm, 661, 5000400);
    v181 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v182 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @5000408 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v181, v182, STR_REF(1152)));
    /* @5000412 string */
    /* @5000420 cast */
    /* @5000424 constant */
    /* @5000428 load */
    /* @5000436 cast */
    /* @5000440 load */
    /* @5000448 constant */
    /* @5000452 add */
    /* @5000456 constant */
    /* @5000460 load */
    /* @5000468 cast */
    /* @5000472 load */
    /* @5000480 constant */
    /* @5000484 add */
    /* @5000488 call */
    GM_SITE(vm, 661, 5000488);
    v183 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v184 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @5000496 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v183, v184, STR_REF(1153)));
    /* @5000500 constant */
    /* @5000504 cast */
    /* @5000508 constant */
    /* @5000512 cast */
    /* @5000516 constant */
    /* @5000520 cast */
    /* @5000524 constant */
    /* @5000528 cast */
    /* @5000532 constant */
    /* @5000536 cast */
    /* @5000540 constant */
    /* @5000544 load */
    /* @5000552 cast */
    /* @5000556 load */
    /* @5000564 constant */
    /* @5000568 add */
    /* @5000572 constant */
    /* @5000576 load */
    /* @5000584 cast */
    /* @5000588 load */
    /* @5000596 constant */
    /* @5000600 add */
    /* @5000604 constant */
    /* @5000608 cast */
    /* @5000612 constant */
    /* @5000616 cast */
    /* @5000620 call */
    GM_SITE(vm, 661, 5000620);
    v185 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v186 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    /* @5000628 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(125), VAL(0), v185, v186, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @5000632 constant */
    /* @5000636 cast */
    /* @5000640 constant */
    /* @5000644 cast */
    /* @5000648 constant */
    /* @5000652 cast */
    /* @5000656 constant */
    /* @5000660 cast */
    /* @5000664 constant */
    /* @5000668 cast */
    /* @5000672 constant */
    /* @5000676 load */
    /* @5000684 cast */
    /* @5000688 load */
    /* @5000696 constant */
    /* @5000700 add */
    /* @5000704 constant */
    /* @5000708 load */
    /* @5000716 cast */
    /* @5000720 load */
    /* @5000728 constant */
    /* @5000732 add */
    /* @5000736 constant */
    /* @5000740 cast */
    /* @5000744 constant */
    /* @5000748 cast */
    /* @5000752 call */
    GM_SITE(vm, 661, 5000752);
    v187 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(190));
    v188 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    /* @5000760 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(125), VAL(1), v187, v188, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @5000764 constant */
    /* @5000768 cast */
    /* @5000772 constant */
    /* @5000776 cast */
    /* @5000780 constant */
    /* @5000784 cast */
    /* @5000788 constant */
    /* @5000792 cast */
    /* @5000796 constant */
    /* @5000800 cast */
    /* @5000804 constant */
    /* @5000808 load */
    /* @5000816 cast */
    /* @5000820 load */
    /* @5000828 constant */
    /* @5000832 add */
    /* @5000836 constant */
    /* @5000840 load */
    /* @5000848 cast */
    /* @5000852 load */
    /* @5000860 constant */
    /* @5000864 add */
    /* @5000868 constant */
    /* @5000872 cast */
    /* @5000876 constant */
    /* @5000880 cast */
    /* @5000884 call */
    GM_SITE(vm, 661, 5000884);
    v189 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    v190 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    /* @5000892 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(125), VAL(2), v189, v190, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @5000896 constant */
    /* @5000900 cast */
    /* @5000904 constant */
    /* @5000908 cast */
    /* @5000912 constant */
    /* @5000916 cast */
    /* @5000920 constant */
    /* @5000924 cast */
    /* @5000928 constant */
    /* @5000932 cast */
    /* @5000936 constant */
    /* @5000940 load */
    /* @5000948 cast */
    /* @5000952 load */
    /* @5000960 constant */
    /* @5000964 add */
    /* @5000968 constant */
    /* @5000972 load */
    /* @5000980 cast */
    /* @5000984 load */
    /* @5000992 constant */
    /* @5000996 add */
    /* @5001000 constant */
    /* @5001004 cast */
    /* @5001008 constant */
    /* @5001012 cast */
    /* @5001016 call */
    GM_SITE(vm, 661, 5001016);
    v191 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(290));
    v192 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    /* @5001024 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(125), VAL(3), v191, v192, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    L_5001028: ;
    /* @5001028 load */
    /* @5001036 constant */
    /* @5001040 cmp */
    /* @5001044 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_5001796;
    /* @5001048 constant */
    /* @5001052 cast */
    /* @5001056 call */
    GM_SITE(vm, 661, 5001056);
    /* @5001064 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5001068 constant */
    /* @5001076 cast */
    /* @5001080 call */
    GM_SITE(vm, 661, 5001080);
    /* @5001088 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5001092 string */
    /* @5001100 cast */
    /* @5001104 constant */
    /* @5001108 load */
    /* @5001116 cast */
    /* @5001120 load */
    /* @5001128 constant */
    /* @5001132 add */
    /* @5001136 constant */
    /* @5001140 load */
    /* @5001148 cast */
    /* @5001152 load */
    /* @5001160 constant */
    /* @5001164 add */
    /* @5001168 call */
    GM_SITE(vm, 661, 5001168);
    v193 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v194 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @5001176 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v193, v194, STR_REF(1152)));
    /* @5001180 string */
    /* @5001188 cast */
    /* @5001192 constant */
    /* @5001196 load */
    /* @5001204 cast */
    /* @5001208 load */
    /* @5001216 constant */
    /* @5001220 add */
    /* @5001224 constant */
    /* @5001228 load */
    /* @5001236 cast */
    /* @5001240 load */
    /* @5001248 constant */
    /* @5001252 add */
    /* @5001256 call */
    GM_SITE(vm, 661, 5001256);
    v195 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v196 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @5001264 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v195, v196, STR_REF(1153)));
    /* @5001268 constant */
    /* @5001272 cast */
    /* @5001276 constant */
    /* @5001280 cast */
    /* @5001284 constant */
    /* @5001288 cast */
    /* @5001292 constant */
    /* @5001296 cast */
    /* @5001300 constant */
    /* @5001304 cast */
    /* @5001308 constant */
    /* @5001312 load */
    /* @5001320 cast */
    /* @5001324 load */
    /* @5001332 constant */
    /* @5001336 add */
    /* @5001340 constant */
    /* @5001344 load */
    /* @5001352 cast */
    /* @5001356 load */
    /* @5001364 constant */
    /* @5001368 add */
    /* @5001372 constant */
    /* @5001376 cast */
    /* @5001380 constant */
    /* @5001384 cast */
    /* @5001388 call */
    GM_SITE(vm, 661, 5001388);
    v197 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v198 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    /* @5001396 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(125), VAL(0), v197, v198, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @5001400 constant */
    /* @5001404 cast */
    /* @5001408 constant */
    /* @5001412 cast */
    /* @5001416 constant */
    /* @5001420 cast */
    /* @5001424 constant */
    /* @5001428 cast */
    /* @5001432 constant */
    /* @5001436 cast */
    /* @5001440 constant */
    /* @5001444 load */
    /* @5001452 cast */
    /* @5001456 load */
    /* @5001464 constant */
    /* @5001468 add */
    /* @5001472 constant */
    /* @5001476 load */
    /* @5001484 cast */
    /* @5001488 load */
    /* @5001496 constant */
    /* @5001500 add */
    /* @5001504 constant */
    /* @5001508 cast */
    /* @5001512 constant */
    /* @5001516 cast */
    /* @5001520 call */
    GM_SITE(vm, 661, 5001520);
    v199 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(190));
    v200 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    /* @5001528 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(125), VAL(1), v199, v200, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @5001532 constant */
    /* @5001536 cast */
    /* @5001540 constant */
    /* @5001544 cast */
    /* @5001548 constant */
    /* @5001552 cast */
    /* @5001556 constant */
    /* @5001560 cast */
    /* @5001564 constant */
    /* @5001568 cast */
    /* @5001572 constant */
    /* @5001576 load */
    /* @5001584 cast */
    /* @5001588 load */
    /* @5001596 constant */
    /* @5001600 add */
    /* @5001604 constant */
    /* @5001608 load */
    /* @5001616 cast */
    /* @5001620 load */
    /* @5001628 constant */
    /* @5001632 add */
    /* @5001636 constant */
    /* @5001640 cast */
    /* @5001644 constant */
    /* @5001648 cast */
    /* @5001652 call */
    GM_SITE(vm, 661, 5001652);
    v201 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    v202 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    /* @5001660 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(125), VAL(2), v201, v202, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @5001664 constant */
    /* @5001668 cast */
    /* @5001672 constant */
    /* @5001676 cast */
    /* @5001680 constant */
    /* @5001684 cast */
    /* @5001688 constant */
    /* @5001692 cast */
    /* @5001696 constant */
    /* @5001700 cast */
    /* @5001704 constant */
    /* @5001708 load */
    /* @5001716 cast */
    /* @5001720 load */
    /* @5001728 constant */
    /* @5001732 add */
    /* @5001736 constant */
    /* @5001740 load */
    /* @5001748 cast */
    /* @5001752 load */
    /* @5001760 constant */
    /* @5001764 add */
    /* @5001768 constant */
    /* @5001772 cast */
    /* @5001776 constant */
    /* @5001780 cast */
    /* @5001784 call */
    GM_SITE(vm, 661, 5001784);
    v203 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(290));
    v204 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    /* @5001792 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(125), VAL(3), v203, v204, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    L_5001796: ;
    /* @5001796 load */
    /* @5001804 constant */
    /* @5001808 cmp */
    /* @5001812 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_5001848;
    /* @5001816 constant */
    /* @5001820 cast */
    /* @5001824 constant */
    /* @5001828 cast */
    /* @5001832 call */
    GM_SITE(vm, 661, 5001832);
    /* @5001840 cast */
    /* @5001844 b */
    v205 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, VAL(0), VAL(1)));
    p5001852_0 = v205;
    goto L_5001852;
    L_5001848: ;
    /* @5001848 constant */
    p5001852_0 = VAL(0);
    L_5001852: ;
    /* @5001852 bf */
    if (!TRUTH(p5001852_0)) goto L_5001868;
    /* @5001856 call */
    GM_SITE(vm, 661, 5001856);
    /* @5001864 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5001868: ;
    return;
}
