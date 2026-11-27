/* generated from CODE 294 (gml_Object_obj_spikegunspike_Step_0), source start 4122168, end 4140672. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0294(GmVM* vm) {
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
    /* @4122168 load */
    /* @4122176 constant */
    /* @4122180 cmp */
    /* @4122184 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hspeed") == VAL(0)))) goto L_4122240;
    /* @4122188 constant */
    /* @4122192 cast */
    /* @4122196 load */
    /* @4122204 load */
    /* @4122212 call */
    GM_SITE(vm, 294, 4122212);
    /* @4122220 cast */
    /* @4122224 bf */
    v1 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(42)));
    if (!TRUTH(v1)) goto L_4122240;
    /* @4122228 call */
    GM_SITE(vm, 294, 4122228);
    /* @4122236 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4122240: ;
    /* @4122240 constant */
    /* @4122244 cast */
    /* @4122248 load */
    /* @4122256 load */
    /* @4122264 load */
    /* @4122272 add */
    /* @4122276 call */
    GM_SITE(vm, 294, 4122276);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @4122284 store */
    v3 = GM_CALL(vm, "instance_place", 3, v2, GM_READ(vm, -1, "y"), VAL(42));
    GM_WRITE(vm, -1, "hitspike", v3);
    /* @4122292 load */
    /* @4122300 constant */
    /* @4122304 cmp */
    /* @4122308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitspike") != VAL(-4)))) goto L_4122344;
    /* @4122312 load */
    /* @4122320 cast */
    /* @4122324 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "hitspike")))) goto L_4122340;
    L_4122328: ;
    /* @4122328 call */
    GM_SITE(vm, 294, 4122328);
    /* @4122336 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4122340: ;
    /* @4122340 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4122328;
    L_4122344: ;
    /* @4122344 constant */
    /* @4122348 cast */
    /* @4122352 load */
    /* @4122360 load */
    /* @4122368 load */
    /* @4122376 add */
    /* @4122380 call */
    GM_SITE(vm, 294, 4122380);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @4122388 store */
    v5 = GM_CALL(vm, "instance_place", 3, v4, GM_READ(vm, -1, "y"), VAL(34));
    GM_WRITE(vm, -1, "hitwall", v5);
    /* @4122396 load */
    /* @4122404 constant */
    /* @4122408 cmp */
    /* @4122412 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitwall") != VAL(-4)))) goto L_4122472;
    /* @4122416 load */
    /* @4122424 cast */
    /* @4122428 load */
    /* @4122436 constant */
    /* @4122440 cmp */
    /* @4122444 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwall")), "type") != VAL(3)))) goto L_4122472;
    /* @4122448 constant */
    /* @4122452 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4122460 constant */
    /* @4122464 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_4122472: ;
    /* @4122472 constant */
    /* @4122476 cast */
    /* @4122480 load */
    /* @4122488 load */
    /* @4122496 constant */
    /* @4122500 add */
    /* @4122504 call */
    GM_SITE(vm, 294, 4122504);
    v6 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @4122512 store */
    v7 = GM_CALL(vm, "instance_place", 3, v6, GM_READ(vm, -1, "y"), VAL(15));
    GM_WRITE(vm, -1, "hitknife", v7);
    /* @4122520 load */
    /* @4122528 constant */
    /* @4122532 cmp */
    /* @4122536 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitknife") != VAL(-4)))) goto L_4122960;
    /* @4122540 constant */
    /* @4122544 load */
    /* @4122552 cast */
    /* @4122556 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "flashing", VAL(1));
    /* @4122564 constant */
    /* @4122568 cast */
    /* @4122572 load */
    /* @4122580 load */
    /* @4122588 load */
    /* @4122596 load */
    /* @4122604 call */
    GM_SITE(vm, 294, 4122604);
    /* @4122612 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4122616 load */
    /* @4122624 cast */
    /* @4122628 dup */
    /* @4122632 load */
    /* @4122640 load */
    /* @4122648 sub */
    /* @4122652 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife") - GM_READ(vm, -5, "spikegundamage")));
    /* @4122660 constant */
    /* @4122664 cast */
    /* @4122668 load */
    /* @4122676 load */
    /* @4122684 constant */
    /* @4122688 add */
    /* @4122692 call */
    GM_SITE(vm, 294, 4122692);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @4122700 store */
    v9 = GM_CALL(vm, "instance_create", 3, v8, GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v9);
    /* @4122708 load */
    /* @4122716 load */
    /* @4122724 cast */
    /* @4122728 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4122736 constant */
    /* @4122740 constant */
    /* @4122744 constant */
    /* @4122748 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4122756 constant */
    /* @4122760 load */
    /* @4122768 cast */
    /* @4122772 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "stunned", VAL(1));
    /* @4122780 constant */
    /* @4122784 load */
    /* @4122792 cast */
    /* @4122796 constant */
    /* @4122800 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "alarm", VAL(4), VAL(10));
    /* @4122808 load */
    /* @4122816 constant */
    /* @4122820 cmp */
    /* @4122824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4122832;
    /* @4122828 b */
    goto L_4122888;
    L_4122832: ;
    /* @4122832 load */
    /* @4122840 constant */
    /* @4122844 cmp */
    /* @4122848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4122888;
    /* @4122852 constant */
    /* @4122856 cast */
    /* @4122860 constant */
    /* @4122864 cast */
    /* @4122868 constant */
    /* @4122872 cast */
    /* @4122876 call */
    GM_SITE(vm, 294, 4122876);
    /* @4122884 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4122888: ;
    /* @4122888 load */
    /* @4122896 constant */
    /* @4122900 add */
    /* @4122904 store */
    v10 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v10);
    /* @4122912 load */
    /* @4122920 constant */
    /* @4122924 cmp */
    /* @4122928 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4122960;
    /* @4122932 constant */
    /* @4122936 load */
    /* @4122944 cast */
    /* @4122948 constant */
    /* @4122952 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "alarm", VAL(6), VAL(1));
    L_4122960: ;
    /* @4122960 constant */
    /* @4122964 cast */
    /* @4122968 load */
    /* @4122976 load */
    /* @4122984 constant */
    /* @4122988 sub */
    /* @4122992 call */
    GM_SITE(vm, 294, 4122992);
    /* @4123000 store */
    v11 = GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(20)), GM_READ(vm, -1, "y"), VAL(15));
    GM_WRITE(vm, -1, "hitknife2", v11);
    /* @4123008 load */
    /* @4123016 constant */
    /* @4123020 cmp */
    /* @4123024 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitknife2") != VAL(-4)))) goto L_4123440;
    /* @4123028 constant */
    /* @4123032 load */
    /* @4123040 cast */
    /* @4123044 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife2")), "flashing", VAL(1));
    /* @4123052 constant */
    /* @4123056 cast */
    /* @4123060 load */
    /* @4123068 load */
    /* @4123076 load */
    /* @4123084 load */
    /* @4123092 call */
    GM_SITE(vm, 294, 4123092);
    /* @4123100 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4123104 load */
    /* @4123112 cast */
    /* @4123116 dup */
    /* @4123120 load */
    /* @4123128 load */
    /* @4123136 sub */
    /* @4123140 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife2")), "hpknife", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknife2")), "hpknife") - GM_READ(vm, -5, "spikegundamage")));
    /* @4123148 constant */
    /* @4123152 cast */
    /* @4123156 load */
    /* @4123164 load */
    /* @4123172 call */
    GM_SITE(vm, 294, 4123172);
    /* @4123180 store */
    v12 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v12);
    /* @4123188 load */
    /* @4123196 load */
    /* @4123204 cast */
    /* @4123208 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4123216 constant */
    /* @4123220 constant */
    /* @4123224 constant */
    /* @4123228 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4123236 constant */
    /* @4123240 load */
    /* @4123248 cast */
    /* @4123252 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife2")), "stunned", VAL(1));
    /* @4123260 constant */
    /* @4123264 load */
    /* @4123272 cast */
    /* @4123276 constant */
    /* @4123280 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitknife2")), "alarm", VAL(4), VAL(10));
    /* @4123288 load */
    /* @4123296 constant */
    /* @4123300 cmp */
    /* @4123304 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4123312;
    /* @4123308 b */
    goto L_4123368;
    L_4123312: ;
    /* @4123312 load */
    /* @4123320 constant */
    /* @4123324 cmp */
    /* @4123328 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4123368;
    /* @4123332 constant */
    /* @4123336 cast */
    /* @4123340 constant */
    /* @4123344 cast */
    /* @4123348 constant */
    /* @4123352 cast */
    /* @4123356 call */
    GM_SITE(vm, 294, 4123356);
    /* @4123364 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4123368: ;
    /* @4123368 load */
    /* @4123376 constant */
    /* @4123380 add */
    /* @4123384 store */
    v13 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v13);
    /* @4123392 load */
    /* @4123400 constant */
    /* @4123404 cmp */
    /* @4123408 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4123440;
    /* @4123412 constant */
    /* @4123416 load */
    /* @4123424 cast */
    /* @4123428 constant */
    /* @4123432 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitknife2")), "alarm", VAL(6), VAL(1));
    L_4123440: ;
    /* @4123440 constant */
    /* @4123444 cast */
    /* @4123448 load */
    /* @4123456 load */
    /* @4123464 constant */
    /* @4123468 add */
    /* @4123472 call */
    GM_SITE(vm, 294, 4123472);
    v14 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @4123480 store */
    v15 = GM_CALL(vm, "instance_place", 3, v14, GM_READ(vm, -1, "y"), VAL(14));
    GM_WRITE(vm, -1, "hit", v15);
    /* @4123488 load */
    /* @4123496 constant */
    /* @4123500 cmp */
    /* @4123504 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit") != VAL(-4)))) goto L_4123920;
    /* @4123508 constant */
    /* @4123512 load */
    /* @4123520 cast */
    /* @4123524 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "flashing", VAL(1));
    /* @4123532 constant */
    /* @4123536 cast */
    /* @4123540 load */
    /* @4123548 load */
    /* @4123556 load */
    /* @4123564 load */
    /* @4123572 call */
    GM_SITE(vm, 294, 4123572);
    /* @4123580 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4123584 load */
    /* @4123592 cast */
    /* @4123596 dup */
    /* @4123600 load */
    /* @4123608 load */
    /* @4123616 sub */
    /* @4123620 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp") - GM_READ(vm, -5, "spikegundamage")));
    /* @4123628 constant */
    /* @4123632 cast */
    /* @4123636 load */
    /* @4123644 load */
    /* @4123652 call */
    GM_SITE(vm, 294, 4123652);
    /* @4123660 store */
    v16 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v16);
    /* @4123668 load */
    /* @4123676 load */
    /* @4123684 cast */
    /* @4123688 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4123696 constant */
    /* @4123700 constant */
    /* @4123704 constant */
    /* @4123708 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4123716 constant */
    /* @4123720 load */
    /* @4123728 cast */
    /* @4123732 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "stunned", VAL(1));
    /* @4123740 constant */
    /* @4123744 load */
    /* @4123752 cast */
    /* @4123756 constant */
    /* @4123760 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit")), "alarm", VAL(4), VAL(10));
    /* @4123768 load */
    /* @4123776 constant */
    /* @4123780 cmp */
    /* @4123784 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4123792;
    /* @4123788 b */
    goto L_4123848;
    L_4123792: ;
    /* @4123792 load */
    /* @4123800 constant */
    /* @4123804 cmp */
    /* @4123808 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4123848;
    /* @4123812 constant */
    /* @4123816 cast */
    /* @4123820 constant */
    /* @4123824 cast */
    /* @4123828 constant */
    /* @4123832 cast */
    /* @4123836 call */
    GM_SITE(vm, 294, 4123836);
    /* @4123844 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4123848: ;
    /* @4123848 load */
    /* @4123856 constant */
    /* @4123860 add */
    /* @4123864 store */
    v17 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v17);
    /* @4123872 load */
    /* @4123880 constant */
    /* @4123884 cmp */
    /* @4123888 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4123920;
    /* @4123892 constant */
    /* @4123896 load */
    /* @4123904 cast */
    /* @4123908 constant */
    /* @4123912 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit")), "alarm", VAL(6), VAL(1));
    L_4123920: ;
    /* @4123920 constant */
    /* @4123924 cast */
    /* @4123928 load */
    /* @4123936 load */
    /* @4123944 constant */
    /* @4123948 sub */
    /* @4123952 call */
    GM_SITE(vm, 294, 4123952);
    /* @4123960 store */
    v18 = GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(20)), GM_READ(vm, -1, "y"), VAL(14));
    GM_WRITE(vm, -1, "hitalt", v18);
    /* @4123968 load */
    /* @4123976 constant */
    /* @4123980 cmp */
    /* @4123984 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitalt") != VAL(-4)))) goto L_4124400;
    /* @4123988 constant */
    /* @4123992 load */
    /* @4124000 cast */
    /* @4124004 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitalt")), "flashing", VAL(1));
    /* @4124012 constant */
    /* @4124016 cast */
    /* @4124020 load */
    /* @4124028 load */
    /* @4124036 load */
    /* @4124044 load */
    /* @4124052 call */
    GM_SITE(vm, 294, 4124052);
    /* @4124060 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4124064 load */
    /* @4124072 cast */
    /* @4124076 dup */
    /* @4124080 load */
    /* @4124088 load */
    /* @4124096 sub */
    /* @4124100 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitalt")), "hp", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitalt")), "hp") - GM_READ(vm, -5, "spikegundamage")));
    /* @4124108 constant */
    /* @4124112 cast */
    /* @4124116 load */
    /* @4124124 load */
    /* @4124132 call */
    GM_SITE(vm, 294, 4124132);
    /* @4124140 store */
    v19 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v19);
    /* @4124148 load */
    /* @4124156 load */
    /* @4124164 cast */
    /* @4124168 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4124176 constant */
    /* @4124180 constant */
    /* @4124184 constant */
    /* @4124188 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4124196 constant */
    /* @4124200 load */
    /* @4124208 cast */
    /* @4124212 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitalt")), "stunned", VAL(1));
    /* @4124220 constant */
    /* @4124224 load */
    /* @4124232 cast */
    /* @4124236 constant */
    /* @4124240 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitalt")), "alarm", VAL(4), VAL(10));
    /* @4124248 load */
    /* @4124256 constant */
    /* @4124260 cmp */
    /* @4124264 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4124272;
    /* @4124268 b */
    goto L_4124328;
    L_4124272: ;
    /* @4124272 load */
    /* @4124280 constant */
    /* @4124284 cmp */
    /* @4124288 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4124328;
    /* @4124292 constant */
    /* @4124296 cast */
    /* @4124300 constant */
    /* @4124304 cast */
    /* @4124308 constant */
    /* @4124312 cast */
    /* @4124316 call */
    GM_SITE(vm, 294, 4124316);
    /* @4124324 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4124328: ;
    /* @4124328 load */
    /* @4124336 constant */
    /* @4124340 add */
    /* @4124344 store */
    v20 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v20);
    /* @4124352 load */
    /* @4124360 constant */
    /* @4124364 cmp */
    /* @4124368 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4124400;
    /* @4124372 constant */
    /* @4124376 load */
    /* @4124384 cast */
    /* @4124388 constant */
    /* @4124392 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitalt")), "alarm", VAL(6), VAL(1));
    L_4124400: ;
    /* @4124400 constant */
    /* @4124404 cast */
    /* @4124408 load */
    /* @4124416 load */
    /* @4124424 constant */
    /* @4124428 add */
    /* @4124432 call */
    GM_SITE(vm, 294, 4124432);
    v21 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @4124440 store */
    v22 = GM_CALL(vm, "instance_place", 3, v21, GM_READ(vm, -1, "y"), VAL(23));
    GM_WRITE(vm, -1, "hitwolf", v22);
    /* @4124448 load */
    /* @4124456 constant */
    /* @4124460 cmp */
    /* @4124464 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitwolf") != VAL(-4)))) goto L_4124880;
    /* @4124468 constant */
    /* @4124472 load */
    /* @4124480 cast */
    /* @4124484 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "flashing", VAL(1));
    /* @4124492 constant */
    /* @4124496 cast */
    /* @4124500 load */
    /* @4124508 load */
    /* @4124516 load */
    /* @4124524 load */
    /* @4124532 call */
    GM_SITE(vm, 294, 4124532);
    /* @4124540 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4124544 load */
    /* @4124552 cast */
    /* @4124556 dup */
    /* @4124560 load */
    /* @4124568 load */
    /* @4124576 sub */
    /* @4124580 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf") - GM_READ(vm, -5, "spikegundamage")));
    /* @4124588 constant */
    /* @4124592 cast */
    /* @4124596 load */
    /* @4124604 load */
    /* @4124612 call */
    GM_SITE(vm, 294, 4124612);
    /* @4124620 store */
    v23 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v23);
    /* @4124628 load */
    /* @4124636 load */
    /* @4124644 cast */
    /* @4124648 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4124656 constant */
    /* @4124660 constant */
    /* @4124664 constant */
    /* @4124668 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4124676 constant */
    /* @4124680 load */
    /* @4124688 cast */
    /* @4124692 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "stunned", VAL(1));
    /* @4124700 constant */
    /* @4124704 load */
    /* @4124712 cast */
    /* @4124716 constant */
    /* @4124720 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "alarm", VAL(4), VAL(10));
    /* @4124728 load */
    /* @4124736 constant */
    /* @4124740 cmp */
    /* @4124744 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4124752;
    /* @4124748 b */
    goto L_4124808;
    L_4124752: ;
    /* @4124752 load */
    /* @4124760 constant */
    /* @4124764 cmp */
    /* @4124768 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4124808;
    /* @4124772 constant */
    /* @4124776 cast */
    /* @4124780 constant */
    /* @4124784 cast */
    /* @4124788 constant */
    /* @4124792 cast */
    /* @4124796 call */
    GM_SITE(vm, 294, 4124796);
    /* @4124804 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4124808: ;
    /* @4124808 load */
    /* @4124816 constant */
    /* @4124820 add */
    /* @4124824 store */
    v24 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v24);
    /* @4124832 load */
    /* @4124840 constant */
    /* @4124844 cmp */
    /* @4124848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4124880;
    /* @4124852 constant */
    /* @4124856 load */
    /* @4124864 cast */
    /* @4124868 constant */
    /* @4124872 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "alarm", VAL(6), VAL(1));
    L_4124880: ;
    /* @4124880 constant */
    /* @4124884 cast */
    /* @4124888 load */
    /* @4124896 load */
    /* @4124904 constant */
    /* @4124908 sub */
    /* @4124912 call */
    GM_SITE(vm, 294, 4124912);
    /* @4124920 store */
    v25 = GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(20)), GM_READ(vm, -1, "y"), VAL(23));
    GM_WRITE(vm, -1, "hitwolfalt", v25);
    /* @4124928 load */
    /* @4124936 constant */
    /* @4124940 cmp */
    /* @4124944 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitwolfalt") != VAL(-4)))) goto L_4125360;
    /* @4124948 constant */
    /* @4124952 load */
    /* @4124960 cast */
    /* @4124964 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolfalt")), "flashing", VAL(1));
    /* @4124972 constant */
    /* @4124976 cast */
    /* @4124980 load */
    /* @4124988 load */
    /* @4124996 load */
    /* @4125004 load */
    /* @4125012 call */
    GM_SITE(vm, 294, 4125012);
    /* @4125020 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4125024 load */
    /* @4125032 cast */
    /* @4125036 dup */
    /* @4125040 load */
    /* @4125048 load */
    /* @4125056 sub */
    /* @4125060 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolfalt")), "hpwolf", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolfalt")), "hpwolf") - GM_READ(vm, -5, "spikegundamage")));
    /* @4125068 constant */
    /* @4125072 cast */
    /* @4125076 load */
    /* @4125084 load */
    /* @4125092 call */
    GM_SITE(vm, 294, 4125092);
    /* @4125100 store */
    v26 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v26);
    /* @4125108 load */
    /* @4125116 load */
    /* @4125124 cast */
    /* @4125128 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4125136 constant */
    /* @4125140 constant */
    /* @4125144 constant */
    /* @4125148 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4125156 constant */
    /* @4125160 load */
    /* @4125168 cast */
    /* @4125172 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolfalt")), "stunned", VAL(1));
    /* @4125180 constant */
    /* @4125184 load */
    /* @4125192 cast */
    /* @4125196 constant */
    /* @4125200 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitwolfalt")), "alarm", VAL(4), VAL(10));
    /* @4125208 load */
    /* @4125216 constant */
    /* @4125220 cmp */
    /* @4125224 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4125232;
    /* @4125228 b */
    goto L_4125288;
    L_4125232: ;
    /* @4125232 load */
    /* @4125240 constant */
    /* @4125244 cmp */
    /* @4125248 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4125288;
    /* @4125252 constant */
    /* @4125256 cast */
    /* @4125260 constant */
    /* @4125264 cast */
    /* @4125268 constant */
    /* @4125272 cast */
    /* @4125276 call */
    GM_SITE(vm, 294, 4125276);
    /* @4125284 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4125288: ;
    /* @4125288 load */
    /* @4125296 constant */
    /* @4125300 add */
    /* @4125304 store */
    v27 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v27);
    /* @4125312 load */
    /* @4125320 constant */
    /* @4125324 cmp */
    /* @4125328 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4125360;
    /* @4125332 constant */
    /* @4125336 load */
    /* @4125344 cast */
    /* @4125348 constant */
    /* @4125352 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitwolfalt")), "alarm", VAL(6), VAL(1));
    L_4125360: ;
    /* @4125360 constant */
    /* @4125364 cast */
    /* @4125368 load */
    /* @4125376 load */
    /* @4125384 constant */
    /* @4125388 add */
    /* @4125392 call */
    GM_SITE(vm, 294, 4125392);
    v28 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @4125400 store */
    v29 = GM_CALL(vm, "instance_place", 3, v28, GM_READ(vm, -1, "y"), VAL(22));
    GM_WRITE(vm, -1, "hit2", v29);
    /* @4125408 load */
    /* @4125416 constant */
    /* @4125420 cmp */
    /* @4125424 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit2") != VAL(-4)))) goto L_4125840;
    /* @4125428 constant */
    /* @4125432 load */
    /* @4125440 cast */
    /* @4125444 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "flashing", VAL(1));
    /* @4125452 constant */
    /* @4125456 cast */
    /* @4125460 load */
    /* @4125468 load */
    /* @4125476 load */
    /* @4125484 load */
    /* @4125492 call */
    GM_SITE(vm, 294, 4125492);
    /* @4125500 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4125504 load */
    /* @4125512 cast */
    /* @4125516 dup */
    /* @4125520 load */
    /* @4125528 load */
    /* @4125536 sub */
    /* @4125540 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo") - GM_READ(vm, -5, "spikegundamage")));
    /* @4125548 constant */
    /* @4125552 cast */
    /* @4125556 load */
    /* @4125564 load */
    /* @4125572 call */
    GM_SITE(vm, 294, 4125572);
    /* @4125580 store */
    v30 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v30);
    /* @4125588 load */
    /* @4125596 load */
    /* @4125604 cast */
    /* @4125608 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4125616 constant */
    /* @4125620 constant */
    /* @4125624 constant */
    /* @4125628 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4125636 constant */
    /* @4125640 load */
    /* @4125648 cast */
    /* @4125652 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "stunned", VAL(1));
    /* @4125660 constant */
    /* @4125664 load */
    /* @4125672 cast */
    /* @4125676 constant */
    /* @4125680 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit2")), "alarm", VAL(4), VAL(10));
    /* @4125688 load */
    /* @4125696 constant */
    /* @4125700 cmp */
    /* @4125704 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4125712;
    /* @4125708 b */
    goto L_4125768;
    L_4125712: ;
    /* @4125712 load */
    /* @4125720 constant */
    /* @4125724 cmp */
    /* @4125728 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4125768;
    /* @4125732 constant */
    /* @4125736 cast */
    /* @4125740 constant */
    /* @4125744 cast */
    /* @4125748 constant */
    /* @4125752 cast */
    /* @4125756 call */
    GM_SITE(vm, 294, 4125756);
    /* @4125764 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4125768: ;
    /* @4125768 load */
    /* @4125776 constant */
    /* @4125780 add */
    /* @4125784 store */
    v31 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v31);
    /* @4125792 load */
    /* @4125800 constant */
    /* @4125804 cmp */
    /* @4125808 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4125840;
    /* @4125812 constant */
    /* @4125816 load */
    /* @4125824 cast */
    /* @4125828 constant */
    /* @4125832 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit2")), "alarm", VAL(6), VAL(1));
    L_4125840: ;
    /* @4125840 constant */
    /* @4125844 cast */
    /* @4125848 load */
    /* @4125856 load */
    /* @4125864 constant */
    /* @4125868 sub */
    /* @4125872 call */
    GM_SITE(vm, 294, 4125872);
    /* @4125880 store */
    v32 = GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(20)), GM_READ(vm, -1, "y"), VAL(22));
    GM_WRITE(vm, -1, "hit2alt", v32);
    /* @4125888 load */
    /* @4125896 constant */
    /* @4125900 cmp */
    /* @4125904 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit2alt") != VAL(-4)))) goto L_4126320;
    /* @4125908 constant */
    /* @4125912 load */
    /* @4125920 cast */
    /* @4125924 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2alt")), "flashing", VAL(1));
    /* @4125932 constant */
    /* @4125936 cast */
    /* @4125940 load */
    /* @4125948 load */
    /* @4125956 load */
    /* @4125964 load */
    /* @4125972 call */
    GM_SITE(vm, 294, 4125972);
    /* @4125980 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4125984 load */
    /* @4125992 cast */
    /* @4125996 dup */
    /* @4126000 load */
    /* @4126008 load */
    /* @4126016 sub */
    /* @4126020 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2alt")), "hptwo", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit2alt")), "hptwo") - GM_READ(vm, -5, "spikegundamage")));
    /* @4126028 constant */
    /* @4126032 cast */
    /* @4126036 load */
    /* @4126044 load */
    /* @4126052 call */
    GM_SITE(vm, 294, 4126052);
    /* @4126060 store */
    v33 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v33);
    /* @4126068 load */
    /* @4126076 load */
    /* @4126084 cast */
    /* @4126088 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4126096 constant */
    /* @4126100 constant */
    /* @4126104 constant */
    /* @4126108 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4126116 constant */
    /* @4126120 load */
    /* @4126128 cast */
    /* @4126132 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2alt")), "stunned", VAL(1));
    /* @4126140 constant */
    /* @4126144 load */
    /* @4126152 cast */
    /* @4126156 constant */
    /* @4126160 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit2alt")), "alarm", VAL(4), VAL(10));
    /* @4126168 load */
    /* @4126176 constant */
    /* @4126180 cmp */
    /* @4126184 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4126192;
    /* @4126188 b */
    goto L_4126248;
    L_4126192: ;
    /* @4126192 load */
    /* @4126200 constant */
    /* @4126204 cmp */
    /* @4126208 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4126248;
    /* @4126212 constant */
    /* @4126216 cast */
    /* @4126220 constant */
    /* @4126224 cast */
    /* @4126228 constant */
    /* @4126232 cast */
    /* @4126236 call */
    GM_SITE(vm, 294, 4126236);
    /* @4126244 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4126248: ;
    /* @4126248 load */
    /* @4126256 constant */
    /* @4126260 add */
    /* @4126264 store */
    v34 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v34);
    /* @4126272 load */
    /* @4126280 constant */
    /* @4126284 cmp */
    /* @4126288 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4126320;
    /* @4126292 constant */
    /* @4126296 load */
    /* @4126304 cast */
    /* @4126308 constant */
    /* @4126312 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit2alt")), "alarm", VAL(6), VAL(1));
    L_4126320: ;
    /* @4126320 constant */
    /* @4126324 cast */
    /* @4126328 load */
    /* @4126336 load */
    /* @4126344 constant */
    /* @4126348 add */
    /* @4126352 call */
    GM_SITE(vm, 294, 4126352);
    v35 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @4126360 store */
    v36 = GM_CALL(vm, "instance_place", 3, v35, GM_READ(vm, -1, "y"), VAL(25));
    GM_WRITE(vm, -1, "hittrex", v36);
    /* @4126368 load */
    /* @4126376 constant */
    /* @4126380 cmp */
    /* @4126384 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hittrex") != VAL(-4)))) goto L_4126748;
    /* @4126388 constant */
    /* @4126392 load */
    /* @4126400 cast */
    /* @4126404 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "flashing", VAL(1));
    /* @4126412 constant */
    /* @4126416 cast */
    /* @4126420 load */
    /* @4126428 load */
    /* @4126436 load */
    /* @4126444 load */
    /* @4126452 call */
    GM_SITE(vm, 294, 4126452);
    /* @4126460 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4126464 load */
    /* @4126472 cast */
    /* @4126476 dup */
    /* @4126480 load */
    /* @4126488 load */
    /* @4126496 sub */
    /* @4126500 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex") - GM_READ(vm, -5, "spikegundamage")));
    /* @4126508 constant */
    /* @4126512 cast */
    /* @4126516 load */
    /* @4126524 load */
    /* @4126532 call */
    GM_SITE(vm, 294, 4126532);
    /* @4126540 store */
    v37 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v37);
    /* @4126548 load */
    /* @4126556 load */
    /* @4126564 cast */
    /* @4126568 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4126576 constant */
    /* @4126580 constant */
    /* @4126584 constant */
    /* @4126588 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4126596 load */
    /* @4126604 constant */
    /* @4126608 cmp */
    /* @4126612 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4126620;
    /* @4126616 b */
    goto L_4126676;
    L_4126620: ;
    /* @4126620 load */
    /* @4126628 constant */
    /* @4126632 cmp */
    /* @4126636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4126676;
    /* @4126640 constant */
    /* @4126644 cast */
    /* @4126648 constant */
    /* @4126652 cast */
    /* @4126656 constant */
    /* @4126660 cast */
    /* @4126664 call */
    GM_SITE(vm, 294, 4126664);
    /* @4126672 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4126676: ;
    /* @4126676 load */
    /* @4126684 constant */
    /* @4126688 add */
    /* @4126692 store */
    v38 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v38);
    /* @4126700 load */
    /* @4126708 constant */
    /* @4126712 cmp */
    /* @4126716 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4126748;
    /* @4126720 constant */
    /* @4126724 load */
    /* @4126732 cast */
    /* @4126736 constant */
    /* @4126740 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "alarm", VAL(6), VAL(1));
    L_4126748: ;
    /* @4126748 constant */
    /* @4126752 cast */
    /* @4126756 load */
    /* @4126764 load */
    /* @4126772 constant */
    /* @4126776 sub */
    /* @4126780 call */
    GM_SITE(vm, 294, 4126780);
    /* @4126788 store */
    v39 = GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(20)), GM_READ(vm, -1, "y"), VAL(25));
    GM_WRITE(vm, -1, "hittrexalt", v39);
    /* @4126796 load */
    /* @4126804 constant */
    /* @4126808 cmp */
    /* @4126812 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hittrexalt") != VAL(-4)))) goto L_4127176;
    /* @4126816 constant */
    /* @4126820 load */
    /* @4126828 cast */
    /* @4126832 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrexalt")), "flashing", VAL(1));
    /* @4126840 constant */
    /* @4126844 cast */
    /* @4126848 load */
    /* @4126856 load */
    /* @4126864 load */
    /* @4126872 load */
    /* @4126880 call */
    GM_SITE(vm, 294, 4126880);
    /* @4126888 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4126892 load */
    /* @4126900 cast */
    /* @4126904 dup */
    /* @4126908 load */
    /* @4126916 load */
    /* @4126924 sub */
    /* @4126928 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrexalt")), "hptrex", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hittrexalt")), "hptrex") - GM_READ(vm, -5, "spikegundamage")));
    /* @4126936 constant */
    /* @4126940 cast */
    /* @4126944 load */
    /* @4126952 load */
    /* @4126960 call */
    GM_SITE(vm, 294, 4126960);
    /* @4126968 store */
    v40 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v40);
    /* @4126976 load */
    /* @4126984 load */
    /* @4126992 cast */
    /* @4126996 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4127004 constant */
    /* @4127008 constant */
    /* @4127012 constant */
    /* @4127016 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4127024 load */
    /* @4127032 constant */
    /* @4127036 cmp */
    /* @4127040 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4127048;
    /* @4127044 b */
    goto L_4127104;
    L_4127048: ;
    /* @4127048 load */
    /* @4127056 constant */
    /* @4127060 cmp */
    /* @4127064 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4127104;
    /* @4127068 constant */
    /* @4127072 cast */
    /* @4127076 constant */
    /* @4127080 cast */
    /* @4127084 constant */
    /* @4127088 cast */
    /* @4127092 call */
    GM_SITE(vm, 294, 4127092);
    /* @4127100 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4127104: ;
    /* @4127104 load */
    /* @4127112 constant */
    /* @4127116 add */
    /* @4127120 store */
    v41 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v41);
    /* @4127128 load */
    /* @4127136 constant */
    /* @4127140 cmp */
    /* @4127144 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4127176;
    /* @4127148 constant */
    /* @4127152 load */
    /* @4127160 cast */
    /* @4127164 constant */
    /* @4127168 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hittrexalt")), "alarm", VAL(6), VAL(1));
    L_4127176: ;
    /* @4127176 constant */
    /* @4127180 cast */
    /* @4127184 load */
    /* @4127192 load */
    /* @4127200 constant */
    /* @4127204 add */
    /* @4127208 call */
    GM_SITE(vm, 294, 4127208);
    v42 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @4127216 store */
    v43 = GM_CALL(vm, "instance_place", 3, v42, GM_READ(vm, -1, "y"), VAL(31));
    GM_WRITE(vm, -1, "hit4", v43);
    /* @4127224 load */
    /* @4127232 constant */
    /* @4127236 cmp */
    /* @4127240 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit4") != VAL(-4)))) goto L_4127656;
    /* @4127244 constant */
    /* @4127248 load */
    /* @4127256 cast */
    /* @4127260 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "flashing", VAL(1));
    /* @4127268 constant */
    /* @4127272 cast */
    /* @4127276 load */
    /* @4127284 load */
    /* @4127292 load */
    /* @4127300 load */
    /* @4127308 call */
    GM_SITE(vm, 294, 4127308);
    /* @4127316 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4127320 load */
    /* @4127328 cast */
    /* @4127332 dup */
    /* @4127336 load */
    /* @4127344 load */
    /* @4127352 sub */
    /* @4127356 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour") - GM_READ(vm, -5, "spikegundamage")));
    /* @4127364 constant */
    /* @4127368 cast */
    /* @4127372 load */
    /* @4127380 load */
    /* @4127388 call */
    GM_SITE(vm, 294, 4127388);
    /* @4127396 store */
    v44 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v44);
    /* @4127404 load */
    /* @4127412 load */
    /* @4127420 cast */
    /* @4127424 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4127432 constant */
    /* @4127436 constant */
    /* @4127440 constant */
    /* @4127444 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4127452 load */
    /* @4127460 constant */
    /* @4127464 cmp */
    /* @4127468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4127476;
    /* @4127472 b */
    goto L_4127532;
    L_4127476: ;
    /* @4127476 load */
    /* @4127484 constant */
    /* @4127488 cmp */
    /* @4127492 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4127532;
    /* @4127496 constant */
    /* @4127500 cast */
    /* @4127504 constant */
    /* @4127508 cast */
    /* @4127512 constant */
    /* @4127516 cast */
    /* @4127520 call */
    GM_SITE(vm, 294, 4127520);
    /* @4127528 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4127532: ;
    /* @4127532 constant */
    /* @4127536 load */
    /* @4127544 cast */
    /* @4127548 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "stunned", VAL(1));
    /* @4127556 constant */
    /* @4127560 load */
    /* @4127568 cast */
    /* @4127572 constant */
    /* @4127576 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit4")), "alarm", VAL(4), VAL(10));
    /* @4127584 load */
    /* @4127592 constant */
    /* @4127596 add */
    /* @4127600 store */
    v45 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v45);
    /* @4127608 load */
    /* @4127616 constant */
    /* @4127620 cmp */
    /* @4127624 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4127656;
    /* @4127628 constant */
    /* @4127632 load */
    /* @4127640 cast */
    /* @4127644 constant */
    /* @4127648 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit4")), "alarm", VAL(6), VAL(1));
    L_4127656: ;
    /* @4127656 constant */
    /* @4127660 cast */
    /* @4127664 load */
    /* @4127672 load */
    /* @4127680 constant */
    /* @4127684 sub */
    /* @4127688 call */
    GM_SITE(vm, 294, 4127688);
    /* @4127696 store */
    v46 = GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(20)), GM_READ(vm, -1, "y"), VAL(31));
    GM_WRITE(vm, -1, "hit4alt", v46);
    /* @4127704 load */
    /* @4127712 constant */
    /* @4127716 cmp */
    /* @4127720 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit4alt") != VAL(-4)))) goto L_4128136;
    /* @4127724 constant */
    /* @4127728 load */
    /* @4127736 cast */
    /* @4127740 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4alt")), "flashing", VAL(1));
    /* @4127748 constant */
    /* @4127752 cast */
    /* @4127756 load */
    /* @4127764 load */
    /* @4127772 load */
    /* @4127780 load */
    /* @4127788 call */
    GM_SITE(vm, 294, 4127788);
    /* @4127796 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4127800 load */
    /* @4127808 cast */
    /* @4127812 dup */
    /* @4127816 load */
    /* @4127824 load */
    /* @4127832 sub */
    /* @4127836 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4alt")), "hpfour", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit4alt")), "hpfour") - GM_READ(vm, -5, "spikegundamage")));
    /* @4127844 constant */
    /* @4127848 cast */
    /* @4127852 load */
    /* @4127860 load */
    /* @4127868 call */
    GM_SITE(vm, 294, 4127868);
    /* @4127876 store */
    v47 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v47);
    /* @4127884 load */
    /* @4127892 load */
    /* @4127900 cast */
    /* @4127904 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4127912 constant */
    /* @4127916 constant */
    /* @4127920 constant */
    /* @4127924 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4127932 load */
    /* @4127940 constant */
    /* @4127944 cmp */
    /* @4127948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4127956;
    /* @4127952 b */
    goto L_4128012;
    L_4127956: ;
    /* @4127956 load */
    /* @4127964 constant */
    /* @4127968 cmp */
    /* @4127972 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4128012;
    /* @4127976 constant */
    /* @4127980 cast */
    /* @4127984 constant */
    /* @4127988 cast */
    /* @4127992 constant */
    /* @4127996 cast */
    /* @4128000 call */
    GM_SITE(vm, 294, 4128000);
    /* @4128008 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4128012: ;
    /* @4128012 constant */
    /* @4128016 load */
    /* @4128024 cast */
    /* @4128028 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4alt")), "stunned", VAL(1));
    /* @4128036 constant */
    /* @4128040 load */
    /* @4128048 cast */
    /* @4128052 constant */
    /* @4128056 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit4alt")), "alarm", VAL(4), VAL(10));
    /* @4128064 load */
    /* @4128072 constant */
    /* @4128076 add */
    /* @4128080 store */
    v48 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v48);
    /* @4128088 load */
    /* @4128096 constant */
    /* @4128100 cmp */
    /* @4128104 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4128136;
    /* @4128108 constant */
    /* @4128112 load */
    /* @4128120 cast */
    /* @4128124 constant */
    /* @4128128 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit4alt")), "alarm", VAL(6), VAL(1));
    L_4128136: ;
    /* @4128136 constant */
    /* @4128140 cast */
    /* @4128144 load */
    /* @4128152 load */
    /* @4128160 constant */
    /* @4128164 add */
    /* @4128168 call */
    GM_SITE(vm, 294, 4128168);
    v49 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @4128176 store */
    v50 = GM_CALL(vm, "instance_place", 3, v49, GM_READ(vm, -1, "y"), VAL(32));
    GM_WRITE(vm, -1, "hit5", v50);
    /* @4128184 load */
    /* @4128192 constant */
    /* @4128196 cmp */
    /* @4128200 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit5") != VAL(-4)))) goto L_4128616;
    /* @4128204 constant */
    /* @4128208 load */
    /* @4128216 cast */
    /* @4128220 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "flashing", VAL(1));
    /* @4128228 constant */
    /* @4128232 cast */
    /* @4128236 load */
    /* @4128244 load */
    /* @4128252 load */
    /* @4128260 load */
    /* @4128268 call */
    GM_SITE(vm, 294, 4128268);
    /* @4128276 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4128280 load */
    /* @4128288 cast */
    /* @4128292 dup */
    /* @4128296 load */
    /* @4128304 load */
    /* @4128312 sub */
    /* @4128316 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime") - GM_READ(vm, -5, "spikegundamage")));
    /* @4128324 constant */
    /* @4128328 cast */
    /* @4128332 load */
    /* @4128340 load */
    /* @4128348 call */
    GM_SITE(vm, 294, 4128348);
    /* @4128356 store */
    v51 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v51);
    /* @4128364 load */
    /* @4128372 load */
    /* @4128380 cast */
    /* @4128384 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4128392 constant */
    /* @4128396 constant */
    /* @4128400 constant */
    /* @4128404 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4128412 load */
    /* @4128420 constant */
    /* @4128424 cmp */
    /* @4128428 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4128436;
    /* @4128432 b */
    goto L_4128492;
    L_4128436: ;
    /* @4128436 load */
    /* @4128444 constant */
    /* @4128448 cmp */
    /* @4128452 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4128492;
    /* @4128456 constant */
    /* @4128460 cast */
    /* @4128464 constant */
    /* @4128468 cast */
    /* @4128472 constant */
    /* @4128476 cast */
    /* @4128480 call */
    GM_SITE(vm, 294, 4128480);
    /* @4128488 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4128492: ;
    /* @4128492 constant */
    /* @4128496 load */
    /* @4128504 cast */
    /* @4128508 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "stunned", VAL(1));
    /* @4128516 constant */
    /* @4128520 load */
    /* @4128528 cast */
    /* @4128532 constant */
    /* @4128536 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit5")), "alarm", VAL(4), VAL(10));
    /* @4128544 load */
    /* @4128552 constant */
    /* @4128556 add */
    /* @4128560 store */
    v52 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v52);
    /* @4128568 load */
    /* @4128576 constant */
    /* @4128580 cmp */
    /* @4128584 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4128616;
    /* @4128588 constant */
    /* @4128592 load */
    /* @4128600 cast */
    /* @4128604 constant */
    /* @4128608 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit5")), "alarm", VAL(6), VAL(1));
    L_4128616: ;
    /* @4128616 constant */
    /* @4128620 cast */
    /* @4128624 load */
    /* @4128632 load */
    /* @4128640 constant */
    /* @4128644 sub */
    /* @4128648 call */
    GM_SITE(vm, 294, 4128648);
    /* @4128656 store */
    v53 = GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(20)), GM_READ(vm, -1, "y"), VAL(32));
    GM_WRITE(vm, -1, "hit5alt", v53);
    /* @4128664 load */
    /* @4128672 constant */
    /* @4128676 cmp */
    /* @4128680 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit5alt") != VAL(-4)))) goto L_4129096;
    /* @4128684 constant */
    /* @4128688 load */
    /* @4128696 cast */
    /* @4128700 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5alt")), "flashing", VAL(1));
    /* @4128708 constant */
    /* @4128712 cast */
    /* @4128716 load */
    /* @4128724 load */
    /* @4128732 load */
    /* @4128740 load */
    /* @4128748 call */
    GM_SITE(vm, 294, 4128748);
    /* @4128756 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4128760 load */
    /* @4128768 cast */
    /* @4128772 dup */
    /* @4128776 load */
    /* @4128784 load */
    /* @4128792 sub */
    /* @4128796 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5alt")), "hpslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit5alt")), "hpslime") - GM_READ(vm, -5, "spikegundamage")));
    /* @4128804 constant */
    /* @4128808 cast */
    /* @4128812 load */
    /* @4128820 load */
    /* @4128828 call */
    GM_SITE(vm, 294, 4128828);
    /* @4128836 store */
    v54 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v54);
    /* @4128844 load */
    /* @4128852 load */
    /* @4128860 cast */
    /* @4128864 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4128872 constant */
    /* @4128876 constant */
    /* @4128880 constant */
    /* @4128884 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4128892 load */
    /* @4128900 constant */
    /* @4128904 cmp */
    /* @4128908 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4128916;
    /* @4128912 b */
    goto L_4128972;
    L_4128916: ;
    /* @4128916 load */
    /* @4128924 constant */
    /* @4128928 cmp */
    /* @4128932 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4128972;
    /* @4128936 constant */
    /* @4128940 cast */
    /* @4128944 constant */
    /* @4128948 cast */
    /* @4128952 constant */
    /* @4128956 cast */
    /* @4128960 call */
    GM_SITE(vm, 294, 4128960);
    /* @4128968 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4128972: ;
    /* @4128972 constant */
    /* @4128976 load */
    /* @4128984 cast */
    /* @4128988 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5alt")), "stunned", VAL(1));
    /* @4128996 constant */
    /* @4129000 load */
    /* @4129008 cast */
    /* @4129012 constant */
    /* @4129016 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit5alt")), "alarm", VAL(4), VAL(10));
    /* @4129024 load */
    /* @4129032 constant */
    /* @4129036 add */
    /* @4129040 store */
    v55 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v55);
    /* @4129048 load */
    /* @4129056 constant */
    /* @4129060 cmp */
    /* @4129064 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4129096;
    /* @4129068 constant */
    /* @4129072 load */
    /* @4129080 cast */
    /* @4129084 constant */
    /* @4129088 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit5alt")), "alarm", VAL(6), VAL(1));
    L_4129096: ;
    /* @4129096 constant */
    /* @4129100 cast */
    /* @4129104 load */
    /* @4129112 load */
    /* @4129120 constant */
    /* @4129124 add */
    /* @4129128 call */
    GM_SITE(vm, 294, 4129128);
    v56 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @4129136 store */
    v57 = GM_CALL(vm, "instance_place", 3, v56, GM_READ(vm, -1, "y"), VAL(24));
    GM_WRITE(vm, -1, "hit7", v57);
    /* @4129144 load */
    /* @4129152 constant */
    /* @4129156 cmp */
    /* @4129160 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit7") != VAL(-4)))) goto L_4129576;
    /* @4129164 constant */
    /* @4129168 load */
    /* @4129176 cast */
    /* @4129180 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "flashing", VAL(1));
    /* @4129188 constant */
    /* @4129192 cast */
    /* @4129196 load */
    /* @4129204 load */
    /* @4129212 load */
    /* @4129220 load */
    /* @4129228 call */
    GM_SITE(vm, 294, 4129228);
    /* @4129236 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4129240 load */
    /* @4129248 cast */
    /* @4129252 dup */
    /* @4129256 load */
    /* @4129264 load */
    /* @4129272 sub */
    /* @4129276 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "hpghost", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit7")), "hpghost") - GM_READ(vm, -5, "spikegundamage")));
    /* @4129284 constant */
    /* @4129288 cast */
    /* @4129292 load */
    /* @4129300 load */
    /* @4129308 call */
    GM_SITE(vm, 294, 4129308);
    /* @4129316 store */
    v58 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v58);
    /* @4129324 load */
    /* @4129332 load */
    /* @4129340 cast */
    /* @4129344 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4129352 constant */
    /* @4129356 constant */
    /* @4129360 constant */
    /* @4129364 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4129372 load */
    /* @4129380 constant */
    /* @4129384 cmp */
    /* @4129388 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4129396;
    /* @4129392 b */
    goto L_4129452;
    L_4129396: ;
    /* @4129396 load */
    /* @4129404 constant */
    /* @4129408 cmp */
    /* @4129412 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4129452;
    /* @4129416 constant */
    /* @4129420 cast */
    /* @4129424 constant */
    /* @4129428 cast */
    /* @4129432 constant */
    /* @4129436 cast */
    /* @4129440 call */
    GM_SITE(vm, 294, 4129440);
    /* @4129448 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4129452: ;
    /* @4129452 constant */
    /* @4129456 load */
    /* @4129464 cast */
    /* @4129468 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "swordstunned", VAL(1));
    /* @4129476 constant */
    /* @4129480 load */
    /* @4129488 cast */
    /* @4129492 constant */
    /* @4129496 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit7")), "alarm", VAL(5), VAL(30));
    /* @4129504 load */
    /* @4129512 constant */
    /* @4129516 add */
    /* @4129520 store */
    v59 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v59);
    /* @4129528 load */
    /* @4129536 constant */
    /* @4129540 cmp */
    /* @4129544 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4129576;
    /* @4129548 constant */
    /* @4129552 load */
    /* @4129560 cast */
    /* @4129564 constant */
    /* @4129568 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit7")), "alarm", VAL(6), VAL(1));
    L_4129576: ;
    /* @4129576 constant */
    /* @4129580 cast */
    /* @4129584 load */
    /* @4129592 load */
    /* @4129600 constant */
    /* @4129604 sub */
    /* @4129608 call */
    GM_SITE(vm, 294, 4129608);
    /* @4129616 store */
    v60 = GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(20)), GM_READ(vm, -1, "y"), VAL(24));
    GM_WRITE(vm, -1, "hit7alt", v60);
    /* @4129624 load */
    /* @4129632 constant */
    /* @4129636 cmp */
    /* @4129640 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit7alt") != VAL(-4)))) goto L_4130056;
    /* @4129644 constant */
    /* @4129648 load */
    /* @4129656 cast */
    /* @4129660 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7alt")), "flashing", VAL(1));
    /* @4129668 constant */
    /* @4129672 cast */
    /* @4129676 load */
    /* @4129684 load */
    /* @4129692 load */
    /* @4129700 load */
    /* @4129708 call */
    GM_SITE(vm, 294, 4129708);
    /* @4129716 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4129720 load */
    /* @4129728 cast */
    /* @4129732 dup */
    /* @4129736 load */
    /* @4129744 load */
    /* @4129752 sub */
    /* @4129756 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7alt")), "hpghost", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit7alt")), "hpghost") - GM_READ(vm, -5, "spikegundamage")));
    /* @4129764 constant */
    /* @4129768 cast */
    /* @4129772 load */
    /* @4129780 load */
    /* @4129788 call */
    GM_SITE(vm, 294, 4129788);
    /* @4129796 store */
    v61 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v61);
    /* @4129804 load */
    /* @4129812 load */
    /* @4129820 cast */
    /* @4129824 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4129832 constant */
    /* @4129836 constant */
    /* @4129840 constant */
    /* @4129844 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4129852 load */
    /* @4129860 constant */
    /* @4129864 cmp */
    /* @4129868 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4129876;
    /* @4129872 b */
    goto L_4129932;
    L_4129876: ;
    /* @4129876 load */
    /* @4129884 constant */
    /* @4129888 cmp */
    /* @4129892 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4129932;
    /* @4129896 constant */
    /* @4129900 cast */
    /* @4129904 constant */
    /* @4129908 cast */
    /* @4129912 constant */
    /* @4129916 cast */
    /* @4129920 call */
    GM_SITE(vm, 294, 4129920);
    /* @4129928 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4129932: ;
    /* @4129932 constant */
    /* @4129936 load */
    /* @4129944 cast */
    /* @4129948 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7alt")), "swordstunned", VAL(1));
    /* @4129956 constant */
    /* @4129960 load */
    /* @4129968 cast */
    /* @4129972 constant */
    /* @4129976 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit7alt")), "alarm", VAL(5), VAL(30));
    /* @4129984 load */
    /* @4129992 constant */
    /* @4129996 add */
    /* @4130000 store */
    v62 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v62);
    /* @4130008 load */
    /* @4130016 constant */
    /* @4130020 cmp */
    /* @4130024 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4130056;
    /* @4130028 constant */
    /* @4130032 load */
    /* @4130040 cast */
    /* @4130044 constant */
    /* @4130048 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit7alt")), "alarm", VAL(6), VAL(1));
    L_4130056: ;
    /* @4130056 constant */
    /* @4130060 cast */
    /* @4130064 load */
    /* @4130072 load */
    /* @4130080 constant */
    /* @4130084 add */
    /* @4130088 call */
    GM_SITE(vm, 294, 4130088);
    v63 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @4130096 store */
    v64 = GM_CALL(vm, "instance_place", 3, v63, GM_READ(vm, -1, "y"), VAL(16));
    GM_WRITE(vm, -1, "hit8", v64);
    /* @4130104 load */
    /* @4130112 constant */
    /* @4130116 cmp */
    /* @4130120 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit8") != VAL(-4)))) goto L_4130536;
    /* @4130124 constant */
    /* @4130128 load */
    /* @4130136 cast */
    /* @4130140 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "flashing", VAL(1));
    /* @4130148 constant */
    /* @4130152 cast */
    /* @4130156 load */
    /* @4130164 load */
    /* @4130172 load */
    /* @4130180 load */
    /* @4130188 call */
    GM_SITE(vm, 294, 4130188);
    /* @4130196 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4130200 load */
    /* @4130208 cast */
    /* @4130212 dup */
    /* @4130216 load */
    /* @4130224 load */
    /* @4130232 sub */
    /* @4130236 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1") - GM_READ(vm, -5, "spikegundamage")));
    /* @4130244 constant */
    /* @4130248 cast */
    /* @4130252 load */
    /* @4130260 load */
    /* @4130268 call */
    GM_SITE(vm, 294, 4130268);
    /* @4130276 store */
    v65 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v65);
    /* @4130284 load */
    /* @4130292 load */
    /* @4130300 cast */
    /* @4130304 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4130312 constant */
    /* @4130316 constant */
    /* @4130320 constant */
    /* @4130324 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4130332 load */
    /* @4130340 constant */
    /* @4130344 cmp */
    /* @4130348 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4130356;
    /* @4130352 b */
    goto L_4130412;
    L_4130356: ;
    /* @4130356 load */
    /* @4130364 constant */
    /* @4130368 cmp */
    /* @4130372 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4130412;
    /* @4130376 constant */
    /* @4130380 cast */
    /* @4130384 constant */
    /* @4130388 cast */
    /* @4130392 constant */
    /* @4130396 cast */
    /* @4130400 call */
    GM_SITE(vm, 294, 4130400);
    /* @4130408 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4130412: ;
    /* @4130412 constant */
    /* @4130416 load */
    /* @4130424 cast */
    /* @4130428 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "stunned", VAL(1));
    /* @4130436 constant */
    /* @4130440 load */
    /* @4130448 cast */
    /* @4130452 constant */
    /* @4130456 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit8")), "alarm", VAL(4), VAL(10));
    /* @4130464 load */
    /* @4130472 constant */
    /* @4130476 add */
    /* @4130480 store */
    v66 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v66);
    /* @4130488 load */
    /* @4130496 constant */
    /* @4130500 cmp */
    /* @4130504 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4130536;
    /* @4130508 constant */
    /* @4130512 load */
    /* @4130520 cast */
    /* @4130524 constant */
    /* @4130528 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit8")), "alarm", VAL(6), VAL(1));
    L_4130536: ;
    /* @4130536 constant */
    /* @4130540 cast */
    /* @4130544 load */
    /* @4130552 load */
    /* @4130560 constant */
    /* @4130564 sub */
    /* @4130568 call */
    GM_SITE(vm, 294, 4130568);
    /* @4130576 store */
    v67 = GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(20)), GM_READ(vm, -1, "y"), VAL(16));
    GM_WRITE(vm, -1, "hit8alt", v67);
    /* @4130584 load */
    /* @4130592 constant */
    /* @4130596 cmp */
    /* @4130600 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit8alt") != VAL(-4)))) goto L_4131016;
    /* @4130604 constant */
    /* @4130608 load */
    /* @4130616 cast */
    /* @4130620 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8alt")), "flashing", VAL(1));
    /* @4130628 constant */
    /* @4130632 cast */
    /* @4130636 load */
    /* @4130644 load */
    /* @4130652 load */
    /* @4130660 load */
    /* @4130668 call */
    GM_SITE(vm, 294, 4130668);
    /* @4130676 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4130680 load */
    /* @4130688 cast */
    /* @4130692 dup */
    /* @4130696 load */
    /* @4130704 load */
    /* @4130712 sub */
    /* @4130716 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8alt")), "hpshooter1", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit8alt")), "hpshooter1") - GM_READ(vm, -5, "spikegundamage")));
    /* @4130724 constant */
    /* @4130728 cast */
    /* @4130732 load */
    /* @4130740 load */
    /* @4130748 call */
    GM_SITE(vm, 294, 4130748);
    /* @4130756 store */
    v68 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v68);
    /* @4130764 load */
    /* @4130772 load */
    /* @4130780 cast */
    /* @4130784 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4130792 constant */
    /* @4130796 constant */
    /* @4130800 constant */
    /* @4130804 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4130812 load */
    /* @4130820 constant */
    /* @4130824 cmp */
    /* @4130828 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4130836;
    /* @4130832 b */
    goto L_4130892;
    L_4130836: ;
    /* @4130836 load */
    /* @4130844 constant */
    /* @4130848 cmp */
    /* @4130852 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4130892;
    /* @4130856 constant */
    /* @4130860 cast */
    /* @4130864 constant */
    /* @4130868 cast */
    /* @4130872 constant */
    /* @4130876 cast */
    /* @4130880 call */
    GM_SITE(vm, 294, 4130880);
    /* @4130888 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4130892: ;
    /* @4130892 constant */
    /* @4130896 load */
    /* @4130904 cast */
    /* @4130908 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8alt")), "stunned", VAL(1));
    /* @4130916 constant */
    /* @4130920 load */
    /* @4130928 cast */
    /* @4130932 constant */
    /* @4130936 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit8alt")), "alarm", VAL(4), VAL(10));
    /* @4130944 load */
    /* @4130952 constant */
    /* @4130956 add */
    /* @4130960 store */
    v69 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v69);
    /* @4130968 load */
    /* @4130976 constant */
    /* @4130980 cmp */
    /* @4130984 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4131016;
    /* @4130988 constant */
    /* @4130992 load */
    /* @4131000 cast */
    /* @4131004 constant */
    /* @4131008 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit8alt")), "alarm", VAL(6), VAL(1));
    L_4131016: ;
    /* @4131016 constant */
    /* @4131020 cast */
    /* @4131024 load */
    /* @4131032 load */
    /* @4131040 constant */
    /* @4131044 add */
    /* @4131048 call */
    GM_SITE(vm, 294, 4131048);
    v70 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @4131056 store */
    v71 = GM_CALL(vm, "instance_place", 3, v70, GM_READ(vm, -1, "y"), VAL(20));
    GM_WRITE(vm, -1, "hit9", v71);
    /* @4131064 load */
    /* @4131072 constant */
    /* @4131076 cmp */
    /* @4131080 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit9") != VAL(-4)))) goto L_4131496;
    /* @4131084 constant */
    /* @4131088 load */
    /* @4131096 cast */
    /* @4131100 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "flashing", VAL(1));
    /* @4131108 constant */
    /* @4131112 cast */
    /* @4131116 load */
    /* @4131124 load */
    /* @4131132 load */
    /* @4131140 load */
    /* @4131148 call */
    GM_SITE(vm, 294, 4131148);
    /* @4131156 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4131160 load */
    /* @4131168 cast */
    /* @4131172 dup */
    /* @4131176 load */
    /* @4131184 load */
    /* @4131192 sub */
    /* @4131196 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2") - GM_READ(vm, -5, "spikegundamage")));
    /* @4131204 constant */
    /* @4131208 cast */
    /* @4131212 load */
    /* @4131220 load */
    /* @4131228 call */
    GM_SITE(vm, 294, 4131228);
    /* @4131236 store */
    v72 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v72);
    /* @4131244 load */
    /* @4131252 load */
    /* @4131260 cast */
    /* @4131264 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4131272 constant */
    /* @4131276 constant */
    /* @4131280 constant */
    /* @4131284 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4131292 load */
    /* @4131300 constant */
    /* @4131304 cmp */
    /* @4131308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4131316;
    /* @4131312 b */
    goto L_4131372;
    L_4131316: ;
    /* @4131316 load */
    /* @4131324 constant */
    /* @4131328 cmp */
    /* @4131332 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4131372;
    /* @4131336 constant */
    /* @4131340 cast */
    /* @4131344 constant */
    /* @4131348 cast */
    /* @4131352 constant */
    /* @4131356 cast */
    /* @4131360 call */
    GM_SITE(vm, 294, 4131360);
    /* @4131368 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4131372: ;
    /* @4131372 constant */
    /* @4131376 load */
    /* @4131384 cast */
    /* @4131388 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "stunned", VAL(1));
    /* @4131396 constant */
    /* @4131400 load */
    /* @4131408 cast */
    /* @4131412 constant */
    /* @4131416 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit9")), "alarm", VAL(4), VAL(10));
    /* @4131424 load */
    /* @4131432 constant */
    /* @4131436 add */
    /* @4131440 store */
    v73 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v73);
    /* @4131448 load */
    /* @4131456 constant */
    /* @4131460 cmp */
    /* @4131464 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4131496;
    /* @4131468 constant */
    /* @4131472 load */
    /* @4131480 cast */
    /* @4131484 constant */
    /* @4131488 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit9")), "alarm", VAL(7), VAL(1));
    L_4131496: ;
    /* @4131496 constant */
    /* @4131500 cast */
    /* @4131504 load */
    /* @4131512 load */
    /* @4131520 constant */
    /* @4131524 sub */
    /* @4131528 call */
    GM_SITE(vm, 294, 4131528);
    /* @4131536 store */
    v74 = GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(20)), GM_READ(vm, -1, "y"), VAL(20));
    GM_WRITE(vm, -1, "hit9alt", v74);
    /* @4131544 load */
    /* @4131552 constant */
    /* @4131556 cmp */
    /* @4131560 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit9alt") != VAL(-4)))) goto L_4131976;
    /* @4131564 constant */
    /* @4131568 load */
    /* @4131576 cast */
    /* @4131580 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9alt")), "flashing", VAL(1));
    /* @4131588 constant */
    /* @4131592 cast */
    /* @4131596 load */
    /* @4131604 load */
    /* @4131612 load */
    /* @4131620 load */
    /* @4131628 call */
    GM_SITE(vm, 294, 4131628);
    /* @4131636 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4131640 load */
    /* @4131648 cast */
    /* @4131652 dup */
    /* @4131656 load */
    /* @4131664 load */
    /* @4131672 sub */
    /* @4131676 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9alt")), "hpshooter2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit9alt")), "hpshooter2") - GM_READ(vm, -5, "spikegundamage")));
    /* @4131684 constant */
    /* @4131688 cast */
    /* @4131692 load */
    /* @4131700 load */
    /* @4131708 call */
    GM_SITE(vm, 294, 4131708);
    /* @4131716 store */
    v75 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v75);
    /* @4131724 load */
    /* @4131732 load */
    /* @4131740 cast */
    /* @4131744 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4131752 constant */
    /* @4131756 constant */
    /* @4131760 constant */
    /* @4131764 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4131772 load */
    /* @4131780 constant */
    /* @4131784 cmp */
    /* @4131788 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4131796;
    /* @4131792 b */
    goto L_4131852;
    L_4131796: ;
    /* @4131796 load */
    /* @4131804 constant */
    /* @4131808 cmp */
    /* @4131812 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4131852;
    /* @4131816 constant */
    /* @4131820 cast */
    /* @4131824 constant */
    /* @4131828 cast */
    /* @4131832 constant */
    /* @4131836 cast */
    /* @4131840 call */
    GM_SITE(vm, 294, 4131840);
    /* @4131848 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4131852: ;
    /* @4131852 constant */
    /* @4131856 load */
    /* @4131864 cast */
    /* @4131868 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9alt")), "stunned", VAL(1));
    /* @4131876 constant */
    /* @4131880 load */
    /* @4131888 cast */
    /* @4131892 constant */
    /* @4131896 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit9alt")), "alarm", VAL(4), VAL(10));
    /* @4131904 load */
    /* @4131912 constant */
    /* @4131916 add */
    /* @4131920 store */
    v76 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v76);
    /* @4131928 load */
    /* @4131936 constant */
    /* @4131940 cmp */
    /* @4131944 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4131976;
    /* @4131948 constant */
    /* @4131952 load */
    /* @4131960 cast */
    /* @4131964 constant */
    /* @4131968 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit9alt")), "alarm", VAL(7), VAL(1));
    L_4131976: ;
    /* @4131976 constant */
    /* @4131980 cast */
    /* @4131984 load */
    /* @4131992 load */
    /* @4132000 constant */
    /* @4132004 add */
    /* @4132008 call */
    GM_SITE(vm, 294, 4132008);
    v77 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @4132016 store */
    v78 = GM_CALL(vm, "instance_place", 3, v77, GM_READ(vm, -1, "y"), VAL(33));
    GM_WRITE(vm, -1, "hit10", v78);
    /* @4132024 load */
    /* @4132032 constant */
    /* @4132036 cmp */
    /* @4132040 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit10") != VAL(-4)))) goto L_4132456;
    /* @4132044 constant */
    /* @4132048 load */
    /* @4132056 cast */
    /* @4132060 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "flashing", VAL(1));
    /* @4132068 constant */
    /* @4132072 cast */
    /* @4132076 load */
    /* @4132084 load */
    /* @4132092 load */
    /* @4132100 load */
    /* @4132108 call */
    GM_SITE(vm, 294, 4132108);
    /* @4132116 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4132120 load */
    /* @4132128 cast */
    /* @4132132 dup */
    /* @4132136 load */
    /* @4132144 load */
    /* @4132152 sub */
    /* @4132156 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime") - GM_READ(vm, -5, "spikegundamage")));
    /* @4132164 constant */
    /* @4132168 cast */
    /* @4132172 load */
    /* @4132180 load */
    /* @4132188 call */
    GM_SITE(vm, 294, 4132188);
    /* @4132196 store */
    v79 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v79);
    /* @4132204 load */
    /* @4132212 load */
    /* @4132220 cast */
    /* @4132224 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4132232 constant */
    /* @4132236 constant */
    /* @4132240 constant */
    /* @4132244 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4132252 load */
    /* @4132260 constant */
    /* @4132264 cmp */
    /* @4132268 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4132276;
    /* @4132272 b */
    goto L_4132332;
    L_4132276: ;
    /* @4132276 load */
    /* @4132284 constant */
    /* @4132288 cmp */
    /* @4132292 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4132332;
    /* @4132296 constant */
    /* @4132300 cast */
    /* @4132304 constant */
    /* @4132308 cast */
    /* @4132312 constant */
    /* @4132316 cast */
    /* @4132320 call */
    GM_SITE(vm, 294, 4132320);
    /* @4132328 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4132332: ;
    /* @4132332 constant */
    /* @4132336 load */
    /* @4132344 cast */
    /* @4132348 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "stunned", VAL(1));
    /* @4132356 constant */
    /* @4132360 load */
    /* @4132368 cast */
    /* @4132372 constant */
    /* @4132376 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit10")), "alarm", VAL(4), VAL(10));
    /* @4132384 load */
    /* @4132392 constant */
    /* @4132396 add */
    /* @4132400 store */
    v80 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v80);
    /* @4132408 load */
    /* @4132416 constant */
    /* @4132420 cmp */
    /* @4132424 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4132456;
    /* @4132428 constant */
    /* @4132432 load */
    /* @4132440 cast */
    /* @4132444 constant */
    /* @4132448 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit10")), "alarm", VAL(6), VAL(1));
    L_4132456: ;
    /* @4132456 constant */
    /* @4132460 cast */
    /* @4132464 load */
    /* @4132472 load */
    /* @4132480 constant */
    /* @4132484 sub */
    /* @4132488 call */
    GM_SITE(vm, 294, 4132488);
    /* @4132496 store */
    v81 = GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(20)), GM_READ(vm, -1, "y"), VAL(33));
    GM_WRITE(vm, -1, "hit10alt", v81);
    /* @4132504 load */
    /* @4132512 constant */
    /* @4132516 cmp */
    /* @4132520 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit10alt") != VAL(-4)))) goto L_4132936;
    /* @4132524 constant */
    /* @4132528 load */
    /* @4132536 cast */
    /* @4132540 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10alt")), "flashing", VAL(1));
    /* @4132548 constant */
    /* @4132552 cast */
    /* @4132556 load */
    /* @4132564 load */
    /* @4132572 load */
    /* @4132580 load */
    /* @4132588 call */
    GM_SITE(vm, 294, 4132588);
    /* @4132596 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4132600 load */
    /* @4132608 cast */
    /* @4132612 dup */
    /* @4132616 load */
    /* @4132624 load */
    /* @4132632 sub */
    /* @4132636 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10alt")), "hpfireslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit10alt")), "hpfireslime") - GM_READ(vm, -5, "spikegundamage")));
    /* @4132644 constant */
    /* @4132648 cast */
    /* @4132652 load */
    /* @4132660 load */
    /* @4132668 call */
    GM_SITE(vm, 294, 4132668);
    /* @4132676 store */
    v82 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v82);
    /* @4132684 load */
    /* @4132692 load */
    /* @4132700 cast */
    /* @4132704 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4132712 constant */
    /* @4132716 constant */
    /* @4132720 constant */
    /* @4132724 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4132732 load */
    /* @4132740 constant */
    /* @4132744 cmp */
    /* @4132748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4132756;
    /* @4132752 b */
    goto L_4132812;
    L_4132756: ;
    /* @4132756 load */
    /* @4132764 constant */
    /* @4132768 cmp */
    /* @4132772 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4132812;
    /* @4132776 constant */
    /* @4132780 cast */
    /* @4132784 constant */
    /* @4132788 cast */
    /* @4132792 constant */
    /* @4132796 cast */
    /* @4132800 call */
    GM_SITE(vm, 294, 4132800);
    /* @4132808 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4132812: ;
    /* @4132812 constant */
    /* @4132816 load */
    /* @4132824 cast */
    /* @4132828 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10alt")), "stunned", VAL(1));
    /* @4132836 constant */
    /* @4132840 load */
    /* @4132848 cast */
    /* @4132852 constant */
    /* @4132856 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit10alt")), "alarm", VAL(4), VAL(10));
    /* @4132864 load */
    /* @4132872 constant */
    /* @4132876 add */
    /* @4132880 store */
    v83 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v83);
    /* @4132888 load */
    /* @4132896 constant */
    /* @4132900 cmp */
    /* @4132904 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4132936;
    /* @4132908 constant */
    /* @4132912 load */
    /* @4132920 cast */
    /* @4132924 constant */
    /* @4132928 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit10alt")), "alarm", VAL(6), VAL(1));
    L_4132936: ;
    /* @4132936 constant */
    /* @4132940 cast */
    /* @4132944 load */
    /* @4132952 load */
    /* @4132960 constant */
    /* @4132964 add */
    /* @4132968 call */
    GM_SITE(vm, 294, 4132968);
    v84 = GM_ADD(GM_READ(vm, -1, "x"), VAL(30));
    /* @4132976 store */
    v85 = GM_CALL(vm, "instance_place", 3, v84, GM_READ(vm, -1, "y"), VAL(21));
    GM_WRITE(vm, -1, "hit11", v85);
    /* @4132984 load */
    /* @4132992 constant */
    /* @4132996 cmp */
    /* @4133000 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit11") != VAL(-4)))) goto L_4133416;
    /* @4133004 constant */
    /* @4133008 load */
    /* @4133016 cast */
    /* @4133020 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "flashing", VAL(1));
    /* @4133028 constant */
    /* @4133032 cast */
    /* @4133036 load */
    /* @4133044 load */
    /* @4133052 load */
    /* @4133060 load */
    /* @4133068 call */
    GM_SITE(vm, 294, 4133068);
    /* @4133076 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4133080 load */
    /* @4133088 cast */
    /* @4133092 dup */
    /* @4133096 load */
    /* @4133104 load */
    /* @4133112 sub */
    /* @4133116 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit") - GM_READ(vm, -5, "spikegundamage")));
    /* @4133124 constant */
    /* @4133128 cast */
    /* @4133132 load */
    /* @4133140 load */
    /* @4133148 call */
    GM_SITE(vm, 294, 4133148);
    /* @4133156 store */
    v86 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v86);
    /* @4133164 load */
    /* @4133172 load */
    /* @4133180 cast */
    /* @4133184 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4133192 constant */
    /* @4133196 constant */
    /* @4133200 constant */
    /* @4133204 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4133212 load */
    /* @4133220 constant */
    /* @4133224 cmp */
    /* @4133228 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4133236;
    /* @4133232 b */
    goto L_4133292;
    L_4133236: ;
    /* @4133236 load */
    /* @4133244 constant */
    /* @4133248 cmp */
    /* @4133252 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4133292;
    /* @4133256 constant */
    /* @4133260 cast */
    /* @4133264 constant */
    /* @4133268 cast */
    /* @4133272 constant */
    /* @4133276 cast */
    /* @4133280 call */
    GM_SITE(vm, 294, 4133280);
    /* @4133288 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4133292: ;
    /* @4133292 constant */
    /* @4133296 load */
    /* @4133304 cast */
    /* @4133308 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "stunned", VAL(1));
    /* @4133316 constant */
    /* @4133320 load */
    /* @4133328 cast */
    /* @4133332 constant */
    /* @4133336 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit11")), "alarm", VAL(4), VAL(10));
    /* @4133344 load */
    /* @4133352 constant */
    /* @4133356 add */
    /* @4133360 store */
    v87 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v87);
    /* @4133368 load */
    /* @4133376 constant */
    /* @4133380 cmp */
    /* @4133384 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4133416;
    /* @4133388 constant */
    /* @4133392 load */
    /* @4133400 cast */
    /* @4133404 constant */
    /* @4133408 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit11")), "alarm", VAL(6), VAL(1));
    L_4133416: ;
    /* @4133416 constant */
    /* @4133420 cast */
    /* @4133424 load */
    /* @4133432 load */
    /* @4133440 constant */
    /* @4133444 sub */
    /* @4133448 call */
    GM_SITE(vm, 294, 4133448);
    /* @4133456 store */
    v88 = GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(30)), GM_READ(vm, -1, "y"), VAL(21));
    GM_WRITE(vm, -1, "hit11alt", v88);
    /* @4133464 load */
    /* @4133472 constant */
    /* @4133476 cmp */
    /* @4133480 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit11alt") != VAL(-4)))) goto L_4133896;
    /* @4133484 constant */
    /* @4133488 load */
    /* @4133496 cast */
    /* @4133500 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11alt")), "flashing", VAL(1));
    /* @4133508 constant */
    /* @4133512 cast */
    /* @4133516 load */
    /* @4133524 load */
    /* @4133532 load */
    /* @4133540 load */
    /* @4133548 call */
    GM_SITE(vm, 294, 4133548);
    /* @4133556 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4133560 load */
    /* @4133568 cast */
    /* @4133572 dup */
    /* @4133576 load */
    /* @4133584 load */
    /* @4133592 sub */
    /* @4133596 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11alt")), "hphulkingbandit", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit11alt")), "hphulkingbandit") - GM_READ(vm, -5, "spikegundamage")));
    /* @4133604 constant */
    /* @4133608 cast */
    /* @4133612 load */
    /* @4133620 load */
    /* @4133628 call */
    GM_SITE(vm, 294, 4133628);
    /* @4133636 store */
    v89 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v89);
    /* @4133644 load */
    /* @4133652 load */
    /* @4133660 cast */
    /* @4133664 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4133672 constant */
    /* @4133676 constant */
    /* @4133680 constant */
    /* @4133684 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4133692 load */
    /* @4133700 constant */
    /* @4133704 cmp */
    /* @4133708 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4133716;
    /* @4133712 b */
    goto L_4133772;
    L_4133716: ;
    /* @4133716 load */
    /* @4133724 constant */
    /* @4133728 cmp */
    /* @4133732 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4133772;
    /* @4133736 constant */
    /* @4133740 cast */
    /* @4133744 constant */
    /* @4133748 cast */
    /* @4133752 constant */
    /* @4133756 cast */
    /* @4133760 call */
    GM_SITE(vm, 294, 4133760);
    /* @4133768 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4133772: ;
    /* @4133772 constant */
    /* @4133776 load */
    /* @4133784 cast */
    /* @4133788 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11alt")), "stunned", VAL(1));
    /* @4133796 constant */
    /* @4133800 load */
    /* @4133808 cast */
    /* @4133812 constant */
    /* @4133816 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit11alt")), "alarm", VAL(4), VAL(10));
    /* @4133824 load */
    /* @4133832 constant */
    /* @4133836 add */
    /* @4133840 store */
    v90 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v90);
    /* @4133848 load */
    /* @4133856 constant */
    /* @4133860 cmp */
    /* @4133864 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4133896;
    /* @4133868 constant */
    /* @4133872 load */
    /* @4133880 cast */
    /* @4133884 constant */
    /* @4133888 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit11alt")), "alarm", VAL(6), VAL(1));
    L_4133896: ;
    /* @4133896 constant */
    /* @4133900 cast */
    /* @4133904 load */
    /* @4133912 load */
    /* @4133920 constant */
    /* @4133924 add */
    /* @4133928 call */
    GM_SITE(vm, 294, 4133928);
    v91 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @4133936 store */
    v92 = GM_CALL(vm, "instance_place", 3, v91, GM_READ(vm, -1, "y"), VAL(19));
    GM_WRITE(vm, -1, "hit12", v92);
    /* @4133944 load */
    /* @4133952 constant */
    /* @4133956 cmp */
    /* @4133960 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit12") != VAL(-4)))) goto L_4134376;
    /* @4133964 constant */
    /* @4133968 load */
    /* @4133976 cast */
    /* @4133980 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "flashing", VAL(1));
    /* @4133988 constant */
    /* @4133992 cast */
    /* @4133996 load */
    /* @4134004 load */
    /* @4134012 load */
    /* @4134020 load */
    /* @4134028 call */
    GM_SITE(vm, 294, 4134028);
    /* @4134036 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4134040 load */
    /* @4134048 cast */
    /* @4134052 dup */
    /* @4134056 load */
    /* @4134064 load */
    /* @4134072 sub */
    /* @4134076 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie") - GM_READ(vm, -5, "spikegundamage")));
    /* @4134084 constant */
    /* @4134088 cast */
    /* @4134092 load */
    /* @4134100 load */
    /* @4134108 call */
    GM_SITE(vm, 294, 4134108);
    /* @4134116 store */
    v93 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v93);
    /* @4134124 load */
    /* @4134132 load */
    /* @4134140 cast */
    /* @4134144 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4134152 constant */
    /* @4134156 constant */
    /* @4134160 constant */
    /* @4134164 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4134172 load */
    /* @4134180 constant */
    /* @4134184 cmp */
    /* @4134188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4134196;
    /* @4134192 b */
    goto L_4134252;
    L_4134196: ;
    /* @4134196 load */
    /* @4134204 constant */
    /* @4134208 cmp */
    /* @4134212 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4134252;
    /* @4134216 constant */
    /* @4134220 cast */
    /* @4134224 constant */
    /* @4134228 cast */
    /* @4134232 constant */
    /* @4134236 cast */
    /* @4134240 call */
    GM_SITE(vm, 294, 4134240);
    /* @4134248 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4134252: ;
    /* @4134252 constant */
    /* @4134256 load */
    /* @4134264 cast */
    /* @4134268 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "stunned", VAL(1));
    /* @4134276 constant */
    /* @4134280 load */
    /* @4134288 cast */
    /* @4134292 constant */
    /* @4134296 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit12")), "alarm", VAL(4), VAL(10));
    /* @4134304 load */
    /* @4134312 constant */
    /* @4134316 add */
    /* @4134320 store */
    v94 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v94);
    /* @4134328 load */
    /* @4134336 constant */
    /* @4134340 cmp */
    /* @4134344 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4134376;
    /* @4134348 constant */
    /* @4134352 load */
    /* @4134360 cast */
    /* @4134364 constant */
    /* @4134368 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit12")), "alarm", VAL(6), VAL(1));
    L_4134376: ;
    /* @4134376 constant */
    /* @4134380 cast */
    /* @4134384 load */
    /* @4134392 load */
    /* @4134400 constant */
    /* @4134404 sub */
    /* @4134408 call */
    GM_SITE(vm, 294, 4134408);
    /* @4134416 store */
    v95 = GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(20)), GM_READ(vm, -1, "y"), VAL(19));
    GM_WRITE(vm, -1, "hit12alt", v95);
    /* @4134424 load */
    /* @4134432 constant */
    /* @4134436 cmp */
    /* @4134440 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit12alt") != VAL(-4)))) goto L_4134856;
    /* @4134444 constant */
    /* @4134448 load */
    /* @4134456 cast */
    /* @4134460 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12alt")), "flashing", VAL(1));
    /* @4134468 constant */
    /* @4134472 cast */
    /* @4134476 load */
    /* @4134484 load */
    /* @4134492 load */
    /* @4134500 load */
    /* @4134508 call */
    GM_SITE(vm, 294, 4134508);
    /* @4134516 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4134520 load */
    /* @4134528 cast */
    /* @4134532 dup */
    /* @4134536 load */
    /* @4134544 load */
    /* @4134552 sub */
    /* @4134556 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12alt")), "hpzombie", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit12alt")), "hpzombie") - GM_READ(vm, -5, "spikegundamage")));
    /* @4134564 constant */
    /* @4134568 cast */
    /* @4134572 load */
    /* @4134580 load */
    /* @4134588 call */
    GM_SITE(vm, 294, 4134588);
    /* @4134596 store */
    v96 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v96);
    /* @4134604 load */
    /* @4134612 load */
    /* @4134620 cast */
    /* @4134624 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4134632 constant */
    /* @4134636 constant */
    /* @4134640 constant */
    /* @4134644 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4134652 load */
    /* @4134660 constant */
    /* @4134664 cmp */
    /* @4134668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4134676;
    /* @4134672 b */
    goto L_4134732;
    L_4134676: ;
    /* @4134676 load */
    /* @4134684 constant */
    /* @4134688 cmp */
    /* @4134692 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4134732;
    /* @4134696 constant */
    /* @4134700 cast */
    /* @4134704 constant */
    /* @4134708 cast */
    /* @4134712 constant */
    /* @4134716 cast */
    /* @4134720 call */
    GM_SITE(vm, 294, 4134720);
    /* @4134728 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4134732: ;
    /* @4134732 constant */
    /* @4134736 load */
    /* @4134744 cast */
    /* @4134748 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12alt")), "stunned", VAL(1));
    /* @4134756 constant */
    /* @4134760 load */
    /* @4134768 cast */
    /* @4134772 constant */
    /* @4134776 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit12alt")), "alarm", VAL(4), VAL(10));
    /* @4134784 load */
    /* @4134792 constant */
    /* @4134796 add */
    /* @4134800 store */
    v97 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v97);
    /* @4134808 load */
    /* @4134816 constant */
    /* @4134820 cmp */
    /* @4134824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4134856;
    /* @4134828 constant */
    /* @4134832 load */
    /* @4134840 cast */
    /* @4134844 constant */
    /* @4134848 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit12alt")), "alarm", VAL(6), VAL(1));
    L_4134856: ;
    /* @4134856 constant */
    /* @4134860 cast */
    /* @4134864 load */
    /* @4134872 load */
    /* @4134880 constant */
    /* @4134884 add */
    /* @4134888 call */
    GM_SITE(vm, 294, 4134888);
    v98 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @4134896 store */
    v99 = GM_CALL(vm, "instance_place", 3, v98, GM_READ(vm, -1, "y"), VAL(18));
    GM_WRITE(vm, -1, "hit13", v99);
    /* @4134904 load */
    /* @4134912 constant */
    /* @4134916 cmp */
    /* @4134920 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit13") != VAL(-4)))) goto L_4135336;
    /* @4134924 constant */
    /* @4134928 load */
    /* @4134936 cast */
    /* @4134940 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "flashing", VAL(1));
    /* @4134948 constant */
    /* @4134952 cast */
    /* @4134956 load */
    /* @4134964 load */
    /* @4134972 load */
    /* @4134980 load */
    /* @4134988 call */
    GM_SITE(vm, 294, 4134988);
    /* @4134996 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4135000 load */
    /* @4135008 cast */
    /* @4135012 dup */
    /* @4135016 load */
    /* @4135024 load */
    /* @4135032 sub */
    /* @4135036 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk") - GM_READ(vm, -5, "spikegundamage")));
    /* @4135044 constant */
    /* @4135048 cast */
    /* @4135052 load */
    /* @4135060 load */
    /* @4135068 call */
    GM_SITE(vm, 294, 4135068);
    /* @4135076 store */
    v100 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v100);
    /* @4135084 load */
    /* @4135092 load */
    /* @4135100 cast */
    /* @4135104 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4135112 constant */
    /* @4135116 constant */
    /* @4135120 constant */
    /* @4135124 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4135132 load */
    /* @4135140 constant */
    /* @4135144 cmp */
    /* @4135148 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4135156;
    /* @4135152 b */
    goto L_4135212;
    L_4135156: ;
    /* @4135156 load */
    /* @4135164 constant */
    /* @4135168 cmp */
    /* @4135172 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4135212;
    /* @4135176 constant */
    /* @4135180 cast */
    /* @4135184 constant */
    /* @4135188 cast */
    /* @4135192 constant */
    /* @4135196 cast */
    /* @4135200 call */
    GM_SITE(vm, 294, 4135200);
    /* @4135208 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4135212: ;
    /* @4135212 constant */
    /* @4135216 load */
    /* @4135224 cast */
    /* @4135228 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "stunned", VAL(1));
    /* @4135236 constant */
    /* @4135240 load */
    /* @4135248 cast */
    /* @4135252 constant */
    /* @4135256 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit13")), "alarm", VAL(4), VAL(10));
    /* @4135264 load */
    /* @4135272 constant */
    /* @4135276 add */
    /* @4135280 store */
    v101 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v101);
    /* @4135288 load */
    /* @4135296 constant */
    /* @4135300 cmp */
    /* @4135304 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4135336;
    /* @4135308 constant */
    /* @4135312 load */
    /* @4135320 cast */
    /* @4135324 constant */
    /* @4135328 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit13")), "alarm", VAL(7), VAL(1));
    L_4135336: ;
    /* @4135336 constant */
    /* @4135340 cast */
    /* @4135344 load */
    /* @4135352 load */
    /* @4135360 constant */
    /* @4135364 sub */
    /* @4135368 call */
    GM_SITE(vm, 294, 4135368);
    /* @4135376 store */
    v102 = GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(20)), GM_READ(vm, -1, "y"), VAL(18));
    GM_WRITE(vm, -1, "hit13alt", v102);
    /* @4135384 load */
    /* @4135392 constant */
    /* @4135396 cmp */
    /* @4135400 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit13alt") != VAL(-4)))) goto L_4135816;
    /* @4135404 constant */
    /* @4135408 load */
    /* @4135416 cast */
    /* @4135420 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13alt")), "flashing", VAL(1));
    /* @4135428 constant */
    /* @4135432 cast */
    /* @4135436 load */
    /* @4135444 load */
    /* @4135452 load */
    /* @4135460 load */
    /* @4135468 call */
    GM_SITE(vm, 294, 4135468);
    /* @4135476 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4135480 load */
    /* @4135488 cast */
    /* @4135492 dup */
    /* @4135496 load */
    /* @4135504 load */
    /* @4135512 sub */
    /* @4135516 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13alt")), "hpfirehulk", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit13alt")), "hpfirehulk") - GM_READ(vm, -5, "spikegundamage")));
    /* @4135524 constant */
    /* @4135528 cast */
    /* @4135532 load */
    /* @4135540 load */
    /* @4135548 call */
    GM_SITE(vm, 294, 4135548);
    /* @4135556 store */
    v103 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v103);
    /* @4135564 load */
    /* @4135572 load */
    /* @4135580 cast */
    /* @4135584 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4135592 constant */
    /* @4135596 constant */
    /* @4135600 constant */
    /* @4135604 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4135612 load */
    /* @4135620 constant */
    /* @4135624 cmp */
    /* @4135628 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4135636;
    /* @4135632 b */
    goto L_4135692;
    L_4135636: ;
    /* @4135636 load */
    /* @4135644 constant */
    /* @4135648 cmp */
    /* @4135652 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4135692;
    /* @4135656 constant */
    /* @4135660 cast */
    /* @4135664 constant */
    /* @4135668 cast */
    /* @4135672 constant */
    /* @4135676 cast */
    /* @4135680 call */
    GM_SITE(vm, 294, 4135680);
    /* @4135688 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4135692: ;
    /* @4135692 constant */
    /* @4135696 load */
    /* @4135704 cast */
    /* @4135708 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13alt")), "stunned", VAL(1));
    /* @4135716 constant */
    /* @4135720 load */
    /* @4135728 cast */
    /* @4135732 constant */
    /* @4135736 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit13alt")), "alarm", VAL(4), VAL(10));
    /* @4135744 load */
    /* @4135752 constant */
    /* @4135756 add */
    /* @4135760 store */
    v104 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v104);
    /* @4135768 load */
    /* @4135776 constant */
    /* @4135780 cmp */
    /* @4135784 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4135816;
    /* @4135788 constant */
    /* @4135792 load */
    /* @4135800 cast */
    /* @4135804 constant */
    /* @4135808 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit13alt")), "alarm", VAL(7), VAL(1));
    L_4135816: ;
    /* @4135816 constant */
    /* @4135820 cast */
    /* @4135824 load */
    /* @4135832 load */
    /* @4135840 constant */
    /* @4135844 add */
    /* @4135848 call */
    GM_SITE(vm, 294, 4135848);
    v105 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @4135856 store */
    v106 = GM_CALL(vm, "instance_place", 3, v105, GM_READ(vm, -1, "y"), VAL(17));
    GM_WRITE(vm, -1, "hit14", v106);
    /* @4135864 load */
    /* @4135872 constant */
    /* @4135876 cmp */
    /* @4135880 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit14") != VAL(-4)))) goto L_4136296;
    /* @4135884 constant */
    /* @4135888 load */
    /* @4135896 cast */
    /* @4135900 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "flashing", VAL(1));
    /* @4135908 constant */
    /* @4135912 cast */
    /* @4135916 load */
    /* @4135924 load */
    /* @4135932 load */
    /* @4135940 load */
    /* @4135948 call */
    GM_SITE(vm, 294, 4135948);
    /* @4135956 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4135960 load */
    /* @4135968 cast */
    /* @4135972 dup */
    /* @4135976 load */
    /* @4135984 load */
    /* @4135992 sub */
    /* @4135996 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton") - GM_READ(vm, -5, "spikegundamage")));
    /* @4136004 constant */
    /* @4136008 cast */
    /* @4136012 load */
    /* @4136020 load */
    /* @4136028 call */
    GM_SITE(vm, 294, 4136028);
    /* @4136036 store */
    v107 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v107);
    /* @4136044 load */
    /* @4136052 load */
    /* @4136060 cast */
    /* @4136064 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4136072 constant */
    /* @4136076 constant */
    /* @4136080 constant */
    /* @4136084 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4136092 load */
    /* @4136100 constant */
    /* @4136104 cmp */
    /* @4136108 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4136116;
    /* @4136112 b */
    goto L_4136172;
    L_4136116: ;
    /* @4136116 load */
    /* @4136124 constant */
    /* @4136128 cmp */
    /* @4136132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4136172;
    /* @4136136 constant */
    /* @4136140 cast */
    /* @4136144 constant */
    /* @4136148 cast */
    /* @4136152 constant */
    /* @4136156 cast */
    /* @4136160 call */
    GM_SITE(vm, 294, 4136160);
    /* @4136168 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4136172: ;
    /* @4136172 constant */
    /* @4136176 load */
    /* @4136184 cast */
    /* @4136188 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "stunned", VAL(1));
    /* @4136196 constant */
    /* @4136200 load */
    /* @4136208 cast */
    /* @4136212 constant */
    /* @4136216 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit14")), "alarm", VAL(4), VAL(10));
    /* @4136224 load */
    /* @4136232 constant */
    /* @4136236 add */
    /* @4136240 store */
    v108 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v108);
    /* @4136248 load */
    /* @4136256 constant */
    /* @4136260 cmp */
    /* @4136264 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4136296;
    /* @4136268 constant */
    /* @4136272 load */
    /* @4136280 cast */
    /* @4136284 constant */
    /* @4136288 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit14")), "alarm", VAL(6), VAL(1));
    L_4136296: ;
    /* @4136296 constant */
    /* @4136300 cast */
    /* @4136304 load */
    /* @4136312 load */
    /* @4136320 constant */
    /* @4136324 sub */
    /* @4136328 call */
    GM_SITE(vm, 294, 4136328);
    /* @4136336 store */
    v109 = GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(20)), GM_READ(vm, -1, "y"), VAL(17));
    GM_WRITE(vm, -1, "hit14alt", v109);
    /* @4136344 load */
    /* @4136352 constant */
    /* @4136356 cmp */
    /* @4136360 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit14alt") != VAL(-4)))) goto L_4136776;
    /* @4136364 constant */
    /* @4136368 load */
    /* @4136376 cast */
    /* @4136380 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14alt")), "flashing", VAL(1));
    /* @4136388 constant */
    /* @4136392 cast */
    /* @4136396 load */
    /* @4136404 load */
    /* @4136412 load */
    /* @4136420 load */
    /* @4136428 call */
    GM_SITE(vm, 294, 4136428);
    /* @4136436 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4136440 load */
    /* @4136448 cast */
    /* @4136452 dup */
    /* @4136456 load */
    /* @4136464 load */
    /* @4136472 sub */
    /* @4136476 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14alt")), "hpskeleton", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit14alt")), "hpskeleton") - GM_READ(vm, -5, "spikegundamage")));
    /* @4136484 constant */
    /* @4136488 cast */
    /* @4136492 load */
    /* @4136500 load */
    /* @4136508 call */
    GM_SITE(vm, 294, 4136508);
    /* @4136516 store */
    v110 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v110);
    /* @4136524 load */
    /* @4136532 load */
    /* @4136540 cast */
    /* @4136544 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4136552 constant */
    /* @4136556 constant */
    /* @4136560 constant */
    /* @4136564 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4136572 load */
    /* @4136580 constant */
    /* @4136584 cmp */
    /* @4136588 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4136596;
    /* @4136592 b */
    goto L_4136652;
    L_4136596: ;
    /* @4136596 load */
    /* @4136604 constant */
    /* @4136608 cmp */
    /* @4136612 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4136652;
    /* @4136616 constant */
    /* @4136620 cast */
    /* @4136624 constant */
    /* @4136628 cast */
    /* @4136632 constant */
    /* @4136636 cast */
    /* @4136640 call */
    GM_SITE(vm, 294, 4136640);
    /* @4136648 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4136652: ;
    /* @4136652 constant */
    /* @4136656 load */
    /* @4136664 cast */
    /* @4136668 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14alt")), "stunned", VAL(1));
    /* @4136676 constant */
    /* @4136680 load */
    /* @4136688 cast */
    /* @4136692 constant */
    /* @4136696 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit14alt")), "alarm", VAL(4), VAL(10));
    /* @4136704 load */
    /* @4136712 constant */
    /* @4136716 add */
    /* @4136720 store */
    v111 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v111);
    /* @4136728 load */
    /* @4136736 constant */
    /* @4136740 cmp */
    /* @4136744 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4136776;
    /* @4136748 constant */
    /* @4136752 load */
    /* @4136760 cast */
    /* @4136764 constant */
    /* @4136768 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit14alt")), "alarm", VAL(6), VAL(1));
    L_4136776: ;
    /* @4136776 constant */
    /* @4136780 cast */
    /* @4136784 load */
    /* @4136792 load */
    /* @4136800 constant */
    /* @4136804 add */
    /* @4136808 call */
    GM_SITE(vm, 294, 4136808);
    v112 = GM_ADD(GM_READ(vm, -1, "x"), VAL(30));
    /* @4136816 store */
    v113 = GM_CALL(vm, "instance_place", 3, v112, GM_READ(vm, -1, "y"), VAL(26));
    GM_WRITE(vm, -1, "hit15", v113);
    /* @4136824 load */
    /* @4136832 constant */
    /* @4136836 cmp */
    /* @4136840 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit15") != VAL(-4)))) goto L_4137204;
    /* @4136844 constant */
    /* @4136848 load */
    /* @4136856 cast */
    /* @4136860 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15")), "flashing", VAL(1));
    /* @4136868 constant */
    /* @4136872 cast */
    /* @4136876 load */
    /* @4136884 load */
    /* @4136892 load */
    /* @4136900 load */
    /* @4136908 call */
    GM_SITE(vm, 294, 4136908);
    /* @4136916 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4136920 load */
    /* @4136928 cast */
    /* @4136932 dup */
    /* @4136936 load */
    /* @4136944 load */
    /* @4136952 sub */
    /* @4136956 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2") - GM_READ(vm, -5, "spikegundamage")));
    /* @4136964 constant */
    /* @4136968 cast */
    /* @4136972 load */
    /* @4136980 load */
    /* @4136988 call */
    GM_SITE(vm, 294, 4136988);
    /* @4136996 store */
    v114 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v114);
    /* @4137004 load */
    /* @4137012 load */
    /* @4137020 cast */
    /* @4137024 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4137032 constant */
    /* @4137036 constant */
    /* @4137040 constant */
    /* @4137044 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4137052 load */
    /* @4137060 constant */
    /* @4137064 cmp */
    /* @4137068 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4137076;
    /* @4137072 b */
    goto L_4137132;
    L_4137076: ;
    /* @4137076 load */
    /* @4137084 constant */
    /* @4137088 cmp */
    /* @4137092 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4137132;
    /* @4137096 constant */
    /* @4137100 cast */
    /* @4137104 constant */
    /* @4137108 cast */
    /* @4137112 constant */
    /* @4137116 cast */
    /* @4137120 call */
    GM_SITE(vm, 294, 4137120);
    /* @4137128 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4137132: ;
    /* @4137132 load */
    /* @4137140 constant */
    /* @4137144 add */
    /* @4137148 store */
    v115 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v115);
    /* @4137156 load */
    /* @4137164 constant */
    /* @4137168 cmp */
    /* @4137172 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4137204;
    /* @4137176 constant */
    /* @4137180 load */
    /* @4137188 cast */
    /* @4137192 constant */
    /* @4137196 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit15")), "alarm", VAL(6), VAL(1));
    L_4137204: ;
    /* @4137204 constant */
    /* @4137208 cast */
    /* @4137212 load */
    /* @4137220 load */
    /* @4137228 constant */
    /* @4137232 sub */
    /* @4137236 call */
    GM_SITE(vm, 294, 4137236);
    /* @4137244 store */
    v116 = GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(30)), GM_READ(vm, -1, "y"), VAL(26));
    GM_WRITE(vm, -1, "hit15alt", v116);
    /* @4137252 load */
    /* @4137260 constant */
    /* @4137264 cmp */
    /* @4137268 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit15alt") != VAL(-4)))) goto L_4137632;
    /* @4137272 constant */
    /* @4137276 load */
    /* @4137284 cast */
    /* @4137288 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15alt")), "flashing", VAL(1));
    /* @4137296 constant */
    /* @4137300 cast */
    /* @4137304 load */
    /* @4137312 load */
    /* @4137320 load */
    /* @4137328 load */
    /* @4137336 call */
    GM_SITE(vm, 294, 4137336);
    /* @4137344 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4137348 load */
    /* @4137356 cast */
    /* @4137360 dup */
    /* @4137364 load */
    /* @4137372 load */
    /* @4137380 sub */
    /* @4137384 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15alt")), "hpboss2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit15alt")), "hpboss2") - GM_READ(vm, -5, "spikegundamage")));
    /* @4137392 constant */
    /* @4137396 cast */
    /* @4137400 load */
    /* @4137408 load */
    /* @4137416 call */
    GM_SITE(vm, 294, 4137416);
    /* @4137424 store */
    v117 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v117);
    /* @4137432 load */
    /* @4137440 load */
    /* @4137448 cast */
    /* @4137452 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4137460 constant */
    /* @4137464 constant */
    /* @4137468 constant */
    /* @4137472 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4137480 load */
    /* @4137488 constant */
    /* @4137492 cmp */
    /* @4137496 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4137504;
    /* @4137500 b */
    goto L_4137560;
    L_4137504: ;
    /* @4137504 load */
    /* @4137512 constant */
    /* @4137516 cmp */
    /* @4137520 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4137560;
    /* @4137524 constant */
    /* @4137528 cast */
    /* @4137532 constant */
    /* @4137536 cast */
    /* @4137540 constant */
    /* @4137544 cast */
    /* @4137548 call */
    GM_SITE(vm, 294, 4137548);
    /* @4137556 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4137560: ;
    /* @4137560 load */
    /* @4137568 constant */
    /* @4137572 add */
    /* @4137576 store */
    v118 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v118);
    /* @4137584 load */
    /* @4137592 constant */
    /* @4137596 cmp */
    /* @4137600 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4137632;
    /* @4137604 constant */
    /* @4137608 load */
    /* @4137616 cast */
    /* @4137620 constant */
    /* @4137624 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit15alt")), "alarm", VAL(6), VAL(1));
    L_4137632: ;
    /* @4137632 constant */
    /* @4137636 cast */
    /* @4137640 load */
    /* @4137648 load */
    /* @4137656 constant */
    /* @4137660 add */
    /* @4137664 call */
    GM_SITE(vm, 294, 4137664);
    v119 = GM_ADD(GM_READ(vm, -1, "x"), VAL(30));
    /* @4137672 store */
    v120 = GM_CALL(vm, "instance_place", 3, v119, GM_READ(vm, -1, "y"), VAL(27));
    GM_WRITE(vm, -1, "hit16", v120);
    /* @4137680 load */
    /* @4137688 constant */
    /* @4137692 cmp */
    /* @4137696 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit16") != VAL(-4)))) goto L_4138012;
    /* @4137700 constant */
    /* @4137704 load */
    /* @4137712 cast */
    /* @4137716 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16")), "flashing", VAL(1));
    /* @4137724 constant */
    /* @4137728 cast */
    /* @4137732 load */
    /* @4137740 load */
    /* @4137748 load */
    /* @4137756 load */
    /* @4137764 call */
    GM_SITE(vm, 294, 4137764);
    /* @4137772 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4137776 load */
    /* @4137784 cast */
    /* @4137788 dup */
    /* @4137792 load */
    /* @4137800 load */
    /* @4137808 sub */
    /* @4137812 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3") - GM_READ(vm, -5, "spikegundamage")));
    /* @4137820 constant */
    /* @4137824 cast */
    /* @4137828 load */
    /* @4137836 load */
    /* @4137844 call */
    GM_SITE(vm, 294, 4137844);
    /* @4137852 store */
    v121 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v121);
    /* @4137860 load */
    /* @4137868 load */
    /* @4137876 cast */
    /* @4137880 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4137888 constant */
    /* @4137892 constant */
    /* @4137896 constant */
    /* @4137900 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4137908 load */
    /* @4137916 constant */
    /* @4137920 cmp */
    /* @4137924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4137932;
    /* @4137928 b */
    goto L_4137988;
    L_4137932: ;
    /* @4137932 load */
    /* @4137940 constant */
    /* @4137944 cmp */
    /* @4137948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4137988;
    /* @4137952 constant */
    /* @4137956 cast */
    /* @4137960 constant */
    /* @4137964 cast */
    /* @4137968 constant */
    /* @4137972 cast */
    /* @4137976 call */
    GM_SITE(vm, 294, 4137976);
    /* @4137984 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4137988: ;
    /* @4137988 load */
    /* @4137996 constant */
    /* @4138000 add */
    /* @4138004 store */
    v122 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v122);
    L_4138012: ;
    /* @4138012 constant */
    /* @4138016 cast */
    /* @4138020 load */
    /* @4138028 load */
    /* @4138036 constant */
    /* @4138040 sub */
    /* @4138044 call */
    GM_SITE(vm, 294, 4138044);
    /* @4138052 store */
    v123 = GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(30)), GM_READ(vm, -1, "y"), VAL(27));
    GM_WRITE(vm, -1, "hit16alt", v123);
    /* @4138060 load */
    /* @4138068 constant */
    /* @4138072 cmp */
    /* @4138076 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit16alt") != VAL(-4)))) goto L_4138392;
    /* @4138080 constant */
    /* @4138084 load */
    /* @4138092 cast */
    /* @4138096 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16alt")), "flashing", VAL(1));
    /* @4138104 constant */
    /* @4138108 cast */
    /* @4138112 load */
    /* @4138120 load */
    /* @4138128 load */
    /* @4138136 load */
    /* @4138144 call */
    GM_SITE(vm, 294, 4138144);
    /* @4138152 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4138156 load */
    /* @4138164 cast */
    /* @4138168 dup */
    /* @4138172 load */
    /* @4138180 load */
    /* @4138188 sub */
    /* @4138192 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16alt")), "hpboss3", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit16alt")), "hpboss3") - GM_READ(vm, -5, "spikegundamage")));
    /* @4138200 constant */
    /* @4138204 cast */
    /* @4138208 load */
    /* @4138216 load */
    /* @4138224 call */
    GM_SITE(vm, 294, 4138224);
    /* @4138232 store */
    v124 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v124);
    /* @4138240 load */
    /* @4138248 load */
    /* @4138256 cast */
    /* @4138260 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4138268 constant */
    /* @4138272 constant */
    /* @4138276 constant */
    /* @4138280 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4138288 load */
    /* @4138296 constant */
    /* @4138300 cmp */
    /* @4138304 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4138312;
    /* @4138308 b */
    goto L_4138368;
    L_4138312: ;
    /* @4138312 load */
    /* @4138320 constant */
    /* @4138324 cmp */
    /* @4138328 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4138368;
    /* @4138332 constant */
    /* @4138336 cast */
    /* @4138340 constant */
    /* @4138344 cast */
    /* @4138348 constant */
    /* @4138352 cast */
    /* @4138356 call */
    GM_SITE(vm, 294, 4138356);
    /* @4138364 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4138368: ;
    /* @4138368 load */
    /* @4138376 constant */
    /* @4138380 add */
    /* @4138384 store */
    v125 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v125);
    L_4138392: ;
    /* @4138392 constant */
    /* @4138396 cast */
    /* @4138400 load */
    /* @4138408 load */
    /* @4138416 constant */
    /* @4138420 add */
    /* @4138424 call */
    GM_SITE(vm, 294, 4138424);
    v126 = GM_ADD(GM_READ(vm, -1, "x"), VAL(30));
    /* @4138432 store */
    v127 = GM_CALL(vm, "instance_place", 3, v126, GM_READ(vm, -1, "y"), VAL(28));
    GM_WRITE(vm, -1, "hitboss4", v127);
    /* @4138440 load */
    /* @4138448 constant */
    /* @4138452 cmp */
    /* @4138456 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss4") != VAL(-4)))) goto L_4138772;
    /* @4138460 constant */
    /* @4138464 load */
    /* @4138472 cast */
    /* @4138476 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "flashing", VAL(1));
    /* @4138484 constant */
    /* @4138488 cast */
    /* @4138492 load */
    /* @4138500 load */
    /* @4138508 load */
    /* @4138516 load */
    /* @4138524 call */
    GM_SITE(vm, 294, 4138524);
    /* @4138532 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4138536 load */
    /* @4138544 cast */
    /* @4138548 dup */
    /* @4138552 load */
    /* @4138560 load */
    /* @4138568 sub */
    /* @4138572 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4") - GM_READ(vm, -5, "spikegundamage")));
    /* @4138580 constant */
    /* @4138584 cast */
    /* @4138588 load */
    /* @4138596 load */
    /* @4138604 call */
    GM_SITE(vm, 294, 4138604);
    /* @4138612 store */
    v128 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v128);
    /* @4138620 load */
    /* @4138628 load */
    /* @4138636 cast */
    /* @4138640 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4138648 constant */
    /* @4138652 constant */
    /* @4138656 constant */
    /* @4138660 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4138668 load */
    /* @4138676 constant */
    /* @4138680 cmp */
    /* @4138684 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4138692;
    /* @4138688 b */
    goto L_4138748;
    L_4138692: ;
    /* @4138692 load */
    /* @4138700 constant */
    /* @4138704 cmp */
    /* @4138708 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4138748;
    /* @4138712 constant */
    /* @4138716 cast */
    /* @4138720 constant */
    /* @4138724 cast */
    /* @4138728 constant */
    /* @4138732 cast */
    /* @4138736 call */
    GM_SITE(vm, 294, 4138736);
    /* @4138744 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4138748: ;
    /* @4138748 load */
    /* @4138756 constant */
    /* @4138760 add */
    /* @4138764 store */
    v129 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v129);
    L_4138772: ;
    /* @4138772 constant */
    /* @4138776 cast */
    /* @4138780 load */
    /* @4138788 load */
    /* @4138796 constant */
    /* @4138800 sub */
    /* @4138804 call */
    GM_SITE(vm, 294, 4138804);
    /* @4138812 store */
    v130 = GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(30)), GM_READ(vm, -1, "y"), VAL(28));
    GM_WRITE(vm, -1, "hitboss4alt", v130);
    /* @4138820 load */
    /* @4138828 constant */
    /* @4138832 cmp */
    /* @4138836 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss4alt") != VAL(-4)))) goto L_4139152;
    /* @4138840 constant */
    /* @4138844 load */
    /* @4138852 cast */
    /* @4138856 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4alt")), "flashing", VAL(1));
    /* @4138864 constant */
    /* @4138868 cast */
    /* @4138872 load */
    /* @4138880 load */
    /* @4138888 load */
    /* @4138896 load */
    /* @4138904 call */
    GM_SITE(vm, 294, 4138904);
    /* @4138912 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4138916 load */
    /* @4138924 cast */
    /* @4138928 dup */
    /* @4138932 load */
    /* @4138940 load */
    /* @4138948 sub */
    /* @4138952 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4alt")), "hpboss4", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss4alt")), "hpboss4") - GM_READ(vm, -5, "spikegundamage")));
    /* @4138960 constant */
    /* @4138964 cast */
    /* @4138968 load */
    /* @4138976 load */
    /* @4138984 call */
    GM_SITE(vm, 294, 4138984);
    /* @4138992 store */
    v131 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v131);
    /* @4139000 load */
    /* @4139008 load */
    /* @4139016 cast */
    /* @4139020 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4139028 constant */
    /* @4139032 constant */
    /* @4139036 constant */
    /* @4139040 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4139048 load */
    /* @4139056 constant */
    /* @4139060 cmp */
    /* @4139064 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4139072;
    /* @4139068 b */
    goto L_4139128;
    L_4139072: ;
    /* @4139072 load */
    /* @4139080 constant */
    /* @4139084 cmp */
    /* @4139088 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4139128;
    /* @4139092 constant */
    /* @4139096 cast */
    /* @4139100 constant */
    /* @4139104 cast */
    /* @4139108 constant */
    /* @4139112 cast */
    /* @4139116 call */
    GM_SITE(vm, 294, 4139116);
    /* @4139124 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4139128: ;
    /* @4139128 load */
    /* @4139136 constant */
    /* @4139140 add */
    /* @4139144 store */
    v132 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v132);
    L_4139152: ;
    /* @4139152 constant */
    /* @4139156 cast */
    /* @4139160 load */
    /* @4139168 load */
    /* @4139176 constant */
    /* @4139180 add */
    /* @4139184 call */
    GM_SITE(vm, 294, 4139184);
    v133 = GM_ADD(GM_READ(vm, -1, "x"), VAL(30));
    /* @4139192 store */
    v134 = GM_CALL(vm, "instance_place", 3, v133, GM_READ(vm, -1, "y"), VAL(29));
    GM_WRITE(vm, -1, "hitboss5", v134);
    /* @4139200 load */
    /* @4139208 constant */
    /* @4139212 cmp */
    /* @4139216 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss5") != VAL(-4)))) goto L_4139532;
    /* @4139220 constant */
    /* @4139224 load */
    /* @4139232 cast */
    /* @4139236 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "flashing", VAL(1));
    /* @4139244 constant */
    /* @4139248 cast */
    /* @4139252 load */
    /* @4139260 load */
    /* @4139268 load */
    /* @4139276 load */
    /* @4139284 call */
    GM_SITE(vm, 294, 4139284);
    /* @4139292 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4139296 load */
    /* @4139304 cast */
    /* @4139308 dup */
    /* @4139312 load */
    /* @4139320 load */
    /* @4139328 sub */
    /* @4139332 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5") - GM_READ(vm, -5, "spikegundamage")));
    /* @4139340 constant */
    /* @4139344 cast */
    /* @4139348 load */
    /* @4139356 load */
    /* @4139364 call */
    GM_SITE(vm, 294, 4139364);
    /* @4139372 store */
    v135 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v135);
    /* @4139380 load */
    /* @4139388 load */
    /* @4139396 cast */
    /* @4139400 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4139408 constant */
    /* @4139412 constant */
    /* @4139416 constant */
    /* @4139420 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4139428 load */
    /* @4139436 constant */
    /* @4139440 cmp */
    /* @4139444 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4139452;
    /* @4139448 b */
    goto L_4139508;
    L_4139452: ;
    /* @4139452 load */
    /* @4139460 constant */
    /* @4139464 cmp */
    /* @4139468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4139508;
    /* @4139472 constant */
    /* @4139476 cast */
    /* @4139480 constant */
    /* @4139484 cast */
    /* @4139488 constant */
    /* @4139492 cast */
    /* @4139496 call */
    GM_SITE(vm, 294, 4139496);
    /* @4139504 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4139508: ;
    /* @4139508 load */
    /* @4139516 constant */
    /* @4139520 add */
    /* @4139524 store */
    v136 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v136);
    L_4139532: ;
    /* @4139532 constant */
    /* @4139536 cast */
    /* @4139540 load */
    /* @4139548 load */
    /* @4139556 constant */
    /* @4139560 sub */
    /* @4139564 call */
    GM_SITE(vm, 294, 4139564);
    /* @4139572 store */
    v137 = GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(30)), GM_READ(vm, -1, "y"), VAL(29));
    GM_WRITE(vm, -1, "hitboss5alt", v137);
    /* @4139580 load */
    /* @4139588 constant */
    /* @4139592 cmp */
    /* @4139596 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss5alt") != VAL(-4)))) goto L_4139912;
    /* @4139600 constant */
    /* @4139604 load */
    /* @4139612 cast */
    /* @4139616 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5alt")), "flashing", VAL(1));
    /* @4139624 constant */
    /* @4139628 cast */
    /* @4139632 load */
    /* @4139640 load */
    /* @4139648 load */
    /* @4139656 load */
    /* @4139664 call */
    GM_SITE(vm, 294, 4139664);
    /* @4139672 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4139676 load */
    /* @4139684 cast */
    /* @4139688 dup */
    /* @4139692 load */
    /* @4139700 load */
    /* @4139708 sub */
    /* @4139712 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5alt")), "hpboss5", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss5alt")), "hpboss5") - GM_READ(vm, -5, "spikegundamage")));
    /* @4139720 constant */
    /* @4139724 cast */
    /* @4139728 load */
    /* @4139736 load */
    /* @4139744 call */
    GM_SITE(vm, 294, 4139744);
    /* @4139752 store */
    v138 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v138);
    /* @4139760 load */
    /* @4139768 load */
    /* @4139776 cast */
    /* @4139780 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4139788 constant */
    /* @4139792 constant */
    /* @4139796 constant */
    /* @4139800 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4139808 load */
    /* @4139816 constant */
    /* @4139820 cmp */
    /* @4139824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4139832;
    /* @4139828 b */
    goto L_4139888;
    L_4139832: ;
    /* @4139832 load */
    /* @4139840 constant */
    /* @4139844 cmp */
    /* @4139848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4139888;
    /* @4139852 constant */
    /* @4139856 cast */
    /* @4139860 constant */
    /* @4139864 cast */
    /* @4139868 constant */
    /* @4139872 cast */
    /* @4139876 call */
    GM_SITE(vm, 294, 4139876);
    /* @4139884 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4139888: ;
    /* @4139888 load */
    /* @4139896 constant */
    /* @4139900 add */
    /* @4139904 store */
    v139 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v139);
    L_4139912: ;
    /* @4139912 constant */
    /* @4139916 cast */
    /* @4139920 load */
    /* @4139928 load */
    /* @4139936 constant */
    /* @4139940 add */
    /* @4139944 call */
    GM_SITE(vm, 294, 4139944);
    v140 = GM_ADD(GM_READ(vm, -1, "x"), VAL(30));
    /* @4139952 store */
    v141 = GM_CALL(vm, "instance_place", 3, v140, GM_READ(vm, -1, "y"), VAL(30));
    GM_WRITE(vm, -1, "hit17", v141);
    /* @4139960 load */
    /* @4139968 constant */
    /* @4139972 cmp */
    /* @4139976 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit17") != VAL(-4)))) goto L_4140292;
    /* @4139980 constant */
    /* @4139984 load */
    /* @4139992 cast */
    /* @4139996 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17")), "flashing", VAL(1));
    /* @4140004 constant */
    /* @4140008 cast */
    /* @4140012 load */
    /* @4140020 load */
    /* @4140028 load */
    /* @4140036 load */
    /* @4140044 call */
    GM_SITE(vm, 294, 4140044);
    /* @4140052 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4140056 load */
    /* @4140064 cast */
    /* @4140068 dup */
    /* @4140072 load */
    /* @4140080 load */
    /* @4140088 sub */
    /* @4140092 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss") - GM_READ(vm, -5, "spikegundamage")));
    /* @4140100 constant */
    /* @4140104 cast */
    /* @4140108 load */
    /* @4140116 load */
    /* @4140124 call */
    GM_SITE(vm, 294, 4140124);
    /* @4140132 store */
    v142 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v142);
    /* @4140140 load */
    /* @4140148 load */
    /* @4140156 cast */
    /* @4140160 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4140168 constant */
    /* @4140172 constant */
    /* @4140176 constant */
    /* @4140180 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4140188 load */
    /* @4140196 constant */
    /* @4140200 cmp */
    /* @4140204 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4140212;
    /* @4140208 b */
    goto L_4140268;
    L_4140212: ;
    /* @4140212 load */
    /* @4140220 constant */
    /* @4140224 cmp */
    /* @4140228 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4140268;
    /* @4140232 constant */
    /* @4140236 cast */
    /* @4140240 constant */
    /* @4140244 cast */
    /* @4140248 constant */
    /* @4140252 cast */
    /* @4140256 call */
    GM_SITE(vm, 294, 4140256);
    /* @4140264 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4140268: ;
    /* @4140268 load */
    /* @4140276 constant */
    /* @4140280 add */
    /* @4140284 store */
    v143 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v143);
    L_4140292: ;
    /* @4140292 constant */
    /* @4140296 cast */
    /* @4140300 load */
    /* @4140308 load */
    /* @4140316 constant */
    /* @4140320 sub */
    /* @4140324 call */
    GM_SITE(vm, 294, 4140324);
    /* @4140332 store */
    v144 = GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(30)), GM_READ(vm, -1, "y"), VAL(30));
    GM_WRITE(vm, -1, "hit17alt", v144);
    /* @4140340 load */
    /* @4140348 constant */
    /* @4140352 cmp */
    /* @4140356 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit17alt") != VAL(-4)))) goto L_4140672;
    /* @4140360 constant */
    /* @4140364 load */
    /* @4140372 cast */
    /* @4140376 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17alt")), "flashing", VAL(1));
    /* @4140384 constant */
    /* @4140388 cast */
    /* @4140392 load */
    /* @4140400 load */
    /* @4140408 load */
    /* @4140416 load */
    /* @4140424 call */
    GM_SITE(vm, 294, 4140424);
    /* @4140432 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4140436 load */
    /* @4140444 cast */
    /* @4140448 dup */
    /* @4140452 load */
    /* @4140460 load */
    /* @4140468 sub */
    /* @4140472 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17alt")), "hpfinalboss", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit17alt")), "hpfinalboss") - GM_READ(vm, -5, "spikegundamage")));
    /* @4140480 constant */
    /* @4140484 cast */
    /* @4140488 load */
    /* @4140496 load */
    /* @4140504 call */
    GM_SITE(vm, 294, 4140504);
    /* @4140512 store */
    v145 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v145);
    /* @4140520 load */
    /* @4140528 load */
    /* @4140536 cast */
    /* @4140540 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "spikegundamage"));
    /* @4140548 constant */
    /* @4140552 constant */
    /* @4140556 constant */
    /* @4140560 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4140568 load */
    /* @4140576 constant */
    /* @4140580 cmp */
    /* @4140584 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4140592;
    /* @4140588 b */
    goto L_4140648;
    L_4140592: ;
    /* @4140592 load */
    /* @4140600 constant */
    /* @4140604 cmp */
    /* @4140608 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4140648;
    /* @4140612 constant */
    /* @4140616 cast */
    /* @4140620 constant */
    /* @4140624 cast */
    /* @4140628 constant */
    /* @4140632 cast */
    /* @4140636 call */
    GM_SITE(vm, 294, 4140636);
    /* @4140644 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4140648: ;
    /* @4140648 load */
    /* @4140656 constant */
    /* @4140660 add */
    /* @4140664 store */
    v146 = GM_ADD(GM_READ(vm, -5, "spikegunxp"), VAL(1));
    GM_WRITE(vm, -5, "spikegunxp", v146);
    L_4140672: ;
    return;
}
