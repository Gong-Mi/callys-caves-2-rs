/* generated from CODE 356 (gml_Object_obj_levelup_Draw_0), source start 4199244, end 4209596. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0356(GmVM* vm) {
    Val p4199300_0;
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
    Val p4201024_0;
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
    Val p4202748_0;
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
    Val p4204472_0;
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
    Val p4206196_0;
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
    Val p4207920_0;
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
    Val v205;
    Val v206;
    Val v207;
    Val v208;
    Val v209;
    Val v210;
    Val v211;
    Val v212;
    Val v213;
    Val v214;
    Val v215;
    Val v216;
    Val v217;
    Val v218;
    Val v219;
    Val v220;
    Val v221;
    Val v222;
    Val v223;
    Val v224;
    Val v225;
    Val v226;
    Val v227;
    Val v228;
    /* @4199244 call */
    GM_SITE(vm, 356, 4199244);
    /* @4199252 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    /* @4199256 load */
    /* @4199264 constant */
    /* @4199268 cmp */
    /* @4199272 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4199296;
    /* @4199276 load */
    /* @4199284 constant */
    /* @4199288 cmp */
    /* @4199292 b */
    p4199300_0 = NUMBOOL(GM_READ(vm, -1, "showpart") == VAL(1));
    goto L_4199300;
    L_4199296: ;
    /* @4199296 constant */
    p4199300_0 = VAL(0);
    L_4199300: ;
    /* @4199300 bf */
    if (!TRUTH(p4199300_0)) goto L_4200980;
    /* @4199304 load */
    /* @4199312 constant */
    /* @4199316 cmp */
    /* @4199320 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(2)))) goto L_4199392;
    /* @4199324 constant */
    /* @4199328 cast */
    /* @4199332 load */
    /* @4199340 load */
    /* @4199348 constant */
    /* @4199352 add */
    /* @4199356 load */
    /* @4199364 constant */
    /* @4199368 add */
    /* @4199372 load */
    /* @4199380 call */
    GM_SITE(vm, 356, 4199380);
    v1 = GM_ADD(GM_READ(vm, 66, "x"), VAL(104));
    v2 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4199388 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v1, v2, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4199392: ;
    /* @4199392 load */
    /* @4199400 constant */
    /* @4199404 cmp */
    /* @4199408 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(3)))) goto L_4199480;
    /* @4199412 constant */
    /* @4199416 cast */
    /* @4199420 load */
    /* @4199428 load */
    /* @4199436 constant */
    /* @4199440 add */
    /* @4199444 load */
    /* @4199452 constant */
    /* @4199456 add */
    /* @4199460 load */
    /* @4199468 call */
    GM_SITE(vm, 356, 4199468);
    v3 = GM_ADD(GM_READ(vm, 66, "x"), VAL(119));
    v4 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4199476 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v3, v4, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4199480: ;
    /* @4199480 load */
    /* @4199488 constant */
    /* @4199492 cmp */
    /* @4199496 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(4)))) goto L_4199568;
    /* @4199500 constant */
    /* @4199504 cast */
    /* @4199508 load */
    /* @4199516 load */
    /* @4199524 constant */
    /* @4199528 add */
    /* @4199532 load */
    /* @4199540 constant */
    /* @4199544 add */
    /* @4199548 load */
    /* @4199556 call */
    GM_SITE(vm, 356, 4199556);
    v5 = GM_ADD(GM_READ(vm, 66, "x"), VAL(134));
    v6 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4199564 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v5, v6, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4199568: ;
    /* @4199568 load */
    /* @4199576 constant */
    /* @4199580 cmp */
    /* @4199584 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(5)))) goto L_4199656;
    /* @4199588 constant */
    /* @4199592 cast */
    /* @4199596 load */
    /* @4199604 load */
    /* @4199612 constant */
    /* @4199616 add */
    /* @4199620 load */
    /* @4199628 constant */
    /* @4199632 add */
    /* @4199636 load */
    /* @4199644 call */
    GM_SITE(vm, 356, 4199644);
    v7 = GM_ADD(GM_READ(vm, 66, "x"), VAL(149));
    v8 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4199652 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v7, v8, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4199656: ;
    /* @4199656 load */
    /* @4199664 constant */
    /* @4199668 cmp */
    /* @4199672 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(6)))) goto L_4199744;
    /* @4199676 constant */
    /* @4199680 cast */
    /* @4199684 load */
    /* @4199692 load */
    /* @4199700 constant */
    /* @4199704 add */
    /* @4199708 load */
    /* @4199716 constant */
    /* @4199720 add */
    /* @4199724 load */
    /* @4199732 call */
    GM_SITE(vm, 356, 4199732);
    v9 = GM_ADD(GM_READ(vm, 66, "x"), VAL(164));
    v10 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4199740 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v9, v10, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4199744: ;
    /* @4199744 load */
    /* @4199752 constant */
    /* @4199756 cmp */
    /* @4199760 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(7)))) goto L_4199832;
    /* @4199764 constant */
    /* @4199768 cast */
    /* @4199772 load */
    /* @4199780 load */
    /* @4199788 constant */
    /* @4199792 add */
    /* @4199796 load */
    /* @4199804 constant */
    /* @4199808 add */
    /* @4199812 load */
    /* @4199820 call */
    GM_SITE(vm, 356, 4199820);
    v11 = GM_ADD(GM_READ(vm, 66, "x"), VAL(179));
    v12 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4199828 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v11, v12, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4199832: ;
    /* @4199832 load */
    /* @4199840 constant */
    /* @4199844 cmp */
    /* @4199848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(8)))) goto L_4199920;
    /* @4199852 constant */
    /* @4199856 cast */
    /* @4199860 load */
    /* @4199868 load */
    /* @4199876 constant */
    /* @4199880 add */
    /* @4199884 load */
    /* @4199892 constant */
    /* @4199896 add */
    /* @4199900 load */
    /* @4199908 call */
    GM_SITE(vm, 356, 4199908);
    v13 = GM_ADD(GM_READ(vm, 66, "x"), VAL(194));
    v14 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4199916 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v13, v14, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4199920: ;
    /* @4199920 load */
    /* @4199928 constant */
    /* @4199932 cmp */
    /* @4199936 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(9)))) goto L_4200008;
    /* @4199940 constant */
    /* @4199944 cast */
    /* @4199948 load */
    /* @4199956 load */
    /* @4199964 constant */
    /* @4199968 add */
    /* @4199972 load */
    /* @4199980 constant */
    /* @4199984 add */
    /* @4199988 load */
    /* @4199996 call */
    GM_SITE(vm, 356, 4199996);
    v15 = GM_ADD(GM_READ(vm, 66, "x"), VAL(58));
    v16 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4200004 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v15, v16, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4200008: ;
    /* @4200008 load */
    /* @4200016 constant */
    /* @4200020 cmp */
    /* @4200024 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(10)))) goto L_4200096;
    /* @4200028 constant */
    /* @4200032 cast */
    /* @4200036 load */
    /* @4200044 load */
    /* @4200052 constant */
    /* @4200056 add */
    /* @4200060 load */
    /* @4200068 constant */
    /* @4200072 add */
    /* @4200076 load */
    /* @4200084 call */
    GM_SITE(vm, 356, 4200084);
    v17 = GM_ADD(GM_READ(vm, 66, "x"), VAL(66));
    v18 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4200092 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v17, v18, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4200096: ;
    /* @4200096 load */
    /* @4200104 constant */
    /* @4200108 cmp */
    /* @4200112 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(11)))) goto L_4200184;
    /* @4200116 constant */
    /* @4200120 cast */
    /* @4200124 load */
    /* @4200132 load */
    /* @4200140 constant */
    /* @4200144 add */
    /* @4200148 load */
    /* @4200156 constant */
    /* @4200160 add */
    /* @4200164 load */
    /* @4200172 call */
    GM_SITE(vm, 356, 4200172);
    v19 = GM_ADD(GM_READ(vm, 66, "x"), VAL(74));
    v20 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4200180 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v19, v20, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4200184: ;
    /* @4200184 load */
    /* @4200192 constant */
    /* @4200196 cmp */
    /* @4200200 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(12)))) goto L_4200272;
    /* @4200204 constant */
    /* @4200208 cast */
    /* @4200212 load */
    /* @4200220 load */
    /* @4200228 constant */
    /* @4200232 add */
    /* @4200236 load */
    /* @4200244 constant */
    /* @4200248 add */
    /* @4200252 load */
    /* @4200260 call */
    GM_SITE(vm, 356, 4200260);
    v21 = GM_ADD(GM_READ(vm, 66, "x"), VAL(82));
    v22 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4200268 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v21, v22, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4200272: ;
    /* @4200272 load */
    /* @4200280 constant */
    /* @4200284 cmp */
    /* @4200288 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(13)))) goto L_4200360;
    /* @4200292 constant */
    /* @4200296 cast */
    /* @4200300 load */
    /* @4200308 load */
    /* @4200316 constant */
    /* @4200320 add */
    /* @4200324 load */
    /* @4200332 constant */
    /* @4200336 add */
    /* @4200340 load */
    /* @4200348 call */
    GM_SITE(vm, 356, 4200348);
    v23 = GM_ADD(GM_READ(vm, 66, "x"), VAL(90));
    v24 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4200356 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v23, v24, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4200360: ;
    /* @4200360 load */
    /* @4200368 constant */
    /* @4200372 cmp */
    /* @4200376 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(14)))) goto L_4200448;
    /* @4200380 constant */
    /* @4200384 cast */
    /* @4200388 load */
    /* @4200396 load */
    /* @4200404 constant */
    /* @4200408 add */
    /* @4200412 load */
    /* @4200420 constant */
    /* @4200424 add */
    /* @4200428 load */
    /* @4200436 call */
    GM_SITE(vm, 356, 4200436);
    v25 = GM_ADD(GM_READ(vm, 66, "x"), VAL(98));
    v26 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4200444 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v25, v26, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4200448: ;
    /* @4200448 load */
    /* @4200456 constant */
    /* @4200460 cmp */
    /* @4200464 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(15)))) goto L_4200536;
    /* @4200468 constant */
    /* @4200472 cast */
    /* @4200476 load */
    /* @4200484 load */
    /* @4200492 constant */
    /* @4200496 add */
    /* @4200500 load */
    /* @4200508 constant */
    /* @4200512 add */
    /* @4200516 load */
    /* @4200524 call */
    GM_SITE(vm, 356, 4200524);
    v27 = GM_ADD(GM_READ(vm, 66, "x"), VAL(106));
    v28 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4200532 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v27, v28, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4200536: ;
    /* @4200536 load */
    /* @4200544 constant */
    /* @4200548 cmp */
    /* @4200552 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(16)))) goto L_4200624;
    /* @4200556 constant */
    /* @4200560 cast */
    /* @4200564 load */
    /* @4200572 load */
    /* @4200580 constant */
    /* @4200584 add */
    /* @4200588 load */
    /* @4200596 constant */
    /* @4200600 add */
    /* @4200604 load */
    /* @4200612 call */
    GM_SITE(vm, 356, 4200612);
    v29 = GM_ADD(GM_READ(vm, 66, "x"), VAL(114));
    v30 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4200620 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v29, v30, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4200624: ;
    /* @4200624 load */
    /* @4200632 constant */
    /* @4200636 cmp */
    /* @4200640 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(17)))) goto L_4200712;
    /* @4200644 constant */
    /* @4200648 cast */
    /* @4200652 load */
    /* @4200660 load */
    /* @4200668 constant */
    /* @4200672 add */
    /* @4200676 load */
    /* @4200684 constant */
    /* @4200688 add */
    /* @4200692 load */
    /* @4200700 call */
    GM_SITE(vm, 356, 4200700);
    v31 = GM_ADD(GM_READ(vm, 66, "x"), VAL(122));
    v32 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4200708 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v31, v32, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4200712: ;
    /* @4200712 load */
    /* @4200720 constant */
    /* @4200724 cmp */
    /* @4200728 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(18)))) goto L_4200800;
    /* @4200732 constant */
    /* @4200736 cast */
    /* @4200740 load */
    /* @4200748 load */
    /* @4200756 constant */
    /* @4200760 add */
    /* @4200764 load */
    /* @4200772 constant */
    /* @4200776 add */
    /* @4200780 load */
    /* @4200788 call */
    GM_SITE(vm, 356, 4200788);
    v33 = GM_ADD(GM_READ(vm, 66, "x"), VAL(130));
    v34 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4200796 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v33, v34, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4200800: ;
    /* @4200800 load */
    /* @4200808 constant */
    /* @4200812 cmp */
    /* @4200816 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(19)))) goto L_4200888;
    /* @4200820 constant */
    /* @4200824 cast */
    /* @4200828 load */
    /* @4200836 load */
    /* @4200844 constant */
    /* @4200848 add */
    /* @4200852 load */
    /* @4200860 constant */
    /* @4200864 add */
    /* @4200868 load */
    /* @4200876 call */
    GM_SITE(vm, 356, 4200876);
    v35 = GM_ADD(GM_READ(vm, 66, "x"), VAL(138));
    v36 = GM_ADD(GM_READ(vm, 66, "y"), VAL(20));
    /* @4200884 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v35, v36, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4200888: ;
    /* @4200888 load */
    /* @4200896 constant */
    /* @4200900 cmp */
    /* @4200904 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(20)))) goto L_4200976;
    /* @4200908 constant */
    /* @4200912 cast */
    /* @4200916 load */
    /* @4200924 load */
    /* @4200932 constant */
    /* @4200936 add */
    /* @4200940 load */
    /* @4200948 constant */
    /* @4200952 add */
    /* @4200956 load */
    /* @4200964 call */
    GM_SITE(vm, 356, 4200964);
    v37 = GM_ADD(GM_READ(vm, 66, "x"), VAL(138));
    v38 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4200972 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v37, v38, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4200976: ;
    /* @4200976 b */
    goto L_4209596;
    L_4200980: ;
    /* @4200980 load */
    /* @4200988 constant */
    /* @4200992 cmp */
    /* @4200996 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4201020;
    /* @4201000 load */
    /* @4201008 constant */
    /* @4201012 cmp */
    /* @4201016 b */
    p4201024_0 = NUMBOOL(GM_READ(vm, -1, "showpart") == VAL(1));
    goto L_4201024;
    L_4201020: ;
    /* @4201020 constant */
    p4201024_0 = VAL(0);
    L_4201024: ;
    /* @4201024 bf */
    if (!TRUTH(p4201024_0)) goto L_4202704;
    /* @4201028 load */
    /* @4201036 constant */
    /* @4201040 cmp */
    /* @4201044 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(2)))) goto L_4201116;
    /* @4201048 constant */
    /* @4201052 cast */
    /* @4201056 load */
    /* @4201064 load */
    /* @4201072 constant */
    /* @4201076 add */
    /* @4201080 load */
    /* @4201088 constant */
    /* @4201092 add */
    /* @4201096 load */
    /* @4201104 call */
    GM_SITE(vm, 356, 4201104);
    v39 = GM_ADD(GM_READ(vm, 66, "x"), VAL(85));
    v40 = GM_ADD(GM_READ(vm, 66, "y"), VAL(25));
    /* @4201112 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v39, v40, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4201116: ;
    /* @4201116 load */
    /* @4201124 constant */
    /* @4201128 cmp */
    /* @4201132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(3)))) goto L_4201204;
    /* @4201136 constant */
    /* @4201140 cast */
    /* @4201144 load */
    /* @4201152 load */
    /* @4201160 constant */
    /* @4201164 add */
    /* @4201168 load */
    /* @4201176 constant */
    /* @4201180 add */
    /* @4201184 load */
    /* @4201192 call */
    GM_SITE(vm, 356, 4201192);
    v41 = GM_ADD(GM_READ(vm, 66, "x"), VAL(100));
    v42 = GM_ADD(GM_READ(vm, 66, "y"), VAL(25));
    /* @4201200 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v41, v42, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4201204: ;
    /* @4201204 load */
    /* @4201212 constant */
    /* @4201216 cmp */
    /* @4201220 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(4)))) goto L_4201292;
    /* @4201224 constant */
    /* @4201228 cast */
    /* @4201232 load */
    /* @4201240 load */
    /* @4201248 constant */
    /* @4201252 add */
    /* @4201256 load */
    /* @4201264 constant */
    /* @4201268 add */
    /* @4201272 load */
    /* @4201280 call */
    GM_SITE(vm, 356, 4201280);
    v43 = GM_ADD(GM_READ(vm, 66, "x"), VAL(115));
    v44 = GM_ADD(GM_READ(vm, 66, "y"), VAL(25));
    /* @4201288 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v43, v44, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4201292: ;
    /* @4201292 load */
    /* @4201300 constant */
    /* @4201304 cmp */
    /* @4201308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(5)))) goto L_4201380;
    /* @4201312 constant */
    /* @4201316 cast */
    /* @4201320 load */
    /* @4201328 load */
    /* @4201336 constant */
    /* @4201340 add */
    /* @4201344 load */
    /* @4201352 constant */
    /* @4201356 add */
    /* @4201360 load */
    /* @4201368 call */
    GM_SITE(vm, 356, 4201368);
    v45 = GM_ADD(GM_READ(vm, 66, "x"), VAL(130));
    v46 = GM_ADD(GM_READ(vm, 66, "y"), VAL(25));
    /* @4201376 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v45, v46, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4201380: ;
    /* @4201380 load */
    /* @4201388 constant */
    /* @4201392 cmp */
    /* @4201396 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(6)))) goto L_4201468;
    /* @4201400 constant */
    /* @4201404 cast */
    /* @4201408 load */
    /* @4201416 load */
    /* @4201424 constant */
    /* @4201428 add */
    /* @4201432 load */
    /* @4201440 constant */
    /* @4201444 add */
    /* @4201448 load */
    /* @4201456 call */
    GM_SITE(vm, 356, 4201456);
    v47 = GM_ADD(GM_READ(vm, 66, "x"), VAL(145));
    v48 = GM_ADD(GM_READ(vm, 66, "y"), VAL(25));
    /* @4201464 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v47, v48, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4201468: ;
    /* @4201468 load */
    /* @4201476 constant */
    /* @4201480 cmp */
    /* @4201484 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(7)))) goto L_4201556;
    /* @4201488 constant */
    /* @4201492 cast */
    /* @4201496 load */
    /* @4201504 load */
    /* @4201512 constant */
    /* @4201516 add */
    /* @4201520 load */
    /* @4201528 constant */
    /* @4201532 add */
    /* @4201536 load */
    /* @4201544 call */
    GM_SITE(vm, 356, 4201544);
    v49 = GM_ADD(GM_READ(vm, 66, "x"), VAL(160));
    v50 = GM_ADD(GM_READ(vm, 66, "y"), VAL(25));
    /* @4201552 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v49, v50, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4201556: ;
    /* @4201556 load */
    /* @4201564 constant */
    /* @4201568 cmp */
    /* @4201572 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(8)))) goto L_4201644;
    /* @4201576 constant */
    /* @4201580 cast */
    /* @4201584 load */
    /* @4201592 load */
    /* @4201600 constant */
    /* @4201604 add */
    /* @4201608 load */
    /* @4201616 constant */
    /* @4201620 add */
    /* @4201624 load */
    /* @4201632 call */
    GM_SITE(vm, 356, 4201632);
    v51 = GM_ADD(GM_READ(vm, 66, "x"), VAL(175));
    v52 = GM_ADD(GM_READ(vm, 66, "y"), VAL(25));
    /* @4201640 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v51, v52, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4201644: ;
    /* @4201644 load */
    /* @4201652 constant */
    /* @4201656 cmp */
    /* @4201660 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(9)))) goto L_4201732;
    /* @4201664 constant */
    /* @4201668 cast */
    /* @4201672 load */
    /* @4201680 load */
    /* @4201688 constant */
    /* @4201692 add */
    /* @4201696 load */
    /* @4201704 constant */
    /* @4201708 add */
    /* @4201712 load */
    /* @4201720 call */
    GM_SITE(vm, 356, 4201720);
    v53 = GM_ADD(GM_READ(vm, 66, "x"), VAL(40));
    v54 = GM_ADD(GM_READ(vm, 66, "y"), VAL(25));
    /* @4201728 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v53, v54, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4201732: ;
    /* @4201732 load */
    /* @4201740 constant */
    /* @4201744 cmp */
    /* @4201748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(10)))) goto L_4201820;
    /* @4201752 constant */
    /* @4201756 cast */
    /* @4201760 load */
    /* @4201768 load */
    /* @4201776 constant */
    /* @4201780 add */
    /* @4201784 load */
    /* @4201792 constant */
    /* @4201796 add */
    /* @4201800 load */
    /* @4201808 call */
    GM_SITE(vm, 356, 4201808);
    v55 = GM_ADD(GM_READ(vm, 66, "x"), VAL(48));
    v56 = GM_ADD(GM_READ(vm, 66, "y"), VAL(25));
    /* @4201816 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v55, v56, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4201820: ;
    /* @4201820 load */
    /* @4201828 constant */
    /* @4201832 cmp */
    /* @4201836 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(11)))) goto L_4201908;
    /* @4201840 constant */
    /* @4201844 cast */
    /* @4201848 load */
    /* @4201856 load */
    /* @4201864 constant */
    /* @4201868 add */
    /* @4201872 load */
    /* @4201880 constant */
    /* @4201884 add */
    /* @4201888 load */
    /* @4201896 call */
    GM_SITE(vm, 356, 4201896);
    v57 = GM_ADD(GM_READ(vm, 66, "x"), VAL(56));
    v58 = GM_ADD(GM_READ(vm, 66, "y"), VAL(25));
    /* @4201904 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v57, v58, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4201908: ;
    /* @4201908 load */
    /* @4201916 constant */
    /* @4201920 cmp */
    /* @4201924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(12)))) goto L_4201996;
    /* @4201928 constant */
    /* @4201932 cast */
    /* @4201936 load */
    /* @4201944 load */
    /* @4201952 constant */
    /* @4201956 add */
    /* @4201960 load */
    /* @4201968 constant */
    /* @4201972 add */
    /* @4201976 load */
    /* @4201984 call */
    GM_SITE(vm, 356, 4201984);
    v59 = GM_ADD(GM_READ(vm, 66, "x"), VAL(64));
    v60 = GM_ADD(GM_READ(vm, 66, "y"), VAL(25));
    /* @4201992 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v59, v60, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4201996: ;
    /* @4201996 load */
    /* @4202004 constant */
    /* @4202008 cmp */
    /* @4202012 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(13)))) goto L_4202084;
    /* @4202016 constant */
    /* @4202020 cast */
    /* @4202024 load */
    /* @4202032 load */
    /* @4202040 constant */
    /* @4202044 add */
    /* @4202048 load */
    /* @4202056 constant */
    /* @4202060 add */
    /* @4202064 load */
    /* @4202072 call */
    GM_SITE(vm, 356, 4202072);
    v61 = GM_ADD(GM_READ(vm, 66, "x"), VAL(72));
    v62 = GM_ADD(GM_READ(vm, 66, "y"), VAL(25));
    /* @4202080 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v61, v62, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4202084: ;
    /* @4202084 load */
    /* @4202092 constant */
    /* @4202096 cmp */
    /* @4202100 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(14)))) goto L_4202172;
    /* @4202104 constant */
    /* @4202108 cast */
    /* @4202112 load */
    /* @4202120 load */
    /* @4202128 constant */
    /* @4202132 add */
    /* @4202136 load */
    /* @4202144 constant */
    /* @4202148 add */
    /* @4202152 load */
    /* @4202160 call */
    GM_SITE(vm, 356, 4202160);
    v63 = GM_ADD(GM_READ(vm, 66, "x"), VAL(80));
    v64 = GM_ADD(GM_READ(vm, 66, "y"), VAL(25));
    /* @4202168 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v63, v64, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4202172: ;
    /* @4202172 load */
    /* @4202180 constant */
    /* @4202184 cmp */
    /* @4202188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(15)))) goto L_4202260;
    /* @4202192 constant */
    /* @4202196 cast */
    /* @4202200 load */
    /* @4202208 load */
    /* @4202216 constant */
    /* @4202220 add */
    /* @4202224 load */
    /* @4202232 constant */
    /* @4202236 add */
    /* @4202240 load */
    /* @4202248 call */
    GM_SITE(vm, 356, 4202248);
    v65 = GM_ADD(GM_READ(vm, 66, "x"), VAL(88));
    v66 = GM_ADD(GM_READ(vm, 66, "y"), VAL(25));
    /* @4202256 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v65, v66, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4202260: ;
    /* @4202260 load */
    /* @4202268 constant */
    /* @4202272 cmp */
    /* @4202276 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(16)))) goto L_4202348;
    /* @4202280 constant */
    /* @4202284 cast */
    /* @4202288 load */
    /* @4202296 load */
    /* @4202304 constant */
    /* @4202308 add */
    /* @4202312 load */
    /* @4202320 constant */
    /* @4202324 add */
    /* @4202328 load */
    /* @4202336 call */
    GM_SITE(vm, 356, 4202336);
    v67 = GM_ADD(GM_READ(vm, 66, "x"), VAL(96));
    v68 = GM_ADD(GM_READ(vm, 66, "y"), VAL(25));
    /* @4202344 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v67, v68, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4202348: ;
    /* @4202348 load */
    /* @4202356 constant */
    /* @4202360 cmp */
    /* @4202364 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(17)))) goto L_4202436;
    /* @4202368 constant */
    /* @4202372 cast */
    /* @4202376 load */
    /* @4202384 load */
    /* @4202392 constant */
    /* @4202396 add */
    /* @4202400 load */
    /* @4202408 constant */
    /* @4202412 add */
    /* @4202416 load */
    /* @4202424 call */
    GM_SITE(vm, 356, 4202424);
    v69 = GM_ADD(GM_READ(vm, 66, "x"), VAL(104));
    v70 = GM_ADD(GM_READ(vm, 66, "y"), VAL(25));
    /* @4202432 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v69, v70, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4202436: ;
    /* @4202436 load */
    /* @4202444 constant */
    /* @4202448 cmp */
    /* @4202452 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(18)))) goto L_4202524;
    /* @4202456 constant */
    /* @4202460 cast */
    /* @4202464 load */
    /* @4202472 load */
    /* @4202480 constant */
    /* @4202484 add */
    /* @4202488 load */
    /* @4202496 constant */
    /* @4202500 add */
    /* @4202504 load */
    /* @4202512 call */
    GM_SITE(vm, 356, 4202512);
    v71 = GM_ADD(GM_READ(vm, 66, "x"), VAL(112));
    v72 = GM_ADD(GM_READ(vm, 66, "y"), VAL(25));
    /* @4202520 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v71, v72, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4202524: ;
    /* @4202524 load */
    /* @4202532 constant */
    /* @4202536 cmp */
    /* @4202540 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(19)))) goto L_4202612;
    /* @4202544 constant */
    /* @4202548 cast */
    /* @4202552 load */
    /* @4202560 load */
    /* @4202568 constant */
    /* @4202572 add */
    /* @4202576 load */
    /* @4202584 constant */
    /* @4202588 add */
    /* @4202592 load */
    /* @4202600 call */
    GM_SITE(vm, 356, 4202600);
    v73 = GM_ADD(GM_READ(vm, 66, "x"), VAL(120));
    v74 = GM_ADD(GM_READ(vm, 66, "y"), VAL(20));
    /* @4202608 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v73, v74, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4202612: ;
    /* @4202612 load */
    /* @4202620 constant */
    /* @4202624 cmp */
    /* @4202628 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(20)))) goto L_4202700;
    /* @4202632 constant */
    /* @4202636 cast */
    /* @4202640 load */
    /* @4202648 load */
    /* @4202656 constant */
    /* @4202660 add */
    /* @4202664 load */
    /* @4202672 constant */
    /* @4202676 add */
    /* @4202680 load */
    /* @4202688 call */
    GM_SITE(vm, 356, 4202688);
    v75 = GM_ADD(GM_READ(vm, 66, "x"), VAL(120));
    v76 = GM_ADD(GM_READ(vm, 66, "y"), VAL(25));
    /* @4202696 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v75, v76, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4202700: ;
    /* @4202700 b */
    goto L_4209596;
    L_4202704: ;
    /* @4202704 load */
    /* @4202712 constant */
    /* @4202716 cmp */
    /* @4202720 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4202744;
    /* @4202724 load */
    /* @4202732 constant */
    /* @4202736 cmp */
    /* @4202740 b */
    p4202748_0 = NUMBOOL(GM_READ(vm, -1, "showpart") == VAL(1));
    goto L_4202748;
    L_4202744: ;
    /* @4202744 constant */
    p4202748_0 = VAL(0);
    L_4202748: ;
    /* @4202748 bf */
    if (!TRUTH(p4202748_0)) goto L_4204428;
    /* @4202752 load */
    /* @4202760 constant */
    /* @4202764 cmp */
    /* @4202768 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(2)))) goto L_4202840;
    /* @4202772 constant */
    /* @4202776 cast */
    /* @4202780 load */
    /* @4202788 load */
    /* @4202796 constant */
    /* @4202800 add */
    /* @4202804 load */
    /* @4202812 constant */
    /* @4202816 add */
    /* @4202820 load */
    /* @4202828 call */
    GM_SITE(vm, 356, 4202828);
    v77 = GM_ADD(GM_READ(vm, 66, "x"), VAL(103));
    v78 = GM_ADD(GM_READ(vm, 66, "y"), VAL(38));
    /* @4202836 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v77, v78, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4202840: ;
    /* @4202840 load */
    /* @4202848 constant */
    /* @4202852 cmp */
    /* @4202856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(3)))) goto L_4202928;
    /* @4202860 constant */
    /* @4202864 cast */
    /* @4202868 load */
    /* @4202876 load */
    /* @4202884 constant */
    /* @4202888 add */
    /* @4202892 load */
    /* @4202900 constant */
    /* @4202904 add */
    /* @4202908 load */
    /* @4202916 call */
    GM_SITE(vm, 356, 4202916);
    v79 = GM_ADD(GM_READ(vm, 66, "x"), VAL(118));
    v80 = GM_ADD(GM_READ(vm, 66, "y"), VAL(38));
    /* @4202924 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v79, v80, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4202928: ;
    /* @4202928 load */
    /* @4202936 constant */
    /* @4202940 cmp */
    /* @4202944 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(4)))) goto L_4203016;
    /* @4202948 constant */
    /* @4202952 cast */
    /* @4202956 load */
    /* @4202964 load */
    /* @4202972 constant */
    /* @4202976 add */
    /* @4202980 load */
    /* @4202988 constant */
    /* @4202992 add */
    /* @4202996 load */
    /* @4203004 call */
    GM_SITE(vm, 356, 4203004);
    v81 = GM_ADD(GM_READ(vm, 66, "x"), VAL(133));
    v82 = GM_ADD(GM_READ(vm, 66, "y"), VAL(38));
    /* @4203012 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v81, v82, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4203016: ;
    /* @4203016 load */
    /* @4203024 constant */
    /* @4203028 cmp */
    /* @4203032 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(5)))) goto L_4203104;
    /* @4203036 constant */
    /* @4203040 cast */
    /* @4203044 load */
    /* @4203052 load */
    /* @4203060 constant */
    /* @4203064 add */
    /* @4203068 load */
    /* @4203076 constant */
    /* @4203080 add */
    /* @4203084 load */
    /* @4203092 call */
    GM_SITE(vm, 356, 4203092);
    v83 = GM_ADD(GM_READ(vm, 66, "x"), VAL(148));
    v84 = GM_ADD(GM_READ(vm, 66, "y"), VAL(38));
    /* @4203100 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v83, v84, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4203104: ;
    /* @4203104 load */
    /* @4203112 constant */
    /* @4203116 cmp */
    /* @4203120 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(6)))) goto L_4203192;
    /* @4203124 constant */
    /* @4203128 cast */
    /* @4203132 load */
    /* @4203140 load */
    /* @4203148 constant */
    /* @4203152 add */
    /* @4203156 load */
    /* @4203164 constant */
    /* @4203168 add */
    /* @4203172 load */
    /* @4203180 call */
    GM_SITE(vm, 356, 4203180);
    v85 = GM_ADD(GM_READ(vm, 66, "x"), VAL(163));
    v86 = GM_ADD(GM_READ(vm, 66, "y"), VAL(38));
    /* @4203188 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v85, v86, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4203192: ;
    /* @4203192 load */
    /* @4203200 constant */
    /* @4203204 cmp */
    /* @4203208 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(7)))) goto L_4203280;
    /* @4203212 constant */
    /* @4203216 cast */
    /* @4203220 load */
    /* @4203228 load */
    /* @4203236 constant */
    /* @4203240 add */
    /* @4203244 load */
    /* @4203252 constant */
    /* @4203256 add */
    /* @4203260 load */
    /* @4203268 call */
    GM_SITE(vm, 356, 4203268);
    v87 = GM_ADD(GM_READ(vm, 66, "x"), VAL(178));
    v88 = GM_ADD(GM_READ(vm, 66, "y"), VAL(38));
    /* @4203276 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v87, v88, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4203280: ;
    /* @4203280 load */
    /* @4203288 constant */
    /* @4203292 cmp */
    /* @4203296 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(8)))) goto L_4203368;
    /* @4203300 constant */
    /* @4203304 cast */
    /* @4203308 load */
    /* @4203316 load */
    /* @4203324 constant */
    /* @4203328 add */
    /* @4203332 load */
    /* @4203340 constant */
    /* @4203344 add */
    /* @4203348 load */
    /* @4203356 call */
    GM_SITE(vm, 356, 4203356);
    v89 = GM_ADD(GM_READ(vm, 66, "x"), VAL(193));
    v90 = GM_ADD(GM_READ(vm, 66, "y"), VAL(38));
    /* @4203364 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v89, v90, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4203368: ;
    /* @4203368 load */
    /* @4203376 constant */
    /* @4203380 cmp */
    /* @4203384 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(9)))) goto L_4203456;
    /* @4203388 constant */
    /* @4203392 cast */
    /* @4203396 load */
    /* @4203404 load */
    /* @4203412 constant */
    /* @4203416 add */
    /* @4203420 load */
    /* @4203428 constant */
    /* @4203432 add */
    /* @4203436 load */
    /* @4203444 call */
    GM_SITE(vm, 356, 4203444);
    v91 = GM_ADD(GM_READ(vm, 66, "x"), VAL(58));
    v92 = GM_ADD(GM_READ(vm, 66, "y"), VAL(33));
    /* @4203452 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v91, v92, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4203456: ;
    /* @4203456 load */
    /* @4203464 constant */
    /* @4203468 cmp */
    /* @4203472 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(10)))) goto L_4203544;
    /* @4203476 constant */
    /* @4203480 cast */
    /* @4203484 load */
    /* @4203492 load */
    /* @4203500 constant */
    /* @4203504 add */
    /* @4203508 load */
    /* @4203516 constant */
    /* @4203520 add */
    /* @4203524 load */
    /* @4203532 call */
    GM_SITE(vm, 356, 4203532);
    v93 = GM_ADD(GM_READ(vm, 66, "x"), VAL(66));
    v94 = GM_ADD(GM_READ(vm, 66, "y"), VAL(33));
    /* @4203540 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v93, v94, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4203544: ;
    /* @4203544 load */
    /* @4203552 constant */
    /* @4203556 cmp */
    /* @4203560 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(11)))) goto L_4203632;
    /* @4203564 constant */
    /* @4203568 cast */
    /* @4203572 load */
    /* @4203580 load */
    /* @4203588 constant */
    /* @4203592 add */
    /* @4203596 load */
    /* @4203604 constant */
    /* @4203608 add */
    /* @4203612 load */
    /* @4203620 call */
    GM_SITE(vm, 356, 4203620);
    v95 = GM_ADD(GM_READ(vm, 66, "x"), VAL(74));
    v96 = GM_ADD(GM_READ(vm, 66, "y"), VAL(33));
    /* @4203628 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v95, v96, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4203632: ;
    /* @4203632 load */
    /* @4203640 constant */
    /* @4203644 cmp */
    /* @4203648 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(12)))) goto L_4203720;
    /* @4203652 constant */
    /* @4203656 cast */
    /* @4203660 load */
    /* @4203668 load */
    /* @4203676 constant */
    /* @4203680 add */
    /* @4203684 load */
    /* @4203692 constant */
    /* @4203696 add */
    /* @4203700 load */
    /* @4203708 call */
    GM_SITE(vm, 356, 4203708);
    v97 = GM_ADD(GM_READ(vm, 66, "x"), VAL(82));
    v98 = GM_ADD(GM_READ(vm, 66, "y"), VAL(33));
    /* @4203716 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v97, v98, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4203720: ;
    /* @4203720 load */
    /* @4203728 constant */
    /* @4203732 cmp */
    /* @4203736 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(13)))) goto L_4203808;
    /* @4203740 constant */
    /* @4203744 cast */
    /* @4203748 load */
    /* @4203756 load */
    /* @4203764 constant */
    /* @4203768 add */
    /* @4203772 load */
    /* @4203780 constant */
    /* @4203784 add */
    /* @4203788 load */
    /* @4203796 call */
    GM_SITE(vm, 356, 4203796);
    v99 = GM_ADD(GM_READ(vm, 66, "x"), VAL(90));
    v100 = GM_ADD(GM_READ(vm, 66, "y"), VAL(33));
    /* @4203804 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v99, v100, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4203808: ;
    /* @4203808 load */
    /* @4203816 constant */
    /* @4203820 cmp */
    /* @4203824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(14)))) goto L_4203896;
    /* @4203828 constant */
    /* @4203832 cast */
    /* @4203836 load */
    /* @4203844 load */
    /* @4203852 constant */
    /* @4203856 add */
    /* @4203860 load */
    /* @4203868 constant */
    /* @4203872 add */
    /* @4203876 load */
    /* @4203884 call */
    GM_SITE(vm, 356, 4203884);
    v101 = GM_ADD(GM_READ(vm, 66, "x"), VAL(98));
    v102 = GM_ADD(GM_READ(vm, 66, "y"), VAL(33));
    /* @4203892 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v101, v102, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4203896: ;
    /* @4203896 load */
    /* @4203904 constant */
    /* @4203908 cmp */
    /* @4203912 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(15)))) goto L_4203984;
    /* @4203916 constant */
    /* @4203920 cast */
    /* @4203924 load */
    /* @4203932 load */
    /* @4203940 constant */
    /* @4203944 add */
    /* @4203948 load */
    /* @4203956 constant */
    /* @4203960 add */
    /* @4203964 load */
    /* @4203972 call */
    GM_SITE(vm, 356, 4203972);
    v103 = GM_ADD(GM_READ(vm, 66, "x"), VAL(106));
    v104 = GM_ADD(GM_READ(vm, 66, "y"), VAL(33));
    /* @4203980 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v103, v104, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4203984: ;
    /* @4203984 load */
    /* @4203992 constant */
    /* @4203996 cmp */
    /* @4204000 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(16)))) goto L_4204072;
    /* @4204004 constant */
    /* @4204008 cast */
    /* @4204012 load */
    /* @4204020 load */
    /* @4204028 constant */
    /* @4204032 add */
    /* @4204036 load */
    /* @4204044 constant */
    /* @4204048 add */
    /* @4204052 load */
    /* @4204060 call */
    GM_SITE(vm, 356, 4204060);
    v105 = GM_ADD(GM_READ(vm, 66, "x"), VAL(114));
    v106 = GM_ADD(GM_READ(vm, 66, "y"), VAL(33));
    /* @4204068 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v105, v106, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4204072: ;
    /* @4204072 load */
    /* @4204080 constant */
    /* @4204084 cmp */
    /* @4204088 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(17)))) goto L_4204160;
    /* @4204092 constant */
    /* @4204096 cast */
    /* @4204100 load */
    /* @4204108 load */
    /* @4204116 constant */
    /* @4204120 add */
    /* @4204124 load */
    /* @4204132 constant */
    /* @4204136 add */
    /* @4204140 load */
    /* @4204148 call */
    GM_SITE(vm, 356, 4204148);
    v107 = GM_ADD(GM_READ(vm, 66, "x"), VAL(122));
    v108 = GM_ADD(GM_READ(vm, 66, "y"), VAL(33));
    /* @4204156 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v107, v108, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4204160: ;
    /* @4204160 load */
    /* @4204168 constant */
    /* @4204172 cmp */
    /* @4204176 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(18)))) goto L_4204248;
    /* @4204180 constant */
    /* @4204184 cast */
    /* @4204188 load */
    /* @4204196 load */
    /* @4204204 constant */
    /* @4204208 add */
    /* @4204212 load */
    /* @4204220 constant */
    /* @4204224 add */
    /* @4204228 load */
    /* @4204236 call */
    GM_SITE(vm, 356, 4204236);
    v109 = GM_ADD(GM_READ(vm, 66, "x"), VAL(130));
    v110 = GM_ADD(GM_READ(vm, 66, "y"), VAL(33));
    /* @4204244 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v109, v110, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4204248: ;
    /* @4204248 load */
    /* @4204256 constant */
    /* @4204260 cmp */
    /* @4204264 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(19)))) goto L_4204336;
    /* @4204268 constant */
    /* @4204272 cast */
    /* @4204276 load */
    /* @4204284 load */
    /* @4204292 constant */
    /* @4204296 add */
    /* @4204300 load */
    /* @4204308 constant */
    /* @4204312 add */
    /* @4204316 load */
    /* @4204324 call */
    GM_SITE(vm, 356, 4204324);
    v111 = GM_ADD(GM_READ(vm, 66, "x"), VAL(138));
    v112 = GM_ADD(GM_READ(vm, 66, "y"), VAL(23));
    /* @4204332 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v111, v112, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4204336: ;
    /* @4204336 load */
    /* @4204344 constant */
    /* @4204348 cmp */
    /* @4204352 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(20)))) goto L_4204424;
    /* @4204356 constant */
    /* @4204360 cast */
    /* @4204364 load */
    /* @4204372 load */
    /* @4204380 constant */
    /* @4204384 add */
    /* @4204388 load */
    /* @4204396 constant */
    /* @4204400 add */
    /* @4204404 load */
    /* @4204412 call */
    GM_SITE(vm, 356, 4204412);
    v113 = GM_ADD(GM_READ(vm, 66, "x"), VAL(138));
    v114 = GM_ADD(GM_READ(vm, 66, "y"), VAL(33));
    /* @4204420 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v113, v114, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4204424: ;
    /* @4204424 b */
    goto L_4209596;
    L_4204428: ;
    /* @4204428 load */
    /* @4204436 constant */
    /* @4204440 cmp */
    /* @4204444 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4204468;
    /* @4204448 load */
    /* @4204456 constant */
    /* @4204460 cmp */
    /* @4204464 b */
    p4204472_0 = NUMBOOL(GM_READ(vm, -1, "showpart") == VAL(1));
    goto L_4204472;
    L_4204468: ;
    /* @4204468 constant */
    p4204472_0 = VAL(0);
    L_4204472: ;
    /* @4204472 bf */
    if (!TRUTH(p4204472_0)) goto L_4206152;
    /* @4204476 load */
    /* @4204484 constant */
    /* @4204488 cmp */
    /* @4204492 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(2)))) goto L_4204564;
    /* @4204496 constant */
    /* @4204500 cast */
    /* @4204504 load */
    /* @4204512 load */
    /* @4204520 constant */
    /* @4204524 add */
    /* @4204528 load */
    /* @4204536 constant */
    /* @4204540 add */
    /* @4204544 load */
    /* @4204552 call */
    GM_SITE(vm, 356, 4204552);
    v115 = GM_ADD(GM_READ(vm, 66, "x"), VAL(103));
    v116 = GM_ADD(GM_READ(vm, 66, "y"), VAL(38));
    /* @4204560 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v115, v116, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4204564: ;
    /* @4204564 load */
    /* @4204572 constant */
    /* @4204576 cmp */
    /* @4204580 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(3)))) goto L_4204652;
    /* @4204584 constant */
    /* @4204588 cast */
    /* @4204592 load */
    /* @4204600 load */
    /* @4204608 constant */
    /* @4204612 add */
    /* @4204616 load */
    /* @4204624 constant */
    /* @4204628 add */
    /* @4204632 load */
    /* @4204640 call */
    GM_SITE(vm, 356, 4204640);
    v117 = GM_ADD(GM_READ(vm, 66, "x"), VAL(118));
    v118 = GM_ADD(GM_READ(vm, 66, "y"), VAL(38));
    /* @4204648 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v117, v118, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4204652: ;
    /* @4204652 load */
    /* @4204660 constant */
    /* @4204664 cmp */
    /* @4204668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(4)))) goto L_4204740;
    /* @4204672 constant */
    /* @4204676 cast */
    /* @4204680 load */
    /* @4204688 load */
    /* @4204696 constant */
    /* @4204700 add */
    /* @4204704 load */
    /* @4204712 constant */
    /* @4204716 add */
    /* @4204720 load */
    /* @4204728 call */
    GM_SITE(vm, 356, 4204728);
    v119 = GM_ADD(GM_READ(vm, 66, "x"), VAL(133));
    v120 = GM_ADD(GM_READ(vm, 66, "y"), VAL(38));
    /* @4204736 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v119, v120, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4204740: ;
    /* @4204740 load */
    /* @4204748 constant */
    /* @4204752 cmp */
    /* @4204756 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(5)))) goto L_4204828;
    /* @4204760 constant */
    /* @4204764 cast */
    /* @4204768 load */
    /* @4204776 load */
    /* @4204784 constant */
    /* @4204788 add */
    /* @4204792 load */
    /* @4204800 constant */
    /* @4204804 add */
    /* @4204808 load */
    /* @4204816 call */
    GM_SITE(vm, 356, 4204816);
    v121 = GM_ADD(GM_READ(vm, 66, "x"), VAL(148));
    v122 = GM_ADD(GM_READ(vm, 66, "y"), VAL(38));
    /* @4204824 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v121, v122, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4204828: ;
    /* @4204828 load */
    /* @4204836 constant */
    /* @4204840 cmp */
    /* @4204844 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(6)))) goto L_4204916;
    /* @4204848 constant */
    /* @4204852 cast */
    /* @4204856 load */
    /* @4204864 load */
    /* @4204872 constant */
    /* @4204876 add */
    /* @4204880 load */
    /* @4204888 constant */
    /* @4204892 add */
    /* @4204896 load */
    /* @4204904 call */
    GM_SITE(vm, 356, 4204904);
    v123 = GM_ADD(GM_READ(vm, 66, "x"), VAL(163));
    v124 = GM_ADD(GM_READ(vm, 66, "y"), VAL(38));
    /* @4204912 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v123, v124, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4204916: ;
    /* @4204916 load */
    /* @4204924 constant */
    /* @4204928 cmp */
    /* @4204932 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(7)))) goto L_4205004;
    /* @4204936 constant */
    /* @4204940 cast */
    /* @4204944 load */
    /* @4204952 load */
    /* @4204960 constant */
    /* @4204964 add */
    /* @4204968 load */
    /* @4204976 constant */
    /* @4204980 add */
    /* @4204984 load */
    /* @4204992 call */
    GM_SITE(vm, 356, 4204992);
    v125 = GM_ADD(GM_READ(vm, 66, "x"), VAL(178));
    v126 = GM_ADD(GM_READ(vm, 66, "y"), VAL(38));
    /* @4205000 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v125, v126, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4205004: ;
    /* @4205004 load */
    /* @4205012 constant */
    /* @4205016 cmp */
    /* @4205020 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(8)))) goto L_4205092;
    /* @4205024 constant */
    /* @4205028 cast */
    /* @4205032 load */
    /* @4205040 load */
    /* @4205048 constant */
    /* @4205052 add */
    /* @4205056 load */
    /* @4205064 constant */
    /* @4205068 add */
    /* @4205072 load */
    /* @4205080 call */
    GM_SITE(vm, 356, 4205080);
    v127 = GM_ADD(GM_READ(vm, 66, "x"), VAL(193));
    v128 = GM_ADD(GM_READ(vm, 66, "y"), VAL(38));
    /* @4205088 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v127, v128, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4205092: ;
    /* @4205092 load */
    /* @4205100 constant */
    /* @4205104 cmp */
    /* @4205108 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(9)))) goto L_4205180;
    /* @4205112 constant */
    /* @4205116 cast */
    /* @4205120 load */
    /* @4205128 load */
    /* @4205136 constant */
    /* @4205140 add */
    /* @4205144 load */
    /* @4205152 constant */
    /* @4205156 add */
    /* @4205160 load */
    /* @4205168 call */
    GM_SITE(vm, 356, 4205168);
    v129 = GM_ADD(GM_READ(vm, 66, "x"), VAL(58));
    v130 = GM_ADD(GM_READ(vm, 66, "y"), VAL(33));
    /* @4205176 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v129, v130, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4205180: ;
    /* @4205180 load */
    /* @4205188 constant */
    /* @4205192 cmp */
    /* @4205196 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(10)))) goto L_4205268;
    /* @4205200 constant */
    /* @4205204 cast */
    /* @4205208 load */
    /* @4205216 load */
    /* @4205224 constant */
    /* @4205228 add */
    /* @4205232 load */
    /* @4205240 constant */
    /* @4205244 add */
    /* @4205248 load */
    /* @4205256 call */
    GM_SITE(vm, 356, 4205256);
    v131 = GM_ADD(GM_READ(vm, 66, "x"), VAL(66));
    v132 = GM_ADD(GM_READ(vm, 66, "y"), VAL(33));
    /* @4205264 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v131, v132, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4205268: ;
    /* @4205268 load */
    /* @4205276 constant */
    /* @4205280 cmp */
    /* @4205284 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(11)))) goto L_4205356;
    /* @4205288 constant */
    /* @4205292 cast */
    /* @4205296 load */
    /* @4205304 load */
    /* @4205312 constant */
    /* @4205316 add */
    /* @4205320 load */
    /* @4205328 constant */
    /* @4205332 add */
    /* @4205336 load */
    /* @4205344 call */
    GM_SITE(vm, 356, 4205344);
    v133 = GM_ADD(GM_READ(vm, 66, "x"), VAL(74));
    v134 = GM_ADD(GM_READ(vm, 66, "y"), VAL(33));
    /* @4205352 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v133, v134, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4205356: ;
    /* @4205356 load */
    /* @4205364 constant */
    /* @4205368 cmp */
    /* @4205372 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(12)))) goto L_4205444;
    /* @4205376 constant */
    /* @4205380 cast */
    /* @4205384 load */
    /* @4205392 load */
    /* @4205400 constant */
    /* @4205404 add */
    /* @4205408 load */
    /* @4205416 constant */
    /* @4205420 add */
    /* @4205424 load */
    /* @4205432 call */
    GM_SITE(vm, 356, 4205432);
    v135 = GM_ADD(GM_READ(vm, 66, "x"), VAL(82));
    v136 = GM_ADD(GM_READ(vm, 66, "y"), VAL(33));
    /* @4205440 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v135, v136, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4205444: ;
    /* @4205444 load */
    /* @4205452 constant */
    /* @4205456 cmp */
    /* @4205460 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(13)))) goto L_4205532;
    /* @4205464 constant */
    /* @4205468 cast */
    /* @4205472 load */
    /* @4205480 load */
    /* @4205488 constant */
    /* @4205492 add */
    /* @4205496 load */
    /* @4205504 constant */
    /* @4205508 add */
    /* @4205512 load */
    /* @4205520 call */
    GM_SITE(vm, 356, 4205520);
    v137 = GM_ADD(GM_READ(vm, 66, "x"), VAL(90));
    v138 = GM_ADD(GM_READ(vm, 66, "y"), VAL(33));
    /* @4205528 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v137, v138, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4205532: ;
    /* @4205532 load */
    /* @4205540 constant */
    /* @4205544 cmp */
    /* @4205548 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(14)))) goto L_4205620;
    /* @4205552 constant */
    /* @4205556 cast */
    /* @4205560 load */
    /* @4205568 load */
    /* @4205576 constant */
    /* @4205580 add */
    /* @4205584 load */
    /* @4205592 constant */
    /* @4205596 add */
    /* @4205600 load */
    /* @4205608 call */
    GM_SITE(vm, 356, 4205608);
    v139 = GM_ADD(GM_READ(vm, 66, "x"), VAL(98));
    v140 = GM_ADD(GM_READ(vm, 66, "y"), VAL(33));
    /* @4205616 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v139, v140, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4205620: ;
    /* @4205620 load */
    /* @4205628 constant */
    /* @4205632 cmp */
    /* @4205636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(15)))) goto L_4205708;
    /* @4205640 constant */
    /* @4205644 cast */
    /* @4205648 load */
    /* @4205656 load */
    /* @4205664 constant */
    /* @4205668 add */
    /* @4205672 load */
    /* @4205680 constant */
    /* @4205684 add */
    /* @4205688 load */
    /* @4205696 call */
    GM_SITE(vm, 356, 4205696);
    v141 = GM_ADD(GM_READ(vm, 66, "x"), VAL(106));
    v142 = GM_ADD(GM_READ(vm, 66, "y"), VAL(33));
    /* @4205704 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v141, v142, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4205708: ;
    /* @4205708 load */
    /* @4205716 constant */
    /* @4205720 cmp */
    /* @4205724 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(16)))) goto L_4205796;
    /* @4205728 constant */
    /* @4205732 cast */
    /* @4205736 load */
    /* @4205744 load */
    /* @4205752 constant */
    /* @4205756 add */
    /* @4205760 load */
    /* @4205768 constant */
    /* @4205772 add */
    /* @4205776 load */
    /* @4205784 call */
    GM_SITE(vm, 356, 4205784);
    v143 = GM_ADD(GM_READ(vm, 66, "x"), VAL(114));
    v144 = GM_ADD(GM_READ(vm, 66, "y"), VAL(33));
    /* @4205792 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v143, v144, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4205796: ;
    /* @4205796 load */
    /* @4205804 constant */
    /* @4205808 cmp */
    /* @4205812 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(17)))) goto L_4205884;
    /* @4205816 constant */
    /* @4205820 cast */
    /* @4205824 load */
    /* @4205832 load */
    /* @4205840 constant */
    /* @4205844 add */
    /* @4205848 load */
    /* @4205856 constant */
    /* @4205860 add */
    /* @4205864 load */
    /* @4205872 call */
    GM_SITE(vm, 356, 4205872);
    v145 = GM_ADD(GM_READ(vm, 66, "x"), VAL(122));
    v146 = GM_ADD(GM_READ(vm, 66, "y"), VAL(33));
    /* @4205880 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v145, v146, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4205884: ;
    /* @4205884 load */
    /* @4205892 constant */
    /* @4205896 cmp */
    /* @4205900 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(18)))) goto L_4205972;
    /* @4205904 constant */
    /* @4205908 cast */
    /* @4205912 load */
    /* @4205920 load */
    /* @4205928 constant */
    /* @4205932 add */
    /* @4205936 load */
    /* @4205944 constant */
    /* @4205948 add */
    /* @4205952 load */
    /* @4205960 call */
    GM_SITE(vm, 356, 4205960);
    v147 = GM_ADD(GM_READ(vm, 66, "x"), VAL(130));
    v148 = GM_ADD(GM_READ(vm, 66, "y"), VAL(33));
    /* @4205968 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v147, v148, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4205972: ;
    /* @4205972 load */
    /* @4205980 constant */
    /* @4205984 cmp */
    /* @4205988 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(19)))) goto L_4206060;
    /* @4205992 constant */
    /* @4205996 cast */
    /* @4206000 load */
    /* @4206008 load */
    /* @4206016 constant */
    /* @4206020 add */
    /* @4206024 load */
    /* @4206032 constant */
    /* @4206036 add */
    /* @4206040 load */
    /* @4206048 call */
    GM_SITE(vm, 356, 4206048);
    v149 = GM_ADD(GM_READ(vm, 66, "x"), VAL(138));
    v150 = GM_ADD(GM_READ(vm, 66, "y"), VAL(23));
    /* @4206056 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v149, v150, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4206060: ;
    /* @4206060 load */
    /* @4206068 constant */
    /* @4206072 cmp */
    /* @4206076 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(20)))) goto L_4206148;
    /* @4206080 constant */
    /* @4206084 cast */
    /* @4206088 load */
    /* @4206096 load */
    /* @4206104 constant */
    /* @4206108 add */
    /* @4206112 load */
    /* @4206120 constant */
    /* @4206124 add */
    /* @4206128 load */
    /* @4206136 call */
    GM_SITE(vm, 356, 4206136);
    v151 = GM_ADD(GM_READ(vm, 66, "x"), VAL(138));
    v152 = GM_ADD(GM_READ(vm, 66, "y"), VAL(33));
    /* @4206144 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v151, v152, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4206148: ;
    /* @4206148 b */
    goto L_4209596;
    L_4206152: ;
    /* @4206152 load */
    /* @4206160 constant */
    /* @4206164 cmp */
    /* @4206168 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4206192;
    /* @4206172 load */
    /* @4206180 constant */
    /* @4206184 cmp */
    /* @4206188 b */
    p4206196_0 = NUMBOOL(GM_READ(vm, -1, "showpart") == VAL(1));
    goto L_4206196;
    L_4206192: ;
    /* @4206192 constant */
    p4206196_0 = VAL(0);
    L_4206196: ;
    /* @4206196 bf */
    if (!TRUTH(p4206196_0)) goto L_4207876;
    /* @4206200 load */
    /* @4206208 constant */
    /* @4206212 cmp */
    /* @4206216 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(2)))) goto L_4206288;
    /* @4206220 constant */
    /* @4206224 cast */
    /* @4206228 load */
    /* @4206236 load */
    /* @4206244 constant */
    /* @4206248 add */
    /* @4206252 load */
    /* @4206260 constant */
    /* @4206264 add */
    /* @4206268 load */
    /* @4206276 call */
    GM_SITE(vm, 356, 4206276);
    v153 = GM_ADD(GM_READ(vm, 66, "x"), VAL(104));
    v154 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4206284 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v153, v154, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4206288: ;
    /* @4206288 load */
    /* @4206296 constant */
    /* @4206300 cmp */
    /* @4206304 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(3)))) goto L_4206376;
    /* @4206308 constant */
    /* @4206312 cast */
    /* @4206316 load */
    /* @4206324 load */
    /* @4206332 constant */
    /* @4206336 add */
    /* @4206340 load */
    /* @4206348 constant */
    /* @4206352 add */
    /* @4206356 load */
    /* @4206364 call */
    GM_SITE(vm, 356, 4206364);
    v155 = GM_ADD(GM_READ(vm, 66, "x"), VAL(119));
    v156 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4206372 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v155, v156, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4206376: ;
    /* @4206376 load */
    /* @4206384 constant */
    /* @4206388 cmp */
    /* @4206392 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(4)))) goto L_4206464;
    /* @4206396 constant */
    /* @4206400 cast */
    /* @4206404 load */
    /* @4206412 load */
    /* @4206420 constant */
    /* @4206424 add */
    /* @4206428 load */
    /* @4206436 constant */
    /* @4206440 add */
    /* @4206444 load */
    /* @4206452 call */
    GM_SITE(vm, 356, 4206452);
    v157 = GM_ADD(GM_READ(vm, 66, "x"), VAL(134));
    v158 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4206460 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v157, v158, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4206464: ;
    /* @4206464 load */
    /* @4206472 constant */
    /* @4206476 cmp */
    /* @4206480 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(5)))) goto L_4206552;
    /* @4206484 constant */
    /* @4206488 cast */
    /* @4206492 load */
    /* @4206500 load */
    /* @4206508 constant */
    /* @4206512 add */
    /* @4206516 load */
    /* @4206524 constant */
    /* @4206528 add */
    /* @4206532 load */
    /* @4206540 call */
    GM_SITE(vm, 356, 4206540);
    v159 = GM_ADD(GM_READ(vm, 66, "x"), VAL(149));
    v160 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4206548 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v159, v160, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4206552: ;
    /* @4206552 load */
    /* @4206560 constant */
    /* @4206564 cmp */
    /* @4206568 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(6)))) goto L_4206640;
    /* @4206572 constant */
    /* @4206576 cast */
    /* @4206580 load */
    /* @4206588 load */
    /* @4206596 constant */
    /* @4206600 add */
    /* @4206604 load */
    /* @4206612 constant */
    /* @4206616 add */
    /* @4206620 load */
    /* @4206628 call */
    GM_SITE(vm, 356, 4206628);
    v161 = GM_ADD(GM_READ(vm, 66, "x"), VAL(164));
    v162 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4206636 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v161, v162, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4206640: ;
    /* @4206640 load */
    /* @4206648 constant */
    /* @4206652 cmp */
    /* @4206656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(7)))) goto L_4206728;
    /* @4206660 constant */
    /* @4206664 cast */
    /* @4206668 load */
    /* @4206676 load */
    /* @4206684 constant */
    /* @4206688 add */
    /* @4206692 load */
    /* @4206700 constant */
    /* @4206704 add */
    /* @4206708 load */
    /* @4206716 call */
    GM_SITE(vm, 356, 4206716);
    v163 = GM_ADD(GM_READ(vm, 66, "x"), VAL(179));
    v164 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4206724 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v163, v164, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4206728: ;
    /* @4206728 load */
    /* @4206736 constant */
    /* @4206740 cmp */
    /* @4206744 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(8)))) goto L_4206816;
    /* @4206748 constant */
    /* @4206752 cast */
    /* @4206756 load */
    /* @4206764 load */
    /* @4206772 constant */
    /* @4206776 add */
    /* @4206780 load */
    /* @4206788 constant */
    /* @4206792 add */
    /* @4206796 load */
    /* @4206804 call */
    GM_SITE(vm, 356, 4206804);
    v165 = GM_ADD(GM_READ(vm, 66, "x"), VAL(194));
    v166 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4206812 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v165, v166, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4206816: ;
    /* @4206816 load */
    /* @4206824 constant */
    /* @4206828 cmp */
    /* @4206832 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(9)))) goto L_4206904;
    /* @4206836 constant */
    /* @4206840 cast */
    /* @4206844 load */
    /* @4206852 load */
    /* @4206860 constant */
    /* @4206864 add */
    /* @4206868 load */
    /* @4206876 constant */
    /* @4206880 add */
    /* @4206884 load */
    /* @4206892 call */
    GM_SITE(vm, 356, 4206892);
    v167 = GM_ADD(GM_READ(vm, 66, "x"), VAL(58));
    v168 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4206900 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v167, v168, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4206904: ;
    /* @4206904 load */
    /* @4206912 constant */
    /* @4206916 cmp */
    /* @4206920 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(10)))) goto L_4206992;
    /* @4206924 constant */
    /* @4206928 cast */
    /* @4206932 load */
    /* @4206940 load */
    /* @4206948 constant */
    /* @4206952 add */
    /* @4206956 load */
    /* @4206964 constant */
    /* @4206968 add */
    /* @4206972 load */
    /* @4206980 call */
    GM_SITE(vm, 356, 4206980);
    v169 = GM_ADD(GM_READ(vm, 66, "x"), VAL(66));
    v170 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4206988 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v169, v170, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4206992: ;
    /* @4206992 load */
    /* @4207000 constant */
    /* @4207004 cmp */
    /* @4207008 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(11)))) goto L_4207080;
    /* @4207012 constant */
    /* @4207016 cast */
    /* @4207020 load */
    /* @4207028 load */
    /* @4207036 constant */
    /* @4207040 add */
    /* @4207044 load */
    /* @4207052 constant */
    /* @4207056 add */
    /* @4207060 load */
    /* @4207068 call */
    GM_SITE(vm, 356, 4207068);
    v171 = GM_ADD(GM_READ(vm, 66, "x"), VAL(74));
    v172 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4207076 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v171, v172, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4207080: ;
    /* @4207080 load */
    /* @4207088 constant */
    /* @4207092 cmp */
    /* @4207096 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(12)))) goto L_4207168;
    /* @4207100 constant */
    /* @4207104 cast */
    /* @4207108 load */
    /* @4207116 load */
    /* @4207124 constant */
    /* @4207128 add */
    /* @4207132 load */
    /* @4207140 constant */
    /* @4207144 add */
    /* @4207148 load */
    /* @4207156 call */
    GM_SITE(vm, 356, 4207156);
    v173 = GM_ADD(GM_READ(vm, 66, "x"), VAL(82));
    v174 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4207164 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v173, v174, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4207168: ;
    /* @4207168 load */
    /* @4207176 constant */
    /* @4207180 cmp */
    /* @4207184 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(13)))) goto L_4207256;
    /* @4207188 constant */
    /* @4207192 cast */
    /* @4207196 load */
    /* @4207204 load */
    /* @4207212 constant */
    /* @4207216 add */
    /* @4207220 load */
    /* @4207228 constant */
    /* @4207232 add */
    /* @4207236 load */
    /* @4207244 call */
    GM_SITE(vm, 356, 4207244);
    v175 = GM_ADD(GM_READ(vm, 66, "x"), VAL(90));
    v176 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4207252 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v175, v176, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4207256: ;
    /* @4207256 load */
    /* @4207264 constant */
    /* @4207268 cmp */
    /* @4207272 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(14)))) goto L_4207344;
    /* @4207276 constant */
    /* @4207280 cast */
    /* @4207284 load */
    /* @4207292 load */
    /* @4207300 constant */
    /* @4207304 add */
    /* @4207308 load */
    /* @4207316 constant */
    /* @4207320 add */
    /* @4207324 load */
    /* @4207332 call */
    GM_SITE(vm, 356, 4207332);
    v177 = GM_ADD(GM_READ(vm, 66, "x"), VAL(98));
    v178 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4207340 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v177, v178, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4207344: ;
    /* @4207344 load */
    /* @4207352 constant */
    /* @4207356 cmp */
    /* @4207360 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(15)))) goto L_4207432;
    /* @4207364 constant */
    /* @4207368 cast */
    /* @4207372 load */
    /* @4207380 load */
    /* @4207388 constant */
    /* @4207392 add */
    /* @4207396 load */
    /* @4207404 constant */
    /* @4207408 add */
    /* @4207412 load */
    /* @4207420 call */
    GM_SITE(vm, 356, 4207420);
    v179 = GM_ADD(GM_READ(vm, 66, "x"), VAL(106));
    v180 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4207428 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v179, v180, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4207432: ;
    /* @4207432 load */
    /* @4207440 constant */
    /* @4207444 cmp */
    /* @4207448 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(16)))) goto L_4207520;
    /* @4207452 constant */
    /* @4207456 cast */
    /* @4207460 load */
    /* @4207468 load */
    /* @4207476 constant */
    /* @4207480 add */
    /* @4207484 load */
    /* @4207492 constant */
    /* @4207496 add */
    /* @4207500 load */
    /* @4207508 call */
    GM_SITE(vm, 356, 4207508);
    v181 = GM_ADD(GM_READ(vm, 66, "x"), VAL(114));
    v182 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4207516 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v181, v182, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4207520: ;
    /* @4207520 load */
    /* @4207528 constant */
    /* @4207532 cmp */
    /* @4207536 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(17)))) goto L_4207608;
    /* @4207540 constant */
    /* @4207544 cast */
    /* @4207548 load */
    /* @4207556 load */
    /* @4207564 constant */
    /* @4207568 add */
    /* @4207572 load */
    /* @4207580 constant */
    /* @4207584 add */
    /* @4207588 load */
    /* @4207596 call */
    GM_SITE(vm, 356, 4207596);
    v183 = GM_ADD(GM_READ(vm, 66, "x"), VAL(122));
    v184 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4207604 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v183, v184, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4207608: ;
    /* @4207608 load */
    /* @4207616 constant */
    /* @4207620 cmp */
    /* @4207624 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(18)))) goto L_4207696;
    /* @4207628 constant */
    /* @4207632 cast */
    /* @4207636 load */
    /* @4207644 load */
    /* @4207652 constant */
    /* @4207656 add */
    /* @4207660 load */
    /* @4207668 constant */
    /* @4207672 add */
    /* @4207676 load */
    /* @4207684 call */
    GM_SITE(vm, 356, 4207684);
    v185 = GM_ADD(GM_READ(vm, 66, "x"), VAL(130));
    v186 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4207692 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v185, v186, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4207696: ;
    /* @4207696 load */
    /* @4207704 constant */
    /* @4207708 cmp */
    /* @4207712 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(19)))) goto L_4207784;
    /* @4207716 constant */
    /* @4207720 cast */
    /* @4207724 load */
    /* @4207732 load */
    /* @4207740 constant */
    /* @4207744 add */
    /* @4207748 load */
    /* @4207756 constant */
    /* @4207760 add */
    /* @4207764 load */
    /* @4207772 call */
    GM_SITE(vm, 356, 4207772);
    v187 = GM_ADD(GM_READ(vm, 66, "x"), VAL(138));
    v188 = GM_ADD(GM_READ(vm, 66, "y"), VAL(20));
    /* @4207780 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v187, v188, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4207784: ;
    /* @4207784 load */
    /* @4207792 constant */
    /* @4207796 cmp */
    /* @4207800 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(20)))) goto L_4207872;
    /* @4207804 constant */
    /* @4207808 cast */
    /* @4207812 load */
    /* @4207820 load */
    /* @4207828 constant */
    /* @4207832 add */
    /* @4207836 load */
    /* @4207844 constant */
    /* @4207848 add */
    /* @4207852 load */
    /* @4207860 call */
    GM_SITE(vm, 356, 4207860);
    v189 = GM_ADD(GM_READ(vm, 66, "x"), VAL(138));
    v190 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4207868 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v189, v190, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4207872: ;
    /* @4207872 b */
    goto L_4209596;
    L_4207876: ;
    /* @4207876 load */
    /* @4207884 constant */
    /* @4207888 cmp */
    /* @4207892 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4207916;
    /* @4207896 load */
    /* @4207904 constant */
    /* @4207908 cmp */
    /* @4207912 b */
    p4207920_0 = NUMBOOL(GM_READ(vm, -1, "showpart") == VAL(1));
    goto L_4207920;
    L_4207916: ;
    /* @4207916 constant */
    p4207920_0 = VAL(0);
    L_4207920: ;
    /* @4207920 bf */
    if (!TRUTH(p4207920_0)) goto L_4209596;
    /* @4207924 load */
    /* @4207932 constant */
    /* @4207936 cmp */
    /* @4207940 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(2)))) goto L_4208012;
    /* @4207944 constant */
    /* @4207948 cast */
    /* @4207952 load */
    /* @4207960 load */
    /* @4207968 constant */
    /* @4207972 add */
    /* @4207976 load */
    /* @4207984 constant */
    /* @4207988 add */
    /* @4207992 load */
    /* @4208000 call */
    GM_SITE(vm, 356, 4208000);
    v191 = GM_ADD(GM_READ(vm, 66, "x"), VAL(104));
    v192 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4208008 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v191, v192, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4208012: ;
    /* @4208012 load */
    /* @4208020 constant */
    /* @4208024 cmp */
    /* @4208028 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(3)))) goto L_4208100;
    /* @4208032 constant */
    /* @4208036 cast */
    /* @4208040 load */
    /* @4208048 load */
    /* @4208056 constant */
    /* @4208060 add */
    /* @4208064 load */
    /* @4208072 constant */
    /* @4208076 add */
    /* @4208080 load */
    /* @4208088 call */
    GM_SITE(vm, 356, 4208088);
    v193 = GM_ADD(GM_READ(vm, 66, "x"), VAL(119));
    v194 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4208096 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v193, v194, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4208100: ;
    /* @4208100 load */
    /* @4208108 constant */
    /* @4208112 cmp */
    /* @4208116 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(4)))) goto L_4208188;
    /* @4208120 constant */
    /* @4208124 cast */
    /* @4208128 load */
    /* @4208136 load */
    /* @4208144 constant */
    /* @4208148 add */
    /* @4208152 load */
    /* @4208160 constant */
    /* @4208164 add */
    /* @4208168 load */
    /* @4208176 call */
    GM_SITE(vm, 356, 4208176);
    v195 = GM_ADD(GM_READ(vm, 66, "x"), VAL(134));
    v196 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4208184 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v195, v196, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4208188: ;
    /* @4208188 load */
    /* @4208196 constant */
    /* @4208200 cmp */
    /* @4208204 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(5)))) goto L_4208276;
    /* @4208208 constant */
    /* @4208212 cast */
    /* @4208216 load */
    /* @4208224 load */
    /* @4208232 constant */
    /* @4208236 add */
    /* @4208240 load */
    /* @4208248 constant */
    /* @4208252 add */
    /* @4208256 load */
    /* @4208264 call */
    GM_SITE(vm, 356, 4208264);
    v197 = GM_ADD(GM_READ(vm, 66, "x"), VAL(149));
    v198 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4208272 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v197, v198, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4208276: ;
    /* @4208276 load */
    /* @4208284 constant */
    /* @4208288 cmp */
    /* @4208292 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(6)))) goto L_4208364;
    /* @4208296 constant */
    /* @4208300 cast */
    /* @4208304 load */
    /* @4208312 load */
    /* @4208320 constant */
    /* @4208324 add */
    /* @4208328 load */
    /* @4208336 constant */
    /* @4208340 add */
    /* @4208344 load */
    /* @4208352 call */
    GM_SITE(vm, 356, 4208352);
    v199 = GM_ADD(GM_READ(vm, 66, "x"), VAL(164));
    v200 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4208360 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v199, v200, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4208364: ;
    /* @4208364 load */
    /* @4208372 constant */
    /* @4208376 cmp */
    /* @4208380 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(7)))) goto L_4208452;
    /* @4208384 constant */
    /* @4208388 cast */
    /* @4208392 load */
    /* @4208400 load */
    /* @4208408 constant */
    /* @4208412 add */
    /* @4208416 load */
    /* @4208424 constant */
    /* @4208428 add */
    /* @4208432 load */
    /* @4208440 call */
    GM_SITE(vm, 356, 4208440);
    v201 = GM_ADD(GM_READ(vm, 66, "x"), VAL(179));
    v202 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4208448 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v201, v202, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4208452: ;
    /* @4208452 load */
    /* @4208460 constant */
    /* @4208464 cmp */
    /* @4208468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(8)))) goto L_4208540;
    /* @4208472 constant */
    /* @4208476 cast */
    /* @4208480 load */
    /* @4208488 load */
    /* @4208496 constant */
    /* @4208500 add */
    /* @4208504 load */
    /* @4208512 constant */
    /* @4208516 add */
    /* @4208520 load */
    /* @4208528 call */
    GM_SITE(vm, 356, 4208528);
    v203 = GM_ADD(GM_READ(vm, 66, "x"), VAL(194));
    v204 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4208536 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v203, v204, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4208540: ;
    /* @4208540 load */
    /* @4208548 constant */
    /* @4208552 cmp */
    /* @4208556 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(9)))) goto L_4208628;
    /* @4208560 constant */
    /* @4208564 cast */
    /* @4208568 load */
    /* @4208576 load */
    /* @4208584 constant */
    /* @4208588 add */
    /* @4208592 load */
    /* @4208600 constant */
    /* @4208604 add */
    /* @4208608 load */
    /* @4208616 call */
    GM_SITE(vm, 356, 4208616);
    v205 = GM_ADD(GM_READ(vm, 66, "x"), VAL(58));
    v206 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4208624 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v205, v206, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4208628: ;
    /* @4208628 load */
    /* @4208636 constant */
    /* @4208640 cmp */
    /* @4208644 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(10)))) goto L_4208716;
    /* @4208648 constant */
    /* @4208652 cast */
    /* @4208656 load */
    /* @4208664 load */
    /* @4208672 constant */
    /* @4208676 add */
    /* @4208680 load */
    /* @4208688 constant */
    /* @4208692 add */
    /* @4208696 load */
    /* @4208704 call */
    GM_SITE(vm, 356, 4208704);
    v207 = GM_ADD(GM_READ(vm, 66, "x"), VAL(66));
    v208 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4208712 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v207, v208, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4208716: ;
    /* @4208716 load */
    /* @4208724 constant */
    /* @4208728 cmp */
    /* @4208732 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(11)))) goto L_4208804;
    /* @4208736 constant */
    /* @4208740 cast */
    /* @4208744 load */
    /* @4208752 load */
    /* @4208760 constant */
    /* @4208764 add */
    /* @4208768 load */
    /* @4208776 constant */
    /* @4208780 add */
    /* @4208784 load */
    /* @4208792 call */
    GM_SITE(vm, 356, 4208792);
    v209 = GM_ADD(GM_READ(vm, 66, "x"), VAL(74));
    v210 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4208800 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v209, v210, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4208804: ;
    /* @4208804 load */
    /* @4208812 constant */
    /* @4208816 cmp */
    /* @4208820 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(12)))) goto L_4208892;
    /* @4208824 constant */
    /* @4208828 cast */
    /* @4208832 load */
    /* @4208840 load */
    /* @4208848 constant */
    /* @4208852 add */
    /* @4208856 load */
    /* @4208864 constant */
    /* @4208868 add */
    /* @4208872 load */
    /* @4208880 call */
    GM_SITE(vm, 356, 4208880);
    v211 = GM_ADD(GM_READ(vm, 66, "x"), VAL(82));
    v212 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4208888 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v211, v212, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4208892: ;
    /* @4208892 load */
    /* @4208900 constant */
    /* @4208904 cmp */
    /* @4208908 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(13)))) goto L_4208980;
    /* @4208912 constant */
    /* @4208916 cast */
    /* @4208920 load */
    /* @4208928 load */
    /* @4208936 constant */
    /* @4208940 add */
    /* @4208944 load */
    /* @4208952 constant */
    /* @4208956 add */
    /* @4208960 load */
    /* @4208968 call */
    GM_SITE(vm, 356, 4208968);
    v213 = GM_ADD(GM_READ(vm, 66, "x"), VAL(90));
    v214 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4208976 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v213, v214, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4208980: ;
    /* @4208980 load */
    /* @4208988 constant */
    /* @4208992 cmp */
    /* @4208996 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(14)))) goto L_4209068;
    /* @4209000 constant */
    /* @4209004 cast */
    /* @4209008 load */
    /* @4209016 load */
    /* @4209024 constant */
    /* @4209028 add */
    /* @4209032 load */
    /* @4209040 constant */
    /* @4209044 add */
    /* @4209048 load */
    /* @4209056 call */
    GM_SITE(vm, 356, 4209056);
    v215 = GM_ADD(GM_READ(vm, 66, "x"), VAL(98));
    v216 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4209064 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v215, v216, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4209068: ;
    /* @4209068 load */
    /* @4209076 constant */
    /* @4209080 cmp */
    /* @4209084 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(15)))) goto L_4209156;
    /* @4209088 constant */
    /* @4209092 cast */
    /* @4209096 load */
    /* @4209104 load */
    /* @4209112 constant */
    /* @4209116 add */
    /* @4209120 load */
    /* @4209128 constant */
    /* @4209132 add */
    /* @4209136 load */
    /* @4209144 call */
    GM_SITE(vm, 356, 4209144);
    v217 = GM_ADD(GM_READ(vm, 66, "x"), VAL(106));
    v218 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4209152 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v217, v218, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4209156: ;
    /* @4209156 load */
    /* @4209164 constant */
    /* @4209168 cmp */
    /* @4209172 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(16)))) goto L_4209244;
    /* @4209176 constant */
    /* @4209180 cast */
    /* @4209184 load */
    /* @4209192 load */
    /* @4209200 constant */
    /* @4209204 add */
    /* @4209208 load */
    /* @4209216 constant */
    /* @4209220 add */
    /* @4209224 load */
    /* @4209232 call */
    GM_SITE(vm, 356, 4209232);
    v219 = GM_ADD(GM_READ(vm, 66, "x"), VAL(114));
    v220 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4209240 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v219, v220, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4209244: ;
    /* @4209244 load */
    /* @4209252 constant */
    /* @4209256 cmp */
    /* @4209260 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(17)))) goto L_4209332;
    /* @4209264 constant */
    /* @4209268 cast */
    /* @4209272 load */
    /* @4209280 load */
    /* @4209288 constant */
    /* @4209292 add */
    /* @4209296 load */
    /* @4209304 constant */
    /* @4209308 add */
    /* @4209312 load */
    /* @4209320 call */
    GM_SITE(vm, 356, 4209320);
    v221 = GM_ADD(GM_READ(vm, 66, "x"), VAL(122));
    v222 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4209328 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v221, v222, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4209332: ;
    /* @4209332 load */
    /* @4209340 constant */
    /* @4209344 cmp */
    /* @4209348 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(18)))) goto L_4209420;
    /* @4209352 constant */
    /* @4209356 cast */
    /* @4209360 load */
    /* @4209368 load */
    /* @4209376 constant */
    /* @4209380 add */
    /* @4209384 load */
    /* @4209392 constant */
    /* @4209396 add */
    /* @4209400 load */
    /* @4209408 call */
    GM_SITE(vm, 356, 4209408);
    v223 = GM_ADD(GM_READ(vm, 66, "x"), VAL(130));
    v224 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4209416 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v223, v224, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4209420: ;
    /* @4209420 load */
    /* @4209428 constant */
    /* @4209432 cmp */
    /* @4209436 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(19)))) goto L_4209508;
    /* @4209440 constant */
    /* @4209444 cast */
    /* @4209448 load */
    /* @4209456 load */
    /* @4209464 constant */
    /* @4209468 add */
    /* @4209472 load */
    /* @4209480 constant */
    /* @4209484 add */
    /* @4209488 load */
    /* @4209496 call */
    GM_SITE(vm, 356, 4209496);
    v225 = GM_ADD(GM_READ(vm, 66, "x"), VAL(138));
    v226 = GM_ADD(GM_READ(vm, 66, "y"), VAL(20));
    /* @4209504 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v225, v226, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4209508: ;
    /* @4209508 load */
    /* @4209516 constant */
    /* @4209520 cmp */
    /* @4209524 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(20)))) goto L_4209596;
    /* @4209528 constant */
    /* @4209532 cast */
    /* @4209536 load */
    /* @4209544 load */
    /* @4209552 constant */
    /* @4209556 add */
    /* @4209560 load */
    /* @4209568 constant */
    /* @4209572 add */
    /* @4209576 load */
    /* @4209584 call */
    GM_SITE(vm, 356, 4209584);
    v227 = GM_ADD(GM_READ(vm, 66, "x"), VAL(138));
    v228 = GM_ADD(GM_READ(vm, 66, "y"), VAL(30));
    /* @4209592 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System2"), v227, v228, GM_READ(vm, -5, "Particle2"), VAL(3)));
    L_4209596: ;
    return;
}
