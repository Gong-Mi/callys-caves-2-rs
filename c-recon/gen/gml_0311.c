/* generated from CODE 311 (gml_Object_obj_sword_Step_0), source start 4163844, end 4187368. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0311(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    Val p4164308_0;
    Val v6;
    Val v7;
    Val p4164612_0;
    Val v8;
    Val v9;
    Val p4164916_0;
    Val v10;
    Val v11;
    Val p4165220_0;
    Val v12;
    Val v13;
    Val p4165524_0;
    Val v14;
    Val v15;
    Val p4165828_0;
    Val v16;
    Val v17;
    Val p4166080_0;
    Val v18;
    Val v19;
    Val p4166384_0;
    Val v20;
    Val v21;
    Val p4166688_0;
    Val v22;
    Val v23;
    Val p4166992_0;
    Val v24;
    Val v25;
    Val p4167296_0;
    Val v26;
    Val v27;
    Val p4167600_0;
    Val v28;
    Val v29;
    Val p4167904_0;
    Val v30;
    Val v31;
    Val p4168208_0;
    Val v32;
    Val v33;
    Val p4168512_0;
    Val v34;
    Val v35;
    Val p4168816_0;
    Val v36;
    Val v37;
    Val p4169068_0;
    Val v38;
    Val v39;
    Val p4169320_0;
    Val v40;
    Val v41;
    Val p4169572_0;
    Val v42;
    Val v43;
    Val p4169824_0;
    Val v44;
    Val v45;
    Val p4170100_0;
    Val v46;
    Val v47;
    Val p4170404_0;
    Val v48;
    Val v49;
    Val p4170708_0;
    Val v50;
    Val v51;
    Val p4171012_0;
    Val v52;
    Val v53;
    Val p4171316_0;
    Val v54;
    Val v55;
    Val p4171620_0;
    Val v56;
    Val v57;
    Val p4171872_0;
    Val v58;
    Val v59;
    Val p4172176_0;
    Val v60;
    Val v61;
    Val p4172480_0;
    Val v62;
    Val v63;
    Val p4172784_0;
    Val v64;
    Val v65;
    Val p4173088_0;
    Val v66;
    Val v67;
    Val p4173392_0;
    Val v68;
    Val v69;
    Val p4173696_0;
    Val v70;
    Val v71;
    Val p4174000_0;
    Val v72;
    Val v73;
    Val p4174304_0;
    Val v74;
    Val v75;
    Val p4174608_0;
    Val v76;
    Val v77;
    Val p4174860_0;
    Val v78;
    Val v79;
    Val p4175112_0;
    Val v80;
    Val v81;
    Val p4175364_0;
    Val v82;
    Val v83;
    Val p4175616_0;
    Val v84;
    Val v85;
    Val p4175892_0;
    Val v86;
    Val v87;
    Val p4176196_0;
    Val v88;
    Val v89;
    Val p4176500_0;
    Val v90;
    Val v91;
    Val p4176804_0;
    Val v92;
    Val v93;
    Val p4177108_0;
    Val v94;
    Val v95;
    Val p4177412_0;
    Val v96;
    Val v97;
    Val p4177664_0;
    Val v98;
    Val v99;
    Val p4177968_0;
    Val v100;
    Val v101;
    Val p4178272_0;
    Val v102;
    Val v103;
    Val p4178576_0;
    Val v104;
    Val v105;
    Val p4178880_0;
    Val v106;
    Val v107;
    Val p4179184_0;
    Val v108;
    Val v109;
    Val p4179488_0;
    Val v110;
    Val v111;
    Val p4179792_0;
    Val v112;
    Val v113;
    Val p4180096_0;
    Val v114;
    Val v115;
    Val p4180400_0;
    Val v116;
    Val v117;
    Val p4180652_0;
    Val v118;
    Val v119;
    Val p4180904_0;
    Val v120;
    Val v121;
    Val p4181156_0;
    Val v122;
    Val v123;
    Val p4181408_0;
    Val v124;
    Val v125;
    Val p4181684_0;
    Val v126;
    Val v127;
    Val p4181988_0;
    Val v128;
    Val v129;
    Val p4182292_0;
    Val v130;
    Val v131;
    Val p4182596_0;
    Val v132;
    Val v133;
    Val p4182900_0;
    Val v134;
    Val v135;
    Val p4183204_0;
    Val v136;
    Val v137;
    Val p4183456_0;
    Val v138;
    Val v139;
    Val p4183760_0;
    Val v140;
    Val v141;
    Val p4184064_0;
    Val v142;
    Val v143;
    Val p4184368_0;
    Val v144;
    Val v145;
    Val p4184672_0;
    Val v146;
    Val v147;
    Val p4184976_0;
    Val v148;
    Val v149;
    Val p4185280_0;
    Val v150;
    Val v151;
    Val p4185584_0;
    Val v152;
    Val v153;
    Val p4185888_0;
    Val v154;
    Val v155;
    Val p4186192_0;
    Val v156;
    Val v157;
    Val p4186444_0;
    Val v158;
    Val v159;
    Val p4186696_0;
    Val v160;
    Val v161;
    Val p4186948_0;
    Val v162;
    Val v163;
    Val p4187200_0;
    Val v164;
    /* @4163844 load */
    /* @4163852 constant */
    /* @4163856 cmp */
    /* @4163860 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "sword") == VAL(0)))) goto L_4163876;
    /* @4163864 constant */
    /* @4163868 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(45));
    L_4163876: ;
    /* @4163876 load */
    /* @4163884 constant */
    /* @4163888 cmp */
    /* @4163892 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "sword") == VAL(1)))) goto L_4163908;
    /* @4163896 constant */
    /* @4163900 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(46));
    L_4163908: ;
    /* @4163908 load */
    /* @4163916 constant */
    /* @4163920 cmp */
    /* @4163924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "sword") == VAL(2)))) goto L_4163940;
    /* @4163928 constant */
    /* @4163932 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(47));
    L_4163940: ;
    /* @4163940 load */
    /* @4163948 constant */
    /* @4163952 cmp */
    /* @4163956 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "sword") == VAL(3)))) goto L_4163972;
    /* @4163960 constant */
    /* @4163964 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(48));
    L_4163972: ;
    /* @4163972 load */
    /* @4163980 constant */
    /* @4163984 cmp */
    /* @4163988 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(0)))) goto L_4164064;
    /* @4163992 load */
    /* @4164000 constant */
    /* @4164004 add */
    /* @4164008 store */
    v1 = GM_ADD(GM_READ(vm, 0, "x"), VAL(5));
    GM_WRITE(vm, -1, "x", v1);
    /* @4164016 load */
    /* @4164024 constant */
    /* @4164028 add */
    /* @4164032 store */
    v2 = GM_ADD(GM_READ(vm, 0, "y"), VAL(6));
    GM_WRITE(vm, -1, "y", v2);
    /* @4164040 load */
    /* @4164048 constant */
    /* @4164052 sub */
    /* @4164056 store */
    GM_WRITE(vm, -1, "image_angle", (GM_READ(vm, -1, "image_angle") - VAL(25)));
    L_4164064: ;
    /* @4164064 load */
    /* @4164072 constant */
    /* @4164076 cmp */
    /* @4164080 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(1)))) goto L_4164156;
    /* @4164084 load */
    /* @4164092 constant */
    /* @4164096 sub */
    /* @4164100 store */
    GM_WRITE(vm, -1, "x", (GM_READ(vm, 0, "x") - VAL(5)));
    /* @4164108 load */
    /* @4164116 constant */
    /* @4164120 add */
    /* @4164124 store */
    v3 = GM_ADD(GM_READ(vm, 0, "y"), VAL(6));
    GM_WRITE(vm, -1, "y", v3);
    /* @4164132 load */
    /* @4164140 constant */
    /* @4164144 add */
    /* @4164148 store */
    v4 = GM_ADD(GM_READ(vm, -1, "image_angle"), VAL(25));
    GM_WRITE(vm, -1, "image_angle", v4);
    L_4164156: ;
    /* @4164156 constant */
    /* @4164160 constant */
    /* @4164164 load */
    /* @4164172 constant */
    /* @4164176 cmp */
    /* @4164180 bf */
    if (!TRUTH(NUMBOOL(GM_READ_ARR(vm, VAL(-1), "alarm", VAL(0)) <= VAL(0)))) goto L_4164204;
    /* @4164184 constant */
    /* @4164188 constant */
    /* @4164192 constant */
    /* @4164196 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(7));
    L_4164204: ;
    /* @4164204 load */
    /* @4164212 constant */
    /* @4164216 cmp */
    /* @4164220 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "sword") == VAL(0)))) goto L_4169996;
    /* @4164224 constant */
    /* @4164228 cast */
    /* @4164232 load */
    /* @4164240 load */
    /* @4164248 call */
    GM_SITE(vm, 311, 4164248);
    /* @4164256 store */
    v5 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(15));
    GM_WRITE(vm, -1, "hitknife", v5);
    /* @4164264 load */
    /* @4164272 constant */
    /* @4164276 cmp */
    /* @4164280 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitknife") != VAL(-4)))) goto L_4164304;
    /* @4164284 load */
    /* @4164292 constant */
    /* @4164296 cmp */
    /* @4164300 b */
    p4164308_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4164308;
    L_4164304: ;
    /* @4164304 constant */
    p4164308_0 = VAL(0);
    L_4164308: ;
    /* @4164308 bf */
    if (!TRUTH(p4164308_0)) goto L_4164528;
    /* @4164312 constant */
    /* @4164316 load */
    /* @4164324 cast */
    /* @4164328 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "flashing", VAL(1));
    /* @4164336 load */
    /* @4164344 cast */
    /* @4164348 dup */
    /* @4164352 load */
    /* @4164360 constant */
    /* @4164364 sub */
    /* @4164368 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife") - VAL(1)));
    /* @4164376 constant */
    /* @4164380 cast */
    /* @4164384 load */
    /* @4164392 cast */
    /* @4164396 load */
    /* @4164404 load */
    /* @4164412 cast */
    /* @4164416 load */
    /* @4164424 call */
    GM_SITE(vm, 311, 4164424);
    /* @4164432 store */
    v6 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v6);
    /* @4164440 constant */
    /* @4164444 load */
    /* @4164452 cast */
    /* @4164456 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(1));
    /* @4164464 constant */
    /* @4164468 load */
    /* @4164476 cast */
    /* @4164480 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "swordstunned", VAL(1));
    /* @4164488 constant */
    /* @4164492 load */
    /* @4164500 cast */
    /* @4164504 constant */
    /* @4164508 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "alarm", VAL(5), VAL(30));
    /* @4164516 constant */
    /* @4164520 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4164528: ;
    /* @4164528 constant */
    /* @4164532 cast */
    /* @4164536 load */
    /* @4164544 load */
    /* @4164552 call */
    GM_SITE(vm, 311, 4164552);
    /* @4164560 store */
    v7 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(24));
    GM_WRITE(vm, -1, "hitghost", v7);
    /* @4164568 load */
    /* @4164576 constant */
    /* @4164580 cmp */
    /* @4164584 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitghost") != VAL(-4)))) goto L_4164608;
    /* @4164588 load */
    /* @4164596 constant */
    /* @4164600 cmp */
    /* @4164604 b */
    p4164612_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4164612;
    L_4164608: ;
    /* @4164608 constant */
    p4164612_0 = VAL(0);
    L_4164612: ;
    /* @4164612 bf */
    if (!TRUTH(p4164612_0)) goto L_4164832;
    /* @4164616 constant */
    /* @4164620 load */
    /* @4164628 cast */
    /* @4164632 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "flashing", VAL(1));
    /* @4164640 load */
    /* @4164648 cast */
    /* @4164652 dup */
    /* @4164656 load */
    /* @4164664 constant */
    /* @4164668 sub */
    /* @4164672 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "hpghost", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "hpghost") - VAL(1)));
    /* @4164680 constant */
    /* @4164684 cast */
    /* @4164688 load */
    /* @4164696 cast */
    /* @4164700 load */
    /* @4164708 load */
    /* @4164716 cast */
    /* @4164720 load */
    /* @4164728 call */
    GM_SITE(vm, 311, 4164728);
    /* @4164736 store */
    v8 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v8);
    /* @4164744 constant */
    /* @4164748 load */
    /* @4164756 cast */
    /* @4164760 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(1));
    /* @4164768 constant */
    /* @4164772 load */
    /* @4164780 cast */
    /* @4164784 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "swordstunned", VAL(1));
    /* @4164792 constant */
    /* @4164796 load */
    /* @4164804 cast */
    /* @4164808 constant */
    /* @4164812 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "alarm", VAL(5), VAL(30));
    /* @4164820 constant */
    /* @4164824 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4164832: ;
    /* @4164832 constant */
    /* @4164836 cast */
    /* @4164840 load */
    /* @4164848 load */
    /* @4164856 call */
    GM_SITE(vm, 311, 4164856);
    /* @4164864 store */
    v9 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(23));
    GM_WRITE(vm, -1, "hitwolf", v9);
    /* @4164872 load */
    /* @4164880 constant */
    /* @4164884 cmp */
    /* @4164888 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitwolf") != VAL(-4)))) goto L_4164912;
    /* @4164892 load */
    /* @4164900 constant */
    /* @4164904 cmp */
    /* @4164908 b */
    p4164916_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4164916;
    L_4164912: ;
    /* @4164912 constant */
    p4164916_0 = VAL(0);
    L_4164916: ;
    /* @4164916 bf */
    if (!TRUTH(p4164916_0)) goto L_4165136;
    /* @4164920 constant */
    /* @4164924 load */
    /* @4164932 cast */
    /* @4164936 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "flashing", VAL(1));
    /* @4164944 load */
    /* @4164952 cast */
    /* @4164956 dup */
    /* @4164960 load */
    /* @4164968 constant */
    /* @4164972 sub */
    /* @4164976 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf") - VAL(1)));
    /* @4164984 constant */
    /* @4164988 cast */
    /* @4164992 load */
    /* @4165000 cast */
    /* @4165004 load */
    /* @4165012 load */
    /* @4165020 cast */
    /* @4165024 load */
    /* @4165032 call */
    GM_SITE(vm, 311, 4165032);
    /* @4165040 store */
    v10 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v10);
    /* @4165048 constant */
    /* @4165052 load */
    /* @4165060 cast */
    /* @4165064 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(1));
    /* @4165072 constant */
    /* @4165076 load */
    /* @4165084 cast */
    /* @4165088 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "swordstunned", VAL(1));
    /* @4165096 constant */
    /* @4165100 load */
    /* @4165108 cast */
    /* @4165112 constant */
    /* @4165116 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "alarm", VAL(5), VAL(30));
    /* @4165124 constant */
    /* @4165128 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4165136: ;
    /* @4165136 constant */
    /* @4165140 cast */
    /* @4165144 load */
    /* @4165152 load */
    /* @4165160 call */
    GM_SITE(vm, 311, 4165160);
    /* @4165168 store */
    v11 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(14));
    GM_WRITE(vm, -1, "hit", v11);
    /* @4165176 load */
    /* @4165184 constant */
    /* @4165188 cmp */
    /* @4165192 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit") != VAL(-4)))) goto L_4165216;
    /* @4165196 load */
    /* @4165204 constant */
    /* @4165208 cmp */
    /* @4165212 b */
    p4165220_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4165220;
    L_4165216: ;
    /* @4165216 constant */
    p4165220_0 = VAL(0);
    L_4165220: ;
    /* @4165220 bf */
    if (!TRUTH(p4165220_0)) goto L_4165440;
    /* @4165224 constant */
    /* @4165228 load */
    /* @4165236 cast */
    /* @4165240 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "flashing", VAL(1));
    /* @4165248 load */
    /* @4165256 cast */
    /* @4165260 dup */
    /* @4165264 load */
    /* @4165272 constant */
    /* @4165276 sub */
    /* @4165280 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp") - VAL(1)));
    /* @4165288 constant */
    /* @4165292 cast */
    /* @4165296 load */
    /* @4165304 cast */
    /* @4165308 load */
    /* @4165316 load */
    /* @4165324 cast */
    /* @4165328 load */
    /* @4165336 call */
    GM_SITE(vm, 311, 4165336);
    /* @4165344 store */
    v12 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v12);
    /* @4165352 constant */
    /* @4165356 load */
    /* @4165364 cast */
    /* @4165368 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(1));
    /* @4165376 constant */
    /* @4165380 load */
    /* @4165388 cast */
    /* @4165392 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "swordstunned", VAL(1));
    /* @4165400 constant */
    /* @4165404 load */
    /* @4165412 cast */
    /* @4165416 constant */
    /* @4165420 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit")), "alarm", VAL(5), VAL(30));
    /* @4165428 constant */
    /* @4165432 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4165440: ;
    /* @4165440 constant */
    /* @4165444 cast */
    /* @4165448 load */
    /* @4165456 load */
    /* @4165464 call */
    GM_SITE(vm, 311, 4165464);
    /* @4165472 store */
    v13 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(22));
    GM_WRITE(vm, -1, "hit2", v13);
    /* @4165480 load */
    /* @4165488 constant */
    /* @4165492 cmp */
    /* @4165496 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit2") != VAL(-4)))) goto L_4165520;
    /* @4165500 load */
    /* @4165508 constant */
    /* @4165512 cmp */
    /* @4165516 b */
    p4165524_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4165524;
    L_4165520: ;
    /* @4165520 constant */
    p4165524_0 = VAL(0);
    L_4165524: ;
    /* @4165524 bf */
    if (!TRUTH(p4165524_0)) goto L_4165744;
    /* @4165528 constant */
    /* @4165532 load */
    /* @4165540 cast */
    /* @4165544 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "flashing", VAL(1));
    /* @4165552 load */
    /* @4165560 cast */
    /* @4165564 dup */
    /* @4165568 load */
    /* @4165576 constant */
    /* @4165580 sub */
    /* @4165584 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo") - VAL(1)));
    /* @4165592 constant */
    /* @4165596 cast */
    /* @4165600 load */
    /* @4165608 cast */
    /* @4165612 load */
    /* @4165620 load */
    /* @4165628 cast */
    /* @4165632 load */
    /* @4165640 call */
    GM_SITE(vm, 311, 4165640);
    /* @4165648 store */
    v14 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit2")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit2")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v14);
    /* @4165656 constant */
    /* @4165660 load */
    /* @4165668 cast */
    /* @4165672 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(1));
    /* @4165680 constant */
    /* @4165684 load */
    /* @4165692 cast */
    /* @4165696 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "swordstunned", VAL(1));
    /* @4165704 constant */
    /* @4165708 load */
    /* @4165716 cast */
    /* @4165720 constant */
    /* @4165724 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit2")), "alarm", VAL(5), VAL(30));
    /* @4165732 constant */
    /* @4165736 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4165744: ;
    /* @4165744 constant */
    /* @4165748 cast */
    /* @4165752 load */
    /* @4165760 load */
    /* @4165768 call */
    GM_SITE(vm, 311, 4165768);
    /* @4165776 store */
    v15 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(25));
    GM_WRITE(vm, -1, "hittrex", v15);
    /* @4165784 load */
    /* @4165792 constant */
    /* @4165796 cmp */
    /* @4165800 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hittrex") != VAL(-4)))) goto L_4165824;
    /* @4165804 load */
    /* @4165812 constant */
    /* @4165816 cmp */
    /* @4165820 b */
    p4165828_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4165828;
    L_4165824: ;
    /* @4165824 constant */
    p4165828_0 = VAL(0);
    L_4165828: ;
    /* @4165828 bf */
    if (!TRUTH(p4165828_0)) goto L_4165996;
    /* @4165832 constant */
    /* @4165836 load */
    /* @4165844 cast */
    /* @4165848 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "flashing", VAL(1));
    /* @4165856 load */
    /* @4165864 cast */
    /* @4165868 dup */
    /* @4165872 load */
    /* @4165880 constant */
    /* @4165884 sub */
    /* @4165888 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex") - VAL(1)));
    /* @4165896 constant */
    /* @4165900 cast */
    /* @4165904 load */
    /* @4165912 cast */
    /* @4165916 load */
    /* @4165924 load */
    /* @4165932 cast */
    /* @4165936 load */
    /* @4165944 call */
    GM_SITE(vm, 311, 4165944);
    /* @4165952 store */
    v16 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v16);
    /* @4165960 constant */
    /* @4165964 load */
    /* @4165972 cast */
    /* @4165976 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(1));
    /* @4165984 constant */
    /* @4165988 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4165996: ;
    /* @4165996 constant */
    /* @4166000 cast */
    /* @4166004 load */
    /* @4166012 load */
    /* @4166020 call */
    GM_SITE(vm, 311, 4166020);
    /* @4166028 store */
    v17 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(31));
    GM_WRITE(vm, -1, "hit4", v17);
    /* @4166036 load */
    /* @4166044 constant */
    /* @4166048 cmp */
    /* @4166052 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit4") != VAL(-4)))) goto L_4166076;
    /* @4166056 load */
    /* @4166064 constant */
    /* @4166068 cmp */
    /* @4166072 b */
    p4166080_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4166080;
    L_4166076: ;
    /* @4166076 constant */
    p4166080_0 = VAL(0);
    L_4166080: ;
    /* @4166080 bf */
    if (!TRUTH(p4166080_0)) goto L_4166300;
    /* @4166084 constant */
    /* @4166088 load */
    /* @4166096 cast */
    /* @4166100 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "flashing", VAL(1));
    /* @4166108 load */
    /* @4166116 cast */
    /* @4166120 dup */
    /* @4166124 load */
    /* @4166132 constant */
    /* @4166136 sub */
    /* @4166140 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour") - VAL(1)));
    /* @4166148 constant */
    /* @4166152 cast */
    /* @4166156 load */
    /* @4166164 cast */
    /* @4166168 load */
    /* @4166176 load */
    /* @4166184 cast */
    /* @4166188 load */
    /* @4166196 call */
    GM_SITE(vm, 311, 4166196);
    /* @4166204 store */
    v18 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit4")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit4")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v18);
    /* @4166212 constant */
    /* @4166216 load */
    /* @4166224 cast */
    /* @4166228 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(1));
    /* @4166236 constant */
    /* @4166240 load */
    /* @4166248 cast */
    /* @4166252 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "swordstunned", VAL(1));
    /* @4166260 constant */
    /* @4166264 load */
    /* @4166272 cast */
    /* @4166276 constant */
    /* @4166280 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit4")), "alarm", VAL(5), VAL(30));
    /* @4166288 constant */
    /* @4166292 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4166300: ;
    /* @4166300 constant */
    /* @4166304 cast */
    /* @4166308 load */
    /* @4166316 load */
    /* @4166324 call */
    GM_SITE(vm, 311, 4166324);
    /* @4166332 store */
    v19 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(32));
    GM_WRITE(vm, -1, "hit5", v19);
    /* @4166340 load */
    /* @4166348 constant */
    /* @4166352 cmp */
    /* @4166356 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit5") != VAL(-4)))) goto L_4166380;
    /* @4166360 load */
    /* @4166368 constant */
    /* @4166372 cmp */
    /* @4166376 b */
    p4166384_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4166384;
    L_4166380: ;
    /* @4166380 constant */
    p4166384_0 = VAL(0);
    L_4166384: ;
    /* @4166384 bf */
    if (!TRUTH(p4166384_0)) goto L_4166604;
    /* @4166388 constant */
    /* @4166392 load */
    /* @4166400 cast */
    /* @4166404 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "flashing", VAL(1));
    /* @4166412 load */
    /* @4166420 cast */
    /* @4166424 dup */
    /* @4166428 load */
    /* @4166436 constant */
    /* @4166440 sub */
    /* @4166444 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime") - VAL(1)));
    /* @4166452 constant */
    /* @4166456 cast */
    /* @4166460 load */
    /* @4166468 cast */
    /* @4166472 load */
    /* @4166480 load */
    /* @4166488 cast */
    /* @4166492 load */
    /* @4166500 call */
    GM_SITE(vm, 311, 4166500);
    /* @4166508 store */
    v20 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit5")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit5")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v20);
    /* @4166516 constant */
    /* @4166520 load */
    /* @4166528 cast */
    /* @4166532 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(1));
    /* @4166540 constant */
    /* @4166544 load */
    /* @4166552 cast */
    /* @4166556 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "swordstunned", VAL(1));
    /* @4166564 constant */
    /* @4166568 load */
    /* @4166576 cast */
    /* @4166580 constant */
    /* @4166584 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit5")), "alarm", VAL(5), VAL(30));
    /* @4166592 constant */
    /* @4166596 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4166604: ;
    /* @4166604 constant */
    /* @4166608 cast */
    /* @4166612 load */
    /* @4166620 load */
    /* @4166628 call */
    GM_SITE(vm, 311, 4166628);
    /* @4166636 store */
    v21 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(16));
    GM_WRITE(vm, -1, "hit8", v21);
    /* @4166644 load */
    /* @4166652 constant */
    /* @4166656 cmp */
    /* @4166660 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit8") != VAL(-4)))) goto L_4166684;
    /* @4166664 load */
    /* @4166672 constant */
    /* @4166676 cmp */
    /* @4166680 b */
    p4166688_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4166688;
    L_4166684: ;
    /* @4166684 constant */
    p4166688_0 = VAL(0);
    L_4166688: ;
    /* @4166688 bf */
    if (!TRUTH(p4166688_0)) goto L_4166908;
    /* @4166692 constant */
    /* @4166696 load */
    /* @4166704 cast */
    /* @4166708 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "flashing", VAL(1));
    /* @4166716 load */
    /* @4166724 cast */
    /* @4166728 dup */
    /* @4166732 load */
    /* @4166740 constant */
    /* @4166744 sub */
    /* @4166748 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1") - VAL(1)));
    /* @4166756 constant */
    /* @4166760 cast */
    /* @4166764 load */
    /* @4166772 cast */
    /* @4166776 load */
    /* @4166784 load */
    /* @4166792 cast */
    /* @4166796 load */
    /* @4166804 call */
    GM_SITE(vm, 311, 4166804);
    /* @4166812 store */
    v22 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit8")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit8")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v22);
    /* @4166820 constant */
    /* @4166824 load */
    /* @4166832 cast */
    /* @4166836 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(1));
    /* @4166844 constant */
    /* @4166848 load */
    /* @4166856 cast */
    /* @4166860 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "swordstunned", VAL(1));
    /* @4166868 constant */
    /* @4166872 load */
    /* @4166880 cast */
    /* @4166884 constant */
    /* @4166888 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit8")), "alarm", VAL(5), VAL(30));
    /* @4166896 constant */
    /* @4166900 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4166908: ;
    /* @4166908 constant */
    /* @4166912 cast */
    /* @4166916 load */
    /* @4166924 load */
    /* @4166932 call */
    GM_SITE(vm, 311, 4166932);
    /* @4166940 store */
    v23 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(20));
    GM_WRITE(vm, -1, "hit9", v23);
    /* @4166948 load */
    /* @4166956 constant */
    /* @4166960 cmp */
    /* @4166964 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit9") != VAL(-4)))) goto L_4166988;
    /* @4166968 load */
    /* @4166976 constant */
    /* @4166980 cmp */
    /* @4166984 b */
    p4166992_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4166992;
    L_4166988: ;
    /* @4166988 constant */
    p4166992_0 = VAL(0);
    L_4166992: ;
    /* @4166992 bf */
    if (!TRUTH(p4166992_0)) goto L_4167212;
    /* @4166996 constant */
    /* @4167000 load */
    /* @4167008 cast */
    /* @4167012 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "flashing", VAL(1));
    /* @4167020 load */
    /* @4167028 cast */
    /* @4167032 dup */
    /* @4167036 load */
    /* @4167044 constant */
    /* @4167048 sub */
    /* @4167052 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2") - VAL(1)));
    /* @4167060 constant */
    /* @4167064 cast */
    /* @4167068 load */
    /* @4167076 cast */
    /* @4167080 load */
    /* @4167088 load */
    /* @4167096 cast */
    /* @4167100 load */
    /* @4167108 call */
    GM_SITE(vm, 311, 4167108);
    /* @4167116 store */
    v24 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit9")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit9")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v24);
    /* @4167124 constant */
    /* @4167128 load */
    /* @4167136 cast */
    /* @4167140 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(1));
    /* @4167148 constant */
    /* @4167152 load */
    /* @4167160 cast */
    /* @4167164 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "swordstunned", VAL(1));
    /* @4167172 constant */
    /* @4167176 load */
    /* @4167184 cast */
    /* @4167188 constant */
    /* @4167192 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit9")), "alarm", VAL(5), VAL(30));
    /* @4167200 constant */
    /* @4167204 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4167212: ;
    /* @4167212 constant */
    /* @4167216 cast */
    /* @4167220 load */
    /* @4167228 load */
    /* @4167236 call */
    GM_SITE(vm, 311, 4167236);
    /* @4167244 store */
    v25 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(33));
    GM_WRITE(vm, -1, "hit10", v25);
    /* @4167252 load */
    /* @4167260 constant */
    /* @4167264 cmp */
    /* @4167268 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit10") != VAL(-4)))) goto L_4167292;
    /* @4167272 load */
    /* @4167280 constant */
    /* @4167284 cmp */
    /* @4167288 b */
    p4167296_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4167296;
    L_4167292: ;
    /* @4167292 constant */
    p4167296_0 = VAL(0);
    L_4167296: ;
    /* @4167296 bf */
    if (!TRUTH(p4167296_0)) goto L_4167516;
    /* @4167300 constant */
    /* @4167304 load */
    /* @4167312 cast */
    /* @4167316 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "flashing", VAL(1));
    /* @4167324 load */
    /* @4167332 cast */
    /* @4167336 dup */
    /* @4167340 load */
    /* @4167348 constant */
    /* @4167352 sub */
    /* @4167356 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime") - VAL(1)));
    /* @4167364 constant */
    /* @4167368 cast */
    /* @4167372 load */
    /* @4167380 cast */
    /* @4167384 load */
    /* @4167392 load */
    /* @4167400 cast */
    /* @4167404 load */
    /* @4167412 call */
    GM_SITE(vm, 311, 4167412);
    /* @4167420 store */
    v26 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit10")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit10")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v26);
    /* @4167428 constant */
    /* @4167432 load */
    /* @4167440 cast */
    /* @4167444 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(1));
    /* @4167452 constant */
    /* @4167456 load */
    /* @4167464 cast */
    /* @4167468 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "swordstunned", VAL(1));
    /* @4167476 constant */
    /* @4167480 load */
    /* @4167488 cast */
    /* @4167492 constant */
    /* @4167496 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit10")), "alarm", VAL(5), VAL(30));
    /* @4167504 constant */
    /* @4167508 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4167516: ;
    /* @4167516 constant */
    /* @4167520 cast */
    /* @4167524 load */
    /* @4167532 load */
    /* @4167540 call */
    GM_SITE(vm, 311, 4167540);
    /* @4167548 store */
    v27 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(21));
    GM_WRITE(vm, -1, "hit11", v27);
    /* @4167556 load */
    /* @4167564 constant */
    /* @4167568 cmp */
    /* @4167572 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit11") != VAL(-4)))) goto L_4167596;
    /* @4167576 load */
    /* @4167584 constant */
    /* @4167588 cmp */
    /* @4167592 b */
    p4167600_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4167600;
    L_4167596: ;
    /* @4167596 constant */
    p4167600_0 = VAL(0);
    L_4167600: ;
    /* @4167600 bf */
    if (!TRUTH(p4167600_0)) goto L_4167820;
    /* @4167604 constant */
    /* @4167608 load */
    /* @4167616 cast */
    /* @4167620 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "flashing", VAL(1));
    /* @4167628 load */
    /* @4167636 cast */
    /* @4167640 dup */
    /* @4167644 load */
    /* @4167652 constant */
    /* @4167656 sub */
    /* @4167660 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit") - VAL(1)));
    /* @4167668 constant */
    /* @4167672 cast */
    /* @4167676 load */
    /* @4167684 cast */
    /* @4167688 load */
    /* @4167696 load */
    /* @4167704 cast */
    /* @4167708 load */
    /* @4167716 call */
    GM_SITE(vm, 311, 4167716);
    /* @4167724 store */
    v28 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit11")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit11")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v28);
    /* @4167732 constant */
    /* @4167736 load */
    /* @4167744 cast */
    /* @4167748 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(1));
    /* @4167756 constant */
    /* @4167760 load */
    /* @4167768 cast */
    /* @4167772 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "swordstunned", VAL(1));
    /* @4167780 constant */
    /* @4167784 load */
    /* @4167792 cast */
    /* @4167796 constant */
    /* @4167800 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit11")), "alarm", VAL(4), VAL(30));
    /* @4167808 constant */
    /* @4167812 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4167820: ;
    /* @4167820 constant */
    /* @4167824 cast */
    /* @4167828 load */
    /* @4167836 load */
    /* @4167844 call */
    GM_SITE(vm, 311, 4167844);
    /* @4167852 store */
    v29 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(19));
    GM_WRITE(vm, -1, "hit12", v29);
    /* @4167860 load */
    /* @4167868 constant */
    /* @4167872 cmp */
    /* @4167876 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit12") != VAL(-4)))) goto L_4167900;
    /* @4167880 load */
    /* @4167888 constant */
    /* @4167892 cmp */
    /* @4167896 b */
    p4167904_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4167904;
    L_4167900: ;
    /* @4167900 constant */
    p4167904_0 = VAL(0);
    L_4167904: ;
    /* @4167904 bf */
    if (!TRUTH(p4167904_0)) goto L_4168124;
    /* @4167908 constant */
    /* @4167912 load */
    /* @4167920 cast */
    /* @4167924 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "flashing", VAL(1));
    /* @4167932 load */
    /* @4167940 cast */
    /* @4167944 dup */
    /* @4167948 load */
    /* @4167956 constant */
    /* @4167960 sub */
    /* @4167964 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie") - VAL(1)));
    /* @4167972 constant */
    /* @4167976 cast */
    /* @4167980 load */
    /* @4167988 cast */
    /* @4167992 load */
    /* @4168000 load */
    /* @4168008 cast */
    /* @4168012 load */
    /* @4168020 call */
    GM_SITE(vm, 311, 4168020);
    /* @4168028 store */
    v30 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit12")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit12")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v30);
    /* @4168036 constant */
    /* @4168040 load */
    /* @4168048 cast */
    /* @4168052 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(1));
    /* @4168060 constant */
    /* @4168064 load */
    /* @4168072 cast */
    /* @4168076 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "swordstunned", VAL(1));
    /* @4168084 constant */
    /* @4168088 load */
    /* @4168096 cast */
    /* @4168100 constant */
    /* @4168104 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit12")), "alarm", VAL(5), VAL(30));
    /* @4168112 constant */
    /* @4168116 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4168124: ;
    /* @4168124 constant */
    /* @4168128 cast */
    /* @4168132 load */
    /* @4168140 load */
    /* @4168148 call */
    GM_SITE(vm, 311, 4168148);
    /* @4168156 store */
    v31 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(18));
    GM_WRITE(vm, -1, "hit13", v31);
    /* @4168164 load */
    /* @4168172 constant */
    /* @4168176 cmp */
    /* @4168180 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit13") != VAL(-4)))) goto L_4168204;
    /* @4168184 load */
    /* @4168192 constant */
    /* @4168196 cmp */
    /* @4168200 b */
    p4168208_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4168208;
    L_4168204: ;
    /* @4168204 constant */
    p4168208_0 = VAL(0);
    L_4168208: ;
    /* @4168208 bf */
    if (!TRUTH(p4168208_0)) goto L_4168428;
    /* @4168212 constant */
    /* @4168216 load */
    /* @4168224 cast */
    /* @4168228 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "flashing", VAL(1));
    /* @4168236 load */
    /* @4168244 cast */
    /* @4168248 dup */
    /* @4168252 load */
    /* @4168260 constant */
    /* @4168264 sub */
    /* @4168268 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk") - VAL(1)));
    /* @4168276 constant */
    /* @4168280 cast */
    /* @4168284 load */
    /* @4168292 cast */
    /* @4168296 load */
    /* @4168304 load */
    /* @4168312 cast */
    /* @4168316 load */
    /* @4168324 call */
    GM_SITE(vm, 311, 4168324);
    /* @4168332 store */
    v32 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit13")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit13")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v32);
    /* @4168340 constant */
    /* @4168344 load */
    /* @4168352 cast */
    /* @4168356 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(1));
    /* @4168364 constant */
    /* @4168368 load */
    /* @4168376 cast */
    /* @4168380 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "swordstunned", VAL(1));
    /* @4168388 constant */
    /* @4168392 load */
    /* @4168400 cast */
    /* @4168404 constant */
    /* @4168408 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit13")), "alarm", VAL(5), VAL(30));
    /* @4168416 constant */
    /* @4168420 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4168428: ;
    /* @4168428 constant */
    /* @4168432 cast */
    /* @4168436 load */
    /* @4168444 load */
    /* @4168452 call */
    GM_SITE(vm, 311, 4168452);
    /* @4168460 store */
    v33 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(17));
    GM_WRITE(vm, -1, "hit14", v33);
    /* @4168468 load */
    /* @4168476 constant */
    /* @4168480 cmp */
    /* @4168484 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit14") != VAL(-4)))) goto L_4168508;
    /* @4168488 load */
    /* @4168496 constant */
    /* @4168500 cmp */
    /* @4168504 b */
    p4168512_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4168512;
    L_4168508: ;
    /* @4168508 constant */
    p4168512_0 = VAL(0);
    L_4168512: ;
    /* @4168512 bf */
    if (!TRUTH(p4168512_0)) goto L_4168732;
    /* @4168516 constant */
    /* @4168520 load */
    /* @4168528 cast */
    /* @4168532 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "flashing", VAL(1));
    /* @4168540 load */
    /* @4168548 cast */
    /* @4168552 dup */
    /* @4168556 load */
    /* @4168564 constant */
    /* @4168568 sub */
    /* @4168572 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton") - VAL(1)));
    /* @4168580 constant */
    /* @4168584 cast */
    /* @4168588 load */
    /* @4168596 cast */
    /* @4168600 load */
    /* @4168608 load */
    /* @4168616 cast */
    /* @4168620 load */
    /* @4168628 call */
    GM_SITE(vm, 311, 4168628);
    /* @4168636 store */
    v34 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit14")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit14")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v34);
    /* @4168644 constant */
    /* @4168648 load */
    /* @4168656 cast */
    /* @4168660 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(1));
    /* @4168668 constant */
    /* @4168672 load */
    /* @4168680 cast */
    /* @4168684 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "swordstunned", VAL(1));
    /* @4168692 constant */
    /* @4168696 load */
    /* @4168704 cast */
    /* @4168708 constant */
    /* @4168712 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit14")), "alarm", VAL(5), VAL(30));
    /* @4168720 constant */
    /* @4168724 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4168732: ;
    /* @4168732 constant */
    /* @4168736 cast */
    /* @4168740 load */
    /* @4168748 load */
    /* @4168756 call */
    GM_SITE(vm, 311, 4168756);
    /* @4168764 store */
    v35 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(26));
    GM_WRITE(vm, -1, "hit15", v35);
    /* @4168772 load */
    /* @4168780 constant */
    /* @4168784 cmp */
    /* @4168788 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit15") != VAL(-4)))) goto L_4168812;
    /* @4168792 load */
    /* @4168800 constant */
    /* @4168804 cmp */
    /* @4168808 b */
    p4168816_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4168816;
    L_4168812: ;
    /* @4168812 constant */
    p4168816_0 = VAL(0);
    L_4168816: ;
    /* @4168816 bf */
    if (!TRUTH(p4168816_0)) goto L_4168984;
    /* @4168820 constant */
    /* @4168824 load */
    /* @4168832 cast */
    /* @4168836 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15")), "flashing", VAL(1));
    /* @4168844 load */
    /* @4168852 cast */
    /* @4168856 dup */
    /* @4168860 load */
    /* @4168868 constant */
    /* @4168872 sub */
    /* @4168876 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2") - VAL(1)));
    /* @4168884 constant */
    /* @4168888 cast */
    /* @4168892 load */
    /* @4168900 cast */
    /* @4168904 load */
    /* @4168912 load */
    /* @4168920 cast */
    /* @4168924 load */
    /* @4168932 call */
    GM_SITE(vm, 311, 4168932);
    /* @4168940 store */
    v36 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit15")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit15")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v36);
    /* @4168948 constant */
    /* @4168952 load */
    /* @4168960 cast */
    /* @4168964 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(1));
    /* @4168972 constant */
    /* @4168976 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4168984: ;
    /* @4168984 constant */
    /* @4168988 cast */
    /* @4168992 load */
    /* @4169000 load */
    /* @4169008 call */
    GM_SITE(vm, 311, 4169008);
    /* @4169016 store */
    v37 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(27));
    GM_WRITE(vm, -1, "hit16", v37);
    /* @4169024 load */
    /* @4169032 constant */
    /* @4169036 cmp */
    /* @4169040 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit16") != VAL(-4)))) goto L_4169064;
    /* @4169044 load */
    /* @4169052 constant */
    /* @4169056 cmp */
    /* @4169060 b */
    p4169068_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4169068;
    L_4169064: ;
    /* @4169064 constant */
    p4169068_0 = VAL(0);
    L_4169068: ;
    /* @4169068 bf */
    if (!TRUTH(p4169068_0)) goto L_4169236;
    /* @4169072 constant */
    /* @4169076 load */
    /* @4169084 cast */
    /* @4169088 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16")), "flashing", VAL(1));
    /* @4169096 load */
    /* @4169104 cast */
    /* @4169108 dup */
    /* @4169112 load */
    /* @4169120 constant */
    /* @4169124 sub */
    /* @4169128 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3") - VAL(1)));
    /* @4169136 constant */
    /* @4169140 cast */
    /* @4169144 load */
    /* @4169152 cast */
    /* @4169156 load */
    /* @4169164 load */
    /* @4169172 cast */
    /* @4169176 load */
    /* @4169184 call */
    GM_SITE(vm, 311, 4169184);
    /* @4169192 store */
    v38 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit16")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit16")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v38);
    /* @4169200 constant */
    /* @4169204 load */
    /* @4169212 cast */
    /* @4169216 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(1));
    /* @4169224 constant */
    /* @4169228 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4169236: ;
    /* @4169236 constant */
    /* @4169240 cast */
    /* @4169244 load */
    /* @4169252 load */
    /* @4169260 call */
    GM_SITE(vm, 311, 4169260);
    /* @4169268 store */
    v39 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(28));
    GM_WRITE(vm, -1, "hitboss4", v39);
    /* @4169276 load */
    /* @4169284 constant */
    /* @4169288 cmp */
    /* @4169292 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss4") != VAL(-4)))) goto L_4169316;
    /* @4169296 load */
    /* @4169304 constant */
    /* @4169308 cmp */
    /* @4169312 b */
    p4169320_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4169320;
    L_4169316: ;
    /* @4169316 constant */
    p4169320_0 = VAL(0);
    L_4169320: ;
    /* @4169320 bf */
    if (!TRUTH(p4169320_0)) goto L_4169488;
    /* @4169324 constant */
    /* @4169328 load */
    /* @4169336 cast */
    /* @4169340 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "flashing", VAL(1));
    /* @4169348 load */
    /* @4169356 cast */
    /* @4169360 dup */
    /* @4169364 load */
    /* @4169372 constant */
    /* @4169376 sub */
    /* @4169380 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4") - VAL(1)));
    /* @4169388 constant */
    /* @4169392 cast */
    /* @4169396 load */
    /* @4169404 cast */
    /* @4169408 load */
    /* @4169416 load */
    /* @4169424 cast */
    /* @4169428 load */
    /* @4169436 call */
    GM_SITE(vm, 311, 4169436);
    /* @4169444 store */
    v40 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v40);
    /* @4169452 constant */
    /* @4169456 load */
    /* @4169464 cast */
    /* @4169468 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(1));
    /* @4169476 constant */
    /* @4169480 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4169488: ;
    /* @4169488 constant */
    /* @4169492 cast */
    /* @4169496 load */
    /* @4169504 load */
    /* @4169512 call */
    GM_SITE(vm, 311, 4169512);
    /* @4169520 store */
    v41 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(29));
    GM_WRITE(vm, -1, "hitboss5", v41);
    /* @4169528 load */
    /* @4169536 constant */
    /* @4169540 cmp */
    /* @4169544 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss5") != VAL(-4)))) goto L_4169568;
    /* @4169548 load */
    /* @4169556 constant */
    /* @4169560 cmp */
    /* @4169564 b */
    p4169572_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4169572;
    L_4169568: ;
    /* @4169568 constant */
    p4169572_0 = VAL(0);
    L_4169572: ;
    /* @4169572 bf */
    if (!TRUTH(p4169572_0)) goto L_4169740;
    /* @4169576 constant */
    /* @4169580 load */
    /* @4169588 cast */
    /* @4169592 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "flashing", VAL(1));
    /* @4169600 load */
    /* @4169608 cast */
    /* @4169612 dup */
    /* @4169616 load */
    /* @4169624 constant */
    /* @4169628 sub */
    /* @4169632 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5") - VAL(1)));
    /* @4169640 constant */
    /* @4169644 cast */
    /* @4169648 load */
    /* @4169656 cast */
    /* @4169660 load */
    /* @4169668 load */
    /* @4169676 cast */
    /* @4169680 load */
    /* @4169688 call */
    GM_SITE(vm, 311, 4169688);
    /* @4169696 store */
    v42 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v42);
    /* @4169704 constant */
    /* @4169708 load */
    /* @4169716 cast */
    /* @4169720 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(1));
    /* @4169728 constant */
    /* @4169732 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4169740: ;
    /* @4169740 constant */
    /* @4169744 cast */
    /* @4169748 load */
    /* @4169756 load */
    /* @4169764 call */
    GM_SITE(vm, 311, 4169764);
    /* @4169772 store */
    v43 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(30));
    GM_WRITE(vm, -1, "hit17", v43);
    /* @4169780 load */
    /* @4169788 constant */
    /* @4169792 cmp */
    /* @4169796 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit17") != VAL(-4)))) goto L_4169820;
    /* @4169800 load */
    /* @4169808 constant */
    /* @4169812 cmp */
    /* @4169816 b */
    p4169824_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4169824;
    L_4169820: ;
    /* @4169820 constant */
    p4169824_0 = VAL(0);
    L_4169824: ;
    /* @4169824 bf */
    if (!TRUTH(p4169824_0)) goto L_4169992;
    /* @4169828 constant */
    /* @4169832 load */
    /* @4169840 cast */
    /* @4169844 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17")), "flashing", VAL(1));
    /* @4169852 load */
    /* @4169860 cast */
    /* @4169864 dup */
    /* @4169868 load */
    /* @4169876 constant */
    /* @4169880 sub */
    /* @4169884 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss") - VAL(1)));
    /* @4169892 constant */
    /* @4169896 cast */
    /* @4169900 load */
    /* @4169908 cast */
    /* @4169912 load */
    /* @4169920 load */
    /* @4169928 cast */
    /* @4169932 load */
    /* @4169940 call */
    GM_SITE(vm, 311, 4169940);
    /* @4169948 store */
    v44 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit17")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit17")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v44);
    /* @4169956 constant */
    /* @4169960 load */
    /* @4169968 cast */
    /* @4169972 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(1));
    /* @4169980 constant */
    /* @4169984 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4169992: ;
    /* @4169992 b */
    goto L_4187368;
    L_4169996: ;
    /* @4169996 load */
    /* @4170004 constant */
    /* @4170008 cmp */
    /* @4170012 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "sword") == VAL(1)))) goto L_4175788;
    /* @4170016 constant */
    /* @4170020 cast */
    /* @4170024 load */
    /* @4170032 load */
    /* @4170040 call */
    GM_SITE(vm, 311, 4170040);
    /* @4170048 store */
    v45 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(15));
    GM_WRITE(vm, -1, "hitknife", v45);
    /* @4170056 load */
    /* @4170064 constant */
    /* @4170068 cmp */
    /* @4170072 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitknife") != VAL(-4)))) goto L_4170096;
    /* @4170076 load */
    /* @4170084 constant */
    /* @4170088 cmp */
    /* @4170092 b */
    p4170100_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4170100;
    L_4170096: ;
    /* @4170096 constant */
    p4170100_0 = VAL(0);
    L_4170100: ;
    /* @4170100 bf */
    if (!TRUTH(p4170100_0)) goto L_4170320;
    /* @4170104 constant */
    /* @4170108 load */
    /* @4170116 cast */
    /* @4170120 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "flashing", VAL(1));
    /* @4170128 load */
    /* @4170136 cast */
    /* @4170140 dup */
    /* @4170144 load */
    /* @4170152 constant */
    /* @4170156 sub */
    /* @4170160 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife") - VAL(2)));
    /* @4170168 constant */
    /* @4170172 cast */
    /* @4170176 load */
    /* @4170184 cast */
    /* @4170188 load */
    /* @4170196 load */
    /* @4170204 cast */
    /* @4170208 load */
    /* @4170216 call */
    GM_SITE(vm, 311, 4170216);
    /* @4170224 store */
    v46 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v46);
    /* @4170232 constant */
    /* @4170236 load */
    /* @4170244 cast */
    /* @4170248 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(2));
    /* @4170256 constant */
    /* @4170260 load */
    /* @4170268 cast */
    /* @4170272 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "swordstunned", VAL(1));
    /* @4170280 constant */
    /* @4170284 load */
    /* @4170292 cast */
    /* @4170296 constant */
    /* @4170300 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "alarm", VAL(5), VAL(30));
    /* @4170308 constant */
    /* @4170312 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4170320: ;
    /* @4170320 constant */
    /* @4170324 cast */
    /* @4170328 load */
    /* @4170336 load */
    /* @4170344 call */
    GM_SITE(vm, 311, 4170344);
    /* @4170352 store */
    v47 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(24));
    GM_WRITE(vm, -1, "hitghost", v47);
    /* @4170360 load */
    /* @4170368 constant */
    /* @4170372 cmp */
    /* @4170376 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitghost") != VAL(-4)))) goto L_4170400;
    /* @4170380 load */
    /* @4170388 constant */
    /* @4170392 cmp */
    /* @4170396 b */
    p4170404_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4170404;
    L_4170400: ;
    /* @4170400 constant */
    p4170404_0 = VAL(0);
    L_4170404: ;
    /* @4170404 bf */
    if (!TRUTH(p4170404_0)) goto L_4170624;
    /* @4170408 constant */
    /* @4170412 load */
    /* @4170420 cast */
    /* @4170424 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "flashing", VAL(1));
    /* @4170432 load */
    /* @4170440 cast */
    /* @4170444 dup */
    /* @4170448 load */
    /* @4170456 constant */
    /* @4170460 sub */
    /* @4170464 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "hpghost", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "hpghost") - VAL(2)));
    /* @4170472 constant */
    /* @4170476 cast */
    /* @4170480 load */
    /* @4170488 cast */
    /* @4170492 load */
    /* @4170500 load */
    /* @4170508 cast */
    /* @4170512 load */
    /* @4170520 call */
    GM_SITE(vm, 311, 4170520);
    /* @4170528 store */
    v48 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v48);
    /* @4170536 constant */
    /* @4170540 load */
    /* @4170548 cast */
    /* @4170552 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(2));
    /* @4170560 constant */
    /* @4170564 load */
    /* @4170572 cast */
    /* @4170576 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "swordstunned", VAL(1));
    /* @4170584 constant */
    /* @4170588 load */
    /* @4170596 cast */
    /* @4170600 constant */
    /* @4170604 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "alarm", VAL(5), VAL(30));
    /* @4170612 constant */
    /* @4170616 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4170624: ;
    /* @4170624 constant */
    /* @4170628 cast */
    /* @4170632 load */
    /* @4170640 load */
    /* @4170648 call */
    GM_SITE(vm, 311, 4170648);
    /* @4170656 store */
    v49 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(23));
    GM_WRITE(vm, -1, "hitwolf", v49);
    /* @4170664 load */
    /* @4170672 constant */
    /* @4170676 cmp */
    /* @4170680 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitwolf") != VAL(-4)))) goto L_4170704;
    /* @4170684 load */
    /* @4170692 constant */
    /* @4170696 cmp */
    /* @4170700 b */
    p4170708_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4170708;
    L_4170704: ;
    /* @4170704 constant */
    p4170708_0 = VAL(0);
    L_4170708: ;
    /* @4170708 bf */
    if (!TRUTH(p4170708_0)) goto L_4170928;
    /* @4170712 constant */
    /* @4170716 load */
    /* @4170724 cast */
    /* @4170728 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "flashing", VAL(1));
    /* @4170736 load */
    /* @4170744 cast */
    /* @4170748 dup */
    /* @4170752 load */
    /* @4170760 constant */
    /* @4170764 sub */
    /* @4170768 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf") - VAL(2)));
    /* @4170776 constant */
    /* @4170780 cast */
    /* @4170784 load */
    /* @4170792 cast */
    /* @4170796 load */
    /* @4170804 load */
    /* @4170812 cast */
    /* @4170816 load */
    /* @4170824 call */
    GM_SITE(vm, 311, 4170824);
    /* @4170832 store */
    v50 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v50);
    /* @4170840 constant */
    /* @4170844 load */
    /* @4170852 cast */
    /* @4170856 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(2));
    /* @4170864 constant */
    /* @4170868 load */
    /* @4170876 cast */
    /* @4170880 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "swordstunned", VAL(1));
    /* @4170888 constant */
    /* @4170892 load */
    /* @4170900 cast */
    /* @4170904 constant */
    /* @4170908 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "alarm", VAL(5), VAL(30));
    /* @4170916 constant */
    /* @4170920 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4170928: ;
    /* @4170928 constant */
    /* @4170932 cast */
    /* @4170936 load */
    /* @4170944 load */
    /* @4170952 call */
    GM_SITE(vm, 311, 4170952);
    /* @4170960 store */
    v51 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(14));
    GM_WRITE(vm, -1, "hit", v51);
    /* @4170968 load */
    /* @4170976 constant */
    /* @4170980 cmp */
    /* @4170984 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit") != VAL(-4)))) goto L_4171008;
    /* @4170988 load */
    /* @4170996 constant */
    /* @4171000 cmp */
    /* @4171004 b */
    p4171012_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4171012;
    L_4171008: ;
    /* @4171008 constant */
    p4171012_0 = VAL(0);
    L_4171012: ;
    /* @4171012 bf */
    if (!TRUTH(p4171012_0)) goto L_4171232;
    /* @4171016 constant */
    /* @4171020 load */
    /* @4171028 cast */
    /* @4171032 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "flashing", VAL(1));
    /* @4171040 load */
    /* @4171048 cast */
    /* @4171052 dup */
    /* @4171056 load */
    /* @4171064 constant */
    /* @4171068 sub */
    /* @4171072 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp") - VAL(2)));
    /* @4171080 constant */
    /* @4171084 cast */
    /* @4171088 load */
    /* @4171096 cast */
    /* @4171100 load */
    /* @4171108 load */
    /* @4171116 cast */
    /* @4171120 load */
    /* @4171128 call */
    GM_SITE(vm, 311, 4171128);
    /* @4171136 store */
    v52 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v52);
    /* @4171144 constant */
    /* @4171148 load */
    /* @4171156 cast */
    /* @4171160 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(2));
    /* @4171168 constant */
    /* @4171172 load */
    /* @4171180 cast */
    /* @4171184 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "swordstunned", VAL(1));
    /* @4171192 constant */
    /* @4171196 load */
    /* @4171204 cast */
    /* @4171208 constant */
    /* @4171212 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit")), "alarm", VAL(5), VAL(30));
    /* @4171220 constant */
    /* @4171224 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4171232: ;
    /* @4171232 constant */
    /* @4171236 cast */
    /* @4171240 load */
    /* @4171248 load */
    /* @4171256 call */
    GM_SITE(vm, 311, 4171256);
    /* @4171264 store */
    v53 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(22));
    GM_WRITE(vm, -1, "hit2", v53);
    /* @4171272 load */
    /* @4171280 constant */
    /* @4171284 cmp */
    /* @4171288 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit2") != VAL(-4)))) goto L_4171312;
    /* @4171292 load */
    /* @4171300 constant */
    /* @4171304 cmp */
    /* @4171308 b */
    p4171316_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4171316;
    L_4171312: ;
    /* @4171312 constant */
    p4171316_0 = VAL(0);
    L_4171316: ;
    /* @4171316 bf */
    if (!TRUTH(p4171316_0)) goto L_4171536;
    /* @4171320 constant */
    /* @4171324 load */
    /* @4171332 cast */
    /* @4171336 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "flashing", VAL(1));
    /* @4171344 load */
    /* @4171352 cast */
    /* @4171356 dup */
    /* @4171360 load */
    /* @4171368 constant */
    /* @4171372 sub */
    /* @4171376 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo") - VAL(2)));
    /* @4171384 constant */
    /* @4171388 cast */
    /* @4171392 load */
    /* @4171400 cast */
    /* @4171404 load */
    /* @4171412 load */
    /* @4171420 cast */
    /* @4171424 load */
    /* @4171432 call */
    GM_SITE(vm, 311, 4171432);
    /* @4171440 store */
    v54 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit2")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit2")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v54);
    /* @4171448 constant */
    /* @4171452 load */
    /* @4171460 cast */
    /* @4171464 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(2));
    /* @4171472 constant */
    /* @4171476 load */
    /* @4171484 cast */
    /* @4171488 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "swordstunned", VAL(1));
    /* @4171496 constant */
    /* @4171500 load */
    /* @4171508 cast */
    /* @4171512 constant */
    /* @4171516 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit2")), "alarm", VAL(5), VAL(30));
    /* @4171524 constant */
    /* @4171528 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4171536: ;
    /* @4171536 constant */
    /* @4171540 cast */
    /* @4171544 load */
    /* @4171552 load */
    /* @4171560 call */
    GM_SITE(vm, 311, 4171560);
    /* @4171568 store */
    v55 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(25));
    GM_WRITE(vm, -1, "hittrex", v55);
    /* @4171576 load */
    /* @4171584 constant */
    /* @4171588 cmp */
    /* @4171592 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hittrex") != VAL(-4)))) goto L_4171616;
    /* @4171596 load */
    /* @4171604 constant */
    /* @4171608 cmp */
    /* @4171612 b */
    p4171620_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4171620;
    L_4171616: ;
    /* @4171616 constant */
    p4171620_0 = VAL(0);
    L_4171620: ;
    /* @4171620 bf */
    if (!TRUTH(p4171620_0)) goto L_4171788;
    /* @4171624 constant */
    /* @4171628 load */
    /* @4171636 cast */
    /* @4171640 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "flashing", VAL(1));
    /* @4171648 load */
    /* @4171656 cast */
    /* @4171660 dup */
    /* @4171664 load */
    /* @4171672 constant */
    /* @4171676 sub */
    /* @4171680 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex") - VAL(2)));
    /* @4171688 constant */
    /* @4171692 cast */
    /* @4171696 load */
    /* @4171704 cast */
    /* @4171708 load */
    /* @4171716 load */
    /* @4171724 cast */
    /* @4171728 load */
    /* @4171736 call */
    GM_SITE(vm, 311, 4171736);
    /* @4171744 store */
    v56 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v56);
    /* @4171752 constant */
    /* @4171756 load */
    /* @4171764 cast */
    /* @4171768 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(2));
    /* @4171776 constant */
    /* @4171780 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4171788: ;
    /* @4171788 constant */
    /* @4171792 cast */
    /* @4171796 load */
    /* @4171804 load */
    /* @4171812 call */
    GM_SITE(vm, 311, 4171812);
    /* @4171820 store */
    v57 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(31));
    GM_WRITE(vm, -1, "hit4", v57);
    /* @4171828 load */
    /* @4171836 constant */
    /* @4171840 cmp */
    /* @4171844 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit4") != VAL(-4)))) goto L_4171868;
    /* @4171848 load */
    /* @4171856 constant */
    /* @4171860 cmp */
    /* @4171864 b */
    p4171872_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4171872;
    L_4171868: ;
    /* @4171868 constant */
    p4171872_0 = VAL(0);
    L_4171872: ;
    /* @4171872 bf */
    if (!TRUTH(p4171872_0)) goto L_4172092;
    /* @4171876 constant */
    /* @4171880 load */
    /* @4171888 cast */
    /* @4171892 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "flashing", VAL(1));
    /* @4171900 load */
    /* @4171908 cast */
    /* @4171912 dup */
    /* @4171916 load */
    /* @4171924 constant */
    /* @4171928 sub */
    /* @4171932 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour") - VAL(2)));
    /* @4171940 constant */
    /* @4171944 cast */
    /* @4171948 load */
    /* @4171956 cast */
    /* @4171960 load */
    /* @4171968 load */
    /* @4171976 cast */
    /* @4171980 load */
    /* @4171988 call */
    GM_SITE(vm, 311, 4171988);
    /* @4171996 store */
    v58 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit4")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit4")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v58);
    /* @4172004 constant */
    /* @4172008 load */
    /* @4172016 cast */
    /* @4172020 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(2));
    /* @4172028 constant */
    /* @4172032 load */
    /* @4172040 cast */
    /* @4172044 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "swordstunned", VAL(1));
    /* @4172052 constant */
    /* @4172056 load */
    /* @4172064 cast */
    /* @4172068 constant */
    /* @4172072 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit4")), "alarm", VAL(5), VAL(30));
    /* @4172080 constant */
    /* @4172084 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4172092: ;
    /* @4172092 constant */
    /* @4172096 cast */
    /* @4172100 load */
    /* @4172108 load */
    /* @4172116 call */
    GM_SITE(vm, 311, 4172116);
    /* @4172124 store */
    v59 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(32));
    GM_WRITE(vm, -1, "hit5", v59);
    /* @4172132 load */
    /* @4172140 constant */
    /* @4172144 cmp */
    /* @4172148 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit5") != VAL(-4)))) goto L_4172172;
    /* @4172152 load */
    /* @4172160 constant */
    /* @4172164 cmp */
    /* @4172168 b */
    p4172176_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4172176;
    L_4172172: ;
    /* @4172172 constant */
    p4172176_0 = VAL(0);
    L_4172176: ;
    /* @4172176 bf */
    if (!TRUTH(p4172176_0)) goto L_4172396;
    /* @4172180 constant */
    /* @4172184 load */
    /* @4172192 cast */
    /* @4172196 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "flashing", VAL(1));
    /* @4172204 load */
    /* @4172212 cast */
    /* @4172216 dup */
    /* @4172220 load */
    /* @4172228 constant */
    /* @4172232 sub */
    /* @4172236 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime") - VAL(2)));
    /* @4172244 constant */
    /* @4172248 cast */
    /* @4172252 load */
    /* @4172260 cast */
    /* @4172264 load */
    /* @4172272 load */
    /* @4172280 cast */
    /* @4172284 load */
    /* @4172292 call */
    GM_SITE(vm, 311, 4172292);
    /* @4172300 store */
    v60 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit5")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit5")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v60);
    /* @4172308 constant */
    /* @4172312 load */
    /* @4172320 cast */
    /* @4172324 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(2));
    /* @4172332 constant */
    /* @4172336 load */
    /* @4172344 cast */
    /* @4172348 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "swordstunned", VAL(1));
    /* @4172356 constant */
    /* @4172360 load */
    /* @4172368 cast */
    /* @4172372 constant */
    /* @4172376 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit5")), "alarm", VAL(5), VAL(30));
    /* @4172384 constant */
    /* @4172388 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4172396: ;
    /* @4172396 constant */
    /* @4172400 cast */
    /* @4172404 load */
    /* @4172412 load */
    /* @4172420 call */
    GM_SITE(vm, 311, 4172420);
    /* @4172428 store */
    v61 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(16));
    GM_WRITE(vm, -1, "hit8", v61);
    /* @4172436 load */
    /* @4172444 constant */
    /* @4172448 cmp */
    /* @4172452 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit8") != VAL(-4)))) goto L_4172476;
    /* @4172456 load */
    /* @4172464 constant */
    /* @4172468 cmp */
    /* @4172472 b */
    p4172480_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4172480;
    L_4172476: ;
    /* @4172476 constant */
    p4172480_0 = VAL(0);
    L_4172480: ;
    /* @4172480 bf */
    if (!TRUTH(p4172480_0)) goto L_4172700;
    /* @4172484 constant */
    /* @4172488 load */
    /* @4172496 cast */
    /* @4172500 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "flashing", VAL(1));
    /* @4172508 load */
    /* @4172516 cast */
    /* @4172520 dup */
    /* @4172524 load */
    /* @4172532 constant */
    /* @4172536 sub */
    /* @4172540 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1") - VAL(2)));
    /* @4172548 constant */
    /* @4172552 cast */
    /* @4172556 load */
    /* @4172564 cast */
    /* @4172568 load */
    /* @4172576 load */
    /* @4172584 cast */
    /* @4172588 load */
    /* @4172596 call */
    GM_SITE(vm, 311, 4172596);
    /* @4172604 store */
    v62 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit8")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit8")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v62);
    /* @4172612 constant */
    /* @4172616 load */
    /* @4172624 cast */
    /* @4172628 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(2));
    /* @4172636 constant */
    /* @4172640 load */
    /* @4172648 cast */
    /* @4172652 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "swordstunned", VAL(1));
    /* @4172660 constant */
    /* @4172664 load */
    /* @4172672 cast */
    /* @4172676 constant */
    /* @4172680 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit8")), "alarm", VAL(5), VAL(30));
    /* @4172688 constant */
    /* @4172692 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4172700: ;
    /* @4172700 constant */
    /* @4172704 cast */
    /* @4172708 load */
    /* @4172716 load */
    /* @4172724 call */
    GM_SITE(vm, 311, 4172724);
    /* @4172732 store */
    v63 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(20));
    GM_WRITE(vm, -1, "hit9", v63);
    /* @4172740 load */
    /* @4172748 constant */
    /* @4172752 cmp */
    /* @4172756 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit9") != VAL(-4)))) goto L_4172780;
    /* @4172760 load */
    /* @4172768 constant */
    /* @4172772 cmp */
    /* @4172776 b */
    p4172784_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4172784;
    L_4172780: ;
    /* @4172780 constant */
    p4172784_0 = VAL(0);
    L_4172784: ;
    /* @4172784 bf */
    if (!TRUTH(p4172784_0)) goto L_4173004;
    /* @4172788 constant */
    /* @4172792 load */
    /* @4172800 cast */
    /* @4172804 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "flashing", VAL(1));
    /* @4172812 load */
    /* @4172820 cast */
    /* @4172824 dup */
    /* @4172828 load */
    /* @4172836 constant */
    /* @4172840 sub */
    /* @4172844 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2") - VAL(2)));
    /* @4172852 constant */
    /* @4172856 cast */
    /* @4172860 load */
    /* @4172868 cast */
    /* @4172872 load */
    /* @4172880 load */
    /* @4172888 cast */
    /* @4172892 load */
    /* @4172900 call */
    GM_SITE(vm, 311, 4172900);
    /* @4172908 store */
    v64 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit9")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit9")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v64);
    /* @4172916 constant */
    /* @4172920 load */
    /* @4172928 cast */
    /* @4172932 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(2));
    /* @4172940 constant */
    /* @4172944 load */
    /* @4172952 cast */
    /* @4172956 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "swordstunned", VAL(1));
    /* @4172964 constant */
    /* @4172968 load */
    /* @4172976 cast */
    /* @4172980 constant */
    /* @4172984 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit9")), "alarm", VAL(5), VAL(30));
    /* @4172992 constant */
    /* @4172996 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4173004: ;
    /* @4173004 constant */
    /* @4173008 cast */
    /* @4173012 load */
    /* @4173020 load */
    /* @4173028 call */
    GM_SITE(vm, 311, 4173028);
    /* @4173036 store */
    v65 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(33));
    GM_WRITE(vm, -1, "hit10", v65);
    /* @4173044 load */
    /* @4173052 constant */
    /* @4173056 cmp */
    /* @4173060 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit10") != VAL(-4)))) goto L_4173084;
    /* @4173064 load */
    /* @4173072 constant */
    /* @4173076 cmp */
    /* @4173080 b */
    p4173088_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4173088;
    L_4173084: ;
    /* @4173084 constant */
    p4173088_0 = VAL(0);
    L_4173088: ;
    /* @4173088 bf */
    if (!TRUTH(p4173088_0)) goto L_4173308;
    /* @4173092 constant */
    /* @4173096 load */
    /* @4173104 cast */
    /* @4173108 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "flashing", VAL(1));
    /* @4173116 load */
    /* @4173124 cast */
    /* @4173128 dup */
    /* @4173132 load */
    /* @4173140 constant */
    /* @4173144 sub */
    /* @4173148 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime") - VAL(2)));
    /* @4173156 constant */
    /* @4173160 cast */
    /* @4173164 load */
    /* @4173172 cast */
    /* @4173176 load */
    /* @4173184 load */
    /* @4173192 cast */
    /* @4173196 load */
    /* @4173204 call */
    GM_SITE(vm, 311, 4173204);
    /* @4173212 store */
    v66 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit10")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit10")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v66);
    /* @4173220 constant */
    /* @4173224 load */
    /* @4173232 cast */
    /* @4173236 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(2));
    /* @4173244 constant */
    /* @4173248 load */
    /* @4173256 cast */
    /* @4173260 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "swordstunned", VAL(1));
    /* @4173268 constant */
    /* @4173272 load */
    /* @4173280 cast */
    /* @4173284 constant */
    /* @4173288 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit10")), "alarm", VAL(5), VAL(30));
    /* @4173296 constant */
    /* @4173300 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4173308: ;
    /* @4173308 constant */
    /* @4173312 cast */
    /* @4173316 load */
    /* @4173324 load */
    /* @4173332 call */
    GM_SITE(vm, 311, 4173332);
    /* @4173340 store */
    v67 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(21));
    GM_WRITE(vm, -1, "hit11", v67);
    /* @4173348 load */
    /* @4173356 constant */
    /* @4173360 cmp */
    /* @4173364 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit11") != VAL(-4)))) goto L_4173388;
    /* @4173368 load */
    /* @4173376 constant */
    /* @4173380 cmp */
    /* @4173384 b */
    p4173392_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4173392;
    L_4173388: ;
    /* @4173388 constant */
    p4173392_0 = VAL(0);
    L_4173392: ;
    /* @4173392 bf */
    if (!TRUTH(p4173392_0)) goto L_4173612;
    /* @4173396 constant */
    /* @4173400 load */
    /* @4173408 cast */
    /* @4173412 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "flashing", VAL(1));
    /* @4173420 load */
    /* @4173428 cast */
    /* @4173432 dup */
    /* @4173436 load */
    /* @4173444 constant */
    /* @4173448 sub */
    /* @4173452 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit") - VAL(2)));
    /* @4173460 constant */
    /* @4173464 cast */
    /* @4173468 load */
    /* @4173476 cast */
    /* @4173480 load */
    /* @4173488 load */
    /* @4173496 cast */
    /* @4173500 load */
    /* @4173508 call */
    GM_SITE(vm, 311, 4173508);
    /* @4173516 store */
    v68 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit11")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit11")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v68);
    /* @4173524 constant */
    /* @4173528 load */
    /* @4173536 cast */
    /* @4173540 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(2));
    /* @4173548 constant */
    /* @4173552 load */
    /* @4173560 cast */
    /* @4173564 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "swordstunned", VAL(1));
    /* @4173572 constant */
    /* @4173576 load */
    /* @4173584 cast */
    /* @4173588 constant */
    /* @4173592 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit11")), "alarm", VAL(4), VAL(30));
    /* @4173600 constant */
    /* @4173604 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4173612: ;
    /* @4173612 constant */
    /* @4173616 cast */
    /* @4173620 load */
    /* @4173628 load */
    /* @4173636 call */
    GM_SITE(vm, 311, 4173636);
    /* @4173644 store */
    v69 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(19));
    GM_WRITE(vm, -1, "hit12", v69);
    /* @4173652 load */
    /* @4173660 constant */
    /* @4173664 cmp */
    /* @4173668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit12") != VAL(-4)))) goto L_4173692;
    /* @4173672 load */
    /* @4173680 constant */
    /* @4173684 cmp */
    /* @4173688 b */
    p4173696_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4173696;
    L_4173692: ;
    /* @4173692 constant */
    p4173696_0 = VAL(0);
    L_4173696: ;
    /* @4173696 bf */
    if (!TRUTH(p4173696_0)) goto L_4173916;
    /* @4173700 constant */
    /* @4173704 load */
    /* @4173712 cast */
    /* @4173716 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "flashing", VAL(1));
    /* @4173724 load */
    /* @4173732 cast */
    /* @4173736 dup */
    /* @4173740 load */
    /* @4173748 constant */
    /* @4173752 sub */
    /* @4173756 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie") - VAL(2)));
    /* @4173764 constant */
    /* @4173768 cast */
    /* @4173772 load */
    /* @4173780 cast */
    /* @4173784 load */
    /* @4173792 load */
    /* @4173800 cast */
    /* @4173804 load */
    /* @4173812 call */
    GM_SITE(vm, 311, 4173812);
    /* @4173820 store */
    v70 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit12")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit12")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v70);
    /* @4173828 constant */
    /* @4173832 load */
    /* @4173840 cast */
    /* @4173844 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(2));
    /* @4173852 constant */
    /* @4173856 load */
    /* @4173864 cast */
    /* @4173868 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "swordstunned", VAL(1));
    /* @4173876 constant */
    /* @4173880 load */
    /* @4173888 cast */
    /* @4173892 constant */
    /* @4173896 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit12")), "alarm", VAL(5), VAL(30));
    /* @4173904 constant */
    /* @4173908 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4173916: ;
    /* @4173916 constant */
    /* @4173920 cast */
    /* @4173924 load */
    /* @4173932 load */
    /* @4173940 call */
    GM_SITE(vm, 311, 4173940);
    /* @4173948 store */
    v71 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(18));
    GM_WRITE(vm, -1, "hit13", v71);
    /* @4173956 load */
    /* @4173964 constant */
    /* @4173968 cmp */
    /* @4173972 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit13") != VAL(-4)))) goto L_4173996;
    /* @4173976 load */
    /* @4173984 constant */
    /* @4173988 cmp */
    /* @4173992 b */
    p4174000_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4174000;
    L_4173996: ;
    /* @4173996 constant */
    p4174000_0 = VAL(0);
    L_4174000: ;
    /* @4174000 bf */
    if (!TRUTH(p4174000_0)) goto L_4174220;
    /* @4174004 constant */
    /* @4174008 load */
    /* @4174016 cast */
    /* @4174020 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "flashing", VAL(1));
    /* @4174028 load */
    /* @4174036 cast */
    /* @4174040 dup */
    /* @4174044 load */
    /* @4174052 constant */
    /* @4174056 sub */
    /* @4174060 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk") - VAL(2)));
    /* @4174068 constant */
    /* @4174072 cast */
    /* @4174076 load */
    /* @4174084 cast */
    /* @4174088 load */
    /* @4174096 load */
    /* @4174104 cast */
    /* @4174108 load */
    /* @4174116 call */
    GM_SITE(vm, 311, 4174116);
    /* @4174124 store */
    v72 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit13")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit13")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v72);
    /* @4174132 constant */
    /* @4174136 load */
    /* @4174144 cast */
    /* @4174148 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(2));
    /* @4174156 constant */
    /* @4174160 load */
    /* @4174168 cast */
    /* @4174172 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "swordstunned", VAL(1));
    /* @4174180 constant */
    /* @4174184 load */
    /* @4174192 cast */
    /* @4174196 constant */
    /* @4174200 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit13")), "alarm", VAL(5), VAL(30));
    /* @4174208 constant */
    /* @4174212 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4174220: ;
    /* @4174220 constant */
    /* @4174224 cast */
    /* @4174228 load */
    /* @4174236 load */
    /* @4174244 call */
    GM_SITE(vm, 311, 4174244);
    /* @4174252 store */
    v73 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(17));
    GM_WRITE(vm, -1, "hit14", v73);
    /* @4174260 load */
    /* @4174268 constant */
    /* @4174272 cmp */
    /* @4174276 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit14") != VAL(-4)))) goto L_4174300;
    /* @4174280 load */
    /* @4174288 constant */
    /* @4174292 cmp */
    /* @4174296 b */
    p4174304_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4174304;
    L_4174300: ;
    /* @4174300 constant */
    p4174304_0 = VAL(0);
    L_4174304: ;
    /* @4174304 bf */
    if (!TRUTH(p4174304_0)) goto L_4174524;
    /* @4174308 constant */
    /* @4174312 load */
    /* @4174320 cast */
    /* @4174324 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "flashing", VAL(1));
    /* @4174332 load */
    /* @4174340 cast */
    /* @4174344 dup */
    /* @4174348 load */
    /* @4174356 constant */
    /* @4174360 sub */
    /* @4174364 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton") - VAL(2)));
    /* @4174372 constant */
    /* @4174376 cast */
    /* @4174380 load */
    /* @4174388 cast */
    /* @4174392 load */
    /* @4174400 load */
    /* @4174408 cast */
    /* @4174412 load */
    /* @4174420 call */
    GM_SITE(vm, 311, 4174420);
    /* @4174428 store */
    v74 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit14")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit14")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v74);
    /* @4174436 constant */
    /* @4174440 load */
    /* @4174448 cast */
    /* @4174452 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(2));
    /* @4174460 constant */
    /* @4174464 load */
    /* @4174472 cast */
    /* @4174476 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "swordstunned", VAL(1));
    /* @4174484 constant */
    /* @4174488 load */
    /* @4174496 cast */
    /* @4174500 constant */
    /* @4174504 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit14")), "alarm", VAL(5), VAL(30));
    /* @4174512 constant */
    /* @4174516 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4174524: ;
    /* @4174524 constant */
    /* @4174528 cast */
    /* @4174532 load */
    /* @4174540 load */
    /* @4174548 call */
    GM_SITE(vm, 311, 4174548);
    /* @4174556 store */
    v75 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(26));
    GM_WRITE(vm, -1, "hit15", v75);
    /* @4174564 load */
    /* @4174572 constant */
    /* @4174576 cmp */
    /* @4174580 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit15") != VAL(-4)))) goto L_4174604;
    /* @4174584 load */
    /* @4174592 constant */
    /* @4174596 cmp */
    /* @4174600 b */
    p4174608_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4174608;
    L_4174604: ;
    /* @4174604 constant */
    p4174608_0 = VAL(0);
    L_4174608: ;
    /* @4174608 bf */
    if (!TRUTH(p4174608_0)) goto L_4174776;
    /* @4174612 constant */
    /* @4174616 load */
    /* @4174624 cast */
    /* @4174628 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15")), "flashing", VAL(1));
    /* @4174636 load */
    /* @4174644 cast */
    /* @4174648 dup */
    /* @4174652 load */
    /* @4174660 constant */
    /* @4174664 sub */
    /* @4174668 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2") - VAL(2)));
    /* @4174676 constant */
    /* @4174680 cast */
    /* @4174684 load */
    /* @4174692 cast */
    /* @4174696 load */
    /* @4174704 load */
    /* @4174712 cast */
    /* @4174716 load */
    /* @4174724 call */
    GM_SITE(vm, 311, 4174724);
    /* @4174732 store */
    v76 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit15")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit15")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v76);
    /* @4174740 constant */
    /* @4174744 load */
    /* @4174752 cast */
    /* @4174756 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(2));
    /* @4174764 constant */
    /* @4174768 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4174776: ;
    /* @4174776 constant */
    /* @4174780 cast */
    /* @4174784 load */
    /* @4174792 load */
    /* @4174800 call */
    GM_SITE(vm, 311, 4174800);
    /* @4174808 store */
    v77 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(27));
    GM_WRITE(vm, -1, "hit16", v77);
    /* @4174816 load */
    /* @4174824 constant */
    /* @4174828 cmp */
    /* @4174832 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit16") != VAL(-4)))) goto L_4174856;
    /* @4174836 load */
    /* @4174844 constant */
    /* @4174848 cmp */
    /* @4174852 b */
    p4174860_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4174860;
    L_4174856: ;
    /* @4174856 constant */
    p4174860_0 = VAL(0);
    L_4174860: ;
    /* @4174860 bf */
    if (!TRUTH(p4174860_0)) goto L_4175028;
    /* @4174864 constant */
    /* @4174868 load */
    /* @4174876 cast */
    /* @4174880 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16")), "flashing", VAL(1));
    /* @4174888 load */
    /* @4174896 cast */
    /* @4174900 dup */
    /* @4174904 load */
    /* @4174912 constant */
    /* @4174916 sub */
    /* @4174920 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3") - VAL(2)));
    /* @4174928 constant */
    /* @4174932 cast */
    /* @4174936 load */
    /* @4174944 cast */
    /* @4174948 load */
    /* @4174956 load */
    /* @4174964 cast */
    /* @4174968 load */
    /* @4174976 call */
    GM_SITE(vm, 311, 4174976);
    /* @4174984 store */
    v78 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit16")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit16")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v78);
    /* @4174992 constant */
    /* @4174996 load */
    /* @4175004 cast */
    /* @4175008 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(2));
    /* @4175016 constant */
    /* @4175020 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4175028: ;
    /* @4175028 constant */
    /* @4175032 cast */
    /* @4175036 load */
    /* @4175044 load */
    /* @4175052 call */
    GM_SITE(vm, 311, 4175052);
    /* @4175060 store */
    v79 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(28));
    GM_WRITE(vm, -1, "hitboss4", v79);
    /* @4175068 load */
    /* @4175076 constant */
    /* @4175080 cmp */
    /* @4175084 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss4") != VAL(-4)))) goto L_4175108;
    /* @4175088 load */
    /* @4175096 constant */
    /* @4175100 cmp */
    /* @4175104 b */
    p4175112_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4175112;
    L_4175108: ;
    /* @4175108 constant */
    p4175112_0 = VAL(0);
    L_4175112: ;
    /* @4175112 bf */
    if (!TRUTH(p4175112_0)) goto L_4175280;
    /* @4175116 constant */
    /* @4175120 load */
    /* @4175128 cast */
    /* @4175132 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "flashing", VAL(1));
    /* @4175140 load */
    /* @4175148 cast */
    /* @4175152 dup */
    /* @4175156 load */
    /* @4175164 constant */
    /* @4175168 sub */
    /* @4175172 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4") - VAL(2)));
    /* @4175180 constant */
    /* @4175184 cast */
    /* @4175188 load */
    /* @4175196 cast */
    /* @4175200 load */
    /* @4175208 load */
    /* @4175216 cast */
    /* @4175220 load */
    /* @4175228 call */
    GM_SITE(vm, 311, 4175228);
    /* @4175236 store */
    v80 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v80);
    /* @4175244 constant */
    /* @4175248 load */
    /* @4175256 cast */
    /* @4175260 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(2));
    /* @4175268 constant */
    /* @4175272 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4175280: ;
    /* @4175280 constant */
    /* @4175284 cast */
    /* @4175288 load */
    /* @4175296 load */
    /* @4175304 call */
    GM_SITE(vm, 311, 4175304);
    /* @4175312 store */
    v81 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(29));
    GM_WRITE(vm, -1, "hitboss5", v81);
    /* @4175320 load */
    /* @4175328 constant */
    /* @4175332 cmp */
    /* @4175336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss5") != VAL(-4)))) goto L_4175360;
    /* @4175340 load */
    /* @4175348 constant */
    /* @4175352 cmp */
    /* @4175356 b */
    p4175364_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4175364;
    L_4175360: ;
    /* @4175360 constant */
    p4175364_0 = VAL(0);
    L_4175364: ;
    /* @4175364 bf */
    if (!TRUTH(p4175364_0)) goto L_4175532;
    /* @4175368 constant */
    /* @4175372 load */
    /* @4175380 cast */
    /* @4175384 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "flashing", VAL(1));
    /* @4175392 load */
    /* @4175400 cast */
    /* @4175404 dup */
    /* @4175408 load */
    /* @4175416 constant */
    /* @4175420 sub */
    /* @4175424 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5") - VAL(2)));
    /* @4175432 constant */
    /* @4175436 cast */
    /* @4175440 load */
    /* @4175448 cast */
    /* @4175452 load */
    /* @4175460 load */
    /* @4175468 cast */
    /* @4175472 load */
    /* @4175480 call */
    GM_SITE(vm, 311, 4175480);
    /* @4175488 store */
    v82 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v82);
    /* @4175496 constant */
    /* @4175500 load */
    /* @4175508 cast */
    /* @4175512 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(2));
    /* @4175520 constant */
    /* @4175524 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4175532: ;
    /* @4175532 constant */
    /* @4175536 cast */
    /* @4175540 load */
    /* @4175548 load */
    /* @4175556 call */
    GM_SITE(vm, 311, 4175556);
    /* @4175564 store */
    v83 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(30));
    GM_WRITE(vm, -1, "hit17", v83);
    /* @4175572 load */
    /* @4175580 constant */
    /* @4175584 cmp */
    /* @4175588 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit17") != VAL(-4)))) goto L_4175612;
    /* @4175592 load */
    /* @4175600 constant */
    /* @4175604 cmp */
    /* @4175608 b */
    p4175616_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4175616;
    L_4175612: ;
    /* @4175612 constant */
    p4175616_0 = VAL(0);
    L_4175616: ;
    /* @4175616 bf */
    if (!TRUTH(p4175616_0)) goto L_4175784;
    /* @4175620 constant */
    /* @4175624 load */
    /* @4175632 cast */
    /* @4175636 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17")), "flashing", VAL(1));
    /* @4175644 load */
    /* @4175652 cast */
    /* @4175656 dup */
    /* @4175660 load */
    /* @4175668 constant */
    /* @4175672 sub */
    /* @4175676 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss") - VAL(2)));
    /* @4175684 constant */
    /* @4175688 cast */
    /* @4175692 load */
    /* @4175700 cast */
    /* @4175704 load */
    /* @4175712 load */
    /* @4175720 cast */
    /* @4175724 load */
    /* @4175732 call */
    GM_SITE(vm, 311, 4175732);
    /* @4175740 store */
    v84 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit17")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit17")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v84);
    /* @4175748 constant */
    /* @4175752 load */
    /* @4175760 cast */
    /* @4175764 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(2));
    /* @4175772 constant */
    /* @4175776 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4175784: ;
    /* @4175784 b */
    goto L_4187368;
    L_4175788: ;
    /* @4175788 load */
    /* @4175796 constant */
    /* @4175800 cmp */
    /* @4175804 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "sword") == VAL(2)))) goto L_4181580;
    /* @4175808 constant */
    /* @4175812 cast */
    /* @4175816 load */
    /* @4175824 load */
    /* @4175832 call */
    GM_SITE(vm, 311, 4175832);
    /* @4175840 store */
    v85 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(15));
    GM_WRITE(vm, -1, "hitknife", v85);
    /* @4175848 load */
    /* @4175856 constant */
    /* @4175860 cmp */
    /* @4175864 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitknife") != VAL(-4)))) goto L_4175888;
    /* @4175868 load */
    /* @4175876 constant */
    /* @4175880 cmp */
    /* @4175884 b */
    p4175892_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4175892;
    L_4175888: ;
    /* @4175888 constant */
    p4175892_0 = VAL(0);
    L_4175892: ;
    /* @4175892 bf */
    if (!TRUTH(p4175892_0)) goto L_4176112;
    /* @4175896 constant */
    /* @4175900 load */
    /* @4175908 cast */
    /* @4175912 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "flashing", VAL(1));
    /* @4175920 load */
    /* @4175928 cast */
    /* @4175932 dup */
    /* @4175936 load */
    /* @4175944 constant */
    /* @4175948 sub */
    /* @4175952 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife") - VAL(3)));
    /* @4175960 constant */
    /* @4175964 cast */
    /* @4175968 load */
    /* @4175976 cast */
    /* @4175980 load */
    /* @4175988 load */
    /* @4175996 cast */
    /* @4176000 load */
    /* @4176008 call */
    GM_SITE(vm, 311, 4176008);
    /* @4176016 store */
    v86 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v86);
    /* @4176024 constant */
    /* @4176028 load */
    /* @4176036 cast */
    /* @4176040 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4176048 constant */
    /* @4176052 load */
    /* @4176060 cast */
    /* @4176064 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "swordstunned", VAL(1));
    /* @4176072 constant */
    /* @4176076 load */
    /* @4176084 cast */
    /* @4176088 constant */
    /* @4176092 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "alarm", VAL(5), VAL(30));
    /* @4176100 constant */
    /* @4176104 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4176112: ;
    /* @4176112 constant */
    /* @4176116 cast */
    /* @4176120 load */
    /* @4176128 load */
    /* @4176136 call */
    GM_SITE(vm, 311, 4176136);
    /* @4176144 store */
    v87 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(24));
    GM_WRITE(vm, -1, "hitghost", v87);
    /* @4176152 load */
    /* @4176160 constant */
    /* @4176164 cmp */
    /* @4176168 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitghost") != VAL(-4)))) goto L_4176192;
    /* @4176172 load */
    /* @4176180 constant */
    /* @4176184 cmp */
    /* @4176188 b */
    p4176196_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4176196;
    L_4176192: ;
    /* @4176192 constant */
    p4176196_0 = VAL(0);
    L_4176196: ;
    /* @4176196 bf */
    if (!TRUTH(p4176196_0)) goto L_4176416;
    /* @4176200 constant */
    /* @4176204 load */
    /* @4176212 cast */
    /* @4176216 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "flashing", VAL(1));
    /* @4176224 load */
    /* @4176232 cast */
    /* @4176236 dup */
    /* @4176240 load */
    /* @4176248 constant */
    /* @4176252 sub */
    /* @4176256 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "hpghost", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "hpghost") - VAL(3)));
    /* @4176264 constant */
    /* @4176268 cast */
    /* @4176272 load */
    /* @4176280 cast */
    /* @4176284 load */
    /* @4176292 load */
    /* @4176300 cast */
    /* @4176304 load */
    /* @4176312 call */
    GM_SITE(vm, 311, 4176312);
    /* @4176320 store */
    v88 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v88);
    /* @4176328 constant */
    /* @4176332 load */
    /* @4176340 cast */
    /* @4176344 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4176352 constant */
    /* @4176356 load */
    /* @4176364 cast */
    /* @4176368 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "swordstunned", VAL(1));
    /* @4176376 constant */
    /* @4176380 load */
    /* @4176388 cast */
    /* @4176392 constant */
    /* @4176396 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "alarm", VAL(5), VAL(30));
    /* @4176404 constant */
    /* @4176408 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4176416: ;
    /* @4176416 constant */
    /* @4176420 cast */
    /* @4176424 load */
    /* @4176432 load */
    /* @4176440 call */
    GM_SITE(vm, 311, 4176440);
    /* @4176448 store */
    v89 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(23));
    GM_WRITE(vm, -1, "hitwolf", v89);
    /* @4176456 load */
    /* @4176464 constant */
    /* @4176468 cmp */
    /* @4176472 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitwolf") != VAL(-4)))) goto L_4176496;
    /* @4176476 load */
    /* @4176484 constant */
    /* @4176488 cmp */
    /* @4176492 b */
    p4176500_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4176500;
    L_4176496: ;
    /* @4176496 constant */
    p4176500_0 = VAL(0);
    L_4176500: ;
    /* @4176500 bf */
    if (!TRUTH(p4176500_0)) goto L_4176720;
    /* @4176504 constant */
    /* @4176508 load */
    /* @4176516 cast */
    /* @4176520 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "flashing", VAL(1));
    /* @4176528 load */
    /* @4176536 cast */
    /* @4176540 dup */
    /* @4176544 load */
    /* @4176552 constant */
    /* @4176556 sub */
    /* @4176560 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf") - VAL(3)));
    /* @4176568 constant */
    /* @4176572 cast */
    /* @4176576 load */
    /* @4176584 cast */
    /* @4176588 load */
    /* @4176596 load */
    /* @4176604 cast */
    /* @4176608 load */
    /* @4176616 call */
    GM_SITE(vm, 311, 4176616);
    /* @4176624 store */
    v90 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v90);
    /* @4176632 constant */
    /* @4176636 load */
    /* @4176644 cast */
    /* @4176648 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4176656 constant */
    /* @4176660 load */
    /* @4176668 cast */
    /* @4176672 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "swordstunned", VAL(1));
    /* @4176680 constant */
    /* @4176684 load */
    /* @4176692 cast */
    /* @4176696 constant */
    /* @4176700 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "alarm", VAL(5), VAL(30));
    /* @4176708 constant */
    /* @4176712 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4176720: ;
    /* @4176720 constant */
    /* @4176724 cast */
    /* @4176728 load */
    /* @4176736 load */
    /* @4176744 call */
    GM_SITE(vm, 311, 4176744);
    /* @4176752 store */
    v91 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(14));
    GM_WRITE(vm, -1, "hit", v91);
    /* @4176760 load */
    /* @4176768 constant */
    /* @4176772 cmp */
    /* @4176776 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit") != VAL(-4)))) goto L_4176800;
    /* @4176780 load */
    /* @4176788 constant */
    /* @4176792 cmp */
    /* @4176796 b */
    p4176804_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4176804;
    L_4176800: ;
    /* @4176800 constant */
    p4176804_0 = VAL(0);
    L_4176804: ;
    /* @4176804 bf */
    if (!TRUTH(p4176804_0)) goto L_4177024;
    /* @4176808 constant */
    /* @4176812 load */
    /* @4176820 cast */
    /* @4176824 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "flashing", VAL(1));
    /* @4176832 load */
    /* @4176840 cast */
    /* @4176844 dup */
    /* @4176848 load */
    /* @4176856 constant */
    /* @4176860 sub */
    /* @4176864 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp") - VAL(3)));
    /* @4176872 constant */
    /* @4176876 cast */
    /* @4176880 load */
    /* @4176888 cast */
    /* @4176892 load */
    /* @4176900 load */
    /* @4176908 cast */
    /* @4176912 load */
    /* @4176920 call */
    GM_SITE(vm, 311, 4176920);
    /* @4176928 store */
    v92 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v92);
    /* @4176936 constant */
    /* @4176940 load */
    /* @4176948 cast */
    /* @4176952 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4176960 constant */
    /* @4176964 load */
    /* @4176972 cast */
    /* @4176976 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "swordstunned", VAL(1));
    /* @4176984 constant */
    /* @4176988 load */
    /* @4176996 cast */
    /* @4177000 constant */
    /* @4177004 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit")), "alarm", VAL(5), VAL(30));
    /* @4177012 constant */
    /* @4177016 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4177024: ;
    /* @4177024 constant */
    /* @4177028 cast */
    /* @4177032 load */
    /* @4177040 load */
    /* @4177048 call */
    GM_SITE(vm, 311, 4177048);
    /* @4177056 store */
    v93 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(22));
    GM_WRITE(vm, -1, "hit2", v93);
    /* @4177064 load */
    /* @4177072 constant */
    /* @4177076 cmp */
    /* @4177080 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit2") != VAL(-4)))) goto L_4177104;
    /* @4177084 load */
    /* @4177092 constant */
    /* @4177096 cmp */
    /* @4177100 b */
    p4177108_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4177108;
    L_4177104: ;
    /* @4177104 constant */
    p4177108_0 = VAL(0);
    L_4177108: ;
    /* @4177108 bf */
    if (!TRUTH(p4177108_0)) goto L_4177328;
    /* @4177112 constant */
    /* @4177116 load */
    /* @4177124 cast */
    /* @4177128 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "flashing", VAL(1));
    /* @4177136 load */
    /* @4177144 cast */
    /* @4177148 dup */
    /* @4177152 load */
    /* @4177160 constant */
    /* @4177164 sub */
    /* @4177168 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo") - VAL(3)));
    /* @4177176 constant */
    /* @4177180 cast */
    /* @4177184 load */
    /* @4177192 cast */
    /* @4177196 load */
    /* @4177204 load */
    /* @4177212 cast */
    /* @4177216 load */
    /* @4177224 call */
    GM_SITE(vm, 311, 4177224);
    /* @4177232 store */
    v94 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit2")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit2")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v94);
    /* @4177240 constant */
    /* @4177244 load */
    /* @4177252 cast */
    /* @4177256 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4177264 constant */
    /* @4177268 load */
    /* @4177276 cast */
    /* @4177280 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "swordstunned", VAL(1));
    /* @4177288 constant */
    /* @4177292 load */
    /* @4177300 cast */
    /* @4177304 constant */
    /* @4177308 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit2")), "alarm", VAL(5), VAL(30));
    /* @4177316 constant */
    /* @4177320 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4177328: ;
    /* @4177328 constant */
    /* @4177332 cast */
    /* @4177336 load */
    /* @4177344 load */
    /* @4177352 call */
    GM_SITE(vm, 311, 4177352);
    /* @4177360 store */
    v95 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(25));
    GM_WRITE(vm, -1, "hittrex", v95);
    /* @4177368 load */
    /* @4177376 constant */
    /* @4177380 cmp */
    /* @4177384 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hittrex") != VAL(-4)))) goto L_4177408;
    /* @4177388 load */
    /* @4177396 constant */
    /* @4177400 cmp */
    /* @4177404 b */
    p4177412_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4177412;
    L_4177408: ;
    /* @4177408 constant */
    p4177412_0 = VAL(0);
    L_4177412: ;
    /* @4177412 bf */
    if (!TRUTH(p4177412_0)) goto L_4177580;
    /* @4177416 constant */
    /* @4177420 load */
    /* @4177428 cast */
    /* @4177432 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "flashing", VAL(1));
    /* @4177440 load */
    /* @4177448 cast */
    /* @4177452 dup */
    /* @4177456 load */
    /* @4177464 constant */
    /* @4177468 sub */
    /* @4177472 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex") - VAL(3)));
    /* @4177480 constant */
    /* @4177484 cast */
    /* @4177488 load */
    /* @4177496 cast */
    /* @4177500 load */
    /* @4177508 load */
    /* @4177516 cast */
    /* @4177520 load */
    /* @4177528 call */
    GM_SITE(vm, 311, 4177528);
    /* @4177536 store */
    v96 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v96);
    /* @4177544 constant */
    /* @4177548 load */
    /* @4177556 cast */
    /* @4177560 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4177568 constant */
    /* @4177572 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4177580: ;
    /* @4177580 constant */
    /* @4177584 cast */
    /* @4177588 load */
    /* @4177596 load */
    /* @4177604 call */
    GM_SITE(vm, 311, 4177604);
    /* @4177612 store */
    v97 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(31));
    GM_WRITE(vm, -1, "hit4", v97);
    /* @4177620 load */
    /* @4177628 constant */
    /* @4177632 cmp */
    /* @4177636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit4") != VAL(-4)))) goto L_4177660;
    /* @4177640 load */
    /* @4177648 constant */
    /* @4177652 cmp */
    /* @4177656 b */
    p4177664_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4177664;
    L_4177660: ;
    /* @4177660 constant */
    p4177664_0 = VAL(0);
    L_4177664: ;
    /* @4177664 bf */
    if (!TRUTH(p4177664_0)) goto L_4177884;
    /* @4177668 constant */
    /* @4177672 load */
    /* @4177680 cast */
    /* @4177684 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "flashing", VAL(1));
    /* @4177692 load */
    /* @4177700 cast */
    /* @4177704 dup */
    /* @4177708 load */
    /* @4177716 constant */
    /* @4177720 sub */
    /* @4177724 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour") - VAL(3)));
    /* @4177732 constant */
    /* @4177736 cast */
    /* @4177740 load */
    /* @4177748 cast */
    /* @4177752 load */
    /* @4177760 load */
    /* @4177768 cast */
    /* @4177772 load */
    /* @4177780 call */
    GM_SITE(vm, 311, 4177780);
    /* @4177788 store */
    v98 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit4")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit4")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v98);
    /* @4177796 constant */
    /* @4177800 load */
    /* @4177808 cast */
    /* @4177812 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4177820 constant */
    /* @4177824 load */
    /* @4177832 cast */
    /* @4177836 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "swordstunned", VAL(1));
    /* @4177844 constant */
    /* @4177848 load */
    /* @4177856 cast */
    /* @4177860 constant */
    /* @4177864 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit4")), "alarm", VAL(5), VAL(30));
    /* @4177872 constant */
    /* @4177876 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4177884: ;
    /* @4177884 constant */
    /* @4177888 cast */
    /* @4177892 load */
    /* @4177900 load */
    /* @4177908 call */
    GM_SITE(vm, 311, 4177908);
    /* @4177916 store */
    v99 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(32));
    GM_WRITE(vm, -1, "hit5", v99);
    /* @4177924 load */
    /* @4177932 constant */
    /* @4177936 cmp */
    /* @4177940 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit5") != VAL(-4)))) goto L_4177964;
    /* @4177944 load */
    /* @4177952 constant */
    /* @4177956 cmp */
    /* @4177960 b */
    p4177968_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4177968;
    L_4177964: ;
    /* @4177964 constant */
    p4177968_0 = VAL(0);
    L_4177968: ;
    /* @4177968 bf */
    if (!TRUTH(p4177968_0)) goto L_4178188;
    /* @4177972 constant */
    /* @4177976 load */
    /* @4177984 cast */
    /* @4177988 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "flashing", VAL(1));
    /* @4177996 load */
    /* @4178004 cast */
    /* @4178008 dup */
    /* @4178012 load */
    /* @4178020 constant */
    /* @4178024 sub */
    /* @4178028 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime") - VAL(3)));
    /* @4178036 constant */
    /* @4178040 cast */
    /* @4178044 load */
    /* @4178052 cast */
    /* @4178056 load */
    /* @4178064 load */
    /* @4178072 cast */
    /* @4178076 load */
    /* @4178084 call */
    GM_SITE(vm, 311, 4178084);
    /* @4178092 store */
    v100 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit5")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit5")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v100);
    /* @4178100 constant */
    /* @4178104 load */
    /* @4178112 cast */
    /* @4178116 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4178124 constant */
    /* @4178128 load */
    /* @4178136 cast */
    /* @4178140 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "swordstunned", VAL(1));
    /* @4178148 constant */
    /* @4178152 load */
    /* @4178160 cast */
    /* @4178164 constant */
    /* @4178168 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit5")), "alarm", VAL(5), VAL(30));
    /* @4178176 constant */
    /* @4178180 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4178188: ;
    /* @4178188 constant */
    /* @4178192 cast */
    /* @4178196 load */
    /* @4178204 load */
    /* @4178212 call */
    GM_SITE(vm, 311, 4178212);
    /* @4178220 store */
    v101 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(16));
    GM_WRITE(vm, -1, "hit8", v101);
    /* @4178228 load */
    /* @4178236 constant */
    /* @4178240 cmp */
    /* @4178244 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit8") != VAL(-4)))) goto L_4178268;
    /* @4178248 load */
    /* @4178256 constant */
    /* @4178260 cmp */
    /* @4178264 b */
    p4178272_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4178272;
    L_4178268: ;
    /* @4178268 constant */
    p4178272_0 = VAL(0);
    L_4178272: ;
    /* @4178272 bf */
    if (!TRUTH(p4178272_0)) goto L_4178492;
    /* @4178276 constant */
    /* @4178280 load */
    /* @4178288 cast */
    /* @4178292 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "flashing", VAL(1));
    /* @4178300 load */
    /* @4178308 cast */
    /* @4178312 dup */
    /* @4178316 load */
    /* @4178324 constant */
    /* @4178328 sub */
    /* @4178332 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1") - VAL(3)));
    /* @4178340 constant */
    /* @4178344 cast */
    /* @4178348 load */
    /* @4178356 cast */
    /* @4178360 load */
    /* @4178368 load */
    /* @4178376 cast */
    /* @4178380 load */
    /* @4178388 call */
    GM_SITE(vm, 311, 4178388);
    /* @4178396 store */
    v102 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit8")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit8")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v102);
    /* @4178404 constant */
    /* @4178408 load */
    /* @4178416 cast */
    /* @4178420 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4178428 constant */
    /* @4178432 load */
    /* @4178440 cast */
    /* @4178444 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "swordstunned", VAL(1));
    /* @4178452 constant */
    /* @4178456 load */
    /* @4178464 cast */
    /* @4178468 constant */
    /* @4178472 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit8")), "alarm", VAL(5), VAL(30));
    /* @4178480 constant */
    /* @4178484 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4178492: ;
    /* @4178492 constant */
    /* @4178496 cast */
    /* @4178500 load */
    /* @4178508 load */
    /* @4178516 call */
    GM_SITE(vm, 311, 4178516);
    /* @4178524 store */
    v103 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(20));
    GM_WRITE(vm, -1, "hit9", v103);
    /* @4178532 load */
    /* @4178540 constant */
    /* @4178544 cmp */
    /* @4178548 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit9") != VAL(-4)))) goto L_4178572;
    /* @4178552 load */
    /* @4178560 constant */
    /* @4178564 cmp */
    /* @4178568 b */
    p4178576_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4178576;
    L_4178572: ;
    /* @4178572 constant */
    p4178576_0 = VAL(0);
    L_4178576: ;
    /* @4178576 bf */
    if (!TRUTH(p4178576_0)) goto L_4178796;
    /* @4178580 constant */
    /* @4178584 load */
    /* @4178592 cast */
    /* @4178596 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "flashing", VAL(1));
    /* @4178604 load */
    /* @4178612 cast */
    /* @4178616 dup */
    /* @4178620 load */
    /* @4178628 constant */
    /* @4178632 sub */
    /* @4178636 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2") - VAL(3)));
    /* @4178644 constant */
    /* @4178648 cast */
    /* @4178652 load */
    /* @4178660 cast */
    /* @4178664 load */
    /* @4178672 load */
    /* @4178680 cast */
    /* @4178684 load */
    /* @4178692 call */
    GM_SITE(vm, 311, 4178692);
    /* @4178700 store */
    v104 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit9")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit9")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v104);
    /* @4178708 constant */
    /* @4178712 load */
    /* @4178720 cast */
    /* @4178724 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4178732 constant */
    /* @4178736 load */
    /* @4178744 cast */
    /* @4178748 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "swordstunned", VAL(1));
    /* @4178756 constant */
    /* @4178760 load */
    /* @4178768 cast */
    /* @4178772 constant */
    /* @4178776 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit9")), "alarm", VAL(5), VAL(30));
    /* @4178784 constant */
    /* @4178788 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4178796: ;
    /* @4178796 constant */
    /* @4178800 cast */
    /* @4178804 load */
    /* @4178812 load */
    /* @4178820 call */
    GM_SITE(vm, 311, 4178820);
    /* @4178828 store */
    v105 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(33));
    GM_WRITE(vm, -1, "hit10", v105);
    /* @4178836 load */
    /* @4178844 constant */
    /* @4178848 cmp */
    /* @4178852 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit10") != VAL(-4)))) goto L_4178876;
    /* @4178856 load */
    /* @4178864 constant */
    /* @4178868 cmp */
    /* @4178872 b */
    p4178880_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4178880;
    L_4178876: ;
    /* @4178876 constant */
    p4178880_0 = VAL(0);
    L_4178880: ;
    /* @4178880 bf */
    if (!TRUTH(p4178880_0)) goto L_4179100;
    /* @4178884 constant */
    /* @4178888 load */
    /* @4178896 cast */
    /* @4178900 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "flashing", VAL(1));
    /* @4178908 load */
    /* @4178916 cast */
    /* @4178920 dup */
    /* @4178924 load */
    /* @4178932 constant */
    /* @4178936 sub */
    /* @4178940 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime") - VAL(3)));
    /* @4178948 constant */
    /* @4178952 cast */
    /* @4178956 load */
    /* @4178964 cast */
    /* @4178968 load */
    /* @4178976 load */
    /* @4178984 cast */
    /* @4178988 load */
    /* @4178996 call */
    GM_SITE(vm, 311, 4178996);
    /* @4179004 store */
    v106 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit10")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit10")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v106);
    /* @4179012 constant */
    /* @4179016 load */
    /* @4179024 cast */
    /* @4179028 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4179036 constant */
    /* @4179040 load */
    /* @4179048 cast */
    /* @4179052 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "swordstunned", VAL(1));
    /* @4179060 constant */
    /* @4179064 load */
    /* @4179072 cast */
    /* @4179076 constant */
    /* @4179080 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit10")), "alarm", VAL(5), VAL(30));
    /* @4179088 constant */
    /* @4179092 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4179100: ;
    /* @4179100 constant */
    /* @4179104 cast */
    /* @4179108 load */
    /* @4179116 load */
    /* @4179124 call */
    GM_SITE(vm, 311, 4179124);
    /* @4179132 store */
    v107 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(21));
    GM_WRITE(vm, -1, "hit11", v107);
    /* @4179140 load */
    /* @4179148 constant */
    /* @4179152 cmp */
    /* @4179156 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit11") != VAL(-4)))) goto L_4179180;
    /* @4179160 load */
    /* @4179168 constant */
    /* @4179172 cmp */
    /* @4179176 b */
    p4179184_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4179184;
    L_4179180: ;
    /* @4179180 constant */
    p4179184_0 = VAL(0);
    L_4179184: ;
    /* @4179184 bf */
    if (!TRUTH(p4179184_0)) goto L_4179404;
    /* @4179188 constant */
    /* @4179192 load */
    /* @4179200 cast */
    /* @4179204 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "flashing", VAL(1));
    /* @4179212 load */
    /* @4179220 cast */
    /* @4179224 dup */
    /* @4179228 load */
    /* @4179236 constant */
    /* @4179240 sub */
    /* @4179244 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit") - VAL(3)));
    /* @4179252 constant */
    /* @4179256 cast */
    /* @4179260 load */
    /* @4179268 cast */
    /* @4179272 load */
    /* @4179280 load */
    /* @4179288 cast */
    /* @4179292 load */
    /* @4179300 call */
    GM_SITE(vm, 311, 4179300);
    /* @4179308 store */
    v108 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit11")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit11")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v108);
    /* @4179316 constant */
    /* @4179320 load */
    /* @4179328 cast */
    /* @4179332 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4179340 constant */
    /* @4179344 load */
    /* @4179352 cast */
    /* @4179356 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "swordstunned", VAL(1));
    /* @4179364 constant */
    /* @4179368 load */
    /* @4179376 cast */
    /* @4179380 constant */
    /* @4179384 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit11")), "alarm", VAL(4), VAL(30));
    /* @4179392 constant */
    /* @4179396 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4179404: ;
    /* @4179404 constant */
    /* @4179408 cast */
    /* @4179412 load */
    /* @4179420 load */
    /* @4179428 call */
    GM_SITE(vm, 311, 4179428);
    /* @4179436 store */
    v109 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(19));
    GM_WRITE(vm, -1, "hit12", v109);
    /* @4179444 load */
    /* @4179452 constant */
    /* @4179456 cmp */
    /* @4179460 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit12") != VAL(-4)))) goto L_4179484;
    /* @4179464 load */
    /* @4179472 constant */
    /* @4179476 cmp */
    /* @4179480 b */
    p4179488_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4179488;
    L_4179484: ;
    /* @4179484 constant */
    p4179488_0 = VAL(0);
    L_4179488: ;
    /* @4179488 bf */
    if (!TRUTH(p4179488_0)) goto L_4179708;
    /* @4179492 constant */
    /* @4179496 load */
    /* @4179504 cast */
    /* @4179508 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "flashing", VAL(1));
    /* @4179516 load */
    /* @4179524 cast */
    /* @4179528 dup */
    /* @4179532 load */
    /* @4179540 constant */
    /* @4179544 sub */
    /* @4179548 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie") - VAL(3)));
    /* @4179556 constant */
    /* @4179560 cast */
    /* @4179564 load */
    /* @4179572 cast */
    /* @4179576 load */
    /* @4179584 load */
    /* @4179592 cast */
    /* @4179596 load */
    /* @4179604 call */
    GM_SITE(vm, 311, 4179604);
    /* @4179612 store */
    v110 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit12")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit12")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v110);
    /* @4179620 constant */
    /* @4179624 load */
    /* @4179632 cast */
    /* @4179636 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4179644 constant */
    /* @4179648 load */
    /* @4179656 cast */
    /* @4179660 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "swordstunned", VAL(1));
    /* @4179668 constant */
    /* @4179672 load */
    /* @4179680 cast */
    /* @4179684 constant */
    /* @4179688 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit12")), "alarm", VAL(5), VAL(30));
    /* @4179696 constant */
    /* @4179700 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4179708: ;
    /* @4179708 constant */
    /* @4179712 cast */
    /* @4179716 load */
    /* @4179724 load */
    /* @4179732 call */
    GM_SITE(vm, 311, 4179732);
    /* @4179740 store */
    v111 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(18));
    GM_WRITE(vm, -1, "hit13", v111);
    /* @4179748 load */
    /* @4179756 constant */
    /* @4179760 cmp */
    /* @4179764 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit13") != VAL(-4)))) goto L_4179788;
    /* @4179768 load */
    /* @4179776 constant */
    /* @4179780 cmp */
    /* @4179784 b */
    p4179792_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4179792;
    L_4179788: ;
    /* @4179788 constant */
    p4179792_0 = VAL(0);
    L_4179792: ;
    /* @4179792 bf */
    if (!TRUTH(p4179792_0)) goto L_4180012;
    /* @4179796 constant */
    /* @4179800 load */
    /* @4179808 cast */
    /* @4179812 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "flashing", VAL(1));
    /* @4179820 load */
    /* @4179828 cast */
    /* @4179832 dup */
    /* @4179836 load */
    /* @4179844 constant */
    /* @4179848 sub */
    /* @4179852 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk") - VAL(3)));
    /* @4179860 constant */
    /* @4179864 cast */
    /* @4179868 load */
    /* @4179876 cast */
    /* @4179880 load */
    /* @4179888 load */
    /* @4179896 cast */
    /* @4179900 load */
    /* @4179908 call */
    GM_SITE(vm, 311, 4179908);
    /* @4179916 store */
    v112 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit13")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit13")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v112);
    /* @4179924 constant */
    /* @4179928 load */
    /* @4179936 cast */
    /* @4179940 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4179948 constant */
    /* @4179952 load */
    /* @4179960 cast */
    /* @4179964 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "swordstunned", VAL(1));
    /* @4179972 constant */
    /* @4179976 load */
    /* @4179984 cast */
    /* @4179988 constant */
    /* @4179992 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit13")), "alarm", VAL(5), VAL(30));
    /* @4180000 constant */
    /* @4180004 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4180012: ;
    /* @4180012 constant */
    /* @4180016 cast */
    /* @4180020 load */
    /* @4180028 load */
    /* @4180036 call */
    GM_SITE(vm, 311, 4180036);
    /* @4180044 store */
    v113 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(17));
    GM_WRITE(vm, -1, "hit14", v113);
    /* @4180052 load */
    /* @4180060 constant */
    /* @4180064 cmp */
    /* @4180068 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit14") != VAL(-4)))) goto L_4180092;
    /* @4180072 load */
    /* @4180080 constant */
    /* @4180084 cmp */
    /* @4180088 b */
    p4180096_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4180096;
    L_4180092: ;
    /* @4180092 constant */
    p4180096_0 = VAL(0);
    L_4180096: ;
    /* @4180096 bf */
    if (!TRUTH(p4180096_0)) goto L_4180316;
    /* @4180100 constant */
    /* @4180104 load */
    /* @4180112 cast */
    /* @4180116 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "flashing", VAL(1));
    /* @4180124 load */
    /* @4180132 cast */
    /* @4180136 dup */
    /* @4180140 load */
    /* @4180148 constant */
    /* @4180152 sub */
    /* @4180156 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton") - VAL(3)));
    /* @4180164 constant */
    /* @4180168 cast */
    /* @4180172 load */
    /* @4180180 cast */
    /* @4180184 load */
    /* @4180192 load */
    /* @4180200 cast */
    /* @4180204 load */
    /* @4180212 call */
    GM_SITE(vm, 311, 4180212);
    /* @4180220 store */
    v114 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit14")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit14")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v114);
    /* @4180228 constant */
    /* @4180232 load */
    /* @4180240 cast */
    /* @4180244 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4180252 constant */
    /* @4180256 load */
    /* @4180264 cast */
    /* @4180268 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "swordstunned", VAL(1));
    /* @4180276 constant */
    /* @4180280 load */
    /* @4180288 cast */
    /* @4180292 constant */
    /* @4180296 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit14")), "alarm", VAL(5), VAL(30));
    /* @4180304 constant */
    /* @4180308 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4180316: ;
    /* @4180316 constant */
    /* @4180320 cast */
    /* @4180324 load */
    /* @4180332 load */
    /* @4180340 call */
    GM_SITE(vm, 311, 4180340);
    /* @4180348 store */
    v115 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(26));
    GM_WRITE(vm, -1, "hit15", v115);
    /* @4180356 load */
    /* @4180364 constant */
    /* @4180368 cmp */
    /* @4180372 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit15") != VAL(-4)))) goto L_4180396;
    /* @4180376 load */
    /* @4180384 constant */
    /* @4180388 cmp */
    /* @4180392 b */
    p4180400_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4180400;
    L_4180396: ;
    /* @4180396 constant */
    p4180400_0 = VAL(0);
    L_4180400: ;
    /* @4180400 bf */
    if (!TRUTH(p4180400_0)) goto L_4180568;
    /* @4180404 constant */
    /* @4180408 load */
    /* @4180416 cast */
    /* @4180420 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15")), "flashing", VAL(1));
    /* @4180428 load */
    /* @4180436 cast */
    /* @4180440 dup */
    /* @4180444 load */
    /* @4180452 constant */
    /* @4180456 sub */
    /* @4180460 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2") - VAL(3)));
    /* @4180468 constant */
    /* @4180472 cast */
    /* @4180476 load */
    /* @4180484 cast */
    /* @4180488 load */
    /* @4180496 load */
    /* @4180504 cast */
    /* @4180508 load */
    /* @4180516 call */
    GM_SITE(vm, 311, 4180516);
    /* @4180524 store */
    v116 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit15")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit15")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v116);
    /* @4180532 constant */
    /* @4180536 load */
    /* @4180544 cast */
    /* @4180548 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4180556 constant */
    /* @4180560 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4180568: ;
    /* @4180568 constant */
    /* @4180572 cast */
    /* @4180576 load */
    /* @4180584 load */
    /* @4180592 call */
    GM_SITE(vm, 311, 4180592);
    /* @4180600 store */
    v117 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(27));
    GM_WRITE(vm, -1, "hit16", v117);
    /* @4180608 load */
    /* @4180616 constant */
    /* @4180620 cmp */
    /* @4180624 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit16") != VAL(-4)))) goto L_4180648;
    /* @4180628 load */
    /* @4180636 constant */
    /* @4180640 cmp */
    /* @4180644 b */
    p4180652_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4180652;
    L_4180648: ;
    /* @4180648 constant */
    p4180652_0 = VAL(0);
    L_4180652: ;
    /* @4180652 bf */
    if (!TRUTH(p4180652_0)) goto L_4180820;
    /* @4180656 constant */
    /* @4180660 load */
    /* @4180668 cast */
    /* @4180672 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16")), "flashing", VAL(1));
    /* @4180680 load */
    /* @4180688 cast */
    /* @4180692 dup */
    /* @4180696 load */
    /* @4180704 constant */
    /* @4180708 sub */
    /* @4180712 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3") - VAL(3)));
    /* @4180720 constant */
    /* @4180724 cast */
    /* @4180728 load */
    /* @4180736 cast */
    /* @4180740 load */
    /* @4180748 load */
    /* @4180756 cast */
    /* @4180760 load */
    /* @4180768 call */
    GM_SITE(vm, 311, 4180768);
    /* @4180776 store */
    v118 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit16")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit16")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v118);
    /* @4180784 constant */
    /* @4180788 load */
    /* @4180796 cast */
    /* @4180800 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4180808 constant */
    /* @4180812 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4180820: ;
    /* @4180820 constant */
    /* @4180824 cast */
    /* @4180828 load */
    /* @4180836 load */
    /* @4180844 call */
    GM_SITE(vm, 311, 4180844);
    /* @4180852 store */
    v119 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(28));
    GM_WRITE(vm, -1, "hitboss4", v119);
    /* @4180860 load */
    /* @4180868 constant */
    /* @4180872 cmp */
    /* @4180876 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss4") != VAL(-4)))) goto L_4180900;
    /* @4180880 load */
    /* @4180888 constant */
    /* @4180892 cmp */
    /* @4180896 b */
    p4180904_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4180904;
    L_4180900: ;
    /* @4180900 constant */
    p4180904_0 = VAL(0);
    L_4180904: ;
    /* @4180904 bf */
    if (!TRUTH(p4180904_0)) goto L_4181072;
    /* @4180908 constant */
    /* @4180912 load */
    /* @4180920 cast */
    /* @4180924 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "flashing", VAL(1));
    /* @4180932 load */
    /* @4180940 cast */
    /* @4180944 dup */
    /* @4180948 load */
    /* @4180956 constant */
    /* @4180960 sub */
    /* @4180964 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4") - VAL(3)));
    /* @4180972 constant */
    /* @4180976 cast */
    /* @4180980 load */
    /* @4180988 cast */
    /* @4180992 load */
    /* @4181000 load */
    /* @4181008 cast */
    /* @4181012 load */
    /* @4181020 call */
    GM_SITE(vm, 311, 4181020);
    /* @4181028 store */
    v120 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v120);
    /* @4181036 constant */
    /* @4181040 load */
    /* @4181048 cast */
    /* @4181052 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4181060 constant */
    /* @4181064 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4181072: ;
    /* @4181072 constant */
    /* @4181076 cast */
    /* @4181080 load */
    /* @4181088 load */
    /* @4181096 call */
    GM_SITE(vm, 311, 4181096);
    /* @4181104 store */
    v121 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(29));
    GM_WRITE(vm, -1, "hitboss5", v121);
    /* @4181112 load */
    /* @4181120 constant */
    /* @4181124 cmp */
    /* @4181128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss5") != VAL(-4)))) goto L_4181152;
    /* @4181132 load */
    /* @4181140 constant */
    /* @4181144 cmp */
    /* @4181148 b */
    p4181156_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4181156;
    L_4181152: ;
    /* @4181152 constant */
    p4181156_0 = VAL(0);
    L_4181156: ;
    /* @4181156 bf */
    if (!TRUTH(p4181156_0)) goto L_4181324;
    /* @4181160 constant */
    /* @4181164 load */
    /* @4181172 cast */
    /* @4181176 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "flashing", VAL(1));
    /* @4181184 load */
    /* @4181192 cast */
    /* @4181196 dup */
    /* @4181200 load */
    /* @4181208 constant */
    /* @4181212 sub */
    /* @4181216 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5") - VAL(3)));
    /* @4181224 constant */
    /* @4181228 cast */
    /* @4181232 load */
    /* @4181240 cast */
    /* @4181244 load */
    /* @4181252 load */
    /* @4181260 cast */
    /* @4181264 load */
    /* @4181272 call */
    GM_SITE(vm, 311, 4181272);
    /* @4181280 store */
    v122 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v122);
    /* @4181288 constant */
    /* @4181292 load */
    /* @4181300 cast */
    /* @4181304 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4181312 constant */
    /* @4181316 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4181324: ;
    /* @4181324 constant */
    /* @4181328 cast */
    /* @4181332 load */
    /* @4181340 load */
    /* @4181348 call */
    GM_SITE(vm, 311, 4181348);
    /* @4181356 store */
    v123 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(30));
    GM_WRITE(vm, -1, "hit17", v123);
    /* @4181364 load */
    /* @4181372 constant */
    /* @4181376 cmp */
    /* @4181380 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit17") != VAL(-4)))) goto L_4181404;
    /* @4181384 load */
    /* @4181392 constant */
    /* @4181396 cmp */
    /* @4181400 b */
    p4181408_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4181408;
    L_4181404: ;
    /* @4181404 constant */
    p4181408_0 = VAL(0);
    L_4181408: ;
    /* @4181408 bf */
    if (!TRUTH(p4181408_0)) goto L_4181576;
    /* @4181412 constant */
    /* @4181416 load */
    /* @4181424 cast */
    /* @4181428 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17")), "flashing", VAL(1));
    /* @4181436 load */
    /* @4181444 cast */
    /* @4181448 dup */
    /* @4181452 load */
    /* @4181460 constant */
    /* @4181464 sub */
    /* @4181468 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss") - VAL(3)));
    /* @4181476 constant */
    /* @4181480 cast */
    /* @4181484 load */
    /* @4181492 cast */
    /* @4181496 load */
    /* @4181504 load */
    /* @4181512 cast */
    /* @4181516 load */
    /* @4181524 call */
    GM_SITE(vm, 311, 4181524);
    /* @4181532 store */
    v124 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit17")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit17")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v124);
    /* @4181540 constant */
    /* @4181544 load */
    /* @4181552 cast */
    /* @4181556 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4181564 constant */
    /* @4181568 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4181576: ;
    /* @4181576 b */
    goto L_4187368;
    L_4181580: ;
    /* @4181580 load */
    /* @4181588 constant */
    /* @4181592 cmp */
    /* @4181596 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "sword") == VAL(3)))) goto L_4187368;
    /* @4181600 constant */
    /* @4181604 cast */
    /* @4181608 load */
    /* @4181616 load */
    /* @4181624 call */
    GM_SITE(vm, 311, 4181624);
    /* @4181632 store */
    v125 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(15));
    GM_WRITE(vm, -1, "hitknife", v125);
    /* @4181640 load */
    /* @4181648 constant */
    /* @4181652 cmp */
    /* @4181656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitknife") != VAL(-4)))) goto L_4181680;
    /* @4181660 load */
    /* @4181668 constant */
    /* @4181672 cmp */
    /* @4181676 b */
    p4181684_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4181684;
    L_4181680: ;
    /* @4181680 constant */
    p4181684_0 = VAL(0);
    L_4181684: ;
    /* @4181684 bf */
    if (!TRUTH(p4181684_0)) goto L_4181904;
    /* @4181688 constant */
    /* @4181692 load */
    /* @4181700 cast */
    /* @4181704 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "flashing", VAL(1));
    /* @4181712 load */
    /* @4181720 cast */
    /* @4181724 dup */
    /* @4181728 load */
    /* @4181736 constant */
    /* @4181740 sub */
    /* @4181744 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife") - VAL(4)));
    /* @4181752 constant */
    /* @4181756 cast */
    /* @4181760 load */
    /* @4181768 cast */
    /* @4181772 load */
    /* @4181780 load */
    /* @4181788 cast */
    /* @4181792 load */
    /* @4181800 call */
    GM_SITE(vm, 311, 4181800);
    /* @4181808 store */
    v126 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v126);
    /* @4181816 constant */
    /* @4181820 load */
    /* @4181828 cast */
    /* @4181832 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(4));
    /* @4181840 constant */
    /* @4181844 load */
    /* @4181852 cast */
    /* @4181856 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "swordstunned", VAL(1));
    /* @4181864 constant */
    /* @4181868 load */
    /* @4181876 cast */
    /* @4181880 constant */
    /* @4181884 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "alarm", VAL(5), VAL(30));
    /* @4181892 constant */
    /* @4181896 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4181904: ;
    /* @4181904 constant */
    /* @4181908 cast */
    /* @4181912 load */
    /* @4181920 load */
    /* @4181928 call */
    GM_SITE(vm, 311, 4181928);
    /* @4181936 store */
    v127 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(24));
    GM_WRITE(vm, -1, "hitghost", v127);
    /* @4181944 load */
    /* @4181952 constant */
    /* @4181956 cmp */
    /* @4181960 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitghost") != VAL(-4)))) goto L_4181984;
    /* @4181964 load */
    /* @4181972 constant */
    /* @4181976 cmp */
    /* @4181980 b */
    p4181988_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4181988;
    L_4181984: ;
    /* @4181984 constant */
    p4181988_0 = VAL(0);
    L_4181988: ;
    /* @4181988 bf */
    if (!TRUTH(p4181988_0)) goto L_4182208;
    /* @4181992 constant */
    /* @4181996 load */
    /* @4182004 cast */
    /* @4182008 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "flashing", VAL(1));
    /* @4182016 load */
    /* @4182024 cast */
    /* @4182028 dup */
    /* @4182032 load */
    /* @4182040 constant */
    /* @4182044 sub */
    /* @4182048 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "hpghost", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "hpghost") - VAL(4)));
    /* @4182056 constant */
    /* @4182060 cast */
    /* @4182064 load */
    /* @4182072 cast */
    /* @4182076 load */
    /* @4182084 load */
    /* @4182092 cast */
    /* @4182096 load */
    /* @4182104 call */
    GM_SITE(vm, 311, 4182104);
    /* @4182112 store */
    v128 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v128);
    /* @4182120 constant */
    /* @4182124 load */
    /* @4182132 cast */
    /* @4182136 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(4));
    /* @4182144 constant */
    /* @4182148 load */
    /* @4182156 cast */
    /* @4182160 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "swordstunned", VAL(1));
    /* @4182168 constant */
    /* @4182172 load */
    /* @4182180 cast */
    /* @4182184 constant */
    /* @4182188 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitghost")), "alarm", VAL(5), VAL(30));
    /* @4182196 constant */
    /* @4182200 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4182208: ;
    /* @4182208 constant */
    /* @4182212 cast */
    /* @4182216 load */
    /* @4182224 load */
    /* @4182232 call */
    GM_SITE(vm, 311, 4182232);
    /* @4182240 store */
    v129 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(23));
    GM_WRITE(vm, -1, "hitwolf", v129);
    /* @4182248 load */
    /* @4182256 constant */
    /* @4182260 cmp */
    /* @4182264 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitwolf") != VAL(-4)))) goto L_4182288;
    /* @4182268 load */
    /* @4182276 constant */
    /* @4182280 cmp */
    /* @4182284 b */
    p4182292_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4182292;
    L_4182288: ;
    /* @4182288 constant */
    p4182292_0 = VAL(0);
    L_4182292: ;
    /* @4182292 bf */
    if (!TRUTH(p4182292_0)) goto L_4182512;
    /* @4182296 constant */
    /* @4182300 load */
    /* @4182308 cast */
    /* @4182312 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "flashing", VAL(1));
    /* @4182320 load */
    /* @4182328 cast */
    /* @4182332 dup */
    /* @4182336 load */
    /* @4182344 constant */
    /* @4182348 sub */
    /* @4182352 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf") - VAL(4)));
    /* @4182360 constant */
    /* @4182364 cast */
    /* @4182368 load */
    /* @4182376 cast */
    /* @4182380 load */
    /* @4182388 load */
    /* @4182396 cast */
    /* @4182400 load */
    /* @4182408 call */
    GM_SITE(vm, 311, 4182408);
    /* @4182416 store */
    v130 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v130);
    /* @4182424 constant */
    /* @4182428 load */
    /* @4182436 cast */
    /* @4182440 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(4));
    /* @4182448 constant */
    /* @4182452 load */
    /* @4182460 cast */
    /* @4182464 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "swordstunned", VAL(1));
    /* @4182472 constant */
    /* @4182476 load */
    /* @4182484 cast */
    /* @4182488 constant */
    /* @4182492 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "alarm", VAL(5), VAL(30));
    /* @4182500 constant */
    /* @4182504 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4182512: ;
    /* @4182512 constant */
    /* @4182516 cast */
    /* @4182520 load */
    /* @4182528 load */
    /* @4182536 call */
    GM_SITE(vm, 311, 4182536);
    /* @4182544 store */
    v131 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(14));
    GM_WRITE(vm, -1, "hit", v131);
    /* @4182552 load */
    /* @4182560 constant */
    /* @4182564 cmp */
    /* @4182568 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit") != VAL(-4)))) goto L_4182592;
    /* @4182572 load */
    /* @4182580 constant */
    /* @4182584 cmp */
    /* @4182588 b */
    p4182596_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4182596;
    L_4182592: ;
    /* @4182592 constant */
    p4182596_0 = VAL(0);
    L_4182596: ;
    /* @4182596 bf */
    if (!TRUTH(p4182596_0)) goto L_4182816;
    /* @4182600 constant */
    /* @4182604 load */
    /* @4182612 cast */
    /* @4182616 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "flashing", VAL(1));
    /* @4182624 load */
    /* @4182632 cast */
    /* @4182636 dup */
    /* @4182640 load */
    /* @4182648 constant */
    /* @4182652 sub */
    /* @4182656 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp") - VAL(4)));
    /* @4182664 constant */
    /* @4182668 cast */
    /* @4182672 load */
    /* @4182680 cast */
    /* @4182684 load */
    /* @4182692 load */
    /* @4182700 cast */
    /* @4182704 load */
    /* @4182712 call */
    GM_SITE(vm, 311, 4182712);
    /* @4182720 store */
    v132 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v132);
    /* @4182728 constant */
    /* @4182732 load */
    /* @4182740 cast */
    /* @4182744 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(4));
    /* @4182752 constant */
    /* @4182756 load */
    /* @4182764 cast */
    /* @4182768 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "swordstunned", VAL(1));
    /* @4182776 constant */
    /* @4182780 load */
    /* @4182788 cast */
    /* @4182792 constant */
    /* @4182796 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit")), "alarm", VAL(5), VAL(30));
    /* @4182804 constant */
    /* @4182808 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4182816: ;
    /* @4182816 constant */
    /* @4182820 cast */
    /* @4182824 load */
    /* @4182832 load */
    /* @4182840 call */
    GM_SITE(vm, 311, 4182840);
    /* @4182848 store */
    v133 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(22));
    GM_WRITE(vm, -1, "hit2", v133);
    /* @4182856 load */
    /* @4182864 constant */
    /* @4182868 cmp */
    /* @4182872 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit2") != VAL(-4)))) goto L_4182896;
    /* @4182876 load */
    /* @4182884 constant */
    /* @4182888 cmp */
    /* @4182892 b */
    p4182900_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4182900;
    L_4182896: ;
    /* @4182896 constant */
    p4182900_0 = VAL(0);
    L_4182900: ;
    /* @4182900 bf */
    if (!TRUTH(p4182900_0)) goto L_4183120;
    /* @4182904 constant */
    /* @4182908 load */
    /* @4182916 cast */
    /* @4182920 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "flashing", VAL(1));
    /* @4182928 load */
    /* @4182936 cast */
    /* @4182940 dup */
    /* @4182944 load */
    /* @4182952 constant */
    /* @4182956 sub */
    /* @4182960 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo") - VAL(4)));
    /* @4182968 constant */
    /* @4182972 cast */
    /* @4182976 load */
    /* @4182984 cast */
    /* @4182988 load */
    /* @4182996 load */
    /* @4183004 cast */
    /* @4183008 load */
    /* @4183016 call */
    GM_SITE(vm, 311, 4183016);
    /* @4183024 store */
    v134 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit2")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit2")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v134);
    /* @4183032 constant */
    /* @4183036 load */
    /* @4183044 cast */
    /* @4183048 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(4));
    /* @4183056 constant */
    /* @4183060 load */
    /* @4183068 cast */
    /* @4183072 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "swordstunned", VAL(1));
    /* @4183080 constant */
    /* @4183084 load */
    /* @4183092 cast */
    /* @4183096 constant */
    /* @4183100 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit2")), "alarm", VAL(5), VAL(30));
    /* @4183108 constant */
    /* @4183112 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4183120: ;
    /* @4183120 constant */
    /* @4183124 cast */
    /* @4183128 load */
    /* @4183136 load */
    /* @4183144 call */
    GM_SITE(vm, 311, 4183144);
    /* @4183152 store */
    v135 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(25));
    GM_WRITE(vm, -1, "hittrex", v135);
    /* @4183160 load */
    /* @4183168 constant */
    /* @4183172 cmp */
    /* @4183176 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hittrex") != VAL(-4)))) goto L_4183200;
    /* @4183180 load */
    /* @4183188 constant */
    /* @4183192 cmp */
    /* @4183196 b */
    p4183204_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4183204;
    L_4183200: ;
    /* @4183200 constant */
    p4183204_0 = VAL(0);
    L_4183204: ;
    /* @4183204 bf */
    if (!TRUTH(p4183204_0)) goto L_4183372;
    /* @4183208 constant */
    /* @4183212 load */
    /* @4183220 cast */
    /* @4183224 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "flashing", VAL(1));
    /* @4183232 load */
    /* @4183240 cast */
    /* @4183244 dup */
    /* @4183248 load */
    /* @4183256 constant */
    /* @4183260 sub */
    /* @4183264 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex") - VAL(4)));
    /* @4183272 constant */
    /* @4183276 cast */
    /* @4183280 load */
    /* @4183288 cast */
    /* @4183292 load */
    /* @4183300 load */
    /* @4183308 cast */
    /* @4183312 load */
    /* @4183320 call */
    GM_SITE(vm, 311, 4183320);
    /* @4183328 store */
    v136 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v136);
    /* @4183336 constant */
    /* @4183340 load */
    /* @4183348 cast */
    /* @4183352 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(1));
    /* @4183360 constant */
    /* @4183364 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4183372: ;
    /* @4183372 constant */
    /* @4183376 cast */
    /* @4183380 load */
    /* @4183388 load */
    /* @4183396 call */
    GM_SITE(vm, 311, 4183396);
    /* @4183404 store */
    v137 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(31));
    GM_WRITE(vm, -1, "hit4", v137);
    /* @4183412 load */
    /* @4183420 constant */
    /* @4183424 cmp */
    /* @4183428 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit4") != VAL(-4)))) goto L_4183452;
    /* @4183432 load */
    /* @4183440 constant */
    /* @4183444 cmp */
    /* @4183448 b */
    p4183456_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4183456;
    L_4183452: ;
    /* @4183452 constant */
    p4183456_0 = VAL(0);
    L_4183456: ;
    /* @4183456 bf */
    if (!TRUTH(p4183456_0)) goto L_4183676;
    /* @4183460 constant */
    /* @4183464 load */
    /* @4183472 cast */
    /* @4183476 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "flashing", VAL(1));
    /* @4183484 load */
    /* @4183492 cast */
    /* @4183496 dup */
    /* @4183500 load */
    /* @4183508 constant */
    /* @4183512 sub */
    /* @4183516 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour") - VAL(4)));
    /* @4183524 constant */
    /* @4183528 cast */
    /* @4183532 load */
    /* @4183540 cast */
    /* @4183544 load */
    /* @4183552 load */
    /* @4183560 cast */
    /* @4183564 load */
    /* @4183572 call */
    GM_SITE(vm, 311, 4183572);
    /* @4183580 store */
    v138 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit4")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit4")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v138);
    /* @4183588 constant */
    /* @4183592 load */
    /* @4183600 cast */
    /* @4183604 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(4));
    /* @4183612 constant */
    /* @4183616 load */
    /* @4183624 cast */
    /* @4183628 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "swordstunned", VAL(1));
    /* @4183636 constant */
    /* @4183640 load */
    /* @4183648 cast */
    /* @4183652 constant */
    /* @4183656 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit4")), "alarm", VAL(5), VAL(30));
    /* @4183664 constant */
    /* @4183668 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4183676: ;
    /* @4183676 constant */
    /* @4183680 cast */
    /* @4183684 load */
    /* @4183692 load */
    /* @4183700 call */
    GM_SITE(vm, 311, 4183700);
    /* @4183708 store */
    v139 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(32));
    GM_WRITE(vm, -1, "hit5", v139);
    /* @4183716 load */
    /* @4183724 constant */
    /* @4183728 cmp */
    /* @4183732 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit5") != VAL(-4)))) goto L_4183756;
    /* @4183736 load */
    /* @4183744 constant */
    /* @4183748 cmp */
    /* @4183752 b */
    p4183760_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4183760;
    L_4183756: ;
    /* @4183756 constant */
    p4183760_0 = VAL(0);
    L_4183760: ;
    /* @4183760 bf */
    if (!TRUTH(p4183760_0)) goto L_4183980;
    /* @4183764 constant */
    /* @4183768 load */
    /* @4183776 cast */
    /* @4183780 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "flashing", VAL(1));
    /* @4183788 load */
    /* @4183796 cast */
    /* @4183800 dup */
    /* @4183804 load */
    /* @4183812 constant */
    /* @4183816 sub */
    /* @4183820 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime") - VAL(4)));
    /* @4183828 constant */
    /* @4183832 cast */
    /* @4183836 load */
    /* @4183844 cast */
    /* @4183848 load */
    /* @4183856 load */
    /* @4183864 cast */
    /* @4183868 load */
    /* @4183876 call */
    GM_SITE(vm, 311, 4183876);
    /* @4183884 store */
    v140 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit5")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit5")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v140);
    /* @4183892 constant */
    /* @4183896 load */
    /* @4183904 cast */
    /* @4183908 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(4));
    /* @4183916 constant */
    /* @4183920 load */
    /* @4183928 cast */
    /* @4183932 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "swordstunned", VAL(1));
    /* @4183940 constant */
    /* @4183944 load */
    /* @4183952 cast */
    /* @4183956 constant */
    /* @4183960 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit5")), "alarm", VAL(5), VAL(30));
    /* @4183968 constant */
    /* @4183972 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4183980: ;
    /* @4183980 constant */
    /* @4183984 cast */
    /* @4183988 load */
    /* @4183996 load */
    /* @4184004 call */
    GM_SITE(vm, 311, 4184004);
    /* @4184012 store */
    v141 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(16));
    GM_WRITE(vm, -1, "hit8", v141);
    /* @4184020 load */
    /* @4184028 constant */
    /* @4184032 cmp */
    /* @4184036 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit8") != VAL(-4)))) goto L_4184060;
    /* @4184040 load */
    /* @4184048 constant */
    /* @4184052 cmp */
    /* @4184056 b */
    p4184064_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4184064;
    L_4184060: ;
    /* @4184060 constant */
    p4184064_0 = VAL(0);
    L_4184064: ;
    /* @4184064 bf */
    if (!TRUTH(p4184064_0)) goto L_4184284;
    /* @4184068 constant */
    /* @4184072 load */
    /* @4184080 cast */
    /* @4184084 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "flashing", VAL(1));
    /* @4184092 load */
    /* @4184100 cast */
    /* @4184104 dup */
    /* @4184108 load */
    /* @4184116 constant */
    /* @4184120 sub */
    /* @4184124 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1") - VAL(4)));
    /* @4184132 constant */
    /* @4184136 cast */
    /* @4184140 load */
    /* @4184148 cast */
    /* @4184152 load */
    /* @4184160 load */
    /* @4184168 cast */
    /* @4184172 load */
    /* @4184180 call */
    GM_SITE(vm, 311, 4184180);
    /* @4184188 store */
    v142 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit8")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit8")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v142);
    /* @4184196 constant */
    /* @4184200 load */
    /* @4184208 cast */
    /* @4184212 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(4));
    /* @4184220 constant */
    /* @4184224 load */
    /* @4184232 cast */
    /* @4184236 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "swordstunned", VAL(1));
    /* @4184244 constant */
    /* @4184248 load */
    /* @4184256 cast */
    /* @4184260 constant */
    /* @4184264 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit8")), "alarm", VAL(5), VAL(30));
    /* @4184272 constant */
    /* @4184276 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4184284: ;
    /* @4184284 constant */
    /* @4184288 cast */
    /* @4184292 load */
    /* @4184300 load */
    /* @4184308 call */
    GM_SITE(vm, 311, 4184308);
    /* @4184316 store */
    v143 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(20));
    GM_WRITE(vm, -1, "hit9", v143);
    /* @4184324 load */
    /* @4184332 constant */
    /* @4184336 cmp */
    /* @4184340 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit9") != VAL(-4)))) goto L_4184364;
    /* @4184344 load */
    /* @4184352 constant */
    /* @4184356 cmp */
    /* @4184360 b */
    p4184368_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4184368;
    L_4184364: ;
    /* @4184364 constant */
    p4184368_0 = VAL(0);
    L_4184368: ;
    /* @4184368 bf */
    if (!TRUTH(p4184368_0)) goto L_4184588;
    /* @4184372 constant */
    /* @4184376 load */
    /* @4184384 cast */
    /* @4184388 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "flashing", VAL(1));
    /* @4184396 load */
    /* @4184404 cast */
    /* @4184408 dup */
    /* @4184412 load */
    /* @4184420 constant */
    /* @4184424 sub */
    /* @4184428 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2") - VAL(4)));
    /* @4184436 constant */
    /* @4184440 cast */
    /* @4184444 load */
    /* @4184452 cast */
    /* @4184456 load */
    /* @4184464 load */
    /* @4184472 cast */
    /* @4184476 load */
    /* @4184484 call */
    GM_SITE(vm, 311, 4184484);
    /* @4184492 store */
    v144 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit9")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit9")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v144);
    /* @4184500 constant */
    /* @4184504 load */
    /* @4184512 cast */
    /* @4184516 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(4));
    /* @4184524 constant */
    /* @4184528 load */
    /* @4184536 cast */
    /* @4184540 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "swordstunned", VAL(1));
    /* @4184548 constant */
    /* @4184552 load */
    /* @4184560 cast */
    /* @4184564 constant */
    /* @4184568 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit9")), "alarm", VAL(5), VAL(30));
    /* @4184576 constant */
    /* @4184580 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4184588: ;
    /* @4184588 constant */
    /* @4184592 cast */
    /* @4184596 load */
    /* @4184604 load */
    /* @4184612 call */
    GM_SITE(vm, 311, 4184612);
    /* @4184620 store */
    v145 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(33));
    GM_WRITE(vm, -1, "hit10", v145);
    /* @4184628 load */
    /* @4184636 constant */
    /* @4184640 cmp */
    /* @4184644 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit10") != VAL(-4)))) goto L_4184668;
    /* @4184648 load */
    /* @4184656 constant */
    /* @4184660 cmp */
    /* @4184664 b */
    p4184672_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4184672;
    L_4184668: ;
    /* @4184668 constant */
    p4184672_0 = VAL(0);
    L_4184672: ;
    /* @4184672 bf */
    if (!TRUTH(p4184672_0)) goto L_4184892;
    /* @4184676 constant */
    /* @4184680 load */
    /* @4184688 cast */
    /* @4184692 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "flashing", VAL(1));
    /* @4184700 load */
    /* @4184708 cast */
    /* @4184712 dup */
    /* @4184716 load */
    /* @4184724 constant */
    /* @4184728 sub */
    /* @4184732 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime") - VAL(4)));
    /* @4184740 constant */
    /* @4184744 cast */
    /* @4184748 load */
    /* @4184756 cast */
    /* @4184760 load */
    /* @4184768 load */
    /* @4184776 cast */
    /* @4184780 load */
    /* @4184788 call */
    GM_SITE(vm, 311, 4184788);
    /* @4184796 store */
    v146 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit10")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit10")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v146);
    /* @4184804 constant */
    /* @4184808 load */
    /* @4184816 cast */
    /* @4184820 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(4));
    /* @4184828 constant */
    /* @4184832 load */
    /* @4184840 cast */
    /* @4184844 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "swordstunned", VAL(1));
    /* @4184852 constant */
    /* @4184856 load */
    /* @4184864 cast */
    /* @4184868 constant */
    /* @4184872 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit10")), "alarm", VAL(5), VAL(30));
    /* @4184880 constant */
    /* @4184884 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4184892: ;
    /* @4184892 constant */
    /* @4184896 cast */
    /* @4184900 load */
    /* @4184908 load */
    /* @4184916 call */
    GM_SITE(vm, 311, 4184916);
    /* @4184924 store */
    v147 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(21));
    GM_WRITE(vm, -1, "hit11", v147);
    /* @4184932 load */
    /* @4184940 constant */
    /* @4184944 cmp */
    /* @4184948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit11") != VAL(-4)))) goto L_4184972;
    /* @4184952 load */
    /* @4184960 constant */
    /* @4184964 cmp */
    /* @4184968 b */
    p4184976_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4184976;
    L_4184972: ;
    /* @4184972 constant */
    p4184976_0 = VAL(0);
    L_4184976: ;
    /* @4184976 bf */
    if (!TRUTH(p4184976_0)) goto L_4185196;
    /* @4184980 constant */
    /* @4184984 load */
    /* @4184992 cast */
    /* @4184996 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "flashing", VAL(1));
    /* @4185004 load */
    /* @4185012 cast */
    /* @4185016 dup */
    /* @4185020 load */
    /* @4185028 constant */
    /* @4185032 sub */
    /* @4185036 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit") - VAL(4)));
    /* @4185044 constant */
    /* @4185048 cast */
    /* @4185052 load */
    /* @4185060 cast */
    /* @4185064 load */
    /* @4185072 load */
    /* @4185080 cast */
    /* @4185084 load */
    /* @4185092 call */
    GM_SITE(vm, 311, 4185092);
    /* @4185100 store */
    v148 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit11")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit11")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v148);
    /* @4185108 constant */
    /* @4185112 load */
    /* @4185120 cast */
    /* @4185124 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(4));
    /* @4185132 constant */
    /* @4185136 load */
    /* @4185144 cast */
    /* @4185148 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "swordstunned", VAL(1));
    /* @4185156 constant */
    /* @4185160 load */
    /* @4185168 cast */
    /* @4185172 constant */
    /* @4185176 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit11")), "alarm", VAL(4), VAL(30));
    /* @4185184 constant */
    /* @4185188 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4185196: ;
    /* @4185196 constant */
    /* @4185200 cast */
    /* @4185204 load */
    /* @4185212 load */
    /* @4185220 call */
    GM_SITE(vm, 311, 4185220);
    /* @4185228 store */
    v149 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(19));
    GM_WRITE(vm, -1, "hit12", v149);
    /* @4185236 load */
    /* @4185244 constant */
    /* @4185248 cmp */
    /* @4185252 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit12") != VAL(-4)))) goto L_4185276;
    /* @4185256 load */
    /* @4185264 constant */
    /* @4185268 cmp */
    /* @4185272 b */
    p4185280_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4185280;
    L_4185276: ;
    /* @4185276 constant */
    p4185280_0 = VAL(0);
    L_4185280: ;
    /* @4185280 bf */
    if (!TRUTH(p4185280_0)) goto L_4185500;
    /* @4185284 constant */
    /* @4185288 load */
    /* @4185296 cast */
    /* @4185300 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "flashing", VAL(1));
    /* @4185308 load */
    /* @4185316 cast */
    /* @4185320 dup */
    /* @4185324 load */
    /* @4185332 constant */
    /* @4185336 sub */
    /* @4185340 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie") - VAL(4)));
    /* @4185348 constant */
    /* @4185352 cast */
    /* @4185356 load */
    /* @4185364 cast */
    /* @4185368 load */
    /* @4185376 load */
    /* @4185384 cast */
    /* @4185388 load */
    /* @4185396 call */
    GM_SITE(vm, 311, 4185396);
    /* @4185404 store */
    v150 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit12")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit12")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v150);
    /* @4185412 constant */
    /* @4185416 load */
    /* @4185424 cast */
    /* @4185428 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(4));
    /* @4185436 constant */
    /* @4185440 load */
    /* @4185448 cast */
    /* @4185452 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "swordstunned", VAL(1));
    /* @4185460 constant */
    /* @4185464 load */
    /* @4185472 cast */
    /* @4185476 constant */
    /* @4185480 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit12")), "alarm", VAL(5), VAL(30));
    /* @4185488 constant */
    /* @4185492 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4185500: ;
    /* @4185500 constant */
    /* @4185504 cast */
    /* @4185508 load */
    /* @4185516 load */
    /* @4185524 call */
    GM_SITE(vm, 311, 4185524);
    /* @4185532 store */
    v151 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(18));
    GM_WRITE(vm, -1, "hit13", v151);
    /* @4185540 load */
    /* @4185548 constant */
    /* @4185552 cmp */
    /* @4185556 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit13") != VAL(-4)))) goto L_4185580;
    /* @4185560 load */
    /* @4185568 constant */
    /* @4185572 cmp */
    /* @4185576 b */
    p4185584_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4185584;
    L_4185580: ;
    /* @4185580 constant */
    p4185584_0 = VAL(0);
    L_4185584: ;
    /* @4185584 bf */
    if (!TRUTH(p4185584_0)) goto L_4185804;
    /* @4185588 constant */
    /* @4185592 load */
    /* @4185600 cast */
    /* @4185604 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "flashing", VAL(1));
    /* @4185612 load */
    /* @4185620 cast */
    /* @4185624 dup */
    /* @4185628 load */
    /* @4185636 constant */
    /* @4185640 sub */
    /* @4185644 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk") - VAL(4)));
    /* @4185652 constant */
    /* @4185656 cast */
    /* @4185660 load */
    /* @4185668 cast */
    /* @4185672 load */
    /* @4185680 load */
    /* @4185688 cast */
    /* @4185692 load */
    /* @4185700 call */
    GM_SITE(vm, 311, 4185700);
    /* @4185708 store */
    v152 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit13")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit13")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v152);
    /* @4185716 constant */
    /* @4185720 load */
    /* @4185728 cast */
    /* @4185732 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(4));
    /* @4185740 constant */
    /* @4185744 load */
    /* @4185752 cast */
    /* @4185756 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "swordstunned", VAL(1));
    /* @4185764 constant */
    /* @4185768 load */
    /* @4185776 cast */
    /* @4185780 constant */
    /* @4185784 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit13")), "alarm", VAL(5), VAL(30));
    /* @4185792 constant */
    /* @4185796 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4185804: ;
    /* @4185804 constant */
    /* @4185808 cast */
    /* @4185812 load */
    /* @4185820 load */
    /* @4185828 call */
    GM_SITE(vm, 311, 4185828);
    /* @4185836 store */
    v153 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(17));
    GM_WRITE(vm, -1, "hit14", v153);
    /* @4185844 load */
    /* @4185852 constant */
    /* @4185856 cmp */
    /* @4185860 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit14") != VAL(-4)))) goto L_4185884;
    /* @4185864 load */
    /* @4185872 constant */
    /* @4185876 cmp */
    /* @4185880 b */
    p4185888_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4185888;
    L_4185884: ;
    /* @4185884 constant */
    p4185888_0 = VAL(0);
    L_4185888: ;
    /* @4185888 bf */
    if (!TRUTH(p4185888_0)) goto L_4186108;
    /* @4185892 constant */
    /* @4185896 load */
    /* @4185904 cast */
    /* @4185908 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "flashing", VAL(1));
    /* @4185916 load */
    /* @4185924 cast */
    /* @4185928 dup */
    /* @4185932 load */
    /* @4185940 constant */
    /* @4185944 sub */
    /* @4185948 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton") - VAL(4)));
    /* @4185956 constant */
    /* @4185960 cast */
    /* @4185964 load */
    /* @4185972 cast */
    /* @4185976 load */
    /* @4185984 load */
    /* @4185992 cast */
    /* @4185996 load */
    /* @4186004 call */
    GM_SITE(vm, 311, 4186004);
    /* @4186012 store */
    v154 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit14")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit14")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v154);
    /* @4186020 constant */
    /* @4186024 load */
    /* @4186032 cast */
    /* @4186036 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(4));
    /* @4186044 constant */
    /* @4186048 load */
    /* @4186056 cast */
    /* @4186060 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "swordstunned", VAL(1));
    /* @4186068 constant */
    /* @4186072 load */
    /* @4186080 cast */
    /* @4186084 constant */
    /* @4186088 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit14")), "alarm", VAL(5), VAL(30));
    /* @4186096 constant */
    /* @4186100 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4186108: ;
    /* @4186108 constant */
    /* @4186112 cast */
    /* @4186116 load */
    /* @4186124 load */
    /* @4186132 call */
    GM_SITE(vm, 311, 4186132);
    /* @4186140 store */
    v155 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(26));
    GM_WRITE(vm, -1, "hit15", v155);
    /* @4186148 load */
    /* @4186156 constant */
    /* @4186160 cmp */
    /* @4186164 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit15") != VAL(-4)))) goto L_4186188;
    /* @4186168 load */
    /* @4186176 constant */
    /* @4186180 cmp */
    /* @4186184 b */
    p4186192_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4186192;
    L_4186188: ;
    /* @4186188 constant */
    p4186192_0 = VAL(0);
    L_4186192: ;
    /* @4186192 bf */
    if (!TRUTH(p4186192_0)) goto L_4186360;
    /* @4186196 constant */
    /* @4186200 load */
    /* @4186208 cast */
    /* @4186212 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15")), "flashing", VAL(1));
    /* @4186220 load */
    /* @4186228 cast */
    /* @4186232 dup */
    /* @4186236 load */
    /* @4186244 constant */
    /* @4186248 sub */
    /* @4186252 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2") - VAL(4)));
    /* @4186260 constant */
    /* @4186264 cast */
    /* @4186268 load */
    /* @4186276 cast */
    /* @4186280 load */
    /* @4186288 load */
    /* @4186296 cast */
    /* @4186300 load */
    /* @4186308 call */
    GM_SITE(vm, 311, 4186308);
    /* @4186316 store */
    v156 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit15")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit15")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v156);
    /* @4186324 constant */
    /* @4186328 load */
    /* @4186336 cast */
    /* @4186340 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(4));
    /* @4186348 constant */
    /* @4186352 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4186360: ;
    /* @4186360 constant */
    /* @4186364 cast */
    /* @4186368 load */
    /* @4186376 load */
    /* @4186384 call */
    GM_SITE(vm, 311, 4186384);
    /* @4186392 store */
    v157 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(27));
    GM_WRITE(vm, -1, "hit16", v157);
    /* @4186400 load */
    /* @4186408 constant */
    /* @4186412 cmp */
    /* @4186416 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit16") != VAL(-4)))) goto L_4186440;
    /* @4186420 load */
    /* @4186428 constant */
    /* @4186432 cmp */
    /* @4186436 b */
    p4186444_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4186444;
    L_4186440: ;
    /* @4186440 constant */
    p4186444_0 = VAL(0);
    L_4186444: ;
    /* @4186444 bf */
    if (!TRUTH(p4186444_0)) goto L_4186612;
    /* @4186448 constant */
    /* @4186452 load */
    /* @4186460 cast */
    /* @4186464 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16")), "flashing", VAL(1));
    /* @4186472 load */
    /* @4186480 cast */
    /* @4186484 dup */
    /* @4186488 load */
    /* @4186496 constant */
    /* @4186500 sub */
    /* @4186504 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3") - VAL(4)));
    /* @4186512 constant */
    /* @4186516 cast */
    /* @4186520 load */
    /* @4186528 cast */
    /* @4186532 load */
    /* @4186540 load */
    /* @4186548 cast */
    /* @4186552 load */
    /* @4186560 call */
    GM_SITE(vm, 311, 4186560);
    /* @4186568 store */
    v158 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit16")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit16")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v158);
    /* @4186576 constant */
    /* @4186580 load */
    /* @4186588 cast */
    /* @4186592 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(4));
    /* @4186600 constant */
    /* @4186604 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4186612: ;
    /* @4186612 constant */
    /* @4186616 cast */
    /* @4186620 load */
    /* @4186628 load */
    /* @4186636 call */
    GM_SITE(vm, 311, 4186636);
    /* @4186644 store */
    v159 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(28));
    GM_WRITE(vm, -1, "hitboss4", v159);
    /* @4186652 load */
    /* @4186660 constant */
    /* @4186664 cmp */
    /* @4186668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss4") != VAL(-4)))) goto L_4186692;
    /* @4186672 load */
    /* @4186680 constant */
    /* @4186684 cmp */
    /* @4186688 b */
    p4186696_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4186696;
    L_4186692: ;
    /* @4186692 constant */
    p4186696_0 = VAL(0);
    L_4186696: ;
    /* @4186696 bf */
    if (!TRUTH(p4186696_0)) goto L_4186864;
    /* @4186700 constant */
    /* @4186704 load */
    /* @4186712 cast */
    /* @4186716 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "flashing", VAL(1));
    /* @4186724 load */
    /* @4186732 cast */
    /* @4186736 dup */
    /* @4186740 load */
    /* @4186748 constant */
    /* @4186752 sub */
    /* @4186756 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4") - VAL(4)));
    /* @4186764 constant */
    /* @4186768 cast */
    /* @4186772 load */
    /* @4186780 cast */
    /* @4186784 load */
    /* @4186792 load */
    /* @4186800 cast */
    /* @4186804 load */
    /* @4186812 call */
    GM_SITE(vm, 311, 4186812);
    /* @4186820 store */
    v160 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v160);
    /* @4186828 constant */
    /* @4186832 load */
    /* @4186840 cast */
    /* @4186844 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(4));
    /* @4186852 constant */
    /* @4186856 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4186864: ;
    /* @4186864 constant */
    /* @4186868 cast */
    /* @4186872 load */
    /* @4186880 load */
    /* @4186888 call */
    GM_SITE(vm, 311, 4186888);
    /* @4186896 store */
    v161 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(29));
    GM_WRITE(vm, -1, "hitboss5", v161);
    /* @4186904 load */
    /* @4186912 constant */
    /* @4186916 cmp */
    /* @4186920 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss5") != VAL(-4)))) goto L_4186944;
    /* @4186924 load */
    /* @4186932 constant */
    /* @4186936 cmp */
    /* @4186940 b */
    p4186948_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4186948;
    L_4186944: ;
    /* @4186944 constant */
    p4186948_0 = VAL(0);
    L_4186948: ;
    /* @4186948 bf */
    if (!TRUTH(p4186948_0)) goto L_4187116;
    /* @4186952 constant */
    /* @4186956 load */
    /* @4186964 cast */
    /* @4186968 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "flashing", VAL(1));
    /* @4186976 load */
    /* @4186984 cast */
    /* @4186988 dup */
    /* @4186992 load */
    /* @4187000 constant */
    /* @4187004 sub */
    /* @4187008 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5") - VAL(4)));
    /* @4187016 constant */
    /* @4187020 cast */
    /* @4187024 load */
    /* @4187032 cast */
    /* @4187036 load */
    /* @4187044 load */
    /* @4187052 cast */
    /* @4187056 load */
    /* @4187064 call */
    GM_SITE(vm, 311, 4187064);
    /* @4187072 store */
    v162 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v162);
    /* @4187080 constant */
    /* @4187084 load */
    /* @4187092 cast */
    /* @4187096 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(4));
    /* @4187104 constant */
    /* @4187108 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4187116: ;
    /* @4187116 constant */
    /* @4187120 cast */
    /* @4187124 load */
    /* @4187132 load */
    /* @4187140 call */
    GM_SITE(vm, 311, 4187140);
    /* @4187148 store */
    v163 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(30));
    GM_WRITE(vm, -1, "hit17", v163);
    /* @4187156 load */
    /* @4187164 constant */
    /* @4187168 cmp */
    /* @4187172 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit17") != VAL(-4)))) goto L_4187196;
    /* @4187176 load */
    /* @4187184 constant */
    /* @4187188 cmp */
    /* @4187192 b */
    p4187200_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4187200;
    L_4187196: ;
    /* @4187196 constant */
    p4187200_0 = VAL(0);
    L_4187200: ;
    /* @4187200 bf */
    if (!TRUTH(p4187200_0)) goto L_4187368;
    /* @4187204 constant */
    /* @4187208 load */
    /* @4187216 cast */
    /* @4187220 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17")), "flashing", VAL(1));
    /* @4187228 load */
    /* @4187236 cast */
    /* @4187240 dup */
    /* @4187244 load */
    /* @4187252 constant */
    /* @4187256 sub */
    /* @4187260 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss") - VAL(4)));
    /* @4187268 constant */
    /* @4187272 cast */
    /* @4187276 load */
    /* @4187284 cast */
    /* @4187288 load */
    /* @4187296 load */
    /* @4187304 cast */
    /* @4187308 load */
    /* @4187316 call */
    GM_SITE(vm, 311, 4187316);
    /* @4187324 store */
    v164 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit17")), "x"), GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit17")), "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v164);
    /* @4187332 constant */
    /* @4187336 load */
    /* @4187344 cast */
    /* @4187348 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(4));
    /* @4187356 constant */
    /* @4187360 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4187368: ;
    return;
}
