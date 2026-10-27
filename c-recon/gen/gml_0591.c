/* generated from CODE 591 (gml_Object_obj_lloydtutorial5_Draw_0), source start 4888944, end 4899668. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0591(GmVM* vm) {
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
    Val p4899652_0;
    Val v157;
    /* @4888944 constant */
    /* @4888948 load */
    /* @4888956 cast */
    /* @4888960 load */
    /* @4888968 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4888976 constant */
    /* @4888980 load */
    /* @4888988 cast */
    /* @4888992 load */
    /* @4889000 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4889008 load */
    /* @4889016 constant */
    /* @4889020 cmp */
    /* @4889024 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4889552;
    /* @4889028 constant */
    /* @4889032 cast */
    /* @4889036 constant */
    /* @4889040 cast */
    /* @4889044 constant */
    /* @4889048 cast */
    /* @4889052 constant */
    /* @4889064 cast */
    /* @4889068 constant */
    /* @4889080 cast */
    /* @4889084 constant */
    /* @4889088 constant */
    /* @4889092 load */
    /* @4889100 constant */
    /* @4889104 constant */
    /* @4889108 load */
    /* @4889116 constant */
    /* @4889120 sub */
    /* @4889124 constant */
    /* @4889128 cast */
    /* @4889132 constant */
    /* @4889136 cast */
    /* @4889140 call */
    GM_SITE(vm, 591, 4889140);
    /* @4889148 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(0.96), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4889152 constant */
    /* @4889156 cast */
    /* @4889160 constant */
    /* @4889164 cast */
    /* @4889168 constant */
    /* @4889172 cast */
    /* @4889176 constant */
    /* @4889180 cast */
    /* @4889184 constant */
    /* @4889188 cast */
    /* @4889192 constant */
    /* @4889196 load */
    /* @4889204 cast */
    /* @4889208 load */
    /* @4889216 constant */
    /* @4889220 add */
    /* @4889224 constant */
    /* @4889228 load */
    /* @4889236 cast */
    /* @4889240 load */
    /* @4889248 constant */
    /* @4889252 add */
    /* @4889256 constant */
    /* @4889260 cast */
    /* @4889264 constant */
    /* @4889268 cast */
    /* @4889272 call */
    GM_SITE(vm, 591, 4889272);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4889280 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v1, v2, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4889284 constant */
    /* @4889288 cast */
    /* @4889292 constant */
    /* @4889296 cast */
    /* @4889300 constant */
    /* @4889304 cast */
    /* @4889308 constant */
    /* @4889312 cast */
    /* @4889316 constant */
    /* @4889320 cast */
    /* @4889324 constant */
    /* @4889328 load */
    /* @4889336 cast */
    /* @4889340 load */
    /* @4889348 constant */
    /* @4889352 add */
    /* @4889356 constant */
    /* @4889360 load */
    /* @4889368 cast */
    /* @4889372 load */
    /* @4889380 constant */
    /* @4889384 add */
    /* @4889388 constant */
    /* @4889392 cast */
    /* @4889396 constant */
    /* @4889400 cast */
    /* @4889404 call */
    GM_SITE(vm, 591, 4889404);
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4889412 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v3, v4, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4889416 load */
    /* @4889424 constant */
    /* @4889428 cmp */
    /* @4889432 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4889552;
    /* @4889436 constant */
    /* @4889440 cast */
    /* @4889444 call */
    GM_SITE(vm, 591, 4889444);
    /* @4889452 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4889456 constant */
    /* @4889464 cast */
    /* @4889468 call */
    GM_SITE(vm, 591, 4889468);
    /* @4889476 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4889480 string */
    /* @4889488 cast */
    /* @4889492 constant */
    /* @4889496 constant */
    /* @4889500 load */
    /* @4889508 constant */
    /* @4889512 add */
    /* @4889516 constant */
    /* @4889520 constant */
    /* @4889524 load */
    /* @4889532 constant */
    /* @4889536 add */
    /* @4889540 call */
    GM_SITE(vm, 591, 4889540);
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(150));
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(200));
    /* @4889548 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v5, v6, STR_REF(743)));
    L_4889552: ;
    /* @4889552 load */
    /* @4889560 constant */
    /* @4889564 cmp */
    /* @4889568 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4890096;
    /* @4889572 constant */
    /* @4889576 cast */
    /* @4889580 constant */
    /* @4889584 cast */
    /* @4889588 constant */
    /* @4889592 cast */
    /* @4889596 constant */
    /* @4889608 cast */
    /* @4889612 constant */
    /* @4889624 cast */
    /* @4889628 constant */
    /* @4889632 constant */
    /* @4889636 load */
    /* @4889644 constant */
    /* @4889648 constant */
    /* @4889652 load */
    /* @4889660 constant */
    /* @4889664 sub */
    /* @4889668 constant */
    /* @4889672 cast */
    /* @4889676 constant */
    /* @4889680 cast */
    /* @4889684 call */
    GM_SITE(vm, 591, 4889684);
    /* @4889692 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(0.82), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4889696 constant */
    /* @4889700 cast */
    /* @4889704 constant */
    /* @4889708 cast */
    /* @4889712 constant */
    /* @4889716 cast */
    /* @4889720 constant */
    /* @4889724 cast */
    /* @4889728 constant */
    /* @4889732 cast */
    /* @4889736 constant */
    /* @4889740 load */
    /* @4889748 cast */
    /* @4889752 load */
    /* @4889760 constant */
    /* @4889764 add */
    /* @4889768 constant */
    /* @4889772 load */
    /* @4889780 cast */
    /* @4889784 load */
    /* @4889792 constant */
    /* @4889796 add */
    /* @4889800 constant */
    /* @4889804 cast */
    /* @4889808 constant */
    /* @4889812 cast */
    /* @4889816 call */
    GM_SITE(vm, 591, 4889816);
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4889824 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v7, v8, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4889828 constant */
    /* @4889832 cast */
    /* @4889836 constant */
    /* @4889840 cast */
    /* @4889844 constant */
    /* @4889848 cast */
    /* @4889852 constant */
    /* @4889856 cast */
    /* @4889860 constant */
    /* @4889864 cast */
    /* @4889868 constant */
    /* @4889872 load */
    /* @4889880 cast */
    /* @4889884 load */
    /* @4889892 constant */
    /* @4889896 add */
    /* @4889900 constant */
    /* @4889904 load */
    /* @4889912 cast */
    /* @4889916 load */
    /* @4889924 constant */
    /* @4889928 add */
    /* @4889932 constant */
    /* @4889936 cast */
    /* @4889940 constant */
    /* @4889944 cast */
    /* @4889948 call */
    GM_SITE(vm, 591, 4889948);
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(320));
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4889956 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v9, v10, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4889960 load */
    /* @4889968 constant */
    /* @4889972 cmp */
    /* @4889976 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4890096;
    /* @4889980 constant */
    /* @4889984 cast */
    /* @4889988 call */
    GM_SITE(vm, 591, 4889988);
    /* @4889996 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4890000 constant */
    /* @4890008 cast */
    /* @4890012 call */
    GM_SITE(vm, 591, 4890012);
    /* @4890020 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4890024 string */
    /* @4890032 cast */
    /* @4890036 constant */
    /* @4890040 constant */
    /* @4890044 load */
    /* @4890052 constant */
    /* @4890056 add */
    /* @4890060 constant */
    /* @4890064 constant */
    /* @4890068 load */
    /* @4890076 constant */
    /* @4890080 add */
    /* @4890084 call */
    GM_SITE(vm, 591, 4890084);
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(110));
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4890092 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v11, v12, STR_REF(743)));
    L_4890096: ;
    /* @4890096 load */
    /* @4890104 constant */
    /* @4890108 cmp */
    /* @4890112 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4890640;
    /* @4890116 constant */
    /* @4890120 cast */
    /* @4890124 constant */
    /* @4890128 cast */
    /* @4890132 constant */
    /* @4890136 cast */
    /* @4890140 constant */
    /* @4890152 cast */
    /* @4890156 constant */
    /* @4890168 cast */
    /* @4890172 constant */
    /* @4890176 constant */
    /* @4890180 load */
    /* @4890188 constant */
    /* @4890192 constant */
    /* @4890196 load */
    /* @4890204 constant */
    /* @4890208 sub */
    /* @4890212 constant */
    /* @4890216 cast */
    /* @4890220 constant */
    /* @4890224 cast */
    /* @4890228 call */
    GM_SITE(vm, 591, 4890228);
    /* @4890236 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4890240 constant */
    /* @4890244 cast */
    /* @4890248 constant */
    /* @4890252 cast */
    /* @4890256 constant */
    /* @4890260 cast */
    /* @4890264 constant */
    /* @4890268 cast */
    /* @4890272 constant */
    /* @4890276 cast */
    /* @4890280 constant */
    /* @4890284 load */
    /* @4890292 cast */
    /* @4890296 load */
    /* @4890304 constant */
    /* @4890308 add */
    /* @4890312 constant */
    /* @4890316 load */
    /* @4890324 cast */
    /* @4890328 load */
    /* @4890336 constant */
    /* @4890340 add */
    /* @4890344 constant */
    /* @4890348 cast */
    /* @4890352 constant */
    /* @4890356 cast */
    /* @4890360 call */
    GM_SITE(vm, 591, 4890360);
    v13 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4890368 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v13, v14, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4890372 constant */
    /* @4890376 cast */
    /* @4890380 constant */
    /* @4890384 cast */
    /* @4890388 constant */
    /* @4890392 cast */
    /* @4890396 constant */
    /* @4890400 cast */
    /* @4890404 constant */
    /* @4890408 cast */
    /* @4890412 constant */
    /* @4890416 load */
    /* @4890424 cast */
    /* @4890428 load */
    /* @4890436 constant */
    /* @4890440 add */
    /* @4890444 constant */
    /* @4890448 load */
    /* @4890456 cast */
    /* @4890460 load */
    /* @4890468 constant */
    /* @4890472 add */
    /* @4890476 constant */
    /* @4890480 cast */
    /* @4890484 constant */
    /* @4890488 cast */
    /* @4890492 call */
    GM_SITE(vm, 591, 4890492);
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4890500 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v15, v16, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4890504 load */
    /* @4890512 constant */
    /* @4890516 cmp */
    /* @4890520 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4890640;
    /* @4890524 constant */
    /* @4890528 cast */
    /* @4890532 call */
    GM_SITE(vm, 591, 4890532);
    /* @4890540 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4890544 constant */
    /* @4890552 cast */
    /* @4890556 call */
    GM_SITE(vm, 591, 4890556);
    /* @4890564 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4890568 string */
    /* @4890576 cast */
    /* @4890580 constant */
    /* @4890584 constant */
    /* @4890588 load */
    /* @4890596 constant */
    /* @4890600 add */
    /* @4890604 constant */
    /* @4890608 constant */
    /* @4890612 load */
    /* @4890620 constant */
    /* @4890624 add */
    /* @4890628 call */
    GM_SITE(vm, 591, 4890628);
    v17 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(180));
    v18 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(300));
    /* @4890636 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v17, v18, STR_REF(743)));
    L_4890640: ;
    /* @4890640 load */
    /* @4890648 constant */
    /* @4890652 cmp */
    /* @4890656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4891184;
    /* @4890660 constant */
    /* @4890664 cast */
    /* @4890668 constant */
    /* @4890672 cast */
    /* @4890676 constant */
    /* @4890680 cast */
    /* @4890684 constant */
    /* @4890696 cast */
    /* @4890700 constant */
    /* @4890712 cast */
    /* @4890716 constant */
    /* @4890720 constant */
    /* @4890724 load */
    /* @4890732 constant */
    /* @4890736 constant */
    /* @4890740 load */
    /* @4890748 constant */
    /* @4890752 sub */
    /* @4890756 constant */
    /* @4890760 cast */
    /* @4890764 constant */
    /* @4890768 cast */
    /* @4890772 call */
    GM_SITE(vm, 591, 4890772);
    /* @4890780 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4890784 constant */
    /* @4890788 cast */
    /* @4890792 constant */
    /* @4890796 cast */
    /* @4890800 constant */
    /* @4890804 cast */
    /* @4890808 constant */
    /* @4890812 cast */
    /* @4890816 constant */
    /* @4890820 cast */
    /* @4890824 constant */
    /* @4890828 load */
    /* @4890836 cast */
    /* @4890840 load */
    /* @4890848 constant */
    /* @4890852 add */
    /* @4890856 constant */
    /* @4890860 load */
    /* @4890868 cast */
    /* @4890872 load */
    /* @4890880 constant */
    /* @4890884 add */
    /* @4890888 constant */
    /* @4890892 cast */
    /* @4890896 constant */
    /* @4890900 cast */
    /* @4890904 call */
    GM_SITE(vm, 591, 4890904);
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4890912 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v19, v20, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4890916 constant */
    /* @4890920 cast */
    /* @4890924 constant */
    /* @4890928 cast */
    /* @4890932 constant */
    /* @4890936 cast */
    /* @4890940 constant */
    /* @4890944 cast */
    /* @4890948 constant */
    /* @4890952 cast */
    /* @4890956 constant */
    /* @4890960 load */
    /* @4890968 cast */
    /* @4890972 load */
    /* @4890980 constant */
    /* @4890984 add */
    /* @4890988 constant */
    /* @4890992 load */
    /* @4891000 cast */
    /* @4891004 load */
    /* @4891012 constant */
    /* @4891016 add */
    /* @4891020 constant */
    /* @4891024 cast */
    /* @4891028 constant */
    /* @4891032 cast */
    /* @4891036 call */
    GM_SITE(vm, 591, 4891036);
    v21 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4891044 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v21, v22, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4891048 load */
    /* @4891056 constant */
    /* @4891060 cmp */
    /* @4891064 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4891184;
    /* @4891068 constant */
    /* @4891072 cast */
    /* @4891076 call */
    GM_SITE(vm, 591, 4891076);
    /* @4891084 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4891088 constant */
    /* @4891096 cast */
    /* @4891100 call */
    GM_SITE(vm, 591, 4891100);
    /* @4891108 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4891112 string */
    /* @4891120 cast */
    /* @4891124 constant */
    /* @4891128 constant */
    /* @4891132 load */
    /* @4891140 constant */
    /* @4891144 add */
    /* @4891148 constant */
    /* @4891152 constant */
    /* @4891156 load */
    /* @4891164 constant */
    /* @4891168 add */
    /* @4891172 call */
    GM_SITE(vm, 591, 4891172);
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(180));
    v24 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(300));
    /* @4891180 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v23, v24, STR_REF(743)));
    L_4891184: ;
    /* @4891184 load */
    /* @4891192 constant */
    /* @4891196 cmp */
    /* @4891200 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4891728;
    /* @4891204 constant */
    /* @4891208 cast */
    /* @4891212 constant */
    /* @4891216 cast */
    /* @4891220 constant */
    /* @4891224 cast */
    /* @4891228 constant */
    /* @4891240 cast */
    /* @4891244 constant */
    /* @4891256 cast */
    /* @4891260 constant */
    /* @4891264 constant */
    /* @4891268 load */
    /* @4891276 constant */
    /* @4891280 constant */
    /* @4891284 load */
    /* @4891292 constant */
    /* @4891296 sub */
    /* @4891300 constant */
    /* @4891304 cast */
    /* @4891308 constant */
    /* @4891312 cast */
    /* @4891316 call */
    GM_SITE(vm, 591, 4891316);
    /* @4891324 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(0.97), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4891328 constant */
    /* @4891332 cast */
    /* @4891336 constant */
    /* @4891340 cast */
    /* @4891344 constant */
    /* @4891348 cast */
    /* @4891352 constant */
    /* @4891356 cast */
    /* @4891360 constant */
    /* @4891364 cast */
    /* @4891368 constant */
    /* @4891372 load */
    /* @4891380 cast */
    /* @4891384 load */
    /* @4891392 constant */
    /* @4891396 add */
    /* @4891400 constant */
    /* @4891404 load */
    /* @4891412 cast */
    /* @4891416 load */
    /* @4891424 constant */
    /* @4891428 add */
    /* @4891432 constant */
    /* @4891436 cast */
    /* @4891440 constant */
    /* @4891444 cast */
    /* @4891448 call */
    GM_SITE(vm, 591, 4891448);
    v25 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v26 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4891456 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v25, v26, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4891460 constant */
    /* @4891464 cast */
    /* @4891468 constant */
    /* @4891472 cast */
    /* @4891476 constant */
    /* @4891480 cast */
    /* @4891484 constant */
    /* @4891488 cast */
    /* @4891492 constant */
    /* @4891496 cast */
    /* @4891500 constant */
    /* @4891504 load */
    /* @4891512 cast */
    /* @4891516 load */
    /* @4891524 constant */
    /* @4891528 add */
    /* @4891532 constant */
    /* @4891536 load */
    /* @4891544 cast */
    /* @4891548 load */
    /* @4891556 constant */
    /* @4891560 add */
    /* @4891564 constant */
    /* @4891568 cast */
    /* @4891572 constant */
    /* @4891576 cast */
    /* @4891580 call */
    GM_SITE(vm, 591, 4891580);
    v27 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v28 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4891588 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v27, v28, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4891592 load */
    /* @4891600 constant */
    /* @4891604 cmp */
    /* @4891608 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4891728;
    /* @4891612 constant */
    /* @4891616 cast */
    /* @4891620 call */
    GM_SITE(vm, 591, 4891620);
    /* @4891628 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4891632 constant */
    /* @4891640 cast */
    /* @4891644 call */
    GM_SITE(vm, 591, 4891644);
    /* @4891652 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4891656 string */
    /* @4891664 cast */
    /* @4891668 constant */
    /* @4891672 constant */
    /* @4891676 load */
    /* @4891684 constant */
    /* @4891688 add */
    /* @4891692 constant */
    /* @4891696 constant */
    /* @4891700 load */
    /* @4891708 constant */
    /* @4891712 add */
    /* @4891716 call */
    GM_SITE(vm, 591, 4891716);
    v29 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(150));
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(200));
    /* @4891724 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v29, v30, STR_REF(743)));
    L_4891728: ;
    /* @4891728 load */
    /* @4891736 constant */
    /* @4891740 cmp */
    /* @4891744 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4892272;
    /* @4891748 constant */
    /* @4891752 cast */
    /* @4891756 constant */
    /* @4891760 cast */
    /* @4891764 constant */
    /* @4891768 cast */
    /* @4891772 constant */
    /* @4891784 cast */
    /* @4891788 constant */
    /* @4891800 cast */
    /* @4891804 constant */
    /* @4891808 constant */
    /* @4891812 load */
    /* @4891820 constant */
    /* @4891824 constant */
    /* @4891828 load */
    /* @4891836 constant */
    /* @4891840 sub */
    /* @4891844 constant */
    /* @4891848 cast */
    /* @4891852 constant */
    /* @4891856 cast */
    /* @4891860 call */
    GM_SITE(vm, 591, 4891860);
    /* @4891868 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(1.06), VAL(0.86), VAL(0), VAL(-1), VAL(1)));
    /* @4891872 constant */
    /* @4891876 cast */
    /* @4891880 constant */
    /* @4891884 cast */
    /* @4891888 constant */
    /* @4891892 cast */
    /* @4891896 constant */
    /* @4891900 cast */
    /* @4891904 constant */
    /* @4891908 cast */
    /* @4891912 constant */
    /* @4891916 load */
    /* @4891924 cast */
    /* @4891928 load */
    /* @4891936 constant */
    /* @4891940 add */
    /* @4891944 constant */
    /* @4891948 load */
    /* @4891956 cast */
    /* @4891960 load */
    /* @4891968 constant */
    /* @4891972 add */
    /* @4891976 constant */
    /* @4891980 cast */
    /* @4891984 constant */
    /* @4891988 cast */
    /* @4891992 call */
    GM_SITE(vm, 591, 4891992);
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v32 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4892000 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v31, v32, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4892004 constant */
    /* @4892008 cast */
    /* @4892012 constant */
    /* @4892016 cast */
    /* @4892020 constant */
    /* @4892024 cast */
    /* @4892028 constant */
    /* @4892032 cast */
    /* @4892036 constant */
    /* @4892040 cast */
    /* @4892044 constant */
    /* @4892048 load */
    /* @4892056 cast */
    /* @4892060 load */
    /* @4892068 constant */
    /* @4892072 add */
    /* @4892076 constant */
    /* @4892080 load */
    /* @4892088 cast */
    /* @4892092 load */
    /* @4892100 constant */
    /* @4892104 add */
    /* @4892108 constant */
    /* @4892112 cast */
    /* @4892116 constant */
    /* @4892120 cast */
    /* @4892124 call */
    GM_SITE(vm, 591, 4892124);
    v33 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(390));
    v34 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4892132 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v33, v34, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4892136 load */
    /* @4892144 constant */
    /* @4892148 cmp */
    /* @4892152 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4892272;
    /* @4892156 constant */
    /* @4892160 cast */
    /* @4892164 call */
    GM_SITE(vm, 591, 4892164);
    /* @4892172 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4892176 constant */
    /* @4892184 cast */
    /* @4892188 call */
    GM_SITE(vm, 591, 4892188);
    /* @4892196 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4892200 string */
    /* @4892208 cast */
    /* @4892212 constant */
    /* @4892216 constant */
    /* @4892220 load */
    /* @4892228 constant */
    /* @4892232 add */
    /* @4892236 constant */
    /* @4892240 constant */
    /* @4892244 load */
    /* @4892252 constant */
    /* @4892256 add */
    /* @4892260 call */
    GM_SITE(vm, 591, 4892260);
    v35 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(160));
    v36 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(200));
    /* @4892268 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v35, v36, STR_REF(743)));
    L_4892272: ;
    /* @4892272 load */
    /* @4892280 constant */
    /* @4892284 cmp */
    /* @4892288 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel1") == VAL(1)))) goto L_4893732;
    /* @4892292 load */
    /* @4892300 constant */
    /* @4892304 cmp */
    /* @4892308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4892532;
    /* @4892312 constant */
    /* @4892316 cast */
    /* @4892320 call */
    GM_SITE(vm, 591, 4892320);
    /* @4892328 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4892332 constant */
    /* @4892340 cast */
    /* @4892344 call */
    GM_SITE(vm, 591, 4892344);
    /* @4892352 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4892356 string */
    /* @4892364 cast */
    /* @4892368 constant */
    /* @4892372 load */
    /* @4892380 cast */
    /* @4892384 load */
    /* @4892392 constant */
    /* @4892396 add */
    /* @4892400 constant */
    /* @4892404 load */
    /* @4892412 cast */
    /* @4892416 load */
    /* @4892424 constant */
    /* @4892428 add */
    /* @4892432 call */
    GM_SITE(vm, 591, 4892432);
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4892440 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v37, v38, STR_REF(1067)));
    /* @4892444 string */
    /* @4892452 cast */
    /* @4892456 constant */
    /* @4892460 load */
    /* @4892468 cast */
    /* @4892472 load */
    /* @4892480 constant */
    /* @4892484 add */
    /* @4892488 constant */
    /* @4892492 load */
    /* @4892500 cast */
    /* @4892504 load */
    /* @4892512 constant */
    /* @4892516 add */
    /* @4892520 call */
    GM_SITE(vm, 591, 4892520);
    v39 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v40 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4892528 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, v40, STR_REF(1068)));
    L_4892532: ;
    /* @4892532 load */
    /* @4892540 constant */
    /* @4892544 cmp */
    /* @4892548 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4892772;
    /* @4892552 constant */
    /* @4892556 cast */
    /* @4892560 call */
    GM_SITE(vm, 591, 4892560);
    /* @4892568 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4892572 constant */
    /* @4892580 cast */
    /* @4892584 call */
    GM_SITE(vm, 591, 4892584);
    /* @4892592 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4892596 string */
    /* @4892604 cast */
    /* @4892608 constant */
    /* @4892612 load */
    /* @4892620 cast */
    /* @4892624 load */
    /* @4892632 constant */
    /* @4892636 add */
    /* @4892640 constant */
    /* @4892644 load */
    /* @4892652 cast */
    /* @4892656 load */
    /* @4892664 constant */
    /* @4892668 add */
    /* @4892672 call */
    GM_SITE(vm, 591, 4892672);
    v41 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v42 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4892680 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v41, v42, STR_REF(1067)));
    /* @4892684 string */
    /* @4892692 cast */
    /* @4892696 constant */
    /* @4892700 load */
    /* @4892708 cast */
    /* @4892712 load */
    /* @4892720 constant */
    /* @4892724 add */
    /* @4892728 constant */
    /* @4892732 load */
    /* @4892740 cast */
    /* @4892744 load */
    /* @4892752 constant */
    /* @4892756 add */
    /* @4892760 call */
    GM_SITE(vm, 591, 4892760);
    v43 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v44 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4892768 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v43, v44, STR_REF(1068)));
    L_4892772: ;
    /* @4892772 load */
    /* @4892780 constant */
    /* @4892784 cmp */
    /* @4892788 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4893012;
    /* @4892792 constant */
    /* @4892796 cast */
    /* @4892800 call */
    GM_SITE(vm, 591, 4892800);
    /* @4892808 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4892812 constant */
    /* @4892820 cast */
    /* @4892824 call */
    GM_SITE(vm, 591, 4892824);
    /* @4892832 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4892836 string */
    /* @4892844 cast */
    /* @4892848 constant */
    /* @4892852 load */
    /* @4892860 cast */
    /* @4892864 load */
    /* @4892872 constant */
    /* @4892876 add */
    /* @4892880 constant */
    /* @4892884 load */
    /* @4892892 cast */
    /* @4892896 load */
    /* @4892904 constant */
    /* @4892908 add */
    /* @4892912 call */
    GM_SITE(vm, 591, 4892912);
    v45 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v46 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4892920 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v45, v46, STR_REF(1067)));
    /* @4892924 string */
    /* @4892932 cast */
    /* @4892936 constant */
    /* @4892940 load */
    /* @4892948 cast */
    /* @4892952 load */
    /* @4892960 constant */
    /* @4892964 add */
    /* @4892968 constant */
    /* @4892972 load */
    /* @4892980 cast */
    /* @4892984 load */
    /* @4892992 constant */
    /* @4892996 add */
    /* @4893000 call */
    GM_SITE(vm, 591, 4893000);
    v47 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v48 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4893008 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v47, v48, STR_REF(1068)));
    L_4893012: ;
    /* @4893012 load */
    /* @4893020 constant */
    /* @4893024 cmp */
    /* @4893028 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4893252;
    /* @4893032 constant */
    /* @4893036 cast */
    /* @4893040 call */
    GM_SITE(vm, 591, 4893040);
    /* @4893048 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4893052 constant */
    /* @4893060 cast */
    /* @4893064 call */
    GM_SITE(vm, 591, 4893064);
    /* @4893072 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4893076 string */
    /* @4893084 cast */
    /* @4893088 constant */
    /* @4893092 load */
    /* @4893100 cast */
    /* @4893104 load */
    /* @4893112 constant */
    /* @4893116 add */
    /* @4893120 constant */
    /* @4893124 load */
    /* @4893132 cast */
    /* @4893136 load */
    /* @4893144 constant */
    /* @4893148 add */
    /* @4893152 call */
    GM_SITE(vm, 591, 4893152);
    v49 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v50 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4893160 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v49, v50, STR_REF(1067)));
    /* @4893164 string */
    /* @4893172 cast */
    /* @4893176 constant */
    /* @4893180 load */
    /* @4893188 cast */
    /* @4893192 load */
    /* @4893200 constant */
    /* @4893204 add */
    /* @4893208 constant */
    /* @4893212 load */
    /* @4893220 cast */
    /* @4893224 load */
    /* @4893232 constant */
    /* @4893236 add */
    /* @4893240 call */
    GM_SITE(vm, 591, 4893240);
    v51 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v52 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4893248 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v51, v52, STR_REF(1068)));
    L_4893252: ;
    /* @4893252 load */
    /* @4893260 constant */
    /* @4893264 cmp */
    /* @4893268 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4893492;
    /* @4893272 constant */
    /* @4893276 cast */
    /* @4893280 call */
    GM_SITE(vm, 591, 4893280);
    /* @4893288 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4893292 constant */
    /* @4893300 cast */
    /* @4893304 call */
    GM_SITE(vm, 591, 4893304);
    /* @4893312 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4893316 string */
    /* @4893324 cast */
    /* @4893328 constant */
    /* @4893332 load */
    /* @4893340 cast */
    /* @4893344 load */
    /* @4893352 constant */
    /* @4893356 add */
    /* @4893360 constant */
    /* @4893364 load */
    /* @4893372 cast */
    /* @4893376 load */
    /* @4893384 constant */
    /* @4893388 add */
    /* @4893392 call */
    GM_SITE(vm, 591, 4893392);
    v53 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v54 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4893400 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v53, v54, STR_REF(1067)));
    /* @4893404 string */
    /* @4893412 cast */
    /* @4893416 constant */
    /* @4893420 load */
    /* @4893428 cast */
    /* @4893432 load */
    /* @4893440 constant */
    /* @4893444 add */
    /* @4893448 constant */
    /* @4893452 load */
    /* @4893460 cast */
    /* @4893464 load */
    /* @4893472 constant */
    /* @4893476 add */
    /* @4893480 call */
    GM_SITE(vm, 591, 4893480);
    v55 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v56 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4893488 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v55, v56, STR_REF(1068)));
    L_4893492: ;
    /* @4893492 load */
    /* @4893500 constant */
    /* @4893504 cmp */
    /* @4893508 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4893732;
    /* @4893512 constant */
    /* @4893516 cast */
    /* @4893520 call */
    GM_SITE(vm, 591, 4893520);
    /* @4893528 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4893532 constant */
    /* @4893540 cast */
    /* @4893544 call */
    GM_SITE(vm, 591, 4893544);
    /* @4893552 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4893556 string */
    /* @4893564 cast */
    /* @4893568 constant */
    /* @4893572 load */
    /* @4893580 cast */
    /* @4893584 load */
    /* @4893592 constant */
    /* @4893596 add */
    /* @4893600 constant */
    /* @4893604 load */
    /* @4893612 cast */
    /* @4893616 load */
    /* @4893624 constant */
    /* @4893628 add */
    /* @4893632 call */
    GM_SITE(vm, 591, 4893632);
    v57 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v58 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4893640 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v57, v58, STR_REF(1067)));
    /* @4893644 string */
    /* @4893652 cast */
    /* @4893656 constant */
    /* @4893660 load */
    /* @4893668 cast */
    /* @4893672 load */
    /* @4893680 constant */
    /* @4893684 add */
    /* @4893688 constant */
    /* @4893692 load */
    /* @4893700 cast */
    /* @4893704 load */
    /* @4893712 constant */
    /* @4893716 add */
    /* @4893720 call */
    GM_SITE(vm, 591, 4893720);
    v59 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v60 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4893728 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v59, v60, STR_REF(1068)));
    L_4893732: ;
    /* @4893732 load */
    /* @4893740 constant */
    /* @4893744 cmp */
    /* @4893748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel2") == VAL(1)))) goto L_4895192;
    /* @4893752 load */
    /* @4893760 constant */
    /* @4893764 cmp */
    /* @4893768 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4893992;
    /* @4893772 constant */
    /* @4893776 cast */
    /* @4893780 call */
    GM_SITE(vm, 591, 4893780);
    /* @4893788 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4893792 constant */
    /* @4893800 cast */
    /* @4893804 call */
    GM_SITE(vm, 591, 4893804);
    /* @4893812 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4893816 string */
    /* @4893824 cast */
    /* @4893828 constant */
    /* @4893832 load */
    /* @4893840 cast */
    /* @4893844 load */
    /* @4893852 constant */
    /* @4893856 add */
    /* @4893860 constant */
    /* @4893864 load */
    /* @4893872 cast */
    /* @4893876 load */
    /* @4893884 constant */
    /* @4893888 add */
    /* @4893892 call */
    GM_SITE(vm, 591, 4893892);
    v61 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v62 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4893900 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v61, v62, STR_REF(1069)));
    /* @4893904 string */
    /* @4893912 cast */
    /* @4893916 constant */
    /* @4893920 load */
    /* @4893928 cast */
    /* @4893932 load */
    /* @4893940 constant */
    /* @4893944 add */
    /* @4893948 constant */
    /* @4893952 load */
    /* @4893960 cast */
    /* @4893964 load */
    /* @4893972 constant */
    /* @4893976 add */
    /* @4893980 call */
    GM_SITE(vm, 591, 4893980);
    v63 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v64 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4893988 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v63, v64, STR_REF(1070)));
    L_4893992: ;
    /* @4893992 load */
    /* @4894000 constant */
    /* @4894004 cmp */
    /* @4894008 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4894232;
    /* @4894012 constant */
    /* @4894016 cast */
    /* @4894020 call */
    GM_SITE(vm, 591, 4894020);
    /* @4894028 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4894032 constant */
    /* @4894040 cast */
    /* @4894044 call */
    GM_SITE(vm, 591, 4894044);
    /* @4894052 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4894056 string */
    /* @4894064 cast */
    /* @4894068 constant */
    /* @4894072 load */
    /* @4894080 cast */
    /* @4894084 load */
    /* @4894092 constant */
    /* @4894096 add */
    /* @4894100 constant */
    /* @4894104 load */
    /* @4894112 cast */
    /* @4894116 load */
    /* @4894124 constant */
    /* @4894128 add */
    /* @4894132 call */
    GM_SITE(vm, 591, 4894132);
    v65 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v66 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    /* @4894140 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v65, v66, STR_REF(1069)));
    /* @4894144 string */
    /* @4894152 cast */
    /* @4894156 constant */
    /* @4894160 load */
    /* @4894168 cast */
    /* @4894172 load */
    /* @4894180 constant */
    /* @4894184 add */
    /* @4894188 constant */
    /* @4894192 load */
    /* @4894200 cast */
    /* @4894204 load */
    /* @4894212 constant */
    /* @4894216 add */
    /* @4894220 call */
    GM_SITE(vm, 591, 4894220);
    v67 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v68 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(140));
    /* @4894228 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v67, v68, STR_REF(1070)));
    L_4894232: ;
    /* @4894232 load */
    /* @4894240 constant */
    /* @4894244 cmp */
    /* @4894248 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4894472;
    /* @4894252 constant */
    /* @4894256 cast */
    /* @4894260 call */
    GM_SITE(vm, 591, 4894260);
    /* @4894268 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4894272 constant */
    /* @4894280 cast */
    /* @4894284 call */
    GM_SITE(vm, 591, 4894284);
    /* @4894292 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4894296 string */
    /* @4894304 cast */
    /* @4894308 constant */
    /* @4894312 load */
    /* @4894320 cast */
    /* @4894324 load */
    /* @4894332 constant */
    /* @4894336 add */
    /* @4894340 constant */
    /* @4894344 load */
    /* @4894352 cast */
    /* @4894356 load */
    /* @4894364 constant */
    /* @4894368 add */
    /* @4894372 call */
    GM_SITE(vm, 591, 4894372);
    v69 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v70 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4894380 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v69, v70, STR_REF(1069)));
    /* @4894384 string */
    /* @4894392 cast */
    /* @4894396 constant */
    /* @4894400 load */
    /* @4894408 cast */
    /* @4894412 load */
    /* @4894420 constant */
    /* @4894424 add */
    /* @4894428 constant */
    /* @4894432 load */
    /* @4894440 cast */
    /* @4894444 load */
    /* @4894452 constant */
    /* @4894456 add */
    /* @4894460 call */
    GM_SITE(vm, 591, 4894460);
    v71 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v72 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4894468 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v71, v72, STR_REF(1070)));
    L_4894472: ;
    /* @4894472 load */
    /* @4894480 constant */
    /* @4894484 cmp */
    /* @4894488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4894712;
    /* @4894492 constant */
    /* @4894496 cast */
    /* @4894500 call */
    GM_SITE(vm, 591, 4894500);
    /* @4894508 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4894512 constant */
    /* @4894520 cast */
    /* @4894524 call */
    GM_SITE(vm, 591, 4894524);
    /* @4894532 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4894536 string */
    /* @4894544 cast */
    /* @4894548 constant */
    /* @4894552 load */
    /* @4894560 cast */
    /* @4894564 load */
    /* @4894572 constant */
    /* @4894576 add */
    /* @4894580 constant */
    /* @4894584 load */
    /* @4894592 cast */
    /* @4894596 load */
    /* @4894604 constant */
    /* @4894608 add */
    /* @4894612 call */
    GM_SITE(vm, 591, 4894612);
    v73 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v74 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4894620 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v73, v74, STR_REF(1069)));
    /* @4894624 string */
    /* @4894632 cast */
    /* @4894636 constant */
    /* @4894640 load */
    /* @4894648 cast */
    /* @4894652 load */
    /* @4894660 constant */
    /* @4894664 add */
    /* @4894668 constant */
    /* @4894672 load */
    /* @4894680 cast */
    /* @4894684 load */
    /* @4894692 constant */
    /* @4894696 add */
    /* @4894700 call */
    GM_SITE(vm, 591, 4894700);
    v75 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v76 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4894708 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v75, v76, STR_REF(1070)));
    L_4894712: ;
    /* @4894712 load */
    /* @4894720 constant */
    /* @4894724 cmp */
    /* @4894728 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4894952;
    /* @4894732 constant */
    /* @4894736 cast */
    /* @4894740 call */
    GM_SITE(vm, 591, 4894740);
    /* @4894748 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4894752 constant */
    /* @4894760 cast */
    /* @4894764 call */
    GM_SITE(vm, 591, 4894764);
    /* @4894772 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4894776 string */
    /* @4894784 cast */
    /* @4894788 constant */
    /* @4894792 load */
    /* @4894800 cast */
    /* @4894804 load */
    /* @4894812 constant */
    /* @4894816 add */
    /* @4894820 constant */
    /* @4894824 load */
    /* @4894832 cast */
    /* @4894836 load */
    /* @4894844 constant */
    /* @4894848 add */
    /* @4894852 call */
    GM_SITE(vm, 591, 4894852);
    v77 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v78 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4894860 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v77, v78, STR_REF(1069)));
    /* @4894864 string */
    /* @4894872 cast */
    /* @4894876 constant */
    /* @4894880 load */
    /* @4894888 cast */
    /* @4894892 load */
    /* @4894900 constant */
    /* @4894904 add */
    /* @4894908 constant */
    /* @4894912 load */
    /* @4894920 cast */
    /* @4894924 load */
    /* @4894932 constant */
    /* @4894936 add */
    /* @4894940 call */
    GM_SITE(vm, 591, 4894940);
    v79 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v80 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4894948 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v79, v80, STR_REF(1070)));
    L_4894952: ;
    /* @4894952 load */
    /* @4894960 constant */
    /* @4894964 cmp */
    /* @4894968 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4895192;
    /* @4894972 constant */
    /* @4894976 cast */
    /* @4894980 call */
    GM_SITE(vm, 591, 4894980);
    /* @4894988 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4894992 constant */
    /* @4895000 cast */
    /* @4895004 call */
    GM_SITE(vm, 591, 4895004);
    /* @4895012 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4895016 string */
    /* @4895024 cast */
    /* @4895028 constant */
    /* @4895032 load */
    /* @4895040 cast */
    /* @4895044 load */
    /* @4895052 constant */
    /* @4895056 add */
    /* @4895060 constant */
    /* @4895064 load */
    /* @4895072 cast */
    /* @4895076 load */
    /* @4895084 constant */
    /* @4895088 add */
    /* @4895092 call */
    GM_SITE(vm, 591, 4895092);
    v81 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v82 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4895100 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v81, v82, STR_REF(1069)));
    /* @4895104 string */
    /* @4895112 cast */
    /* @4895116 constant */
    /* @4895120 load */
    /* @4895128 cast */
    /* @4895132 load */
    /* @4895140 constant */
    /* @4895144 add */
    /* @4895148 constant */
    /* @4895152 load */
    /* @4895160 cast */
    /* @4895164 load */
    /* @4895172 constant */
    /* @4895176 add */
    /* @4895180 call */
    GM_SITE(vm, 591, 4895180);
    v83 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    v84 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4895188 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v83, v84, STR_REF(1070)));
    L_4895192: ;
    /* @4895192 load */
    /* @4895200 constant */
    /* @4895204 cmp */
    /* @4895208 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel3") == VAL(1)))) goto L_4896652;
    /* @4895212 load */
    /* @4895220 constant */
    /* @4895224 cmp */
    /* @4895228 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4895452;
    /* @4895232 constant */
    /* @4895236 cast */
    /* @4895240 call */
    GM_SITE(vm, 591, 4895240);
    /* @4895248 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4895252 constant */
    /* @4895260 cast */
    /* @4895264 call */
    GM_SITE(vm, 591, 4895264);
    /* @4895272 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4895276 string */
    /* @4895284 cast */
    /* @4895288 constant */
    /* @4895292 load */
    /* @4895300 cast */
    /* @4895304 load */
    /* @4895312 constant */
    /* @4895316 add */
    /* @4895320 constant */
    /* @4895324 load */
    /* @4895332 cast */
    /* @4895336 load */
    /* @4895344 constant */
    /* @4895348 add */
    /* @4895352 call */
    GM_SITE(vm, 591, 4895352);
    v85 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v86 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4895360 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v85, v86, STR_REF(1071)));
    /* @4895364 string */
    /* @4895372 cast */
    /* @4895376 constant */
    /* @4895380 load */
    /* @4895388 cast */
    /* @4895392 load */
    /* @4895400 constant */
    /* @4895404 add */
    /* @4895408 constant */
    /* @4895412 load */
    /* @4895420 cast */
    /* @4895424 load */
    /* @4895432 constant */
    /* @4895436 add */
    /* @4895440 call */
    GM_SITE(vm, 591, 4895440);
    v87 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v88 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4895448 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v87, v88, STR_REF(1072)));
    L_4895452: ;
    /* @4895452 load */
    /* @4895460 constant */
    /* @4895464 cmp */
    /* @4895468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4895692;
    /* @4895472 constant */
    /* @4895476 cast */
    /* @4895480 call */
    GM_SITE(vm, 591, 4895480);
    /* @4895488 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4895492 constant */
    /* @4895500 cast */
    /* @4895504 call */
    GM_SITE(vm, 591, 4895504);
    /* @4895512 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4895516 string */
    /* @4895524 cast */
    /* @4895528 constant */
    /* @4895532 load */
    /* @4895540 cast */
    /* @4895544 load */
    /* @4895552 constant */
    /* @4895556 add */
    /* @4895560 constant */
    /* @4895564 load */
    /* @4895572 cast */
    /* @4895576 load */
    /* @4895584 constant */
    /* @4895588 add */
    /* @4895592 call */
    GM_SITE(vm, 591, 4895592);
    v89 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v90 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4895600 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v89, v90, STR_REF(1071)));
    /* @4895604 string */
    /* @4895612 cast */
    /* @4895616 constant */
    /* @4895620 load */
    /* @4895628 cast */
    /* @4895632 load */
    /* @4895640 constant */
    /* @4895644 add */
    /* @4895648 constant */
    /* @4895652 load */
    /* @4895660 cast */
    /* @4895664 load */
    /* @4895672 constant */
    /* @4895676 add */
    /* @4895680 call */
    GM_SITE(vm, 591, 4895680);
    v91 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v92 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4895688 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v91, v92, STR_REF(1072)));
    L_4895692: ;
    /* @4895692 load */
    /* @4895700 constant */
    /* @4895704 cmp */
    /* @4895708 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4895932;
    /* @4895712 constant */
    /* @4895716 cast */
    /* @4895720 call */
    GM_SITE(vm, 591, 4895720);
    /* @4895728 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4895732 constant */
    /* @4895740 cast */
    /* @4895744 call */
    GM_SITE(vm, 591, 4895744);
    /* @4895752 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4895756 string */
    /* @4895764 cast */
    /* @4895768 constant */
    /* @4895772 load */
    /* @4895780 cast */
    /* @4895784 load */
    /* @4895792 constant */
    /* @4895796 add */
    /* @4895800 constant */
    /* @4895804 load */
    /* @4895812 cast */
    /* @4895816 load */
    /* @4895824 constant */
    /* @4895828 add */
    /* @4895832 call */
    GM_SITE(vm, 591, 4895832);
    v93 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v94 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4895840 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v93, v94, STR_REF(1071)));
    /* @4895844 string */
    /* @4895852 cast */
    /* @4895856 constant */
    /* @4895860 load */
    /* @4895868 cast */
    /* @4895872 load */
    /* @4895880 constant */
    /* @4895884 add */
    /* @4895888 constant */
    /* @4895892 load */
    /* @4895900 cast */
    /* @4895904 load */
    /* @4895912 constant */
    /* @4895916 add */
    /* @4895920 call */
    GM_SITE(vm, 591, 4895920);
    v95 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v96 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4895928 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v95, v96, STR_REF(1072)));
    L_4895932: ;
    /* @4895932 load */
    /* @4895940 constant */
    /* @4895944 cmp */
    /* @4895948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4896172;
    /* @4895952 constant */
    /* @4895956 cast */
    /* @4895960 call */
    GM_SITE(vm, 591, 4895960);
    /* @4895968 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4895972 constant */
    /* @4895980 cast */
    /* @4895984 call */
    GM_SITE(vm, 591, 4895984);
    /* @4895992 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4895996 string */
    /* @4896004 cast */
    /* @4896008 constant */
    /* @4896012 load */
    /* @4896020 cast */
    /* @4896024 load */
    /* @4896032 constant */
    /* @4896036 add */
    /* @4896040 constant */
    /* @4896044 load */
    /* @4896052 cast */
    /* @4896056 load */
    /* @4896064 constant */
    /* @4896068 add */
    /* @4896072 call */
    GM_SITE(vm, 591, 4896072);
    v97 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v98 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4896080 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v97, v98, STR_REF(1071)));
    /* @4896084 string */
    /* @4896092 cast */
    /* @4896096 constant */
    /* @4896100 load */
    /* @4896108 cast */
    /* @4896112 load */
    /* @4896120 constant */
    /* @4896124 add */
    /* @4896128 constant */
    /* @4896132 load */
    /* @4896140 cast */
    /* @4896144 load */
    /* @4896152 constant */
    /* @4896156 add */
    /* @4896160 call */
    GM_SITE(vm, 591, 4896160);
    v99 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v100 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4896168 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v99, v100, STR_REF(1072)));
    L_4896172: ;
    /* @4896172 load */
    /* @4896180 constant */
    /* @4896184 cmp */
    /* @4896188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4896412;
    /* @4896192 constant */
    /* @4896196 cast */
    /* @4896200 call */
    GM_SITE(vm, 591, 4896200);
    /* @4896208 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4896212 constant */
    /* @4896220 cast */
    /* @4896224 call */
    GM_SITE(vm, 591, 4896224);
    /* @4896232 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4896236 string */
    /* @4896244 cast */
    /* @4896248 constant */
    /* @4896252 load */
    /* @4896260 cast */
    /* @4896264 load */
    /* @4896272 constant */
    /* @4896276 add */
    /* @4896280 constant */
    /* @4896284 load */
    /* @4896292 cast */
    /* @4896296 load */
    /* @4896304 constant */
    /* @4896308 add */
    /* @4896312 call */
    GM_SITE(vm, 591, 4896312);
    v101 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v102 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4896320 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v101, v102, STR_REF(1071)));
    /* @4896324 string */
    /* @4896332 cast */
    /* @4896336 constant */
    /* @4896340 load */
    /* @4896348 cast */
    /* @4896352 load */
    /* @4896360 constant */
    /* @4896364 add */
    /* @4896368 constant */
    /* @4896372 load */
    /* @4896380 cast */
    /* @4896384 load */
    /* @4896392 constant */
    /* @4896396 add */
    /* @4896400 call */
    GM_SITE(vm, 591, 4896400);
    v103 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v104 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4896408 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v103, v104, STR_REF(1072)));
    L_4896412: ;
    /* @4896412 load */
    /* @4896420 constant */
    /* @4896424 cmp */
    /* @4896428 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4896652;
    /* @4896432 constant */
    /* @4896436 cast */
    /* @4896440 call */
    GM_SITE(vm, 591, 4896440);
    /* @4896448 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4896452 constant */
    /* @4896460 cast */
    /* @4896464 call */
    GM_SITE(vm, 591, 4896464);
    /* @4896472 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4896476 string */
    /* @4896484 cast */
    /* @4896488 constant */
    /* @4896492 load */
    /* @4896500 cast */
    /* @4896504 load */
    /* @4896512 constant */
    /* @4896516 add */
    /* @4896520 constant */
    /* @4896524 load */
    /* @4896532 cast */
    /* @4896536 load */
    /* @4896544 constant */
    /* @4896548 add */
    /* @4896552 call */
    GM_SITE(vm, 591, 4896552);
    v105 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v106 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4896560 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v105, v106, STR_REF(1071)));
    /* @4896564 string */
    /* @4896572 cast */
    /* @4896576 constant */
    /* @4896580 load */
    /* @4896588 cast */
    /* @4896592 load */
    /* @4896600 constant */
    /* @4896604 add */
    /* @4896608 constant */
    /* @4896612 load */
    /* @4896620 cast */
    /* @4896624 load */
    /* @4896632 constant */
    /* @4896636 add */
    /* @4896640 call */
    GM_SITE(vm, 591, 4896640);
    v107 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v108 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4896648 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v107, v108, STR_REF(1072)));
    L_4896652: ;
    /* @4896652 load */
    /* @4896660 constant */
    /* @4896664 cmp */
    /* @4896668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel4") == VAL(1)))) goto L_4898112;
    /* @4896672 load */
    /* @4896680 constant */
    /* @4896684 cmp */
    /* @4896688 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4896912;
    /* @4896692 constant */
    /* @4896696 cast */
    /* @4896700 call */
    GM_SITE(vm, 591, 4896700);
    /* @4896708 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4896712 constant */
    /* @4896720 cast */
    /* @4896724 call */
    GM_SITE(vm, 591, 4896724);
    /* @4896732 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4896736 string */
    /* @4896744 cast */
    /* @4896748 constant */
    /* @4896752 load */
    /* @4896760 cast */
    /* @4896764 load */
    /* @4896772 constant */
    /* @4896776 add */
    /* @4896780 constant */
    /* @4896784 load */
    /* @4896792 cast */
    /* @4896796 load */
    /* @4896804 constant */
    /* @4896808 add */
    /* @4896812 call */
    GM_SITE(vm, 591, 4896812);
    v109 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v110 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4896820 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v109, v110, STR_REF(1073)));
    /* @4896824 string */
    /* @4896832 cast */
    /* @4896836 constant */
    /* @4896840 load */
    /* @4896848 cast */
    /* @4896852 load */
    /* @4896860 constant */
    /* @4896864 add */
    /* @4896868 constant */
    /* @4896872 load */
    /* @4896880 cast */
    /* @4896884 load */
    /* @4896892 constant */
    /* @4896896 add */
    /* @4896900 call */
    GM_SITE(vm, 591, 4896900);
    v111 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v112 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4896908 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v111, v112, STR_REF(1065)));
    L_4896912: ;
    /* @4896912 load */
    /* @4896920 constant */
    /* @4896924 cmp */
    /* @4896928 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4897152;
    /* @4896932 constant */
    /* @4896936 cast */
    /* @4896940 call */
    GM_SITE(vm, 591, 4896940);
    /* @4896948 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4896952 constant */
    /* @4896960 cast */
    /* @4896964 call */
    GM_SITE(vm, 591, 4896964);
    /* @4896972 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4896976 string */
    /* @4896984 cast */
    /* @4896988 constant */
    /* @4896992 load */
    /* @4897000 cast */
    /* @4897004 load */
    /* @4897012 constant */
    /* @4897016 add */
    /* @4897020 constant */
    /* @4897024 load */
    /* @4897032 cast */
    /* @4897036 load */
    /* @4897044 constant */
    /* @4897048 add */
    /* @4897052 call */
    GM_SITE(vm, 591, 4897052);
    v113 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v114 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4897060 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v113, v114, STR_REF(1073)));
    /* @4897064 string */
    /* @4897072 cast */
    /* @4897076 constant */
    /* @4897080 load */
    /* @4897088 cast */
    /* @4897092 load */
    /* @4897100 constant */
    /* @4897104 add */
    /* @4897108 constant */
    /* @4897112 load */
    /* @4897120 cast */
    /* @4897124 load */
    /* @4897132 constant */
    /* @4897136 add */
    /* @4897140 call */
    GM_SITE(vm, 591, 4897140);
    v115 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v116 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4897148 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v115, v116, STR_REF(1065)));
    L_4897152: ;
    /* @4897152 load */
    /* @4897160 constant */
    /* @4897164 cmp */
    /* @4897168 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4897392;
    /* @4897172 constant */
    /* @4897176 cast */
    /* @4897180 call */
    GM_SITE(vm, 591, 4897180);
    /* @4897188 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4897192 constant */
    /* @4897200 cast */
    /* @4897204 call */
    GM_SITE(vm, 591, 4897204);
    /* @4897212 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4897216 string */
    /* @4897224 cast */
    /* @4897228 constant */
    /* @4897232 load */
    /* @4897240 cast */
    /* @4897244 load */
    /* @4897252 constant */
    /* @4897256 add */
    /* @4897260 constant */
    /* @4897264 load */
    /* @4897272 cast */
    /* @4897276 load */
    /* @4897284 constant */
    /* @4897288 add */
    /* @4897292 call */
    GM_SITE(vm, 591, 4897292);
    v117 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v118 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4897300 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v117, v118, STR_REF(1073)));
    /* @4897304 string */
    /* @4897312 cast */
    /* @4897316 constant */
    /* @4897320 load */
    /* @4897328 cast */
    /* @4897332 load */
    /* @4897340 constant */
    /* @4897344 add */
    /* @4897348 constant */
    /* @4897352 load */
    /* @4897360 cast */
    /* @4897364 load */
    /* @4897372 constant */
    /* @4897376 add */
    /* @4897380 call */
    GM_SITE(vm, 591, 4897380);
    v119 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v120 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4897388 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v119, v120, STR_REF(1065)));
    L_4897392: ;
    /* @4897392 load */
    /* @4897400 constant */
    /* @4897404 cmp */
    /* @4897408 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4897632;
    /* @4897412 constant */
    /* @4897416 cast */
    /* @4897420 call */
    GM_SITE(vm, 591, 4897420);
    /* @4897428 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4897432 constant */
    /* @4897440 cast */
    /* @4897444 call */
    GM_SITE(vm, 591, 4897444);
    /* @4897452 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4897456 string */
    /* @4897464 cast */
    /* @4897468 constant */
    /* @4897472 load */
    /* @4897480 cast */
    /* @4897484 load */
    /* @4897492 constant */
    /* @4897496 add */
    /* @4897500 constant */
    /* @4897504 load */
    /* @4897512 cast */
    /* @4897516 load */
    /* @4897524 constant */
    /* @4897528 add */
    /* @4897532 call */
    GM_SITE(vm, 591, 4897532);
    v121 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v122 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4897540 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v121, v122, STR_REF(1073)));
    /* @4897544 string */
    /* @4897552 cast */
    /* @4897556 constant */
    /* @4897560 load */
    /* @4897568 cast */
    /* @4897572 load */
    /* @4897580 constant */
    /* @4897584 add */
    /* @4897588 constant */
    /* @4897592 load */
    /* @4897600 cast */
    /* @4897604 load */
    /* @4897612 constant */
    /* @4897616 add */
    /* @4897620 call */
    GM_SITE(vm, 591, 4897620);
    v123 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v124 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4897628 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v123, v124, STR_REF(1065)));
    L_4897632: ;
    /* @4897632 load */
    /* @4897640 constant */
    /* @4897644 cmp */
    /* @4897648 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4897872;
    /* @4897652 constant */
    /* @4897656 cast */
    /* @4897660 call */
    GM_SITE(vm, 591, 4897660);
    /* @4897668 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4897672 constant */
    /* @4897680 cast */
    /* @4897684 call */
    GM_SITE(vm, 591, 4897684);
    /* @4897692 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4897696 string */
    /* @4897704 cast */
    /* @4897708 constant */
    /* @4897712 load */
    /* @4897720 cast */
    /* @4897724 load */
    /* @4897732 constant */
    /* @4897736 add */
    /* @4897740 constant */
    /* @4897744 load */
    /* @4897752 cast */
    /* @4897756 load */
    /* @4897764 constant */
    /* @4897768 add */
    /* @4897772 call */
    GM_SITE(vm, 591, 4897772);
    v125 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v126 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4897780 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v125, v126, STR_REF(1073)));
    /* @4897784 string */
    /* @4897792 cast */
    /* @4897796 constant */
    /* @4897800 load */
    /* @4897808 cast */
    /* @4897812 load */
    /* @4897820 constant */
    /* @4897824 add */
    /* @4897828 constant */
    /* @4897832 load */
    /* @4897840 cast */
    /* @4897844 load */
    /* @4897852 constant */
    /* @4897856 add */
    /* @4897860 call */
    GM_SITE(vm, 591, 4897860);
    v127 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v128 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4897868 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v127, v128, STR_REF(1065)));
    L_4897872: ;
    /* @4897872 load */
    /* @4897880 constant */
    /* @4897884 cmp */
    /* @4897888 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4898112;
    /* @4897892 constant */
    /* @4897896 cast */
    /* @4897900 call */
    GM_SITE(vm, 591, 4897900);
    /* @4897908 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4897912 constant */
    /* @4897920 cast */
    /* @4897924 call */
    GM_SITE(vm, 591, 4897924);
    /* @4897932 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4897936 string */
    /* @4897944 cast */
    /* @4897948 constant */
    /* @4897952 load */
    /* @4897960 cast */
    /* @4897964 load */
    /* @4897972 constant */
    /* @4897976 add */
    /* @4897980 constant */
    /* @4897984 load */
    /* @4897992 cast */
    /* @4897996 load */
    /* @4898004 constant */
    /* @4898008 add */
    /* @4898012 call */
    GM_SITE(vm, 591, 4898012);
    v129 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v130 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4898020 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v129, v130, STR_REF(1073)));
    /* @4898024 string */
    /* @4898032 cast */
    /* @4898036 constant */
    /* @4898040 load */
    /* @4898048 cast */
    /* @4898052 load */
    /* @4898060 constant */
    /* @4898064 add */
    /* @4898068 constant */
    /* @4898072 load */
    /* @4898080 cast */
    /* @4898084 load */
    /* @4898092 constant */
    /* @4898096 add */
    /* @4898100 call */
    GM_SITE(vm, 591, 4898100);
    v131 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v132 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4898108 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v131, v132, STR_REF(1065)));
    L_4898112: ;
    /* @4898112 load */
    /* @4898120 constant */
    /* @4898124 cmp */
    /* @4898128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel5") == VAL(1)))) goto L_4899596;
    /* @4898132 load */
    /* @4898140 constant */
    /* @4898144 cmp */
    /* @4898148 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4898376;
    /* @4898152 constant */
    /* @4898156 cast */
    /* @4898160 call */
    GM_SITE(vm, 591, 4898160);
    /* @4898168 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4898172 constant */
    /* @4898180 cast */
    /* @4898184 call */
    GM_SITE(vm, 591, 4898184);
    /* @4898192 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4898196 string */
    /* @4898204 cast */
    /* @4898208 constant */
    /* @4898212 load */
    /* @4898220 cast */
    /* @4898224 load */
    /* @4898232 constant */
    /* @4898236 add */
    /* @4898240 constant */
    /* @4898244 load */
    /* @4898252 cast */
    /* @4898256 load */
    /* @4898264 constant */
    /* @4898268 add */
    /* @4898272 call */
    GM_SITE(vm, 591, 4898272);
    v133 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v134 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4898280 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v133, v134, STR_REF(1074)));
    /* @4898284 constant */
    /* @4898288 load */
    /* @4898296 cast */
    /* @4898300 load */
    /* @4898308 constant */
    /* @4898312 add */
    /* @4898316 constant */
    /* @4898320 load */
    /* @4898328 cast */
    /* @4898332 load */
    /* @4898340 constant */
    /* @4898344 add */
    /* @4898348 constant */
    /* @4898352 cast */
    /* @4898356 constant */
    /* @4898360 cast */
    /* @4898364 call */
    GM_SITE(vm, 591, 4898364);
    v135 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v136 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4898372 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(122), VAL(0), v135, v136));
    L_4898376: ;
    /* @4898376 load */
    /* @4898384 constant */
    /* @4898388 cmp */
    /* @4898392 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4898620;
    /* @4898396 constant */
    /* @4898400 cast */
    /* @4898404 call */
    GM_SITE(vm, 591, 4898404);
    /* @4898412 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4898416 constant */
    /* @4898424 cast */
    /* @4898428 call */
    GM_SITE(vm, 591, 4898428);
    /* @4898436 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4898440 string */
    /* @4898448 cast */
    /* @4898452 constant */
    /* @4898456 load */
    /* @4898464 cast */
    /* @4898468 load */
    /* @4898476 constant */
    /* @4898480 add */
    /* @4898484 constant */
    /* @4898488 load */
    /* @4898496 cast */
    /* @4898500 load */
    /* @4898508 constant */
    /* @4898512 add */
    /* @4898516 call */
    GM_SITE(vm, 591, 4898516);
    v137 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v138 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4898524 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v137, v138, STR_REF(1074)));
    /* @4898528 constant */
    /* @4898532 load */
    /* @4898540 cast */
    /* @4898544 load */
    /* @4898552 constant */
    /* @4898556 add */
    /* @4898560 constant */
    /* @4898564 load */
    /* @4898572 cast */
    /* @4898576 load */
    /* @4898584 constant */
    /* @4898588 add */
    /* @4898592 constant */
    /* @4898596 cast */
    /* @4898600 constant */
    /* @4898604 cast */
    /* @4898608 call */
    GM_SITE(vm, 591, 4898608);
    v139 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v140 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4898616 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(122), VAL(0), v139, v140));
    L_4898620: ;
    /* @4898620 load */
    /* @4898628 constant */
    /* @4898632 cmp */
    /* @4898636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4898864;
    /* @4898640 constant */
    /* @4898644 cast */
    /* @4898648 call */
    GM_SITE(vm, 591, 4898648);
    /* @4898656 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4898660 constant */
    /* @4898668 cast */
    /* @4898672 call */
    GM_SITE(vm, 591, 4898672);
    /* @4898680 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4898684 string */
    /* @4898692 cast */
    /* @4898696 constant */
    /* @4898700 load */
    /* @4898708 cast */
    /* @4898712 load */
    /* @4898720 constant */
    /* @4898724 add */
    /* @4898728 constant */
    /* @4898732 load */
    /* @4898740 cast */
    /* @4898744 load */
    /* @4898752 constant */
    /* @4898756 add */
    /* @4898760 call */
    GM_SITE(vm, 591, 4898760);
    v141 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v142 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4898768 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v141, v142, STR_REF(1074)));
    /* @4898772 constant */
    /* @4898776 load */
    /* @4898784 cast */
    /* @4898788 load */
    /* @4898796 constant */
    /* @4898800 add */
    /* @4898804 constant */
    /* @4898808 load */
    /* @4898816 cast */
    /* @4898820 load */
    /* @4898828 constant */
    /* @4898832 add */
    /* @4898836 constant */
    /* @4898840 cast */
    /* @4898844 constant */
    /* @4898848 cast */
    /* @4898852 call */
    GM_SITE(vm, 591, 4898852);
    v143 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v144 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(110));
    /* @4898860 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(122), VAL(0), v143, v144));
    L_4898864: ;
    /* @4898864 load */
    /* @4898872 constant */
    /* @4898876 cmp */
    /* @4898880 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4899108;
    /* @4898884 constant */
    /* @4898888 cast */
    /* @4898892 call */
    GM_SITE(vm, 591, 4898892);
    /* @4898900 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4898904 constant */
    /* @4898912 cast */
    /* @4898916 call */
    GM_SITE(vm, 591, 4898916);
    /* @4898924 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4898928 string */
    /* @4898936 cast */
    /* @4898940 constant */
    /* @4898944 load */
    /* @4898952 cast */
    /* @4898956 load */
    /* @4898964 constant */
    /* @4898968 add */
    /* @4898972 constant */
    /* @4898976 load */
    /* @4898984 cast */
    /* @4898988 load */
    /* @4898996 constant */
    /* @4899000 add */
    /* @4899004 call */
    GM_SITE(vm, 591, 4899004);
    v145 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v146 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4899012 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v145, v146, STR_REF(1074)));
    /* @4899016 constant */
    /* @4899020 load */
    /* @4899028 cast */
    /* @4899032 load */
    /* @4899040 constant */
    /* @4899044 add */
    /* @4899048 constant */
    /* @4899052 load */
    /* @4899060 cast */
    /* @4899064 load */
    /* @4899072 constant */
    /* @4899076 add */
    /* @4899080 constant */
    /* @4899084 cast */
    /* @4899088 constant */
    /* @4899092 cast */
    /* @4899096 call */
    GM_SITE(vm, 591, 4899096);
    v147 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v148 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(110));
    /* @4899104 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(122), VAL(0), v147, v148));
    L_4899108: ;
    /* @4899108 load */
    /* @4899116 constant */
    /* @4899120 cmp */
    /* @4899124 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4899352;
    /* @4899128 constant */
    /* @4899132 cast */
    /* @4899136 call */
    GM_SITE(vm, 591, 4899136);
    /* @4899144 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4899148 constant */
    /* @4899156 cast */
    /* @4899160 call */
    GM_SITE(vm, 591, 4899160);
    /* @4899168 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4899172 string */
    /* @4899180 cast */
    /* @4899184 constant */
    /* @4899188 load */
    /* @4899196 cast */
    /* @4899200 load */
    /* @4899208 constant */
    /* @4899212 add */
    /* @4899216 constant */
    /* @4899220 load */
    /* @4899228 cast */
    /* @4899232 load */
    /* @4899240 constant */
    /* @4899244 add */
    /* @4899248 call */
    GM_SITE(vm, 591, 4899248);
    v149 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v150 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4899256 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v149, v150, STR_REF(1074)));
    /* @4899260 constant */
    /* @4899264 load */
    /* @4899272 cast */
    /* @4899276 load */
    /* @4899284 constant */
    /* @4899288 add */
    /* @4899292 constant */
    /* @4899296 load */
    /* @4899304 cast */
    /* @4899308 load */
    /* @4899316 constant */
    /* @4899320 add */
    /* @4899324 constant */
    /* @4899328 cast */
    /* @4899332 constant */
    /* @4899336 cast */
    /* @4899340 call */
    GM_SITE(vm, 591, 4899340);
    v151 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v152 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4899348 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(122), VAL(0), v151, v152));
    L_4899352: ;
    /* @4899352 load */
    /* @4899360 constant */
    /* @4899364 cmp */
    /* @4899368 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4899596;
    /* @4899372 constant */
    /* @4899376 cast */
    /* @4899380 call */
    GM_SITE(vm, 591, 4899380);
    /* @4899388 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4899392 constant */
    /* @4899400 cast */
    /* @4899404 call */
    GM_SITE(vm, 591, 4899404);
    /* @4899412 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4899416 string */
    /* @4899424 cast */
    /* @4899428 constant */
    /* @4899432 load */
    /* @4899440 cast */
    /* @4899444 load */
    /* @4899452 constant */
    /* @4899456 add */
    /* @4899460 constant */
    /* @4899464 load */
    /* @4899472 cast */
    /* @4899476 load */
    /* @4899484 constant */
    /* @4899488 add */
    /* @4899492 call */
    GM_SITE(vm, 591, 4899492);
    v153 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v154 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4899500 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v153, v154, STR_REF(1074)));
    /* @4899504 constant */
    /* @4899508 load */
    /* @4899516 cast */
    /* @4899520 load */
    /* @4899528 constant */
    /* @4899532 add */
    /* @4899536 constant */
    /* @4899540 load */
    /* @4899548 cast */
    /* @4899552 load */
    /* @4899560 constant */
    /* @4899564 add */
    /* @4899568 constant */
    /* @4899572 cast */
    /* @4899576 constant */
    /* @4899580 cast */
    /* @4899584 call */
    GM_SITE(vm, 591, 4899584);
    v155 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v156 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4899592 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(122), VAL(0), v155, v156));
    L_4899596: ;
    /* @4899596 load */
    /* @4899604 constant */
    /* @4899608 cmp */
    /* @4899612 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4899648;
    /* @4899616 constant */
    /* @4899620 cast */
    /* @4899624 constant */
    /* @4899628 cast */
    /* @4899632 call */
    GM_SITE(vm, 591, 4899632);
    /* @4899640 cast */
    /* @4899644 b */
    v157 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, VAL(0), VAL(1)));
    p4899652_0 = v157;
    goto L_4899652;
    L_4899648: ;
    /* @4899648 constant */
    p4899652_0 = VAL(0);
    L_4899652: ;
    /* @4899652 bf */
    if (!TRUTH(p4899652_0)) goto L_4899668;
    /* @4899656 call */
    GM_SITE(vm, 591, 4899656);
    /* @4899664 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4899668: ;
    return;
}
