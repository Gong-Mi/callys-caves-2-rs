/* generated from CODE 641 (gml_Object_obj_lloydtutorial12_Draw_0), source start 4958264, end 4970424. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0641(GmVM* vm) {
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
    Val p4970408_0;
    Val v181;
    /* @4958264 constant */
    /* @4958268 load */
    /* @4958276 cast */
    /* @4958280 load */
    /* @4958288 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4958296 constant */
    /* @4958300 load */
    /* @4958308 cast */
    /* @4958312 load */
    /* @4958320 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4958328 load */
    /* @4958336 constant */
    /* @4958340 cmp */
    /* @4958344 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4958872;
    /* @4958348 constant */
    /* @4958352 cast */
    /* @4958356 constant */
    /* @4958360 cast */
    /* @4958364 constant */
    /* @4958368 cast */
    /* @4958372 constant */
    /* @4958384 cast */
    /* @4958388 constant */
    /* @4958400 cast */
    /* @4958404 constant */
    /* @4958408 constant */
    /* @4958412 load */
    /* @4958420 constant */
    /* @4958424 constant */
    /* @4958428 load */
    /* @4958436 constant */
    /* @4958440 sub */
    /* @4958444 constant */
    /* @4958448 cast */
    /* @4958452 constant */
    /* @4958456 cast */
    /* @4958460 call */
    GM_SITE(vm, 641, 4958460);
    /* @4958468 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(0.96), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4958472 constant */
    /* @4958476 cast */
    /* @4958480 constant */
    /* @4958484 cast */
    /* @4958488 constant */
    /* @4958492 cast */
    /* @4958496 constant */
    /* @4958500 cast */
    /* @4958504 constant */
    /* @4958508 cast */
    /* @4958512 constant */
    /* @4958516 load */
    /* @4958524 cast */
    /* @4958528 load */
    /* @4958536 constant */
    /* @4958540 add */
    /* @4958544 constant */
    /* @4958548 load */
    /* @4958556 cast */
    /* @4958560 load */
    /* @4958568 constant */
    /* @4958572 add */
    /* @4958576 constant */
    /* @4958580 cast */
    /* @4958584 constant */
    /* @4958588 cast */
    /* @4958592 call */
    GM_SITE(vm, 641, 4958592);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4958600 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v1, v2, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4958604 constant */
    /* @4958608 cast */
    /* @4958612 constant */
    /* @4958616 cast */
    /* @4958620 constant */
    /* @4958624 cast */
    /* @4958628 constant */
    /* @4958632 cast */
    /* @4958636 constant */
    /* @4958640 cast */
    /* @4958644 constant */
    /* @4958648 load */
    /* @4958656 cast */
    /* @4958660 load */
    /* @4958668 constant */
    /* @4958672 add */
    /* @4958676 constant */
    /* @4958680 load */
    /* @4958688 cast */
    /* @4958692 load */
    /* @4958700 constant */
    /* @4958704 add */
    /* @4958708 constant */
    /* @4958712 cast */
    /* @4958716 constant */
    /* @4958720 cast */
    /* @4958724 call */
    GM_SITE(vm, 641, 4958724);
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4958732 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v3, v4, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4958736 load */
    /* @4958744 constant */
    /* @4958748 cmp */
    /* @4958752 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4958872;
    /* @4958756 constant */
    /* @4958760 cast */
    /* @4958764 call */
    GM_SITE(vm, 641, 4958764);
    /* @4958772 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4958776 constant */
    /* @4958784 cast */
    /* @4958788 call */
    GM_SITE(vm, 641, 4958788);
    /* @4958796 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4958800 string */
    /* @4958808 cast */
    /* @4958812 constant */
    /* @4958816 constant */
    /* @4958820 load */
    /* @4958828 constant */
    /* @4958832 add */
    /* @4958836 constant */
    /* @4958840 constant */
    /* @4958844 load */
    /* @4958852 constant */
    /* @4958856 add */
    /* @4958860 call */
    GM_SITE(vm, 641, 4958860);
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(150));
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(200));
    /* @4958868 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v5, v6, STR_REF(743)));
    L_4958872: ;
    /* @4958872 load */
    /* @4958880 constant */
    /* @4958884 cmp */
    /* @4958888 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4959416;
    /* @4958892 constant */
    /* @4958896 cast */
    /* @4958900 constant */
    /* @4958904 cast */
    /* @4958908 constant */
    /* @4958912 cast */
    /* @4958916 constant */
    /* @4958928 cast */
    /* @4958932 constant */
    /* @4958944 cast */
    /* @4958948 constant */
    /* @4958952 constant */
    /* @4958956 load */
    /* @4958964 constant */
    /* @4958968 constant */
    /* @4958972 load */
    /* @4958980 constant */
    /* @4958984 sub */
    /* @4958988 constant */
    /* @4958992 cast */
    /* @4958996 constant */
    /* @4959000 cast */
    /* @4959004 call */
    GM_SITE(vm, 641, 4959004);
    /* @4959012 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(0.82), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4959016 constant */
    /* @4959020 cast */
    /* @4959024 constant */
    /* @4959028 cast */
    /* @4959032 constant */
    /* @4959036 cast */
    /* @4959040 constant */
    /* @4959044 cast */
    /* @4959048 constant */
    /* @4959052 cast */
    /* @4959056 constant */
    /* @4959060 load */
    /* @4959068 cast */
    /* @4959072 load */
    /* @4959080 constant */
    /* @4959084 add */
    /* @4959088 constant */
    /* @4959092 load */
    /* @4959100 cast */
    /* @4959104 load */
    /* @4959112 constant */
    /* @4959116 add */
    /* @4959120 constant */
    /* @4959124 cast */
    /* @4959128 constant */
    /* @4959132 cast */
    /* @4959136 call */
    GM_SITE(vm, 641, 4959136);
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4959144 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v7, v8, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4959148 constant */
    /* @4959152 cast */
    /* @4959156 constant */
    /* @4959160 cast */
    /* @4959164 constant */
    /* @4959168 cast */
    /* @4959172 constant */
    /* @4959176 cast */
    /* @4959180 constant */
    /* @4959184 cast */
    /* @4959188 constant */
    /* @4959192 load */
    /* @4959200 cast */
    /* @4959204 load */
    /* @4959212 constant */
    /* @4959216 add */
    /* @4959220 constant */
    /* @4959224 load */
    /* @4959232 cast */
    /* @4959236 load */
    /* @4959244 constant */
    /* @4959248 add */
    /* @4959252 constant */
    /* @4959256 cast */
    /* @4959260 constant */
    /* @4959264 cast */
    /* @4959268 call */
    GM_SITE(vm, 641, 4959268);
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(320));
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4959276 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v9, v10, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4959280 load */
    /* @4959288 constant */
    /* @4959292 cmp */
    /* @4959296 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4959416;
    /* @4959300 constant */
    /* @4959304 cast */
    /* @4959308 call */
    GM_SITE(vm, 641, 4959308);
    /* @4959316 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4959320 constant */
    /* @4959328 cast */
    /* @4959332 call */
    GM_SITE(vm, 641, 4959332);
    /* @4959340 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4959344 string */
    /* @4959352 cast */
    /* @4959356 constant */
    /* @4959360 constant */
    /* @4959364 load */
    /* @4959372 constant */
    /* @4959376 add */
    /* @4959380 constant */
    /* @4959384 constant */
    /* @4959388 load */
    /* @4959396 constant */
    /* @4959400 add */
    /* @4959404 call */
    GM_SITE(vm, 641, 4959404);
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(110));
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4959412 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v11, v12, STR_REF(743)));
    L_4959416: ;
    /* @4959416 load */
    /* @4959424 constant */
    /* @4959428 cmp */
    /* @4959432 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4959960;
    /* @4959436 constant */
    /* @4959440 cast */
    /* @4959444 constant */
    /* @4959448 cast */
    /* @4959452 constant */
    /* @4959456 cast */
    /* @4959460 constant */
    /* @4959472 cast */
    /* @4959476 constant */
    /* @4959488 cast */
    /* @4959492 constant */
    /* @4959496 constant */
    /* @4959500 load */
    /* @4959508 constant */
    /* @4959512 constant */
    /* @4959516 load */
    /* @4959524 constant */
    /* @4959528 sub */
    /* @4959532 constant */
    /* @4959536 cast */
    /* @4959540 constant */
    /* @4959544 cast */
    /* @4959548 call */
    GM_SITE(vm, 641, 4959548);
    /* @4959556 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4959560 constant */
    /* @4959564 cast */
    /* @4959568 constant */
    /* @4959572 cast */
    /* @4959576 constant */
    /* @4959580 cast */
    /* @4959584 constant */
    /* @4959588 cast */
    /* @4959592 constant */
    /* @4959596 cast */
    /* @4959600 constant */
    /* @4959604 load */
    /* @4959612 cast */
    /* @4959616 load */
    /* @4959624 constant */
    /* @4959628 add */
    /* @4959632 constant */
    /* @4959636 load */
    /* @4959644 cast */
    /* @4959648 load */
    /* @4959656 constant */
    /* @4959660 add */
    /* @4959664 constant */
    /* @4959668 cast */
    /* @4959672 constant */
    /* @4959676 cast */
    /* @4959680 call */
    GM_SITE(vm, 641, 4959680);
    v13 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4959688 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v13, v14, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4959692 constant */
    /* @4959696 cast */
    /* @4959700 constant */
    /* @4959704 cast */
    /* @4959708 constant */
    /* @4959712 cast */
    /* @4959716 constant */
    /* @4959720 cast */
    /* @4959724 constant */
    /* @4959728 cast */
    /* @4959732 constant */
    /* @4959736 load */
    /* @4959744 cast */
    /* @4959748 load */
    /* @4959756 constant */
    /* @4959760 add */
    /* @4959764 constant */
    /* @4959768 load */
    /* @4959776 cast */
    /* @4959780 load */
    /* @4959788 constant */
    /* @4959792 add */
    /* @4959796 constant */
    /* @4959800 cast */
    /* @4959804 constant */
    /* @4959808 cast */
    /* @4959812 call */
    GM_SITE(vm, 641, 4959812);
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4959820 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v15, v16, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4959824 load */
    /* @4959832 constant */
    /* @4959836 cmp */
    /* @4959840 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4959960;
    /* @4959844 constant */
    /* @4959848 cast */
    /* @4959852 call */
    GM_SITE(vm, 641, 4959852);
    /* @4959860 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4959864 constant */
    /* @4959872 cast */
    /* @4959876 call */
    GM_SITE(vm, 641, 4959876);
    /* @4959884 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4959888 string */
    /* @4959896 cast */
    /* @4959900 constant */
    /* @4959904 constant */
    /* @4959908 load */
    /* @4959916 constant */
    /* @4959920 add */
    /* @4959924 constant */
    /* @4959928 constant */
    /* @4959932 load */
    /* @4959940 constant */
    /* @4959944 add */
    /* @4959948 call */
    GM_SITE(vm, 641, 4959948);
    v17 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(180));
    v18 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(300));
    /* @4959956 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v17, v18, STR_REF(743)));
    L_4959960: ;
    /* @4959960 load */
    /* @4959968 constant */
    /* @4959972 cmp */
    /* @4959976 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4960504;
    /* @4959980 constant */
    /* @4959984 cast */
    /* @4959988 constant */
    /* @4959992 cast */
    /* @4959996 constant */
    /* @4960000 cast */
    /* @4960004 constant */
    /* @4960016 cast */
    /* @4960020 constant */
    /* @4960032 cast */
    /* @4960036 constant */
    /* @4960040 constant */
    /* @4960044 load */
    /* @4960052 constant */
    /* @4960056 constant */
    /* @4960060 load */
    /* @4960068 constant */
    /* @4960072 sub */
    /* @4960076 constant */
    /* @4960080 cast */
    /* @4960084 constant */
    /* @4960088 cast */
    /* @4960092 call */
    GM_SITE(vm, 641, 4960092);
    /* @4960100 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4960104 constant */
    /* @4960108 cast */
    /* @4960112 constant */
    /* @4960116 cast */
    /* @4960120 constant */
    /* @4960124 cast */
    /* @4960128 constant */
    /* @4960132 cast */
    /* @4960136 constant */
    /* @4960140 cast */
    /* @4960144 constant */
    /* @4960148 load */
    /* @4960156 cast */
    /* @4960160 load */
    /* @4960168 constant */
    /* @4960172 add */
    /* @4960176 constant */
    /* @4960180 load */
    /* @4960188 cast */
    /* @4960192 load */
    /* @4960200 constant */
    /* @4960204 add */
    /* @4960208 constant */
    /* @4960212 cast */
    /* @4960216 constant */
    /* @4960220 cast */
    /* @4960224 call */
    GM_SITE(vm, 641, 4960224);
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4960232 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v19, v20, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4960236 constant */
    /* @4960240 cast */
    /* @4960244 constant */
    /* @4960248 cast */
    /* @4960252 constant */
    /* @4960256 cast */
    /* @4960260 constant */
    /* @4960264 cast */
    /* @4960268 constant */
    /* @4960272 cast */
    /* @4960276 constant */
    /* @4960280 load */
    /* @4960288 cast */
    /* @4960292 load */
    /* @4960300 constant */
    /* @4960304 add */
    /* @4960308 constant */
    /* @4960312 load */
    /* @4960320 cast */
    /* @4960324 load */
    /* @4960332 constant */
    /* @4960336 add */
    /* @4960340 constant */
    /* @4960344 cast */
    /* @4960348 constant */
    /* @4960352 cast */
    /* @4960356 call */
    GM_SITE(vm, 641, 4960356);
    v21 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4960364 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v21, v22, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4960368 load */
    /* @4960376 constant */
    /* @4960380 cmp */
    /* @4960384 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4960504;
    /* @4960388 constant */
    /* @4960392 cast */
    /* @4960396 call */
    GM_SITE(vm, 641, 4960396);
    /* @4960404 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4960408 constant */
    /* @4960416 cast */
    /* @4960420 call */
    GM_SITE(vm, 641, 4960420);
    /* @4960428 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4960432 string */
    /* @4960440 cast */
    /* @4960444 constant */
    /* @4960448 constant */
    /* @4960452 load */
    /* @4960460 constant */
    /* @4960464 add */
    /* @4960468 constant */
    /* @4960472 constant */
    /* @4960476 load */
    /* @4960484 constant */
    /* @4960488 add */
    /* @4960492 call */
    GM_SITE(vm, 641, 4960492);
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(180));
    v24 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(300));
    /* @4960500 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v23, v24, STR_REF(743)));
    L_4960504: ;
    /* @4960504 load */
    /* @4960512 constant */
    /* @4960516 cmp */
    /* @4960520 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4961048;
    /* @4960524 constant */
    /* @4960528 cast */
    /* @4960532 constant */
    /* @4960536 cast */
    /* @4960540 constant */
    /* @4960544 cast */
    /* @4960548 constant */
    /* @4960560 cast */
    /* @4960564 constant */
    /* @4960576 cast */
    /* @4960580 constant */
    /* @4960584 constant */
    /* @4960588 load */
    /* @4960596 constant */
    /* @4960600 constant */
    /* @4960604 load */
    /* @4960612 constant */
    /* @4960616 sub */
    /* @4960620 constant */
    /* @4960624 cast */
    /* @4960628 constant */
    /* @4960632 cast */
    /* @4960636 call */
    GM_SITE(vm, 641, 4960636);
    /* @4960644 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(0.97), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4960648 constant */
    /* @4960652 cast */
    /* @4960656 constant */
    /* @4960660 cast */
    /* @4960664 constant */
    /* @4960668 cast */
    /* @4960672 constant */
    /* @4960676 cast */
    /* @4960680 constant */
    /* @4960684 cast */
    /* @4960688 constant */
    /* @4960692 load */
    /* @4960700 cast */
    /* @4960704 load */
    /* @4960712 constant */
    /* @4960716 add */
    /* @4960720 constant */
    /* @4960724 load */
    /* @4960732 cast */
    /* @4960736 load */
    /* @4960744 constant */
    /* @4960748 add */
    /* @4960752 constant */
    /* @4960756 cast */
    /* @4960760 constant */
    /* @4960764 cast */
    /* @4960768 call */
    GM_SITE(vm, 641, 4960768);
    v25 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v26 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4960776 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v25, v26, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4960780 constant */
    /* @4960784 cast */
    /* @4960788 constant */
    /* @4960792 cast */
    /* @4960796 constant */
    /* @4960800 cast */
    /* @4960804 constant */
    /* @4960808 cast */
    /* @4960812 constant */
    /* @4960816 cast */
    /* @4960820 constant */
    /* @4960824 load */
    /* @4960832 cast */
    /* @4960836 load */
    /* @4960844 constant */
    /* @4960848 add */
    /* @4960852 constant */
    /* @4960856 load */
    /* @4960864 cast */
    /* @4960868 load */
    /* @4960876 constant */
    /* @4960880 add */
    /* @4960884 constant */
    /* @4960888 cast */
    /* @4960892 constant */
    /* @4960896 cast */
    /* @4960900 call */
    GM_SITE(vm, 641, 4960900);
    v27 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v28 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4960908 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v27, v28, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4960912 load */
    /* @4960920 constant */
    /* @4960924 cmp */
    /* @4960928 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4961048;
    /* @4960932 constant */
    /* @4960936 cast */
    /* @4960940 call */
    GM_SITE(vm, 641, 4960940);
    /* @4960948 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4960952 constant */
    /* @4960960 cast */
    /* @4960964 call */
    GM_SITE(vm, 641, 4960964);
    /* @4960972 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4960976 string */
    /* @4960984 cast */
    /* @4960988 constant */
    /* @4960992 constant */
    /* @4960996 load */
    /* @4961004 constant */
    /* @4961008 add */
    /* @4961012 constant */
    /* @4961016 constant */
    /* @4961020 load */
    /* @4961028 constant */
    /* @4961032 add */
    /* @4961036 call */
    GM_SITE(vm, 641, 4961036);
    v29 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(150));
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(200));
    /* @4961044 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v29, v30, STR_REF(743)));
    L_4961048: ;
    /* @4961048 load */
    /* @4961056 constant */
    /* @4961060 cmp */
    /* @4961064 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4961592;
    /* @4961068 constant */
    /* @4961072 cast */
    /* @4961076 constant */
    /* @4961080 cast */
    /* @4961084 constant */
    /* @4961088 cast */
    /* @4961092 constant */
    /* @4961104 cast */
    /* @4961108 constant */
    /* @4961120 cast */
    /* @4961124 constant */
    /* @4961128 constant */
    /* @4961132 load */
    /* @4961140 constant */
    /* @4961144 constant */
    /* @4961148 load */
    /* @4961156 constant */
    /* @4961160 sub */
    /* @4961164 constant */
    /* @4961168 cast */
    /* @4961172 constant */
    /* @4961176 cast */
    /* @4961180 call */
    GM_SITE(vm, 641, 4961180);
    /* @4961188 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(1.06), VAL(0.86), VAL(0), VAL(-1), VAL(1)));
    /* @4961192 constant */
    /* @4961196 cast */
    /* @4961200 constant */
    /* @4961204 cast */
    /* @4961208 constant */
    /* @4961212 cast */
    /* @4961216 constant */
    /* @4961220 cast */
    /* @4961224 constant */
    /* @4961228 cast */
    /* @4961232 constant */
    /* @4961236 load */
    /* @4961244 cast */
    /* @4961248 load */
    /* @4961256 constant */
    /* @4961260 add */
    /* @4961264 constant */
    /* @4961268 load */
    /* @4961276 cast */
    /* @4961280 load */
    /* @4961288 constant */
    /* @4961292 add */
    /* @4961296 constant */
    /* @4961300 cast */
    /* @4961304 constant */
    /* @4961308 cast */
    /* @4961312 call */
    GM_SITE(vm, 641, 4961312);
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v32 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4961320 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v31, v32, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4961324 constant */
    /* @4961328 cast */
    /* @4961332 constant */
    /* @4961336 cast */
    /* @4961340 constant */
    /* @4961344 cast */
    /* @4961348 constant */
    /* @4961352 cast */
    /* @4961356 constant */
    /* @4961360 cast */
    /* @4961364 constant */
    /* @4961368 load */
    /* @4961376 cast */
    /* @4961380 load */
    /* @4961388 constant */
    /* @4961392 add */
    /* @4961396 constant */
    /* @4961400 load */
    /* @4961408 cast */
    /* @4961412 load */
    /* @4961420 constant */
    /* @4961424 add */
    /* @4961428 constant */
    /* @4961432 cast */
    /* @4961436 constant */
    /* @4961440 cast */
    /* @4961444 call */
    GM_SITE(vm, 641, 4961444);
    v33 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(390));
    v34 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4961452 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v33, v34, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4961456 load */
    /* @4961464 constant */
    /* @4961468 cmp */
    /* @4961472 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4961592;
    /* @4961476 constant */
    /* @4961480 cast */
    /* @4961484 call */
    GM_SITE(vm, 641, 4961484);
    /* @4961492 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4961496 constant */
    /* @4961504 cast */
    /* @4961508 call */
    GM_SITE(vm, 641, 4961508);
    /* @4961516 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4961520 string */
    /* @4961528 cast */
    /* @4961532 constant */
    /* @4961536 constant */
    /* @4961540 load */
    /* @4961548 constant */
    /* @4961552 add */
    /* @4961556 constant */
    /* @4961560 constant */
    /* @4961564 load */
    /* @4961572 constant */
    /* @4961576 add */
    /* @4961580 call */
    GM_SITE(vm, 641, 4961580);
    v35 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(160));
    v36 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(200));
    /* @4961588 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v35, v36, STR_REF(743)));
    L_4961592: ;
    /* @4961592 load */
    /* @4961600 constant */
    /* @4961604 cmp */
    /* @4961608 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel1") == VAL(1)))) goto L_4963052;
    /* @4961612 load */
    /* @4961620 constant */
    /* @4961624 cmp */
    /* @4961628 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4961852;
    /* @4961632 constant */
    /* @4961636 cast */
    /* @4961640 call */
    GM_SITE(vm, 641, 4961640);
    /* @4961648 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4961652 constant */
    /* @4961660 cast */
    /* @4961664 call */
    GM_SITE(vm, 641, 4961664);
    /* @4961672 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4961676 string */
    /* @4961684 cast */
    /* @4961688 constant */
    /* @4961692 load */
    /* @4961700 cast */
    /* @4961704 load */
    /* @4961712 constant */
    /* @4961716 add */
    /* @4961720 constant */
    /* @4961724 load */
    /* @4961732 cast */
    /* @4961736 load */
    /* @4961744 constant */
    /* @4961748 add */
    /* @4961752 call */
    GM_SITE(vm, 641, 4961752);
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4961760 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v37, v38, STR_REF(1121)));
    /* @4961764 string */
    /* @4961772 cast */
    /* @4961776 constant */
    /* @4961780 load */
    /* @4961788 cast */
    /* @4961792 load */
    /* @4961800 constant */
    /* @4961804 add */
    /* @4961808 constant */
    /* @4961812 load */
    /* @4961820 cast */
    /* @4961824 load */
    /* @4961832 constant */
    /* @4961836 add */
    /* @4961840 call */
    GM_SITE(vm, 641, 4961840);
    v39 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v40 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4961848 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, v40, STR_REF(1122)));
    L_4961852: ;
    /* @4961852 load */
    /* @4961860 constant */
    /* @4961864 cmp */
    /* @4961868 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4962092;
    /* @4961872 constant */
    /* @4961876 cast */
    /* @4961880 call */
    GM_SITE(vm, 641, 4961880);
    /* @4961888 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4961892 constant */
    /* @4961900 cast */
    /* @4961904 call */
    GM_SITE(vm, 641, 4961904);
    /* @4961912 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4961916 string */
    /* @4961924 cast */
    /* @4961928 constant */
    /* @4961932 load */
    /* @4961940 cast */
    /* @4961944 load */
    /* @4961952 constant */
    /* @4961956 add */
    /* @4961960 constant */
    /* @4961964 load */
    /* @4961972 cast */
    /* @4961976 load */
    /* @4961984 constant */
    /* @4961988 add */
    /* @4961992 call */
    GM_SITE(vm, 641, 4961992);
    v41 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v42 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4962000 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v41, v42, STR_REF(1121)));
    /* @4962004 string */
    /* @4962012 cast */
    /* @4962016 constant */
    /* @4962020 load */
    /* @4962028 cast */
    /* @4962032 load */
    /* @4962040 constant */
    /* @4962044 add */
    /* @4962048 constant */
    /* @4962052 load */
    /* @4962060 cast */
    /* @4962064 load */
    /* @4962072 constant */
    /* @4962076 add */
    /* @4962080 call */
    GM_SITE(vm, 641, 4962080);
    v43 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v44 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4962088 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v43, v44, STR_REF(1122)));
    L_4962092: ;
    /* @4962092 load */
    /* @4962100 constant */
    /* @4962104 cmp */
    /* @4962108 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4962332;
    /* @4962112 constant */
    /* @4962116 cast */
    /* @4962120 call */
    GM_SITE(vm, 641, 4962120);
    /* @4962128 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4962132 constant */
    /* @4962140 cast */
    /* @4962144 call */
    GM_SITE(vm, 641, 4962144);
    /* @4962152 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4962156 string */
    /* @4962164 cast */
    /* @4962168 constant */
    /* @4962172 load */
    /* @4962180 cast */
    /* @4962184 load */
    /* @4962192 constant */
    /* @4962196 add */
    /* @4962200 constant */
    /* @4962204 load */
    /* @4962212 cast */
    /* @4962216 load */
    /* @4962224 constant */
    /* @4962228 add */
    /* @4962232 call */
    GM_SITE(vm, 641, 4962232);
    v45 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v46 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4962240 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v45, v46, STR_REF(1121)));
    /* @4962244 string */
    /* @4962252 cast */
    /* @4962256 constant */
    /* @4962260 load */
    /* @4962268 cast */
    /* @4962272 load */
    /* @4962280 constant */
    /* @4962284 add */
    /* @4962288 constant */
    /* @4962292 load */
    /* @4962300 cast */
    /* @4962304 load */
    /* @4962312 constant */
    /* @4962316 add */
    /* @4962320 call */
    GM_SITE(vm, 641, 4962320);
    v47 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v48 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4962328 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v47, v48, STR_REF(1122)));
    L_4962332: ;
    /* @4962332 load */
    /* @4962340 constant */
    /* @4962344 cmp */
    /* @4962348 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4962572;
    /* @4962352 constant */
    /* @4962356 cast */
    /* @4962360 call */
    GM_SITE(vm, 641, 4962360);
    /* @4962368 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4962372 constant */
    /* @4962380 cast */
    /* @4962384 call */
    GM_SITE(vm, 641, 4962384);
    /* @4962392 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4962396 string */
    /* @4962404 cast */
    /* @4962408 constant */
    /* @4962412 load */
    /* @4962420 cast */
    /* @4962424 load */
    /* @4962432 constant */
    /* @4962436 add */
    /* @4962440 constant */
    /* @4962444 load */
    /* @4962452 cast */
    /* @4962456 load */
    /* @4962464 constant */
    /* @4962468 add */
    /* @4962472 call */
    GM_SITE(vm, 641, 4962472);
    v49 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v50 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4962480 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v49, v50, STR_REF(1121)));
    /* @4962484 string */
    /* @4962492 cast */
    /* @4962496 constant */
    /* @4962500 load */
    /* @4962508 cast */
    /* @4962512 load */
    /* @4962520 constant */
    /* @4962524 add */
    /* @4962528 constant */
    /* @4962532 load */
    /* @4962540 cast */
    /* @4962544 load */
    /* @4962552 constant */
    /* @4962556 add */
    /* @4962560 call */
    GM_SITE(vm, 641, 4962560);
    v51 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v52 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4962568 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v51, v52, STR_REF(1122)));
    L_4962572: ;
    /* @4962572 load */
    /* @4962580 constant */
    /* @4962584 cmp */
    /* @4962588 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4962812;
    /* @4962592 constant */
    /* @4962596 cast */
    /* @4962600 call */
    GM_SITE(vm, 641, 4962600);
    /* @4962608 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4962612 constant */
    /* @4962620 cast */
    /* @4962624 call */
    GM_SITE(vm, 641, 4962624);
    /* @4962632 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4962636 string */
    /* @4962644 cast */
    /* @4962648 constant */
    /* @4962652 load */
    /* @4962660 cast */
    /* @4962664 load */
    /* @4962672 constant */
    /* @4962676 add */
    /* @4962680 constant */
    /* @4962684 load */
    /* @4962692 cast */
    /* @4962696 load */
    /* @4962704 constant */
    /* @4962708 add */
    /* @4962712 call */
    GM_SITE(vm, 641, 4962712);
    v53 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v54 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4962720 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v53, v54, STR_REF(1121)));
    /* @4962724 string */
    /* @4962732 cast */
    /* @4962736 constant */
    /* @4962740 load */
    /* @4962748 cast */
    /* @4962752 load */
    /* @4962760 constant */
    /* @4962764 add */
    /* @4962768 constant */
    /* @4962772 load */
    /* @4962780 cast */
    /* @4962784 load */
    /* @4962792 constant */
    /* @4962796 add */
    /* @4962800 call */
    GM_SITE(vm, 641, 4962800);
    v55 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v56 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4962808 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v55, v56, STR_REF(1122)));
    L_4962812: ;
    /* @4962812 load */
    /* @4962820 constant */
    /* @4962824 cmp */
    /* @4962828 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4963052;
    /* @4962832 constant */
    /* @4962836 cast */
    /* @4962840 call */
    GM_SITE(vm, 641, 4962840);
    /* @4962848 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4962852 constant */
    /* @4962860 cast */
    /* @4962864 call */
    GM_SITE(vm, 641, 4962864);
    /* @4962872 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4962876 string */
    /* @4962884 cast */
    /* @4962888 constant */
    /* @4962892 load */
    /* @4962900 cast */
    /* @4962904 load */
    /* @4962912 constant */
    /* @4962916 add */
    /* @4962920 constant */
    /* @4962924 load */
    /* @4962932 cast */
    /* @4962936 load */
    /* @4962944 constant */
    /* @4962948 add */
    /* @4962952 call */
    GM_SITE(vm, 641, 4962952);
    v57 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v58 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4962960 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v57, v58, STR_REF(1121)));
    /* @4962964 string */
    /* @4962972 cast */
    /* @4962976 constant */
    /* @4962980 load */
    /* @4962988 cast */
    /* @4962992 load */
    /* @4963000 constant */
    /* @4963004 add */
    /* @4963008 constant */
    /* @4963012 load */
    /* @4963020 cast */
    /* @4963024 load */
    /* @4963032 constant */
    /* @4963036 add */
    /* @4963040 call */
    GM_SITE(vm, 641, 4963040);
    v59 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v60 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4963048 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v59, v60, STR_REF(1122)));
    L_4963052: ;
    /* @4963052 load */
    /* @4963060 constant */
    /* @4963064 cmp */
    /* @4963068 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel2") == VAL(1)))) goto L_4964512;
    /* @4963072 load */
    /* @4963080 constant */
    /* @4963084 cmp */
    /* @4963088 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4963312;
    /* @4963092 constant */
    /* @4963096 cast */
    /* @4963100 call */
    GM_SITE(vm, 641, 4963100);
    /* @4963108 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4963112 constant */
    /* @4963120 cast */
    /* @4963124 call */
    GM_SITE(vm, 641, 4963124);
    /* @4963132 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4963136 string */
    /* @4963144 cast */
    /* @4963148 constant */
    /* @4963152 load */
    /* @4963160 cast */
    /* @4963164 load */
    /* @4963172 constant */
    /* @4963176 add */
    /* @4963180 constant */
    /* @4963184 load */
    /* @4963192 cast */
    /* @4963196 load */
    /* @4963204 constant */
    /* @4963208 add */
    /* @4963212 call */
    GM_SITE(vm, 641, 4963212);
    v61 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    v62 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4963220 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v61, v62, STR_REF(1123)));
    /* @4963224 string */
    /* @4963232 cast */
    /* @4963236 constant */
    /* @4963240 load */
    /* @4963248 cast */
    /* @4963252 load */
    /* @4963260 constant */
    /* @4963264 add */
    /* @4963268 constant */
    /* @4963272 load */
    /* @4963280 cast */
    /* @4963284 load */
    /* @4963292 constant */
    /* @4963296 add */
    /* @4963300 call */
    GM_SITE(vm, 641, 4963300);
    v63 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    v64 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4963308 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v63, v64, STR_REF(1124)));
    L_4963312: ;
    /* @4963312 load */
    /* @4963320 constant */
    /* @4963324 cmp */
    /* @4963328 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4963552;
    /* @4963332 constant */
    /* @4963336 cast */
    /* @4963340 call */
    GM_SITE(vm, 641, 4963340);
    /* @4963348 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4963352 constant */
    /* @4963360 cast */
    /* @4963364 call */
    GM_SITE(vm, 641, 4963364);
    /* @4963372 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4963376 string */
    /* @4963384 cast */
    /* @4963388 constant */
    /* @4963392 load */
    /* @4963400 cast */
    /* @4963404 load */
    /* @4963412 constant */
    /* @4963416 add */
    /* @4963420 constant */
    /* @4963424 load */
    /* @4963432 cast */
    /* @4963436 load */
    /* @4963444 constant */
    /* @4963448 add */
    /* @4963452 call */
    GM_SITE(vm, 641, 4963452);
    v65 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v66 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(120));
    /* @4963460 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v65, v66, STR_REF(1123)));
    /* @4963464 string */
    /* @4963472 cast */
    /* @4963476 constant */
    /* @4963480 load */
    /* @4963488 cast */
    /* @4963492 load */
    /* @4963500 constant */
    /* @4963504 add */
    /* @4963508 constant */
    /* @4963512 load */
    /* @4963520 cast */
    /* @4963524 load */
    /* @4963532 constant */
    /* @4963536 add */
    /* @4963540 call */
    GM_SITE(vm, 641, 4963540);
    v67 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v68 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(140));
    /* @4963548 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v67, v68, STR_REF(1124)));
    L_4963552: ;
    /* @4963552 load */
    /* @4963560 constant */
    /* @4963564 cmp */
    /* @4963568 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4963792;
    /* @4963572 constant */
    /* @4963576 cast */
    /* @4963580 call */
    GM_SITE(vm, 641, 4963580);
    /* @4963588 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4963592 constant */
    /* @4963600 cast */
    /* @4963604 call */
    GM_SITE(vm, 641, 4963604);
    /* @4963612 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4963616 string */
    /* @4963624 cast */
    /* @4963628 constant */
    /* @4963632 load */
    /* @4963640 cast */
    /* @4963644 load */
    /* @4963652 constant */
    /* @4963656 add */
    /* @4963660 constant */
    /* @4963664 load */
    /* @4963672 cast */
    /* @4963676 load */
    /* @4963684 constant */
    /* @4963688 add */
    /* @4963692 call */
    GM_SITE(vm, 641, 4963692);
    v69 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v70 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4963700 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v69, v70, STR_REF(1123)));
    /* @4963704 string */
    /* @4963712 cast */
    /* @4963716 constant */
    /* @4963720 load */
    /* @4963728 cast */
    /* @4963732 load */
    /* @4963740 constant */
    /* @4963744 add */
    /* @4963748 constant */
    /* @4963752 load */
    /* @4963760 cast */
    /* @4963764 load */
    /* @4963772 constant */
    /* @4963776 add */
    /* @4963780 call */
    GM_SITE(vm, 641, 4963780);
    v71 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v72 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4963788 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v71, v72, STR_REF(1124)));
    L_4963792: ;
    /* @4963792 load */
    /* @4963800 constant */
    /* @4963804 cmp */
    /* @4963808 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4964032;
    /* @4963812 constant */
    /* @4963816 cast */
    /* @4963820 call */
    GM_SITE(vm, 641, 4963820);
    /* @4963828 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4963832 constant */
    /* @4963840 cast */
    /* @4963844 call */
    GM_SITE(vm, 641, 4963844);
    /* @4963852 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4963856 string */
    /* @4963864 cast */
    /* @4963868 constant */
    /* @4963872 load */
    /* @4963880 cast */
    /* @4963884 load */
    /* @4963892 constant */
    /* @4963896 add */
    /* @4963900 constant */
    /* @4963904 load */
    /* @4963912 cast */
    /* @4963916 load */
    /* @4963924 constant */
    /* @4963928 add */
    /* @4963932 call */
    GM_SITE(vm, 641, 4963932);
    v73 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v74 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4963940 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v73, v74, STR_REF(1123)));
    /* @4963944 string */
    /* @4963952 cast */
    /* @4963956 constant */
    /* @4963960 load */
    /* @4963968 cast */
    /* @4963972 load */
    /* @4963980 constant */
    /* @4963984 add */
    /* @4963988 constant */
    /* @4963992 load */
    /* @4964000 cast */
    /* @4964004 load */
    /* @4964012 constant */
    /* @4964016 add */
    /* @4964020 call */
    GM_SITE(vm, 641, 4964020);
    v75 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(200));
    v76 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4964028 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v75, v76, STR_REF(1124)));
    L_4964032: ;
    /* @4964032 load */
    /* @4964040 constant */
    /* @4964044 cmp */
    /* @4964048 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4964272;
    /* @4964052 constant */
    /* @4964056 cast */
    /* @4964060 call */
    GM_SITE(vm, 641, 4964060);
    /* @4964068 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4964072 constant */
    /* @4964080 cast */
    /* @4964084 call */
    GM_SITE(vm, 641, 4964084);
    /* @4964092 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4964096 string */
    /* @4964104 cast */
    /* @4964108 constant */
    /* @4964112 load */
    /* @4964120 cast */
    /* @4964124 load */
    /* @4964132 constant */
    /* @4964136 add */
    /* @4964140 constant */
    /* @4964144 load */
    /* @4964152 cast */
    /* @4964156 load */
    /* @4964164 constant */
    /* @4964168 add */
    /* @4964172 call */
    GM_SITE(vm, 641, 4964172);
    v77 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    v78 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4964180 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v77, v78, STR_REF(1123)));
    /* @4964184 string */
    /* @4964192 cast */
    /* @4964196 constant */
    /* @4964200 load */
    /* @4964208 cast */
    /* @4964212 load */
    /* @4964220 constant */
    /* @4964224 add */
    /* @4964228 constant */
    /* @4964232 load */
    /* @4964240 cast */
    /* @4964244 load */
    /* @4964252 constant */
    /* @4964256 add */
    /* @4964260 call */
    GM_SITE(vm, 641, 4964260);
    v79 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    v80 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4964268 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v79, v80, STR_REF(1124)));
    L_4964272: ;
    /* @4964272 load */
    /* @4964280 constant */
    /* @4964284 cmp */
    /* @4964288 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4964512;
    /* @4964292 constant */
    /* @4964296 cast */
    /* @4964300 call */
    GM_SITE(vm, 641, 4964300);
    /* @4964308 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4964312 constant */
    /* @4964320 cast */
    /* @4964324 call */
    GM_SITE(vm, 641, 4964324);
    /* @4964332 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4964336 string */
    /* @4964344 cast */
    /* @4964348 constant */
    /* @4964352 load */
    /* @4964360 cast */
    /* @4964364 load */
    /* @4964372 constant */
    /* @4964376 add */
    /* @4964380 constant */
    /* @4964384 load */
    /* @4964392 cast */
    /* @4964396 load */
    /* @4964404 constant */
    /* @4964408 add */
    /* @4964412 call */
    GM_SITE(vm, 641, 4964412);
    v81 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    v82 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(150));
    /* @4964420 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v81, v82, STR_REF(1123)));
    /* @4964424 string */
    /* @4964432 cast */
    /* @4964436 constant */
    /* @4964440 load */
    /* @4964448 cast */
    /* @4964452 load */
    /* @4964460 constant */
    /* @4964464 add */
    /* @4964468 constant */
    /* @4964472 load */
    /* @4964480 cast */
    /* @4964484 load */
    /* @4964492 constant */
    /* @4964496 add */
    /* @4964500 call */
    GM_SITE(vm, 641, 4964500);
    v83 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    v84 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(170));
    /* @4964508 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v83, v84, STR_REF(1124)));
    L_4964512: ;
    /* @4964512 load */
    /* @4964520 constant */
    /* @4964524 cmp */
    /* @4964528 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel3") == VAL(1)))) goto L_4965972;
    /* @4964532 load */
    /* @4964540 constant */
    /* @4964544 cmp */
    /* @4964548 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4964772;
    /* @4964552 constant */
    /* @4964556 cast */
    /* @4964560 call */
    GM_SITE(vm, 641, 4964560);
    /* @4964568 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4964572 constant */
    /* @4964580 cast */
    /* @4964584 call */
    GM_SITE(vm, 641, 4964584);
    /* @4964592 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4964596 string */
    /* @4964604 cast */
    /* @4964608 constant */
    /* @4964612 load */
    /* @4964620 cast */
    /* @4964624 load */
    /* @4964632 constant */
    /* @4964636 add */
    /* @4964640 constant */
    /* @4964644 load */
    /* @4964652 cast */
    /* @4964656 load */
    /* @4964664 constant */
    /* @4964668 add */
    /* @4964672 call */
    GM_SITE(vm, 641, 4964672);
    v85 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v86 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4964680 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v85, v86, STR_REF(1125)));
    /* @4964684 string */
    /* @4964692 cast */
    /* @4964696 constant */
    /* @4964700 load */
    /* @4964708 cast */
    /* @4964712 load */
    /* @4964720 constant */
    /* @4964724 add */
    /* @4964728 constant */
    /* @4964732 load */
    /* @4964740 cast */
    /* @4964744 load */
    /* @4964752 constant */
    /* @4964756 add */
    /* @4964760 call */
    GM_SITE(vm, 641, 4964760);
    v87 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v88 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4964768 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v87, v88, STR_REF(1126)));
    L_4964772: ;
    /* @4964772 load */
    /* @4964780 constant */
    /* @4964784 cmp */
    /* @4964788 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4965012;
    /* @4964792 constant */
    /* @4964796 cast */
    /* @4964800 call */
    GM_SITE(vm, 641, 4964800);
    /* @4964808 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4964812 constant */
    /* @4964820 cast */
    /* @4964824 call */
    GM_SITE(vm, 641, 4964824);
    /* @4964832 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4964836 string */
    /* @4964844 cast */
    /* @4964848 constant */
    /* @4964852 load */
    /* @4964860 cast */
    /* @4964864 load */
    /* @4964872 constant */
    /* @4964876 add */
    /* @4964880 constant */
    /* @4964884 load */
    /* @4964892 cast */
    /* @4964896 load */
    /* @4964904 constant */
    /* @4964908 add */
    /* @4964912 call */
    GM_SITE(vm, 641, 4964912);
    v89 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v90 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4964920 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v89, v90, STR_REF(1125)));
    /* @4964924 string */
    /* @4964932 cast */
    /* @4964936 constant */
    /* @4964940 load */
    /* @4964948 cast */
    /* @4964952 load */
    /* @4964960 constant */
    /* @4964964 add */
    /* @4964968 constant */
    /* @4964972 load */
    /* @4964980 cast */
    /* @4964984 load */
    /* @4964992 constant */
    /* @4964996 add */
    /* @4965000 call */
    GM_SITE(vm, 641, 4965000);
    v91 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v92 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4965008 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v91, v92, STR_REF(1126)));
    L_4965012: ;
    /* @4965012 load */
    /* @4965020 constant */
    /* @4965024 cmp */
    /* @4965028 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4965252;
    /* @4965032 constant */
    /* @4965036 cast */
    /* @4965040 call */
    GM_SITE(vm, 641, 4965040);
    /* @4965048 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4965052 constant */
    /* @4965060 cast */
    /* @4965064 call */
    GM_SITE(vm, 641, 4965064);
    /* @4965072 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4965076 string */
    /* @4965084 cast */
    /* @4965088 constant */
    /* @4965092 load */
    /* @4965100 cast */
    /* @4965104 load */
    /* @4965112 constant */
    /* @4965116 add */
    /* @4965120 constant */
    /* @4965124 load */
    /* @4965132 cast */
    /* @4965136 load */
    /* @4965144 constant */
    /* @4965148 add */
    /* @4965152 call */
    GM_SITE(vm, 641, 4965152);
    v93 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v94 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4965160 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v93, v94, STR_REF(1125)));
    /* @4965164 string */
    /* @4965172 cast */
    /* @4965176 constant */
    /* @4965180 load */
    /* @4965188 cast */
    /* @4965192 load */
    /* @4965200 constant */
    /* @4965204 add */
    /* @4965208 constant */
    /* @4965212 load */
    /* @4965220 cast */
    /* @4965224 load */
    /* @4965232 constant */
    /* @4965236 add */
    /* @4965240 call */
    GM_SITE(vm, 641, 4965240);
    v95 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v96 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4965248 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v95, v96, STR_REF(1126)));
    L_4965252: ;
    /* @4965252 load */
    /* @4965260 constant */
    /* @4965264 cmp */
    /* @4965268 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4965492;
    /* @4965272 constant */
    /* @4965276 cast */
    /* @4965280 call */
    GM_SITE(vm, 641, 4965280);
    /* @4965288 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4965292 constant */
    /* @4965300 cast */
    /* @4965304 call */
    GM_SITE(vm, 641, 4965304);
    /* @4965312 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4965316 string */
    /* @4965324 cast */
    /* @4965328 constant */
    /* @4965332 load */
    /* @4965340 cast */
    /* @4965344 load */
    /* @4965352 constant */
    /* @4965356 add */
    /* @4965360 constant */
    /* @4965364 load */
    /* @4965372 cast */
    /* @4965376 load */
    /* @4965384 constant */
    /* @4965388 add */
    /* @4965392 call */
    GM_SITE(vm, 641, 4965392);
    v97 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v98 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4965400 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v97, v98, STR_REF(1125)));
    /* @4965404 string */
    /* @4965412 cast */
    /* @4965416 constant */
    /* @4965420 load */
    /* @4965428 cast */
    /* @4965432 load */
    /* @4965440 constant */
    /* @4965444 add */
    /* @4965448 constant */
    /* @4965452 load */
    /* @4965460 cast */
    /* @4965464 load */
    /* @4965472 constant */
    /* @4965476 add */
    /* @4965480 call */
    GM_SITE(vm, 641, 4965480);
    v99 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v100 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4965488 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v99, v100, STR_REF(1126)));
    L_4965492: ;
    /* @4965492 load */
    /* @4965500 constant */
    /* @4965504 cmp */
    /* @4965508 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4965732;
    /* @4965512 constant */
    /* @4965516 cast */
    /* @4965520 call */
    GM_SITE(vm, 641, 4965520);
    /* @4965528 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4965532 constant */
    /* @4965540 cast */
    /* @4965544 call */
    GM_SITE(vm, 641, 4965544);
    /* @4965552 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4965556 string */
    /* @4965564 cast */
    /* @4965568 constant */
    /* @4965572 load */
    /* @4965580 cast */
    /* @4965584 load */
    /* @4965592 constant */
    /* @4965596 add */
    /* @4965600 constant */
    /* @4965604 load */
    /* @4965612 cast */
    /* @4965616 load */
    /* @4965624 constant */
    /* @4965628 add */
    /* @4965632 call */
    GM_SITE(vm, 641, 4965632);
    v101 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v102 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4965640 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v101, v102, STR_REF(1125)));
    /* @4965644 string */
    /* @4965652 cast */
    /* @4965656 constant */
    /* @4965660 load */
    /* @4965668 cast */
    /* @4965672 load */
    /* @4965680 constant */
    /* @4965684 add */
    /* @4965688 constant */
    /* @4965692 load */
    /* @4965700 cast */
    /* @4965704 load */
    /* @4965712 constant */
    /* @4965716 add */
    /* @4965720 call */
    GM_SITE(vm, 641, 4965720);
    v103 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v104 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4965728 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v103, v104, STR_REF(1126)));
    L_4965732: ;
    /* @4965732 load */
    /* @4965740 constant */
    /* @4965744 cmp */
    /* @4965748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4965972;
    /* @4965752 constant */
    /* @4965756 cast */
    /* @4965760 call */
    GM_SITE(vm, 641, 4965760);
    /* @4965768 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4965772 constant */
    /* @4965780 cast */
    /* @4965784 call */
    GM_SITE(vm, 641, 4965784);
    /* @4965792 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4965796 string */
    /* @4965804 cast */
    /* @4965808 constant */
    /* @4965812 load */
    /* @4965820 cast */
    /* @4965824 load */
    /* @4965832 constant */
    /* @4965836 add */
    /* @4965840 constant */
    /* @4965844 load */
    /* @4965852 cast */
    /* @4965856 load */
    /* @4965864 constant */
    /* @4965868 add */
    /* @4965872 call */
    GM_SITE(vm, 641, 4965872);
    v105 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v106 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4965880 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v105, v106, STR_REF(1125)));
    /* @4965884 string */
    /* @4965892 cast */
    /* @4965896 constant */
    /* @4965900 load */
    /* @4965908 cast */
    /* @4965912 load */
    /* @4965920 constant */
    /* @4965924 add */
    /* @4965928 constant */
    /* @4965932 load */
    /* @4965940 cast */
    /* @4965944 load */
    /* @4965952 constant */
    /* @4965956 add */
    /* @4965960 call */
    GM_SITE(vm, 641, 4965960);
    v107 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v108 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4965968 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v107, v108, STR_REF(1126)));
    L_4965972: ;
    /* @4965972 load */
    /* @4965980 constant */
    /* @4965984 cmp */
    /* @4965988 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel4") == VAL(1)))) goto L_4967432;
    /* @4965992 load */
    /* @4966000 constant */
    /* @4966004 cmp */
    /* @4966008 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4966232;
    /* @4966012 constant */
    /* @4966016 cast */
    /* @4966020 call */
    GM_SITE(vm, 641, 4966020);
    /* @4966028 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4966032 constant */
    /* @4966040 cast */
    /* @4966044 call */
    GM_SITE(vm, 641, 4966044);
    /* @4966052 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4966056 string */
    /* @4966064 cast */
    /* @4966068 constant */
    /* @4966072 load */
    /* @4966080 cast */
    /* @4966084 load */
    /* @4966092 constant */
    /* @4966096 add */
    /* @4966100 constant */
    /* @4966104 load */
    /* @4966112 cast */
    /* @4966116 load */
    /* @4966124 constant */
    /* @4966128 add */
    /* @4966132 call */
    GM_SITE(vm, 641, 4966132);
    v109 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v110 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4966140 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v109, v110, STR_REF(1127)));
    /* @4966144 string */
    /* @4966152 cast */
    /* @4966156 constant */
    /* @4966160 load */
    /* @4966168 cast */
    /* @4966172 load */
    /* @4966180 constant */
    /* @4966184 add */
    /* @4966188 constant */
    /* @4966192 load */
    /* @4966200 cast */
    /* @4966204 load */
    /* @4966212 constant */
    /* @4966216 add */
    /* @4966220 call */
    GM_SITE(vm, 641, 4966220);
    v111 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v112 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4966228 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v111, v112, STR_REF(1128)));
    L_4966232: ;
    /* @4966232 load */
    /* @4966240 constant */
    /* @4966244 cmp */
    /* @4966248 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4966472;
    /* @4966252 constant */
    /* @4966256 cast */
    /* @4966260 call */
    GM_SITE(vm, 641, 4966260);
    /* @4966268 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4966272 constant */
    /* @4966280 cast */
    /* @4966284 call */
    GM_SITE(vm, 641, 4966284);
    /* @4966292 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4966296 string */
    /* @4966304 cast */
    /* @4966308 constant */
    /* @4966312 load */
    /* @4966320 cast */
    /* @4966324 load */
    /* @4966332 constant */
    /* @4966336 add */
    /* @4966340 constant */
    /* @4966344 load */
    /* @4966352 cast */
    /* @4966356 load */
    /* @4966364 constant */
    /* @4966368 add */
    /* @4966372 call */
    GM_SITE(vm, 641, 4966372);
    v113 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v114 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4966380 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v113, v114, STR_REF(1127)));
    /* @4966384 string */
    /* @4966392 cast */
    /* @4966396 constant */
    /* @4966400 load */
    /* @4966408 cast */
    /* @4966412 load */
    /* @4966420 constant */
    /* @4966424 add */
    /* @4966428 constant */
    /* @4966432 load */
    /* @4966440 cast */
    /* @4966444 load */
    /* @4966452 constant */
    /* @4966456 add */
    /* @4966460 call */
    GM_SITE(vm, 641, 4966460);
    v115 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v116 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4966468 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v115, v116, STR_REF(1128)));
    L_4966472: ;
    /* @4966472 load */
    /* @4966480 constant */
    /* @4966484 cmp */
    /* @4966488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4966712;
    /* @4966492 constant */
    /* @4966496 cast */
    /* @4966500 call */
    GM_SITE(vm, 641, 4966500);
    /* @4966508 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4966512 constant */
    /* @4966520 cast */
    /* @4966524 call */
    GM_SITE(vm, 641, 4966524);
    /* @4966532 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4966536 string */
    /* @4966544 cast */
    /* @4966548 constant */
    /* @4966552 load */
    /* @4966560 cast */
    /* @4966564 load */
    /* @4966572 constant */
    /* @4966576 add */
    /* @4966580 constant */
    /* @4966584 load */
    /* @4966592 cast */
    /* @4966596 load */
    /* @4966604 constant */
    /* @4966608 add */
    /* @4966612 call */
    GM_SITE(vm, 641, 4966612);
    v117 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v118 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4966620 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v117, v118, STR_REF(1127)));
    /* @4966624 string */
    /* @4966632 cast */
    /* @4966636 constant */
    /* @4966640 load */
    /* @4966648 cast */
    /* @4966652 load */
    /* @4966660 constant */
    /* @4966664 add */
    /* @4966668 constant */
    /* @4966672 load */
    /* @4966680 cast */
    /* @4966684 load */
    /* @4966692 constant */
    /* @4966696 add */
    /* @4966700 call */
    GM_SITE(vm, 641, 4966700);
    v119 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v120 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4966708 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v119, v120, STR_REF(1128)));
    L_4966712: ;
    /* @4966712 load */
    /* @4966720 constant */
    /* @4966724 cmp */
    /* @4966728 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4966952;
    /* @4966732 constant */
    /* @4966736 cast */
    /* @4966740 call */
    GM_SITE(vm, 641, 4966740);
    /* @4966748 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4966752 constant */
    /* @4966760 cast */
    /* @4966764 call */
    GM_SITE(vm, 641, 4966764);
    /* @4966772 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4966776 string */
    /* @4966784 cast */
    /* @4966788 constant */
    /* @4966792 load */
    /* @4966800 cast */
    /* @4966804 load */
    /* @4966812 constant */
    /* @4966816 add */
    /* @4966820 constant */
    /* @4966824 load */
    /* @4966832 cast */
    /* @4966836 load */
    /* @4966844 constant */
    /* @4966848 add */
    /* @4966852 call */
    GM_SITE(vm, 641, 4966852);
    v121 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v122 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4966860 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v121, v122, STR_REF(1127)));
    /* @4966864 string */
    /* @4966872 cast */
    /* @4966876 constant */
    /* @4966880 load */
    /* @4966888 cast */
    /* @4966892 load */
    /* @4966900 constant */
    /* @4966904 add */
    /* @4966908 constant */
    /* @4966912 load */
    /* @4966920 cast */
    /* @4966924 load */
    /* @4966932 constant */
    /* @4966936 add */
    /* @4966940 call */
    GM_SITE(vm, 641, 4966940);
    v123 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v124 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4966948 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v123, v124, STR_REF(1128)));
    L_4966952: ;
    /* @4966952 load */
    /* @4966960 constant */
    /* @4966964 cmp */
    /* @4966968 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4967192;
    /* @4966972 constant */
    /* @4966976 cast */
    /* @4966980 call */
    GM_SITE(vm, 641, 4966980);
    /* @4966988 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4966992 constant */
    /* @4967000 cast */
    /* @4967004 call */
    GM_SITE(vm, 641, 4967004);
    /* @4967012 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4967016 string */
    /* @4967024 cast */
    /* @4967028 constant */
    /* @4967032 load */
    /* @4967040 cast */
    /* @4967044 load */
    /* @4967052 constant */
    /* @4967056 add */
    /* @4967060 constant */
    /* @4967064 load */
    /* @4967072 cast */
    /* @4967076 load */
    /* @4967084 constant */
    /* @4967088 add */
    /* @4967092 call */
    GM_SITE(vm, 641, 4967092);
    v125 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v126 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4967100 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v125, v126, STR_REF(1127)));
    /* @4967104 string */
    /* @4967112 cast */
    /* @4967116 constant */
    /* @4967120 load */
    /* @4967128 cast */
    /* @4967132 load */
    /* @4967140 constant */
    /* @4967144 add */
    /* @4967148 constant */
    /* @4967152 load */
    /* @4967160 cast */
    /* @4967164 load */
    /* @4967172 constant */
    /* @4967176 add */
    /* @4967180 call */
    GM_SITE(vm, 641, 4967180);
    v127 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v128 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4967188 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v127, v128, STR_REF(1128)));
    L_4967192: ;
    /* @4967192 load */
    /* @4967200 constant */
    /* @4967204 cmp */
    /* @4967208 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4967432;
    /* @4967212 constant */
    /* @4967216 cast */
    /* @4967220 call */
    GM_SITE(vm, 641, 4967220);
    /* @4967228 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4967232 constant */
    /* @4967240 cast */
    /* @4967244 call */
    GM_SITE(vm, 641, 4967244);
    /* @4967252 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4967256 string */
    /* @4967264 cast */
    /* @4967268 constant */
    /* @4967272 load */
    /* @4967280 cast */
    /* @4967284 load */
    /* @4967292 constant */
    /* @4967296 add */
    /* @4967300 constant */
    /* @4967304 load */
    /* @4967312 cast */
    /* @4967316 load */
    /* @4967324 constant */
    /* @4967328 add */
    /* @4967332 call */
    GM_SITE(vm, 641, 4967332);
    v129 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v130 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4967340 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v129, v130, STR_REF(1127)));
    /* @4967344 string */
    /* @4967352 cast */
    /* @4967356 constant */
    /* @4967360 load */
    /* @4967368 cast */
    /* @4967372 load */
    /* @4967380 constant */
    /* @4967384 add */
    /* @4967388 constant */
    /* @4967392 load */
    /* @4967400 cast */
    /* @4967404 load */
    /* @4967412 constant */
    /* @4967416 add */
    /* @4967420 call */
    GM_SITE(vm, 641, 4967420);
    v131 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v132 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4967428 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v131, v132, STR_REF(1128)));
    L_4967432: ;
    /* @4967432 load */
    /* @4967440 constant */
    /* @4967444 cmp */
    /* @4967448 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel5") == VAL(1)))) goto L_4968892;
    /* @4967452 load */
    /* @4967460 constant */
    /* @4967464 cmp */
    /* @4967468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4967692;
    /* @4967472 constant */
    /* @4967476 cast */
    /* @4967480 call */
    GM_SITE(vm, 641, 4967480);
    /* @4967488 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4967492 constant */
    /* @4967500 cast */
    /* @4967504 call */
    GM_SITE(vm, 641, 4967504);
    /* @4967512 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4967516 string */
    /* @4967524 cast */
    /* @4967528 constant */
    /* @4967532 load */
    /* @4967540 cast */
    /* @4967544 load */
    /* @4967552 constant */
    /* @4967556 add */
    /* @4967560 constant */
    /* @4967564 load */
    /* @4967572 cast */
    /* @4967576 load */
    /* @4967584 constant */
    /* @4967588 add */
    /* @4967592 call */
    GM_SITE(vm, 641, 4967592);
    v133 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v134 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4967600 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v133, v134, STR_REF(1129)));
    /* @4967604 string */
    /* @4967612 cast */
    /* @4967616 constant */
    /* @4967620 load */
    /* @4967628 cast */
    /* @4967632 load */
    /* @4967640 constant */
    /* @4967644 add */
    /* @4967648 constant */
    /* @4967652 load */
    /* @4967660 cast */
    /* @4967664 load */
    /* @4967672 constant */
    /* @4967676 add */
    /* @4967680 call */
    GM_SITE(vm, 641, 4967680);
    v135 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v136 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4967688 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v135, v136, STR_REF(1130)));
    L_4967692: ;
    /* @4967692 load */
    /* @4967700 constant */
    /* @4967704 cmp */
    /* @4967708 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4967932;
    /* @4967712 constant */
    /* @4967716 cast */
    /* @4967720 call */
    GM_SITE(vm, 641, 4967720);
    /* @4967728 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4967732 constant */
    /* @4967740 cast */
    /* @4967744 call */
    GM_SITE(vm, 641, 4967744);
    /* @4967752 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4967756 string */
    /* @4967764 cast */
    /* @4967768 constant */
    /* @4967772 load */
    /* @4967780 cast */
    /* @4967784 load */
    /* @4967792 constant */
    /* @4967796 add */
    /* @4967800 constant */
    /* @4967804 load */
    /* @4967812 cast */
    /* @4967816 load */
    /* @4967824 constant */
    /* @4967828 add */
    /* @4967832 call */
    GM_SITE(vm, 641, 4967832);
    v137 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v138 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4967840 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v137, v138, STR_REF(1129)));
    /* @4967844 string */
    /* @4967852 cast */
    /* @4967856 constant */
    /* @4967860 load */
    /* @4967868 cast */
    /* @4967872 load */
    /* @4967880 constant */
    /* @4967884 add */
    /* @4967888 constant */
    /* @4967892 load */
    /* @4967900 cast */
    /* @4967904 load */
    /* @4967912 constant */
    /* @4967916 add */
    /* @4967920 call */
    GM_SITE(vm, 641, 4967920);
    v139 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v140 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4967928 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v139, v140, STR_REF(1130)));
    L_4967932: ;
    /* @4967932 load */
    /* @4967940 constant */
    /* @4967944 cmp */
    /* @4967948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4968172;
    /* @4967952 constant */
    /* @4967956 cast */
    /* @4967960 call */
    GM_SITE(vm, 641, 4967960);
    /* @4967968 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4967972 constant */
    /* @4967980 cast */
    /* @4967984 call */
    GM_SITE(vm, 641, 4967984);
    /* @4967992 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4967996 string */
    /* @4968004 cast */
    /* @4968008 constant */
    /* @4968012 load */
    /* @4968020 cast */
    /* @4968024 load */
    /* @4968032 constant */
    /* @4968036 add */
    /* @4968040 constant */
    /* @4968044 load */
    /* @4968052 cast */
    /* @4968056 load */
    /* @4968064 constant */
    /* @4968068 add */
    /* @4968072 call */
    GM_SITE(vm, 641, 4968072);
    v141 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v142 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4968080 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v141, v142, STR_REF(1129)));
    /* @4968084 string */
    /* @4968092 cast */
    /* @4968096 constant */
    /* @4968100 load */
    /* @4968108 cast */
    /* @4968112 load */
    /* @4968120 constant */
    /* @4968124 add */
    /* @4968128 constant */
    /* @4968132 load */
    /* @4968140 cast */
    /* @4968144 load */
    /* @4968152 constant */
    /* @4968156 add */
    /* @4968160 call */
    GM_SITE(vm, 641, 4968160);
    v143 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v144 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4968168 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v143, v144, STR_REF(1130)));
    L_4968172: ;
    /* @4968172 load */
    /* @4968180 constant */
    /* @4968184 cmp */
    /* @4968188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4968412;
    /* @4968192 constant */
    /* @4968196 cast */
    /* @4968200 call */
    GM_SITE(vm, 641, 4968200);
    /* @4968208 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4968212 constant */
    /* @4968220 cast */
    /* @4968224 call */
    GM_SITE(vm, 641, 4968224);
    /* @4968232 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4968236 string */
    /* @4968244 cast */
    /* @4968248 constant */
    /* @4968252 load */
    /* @4968260 cast */
    /* @4968264 load */
    /* @4968272 constant */
    /* @4968276 add */
    /* @4968280 constant */
    /* @4968284 load */
    /* @4968292 cast */
    /* @4968296 load */
    /* @4968304 constant */
    /* @4968308 add */
    /* @4968312 call */
    GM_SITE(vm, 641, 4968312);
    v145 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v146 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4968320 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v145, v146, STR_REF(1129)));
    /* @4968324 string */
    /* @4968332 cast */
    /* @4968336 constant */
    /* @4968340 load */
    /* @4968348 cast */
    /* @4968352 load */
    /* @4968360 constant */
    /* @4968364 add */
    /* @4968368 constant */
    /* @4968372 load */
    /* @4968380 cast */
    /* @4968384 load */
    /* @4968392 constant */
    /* @4968396 add */
    /* @4968400 call */
    GM_SITE(vm, 641, 4968400);
    v147 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v148 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4968408 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v147, v148, STR_REF(1130)));
    L_4968412: ;
    /* @4968412 load */
    /* @4968420 constant */
    /* @4968424 cmp */
    /* @4968428 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4968652;
    /* @4968432 constant */
    /* @4968436 cast */
    /* @4968440 call */
    GM_SITE(vm, 641, 4968440);
    /* @4968448 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4968452 constant */
    /* @4968460 cast */
    /* @4968464 call */
    GM_SITE(vm, 641, 4968464);
    /* @4968472 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4968476 string */
    /* @4968484 cast */
    /* @4968488 constant */
    /* @4968492 load */
    /* @4968500 cast */
    /* @4968504 load */
    /* @4968512 constant */
    /* @4968516 add */
    /* @4968520 constant */
    /* @4968524 load */
    /* @4968532 cast */
    /* @4968536 load */
    /* @4968544 constant */
    /* @4968548 add */
    /* @4968552 call */
    GM_SITE(vm, 641, 4968552);
    v149 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v150 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4968560 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v149, v150, STR_REF(1129)));
    /* @4968564 string */
    /* @4968572 cast */
    /* @4968576 constant */
    /* @4968580 load */
    /* @4968588 cast */
    /* @4968592 load */
    /* @4968600 constant */
    /* @4968604 add */
    /* @4968608 constant */
    /* @4968612 load */
    /* @4968620 cast */
    /* @4968624 load */
    /* @4968632 constant */
    /* @4968636 add */
    /* @4968640 call */
    GM_SITE(vm, 641, 4968640);
    v151 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v152 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4968648 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v151, v152, STR_REF(1130)));
    L_4968652: ;
    /* @4968652 load */
    /* @4968660 constant */
    /* @4968664 cmp */
    /* @4968668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4968892;
    /* @4968672 constant */
    /* @4968676 cast */
    /* @4968680 call */
    GM_SITE(vm, 641, 4968680);
    /* @4968688 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4968692 constant */
    /* @4968700 cast */
    /* @4968704 call */
    GM_SITE(vm, 641, 4968704);
    /* @4968712 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4968716 string */
    /* @4968724 cast */
    /* @4968728 constant */
    /* @4968732 load */
    /* @4968740 cast */
    /* @4968744 load */
    /* @4968752 constant */
    /* @4968756 add */
    /* @4968760 constant */
    /* @4968764 load */
    /* @4968772 cast */
    /* @4968776 load */
    /* @4968784 constant */
    /* @4968788 add */
    /* @4968792 call */
    GM_SITE(vm, 641, 4968792);
    v153 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v154 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4968800 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v153, v154, STR_REF(1129)));
    /* @4968804 string */
    /* @4968812 cast */
    /* @4968816 constant */
    /* @4968820 load */
    /* @4968828 cast */
    /* @4968832 load */
    /* @4968840 constant */
    /* @4968844 add */
    /* @4968848 constant */
    /* @4968852 load */
    /* @4968860 cast */
    /* @4968864 load */
    /* @4968872 constant */
    /* @4968876 add */
    /* @4968880 call */
    GM_SITE(vm, 641, 4968880);
    v155 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v156 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4968888 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v155, v156, STR_REF(1130)));
    L_4968892: ;
    /* @4968892 load */
    /* @4968900 constant */
    /* @4968904 cmp */
    /* @4968908 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel6") == VAL(1)))) goto L_4970352;
    /* @4968912 load */
    /* @4968920 constant */
    /* @4968924 cmp */
    /* @4968928 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4969152;
    /* @4968932 constant */
    /* @4968936 cast */
    /* @4968940 call */
    GM_SITE(vm, 641, 4968940);
    /* @4968948 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4968952 constant */
    /* @4968960 cast */
    /* @4968964 call */
    GM_SITE(vm, 641, 4968964);
    /* @4968972 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4968976 string */
    /* @4968984 cast */
    /* @4968988 constant */
    /* @4968992 load */
    /* @4969000 cast */
    /* @4969004 load */
    /* @4969012 constant */
    /* @4969016 add */
    /* @4969020 constant */
    /* @4969024 load */
    /* @4969032 cast */
    /* @4969036 load */
    /* @4969044 constant */
    /* @4969048 add */
    /* @4969052 call */
    GM_SITE(vm, 641, 4969052);
    v157 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v158 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4969060 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v157, v158, STR_REF(1131)));
    /* @4969064 string */
    /* @4969072 cast */
    /* @4969076 constant */
    /* @4969080 load */
    /* @4969088 cast */
    /* @4969092 load */
    /* @4969100 constant */
    /* @4969104 add */
    /* @4969108 constant */
    /* @4969112 load */
    /* @4969120 cast */
    /* @4969124 load */
    /* @4969132 constant */
    /* @4969136 add */
    /* @4969140 call */
    GM_SITE(vm, 641, 4969140);
    v159 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v160 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4969148 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v159, v160, STR_REF(1132)));
    L_4969152: ;
    /* @4969152 load */
    /* @4969160 constant */
    /* @4969164 cmp */
    /* @4969168 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4969392;
    /* @4969172 constant */
    /* @4969176 cast */
    /* @4969180 call */
    GM_SITE(vm, 641, 4969180);
    /* @4969188 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4969192 constant */
    /* @4969200 cast */
    /* @4969204 call */
    GM_SITE(vm, 641, 4969204);
    /* @4969212 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4969216 string */
    /* @4969224 cast */
    /* @4969228 constant */
    /* @4969232 load */
    /* @4969240 cast */
    /* @4969244 load */
    /* @4969252 constant */
    /* @4969256 add */
    /* @4969260 constant */
    /* @4969264 load */
    /* @4969272 cast */
    /* @4969276 load */
    /* @4969284 constant */
    /* @4969288 add */
    /* @4969292 call */
    GM_SITE(vm, 641, 4969292);
    v161 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v162 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4969300 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v161, v162, STR_REF(1131)));
    /* @4969304 string */
    /* @4969312 cast */
    /* @4969316 constant */
    /* @4969320 load */
    /* @4969328 cast */
    /* @4969332 load */
    /* @4969340 constant */
    /* @4969344 add */
    /* @4969348 constant */
    /* @4969352 load */
    /* @4969360 cast */
    /* @4969364 load */
    /* @4969372 constant */
    /* @4969376 add */
    /* @4969380 call */
    GM_SITE(vm, 641, 4969380);
    v163 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v164 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4969388 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v163, v164, STR_REF(1132)));
    L_4969392: ;
    /* @4969392 load */
    /* @4969400 constant */
    /* @4969404 cmp */
    /* @4969408 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4969632;
    /* @4969412 constant */
    /* @4969416 cast */
    /* @4969420 call */
    GM_SITE(vm, 641, 4969420);
    /* @4969428 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4969432 constant */
    /* @4969440 cast */
    /* @4969444 call */
    GM_SITE(vm, 641, 4969444);
    /* @4969452 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4969456 string */
    /* @4969464 cast */
    /* @4969468 constant */
    /* @4969472 load */
    /* @4969480 cast */
    /* @4969484 load */
    /* @4969492 constant */
    /* @4969496 add */
    /* @4969500 constant */
    /* @4969504 load */
    /* @4969512 cast */
    /* @4969516 load */
    /* @4969524 constant */
    /* @4969528 add */
    /* @4969532 call */
    GM_SITE(vm, 641, 4969532);
    v165 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v166 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4969540 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v165, v166, STR_REF(1131)));
    /* @4969544 string */
    /* @4969552 cast */
    /* @4969556 constant */
    /* @4969560 load */
    /* @4969568 cast */
    /* @4969572 load */
    /* @4969580 constant */
    /* @4969584 add */
    /* @4969588 constant */
    /* @4969592 load */
    /* @4969600 cast */
    /* @4969604 load */
    /* @4969612 constant */
    /* @4969616 add */
    /* @4969620 call */
    GM_SITE(vm, 641, 4969620);
    v167 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v168 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4969628 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v167, v168, STR_REF(1132)));
    L_4969632: ;
    /* @4969632 load */
    /* @4969640 constant */
    /* @4969644 cmp */
    /* @4969648 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4969872;
    /* @4969652 constant */
    /* @4969656 cast */
    /* @4969660 call */
    GM_SITE(vm, 641, 4969660);
    /* @4969668 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4969672 constant */
    /* @4969680 cast */
    /* @4969684 call */
    GM_SITE(vm, 641, 4969684);
    /* @4969692 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4969696 string */
    /* @4969704 cast */
    /* @4969708 constant */
    /* @4969712 load */
    /* @4969720 cast */
    /* @4969724 load */
    /* @4969732 constant */
    /* @4969736 add */
    /* @4969740 constant */
    /* @4969744 load */
    /* @4969752 cast */
    /* @4969756 load */
    /* @4969764 constant */
    /* @4969768 add */
    /* @4969772 call */
    GM_SITE(vm, 641, 4969772);
    v169 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v170 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4969780 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v169, v170, STR_REF(1131)));
    /* @4969784 string */
    /* @4969792 cast */
    /* @4969796 constant */
    /* @4969800 load */
    /* @4969808 cast */
    /* @4969812 load */
    /* @4969820 constant */
    /* @4969824 add */
    /* @4969828 constant */
    /* @4969832 load */
    /* @4969840 cast */
    /* @4969844 load */
    /* @4969852 constant */
    /* @4969856 add */
    /* @4969860 call */
    GM_SITE(vm, 641, 4969860);
    v171 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v172 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4969868 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v171, v172, STR_REF(1132)));
    L_4969872: ;
    /* @4969872 load */
    /* @4969880 constant */
    /* @4969884 cmp */
    /* @4969888 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4970112;
    /* @4969892 constant */
    /* @4969896 cast */
    /* @4969900 call */
    GM_SITE(vm, 641, 4969900);
    /* @4969908 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4969912 constant */
    /* @4969920 cast */
    /* @4969924 call */
    GM_SITE(vm, 641, 4969924);
    /* @4969932 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4969936 string */
    /* @4969944 cast */
    /* @4969948 constant */
    /* @4969952 load */
    /* @4969960 cast */
    /* @4969964 load */
    /* @4969972 constant */
    /* @4969976 add */
    /* @4969980 constant */
    /* @4969984 load */
    /* @4969992 cast */
    /* @4969996 load */
    /* @4970004 constant */
    /* @4970008 add */
    /* @4970012 call */
    GM_SITE(vm, 641, 4970012);
    v173 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v174 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4970020 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v173, v174, STR_REF(1131)));
    /* @4970024 string */
    /* @4970032 cast */
    /* @4970036 constant */
    /* @4970040 load */
    /* @4970048 cast */
    /* @4970052 load */
    /* @4970060 constant */
    /* @4970064 add */
    /* @4970068 constant */
    /* @4970072 load */
    /* @4970080 cast */
    /* @4970084 load */
    /* @4970092 constant */
    /* @4970096 add */
    /* @4970100 call */
    GM_SITE(vm, 641, 4970100);
    v175 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v176 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4970108 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v175, v176, STR_REF(1132)));
    L_4970112: ;
    /* @4970112 load */
    /* @4970120 constant */
    /* @4970124 cmp */
    /* @4970128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4970352;
    /* @4970132 constant */
    /* @4970136 cast */
    /* @4970140 call */
    GM_SITE(vm, 641, 4970140);
    /* @4970148 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4970152 constant */
    /* @4970160 cast */
    /* @4970164 call */
    GM_SITE(vm, 641, 4970164);
    /* @4970172 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4970176 string */
    /* @4970184 cast */
    /* @4970188 constant */
    /* @4970192 load */
    /* @4970200 cast */
    /* @4970204 load */
    /* @4970212 constant */
    /* @4970216 add */
    /* @4970220 constant */
    /* @4970224 load */
    /* @4970232 cast */
    /* @4970236 load */
    /* @4970244 constant */
    /* @4970248 add */
    /* @4970252 call */
    GM_SITE(vm, 641, 4970252);
    v177 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v178 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4970260 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v177, v178, STR_REF(1131)));
    /* @4970264 string */
    /* @4970272 cast */
    /* @4970276 constant */
    /* @4970280 load */
    /* @4970288 cast */
    /* @4970292 load */
    /* @4970300 constant */
    /* @4970304 add */
    /* @4970308 constant */
    /* @4970312 load */
    /* @4970320 cast */
    /* @4970324 load */
    /* @4970332 constant */
    /* @4970336 add */
    /* @4970340 call */
    GM_SITE(vm, 641, 4970340);
    v179 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v180 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4970348 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v179, v180, STR_REF(1132)));
    L_4970352: ;
    /* @4970352 load */
    /* @4970360 constant */
    /* @4970364 cmp */
    /* @4970368 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4970404;
    /* @4970372 constant */
    /* @4970376 cast */
    /* @4970380 constant */
    /* @4970384 cast */
    /* @4970388 call */
    GM_SITE(vm, 641, 4970388);
    /* @4970396 cast */
    /* @4970400 b */
    v181 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, VAL(0), VAL(1)));
    p4970408_0 = v181;
    goto L_4970408;
    L_4970404: ;
    /* @4970404 constant */
    p4970408_0 = VAL(0);
    L_4970408: ;
    /* @4970408 bf */
    if (!TRUTH(p4970408_0)) goto L_4970424;
    /* @4970412 call */
    GM_SITE(vm, 641, 4970412);
    /* @4970420 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4970424: ;
    return;
}
