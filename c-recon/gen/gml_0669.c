/* generated from CODE 669 (gml_Object_obj_lloydtutorial16_Draw_0), source start 5002584, end 5013284. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0669(GmVM* vm) {
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
    Val p5013268_0;
    Val v157;
    /* @5002584 constant */
    /* @5002588 load */
    /* @5002596 cast */
    /* @5002600 load */
    /* @5002608 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @5002616 constant */
    /* @5002620 load */
    /* @5002628 cast */
    /* @5002632 load */
    /* @5002640 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @5002648 load */
    /* @5002656 constant */
    /* @5002660 cmp */
    /* @5002664 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_5003192;
    /* @5002668 constant */
    /* @5002672 cast */
    /* @5002676 constant */
    /* @5002680 cast */
    /* @5002684 constant */
    /* @5002688 cast */
    /* @5002692 constant */
    /* @5002704 cast */
    /* @5002708 constant */
    /* @5002720 cast */
    /* @5002724 constant */
    /* @5002728 constant */
    /* @5002732 load */
    /* @5002740 constant */
    /* @5002744 constant */
    /* @5002748 load */
    /* @5002756 constant */
    /* @5002760 sub */
    /* @5002764 constant */
    /* @5002768 cast */
    /* @5002772 constant */
    /* @5002776 cast */
    /* @5002780 call */
    GM_SITE(vm, 669, 5002780);
    /* @5002788 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(0.96), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @5002792 constant */
    /* @5002796 cast */
    /* @5002800 constant */
    /* @5002804 cast */
    /* @5002808 constant */
    /* @5002812 cast */
    /* @5002816 constant */
    /* @5002820 cast */
    /* @5002824 constant */
    /* @5002828 cast */
    /* @5002832 constant */
    /* @5002836 load */
    /* @5002844 cast */
    /* @5002848 load */
    /* @5002856 constant */
    /* @5002860 add */
    /* @5002864 constant */
    /* @5002868 load */
    /* @5002876 cast */
    /* @5002880 load */
    /* @5002888 constant */
    /* @5002892 add */
    /* @5002896 constant */
    /* @5002900 cast */
    /* @5002904 constant */
    /* @5002908 cast */
    /* @5002912 call */
    GM_SITE(vm, 669, 5002912);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @5002920 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v1, v2, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @5002924 constant */
    /* @5002928 cast */
    /* @5002932 constant */
    /* @5002936 cast */
    /* @5002940 constant */
    /* @5002944 cast */
    /* @5002948 constant */
    /* @5002952 cast */
    /* @5002956 constant */
    /* @5002960 cast */
    /* @5002964 constant */
    /* @5002968 load */
    /* @5002976 cast */
    /* @5002980 load */
    /* @5002988 constant */
    /* @5002992 add */
    /* @5002996 constant */
    /* @5003000 load */
    /* @5003008 cast */
    /* @5003012 load */
    /* @5003020 constant */
    /* @5003024 add */
    /* @5003028 constant */
    /* @5003032 cast */
    /* @5003036 constant */
    /* @5003040 cast */
    /* @5003044 call */
    GM_SITE(vm, 669, 5003044);
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @5003052 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v3, v4, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @5003056 load */
    /* @5003064 constant */
    /* @5003068 cmp */
    /* @5003072 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_5003192;
    /* @5003076 constant */
    /* @5003080 cast */
    /* @5003084 call */
    GM_SITE(vm, 669, 5003084);
    /* @5003092 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @5003096 constant */
    /* @5003104 cast */
    /* @5003108 call */
    GM_SITE(vm, 669, 5003108);
    /* @5003116 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5003120 string */
    /* @5003128 cast */
    /* @5003132 constant */
    /* @5003136 constant */
    /* @5003140 load */
    /* @5003148 constant */
    /* @5003152 add */
    /* @5003156 constant */
    /* @5003160 constant */
    /* @5003164 load */
    /* @5003172 constant */
    /* @5003176 add */
    /* @5003180 call */
    GM_SITE(vm, 669, 5003180);
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(150));
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(200));
    /* @5003188 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v5, v6, STR_REF(743)));
    L_5003192: ;
    /* @5003192 load */
    /* @5003200 constant */
    /* @5003204 cmp */
    /* @5003208 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_5003736;
    /* @5003212 constant */
    /* @5003216 cast */
    /* @5003220 constant */
    /* @5003224 cast */
    /* @5003228 constant */
    /* @5003232 cast */
    /* @5003236 constant */
    /* @5003248 cast */
    /* @5003252 constant */
    /* @5003264 cast */
    /* @5003268 constant */
    /* @5003272 constant */
    /* @5003276 load */
    /* @5003284 constant */
    /* @5003288 constant */
    /* @5003292 load */
    /* @5003300 constant */
    /* @5003304 sub */
    /* @5003308 constant */
    /* @5003312 cast */
    /* @5003316 constant */
    /* @5003320 cast */
    /* @5003324 call */
    GM_SITE(vm, 669, 5003324);
    /* @5003332 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(0.82), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @5003336 constant */
    /* @5003340 cast */
    /* @5003344 constant */
    /* @5003348 cast */
    /* @5003352 constant */
    /* @5003356 cast */
    /* @5003360 constant */
    /* @5003364 cast */
    /* @5003368 constant */
    /* @5003372 cast */
    /* @5003376 constant */
    /* @5003380 load */
    /* @5003388 cast */
    /* @5003392 load */
    /* @5003400 constant */
    /* @5003404 add */
    /* @5003408 constant */
    /* @5003412 load */
    /* @5003420 cast */
    /* @5003424 load */
    /* @5003432 constant */
    /* @5003436 add */
    /* @5003440 constant */
    /* @5003444 cast */
    /* @5003448 constant */
    /* @5003452 cast */
    /* @5003456 call */
    GM_SITE(vm, 669, 5003456);
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @5003464 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v7, v8, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @5003468 constant */
    /* @5003472 cast */
    /* @5003476 constant */
    /* @5003480 cast */
    /* @5003484 constant */
    /* @5003488 cast */
    /* @5003492 constant */
    /* @5003496 cast */
    /* @5003500 constant */
    /* @5003504 cast */
    /* @5003508 constant */
    /* @5003512 load */
    /* @5003520 cast */
    /* @5003524 load */
    /* @5003532 constant */
    /* @5003536 add */
    /* @5003540 constant */
    /* @5003544 load */
    /* @5003552 cast */
    /* @5003556 load */
    /* @5003564 constant */
    /* @5003568 add */
    /* @5003572 constant */
    /* @5003576 cast */
    /* @5003580 constant */
    /* @5003584 cast */
    /* @5003588 call */
    GM_SITE(vm, 669, 5003588);
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(320));
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @5003596 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v9, v10, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @5003600 load */
    /* @5003608 constant */
    /* @5003612 cmp */
    /* @5003616 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_5003736;
    /* @5003620 constant */
    /* @5003624 cast */
    /* @5003628 call */
    GM_SITE(vm, 669, 5003628);
    /* @5003636 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @5003640 constant */
    /* @5003648 cast */
    /* @5003652 call */
    GM_SITE(vm, 669, 5003652);
    /* @5003660 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5003664 string */
    /* @5003672 cast */
    /* @5003676 constant */
    /* @5003680 constant */
    /* @5003684 load */
    /* @5003692 constant */
    /* @5003696 add */
    /* @5003700 constant */
    /* @5003704 constant */
    /* @5003708 load */
    /* @5003716 constant */
    /* @5003720 add */
    /* @5003724 call */
    GM_SITE(vm, 669, 5003724);
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(110));
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @5003732 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v11, v12, STR_REF(743)));
    L_5003736: ;
    /* @5003736 load */
    /* @5003744 constant */
    /* @5003748 cmp */
    /* @5003752 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_5004280;
    /* @5003756 constant */
    /* @5003760 cast */
    /* @5003764 constant */
    /* @5003768 cast */
    /* @5003772 constant */
    /* @5003776 cast */
    /* @5003780 constant */
    /* @5003792 cast */
    /* @5003796 constant */
    /* @5003808 cast */
    /* @5003812 constant */
    /* @5003816 constant */
    /* @5003820 load */
    /* @5003828 constant */
    /* @5003832 constant */
    /* @5003836 load */
    /* @5003844 constant */
    /* @5003848 sub */
    /* @5003852 constant */
    /* @5003856 cast */
    /* @5003860 constant */
    /* @5003864 cast */
    /* @5003868 call */
    GM_SITE(vm, 669, 5003868);
    /* @5003876 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @5003880 constant */
    /* @5003884 cast */
    /* @5003888 constant */
    /* @5003892 cast */
    /* @5003896 constant */
    /* @5003900 cast */
    /* @5003904 constant */
    /* @5003908 cast */
    /* @5003912 constant */
    /* @5003916 cast */
    /* @5003920 constant */
    /* @5003924 load */
    /* @5003932 cast */
    /* @5003936 load */
    /* @5003944 constant */
    /* @5003948 add */
    /* @5003952 constant */
    /* @5003956 load */
    /* @5003964 cast */
    /* @5003968 load */
    /* @5003976 constant */
    /* @5003980 add */
    /* @5003984 constant */
    /* @5003988 cast */
    /* @5003992 constant */
    /* @5003996 cast */
    /* @5004000 call */
    GM_SITE(vm, 669, 5004000);
    v13 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @5004008 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v13, v14, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @5004012 constant */
    /* @5004016 cast */
    /* @5004020 constant */
    /* @5004024 cast */
    /* @5004028 constant */
    /* @5004032 cast */
    /* @5004036 constant */
    /* @5004040 cast */
    /* @5004044 constant */
    /* @5004048 cast */
    /* @5004052 constant */
    /* @5004056 load */
    /* @5004064 cast */
    /* @5004068 load */
    /* @5004076 constant */
    /* @5004080 add */
    /* @5004084 constant */
    /* @5004088 load */
    /* @5004096 cast */
    /* @5004100 load */
    /* @5004108 constant */
    /* @5004112 add */
    /* @5004116 constant */
    /* @5004120 cast */
    /* @5004124 constant */
    /* @5004128 cast */
    /* @5004132 call */
    GM_SITE(vm, 669, 5004132);
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @5004140 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v15, v16, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @5004144 load */
    /* @5004152 constant */
    /* @5004156 cmp */
    /* @5004160 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_5004280;
    /* @5004164 constant */
    /* @5004168 cast */
    /* @5004172 call */
    GM_SITE(vm, 669, 5004172);
    /* @5004180 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @5004184 constant */
    /* @5004192 cast */
    /* @5004196 call */
    GM_SITE(vm, 669, 5004196);
    /* @5004204 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5004208 string */
    /* @5004216 cast */
    /* @5004220 constant */
    /* @5004224 constant */
    /* @5004228 load */
    /* @5004236 constant */
    /* @5004240 add */
    /* @5004244 constant */
    /* @5004248 constant */
    /* @5004252 load */
    /* @5004260 constant */
    /* @5004264 add */
    /* @5004268 call */
    GM_SITE(vm, 669, 5004268);
    v17 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(180));
    v18 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(300));
    /* @5004276 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v17, v18, STR_REF(743)));
    L_5004280: ;
    /* @5004280 load */
    /* @5004288 constant */
    /* @5004292 cmp */
    /* @5004296 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_5004824;
    /* @5004300 constant */
    /* @5004304 cast */
    /* @5004308 constant */
    /* @5004312 cast */
    /* @5004316 constant */
    /* @5004320 cast */
    /* @5004324 constant */
    /* @5004336 cast */
    /* @5004340 constant */
    /* @5004352 cast */
    /* @5004356 constant */
    /* @5004360 constant */
    /* @5004364 load */
    /* @5004372 constant */
    /* @5004376 constant */
    /* @5004380 load */
    /* @5004388 constant */
    /* @5004392 sub */
    /* @5004396 constant */
    /* @5004400 cast */
    /* @5004404 constant */
    /* @5004408 cast */
    /* @5004412 call */
    GM_SITE(vm, 669, 5004412);
    /* @5004420 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @5004424 constant */
    /* @5004428 cast */
    /* @5004432 constant */
    /* @5004436 cast */
    /* @5004440 constant */
    /* @5004444 cast */
    /* @5004448 constant */
    /* @5004452 cast */
    /* @5004456 constant */
    /* @5004460 cast */
    /* @5004464 constant */
    /* @5004468 load */
    /* @5004476 cast */
    /* @5004480 load */
    /* @5004488 constant */
    /* @5004492 add */
    /* @5004496 constant */
    /* @5004500 load */
    /* @5004508 cast */
    /* @5004512 load */
    /* @5004520 constant */
    /* @5004524 add */
    /* @5004528 constant */
    /* @5004532 cast */
    /* @5004536 constant */
    /* @5004540 cast */
    /* @5004544 call */
    GM_SITE(vm, 669, 5004544);
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @5004552 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v19, v20, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @5004556 constant */
    /* @5004560 cast */
    /* @5004564 constant */
    /* @5004568 cast */
    /* @5004572 constant */
    /* @5004576 cast */
    /* @5004580 constant */
    /* @5004584 cast */
    /* @5004588 constant */
    /* @5004592 cast */
    /* @5004596 constant */
    /* @5004600 load */
    /* @5004608 cast */
    /* @5004612 load */
    /* @5004620 constant */
    /* @5004624 add */
    /* @5004628 constant */
    /* @5004632 load */
    /* @5004640 cast */
    /* @5004644 load */
    /* @5004652 constant */
    /* @5004656 add */
    /* @5004660 constant */
    /* @5004664 cast */
    /* @5004668 constant */
    /* @5004672 cast */
    /* @5004676 call */
    GM_SITE(vm, 669, 5004676);
    v21 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @5004684 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v21, v22, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @5004688 load */
    /* @5004696 constant */
    /* @5004700 cmp */
    /* @5004704 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_5004824;
    /* @5004708 constant */
    /* @5004712 cast */
    /* @5004716 call */
    GM_SITE(vm, 669, 5004716);
    /* @5004724 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @5004728 constant */
    /* @5004736 cast */
    /* @5004740 call */
    GM_SITE(vm, 669, 5004740);
    /* @5004748 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5004752 string */
    /* @5004760 cast */
    /* @5004764 constant */
    /* @5004768 constant */
    /* @5004772 load */
    /* @5004780 constant */
    /* @5004784 add */
    /* @5004788 constant */
    /* @5004792 constant */
    /* @5004796 load */
    /* @5004804 constant */
    /* @5004808 add */
    /* @5004812 call */
    GM_SITE(vm, 669, 5004812);
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(180));
    v24 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(300));
    /* @5004820 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v23, v24, STR_REF(743)));
    L_5004824: ;
    /* @5004824 load */
    /* @5004832 constant */
    /* @5004836 cmp */
    /* @5004840 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_5005368;
    /* @5004844 constant */
    /* @5004848 cast */
    /* @5004852 constant */
    /* @5004856 cast */
    /* @5004860 constant */
    /* @5004864 cast */
    /* @5004868 constant */
    /* @5004880 cast */
    /* @5004884 constant */
    /* @5004896 cast */
    /* @5004900 constant */
    /* @5004904 constant */
    /* @5004908 load */
    /* @5004916 constant */
    /* @5004920 constant */
    /* @5004924 load */
    /* @5004932 constant */
    /* @5004936 sub */
    /* @5004940 constant */
    /* @5004944 cast */
    /* @5004948 constant */
    /* @5004952 cast */
    /* @5004956 call */
    GM_SITE(vm, 669, 5004956);
    /* @5004964 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(0.97), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @5004968 constant */
    /* @5004972 cast */
    /* @5004976 constant */
    /* @5004980 cast */
    /* @5004984 constant */
    /* @5004988 cast */
    /* @5004992 constant */
    /* @5004996 cast */
    /* @5005000 constant */
    /* @5005004 cast */
    /* @5005008 constant */
    /* @5005012 load */
    /* @5005020 cast */
    /* @5005024 load */
    /* @5005032 constant */
    /* @5005036 add */
    /* @5005040 constant */
    /* @5005044 load */
    /* @5005052 cast */
    /* @5005056 load */
    /* @5005064 constant */
    /* @5005068 add */
    /* @5005072 constant */
    /* @5005076 cast */
    /* @5005080 constant */
    /* @5005084 cast */
    /* @5005088 call */
    GM_SITE(vm, 669, 5005088);
    v25 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v26 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @5005096 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v25, v26, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @5005100 constant */
    /* @5005104 cast */
    /* @5005108 constant */
    /* @5005112 cast */
    /* @5005116 constant */
    /* @5005120 cast */
    /* @5005124 constant */
    /* @5005128 cast */
    /* @5005132 constant */
    /* @5005136 cast */
    /* @5005140 constant */
    /* @5005144 load */
    /* @5005152 cast */
    /* @5005156 load */
    /* @5005164 constant */
    /* @5005168 add */
    /* @5005172 constant */
    /* @5005176 load */
    /* @5005184 cast */
    /* @5005188 load */
    /* @5005196 constant */
    /* @5005200 add */
    /* @5005204 constant */
    /* @5005208 cast */
    /* @5005212 constant */
    /* @5005216 cast */
    /* @5005220 call */
    GM_SITE(vm, 669, 5005220);
    v27 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v28 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @5005228 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v27, v28, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @5005232 load */
    /* @5005240 constant */
    /* @5005244 cmp */
    /* @5005248 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_5005368;
    /* @5005252 constant */
    /* @5005256 cast */
    /* @5005260 call */
    GM_SITE(vm, 669, 5005260);
    /* @5005268 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @5005272 constant */
    /* @5005280 cast */
    /* @5005284 call */
    GM_SITE(vm, 669, 5005284);
    /* @5005292 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5005296 string */
    /* @5005304 cast */
    /* @5005308 constant */
    /* @5005312 constant */
    /* @5005316 load */
    /* @5005324 constant */
    /* @5005328 add */
    /* @5005332 constant */
    /* @5005336 constant */
    /* @5005340 load */
    /* @5005348 constant */
    /* @5005352 add */
    /* @5005356 call */
    GM_SITE(vm, 669, 5005356);
    v29 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(150));
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(200));
    /* @5005364 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v29, v30, STR_REF(743)));
    L_5005368: ;
    /* @5005368 load */
    /* @5005376 constant */
    /* @5005380 cmp */
    /* @5005384 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_5005912;
    /* @5005388 constant */
    /* @5005392 cast */
    /* @5005396 constant */
    /* @5005400 cast */
    /* @5005404 constant */
    /* @5005408 cast */
    /* @5005412 constant */
    /* @5005424 cast */
    /* @5005428 constant */
    /* @5005440 cast */
    /* @5005444 constant */
    /* @5005448 constant */
    /* @5005452 load */
    /* @5005460 constant */
    /* @5005464 constant */
    /* @5005468 load */
    /* @5005476 constant */
    /* @5005480 sub */
    /* @5005484 constant */
    /* @5005488 cast */
    /* @5005492 constant */
    /* @5005496 cast */
    /* @5005500 call */
    GM_SITE(vm, 669, 5005500);
    /* @5005508 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(1.06), VAL(0.86), VAL(0), VAL(-1), VAL(1)));
    /* @5005512 constant */
    /* @5005516 cast */
    /* @5005520 constant */
    /* @5005524 cast */
    /* @5005528 constant */
    /* @5005532 cast */
    /* @5005536 constant */
    /* @5005540 cast */
    /* @5005544 constant */
    /* @5005548 cast */
    /* @5005552 constant */
    /* @5005556 load */
    /* @5005564 cast */
    /* @5005568 load */
    /* @5005576 constant */
    /* @5005580 add */
    /* @5005584 constant */
    /* @5005588 load */
    /* @5005596 cast */
    /* @5005600 load */
    /* @5005608 constant */
    /* @5005612 add */
    /* @5005616 constant */
    /* @5005620 cast */
    /* @5005624 constant */
    /* @5005628 cast */
    /* @5005632 call */
    GM_SITE(vm, 669, 5005632);
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v32 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @5005640 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v31, v32, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @5005644 constant */
    /* @5005648 cast */
    /* @5005652 constant */
    /* @5005656 cast */
    /* @5005660 constant */
    /* @5005664 cast */
    /* @5005668 constant */
    /* @5005672 cast */
    /* @5005676 constant */
    /* @5005680 cast */
    /* @5005684 constant */
    /* @5005688 load */
    /* @5005696 cast */
    /* @5005700 load */
    /* @5005708 constant */
    /* @5005712 add */
    /* @5005716 constant */
    /* @5005720 load */
    /* @5005728 cast */
    /* @5005732 load */
    /* @5005740 constant */
    /* @5005744 add */
    /* @5005748 constant */
    /* @5005752 cast */
    /* @5005756 constant */
    /* @5005760 cast */
    /* @5005764 call */
    GM_SITE(vm, 669, 5005764);
    v33 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(390));
    v34 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @5005772 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v33, v34, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @5005776 load */
    /* @5005784 constant */
    /* @5005788 cmp */
    /* @5005792 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_5005912;
    /* @5005796 constant */
    /* @5005800 cast */
    /* @5005804 call */
    GM_SITE(vm, 669, 5005804);
    /* @5005812 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @5005816 constant */
    /* @5005824 cast */
    /* @5005828 call */
    GM_SITE(vm, 669, 5005828);
    /* @5005836 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5005840 string */
    /* @5005848 cast */
    /* @5005852 constant */
    /* @5005856 constant */
    /* @5005860 load */
    /* @5005868 constant */
    /* @5005872 add */
    /* @5005876 constant */
    /* @5005880 constant */
    /* @5005884 load */
    /* @5005892 constant */
    /* @5005896 add */
    /* @5005900 call */
    GM_SITE(vm, 669, 5005900);
    v35 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(160));
    v36 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(200));
    /* @5005908 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v35, v36, STR_REF(743)));
    L_5005912: ;
    /* @5005912 load */
    /* @5005920 constant */
    /* @5005924 cmp */
    /* @5005928 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel1") == VAL(1)))) goto L_5007372;
    /* @5005932 load */
    /* @5005940 constant */
    /* @5005944 cmp */
    /* @5005948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_5006172;
    /* @5005952 constant */
    /* @5005956 cast */
    /* @5005960 call */
    GM_SITE(vm, 669, 5005960);
    /* @5005968 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5005972 constant */
    /* @5005980 cast */
    /* @5005984 call */
    GM_SITE(vm, 669, 5005984);
    /* @5005992 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5005996 string */
    /* @5006004 cast */
    /* @5006008 constant */
    /* @5006012 load */
    /* @5006020 cast */
    /* @5006024 load */
    /* @5006032 constant */
    /* @5006036 add */
    /* @5006040 constant */
    /* @5006044 load */
    /* @5006052 cast */
    /* @5006056 load */
    /* @5006064 constant */
    /* @5006068 add */
    /* @5006072 call */
    GM_SITE(vm, 669, 5006072);
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @5006080 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v37, v38, STR_REF(1058)));
    /* @5006084 string */
    /* @5006092 cast */
    /* @5006096 constant */
    /* @5006100 load */
    /* @5006108 cast */
    /* @5006112 load */
    /* @5006120 constant */
    /* @5006124 add */
    /* @5006128 constant */
    /* @5006132 load */
    /* @5006140 cast */
    /* @5006144 load */
    /* @5006152 constant */
    /* @5006156 add */
    /* @5006160 call */
    GM_SITE(vm, 669, 5006160);
    v39 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v40 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @5006168 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, v40, STR_REF(1154)));
    L_5006172: ;
    /* @5006172 load */
    /* @5006180 constant */
    /* @5006184 cmp */
    /* @5006188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_5006412;
    /* @5006192 constant */
    /* @5006196 cast */
    /* @5006200 call */
    GM_SITE(vm, 669, 5006200);
    /* @5006208 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5006212 constant */
    /* @5006220 cast */
    /* @5006224 call */
    GM_SITE(vm, 669, 5006224);
    /* @5006232 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5006236 string */
    /* @5006244 cast */
    /* @5006248 constant */
    /* @5006252 load */
    /* @5006260 cast */
    /* @5006264 load */
    /* @5006272 constant */
    /* @5006276 add */
    /* @5006280 constant */
    /* @5006284 load */
    /* @5006292 cast */
    /* @5006296 load */
    /* @5006304 constant */
    /* @5006308 add */
    /* @5006312 call */
    GM_SITE(vm, 669, 5006312);
    v41 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v42 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @5006320 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v41, v42, STR_REF(1058)));
    /* @5006324 string */
    /* @5006332 cast */
    /* @5006336 constant */
    /* @5006340 load */
    /* @5006348 cast */
    /* @5006352 load */
    /* @5006360 constant */
    /* @5006364 add */
    /* @5006368 constant */
    /* @5006372 load */
    /* @5006380 cast */
    /* @5006384 load */
    /* @5006392 constant */
    /* @5006396 add */
    /* @5006400 call */
    GM_SITE(vm, 669, 5006400);
    v43 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v44 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @5006408 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v43, v44, STR_REF(1154)));
    L_5006412: ;
    /* @5006412 load */
    /* @5006420 constant */
    /* @5006424 cmp */
    /* @5006428 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_5006652;
    /* @5006432 constant */
    /* @5006436 cast */
    /* @5006440 call */
    GM_SITE(vm, 669, 5006440);
    /* @5006448 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @5006452 constant */
    /* @5006460 cast */
    /* @5006464 call */
    GM_SITE(vm, 669, 5006464);
    /* @5006472 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5006476 string */
    /* @5006484 cast */
    /* @5006488 constant */
    /* @5006492 load */
    /* @5006500 cast */
    /* @5006504 load */
    /* @5006512 constant */
    /* @5006516 add */
    /* @5006520 constant */
    /* @5006524 load */
    /* @5006532 cast */
    /* @5006536 load */
    /* @5006544 constant */
    /* @5006548 add */
    /* @5006552 call */
    GM_SITE(vm, 669, 5006552);
    v45 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v46 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @5006560 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v45, v46, STR_REF(1058)));
    /* @5006564 string */
    /* @5006572 cast */
    /* @5006576 constant */
    /* @5006580 load */
    /* @5006588 cast */
    /* @5006592 load */
    /* @5006600 constant */
    /* @5006604 add */
    /* @5006608 constant */
    /* @5006612 load */
    /* @5006620 cast */
    /* @5006624 load */
    /* @5006632 constant */
    /* @5006636 add */
    /* @5006640 call */
    GM_SITE(vm, 669, 5006640);
    v47 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v48 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @5006648 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v47, v48, STR_REF(1154)));
    L_5006652: ;
    /* @5006652 load */
    /* @5006660 constant */
    /* @5006664 cmp */
    /* @5006668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_5006892;
    /* @5006672 constant */
    /* @5006676 cast */
    /* @5006680 call */
    GM_SITE(vm, 669, 5006680);
    /* @5006688 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @5006692 constant */
    /* @5006700 cast */
    /* @5006704 call */
    GM_SITE(vm, 669, 5006704);
    /* @5006712 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5006716 string */
    /* @5006724 cast */
    /* @5006728 constant */
    /* @5006732 load */
    /* @5006740 cast */
    /* @5006744 load */
    /* @5006752 constant */
    /* @5006756 add */
    /* @5006760 constant */
    /* @5006764 load */
    /* @5006772 cast */
    /* @5006776 load */
    /* @5006784 constant */
    /* @5006788 add */
    /* @5006792 call */
    GM_SITE(vm, 669, 5006792);
    v49 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v50 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @5006800 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v49, v50, STR_REF(1058)));
    /* @5006804 string */
    /* @5006812 cast */
    /* @5006816 constant */
    /* @5006820 load */
    /* @5006828 cast */
    /* @5006832 load */
    /* @5006840 constant */
    /* @5006844 add */
    /* @5006848 constant */
    /* @5006852 load */
    /* @5006860 cast */
    /* @5006864 load */
    /* @5006872 constant */
    /* @5006876 add */
    /* @5006880 call */
    GM_SITE(vm, 669, 5006880);
    v51 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v52 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @5006888 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v51, v52, STR_REF(1154)));
    L_5006892: ;
    /* @5006892 load */
    /* @5006900 constant */
    /* @5006904 cmp */
    /* @5006908 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_5007132;
    /* @5006912 constant */
    /* @5006916 cast */
    /* @5006920 call */
    GM_SITE(vm, 669, 5006920);
    /* @5006928 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5006932 constant */
    /* @5006940 cast */
    /* @5006944 call */
    GM_SITE(vm, 669, 5006944);
    /* @5006952 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5006956 string */
    /* @5006964 cast */
    /* @5006968 constant */
    /* @5006972 load */
    /* @5006980 cast */
    /* @5006984 load */
    /* @5006992 constant */
    /* @5006996 add */
    /* @5007000 constant */
    /* @5007004 load */
    /* @5007012 cast */
    /* @5007016 load */
    /* @5007024 constant */
    /* @5007028 add */
    /* @5007032 call */
    GM_SITE(vm, 669, 5007032);
    v53 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v54 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @5007040 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v53, v54, STR_REF(1058)));
    /* @5007044 string */
    /* @5007052 cast */
    /* @5007056 constant */
    /* @5007060 load */
    /* @5007068 cast */
    /* @5007072 load */
    /* @5007080 constant */
    /* @5007084 add */
    /* @5007088 constant */
    /* @5007092 load */
    /* @5007100 cast */
    /* @5007104 load */
    /* @5007112 constant */
    /* @5007116 add */
    /* @5007120 call */
    GM_SITE(vm, 669, 5007120);
    v55 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v56 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @5007128 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v55, v56, STR_REF(1154)));
    L_5007132: ;
    /* @5007132 load */
    /* @5007140 constant */
    /* @5007144 cmp */
    /* @5007148 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_5007372;
    /* @5007152 constant */
    /* @5007156 cast */
    /* @5007160 call */
    GM_SITE(vm, 669, 5007160);
    /* @5007168 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5007172 constant */
    /* @5007180 cast */
    /* @5007184 call */
    GM_SITE(vm, 669, 5007184);
    /* @5007192 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5007196 string */
    /* @5007204 cast */
    /* @5007208 constant */
    /* @5007212 load */
    /* @5007220 cast */
    /* @5007224 load */
    /* @5007232 constant */
    /* @5007236 add */
    /* @5007240 constant */
    /* @5007244 load */
    /* @5007252 cast */
    /* @5007256 load */
    /* @5007264 constant */
    /* @5007268 add */
    /* @5007272 call */
    GM_SITE(vm, 669, 5007272);
    v57 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v58 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @5007280 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v57, v58, STR_REF(1058)));
    /* @5007284 string */
    /* @5007292 cast */
    /* @5007296 constant */
    /* @5007300 load */
    /* @5007308 cast */
    /* @5007312 load */
    /* @5007320 constant */
    /* @5007324 add */
    /* @5007328 constant */
    /* @5007332 load */
    /* @5007340 cast */
    /* @5007344 load */
    /* @5007352 constant */
    /* @5007356 add */
    /* @5007360 call */
    GM_SITE(vm, 669, 5007360);
    v59 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v60 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @5007368 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v59, v60, STR_REF(1154)));
    L_5007372: ;
    /* @5007372 load */
    /* @5007380 constant */
    /* @5007384 cmp */
    /* @5007388 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel2") == VAL(1)))) goto L_5008832;
    /* @5007392 load */
    /* @5007400 constant */
    /* @5007404 cmp */
    /* @5007408 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_5007632;
    /* @5007412 constant */
    /* @5007416 cast */
    /* @5007420 call */
    GM_SITE(vm, 669, 5007420);
    /* @5007428 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5007432 constant */
    /* @5007440 cast */
    /* @5007444 call */
    GM_SITE(vm, 669, 5007444);
    /* @5007452 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5007456 string */
    /* @5007464 cast */
    /* @5007468 constant */
    /* @5007472 load */
    /* @5007480 cast */
    /* @5007484 load */
    /* @5007492 constant */
    /* @5007496 add */
    /* @5007500 constant */
    /* @5007504 load */
    /* @5007512 cast */
    /* @5007516 load */
    /* @5007524 constant */
    /* @5007528 add */
    /* @5007532 call */
    GM_SITE(vm, 669, 5007532);
    v61 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    v62 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @5007540 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v61, v62, STR_REF(1155)));
    /* @5007544 string */
    /* @5007552 cast */
    /* @5007556 constant */
    /* @5007560 load */
    /* @5007568 cast */
    /* @5007572 load */
    /* @5007580 constant */
    /* @5007584 add */
    /* @5007588 constant */
    /* @5007592 load */
    /* @5007600 cast */
    /* @5007604 load */
    /* @5007612 constant */
    /* @5007616 add */
    /* @5007620 call */
    GM_SITE(vm, 669, 5007620);
    v63 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    v64 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @5007628 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v63, v64, STR_REF(1156)));
    L_5007632: ;
    /* @5007632 load */
    /* @5007640 constant */
    /* @5007644 cmp */
    /* @5007648 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_5007872;
    /* @5007652 constant */
    /* @5007656 cast */
    /* @5007660 call */
    GM_SITE(vm, 669, 5007660);
    /* @5007668 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5007672 constant */
    /* @5007680 cast */
    /* @5007684 call */
    GM_SITE(vm, 669, 5007684);
    /* @5007692 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5007696 string */
    /* @5007704 cast */
    /* @5007708 constant */
    /* @5007712 load */
    /* @5007720 cast */
    /* @5007724 load */
    /* @5007732 constant */
    /* @5007736 add */
    /* @5007740 constant */
    /* @5007744 load */
    /* @5007752 cast */
    /* @5007756 load */
    /* @5007764 constant */
    /* @5007768 add */
    /* @5007772 call */
    GM_SITE(vm, 669, 5007772);
    v65 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v66 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    /* @5007780 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v65, v66, STR_REF(1155)));
    /* @5007784 string */
    /* @5007792 cast */
    /* @5007796 constant */
    /* @5007800 load */
    /* @5007808 cast */
    /* @5007812 load */
    /* @5007820 constant */
    /* @5007824 add */
    /* @5007828 constant */
    /* @5007832 load */
    /* @5007840 cast */
    /* @5007844 load */
    /* @5007852 constant */
    /* @5007856 add */
    /* @5007860 call */
    GM_SITE(vm, 669, 5007860);
    v67 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v68 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(140));
    /* @5007868 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v67, v68, STR_REF(1156)));
    L_5007872: ;
    /* @5007872 load */
    /* @5007880 constant */
    /* @5007884 cmp */
    /* @5007888 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_5008112;
    /* @5007892 constant */
    /* @5007896 cast */
    /* @5007900 call */
    GM_SITE(vm, 669, 5007900);
    /* @5007908 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @5007912 constant */
    /* @5007920 cast */
    /* @5007924 call */
    GM_SITE(vm, 669, 5007924);
    /* @5007932 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5007936 string */
    /* @5007944 cast */
    /* @5007948 constant */
    /* @5007952 load */
    /* @5007960 cast */
    /* @5007964 load */
    /* @5007972 constant */
    /* @5007976 add */
    /* @5007980 constant */
    /* @5007984 load */
    /* @5007992 cast */
    /* @5007996 load */
    /* @5008004 constant */
    /* @5008008 add */
    /* @5008012 call */
    GM_SITE(vm, 669, 5008012);
    v69 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v70 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @5008020 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v69, v70, STR_REF(1155)));
    /* @5008024 string */
    /* @5008032 cast */
    /* @5008036 constant */
    /* @5008040 load */
    /* @5008048 cast */
    /* @5008052 load */
    /* @5008060 constant */
    /* @5008064 add */
    /* @5008068 constant */
    /* @5008072 load */
    /* @5008080 cast */
    /* @5008084 load */
    /* @5008092 constant */
    /* @5008096 add */
    /* @5008100 call */
    GM_SITE(vm, 669, 5008100);
    v71 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v72 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @5008108 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v71, v72, STR_REF(1156)));
    L_5008112: ;
    /* @5008112 load */
    /* @5008120 constant */
    /* @5008124 cmp */
    /* @5008128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_5008352;
    /* @5008132 constant */
    /* @5008136 cast */
    /* @5008140 call */
    GM_SITE(vm, 669, 5008140);
    /* @5008148 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @5008152 constant */
    /* @5008160 cast */
    /* @5008164 call */
    GM_SITE(vm, 669, 5008164);
    /* @5008172 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5008176 string */
    /* @5008184 cast */
    /* @5008188 constant */
    /* @5008192 load */
    /* @5008200 cast */
    /* @5008204 load */
    /* @5008212 constant */
    /* @5008216 add */
    /* @5008220 constant */
    /* @5008224 load */
    /* @5008232 cast */
    /* @5008236 load */
    /* @5008244 constant */
    /* @5008248 add */
    /* @5008252 call */
    GM_SITE(vm, 669, 5008252);
    v73 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v74 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @5008260 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v73, v74, STR_REF(1155)));
    /* @5008264 string */
    /* @5008272 cast */
    /* @5008276 constant */
    /* @5008280 load */
    /* @5008288 cast */
    /* @5008292 load */
    /* @5008300 constant */
    /* @5008304 add */
    /* @5008308 constant */
    /* @5008312 load */
    /* @5008320 cast */
    /* @5008324 load */
    /* @5008332 constant */
    /* @5008336 add */
    /* @5008340 call */
    GM_SITE(vm, 669, 5008340);
    v75 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v76 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @5008348 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v75, v76, STR_REF(1156)));
    L_5008352: ;
    /* @5008352 load */
    /* @5008360 constant */
    /* @5008364 cmp */
    /* @5008368 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_5008592;
    /* @5008372 constant */
    /* @5008376 cast */
    /* @5008380 call */
    GM_SITE(vm, 669, 5008380);
    /* @5008388 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5008392 constant */
    /* @5008400 cast */
    /* @5008404 call */
    GM_SITE(vm, 669, 5008404);
    /* @5008412 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5008416 string */
    /* @5008424 cast */
    /* @5008428 constant */
    /* @5008432 load */
    /* @5008440 cast */
    /* @5008444 load */
    /* @5008452 constant */
    /* @5008456 add */
    /* @5008460 constant */
    /* @5008464 load */
    /* @5008472 cast */
    /* @5008476 load */
    /* @5008484 constant */
    /* @5008488 add */
    /* @5008492 call */
    GM_SITE(vm, 669, 5008492);
    v77 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    v78 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @5008500 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v77, v78, STR_REF(1155)));
    /* @5008504 string */
    /* @5008512 cast */
    /* @5008516 constant */
    /* @5008520 load */
    /* @5008528 cast */
    /* @5008532 load */
    /* @5008540 constant */
    /* @5008544 add */
    /* @5008548 constant */
    /* @5008552 load */
    /* @5008560 cast */
    /* @5008564 load */
    /* @5008572 constant */
    /* @5008576 add */
    /* @5008580 call */
    GM_SITE(vm, 669, 5008580);
    v79 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    v80 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @5008588 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v79, v80, STR_REF(1156)));
    L_5008592: ;
    /* @5008592 load */
    /* @5008600 constant */
    /* @5008604 cmp */
    /* @5008608 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_5008832;
    /* @5008612 constant */
    /* @5008616 cast */
    /* @5008620 call */
    GM_SITE(vm, 669, 5008620);
    /* @5008628 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5008632 constant */
    /* @5008640 cast */
    /* @5008644 call */
    GM_SITE(vm, 669, 5008644);
    /* @5008652 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5008656 string */
    /* @5008664 cast */
    /* @5008668 constant */
    /* @5008672 load */
    /* @5008680 cast */
    /* @5008684 load */
    /* @5008692 constant */
    /* @5008696 add */
    /* @5008700 constant */
    /* @5008704 load */
    /* @5008712 cast */
    /* @5008716 load */
    /* @5008724 constant */
    /* @5008728 add */
    /* @5008732 call */
    GM_SITE(vm, 669, 5008732);
    v81 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    v82 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @5008740 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v81, v82, STR_REF(1155)));
    /* @5008744 string */
    /* @5008752 cast */
    /* @5008756 constant */
    /* @5008760 load */
    /* @5008768 cast */
    /* @5008772 load */
    /* @5008780 constant */
    /* @5008784 add */
    /* @5008788 constant */
    /* @5008792 load */
    /* @5008800 cast */
    /* @5008804 load */
    /* @5008812 constant */
    /* @5008816 add */
    /* @5008820 call */
    GM_SITE(vm, 669, 5008820);
    v83 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    v84 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @5008828 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v83, v84, STR_REF(1156)));
    L_5008832: ;
    /* @5008832 load */
    /* @5008840 constant */
    /* @5008844 cmp */
    /* @5008848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel3") == VAL(1)))) goto L_5010292;
    /* @5008852 load */
    /* @5008860 constant */
    /* @5008864 cmp */
    /* @5008868 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_5009092;
    /* @5008872 constant */
    /* @5008876 cast */
    /* @5008880 call */
    GM_SITE(vm, 669, 5008880);
    /* @5008888 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5008892 constant */
    /* @5008900 cast */
    /* @5008904 call */
    GM_SITE(vm, 669, 5008904);
    /* @5008912 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5008916 string */
    /* @5008924 cast */
    /* @5008928 constant */
    /* @5008932 load */
    /* @5008940 cast */
    /* @5008944 load */
    /* @5008952 constant */
    /* @5008956 add */
    /* @5008960 constant */
    /* @5008964 load */
    /* @5008972 cast */
    /* @5008976 load */
    /* @5008984 constant */
    /* @5008988 add */
    /* @5008992 call */
    GM_SITE(vm, 669, 5008992);
    v85 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v86 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @5009000 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v85, v86, STR_REF(1157)));
    /* @5009004 string */
    /* @5009012 cast */
    /* @5009016 constant */
    /* @5009020 load */
    /* @5009028 cast */
    /* @5009032 load */
    /* @5009040 constant */
    /* @5009044 add */
    /* @5009048 constant */
    /* @5009052 load */
    /* @5009060 cast */
    /* @5009064 load */
    /* @5009072 constant */
    /* @5009076 add */
    /* @5009080 call */
    GM_SITE(vm, 669, 5009080);
    v87 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v88 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @5009088 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v87, v88, STR_REF(1158)));
    L_5009092: ;
    /* @5009092 load */
    /* @5009100 constant */
    /* @5009104 cmp */
    /* @5009108 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_5009332;
    /* @5009112 constant */
    /* @5009116 cast */
    /* @5009120 call */
    GM_SITE(vm, 669, 5009120);
    /* @5009128 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5009132 constant */
    /* @5009140 cast */
    /* @5009144 call */
    GM_SITE(vm, 669, 5009144);
    /* @5009152 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5009156 string */
    /* @5009164 cast */
    /* @5009168 constant */
    /* @5009172 load */
    /* @5009180 cast */
    /* @5009184 load */
    /* @5009192 constant */
    /* @5009196 add */
    /* @5009200 constant */
    /* @5009204 load */
    /* @5009212 cast */
    /* @5009216 load */
    /* @5009224 constant */
    /* @5009228 add */
    /* @5009232 call */
    GM_SITE(vm, 669, 5009232);
    v89 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v90 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @5009240 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v89, v90, STR_REF(1157)));
    /* @5009244 string */
    /* @5009252 cast */
    /* @5009256 constant */
    /* @5009260 load */
    /* @5009268 cast */
    /* @5009272 load */
    /* @5009280 constant */
    /* @5009284 add */
    /* @5009288 constant */
    /* @5009292 load */
    /* @5009300 cast */
    /* @5009304 load */
    /* @5009312 constant */
    /* @5009316 add */
    /* @5009320 call */
    GM_SITE(vm, 669, 5009320);
    v91 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v92 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @5009328 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v91, v92, STR_REF(1158)));
    L_5009332: ;
    /* @5009332 load */
    /* @5009340 constant */
    /* @5009344 cmp */
    /* @5009348 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_5009572;
    /* @5009352 constant */
    /* @5009356 cast */
    /* @5009360 call */
    GM_SITE(vm, 669, 5009360);
    /* @5009368 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @5009372 constant */
    /* @5009380 cast */
    /* @5009384 call */
    GM_SITE(vm, 669, 5009384);
    /* @5009392 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5009396 string */
    /* @5009404 cast */
    /* @5009408 constant */
    /* @5009412 load */
    /* @5009420 cast */
    /* @5009424 load */
    /* @5009432 constant */
    /* @5009436 add */
    /* @5009440 constant */
    /* @5009444 load */
    /* @5009452 cast */
    /* @5009456 load */
    /* @5009464 constant */
    /* @5009468 add */
    /* @5009472 call */
    GM_SITE(vm, 669, 5009472);
    v93 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v94 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @5009480 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v93, v94, STR_REF(1157)));
    /* @5009484 string */
    /* @5009492 cast */
    /* @5009496 constant */
    /* @5009500 load */
    /* @5009508 cast */
    /* @5009512 load */
    /* @5009520 constant */
    /* @5009524 add */
    /* @5009528 constant */
    /* @5009532 load */
    /* @5009540 cast */
    /* @5009544 load */
    /* @5009552 constant */
    /* @5009556 add */
    /* @5009560 call */
    GM_SITE(vm, 669, 5009560);
    v95 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v96 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @5009568 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v95, v96, STR_REF(1158)));
    L_5009572: ;
    /* @5009572 load */
    /* @5009580 constant */
    /* @5009584 cmp */
    /* @5009588 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_5009812;
    /* @5009592 constant */
    /* @5009596 cast */
    /* @5009600 call */
    GM_SITE(vm, 669, 5009600);
    /* @5009608 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @5009612 constant */
    /* @5009620 cast */
    /* @5009624 call */
    GM_SITE(vm, 669, 5009624);
    /* @5009632 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5009636 string */
    /* @5009644 cast */
    /* @5009648 constant */
    /* @5009652 load */
    /* @5009660 cast */
    /* @5009664 load */
    /* @5009672 constant */
    /* @5009676 add */
    /* @5009680 constant */
    /* @5009684 load */
    /* @5009692 cast */
    /* @5009696 load */
    /* @5009704 constant */
    /* @5009708 add */
    /* @5009712 call */
    GM_SITE(vm, 669, 5009712);
    v97 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v98 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @5009720 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v97, v98, STR_REF(1157)));
    /* @5009724 string */
    /* @5009732 cast */
    /* @5009736 constant */
    /* @5009740 load */
    /* @5009748 cast */
    /* @5009752 load */
    /* @5009760 constant */
    /* @5009764 add */
    /* @5009768 constant */
    /* @5009772 load */
    /* @5009780 cast */
    /* @5009784 load */
    /* @5009792 constant */
    /* @5009796 add */
    /* @5009800 call */
    GM_SITE(vm, 669, 5009800);
    v99 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v100 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @5009808 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v99, v100, STR_REF(1158)));
    L_5009812: ;
    /* @5009812 load */
    /* @5009820 constant */
    /* @5009824 cmp */
    /* @5009828 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_5010052;
    /* @5009832 constant */
    /* @5009836 cast */
    /* @5009840 call */
    GM_SITE(vm, 669, 5009840);
    /* @5009848 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5009852 constant */
    /* @5009860 cast */
    /* @5009864 call */
    GM_SITE(vm, 669, 5009864);
    /* @5009872 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5009876 string */
    /* @5009884 cast */
    /* @5009888 constant */
    /* @5009892 load */
    /* @5009900 cast */
    /* @5009904 load */
    /* @5009912 constant */
    /* @5009916 add */
    /* @5009920 constant */
    /* @5009924 load */
    /* @5009932 cast */
    /* @5009936 load */
    /* @5009944 constant */
    /* @5009948 add */
    /* @5009952 call */
    GM_SITE(vm, 669, 5009952);
    v101 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v102 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @5009960 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v101, v102, STR_REF(1157)));
    /* @5009964 string */
    /* @5009972 cast */
    /* @5009976 constant */
    /* @5009980 load */
    /* @5009988 cast */
    /* @5009992 load */
    /* @5010000 constant */
    /* @5010004 add */
    /* @5010008 constant */
    /* @5010012 load */
    /* @5010020 cast */
    /* @5010024 load */
    /* @5010032 constant */
    /* @5010036 add */
    /* @5010040 call */
    GM_SITE(vm, 669, 5010040);
    v103 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v104 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @5010048 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v103, v104, STR_REF(1158)));
    L_5010052: ;
    /* @5010052 load */
    /* @5010060 constant */
    /* @5010064 cmp */
    /* @5010068 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_5010292;
    /* @5010072 constant */
    /* @5010076 cast */
    /* @5010080 call */
    GM_SITE(vm, 669, 5010080);
    /* @5010088 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5010092 constant */
    /* @5010100 cast */
    /* @5010104 call */
    GM_SITE(vm, 669, 5010104);
    /* @5010112 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5010116 string */
    /* @5010124 cast */
    /* @5010128 constant */
    /* @5010132 load */
    /* @5010140 cast */
    /* @5010144 load */
    /* @5010152 constant */
    /* @5010156 add */
    /* @5010160 constant */
    /* @5010164 load */
    /* @5010172 cast */
    /* @5010176 load */
    /* @5010184 constant */
    /* @5010188 add */
    /* @5010192 call */
    GM_SITE(vm, 669, 5010192);
    v105 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v106 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @5010200 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v105, v106, STR_REF(1157)));
    /* @5010204 string */
    /* @5010212 cast */
    /* @5010216 constant */
    /* @5010220 load */
    /* @5010228 cast */
    /* @5010232 load */
    /* @5010240 constant */
    /* @5010244 add */
    /* @5010248 constant */
    /* @5010252 load */
    /* @5010260 cast */
    /* @5010264 load */
    /* @5010272 constant */
    /* @5010276 add */
    /* @5010280 call */
    GM_SITE(vm, 669, 5010280);
    v107 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v108 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @5010288 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v107, v108, STR_REF(1158)));
    L_5010292: ;
    /* @5010292 load */
    /* @5010300 constant */
    /* @5010304 cmp */
    /* @5010308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel4") == VAL(1)))) goto L_5011752;
    /* @5010312 load */
    /* @5010320 constant */
    /* @5010324 cmp */
    /* @5010328 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_5010552;
    /* @5010332 constant */
    /* @5010336 cast */
    /* @5010340 call */
    GM_SITE(vm, 669, 5010340);
    /* @5010348 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5010352 constant */
    /* @5010360 cast */
    /* @5010364 call */
    GM_SITE(vm, 669, 5010364);
    /* @5010372 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5010376 string */
    /* @5010384 cast */
    /* @5010388 constant */
    /* @5010392 load */
    /* @5010400 cast */
    /* @5010404 load */
    /* @5010412 constant */
    /* @5010416 add */
    /* @5010420 constant */
    /* @5010424 load */
    /* @5010432 cast */
    /* @5010436 load */
    /* @5010444 constant */
    /* @5010448 add */
    /* @5010452 call */
    GM_SITE(vm, 669, 5010452);
    v109 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v110 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @5010460 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v109, v110, STR_REF(1159)));
    /* @5010464 string */
    /* @5010472 cast */
    /* @5010476 constant */
    /* @5010480 load */
    /* @5010488 cast */
    /* @5010492 load */
    /* @5010500 constant */
    /* @5010504 add */
    /* @5010508 constant */
    /* @5010512 load */
    /* @5010520 cast */
    /* @5010524 load */
    /* @5010532 constant */
    /* @5010536 add */
    /* @5010540 call */
    GM_SITE(vm, 669, 5010540);
    v111 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v112 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @5010548 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v111, v112, STR_REF(1160)));
    L_5010552: ;
    /* @5010552 load */
    /* @5010560 constant */
    /* @5010564 cmp */
    /* @5010568 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_5010792;
    /* @5010572 constant */
    /* @5010576 cast */
    /* @5010580 call */
    GM_SITE(vm, 669, 5010580);
    /* @5010588 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5010592 constant */
    /* @5010600 cast */
    /* @5010604 call */
    GM_SITE(vm, 669, 5010604);
    /* @5010612 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5010616 string */
    /* @5010624 cast */
    /* @5010628 constant */
    /* @5010632 load */
    /* @5010640 cast */
    /* @5010644 load */
    /* @5010652 constant */
    /* @5010656 add */
    /* @5010660 constant */
    /* @5010664 load */
    /* @5010672 cast */
    /* @5010676 load */
    /* @5010684 constant */
    /* @5010688 add */
    /* @5010692 call */
    GM_SITE(vm, 669, 5010692);
    v113 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v114 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @5010700 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v113, v114, STR_REF(1159)));
    /* @5010704 string */
    /* @5010712 cast */
    /* @5010716 constant */
    /* @5010720 load */
    /* @5010728 cast */
    /* @5010732 load */
    /* @5010740 constant */
    /* @5010744 add */
    /* @5010748 constant */
    /* @5010752 load */
    /* @5010760 cast */
    /* @5010764 load */
    /* @5010772 constant */
    /* @5010776 add */
    /* @5010780 call */
    GM_SITE(vm, 669, 5010780);
    v115 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v116 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @5010788 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v115, v116, STR_REF(1160)));
    L_5010792: ;
    /* @5010792 load */
    /* @5010800 constant */
    /* @5010804 cmp */
    /* @5010808 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_5011032;
    /* @5010812 constant */
    /* @5010816 cast */
    /* @5010820 call */
    GM_SITE(vm, 669, 5010820);
    /* @5010828 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @5010832 constant */
    /* @5010840 cast */
    /* @5010844 call */
    GM_SITE(vm, 669, 5010844);
    /* @5010852 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5010856 string */
    /* @5010864 cast */
    /* @5010868 constant */
    /* @5010872 load */
    /* @5010880 cast */
    /* @5010884 load */
    /* @5010892 constant */
    /* @5010896 add */
    /* @5010900 constant */
    /* @5010904 load */
    /* @5010912 cast */
    /* @5010916 load */
    /* @5010924 constant */
    /* @5010928 add */
    /* @5010932 call */
    GM_SITE(vm, 669, 5010932);
    v117 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v118 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @5010940 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v117, v118, STR_REF(1159)));
    /* @5010944 string */
    /* @5010952 cast */
    /* @5010956 constant */
    /* @5010960 load */
    /* @5010968 cast */
    /* @5010972 load */
    /* @5010980 constant */
    /* @5010984 add */
    /* @5010988 constant */
    /* @5010992 load */
    /* @5011000 cast */
    /* @5011004 load */
    /* @5011012 constant */
    /* @5011016 add */
    /* @5011020 call */
    GM_SITE(vm, 669, 5011020);
    v119 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v120 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @5011028 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v119, v120, STR_REF(1160)));
    L_5011032: ;
    /* @5011032 load */
    /* @5011040 constant */
    /* @5011044 cmp */
    /* @5011048 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_5011272;
    /* @5011052 constant */
    /* @5011056 cast */
    /* @5011060 call */
    GM_SITE(vm, 669, 5011060);
    /* @5011068 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @5011072 constant */
    /* @5011080 cast */
    /* @5011084 call */
    GM_SITE(vm, 669, 5011084);
    /* @5011092 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5011096 string */
    /* @5011104 cast */
    /* @5011108 constant */
    /* @5011112 load */
    /* @5011120 cast */
    /* @5011124 load */
    /* @5011132 constant */
    /* @5011136 add */
    /* @5011140 constant */
    /* @5011144 load */
    /* @5011152 cast */
    /* @5011156 load */
    /* @5011164 constant */
    /* @5011168 add */
    /* @5011172 call */
    GM_SITE(vm, 669, 5011172);
    v121 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v122 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @5011180 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v121, v122, STR_REF(1159)));
    /* @5011184 string */
    /* @5011192 cast */
    /* @5011196 constant */
    /* @5011200 load */
    /* @5011208 cast */
    /* @5011212 load */
    /* @5011220 constant */
    /* @5011224 add */
    /* @5011228 constant */
    /* @5011232 load */
    /* @5011240 cast */
    /* @5011244 load */
    /* @5011252 constant */
    /* @5011256 add */
    /* @5011260 call */
    GM_SITE(vm, 669, 5011260);
    v123 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v124 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @5011268 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v123, v124, STR_REF(1160)));
    L_5011272: ;
    /* @5011272 load */
    /* @5011280 constant */
    /* @5011284 cmp */
    /* @5011288 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_5011512;
    /* @5011292 constant */
    /* @5011296 cast */
    /* @5011300 call */
    GM_SITE(vm, 669, 5011300);
    /* @5011308 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5011312 constant */
    /* @5011320 cast */
    /* @5011324 call */
    GM_SITE(vm, 669, 5011324);
    /* @5011332 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5011336 string */
    /* @5011344 cast */
    /* @5011348 constant */
    /* @5011352 load */
    /* @5011360 cast */
    /* @5011364 load */
    /* @5011372 constant */
    /* @5011376 add */
    /* @5011380 constant */
    /* @5011384 load */
    /* @5011392 cast */
    /* @5011396 load */
    /* @5011404 constant */
    /* @5011408 add */
    /* @5011412 call */
    GM_SITE(vm, 669, 5011412);
    v125 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v126 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @5011420 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v125, v126, STR_REF(1159)));
    /* @5011424 string */
    /* @5011432 cast */
    /* @5011436 constant */
    /* @5011440 load */
    /* @5011448 cast */
    /* @5011452 load */
    /* @5011460 constant */
    /* @5011464 add */
    /* @5011468 constant */
    /* @5011472 load */
    /* @5011480 cast */
    /* @5011484 load */
    /* @5011492 constant */
    /* @5011496 add */
    /* @5011500 call */
    GM_SITE(vm, 669, 5011500);
    v127 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v128 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @5011508 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v127, v128, STR_REF(1160)));
    L_5011512: ;
    /* @5011512 load */
    /* @5011520 constant */
    /* @5011524 cmp */
    /* @5011528 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_5011752;
    /* @5011532 constant */
    /* @5011536 cast */
    /* @5011540 call */
    GM_SITE(vm, 669, 5011540);
    /* @5011548 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5011552 constant */
    /* @5011560 cast */
    /* @5011564 call */
    GM_SITE(vm, 669, 5011564);
    /* @5011572 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5011576 string */
    /* @5011584 cast */
    /* @5011588 constant */
    /* @5011592 load */
    /* @5011600 cast */
    /* @5011604 load */
    /* @5011612 constant */
    /* @5011616 add */
    /* @5011620 constant */
    /* @5011624 load */
    /* @5011632 cast */
    /* @5011636 load */
    /* @5011644 constant */
    /* @5011648 add */
    /* @5011652 call */
    GM_SITE(vm, 669, 5011652);
    v129 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v130 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @5011660 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v129, v130, STR_REF(1159)));
    /* @5011664 string */
    /* @5011672 cast */
    /* @5011676 constant */
    /* @5011680 load */
    /* @5011688 cast */
    /* @5011692 load */
    /* @5011700 constant */
    /* @5011704 add */
    /* @5011708 constant */
    /* @5011712 load */
    /* @5011720 cast */
    /* @5011724 load */
    /* @5011732 constant */
    /* @5011736 add */
    /* @5011740 call */
    GM_SITE(vm, 669, 5011740);
    v131 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v132 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @5011748 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v131, v132, STR_REF(1160)));
    L_5011752: ;
    /* @5011752 load */
    /* @5011760 constant */
    /* @5011764 cmp */
    /* @5011768 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel5") == VAL(1)))) goto L_5013212;
    /* @5011772 load */
    /* @5011780 constant */
    /* @5011784 cmp */
    /* @5011788 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_5012012;
    /* @5011792 constant */
    /* @5011796 cast */
    /* @5011800 call */
    GM_SITE(vm, 669, 5011800);
    /* @5011808 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5011812 constant */
    /* @5011820 cast */
    /* @5011824 call */
    GM_SITE(vm, 669, 5011824);
    /* @5011832 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5011836 string */
    /* @5011844 cast */
    /* @5011848 constant */
    /* @5011852 load */
    /* @5011860 cast */
    /* @5011864 load */
    /* @5011872 constant */
    /* @5011876 add */
    /* @5011880 constant */
    /* @5011884 load */
    /* @5011892 cast */
    /* @5011896 load */
    /* @5011904 constant */
    /* @5011908 add */
    /* @5011912 call */
    GM_SITE(vm, 669, 5011912);
    v133 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v134 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @5011920 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v133, v134, STR_REF(1161)));
    /* @5011924 string */
    /* @5011932 cast */
    /* @5011936 constant */
    /* @5011940 load */
    /* @5011948 cast */
    /* @5011952 load */
    /* @5011960 constant */
    /* @5011964 add */
    /* @5011968 constant */
    /* @5011972 load */
    /* @5011980 cast */
    /* @5011984 load */
    /* @5011992 constant */
    /* @5011996 add */
    /* @5012000 call */
    GM_SITE(vm, 669, 5012000);
    v135 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v136 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @5012008 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v135, v136, STR_REF(1162)));
    L_5012012: ;
    /* @5012012 load */
    /* @5012020 constant */
    /* @5012024 cmp */
    /* @5012028 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_5012252;
    /* @5012032 constant */
    /* @5012036 cast */
    /* @5012040 call */
    GM_SITE(vm, 669, 5012040);
    /* @5012048 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5012052 constant */
    /* @5012060 cast */
    /* @5012064 call */
    GM_SITE(vm, 669, 5012064);
    /* @5012072 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5012076 string */
    /* @5012084 cast */
    /* @5012088 constant */
    /* @5012092 load */
    /* @5012100 cast */
    /* @5012104 load */
    /* @5012112 constant */
    /* @5012116 add */
    /* @5012120 constant */
    /* @5012124 load */
    /* @5012132 cast */
    /* @5012136 load */
    /* @5012144 constant */
    /* @5012148 add */
    /* @5012152 call */
    GM_SITE(vm, 669, 5012152);
    v137 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v138 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @5012160 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v137, v138, STR_REF(1161)));
    /* @5012164 string */
    /* @5012172 cast */
    /* @5012176 constant */
    /* @5012180 load */
    /* @5012188 cast */
    /* @5012192 load */
    /* @5012200 constant */
    /* @5012204 add */
    /* @5012208 constant */
    /* @5012212 load */
    /* @5012220 cast */
    /* @5012224 load */
    /* @5012232 constant */
    /* @5012236 add */
    /* @5012240 call */
    GM_SITE(vm, 669, 5012240);
    v139 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v140 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @5012248 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v139, v140, STR_REF(1162)));
    L_5012252: ;
    /* @5012252 load */
    /* @5012260 constant */
    /* @5012264 cmp */
    /* @5012268 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_5012492;
    /* @5012272 constant */
    /* @5012276 cast */
    /* @5012280 call */
    GM_SITE(vm, 669, 5012280);
    /* @5012288 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @5012292 constant */
    /* @5012300 cast */
    /* @5012304 call */
    GM_SITE(vm, 669, 5012304);
    /* @5012312 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5012316 string */
    /* @5012324 cast */
    /* @5012328 constant */
    /* @5012332 load */
    /* @5012340 cast */
    /* @5012344 load */
    /* @5012352 constant */
    /* @5012356 add */
    /* @5012360 constant */
    /* @5012364 load */
    /* @5012372 cast */
    /* @5012376 load */
    /* @5012384 constant */
    /* @5012388 add */
    /* @5012392 call */
    GM_SITE(vm, 669, 5012392);
    v141 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v142 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @5012400 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v141, v142, STR_REF(1161)));
    /* @5012404 string */
    /* @5012412 cast */
    /* @5012416 constant */
    /* @5012420 load */
    /* @5012428 cast */
    /* @5012432 load */
    /* @5012440 constant */
    /* @5012444 add */
    /* @5012448 constant */
    /* @5012452 load */
    /* @5012460 cast */
    /* @5012464 load */
    /* @5012472 constant */
    /* @5012476 add */
    /* @5012480 call */
    GM_SITE(vm, 669, 5012480);
    v143 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v144 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @5012488 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v143, v144, STR_REF(1162)));
    L_5012492: ;
    /* @5012492 load */
    /* @5012500 constant */
    /* @5012504 cmp */
    /* @5012508 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_5012732;
    /* @5012512 constant */
    /* @5012516 cast */
    /* @5012520 call */
    GM_SITE(vm, 669, 5012520);
    /* @5012528 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @5012532 constant */
    /* @5012540 cast */
    /* @5012544 call */
    GM_SITE(vm, 669, 5012544);
    /* @5012552 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5012556 string */
    /* @5012564 cast */
    /* @5012568 constant */
    /* @5012572 load */
    /* @5012580 cast */
    /* @5012584 load */
    /* @5012592 constant */
    /* @5012596 add */
    /* @5012600 constant */
    /* @5012604 load */
    /* @5012612 cast */
    /* @5012616 load */
    /* @5012624 constant */
    /* @5012628 add */
    /* @5012632 call */
    GM_SITE(vm, 669, 5012632);
    v145 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v146 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @5012640 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v145, v146, STR_REF(1161)));
    /* @5012644 string */
    /* @5012652 cast */
    /* @5012656 constant */
    /* @5012660 load */
    /* @5012668 cast */
    /* @5012672 load */
    /* @5012680 constant */
    /* @5012684 add */
    /* @5012688 constant */
    /* @5012692 load */
    /* @5012700 cast */
    /* @5012704 load */
    /* @5012712 constant */
    /* @5012716 add */
    /* @5012720 call */
    GM_SITE(vm, 669, 5012720);
    v147 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v148 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @5012728 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v147, v148, STR_REF(1162)));
    L_5012732: ;
    /* @5012732 load */
    /* @5012740 constant */
    /* @5012744 cmp */
    /* @5012748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_5012972;
    /* @5012752 constant */
    /* @5012756 cast */
    /* @5012760 call */
    GM_SITE(vm, 669, 5012760);
    /* @5012768 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5012772 constant */
    /* @5012780 cast */
    /* @5012784 call */
    GM_SITE(vm, 669, 5012784);
    /* @5012792 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5012796 string */
    /* @5012804 cast */
    /* @5012808 constant */
    /* @5012812 load */
    /* @5012820 cast */
    /* @5012824 load */
    /* @5012832 constant */
    /* @5012836 add */
    /* @5012840 constant */
    /* @5012844 load */
    /* @5012852 cast */
    /* @5012856 load */
    /* @5012864 constant */
    /* @5012868 add */
    /* @5012872 call */
    GM_SITE(vm, 669, 5012872);
    v149 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v150 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @5012880 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v149, v150, STR_REF(1161)));
    /* @5012884 string */
    /* @5012892 cast */
    /* @5012896 constant */
    /* @5012900 load */
    /* @5012908 cast */
    /* @5012912 load */
    /* @5012920 constant */
    /* @5012924 add */
    /* @5012928 constant */
    /* @5012932 load */
    /* @5012940 cast */
    /* @5012944 load */
    /* @5012952 constant */
    /* @5012956 add */
    /* @5012960 call */
    GM_SITE(vm, 669, 5012960);
    v151 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v152 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @5012968 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v151, v152, STR_REF(1162)));
    L_5012972: ;
    /* @5012972 load */
    /* @5012980 constant */
    /* @5012984 cmp */
    /* @5012988 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_5013212;
    /* @5012992 constant */
    /* @5012996 cast */
    /* @5013000 call */
    GM_SITE(vm, 669, 5013000);
    /* @5013008 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @5013012 constant */
    /* @5013020 cast */
    /* @5013024 call */
    GM_SITE(vm, 669, 5013024);
    /* @5013032 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @5013036 string */
    /* @5013044 cast */
    /* @5013048 constant */
    /* @5013052 load */
    /* @5013060 cast */
    /* @5013064 load */
    /* @5013072 constant */
    /* @5013076 add */
    /* @5013080 constant */
    /* @5013084 load */
    /* @5013092 cast */
    /* @5013096 load */
    /* @5013104 constant */
    /* @5013108 add */
    /* @5013112 call */
    GM_SITE(vm, 669, 5013112);
    v153 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v154 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @5013120 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v153, v154, STR_REF(1161)));
    /* @5013124 string */
    /* @5013132 cast */
    /* @5013136 constant */
    /* @5013140 load */
    /* @5013148 cast */
    /* @5013152 load */
    /* @5013160 constant */
    /* @5013164 add */
    /* @5013168 constant */
    /* @5013172 load */
    /* @5013180 cast */
    /* @5013184 load */
    /* @5013192 constant */
    /* @5013196 add */
    /* @5013200 call */
    GM_SITE(vm, 669, 5013200);
    v155 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v156 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @5013208 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v155, v156, STR_REF(1162)));
    L_5013212: ;
    /* @5013212 load */
    /* @5013220 constant */
    /* @5013224 cmp */
    /* @5013228 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_5013264;
    /* @5013232 constant */
    /* @5013236 cast */
    /* @5013240 constant */
    /* @5013244 cast */
    /* @5013248 call */
    GM_SITE(vm, 669, 5013248);
    /* @5013256 cast */
    /* @5013260 b */
    v157 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, VAL(0), VAL(1)));
    p5013268_0 = v157;
    goto L_5013268;
    L_5013264: ;
    /* @5013264 constant */
    p5013268_0 = VAL(0);
    L_5013268: ;
    /* @5013268 bf */
    if (!TRUTH(p5013268_0)) goto L_5013284;
    /* @5013272 call */
    GM_SITE(vm, 669, 5013272);
    /* @5013280 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5013284: ;
    return;
}
