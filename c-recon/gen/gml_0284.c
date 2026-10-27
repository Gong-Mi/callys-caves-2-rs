/* generated from CODE 284 (gml_Object_obj_bullet_Step_0), source start 4090476, end 4107044. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0284(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val p4090668_0;
    Val v4;
    Val v5;
    Val v6;
    Val v7;
    Val v8;
    Val v9;
    Val v10;
    Val p4091516_0;
    Val v11;
    Val v12;
    Val v13;
    Val v14;
    Val v15;
    Val v16;
    Val v17;
    Val p4092364_0;
    Val v18;
    Val v19;
    Val v20;
    Val v21;
    Val v22;
    Val v23;
    Val v24;
    Val p4093212_0;
    Val v25;
    Val v26;
    Val v27;
    Val v28;
    Val v29;
    Val v30;
    Val v31;
    Val p4094060_0;
    Val v32;
    Val v33;
    Val v34;
    Val v35;
    Val v36;
    Val v37;
    Val v38;
    Val p4094856_0;
    Val v39;
    Val v40;
    Val v41;
    Val v42;
    Val v43;
    Val v44;
    Val v45;
    Val p4095704_0;
    Val v46;
    Val v47;
    Val v48;
    Val v49;
    Val v50;
    Val v51;
    Val v52;
    Val p4096552_0;
    Val v53;
    Val v54;
    Val v55;
    Val v56;
    Val v57;
    Val v58;
    Val v59;
    Val p4097400_0;
    Val v60;
    Val v61;
    Val v62;
    Val v63;
    Val v64;
    Val v65;
    Val v66;
    Val p4098248_0;
    Val v67;
    Val v68;
    Val v69;
    Val v70;
    Val v71;
    Val v72;
    Val v73;
    Val p4099096_0;
    Val v74;
    Val v75;
    Val v76;
    Val v77;
    Val v78;
    Val v79;
    Val v80;
    Val p4099944_0;
    Val v81;
    Val v82;
    Val v83;
    Val v84;
    Val v85;
    Val v86;
    Val v87;
    Val p4100792_0;
    Val v88;
    Val v89;
    Val v90;
    Val v91;
    Val v92;
    Val v93;
    Val v94;
    Val p4101640_0;
    Val v95;
    Val v96;
    Val v97;
    Val v98;
    Val v99;
    Val v100;
    Val v101;
    Val p4102488_0;
    Val v102;
    Val v103;
    Val v104;
    Val v105;
    Val v106;
    Val v107;
    Val v108;
    Val p4103336_0;
    Val v109;
    Val v110;
    Val v111;
    Val v112;
    Val v113;
    Val v114;
    Val v115;
    Val p4104132_0;
    Val v116;
    Val v117;
    Val v118;
    Val v119;
    Val v120;
    Val v121;
    Val v122;
    Val p4104884_0;
    Val v123;
    Val v124;
    Val v125;
    Val v126;
    Val v127;
    Val v128;
    Val v129;
    Val p4105632_0;
    Val v130;
    Val v131;
    Val v132;
    Val v133;
    Val v134;
    Val v135;
    Val v136;
    Val p4106380_0;
    Val v137;
    Val v138;
    Val v139;
    Val v140;
    Val v141;
    Val v142;
    /* @4090476 constant */
    /* @4090480 cast */
    /* @4090484 load */
    /* @4090492 load */
    /* @4090500 call */
    GM_SITE(vm, 284, 4090500);
    /* @4090508 cast */
    /* @4090512 bf */
    v1 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v1)) goto L_4090568;
    /* @4090516 constant */
    /* @4090520 cast */
    /* @4090524 load */
    /* @4090532 load */
    /* @4090540 call */
    GM_SITE(vm, 284, 4090540);
    /* @4090548 store */
    v2 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(13));
    GM_WRITE(vm, -1, "i1", v2);
    /* @4090556 call */
    GM_SITE(vm, 284, 4090556);
    /* @4090564 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4090568: ;
    /* @4090568 load */
    /* @4090576 store */
    GM_WRITE(vm, -1, "image_angle", GM_READ(vm, -1, "direction"));
    /* @4090584 constant */
    /* @4090588 cast */
    /* @4090592 load */
    /* @4090600 load */
    /* @4090608 call */
    GM_SITE(vm, 284, 4090608);
    /* @4090616 store */
    v3 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(15));
    GM_WRITE(vm, -1, "hitknife", v3);
    /* @4090624 load */
    /* @4090632 constant */
    /* @4090636 cmp */
    /* @4090640 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitknife") != VAL(-4)))) goto L_4090664;
    /* @4090644 load */
    /* @4090652 constant */
    /* @4090656 cmp */
    /* @4090660 b */
    p4090668_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4090668;
    L_4090664: ;
    /* @4090664 constant */
    p4090668_0 = VAL(0);
    L_4090668: ;
    /* @4090668 bf */
    if (!TRUTH(p4090668_0)) goto L_4091432;
    /* @4090672 constant */
    /* @4090676 load */
    /* @4090684 cast */
    /* @4090688 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "flashing", VAL(1));
    /* @4090696 constant */
    /* @4090700 cast */
    /* @4090704 load */
    /* @4090712 load */
    /* @4090720 load */
    /* @4090728 load */
    /* @4090736 call */
    GM_SITE(vm, 284, 4090736);
    /* @4090744 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4090748 constant */
    /* @4090752 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4090760 load */
    /* @4090768 constant */
    /* @4090772 cmp */
    /* @4090776 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4090916;
    /* @4090780 load */
    /* @4090788 cast */
    /* @4090792 dup */
    /* @4090796 load */
    /* @4090804 load */
    /* @4090812 sub */
    /* @4090816 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife") - GM_READ(vm, -5, "pistoldamage")));
    /* @4090824 constant */
    /* @4090828 cast */
    /* @4090832 load */
    /* @4090840 load */
    /* @4090848 call */
    GM_SITE(vm, 284, 4090848);
    /* @4090856 store */
    v4 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v4);
    /* @4090864 load */
    /* @4090872 load */
    /* @4090880 cast */
    /* @4090884 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "pistoldamage"));
    /* @4090892 load */
    /* @4090900 constant */
    /* @4090904 add */
    /* @4090908 store */
    v5 = GM_ADD(GM_READ(vm, -5, "pistolxp"), VAL(1));
    GM_WRITE(vm, -5, "pistolxp", v5);
    L_4090916: ;
    /* @4090916 load */
    /* @4090924 constant */
    /* @4090928 cmp */
    /* @4090932 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4091072;
    /* @4090936 load */
    /* @4090944 cast */
    /* @4090948 dup */
    /* @4090952 load */
    /* @4090960 load */
    /* @4090968 sub */
    /* @4090972 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife") - GM_READ(vm, -5, "shotgundamage")));
    /* @4090980 constant */
    /* @4090984 cast */
    /* @4090988 load */
    /* @4090996 load */
    /* @4091004 call */
    GM_SITE(vm, 284, 4091004);
    /* @4091012 store */
    v6 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v6);
    /* @4091020 load */
    /* @4091028 load */
    /* @4091036 cast */
    /* @4091040 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "shotgundamage"));
    /* @4091048 load */
    /* @4091056 constant */
    /* @4091060 add */
    /* @4091064 store */
    v7 = GM_ADD(GM_READ(vm, -5, "shotgunxp"), VAL(1));
    GM_WRITE(vm, -5, "shotgunxp", v7);
    L_4091072: ;
    /* @4091072 load */
    /* @4091080 constant */
    /* @4091084 cmp */
    /* @4091088 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4091228;
    /* @4091092 load */
    /* @4091100 cast */
    /* @4091104 dup */
    /* @4091108 load */
    /* @4091116 load */
    /* @4091124 sub */
    /* @4091128 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife") - GM_READ(vm, -5, "assaultrifledamage")));
    /* @4091136 constant */
    /* @4091140 cast */
    /* @4091144 load */
    /* @4091152 load */
    /* @4091160 call */
    GM_SITE(vm, 284, 4091160);
    /* @4091168 store */
    v8 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v8);
    /* @4091176 load */
    /* @4091184 load */
    /* @4091192 cast */
    /* @4091196 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "assaultrifledamage"));
    /* @4091204 load */
    /* @4091212 constant */
    /* @4091216 add */
    /* @4091220 store */
    v9 = GM_ADD(GM_READ(vm, -5, "assaultriflexp"), VAL(1));
    GM_WRITE(vm, -5, "assaultriflexp", v9);
    L_4091228: ;
    /* @4091228 constant */
    /* @4091232 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4091240 load */
    /* @4091248 constant */
    /* @4091252 cmp */
    /* @4091256 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4091264;
    /* @4091260 b */
    goto L_4091320;
    L_4091264: ;
    /* @4091264 load */
    /* @4091272 constant */
    /* @4091276 cmp */
    /* @4091280 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4091320;
    /* @4091284 constant */
    /* @4091288 cast */
    /* @4091292 constant */
    /* @4091296 cast */
    /* @4091300 constant */
    /* @4091304 cast */
    /* @4091308 call */
    GM_SITE(vm, 284, 4091308);
    /* @4091316 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4091320: ;
    /* @4091320 call */
    GM_SITE(vm, 284, 4091320);
    /* @4091328 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4091332 constant */
    /* @4091336 load */
    /* @4091344 cast */
    /* @4091348 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "stunned", VAL(1));
    /* @4091356 constant */
    /* @4091360 load */
    /* @4091368 cast */
    /* @4091372 constant */
    /* @4091376 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "alarm", VAL(4), VAL(10));
    /* @4091384 load */
    /* @4091392 constant */
    /* @4091396 cmp */
    /* @4091400 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4091432;
    /* @4091404 constant */
    /* @4091408 load */
    /* @4091416 cast */
    /* @4091420 constant */
    /* @4091424 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "alarm", VAL(6), VAL(1));
    L_4091432: ;
    /* @4091432 constant */
    /* @4091436 cast */
    /* @4091440 load */
    /* @4091448 load */
    /* @4091456 call */
    GM_SITE(vm, 284, 4091456);
    /* @4091464 store */
    v10 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(23));
    GM_WRITE(vm, -1, "hitwolf", v10);
    /* @4091472 load */
    /* @4091480 constant */
    /* @4091484 cmp */
    /* @4091488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitwolf") != VAL(-4)))) goto L_4091512;
    /* @4091492 load */
    /* @4091500 constant */
    /* @4091504 cmp */
    /* @4091508 b */
    p4091516_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4091516;
    L_4091512: ;
    /* @4091512 constant */
    p4091516_0 = VAL(0);
    L_4091516: ;
    /* @4091516 bf */
    if (!TRUTH(p4091516_0)) goto L_4092280;
    /* @4091520 constant */
    /* @4091524 load */
    /* @4091532 cast */
    /* @4091536 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "flashing", VAL(1));
    /* @4091544 constant */
    /* @4091548 cast */
    /* @4091552 load */
    /* @4091560 load */
    /* @4091568 load */
    /* @4091576 load */
    /* @4091584 call */
    GM_SITE(vm, 284, 4091584);
    /* @4091592 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4091596 constant */
    /* @4091600 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4091608 load */
    /* @4091616 constant */
    /* @4091620 cmp */
    /* @4091624 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4091764;
    /* @4091628 load */
    /* @4091636 cast */
    /* @4091640 dup */
    /* @4091644 load */
    /* @4091652 load */
    /* @4091660 sub */
    /* @4091664 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf") - GM_READ(vm, -5, "pistoldamage")));
    /* @4091672 constant */
    /* @4091676 cast */
    /* @4091680 load */
    /* @4091688 load */
    /* @4091696 call */
    GM_SITE(vm, 284, 4091696);
    /* @4091704 store */
    v11 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v11);
    /* @4091712 load */
    /* @4091720 load */
    /* @4091728 cast */
    /* @4091732 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "pistoldamage"));
    /* @4091740 load */
    /* @4091748 constant */
    /* @4091752 add */
    /* @4091756 store */
    v12 = GM_ADD(GM_READ(vm, -5, "pistolxp"), VAL(1));
    GM_WRITE(vm, -5, "pistolxp", v12);
    L_4091764: ;
    /* @4091764 load */
    /* @4091772 constant */
    /* @4091776 cmp */
    /* @4091780 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4091920;
    /* @4091784 load */
    /* @4091792 cast */
    /* @4091796 dup */
    /* @4091800 load */
    /* @4091808 load */
    /* @4091816 sub */
    /* @4091820 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf") - GM_READ(vm, -5, "shotgundamage")));
    /* @4091828 constant */
    /* @4091832 cast */
    /* @4091836 load */
    /* @4091844 load */
    /* @4091852 call */
    GM_SITE(vm, 284, 4091852);
    /* @4091860 store */
    v13 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v13);
    /* @4091868 load */
    /* @4091876 load */
    /* @4091884 cast */
    /* @4091888 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "shotgundamage"));
    /* @4091896 load */
    /* @4091904 constant */
    /* @4091908 add */
    /* @4091912 store */
    v14 = GM_ADD(GM_READ(vm, -5, "shotgunxp"), VAL(1));
    GM_WRITE(vm, -5, "shotgunxp", v14);
    L_4091920: ;
    /* @4091920 load */
    /* @4091928 constant */
    /* @4091932 cmp */
    /* @4091936 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4092076;
    /* @4091940 load */
    /* @4091948 cast */
    /* @4091952 dup */
    /* @4091956 load */
    /* @4091964 load */
    /* @4091972 sub */
    /* @4091976 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf") - GM_READ(vm, -5, "assaultrifledamage")));
    /* @4091984 constant */
    /* @4091988 cast */
    /* @4091992 load */
    /* @4092000 load */
    /* @4092008 call */
    GM_SITE(vm, 284, 4092008);
    /* @4092016 store */
    v15 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v15);
    /* @4092024 load */
    /* @4092032 load */
    /* @4092040 cast */
    /* @4092044 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "assaultrifledamage"));
    /* @4092052 load */
    /* @4092060 constant */
    /* @4092064 add */
    /* @4092068 store */
    v16 = GM_ADD(GM_READ(vm, -5, "assaultriflexp"), VAL(1));
    GM_WRITE(vm, -5, "assaultriflexp", v16);
    L_4092076: ;
    /* @4092076 constant */
    /* @4092080 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4092088 load */
    /* @4092096 constant */
    /* @4092100 cmp */
    /* @4092104 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4092112;
    /* @4092108 b */
    goto L_4092168;
    L_4092112: ;
    /* @4092112 load */
    /* @4092120 constant */
    /* @4092124 cmp */
    /* @4092128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4092168;
    /* @4092132 constant */
    /* @4092136 cast */
    /* @4092140 constant */
    /* @4092144 cast */
    /* @4092148 constant */
    /* @4092152 cast */
    /* @4092156 call */
    GM_SITE(vm, 284, 4092156);
    /* @4092164 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4092168: ;
    /* @4092168 call */
    GM_SITE(vm, 284, 4092168);
    /* @4092176 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4092180 constant */
    /* @4092184 load */
    /* @4092192 cast */
    /* @4092196 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "stunned", VAL(1));
    /* @4092204 constant */
    /* @4092208 load */
    /* @4092216 cast */
    /* @4092220 constant */
    /* @4092224 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "alarm", VAL(4), VAL(10));
    /* @4092232 load */
    /* @4092240 constant */
    /* @4092244 cmp */
    /* @4092248 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4092280;
    /* @4092252 constant */
    /* @4092256 load */
    /* @4092264 cast */
    /* @4092268 constant */
    /* @4092272 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "alarm", VAL(6), VAL(1));
    L_4092280: ;
    /* @4092280 constant */
    /* @4092284 cast */
    /* @4092288 load */
    /* @4092296 load */
    /* @4092304 call */
    GM_SITE(vm, 284, 4092304);
    /* @4092312 store */
    v17 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(14));
    GM_WRITE(vm, -1, "hit", v17);
    /* @4092320 load */
    /* @4092328 constant */
    /* @4092332 cmp */
    /* @4092336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit") != VAL(-4)))) goto L_4092360;
    /* @4092340 load */
    /* @4092348 constant */
    /* @4092352 cmp */
    /* @4092356 b */
    p4092364_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4092364;
    L_4092360: ;
    /* @4092360 constant */
    p4092364_0 = VAL(0);
    L_4092364: ;
    /* @4092364 bf */
    if (!TRUTH(p4092364_0)) goto L_4093128;
    /* @4092368 constant */
    /* @4092372 load */
    /* @4092380 cast */
    /* @4092384 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "flashing", VAL(1));
    /* @4092392 constant */
    /* @4092396 cast */
    /* @4092400 load */
    /* @4092408 load */
    /* @4092416 load */
    /* @4092424 load */
    /* @4092432 call */
    GM_SITE(vm, 284, 4092432);
    /* @4092440 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4092444 constant */
    /* @4092448 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4092456 load */
    /* @4092464 constant */
    /* @4092468 cmp */
    /* @4092472 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4092612;
    /* @4092476 load */
    /* @4092484 cast */
    /* @4092488 dup */
    /* @4092492 load */
    /* @4092500 load */
    /* @4092508 sub */
    /* @4092512 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp") - GM_READ(vm, -5, "pistoldamage")));
    /* @4092520 constant */
    /* @4092524 cast */
    /* @4092528 load */
    /* @4092536 load */
    /* @4092544 call */
    GM_SITE(vm, 284, 4092544);
    /* @4092552 store */
    v18 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v18);
    /* @4092560 load */
    /* @4092568 load */
    /* @4092576 cast */
    /* @4092580 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "pistoldamage"));
    /* @4092588 load */
    /* @4092596 constant */
    /* @4092600 add */
    /* @4092604 store */
    v19 = GM_ADD(GM_READ(vm, -5, "pistolxp"), VAL(1));
    GM_WRITE(vm, -5, "pistolxp", v19);
    L_4092612: ;
    /* @4092612 load */
    /* @4092620 constant */
    /* @4092624 cmp */
    /* @4092628 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4092768;
    /* @4092632 load */
    /* @4092640 cast */
    /* @4092644 dup */
    /* @4092648 load */
    /* @4092656 load */
    /* @4092664 sub */
    /* @4092668 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp") - GM_READ(vm, -5, "shotgundamage")));
    /* @4092676 constant */
    /* @4092680 cast */
    /* @4092684 load */
    /* @4092692 load */
    /* @4092700 call */
    GM_SITE(vm, 284, 4092700);
    /* @4092708 store */
    v20 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v20);
    /* @4092716 load */
    /* @4092724 load */
    /* @4092732 cast */
    /* @4092736 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "shotgundamage"));
    /* @4092744 load */
    /* @4092752 constant */
    /* @4092756 add */
    /* @4092760 store */
    v21 = GM_ADD(GM_READ(vm, -5, "shotgunxp"), VAL(1));
    GM_WRITE(vm, -5, "shotgunxp", v21);
    L_4092768: ;
    /* @4092768 load */
    /* @4092776 constant */
    /* @4092780 cmp */
    /* @4092784 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4092924;
    /* @4092788 load */
    /* @4092796 cast */
    /* @4092800 dup */
    /* @4092804 load */
    /* @4092812 load */
    /* @4092820 sub */
    /* @4092824 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp") - GM_READ(vm, -5, "assaultrifledamage")));
    /* @4092832 constant */
    /* @4092836 cast */
    /* @4092840 load */
    /* @4092848 load */
    /* @4092856 call */
    GM_SITE(vm, 284, 4092856);
    /* @4092864 store */
    v22 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v22);
    /* @4092872 load */
    /* @4092880 load */
    /* @4092888 cast */
    /* @4092892 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "assaultrifledamage"));
    /* @4092900 load */
    /* @4092908 constant */
    /* @4092912 add */
    /* @4092916 store */
    v23 = GM_ADD(GM_READ(vm, -5, "assaultriflexp"), VAL(1));
    GM_WRITE(vm, -5, "assaultriflexp", v23);
    L_4092924: ;
    /* @4092924 constant */
    /* @4092928 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4092936 load */
    /* @4092944 constant */
    /* @4092948 cmp */
    /* @4092952 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4092960;
    /* @4092956 b */
    goto L_4093016;
    L_4092960: ;
    /* @4092960 load */
    /* @4092968 constant */
    /* @4092972 cmp */
    /* @4092976 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4093016;
    /* @4092980 constant */
    /* @4092984 cast */
    /* @4092988 constant */
    /* @4092992 cast */
    /* @4092996 constant */
    /* @4093000 cast */
    /* @4093004 call */
    GM_SITE(vm, 284, 4093004);
    /* @4093012 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4093016: ;
    /* @4093016 call */
    GM_SITE(vm, 284, 4093016);
    /* @4093024 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4093028 constant */
    /* @4093032 load */
    /* @4093040 cast */
    /* @4093044 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "stunned", VAL(1));
    /* @4093052 constant */
    /* @4093056 load */
    /* @4093064 cast */
    /* @4093068 constant */
    /* @4093072 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit")), "alarm", VAL(4), VAL(10));
    /* @4093080 load */
    /* @4093088 constant */
    /* @4093092 cmp */
    /* @4093096 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4093128;
    /* @4093100 constant */
    /* @4093104 load */
    /* @4093112 cast */
    /* @4093116 constant */
    /* @4093120 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit")), "alarm", VAL(6), VAL(1));
    L_4093128: ;
    /* @4093128 constant */
    /* @4093132 cast */
    /* @4093136 load */
    /* @4093144 load */
    /* @4093152 call */
    GM_SITE(vm, 284, 4093152);
    /* @4093160 store */
    v24 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(22));
    GM_WRITE(vm, -1, "hit2", v24);
    /* @4093168 load */
    /* @4093176 constant */
    /* @4093180 cmp */
    /* @4093184 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit2") != VAL(-4)))) goto L_4093208;
    /* @4093188 load */
    /* @4093196 constant */
    /* @4093200 cmp */
    /* @4093204 b */
    p4093212_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4093212;
    L_4093208: ;
    /* @4093208 constant */
    p4093212_0 = VAL(0);
    L_4093212: ;
    /* @4093212 bf */
    if (!TRUTH(p4093212_0)) goto L_4093976;
    /* @4093216 constant */
    /* @4093220 load */
    /* @4093228 cast */
    /* @4093232 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "flashing", VAL(1));
    /* @4093240 constant */
    /* @4093244 cast */
    /* @4093248 load */
    /* @4093256 load */
    /* @4093264 load */
    /* @4093272 load */
    /* @4093280 call */
    GM_SITE(vm, 284, 4093280);
    /* @4093288 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4093292 constant */
    /* @4093296 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4093304 load */
    /* @4093312 constant */
    /* @4093316 cmp */
    /* @4093320 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4093460;
    /* @4093324 load */
    /* @4093332 cast */
    /* @4093336 dup */
    /* @4093340 load */
    /* @4093348 load */
    /* @4093356 sub */
    /* @4093360 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo") - GM_READ(vm, -5, "pistoldamage")));
    /* @4093368 constant */
    /* @4093372 cast */
    /* @4093376 load */
    /* @4093384 load */
    /* @4093392 call */
    GM_SITE(vm, 284, 4093392);
    /* @4093400 store */
    v25 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v25);
    /* @4093408 load */
    /* @4093416 load */
    /* @4093424 cast */
    /* @4093428 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "pistoldamage"));
    /* @4093436 load */
    /* @4093444 constant */
    /* @4093448 add */
    /* @4093452 store */
    v26 = GM_ADD(GM_READ(vm, -5, "pistolxp"), VAL(1));
    GM_WRITE(vm, -5, "pistolxp", v26);
    L_4093460: ;
    /* @4093460 load */
    /* @4093468 constant */
    /* @4093472 cmp */
    /* @4093476 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4093616;
    /* @4093480 load */
    /* @4093488 cast */
    /* @4093492 dup */
    /* @4093496 load */
    /* @4093504 load */
    /* @4093512 sub */
    /* @4093516 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo") - GM_READ(vm, -5, "shotgundamage")));
    /* @4093524 constant */
    /* @4093528 cast */
    /* @4093532 load */
    /* @4093540 load */
    /* @4093548 call */
    GM_SITE(vm, 284, 4093548);
    /* @4093556 store */
    v27 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v27);
    /* @4093564 load */
    /* @4093572 load */
    /* @4093580 cast */
    /* @4093584 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "shotgundamage"));
    /* @4093592 load */
    /* @4093600 constant */
    /* @4093604 add */
    /* @4093608 store */
    v28 = GM_ADD(GM_READ(vm, -5, "shotgunxp"), VAL(1));
    GM_WRITE(vm, -5, "shotgunxp", v28);
    L_4093616: ;
    /* @4093616 load */
    /* @4093624 constant */
    /* @4093628 cmp */
    /* @4093632 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4093772;
    /* @4093636 load */
    /* @4093644 cast */
    /* @4093648 dup */
    /* @4093652 load */
    /* @4093660 load */
    /* @4093668 sub */
    /* @4093672 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo") - GM_READ(vm, -5, "assaultrifledamage")));
    /* @4093680 constant */
    /* @4093684 cast */
    /* @4093688 load */
    /* @4093696 load */
    /* @4093704 call */
    GM_SITE(vm, 284, 4093704);
    /* @4093712 store */
    v29 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v29);
    /* @4093720 load */
    /* @4093728 load */
    /* @4093736 cast */
    /* @4093740 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "assaultrifledamage"));
    /* @4093748 load */
    /* @4093756 constant */
    /* @4093760 add */
    /* @4093764 store */
    v30 = GM_ADD(GM_READ(vm, -5, "assaultriflexp"), VAL(1));
    GM_WRITE(vm, -5, "assaultriflexp", v30);
    L_4093772: ;
    /* @4093772 constant */
    /* @4093776 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4093784 load */
    /* @4093792 constant */
    /* @4093796 cmp */
    /* @4093800 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4093808;
    /* @4093804 b */
    goto L_4093864;
    L_4093808: ;
    /* @4093808 load */
    /* @4093816 constant */
    /* @4093820 cmp */
    /* @4093824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4093864;
    /* @4093828 constant */
    /* @4093832 cast */
    /* @4093836 constant */
    /* @4093840 cast */
    /* @4093844 constant */
    /* @4093848 cast */
    /* @4093852 call */
    GM_SITE(vm, 284, 4093852);
    /* @4093860 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4093864: ;
    /* @4093864 call */
    GM_SITE(vm, 284, 4093864);
    /* @4093872 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4093876 constant */
    /* @4093880 load */
    /* @4093888 cast */
    /* @4093892 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "stunned", VAL(1));
    /* @4093900 constant */
    /* @4093904 load */
    /* @4093912 cast */
    /* @4093916 constant */
    /* @4093920 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit2")), "alarm", VAL(4), VAL(10));
    /* @4093928 load */
    /* @4093936 constant */
    /* @4093940 cmp */
    /* @4093944 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4093976;
    /* @4093948 constant */
    /* @4093952 load */
    /* @4093960 cast */
    /* @4093964 constant */
    /* @4093968 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit2")), "alarm", VAL(6), VAL(1));
    L_4093976: ;
    /* @4093976 constant */
    /* @4093980 cast */
    /* @4093984 load */
    /* @4093992 load */
    /* @4094000 call */
    GM_SITE(vm, 284, 4094000);
    /* @4094008 store */
    v31 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(25));
    GM_WRITE(vm, -1, "hittrex", v31);
    /* @4094016 load */
    /* @4094024 constant */
    /* @4094028 cmp */
    /* @4094032 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hittrex") != VAL(-4)))) goto L_4094056;
    /* @4094036 load */
    /* @4094044 constant */
    /* @4094048 cmp */
    /* @4094052 b */
    p4094060_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4094060;
    L_4094056: ;
    /* @4094056 constant */
    p4094060_0 = VAL(0);
    L_4094060: ;
    /* @4094060 bf */
    if (!TRUTH(p4094060_0)) goto L_4094772;
    /* @4094064 constant */
    /* @4094068 load */
    /* @4094076 cast */
    /* @4094080 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "flashing", VAL(1));
    /* @4094088 constant */
    /* @4094092 cast */
    /* @4094096 load */
    /* @4094104 load */
    /* @4094112 load */
    /* @4094120 load */
    /* @4094128 call */
    GM_SITE(vm, 284, 4094128);
    /* @4094136 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4094140 constant */
    /* @4094144 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4094152 load */
    /* @4094160 constant */
    /* @4094164 cmp */
    /* @4094168 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4094308;
    /* @4094172 load */
    /* @4094180 cast */
    /* @4094184 dup */
    /* @4094188 load */
    /* @4094196 load */
    /* @4094204 sub */
    /* @4094208 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex") - GM_READ(vm, -5, "pistoldamage")));
    /* @4094216 constant */
    /* @4094220 cast */
    /* @4094224 load */
    /* @4094232 load */
    /* @4094240 call */
    GM_SITE(vm, 284, 4094240);
    /* @4094248 store */
    v32 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v32);
    /* @4094256 load */
    /* @4094264 load */
    /* @4094272 cast */
    /* @4094276 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "pistoldamage"));
    /* @4094284 load */
    /* @4094292 constant */
    /* @4094296 add */
    /* @4094300 store */
    v33 = GM_ADD(GM_READ(vm, -5, "pistolxp"), VAL(1));
    GM_WRITE(vm, -5, "pistolxp", v33);
    L_4094308: ;
    /* @4094308 load */
    /* @4094316 constant */
    /* @4094320 cmp */
    /* @4094324 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4094464;
    /* @4094328 load */
    /* @4094336 cast */
    /* @4094340 dup */
    /* @4094344 load */
    /* @4094352 load */
    /* @4094360 sub */
    /* @4094364 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex") - GM_READ(vm, -5, "shotgundamage")));
    /* @4094372 constant */
    /* @4094376 cast */
    /* @4094380 load */
    /* @4094388 load */
    /* @4094396 call */
    GM_SITE(vm, 284, 4094396);
    /* @4094404 store */
    v34 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v34);
    /* @4094412 load */
    /* @4094420 load */
    /* @4094428 cast */
    /* @4094432 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "shotgundamage"));
    /* @4094440 load */
    /* @4094448 constant */
    /* @4094452 add */
    /* @4094456 store */
    v35 = GM_ADD(GM_READ(vm, -5, "shotgunxp"), VAL(1));
    GM_WRITE(vm, -5, "shotgunxp", v35);
    L_4094464: ;
    /* @4094464 load */
    /* @4094472 constant */
    /* @4094476 cmp */
    /* @4094480 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4094620;
    /* @4094484 load */
    /* @4094492 cast */
    /* @4094496 dup */
    /* @4094500 load */
    /* @4094508 load */
    /* @4094516 sub */
    /* @4094520 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex") - GM_READ(vm, -5, "assaultrifledamage")));
    /* @4094528 constant */
    /* @4094532 cast */
    /* @4094536 load */
    /* @4094544 load */
    /* @4094552 call */
    GM_SITE(vm, 284, 4094552);
    /* @4094560 store */
    v36 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v36);
    /* @4094568 load */
    /* @4094576 load */
    /* @4094584 cast */
    /* @4094588 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "assaultrifledamage"));
    /* @4094596 load */
    /* @4094604 constant */
    /* @4094608 add */
    /* @4094612 store */
    v37 = GM_ADD(GM_READ(vm, -5, "assaultriflexp"), VAL(1));
    GM_WRITE(vm, -5, "assaultriflexp", v37);
    L_4094620: ;
    /* @4094620 constant */
    /* @4094624 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4094632 load */
    /* @4094640 constant */
    /* @4094644 cmp */
    /* @4094648 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4094656;
    /* @4094652 b */
    goto L_4094712;
    L_4094656: ;
    /* @4094656 load */
    /* @4094664 constant */
    /* @4094668 cmp */
    /* @4094672 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4094712;
    /* @4094676 constant */
    /* @4094680 cast */
    /* @4094684 constant */
    /* @4094688 cast */
    /* @4094692 constant */
    /* @4094696 cast */
    /* @4094700 call */
    GM_SITE(vm, 284, 4094700);
    /* @4094708 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4094712: ;
    /* @4094712 call */
    GM_SITE(vm, 284, 4094712);
    /* @4094720 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4094724 load */
    /* @4094732 constant */
    /* @4094736 cmp */
    /* @4094740 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4094772;
    /* @4094744 constant */
    /* @4094748 load */
    /* @4094756 cast */
    /* @4094760 constant */
    /* @4094764 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "alarm", VAL(6), VAL(1));
    L_4094772: ;
    /* @4094772 constant */
    /* @4094776 cast */
    /* @4094780 load */
    /* @4094788 load */
    /* @4094796 call */
    GM_SITE(vm, 284, 4094796);
    /* @4094804 store */
    v38 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(31));
    GM_WRITE(vm, -1, "hit4", v38);
    /* @4094812 load */
    /* @4094820 constant */
    /* @4094824 cmp */
    /* @4094828 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit4") != VAL(-4)))) goto L_4094852;
    /* @4094832 load */
    /* @4094840 constant */
    /* @4094844 cmp */
    /* @4094848 b */
    p4094856_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4094856;
    L_4094852: ;
    /* @4094852 constant */
    p4094856_0 = VAL(0);
    L_4094856: ;
    /* @4094856 bf */
    if (!TRUTH(p4094856_0)) goto L_4095620;
    /* @4094860 constant */
    /* @4094864 load */
    /* @4094872 cast */
    /* @4094876 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "flashing", VAL(1));
    /* @4094884 constant */
    /* @4094888 cast */
    /* @4094892 load */
    /* @4094900 load */
    /* @4094908 load */
    /* @4094916 load */
    /* @4094924 call */
    GM_SITE(vm, 284, 4094924);
    /* @4094932 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4094936 constant */
    /* @4094940 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4094948 load */
    /* @4094956 constant */
    /* @4094960 cmp */
    /* @4094964 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4095104;
    /* @4094968 load */
    /* @4094976 cast */
    /* @4094980 dup */
    /* @4094984 load */
    /* @4094992 load */
    /* @4095000 sub */
    /* @4095004 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour") - GM_READ(vm, -5, "pistoldamage")));
    /* @4095012 constant */
    /* @4095016 cast */
    /* @4095020 load */
    /* @4095028 load */
    /* @4095036 call */
    GM_SITE(vm, 284, 4095036);
    /* @4095044 store */
    v39 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v39);
    /* @4095052 load */
    /* @4095060 load */
    /* @4095068 cast */
    /* @4095072 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "pistoldamage"));
    /* @4095080 load */
    /* @4095088 constant */
    /* @4095092 add */
    /* @4095096 store */
    v40 = GM_ADD(GM_READ(vm, -5, "pistolxp"), VAL(1));
    GM_WRITE(vm, -5, "pistolxp", v40);
    L_4095104: ;
    /* @4095104 load */
    /* @4095112 constant */
    /* @4095116 cmp */
    /* @4095120 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4095260;
    /* @4095124 load */
    /* @4095132 cast */
    /* @4095136 dup */
    /* @4095140 load */
    /* @4095148 load */
    /* @4095156 sub */
    /* @4095160 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour") - GM_READ(vm, -5, "shotgundamage")));
    /* @4095168 constant */
    /* @4095172 cast */
    /* @4095176 load */
    /* @4095184 load */
    /* @4095192 call */
    GM_SITE(vm, 284, 4095192);
    /* @4095200 store */
    v41 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v41);
    /* @4095208 load */
    /* @4095216 load */
    /* @4095224 cast */
    /* @4095228 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "shotgundamage"));
    /* @4095236 load */
    /* @4095244 constant */
    /* @4095248 add */
    /* @4095252 store */
    v42 = GM_ADD(GM_READ(vm, -5, "shotgunxp"), VAL(1));
    GM_WRITE(vm, -5, "shotgunxp", v42);
    L_4095260: ;
    /* @4095260 load */
    /* @4095268 constant */
    /* @4095272 cmp */
    /* @4095276 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4095416;
    /* @4095280 load */
    /* @4095288 cast */
    /* @4095292 dup */
    /* @4095296 load */
    /* @4095304 load */
    /* @4095312 sub */
    /* @4095316 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour") - GM_READ(vm, -5, "assaultrifledamage")));
    /* @4095324 constant */
    /* @4095328 cast */
    /* @4095332 load */
    /* @4095340 load */
    /* @4095348 call */
    GM_SITE(vm, 284, 4095348);
    /* @4095356 store */
    v43 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v43);
    /* @4095364 load */
    /* @4095372 load */
    /* @4095380 cast */
    /* @4095384 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "assaultrifledamage"));
    /* @4095392 load */
    /* @4095400 constant */
    /* @4095404 add */
    /* @4095408 store */
    v44 = GM_ADD(GM_READ(vm, -5, "assaultriflexp"), VAL(1));
    GM_WRITE(vm, -5, "assaultriflexp", v44);
    L_4095416: ;
    /* @4095416 constant */
    /* @4095420 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4095428 load */
    /* @4095436 constant */
    /* @4095440 cmp */
    /* @4095444 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4095452;
    /* @4095448 b */
    goto L_4095508;
    L_4095452: ;
    /* @4095452 load */
    /* @4095460 constant */
    /* @4095464 cmp */
    /* @4095468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4095508;
    /* @4095472 constant */
    /* @4095476 cast */
    /* @4095480 constant */
    /* @4095484 cast */
    /* @4095488 constant */
    /* @4095492 cast */
    /* @4095496 call */
    GM_SITE(vm, 284, 4095496);
    /* @4095504 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4095508: ;
    /* @4095508 call */
    GM_SITE(vm, 284, 4095508);
    /* @4095516 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4095520 constant */
    /* @4095524 load */
    /* @4095532 cast */
    /* @4095536 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "stunned", VAL(1));
    /* @4095544 constant */
    /* @4095548 load */
    /* @4095556 cast */
    /* @4095560 constant */
    /* @4095564 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit4")), "alarm", VAL(4), VAL(10));
    /* @4095572 load */
    /* @4095580 constant */
    /* @4095584 cmp */
    /* @4095588 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4095620;
    /* @4095592 constant */
    /* @4095596 load */
    /* @4095604 cast */
    /* @4095608 constant */
    /* @4095612 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit4")), "alarm", VAL(6), VAL(1));
    L_4095620: ;
    /* @4095620 constant */
    /* @4095624 cast */
    /* @4095628 load */
    /* @4095636 load */
    /* @4095644 call */
    GM_SITE(vm, 284, 4095644);
    /* @4095652 store */
    v45 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(32));
    GM_WRITE(vm, -1, "hit5", v45);
    /* @4095660 load */
    /* @4095668 constant */
    /* @4095672 cmp */
    /* @4095676 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit5") != VAL(-4)))) goto L_4095700;
    /* @4095680 load */
    /* @4095688 constant */
    /* @4095692 cmp */
    /* @4095696 b */
    p4095704_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4095704;
    L_4095700: ;
    /* @4095700 constant */
    p4095704_0 = VAL(0);
    L_4095704: ;
    /* @4095704 bf */
    if (!TRUTH(p4095704_0)) goto L_4096468;
    /* @4095708 constant */
    /* @4095712 load */
    /* @4095720 cast */
    /* @4095724 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "flashing", VAL(1));
    /* @4095732 constant */
    /* @4095736 cast */
    /* @4095740 load */
    /* @4095748 load */
    /* @4095756 load */
    /* @4095764 load */
    /* @4095772 call */
    GM_SITE(vm, 284, 4095772);
    /* @4095780 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4095784 constant */
    /* @4095788 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4095796 load */
    /* @4095804 constant */
    /* @4095808 cmp */
    /* @4095812 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4095952;
    /* @4095816 load */
    /* @4095824 cast */
    /* @4095828 dup */
    /* @4095832 load */
    /* @4095840 load */
    /* @4095848 sub */
    /* @4095852 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime") - GM_READ(vm, -5, "pistoldamage")));
    /* @4095860 constant */
    /* @4095864 cast */
    /* @4095868 load */
    /* @4095876 load */
    /* @4095884 call */
    GM_SITE(vm, 284, 4095884);
    /* @4095892 store */
    v46 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v46);
    /* @4095900 load */
    /* @4095908 load */
    /* @4095916 cast */
    /* @4095920 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "pistoldamage"));
    /* @4095928 load */
    /* @4095936 constant */
    /* @4095940 add */
    /* @4095944 store */
    v47 = GM_ADD(GM_READ(vm, -5, "pistolxp"), VAL(1));
    GM_WRITE(vm, -5, "pistolxp", v47);
    L_4095952: ;
    /* @4095952 load */
    /* @4095960 constant */
    /* @4095964 cmp */
    /* @4095968 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4096108;
    /* @4095972 load */
    /* @4095980 cast */
    /* @4095984 dup */
    /* @4095988 load */
    /* @4095996 load */
    /* @4096004 sub */
    /* @4096008 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime") - GM_READ(vm, -5, "shotgundamage")));
    /* @4096016 constant */
    /* @4096020 cast */
    /* @4096024 load */
    /* @4096032 load */
    /* @4096040 call */
    GM_SITE(vm, 284, 4096040);
    /* @4096048 store */
    v48 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v48);
    /* @4096056 load */
    /* @4096064 load */
    /* @4096072 cast */
    /* @4096076 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "shotgundamage"));
    /* @4096084 load */
    /* @4096092 constant */
    /* @4096096 add */
    /* @4096100 store */
    v49 = GM_ADD(GM_READ(vm, -5, "shotgunxp"), VAL(1));
    GM_WRITE(vm, -5, "shotgunxp", v49);
    L_4096108: ;
    /* @4096108 load */
    /* @4096116 constant */
    /* @4096120 cmp */
    /* @4096124 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4096264;
    /* @4096128 load */
    /* @4096136 cast */
    /* @4096140 dup */
    /* @4096144 load */
    /* @4096152 load */
    /* @4096160 sub */
    /* @4096164 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime") - GM_READ(vm, -5, "assaultrifledamage")));
    /* @4096172 constant */
    /* @4096176 cast */
    /* @4096180 load */
    /* @4096188 load */
    /* @4096196 call */
    GM_SITE(vm, 284, 4096196);
    /* @4096204 store */
    v50 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v50);
    /* @4096212 load */
    /* @4096220 load */
    /* @4096228 cast */
    /* @4096232 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "assaultrifledamage"));
    /* @4096240 load */
    /* @4096248 constant */
    /* @4096252 add */
    /* @4096256 store */
    v51 = GM_ADD(GM_READ(vm, -5, "assaultriflexp"), VAL(1));
    GM_WRITE(vm, -5, "assaultriflexp", v51);
    L_4096264: ;
    /* @4096264 constant */
    /* @4096268 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4096276 load */
    /* @4096284 constant */
    /* @4096288 cmp */
    /* @4096292 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4096300;
    /* @4096296 b */
    goto L_4096356;
    L_4096300: ;
    /* @4096300 load */
    /* @4096308 constant */
    /* @4096312 cmp */
    /* @4096316 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4096356;
    /* @4096320 constant */
    /* @4096324 cast */
    /* @4096328 constant */
    /* @4096332 cast */
    /* @4096336 constant */
    /* @4096340 cast */
    /* @4096344 call */
    GM_SITE(vm, 284, 4096344);
    /* @4096352 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4096356: ;
    /* @4096356 call */
    GM_SITE(vm, 284, 4096356);
    /* @4096364 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4096368 constant */
    /* @4096372 load */
    /* @4096380 cast */
    /* @4096384 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "stunned", VAL(1));
    /* @4096392 constant */
    /* @4096396 load */
    /* @4096404 cast */
    /* @4096408 constant */
    /* @4096412 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit5")), "alarm", VAL(4), VAL(10));
    /* @4096420 load */
    /* @4096428 constant */
    /* @4096432 cmp */
    /* @4096436 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4096468;
    /* @4096440 constant */
    /* @4096444 load */
    /* @4096452 cast */
    /* @4096456 constant */
    /* @4096460 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit5")), "alarm", VAL(6), VAL(1));
    L_4096468: ;
    /* @4096468 constant */
    /* @4096472 cast */
    /* @4096476 load */
    /* @4096484 load */
    /* @4096492 call */
    GM_SITE(vm, 284, 4096492);
    /* @4096500 store */
    v52 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(24));
    GM_WRITE(vm, -1, "hit7", v52);
    /* @4096508 load */
    /* @4096516 constant */
    /* @4096520 cmp */
    /* @4096524 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit7") != VAL(-4)))) goto L_4096548;
    /* @4096528 load */
    /* @4096536 constant */
    /* @4096540 cmp */
    /* @4096544 b */
    p4096552_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4096552;
    L_4096548: ;
    /* @4096548 constant */
    p4096552_0 = VAL(0);
    L_4096552: ;
    /* @4096552 bf */
    if (!TRUTH(p4096552_0)) goto L_4097316;
    /* @4096556 constant */
    /* @4096560 load */
    /* @4096568 cast */
    /* @4096572 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "flashing", VAL(1));
    /* @4096580 constant */
    /* @4096584 cast */
    /* @4096588 load */
    /* @4096596 load */
    /* @4096604 load */
    /* @4096612 load */
    /* @4096620 call */
    GM_SITE(vm, 284, 4096620);
    /* @4096628 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4096632 constant */
    /* @4096636 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4096644 load */
    /* @4096652 constant */
    /* @4096656 cmp */
    /* @4096660 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4096800;
    /* @4096664 load */
    /* @4096672 cast */
    /* @4096676 dup */
    /* @4096680 load */
    /* @4096688 load */
    /* @4096696 sub */
    /* @4096700 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "hpghost", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit7")), "hpghost") - GM_READ(vm, -5, "pistoldamage")));
    /* @4096708 constant */
    /* @4096712 cast */
    /* @4096716 load */
    /* @4096724 load */
    /* @4096732 call */
    GM_SITE(vm, 284, 4096732);
    /* @4096740 store */
    v53 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v53);
    /* @4096748 load */
    /* @4096756 load */
    /* @4096764 cast */
    /* @4096768 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "pistoldamage"));
    /* @4096776 load */
    /* @4096784 constant */
    /* @4096788 add */
    /* @4096792 store */
    v54 = GM_ADD(GM_READ(vm, -5, "pistolxp"), VAL(1));
    GM_WRITE(vm, -5, "pistolxp", v54);
    L_4096800: ;
    /* @4096800 load */
    /* @4096808 constant */
    /* @4096812 cmp */
    /* @4096816 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4096956;
    /* @4096820 load */
    /* @4096828 cast */
    /* @4096832 dup */
    /* @4096836 load */
    /* @4096844 load */
    /* @4096852 sub */
    /* @4096856 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "hpghost", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit7")), "hpghost") - GM_READ(vm, -5, "shotgundamage")));
    /* @4096864 constant */
    /* @4096868 cast */
    /* @4096872 load */
    /* @4096880 load */
    /* @4096888 call */
    GM_SITE(vm, 284, 4096888);
    /* @4096896 store */
    v55 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v55);
    /* @4096904 load */
    /* @4096912 load */
    /* @4096920 cast */
    /* @4096924 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "shotgundamage"));
    /* @4096932 load */
    /* @4096940 constant */
    /* @4096944 add */
    /* @4096948 store */
    v56 = GM_ADD(GM_READ(vm, -5, "shotgunxp"), VAL(1));
    GM_WRITE(vm, -5, "shotgunxp", v56);
    L_4096956: ;
    /* @4096956 load */
    /* @4096964 constant */
    /* @4096968 cmp */
    /* @4096972 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4097112;
    /* @4096976 load */
    /* @4096984 cast */
    /* @4096988 dup */
    /* @4096992 load */
    /* @4097000 load */
    /* @4097008 sub */
    /* @4097012 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "hpghost", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit7")), "hpghost") - GM_READ(vm, -5, "assaultrifledamage")));
    /* @4097020 constant */
    /* @4097024 cast */
    /* @4097028 load */
    /* @4097036 load */
    /* @4097044 call */
    GM_SITE(vm, 284, 4097044);
    /* @4097052 store */
    v57 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v57);
    /* @4097060 load */
    /* @4097068 load */
    /* @4097076 cast */
    /* @4097080 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "assaultrifledamage"));
    /* @4097088 load */
    /* @4097096 constant */
    /* @4097100 add */
    /* @4097104 store */
    v58 = GM_ADD(GM_READ(vm, -5, "assaultriflexp"), VAL(1));
    GM_WRITE(vm, -5, "assaultriflexp", v58);
    L_4097112: ;
    /* @4097112 constant */
    /* @4097116 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4097124 load */
    /* @4097132 constant */
    /* @4097136 cmp */
    /* @4097140 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4097148;
    /* @4097144 b */
    goto L_4097204;
    L_4097148: ;
    /* @4097148 load */
    /* @4097156 constant */
    /* @4097160 cmp */
    /* @4097164 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4097204;
    /* @4097168 constant */
    /* @4097172 cast */
    /* @4097176 constant */
    /* @4097180 cast */
    /* @4097184 constant */
    /* @4097188 cast */
    /* @4097192 call */
    GM_SITE(vm, 284, 4097192);
    /* @4097200 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4097204: ;
    /* @4097204 call */
    GM_SITE(vm, 284, 4097204);
    /* @4097212 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4097216 constant */
    /* @4097220 load */
    /* @4097228 cast */
    /* @4097232 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "stunned", VAL(1));
    /* @4097240 constant */
    /* @4097244 load */
    /* @4097252 cast */
    /* @4097256 constant */
    /* @4097260 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit7")), "alarm", VAL(4), VAL(10));
    /* @4097268 load */
    /* @4097276 constant */
    /* @4097280 cmp */
    /* @4097284 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4097316;
    /* @4097288 constant */
    /* @4097292 load */
    /* @4097300 cast */
    /* @4097304 constant */
    /* @4097308 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit7")), "alarm", VAL(6), VAL(1));
    L_4097316: ;
    /* @4097316 constant */
    /* @4097320 cast */
    /* @4097324 load */
    /* @4097332 load */
    /* @4097340 call */
    GM_SITE(vm, 284, 4097340);
    /* @4097348 store */
    v59 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(16));
    GM_WRITE(vm, -1, "hit8", v59);
    /* @4097356 load */
    /* @4097364 constant */
    /* @4097368 cmp */
    /* @4097372 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit8") != VAL(-4)))) goto L_4097396;
    /* @4097376 load */
    /* @4097384 constant */
    /* @4097388 cmp */
    /* @4097392 b */
    p4097400_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4097400;
    L_4097396: ;
    /* @4097396 constant */
    p4097400_0 = VAL(0);
    L_4097400: ;
    /* @4097400 bf */
    if (!TRUTH(p4097400_0)) goto L_4098164;
    /* @4097404 constant */
    /* @4097408 load */
    /* @4097416 cast */
    /* @4097420 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "flashing", VAL(1));
    /* @4097428 constant */
    /* @4097432 cast */
    /* @4097436 load */
    /* @4097444 load */
    /* @4097452 load */
    /* @4097460 load */
    /* @4097468 call */
    GM_SITE(vm, 284, 4097468);
    /* @4097476 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4097480 constant */
    /* @4097484 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4097492 load */
    /* @4097500 constant */
    /* @4097504 cmp */
    /* @4097508 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4097648;
    /* @4097512 load */
    /* @4097520 cast */
    /* @4097524 dup */
    /* @4097528 load */
    /* @4097536 load */
    /* @4097544 sub */
    /* @4097548 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1") - GM_READ(vm, -5, "pistoldamage")));
    /* @4097556 constant */
    /* @4097560 cast */
    /* @4097564 load */
    /* @4097572 load */
    /* @4097580 call */
    GM_SITE(vm, 284, 4097580);
    /* @4097588 store */
    v60 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v60);
    /* @4097596 load */
    /* @4097604 load */
    /* @4097612 cast */
    /* @4097616 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "pistoldamage"));
    /* @4097624 load */
    /* @4097632 constant */
    /* @4097636 add */
    /* @4097640 store */
    v61 = GM_ADD(GM_READ(vm, -5, "pistolxp"), VAL(1));
    GM_WRITE(vm, -5, "pistolxp", v61);
    L_4097648: ;
    /* @4097648 load */
    /* @4097656 constant */
    /* @4097660 cmp */
    /* @4097664 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4097804;
    /* @4097668 load */
    /* @4097676 cast */
    /* @4097680 dup */
    /* @4097684 load */
    /* @4097692 load */
    /* @4097700 sub */
    /* @4097704 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1") - GM_READ(vm, -5, "shotgundamage")));
    /* @4097712 constant */
    /* @4097716 cast */
    /* @4097720 load */
    /* @4097728 load */
    /* @4097736 call */
    GM_SITE(vm, 284, 4097736);
    /* @4097744 store */
    v62 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v62);
    /* @4097752 load */
    /* @4097760 load */
    /* @4097768 cast */
    /* @4097772 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "shotgundamage"));
    /* @4097780 load */
    /* @4097788 constant */
    /* @4097792 add */
    /* @4097796 store */
    v63 = GM_ADD(GM_READ(vm, -5, "shotgunxp"), VAL(1));
    GM_WRITE(vm, -5, "shotgunxp", v63);
    L_4097804: ;
    /* @4097804 load */
    /* @4097812 constant */
    /* @4097816 cmp */
    /* @4097820 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4097960;
    /* @4097824 load */
    /* @4097832 cast */
    /* @4097836 dup */
    /* @4097840 load */
    /* @4097848 load */
    /* @4097856 sub */
    /* @4097860 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1") - GM_READ(vm, -5, "assaultrifledamage")));
    /* @4097868 constant */
    /* @4097872 cast */
    /* @4097876 load */
    /* @4097884 load */
    /* @4097892 call */
    GM_SITE(vm, 284, 4097892);
    /* @4097900 store */
    v64 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v64);
    /* @4097908 load */
    /* @4097916 load */
    /* @4097924 cast */
    /* @4097928 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "assaultrifledamage"));
    /* @4097936 load */
    /* @4097944 constant */
    /* @4097948 add */
    /* @4097952 store */
    v65 = GM_ADD(GM_READ(vm, -5, "assaultriflexp"), VAL(1));
    GM_WRITE(vm, -5, "assaultriflexp", v65);
    L_4097960: ;
    /* @4097960 constant */
    /* @4097964 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4097972 load */
    /* @4097980 constant */
    /* @4097984 cmp */
    /* @4097988 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4097996;
    /* @4097992 b */
    goto L_4098052;
    L_4097996: ;
    /* @4097996 load */
    /* @4098004 constant */
    /* @4098008 cmp */
    /* @4098012 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4098052;
    /* @4098016 constant */
    /* @4098020 cast */
    /* @4098024 constant */
    /* @4098028 cast */
    /* @4098032 constant */
    /* @4098036 cast */
    /* @4098040 call */
    GM_SITE(vm, 284, 4098040);
    /* @4098048 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4098052: ;
    /* @4098052 call */
    GM_SITE(vm, 284, 4098052);
    /* @4098060 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4098064 constant */
    /* @4098068 load */
    /* @4098076 cast */
    /* @4098080 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "stunned", VAL(1));
    /* @4098088 constant */
    /* @4098092 load */
    /* @4098100 cast */
    /* @4098104 constant */
    /* @4098108 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit8")), "alarm", VAL(4), VAL(10));
    /* @4098116 load */
    /* @4098124 constant */
    /* @4098128 cmp */
    /* @4098132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4098164;
    /* @4098136 constant */
    /* @4098140 load */
    /* @4098148 cast */
    /* @4098152 constant */
    /* @4098156 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit8")), "alarm", VAL(6), VAL(1));
    L_4098164: ;
    /* @4098164 constant */
    /* @4098168 cast */
    /* @4098172 load */
    /* @4098180 load */
    /* @4098188 call */
    GM_SITE(vm, 284, 4098188);
    /* @4098196 store */
    v66 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(20));
    GM_WRITE(vm, -1, "hit9", v66);
    /* @4098204 load */
    /* @4098212 constant */
    /* @4098216 cmp */
    /* @4098220 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit9") != VAL(-4)))) goto L_4098244;
    /* @4098224 load */
    /* @4098232 constant */
    /* @4098236 cmp */
    /* @4098240 b */
    p4098248_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4098248;
    L_4098244: ;
    /* @4098244 constant */
    p4098248_0 = VAL(0);
    L_4098248: ;
    /* @4098248 bf */
    if (!TRUTH(p4098248_0)) goto L_4099012;
    /* @4098252 constant */
    /* @4098256 load */
    /* @4098264 cast */
    /* @4098268 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "flashing", VAL(1));
    /* @4098276 constant */
    /* @4098280 cast */
    /* @4098284 load */
    /* @4098292 load */
    /* @4098300 load */
    /* @4098308 load */
    /* @4098316 call */
    GM_SITE(vm, 284, 4098316);
    /* @4098324 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4098328 constant */
    /* @4098332 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4098340 load */
    /* @4098348 constant */
    /* @4098352 cmp */
    /* @4098356 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4098496;
    /* @4098360 load */
    /* @4098368 cast */
    /* @4098372 dup */
    /* @4098376 load */
    /* @4098384 load */
    /* @4098392 sub */
    /* @4098396 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2") - GM_READ(vm, -5, "pistoldamage")));
    /* @4098404 constant */
    /* @4098408 cast */
    /* @4098412 load */
    /* @4098420 load */
    /* @4098428 call */
    GM_SITE(vm, 284, 4098428);
    /* @4098436 store */
    v67 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v67);
    /* @4098444 load */
    /* @4098452 load */
    /* @4098460 cast */
    /* @4098464 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "pistoldamage"));
    /* @4098472 load */
    /* @4098480 constant */
    /* @4098484 add */
    /* @4098488 store */
    v68 = GM_ADD(GM_READ(vm, -5, "pistolxp"), VAL(1));
    GM_WRITE(vm, -5, "pistolxp", v68);
    L_4098496: ;
    /* @4098496 load */
    /* @4098504 constant */
    /* @4098508 cmp */
    /* @4098512 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4098652;
    /* @4098516 load */
    /* @4098524 cast */
    /* @4098528 dup */
    /* @4098532 load */
    /* @4098540 load */
    /* @4098548 sub */
    /* @4098552 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2") - GM_READ(vm, -5, "shotgundamage")));
    /* @4098560 constant */
    /* @4098564 cast */
    /* @4098568 load */
    /* @4098576 load */
    /* @4098584 call */
    GM_SITE(vm, 284, 4098584);
    /* @4098592 store */
    v69 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v69);
    /* @4098600 load */
    /* @4098608 load */
    /* @4098616 cast */
    /* @4098620 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "shotgundamage"));
    /* @4098628 load */
    /* @4098636 constant */
    /* @4098640 add */
    /* @4098644 store */
    v70 = GM_ADD(GM_READ(vm, -5, "shotgunxp"), VAL(1));
    GM_WRITE(vm, -5, "shotgunxp", v70);
    L_4098652: ;
    /* @4098652 load */
    /* @4098660 constant */
    /* @4098664 cmp */
    /* @4098668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4098808;
    /* @4098672 load */
    /* @4098680 cast */
    /* @4098684 dup */
    /* @4098688 load */
    /* @4098696 load */
    /* @4098704 sub */
    /* @4098708 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2") - GM_READ(vm, -5, "assaultrifledamage")));
    /* @4098716 constant */
    /* @4098720 cast */
    /* @4098724 load */
    /* @4098732 load */
    /* @4098740 call */
    GM_SITE(vm, 284, 4098740);
    /* @4098748 store */
    v71 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v71);
    /* @4098756 load */
    /* @4098764 load */
    /* @4098772 cast */
    /* @4098776 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "assaultrifledamage"));
    /* @4098784 load */
    /* @4098792 constant */
    /* @4098796 add */
    /* @4098800 store */
    v72 = GM_ADD(GM_READ(vm, -5, "assaultriflexp"), VAL(1));
    GM_WRITE(vm, -5, "assaultriflexp", v72);
    L_4098808: ;
    /* @4098808 constant */
    /* @4098812 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4098820 load */
    /* @4098828 constant */
    /* @4098832 cmp */
    /* @4098836 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4098844;
    /* @4098840 b */
    goto L_4098900;
    L_4098844: ;
    /* @4098844 load */
    /* @4098852 constant */
    /* @4098856 cmp */
    /* @4098860 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4098900;
    /* @4098864 constant */
    /* @4098868 cast */
    /* @4098872 constant */
    /* @4098876 cast */
    /* @4098880 constant */
    /* @4098884 cast */
    /* @4098888 call */
    GM_SITE(vm, 284, 4098888);
    /* @4098896 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4098900: ;
    /* @4098900 call */
    GM_SITE(vm, 284, 4098900);
    /* @4098908 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4098912 constant */
    /* @4098916 load */
    /* @4098924 cast */
    /* @4098928 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "stunned", VAL(1));
    /* @4098936 constant */
    /* @4098940 load */
    /* @4098948 cast */
    /* @4098952 constant */
    /* @4098956 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit9")), "alarm", VAL(4), VAL(10));
    /* @4098964 load */
    /* @4098972 constant */
    /* @4098976 cmp */
    /* @4098980 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4099012;
    /* @4098984 constant */
    /* @4098988 load */
    /* @4098996 cast */
    /* @4099000 constant */
    /* @4099004 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit9")), "alarm", VAL(7), VAL(1));
    L_4099012: ;
    /* @4099012 constant */
    /* @4099016 cast */
    /* @4099020 load */
    /* @4099028 load */
    /* @4099036 call */
    GM_SITE(vm, 284, 4099036);
    /* @4099044 store */
    v73 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(33));
    GM_WRITE(vm, -1, "hit10", v73);
    /* @4099052 load */
    /* @4099060 constant */
    /* @4099064 cmp */
    /* @4099068 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit10") != VAL(-4)))) goto L_4099092;
    /* @4099072 load */
    /* @4099080 constant */
    /* @4099084 cmp */
    /* @4099088 b */
    p4099096_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4099096;
    L_4099092: ;
    /* @4099092 constant */
    p4099096_0 = VAL(0);
    L_4099096: ;
    /* @4099096 bf */
    if (!TRUTH(p4099096_0)) goto L_4099860;
    /* @4099100 constant */
    /* @4099104 load */
    /* @4099112 cast */
    /* @4099116 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "flashing", VAL(1));
    /* @4099124 constant */
    /* @4099128 cast */
    /* @4099132 load */
    /* @4099140 load */
    /* @4099148 load */
    /* @4099156 load */
    /* @4099164 call */
    GM_SITE(vm, 284, 4099164);
    /* @4099172 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4099176 constant */
    /* @4099180 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4099188 load */
    /* @4099196 constant */
    /* @4099200 cmp */
    /* @4099204 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4099344;
    /* @4099208 load */
    /* @4099216 cast */
    /* @4099220 dup */
    /* @4099224 load */
    /* @4099232 load */
    /* @4099240 sub */
    /* @4099244 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime") - GM_READ(vm, -5, "pistoldamage")));
    /* @4099252 constant */
    /* @4099256 cast */
    /* @4099260 load */
    /* @4099268 load */
    /* @4099276 call */
    GM_SITE(vm, 284, 4099276);
    /* @4099284 store */
    v74 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v74);
    /* @4099292 load */
    /* @4099300 load */
    /* @4099308 cast */
    /* @4099312 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "pistoldamage"));
    /* @4099320 load */
    /* @4099328 constant */
    /* @4099332 add */
    /* @4099336 store */
    v75 = GM_ADD(GM_READ(vm, -5, "pistolxp"), VAL(1));
    GM_WRITE(vm, -5, "pistolxp", v75);
    L_4099344: ;
    /* @4099344 load */
    /* @4099352 constant */
    /* @4099356 cmp */
    /* @4099360 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4099500;
    /* @4099364 load */
    /* @4099372 cast */
    /* @4099376 dup */
    /* @4099380 load */
    /* @4099388 load */
    /* @4099396 sub */
    /* @4099400 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime") - GM_READ(vm, -5, "shotgundamage")));
    /* @4099408 constant */
    /* @4099412 cast */
    /* @4099416 load */
    /* @4099424 load */
    /* @4099432 call */
    GM_SITE(vm, 284, 4099432);
    /* @4099440 store */
    v76 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v76);
    /* @4099448 load */
    /* @4099456 load */
    /* @4099464 cast */
    /* @4099468 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "shotgundamage"));
    /* @4099476 load */
    /* @4099484 constant */
    /* @4099488 add */
    /* @4099492 store */
    v77 = GM_ADD(GM_READ(vm, -5, "shotgunxp"), VAL(1));
    GM_WRITE(vm, -5, "shotgunxp", v77);
    L_4099500: ;
    /* @4099500 load */
    /* @4099508 constant */
    /* @4099512 cmp */
    /* @4099516 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4099656;
    /* @4099520 load */
    /* @4099528 cast */
    /* @4099532 dup */
    /* @4099536 load */
    /* @4099544 load */
    /* @4099552 sub */
    /* @4099556 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime") - GM_READ(vm, -5, "assaultrifledamage")));
    /* @4099564 constant */
    /* @4099568 cast */
    /* @4099572 load */
    /* @4099580 load */
    /* @4099588 call */
    GM_SITE(vm, 284, 4099588);
    /* @4099596 store */
    v78 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v78);
    /* @4099604 load */
    /* @4099612 load */
    /* @4099620 cast */
    /* @4099624 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "assaultrifledamage"));
    /* @4099632 load */
    /* @4099640 constant */
    /* @4099644 add */
    /* @4099648 store */
    v79 = GM_ADD(GM_READ(vm, -5, "assaultriflexp"), VAL(1));
    GM_WRITE(vm, -5, "assaultriflexp", v79);
    L_4099656: ;
    /* @4099656 constant */
    /* @4099660 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4099668 load */
    /* @4099676 constant */
    /* @4099680 cmp */
    /* @4099684 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4099692;
    /* @4099688 b */
    goto L_4099748;
    L_4099692: ;
    /* @4099692 load */
    /* @4099700 constant */
    /* @4099704 cmp */
    /* @4099708 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4099748;
    /* @4099712 constant */
    /* @4099716 cast */
    /* @4099720 constant */
    /* @4099724 cast */
    /* @4099728 constant */
    /* @4099732 cast */
    /* @4099736 call */
    GM_SITE(vm, 284, 4099736);
    /* @4099744 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4099748: ;
    /* @4099748 call */
    GM_SITE(vm, 284, 4099748);
    /* @4099756 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4099760 constant */
    /* @4099764 load */
    /* @4099772 cast */
    /* @4099776 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "stunned", VAL(1));
    /* @4099784 constant */
    /* @4099788 load */
    /* @4099796 cast */
    /* @4099800 constant */
    /* @4099804 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit10")), "alarm", VAL(4), VAL(10));
    /* @4099812 load */
    /* @4099820 constant */
    /* @4099824 cmp */
    /* @4099828 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4099860;
    /* @4099832 constant */
    /* @4099836 load */
    /* @4099844 cast */
    /* @4099848 constant */
    /* @4099852 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit10")), "alarm", VAL(6), VAL(1));
    L_4099860: ;
    /* @4099860 constant */
    /* @4099864 cast */
    /* @4099868 load */
    /* @4099876 load */
    /* @4099884 call */
    GM_SITE(vm, 284, 4099884);
    /* @4099892 store */
    v80 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(21));
    GM_WRITE(vm, -1, "hit11", v80);
    /* @4099900 load */
    /* @4099908 constant */
    /* @4099912 cmp */
    /* @4099916 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit11") != VAL(-4)))) goto L_4099940;
    /* @4099920 load */
    /* @4099928 constant */
    /* @4099932 cmp */
    /* @4099936 b */
    p4099944_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4099944;
    L_4099940: ;
    /* @4099940 constant */
    p4099944_0 = VAL(0);
    L_4099944: ;
    /* @4099944 bf */
    if (!TRUTH(p4099944_0)) goto L_4100708;
    /* @4099948 constant */
    /* @4099952 load */
    /* @4099960 cast */
    /* @4099964 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "flashing", VAL(1));
    /* @4099972 constant */
    /* @4099976 cast */
    /* @4099980 load */
    /* @4099988 load */
    /* @4099996 load */
    /* @4100004 load */
    /* @4100012 call */
    GM_SITE(vm, 284, 4100012);
    /* @4100020 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4100024 constant */
    /* @4100028 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4100036 load */
    /* @4100044 constant */
    /* @4100048 cmp */
    /* @4100052 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4100192;
    /* @4100056 load */
    /* @4100064 cast */
    /* @4100068 dup */
    /* @4100072 load */
    /* @4100080 load */
    /* @4100088 sub */
    /* @4100092 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit") - GM_READ(vm, -5, "pistoldamage")));
    /* @4100100 constant */
    /* @4100104 cast */
    /* @4100108 load */
    /* @4100116 load */
    /* @4100124 call */
    GM_SITE(vm, 284, 4100124);
    /* @4100132 store */
    v81 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v81);
    /* @4100140 load */
    /* @4100148 load */
    /* @4100156 cast */
    /* @4100160 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "pistoldamage"));
    /* @4100168 load */
    /* @4100176 constant */
    /* @4100180 add */
    /* @4100184 store */
    v82 = GM_ADD(GM_READ(vm, -5, "pistolxp"), VAL(1));
    GM_WRITE(vm, -5, "pistolxp", v82);
    L_4100192: ;
    /* @4100192 load */
    /* @4100200 constant */
    /* @4100204 cmp */
    /* @4100208 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4100348;
    /* @4100212 load */
    /* @4100220 cast */
    /* @4100224 dup */
    /* @4100228 load */
    /* @4100236 load */
    /* @4100244 sub */
    /* @4100248 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit") - GM_READ(vm, -5, "shotgundamage")));
    /* @4100256 constant */
    /* @4100260 cast */
    /* @4100264 load */
    /* @4100272 load */
    /* @4100280 call */
    GM_SITE(vm, 284, 4100280);
    /* @4100288 store */
    v83 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v83);
    /* @4100296 load */
    /* @4100304 load */
    /* @4100312 cast */
    /* @4100316 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "shotgundamage"));
    /* @4100324 load */
    /* @4100332 constant */
    /* @4100336 add */
    /* @4100340 store */
    v84 = GM_ADD(GM_READ(vm, -5, "shotgunxp"), VAL(1));
    GM_WRITE(vm, -5, "shotgunxp", v84);
    L_4100348: ;
    /* @4100348 load */
    /* @4100356 constant */
    /* @4100360 cmp */
    /* @4100364 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4100504;
    /* @4100368 load */
    /* @4100376 cast */
    /* @4100380 dup */
    /* @4100384 load */
    /* @4100392 load */
    /* @4100400 sub */
    /* @4100404 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit") - GM_READ(vm, -5, "assaultrifledamage")));
    /* @4100412 constant */
    /* @4100416 cast */
    /* @4100420 load */
    /* @4100428 load */
    /* @4100436 call */
    GM_SITE(vm, 284, 4100436);
    /* @4100444 store */
    v85 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v85);
    /* @4100452 load */
    /* @4100460 load */
    /* @4100468 cast */
    /* @4100472 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "assaultrifledamage"));
    /* @4100480 load */
    /* @4100488 constant */
    /* @4100492 add */
    /* @4100496 store */
    v86 = GM_ADD(GM_READ(vm, -5, "assaultriflexp"), VAL(1));
    GM_WRITE(vm, -5, "assaultriflexp", v86);
    L_4100504: ;
    /* @4100504 constant */
    /* @4100508 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4100516 load */
    /* @4100524 constant */
    /* @4100528 cmp */
    /* @4100532 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4100540;
    /* @4100536 b */
    goto L_4100596;
    L_4100540: ;
    /* @4100540 load */
    /* @4100548 constant */
    /* @4100552 cmp */
    /* @4100556 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4100596;
    /* @4100560 constant */
    /* @4100564 cast */
    /* @4100568 constant */
    /* @4100572 cast */
    /* @4100576 constant */
    /* @4100580 cast */
    /* @4100584 call */
    GM_SITE(vm, 284, 4100584);
    /* @4100592 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4100596: ;
    /* @4100596 call */
    GM_SITE(vm, 284, 4100596);
    /* @4100604 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4100608 constant */
    /* @4100612 load */
    /* @4100620 cast */
    /* @4100624 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "stunned", VAL(1));
    /* @4100632 constant */
    /* @4100636 load */
    /* @4100644 cast */
    /* @4100648 constant */
    /* @4100652 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit11")), "alarm", VAL(4), VAL(10));
    /* @4100660 load */
    /* @4100668 constant */
    /* @4100672 cmp */
    /* @4100676 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4100708;
    /* @4100680 constant */
    /* @4100684 load */
    /* @4100692 cast */
    /* @4100696 constant */
    /* @4100700 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit11")), "alarm", VAL(6), VAL(1));
    L_4100708: ;
    /* @4100708 constant */
    /* @4100712 cast */
    /* @4100716 load */
    /* @4100724 load */
    /* @4100732 call */
    GM_SITE(vm, 284, 4100732);
    /* @4100740 store */
    v87 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(19));
    GM_WRITE(vm, -1, "hit12", v87);
    /* @4100748 load */
    /* @4100756 constant */
    /* @4100760 cmp */
    /* @4100764 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit12") != VAL(-4)))) goto L_4100788;
    /* @4100768 load */
    /* @4100776 constant */
    /* @4100780 cmp */
    /* @4100784 b */
    p4100792_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4100792;
    L_4100788: ;
    /* @4100788 constant */
    p4100792_0 = VAL(0);
    L_4100792: ;
    /* @4100792 bf */
    if (!TRUTH(p4100792_0)) goto L_4101556;
    /* @4100796 constant */
    /* @4100800 load */
    /* @4100808 cast */
    /* @4100812 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "flashing", VAL(1));
    /* @4100820 constant */
    /* @4100824 cast */
    /* @4100828 load */
    /* @4100836 load */
    /* @4100844 load */
    /* @4100852 load */
    /* @4100860 call */
    GM_SITE(vm, 284, 4100860);
    /* @4100868 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4100872 constant */
    /* @4100876 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4100884 load */
    /* @4100892 constant */
    /* @4100896 cmp */
    /* @4100900 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4101040;
    /* @4100904 load */
    /* @4100912 cast */
    /* @4100916 dup */
    /* @4100920 load */
    /* @4100928 load */
    /* @4100936 sub */
    /* @4100940 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie") - GM_READ(vm, -5, "pistoldamage")));
    /* @4100948 constant */
    /* @4100952 cast */
    /* @4100956 load */
    /* @4100964 load */
    /* @4100972 call */
    GM_SITE(vm, 284, 4100972);
    /* @4100980 store */
    v88 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v88);
    /* @4100988 load */
    /* @4100996 load */
    /* @4101004 cast */
    /* @4101008 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "pistoldamage"));
    /* @4101016 load */
    /* @4101024 constant */
    /* @4101028 add */
    /* @4101032 store */
    v89 = GM_ADD(GM_READ(vm, -5, "pistolxp"), VAL(1));
    GM_WRITE(vm, -5, "pistolxp", v89);
    L_4101040: ;
    /* @4101040 load */
    /* @4101048 constant */
    /* @4101052 cmp */
    /* @4101056 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4101196;
    /* @4101060 load */
    /* @4101068 cast */
    /* @4101072 dup */
    /* @4101076 load */
    /* @4101084 load */
    /* @4101092 sub */
    /* @4101096 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie") - GM_READ(vm, -5, "shotgundamage")));
    /* @4101104 constant */
    /* @4101108 cast */
    /* @4101112 load */
    /* @4101120 load */
    /* @4101128 call */
    GM_SITE(vm, 284, 4101128);
    /* @4101136 store */
    v90 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v90);
    /* @4101144 load */
    /* @4101152 load */
    /* @4101160 cast */
    /* @4101164 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "shotgundamage"));
    /* @4101172 load */
    /* @4101180 constant */
    /* @4101184 add */
    /* @4101188 store */
    v91 = GM_ADD(GM_READ(vm, -5, "shotgunxp"), VAL(1));
    GM_WRITE(vm, -5, "shotgunxp", v91);
    L_4101196: ;
    /* @4101196 load */
    /* @4101204 constant */
    /* @4101208 cmp */
    /* @4101212 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4101352;
    /* @4101216 load */
    /* @4101224 cast */
    /* @4101228 dup */
    /* @4101232 load */
    /* @4101240 load */
    /* @4101248 sub */
    /* @4101252 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie") - GM_READ(vm, -5, "assaultrifledamage")));
    /* @4101260 constant */
    /* @4101264 cast */
    /* @4101268 load */
    /* @4101276 load */
    /* @4101284 call */
    GM_SITE(vm, 284, 4101284);
    /* @4101292 store */
    v92 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v92);
    /* @4101300 load */
    /* @4101308 load */
    /* @4101316 cast */
    /* @4101320 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "assaultrifledamage"));
    /* @4101328 load */
    /* @4101336 constant */
    /* @4101340 add */
    /* @4101344 store */
    v93 = GM_ADD(GM_READ(vm, -5, "assaultriflexp"), VAL(1));
    GM_WRITE(vm, -5, "assaultriflexp", v93);
    L_4101352: ;
    /* @4101352 constant */
    /* @4101356 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4101364 load */
    /* @4101372 constant */
    /* @4101376 cmp */
    /* @4101380 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4101388;
    /* @4101384 b */
    goto L_4101444;
    L_4101388: ;
    /* @4101388 load */
    /* @4101396 constant */
    /* @4101400 cmp */
    /* @4101404 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4101444;
    /* @4101408 constant */
    /* @4101412 cast */
    /* @4101416 constant */
    /* @4101420 cast */
    /* @4101424 constant */
    /* @4101428 cast */
    /* @4101432 call */
    GM_SITE(vm, 284, 4101432);
    /* @4101440 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4101444: ;
    /* @4101444 call */
    GM_SITE(vm, 284, 4101444);
    /* @4101452 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4101456 constant */
    /* @4101460 load */
    /* @4101468 cast */
    /* @4101472 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "stunned", VAL(1));
    /* @4101480 constant */
    /* @4101484 load */
    /* @4101492 cast */
    /* @4101496 constant */
    /* @4101500 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit12")), "alarm", VAL(4), VAL(10));
    /* @4101508 load */
    /* @4101516 constant */
    /* @4101520 cmp */
    /* @4101524 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4101556;
    /* @4101528 constant */
    /* @4101532 load */
    /* @4101540 cast */
    /* @4101544 constant */
    /* @4101548 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit12")), "alarm", VAL(6), VAL(1));
    L_4101556: ;
    /* @4101556 constant */
    /* @4101560 cast */
    /* @4101564 load */
    /* @4101572 load */
    /* @4101580 call */
    GM_SITE(vm, 284, 4101580);
    /* @4101588 store */
    v94 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(18));
    GM_WRITE(vm, -1, "hit13", v94);
    /* @4101596 load */
    /* @4101604 constant */
    /* @4101608 cmp */
    /* @4101612 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit13") != VAL(-4)))) goto L_4101636;
    /* @4101616 load */
    /* @4101624 constant */
    /* @4101628 cmp */
    /* @4101632 b */
    p4101640_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4101640;
    L_4101636: ;
    /* @4101636 constant */
    p4101640_0 = VAL(0);
    L_4101640: ;
    /* @4101640 bf */
    if (!TRUTH(p4101640_0)) goto L_4102404;
    /* @4101644 constant */
    /* @4101648 load */
    /* @4101656 cast */
    /* @4101660 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "flashing", VAL(1));
    /* @4101668 constant */
    /* @4101672 cast */
    /* @4101676 load */
    /* @4101684 load */
    /* @4101692 load */
    /* @4101700 load */
    /* @4101708 call */
    GM_SITE(vm, 284, 4101708);
    /* @4101716 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4101720 constant */
    /* @4101724 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4101732 load */
    /* @4101740 constant */
    /* @4101744 cmp */
    /* @4101748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4101888;
    /* @4101752 load */
    /* @4101760 cast */
    /* @4101764 dup */
    /* @4101768 load */
    /* @4101776 load */
    /* @4101784 sub */
    /* @4101788 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk") - GM_READ(vm, -5, "pistoldamage")));
    /* @4101796 constant */
    /* @4101800 cast */
    /* @4101804 load */
    /* @4101812 load */
    /* @4101820 call */
    GM_SITE(vm, 284, 4101820);
    /* @4101828 store */
    v95 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v95);
    /* @4101836 load */
    /* @4101844 load */
    /* @4101852 cast */
    /* @4101856 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "pistoldamage"));
    /* @4101864 load */
    /* @4101872 constant */
    /* @4101876 add */
    /* @4101880 store */
    v96 = GM_ADD(GM_READ(vm, -5, "pistolxp"), VAL(1));
    GM_WRITE(vm, -5, "pistolxp", v96);
    L_4101888: ;
    /* @4101888 load */
    /* @4101896 constant */
    /* @4101900 cmp */
    /* @4101904 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4102044;
    /* @4101908 load */
    /* @4101916 cast */
    /* @4101920 dup */
    /* @4101924 load */
    /* @4101932 load */
    /* @4101940 sub */
    /* @4101944 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk") - GM_READ(vm, -5, "shotgundamage")));
    /* @4101952 constant */
    /* @4101956 cast */
    /* @4101960 load */
    /* @4101968 load */
    /* @4101976 call */
    GM_SITE(vm, 284, 4101976);
    /* @4101984 store */
    v97 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v97);
    /* @4101992 load */
    /* @4102000 load */
    /* @4102008 cast */
    /* @4102012 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "shotgundamage"));
    /* @4102020 load */
    /* @4102028 constant */
    /* @4102032 add */
    /* @4102036 store */
    v98 = GM_ADD(GM_READ(vm, -5, "shotgunxp"), VAL(1));
    GM_WRITE(vm, -5, "shotgunxp", v98);
    L_4102044: ;
    /* @4102044 load */
    /* @4102052 constant */
    /* @4102056 cmp */
    /* @4102060 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4102200;
    /* @4102064 load */
    /* @4102072 cast */
    /* @4102076 dup */
    /* @4102080 load */
    /* @4102088 load */
    /* @4102096 sub */
    /* @4102100 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk") - GM_READ(vm, -5, "assaultrifledamage")));
    /* @4102108 constant */
    /* @4102112 cast */
    /* @4102116 load */
    /* @4102124 load */
    /* @4102132 call */
    GM_SITE(vm, 284, 4102132);
    /* @4102140 store */
    v99 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v99);
    /* @4102148 load */
    /* @4102156 load */
    /* @4102164 cast */
    /* @4102168 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "assaultrifledamage"));
    /* @4102176 load */
    /* @4102184 constant */
    /* @4102188 add */
    /* @4102192 store */
    v100 = GM_ADD(GM_READ(vm, -5, "assaultriflexp"), VAL(1));
    GM_WRITE(vm, -5, "assaultriflexp", v100);
    L_4102200: ;
    /* @4102200 constant */
    /* @4102204 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4102212 load */
    /* @4102220 constant */
    /* @4102224 cmp */
    /* @4102228 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4102236;
    /* @4102232 b */
    goto L_4102292;
    L_4102236: ;
    /* @4102236 load */
    /* @4102244 constant */
    /* @4102248 cmp */
    /* @4102252 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4102292;
    /* @4102256 constant */
    /* @4102260 cast */
    /* @4102264 constant */
    /* @4102268 cast */
    /* @4102272 constant */
    /* @4102276 cast */
    /* @4102280 call */
    GM_SITE(vm, 284, 4102280);
    /* @4102288 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4102292: ;
    /* @4102292 call */
    GM_SITE(vm, 284, 4102292);
    /* @4102300 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4102304 constant */
    /* @4102308 load */
    /* @4102316 cast */
    /* @4102320 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "stunned", VAL(1));
    /* @4102328 constant */
    /* @4102332 load */
    /* @4102340 cast */
    /* @4102344 constant */
    /* @4102348 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit13")), "alarm", VAL(4), VAL(10));
    /* @4102356 load */
    /* @4102364 constant */
    /* @4102368 cmp */
    /* @4102372 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4102404;
    /* @4102376 constant */
    /* @4102380 load */
    /* @4102388 cast */
    /* @4102392 constant */
    /* @4102396 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit13")), "alarm", VAL(7), VAL(1));
    L_4102404: ;
    /* @4102404 constant */
    /* @4102408 cast */
    /* @4102412 load */
    /* @4102420 load */
    /* @4102428 call */
    GM_SITE(vm, 284, 4102428);
    /* @4102436 store */
    v101 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(17));
    GM_WRITE(vm, -1, "hit14", v101);
    /* @4102444 load */
    /* @4102452 constant */
    /* @4102456 cmp */
    /* @4102460 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit14") != VAL(-4)))) goto L_4102484;
    /* @4102464 load */
    /* @4102472 constant */
    /* @4102476 cmp */
    /* @4102480 b */
    p4102488_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4102488;
    L_4102484: ;
    /* @4102484 constant */
    p4102488_0 = VAL(0);
    L_4102488: ;
    /* @4102488 bf */
    if (!TRUTH(p4102488_0)) goto L_4103252;
    /* @4102492 constant */
    /* @4102496 load */
    /* @4102504 cast */
    /* @4102508 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "flashing", VAL(1));
    /* @4102516 constant */
    /* @4102520 cast */
    /* @4102524 load */
    /* @4102532 load */
    /* @4102540 load */
    /* @4102548 load */
    /* @4102556 call */
    GM_SITE(vm, 284, 4102556);
    /* @4102564 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4102568 constant */
    /* @4102572 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4102580 load */
    /* @4102588 constant */
    /* @4102592 cmp */
    /* @4102596 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4102736;
    /* @4102600 load */
    /* @4102608 cast */
    /* @4102612 dup */
    /* @4102616 load */
    /* @4102624 load */
    /* @4102632 sub */
    /* @4102636 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton") - GM_READ(vm, -5, "pistoldamage")));
    /* @4102644 constant */
    /* @4102648 cast */
    /* @4102652 load */
    /* @4102660 load */
    /* @4102668 call */
    GM_SITE(vm, 284, 4102668);
    /* @4102676 store */
    v102 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v102);
    /* @4102684 load */
    /* @4102692 load */
    /* @4102700 cast */
    /* @4102704 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "pistoldamage"));
    /* @4102712 load */
    /* @4102720 constant */
    /* @4102724 add */
    /* @4102728 store */
    v103 = GM_ADD(GM_READ(vm, -5, "pistolxp"), VAL(1));
    GM_WRITE(vm, -5, "pistolxp", v103);
    L_4102736: ;
    /* @4102736 load */
    /* @4102744 constant */
    /* @4102748 cmp */
    /* @4102752 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4102892;
    /* @4102756 load */
    /* @4102764 cast */
    /* @4102768 dup */
    /* @4102772 load */
    /* @4102780 load */
    /* @4102788 sub */
    /* @4102792 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton") - GM_READ(vm, -5, "shotgundamage")));
    /* @4102800 constant */
    /* @4102804 cast */
    /* @4102808 load */
    /* @4102816 load */
    /* @4102824 call */
    GM_SITE(vm, 284, 4102824);
    /* @4102832 store */
    v104 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v104);
    /* @4102840 load */
    /* @4102848 load */
    /* @4102856 cast */
    /* @4102860 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "shotgundamage"));
    /* @4102868 load */
    /* @4102876 constant */
    /* @4102880 add */
    /* @4102884 store */
    v105 = GM_ADD(GM_READ(vm, -5, "shotgunxp"), VAL(1));
    GM_WRITE(vm, -5, "shotgunxp", v105);
    L_4102892: ;
    /* @4102892 load */
    /* @4102900 constant */
    /* @4102904 cmp */
    /* @4102908 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4103048;
    /* @4102912 load */
    /* @4102920 cast */
    /* @4102924 dup */
    /* @4102928 load */
    /* @4102936 load */
    /* @4102944 sub */
    /* @4102948 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton") - GM_READ(vm, -5, "assaultrifledamage")));
    /* @4102956 constant */
    /* @4102960 cast */
    /* @4102964 load */
    /* @4102972 load */
    /* @4102980 call */
    GM_SITE(vm, 284, 4102980);
    /* @4102988 store */
    v106 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v106);
    /* @4102996 load */
    /* @4103004 load */
    /* @4103012 cast */
    /* @4103016 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "assaultrifledamage"));
    /* @4103024 load */
    /* @4103032 constant */
    /* @4103036 add */
    /* @4103040 store */
    v107 = GM_ADD(GM_READ(vm, -5, "assaultriflexp"), VAL(1));
    GM_WRITE(vm, -5, "assaultriflexp", v107);
    L_4103048: ;
    /* @4103048 constant */
    /* @4103052 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4103060 load */
    /* @4103068 constant */
    /* @4103072 cmp */
    /* @4103076 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4103084;
    /* @4103080 b */
    goto L_4103140;
    L_4103084: ;
    /* @4103084 load */
    /* @4103092 constant */
    /* @4103096 cmp */
    /* @4103100 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4103140;
    /* @4103104 constant */
    /* @4103108 cast */
    /* @4103112 constant */
    /* @4103116 cast */
    /* @4103120 constant */
    /* @4103124 cast */
    /* @4103128 call */
    GM_SITE(vm, 284, 4103128);
    /* @4103136 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4103140: ;
    /* @4103140 call */
    GM_SITE(vm, 284, 4103140);
    /* @4103148 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4103152 constant */
    /* @4103156 load */
    /* @4103164 cast */
    /* @4103168 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "stunned", VAL(1));
    /* @4103176 constant */
    /* @4103180 load */
    /* @4103188 cast */
    /* @4103192 constant */
    /* @4103196 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit14")), "alarm", VAL(4), VAL(10));
    /* @4103204 load */
    /* @4103212 constant */
    /* @4103216 cmp */
    /* @4103220 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4103252;
    /* @4103224 constant */
    /* @4103228 load */
    /* @4103236 cast */
    /* @4103240 constant */
    /* @4103244 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit14")), "alarm", VAL(6), VAL(1));
    L_4103252: ;
    /* @4103252 constant */
    /* @4103256 cast */
    /* @4103260 load */
    /* @4103268 load */
    /* @4103276 call */
    GM_SITE(vm, 284, 4103276);
    /* @4103284 store */
    v108 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(26));
    GM_WRITE(vm, -1, "hit15", v108);
    /* @4103292 load */
    /* @4103300 constant */
    /* @4103304 cmp */
    /* @4103308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit15") != VAL(-4)))) goto L_4103332;
    /* @4103312 load */
    /* @4103320 constant */
    /* @4103324 cmp */
    /* @4103328 b */
    p4103336_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4103336;
    L_4103332: ;
    /* @4103332 constant */
    p4103336_0 = VAL(0);
    L_4103336: ;
    /* @4103336 bf */
    if (!TRUTH(p4103336_0)) goto L_4104048;
    /* @4103340 constant */
    /* @4103344 load */
    /* @4103352 cast */
    /* @4103356 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15")), "flashing", VAL(1));
    /* @4103364 constant */
    /* @4103368 cast */
    /* @4103372 load */
    /* @4103380 load */
    /* @4103388 load */
    /* @4103396 load */
    /* @4103404 call */
    GM_SITE(vm, 284, 4103404);
    /* @4103412 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4103416 constant */
    /* @4103420 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4103428 load */
    /* @4103436 constant */
    /* @4103440 cmp */
    /* @4103444 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4103584;
    /* @4103448 load */
    /* @4103456 cast */
    /* @4103460 dup */
    /* @4103464 load */
    /* @4103472 load */
    /* @4103480 sub */
    /* @4103484 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2") - GM_READ(vm, -5, "pistoldamage")));
    /* @4103492 constant */
    /* @4103496 cast */
    /* @4103500 load */
    /* @4103508 load */
    /* @4103516 call */
    GM_SITE(vm, 284, 4103516);
    /* @4103524 store */
    v109 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v109);
    /* @4103532 load */
    /* @4103540 load */
    /* @4103548 cast */
    /* @4103552 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "pistoldamage"));
    /* @4103560 load */
    /* @4103568 constant */
    /* @4103572 add */
    /* @4103576 store */
    v110 = GM_ADD(GM_READ(vm, -5, "pistolxp"), VAL(1));
    GM_WRITE(vm, -5, "pistolxp", v110);
    L_4103584: ;
    /* @4103584 load */
    /* @4103592 constant */
    /* @4103596 cmp */
    /* @4103600 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4103740;
    /* @4103604 load */
    /* @4103612 cast */
    /* @4103616 dup */
    /* @4103620 load */
    /* @4103628 load */
    /* @4103636 sub */
    /* @4103640 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2") - GM_READ(vm, -5, "shotgundamage")));
    /* @4103648 constant */
    /* @4103652 cast */
    /* @4103656 load */
    /* @4103664 load */
    /* @4103672 call */
    GM_SITE(vm, 284, 4103672);
    /* @4103680 store */
    v111 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v111);
    /* @4103688 load */
    /* @4103696 load */
    /* @4103704 cast */
    /* @4103708 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "shotgundamage"));
    /* @4103716 load */
    /* @4103724 constant */
    /* @4103728 add */
    /* @4103732 store */
    v112 = GM_ADD(GM_READ(vm, -5, "shotgunxp"), VAL(1));
    GM_WRITE(vm, -5, "shotgunxp", v112);
    L_4103740: ;
    /* @4103740 load */
    /* @4103748 constant */
    /* @4103752 cmp */
    /* @4103756 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4103896;
    /* @4103760 load */
    /* @4103768 cast */
    /* @4103772 dup */
    /* @4103776 load */
    /* @4103784 load */
    /* @4103792 sub */
    /* @4103796 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2") - GM_READ(vm, -5, "assaultrifledamage")));
    /* @4103804 constant */
    /* @4103808 cast */
    /* @4103812 load */
    /* @4103820 load */
    /* @4103828 call */
    GM_SITE(vm, 284, 4103828);
    /* @4103836 store */
    v113 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v113);
    /* @4103844 load */
    /* @4103852 load */
    /* @4103860 cast */
    /* @4103864 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "assaultrifledamage"));
    /* @4103872 load */
    /* @4103880 constant */
    /* @4103884 add */
    /* @4103888 store */
    v114 = GM_ADD(GM_READ(vm, -5, "assaultriflexp"), VAL(1));
    GM_WRITE(vm, -5, "assaultriflexp", v114);
    L_4103896: ;
    /* @4103896 constant */
    /* @4103900 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4103908 load */
    /* @4103916 constant */
    /* @4103920 cmp */
    /* @4103924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4103932;
    /* @4103928 b */
    goto L_4103988;
    L_4103932: ;
    /* @4103932 load */
    /* @4103940 constant */
    /* @4103944 cmp */
    /* @4103948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4103988;
    /* @4103952 constant */
    /* @4103956 cast */
    /* @4103960 constant */
    /* @4103964 cast */
    /* @4103968 constant */
    /* @4103972 cast */
    /* @4103976 call */
    GM_SITE(vm, 284, 4103976);
    /* @4103984 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4103988: ;
    /* @4103988 load */
    /* @4103996 constant */
    /* @4104000 cmp */
    /* @4104004 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4104036;
    /* @4104008 constant */
    /* @4104012 load */
    /* @4104020 cast */
    /* @4104024 constant */
    /* @4104028 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit15")), "alarm", VAL(6), VAL(1));
    L_4104036: ;
    /* @4104036 call */
    GM_SITE(vm, 284, 4104036);
    /* @4104044 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4104048: ;
    /* @4104048 constant */
    /* @4104052 cast */
    /* @4104056 load */
    /* @4104064 load */
    /* @4104072 call */
    GM_SITE(vm, 284, 4104072);
    /* @4104080 store */
    v115 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(27));
    GM_WRITE(vm, -1, "hit16", v115);
    /* @4104088 load */
    /* @4104096 constant */
    /* @4104100 cmp */
    /* @4104104 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit16") != VAL(-4)))) goto L_4104128;
    /* @4104108 load */
    /* @4104116 constant */
    /* @4104120 cmp */
    /* @4104124 b */
    p4104132_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4104132;
    L_4104128: ;
    /* @4104128 constant */
    p4104132_0 = VAL(0);
    L_4104132: ;
    /* @4104132 bf */
    if (!TRUTH(p4104132_0)) goto L_4104800;
    /* @4104136 constant */
    /* @4104140 load */
    /* @4104148 cast */
    /* @4104152 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16")), "flashing", VAL(1));
    /* @4104160 constant */
    /* @4104164 cast */
    /* @4104168 load */
    /* @4104176 load */
    /* @4104184 load */
    /* @4104192 load */
    /* @4104200 call */
    GM_SITE(vm, 284, 4104200);
    /* @4104208 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4104212 constant */
    /* @4104216 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4104224 load */
    /* @4104232 constant */
    /* @4104236 cmp */
    /* @4104240 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4104380;
    /* @4104244 load */
    /* @4104252 cast */
    /* @4104256 dup */
    /* @4104260 load */
    /* @4104268 load */
    /* @4104276 sub */
    /* @4104280 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3") - GM_READ(vm, -5, "pistoldamage")));
    /* @4104288 constant */
    /* @4104292 cast */
    /* @4104296 load */
    /* @4104304 load */
    /* @4104312 call */
    GM_SITE(vm, 284, 4104312);
    /* @4104320 store */
    v116 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v116);
    /* @4104328 load */
    /* @4104336 load */
    /* @4104344 cast */
    /* @4104348 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "pistoldamage"));
    /* @4104356 load */
    /* @4104364 constant */
    /* @4104368 add */
    /* @4104372 store */
    v117 = GM_ADD(GM_READ(vm, -5, "pistolxp"), VAL(1));
    GM_WRITE(vm, -5, "pistolxp", v117);
    L_4104380: ;
    /* @4104380 load */
    /* @4104388 constant */
    /* @4104392 cmp */
    /* @4104396 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4104536;
    /* @4104400 load */
    /* @4104408 cast */
    /* @4104412 dup */
    /* @4104416 load */
    /* @4104424 load */
    /* @4104432 sub */
    /* @4104436 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3") - GM_READ(vm, -5, "shotgundamage")));
    /* @4104444 constant */
    /* @4104448 cast */
    /* @4104452 load */
    /* @4104460 load */
    /* @4104468 call */
    GM_SITE(vm, 284, 4104468);
    /* @4104476 store */
    v118 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v118);
    /* @4104484 load */
    /* @4104492 load */
    /* @4104500 cast */
    /* @4104504 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "shotgundamage"));
    /* @4104512 load */
    /* @4104520 constant */
    /* @4104524 add */
    /* @4104528 store */
    v119 = GM_ADD(GM_READ(vm, -5, "shotgunxp"), VAL(1));
    GM_WRITE(vm, -5, "shotgunxp", v119);
    L_4104536: ;
    /* @4104536 load */
    /* @4104544 constant */
    /* @4104548 cmp */
    /* @4104552 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4104692;
    /* @4104556 load */
    /* @4104564 cast */
    /* @4104568 dup */
    /* @4104572 load */
    /* @4104580 load */
    /* @4104588 sub */
    /* @4104592 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3") - GM_READ(vm, -5, "assaultrifledamage")));
    /* @4104600 constant */
    /* @4104604 cast */
    /* @4104608 load */
    /* @4104616 load */
    /* @4104624 call */
    GM_SITE(vm, 284, 4104624);
    /* @4104632 store */
    v120 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v120);
    /* @4104640 load */
    /* @4104648 load */
    /* @4104656 cast */
    /* @4104660 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "assaultrifledamage"));
    /* @4104668 load */
    /* @4104676 constant */
    /* @4104680 add */
    /* @4104684 store */
    v121 = GM_ADD(GM_READ(vm, -5, "assaultriflexp"), VAL(1));
    GM_WRITE(vm, -5, "assaultriflexp", v121);
    L_4104692: ;
    /* @4104692 constant */
    /* @4104696 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4104704 load */
    /* @4104712 constant */
    /* @4104716 cmp */
    /* @4104720 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4104728;
    /* @4104724 b */
    goto L_4104784;
    L_4104728: ;
    /* @4104728 load */
    /* @4104736 constant */
    /* @4104740 cmp */
    /* @4104744 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4104784;
    /* @4104748 constant */
    /* @4104752 cast */
    /* @4104756 constant */
    /* @4104760 cast */
    /* @4104764 constant */
    /* @4104768 cast */
    /* @4104772 call */
    GM_SITE(vm, 284, 4104772);
    /* @4104780 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4104784: ;
    /* @4104784 call */
    GM_SITE(vm, 284, 4104784);
    /* @4104792 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4104796 b */
    goto L_4104800;
    L_4104800: ;
    /* @4104800 constant */
    /* @4104804 cast */
    /* @4104808 load */
    /* @4104816 load */
    /* @4104824 call */
    GM_SITE(vm, 284, 4104824);
    /* @4104832 store */
    v122 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(28));
    GM_WRITE(vm, -1, "hitboss4", v122);
    /* @4104840 load */
    /* @4104848 constant */
    /* @4104852 cmp */
    /* @4104856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss4") != VAL(-4)))) goto L_4104880;
    /* @4104860 load */
    /* @4104868 constant */
    /* @4104872 cmp */
    /* @4104876 b */
    p4104884_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4104884;
    L_4104880: ;
    /* @4104880 constant */
    p4104884_0 = VAL(0);
    L_4104884: ;
    /* @4104884 bf */
    if (!TRUTH(p4104884_0)) goto L_4105548;
    /* @4104888 constant */
    /* @4104892 load */
    /* @4104900 cast */
    /* @4104904 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "flashing", VAL(1));
    /* @4104912 constant */
    /* @4104916 cast */
    /* @4104920 load */
    /* @4104928 load */
    /* @4104936 load */
    /* @4104944 load */
    /* @4104952 call */
    GM_SITE(vm, 284, 4104952);
    /* @4104960 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4104964 constant */
    /* @4104968 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4104976 load */
    /* @4104984 constant */
    /* @4104988 cmp */
    /* @4104992 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4105132;
    /* @4104996 load */
    /* @4105004 cast */
    /* @4105008 dup */
    /* @4105012 load */
    /* @4105020 load */
    /* @4105028 sub */
    /* @4105032 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4") - GM_READ(vm, -5, "pistoldamage")));
    /* @4105040 constant */
    /* @4105044 cast */
    /* @4105048 load */
    /* @4105056 load */
    /* @4105064 call */
    GM_SITE(vm, 284, 4105064);
    /* @4105072 store */
    v123 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v123);
    /* @4105080 load */
    /* @4105088 load */
    /* @4105096 cast */
    /* @4105100 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "pistoldamage"));
    /* @4105108 load */
    /* @4105116 constant */
    /* @4105120 add */
    /* @4105124 store */
    v124 = GM_ADD(GM_READ(vm, -5, "pistolxp"), VAL(1));
    GM_WRITE(vm, -5, "pistolxp", v124);
    L_4105132: ;
    /* @4105132 load */
    /* @4105140 constant */
    /* @4105144 cmp */
    /* @4105148 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4105288;
    /* @4105152 load */
    /* @4105160 cast */
    /* @4105164 dup */
    /* @4105168 load */
    /* @4105176 load */
    /* @4105184 sub */
    /* @4105188 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4") - GM_READ(vm, -5, "shotgundamage")));
    /* @4105196 constant */
    /* @4105200 cast */
    /* @4105204 load */
    /* @4105212 load */
    /* @4105220 call */
    GM_SITE(vm, 284, 4105220);
    /* @4105228 store */
    v125 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v125);
    /* @4105236 load */
    /* @4105244 load */
    /* @4105252 cast */
    /* @4105256 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "shotgundamage"));
    /* @4105264 load */
    /* @4105272 constant */
    /* @4105276 add */
    /* @4105280 store */
    v126 = GM_ADD(GM_READ(vm, -5, "shotgunxp"), VAL(1));
    GM_WRITE(vm, -5, "shotgunxp", v126);
    L_4105288: ;
    /* @4105288 load */
    /* @4105296 constant */
    /* @4105300 cmp */
    /* @4105304 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4105444;
    /* @4105308 load */
    /* @4105316 cast */
    /* @4105320 dup */
    /* @4105324 load */
    /* @4105332 load */
    /* @4105340 sub */
    /* @4105344 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4") - GM_READ(vm, -5, "assaultrifledamage")));
    /* @4105352 constant */
    /* @4105356 cast */
    /* @4105360 load */
    /* @4105368 load */
    /* @4105376 call */
    GM_SITE(vm, 284, 4105376);
    /* @4105384 store */
    v127 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v127);
    /* @4105392 load */
    /* @4105400 load */
    /* @4105408 cast */
    /* @4105412 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "assaultrifledamage"));
    /* @4105420 load */
    /* @4105428 constant */
    /* @4105432 add */
    /* @4105436 store */
    v128 = GM_ADD(GM_READ(vm, -5, "assaultriflexp"), VAL(1));
    GM_WRITE(vm, -5, "assaultriflexp", v128);
    L_4105444: ;
    /* @4105444 constant */
    /* @4105448 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4105456 load */
    /* @4105464 constant */
    /* @4105468 cmp */
    /* @4105472 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4105480;
    /* @4105476 b */
    goto L_4105536;
    L_4105480: ;
    /* @4105480 load */
    /* @4105488 constant */
    /* @4105492 cmp */
    /* @4105496 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4105536;
    /* @4105500 constant */
    /* @4105504 cast */
    /* @4105508 constant */
    /* @4105512 cast */
    /* @4105516 constant */
    /* @4105520 cast */
    /* @4105524 call */
    GM_SITE(vm, 284, 4105524);
    /* @4105532 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4105536: ;
    /* @4105536 call */
    GM_SITE(vm, 284, 4105536);
    /* @4105544 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4105548: ;
    /* @4105548 constant */
    /* @4105552 cast */
    /* @4105556 load */
    /* @4105564 load */
    /* @4105572 call */
    GM_SITE(vm, 284, 4105572);
    /* @4105580 store */
    v129 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(29));
    GM_WRITE(vm, -1, "hitboss5", v129);
    /* @4105588 load */
    /* @4105596 constant */
    /* @4105600 cmp */
    /* @4105604 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss5") != VAL(-4)))) goto L_4105628;
    /* @4105608 load */
    /* @4105616 constant */
    /* @4105620 cmp */
    /* @4105624 b */
    p4105632_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4105632;
    L_4105628: ;
    /* @4105628 constant */
    p4105632_0 = VAL(0);
    L_4105632: ;
    /* @4105632 bf */
    if (!TRUTH(p4105632_0)) goto L_4106296;
    /* @4105636 constant */
    /* @4105640 load */
    /* @4105648 cast */
    /* @4105652 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "flashing", VAL(1));
    /* @4105660 constant */
    /* @4105664 cast */
    /* @4105668 load */
    /* @4105676 load */
    /* @4105684 load */
    /* @4105692 load */
    /* @4105700 call */
    GM_SITE(vm, 284, 4105700);
    /* @4105708 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4105712 constant */
    /* @4105716 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4105724 load */
    /* @4105732 constant */
    /* @4105736 cmp */
    /* @4105740 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4105880;
    /* @4105744 load */
    /* @4105752 cast */
    /* @4105756 dup */
    /* @4105760 load */
    /* @4105768 load */
    /* @4105776 sub */
    /* @4105780 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5") - GM_READ(vm, -5, "pistoldamage")));
    /* @4105788 constant */
    /* @4105792 cast */
    /* @4105796 load */
    /* @4105804 load */
    /* @4105812 call */
    GM_SITE(vm, 284, 4105812);
    /* @4105820 store */
    v130 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v130);
    /* @4105828 load */
    /* @4105836 load */
    /* @4105844 cast */
    /* @4105848 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "pistoldamage"));
    /* @4105856 load */
    /* @4105864 constant */
    /* @4105868 add */
    /* @4105872 store */
    v131 = GM_ADD(GM_READ(vm, -5, "pistolxp"), VAL(1));
    GM_WRITE(vm, -5, "pistolxp", v131);
    L_4105880: ;
    /* @4105880 load */
    /* @4105888 constant */
    /* @4105892 cmp */
    /* @4105896 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4106036;
    /* @4105900 load */
    /* @4105908 cast */
    /* @4105912 dup */
    /* @4105916 load */
    /* @4105924 load */
    /* @4105932 sub */
    /* @4105936 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5") - GM_READ(vm, -5, "shotgundamage")));
    /* @4105944 constant */
    /* @4105948 cast */
    /* @4105952 load */
    /* @4105960 load */
    /* @4105968 call */
    GM_SITE(vm, 284, 4105968);
    /* @4105976 store */
    v132 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v132);
    /* @4105984 load */
    /* @4105992 load */
    /* @4106000 cast */
    /* @4106004 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "shotgundamage"));
    /* @4106012 load */
    /* @4106020 constant */
    /* @4106024 add */
    /* @4106028 store */
    v133 = GM_ADD(GM_READ(vm, -5, "shotgunxp"), VAL(1));
    GM_WRITE(vm, -5, "shotgunxp", v133);
    L_4106036: ;
    /* @4106036 load */
    /* @4106044 constant */
    /* @4106048 cmp */
    /* @4106052 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4106192;
    /* @4106056 load */
    /* @4106064 cast */
    /* @4106068 dup */
    /* @4106072 load */
    /* @4106080 load */
    /* @4106088 sub */
    /* @4106092 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5") - GM_READ(vm, -5, "assaultrifledamage")));
    /* @4106100 constant */
    /* @4106104 cast */
    /* @4106108 load */
    /* @4106116 load */
    /* @4106124 call */
    GM_SITE(vm, 284, 4106124);
    /* @4106132 store */
    v134 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v134);
    /* @4106140 load */
    /* @4106148 load */
    /* @4106156 cast */
    /* @4106160 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "assaultrifledamage"));
    /* @4106168 load */
    /* @4106176 constant */
    /* @4106180 add */
    /* @4106184 store */
    v135 = GM_ADD(GM_READ(vm, -5, "assaultriflexp"), VAL(1));
    GM_WRITE(vm, -5, "assaultriflexp", v135);
    L_4106192: ;
    /* @4106192 constant */
    /* @4106196 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4106204 load */
    /* @4106212 constant */
    /* @4106216 cmp */
    /* @4106220 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4106228;
    /* @4106224 b */
    goto L_4106284;
    L_4106228: ;
    /* @4106228 load */
    /* @4106236 constant */
    /* @4106240 cmp */
    /* @4106244 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4106284;
    /* @4106248 constant */
    /* @4106252 cast */
    /* @4106256 constant */
    /* @4106260 cast */
    /* @4106264 constant */
    /* @4106268 cast */
    /* @4106272 call */
    GM_SITE(vm, 284, 4106272);
    /* @4106280 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4106284: ;
    /* @4106284 call */
    GM_SITE(vm, 284, 4106284);
    /* @4106292 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4106296: ;
    /* @4106296 constant */
    /* @4106300 cast */
    /* @4106304 load */
    /* @4106312 load */
    /* @4106320 call */
    GM_SITE(vm, 284, 4106320);
    /* @4106328 store */
    v136 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(30));
    GM_WRITE(vm, -1, "hit17", v136);
    /* @4106336 load */
    /* @4106344 constant */
    /* @4106348 cmp */
    /* @4106352 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit17") != VAL(-4)))) goto L_4106376;
    /* @4106356 load */
    /* @4106364 constant */
    /* @4106368 cmp */
    /* @4106372 b */
    p4106380_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4106380;
    L_4106376: ;
    /* @4106376 constant */
    p4106380_0 = VAL(0);
    L_4106380: ;
    /* @4106380 bf */
    if (!TRUTH(p4106380_0)) goto L_4107044;
    /* @4106384 constant */
    /* @4106388 load */
    /* @4106396 cast */
    /* @4106400 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17")), "flashing", VAL(1));
    /* @4106408 constant */
    /* @4106412 cast */
    /* @4106416 load */
    /* @4106424 load */
    /* @4106432 load */
    /* @4106440 load */
    /* @4106448 call */
    GM_SITE(vm, 284, 4106448);
    /* @4106456 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4106460 constant */
    /* @4106464 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4106472 load */
    /* @4106480 constant */
    /* @4106484 cmp */
    /* @4106488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4106628;
    /* @4106492 load */
    /* @4106500 cast */
    /* @4106504 dup */
    /* @4106508 load */
    /* @4106516 load */
    /* @4106524 sub */
    /* @4106528 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss") - GM_READ(vm, -5, "pistoldamage")));
    /* @4106536 constant */
    /* @4106540 cast */
    /* @4106544 load */
    /* @4106552 load */
    /* @4106560 call */
    GM_SITE(vm, 284, 4106560);
    /* @4106568 store */
    v137 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v137);
    /* @4106576 load */
    /* @4106584 load */
    /* @4106592 cast */
    /* @4106596 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "pistoldamage"));
    /* @4106604 load */
    /* @4106612 constant */
    /* @4106616 add */
    /* @4106620 store */
    v138 = GM_ADD(GM_READ(vm, -5, "pistolxp"), VAL(1));
    GM_WRITE(vm, -5, "pistolxp", v138);
    L_4106628: ;
    /* @4106628 load */
    /* @4106636 constant */
    /* @4106640 cmp */
    /* @4106644 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4106784;
    /* @4106648 load */
    /* @4106656 cast */
    /* @4106660 dup */
    /* @4106664 load */
    /* @4106672 load */
    /* @4106680 sub */
    /* @4106684 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss") - GM_READ(vm, -5, "shotgundamage")));
    /* @4106692 constant */
    /* @4106696 cast */
    /* @4106700 load */
    /* @4106708 load */
    /* @4106716 call */
    GM_SITE(vm, 284, 4106716);
    /* @4106724 store */
    v139 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v139);
    /* @4106732 load */
    /* @4106740 load */
    /* @4106748 cast */
    /* @4106752 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "shotgundamage"));
    /* @4106760 load */
    /* @4106768 constant */
    /* @4106772 add */
    /* @4106776 store */
    v140 = GM_ADD(GM_READ(vm, -5, "shotgunxp"), VAL(1));
    GM_WRITE(vm, -5, "shotgunxp", v140);
    L_4106784: ;
    /* @4106784 load */
    /* @4106792 constant */
    /* @4106796 cmp */
    /* @4106800 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4106940;
    /* @4106804 load */
    /* @4106812 cast */
    /* @4106816 dup */
    /* @4106820 load */
    /* @4106828 load */
    /* @4106836 sub */
    /* @4106840 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss") - GM_READ(vm, -5, "assaultrifledamage")));
    /* @4106848 constant */
    /* @4106852 cast */
    /* @4106856 load */
    /* @4106864 load */
    /* @4106872 call */
    GM_SITE(vm, 284, 4106872);
    /* @4106880 store */
    v141 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v141);
    /* @4106888 load */
    /* @4106896 load */
    /* @4106904 cast */
    /* @4106908 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "assaultrifledamage"));
    /* @4106916 load */
    /* @4106924 constant */
    /* @4106928 add */
    /* @4106932 store */
    v142 = GM_ADD(GM_READ(vm, -5, "assaultriflexp"), VAL(1));
    GM_WRITE(vm, -5, "assaultriflexp", v142);
    L_4106940: ;
    /* @4106940 constant */
    /* @4106944 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4106952 load */
    /* @4106960 constant */
    /* @4106964 cmp */
    /* @4106968 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4106976;
    /* @4106972 b */
    goto L_4107032;
    L_4106976: ;
    /* @4106976 load */
    /* @4106984 constant */
    /* @4106988 cmp */
    /* @4106992 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4107032;
    /* @4106996 constant */
    /* @4107000 cast */
    /* @4107004 constant */
    /* @4107008 cast */
    /* @4107012 constant */
    /* @4107016 cast */
    /* @4107020 call */
    GM_SITE(vm, 284, 4107020);
    /* @4107028 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4107032: ;
    /* @4107032 call */
    GM_SITE(vm, 284, 4107032);
    /* @4107040 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4107044: ;
    return;
}
